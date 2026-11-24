#include "recovered/recovery_b775_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b775 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b650(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0007caa0(Memory&,State&,Frame&,const Operations&);
void f_0007cac0(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
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
default:throw std::domain_error("recovery775 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0062f020(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062f020: { // 0x62f020: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062f021: { // 0x62f021: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0062f023: { // 0x62f023: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0062f026: { // 0x62f026: 83ec50 SUB ESP,0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  L0062f029: { // 0x62f029: 0fbf5140 MOVSX EDX,word ptr [ECX + 0x40]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000040u)),16));
  }
  L0062f02d: { // 0x62f02d: 0fbf4142 MOVSX EAX,word ptr [ECX + 0x42]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000042u)),16));
  }
  L0062f031: { // 0x62f031: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062f032: { // 0x62f032: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062f033: { // 0x62f033: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062f034: { // 0x62f034: 8b7144 MOV ESI,dword ptr [ECX + 0x44]
    s.si = m.r32((s.cx+0x00000044u));
  }
  L0062f037: { // 0x62f037: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0062f039: { // 0x62f039: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0062f03b: { // 0x62f03b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062f03c: { // 0x62f03c: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0062f040: { // 0x62f040: 8d7c7201 LEA EDI,[EDX + ESI*0x2 + 0x1]
    s.di = (s.dx+(s.si * 0x00000002u)+0x00000001u);
  }
  L0062f044: { // 0x62f044: 8d747001 LEA ESI,[EAX + ESI*0x2 + 0x1]
    s.si = (s.ax+(s.si * 0x00000002u)+0x00000001u);
  }
  L0062f048: { // 0x62f048: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0062f04a: { // 0x62f04a: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0062f04e: { // 0x62f04e: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L0062f052: { // 0x62f052: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0062f056: { // 0x62f056: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0062f05a: { // 0x62f05a: 0f8d43010000 JGE 0x0062f1a3
    if(integer::condition("JGE",flags)) goto L0062f1a3;
  }
  L0062f060: { // 0x62f060: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0062f064: { // 0x62f064: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0062f068: { // 0x62f068: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0062f06a: { // 0x62f06a: 0f8d22010000 JGE 0x0062f192
    if(integer::condition("JGE",flags)) goto L0062f192;
  }
  L0062f070: { // 0x62f070: eb04 JMP 0x0062f076
    goto L0062f076;
  }
  L0062f072: { // 0x62f072: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0062f076: { // 0x62f076: 668b442418 MOV AX,word ptr [ESP + 0x18]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000018u)));
  }
  L0062f07b: { // 0x62f07b: 668b542420 MOV DX,word ptr [ESP + 0x20]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000020u)));
  }
  L0062f080: { // 0x62f080: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0062f085: { // 0x62f085: 8d4140 LEA EAX,[ECX + 0x40]
    s.ax = (s.cx+0x00000040u);
  }
  L0062f088: { // 0x62f088: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f089: { // 0x62f089: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f08e: { // 0x62f08e: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0062f093: { // 0x62f093: e86864f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484120u); flags=s.arithmetic_flags;
  }
  L0062f098: { // 0x62f098: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0062f09a: { // 0x62f09a: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0062f09e: { // 0x62f09e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f09f: { // 0x62f09f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f0a4: { // 0x62f0a4: e85764f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484137u); flags=s.arithmetic_flags;
  }
  L0062f0a9: { // 0x62f0a9: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0062f0ab: { // 0x62f0ab: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062f0ad: { // 0x62f0ad: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L0062f0b1: { // 0x62f0b1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062f0b3: { // 0x62f0b3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f0b4: { // 0x62f0b4: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6484151u); flags=s.arithmetic_flags;
  }
  L0062f0b7: { // 0x62f0b7: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0062f0b9: { // 0x62f0b9: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0062f0bc: { // 0x62f0bc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0062f0be: { // 0x62f0be: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0062f0c1: { // 0x62f0c1: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L0062f0c4: { // 0x62f0c4: 8d442454 LEA EAX,[ESP + 0x54]
    s.ax = (f.sp+0x00000054u);
  }
  L0062f0c8: { // 0x62f0c8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f0c9: { // 0x62f0c9: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6484172u); flags=s.arithmetic_flags;
  }
  L0062f0cc: { // 0x62f0cc: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0062f0ce: { // 0x62f0ce: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0062f0d1: { // 0x62f0d1: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0062f0d3: { // 0x62f0d3: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0062f0d5: { // 0x62f0d5: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062f0d8: { // 0x62f0d8: 89742444 MOV dword ptr [ESP + 0x44],ESI
    m.w32((f.sp+0x00000044u), s.si);
  }
  L0062f0dc: { // 0x62f0dc: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L0062f0de: { // 0x62f0de: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0062f0e1: { // 0x62f0e1: 897c2448 MOV dword ptr [ESP + 0x48],EDI
    m.w32((f.sp+0x00000048u), s.di);
  }
  L0062f0e5: { // 0x62f0e5: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f0e9: { // 0x62f0e9: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0062f0eb: { // 0x62f0eb: 895c244c MOV dword ptr [ESP + 0x4c],EBX
    m.w32((f.sp+0x0000004cu), s.bx);
  }
  L0062f0ef: { // 0x62f0ef: db44244c FILD dword ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f0f3: { // 0x62f0f3: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f0f7: { // 0x62f0f7: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062f0f9: { // 0x62f0f9: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0062f0fb: { // 0x62f0fb: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0062f0fd: { // 0x62f0fd: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0062f0ff: { // 0x62f0ff: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0062f101: { // 0x62f101: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L0062f103: { // 0x62f103: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L0062f105: { // 0x62f105: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0062f107: { // 0x62f107: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f10a: { // 0x62f10a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f10c: { // 0x62f10c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f10e: { // 0x62f10e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f110: { // 0x62f110: e86bafe8ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6484245u); flags=s.arithmetic_flags;
  }
  L0062f115: { // 0x62f115: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0062f118: { // 0x62f118: e833b91300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6484253u); flags=s.arithmetic_flags;
  }
  L0062f11d: { // 0x62f11d: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0062f121: { // 0x62f121: c744242800000000 MOV dword ptr [ESP + 0x28],0x0
    m.w32((f.sp+0x00000028u), 0x00000000u);
  }
  L0062f129: { // 0x62f129: c744242c00000000 MOV dword ptr [ESP + 0x2c],0x0
    m.w32((f.sp+0x0000002cu), 0x00000000u);
  }
  L0062f131: { // 0x62f131: 8b4a48 MOV ECX,dword ptr [EDX + 0x48]
    s.cx = m.r32((s.dx+0x00000048u));
  }
  L0062f134: { // 0x62f134: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062f136: { // 0x62f136: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0062f13a: { // 0x62f13a: 7f15 JG 0x0062f151
    if(integer::condition("JG",flags)) goto L0062f151;
  }
  L0062f13c: { // 0x62f13c: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0062f13e: { // 0x62f13e: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0062f142: { // 0x62f142: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f146: { // 0x62f146: da742430 FIDIV dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0062f14a: { // 0x62f14a: da4a4c FIMUL dword ptr [EDX + 0x4c]
    const auto address=(s.dx+0x0000004cu);
    multiply_integer32(s.fp,m.r32(address));
  }
  L0062f14d: { // 0x62f14d: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f151: { // 0x62f151: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0062f155: { // 0x62f155: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f15a: { // 0x62f15a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f15b: { // 0x62f15b: e8a063f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484320u); flags=s.arithmetic_flags;
  }
  L0062f160: { // 0x62f160: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0062f164: { // 0x62f164: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0062f167: { // 0x62f167: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062f169: { // 0x62f169: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f16c: { // 0x62f16c: e82fd9e4ff CALL 0x0047caa0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047caa0u,6484337u); flags=s.arithmetic_flags;
  }
  L0062f171: { // 0x62f171: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0062f175: { // 0x62f175: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0062f179: { // 0x62f179: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062f17a: { // 0x62f17a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062f17c: { // 0x62f17c: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0062f180: { // 0x62f180: 0f8cecfeffff JL 0x0062f072
    if(integer::condition("JL",flags)) goto L0062f072;
  }
  L0062f186: { // 0x62f186: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L0062f18a: { // 0x62f18a: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0062f18e: { // 0x62f18e: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0062f192: { // 0x62f192: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0062f196: { // 0x62f196: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062f197: { // 0x62f197: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0062f199: { // 0x62f199: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0062f19d: { // 0x62f19d: 0f8cbdfeffff JL 0x0062f060
    if(integer::condition("JL",flags)) goto L0062f060;
  }
  L0062f1a3: { // 0x62f1a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062f1a4: { // 0x62f1a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062f1a5: { // 0x62f1a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062f1a6: { // 0x62f1a6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062f1a7: { // 0x62f1a7: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0062f1a9: { // 0x62f1a9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062f1aa: { // 0x62f1aa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0062f1b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062f1b0: { // 0x62f1b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062f1b1: { // 0x62f1b1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0062f1b3: { // 0x62f1b3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0062f1b6: { // 0x62f1b6: 83ec60 SUB ESP,0x60
    f.sp = integer::sub(f.sp,0x00000060u,32,flags);
  }
  L0062f1b9: { // 0x62f1b9: 8b4170 MOV EAX,dword ptr [ECX + 0x70]
    s.ax = m.r32((s.cx+0x00000070u));
  }
  L0062f1bc: { // 0x62f1bc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062f1bd: { // 0x62f1bd: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062f1be: { // 0x62f1be: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062f1bf: { // 0x62f1bf: 8b35881b8200 MOV ESI,dword ptr [0x00821b88]
    s.si = m.r32((0x00821b88u));
  }
  L0062f1c5: { // 0x62f1c5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062f1c6: { // 0x62f1c6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0062f1c7: { // 0x62f1c7: f7be54140000 IDIV dword ptr [ESI + 0x1454]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.si+0x00001454u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0062f1cd: { // 0x62f1cd: 0fbf5140 MOVSX EDX,word ptr [ECX + 0x40]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000040u)),16));
  }
  L0062f1d1: { // 0x62f1d1: 8b7144 MOV ESI,dword ptr [ECX + 0x44]
    s.si = m.r32((s.cx+0x00000044u));
  }
  L0062f1d4: { // 0x62f1d4: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0062f1d8: { // 0x62f1d8: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0062f1da: { // 0x62f1da: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0062f1de: { // 0x62f1de: 8d7c7201 LEA EDI,[EDX + ESI*0x2 + 0x1]
    s.di = (s.dx+(s.si * 0x00000002u)+0x00000001u);
  }
  L0062f1e2: { // 0x62f1e2: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L0062f1e6: { // 0x62f1e6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062f1e7: { // 0x62f1e7: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0062f1eb: { // 0x62f1eb: 0fbf4142 MOVSX EAX,word ptr [ECX + 0x42]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000042u)),16));
  }
  L0062f1ef: { // 0x62f1ef: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0062f1f1: { // 0x62f1f1: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0062f1f5: { // 0x62f1f5: 8d747001 LEA ESI,[EAX + ESI*0x2 + 0x1]
    s.si = (s.ax+(s.si * 0x00000002u)+0x00000001u);
  }
  L0062f1f9: { // 0x62f1f9: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0062f1fb: { // 0x62f1fb: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L0062f1ff: { // 0x62f1ff: 0f8d4a010000 JGE 0x0062f34f
    if(integer::condition("JGE",flags)) goto L0062f34f;
  }
  L0062f205: { // 0x62f205: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0062f209: { // 0x62f209: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0062f20d: { // 0x62f20d: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0062f20f: { // 0x62f20f: 0f8d29010000 JGE 0x0062f33e
    if(integer::condition("JGE",flags)) goto L0062f33e;
  }
  L0062f215: { // 0x62f215: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f219: { // 0x62f219: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f21d: { // 0x62f21d: eb04 JMP 0x0062f223
    goto L0062f223;
  }
  L0062f21f: { // 0x62f21f: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0062f223: { // 0x62f223: 668b442418 MOV AX,word ptr [ESP + 0x18]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000018u)));
  }
  L0062f228: { // 0x62f228: 668b542420 MOV DX,word ptr [ESP + 0x20]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000020u)));
  }
  L0062f22d: { // 0x62f22d: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L0062f232: { // 0x62f232: 8d4140 LEA EAX,[ECX + 0x40]
    s.ax = (s.cx+0x00000040u);
  }
  L0062f235: { // 0x62f235: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f236: { // 0x62f236: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f23b: { // 0x62f23b: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L0062f240: { // 0x62f240: e8bb62f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484549u); flags=s.arithmetic_flags;
  }
  L0062f245: { // 0x62f245: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0062f247: { // 0x62f247: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0062f24b: { // 0x62f24b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f24c: { // 0x62f24c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f251: { // 0x62f251: e8aa62f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484566u); flags=s.arithmetic_flags;
  }
  L0062f256: { // 0x62f256: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0062f258: { // 0x62f258: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062f25a: { // 0x62f25a: 8d442458 LEA EAX,[ESP + 0x58]
    s.ax = (f.sp+0x00000058u);
  }
  L0062f25e: { // 0x62f25e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062f260: { // 0x62f260: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f261: { // 0x62f261: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6484580u); flags=s.arithmetic_flags;
  }
  L0062f264: { // 0x62f264: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0062f266: { // 0x62f266: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0062f269: { // 0x62f269: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0062f26b: { // 0x62f26b: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0062f26e: { // 0x62f26e: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L0062f271: { // 0x62f271: 8d442464 LEA EAX,[ESP + 0x64]
    s.ax = (f.sp+0x00000064u);
  }
  L0062f275: { // 0x62f275: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f276: { // 0x62f276: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6484601u); flags=s.arithmetic_flags;
  }
  L0062f279: { // 0x62f279: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0062f27b: { // 0x62f27b: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0062f27e: { // 0x62f27e: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0062f280: { // 0x62f280: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0062f282: { // 0x62f282: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062f285: { // 0x62f285: 89742454 MOV dword ptr [ESP + 0x54],ESI
    m.w32((f.sp+0x00000054u), s.si);
  }
  L0062f289: { // 0x62f289: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L0062f28b: { // 0x62f28b: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0062f28e: { // 0x62f28e: 897c2458 MOV dword ptr [ESP + 0x58],EDI
    m.w32((f.sp+0x00000058u), s.di);
  }
  L0062f292: { // 0x62f292: db442458 FILD dword ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f296: { // 0x62f296: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0062f298: { // 0x62f298: 895c245c MOV dword ptr [ESP + 0x5c],EBX
    m.w32((f.sp+0x0000005cu), s.bx);
  }
  L0062f29c: { // 0x62f29c: db44245c FILD dword ptr [ESP + 0x5c]
    const auto address=(f.sp+0x0000005cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f2a0: { // 0x62f2a0: db442454 FILD dword ptr [ESP + 0x54]
    const auto address=(f.sp+0x00000054u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f2a4: { // 0x62f2a4: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062f2a6: { // 0x62f2a6: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0062f2a8: { // 0x62f2a8: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0062f2aa: { // 0x62f2aa: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0062f2ac: { // 0x62f2ac: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0062f2ae: { // 0x62f2ae: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L0062f2b0: { // 0x62f2b0: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L0062f2b2: { // 0x62f2b2: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0062f2b4: { // 0x62f2b4: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f2b7: { // 0x62f2b7: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f2b9: { // 0x62f2b9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f2bb: { // 0x62f2bb: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f2bd: { // 0x62f2bd: e8beade8ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6484674u); flags=s.arithmetic_flags;
  }
  L0062f2c2: { // 0x62f2c2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0062f2c5: { // 0x62f2c5: e886b71300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6484682u); flags=s.arithmetic_flags;
  }
  L0062f2ca: { // 0x62f2ca: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0062f2ce: { // 0x62f2ce: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L0062f2d4: { // 0x62f2d4: 8b4a48 MOV ECX,dword ptr [EDX + 0x48]
    s.cx = m.r32((s.dx+0x00000048u));
  }
  L0062f2d7: { // 0x62f2d7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062f2d9: { // 0x62f2d9: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0062f2dd: { // 0x62f2dd: 7f13 JG 0x0062f2f2
    if(integer::condition("JG",flags)) goto L0062f2f2;
  }
  L0062f2df: { // 0x62f2df: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0062f2e1: { // 0x62f2e1: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f2e3: { // 0x62f2e3: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0062f2e7: { // 0x62f2e7: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f2eb: { // 0x62f2eb: da742430 FIDIV dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0062f2ef: { // 0x62f2ef: da4a4c FIMUL dword ptr [EDX + 0x4c]
    const auto address=(s.dx+0x0000004cu);
    multiply_integer32(s.fp,m.r32(address));
  }
  L0062f2f2: { // 0x62f2f2: da7250 FIDIV dword ptr [EDX + 0x50]
    const auto address=(s.dx+0x00000050u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0062f2f5: { // 0x62f2f5: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0062f2f9: { // 0x62f2f9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f2fe: { // 0x62f2fe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f2ff: { // 0x62f2ff: dc4c2444 FMUL double ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.multiply64(read64(m,address));
  }
  L0062f303: { // 0x62f303: dd5c2434 FSTP double ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f307: { // 0x62f307: e8f461f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484748u); flags=s.arithmetic_flags;
  }
  L0062f30c: { // 0x62f30c: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0062f310: { // 0x62f310: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0062f314: { // 0x62f314: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0062f315: { // 0x62f315: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062f316: { // 0x62f316: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062f318: { // 0x62f318: e8a3d7e4ff CALL 0x0047cac0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cac0u,6484765u); flags=s.arithmetic_flags;
  }
  L0062f31d: { // 0x62f31d: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0062f321: { // 0x62f321: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0062f325: { // 0x62f325: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062f326: { // 0x62f326: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062f328: { // 0x62f328: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0062f32c: { // 0x62f32c: 0f8cedfeffff JL 0x0062f21f
    if(integer::condition("JL",flags)) goto L0062f21f;
  }
  L0062f332: { // 0x62f332: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L0062f336: { // 0x62f336: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0062f33a: { // 0x62f33a: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0062f33e: { // 0x62f33e: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0062f342: { // 0x62f342: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062f343: { // 0x62f343: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0062f345: { // 0x62f345: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0062f349: { // 0x62f349: 0f8cb6feffff JL 0x0062f205
    if(integer::condition("JL",flags)) goto L0062f205;
  }
  L0062f34f: { // 0x62f34f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062f350: { // 0x62f350: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062f351: { // 0x62f351: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062f352: { // 0x62f352: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062f353: { // 0x62f353: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0062f355: { // 0x62f355: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062f356: { // 0x62f356: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0062f360(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062f360: { // 0x62f360: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062f361: { // 0x62f361: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0062f363: { // 0x62f363: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0062f366: { // 0x62f366: 83ec50 SUB ESP,0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  L0062f369: { // 0x62f369: 0fbf5140 MOVSX EDX,word ptr [ECX + 0x40]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000040u)),16));
  }
  L0062f36d: { // 0x62f36d: 0fbf4142 MOVSX EAX,word ptr [ECX + 0x42]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000042u)),16));
  }
  L0062f371: { // 0x62f371: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062f372: { // 0x62f372: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062f373: { // 0x62f373: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062f374: { // 0x62f374: 8b7144 MOV ESI,dword ptr [ECX + 0x44]
    s.si = m.r32((s.cx+0x00000044u));
  }
  L0062f377: { // 0x62f377: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0062f379: { // 0x62f379: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0062f37b: { // 0x62f37b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062f37c: { // 0x62f37c: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0062f380: { // 0x62f380: 8d7c7201 LEA EDI,[EDX + ESI*0x2 + 0x1]
    s.di = (s.dx+(s.si * 0x00000002u)+0x00000001u);
  }
  L0062f384: { // 0x62f384: 8d747001 LEA ESI,[EAX + ESI*0x2 + 0x1]
    s.si = (s.ax+(s.si * 0x00000002u)+0x00000001u);
  }
  L0062f388: { // 0x62f388: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0062f38a: { // 0x62f38a: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0062f38e: { // 0x62f38e: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L0062f392: { // 0x62f392: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0062f396: { // 0x62f396: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0062f39a: { // 0x62f39a: 0f8d3e010000 JGE 0x0062f4de
    if(integer::condition("JGE",flags)) goto L0062f4de;
  }
  L0062f3a0: { // 0x62f3a0: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0062f3a4: { // 0x62f3a4: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0062f3a8: { // 0x62f3a8: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0062f3aa: { // 0x62f3aa: 0f8d1d010000 JGE 0x0062f4cd
    if(integer::condition("JGE",flags)) goto L0062f4cd;
  }
  L0062f3b0: { // 0x62f3b0: eb04 JMP 0x0062f3b6
    goto L0062f3b6;
  }
  L0062f3b2: { // 0x62f3b2: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0062f3b6: { // 0x62f3b6: 668b442414 MOV AX,word ptr [ESP + 0x14]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000014u)));
  }
  L0062f3bb: { // 0x62f3bb: 668b54241c MOV DX,word ptr [ESP + 0x1c]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000001cu)));
  }
  L0062f3c0: { // 0x62f3c0: 6689442410 MOV word ptr [ESP + 0x10],AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L0062f3c5: { // 0x62f3c5: 8d4140 LEA EAX,[ECX + 0x40]
    s.ax = (s.cx+0x00000040u);
  }
  L0062f3c8: { // 0x62f3c8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f3c9: { // 0x62f3c9: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f3ce: { // 0x62f3ce: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L0062f3d3: { // 0x62f3d3: e82861f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484952u); flags=s.arithmetic_flags;
  }
  L0062f3d8: { // 0x62f3d8: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0062f3da: { // 0x62f3da: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0062f3de: { // 0x62f3de: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f3df: { // 0x62f3df: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f3e4: { // 0x62f3e4: e81761f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6484969u); flags=s.arithmetic_flags;
  }
  L0062f3e9: { // 0x62f3e9: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0062f3eb: { // 0x62f3eb: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062f3ed: { // 0x62f3ed: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L0062f3f1: { // 0x62f3f1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062f3f3: { // 0x62f3f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f3f4: { // 0x62f3f4: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6484983u); flags=s.arithmetic_flags;
  }
  L0062f3f7: { // 0x62f3f7: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0062f3f9: { // 0x62f3f9: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0062f3fc: { // 0x62f3fc: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0062f3fe: { // 0x62f3fe: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0062f401: { // 0x62f401: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L0062f404: { // 0x62f404: 8d442454 LEA EAX,[ESP + 0x54]
    s.ax = (f.sp+0x00000054u);
  }
  L0062f408: { // 0x62f408: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f409: { // 0x62f409: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6485004u); flags=s.arithmetic_flags;
  }
  L0062f40c: { // 0x62f40c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0062f40e: { // 0x62f40e: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0062f411: { // 0x62f411: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0062f413: { // 0x62f413: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0062f415: { // 0x62f415: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062f418: { // 0x62f418: 89742444 MOV dword ptr [ESP + 0x44],ESI
    m.w32((f.sp+0x00000044u), s.si);
  }
  L0062f41c: { // 0x62f41c: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L0062f41e: { // 0x62f41e: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L0062f421: { // 0x62f421: 897c2448 MOV dword ptr [ESP + 0x48],EDI
    m.w32((f.sp+0x00000048u), s.di);
  }
  L0062f425: { // 0x62f425: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f429: { // 0x62f429: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0062f42b: { // 0x62f42b: 895c244c MOV dword ptr [ESP + 0x4c],EBX
    m.w32((f.sp+0x0000004cu), s.bx);
  }
  L0062f42f: { // 0x62f42f: db44244c FILD dword ptr [ESP + 0x4c]
    const auto address=(f.sp+0x0000004cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f433: { // 0x62f433: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f437: { // 0x62f437: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062f439: { // 0x62f439: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0062f43b: { // 0x62f43b: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L0062f43d: { // 0x62f43d: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0062f43f: { // 0x62f43f: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0062f441: { // 0x62f441: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L0062f443: { // 0x62f443: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L0062f445: { // 0x62f445: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0062f447: { // 0x62f447: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f44a: { // 0x62f44a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f44c: { // 0x62f44c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f44e: { // 0x62f44e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f450: { // 0x62f450: e82bace8ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6485077u); flags=s.arithmetic_flags;
  }
  L0062f455: { // 0x62f455: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0062f458: { // 0x62f458: e8f3b51300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6485085u); flags=s.arithmetic_flags;
  }
  L0062f45d: { // 0x62f45d: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0062f461: { // 0x62f461: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L0062f467: { // 0x62f467: 8b4a48 MOV ECX,dword ptr [EDX + 0x48]
    s.cx = m.r32((s.dx+0x00000048u));
  }
  L0062f46a: { // 0x62f46a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062f46c: { // 0x62f46c: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0062f470: { // 0x62f470: 7f13 JG 0x0062f485
    if(integer::condition("JG",flags)) goto L0062f485;
  }
  L0062f472: { // 0x62f472: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0062f474: { // 0x62f474: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062f476: { // 0x62f476: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0062f47a: { // 0x62f47a: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062f47e: { // 0x62f47e: da742428 FIDIV dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0062f482: { // 0x62f482: da4a4c FIMUL dword ptr [EDX + 0x4c]
    const auto address=(s.dx+0x0000004cu);
    multiply_integer32(s.fp,m.r32(address));
  }
  L0062f485: { // 0x62f485: da7250 FIDIV dword ptr [EDX + 0x50]
    const auto address=(s.dx+0x00000050u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0062f488: { // 0x62f488: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0062f48c: { // 0x62f48c: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0062f491: { // 0x62f491: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062f492: { // 0x62f492: dd5c242c FSTP double ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062f496: { // 0x62f496: e86560f1ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6485147u); flags=s.arithmetic_flags;
  }
  L0062f49b: { // 0x62f49b: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0062f49f: { // 0x62f49f: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0062f4a3: { // 0x62f4a3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0062f4a4: { // 0x62f4a4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062f4a5: { // 0x62f4a5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062f4a7: { // 0x62f4a7: e814d6e4ff CALL 0x0047cac0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047cac0u,6485164u); flags=s.arithmetic_flags;
  }
  L0062f4ac: { // 0x62f4ac: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0062f4b0: { // 0x62f4b0: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0062f4b4: { // 0x62f4b4: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062f4b5: { // 0x62f4b5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062f4b7: { // 0x62f4b7: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0062f4bb: { // 0x62f4bb: 0f8cf1feffff JL 0x0062f3b2
    if(integer::condition("JL",flags)) goto L0062f3b2;
  }
  L0062f4c1: { // 0x62f4c1: 8b742434 MOV ESI,dword ptr [ESP + 0x34]
    s.si = m.r32((f.sp+0x00000034u));
  }
  L0062f4c5: { // 0x62f4c5: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0062f4c9: { // 0x62f4c9: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0062f4cd: { // 0x62f4cd: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0062f4d1: { // 0x62f4d1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062f4d2: { // 0x62f4d2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0062f4d4: { // 0x62f4d4: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0062f4d8: { // 0x62f4d8: 0f8cc2feffff JL 0x0062f3a0
    if(integer::condition("JL",flags)) goto L0062f3a0;
  }
  L0062f4de: { // 0x62f4de: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062f4df: { // 0x62f4df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062f4e0: { // 0x62f4e0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062f4e1: { // 0x62f4e1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062f4e2: { // 0x62f4e2: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0062f4e4: { // 0x62f4e4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062f4e5: { // 0x62f4e5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
