#include "recovered/recovery_b1104_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1104 {
namespace {
void f_00176620(Memory&,State&,Frame&,const Operations&);
void f_00176560(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00176620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00576620: { // 0x576620: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00576621: { // 0x576621: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L00576623: { // 0x576623: 83e4f8 AND ESP, 0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00576626: { // 0x576626: 83ec14 SUB ESP, 0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L00576629: { // 0x576629: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057662a: { // 0x57662a: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0057662c: { // 0x57662c: 803e00 CMP byte ptr [ESI], 0
    (void)integer::sub(m.r8((s.si)),0u,8,flags);
  }
  L0057662f: { // 0x57662f: 740d JZ 0x57663e
    if(integer::condition("JZ",flags)) goto L0057663e;
  }
  L00576631: { // 0x576631: c60600 MOV byte ptr [ESI], 0
    m.w8((s.si), 0u);
  }
  L00576634: { // 0x576634: dd4608 FLD qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    s.fp.load64(read64(m,address));
  }
  L00576637: { // 0x576637: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00576638: { // 0x576638: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L0057663a: { // 0x57663a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057663b: { // 0x57663b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0057663c: { // 0x57663c: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057663e: { // 0x57663e: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727809u); flags=s.arithmetic_flags;
  }
  L00576641: { // 0x576641: dcc0 FADD st(0), st(0)
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576643: { // 0x576643: dc2508577800 FSUB qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576649: { // 0x576649: dd5c2408 FSTP qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057664d: { // 0x57664d: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727824u); flags=s.arithmetic_flags;
  }
  L00576650: { // 0x576650: dcc0 FADD st(0), st(0)
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576652: { // 0x576652: dc2508577800 FSUB qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576658: { // 0x576658: dd542410 FST qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057665c: { // 0x57665c: d9c0 FLD st(0)
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0057665e: { // 0x57665e: dec9 FMULP st(1)
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L00576660: { // 0x576660: dd442408 FLD qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.load64(read64(m,address));
  }
  L00576664: { // 0x576664: dc4c2408 FMUL qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.multiply64(read64(m,address));
  }
  L00576668: { // 0x576668: dec1 FADDP st(1)
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057666a: { // 0x57666a: dc1508577800 FCOM qword ptr [0x785708]
    const auto address=(0x00785708u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00576670: { // 0x576670: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00576672: { // 0x576672: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00576675: { // 0x576675: 74c5 JZ 0x57663c
    if(integer::condition("JZ",flags)) goto L0057663c;
  }
  L00576677: { // 0x576677: dc1510667800 FCOM qword ptr [0x786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057667d: { // 0x57667d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057667f: { // 0x57667f: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00576682: { // 0x576682: 75b8 JNZ 0x57663c
    if(integer::condition("JNZ",flags)) goto L0057663c;
  }
  L00576684: { // 0x576684: d9c0 FLD st(0)
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576686: { // 0x576686: d9ed FLDLN2
    numeric_b88::detail::reg<0xd9ed>(s.fp);
  }
  L00576688: { // 0x576688: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L0057668b: { // 0x57668b: d9c9 FXCH st(1)
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0057668d: { // 0x57668d: d9f1 FYL2X
    numeric_b88::detail::reg<0xd9f1>(s.fp);
  }
  L0057668f: { // 0x57668f: d9c0 FLD st(0)
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576691: { // 0x576691: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00576693: { // 0x576693: d8e1 FSUB st(1)
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00576695: { // 0x576695: d8f2 FDIV st(2)
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L00576697: { // 0x576697: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057669a: { // 0x57669a: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669c: { // 0x57669c: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669e: { // 0x57669e: e8dd39f4ff CALL 0x4ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5727907u); flags=s.arithmetic_flags;
  }
  L005766a3: { // 0x5766a3: d9c0 FLD st(0)
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L005766a5: { // 0x5766a5: dc4c2418 FMUL qword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L005766a9: { // 0x5766a9: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005766ac: { // 0x5766ac: c60601 MOV byte ptr [ESI], 1
    m.w8((s.si), 1u);
  }
  L005766af: { // 0x5766af: dd5e08 FSTP qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005766b2: { // 0x5766b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005766b3: { // 0x5766b3: dc4c2404 FMUL qword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.multiply64(read64(m,address));
  }
  L005766b7: { // 0x5766b7: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L005766b9: { // 0x5766b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005766ba: { // 0x5766ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00176560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00576560: { // 0x576560: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00576563: { // 0x576563: b9d881a500 MOV ECX, 0xa581d8
    s.cx = 0x00a581d8u;
  }
  L00576568: { // 0x576568: e873980b00 CALL 0x62fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5727597u); flags=s.arithmetic_flags;
  }
  L0057656d: { // 0x57656d: 89442400 MOV dword ptr [ESP], EAX
    m.w32((f.sp), s.ax);
  }
  L00576571: { // 0x576571: c744240400000000 MOV dword ptr [ESP + 4], 0
    m.w32((f.sp+4u), 0u);
  }
  L00576579: { // 0x576579: df6c2400 FILD qword ptr [ESP]
    const auto address=(f.sp);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057657d: { // 0x57657d: dc0db00d7900 FMUL qword ptr [0x790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L00576583: { // 0x576583: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L00576586: { // 0x576586: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX], 0
    (void)integer::sub(m.r8((s.cx)),0u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x62fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX, dword ptr [ECX + 8]
    s.dx = m.r32((s.cx+8u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX, dword ptr [ECX + EDX*4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 4u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI, dword ptr [ECX + EAX*4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 4u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX, [ECX + EAX*4 + 0xc]
    s.ax = (s.cx+(s.ax * 4u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI, EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX], ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI, dword ptr [ECX + 8]
    s.si = m.r32((s.cx+8u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX, dword ptr [ECX + EDX*4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 4u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX, 0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 8], ESI
    m.w32((s.cx+8u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x62fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 4], 0
    m.w32((s.cx+4u), 0u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI, 0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x62fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 8], 0
    m.w32((s.cx+8u), 0u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5727776u:f_00176620(m,s,child,{});break;
case 5727584u:f_00176560(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 4956288u:f_000ba080(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery1104 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00581530(Memory& original,const Inputs& i){
 const auto q=original.r32(i.cx+0x44u),ri=original.r32(0xa581dcu),rj=original.r32(0xa581e0u);const auto cw=i.fp.image.word(0);
 if(q<20u||q>100u||original.r32(0x836b4cu)!=7u||original.r32(0xa58634u)!=3u||original.r32(0xa58638u)!=9u||original.r32(0xa57978u)!=0x576560u||original.r8(0xa581d8u)!=0u||ri>=250u||rj!=(ri+103u)%250u||(cw!=0x37fu&&cw!=0x27fu&&cw!=0xe7fu))throw std::domain_error("recovery1104 outside reviewed initialized numeric domain");

 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);


  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00581530: { // 0x581530: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00581531: { // 0x581531: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L00581533: { // 0x581533: 83e4f8 AND ESP, 0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00581536: { // 0x581536: 83ec78 SUB ESP, 0x78
    f.sp = integer::sub(f.sp,0x00000078u,32,flags);
  }
  L00581539: { // 0x581539: db4144 FILD dword ptr [ECX + 0x44]
    const auto address=(s.cx+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L0058153c: { // 0x58153c: a14c6b8300 MOV EAX, dword ptr [0x836b4c]
    s.ax = m.r32((0x00836b4cu));
  }
  L00581541: { // 0x581541: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00581542: { // 0x581542: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L00581544: { // 0x581544: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00581545: { // 0x581545: d9c0 FLD st(0)
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00581547: { // 0x581547: 0fafd8 IMUL EBX, EAX
    s.bx = integer::imul(s.bx,s.ax,32,flags);
  }
  L0058154a: { // 0x58154a: dc0dd00f7900 FMUL qword ptr [0x790fd0]
    const auto address=(0x00790fd0u);
    s.fp.multiply64(read64(m,address));
  }
  L00581550: { // 0x581550: dc0570757800 FADD qword ptr [0x787570]
    const auto address=(0x00787570u);
    s.fp.add64(read64(m,address));
  }
  L00581556: { // 0x581556: dd5c2458 FSTP qword ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058155a: { // 0x58155a: d9c0 FLD st(0)
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0058155c: { // 0x58155c: dc0dc80f7900 FMUL qword ptr [0x790fc8]
    const auto address=(0x00790fc8u);
    s.fp.multiply64(read64(m,address));
  }
  L00581562: { // 0x581562: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00581563: { // 0x581563: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00581564: { // 0x581564: 895c2424 MOV dword ptr [ESP + 0x24], EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L00581568: { // 0x581568: dd5c2450 FSTP qword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058156c: { // 0x58156c: dc0d70817800 FMUL qword ptr [0x788170]
    const auto address=(0x00788170u);
    s.fp.multiply64(read64(m,address));
  }
  L00581572: { // 0x581572: dd9c2480000000 FSTP qword ptr [ESP + 0x80]
    const auto address=(f.sp+0x00000080u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581579: { // 0x581579: dd442450 FLD qword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load64(read64(m,address));
  }
  L0058157d: { // 0x58157d: dc1de00c7900 FCOMP qword ptr [0x790ce0]
    const auto address=(0x00790ce0u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581583: { // 0x581583: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581585: { // 0x581585: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00581588: { // 0x581588: 0f853a040000 JNZ 0x5819c8
    if(integer::condition("JNZ",flags)) goto L005819c8;
  }
  L0058158e: { // 0x58158e: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00581590: { // 0x581590: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00581592: { // 0x581592: 0f8e30040000 JLE 0x5819c8
    if(integer::condition("JLE",flags)) goto L005819c8;
  }
  L00581598: { // 0x581598: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0058159a: { // 0x58159a: 895c2420 MOV dword ptr [ESP + 0x20], EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0058159e: { // 0x58159e: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L005815a2: { // 0x5815a2: a13c86a500 MOV EAX, dword ptr [0xa5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L005815a7: { // 0x5815a7: 03f0 ADD ESI, EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L005815a9: { // 0x5815a9: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005815ab: { // 0x5815ab: 894c2428 MOV dword ptr [ESP + 0x28], ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005815af: { // 0x5815af: 8b44242a MOV EAX, dword ptr [ESP + 0x2a]
    s.ax = m.r32((f.sp+0x0000002au));
  }
  L005815b3: { // 0x5815b3: 663bcf CMP CX, DI
    (void)integer::sub((s.cx & 0xffffu),(s.di & 0xffffu),16,flags);
  }
  L005815b6: { // 0x5815b6: 7509 JNZ 0x5815c1
    if(integer::condition("JNZ",flags)) goto L005815c1;
  }
  L005815b8: { // 0x5815b8: 663bc7 CMP AX, DI
    (void)integer::sub((s.ax & 0xffffu),(s.di & 0xffffu),16,flags);
  }
  L005815bb: { // 0x5815bb: 0f848e030000 JZ 0x58194f
    if(integer::condition("JZ",flags)) goto L0058194f;
  }
  L005815c1: { // 0x5815c1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005815c2: { // 0x5815c2: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005815c3: { // 0x5815c3: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005815c7: { // 0x5815c7: 897e10 MOV dword ptr [ESI + 0x10], EDI
    m.w32((s.si+0x00000010u), s.di);
  }
  L005815ca: { // 0x5815ca: 0fbfd1 MOVSX EDX, CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L005815cd: { // 0x5815cd: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005815d0: { // 0x5815d0: 897e14 MOV dword ptr [ESI + 0x14], EDI
    m.w32((s.si+0x00000014u), s.di);
  }
  L005815d3: { // 0x5815d3: 8b3d3486a500 MOV EDI, dword ptr [0xa58634]
    s.di = m.r32((0x00a58634u));
  }
  L005815d9: { // 0x5815d9: 8d2c10 LEA EBP, [EAX + EDX]
    s.bp = (s.ax+s.dx);
  }
  L005815dc: { // 0x5815dc: c744244800000000 MOV dword ptr [ESP + 0x48], 0
    m.w32((f.sp+0x00000048u), 0u);
  }
  L005815e4: { // 0x5815e4: 3bef CMP EBP, EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L005815e6: { // 0x5815e6: c744244c00000000 MOV dword ptr [ESP + 0x4c], 0
    m.w32((f.sp+0x0000004cu), 0u);
  }
  L005815ee: { // 0x5815ee: c744243000000000 MOV dword ptr [ESP + 0x30], 0
    m.w32((f.sp+0x00000030u), 0u);
  }
  L005815f6: { // 0x5815f6: c744243400000000 MOV dword ptr [ESP + 0x34], 0
    m.w32((f.sp+0x00000034u), 0u);
  }
  L005815fe: { // 0x5815fe: 7e3b JLE 0x58163b
    if(integer::condition("JLE",flags)) goto L0058163b;
  }
  L00581600: { // 0x581600: 8bda MOV EBX, EDX
    s.bx = s.dx;
  }
  L00581602: { // 0x581602: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00581604: { // 0x581604: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00581606: { // 0x581606: 7d33 JGE 0x58163b
    if(integer::condition("JGE",flags)) goto L0058163b;
  }
  L00581608: { // 0x581608: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0058160a: { // 0x58160a: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0058160c: { // 0x58160c: 7d2d JGE 0x58163b
    if(integer::condition("JGE",flags)) goto L0058163b;
  }
  L0058160e: { // 0x58160e: 3b2d3886a500 CMP EBP, dword ptr [0xa58638]
    (void)integer::sub(s.bp,m.r32((0x00a58638u)),32,flags);
  }
  L00581614: { // 0x581614: 7f25 JG 0x58163b
    if(integer::condition("JG",flags)) goto L0058163b;
  }
  L00581616: { // 0x581616: 0fbf442410 MOVSX EAX, word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0058161b: { // 0x58161b: 0faf054c6b8300 IMUL EAX, dword ptr [0x836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00581622: { // 0x581622: 0fbfd1 MOVSX EDX, CX
    s.dx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00581625: { // 0x581625: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00581627: { // 0x581627: 8b153c86a500 MOV EDX, dword ptr [0xa5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0058162d: { // 0x58162d: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L00581630: { // 0x581630: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L00581633: { // 0x581633: dd441008 FLD qword ptr [EAX + EDX + 8]
    const auto address=(s.ax+s.dx+8u);
    s.fp.load64(read64(m,address));
  }
  L00581637: { // 0x581637: dd5c2448 FSTP qword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058163b: { // 0x58163b: 0fbf44242a MOVSX EAX, word ptr [ESP + 0x2a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002au)),16));
  }
  L00581640: { // 0x581640: 0fbfc9 MOVSX ECX, CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L00581643: { // 0x581643: 8d1408 LEA EDX, [EAX + ECX]
    s.dx = (s.ax+s.cx);
  }
  L00581646: { // 0x581646: 3bd7 CMP EDX, EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L00581648: { // 0x581648: 7e51 JLE 0x58169b
    if(integer::condition("JLE",flags)) goto L0058169b;
  }
  L0058164a: { // 0x58164a: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0058164c: { // 0x58164c: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L0058164e: { // 0x58164e: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00581650: { // 0x581650: 7d49 JGE 0x58169b
    if(integer::condition("JGE",flags)) goto L0058169b;
  }
  L00581652: { // 0x581652: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L00581654: { // 0x581654: 2bd9 SUB EBX, ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L00581656: { // 0x581656: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L00581658: { // 0x581658: 7d41 JGE 0x58169b
    if(integer::condition("JGE",flags)) goto L0058169b;
  }
  L0058165a: { // 0x58165a: 3b153886a500 CMP EDX, dword ptr [0xa58638]
    (void)integer::sub(s.dx,m.r32((0x00a58638u)),32,flags);
  }
  L00581660: { // 0x581660: 7f39 JG 0x58169b
    if(integer::condition("JG",flags)) goto L0058169b;
  }
  L00581662: { // 0x581662: 0faf054c6b8300 IMUL EAX, dword ptr [0x836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L00581669: { // 0x581669: dd4608 FLD qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    s.fp.load64(read64(m,address));
  }
  L0058166c: { // 0x58166c: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0058166e: { // 0x58166e: 8b0d3c86a500 MOV ECX, dword ptr [0xa5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L00581674: { // 0x581674: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L00581677: { // 0x581677: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L0058167a: { // 0x58167a: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0058167c: { // 0x58167c: dc4008 FADD qword ptr [EAX + 8]
    const auto address=(s.ax+8u);
    s.fp.add64(read64(m,address));
  }
  L0058167f: { // 0x58167f: dd5e08 FSTP qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581682: { // 0x581682: 8b4810 MOV ECX, dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00581685: { // 0x581685: 894e10 MOV dword ptr [ESI + 0x10], ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00581688: { // 0x581688: 8b5014 MOV EDX, dword ptr [EAX + 0x14]
    s.dx = m.r32((s.ax+0x00000014u));
  }
  L0058168b: { // 0x58168b: 895614 MOV dword ptr [ESI + 0x14], EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  L0058168e: { // 0x58168e: dd4008 FLD qword ptr [EAX + 8]
    const auto address=(s.ax+8u);
    s.fp.load64(read64(m,address));
  }
  L00581691: { // 0x581691: dc642448 FSUB qword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.subtract64(read64(m,address));
  }
  L00581695: { // 0x581695: dd5c2430 FSTP qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581699: { // 0x581699: eb1a JMP 0x5816b5
    goto L005816b5;
  }
  L0058169b: { // 0x58169b: 8b4608 MOV EAX, dword ptr [ESI + 8]
    s.ax = m.r32((s.si+8u));
  }
  L0058169e: { // 0x58169e: 8b542450 MOV EDX, dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L005816a2: { // 0x5816a2: 894608 MOV dword ptr [ESI + 8], EAX
    m.w32((s.si+8u), s.ax);
  }
  L005816a5: { // 0x5816a5: 8b4e0c MOV ECX, dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L005816a8: { // 0x5816a8: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L005816ac: { // 0x5816ac: 895610 MOV dword ptr [ESI + 0x10], EDX
    m.w32((s.si+0x00000010u), s.dx);
  }
  L005816af: { // 0x5816af: 894e0c MOV dword ptr [ESI + 0xc], ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L005816b2: { // 0x5816b2: 894614 MOV dword ptr [ESI + 0x14], EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  L005816b5: { // 0x5816b5: 0fbf4c2428 MOVSX ECX, word ptr [ESP + 0x28]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000028u)),16));
  }
  L005816ba: { // 0x5816ba: 0fbf442410 MOVSX EAX, word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L005816bf: { // 0x5816bf: 8b153486a500 MOV EDX, dword ptr [0xa58634]
    s.dx = m.r32((0x00a58634u));
  }
  L005816c5: { // 0x5816c5: 8d3c08 LEA EDI, [EAX + ECX]
    s.di = (s.ax+s.cx);
  }
  L005816c8: { // 0x5816c8: 3bfa CMP EDI, EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L005816ca: { // 0x5816ca: 7e52 JLE 0x58171e
    if(integer::condition("JLE",flags)) goto L0058171e;
  }
  L005816cc: { // 0x5816cc: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L005816ce: { // 0x5816ce: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L005816d0: { // 0x5816d0: 3bda CMP EBX, EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L005816d2: { // 0x5816d2: 7d4a JGE 0x58171e
    if(integer::condition("JGE",flags)) goto L0058171e;
  }
  L005816d4: { // 0x5816d4: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L005816d6: { // 0x5816d6: 2bd9 SUB EBX, ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L005816d8: { // 0x5816d8: 3bda CMP EBX, EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L005816da: { // 0x5816da: 7d42 JGE 0x58171e
    if(integer::condition("JGE",flags)) goto L0058171e;
  }
  L005816dc: { // 0x5816dc: 3b3d3886a500 CMP EDI, dword ptr [0xa58638]
    (void)integer::sub(s.di,m.r32((0x00a58638u)),32,flags);
  }
  L005816e2: { // 0x5816e2: 7f3a JG 0x58171e
    if(integer::condition("JG",flags)) goto L0058171e;
  }
  L005816e4: { // 0x5816e4: 0faf054c6b8300 IMUL EAX, dword ptr [0x836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L005816eb: { // 0x5816eb: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005816ed: { // 0x5816ed: 8b0d3c86a500 MOV ECX, dword ptr [0xa5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L005816f3: { // 0x5816f3: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  L005816f6: { // 0x5816f6: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L005816f9: { // 0x5816f9: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005816fb: { // 0x5816fb: dd4008 FLD qword ptr [EAX + 8]
    const auto address=(s.ax+8u);
    s.fp.load64(read64(m,address));
  }
  L005816fe: { // 0x5816fe: dc4608 FADD qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    s.fp.add64(read64(m,address));
  }
  L00581701: { // 0x581701: dd5e08 FSTP qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581704: { // 0x581704: dd4010 FLD qword ptr [EAX + 0x10]
    const auto address=(s.ax+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L00581707: { // 0x581707: dc4610 FADD qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L0058170a: { // 0x58170a: dd5e10 FSTP qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058170d: { // 0x58170d: dd4008 FLD qword ptr [EAX + 8]
    const auto address=(s.ax+8u);
    s.fp.load64(read64(m,address));
  }
  L00581710: { // 0x581710: dc642448 FSUB qword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.subtract64(read64(m,address));
  }
  L00581714: { // 0x581714: dc442430 FADD qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.add64(read64(m,address));
  }
  L00581718: { // 0x581718: dd5c2430 FSTP qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058171c: { // 0x58171c: eb16 JMP 0x581734
    goto L00581734;
  }
  L0058171e: { // 0x58171e: dd442450 FLD qword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.load64(read64(m,address));
  }
  L00581722: { // 0x581722: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L00581725: { // 0x581725: dc4610 FADD qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L00581728: { // 0x581728: 894e08 MOV dword ptr [ESI + 8], ECX
    m.w32((s.si+8u), s.cx);
  }
  L0058172b: { // 0x58172b: 8b560c MOV EDX, dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L0058172e: { // 0x58172e: 89560c MOV dword ptr [ESI + 0xc], EDX
    m.w32((s.si+0x0000000cu), s.dx);
  }
  L00581731: { // 0x581731: dd5e10 FSTP qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581734: { // 0x581734: dd4608 FLD qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    s.fp.load64(read64(m,address));
  }
  L00581737: { // 0x581737: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L0058173d: { // 0x58173d: dd5608 FST qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00581740: { // 0x581740: dd4610 FLD qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L00581743: { // 0x581743: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L00581749: { // 0x581749: dd5e10 FSTP qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058174c: { // 0x58174c: dd442430 FLD qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L00581750: { // 0x581750: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581756: { // 0x581756: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581758: { // 0x581758: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058175b: { // 0x58175b: 7512 JNZ 0x58176f
    if(integer::condition("JNZ",flags)) goto L0058176f;
  }
  L0058175d: { // 0x58175d: 8b442460 MOV EAX, dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L00581761: { // 0x581761: 8b4c2464 MOV ECX, dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00581765: { // 0x581765: 89442430 MOV dword ptr [ESP + 0x30], EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00581769: { // 0x581769: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0058176d: { // 0x58176d: eb1b JMP 0x58178a
    goto L0058178a;
  }
  L0058176f: { // 0x58176f: dd442430 FLD qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L00581773: { // 0x581773: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581779: { // 0x581779: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058177b: { // 0x58177b: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L0058177e: { // 0x58177e: 740a JZ 0x58178a
    if(integer::condition("JZ",flags)) goto L0058178a;
  }
  L00581780: { // 0x581780: dd442460 FLD qword ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.load64(read64(m,address));
  }
  L00581784: { // 0x581784: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00581786: { // 0x581786: dd5c2430 FSTP qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058178a: { // 0x58178a: 8a4645 MOV AL, byte ptr [ESI + 0x45]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000045u)));
  }
  L0058178d: { // 0x58178d: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0058178f: { // 0x58178f: 7428 JZ 0x5817b9
    if(integer::condition("JZ",flags)) goto L005817b9;
  }
  L00581791: { // 0x581791: dc1510667800 FCOM qword ptr [0x786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00581797: { // 0x581797: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581799: { // 0x581799: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058179c: { // 0x58179c: 7408 JZ 0x5817a6
    if(integer::condition("JZ",flags)) goto L005817a6;
  }
  L0058179e: { // 0x58179e: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005817a0: { // 0x5817a0: dd0510667800 FLD qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L005817a6: { // 0x5817a6: dd5e08 FSTP qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005817a9: { // 0x5817a9: c746107b14ae47 MOV dword ptr [ESI + 0x10], 0x47ae147b
    m.w32((s.si+0x00000010u), 0x47ae147bu);
  }
  L005817b0: { // 0x5817b0: c74614e17a643f MOV dword ptr [ESI + 0x14], 0x3f647ae1
    m.w32((s.si+0x00000014u), 0x3f647ae1u);
  }
  L005817b7: { // 0x5817b7: eb02 JMP 0x5817bb
    goto L005817bb;
  }
  L005817b9: { // 0x5817b9: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005817bb: { // 0x5817bb: dd4610 FLD qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L005817be: { // 0x5817be: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L005817c0: { // 0x5817c0: dd5c2440 FSTP qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005817c4: { // 0x5817c4: dd842480000000 FLD qword ptr [ESP + 0x80]
    const auto address=(f.sp+0x00000080u);
    s.fp.load64(read64(m,address));
  }
  L005817cb: { // 0x5817cb: dc6610 FSUB qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.subtract64(read64(m,address));
  }
  L005817ce: { // 0x5817ce: a1e40c7900 MOV EAX, dword ptr [0x790ce4]
    s.ax = m.r32((0x00790ce4u));
  }
  L005817d3: { // 0x5817d3: 8b15e00c7900 MOV EDX, dword ptr [0x790ce0]
    s.dx = m.r32((0x00790ce0u));
  }
  L005817d9: { // 0x5817d9: 8944245c MOV dword ptr [ESP + 0x5c], EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L005817dd: { // 0x5817dd: c744246800000000 MOV dword ptr [ESP + 0x68], 0
    m.w32((f.sp+0x00000068u), 0u);
  }
  L005817e5: { // 0x5817e5: c744246c00000000 MOV dword ptr [ESP + 0x6c], 0
    m.w32((f.sp+0x0000006cu), 0u);
  }
  L005817ed: { // 0x5817ed: 89542458 MOV dword ptr [ESP + 0x58], EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L005817f1: { // 0x5817f1: dd5c2410 FSTP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005817f5: { // 0x5817f5: dd05e00c7900 FLD qword ptr [0x790ce0]
    const auto address=(0x00790ce0u);
    s.fp.load64(read64(m,address));
  }
  L005817fb: { // 0x5817fb: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L005817fd: { // 0x5817fd: dc5c2410 FCOMP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581801: { // 0x581801: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581803: { // 0x581803: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00581806: { // 0x581806: 7411 JZ 0x581819
    if(integer::condition("JZ",flags)) goto L00581819;
  }
  L00581808: { // 0x581808: dd05e00c7900 FLD qword ptr [0x790ce0]
    const auto address=(0x00790ce0u);
    s.fp.load64(read64(m,address));
  }
  L0058180e: { // 0x58180e: dc5c2440 FCOMP qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581812: { // 0x581812: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581814: { // 0x581814: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00581817: { // 0x581817: 741a JZ 0x581833
    if(integer::condition("JZ",flags)) goto L00581833;
  }
  L00581819: { // 0x581819: dd442410 FLD qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0058181d: { // 0x58181d: dc642440 FSUB qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.subtract64(read64(m,address));
  }
  L00581821: { // 0x581821: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L00581827: { // 0x581827: dd542458 FST qword ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0058182b: { // 0x58182b: dc442440 FADD qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.add64(read64(m,address));
  }
  L0058182f: { // 0x58182f: dd5c2468 FSTP qword ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581833: { // 0x581833: b96879a500 MOV ECX, 0xa57968
    s.cx = 0x00a57968u;
  }
  L00581838: { // 0x581838: e8e34dffff CALL 0x576620
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576620u,5773373u); flags=s.arithmetic_flags;
  }
  L0058183d: { // 0x58183d: dc4c2458 FMUL qword ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L00581841: { // 0x581841: dc442468 FADD qword ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.add64(read64(m,address));
  }
  L00581845: { // 0x581845: dd542470 FST qword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00581849: { // 0x581849: dc5c2440 FCOMP qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0058184d: { // 0x58184d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058184f: { // 0x58184f: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00581852: { // 0x581852: 75df JNZ 0x581833
    if(integer::condition("JNZ",flags)) goto L00581833;
  }
  L00581854: { // 0x581854: dd442470 FLD qword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    s.fp.load64(read64(m,address));
  }
  L00581858: { // 0x581858: dc5c2410 FCOMP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0058185c: { // 0x58185c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058185e: { // 0x58185e: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00581861: { // 0x581861: 74d0 JZ 0x581833
    if(integer::condition("JZ",flags)) goto L00581833;
  }
  L00581863: { // 0x581863: dd442470 FLD qword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    s.fp.load64(read64(m,address));
  }
  L00581867: { // 0x581867: dc4610 FADD qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L0058186a: { // 0x58186a: dd542470 FST qword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0058186e: { // 0x58186e: dd5e10 FSTP qword ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00581871: { // 0x581871: dd05c00f7900 FLD qword ptr [0x790fc0]
    const auto address=(0x00790fc0u);
    s.fp.load64(read64(m,address));
  }
  L00581877: { // 0x581877: dc6608 FSUB qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    s.fp.subtract64(read64(m,address));
  }
  L0058187a: { // 0x58187a: dd5c2410 FSTP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058187e: { // 0x58187e: dd05f8567800 FLD qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.load64(read64(m,address));
  }
  L00581884: { // 0x581884: dc6608 FSUB qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    s.fp.subtract64(read64(m,address));
  }
  L00581887: { // 0x581887: dd5c2440 FSTP qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058188b: { // 0x58188b: dd442430 FLD qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L0058188f: { // 0x58188f: dc5c2410 FCOMP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581893: { // 0x581893: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581895: { // 0x581895: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00581898: { // 0x581898: 7406 JZ 0x5818a0
    if(integer::condition("JZ",flags)) goto L005818a0;
  }
  L0058189a: { // 0x58189a: dd442410 FLD qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L0058189e: { // 0x58189e: eb19 JMP 0x5818b9
    goto L005818b9;
  }
  L005818a0: { // 0x5818a0: dd442430 FLD qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L005818a4: { // 0x5818a4: dc5c2440 FCOMP qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L005818a8: { // 0x5818a8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L005818aa: { // 0x5818aa: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L005818ad: { // 0x5818ad: 7506 JNZ 0x5818b5
    if(integer::condition("JNZ",flags)) goto L005818b5;
  }
  L005818af: { // 0x5818af: dd442440 FLD qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L005818b3: { // 0x5818b3: eb04 JMP 0x5818b9
    goto L005818b9;
  }
  L005818b5: { // 0x5818b5: dd442430 FLD qword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L005818b9: { // 0x5818b9: 8b4c2470 MOV ECX, dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L005818bd: { // 0x5818bd: 8b542474 MOV EDX, dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L005818c1: { // 0x5818c1: dd542478 FST qword ptr [ESP + 0x78]
    const auto address=(f.sp+0x00000078u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L005818c5: { // 0x5818c5: 894c2438 MOV dword ptr [ESP + 0x38], ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L005818c9: { // 0x5818c9: 8954243c MOV dword ptr [ESP + 0x3c], EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L005818cd: { // 0x5818cd: d9c0 FLD st(0)
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L005818cf: { // 0x5818cf: dc642438 FSUB qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L005818d3: { // 0x5818d3: dc5c2440 FCOMP qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L005818d7: { // 0x5818d7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L005818d9: { // 0x5818d9: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L005818dc: { // 0x5818dc: 7415 JZ 0x5818f3
    if(integer::condition("JZ",flags)) goto L005818f3;
  }
  L005818de: { // 0x5818de: dd442438 FLD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L005818e2: { // 0x5818e2: d8c1 FADD st(1)
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L005818e4: { // 0x5818e4: dc5c2410 FCOMP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.compare_pop64(read64(m,address));
  }
  L005818e8: { // 0x5818e8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L005818ea: { // 0x5818ea: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L005818ed: { // 0x5818ed: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005818ef: { // 0x5818ef: 741e JZ 0x58190f
    if(integer::condition("JZ",flags)) goto L0058190f;
  }
  L005818f1: { // 0x5818f1: eb02 JMP 0x5818f5
    goto L005818f5;
  }
  L005818f3: { // 0x5818f3: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L005818f5: { // 0x5818f5: dd442440 FLD qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L005818f9: { // 0x5818f9: dc642410 FSUB qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.subtract64(read64(m,address));
  }
  L005818fd: { // 0x5818fd: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L00581903: { // 0x581903: dd542438 FST qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00581907: { // 0x581907: dc442410 FADD qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L0058190b: { // 0x58190b: dd5c2478 FSTP qword ptr [ESP + 0x78]
    const auto address=(f.sp+0x00000078u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058190f: { // 0x58190f: b96879a500 MOV ECX, 0xa57968
    s.cx = 0x00a57968u;
  }
  L00581914: { // 0x581914: e8074dffff CALL 0x576620
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576620u,5773593u); flags=s.arithmetic_flags;
  }
  L00581919: { // 0x581919: dc4c2438 FMUL qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.multiply64(read64(m,address));
  }
  L0058191d: { // 0x58191d: dc442478 FADD qword ptr [ESP + 0x78]
    const auto address=(f.sp+0x00000078u);
    s.fp.add64(read64(m,address));
  }
  L00581921: { // 0x581921: dd542470 FST qword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00581925: { // 0x581925: dc5c2410 FCOMP qword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581929: { // 0x581929: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058192b: { // 0x58192b: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L0058192e: { // 0x58192e: 75df JNZ 0x58190f
    if(integer::condition("JNZ",flags)) goto L0058190f;
  }
  L00581930: { // 0x581930: dd442470 FLD qword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    s.fp.load64(read64(m,address));
  }
  L00581934: { // 0x581934: dc5c2440 FCOMP qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00581938: { // 0x581938: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058193a: { // 0x58193a: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058193d: { // 0x58193d: 74d0 JZ 0x58190f
    if(integer::condition("JZ",flags)) goto L0058190f;
  }
  L0058193f: { // 0x58193f: dd442470 FLD qword ptr [ESP + 0x70]
    const auto address=(f.sp+0x00000070u);
    s.fp.load64(read64(m,address));
  }
  L00581943: { // 0x581943: dc4608 FADD qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    s.fp.add64(read64(m,address));
  }
  L00581946: { // 0x581946: 8b5c2424 MOV EBX, dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L0058194a: { // 0x58194a: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0058194c: { // 0x58194c: dd5e08 FSTP qword ptr [ESI + 8]
    const auto address=(s.si+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0058194f: { // 0x58194f: 8b74241c MOV ESI, dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00581953: { // 0x581953: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00581957: { // 0x581957: 83c650 ADD ESI, 0x50
    s.si = integer::add(s.si,0x00000050u,32,flags);
  }
  L0058195a: { // 0x58195a: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0058195b: { // 0x58195b: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L0058195f: { // 0x58195f: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00581963: { // 0x581963: 0f8539fcffff JNZ 0x5815a2
    if(integer::condition("JNZ",flags)) goto L005815a2;
  }
  L00581969: { // 0x581969: 3bdf CMP EBX, EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0058196b: { // 0x58196b: 7e5b JLE 0x5819c8
    if(integer::condition("JLE",flags)) goto L005819c8;
  }
  L0058196d: { // 0x58196d: a13c86a500 MOV EAX, dword ptr [0xa5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L00581972: { // 0x581972: dd440708 FLD qword ptr [EDI + EAX + 8]
    const auto address=(s.di+s.ax+8u);
    s.fp.load64(read64(m,address));
  }
  L00581976: { // 0x581976: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0058197c: { // 0x58197c: 8d740708 LEA ESI, [EDI + EAX + 8]
    s.si = (s.di+s.ax+8u);
  }
  L00581980: { // 0x581980: dd06 FLD qword ptr [ESI]
    const auto address=(s.si);
    s.fp.load64(read64(m,address));
  }
  L00581982: { // 0x581982: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00581984: { // 0x581984: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00581987: { // 0x581987: 7415 JZ 0x58199e
    if(integer::condition("JZ",flags)) goto L0058199e;
  }
  L00581989: { // 0x581989: dc2528577800 FSUB qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.subtract64(read64(m,address));
  }
  L0058198f: { // 0x58198f: e8bc901e00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5773716u); flags=s.arithmetic_flags;
  }
  L00581994: { // 0x581994: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00581998: { // 0x581998: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0058199c: { // 0x58199c: eb22 JMP 0x5819c0
    goto L005819c0;
  }
  L0058199e: { // 0x58199e: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L005819a4: { // 0x5819a4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L005819a6: { // 0x5819a6: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L005819a9: { // 0x5819a9: 7517 JNZ 0x5819c2
    if(integer::condition("JNZ",flags)) goto L005819c2;
  }
  L005819ab: { // 0x5819ab: dd06 FLD qword ptr [ESI]
    const auto address=(s.si);
    s.fp.load64(read64(m,address));
  }
  L005819ad: { // 0x5819ad: dc0528577800 FADD qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L005819b3: { // 0x5819b3: e898901e00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5773752u); flags=s.arithmetic_flags;
  }
  L005819b8: { // 0x5819b8: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L005819bc: { // 0x5819bc: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L005819c0: { // 0x5819c0: dd1e FSTP qword ptr [ESI]
    const auto address=(s.si);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005819c2: { // 0x5819c2: 83c750 ADD EDI, 0x50
    s.di = integer::add(s.di,0x00000050u,32,flags);
  }
  L005819c5: { // 0x5819c5: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L005819c6: { // 0x5819c6: 75a5 JNZ 0x58196d
    if(integer::condition("JNZ",flags)) goto L0058196d;
  }
  L005819c8: { // 0x5819c8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005819c9: { // 0x5819c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005819ca: { // 0x5819ca: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005819cb: { // 0x5819cb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005819cc: { // 0x5819cc: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L005819ce: { // 0x5819ce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005819cf: { // 0x5819cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
