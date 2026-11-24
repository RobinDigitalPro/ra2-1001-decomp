#include "recovered/recovery_b821_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b821 {
namespace {
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007b650(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0007caa0(Memory&,State&,Frame&,const Operations&);
void f_0007cac0(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0007cb10(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
void f_000346e0(Memory&,State&,Frame&,const Operations&);
void f_00037560(Memory&,State&,Frame&,const Operations&);
void f_0001b630(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_001cd850(Memory&,State&,Frame&,const Operations&);
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
void f_00157070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557070: { // 0x00557070: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00557073: { // 0x00557073: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00557077: { // 0x00557077: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557078: { // 0x00557078: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055707a: { // 0x0055707a: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0055707d: { // 0x0055707d: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00557081: { // 0x00557081: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  L00557085: { // 0x00557085: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557086: { // 0x00557086: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055708c: { // 0x0055708c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055708e: { // 0x0055708e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00557090: { // 0x00557090: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00557093: { // 0x00557093: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557094: { // 0x00557094: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055709a: { // 0x0055709a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055709c: { // 0x0055709c: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055709f: { // 0x0055709f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005570a1: { // 0x005570a1: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005570a4: { // 0x005570a4: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L005570a7: { // 0x005570a7: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005570a9: { // 0x005570a9: 7815 JS 0x005570c0
    if(integer::condition("JS",flags)) goto L005570c0;
  }
  L005570ab: { // 0x005570ab: 3b0d5ca98100 CMP ECX,dword ptr [0x0081a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  L005570b1: { // 0x005570b1: 7d0d JGE 0x005570c0
    if(integer::condition("JGE",flags)) goto L005570c0;
  }
  L005570b3: { // 0x005570b3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005570b9: { // 0x005570b9: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L005570bc: { // 0x005570bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005570be: { // 0x005570be: 7518 JNZ 0x005570d8
    if(integer::condition("JNZ",flags)) goto L005570d8;
  }
  L005570c0: { // 0x005570c0: 6689742410 MOV word ptr [ESP + 0x10],SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L005570c5: { // 0x005570c5: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L005570ca: { // 0x005570ca: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005570ce: { // 0x005570ce: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L005570d3: { // 0x005570d3: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005570d8: { // 0x005570d8: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  L005570dc: { // 0x005570dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005570dd: { // 0x005570dd: e8de91f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5599458u); flags=s.arithmetic_flags;
  }
  L005570e2: { // 0x005570e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005570e3: { // 0x005570e3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005570e6: { // 0x005570e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX,0x9
    s.dx = integer::shift(s.dx,0x00000009u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x005454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX,dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x005454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX,dword ptr [ECX + EDX*0x4]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x005454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc],SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe],AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000346e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004346e0: { // 0x4346e0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L004346e4: { // 0x4346e4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004346e6: { // 0x4346e6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004346ea: { // 0x4346ea: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004346ec: { // 0x4346ec: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004346f0: { // 0x4346f0: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L004346f3: { // 0x4346f3: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L004346f6: { // 0x4346f6: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00037560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00437560: { // 0x437560: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00437562: { // 0x437562: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L00437566: { // 0x437566: d901 FLD float ptr [ECX]
    const auto address=(s.cx);
    s.fp.load32(m.r32(address));
  }
  L00437568: { // 0x437568: d800 FADD float ptr [EAX]
    const auto address=(s.ax);
    s.fp.add32(m.r32(address));
  }
  L0043756a: { // 0x43756a: d918 FSTP float ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0043756c: { // 0x43756c: d94104 FLD float ptr [ECX + 0x4]
    const auto address=(s.cx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0043756f: { // 0x43756f: d84004 FADD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.add32(m.r32(address));
  }
  L00437572: { // 0x437572: d95804 FSTP float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00437575: { // 0x437575: d94108 FLD float ptr [ECX + 0x8]
    const auto address=(s.cx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00437578: { // 0x437578: d84008 FADD float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    s.fp.add32(m.r32(address));
  }
  L0043757b: { // 0x43757b: d95808 FSTP float ptr [EAX + 0x8]
    const auto address=(s.ax+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0043757e: { // 0x43757e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0001b630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b630: { // 0x41b630: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0041b634: { // 0x41b634: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041b636: { // 0x41b636: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0041b63a: { // 0x41b63a: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b63c: { // 0x41b63c: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0041b640: { // 0x41b640: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0041b643: { // 0x41b643: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0041b646: { // 0x41b646: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x0062fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x0062fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI,0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX,0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x0062fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x0062fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI,EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x0062fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x0062fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x0062fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x0062fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI,dword ptr [EDX + ECX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX,[EDX + ECX*0x4 + 0xc]
    s.ax = (s.dx+(s.cx * 0x00000004u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX,dword ptr [EDX + ECX*0x4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI,dword ptr [EDX + EAX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX,0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x0062fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 0x4],0x0
    m.w32((s.dx+0x00000004u), 0x00000000u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX,0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x0062fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 0x8],0x0
    m.w32((s.dx+0x00000008u), 0x00000000u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX,EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x0062fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_001cd850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd850: { // 0x5cd850: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cd854: { // 0x5cd854: 81c188000000 ADD ECX,0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L005cd85a: { // 0x5cd85a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005cd85c: { // 0x5cd85c: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L005cd85e: { // 0x5cd85e: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cd861: { // 0x5cd861: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L005cd864: { // 0x5cd864: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cd867: { // 0x5cd867: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L005cd86a: { // 0x5cd86a: c20400 RET 0x4
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
case 4705040u:f_0007cb10(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
case 4409056u:f_000346e0(m,s,child,{});break;
case 4420960u:f_00037560(m,s,child,{});break;
case 4306480u:f_0001b630(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
case 6084688u:f_001cd850(m,s,child,{});break;
default:throw std::domain_error("recovery821 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00601120(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00601120: { // 0x601120: 81ec24010000 SUB ESP,0x124
    f.sp = integer::sub(f.sp,0x00000124u,32,flags);
  }
  L00601126: { // 0x601126: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00601127: { // 0x601127: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00601128: { // 0x601128: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0060112a: { // 0x60112a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060112b: { // 0x60112b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060112c: { // 0x60112c: 8d8588000000 LEA EAX,[EBP + 0x88]
    s.ax = (s.bp+0x00000088u);
  }
  L00601132: { // 0x601132: 8b8d88000000 MOV ECX,dword ptr [EBP + 0x88]
    s.cx = m.r32((s.bp+0x00000088u));
  }
  L00601138: { // 0x601138: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0060113c: { // 0x60113c: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00601142: { // 0x601142: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00601145: { // 0x601145: db8120130000 FILD dword ptr [ECX + 0x1320]
    const auto address=(s.cx+0x00001320u);
    s.fp.load_integer32(m.r32(address));
  }
  L0060114b: { // 0x60114b: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0060114e: { // 0x60114e: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00601152: { // 0x601152: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00601156: { // 0x601156: d8ad04010000 FSUBR float ptr [EBP + 0x104]
    const auto address=(s.bp+0x00000104u);
    ra2::platform::x87_b61::reverse_subtract32(s.fp,m.r32(address));
  }
  L0060115c: { // 0x60115c: d99d04010000 FSTP float ptr [EBP + 0x104]
    const auto address=(s.bp+0x00000104u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601162: { // 0x601162: d985fc000000 FLD float ptr [EBP + 0xfc]
    const auto address=(s.bp+0x000000fcu);
    s.fp.load32(m.r32(address));
  }
  L00601168: { // 0x601168: d95c2434 FSTP float ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0060116c: { // 0x60116c: d98500010000 FLD float ptr [EBP + 0x100]
    const auto address=(s.bp+0x00000100u);
    s.fp.load32(m.r32(address));
  }
  L00601172: { // 0x601172: d95c2438 FSTP float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601176: { // 0x601176: d98504010000 FLD float ptr [EBP + 0x104]
    const auto address=(s.bp+0x00000104u);
    s.fp.load32(m.r32(address));
  }
  L0060117c: { // 0x60117c: d95c243c FSTP float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601180: { // 0x601180: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00601184: { // 0x601184: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L0060118a: { // 0x60118a: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0060118e: { // 0x60118e: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L00601192: { // 0x601192: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601196: { // 0x601196: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0060119a: { // 0x60119a: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0060119e: { // 0x60119e: d944243c FLD float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load32(m.r32(address));
  }
  L006011a2: { // 0x6011a2: db8220130000 FILD dword ptr [EDX + 0x1320]
    const auto address=(s.dx+0x00001320u);
    s.fp.load_integer32(m.r32(address));
  }
  L006011a8: { // 0x6011a8: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L006011aa: { // 0x6011aa: d95c243c FSTP float ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006011ae: { // 0x6011ae: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L006011b2: { // 0x6011b2: e899981600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6295991u); flags=s.arithmetic_flags;
  }
  L006011b7: { // 0x6011b7: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L006011bb: { // 0x6011bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006011bc: { // 0x6011bc: e88f981600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296001u); flags=s.arithmetic_flags;
  }
  L006011c1: { // 0x6011c1: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L006011c5: { // 0x6011c5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006011c6: { // 0x6011c6: e885981600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296011u); flags=s.arithmetic_flags;
  }
  L006011cb: { // 0x6011cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006011cc: { // 0x6011cc: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L006011d0: { // 0x6011d0: e80b35e3ff CALL 0x004346e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004346e0u,6296021u); flags=s.arithmetic_flags;
  }
  L006011d5: { // 0x6011d5: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L006011d9: { // 0x6011d9: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006011dd: { // 0x6011dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006011de: { // 0x6011de: e87d63e3ff CALL 0x00437560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00437560u,6296035u); flags=s.arithmetic_flags;
  }
  L006011e3: { // 0x6011e3: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L006011e7: { // 0x6011e7: e864981600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296044u); flags=s.arithmetic_flags;
  }
  L006011ec: { // 0x6011ec: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L006011f0: { // 0x6011f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006011f1: { // 0x6011f1: e85a981600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296054u); flags=s.arithmetic_flags;
  }
  L006011f6: { // 0x6011f6: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L006011fa: { // 0x6011fa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006011fb: { // 0x6011fb: e850981600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296064u); flags=s.arithmetic_flags;
  }
  L00601200: { // 0x601200: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00601201: { // 0x601201: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L00601205: { // 0x601205: e8d634e3ff CALL 0x004346e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004346e0u,6296074u); flags=s.arithmetic_flags;
  }
  L0060120a: { // 0x60120a: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0060120e: { // 0x60120e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060120f: { // 0x60120f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00601214: { // 0x601214: e8575ef5ff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6296089u); flags=s.arithmetic_flags;
  }
  L00601219: { // 0x601219: 8b1570e0a500 MOV EDX,dword ptr [0x00a5e070]
    s.dx = m.r32((0x00a5e070u));
  }
  L0060121f: { // 0x60121f: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00601223: { // 0x601223: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00601228: { // 0x601228: 8d1c10 LEA EBX,[EAX + EDX*0x1]
    s.bx = (s.ax+(s.dx * 0x00000001u));
  }
  L0060122b: { // 0x60122b: 8d442450 LEA EAX,[ESP + 0x50]
    s.ax = (f.sp+0x00000050u);
  }
  L0060122f: { // 0x60122f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00601230: { // 0x601230: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L00601234: { // 0x601234: e85742f4ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6296121u); flags=s.arithmetic_flags;
  }
  L00601239: { // 0x601239: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0060123b: { // 0x60123b: bf00010000 MOV EDI,0x100
    s.di = 0x00000100u;
  }
  L00601240: { // 0x601240: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L00601245: { // 0x601245: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L0060124a: { // 0x60124a: 85be40010000 TEST dword ptr [ESI + 0x140],EDI
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.di),32,flags);
  }
  L00601250: { // 0x601250: 7517 JNZ 0x00601269
    if(integer::condition("JNZ",flags)) goto L00601269;
  }
  L00601252: { // 0x601252: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L00601256: { // 0x601256: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00601257: { // 0x601257: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0060125c: { // 0x60125c: e82f42f4ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6296161u); flags=s.arithmetic_flags;
  }
  L00601261: { // 0x601261: 85b840010000 TEST dword ptr [EAX + 0x140],EDI
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.di),32,flags);
  }
  L00601267: { // 0x601267: 7420 JZ 0x00601289
    if(integer::condition("JZ",flags)) goto L00601289;
  }
  L00601269: { // 0x601269: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L0060126d: { // 0x60126d: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0060126f: { // 0x60126f: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00601273: { // 0x601273: 7c0b JL 0x00601280
    if(integer::condition("JL",flags)) goto L00601280;
  }
  L00601275: { // 0x601275: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00601277: { // 0x601277: 7d10 JGE 0x00601289
    if(integer::condition("JGE",flags)) goto L00601289;
  }
  L00601279: { // 0x601279: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L0060127e: { // 0x60127e: eb09 JMP 0x00601289
    goto L00601289;
  }
  L00601280: { // 0x601280: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00601282: { // 0x601282: 7c05 JL 0x00601289
    if(integer::condition("JL",flags)) goto L00601289;
  }
  L00601284: { // 0x601284: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L00601289: { // 0x601289: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L0060128d: { // 0x60128d: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0060128f: { // 0x60128f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00601291: { // 0x601291: 757c JNZ 0x0060130f
    if(integer::condition("JNZ",flags)) goto L0060130f;
  }
  L00601293: { // 0x601293: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00601297: { // 0x601297: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00601299: { // 0x601299: 7574 JNZ 0x0060130f
    if(integer::condition("JNZ",flags)) goto L0060130f;
  }
  L0060129b: { // 0x60129b: db442440 FILD dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load_integer32(m.r32(address));
  }
  L0060129f: { // 0x60129f: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L006012a3: { // 0x6012a3: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L006012a5: { // 0x6012a5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006012a7: { // 0x6012a7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006012aa: { // 0x6012aa: 7561 JNZ 0x0060130d
    if(integer::condition("JNZ",flags)) goto L0060130d;
  }
  L006012ac: { // 0x6012ac: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L006012b0: { // 0x6012b0: d825a87a7800 FSUB float ptr [0x00787aa8]
    const auto address=(0x00787aa8u);
    s.fp.subtract32(m.r32(address));
  }
  L006012b6: { // 0x6012b6: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L006012b8: { // 0x6012b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006012ba: { // 0x6012ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L006012bd: { // 0x6012bd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006012bf: { // 0x6012bf: 744e JZ 0x0060130f
    if(integer::condition("JZ",flags)) goto L0060130f;
  }
  L006012c1: { // 0x6012c1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006012c3: { // 0x6012c3: e8e800e7ff CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,6296264u); flags=s.arithmetic_flags;
  }
  L006012c8: { // 0x6012c8: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006012ca: { // 0x6012ca: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006012cc: { // 0x6012cc: 750f JNZ 0x006012dd
    if(integer::condition("JNZ",flags)) goto L006012dd;
  }
  L006012ce: { // 0x6012ce: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006012d0: { // 0x6012d0: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L006012d2: { // 0x6012d2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006012d4: { // 0x6012d4: e86741e7ff CALL 0x00475440
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475440u,6296281u); flags=s.arithmetic_flags;
  }
  L006012d9: { // 0x6012d9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006012db: { // 0x6012db: 7432 JZ 0x0060130f
    if(integer::condition("JZ",flags)) goto L0060130f;
  }
  L006012dd: { // 0x6012dd: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006012df: { // 0x6012df: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006012e1: { // 0x6012e1: 742c JZ 0x0060130f
    if(integer::condition("JZ",flags)) goto L0060130f;
  }
  L006012e3: { // 0x6012e3: 8b9718040000 MOV EDX,dword ptr [EDI + 0x418]
    s.dx = m.r32((s.di+0x00000418u));
  }
  L006012e9: { // 0x6012e9: 8a8259130000 MOV AL,byte ptr [EDX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001359u)));
  }
  L006012ef: { // 0x6012ef: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006012f1: { // 0x6012f1: 740b JZ 0x006012fe
    if(integer::condition("JZ",flags)) goto L006012fe;
  }
  L006012f3: { // 0x6012f3: 83bfec04000008 CMP dword ptr [EDI + 0x4ec],0x8
    (void)integer::sub(m.r32((s.di+0x000004ecu)),0x00000008u,32,flags);
  }
  L006012fa: { // 0x6012fa: 7c02 JL 0x006012fe
    if(integer::condition("JL",flags)) goto L006012fe;
  }
  L006012fc: { // 0x6012fc: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006012fe: { // 0x6012fe: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00601300: { // 0x601300: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00601302: { // 0x601302: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),6296325u); flags=s.arithmetic_flags;
  }
  L00601305: { // 0x601305: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00601307: { // 0x601307: 7406 JZ 0x0060130f
    if(integer::condition("JZ",flags)) goto L0060130f;
  }
  L00601309: { // 0x601309: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L0060130b: { // 0x60130b: eb02 JMP 0x0060130f
    goto L0060130f;
  }
  L0060130d: { // 0x60130d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0060130f: { // 0x60130f: db442440 FILD dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load_integer32(m.r32(address));
  }
  L00601313: { // 0x601313: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601317: { // 0x601317: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0060131b: { // 0x60131b: d85c2420 FCOMP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0060131f: { // 0x60131f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00601321: { // 0x601321: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L00601325: { // 0x601325: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00601328: { // 0x601328: 7515 JNZ 0x0060133f
    if(integer::condition("JNZ",flags)) goto L0060133f;
  }
  L0060132a: { // 0x60132a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060132c: { // 0x60132c: 7515 JNZ 0x00601343
    if(integer::condition("JNZ",flags)) goto L00601343;
  }
  L0060132e: { // 0x60132e: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00601332: { // 0x601332: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00601334: { // 0x601334: 751f JNZ 0x00601355
    if(integer::condition("JNZ",flags)) goto L00601355;
  }
  L00601336: { // 0x601336: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00601338: { // 0x601338: 7530 JNZ 0x0060136a
    if(integer::condition("JNZ",flags)) goto L0060136a;
  }
  L0060133a: { // 0x60133a: e939010000 JMP 0x00601478
    goto L00601478;
  }
  L0060133f: { // 0x60133f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00601341: { // 0x601341: 740a JZ 0x0060134d
    if(integer::condition("JZ",flags)) goto L0060134d;
  }
  L00601343: { // 0x601343: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L00601347: { // 0x601347: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0060134b: { // 0x60134b: eb3f JMP 0x0060138c
    goto L0060138c;
  }
  L0060134d: { // 0x60134d: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00601351: { // 0x601351: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00601353: { // 0x601353: 7415 JZ 0x0060136a
    if(integer::condition("JZ",flags)) goto L0060136a;
  }
  L00601355: { // 0x601355: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00601359: { // 0x601359: 83c1ec ADD ECX,-0x14
    s.cx = integer::add(s.cx,0xffffffecu,32,flags);
  }
  L0060135c: { // 0x60135c: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00601360: { // 0x601360: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00601364: { // 0x601364: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601368: { // 0x601368: eb22 JMP 0x0060138c
    goto L0060138c;
  }
  L0060136a: { // 0x60136a: 8b542440 MOV EDX,dword ptr [ESP + 0x40]
    s.dx = m.r32((f.sp+0x00000040u));
  }
  L0060136e: { // 0x60136e: 83c29c ADD EDX,-0x64
    s.dx = integer::add(s.dx,0xffffff9cu,32,flags);
  }
  L00601371: { // 0x601371: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L00601375: { // 0x601375: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L00601379: { // 0x601379: d85c242c FCOMP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.compare_pop32(m.r32(address));
  }
  L0060137d: { // 0x60137d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0060137f: { // 0x60137f: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00601382: { // 0x601382: 7408 JZ 0x0060138c
    if(integer::condition("JZ",flags)) goto L0060138c;
  }
  L00601384: { // 0x601384: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00601388: { // 0x601388: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0060138c: { // 0x60138c: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00601390: { // 0x601390: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00601391: { // 0x601391: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00601397: { // 0x601397: e8b4b30900 CALL 0x0069c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c750u,6296476u); flags=s.arithmetic_flags;
  }
  L0060139c: { // 0x60139c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0060139e: { // 0x60139e: 8d8c24d4000000 LEA ECX,[ESP + 0xd4]
    s.cx = (f.sp+0x000000d4u);
  }
  L006013a5: { // 0x6013a5: e876c51000 CALL 0x0070d920
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070d920u,6296490u); flags=s.arithmetic_flags;
  }
  L006013aa: { // 0x6013aa: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006013af: { // 0x6013af: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006013b1: { // 0x6013b1: 8d7c2474 LEA EDI,[ESP + 0x74]
    s.di = (f.sp+0x00000074u);
  }
  L006013b5: { // 0x6013b5: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L006013b9: { // 0x6013b9: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006013bb: { // 0x6013bb: 8d8c2404010000 LEA ECX,[ESP + 0x104]
    s.cx = (f.sp+0x00000104u);
  }
  L006013c2: { // 0x6013c2: e859cef8ff CALL 0x0058e220
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e220u,6296519u); flags=s.arithmetic_flags;
  }
  L006013c7: { // 0x6013c7: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L006013cc: { // 0x6013cc: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006013ce: { // 0x6013ce: 8dbc24a4000000 LEA EDI,[ESP + 0xa4]
    s.di = (f.sp+0x000000a4u);
  }
  L006013d5: { // 0x6013d5: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L006013d9: { // 0x6013d9: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006013db: { // 0x6013db: d9442438 FLD float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load32(m.r32(address));
  }
  L006013df: { // 0x6013df: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L006013e1: { // 0x6013e1: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L006013e5: { // 0x6013e5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006013e6: { // 0x6013e6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006013e7: { // 0x6013e7: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L006013eb: { // 0x6013eb: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006013ee: { // 0x6013ee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006013ef: { // 0x6013ef: e81c61e3ff CALL 0x00437510
    s.arithmetic_flags=flags; invoke(m,s,f,0x00437510u,6296564u); flags=s.arithmetic_flags;
  }
  L006013f4: { // 0x6013f4: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006013f8: { // 0x6013f8: 8d542468 LEA EDX,[ESP + 0x68]
    s.dx = (f.sp+0x00000068u);
  }
  L006013fc: { // 0x6013fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006013fd: { // 0x6013fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006013fe: { // 0x6013fe: 8d8c24ac000000 LEA ECX,[ESP + 0xac]
    s.cx = (f.sp+0x000000acu);
  }
  L00601405: { // 0x601405: e8c6c6f8ff CALL 0x0058dad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058dad0u,6296586u); flags=s.arithmetic_flags;
  }
  L0060140a: { // 0x60140a: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0060140c: { // 0x60140c: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L00601411: { // 0x601411: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00601415: { // 0x601415: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00601419: { // 0x601419: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060141c: { // 0x60141c: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00601420: { // 0x601420: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00601423: { // 0x601423: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00601427: { // 0x601427: e80461e3ff CALL 0x00437530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00437530u,6296620u); flags=s.arithmetic_flags;
  }
  L0060142c: { // 0x60142c: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L00601430: { // 0x601430: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L00601434: { // 0x601434: 8d54245c LEA EDX,[ESP + 0x5c]
    s.dx = (f.sp+0x0000005cu);
  }
  L00601438: { // 0x601438: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0060143a: { // 0x60143a: d95c241c FSTP float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0060143e: { // 0x60143e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060143f: { // 0x60143f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00601440: { // 0x601440: 8d4c247c LEA ECX,[ESP + 0x7c]
    s.cx = (f.sp+0x0000007cu);
  }
  L00601444: { // 0x601444: e887c6f8ff CALL 0x0058dad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058dad0u,6296649u); flags=s.arithmetic_flags;
  }
  L00601449: { // 0x601449: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0060144b: { // 0x60144b: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0060144f: { // 0x60144f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00601452: { // 0x601452: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00601456: { // 0x601456: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00601459: { // 0x601459: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0060145d: { // 0x60145d: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L00601461: { // 0x601461: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00601463: { // 0x601463: d95c2438 FSTP float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00601467: { // 0x601467: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00601469: { // 0x601469: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0060146d: { // 0x60146d: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L00601471: { // 0x601471: c6852101000001 MOV byte ptr [EBP + 0x121],0x1
    m.w8((s.bp+0x00000121u), 0x00000001u);
  }
  L00601478: { // 0x601478: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0060147c: { // 0x60147c: e8cf951600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296705u); flags=s.arithmetic_flags;
  }
  L00601481: { // 0x601481: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L00601485: { // 0x601485: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00601486: { // 0x601486: e8c5951600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296715u); flags=s.arithmetic_flags;
  }
  L0060148b: { // 0x60148b: d9442428 FLD float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load32(m.r32(address));
  }
  L0060148f: { // 0x60148f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00601490: { // 0x601490: e8bb951600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6296725u); flags=s.arithmetic_flags;
  }
  L00601495: { // 0x601495: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00601496: { // 0x601496: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0060149a: { // 0x60149a: e891a1e1ff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,6296735u); flags=s.arithmetic_flags;
  }
  L0060149f: { // 0x60149f: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L006014a2: { // 0x6014a2: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L006014a6: { // 0x6014a6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006014a7: { // 0x6014a7: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006014a9: { // 0x6014a9: ff909c010000 CALL dword ptr [EAX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),6296751u); flags=s.arithmetic_flags;
  }
  L006014af: { // 0x6014af: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006014b5: { // 0x6014b5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006014b7: { // 0x6014b7: 68feffff7f PUSH 0x7ffffffe
    f.push(m,0x7ffffffeu);
  }
  L006014bc: { // 0x6014bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006014bd: { // 0x6014bd: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L006014c3: { // 0x6014c3: e878e90200 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6296776u); flags=s.arithmetic_flags;
  }
  L006014c8: { // 0x6014c8: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L006014cc: { // 0x6014cc: 8b8d98000000 MOV ECX,dword ptr [EBP + 0x98]
    s.cx = m.r32((s.bp+0x00000098u));
  }
  L006014d2: { // 0x6014d2: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L006014d6: { // 0x6014d6: dc0d80727800 FMUL double ptr [0x00787280]
    const auto address=(0x00787280u);
    s.fp.multiply64(read64(m,address));
  }
  L006014dc: { // 0x6014dc: dc0df8c07800 FMUL double ptr [0x0078c0f8]
    const auto address=(0x0078c0f8u);
    s.fp.multiply64(read64(m,address));
  }
  L006014e2: { // 0x6014e2: dc8180020000 FADD double ptr [ECX + 0x280]
    const auto address=(s.cx+0x00000280u);
    s.fp.add64(read64(m,address));
  }
  L006014e8: { // 0x6014e8: dc85a8000000 FADD double ptr [EBP + 0xa8]
    const auto address=(s.bp+0x000000a8u);
    s.fp.add64(read64(m,address));
  }
  L006014ee: { // 0x6014ee: dd95a8000000 FST double ptr [EBP + 0xa8]
    const auto address=(s.bp+0x000000a8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L006014f4: { // 0x6014f4: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006014fa: { // 0x6014fa: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006014fc: { // 0x6014fc: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006014ff: { // 0x6014ff: 7541 JNZ 0x00601542
    if(integer::condition("JNZ",flags)) goto L00601542;
  }
  L00601501: { // 0x601501: 8b8998020000 MOV ECX,dword ptr [ECX + 0x298]
    s.cx = m.r32((s.cx+0x00000298u));
  }
  L00601507: { // 0x601507: 8b85a0000000 MOV EAX,dword ptr [EBP + 0xa0]
    s.ax = m.r32((s.bp+0x000000a0u));
  }
  L0060150d: { // 0x60150d: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00601510: { // 0x601510: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00601512: { // 0x601512: 7d1e JGE 0x00601532
    if(integer::condition("JGE",flags)) goto L00601532;
  }
  L00601514: { // 0x601514: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00601515: { // 0x601515: 89b5a8000000 MOV dword ptr [EBP + 0xa8],ESI
    m.w32((s.bp+0x000000a8u), s.si);
  }
  L0060151b: { // 0x60151b: 89b5ac000000 MOV dword ptr [EBP + 0xac],ESI
    m.w32((s.bp+0x000000acu), s.si);
  }
  L00601521: { // 0x601521: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00601522: { // 0x601522: 8985a0000000 MOV dword ptr [EBP + 0xa0],EAX
    m.w32((s.bp+0x000000a0u), s.ax);
  }
  L00601528: { // 0x601528: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00601529: { // 0x601529: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060152a: { // 0x60152a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060152b: { // 0x60152b: 81c424010000 ADD ESP,0x124
    f.sp = integer::add(f.sp,0x00000124u,32,flags);
  }
  L00601531: { // 0x601531: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00601532: { // 0x601532: 89b5a8000000 MOV dword ptr [EBP + 0xa8],ESI
    m.w32((s.bp+0x000000a8u), s.si);
  }
  L00601538: { // 0x601538: c785ac0000000000f03f MOV dword ptr [EBP + 0xac],0x3ff00000
    m.w32((s.bp+0x000000acu), 0x3ff00000u);
  }
  L00601542: { // 0x601542: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00601543: { // 0x601543: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00601544: { // 0x601544: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00601545: { // 0x601545: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00601546: { // 0x601546: 81c424010000 ADD ESP,0x124
    f.sp = integer::add(f.sp,0x00000124u,32,flags);
  }
  L0060154c: { // 0x60154c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00602000(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00602000: { // 0x602000: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00602003: { // 0x602003: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00602004: { // 0x602004: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00602006: { // 0x602006: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L0060200c: { // 0x60200c: 8b80e4020000 MOV EAX,dword ptr [EAX + 0x2e4]
    s.ax = m.r32((s.ax+0x000002e4u));
  }
  L00602012: { // 0x602012: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  L00602015: { // 0x602015: 0f84de000000 JZ 0x006020f9
    if(integer::condition("JZ",flags)) goto L006020f9;
  }
  L0060201b: { // 0x60201b: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0060201c: { // 0x60201c: 0f84cb000000 JZ 0x006020ed
    if(integer::condition("JZ",flags)) goto L006020ed;
  }
  L00602022: { // 0x602022: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00602023: { // 0x602023: 0f85d7000000 JNZ 0x00602100
    if(integer::condition("JNZ",flags)) goto L00602100;
  }
  L00602029: { // 0x602029: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L0060202f: { // 0x60202f: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00602035: { // 0x602035: 8d8688000000 LEA EAX,[ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L0060203b: { // 0x60203b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060203c: { // 0x60203c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060203d: { // 0x60203d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0060203f: { // 0x60203f: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00602041: { // 0x602041: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00602043: { // 0x602043: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00602047: { // 0x602047: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L0060204a: { // 0x60204a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0060204d: { // 0x60204d: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00602050: { // 0x602050: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00602054: { // 0x602054: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00602056: { // 0x602056: 8b7f08 MOV EDI,dword ptr [EDI + 0x8]
    s.di = m.r32((s.di+0x00000008u));
  }
  L00602059: { // 0x602059: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0060205d: { // 0x60205d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00602060: { // 0x602060: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00602064: { // 0x602064: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00602068: { // 0x602068: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0060206c: { // 0x60206c: 7524 JNZ 0x00602092
    if(integer::condition("JNZ",flags)) goto L00602092;
  }
  L0060206e: { // 0x60206e: 8b9ef0000000 MOV EBX,dword ptr [ESI + 0xf0]
    s.bx = m.r32((s.si+0x000000f0u));
  }
  L00602074: { // 0x602074: 8b86f8000000 MOV EAX,dword ptr [ESI + 0xf8]
    s.ax = m.r32((s.si+0x000000f8u));
  }
  L0060207a: { // 0x60207a: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L0060207c: { // 0x60207c: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00602080: { // 0x602080: 8b8ef4000000 MOV ECX,dword ptr [ESI + 0xf4]
    s.cx = m.r32((s.si+0x000000f4u));
  }
  L00602086: { // 0x602086: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00602088: { // 0x602088: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0060208a: { // 0x60208a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0060208e: { // 0x60208e: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00602092: { // 0x602092: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L00602098: { // 0x602098: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0060209e: { // 0x60209e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006020a0: { // 0x6020a0: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006020a3: { // 0x6020a3: 7532 JNZ 0x006020d7
    if(integer::condition("JNZ",flags)) goto L006020d7;
  }
  L006020a5: { // 0x6020a5: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L006020a9: { // 0x6020a9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006020aa: { // 0x6020aa: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006020af: { // 0x6020af: e8bc4ff5ff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6299828u); flags=s.arithmetic_flags;
  }
  L006020b4: { // 0x6020b4: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L006020b8: { // 0x6020b8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006020bd: { // 0x6020bd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006020be: { // 0x6020be: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006020c0: { // 0x6020c0: e8ab4ff5ff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6299845u); flags=s.arithmetic_flags;
  }
  L006020c5: { // 0x6020c5: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L006020c7: { // 0x6020c7: 7e0e JLE 0x006020d7
    if(integer::condition("JLE",flags)) goto L006020d7;
  }
  L006020c9: { // 0x6020c9: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006020cb: { // 0x6020cb: 88861d010000 MOV byte ptr [ESI + 0x11d],AL
    m.w8((s.si+0x0000011du), (s.ax & 0xffu));
  }
  L006020d1: { // 0x6020d1: 888621010000 MOV byte ptr [ESI + 0x121],AL
    m.w8((s.si+0x00000121u), (s.ax & 0xffu));
  }
  L006020d7: { // 0x6020d7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006020d9: { // 0x6020d9: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006020dd: { // 0x6020dd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006020de: { // 0x6020de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006020e0: { // 0x6020e0: ff909c010000 CALL dword ptr [EAX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000019cu)),6299878u); flags=s.arithmetic_flags;
  }
  L006020e6: { // 0x6020e6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006020e7: { // 0x6020e7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006020e8: { // 0x6020e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006020e9: { // 0x6020e9: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006020ec: { // 0x6020ec: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006020ed: { // 0x6020ed: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006020ef: { // 0x6020ef: e81cfdffff CALL 0x00601e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601e10u,6299892u); flags=s.arithmetic_flags;
  }
  L006020f4: { // 0x6020f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006020f5: { // 0x6020f5: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006020f8: { // 0x6020f8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006020f9: { // 0x6020f9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006020fb: { // 0x6020fb: e8c0fbffff CALL 0x00601cc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00601cc0u,6299904u); flags=s.arithmetic_flags;
  }
  L00602100: { // 0x602100: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00602101: { // 0x602101: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00602104: { // 0x602104: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
