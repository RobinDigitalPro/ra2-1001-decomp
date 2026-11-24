#include "recovered/numeric_b97_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::numeric_b97 {
namespace {
void f_000ba140(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_000ba0f0(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_000ba220(Memory&,State&,Frame&,const Operations&);
void f_0001b630(Memory&,State&,Frame&,const Operations&);
void f_0011f1a0(Memory&,State&,Frame&,const Operations&);
void f_0011f190(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000ba140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4ba140: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
   { // 0x4ba144: d80d3c317c00 FMUL float ptr [0x007c313c]
    const auto address=(0x007c313cu);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x4ba14a: e801092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956495u); flags=s.arithmetic_flags;
  }
   { // 0x4ba14f: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
   { // 0x4ba151: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ba152: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x4ba154: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
   { // 0x4ba157: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ba159: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
   { // 0x4ba15e: 7910 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
   { // 0x4ba160: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x4ba161: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
   { // 0x4ba166: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
   { // 0x4ba167: 7907 JNS 0x004ba170
    if(integer::condition("JNS",flags)) goto L004ba170;
  }
   { // 0x4ba169: 0500280000 ADD EAX,0x2800
    s.ax = integer::add(s.ax,0x00002800u,32,flags);
  }
   { // 0x4ba16e: eb05 JMP 0x004ba175
    goto L004ba175;
  }
  L004ba170: { // 0x4ba170: 0500080000 ADD EAX,0x800
    s.ax = integer::add(s.ax,0x00000800u,32,flags);
  }
  L004ba175: { // 0x4ba175: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
   { // 0x4ba177: 7408 JZ 0x004ba181
    if(integer::condition("JZ",flags)) goto L004ba181;
  }
   { // 0x4ba179: 3dff270000 CMP EAX,0x27ff
    (void)integer::sub(s.ax,0x000027ffu,32,flags);
  }
   { // 0x4ba17e: 7d01 JGE 0x004ba181
    if(integer::condition("JGE",flags)) goto L004ba181;
  }
   { // 0x4ba180: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba181: { // 0x4ba181: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
   { // 0x4ba188: c3 RET
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
    s.fp.load_control(m.r16(address));
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
void f_000ba0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4ba0f0: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
   { // 0x4ba0f4: d80d38317c00 FMUL float ptr [0x007c3138]
    const auto address=(0x007c3138u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x4ba0fa: e851092b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956415u); flags=s.arithmetic_flags;
  }
   { // 0x4ba0ff: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
   { // 0x4ba101: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ba102: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x4ba104: 80e101 AND CL,0x1
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags));
  }
   { // 0x4ba107: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ba109: 25ff1f0080 AND EAX,0x80001fff
    s.ax = integer::logical((s.ax)&(0x80001fffu),32,flags);
  }
   { // 0x4ba10e: 790e JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
   { // 0x4ba110: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x4ba111: 0d00e0ffff OR EAX,0xffffe000
    s.ax = integer::logical((s.ax)|(0xffffe000u),32,flags);
  }
   { // 0x4ba116: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
   { // 0x4ba117: 7905 JNS 0x004ba11e
    if(integer::condition("JNS",flags)) goto L004ba11e;
  }
   { // 0x4ba119: 0500200000 ADD EAX,0x2000
    s.ax = integer::add(s.ax,0x00002000u,32,flags);
  }
  L004ba11e: { // 0x4ba11e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
   { // 0x4ba120: 7408 JZ 0x004ba12a
    if(integer::condition("JZ",flags)) goto L004ba12a;
  }
   { // 0x4ba122: 3dff1f0000 CMP EAX,0x1fff
    (void)integer::sub(s.ax,0x00001fffu,32,flags);
  }
   { // 0x4ba127: 7d01 JGE 0x004ba12a
    if(integer::condition("JGE",flags)) goto L004ba12a;
  }
   { // 0x4ba129: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ba12a: { // 0x4ba12a: d9048504a17e00 FLD float ptr [EAX*0x4 + 0x7ea104]
    const auto address=((s.ax * 0x00000004u)+0x007ea104u);
    s.fp.load32(m.r32(address));
  }
   { // 0x4ba131: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
   { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
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
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
   { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
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
    s.fp.multiply64(read64(m,address));
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
    s.fp.load32(m.r32(address));
  }
   { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}




void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
   { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
   { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
   { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
   { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
   { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
   { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
   { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
   { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
   { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
   { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
   { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
   { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
   { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
   { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
   { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
   { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
   { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
   { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
   { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
   { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000ba220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4ba220: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
   { // 0x4ba224: d9542404 FST float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
   { // 0x4ba228: d83538018000 FDIV float ptr [0x00800138]
    const auto address=(0x00800138u);
    floating_b61::fp_extended::divide32(s.fp,m.r32(address));
  }
   { // 0x4ba22e: e81d082b00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4956723u); flags=s.arithmetic_flags;
  }
   { // 0x4ba233: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ba234: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
   { // 0x4ba236: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x4ba238: 3d01100000 CMP EAX,0x1001
    (void)integer::sub(s.ax,0x00001001u,32,flags);
  }
   { // 0x4ba23d: 7d09 JGE 0x004ba248
    if(integer::condition("JGE",flags)) goto L004ba248;
  }
   { // 0x4ba23f: d9048534c17f00 FLD float ptr [EAX*0x4 + 0x7fc134]
    const auto address=((s.ax * 0x00000004u)+0x007fc134u);
    s.fp.load32(m.r32(address));
  }
   { // 0x4ba246: eb06 JMP 0x004ba24e
    goto L004ba24e;
  }
  L004ba248: { // 0x4ba248: d9058cbf7800 FLD float ptr [0x0078bf8c]
    const auto address=(0x0078bf8cu);
    s.fp.load32(m.r32(address));
  }
  L004ba24e: { // 0x4ba24e: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
   { // 0x4ba252: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
   { // 0x4ba258: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x4ba25a: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x4ba25d: 7402 JZ 0x004ba261
    if(integer::condition("JZ",flags)) goto L004ba261;
  }
   { // 0x4ba25f: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L004ba261: { // 0x4ba261: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0001b630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x41b630: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
   { // 0x41b634: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
   { // 0x41b636: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
   { // 0x41b63a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
   { // 0x41b63c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
   { // 0x41b640: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
   { // 0x41b643: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
   { // 0x41b646: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}


void f_0011f1a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x51f1a0: 8b0d7c95a300 MOV ECX,dword ptr [0x00a3957c]
    s.cx = m.r32((0x00a3957cu));
  }
   { // 0x51f1a6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x51f1a8: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
   { // 0x51f1ab: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
   { // 0x51f1ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0011f190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x51f190: a07495a300 MOV AL,[0x00a39574]
    s.ax = with_al(s.ax, m.r8((0x00a39574u)));
  }
   { // 0x51f195: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x6d4b30: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
   { // 0x6d4b34: 8d14c500000000 LEA EDX,[EAX*0x8 + 0x0]
    s.dx = ((s.ax * 0x00000008u)+0x00000000u);
  }
   { // 0x6d4b3b: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
   { // 0x6d4b3d: 8d84914c070000 LEA EAX,[ECX + EDX*0x4 + 0x74c]
    s.ax = (s.cx+(s.dx * 0x00000004u)+0x0000074cu);
  }
   { // 0x6d4b44: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4956480u:f_000ba140(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4956400u:f_000ba0f0(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 4956704u:f_000ba220(m,s,child,{});break;
case 4306480u:f_0001b630(m,s,child,{});break;
case 5370272u:f_0011f1a0(m,s,child,{});break;
case 5370256u:f_0011f190(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
default:throw std::domain_error("numeric97 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0045e710(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x45e710: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
   { // 0x45e713: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x45e714: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x45e715: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
   { // 0x45e717: 8a878a130000 MOV AL,byte ptr [EDI + 0x138a]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000138au)));
  }
   { // 0x45e71d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
   { // 0x45e71f: 0f8409010000 JZ 0x0045e82e
    if(integer::condition("JZ",flags)) goto L0045e82e;
  }
   { // 0x45e725: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
   { // 0x45e727: e804642700 CALL 0x006d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4581164u); flags=s.arithmetic_flags;
  }
   { // 0x45e72c: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
   { // 0x45e72e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x45e730: 0f84f8000000 JZ 0x0045e82e
    if(integer::condition("JZ",flags)) goto L0045e82e;
  }
   { // 0x45e736: db86a4000000 FILD dword ptr [ESI + 0xa4]
    const auto address=(s.si+0x000000a4u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x45e73c: db86b0000000 FILD dword ptr [ESI + 0xb0]
    const auto address=(s.si+0x000000b0u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x45e742: dc0de8827800 FMUL double ptr [0x007882e8]
    const auto address=(0x007882e8u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x45e748: def9 FDIVP
    numeric_b88::detail::reg<0xdef9>(s.fp);
  }
   { // 0x45e74a: e801c33000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4581199u); flags=s.arithmetic_flags;
  }
   { // 0x45e74f: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
   { // 0x45e753: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
   { // 0x45e759: 8a8874020000 MOV CL,byte ptr [EAX + 0x274]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000274u)));
  }
   { // 0x45e75f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
   { // 0x45e761: 743c JZ 0x0045e79f
    if(integer::condition("JZ",flags)) goto L0045e79f;
  }
   { // 0x45e763: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
   { // 0x45e769: 8b96ac000000 MOV EDX,dword ptr [ESI + 0xac]
    s.dx = m.r32((s.si+0x000000acu));
  }
   { // 0x45e76f: db81cc090000 FILD dword ptr [ECX + 0x9cc]
    const auto address=(s.cx+0x000009ccu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x45e775: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x45e779: dc8ab8000000 FMUL double ptr [EDX + 0xb8]
    const auto address=(s.dx+0x000000b8u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x45e77f: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x45e783: dc542410 FCOM double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x45e787: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x45e789: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x45e78c: 7506 JNZ 0x0045e794
    if(integer::condition("JNZ",flags)) goto L0045e794;
  }
   { // 0x45e78e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x45e790: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0045e794: { // 0x45e794: e8b7c23000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4581273u); flags=s.arithmetic_flags;
  }
   { // 0x45e799: 8987d8110000 MOV dword ptr [EDI + 0x11d8],EAX
    m.w32((s.di+0x000011d8u), s.ax);
  }
  L0045e79f: { // 0x45e79f: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
   { // 0x45e7a5: 8a8875020000 MOV CL,byte ptr [EAX + 0x275]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000275u)));
  }
   { // 0x45e7ab: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
   { // 0x45e7ad: 747f JZ 0x0045e82e
    if(integer::condition("JZ",flags)) goto L0045e82e;
  }
   { // 0x45e7af: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
   { // 0x45e7b5: 8b96ac000000 MOV EDX,dword ptr [ESI + 0xac]
    s.dx = m.r32((s.si+0x000000acu));
  }
   { // 0x45e7bb: db81cc090000 FILD dword ptr [ECX + 0x9cc]
    const auto address=(s.cx+0x000009ccu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x45e7c1: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x45e7c5: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x45e7c9: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
   { // 0x45e7cd: dc8ac0000000 FMUL double ptr [EDX + 0xc0]
    const auto address=(s.dx+0x000000c0u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x45e7d3: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x45e7d7: dc542410 FCOM double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x45e7db: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x45e7dd: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x45e7e0: 7506 JNZ 0x0045e7e8
    if(integer::condition("JNZ",flags)) goto L0045e7e8;
  }
   { // 0x45e7e2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x45e7e4: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0045e7e8: { // 0x45e7e8: e863c23000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4581357u); flags=s.arithmetic_flags;
  }
   { // 0x45e7ed: 8987dc110000 MOV dword ptr [EDI + 0x11dc],EAX
    m.w32((s.di+0x000011dcu), s.ax);
  }
   { // 0x45e7f3: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
   { // 0x45e7f8: 8b8eac000000 MOV ECX,dword ptr [ESI + 0xac]
    s.cx = m.r32((s.si+0x000000acu));
  }
   { // 0x45e7fe: db80cc090000 FILD dword ptr [EAX + 0x9cc]
    const auto address=(s.ax+0x000009ccu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x45e804: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
   { // 0x45e808: dc89a0000000 FMUL double ptr [ECX + 0xa0]
    const auto address=(s.cx+0x000000a0u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x45e80e: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x45e812: dc542410 FCOM double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x45e816: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x45e818: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x45e81b: 7506 JNZ 0x0045e823
    if(integer::condition("JNZ",flags)) goto L0045e823;
  }
   { // 0x45e81d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x45e81f: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0045e823: { // 0x45e823: e828c23000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4581416u); flags=s.arithmetic_flags;
  }
   { // 0x45e828: 8987e0110000 MOV dword ptr [EDI + 0x11e0],EAX
    m.w32((s.di+0x000011e0u), s.ax);
  }
  L0045e82e: { // 0x45e82e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x45e82f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x45e830: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x45e833: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004794f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4794f0: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
   { // 0x4794f5: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x4794f6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x4794f8: 8b80ac220000 MOV EAX,dword ptr [EAX + 0x22ac]
    s.ax = m.r32((s.ax+0x000022acu));
  }
   { // 0x4794fe: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
   { // 0x479501: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
   { // 0x479504: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
   { // 0x479507: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
   { // 0x47950c: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
   { // 0x47950f: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
   { // 0x479511: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x479514: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
   { // 0x479516: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
   { // 0x479519: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
   { // 0x47951b: 66039608010000 ADD DX,word ptr [ESI + 0x108]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.si+0x00000108u)),16,flags));
  }
   { // 0x479522: 6689960a010000 MOV word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), (s.dx & 0xffffu));
  }
   { // 0x479529: 6689960e010000 MOV word ptr [ESI + 0x10e],DX
    m.w16((s.si+0x0000010eu), (s.dx & 0xffffu));
  }
   { // 0x479530: e85b5c0a00 CALL 0x0051f190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0051f190u,4691253u); flags=s.arithmetic_flags;
  }
   { // 0x479535: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
   { // 0x479537: 7440 JZ 0x00479579
    if(integer::condition("JZ",flags)) goto L00479579;
  }
   { // 0x479539: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
   { // 0x47953f: 660fbe861b010000 MOVSX AX,byte ptr [ESI + 0x11b]
    s.ax = with_ax(s.ax, std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8)));
  }
   { // 0x479547: 668b91dc220000 MOV DX,word ptr [ECX + 0x22dc]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x000022dcu)));
  }
   { // 0x47954e: 660fafd0 IMUL DX,AX
    s.dx = with_ax(s.dx, integer::imul((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
   { // 0x479552: 662b91d8220000 SUB DX,word ptr [ECX + 0x22d8]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.cx+0x000022d8u)),16,flags));
  }
   { // 0x479559: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
   { // 0x47955c: 6601960a010000 ADD word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), integer::add(m.r16((s.si+0x0000010au)),(s.dx & 0xffffu),16,flags));
  }
   { // 0x479563: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
   { // 0x479568: 660faf88dc220000 IMUL CX,word ptr [EAX + 0x22dc]
    s.cx = with_ax(s.cx, integer::imul((s.cx & 0xffffu),m.r16((s.ax+0x000022dcu)),16,flags));
  }
   { // 0x479570: 662b88d8220000 SUB CX,word ptr [EAX + 0x22d8]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.ax+0x000022d8u)),16,flags));
  }
   { // 0x479577: eb79 JMP 0x004795f2
    goto L004795f2;
  }
  L00479579: { // 0x479579: e8225c0a00 CALL 0x0051f1a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0051f1a0u,4691326u); flags=s.arithmetic_flags;
  }
   { // 0x47957e: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
   { // 0x479584: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
   { // 0x479586: 660fbe861b010000 MOVSX AX,byte ptr [ESI + 0x11b]
    s.ax = with_ax(s.ax, std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8)));
  }
   { // 0x47958e: 7432 JZ 0x004795c2
    if(integer::condition("JZ",flags)) goto L004795c2;
  }
   { // 0x479590: 668b91f4220000 MOV DX,word ptr [ECX + 0x22f4]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x000022f4u)));
  }
   { // 0x479597: 660fafd0 IMUL DX,AX
    s.dx = with_ax(s.dx, integer::imul((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
   { // 0x47959b: 662b91f0220000 SUB DX,word ptr [ECX + 0x22f0]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.cx+0x000022f0u)),16,flags));
  }
   { // 0x4795a2: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
   { // 0x4795a5: 6601960a010000 ADD word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), integer::add(m.r16((s.si+0x0000010au)),(s.dx & 0xffffu),16,flags));
  }
   { // 0x4795ac: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
   { // 0x4795b1: 660faf88f4220000 IMUL CX,word ptr [EAX + 0x22f4]
    s.cx = with_ax(s.cx, integer::imul((s.cx & 0xffffu),m.r16((s.ax+0x000022f4u)),16,flags));
  }
   { // 0x4795b9: 662b88f0220000 SUB CX,word ptr [EAX + 0x22f0]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.ax+0x000022f0u)),16,flags));
  }
   { // 0x4795c0: eb30 JMP 0x004795f2
    goto L004795f2;
  }
  L004795c2: { // 0x4795c2: 668b91c4220000 MOV DX,word ptr [ECX + 0x22c4]
    s.dx = with_ax(s.dx, m.r16((s.cx+0x000022c4u)));
  }
   { // 0x4795c9: 660fafd0 IMUL DX,AX
    s.dx = with_ax(s.dx, integer::imul((s.dx & 0xffffu),(s.ax & 0xffffu),16,flags));
  }
   { // 0x4795cd: 662b91c0220000 SUB DX,word ptr [ECX + 0x22c0]
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),m.r16((s.cx+0x000022c0u)),16,flags));
  }
   { // 0x4795d4: 8d4804 LEA ECX,[EAX + 0x4]
    s.cx = (s.ax+0x00000004u);
  }
   { // 0x4795d7: 6601960a010000 ADD word ptr [ESI + 0x10a],DX
    m.w16((s.si+0x0000010au), integer::add(m.r16((s.si+0x0000010au)),(s.dx & 0xffffu),16,flags));
  }
   { // 0x4795de: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
   { // 0x4795e3: 660faf88c4220000 IMUL CX,word ptr [EAX + 0x22c4]
    s.cx = with_ax(s.cx, integer::imul((s.cx & 0xffffu),m.r16((s.ax+0x000022c4u)),16,flags));
  }
   { // 0x4795eb: 662b88c0220000 SUB CX,word ptr [EAX + 0x22c0]
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),m.r16((s.ax+0x000022c0u)),16,flags));
  }
  L004795f2: { // 0x4795f2: 66018e0e010000 ADD word ptr [ESI + 0x10e],CX
    m.w16((s.si+0x0000010eu), integer::add(m.r16((s.si+0x0000010eu)),(s.cx & 0xffffu),16,flags));
  }
   { // 0x4795f9: 8b8e04010000 MOV ECX,dword ptr [ESI + 0x104]
    s.cx = m.r32((s.si+0x00000104u));
  }
   { // 0x4795ff: 0fbf960a010000 MOVSX EDX,word ptr [ESI + 0x10a]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x0000010au)),16));
  }
   { // 0x479606: 0fbf860e010000 MOVSX EAX,word ptr [ESI + 0x10e]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x0000010eu)),16));
  }
   { // 0x47960d: 0fafd1 IMUL EDX,ECX
    s.dx = integer::imul(s.dx,s.cx,32,flags);
  }
   { // 0x479610: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
   { // 0x479613: 668b8e0a010000 MOV CX,word ptr [ESI + 0x10a]
    s.cx = with_ax(s.cx, m.r16((s.si+0x0000010au)));
  }
   { // 0x47961a: c1fa10 SAR EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x47961d: c1f810 SAR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x479620: 6681f9d007 CMP CX,0x7d0
    (void)integer::sub((s.cx & 0xffffu),0x000007d0u,16,flags);
  }
   { // 0x479625: 6689960c010000 MOV word ptr [ESI + 0x10c],DX
    m.w16((s.si+0x0000010cu), (s.dx & 0xffffu));
  }
   { // 0x47962c: 6689860e010000 MOV word ptr [ESI + 0x10e],AX
    m.w16((s.si+0x0000010eu), (s.ax & 0xffffu));
  }
   { // 0x479633: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
   { // 0x479636: 7c05 JL 0x0047963d
    if(integer::condition("JL",flags)) goto L0047963d;
  }
   { // 0x479638: b9d0070000 MOV ECX,0x7d0
    s.cx = 0x000007d0u;
  }
  L0047963d: { // 0x47963d: 66898e0a010000 MOV word ptr [ESI + 0x10a],CX
    m.w16((s.si+0x0000010au), (s.cx & 0xffffu));
  }
   { // 0x479644: 668b8e0c010000 MOV CX,word ptr [ESI + 0x10c]
    s.cx = with_ax(s.cx, m.r16((s.si+0x0000010cu)));
  }
   { // 0x47964b: 6681f9d007 CMP CX,0x7d0
    (void)integer::sub((s.cx & 0xffffu),0x000007d0u,16,flags);
  }
   { // 0x479650: 0fbfd1 MOVSX EDX,CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
   { // 0x479653: 7c05 JL 0x0047965a
    if(integer::condition("JL",flags)) goto L0047965a;
  }
   { // 0x479655: bad0070000 MOV EDX,0x7d0
    s.dx = 0x000007d0u;
  }
  L0047965a: { // 0x47965a: 663dd007 CMP AX,0x7d0
    (void)integer::sub((s.ax & 0xffffu),0x000007d0u,16,flags);
  }
   { // 0x47965e: 6689960c010000 MOV word ptr [ESI + 0x10c],DX
    m.w16((s.si+0x0000010cu), (s.dx & 0xffffu));
  }
   { // 0x479665: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
   { // 0x479668: 7c05 JL 0x0047966f
    if(integer::condition("JL",flags)) goto L0047966f;
  }
   { // 0x47966a: b9d0070000 MOV ECX,0x7d0
    s.cx = 0x000007d0u;
  }
  L0047966f: { // 0x47966f: 668b860a010000 MOV AX,word ptr [ESI + 0x10a]
    s.ax = with_ax(s.ax, m.r16((s.si+0x0000010au)));
  }
   { // 0x479676: 66898e0e010000 MOV word ptr [ESI + 0x10e],CX
    m.w16((s.si+0x0000010eu), (s.cx & 0xffffu));
  }
   { // 0x47967d: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
   { // 0x479680: 7e05 JLE 0x00479687
    if(integer::condition("JLE",flags)) goto L00479687;
  }
   { // 0x479682: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
   { // 0x479685: eb02 JMP 0x00479689
    goto L00479689;
  }
  L00479687: { // 0x479687: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00479689: { // 0x479689: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
   { // 0x47968c: 6689860a010000 MOV word ptr [ESI + 0x10a],AX
    m.w16((s.si+0x0000010au), (s.ax & 0xffffu));
  }
   { // 0x479693: 7e05 JLE 0x0047969a
    if(integer::condition("JLE",flags)) goto L0047969a;
  }
   { // 0x479695: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
   { // 0x479698: eb02 JMP 0x0047969c
    goto L0047969c;
  }
  L0047969a: { // 0x47969a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0047969c: { // 0x47969c: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
   { // 0x47969f: 6689860c010000 MOV word ptr [ESI + 0x10c],AX
    m.w16((s.si+0x0000010cu), (s.ax & 0xffffu));
  }
   { // 0x4796a6: 7e0c JLE 0x004796b4
    if(integer::condition("JLE",flags)) goto L004796b4;
  }
   { // 0x4796a8: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
   { // 0x4796ab: 6689860e010000 MOV word ptr [ESI + 0x10e],AX
    m.w16((s.si+0x0000010eu), (s.ax & 0xffffu));
  }
   { // 0x4796b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4796b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004796b4: { // 0x4796b4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x4796b6: 6689860e010000 MOV word ptr [ESI + 0x10e],AX
    m.w16((s.si+0x0000010eu), (s.ax & 0xffffu));
  }
   { // 0x4796bd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4796be: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004cea00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4cea00: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
   { // 0x4cea04: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
   { // 0x4cea07: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x4cea08: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x4cea0a: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
   { // 0x4cea0e: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x4cea0f: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
   { // 0x4cea11: 7f02 JG 0x004cea15
    if(integer::condition("JG",flags)) goto L004cea15;
  }
   { // 0x4cea13: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004cea15: { // 0x4cea15: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
   { // 0x4cea1a: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
   { // 0x4cea1c: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x4cea1f: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
   { // 0x4cea21: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
   { // 0x4cea25: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
   { // 0x4cea28: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
   { // 0x4cea2b: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
   { // 0x4cea30: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
   { // 0x4cea33: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
   { // 0x4cea36: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
   { // 0x4cea3a: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
   { // 0x4cea3d: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
   { // 0x4cea41: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
   { // 0x4cea44: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
   { // 0x4cea46: 8d4e18 LEA ECX,[ESI + 0x18]
    s.cx = (s.si+0x00000018u);
  }
   { // 0x4cea49: 8b3a MOV EDI,dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
   { // 0x4cea4b: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
   { // 0x4cea4d: 8b7a04 MOV EDI,dword ptr [EDX + 0x4]
    s.di = m.r32((s.dx+0x00000004u));
  }
   { // 0x4cea50: 897904 MOV dword ptr [ECX + 0x4],EDI
    m.w32((s.cx+0x00000004u), s.di);
  }
   { // 0x4cea53: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
   { // 0x4cea56: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
   { // 0x4cea59: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
   { // 0x4cea5d: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
   { // 0x4cea5f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
   { // 0x4cea61: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
   { // 0x4cea63: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
   { // 0x4cea66: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
   { // 0x4cea6a: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
   { // 0x4cea6d: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
   { // 0x4cea70: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
   { // 0x4cea72: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
   { // 0x4cea76: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
   { // 0x4cea79: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4cea7d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
   { // 0x4cea7f: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
   { // 0x4cea83: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4cea87: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4cea8b: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
   { // 0x4cea8d: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x4cea8f: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
   { // 0x4cea91: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
   { // 0x4cea93: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x4cea95: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
   { // 0x4cea97: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
   { // 0x4cea99: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x4cea9b: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4cea9e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x4ceaa0: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x4ceaa2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x4ceaa4: e8d7b5feff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5040809u); flags=s.arithmetic_flags;
  }
   { // 0x4ceaa9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x4ceaac: e89fbf2900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5040817u); flags=s.arithmetic_flags;
  }
   { // 0x4ceab1: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
   { // 0x4ceab4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x4ceab5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4ceab6: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
   { // 0x4ceab9: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004ea450(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x4ea450: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x4ea451: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
   { // 0x4ea453: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
   { // 0x4ea456: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
   { // 0x4ea459: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
   { // 0x4ea45c: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x4ea45d: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x4ea45e: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
   { // 0x4ea461: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x4ea462: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x4ea464: 0f87f7020000 JA 0x004ea761
    if(integer::condition("JA",flags)) goto L004ea761;
  }
   { // 0x4ea46a: ff248578a74e00 JMP dword ptr [EAX*0x4 + 0x4ea778]
    switch(s.ax){case 0:goto L004ea471;case 1:goto L004ea4b1;case 2:goto L004ea55d;case 3:goto L004ea609;case 4:goto L004ea6b5;default:throw std::domain_error("numeric97 ea450 switch index outside 0..4");}
  }
  L004ea471: { // 0x4ea471: 8b86bc530000 MOV EAX,dword ptr [ESI + 0x53bc]
    s.ax = m.r32((s.si+0x000053bcu));
  }
   { // 0x4ea477: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea478: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea47e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea480: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea483: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
   { // 0x4ea488: 8b86c0530000 MOV EAX,dword ptr [ESI + 0x53c0]
    s.ax = m.r32((s.si+0x000053c0u));
  }
   { // 0x4ea48e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea48f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea495: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea497: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea49a: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
   { // 0x4ea49f: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
   { // 0x4ea4a2: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x4ea4a6: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
   { // 0x4ea4a8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x4ea4a9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4ea4aa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x4ea4ab: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x4ea4ad: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x4ea4ae: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004ea4b1: { // 0x4ea4b1: 8b86c8530000 MOV EAX,dword ptr [ESI + 0x53c8]
    s.ax = m.r32((s.si+0x000053c8u));
  }
   { // 0x4ea4b7: 8bbec4530000 MOV EDI,dword ptr [ESI + 0x53c4]
    s.di = m.r32((s.si+0x000053c4u));
  }
   { // 0x4ea4bd: 68c921f93f PUSH 0x3ff921c9
    f.push(m,0x3ff921c9u);
  }
   { // 0x4ea4c2: 68dafbe80f PUSH 0xfe8fbda
    f.push(m,0x0fe8fbdau);
  }
   { // 0x4ea4c7: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
   { // 0x4ea4ca: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
   { // 0x4ea4ce: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea4d2: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea4d6: db86c0530000 FILD dword ptr [ESI + 0x53c0]
    const auto address=(s.si+0x000053c0u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea4dc: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea4e0: e80bfcfcff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5154021u); flags=s.arithmetic_flags;
  }
   { // 0x4ea4e5: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea4e9: dc6c2420 FSUBR double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.reverse_subtract64(read64(m,address));
  }
   { // 0x4ea4ed: e85e052800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154034u); flags=s.arithmetic_flags;
  }
   { // 0x4ea4f2: 68c921f93f PUSH 0x3ff921c9
    f.push(m,0x3ff921c9u);
  }
   { // 0x4ea4f7: 68dafbe80f PUSH 0xfe8fbda
    f.push(m,0x0fe8fbdau);
  }
   { // 0x4ea4fc: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
   { // 0x4ea4fe: e83dfcfcff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5154051u); flags=s.arithmetic_flags;
  }
   { // 0x4ea503: dc4c2420 FMUL double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea507: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x4ea50a: da86bc530000 FIADD dword ptr [ESI + 0x53bc]
    const auto address=(s.si+0x000053bcu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
   { // 0x4ea510: e83b052800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154069u); flags=s.arithmetic_flags;
  }
   { // 0x4ea515: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x4ea516: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x4ea517: 50 PUSH EAX
    f.push(m,s.ax);
  }
   { // 0x4ea518: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
   { // 0x4ea51c: e80f11f3ff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,5154081u); flags=s.arithmetic_flags;
  }
   { // 0x4ea521: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
   { // 0x4ea525: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea526: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea52c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea52e: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea531: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
   { // 0x4ea536: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
   { // 0x4ea53a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea53b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea541: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea543: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea546: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
   { // 0x4ea54b: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
   { // 0x4ea54e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x4ea552: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
   { // 0x4ea554: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x4ea555: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4ea556: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x4ea557: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x4ea559: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x4ea55a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004ea55d: { // 0x4ea55d: 8b86c8530000 MOV EAX,dword ptr [ESI + 0x53c8]
    s.ax = m.r32((s.si+0x000053c8u));
  }
   { // 0x4ea563: 8bbec4530000 MOV EDI,dword ptr [ESI + 0x53c4]
    s.di = m.r32((s.si+0x000053c4u));
  }
   { // 0x4ea569: 682d2219bf PUSH 0xbf19222d
    f.push(m,0xbf19222du);
  }
   { // 0x4ea56e: 68575e9f98 PUSH 0x989f5e57
    f.push(m,0x989f5e57u);
  }
   { // 0x4ea573: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
   { // 0x4ea576: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
   { // 0x4ea57a: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea57e: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea582: db86c0530000 FILD dword ptr [ESI + 0x53c0]
    const auto address=(s.si+0x000053c0u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea588: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea58c: e85ffbfcff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5154193u); flags=s.arithmetic_flags;
  }
   { // 0x4ea591: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea595: dc6c2420 FSUBR double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.reverse_subtract64(read64(m,address));
  }
   { // 0x4ea599: e8b2042800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154206u); flags=s.arithmetic_flags;
  }
   { // 0x4ea59e: 682d2219bf PUSH 0xbf19222d
    f.push(m,0xbf19222du);
  }
   { // 0x4ea5a3: 68575e9f98 PUSH 0x989f5e57
    f.push(m,0x989f5e57u);
  }
   { // 0x4ea5a8: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
   { // 0x4ea5aa: e891fbfcff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5154223u); flags=s.arithmetic_flags;
  }
   { // 0x4ea5af: dc4c2420 FMUL double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea5b3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x4ea5b6: da86bc530000 FIADD dword ptr [ESI + 0x53bc]
    const auto address=(s.si+0x000053bcu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
   { // 0x4ea5bc: e88f042800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154241u); flags=s.arithmetic_flags;
  }
   { // 0x4ea5c1: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x4ea5c2: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x4ea5c3: 50 PUSH EAX
    f.push(m,s.ax);
  }
   { // 0x4ea5c4: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
   { // 0x4ea5c8: e86310f3ff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,5154253u); flags=s.arithmetic_flags;
  }
   { // 0x4ea5cd: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
   { // 0x4ea5d1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea5d2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea5d8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea5da: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea5dd: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
   { // 0x4ea5e2: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
   { // 0x4ea5e6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea5e7: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea5ed: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea5ef: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea5f2: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
   { // 0x4ea5f7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
   { // 0x4ea5fa: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x4ea5fe: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
   { // 0x4ea600: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x4ea601: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4ea602: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x4ea603: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x4ea605: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x4ea606: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004ea609: { // 0x4ea609: 8b86c8530000 MOV EAX,dword ptr [ESI + 0x53c8]
    s.ax = m.r32((s.si+0x000053c8u));
  }
   { // 0x4ea60f: 8bbec4530000 MOV EDI,dword ptr [ESI + 0x53c4]
    s.di = m.r32((s.si+0x000053c4u));
  }
   { // 0x4ea615: 68fb210940 PUSH 0x400921fb
    f.push(m,0x400921fbu);
  }
   { // 0x4ea61a: 68182d4454 PUSH 0x54442d18
    f.push(m,0x54442d18u);
  }
   { // 0x4ea61f: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
   { // 0x4ea622: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
   { // 0x4ea626: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea62a: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea62e: db86c0530000 FILD dword ptr [ESI + 0x53c0]
    const auto address=(s.si+0x000053c0u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea634: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea638: e8b3fafcff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5154365u); flags=s.arithmetic_flags;
  }
   { // 0x4ea63d: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea641: dc6c2420 FSUBR double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.reverse_subtract64(read64(m,address));
  }
   { // 0x4ea645: e806042800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154378u); flags=s.arithmetic_flags;
  }
   { // 0x4ea64a: 68fb210940 PUSH 0x400921fb
    f.push(m,0x400921fbu);
  }
   { // 0x4ea64f: 68182d4454 PUSH 0x54442d18
    f.push(m,0x54442d18u);
  }
   { // 0x4ea654: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
   { // 0x4ea656: e8e5fafcff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5154395u); flags=s.arithmetic_flags;
  }
   { // 0x4ea65b: dc4c2420 FMUL double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea65f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x4ea662: da86bc530000 FIADD dword ptr [ESI + 0x53bc]
    const auto address=(s.si+0x000053bcu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
   { // 0x4ea668: e8e3032800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154413u); flags=s.arithmetic_flags;
  }
   { // 0x4ea66d: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x4ea66e: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x4ea66f: 50 PUSH EAX
    f.push(m,s.ax);
  }
   { // 0x4ea670: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
   { // 0x4ea674: e8b70ff3ff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,5154425u); flags=s.arithmetic_flags;
  }
   { // 0x4ea679: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
   { // 0x4ea67d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea67e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea684: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea686: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea689: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
   { // 0x4ea68e: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
   { // 0x4ea692: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea693: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea699: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea69b: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea69e: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
   { // 0x4ea6a3: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
   { // 0x4ea6a6: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x4ea6aa: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
   { // 0x4ea6ac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x4ea6ad: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4ea6ae: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x4ea6af: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x4ea6b1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x4ea6b2: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004ea6b5: { // 0x4ea6b5: 8b86c8530000 MOV EAX,dword ptr [ESI + 0x53c8]
    s.ax = m.r32((s.si+0x000053c8u));
  }
   { // 0x4ea6bb: 8bbec4530000 MOV EDI,dword ptr [ESI + 0x53c4]
    s.di = m.r32((s.si+0x000053c4u));
  }
   { // 0x4ea6c1: 6889d91240 PUSH 0x4012d989
    f.push(m,0x4012d989u);
  }
   { // 0x4ea6c6: 6822ee4910 PUSH 0x1049ee22
    f.push(m,0x1049ee22u);
  }
   { // 0x4ea6cb: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
   { // 0x4ea6ce: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
   { // 0x4ea6d2: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea6d6: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea6da: db86c0530000 FILD dword ptr [ESI + 0x53c0]
    const auto address=(s.si+0x000053c0u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x4ea6e0: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x4ea6e4: e807fafcff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5154537u); flags=s.arithmetic_flags;
  }
   { // 0x4ea6e9: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea6ed: dc6c2420 FSUBR double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.reverse_subtract64(read64(m,address));
  }
   { // 0x4ea6f1: e85a032800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154550u); flags=s.arithmetic_flags;
  }
   { // 0x4ea6f6: 6889d91240 PUSH 0x4012d989
    f.push(m,0x4012d989u);
  }
   { // 0x4ea6fb: 6822ee4910 PUSH 0x1049ee22
    f.push(m,0x1049ee22u);
  }
   { // 0x4ea700: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
   { // 0x4ea702: e839fafcff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5154567u); flags=s.arithmetic_flags;
  }
   { // 0x4ea707: dc4c2420 FMUL double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x4ea70b: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x4ea70e: da86bc530000 FIADD dword ptr [ESI + 0x53bc]
    const auto address=(s.si+0x000053bcu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
   { // 0x4ea714: e837032800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5154585u); flags=s.arithmetic_flags;
  }
   { // 0x4ea719: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x4ea71a: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x4ea71b: 50 PUSH EAX
    f.push(m,s.ax);
  }
   { // 0x4ea71c: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
   { // 0x4ea720: e80b0ff3ff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,5154597u); flags=s.arithmetic_flags;
  }
   { // 0x4ea725: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
   { // 0x4ea729: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea72a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea730: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea732: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea735: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
   { // 0x4ea73a: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
   { // 0x4ea73e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
   { // 0x4ea73f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
   { // 0x4ea745: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
   { // 0x4ea747: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
   { // 0x4ea74a: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
   { // 0x4ea74f: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
   { // 0x4ea752: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
   { // 0x4ea756: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
   { // 0x4ea758: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x4ea759: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4ea75a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x4ea75b: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x4ea75d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x4ea75e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004ea761: { // 0x4ea761: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
   { // 0x4ea764: 8b155c8ba200 MOV EDX,dword ptr [0x00a28b5c]
    s.dx = m.r32((0x00a28b5cu));
  }
   { // 0x4ea76a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x4ea76b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x4ea76c: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
   { // 0x4ea76e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x4ea76f: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
   { // 0x4ea771: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x4ea772: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0056ade0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x56ade0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
   { // 0x56ade3: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
   { // 0x56ade7: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
   { // 0x56adeb: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x56adec: 0fbf10 MOVSX EDX,word ptr [EAX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
   { // 0x56adef: 0fbf31 MOVSX ESI,word ptr [ECX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
   { // 0x56adf2: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
   { // 0x56adf4: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x56adf7: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
   { // 0x56adfb: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
   { // 0x56adff: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
   { // 0x56ae01: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
   { // 0x56ae03: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
   { // 0x56ae05: 0fafd6 IMUL EDX,ESI
    s.dx = integer::imul(s.dx,s.si,32,flags);
  }
   { // 0x56ae08: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
   { // 0x56ae0b: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
   { // 0x56ae0d: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
   { // 0x56ae11: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
   { // 0x56ae15: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
   { // 0x56ae19: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x56ae1d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x56ae20: e85bf2f4ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5680677u); flags=s.arithmetic_flags;
  }
   { // 0x56ae25: dd5c2414 FSTP double ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x56ae29: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x56ae2c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x56ae2e: 0f84b0000000 JZ 0x0056aee4
    if(integer::condition("JZ",flags)) goto L0056aee4;
  }
   { // 0x56ae34: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x56ae38: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x56ae3b: da74240c FIDIV dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.divide_integer32(m.r32(address));
  }
   { // 0x56ae3f: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
   { // 0x56ae41: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x56ae44: e8d7f3f4ff CALL 0x004ba220
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba220u,5680713u); flags=s.arithmetic_flags;
  }
   { // 0x56ae49: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x56ae4c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x56ae4e: 7d06 JGE 0x0056ae56
    if(integer::condition("JGE",flags)) goto L0056ae56;
  }
   { // 0x56ae50: dc0558817800 FADD double ptr [0x00788158]
    const auto address=(0x00788158u);
    s.fp.add64(read64(m,address));
  }
  L0056ae56: { // 0x56ae56: dc642420 FSUB double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.subtract64(read64(m,address));
  }
   { // 0x56ae5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x56ae5b: d9e1 FABS
    numeric_b88::detail::reg<0xd9e1>(s.fp);
  }
   { // 0x56ae5d: dc15b8797800 FCOM double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x56ae63: dd54241c FST double ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
   { // 0x56ae67: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x56ae69: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x56ae6c: 7517 JNZ 0x0056ae85
    if(integer::condition("JNZ",flags)) goto L0056ae85;
  }
  L0056ae6e: { // 0x56ae6e: dc25b8797800 FSUB double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    s.fp.subtract64(read64(m,address));
  }
   { // 0x56ae74: dc15b8797800 FCOM double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x56ae7a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x56ae7c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x56ae7f: 74ed JZ 0x0056ae6e
    if(integer::condition("JZ",flags)) goto L0056ae6e;
  }
   { // 0x56ae81: dd54241c FST double ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0056ae85: { // 0x56ae85: dc1558817800 FCOM double ptr [0x00788158]
    const auto address=(0x00788158u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x56ae8b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x56ae8d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
   { // 0x56ae90: 750c JNZ 0x0056ae9e
    if(integer::condition("JNZ",flags)) goto L0056ae9e;
  }
   { // 0x56ae92: dd05b8797800 FLD double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    s.fp.load64(read64(m,address));
  }
   { // 0x56ae98: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
   { // 0x56ae9a: dd5c241c FSTP double ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0056ae9e: { // 0x56ae9e: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
   { // 0x56aea3: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x56aea5: e8364f0c00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5680810u); flags=s.arithmetic_flags;
  }
   { // 0x56aeaa: 89442400 MOV dword ptr [ESP],EAX
    m.w32((f.sp), s.ax);
  }
   { // 0x56aeae: c744240400000000 MOV dword ptr [ESP + 0x4],0x0
    m.w32((f.sp+0x00000004u), 0x00000000u);
  }
   { // 0x56aeb6: df6c2400 FILD qword ptr [ESP]
    const auto address=(f.sp);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
   { // 0x56aeba: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x56aec0: dc0dc00b7900 FMUL double ptr [0x00790bc0]
    const auto address=(0x00790bc0u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x56aec6: dd05d00b7900 FLD double ptr [0x00790bd0]
    const auto address=(0x00790bd0u);
    s.fp.load64(read64(m,address));
  }
   { // 0x56aecc: dc4c241c FMUL double ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x56aed0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x56aed2: dd05c80b7900 FLD double ptr [0x00790bc8]
    const auto address=(0x00790bc8u);
    s.fp.load64(read64(m,address));
  }
   { // 0x56aed8: dc4c2408 FMUL double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.multiply64(read64(m,address));
  }
   { // 0x56aedc: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x56aede: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x56aee1: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0056aee4: { // 0x56aee4: dd0530667800 FLD double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.load64(read64(m,address));
  }
   { // 0x56aeea: e967ffffff JMP 0x0056ae56
    goto L0056ae56;
  }

}

std::uint32_t fun_0058cd50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x58cd50: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x58cd53: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cd57: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x58cd58: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x58cd59: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x58cd5d: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
   { // 0x58cd61: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x58cd62: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
   { // 0x58cd66: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x58cd68: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x58cd69: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x58cd6a: e8d1d3f2ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5819759u); flags=s.arithmetic_flags;
  }
   { // 0x58cd6f: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58cd73: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x58cd74: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x58cd75: e876d3f2ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5819770u); flags=s.arithmetic_flags;
  }
   { // 0x58cd7a: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
   { // 0x58cd7e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x58cd81: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
   { // 0x58cd83: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cd85: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
   { // 0x58cd87: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
   { // 0x58cd89: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cd8f: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
   { // 0x58cd91: d84c241c FMUL float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cd95: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x58cd97: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58cd99: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x58cd9b: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cda1: d864241c FSUB float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.subtract32(m.r32(address));
  }
   { // 0x58cda5: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cda7: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdaa: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x58cdac: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
   { // 0x58cdae: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdb1: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
   { // 0x58cdb3: d95e04 FSTP float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58cdb6: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cdb9: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdbb: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x58cdbd: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
   { // 0x58cdbf: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdc2: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
   { // 0x58cdc5: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58cdc7: d95e08 FSTP float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58cdca: d900 FLD float ptr [EAX]
    const auto address=(s.ax);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cdcc: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdcf: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x58cdd1: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
   { // 0x58cdd3: d84808 FMUL float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdd6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58cdd8: d95e10 FSTP float ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58cddb: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cdde: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
   { // 0x58cde0: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
   { // 0x58cde2: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cde8: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
   { // 0x58cdea: d84c241c FMUL float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdee: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x58cdf0: d95e14 FSTP float ptr [ESI + 0x14]
    const auto address=(s.si+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58cdf3: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x58cdf5: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58cdf8: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58cdfb: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x58cdfd: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
   { // 0x58cdff: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58ce01: 894e1c MOV dword ptr [ESI + 0x1c],ECX
    m.w32((s.si+0x0000001cu), s.cx);
  }
   { // 0x58ce04: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
   { // 0x58ce06: d95e18 FSTP float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58ce09: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58ce0c: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58ce0e: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x58ce10: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
   { // 0x58ce12: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58ce15: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
   { // 0x58ce17: d95e20 FSTP float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58ce1a: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58ce1d: d84804 FMUL float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58ce20: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x58ce22: d9ca FXCH ST2
    numeric_b88::detail::reg<0xd9ca>(s.fp);
  }
   { // 0x58ce24: d808 FMUL float ptr [EAX]
    const auto address=(s.ax);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58ce26: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x58ce27: dec2 FADDP ST2,ST0
    numeric_b88::detail::reg<0xdec2>(s.fp);
  }
   { // 0x58ce29: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
   { // 0x58ce2b: d95e24 FSTP float ptr [ESI + 0x24]
    const auto address=(s.si+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58ce2e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x58ce30: d94008 FLD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58ce33: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
   { // 0x58ce35: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
   { // 0x58ce37: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58ce3d: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
   { // 0x58ce3f: 894e2c MOV dword ptr [ESI + 0x2c],ECX
    m.w32((s.si+0x0000002cu), s.cx);
  }
   { // 0x58ce42: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
   { // 0x58ce44: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58ce48: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x58ce4a: d95e28 FSTP float ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58ce4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x58ce4e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x58ce4f: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x58ce51: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x58ce54: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0058d680(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x58d680: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x58d683: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
   { // 0x58d687: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x58d688: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x58d689: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x58d68d: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
   { // 0x58d691: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x58d692: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
   { // 0x58d696: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x58d698: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x58d699: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x58d69a: e851caf2ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,5822111u); flags=s.arithmetic_flags;
  }
   { // 0x58d69f: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58d6a3: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x58d6a4: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x58d6a5: e896caf2ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,5822122u); flags=s.arithmetic_flags;
  }
   { // 0x58d6aa: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
   { // 0x58d6ac: d94608 FLD float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58d6af: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x58d6b1: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
   { // 0x58d6b3: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x58d6b5: d84c2428 FMUL float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58d6b9: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x58d6bc: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
   { // 0x58d6be: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x58d6bf: d91e FSTP float ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58d6c1: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
   { // 0x58d6c3: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
   { // 0x58d6c5: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58d6c9: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58d6cb: d95e08 FSTP float ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58d6ce: d94610 FLD float ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58d6d1: d94618 FLD float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58d6d4: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x58d6d6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
   { // 0x58d6d8: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x58d6da: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58d6de: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
   { // 0x58d6e0: d95e10 FSTP float ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58d6e3: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
   { // 0x58d6e5: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
   { // 0x58d6e7: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58d6eb: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58d6ed: d95e18 FSTP float ptr [ESI + 0x18]
    const auto address=(s.si+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58d6f0: d94620 FLD float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58d6f3: d94628 FLD float ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    s.fp.load32(m.r32(address));
  }
   { // 0x58d6f6: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x58d6f8: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
   { // 0x58d6fa: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x58d6fc: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58d700: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
   { // 0x58d702: d95e20 FSTP float ptr [ESI + 0x20]
    const auto address=(s.si+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58d705: d8ca FMUL ST2
    numeric_b88::detail::reg<0xd8ca>(s.fp);
  }
   { // 0x58d707: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
   { // 0x58d709: d84c2414 FMUL float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x58d70d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x58d70f: d95e28 FSTP float ptr [ESI + 0x28]
    const auto address=(s.si+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x58d712: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x58d713: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x58d714: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x58d716: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x58d719: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0061a540(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x61a540: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
   { // 0x61a543: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x61a544: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
   { // 0x61a547: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x61a548: 8b6a08 MOV EBP,dword ptr [EDX + 0x8]
    s.bp = m.r32((s.dx+0x00000008u));
  }
   { // 0x61a54b: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
   { // 0x61a54f: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
   { // 0x61a553: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a557: d84c2410 FMUL float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x61a55b: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a55f: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x61a563: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x61a564: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x61a565: 8b3a MOV EDI,dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
   { // 0x61a567: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x61a56a: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x61a56c: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
   { // 0x61a570: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
   { // 0x61a572: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a576: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x61a57a: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x61a57c: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x61a57f: e8fcfae9ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6399364u); flags=s.arithmetic_flags;
  }
   { // 0x61a584: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x61a58a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x61a58d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x61a58f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
   { // 0x61a592: 7536 JNZ 0x0061a5ca
    if(integer::condition("JNZ",flags)) goto L0061a5ca;
  }
   { // 0x61a594: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a598: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
   { // 0x61a59a: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x61a59e: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a5a2: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
   { // 0x61a5a4: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
   { // 0x61a5a8: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
   { // 0x61a5ac: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x61a5b0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
   { // 0x61a5b4: d87c2418 FDIVR float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    reverse_divide32(s.fp,m.r32(address));
  }
   { // 0x61a5b8: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
   { // 0x61a5bc: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x61a5c0: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
   { // 0x61a5c4: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
   { // 0x61a5c8: eb0e JMP 0x0061a5d8
    goto L0061a5d8;
  }
  L0061a5ca: { // 0x61a5ca: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x61a5cc: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
   { // 0x61a5d0: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
   { // 0x61a5d4: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0061a5d8: { // 0x61a5d8: d944243c FLD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a5dc: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x61a5e2: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x61a5e6: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
   { // 0x61a5ea: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
   { // 0x61a5ee: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x61a5ef: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x61a5f0: e8fbfae9ff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,6399477u); flags=s.arithmetic_flags;
  }
   { // 0x61a5f5: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a5f9: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x61a5fb: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x61a5fc: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x61a5fd: d95c2438 FSTP float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x61a601: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a605: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x61a607: d95c243c FSTP float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x61a60b: d9442434 FLD float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load32(m.r32(address));
  }
   { // 0x61a60f: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
   { // 0x61a611: d95c2440 FSTP float ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x61a615: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x61a617: e824fbe9ff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,6399516u); flags=s.arithmetic_flags;
  }
   { // 0x61a61c: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
   { // 0x61a620: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
   { // 0x61a624: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
   { // 0x61a626: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x61a629: d95c2434 FSTP float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x61a62d: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
   { // 0x61a62f: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
   { // 0x61a633: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x61a634: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x61a635: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
   { // 0x61a638: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
   { // 0x61a63c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x61a63d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x61a63e: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
   { // 0x61a641: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
   { // 0x61a644: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
   { // 0x61a647: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00710660(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x710660: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
   { // 0x710663: 53 PUSH EBX
    f.push(m,s.bx);
  }
   { // 0x710664: 55 PUSH EBP
    f.push(m,s.bp);
  }
   { // 0x710665: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
   { // 0x710667: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
   { // 0x71066b: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x71066c: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x71066d: d94500 FLD float ptr [EBP]
    const auto address=(s.bp);
    s.fp.load32(m.r32(address));
  }
   { // 0x710670: d802 FADD float ptr [EDX]
    const auto address=(s.dx);
    s.fp.add32(m.r32(address));
  }
   { // 0x710672: 8b349de8377e00 MOV ESI,dword ptr [EBX*0x4 + 0x7e37e8]
    s.si = m.r32(((s.bx * 0x00000004u)+0x007e37e8u));
  }
   { // 0x710679: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
   { // 0x71067c: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x710680: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
   { // 0x710683: d84504 FADD float ptr [EBP + 0x4]
    const auto address=(s.bp+0x00000004u);
    s.fp.add32(m.r32(address));
  }
   { // 0x710686: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x71068a: d94208 FLD float ptr [EDX + 0x8]
    const auto address=(s.dx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
   { // 0x71068d: d84508 FADD float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.add32(m.r32(address));
  }
   { // 0x710690: d9542420 FST float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
   { // 0x710694: d84c2420 FMUL float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x710698: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
   { // 0x71069c: d84c2418 FMUL float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x7106a0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x7106a2: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
   { // 0x7106a6: d84c241c FMUL float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x7106aa: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x7106ac: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x7106af: e8cc99daff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,7407284u); flags=s.arithmetic_flags;
  }
   { // 0x7106b4: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x7106ba: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
   { // 0x7106bd: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x7106bf: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
   { // 0x7106c2: 7532 JNZ 0x007106f6
    if(integer::condition("JNZ",flags)) goto L007106f6;
  }
   { // 0x7106c4: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
   { // 0x7106c8: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
   { // 0x7106ca: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x7106ce: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
   { // 0x7106d2: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
   { // 0x7106d4: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
   { // 0x7106d8: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
   { // 0x7106dc: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x7106e0: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
   { // 0x7106e4: d87c2418 FDIVR float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    reverse_divide32(s.fp,m.r32(address));
  }
   { // 0x7106e8: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
   { // 0x7106ec: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x7106f0: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
   { // 0x7106f4: eb16 JMP 0x0071070c
    goto L0071070c;
  }
  L007106f6: { // 0x7106f6: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
   { // 0x7106fa: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
   { // 0x7106fe: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
   { // 0x710702: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
   { // 0x710706: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x710708: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0071070c: { // 0x71070c: 8b1c9dfc377e00 MOV EBX,dword ptr [EBX*0x4 + 0x7e37fc]
    s.bx = m.r32(((s.bx * 0x00000004u)+0x007e37fcu));
  }
   { // 0x710713: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
   { // 0x710715: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
   { // 0x710717: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
   { // 0x71071b: 0f8eab000000 JLE 0x007107cc
    if(integer::condition("JLE",flags)) goto L007107cc;
  }
   { // 0x710721: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L00710724: { // 0x710724: d94604 FLD float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.load32(m.r32(address));
  }
   { // 0x710727: d84d08 FMUL float ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x71072a: d906 FLD float ptr [ESI]
    const auto address=(s.si);
    s.fp.load32(m.r32(address));
  }
   { // 0x71072c: d84d04 FMUL float ptr [EBP + 0x4]
    const auto address=(s.bp+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x71072f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x710731: d946fc FLD float ptr [ESI + -0x4]
    const auto address=(s.si-0x00000004u);
    s.fp.load32(m.r32(address));
  }
   { // 0x710734: d84d00 FMUL float ptr [EBP]
    const auto address=(s.bp);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x710737: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x710739: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
   { // 0x71073d: d84efc FMUL float ptr [ESI + -0x4]
    const auto address=(s.si-0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x710740: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
   { // 0x710744: d80e FMUL float ptr [ESI]
    const auto address=(s.si);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x710746: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x710748: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
   { // 0x71074c: d84e04 FMUL float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x71074f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
   { // 0x710751: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
   { // 0x710753: d84c2438 FMUL float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x710757: d86c2438 FSUBR float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    ra2::platform::x87_b61::reverse_subtract32(s.fp,m.r32(address));
  }
   { // 0x71075b: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
   { // 0x71075d: d8f9 FDIVR ST0,ST1
    numeric_b88::detail::reg<0xd8f9>(s.fp);
  }
   { // 0x71075f: d95c243c FSTP float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
   { // 0x710763: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x710765: d944243c FLD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load32(m.r32(address));
  }
   { // 0x710769: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
   { // 0x71076f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x710771: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x710774: 7408 JZ 0x0071077e
    if(integer::condition("JZ",flags)) goto L0071077e;
  }
   { // 0x710776: c744243c00000000 MOV dword ptr [ESP + 0x3c],0x0
    m.w32((f.sp+0x0000003cu), 0x00000000u);
  }
  L0071077e: { // 0x71077e: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
   { // 0x710784: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x710786: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x710789: 7408 JZ 0x00710793
    if(integer::condition("JZ",flags)) goto L00710793;
  }
   { // 0x71078b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x71078d: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L00710793: { // 0x710793: d844243c FADD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.add32(m.r32(address));
  }
   { // 0x710797: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
   { // 0x71079d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x71079f: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x7107a2: 740b JZ 0x007107af
    if(integer::condition("JZ",flags)) goto L007107af;
  }
   { // 0x7107a4: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x7107a6: c6879008ae0000 MOV byte ptr [EDI + 0xae0890],0x0
    m.w8((s.di+0x00ae0890u), 0x00000000u);
  }
   { // 0x7107ad: eb11 JMP 0x007107c0
    goto L007107c0;
  }
  L007107af: { // 0x7107af: d80dd0987900 FMUL float ptr [0x007998d0]
    const auto address=(0x007998d0u);
    s.fp.multiply32(m.r32(address));
  }
   { // 0x7107b5: e896a20500 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7407546u); flags=s.arithmetic_flags;
  }
   { // 0x7107ba: 88879008ae00 MOV byte ptr [EDI + 0xae0890],AL
    m.w8((s.di+0x00ae0890u), (s.ax & 0xffu));
  }
  L007107c0: { // 0x7107c0: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
   { // 0x7107c1: 83c60c ADD ESI,0xc
    s.si = integer::add(s.si,0x0000000cu,32,flags);
  }
   { // 0x7107c4: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
   { // 0x7107c6: 0f8c58ffffff JL 0x00710724
    if(integer::condition("JL",flags)) goto L00710724;
  }
  L007107cc: { // 0x7107cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x7107cd: b010 MOV AL,0x10
    s.ax = with_al(s.ax, 0x00000010u);
  }
   { // 0x7107cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x7107d0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
   { // 0x7107d1: a28f09ae00 MOV [0x00ae098f],AL
    m.w8((0x00ae098fu), (s.ax & 0xffu));
  }
   { // 0x7107d6: a28e09ae00 MOV [0x00ae098e],AL
    m.w8((0x00ae098eu), (s.ax & 0xffu));
  }
   { // 0x7107db: a28d09ae00 MOV [0x00ae098d],AL
    m.w8((0x00ae098du), (s.ax & 0xffu));
  }
   { // 0x7107e0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
   { // 0x7107e1: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
   { // 0x7107e4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00716970(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
   { // 0x716970: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
   { // 0x716973: 56 PUSH ESI
    f.push(m,s.si);
  }
   { // 0x716974: 8b32 MOV ESI,dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
   { // 0x716976: 57 PUSH EDI
    f.push(m,s.di);
  }
   { // 0x716977: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
   { // 0x716979: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
   { // 0x71697b: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
   { // 0x71697e: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
   { // 0x716981: 68fb21d93f PUSH 0x3fd921fb
    f.push(m,0x3fd921fbu);
  }
   { // 0x716986: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
   { // 0x716988: 68182d4454 PUSH 0x54442d18
    f.push(m,0x54442d18u);
  }
   { // 0x71698d: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
   { // 0x716991: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
   { // 0x716995: e85637daff CALL 0x004ba0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba0f0u,7432602u); flags=s.arithmetic_flags;
  }
   { // 0x71699a: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
   { // 0x71699e: 68fb21d93f PUSH 0x3fd921fb
    f.push(m,0x3fd921fbu);
  }
   { // 0x7169a3: 68182d4454 PUSH 0x54442d18
    f.push(m,0x54442d18u);
  }
   { // 0x7169a8: e89337daff CALL 0x004ba140
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba140u,7432621u); flags=s.arithmetic_flags;
  }
   { // 0x7169ad: dc7c2420 FDIVR double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    reverse_divide64(s.fp,read64(m,address));
  }
   { // 0x7169b1: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x7169b4: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x7169b6: 0f849f000000 JZ 0x00716a5b
    if(integer::condition("JZ",flags)) goto L00716a5b;
  }
   { // 0x7169bc: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
   { // 0x7169c0: da74240c FIDIV dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.divide_integer32(m.r32(address));
  }
   { // 0x7169c4: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
   { // 0x7169ca: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
   { // 0x7169cc: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x7169ce: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
   { // 0x7169d0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x7169d2: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
   { // 0x7169d4: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x7169d7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x7169d9: 741c JZ 0x007169f7
    if(integer::condition("JZ",flags)) goto L007169f7;
  }
   { // 0x7169db: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x7169de: 751c JNZ 0x007169fc
    if(integer::condition("JNZ",flags)) goto L007169fc;
  }
   { // 0x7169e0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x7169e2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x7169e3: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x7169e5: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
   { // 0x7169e8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x7169e9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x7169ea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x7169ec: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
   { // 0x7169ee: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x7169f0: 83c005 ADD EAX,0x5
    s.ax = integer::add(s.ax,0x00000005u,32,flags);
  }
   { // 0x7169f3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x7169f6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L007169f7: { // 0x7169f7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x7169fa: 7426 JZ 0x00716a22
    if(integer::condition("JZ",flags)) goto L00716a22;
  }
  L007169fc: { // 0x7169fc: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x7169fe: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
   { // 0x716a00: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x716a02: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
   { // 0x716a04: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x716a06: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x716a09: 7517 JNZ 0x00716a22
    if(integer::condition("JNZ",flags)) goto L00716a22;
  }
   { // 0x716a0b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x716a0d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x716a0e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x716a10: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
   { // 0x716a13: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x716a14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x716a15: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x716a17: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
   { // 0x716a19: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x716a1b: 83c006 ADD EAX,0x6
    s.ax = integer::add(s.ax,0x00000006u,32,flags);
  }
   { // 0x716a1e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x716a21: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00716a22: { // 0x716a22: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x716a24: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
   { // 0x716a26: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
   { // 0x716a28: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
   { // 0x716a2a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x716a2c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x716a2f: 7428 JZ 0x00716a59
    if(integer::condition("JZ",flags)) goto L00716a59;
  }
   { // 0x716a31: dd0578857800 FLD double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.load64(read64(m,address));
  }
   { // 0x716a37: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
   { // 0x716a39: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
   { // 0x716a3b: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
   { // 0x716a3d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
   { // 0x716a3f: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
   { // 0x716a42: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
   { // 0x716a44: 7517 JNZ 0x00716a5d
    if(integer::condition("JNZ",flags)) goto L00716a5d;
  }
   { // 0x716a46: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x716a48: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x716a49: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
   { // 0x716a4b: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
   { // 0x716a4e: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x716a4f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x716a50: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
   { // 0x716a52: 83c007 ADD EAX,0x7
    s.ax = integer::add(s.ax,0x00000007u,32,flags);
  }
   { // 0x716a55: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x716a58: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00716a59: { // 0x716a59: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00716a5b: { // 0x716a5b: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00716a5d: { // 0x716a5d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
   { // 0x716a5f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
   { // 0x716a61: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
   { // 0x716a64: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
   { // 0x716a65: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
   { // 0x716a66: 24fc AND AL,0xfc
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fcu),8,flags));
  }
   { // 0x716a68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
   { // 0x716a69: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
   { // 0x716a6c: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
   { // 0x716a6f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
