#include "recovered/recovery_b810_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b810 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b650(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0007caa0(Memory&,State&,Frame&,const Operations&);
void f_0007cac0(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0007cb10(Memory&,State&,Frame&,const Operations&);
void f_000bb760(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX, word ptr [EDX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+2u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI, word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX, dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007b650(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b650: { // 0x47b650: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L0047b653: { // 0x47b653: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047b654: { // 0x47b654: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047b655: { // 0x47b655: 0fbf7124 MOVSX ESI, word ptr [ECX + 0x24]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000024u)),16));
  }
  L0047b659: { // 0x47b659: 0fbf7926 MOVSX EDI, word ptr [ECX + 0x26]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000026u)),16));
  }
  L0047b65d: { // 0x47b65d: c1e608 SHL ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::left);
  }
  L0047b660: { // 0x47b660: c1e708 SHL EDI, 8
    s.di = integer::shift(s.di,8u,32,flags,integer::Shift::left);
  }
  L0047b663: { // 0x47b663: 8d442408 LEA EAX, [ESP + 8]
    s.ax = (f.sp+8u);
  }
  L0047b667: { // 0x47b667: 81c680000000 ADD ESI, 0x80
    s.si = integer::add(s.si,0x00000080u,32,flags);
  }
  L0047b66d: { // 0x47b66d: 81c780000000 ADD EDI, 0x80
    s.di = integer::add(s.di,0x00000080u,32,flags);
  }
  L0047b673: { // 0x47b673: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047b674: { // 0x47b674: 8974240c MOV dword ptr [ESP + 0xc], ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0047b678: { // 0x47b678: 897c2410 MOV dword ptr [ESP + 0x10], EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0047b67c: { // 0x47b67c: e83f4cffff CALL 0x4702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,4699777u); flags=s.arithmetic_flags;
  }
  L0047b681: { // 0x47b681: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0047b685: { // 0x47b685: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0047b687: { // 0x47b687: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L0047b689: { // 0x47b689: 897a04 MOV dword ptr [EDX + 4], EDI
    m.w32((s.dx+4u), s.di);
  }
  L0047b68c: { // 0x47b68c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047b68d: { // 0x47b68d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047b68e: { // 0x47b68e: 894208 MOV dword ptr [EDX + 8], EAX
    m.w32((s.dx+8u), s.ax);
  }
  L0047b691: { // 0x47b691: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047b693: { // 0x47b693: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L0047b696: { // 0x47b696: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD qword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x4ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM dword ptr [0x785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x4ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL qword ptr [0x788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX, 0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX, 0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX, 0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x4ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX, 0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX, 1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),1u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX, 0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX, 0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX, dword ptr [ECX*4 + 0x80013c]
    s.cx = m.r32(((s.cx * 4u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX, 0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 4], ECX
    m.w32((f.sp+4u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load32(m.r32(address));
  }
  L004ba0ed: { // 0x4ba0ed: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX, dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX, 0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX, dword ptr [0x7c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x76aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX, dword ptr [0x7c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP], EDX
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
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0007caa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047caa0: { // 0x47caa0: dd442404 FLD qword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load64(read64(m,address));
  }
  L0047caa4: { // 0x47caa4: dc81f0000000 FADD qword ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    s.fp.add64(read64(m,address));
  }
  L0047caaa: { // 0x47caaa: dd99f0000000 FSTP qword ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047cab0: { // 0x47cab0: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0007cac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047cac0: { // 0x47cac0: dd81f0000000 FLD qword ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    s.fp.load64(read64(m,address));
  }
  L0047cac6: { // 0x47cac6: dc642404 FSUB qword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.subtract64(read64(m,address));
  }
  L0047caca: { // 0x47caca: dd91f0000000 FST qword ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047cad0: { // 0x47cad0: dd0510667800 FLD qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L0047cad6: { // 0x47cad6: d8d9 FCOMP st(1)
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L0047cad8: { // 0x47cad8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0047cada: { // 0x47cada: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0047cadd: { // 0x47cadd: 7519 JNZ 0x47caf8
    if(integer::condition("JNZ",flags)) goto L0047caf8;
  }
  L0047cadf: { // 0x47cadf: c781f000000000000000 MOV dword ptr [ECX + 0xf0], 0
    m.w32((s.cx+0x000000f0u), 0u);
  }
  L0047cae9: { // 0x47cae9: c781f400000000000000 MOV dword ptr [ECX + 0xf4], 0
    m.w32((s.cx+0x000000f4u), 0u);
  }
  L0047caf3: { // 0x47caf3: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0047caf5: { // 0x47caf5: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0047caf8: { // 0x47caf8: dd99f0000000 FSTP qword ptr [ECX + 0xf0]
    const auto address=(s.cx+0x000000f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047cafe: { // 0x47cafe: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000702c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004702c0: { // 0x4702c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004702c1: { // 0x4702c1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L004702c3: { // 0x4702c3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004702c6: { // 0x4702c6: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004702c9: { // 0x4702c9: a0708f8300 MOV AL,[0x00838f70]
    s.ax = with_al(s.ax, m.r8((0x00838f70u)));
  }
  L004702ce: { // 0x4702ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004702cf: { // 0x4702cf: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004702d1: { // 0x4702d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004702d3: { // 0x4702d3: 7513 JNZ 0x004702e8
    if(integer::condition("JNZ",flags)) goto L004702e8;
  }
  L004702d5: { // 0x4702d5: db05808f8300 FILD dword ptr [0x00838f80]
    const auto address=(0x00838f80u);
    s.fp.load_integer32(m.r32(address));
  }
  L004702db: { // 0x4702db: 0c01 OR AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000001u),8,flags));
  }
  L004702dd: { // 0x4702dd: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702e2: { // 0x4702e2: dd1df08e8300 FSTP double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004702e8: { // 0x4702e8: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L004702ea: { // 0x4702ea: 7519 JNZ 0x00470305
    if(integer::condition("JNZ",flags)) goto L00470305;
  }
  L004702ec: { // 0x4702ec: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004702f2: { // 0x4702f2: dc0d30577800 FMUL double ptr [0x00785730]
    const auto address=(0x00785730u);
    s.fp.multiply64(read64(m,address));
  }
  L004702f8: { // 0x4702f8: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L004702fa: { // 0x4702fa: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702ff: { // 0x4702ff: dd1d108f8300 FSTP double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00470305: { // 0x470305: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L00470307: { // 0x470307: 0f85a7060000 JNZ 0x004709b4
    if(integer::condition("JNZ",flags)) goto L004709b4;
  }
  L0047030d: { // 0x47030d: 8b0df48e8300 MOV ECX,dword ptr [0x00838ef4]
    s.cx = m.r32((0x00838ef4u));
  }
  L00470313: { // 0x470313: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L00470315: { // 0x470315: a2708f8300 MOV [0x00838f70],AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L0047031a: { // 0x47031a: a1f08e8300 MOV EAX,[0x00838ef0]
    s.ax = m.r32((0x00838ef0u));
  }
  L0047031f: { // 0x47031f: a398d77b00 MOV [0x007bd798],EAX
    m.w32((0x007bd798u), s.ax);
  }
  L00470324: { // 0x470324: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470326: { // 0x470326: 890d9cd77b00 MOV dword ptr [0x007bd79c],ECX
    m.w32((0x007bd79cu), s.cx);
  }
  L0047032c: { // 0x47032c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047032e: { // 0x47032e: 8915c0d77b00 MOV dword ptr [0x007bd7c0],EDX
    m.w32((0x007bd7c0u), s.dx);
  }
  L00470334: { // 0x470334: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470336: { // 0x470336: a3c4d77b00 MOV [0x007bd7c4],EAX
    m.w32((0x007bd7c4u), s.ax);
  }
  L0047033b: { // 0x47033b: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047033d: { // 0x47033d: 890de0d77b00 MOV dword ptr [0x007bd7e0],ECX
    m.w32((0x007bd7e0u), s.cx);
  }
  L00470343: { // 0x470343: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470345: { // 0x470345: 8915e4d77b00 MOV dword ptr [0x007bd7e4],EDX
    m.w32((0x007bd7e4u), s.dx);
  }
  L0047034b: { // 0x47034b: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047034d: { // 0x47034d: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470353: { // 0x470353: a3e8d77b00 MOV [0x007bd7e8],EAX
    m.w32((0x007bd7e8u), s.ax);
  }
  L00470358: { // 0x470358: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047035a: { // 0x47035a: 890decd77b00 MOV dword ptr [0x007bd7ec],ECX
    m.w32((0x007bd7ecu), s.cx);
  }
  L00470360: { // 0x470360: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470362: { // 0x470362: 891508d87b00 MOV dword ptr [0x007bd808],EDX
    m.w32((0x007bd808u), s.dx);
  }
  L00470368: { // 0x470368: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047036a: { // 0x47036a: a30cd87b00 MOV [0x007bd80c],EAX
    m.w32((0x007bd80cu), s.ax);
  }
  L0047036f: { // 0x47036f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470371: { // 0x470371: 890d10d87b00 MOV dword ptr [0x007bd810],ECX
    m.w32((0x007bd810u), s.cx);
  }
  L00470377: { // 0x470377: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470379: { // 0x470379: 891514d87b00 MOV dword ptr [0x007bd814],EDX
    m.w32((0x007bd814u), s.dx);
  }
  L0047037f: { // 0x47037f: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470381: { // 0x470381: a338d87b00 MOV [0x007bd838],EAX
    m.w32((0x007bd838u), s.ax);
  }
  L00470386: { // 0x470386: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470388: { // 0x470388: 890d3cd87b00 MOV dword ptr [0x007bd83c],ECX
    m.w32((0x007bd83cu), s.cx);
  }
  L0047038e: { // 0x47038e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470390: { // 0x470390: 891560d87b00 MOV dword ptr [0x007bd860],EDX
    m.w32((0x007bd860u), s.dx);
  }
  L00470396: { // 0x470396: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470398: { // 0x470398: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0047039a: { // 0x47039a: dd1d30d87b00 FSTP double ptr [0x007bd830]
    const auto address=(0x007bd830u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004703a0: { // 0x4703a0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004703a2: { // 0x4703a2: c705a0d77b0000000000 MOV dword ptr [0x007bd7a0],0x0
    m.w32((0x007bd7a0u), 0x00000000u);
  }
  L004703ac: { // 0x4703ac: c705a4d77b0000000000 MOV dword ptr [0x007bd7a4],0x0
    m.w32((0x007bd7a4u), 0x00000000u);
  }
  L004703b6: { // 0x4703b6: c705a8d77b0000000000 MOV dword ptr [0x007bd7a8],0x0
    m.w32((0x007bd7a8u), 0x00000000u);
  }
  L004703c0: { // 0x4703c0: c705acd77b0000000000 MOV dword ptr [0x007bd7ac],0x0
    m.w32((0x007bd7acu), 0x00000000u);
  }
  L004703ca: { // 0x4703ca: c705b0d77b0000000000 MOV dword ptr [0x007bd7b0],0x0
    m.w32((0x007bd7b0u), 0x00000000u);
  }
  L004703d4: { // 0x4703d4: c705b4d77b000000f03f MOV dword ptr [0x007bd7b4],0x3ff00000
    m.w32((0x007bd7b4u), 0x3ff00000u);
  }
  L004703de: { // 0x4703de: c705b8d77b0000000000 MOV dword ptr [0x007bd7b8],0x0
    m.w32((0x007bd7b8u), 0x00000000u);
  }
  L004703e8: { // 0x4703e8: c705bcd77b0000000000 MOV dword ptr [0x007bd7bc],0x0
    m.w32((0x007bd7bcu), 0x00000000u);
  }
  L004703f2: { // 0x4703f2: c705c8d77b0000000000 MOV dword ptr [0x007bd7c8],0x0
    m.w32((0x007bd7c8u), 0x00000000u);
  }
  L004703fc: { // 0x4703fc: c705ccd77b0000000000 MOV dword ptr [0x007bd7cc],0x0
    m.w32((0x007bd7ccu), 0x00000000u);
  }
  L00470406: { // 0x470406: c705d0d77b0000000000 MOV dword ptr [0x007bd7d0],0x0
    m.w32((0x007bd7d0u), 0x00000000u);
  }
  L00470410: { // 0x470410: c705d4d77b000000f0bf MOV dword ptr [0x007bd7d4],0xbff00000
    m.w32((0x007bd7d4u), 0xbff00000u);
  }
  L0047041a: { // 0x47041a: c705d8d77b0000000000 MOV dword ptr [0x007bd7d8],0x0
    m.w32((0x007bd7d8u), 0x00000000u);
  }
  L00470424: { // 0x470424: c705dcd77b0000000000 MOV dword ptr [0x007bd7dc],0x0
    m.w32((0x007bd7dcu), 0x00000000u);
  }
  L0047042e: { // 0x47042e: c705f0d77b0000000000 MOV dword ptr [0x007bd7f0],0x0
    m.w32((0x007bd7f0u), 0x00000000u);
  }
  L00470438: { // 0x470438: c705f4d77b0000000000 MOV dword ptr [0x007bd7f4],0x0
    m.w32((0x007bd7f4u), 0x00000000u);
  }
  L00470442: { // 0x470442: c705f8d77b0000000000 MOV dword ptr [0x007bd7f8],0x0
    m.w32((0x007bd7f8u), 0x00000000u);
  }
  L0047044c: { // 0x47044c: c705fcd77b0000000000 MOV dword ptr [0x007bd7fc],0x0
    m.w32((0x007bd7fcu), 0x00000000u);
  }
  L00470456: { // 0x470456: c70500d87b0000000000 MOV dword ptr [0x007bd800],0x0
    m.w32((0x007bd800u), 0x00000000u);
  }
  L00470460: { // 0x470460: c70504d87b000000f0bf MOV dword ptr [0x007bd804],0xbff00000
    m.w32((0x007bd804u), 0xbff00000u);
  }
  L0047046a: { // 0x47046a: c70518d87b0000000000 MOV dword ptr [0x007bd818],0x0
    m.w32((0x007bd818u), 0x00000000u);
  }
  L00470474: { // 0x470474: c7051cd87b0000000000 MOV dword ptr [0x007bd81c],0x0
    m.w32((0x007bd81cu), 0x00000000u);
  }
  L0047047e: { // 0x47047e: c70520d87b0000000000 MOV dword ptr [0x007bd820],0x0
    m.w32((0x007bd820u), 0x00000000u);
  }
  L00470488: { // 0x470488: c70524d87b000000f03f MOV dword ptr [0x007bd824],0x3ff00000
    m.w32((0x007bd824u), 0x3ff00000u);
  }
  L00470492: { // 0x470492: c70528d87b0000000000 MOV dword ptr [0x007bd828],0x0
    m.w32((0x007bd828u), 0x00000000u);
  }
  L0047049c: { // 0x47049c: c7052cd87b000000f03f MOV dword ptr [0x007bd82c],0x3ff00000
    m.w32((0x007bd82cu), 0x3ff00000u);
  }
  L004704a6: { // 0x4704a6: c70540d87b0000000000 MOV dword ptr [0x007bd840],0x0
    m.w32((0x007bd840u), 0x00000000u);
  }
  L004704b0: { // 0x4704b0: c70544d87b0000000000 MOV dword ptr [0x007bd844],0x0
    m.w32((0x007bd844u), 0x00000000u);
  }
  L004704ba: { // 0x4704ba: c70548d87b0000000000 MOV dword ptr [0x007bd848],0x0
    m.w32((0x007bd848u), 0x00000000u);
  }
  L004704c4: { // 0x4704c4: c7054cd87b000000f0bf MOV dword ptr [0x007bd84c],0xbff00000
    m.w32((0x007bd84cu), 0xbff00000u);
  }
  L004704ce: { // 0x4704ce: c70550d87b0000000000 MOV dword ptr [0x007bd850],0x0
    m.w32((0x007bd850u), 0x00000000u);
  }
  L004704d8: { // 0x4704d8: c70554d87b000000f03f MOV dword ptr [0x007bd854],0x3ff00000
    m.w32((0x007bd854u), 0x3ff00000u);
  }
  L004704e2: { // 0x4704e2: c70558d87b0000000000 MOV dword ptr [0x007bd858],0x0
    m.w32((0x007bd858u), 0x00000000u);
  }
  L004704ec: { // 0x4704ec: c7055cd87b0000000000 MOV dword ptr [0x007bd85c],0x0
    m.w32((0x007bd85cu), 0x00000000u);
  }
  L004704f6: { // 0x4704f6: a364d87b00 MOV [0x007bd864],EAX
    m.w32((0x007bd864u), s.ax);
  }
  L004704fb: { // 0x4704fb: c70568d87b0000000000 MOV dword ptr [0x007bd868],0x0
    m.w32((0x007bd868u), 0x00000000u);
  }
  L00470505: { // 0x470505: c7056cd87b0000000000 MOV dword ptr [0x007bd86c],0x0
    m.w32((0x007bd86cu), 0x00000000u);
  }
  L0047050f: { // 0x47050f: c70570d87b0000000000 MOV dword ptr [0x007bd870],0x0
    m.w32((0x007bd870u), 0x00000000u);
  }
  L00470519: { // 0x470519: c70574d87b000000f0bf MOV dword ptr [0x007bd874],0xbff00000
    m.w32((0x007bd874u), 0xbff00000u);
  }
  L00470523: { // 0x470523: c70578d87b0000000000 MOV dword ptr [0x007bd878],0x0
    m.w32((0x007bd878u), 0x00000000u);
  }
  L0047052d: { // 0x47052d: c7057cd87b000000f0bf MOV dword ptr [0x007bd87c],0xbff00000
    m.w32((0x007bd87cu), 0xbff00000u);
  }
  L00470537: { // 0x470537: 890d80d87b00 MOV dword ptr [0x007bd880],ECX
    m.w32((0x007bd880u), s.cx);
  }
  L0047053d: { // 0x47053d: 891584d87b00 MOV dword ptr [0x007bd884],EDX
    m.w32((0x007bd884u), s.dx);
  }
  L00470543: { // 0x470543: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470545: { // 0x470545: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470547: { // 0x470547: a388d87b00 MOV [0x007bd888],EAX
    m.w32((0x007bd888u), s.ax);
  }
  L0047054c: { // 0x47054c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047054e: { // 0x47054e: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470554: { // 0x470554: 890d8cd87b00 MOV dword ptr [0x007bd88c],ECX
    m.w32((0x007bd88cu), s.cx);
  }
  L0047055a: { // 0x47055a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047055c: { // 0x47055c: 8915b0d87b00 MOV dword ptr [0x007bd8b0],EDX
    m.w32((0x007bd8b0u), s.dx);
  }
  L00470562: { // 0x470562: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470564: { // 0x470564: a3b4d87b00 MOV [0x007bd8b4],EAX
    m.w32((0x007bd8b4u), s.ax);
  }
  L00470569: { // 0x470569: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0047056b: { // 0x47056b: 890dd8d87b00 MOV dword ptr [0x007bd8d8],ECX
    m.w32((0x007bd8d8u), s.cx);
  }
  L00470571: { // 0x470571: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00470573: { // 0x470573: 8915dcd87b00 MOV dword ptr [0x007bd8dc],EDX
    m.w32((0x007bd8dcu), s.dx);
  }
  L00470579: { // 0x470579: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0047057b: { // 0x47057b: a3f8d87b00 MOV [0x007bd8f8],EAX
    m.w32((0x007bd8f8u), s.ax);
  }
  L00470580: { // 0x470580: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470582: { // 0x470582: 890dfcd87b00 MOV dword ptr [0x007bd8fc],ECX
    m.w32((0x007bd8fcu), s.cx);
  }
  L00470588: { // 0x470588: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047058a: { // 0x47058a: 891500d97b00 MOV dword ptr [0x007bd900],EDX
    m.w32((0x007bd900u), s.dx);
  }
  L00470590: { // 0x470590: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00470592: { // 0x470592: a304d97b00 MOV [0x007bd904],EAX
    m.w32((0x007bd904u), s.ax);
  }
  L00470597: { // 0x470597: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470599: { // 0x470599: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047059b: { // 0x47059b: 890d28d97b00 MOV dword ptr [0x007bd928],ECX
    m.w32((0x007bd928u), s.cx);
  }
  L004705a1: { // 0x4705a1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705a3: { // 0x4705a3: 89152cd97b00 MOV dword ptr [0x007bd92c],EDX
    m.w32((0x007bd92cu), s.dx);
  }
  L004705a9: { // 0x4705a9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004705ab: { // 0x4705ab: a348d97b00 MOV [0x007bd948],EAX
    m.w32((0x007bd948u), s.ax);
  }
  L004705b0: { // 0x4705b0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004705b2: { // 0x4705b2: dd1520d97b00 FST double ptr [0x007bd920]
    const auto address=(0x007bd920u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705b8: { // 0x4705b8: dd1578d97b00 FST double ptr [0x007bd978]
    const auto address=(0x007bd978u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705be: { // 0x4705be: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004705c0: { // 0x4705c0: c70590d87b0000000000 MOV dword ptr [0x007bd890],0x0
    m.w32((0x007bd890u), 0x00000000u);
  }
  L004705ca: { // 0x4705ca: c70594d87b0000000000 MOV dword ptr [0x007bd894],0x0
    m.w32((0x007bd894u), 0x00000000u);
  }
  L004705d4: { // 0x4705d4: c70598d87b0000000000 MOV dword ptr [0x007bd898],0x0
    m.w32((0x007bd898u), 0x00000000u);
  }
  L004705de: { // 0x4705de: c7059cd87b000000f03f MOV dword ptr [0x007bd89c],0x3ff00000
    m.w32((0x007bd89cu), 0x3ff00000u);
  }
  L004705e8: { // 0x4705e8: c705a0d87b0000000000 MOV dword ptr [0x007bd8a0],0x0
    m.w32((0x007bd8a0u), 0x00000000u);
  }
  L004705f2: { // 0x4705f2: c705a4d87b000000f0bf MOV dword ptr [0x007bd8a4],0xbff00000
    m.w32((0x007bd8a4u), 0xbff00000u);
  }
  L004705fc: { // 0x4705fc: c705a8d87b0000000000 MOV dword ptr [0x007bd8a8],0x0
    m.w32((0x007bd8a8u), 0x00000000u);
  }
  L00470606: { // 0x470606: c705acd87b0000000000 MOV dword ptr [0x007bd8ac],0x0
    m.w32((0x007bd8acu), 0x00000000u);
  }
  L00470610: { // 0x470610: c705b8d87b0000000000 MOV dword ptr [0x007bd8b8],0x0
    m.w32((0x007bd8b8u), 0x00000000u);
  }
  L0047061a: { // 0x47061a: c705bcd87b0000000000 MOV dword ptr [0x007bd8bc],0x0
    m.w32((0x007bd8bcu), 0x00000000u);
  }
  L00470624: { // 0x470624: c705c0d87b0000000000 MOV dword ptr [0x007bd8c0],0x0
    m.w32((0x007bd8c0u), 0x00000000u);
  }
  L0047062e: { // 0x47062e: c705c4d87b000000f03f MOV dword ptr [0x007bd8c4],0x3ff00000
    m.w32((0x007bd8c4u), 0x3ff00000u);
  }
  L00470638: { // 0x470638: c705c8d87b0000000000 MOV dword ptr [0x007bd8c8],0x0
    m.w32((0x007bd8c8u), 0x00000000u);
  }
  L00470642: { // 0x470642: c705ccd87b000000f03f MOV dword ptr [0x007bd8cc],0x3ff00000
    m.w32((0x007bd8ccu), 0x3ff00000u);
  }
  L0047064c: { // 0x47064c: c705d0d87b0000000000 MOV dword ptr [0x007bd8d0],0x0
    m.w32((0x007bd8d0u), 0x00000000u);
  }
  L00470656: { // 0x470656: c705d4d87b0000000000 MOV dword ptr [0x007bd8d4],0x0
    m.w32((0x007bd8d4u), 0x00000000u);
  }
  L00470660: { // 0x470660: c705e0d87b0000000000 MOV dword ptr [0x007bd8e0],0x0
    m.w32((0x007bd8e0u), 0x00000000u);
  }
  L0047066a: { // 0x47066a: c705e4d87b0000000000 MOV dword ptr [0x007bd8e4],0x0
    m.w32((0x007bd8e4u), 0x00000000u);
  }
  L00470674: { // 0x470674: c705e8d87b0000000000 MOV dword ptr [0x007bd8e8],0x0
    m.w32((0x007bd8e8u), 0x00000000u);
  }
  L0047067e: { // 0x47067e: c705ecd87b000000f0bf MOV dword ptr [0x007bd8ec],0xbff00000
    m.w32((0x007bd8ecu), 0xbff00000u);
  }
  L00470688: { // 0x470688: c705f0d87b0000000000 MOV dword ptr [0x007bd8f0],0x0
    m.w32((0x007bd8f0u), 0x00000000u);
  }
  L00470692: { // 0x470692: c705f4d87b000000f03f MOV dword ptr [0x007bd8f4],0x3ff00000
    m.w32((0x007bd8f4u), 0x3ff00000u);
  }
  L0047069c: { // 0x47069c: c70508d97b0000000000 MOV dword ptr [0x007bd908],0x0
    m.w32((0x007bd908u), 0x00000000u);
  }
  L004706a6: { // 0x4706a6: c7050cd97b0000000000 MOV dword ptr [0x007bd90c],0x0
    m.w32((0x007bd90cu), 0x00000000u);
  }
  L004706b0: { // 0x4706b0: c70510d97b0000000000 MOV dword ptr [0x007bd910],0x0
    m.w32((0x007bd910u), 0x00000000u);
  }
  L004706ba: { // 0x4706ba: c70514d97b000000f0bf MOV dword ptr [0x007bd914],0xbff00000
    m.w32((0x007bd914u), 0xbff00000u);
  }
  L004706c4: { // 0x4706c4: c70518d97b0000000000 MOV dword ptr [0x007bd918],0x0
    m.w32((0x007bd918u), 0x00000000u);
  }
  L004706ce: { // 0x4706ce: c7051cd97b000000f0bf MOV dword ptr [0x007bd91c],0xbff00000
    m.w32((0x007bd91cu), 0xbff00000u);
  }
  L004706d8: { // 0x4706d8: c70530d97b0000000000 MOV dword ptr [0x007bd930],0x0
    m.w32((0x007bd930u), 0x00000000u);
  }
  L004706e2: { // 0x4706e2: c70534d97b0000000000 MOV dword ptr [0x007bd934],0x0
    m.w32((0x007bd934u), 0x00000000u);
  }
  L004706ec: { // 0x4706ec: c70538d97b0000000000 MOV dword ptr [0x007bd938],0x0
    m.w32((0x007bd938u), 0x00000000u);
  }
  L004706f6: { // 0x4706f6: c7053cd97b000000f03f MOV dword ptr [0x007bd93c],0x3ff00000
    m.w32((0x007bd93cu), 0x3ff00000u);
  }
  L00470700: { // 0x470700: c70540d97b0000000000 MOV dword ptr [0x007bd940],0x0
    m.w32((0x007bd940u), 0x00000000u);
  }
  L0047070a: { // 0x47070a: c70544d97b000000f0bf MOV dword ptr [0x007bd944],0xbff00000
    m.w32((0x007bd944u), 0xbff00000u);
  }
  L00470714: { // 0x470714: 890d4cd97b00 MOV dword ptr [0x007bd94c],ECX
    m.w32((0x007bd94cu), s.cx);
  }
  L0047071a: { // 0x47071a: 891550d97b00 MOV dword ptr [0x007bd950],EDX
    m.w32((0x007bd950u), s.dx);
  }
  L00470720: { // 0x470720: a354d97b00 MOV [0x007bd954],EAX
    m.w32((0x007bd954u), s.ax);
  }
  L00470725: { // 0x470725: c70558d97b0000000000 MOV dword ptr [0x007bd958],0x0
    m.w32((0x007bd958u), 0x00000000u);
  }
  L0047072f: { // 0x47072f: c7055cd97b0000000000 MOV dword ptr [0x007bd95c],0x0
    m.w32((0x007bd95cu), 0x00000000u);
  }
  L00470739: { // 0x470739: c70560d97b0000000000 MOV dword ptr [0x007bd960],0x0
    m.w32((0x007bd960u), 0x00000000u);
  }
  L00470743: { // 0x470743: c70564d97b000000f03f MOV dword ptr [0x007bd964],0x3ff00000
    m.w32((0x007bd964u), 0x3ff00000u);
  }
  L0047074d: { // 0x47074d: c70568d97b0000000000 MOV dword ptr [0x007bd968],0x0
    m.w32((0x007bd968u), 0x00000000u);
  }
  L00470757: { // 0x470757: c7056cd97b000000f03f MOV dword ptr [0x007bd96c],0x3ff00000
    m.w32((0x007bd96cu), 0x3ff00000u);
  }
  L00470761: { // 0x470761: c70570d97b0000000000 MOV dword ptr [0x007bd970],0x0
    m.w32((0x007bd970u), 0x00000000u);
  }
  L0047076b: { // 0x47076b: c70574d97b0000000000 MOV dword ptr [0x007bd974],0x0
    m.w32((0x007bd974u), 0x00000000u);
  }
  L00470775: { // 0x470775: c70580d97b0000000000 MOV dword ptr [0x007bd980],0x0
    m.w32((0x007bd980u), 0x00000000u);
  }
  L0047077f: { // 0x47077f: c70584d97b0000000000 MOV dword ptr [0x007bd984],0x0
    m.w32((0x007bd984u), 0x00000000u);
  }
  L00470789: { // 0x470789: c70588d97b0000000000 MOV dword ptr [0x007bd988],0x0
    m.w32((0x007bd988u), 0x00000000u);
  }
  L00470793: { // 0x470793: dd15a0d97b00 FST double ptr [0x007bd9a0]
    const auto address=(0x007bd9a0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470799: { // 0x470799: dd15c0d97b00 FST double ptr [0x007bd9c0]
    const auto address=(0x007bd9c0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047079f: { // 0x47079f: dd15c8d97b00 FST double ptr [0x007bd9c8]
    const auto address=(0x007bd9c8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707a5: { // 0x4707a5: dd1df0d97b00 FSTP double ptr [0x007bd9f0]
    const auto address=(0x007bd9f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004707ab: { // 0x4707ab: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707b1: { // 0x4707b1: dc0d28577800 FMUL double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L004707b7: { // 0x4707b7: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707b9: { // 0x4707b9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707bb: { // 0x4707bb: 890d98d97b00 MOV dword ptr [0x007bd998],ECX
    m.w32((0x007bd998u), s.cx);
  }
  L004707c1: { // 0x4707c1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707c3: { // 0x4707c3: 89159cd97b00 MOV dword ptr [0x007bd99c],EDX
    m.w32((0x007bd99cu), s.dx);
  }
  L004707c9: { // 0x4707c9: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707cb: { // 0x4707cb: dd1518da7b00 FST double ptr [0x007bda18]
    const auto address=(0x007bda18u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d1: { // 0x4707d1: dd1520da7b00 FST double ptr [0x007bda20]
    const auto address=(0x007bda20u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d7: { // 0x4707d7: dd1540da7b00 FST double ptr [0x007bda40]
    const auto address=(0x007bda40u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707dd: { // 0x4707dd: dd05f08e8300 FLD double ptr [0x00838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707e3: { // 0x4707e3: dc0db0797800 FMUL double ptr [0x007879b0]
    const auto address=(0x007879b0u);
    s.fp.multiply64(read64(m,address));
  }
  L004707e9: { // 0x4707e9: a3e8d97b00 MOV [0x007bd9e8],EAX
    m.w32((0x007bd9e8u), s.ax);
  }
  L004707ee: { // 0x4707ee: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004707f0: { // 0x4707f0: 890decd97b00 MOV dword ptr [0x007bd9ec],ECX
    m.w32((0x007bd9ecu), s.cx);
  }
  L004707f6: { // 0x4707f6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004707f8: { // 0x4707f8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004707fa: { // 0x4707fa: 891538da7b00 MOV dword ptr [0x007bda38],EDX
    m.w32((0x007bda38u), s.dx);
  }
  L00470800: { // 0x470800: dd542408 FST double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470804: { // 0x470804: dd1d48da7b00 FSTP double ptr [0x007bda48]
    const auto address=(0x007bda48u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047080a: { // 0x47080a: a33cda7b00 MOV [0x007bda3c],EAX
    m.w32((0x007bda3cu), s.ax);
  }
  L0047080f: { // 0x47080f: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00470811: { // 0x470811: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00470815: { // 0x470815: 890d88da7b00 MOV dword ptr [0x007bda88],ECX
    m.w32((0x007bda88u), s.cx);
  }
  L0047081b: { // 0x47081b: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0047081f: { // 0x47081f: c7058cd97b000000f0bf MOV dword ptr [0x007bd98c],0xbff00000
    m.w32((0x007bd98cu), 0xbff00000u);
  }
  L00470829: { // 0x470829: dd1568da7b00 FST double ptr [0x007bda68]
    const auto address=(0x007bda68u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047082f: { // 0x47082f: dd1570da7b00 FST double ptr [0x007bda70]
    const auto address=(0x007bda70u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470835: { // 0x470835: dd1d90da7b00 FSTP double ptr [0x007bda90]
    const auto address=(0x007bda90u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047083b: { // 0x47083b: c70590d97b0000000000 MOV dword ptr [0x007bd990],0x0
    m.w32((0x007bd990u), 0x00000000u);
  }
  L00470845: { // 0x470845: c70594d97b000000f03f MOV dword ptr [0x007bd994],0x3ff00000
    m.w32((0x007bd994u), 0x3ff00000u);
  }
  L0047084f: { // 0x47084f: c705a8d97b0000000000 MOV dword ptr [0x007bd9a8],0x0
    m.w32((0x007bd9a8u), 0x00000000u);
  }
  L00470859: { // 0x470859: c705acd97b0000000000 MOV dword ptr [0x007bd9ac],0x0
    m.w32((0x007bd9acu), 0x00000000u);
  }
  L00470863: { // 0x470863: c705b0d97b0000000000 MOV dword ptr [0x007bd9b0],0x0
    m.w32((0x007bd9b0u), 0x00000000u);
  }
  L0047086d: { // 0x47086d: c705b4d97b000000f0bf MOV dword ptr [0x007bd9b4],0xbff00000
    m.w32((0x007bd9b4u), 0xbff00000u);
  }
  L00470877: { // 0x470877: c705b8d97b0000000000 MOV dword ptr [0x007bd9b8],0x0
    m.w32((0x007bd9b8u), 0x00000000u);
  }
  L00470881: { // 0x470881: c705bcd97b000000f0bf MOV dword ptr [0x007bd9bc],0xbff00000
    m.w32((0x007bd9bcu), 0xbff00000u);
  }
  L0047088b: { // 0x47088b: c705d0d97b0000000000 MOV dword ptr [0x007bd9d0],0x0
    m.w32((0x007bd9d0u), 0x00000000u);
  }
  L00470895: { // 0x470895: c705d4d97b0000000000 MOV dword ptr [0x007bd9d4],0x0
    m.w32((0x007bd9d4u), 0x00000000u);
  }
  L0047089f: { // 0x47089f: c705d8d97b0000000000 MOV dword ptr [0x007bd9d8],0x0
    m.w32((0x007bd9d8u), 0x00000000u);
  }
  L004708a9: { // 0x4708a9: c705dcd97b000000f03f MOV dword ptr [0x007bd9dc],0x3ff00000
    m.w32((0x007bd9dcu), 0x3ff00000u);
  }
  L004708b3: { // 0x4708b3: c705e0d97b0000000000 MOV dword ptr [0x007bd9e0],0x0
    m.w32((0x007bd9e0u), 0x00000000u);
  }
  L004708bd: { // 0x4708bd: c705e4d97b000000f0bf MOV dword ptr [0x007bd9e4],0xbff00000
    m.w32((0x007bd9e4u), 0xbff00000u);
  }
  L004708c7: { // 0x4708c7: c705f8d97b0000000000 MOV dword ptr [0x007bd9f8],0x0
    m.w32((0x007bd9f8u), 0x00000000u);
  }
  L004708d1: { // 0x4708d1: c705fcd97b0000000000 MOV dword ptr [0x007bd9fc],0x0
    m.w32((0x007bd9fcu), 0x00000000u);
  }
  L004708db: { // 0x4708db: c70500da7b0000000000 MOV dword ptr [0x007bda00],0x0
    m.w32((0x007bda00u), 0x00000000u);
  }
  L004708e5: { // 0x4708e5: c70504da7b0000000000 MOV dword ptr [0x007bda04],0x0
    m.w32((0x007bda04u), 0x00000000u);
  }
  L004708ef: { // 0x4708ef: c70508da7b0000000000 MOV dword ptr [0x007bda08],0x0
    m.w32((0x007bda08u), 0x00000000u);
  }
  L004708f9: { // 0x4708f9: c7050cda7b0000000000 MOV dword ptr [0x007bda0c],0x0
    m.w32((0x007bda0cu), 0x00000000u);
  }
  L00470903: { // 0x470903: c70510da7b0000000000 MOV dword ptr [0x007bda10],0x0
    m.w32((0x007bda10u), 0x00000000u);
  }
  L0047090d: { // 0x47090d: c70514da7b0000000000 MOV dword ptr [0x007bda14],0x0
    m.w32((0x007bda14u), 0x00000000u);
  }
  L00470917: { // 0x470917: c70528da7b0000000000 MOV dword ptr [0x007bda28],0x0
    m.w32((0x007bda28u), 0x00000000u);
  }
  L00470921: { // 0x470921: c7052cda7b0000000000 MOV dword ptr [0x007bda2c],0x0
    m.w32((0x007bda2cu), 0x00000000u);
  }
  L0047092b: { // 0x47092b: c70530da7b0000000000 MOV dword ptr [0x007bda30],0x0
    m.w32((0x007bda30u), 0x00000000u);
  }
  L00470935: { // 0x470935: c70534da7b0000000000 MOV dword ptr [0x007bda34],0x0
    m.w32((0x007bda34u), 0x00000000u);
  }
  L0047093f: { // 0x47093f: c70550da7b0000000000 MOV dword ptr [0x007bda50],0x0
    m.w32((0x007bda50u), 0x00000000u);
  }
  L00470949: { // 0x470949: c70554da7b0000000000 MOV dword ptr [0x007bda54],0x0
    m.w32((0x007bda54u), 0x00000000u);
  }
  L00470953: { // 0x470953: c70558da7b0000000000 MOV dword ptr [0x007bda58],0x0
    m.w32((0x007bda58u), 0x00000000u);
  }
  L0047095d: { // 0x47095d: c7055cda7b0000000000 MOV dword ptr [0x007bda5c],0x0
    m.w32((0x007bda5cu), 0x00000000u);
  }
  L00470967: { // 0x470967: c70560da7b0000000000 MOV dword ptr [0x007bda60],0x0
    m.w32((0x007bda60u), 0x00000000u);
  }
  L00470971: { // 0x470971: c70564da7b0000000000 MOV dword ptr [0x007bda64],0x0
    m.w32((0x007bda64u), 0x00000000u);
  }
  L0047097b: { // 0x47097b: c70578da7b0000000000 MOV dword ptr [0x007bda78],0x0
    m.w32((0x007bda78u), 0x00000000u);
  }
  L00470985: { // 0x470985: c7057cda7b0000000000 MOV dword ptr [0x007bda7c],0x0
    m.w32((0x007bda7cu), 0x00000000u);
  }
  L0047098f: { // 0x47098f: c70580da7b0000000000 MOV dword ptr [0x007bda80],0x0
    m.w32((0x007bda80u), 0x00000000u);
  }
  L00470999: { // 0x470999: c70584da7b0000000000 MOV dword ptr [0x007bda84],0x0
    m.w32((0x007bda84u), 0x00000000u);
  }
  L004709a3: { // 0x4709a3: 89158cda7b00 MOV dword ptr [0x007bda8c],EDX
    m.w32((0x007bda8cu), s.dx);
  }
  L004709a9: { // 0x4709a9: a398da7b00 MOV [0x007bda98],EAX
    m.w32((0x007bda98u), s.ax);
  }
  L004709ae: { // 0x4709ae: 890d9cda7b00 MOV dword ptr [0x007bda9c],ECX
    m.w32((0x007bda9cu), s.cx);
  }
  L004709b4: { // 0x4709b4: 0fbe961b010000 MOVSX EDX,byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004709bb: { // 0x4709bb: 0faf15808f8300 IMUL EDX,dword ptr [0x00838f80]
    s.dx = integer::imul(s.dx,m.r32((0x00838f80u)),32,flags);
  }
  L004709c2: { // 0x4709c2: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L004709c6: { // 0x4709c6: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L004709ca: { // 0x4709ca: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004709d0: { // 0x4709d0: e87ba02f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655573u); flags=s.arithmetic_flags;
  }
  L004709d5: { // 0x4709d5: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L004709db: { // 0x4709db: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L004709df: { // 0x4709df: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004709e1: { // 0x4709e1: 0f868d000000 JBE 0x00470a74
    if(integer::condition("JBE",flags)) goto L00470a74;
  }
  L004709e7: { // 0x4709e7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L004709ea: { // 0x4709ea: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004709f0: { // 0x4709f0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004709f1: { // 0x4709f1: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004709f4: { // 0x4709f4: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004709f6: { // 0x4709f6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004709fc: { // 0x4709fc: 8d0c89 LEA ECX,[ECX + ECX*0x4]
    s.cx = (s.cx+(s.cx * 0x00000004u));
  }
  L004709ff: { // 0x4709ff: 89542404 MOV dword ptr [ESP + 0x4],EDX
    m.w32((f.sp+0x00000004u), s.dx);
  }
  L00470a03: { // 0x470a03: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00470a08: { // 0x470a08: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a0c: { // 0x470a0c: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L00470a0f: { // 0x470a0f: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00470a13: { // 0x470a13: dc8988d77b00 FMUL double ptr [ECX + 0x7bd788]
    const auto address=(s.cx+0x007bd788u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a19: { // 0x470a19: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a1f: { // 0x470a1f: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a23: { // 0x470a23: dc8980d77b00 FMUL double ptr [ECX + 0x7bd780]
    const auto address=(s.cx+0x007bd780u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a29: { // 0x470a29: dc0d108f8300 FMUL double ptr [0x00838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a2f: { // 0x470a2f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00470a31: { // 0x470a31: dc8190d77b00 FADD double ptr [ECX + 0x7bd790]
    const auto address=(s.cx+0x007bd790u);
    s.fp.add64(read64(m,address));
  }
  L00470a37: { // 0x470a37: dc81a0d77b00 FADD double ptr [ECX + 0x7bd7a0]
    const auto address=(s.cx+0x007bd7a0u);
    s.fp.add64(read64(m,address));
  }
  L00470a3d: { // 0x470a3d: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a43: { // 0x470a43: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a45: { // 0x470a45: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00470a48: { // 0x470a48: 7408 JZ 0x00470a52
    if(integer::condition("JZ",flags)) goto L00470a52;
  }
  L00470a4a: { // 0x470a4a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a4c: { // 0x470a4c: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L00470a52: { // 0x470a52: dc9198d77b00 FCOM double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a58: { // 0x470a58: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a5a: { // 0x470a5a: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00470a5d: { // 0x470a5d: 7508 JNZ 0x00470a67
    if(integer::condition("JNZ",flags)) goto L00470a67;
  }
  L00470a5f: { // 0x470a5f: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a61: { // 0x470a61: dd8198d77b00 FLD double ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    s.fp.load64(read64(m,address));
  }
  L00470a67: { // 0x470a67: db442408 FILD dword ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a6b: { // 0x470a6b: d8c1 FADD ST0,ST1
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00470a6d: { // 0x470a6d: e8de9f2f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655730u); flags=s.arithmetic_flags;
  }
  L00470a72: { // 0x470a72: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a74: { // 0x470a74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00470a75: { // 0x470a75: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00470a77: { // 0x470a77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00470a78: { // 0x470a78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007cb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047cb10: { // 0x47cb10: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L0047cb16: { // 0x47cb16: 0fbe891b010000 MOVSX ECX,byte ptr [ECX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.cx+0x0000011bu)),8));
  }
  L0047cb1d: { // 0x47cb1d: c1e807 SHR EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::right);
  }
  L0047cb20: { // 0x47cb20: 83e001 AND EAX,0x1
    s.ax = integer::logical((s.ax)&(0x00000001u),32,flags);
  }
  L0047cb23: { // 0x47cb23: 8d0481 LEA EAX,[ECX + EAX*0x4]
    s.ax = (s.cx+(s.ax * 0x00000004u));
  }
  L0047cb26: { // 0x47cb26: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000bb760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004bb760: { // 0x4bb760: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L004bb763: { // 0x4bb763: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004bb764: { // 0x4bb764: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004bb765: { // 0x4bb765: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004bb766: { // 0x4bb766: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004bb767: { // 0x4bb767: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L004bb76b: { // 0x4bb76b: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L004bb76d: { // 0x4bb76d: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004bb76f: { // 0x4bb76f: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L004bb771: { // 0x4bb771: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb772: { // 0x4bb772: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb778: { // 0x4bb778: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004bb77c: { // 0x4bb77c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb77e: { // 0x4bb77e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb77f: { // 0x4bb77f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb782: { // 0x4bb782: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L004bb787: { // 0x4bb787: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L004bb78b: { // 0x4bb78b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb78c: { // 0x4bb78c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb792: { // 0x4bb792: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004bb797: { // 0x4bb797: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb799: { // 0x4bb799: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L004bb79d: { // 0x4bb79d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb7a0: { // 0x4bb7a0: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L004bb7a5: { // 0x4bb7a5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004bb7a9: { // 0x4bb7a9: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L004bb7ad: { // 0x4bb7ad: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004bb7b1: { // 0x4bb7b1: e84a9d0800 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4962230u); flags=s.arithmetic_flags;
  }
  L004bb7b6: { // 0x4bb7b6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb7b8: { // 0x4bb7b8: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L004bb7bc: { // 0x4bb7bc: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L004bb7c0: { // 0x4bb7c0: 8a8266020000 MOV AL,byte ptr [EDX + 0x266]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000266u)));
  }
  L004bb7c6: { // 0x4bb7c6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb7c8: { // 0x4bb7c8: 7437 JZ 0x004bb801
    if(integer::condition("JZ",flags)) goto L004bb801;
  }
  L004bb7ca: { // 0x4bb7ca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb7cc: { // 0x4bb7cc: e83f13fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962257u); flags=s.arithmetic_flags;
  }
  L004bb7d1: { // 0x4bb7d1: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004bb7d5: { // 0x4bb7d5: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb7d7: { // 0x4bb7d7: e83413fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962268u); flags=s.arithmetic_flags;
  }
  L004bb7dc: { // 0x4bb7dc: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L004bb7de: { // 0x4bb7de: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L004bb7e1: { // 0x4bb7e1: 7c1a JL 0x004bb7fd
    if(integer::condition("JL",flags)) goto L004bb7fd;
  }
  L004bb7e3: { // 0x4bb7e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb7e5: { // 0x4bb7e5: e82613fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962282u); flags=s.arithmetic_flags;
  }
  L004bb7ea: { // 0x4bb7ea: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004bb7ec: { // 0x4bb7ec: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb7ee: { // 0x4bb7ee: e81d13fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962291u); flags=s.arithmetic_flags;
  }
  L004bb7f3: { // 0x4bb7f3: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L004bb7f5: { // 0x4bb7f5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004bb7f7: { // 0x4bb7f7: 0f8f8c000000 JG 0x004bb889
    if(integer::condition("JG",flags)) goto L004bb889;
  }
  L004bb7fd: { // 0x4bb7fd: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L004bb801: { // 0x4bb801: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L004bb805: { // 0x4bb805: 8a8868020000 MOV CL,byte ptr [EAX + 0x268]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000268u)));
  }
  L004bb80b: { // 0x4bb80b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004bb80d: { // 0x4bb80d: 0f8455020000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb813: { // 0x4bb813: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L004bb816: { // 0x4bb816: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004bb819: { // 0x4bb819: 7417 JZ 0x004bb832
    if(integer::condition("JZ",flags)) goto L004bb832;
  }
  L004bb81b: { // 0x4bb81b: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L004bb821: { // 0x4bb821: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004bb824: { // 0x4bb824: 8a8278020000 MOV AL,byte ptr [EDX + 0x278]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000278u)));
  }
  L004bb82a: { // 0x4bb82a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb82c: { // 0x4bb82c: 7404 JZ 0x004bb832
    if(integer::condition("JZ",flags)) goto L004bb832;
  }
  L004bb82e: { // 0x4bb82e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004bb830: { // 0x4bb830: eb02 JMP 0x004bb834
    goto L004bb834;
  }
  L004bb832: { // 0x4bb832: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004bb834: { // 0x4bb834: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004bb836: { // 0x4bb836: 0f842c020000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb83c: { // 0x4bb83c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb83e: { // 0x4bb83e: 0f8424020000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb844: { // 0x4bb844: 8a851b010000 MOV AL,byte ptr [EBP + 0x11b]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000011bu)));
  }
  L004bb84a: { // 0x4bb84a: 8a8b1b010000 MOV CL,byte ptr [EBX + 0x11b]
    s.cx = with_al(s.cx, m.r8((s.bx+0x0000011bu)));
  }
  L004bb850: { // 0x4bb850: 3ac1 CMP AL,CL
    (void)integer::sub((s.ax & 0xffu),(s.cx & 0xffu),8,flags);
  }
  L004bb852: { // 0x4bb852: 0f8f10020000 JG 0x004bba68
    if(integer::condition("JG",flags)) goto L004bba68;
  }
  L004bb858: { // 0x4bb858: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004bb85e: { // 0x4bb85e: 8a8198140000 MOV AL,byte ptr [ECX + 0x1498]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001498u)));
  }
  L004bb864: { // 0x4bb864: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb866: { // 0x4bb866: 7421 JZ 0x004bb889
    if(integer::condition("JZ",flags)) goto L004bb889;
  }
  L004bb868: { // 0x4bb868: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  L004bb86b: { // 0x4bb86b: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L004bb870: { // 0x4bb870: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004bb873: { // 0x4bb873: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004bb875: { // 0x4bb875: 7412 JZ 0x004bb889
    if(integer::condition("JZ",flags)) goto L004bb889;
  }
  L004bb877: { // 0x4bb877: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004bb87b: { // 0x4bb87b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb87c: { // 0x4bb87c: e85f930200 CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4962433u); flags=s.arithmetic_flags;
  }
  L004bb881: { // 0x4bb881: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb883: { // 0x4bb883: 0f85df010000 JNZ 0x004bba68
    if(integer::condition("JNZ",flags)) goto L004bba68;
  }
  L004bb889: { // 0x4bb889: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004bb88b: { // 0x4bb88b: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004bb88f: { // 0x4bb88f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb890: { // 0x4bb890: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb892: { // 0x4bb892: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4962453u); flags=s.arithmetic_flags;
  }
  L004bb895: { // 0x4bb895: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004bb897: { // 0x4bb897: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004bb89a: { // 0x4bb89a: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004bb89c: { // 0x4bb89c: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004bb89e: { // 0x4bb89e: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L004bb8a2: { // 0x4bb8a2: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  L004bb8a5: { // 0x4bb8a5: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb8a7: { // 0x4bb8a7: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L004bb8aa: { // 0x4bb8aa: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004bb8ae: { // 0x4bb8ae: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L004bb8b2: { // 0x4bb8b2: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L004bb8b4: { // 0x4bb8b4: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004bb8b8: { // 0x4bb8b8: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004bb8bc: { // 0x4bb8bc: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004bb8c0: { // 0x4bb8c0: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L004bb8c4: { // 0x4bb8c4: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L004bb8c8: { // 0x4bb8c8: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004bb8ca: { // 0x4bb8ca: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004bb8cc: { // 0x4bb8cc: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004bb8ce: { // 0x4bb8ce: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004bb8d0: { // 0x4bb8d0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004bb8d2: { // 0x4bb8d2: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L004bb8d4: { // 0x4bb8d4: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L004bb8d6: { // 0x4bb8d6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004bb8d8: { // 0x4bb8d8: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004bb8db: { // 0x4bb8db: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004bb8dd: { // 0x4bb8dd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004bb8df: { // 0x4bb8df: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004bb8e1: { // 0x4bb8e1: e89ae7ffff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4962534u); flags=s.arithmetic_flags;
  }
  L004bb8e6: { // 0x4bb8e6: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004bb8e9: { // 0x4bb8e9: e862f12a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4962542u); flags=s.arithmetic_flags;
  }
  L004bb8ee: { // 0x4bb8ee: 83f855 CMP EAX,0x55
    (void)integer::sub(s.ax,0x00000055u,32,flags);
  }
  L004bb8f1: { // 0x4bb8f1: 0f8e65010000 JLE 0x004bba5c
    if(integer::condition("JLE",flags)) goto L004bba5c;
  }
  L004bb8f7: { // 0x4bb8f7: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L004bb8fa: { // 0x4bb8fa: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004bb8fe: { // 0x4bb8fe: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb8ff: { // 0x4bb8ff: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004bb901: { // 0x4bb901: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4962564u); flags=s.arithmetic_flags;
  }
  L004bb904: { // 0x4bb904: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L004bb906: { // 0x4bb906: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004bb90a: { // 0x4bb90a: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L004bb90d: { // 0x4bb90d: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L004bb910: { // 0x4bb910: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004bb912: { // 0x4bb912: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L004bb916: { // 0x4bb916: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L004bb91a: { // 0x4bb91a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb91b: { // 0x4bb91b: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4962590u); flags=s.arithmetic_flags;
  }
  L004bb91e: { // 0x4bb91e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004bb920: { // 0x4bb920: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004bb923: { // 0x4bb923: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L004bb927: { // 0x4bb927: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L004bb92a: { // 0x4bb92a: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004bb92e: { // 0x4bb92e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bb930: { // 0x4bb930: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L004bb932: { // 0x4bb932: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb933: { // 0x4bb933: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004bb935: { // 0x4bb935: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004bb937: { // 0x4bb937: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L004bb939: { // 0x4bb939: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004bb93b: { // 0x4bb93b: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004bb93f: { // 0x4bb93f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004bb941: { // 0x4bb941: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb942: { // 0x4bb942: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb944: { // 0x4bb944: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004bb946: { // 0x4bb946: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L004bb948: { // 0x4bb948: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L004bb94a: { // 0x4bb94a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb94b: { // 0x4bb94b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004bb94d: { // 0x4bb94d: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L004bb951: { // 0x4bb951: 33fa XOR EDI,EDX
    s.di = integer::logical((s.di)^(s.dx),32,flags);
  }
  L004bb953: { // 0x4bb953: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb955: { // 0x4bb955: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L004bb957: { // 0x4bb957: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb958: { // 0x4bb958: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004bb95a: { // 0x4bb95a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004bb95c: { // 0x4bb95c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L004bb95e: { // 0x4bb95e: 7d06 JGE 0x004bb966
    if(integer::condition("JGE",flags)) goto L004bb966;
  }
  L004bb960: { // 0x4bb960: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004bb962: { // 0x4bb962: 7f10 JG 0x004bb974
    if(integer::condition("JG",flags)) goto L004bb974;
  }
  L004bb964: { // 0x4bb964: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L004bb966: { // 0x4bb966: 0f8ee2000000 JLE 0x004bba4e
    if(integer::condition("JLE",flags)) goto L004bba4e;
  }
  L004bb96c: { // 0x4bb96c: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004bb96e: { // 0x4bb96e: 0f8eda000000 JLE 0x004bba4e
    if(integer::condition("JLE",flags)) goto L004bba4e;
  }
  L004bb974: { // 0x4bb974: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004bb978: { // 0x4bb978: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb979: { // 0x4bb979: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004bb97e: { // 0x4bb97e: e87d9b0800 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4962691u); flags=s.arithmetic_flags;
  }
  L004bb983: { // 0x4bb983: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb985: { // 0x4bb985: 8b7c244c MOV EDI,dword ptr [ESP + 0x4c]
    s.di = m.r32((f.sp+0x0000004cu));
  }
  L004bb989: { // 0x4bb989: 8a8766020000 MOV AL,byte ptr [EDI + 0x266]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000266u)));
  }
  L004bb98f: { // 0x4bb98f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb991: { // 0x4bb991: 743f JZ 0x004bb9d2
    if(integer::condition("JZ",flags)) goto L004bb9d2;
  }
  L004bb993: { // 0x4bb993: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004bb997: { // 0x4bb997: e87411fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962716u); flags=s.arithmetic_flags;
  }
  L004bb99c: { // 0x4bb99c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb99e: { // 0x4bb99e: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb9a0: { // 0x4bb9a0: e86b11fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962725u); flags=s.arithmetic_flags;
  }
  L004bb9a5: { // 0x4bb9a5: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb9a7: { // 0x4bb9a7: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L004bb9aa: { // 0x4bb9aa: 7c26 JL 0x004bb9d2
    if(integer::condition("JL",flags)) goto L004bb9d2;
  }
  L004bb9ac: { // 0x4bb9ac: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L004bb9b0: { // 0x4bb9b0: e85b11fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962741u); flags=s.arithmetic_flags;
  }
  L004bb9b5: { // 0x4bb9b5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb9b7: { // 0x4bb9b7: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb9b9: { // 0x4bb9b9: e85211fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962750u); flags=s.arithmetic_flags;
  }
  L004bb9be: { // 0x4bb9be: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb9c0: { // 0x4bb9c0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004bb9c2: { // 0x4bb9c2: 7e0e JLE 0x004bb9d2
    if(integer::condition("JLE",flags)) goto L004bb9d2;
  }
  L004bb9c4: { // 0x4bb9c4: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004bb9c8: { // 0x4bb9c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bb9c9: { // 0x4bb9c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bb9ca: { // 0x4bb9ca: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bb9cb: { // 0x4bb9cb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bb9cc: { // 0x4bb9cc: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bb9cf: { // 0x4bb9cf: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L004bb9d2: { // 0x4bb9d2: 8a8768020000 MOV AL,byte ptr [EDI + 0x268]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000268u)));
  }
  L004bb9d8: { // 0x4bb9d8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb9da: { // 0x4bb9da: 0f8488000000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb9e0: { // 0x4bb9e0: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L004bb9e3: { // 0x4bb9e3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004bb9e6: { // 0x4bb9e6: 7417 JZ 0x004bb9ff
    if(integer::condition("JZ",flags)) goto L004bb9ff;
  }
  L004bb9e8: { // 0x4bb9e8: 8b151ce1a100 MOV EDX,dword ptr [0x00a1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L004bb9ee: { // 0x4bb9ee: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L004bb9f1: { // 0x4bb9f1: 8a8878020000 MOV CL,byte ptr [EAX + 0x278]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000278u)));
  }
  L004bb9f7: { // 0x4bb9f7: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004bb9f9: { // 0x4bb9f9: 7404 JZ 0x004bb9ff
    if(integer::condition("JZ",flags)) goto L004bb9ff;
  }
  L004bb9fb: { // 0x4bb9fb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004bb9fd: { // 0x4bb9fd: eb02 JMP 0x004bba01
    goto L004bba01;
  }
  L004bb9ff: { // 0x4bb9ff: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004bba01: { // 0x4bba01: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004bba05: { // 0x4bba05: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L004bba07: { // 0x4bba07: 745f JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bba09: { // 0x4bba09: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bba0b: { // 0x4bba0b: 745b JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bba0d: { // 0x4bba0d: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L004bba11: { // 0x4bba11: 8a821b010000 MOV AL,byte ptr [EDX + 0x11b]
    s.ax = with_al(s.ax, m.r8((s.dx+0x0000011bu)));
  }
  L004bba17: { // 0x4bba17: 8a911b010000 MOV DL,byte ptr [ECX + 0x11b]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000011bu)));
  }
  L004bba1d: { // 0x4bba1d: 3ac2 CMP AL,DL
    (void)integer::sub((s.ax & 0xffu),(s.dx & 0xffu),8,flags);
  }
  L004bba1f: { // 0x4bba1f: 7f47 JG 0x004bba68
    if(integer::condition("JG",flags)) goto L004bba68;
  }
  L004bba21: { // 0x4bba21: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004bba27: { // 0x4bba27: 8a8198140000 MOV AL,byte ptr [ECX + 0x1498]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001498u)));
  }
  L004bba2d: { // 0x4bba2d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bba2f: { // 0x4bba2f: 741d JZ 0x004bba4e
    if(integer::condition("JZ",flags)) goto L004bba4e;
  }
  L004bba31: { // 0x4bba31: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  L004bba34: { // 0x4bba34: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L004bba39: { // 0x4bba39: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004bba3c: { // 0x4bba3c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004bba3e: { // 0x4bba3e: 740e JZ 0x004bba4e
    if(integer::condition("JZ",flags)) goto L004bba4e;
  }
  L004bba40: { // 0x4bba40: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004bba44: { // 0x4bba44: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bba45: { // 0x4bba45: e896910200 CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4962890u); flags=s.arithmetic_flags;
  }
  L004bba4a: { // 0x4bba4a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bba4c: { // 0x4bba4c: 751a JNZ 0x004bba68
    if(integer::condition("JNZ",flags)) goto L004bba68;
  }
  L004bba4e: { // 0x4bba4e: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004bba52: { // 0x4bba52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bba53: { // 0x4bba53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bba54: { // 0x4bba54: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bba55: { // 0x4bba55: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bba56: { // 0x4bba56: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bba59: { // 0x4bba59: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L004bba5c: { // 0x4bba5c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bba5e: { // 0x4bba5e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bba5f: { // 0x4bba5f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bba60: { // 0x4bba60: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bba61: { // 0x4bba61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bba62: { // 0x4bba62: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bba65: { // 0x4bba65: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
  L004bba68: { // 0x4bba68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bba69: { // 0x4bba69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bba6a: { // 0x4bba6a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bba6b: { // 0x4bba6b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004bba6d: { // 0x4bba6d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bba6e: { // 0x4bba6e: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bba71: { // 0x4bba71: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5526784u:f_00145500(m,s,child,{});break;
case 4699728u:f_0007b650(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4704928u:f_0007caa0(m,s,child,{});break;
case 4704960u:f_0007cac0(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 4705040u:f_0007cb10(m,s,child,{});break;
case 4962144u:f_000bb760(m,s,child,{});break;
default:throw std::domain_error("recovery810 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004bb500(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004bb500: { // 0x4bb500: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L004bb503: { // 0x4bb503: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L004bb507: { // 0x4bb507: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004bb508: { // 0x4bb508: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004bb509: { // 0x4bb509: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L004bb50b: { // 0x4bb50b: 8a8866020000 MOV CL,byte ptr [EAX + 0x266]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000266u)));
  }
  L004bb511: { // 0x4bb511: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004bb512: { // 0x4bb512: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004bb513: { // 0x4bb513: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L004bb515: { // 0x4bb515: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004bb517: { // 0x4bb517: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L004bb51b: { // 0x4bb51b: 750e JNZ 0x004bb52b
    if(integer::condition("JNZ",flags)) goto L004bb52b;
  }
  L004bb51d: { // 0x4bb51d: 8a8868020000 MOV CL,byte ptr [EAX + 0x268]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000268u)));
  }
  L004bb523: { // 0x4bb523: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004bb525: { // 0x4bb525: 0f84d7010000 JZ 0x004bb702
    if(integer::condition("JZ",flags)) goto L004bb702;
  }
  L004bb52b: { // 0x4bb52b: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L004bb52d: { // 0x4bb52d: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L004bb52f: { // 0x4bb52f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb530: { // 0x4bb530: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb536: { // 0x4bb536: 8b7f04 MOV EDI,dword ptr [EDI + 0x4]
    s.di = m.r32((s.di+0x00000004u));
  }
  L004bb539: { // 0x4bb539: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb53b: { // 0x4bb53b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004bb53d: { // 0x4bb53d: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L004bb540: { // 0x4bb540: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb541: { // 0x4bb541: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb547: { // 0x4bb547: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb549: { // 0x4bb549: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004bb54b: { // 0x4bb54b: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb54e: { // 0x4bb54e: c1fd08 SAR EBP,0x8
    s.bp = integer::shift(s.bp,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb551: { // 0x4bb551: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L004bb556: { // 0x4bb556: 66896c241a MOV word ptr [ESP + 0x1a],BP
    m.w16((f.sp+0x0000001au), (s.bp & 0xffffu));
  }
  L004bb55b: { // 0x4bb55b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004bb55f: { // 0x4bb55f: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004bb563: { // 0x4bb563: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bb565: { // 0x4bb565: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb566: { // 0x4bb566: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb56c: { // 0x4bb56c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb56e: { // 0x4bb56e: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb571: { // 0x4bb571: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L004bb576: { // 0x4bb576: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004bb578: { // 0x4bb578: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb579: { // 0x4bb579: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb57f: { // 0x4bb57f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb581: { // 0x4bb581: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb584: { // 0x4bb584: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L004bb589: { // 0x4bb589: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004bb58d: { // 0x4bb58d: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L004bb591: { // 0x4bb591: 0fbfd2 MOVSX EDX,DX
    s.dx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L004bb594: { // 0x4bb594: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L004bb597: { // 0x4bb597: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004bb599: { // 0x4bb599: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb59a: { // 0x4bb59a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004bb59c: { // 0x4bb59c: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L004bb59e: { // 0x4bb59e: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004bb5a0: { // 0x4bb5a0: 0fbf542412 MOVSX EDX,word ptr [ESP + 0x12]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L004bb5a5: { // 0x4bb5a5: 0fbfc5 MOVSX EAX,BP
    s.ax = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L004bb5a8: { // 0x4bb5a8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004bb5aa: { // 0x4bb5aa: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L004bb5ac: { // 0x4bb5ac: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb5ad: { // 0x4bb5ad: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004bb5af: { // 0x4bb5af: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004bb5b1: { // 0x4bb5b1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004bb5b3: { // 0x4bb5b3: 7f02 JG 0x004bb5b7
    if(integer::condition("JG",flags)) goto L004bb5b7;
  }
  L004bb5b5: { // 0x4bb5b5: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L004bb5b7: { // 0x4bb5b7: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L004bb5ba: { // 0x4bb5ba: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L004bb5bc: { // 0x4bb5bc: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L004bb5bf: { // 0x4bb5bf: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004bb5c1: { // 0x4bb5c1: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004bb5c5: { // 0x4bb5c5: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L004bb5c7: { // 0x4bb5c7: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L004bb5ca: { // 0x4bb5ca: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004bb5cc: { // 0x4bb5cc: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L004bb5ce: { // 0x4bb5ce: 7514 JNZ 0x004bb5e4
    if(integer::condition("JNZ",flags)) goto L004bb5e4;
  }
  L004bb5d0: { // 0x4bb5d0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004bb5d2: { // 0x4bb5d2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004bb5d4: { // 0x4bb5d4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004bb5d6: { // 0x4bb5d6: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L004bb5da: { // 0x4bb5da: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L004bb5de: { // 0x4bb5de: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L004bb5e2: { // 0x4bb5e2: eb1f JMP 0x004bb603
    goto L004bb603;
  }
  L004bb5e4: { // 0x4bb5e4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bb5e6: { // 0x4bb5e6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb5e7: { // 0x4bb5e7: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004bb5e9: { // 0x4bb5e9: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb5eb: { // 0x4bb5eb: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004bb5ed: { // 0x4bb5ed: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb5ee: { // 0x4bb5ee: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004bb5f0: { // 0x4bb5f0: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L004bb5f4: { // 0x4bb5f4: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004bb5f6: { // 0x4bb5f6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004bb5f8: { // 0x4bb5f8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb5f9: { // 0x4bb5f9: f7fd IDIV EBP
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bp,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004bb5fb: { // 0x4bb5fb: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L004bb5ff: { // 0x4bb5ff: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L004bb603: { // 0x4bb603: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L004bb607: { // 0x4bb607: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb608: { // 0x4bb608: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004bb60d: { // 0x4bb60d: e8ee9e0800 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4961810u); flags=s.arithmetic_flags;
  }
  L004bb612: { // 0x4bb612: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L004bb616: { // 0x4bb616: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb618: { // 0x4bb618: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb619: { // 0x4bb619: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004bb61e: { // 0x4bb61e: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L004bb622: { // 0x4bb622: e8d99e0800 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4961831u); flags=s.arithmetic_flags;
  }
  L004bb627: { // 0x4bb627: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004bb629: { // 0x4bb629: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L004bb62d: { // 0x4bb62d: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L004bb62f: { // 0x4bb62f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bb631: { // 0x4bb631: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L004bb635: { // 0x4bb635: 0f8ec7000000 JLE 0x004bb702
    if(integer::condition("JLE",flags)) goto L004bb702;
  }
  L004bb63b: { // 0x4bb63b: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004bb63f: { // 0x4bb63f: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L004bb643: { // 0x4bb643: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004bb647: { // 0x4bb647: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L004bb64b: { // 0x4bb64b: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L004bb64d: { // 0x4bb64d: 8b7b04 MOV EDI,dword ptr [EBX + 0x4]
    s.di = m.r32((s.bx+0x00000004u));
  }
  L004bb650: { // 0x4bb650: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004bb654: { // 0x4bb654: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004bb656: { // 0x4bb656: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L004bb659: { // 0x4bb659: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L004bb65b: { // 0x4bb65b: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004bb65f: { // 0x4bb65f: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L004bb661: { // 0x4bb661: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L004bb665: { // 0x4bb665: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb666: { // 0x4bb666: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L004bb66a: { // 0x4bb66a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb66b: { // 0x4bb66b: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004bb66e: { // 0x4bb66e: 8bd4 MOV EDX,ESP
    s.dx = f.sp;
  }
  L004bb670: { // 0x4bb670: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004bb671: { // 0x4bb671: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  L004bb673: { // 0x4bb673: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L004bb676: { // 0x4bb676: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L004bb679: { // 0x4bb679: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L004bb67d: { // 0x4bb67d: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L004bb681: { // 0x4bb681: e8da000000 CALL 0x004bb760
    s.arithmetic_flags=flags; invoke(m,s,f,0x004bb760u,4961926u); flags=s.arithmetic_flags;
  }
  L004bb686: { // 0x4bb686: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004bb688: { // 0x4bb688: 757a JNZ 0x004bb704
    if(integer::condition("JNZ",flags)) goto L004bb704;
  }
  L004bb68a: { // 0x4bb68a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bb68c: { // 0x4bb68c: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  L004bb690: { // 0x4bb690: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb691: { // 0x4bb691: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb697: { // 0x4bb697: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb698: { // 0x4bb698: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb69a: { // 0x4bb69a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004bb69f: { // 0x4bb69f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb6a2: { // 0x4bb6a2: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L004bb6a7: { // 0x4bb6a7: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004bb6a9: { // 0x4bb6a9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb6aa: { // 0x4bb6aa: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb6b0: { // 0x4bb6b0: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb6b2: { // 0x4bb6b2: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb6b5: { // 0x4bb6b5: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L004bb6ba: { // 0x4bb6ba: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004bb6be: { // 0x4bb6be: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L004bb6c2: { // 0x4bb6c2: e8399e0800 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4961991u); flags=s.arithmetic_flags;
  }
  L004bb6c7: { // 0x4bb6c7: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L004bb6cb: { // 0x4bb6cb: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L004bb6cf: { // 0x4bb6cf: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L004bb6d3: { // 0x4bb6d3: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004bb6d7: { // 0x4bb6d7: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004bb6d9: { // 0x4bb6d9: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L004bb6dd: { // 0x4bb6dd: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004bb6e1: { // 0x4bb6e1: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L004bb6e5: { // 0x4bb6e5: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L004bb6e7: { // 0x4bb6e7: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L004bb6eb: { // 0x4bb6eb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004bb6ec: { // 0x4bb6ec: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004bb6ee: { // 0x4bb6ee: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L004bb6f0: { // 0x4bb6f0: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L004bb6f4: { // 0x4bb6f4: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L004bb6f8: { // 0x4bb6f8: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L004bb6fc: { // 0x4bb6fc: 0f8c45ffffff JL 0x004bb647
    if(integer::condition("JL",flags)) goto L004bb647;
  }
  L004bb702: { // 0x4bb702: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004bb704: { // 0x4bb704: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bb705: { // 0x4bb705: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bb706: { // 0x4bb706: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bb707: { // 0x4bb707: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bb708: { // 0x4bb708: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L004bb70b: { // 0x4bb70b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004bb760(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004bb760: { // 0x4bb760: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L004bb763: { // 0x4bb763: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004bb764: { // 0x4bb764: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004bb765: { // 0x4bb765: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004bb766: { // 0x4bb766: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004bb767: { // 0x4bb767: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L004bb76b: { // 0x4bb76b: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L004bb76d: { // 0x4bb76d: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004bb76f: { // 0x4bb76f: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L004bb771: { // 0x4bb771: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb772: { // 0x4bb772: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb778: { // 0x4bb778: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004bb77c: { // 0x4bb77c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb77e: { // 0x4bb77e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb77f: { // 0x4bb77f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb782: { // 0x4bb782: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L004bb787: { // 0x4bb787: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L004bb78b: { // 0x4bb78b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb78c: { // 0x4bb78c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004bb792: { // 0x4bb792: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004bb797: { // 0x4bb797: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004bb799: { // 0x4bb799: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L004bb79d: { // 0x4bb79d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004bb7a0: { // 0x4bb7a0: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L004bb7a5: { // 0x4bb7a5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004bb7a9: { // 0x4bb7a9: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L004bb7ad: { // 0x4bb7ad: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004bb7b1: { // 0x4bb7b1: e84a9d0800 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4962230u); flags=s.arithmetic_flags;
  }
  L004bb7b6: { // 0x4bb7b6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb7b8: { // 0x4bb7b8: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  L004bb7bc: { // 0x4bb7bc: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L004bb7c0: { // 0x4bb7c0: 8a8266020000 MOV AL,byte ptr [EDX + 0x266]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000266u)));
  }
  L004bb7c6: { // 0x4bb7c6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb7c8: { // 0x4bb7c8: 7437 JZ 0x004bb801
    if(integer::condition("JZ",flags)) goto L004bb801;
  }
  L004bb7ca: { // 0x4bb7ca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb7cc: { // 0x4bb7cc: e83f13fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962257u); flags=s.arithmetic_flags;
  }
  L004bb7d1: { // 0x4bb7d1: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004bb7d5: { // 0x4bb7d5: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb7d7: { // 0x4bb7d7: e83413fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962268u); flags=s.arithmetic_flags;
  }
  L004bb7dc: { // 0x4bb7dc: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L004bb7de: { // 0x4bb7de: 83fb04 CMP EBX,0x4
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L004bb7e1: { // 0x4bb7e1: 7c1a JL 0x004bb7fd
    if(integer::condition("JL",flags)) goto L004bb7fd;
  }
  L004bb7e3: { // 0x4bb7e3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb7e5: { // 0x4bb7e5: e82613fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962282u); flags=s.arithmetic_flags;
  }
  L004bb7ea: { // 0x4bb7ea: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004bb7ec: { // 0x4bb7ec: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb7ee: { // 0x4bb7ee: e81d13fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962291u); flags=s.arithmetic_flags;
  }
  L004bb7f3: { // 0x4bb7f3: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L004bb7f5: { // 0x4bb7f5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004bb7f7: { // 0x4bb7f7: 0f8f8c000000 JG 0x004bb889
    if(integer::condition("JG",flags)) goto L004bb889;
  }
  L004bb7fd: { // 0x4bb7fd: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L004bb801: { // 0x4bb801: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L004bb805: { // 0x4bb805: 8a8868020000 MOV CL,byte ptr [EAX + 0x268]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000268u)));
  }
  L004bb80b: { // 0x4bb80b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004bb80d: { // 0x4bb80d: 0f8455020000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb813: { // 0x4bb813: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L004bb816: { // 0x4bb816: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004bb819: { // 0x4bb819: 7417 JZ 0x004bb832
    if(integer::condition("JZ",flags)) goto L004bb832;
  }
  L004bb81b: { // 0x4bb81b: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L004bb821: { // 0x4bb821: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L004bb824: { // 0x4bb824: 8a8278020000 MOV AL,byte ptr [EDX + 0x278]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000278u)));
  }
  L004bb82a: { // 0x4bb82a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb82c: { // 0x4bb82c: 7404 JZ 0x004bb832
    if(integer::condition("JZ",flags)) goto L004bb832;
  }
  L004bb82e: { // 0x4bb82e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004bb830: { // 0x4bb830: eb02 JMP 0x004bb834
    goto L004bb834;
  }
  L004bb832: { // 0x4bb832: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004bb834: { // 0x4bb834: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L004bb836: { // 0x4bb836: 0f842c020000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb83c: { // 0x4bb83c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb83e: { // 0x4bb83e: 0f8424020000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb844: { // 0x4bb844: 8a851b010000 MOV AL,byte ptr [EBP + 0x11b]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000011bu)));
  }
  L004bb84a: { // 0x4bb84a: 8a8b1b010000 MOV CL,byte ptr [EBX + 0x11b]
    s.cx = with_al(s.cx, m.r8((s.bx+0x0000011bu)));
  }
  L004bb850: { // 0x4bb850: 3ac1 CMP AL,CL
    (void)integer::sub((s.ax & 0xffu),(s.cx & 0xffu),8,flags);
  }
  L004bb852: { // 0x4bb852: 0f8f10020000 JG 0x004bba68
    if(integer::condition("JG",flags)) goto L004bba68;
  }
  L004bb858: { // 0x4bb858: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004bb85e: { // 0x4bb85e: 8a8198140000 MOV AL,byte ptr [ECX + 0x1498]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001498u)));
  }
  L004bb864: { // 0x4bb864: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb866: { // 0x4bb866: 7421 JZ 0x004bb889
    if(integer::condition("JZ",flags)) goto L004bb889;
  }
  L004bb868: { // 0x4bb868: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  L004bb86b: { // 0x4bb86b: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L004bb870: { // 0x4bb870: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004bb873: { // 0x4bb873: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004bb875: { // 0x4bb875: 7412 JZ 0x004bb889
    if(integer::condition("JZ",flags)) goto L004bb889;
  }
  L004bb877: { // 0x4bb877: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004bb87b: { // 0x4bb87b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb87c: { // 0x4bb87c: e85f930200 CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4962433u); flags=s.arithmetic_flags;
  }
  L004bb881: { // 0x4bb881: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb883: { // 0x4bb883: 0f85df010000 JNZ 0x004bba68
    if(integer::condition("JNZ",flags)) goto L004bba68;
  }
  L004bb889: { // 0x4bb889: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004bb88b: { // 0x4bb88b: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004bb88f: { // 0x4bb88f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb890: { // 0x4bb890: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb892: { // 0x4bb892: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4962453u); flags=s.arithmetic_flags;
  }
  L004bb895: { // 0x4bb895: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004bb897: { // 0x4bb897: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004bb89a: { // 0x4bb89a: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004bb89c: { // 0x4bb89c: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004bb89e: { // 0x4bb89e: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L004bb8a2: { // 0x4bb8a2: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  L004bb8a5: { // 0x4bb8a5: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb8a7: { // 0x4bb8a7: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L004bb8aa: { // 0x4bb8aa: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004bb8ae: { // 0x4bb8ae: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L004bb8b2: { // 0x4bb8b2: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L004bb8b4: { // 0x4bb8b4: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004bb8b8: { // 0x4bb8b8: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004bb8bc: { // 0x4bb8bc: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004bb8c0: { // 0x4bb8c0: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L004bb8c4: { // 0x4bb8c4: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L004bb8c8: { // 0x4bb8c8: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004bb8ca: { // 0x4bb8ca: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004bb8cc: { // 0x4bb8cc: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004bb8ce: { // 0x4bb8ce: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004bb8d0: { // 0x4bb8d0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004bb8d2: { // 0x4bb8d2: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L004bb8d4: { // 0x4bb8d4: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L004bb8d6: { // 0x4bb8d6: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004bb8d8: { // 0x4bb8d8: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004bb8db: { // 0x4bb8db: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004bb8dd: { // 0x4bb8dd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004bb8df: { // 0x4bb8df: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004bb8e1: { // 0x4bb8e1: e89ae7ffff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4962534u); flags=s.arithmetic_flags;
  }
  L004bb8e6: { // 0x4bb8e6: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004bb8e9: { // 0x4bb8e9: e862f12a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4962542u); flags=s.arithmetic_flags;
  }
  L004bb8ee: { // 0x4bb8ee: 83f855 CMP EAX,0x55
    (void)integer::sub(s.ax,0x00000055u,32,flags);
  }
  L004bb8f1: { // 0x4bb8f1: 0f8e65010000 JLE 0x004bba5c
    if(integer::condition("JLE",flags)) goto L004bba5c;
  }
  L004bb8f7: { // 0x4bb8f7: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L004bb8fa: { // 0x4bb8fa: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L004bb8fe: { // 0x4bb8fe: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb8ff: { // 0x4bb8ff: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004bb901: { // 0x4bb901: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4962564u); flags=s.arithmetic_flags;
  }
  L004bb904: { // 0x4bb904: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L004bb906: { // 0x4bb906: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004bb90a: { // 0x4bb90a: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L004bb90d: { // 0x4bb90d: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L004bb910: { // 0x4bb910: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004bb912: { // 0x4bb912: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L004bb916: { // 0x4bb916: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L004bb91a: { // 0x4bb91a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bb91b: { // 0x4bb91b: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),4962590u); flags=s.arithmetic_flags;
  }
  L004bb91e: { // 0x4bb91e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004bb920: { // 0x4bb920: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004bb923: { // 0x4bb923: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L004bb927: { // 0x4bb927: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L004bb92a: { // 0x4bb92a: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004bb92e: { // 0x4bb92e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bb930: { // 0x4bb930: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L004bb932: { // 0x4bb932: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb933: { // 0x4bb933: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004bb935: { // 0x4bb935: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L004bb937: { // 0x4bb937: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L004bb939: { // 0x4bb939: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004bb93b: { // 0x4bb93b: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004bb93f: { // 0x4bb93f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004bb941: { // 0x4bb941: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb942: { // 0x4bb942: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb944: { // 0x4bb944: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004bb946: { // 0x4bb946: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L004bb948: { // 0x4bb948: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L004bb94a: { // 0x4bb94a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb94b: { // 0x4bb94b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004bb94d: { // 0x4bb94d: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L004bb951: { // 0x4bb951: 33fa XOR EDI,EDX
    s.di = integer::logical((s.di)^(s.dx),32,flags);
  }
  L004bb953: { // 0x4bb953: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb955: { // 0x4bb955: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L004bb957: { // 0x4bb957: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004bb958: { // 0x4bb958: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004bb95a: { // 0x4bb95a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004bb95c: { // 0x4bb95c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L004bb95e: { // 0x4bb95e: 7d06 JGE 0x004bb966
    if(integer::condition("JGE",flags)) goto L004bb966;
  }
  L004bb960: { // 0x4bb960: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004bb962: { // 0x4bb962: 7f10 JG 0x004bb974
    if(integer::condition("JG",flags)) goto L004bb974;
  }
  L004bb964: { // 0x4bb964: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L004bb966: { // 0x4bb966: 0f8ee2000000 JLE 0x004bba4e
    if(integer::condition("JLE",flags)) goto L004bba4e;
  }
  L004bb96c: { // 0x4bb96c: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004bb96e: { // 0x4bb96e: 0f8eda000000 JLE 0x004bba4e
    if(integer::condition("JLE",flags)) goto L004bba4e;
  }
  L004bb974: { // 0x4bb974: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004bb978: { // 0x4bb978: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004bb979: { // 0x4bb979: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004bb97e: { // 0x4bb97e: e87d9b0800 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4962691u); flags=s.arithmetic_flags;
  }
  L004bb983: { // 0x4bb983: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004bb985: { // 0x4bb985: 8b7c244c MOV EDI,dword ptr [ESP + 0x4c]
    s.di = m.r32((f.sp+0x0000004cu));
  }
  L004bb989: { // 0x4bb989: 8a8766020000 MOV AL,byte ptr [EDI + 0x266]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000266u)));
  }
  L004bb98f: { // 0x4bb98f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb991: { // 0x4bb991: 743f JZ 0x004bb9d2
    if(integer::condition("JZ",flags)) goto L004bb9d2;
  }
  L004bb993: { // 0x4bb993: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004bb997: { // 0x4bb997: e87411fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962716u); flags=s.arithmetic_flags;
  }
  L004bb99c: { // 0x4bb99c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb99e: { // 0x4bb99e: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb9a0: { // 0x4bb9a0: e86b11fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962725u); flags=s.arithmetic_flags;
  }
  L004bb9a5: { // 0x4bb9a5: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb9a7: { // 0x4bb9a7: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L004bb9aa: { // 0x4bb9aa: 7c26 JL 0x004bb9d2
    if(integer::condition("JL",flags)) goto L004bb9d2;
  }
  L004bb9ac: { // 0x4bb9ac: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L004bb9b0: { // 0x4bb9b0: e85b11fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962741u); flags=s.arithmetic_flags;
  }
  L004bb9b5: { // 0x4bb9b5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004bb9b7: { // 0x4bb9b7: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L004bb9b9: { // 0x4bb9b9: e85211fcff CALL 0x0047cb10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cb10u,4962750u); flags=s.arithmetic_flags;
  }
  L004bb9be: { // 0x4bb9be: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L004bb9c0: { // 0x4bb9c0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004bb9c2: { // 0x4bb9c2: 7e0e JLE 0x004bb9d2
    if(integer::condition("JLE",flags)) goto L004bb9d2;
  }
  L004bb9c4: { // 0x4bb9c4: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004bb9c8: { // 0x4bb9c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bb9c9: { // 0x4bb9c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bb9ca: { // 0x4bb9ca: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bb9cb: { // 0x4bb9cb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bb9cc: { // 0x4bb9cc: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bb9cf: { // 0x4bb9cf: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004bb9d2: { // 0x4bb9d2: 8a8768020000 MOV AL,byte ptr [EDI + 0x268]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000268u)));
  }
  L004bb9d8: { // 0x4bb9d8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bb9da: { // 0x4bb9da: 0f8488000000 JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bb9e0: { // 0x4bb9e0: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  L004bb9e3: { // 0x4bb9e3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004bb9e6: { // 0x4bb9e6: 7417 JZ 0x004bb9ff
    if(integer::condition("JZ",flags)) goto L004bb9ff;
  }
  L004bb9e8: { // 0x4bb9e8: 8b151ce1a100 MOV EDX,dword ptr [0x00a1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L004bb9ee: { // 0x4bb9ee: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L004bb9f1: { // 0x4bb9f1: 8a8878020000 MOV CL,byte ptr [EAX + 0x278]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000278u)));
  }
  L004bb9f7: { // 0x4bb9f7: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004bb9f9: { // 0x4bb9f9: 7404 JZ 0x004bb9ff
    if(integer::condition("JZ",flags)) goto L004bb9ff;
  }
  L004bb9fb: { // 0x4bb9fb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004bb9fd: { // 0x4bb9fd: eb02 JMP 0x004bba01
    goto L004bba01;
  }
  L004bb9ff: { // 0x4bb9ff: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004bba01: { // 0x4bba01: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004bba05: { // 0x4bba05: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L004bba07: { // 0x4bba07: 745f JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bba09: { // 0x4bba09: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bba0b: { // 0x4bba0b: 745b JZ 0x004bba68
    if(integer::condition("JZ",flags)) goto L004bba68;
  }
  L004bba0d: { // 0x4bba0d: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L004bba11: { // 0x4bba11: 8a821b010000 MOV AL,byte ptr [EDX + 0x11b]
    s.ax = with_al(s.ax, m.r8((s.dx+0x0000011bu)));
  }
  L004bba17: { // 0x4bba17: 8a911b010000 MOV DL,byte ptr [ECX + 0x11b]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000011bu)));
  }
  L004bba1d: { // 0x4bba1d: 3ac2 CMP AL,DL
    (void)integer::sub((s.ax & 0xffu),(s.dx & 0xffu),8,flags);
  }
  L004bba1f: { // 0x4bba1f: 7f47 JG 0x004bba68
    if(integer::condition("JG",flags)) goto L004bba68;
  }
  L004bba21: { // 0x4bba21: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004bba27: { // 0x4bba27: 8a8198140000 MOV AL,byte ptr [ECX + 0x1498]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001498u)));
  }
  L004bba2d: { // 0x4bba2d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bba2f: { // 0x4bba2f: 741d JZ 0x004bba4e
    if(integer::condition("JZ",flags)) goto L004bba4e;
  }
  L004bba31: { // 0x4bba31: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  L004bba34: { // 0x4bba34: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L004bba39: { // 0x4bba39: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L004bba3c: { // 0x4bba3c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004bba3e: { // 0x4bba3e: 740e JZ 0x004bba4e
    if(integer::condition("JZ",flags)) goto L004bba4e;
  }
  L004bba40: { // 0x4bba40: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004bba44: { // 0x4bba44: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004bba45: { // 0x4bba45: e896910200 CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,4962890u); flags=s.arithmetic_flags;
  }
  L004bba4a: { // 0x4bba4a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004bba4c: { // 0x4bba4c: 751a JNZ 0x004bba68
    if(integer::condition("JNZ",flags)) goto L004bba68;
  }
  L004bba4e: { // 0x4bba4e: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004bba52: { // 0x4bba52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bba53: { // 0x4bba53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bba54: { // 0x4bba54: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bba55: { // 0x4bba55: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bba56: { // 0x4bba56: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bba59: { // 0x4bba59: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004bba5c: { // 0x4bba5c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004bba5e: { // 0x4bba5e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bba5f: { // 0x4bba5f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bba60: { // 0x4bba60: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bba61: { // 0x4bba61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bba62: { // 0x4bba62: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bba65: { // 0x4bba65: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004bba68: { // 0x4bba68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004bba69: { // 0x4bba69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004bba6a: { // 0x4bba6a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004bba6b: { // 0x4bba6b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004bba6d: { // 0x4bba6d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004bba6e: { // 0x4bba6e: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L004bba71: { // 0x4bba71: c21800 RET 0x18
    s.arithmetic_flags=flags; finish(m,s,f,24u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
