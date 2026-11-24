#include "recovered/recovery_b1543_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1543 {
namespace {
void f_0022ca80(Memory&,State&,Frame&,const Operations&);
void f_0022ce70(Memory&,State&,Frame&,const Operations&);
void f_0022d3a0(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0036d67b(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0022ca80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062ca80: { // 0x62ca80: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062ca81: { // 0x62ca81: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0062ca83: { // 0x62ca83: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0062ca86: { // 0x62ca86: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0062ca89: { // 0x62ca89: a138e0a900 MOV EAX,[0x00a9e038]
    s.ax = m.r32((0x00a9e038u));
  }
  L0062ca8e: { // 0x62ca8e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062ca8f: { // 0x62ca8f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062ca90: { // 0x62ca90: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062ca91: { // 0x62ca91: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L0062ca94: { // 0x62ca94: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0062ca96: { // 0x62ca96: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0062ca98: { // 0x62ca98: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062ca99: { // 0x62ca99: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062ca9b: { // 0x62ca9b: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0062ca9f: { // 0x62ca9f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0062caa3: { // 0x62caa3: 7c2a JL 0x0062cacf
    if(integer::condition("JL",flags)) goto L0062cacf;
  }
  L0062caa5: { // 0x62caa5: a12ce0a900 MOV EAX,[0x00a9e02c]
    s.ax = m.r32((0x00a9e02cu));
  }
  L0062caaa: { // 0x62caaa: 8d7901 LEA EDI,[ECX + 0x1]
    s.di = (s.cx+0x00000001u);
  }
  L0062caad: { // 0x62caad: 8d1488 LEA EDX,[EAX + ECX*0x4]
    s.dx = (s.ax+(s.cx * 0x00000004u));
  }
  L0062cab0: { // 0x62cab0: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0062cab2: { // 0x62cab2: 83780802 CMP dword ptr [EAX + 0x8],0x2
    (void)integer::sub(m.r32((s.ax+0x00000008u)),0x00000002u,32,flags);
  }
  L0062cab6: { // 0x62cab6: 7509 JNZ 0x0062cac1
    if(integer::condition("JNZ",flags)) goto L0062cac1;
  }
  L0062cab8: { // 0x62cab8: 8a5801 MOV BL,byte ptr [EAX + 0x1]
    s.bx = with_al(s.bx, m.r8((s.ax+0x00000001u)));
  }
  L0062cabb: { // 0x62cabb: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062cabc: { // 0x62cabc: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0062cabe: { // 0x62cabe: 7401 JZ 0x0062cac1
    if(integer::condition("JZ",flags)) goto L0062cac1;
  }
  L0062cac0: { // 0x62cac0: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0062cac1: { // 0x62cac1: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
  L0062cac4: { // 0x62cac4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0062cac5: { // 0x62cac5: 75e9 JNZ 0x0062cab0
    if(integer::condition("JNZ",flags)) goto L0062cab0;
  }
  L0062cac7: { // 0x62cac7: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0062cacb: { // 0x62cacb: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0062cacf: { // 0x62cacf: 8b154c67a500 MOV EDX,dword ptr [0x00a5674c]
    s.dx = m.r32((0x00a5674cu));
  }
  L0062cad5: { // 0x62cad5: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0062cadd: { // 0x62cadd: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0062cae1: { // 0x62cae1: df6c2420 FILD qword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0062cae5: { // 0x62cae5: db059858a200 FILD dword ptr [0x00a25898]
    const auto address=(0x00a25898u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062caeb: { // 0x62caeb: def9 FDIVP
    numeric_b88::detail::reg<0xdef9>(s.fp);
  }
  L0062caed: { // 0x62caed: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062caef: { // 0x62caef: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0062caf1: { // 0x62caf1: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L0062caf3: { // 0x62caf3: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062caf7: { // 0x62caf7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062cafb: { // 0x62cafb: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062caff: { // 0x62caff: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062cb01: { // 0x62cb01: dc742420 FDIV double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.divide64(read64(m,address));
  }
  L0062cb05: { // 0x62cb05: d8e2 FSUB ST0,ST2
    numeric_b88::detail::reg<0xd8e2>(s.fp);
  }
  L0062cb07: { // 0x62cb07: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb0b: { // 0x62cb0b: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L0062cb11: { // 0x62cb11: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L0062cb15: { // 0x62cb15: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0062cb1b: { // 0x62cb1b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0062cb1d: { // 0x62cb1d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0062cb20: { // 0x62cb20: 750a JNZ 0x0062cb2c
    if(integer::condition("JNZ",flags)) goto L0062cb2c;
  }
  L0062cb22: { // 0x62cb22: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062cb24: { // 0x62cb24: dd442420 FLD double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L0062cb28: { // 0x62cb28: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L0062cb2c: { // 0x62cb2c: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0062cb2e: { // 0x62cb2e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062cb30: { // 0x62cb30: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0062cb32: { // 0x62cb32: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb36: { // 0x62cb36: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062cb38: { // 0x62cb38: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L0062cb3e: { // 0x62cb3e: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0062cb40: { // 0x62cb40: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb44: { // 0x62cb44: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062cb46: { // 0x62cb46: 0f8cf7000000 JL 0x0062cc43
    if(integer::condition("JL",flags)) goto L0062cc43;
  }
  L0062cb4c: { // 0x62cb4c: bd64000000 MOV EBP,0x64
    s.bp = 0x00000064u;
  }
  L0062cb51: { // 0x62cb51: a12ce0a900 MOV EAX,[0x00a9e02c]
    s.ax = m.r32((0x00a9e02cu));
  }
  L0062cb56: { // 0x62cb56: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0062cb59: { // 0x62cb59: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0062cb5d: { // 0x62cb5d: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0062cb60: { // 0x62cb60: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0062cb63: { // 0x62cb63: 753c JNZ 0x0062cba1
    if(integer::condition("JNZ",flags)) goto L0062cba1;
  }
  L0062cb65: { // 0x62cb65: dd442420 FLD double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L0062cb69: { // 0x62cb69: dc0d30817800 FMUL double ptr [0x00788130]
    const auto address=(0x00788130u);
    s.fp.multiply64(read64(m,address));
  }
  L0062cb6f: { // 0x62cb6f: e8dcde1300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6474612u); flags=s.arithmetic_flags;
  }
  L0062cb74: { // 0x62cb74: 83f80a CMP EAX,0xa
    (void)integer::sub(s.ax,0x0000000au,32,flags);
  }
  L0062cb77: { // 0x62cb77: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0062cb7b: { // 0x62cb7b: 7d0a JGE 0x0062cb87
    if(integer::condition("JGE",flags)) goto L0062cb87;
  }
  L0062cb7d: { // 0x62cb7d: c74424180a000000 MOV dword ptr [ESP + 0x18],0xa
    m.w32((f.sp+0x00000018u), 0x0000000au);
  }
  L0062cb85: { // 0x62cb85: eb08 JMP 0x0062cb8f
    goto L0062cb8f;
  }
  L0062cb87: { // 0x62cb87: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0062cb89: { // 0x62cb89: 7e04 JLE 0x0062cb8f
    if(integer::condition("JLE",flags)) goto L0062cb8f;
  }
  L0062cb8b: { // 0x62cb8b: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0062cb8f: { // 0x62cb8f: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062cb93: { // 0x62cb93: dd5e10 FSTP double ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb96: { // 0x62cb96: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0062cb9a: { // 0x62cb9a: e8d1020000 CALL 0x0062ce70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062ce70u,6474655u); flags=s.arithmetic_flags;
  }
  L0062cb9f: { // 0x62cb9f: eb46 JMP 0x0062cbe7
    goto L0062cbe7;
  }
  L0062cba1: { // 0x62cba1: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0062cba4: { // 0x62cba4: 0f8592000000 JNZ 0x0062cc3c
    if(integer::condition("JNZ",flags)) goto L0062cc3c;
  }
  L0062cbaa: { // 0x62cbaa: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0062cbad: { // 0x62cbad: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062cbaf: { // 0x62cbaf: 742f JZ 0x0062cbe0
    if(integer::condition("JZ",flags)) goto L0062cbe0;
  }
  L0062cbb1: { // 0x62cbb1: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  L0062cbb3: { // 0x62cbb3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062cbb5: { // 0x62cbb5: b958158200 MOV ECX,0x821558
    s.cx = 0x00821558u;
  }
  L0062cbba: { // 0x62cbba: e881320000 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6474687u); flags=s.arithmetic_flags;
  }
  L0062cbbf: { // 0x62cbbf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0062cbc1: { // 0x62cbc1: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0062cbc5: { // 0x62cbc5: dc0df0677800 FMUL double ptr [0x007867f0]
    const auto address=(0x007867f0u);
    s.fp.multiply64(read64(m,address));
  }
  L0062cbcb: { // 0x62cbcb: e880de1300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6474704u); flags=s.arithmetic_flags;
  }
  L0062cbd0: { // 0x62cbd0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0062cbd2: { // 0x62cbd2: 7d08 JGE 0x0062cbdc
    if(integer::condition("JGE",flags)) goto L0062cbdc;
  }
  L0062cbd4: { // 0x62cbd4: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0062cbd8: { // 0x62cbd8: c6410100 MOV byte ptr [ECX + 0x1],0x0
    m.w8((s.cx+0x00000001u), 0x00000000u);
  }
  L0062cbdc: { // 0x62cbdc: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0062cbe0: { // 0x62cbe0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062cbe2: { // 0x62cbe2: e8b9070000 CALL 0x0062d3a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062d3a0u,6474727u); flags=s.arithmetic_flags;
  }
  L0062cbe7: { // 0x62cbe7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062cbe9: { // 0x62cbe9: 7451 JZ 0x0062cc3c
    if(integer::condition("JZ",flags)) goto L0062cc3c;
  }
  L0062cbeb: { // 0x62cbeb: a128e0a900 MOV EAX,[0x00a9e028]
    s.ax = m.r32((0x00a9e028u));
  }
  L0062cbf0: { // 0x62cbf0: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0062cbf4: { // 0x62cbf4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062cbf5: { // 0x62cbf5: b928e0a900 MOV ECX,0xa9e028
    s.cx = 0x00a9e028u;
  }
  L0062cbfa: { // 0x62cbfa: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6474749u); flags=s.arithmetic_flags;
  }
  L0062cbfd: { // 0x62cbfd: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0062cc00: { // 0x62cc00: 742d JZ 0x0062cc2f
    if(integer::condition("JZ",flags)) goto L0062cc2f;
  }
  L0062cc02: { // 0x62cc02: 8b0d38e0a900 MOV ECX,dword ptr [0x00a9e038]
    s.cx = m.r32((0x00a9e038u));
  }
  L0062cc08: { // 0x62cc08: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062cc0a: { // 0x62cc0a: 7d23 JGE 0x0062cc2f
    if(integer::condition("JGE",flags)) goto L0062cc2f;
  }
  L0062cc0c: { // 0x62cc0c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062cc0d: { // 0x62cc0d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062cc0f: { // 0x62cc0f: 890d38e0a900 MOV dword ptr [0x00a9e038],ECX
    m.w32((0x00a9e038u), s.cx);
  }
  L0062cc15: { // 0x62cc15: 7d18 JGE 0x0062cc2f
    if(integer::condition("JGE",flags)) goto L0062cc2f;
  }
  L0062cc17: { // 0x62cc17: 8b0d2ce0a900 MOV ECX,dword ptr [0x00a9e02c]
    s.cx = m.r32((0x00a9e02cu));
  }
  L0062cc1d: { // 0x62cc1d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062cc1e: { // 0x62cc1e: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0062cc21: { // 0x62cc21: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0062cc25: { // 0x62cc25: 8b0d38e0a900 MOV ECX,dword ptr [0x00a9e038]
    s.cx = m.r32((0x00a9e038u));
  }
  L0062cc2b: { // 0x62cc2b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062cc2d: { // 0x62cc2d: 7ce8 JL 0x0062cc17
    if(integer::condition("JL",flags)) goto L0062cc17;
  }
  L0062cc2f: { // 0x62cc2f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0062cc33: { // 0x62cc33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062cc34: { // 0x62cc34: e8420a1400 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6474809u); flags=s.arithmetic_flags;
  }
  L0062cc39: { // 0x62cc39: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0062cc3c: { // 0x62cc3c: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0062cc3d: { // 0x62cc3d: 0f890effffff JNS 0x0062cb51
    if(integer::condition("JNS",flags)) goto L0062cb51;
  }
  L0062cc43: { // 0x62cc43: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062cc44: { // 0x62cc44: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062cc45: { // 0x62cc45: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062cc46: { // 0x62cc46: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062cc47: { // 0x62cc47: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0062cc49: { // 0x62cc49: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062cc4a: { // 0x62cc4a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022ce70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062ce70: { // 0x62ce70: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062ce71: { // 0x62ce71: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0062ce73: { // 0x62ce73: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0062ce76: { // 0x62ce76: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L0062ce79: { // 0x62ce79: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062ce7a: { // 0x62ce7a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062ce7b: { // 0x62ce7b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062ce7c: { // 0x62ce7c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0062ce7e: { // 0x62ce7e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062ce7f: { // 0x62ce7f: 803e00 CMP byte ptr [ESI],0x0
    (void)integer::sub(m.r8((s.si)),0x00000000u,8,flags);
  }
  L0062ce82: { // 0x62ce82: 755c JNZ 0x0062cee0
    if(integer::condition("JNZ",flags)) goto L0062cee0;
  }
  L0062ce84: { // 0x62ce84: c60601 MOV byte ptr [ESI],0x1
    m.w8((s.si), 0x00000001u);
  }
  L0062ce87: { // 0x62ce87: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  L0062ce8a: { // 0x62ce8a: 8b7e1c MOV EDI,dword ptr [ESI + 0x1c]
    s.di = m.r32((s.si+0x0000001cu));
  }
  L0062ce8d: { // 0x62ce8d: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  L0062ce90: { // 0x62ce90: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  L0062ce93: { // 0x62ce93: 8b6e24 MOV EBP,dword ptr [ESI + 0x24]
    s.bp = m.r32((s.si+0x00000024u));
  }
  L0062ce96: { // 0x62ce96: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L0062ce98: { // 0x62ce98: 8d7e4c LEA EDI,[ESI + 0x4c]
    s.di = (s.si+0x0000004cu);
  }
  L0062ce9b: { // 0x62ce9b: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L0062ce9d: { // 0x62ce9d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0062ce9f: { // 0x62ce9f: 8b5630 MOV EDX,dword ptr [ESI + 0x30]
    s.dx = m.r32((s.si+0x00000030u));
  }
  L0062cea2: { // 0x62cea2: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0062cea5: { // 0x62cea5: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0062cea7: { // 0x62cea7: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L0062cea9: { // 0x62cea9: 894b04 MOV dword ptr [EBX + 0x4],ECX
    m.w32((s.bx+0x00000004u), s.cx);
  }
  L0062ceac: { // 0x62ceac: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  L0062ceaf: { // 0x62ceaf: 8b3f MOV EDI,dword ptr [EDI]
    s.di = m.r32((s.di));
  }
  L0062ceb1: { // 0x62ceb1: 8b4e50 MOV ECX,dword ptr [ESI + 0x50]
    s.cx = m.r32((s.si+0x00000050u));
  }
  L0062ceb4: { // 0x62ceb4: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  L0062ceb7: { // 0x62ceb7: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0062ceb9: { // 0x62ceb9: 0fafd7 IMUL EDX,EDI
    s.dx = integer::imul(s.dx,s.di,32,flags);
  }
  L0062cebc: { // 0x62cebc: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062cebe: { // 0x62cebe: 0faff9 IMUL EDI,ECX
    s.di = integer::imul(s.di,s.cx,32,flags);
  }
  L0062cec1: { // 0x62cec1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062cec3: { // 0x62cec3: 03d7 ADD EDX,EDI
    s.dx = integer::add(s.dx,s.di,32,flags);
  }
  L0062cec5: { // 0x62cec5: 0fafc8 IMUL ECX,EAX
    s.cx = integer::imul(s.cx,s.ax,32,flags);
  }
  L0062cec8: { // 0x62cec8: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0062ceca: { // 0x62ceca: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0062cece: { // 0x62cece: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0062ced2: { // 0x62ced2: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062ced5: { // 0x62ced5: e8a6d1e8ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6475482u); flags=s.arithmetic_flags;
  }
  L0062ceda: { // 0x62ceda: dd5e58 FSTP double ptr [ESI + 0x58]
    const auto address=(s.si+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cedd: { // 0x62cedd: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0062cee0: { // 0x62cee0: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0062cee3: { // 0x62cee3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062cee5: { // 0x62cee5: 0f84bc010000 JZ 0x0062d0a7
    if(integer::condition("JZ",flags)) goto L0062d0a7;
  }
  L0062ceeb: { // 0x62ceeb: dd4658 FLD double ptr [ESI + 0x58]
    const auto address=(s.si+0x00000058u);
    s.fp.load64(read64(m,address));
  }
  L0062ceee: { // 0x62ceee: dc7610 FDIV double ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.divide64(read64(m,address));
  }
  L0062cef1: { // 0x62cef1: e85adb1300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6475510u); flags=s.arithmetic_flags;
  }
  L0062cef6: { // 0x62cef6: 8b7e4c MOV EDI,dword ptr [ESI + 0x4c]
    s.di = m.r32((s.si+0x0000004cu));
  }
  L0062cef9: { // 0x62cef9: 8b5e50 MOV EBX,dword ptr [ESI + 0x50]
    s.bx = m.r32((s.si+0x00000050u));
  }
  L0062cefc: { // 0x62cefc: 8b6e54 MOV EBP,dword ptr [ESI + 0x54]
    s.bp = m.r32((s.si+0x00000054u));
  }
  L0062ceff: { // 0x62ceff: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062cf01: { // 0x62cf01: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062cf03: { // 0x62cf03: 894e7c MOV dword ptr [ESI + 0x7c],ECX
    m.w32((s.si+0x0000007cu), s.cx);
  }
  L0062cf06: { // 0x62cf06: 7415 JZ 0x0062cf1d
    if(integer::condition("JZ",flags)) goto L0062cf1d;
  }
  L0062cf08: { // 0x62cf08: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0062cf0a: { // 0x62cf0a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0062cf0b: { // 0x62cf0b: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0062cf0d: { // 0x62cf0d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0062cf0f: { // 0x62cf0f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0062cf11: { // 0x62cf11: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0062cf12: { // 0x62cf12: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0062cf14: { // 0x62cf14: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062cf16: { // 0x62cf16: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0062cf18: { // 0x62cf18: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0062cf19: { // 0x62cf19: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0062cf1b: { // 0x62cf1b: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062cf1d: { // 0x62cf1d: db466c FILD dword ptr [ESI + 0x6c]
    const auto address=(s.si+0x0000006cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0062cf20: { // 0x62cf20: da7634 FIDIV dword ptr [ESI + 0x34]
    const auto address=(s.si+0x00000034u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0062cf23: { // 0x62cf23: 8d9680000000 LEA EDX,[ESI + 0x80]
    s.dx = (s.si+0x00000080u);
  }
  L0062cf29: { // 0x62cf29: 8d461c LEA EAX,[ESI + 0x1c]
    s.ax = (s.si+0x0000001cu);
  }
  L0062cf2c: { // 0x62cf2c: c7467800000000 MOV dword ptr [ESI + 0x78],0x0
    m.w32((s.si+0x00000078u), 0x00000000u);
  }
  L0062cf33: { // 0x62cf33: 893a MOV dword ptr [EDX],EDI
    m.w32((s.dx), s.di);
  }
  L0062cf35: { // 0x62cf35: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  L0062cf38: { // 0x62cf38: 896a08 MOV dword ptr [EDX + 0x8],EBP
    m.w32((s.dx+0x00000008u), s.bp);
  }
  L0062cf3b: { // 0x62cf3b: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0062cf3d: { // 0x62cf3d: 8dae8c000000 LEA EBP,[ESI + 0x8c]
    s.bp = (s.si+0x0000008cu);
  }
  L0062cf43: { // 0x62cf43: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0062cf45: { // 0x62cf45: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0062cf47: { // 0x62cf47: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0062cf4a: { // 0x62cf4a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0062cf4d: { // 0x62cf4d: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062cf50: { // 0x62cf50: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L0062cf53: { // 0x62cf53: 8d4e18 LEA ECX,[ESI + 0x18]
    s.cx = (s.si+0x00000018u);
  }
  L0062cf56: { // 0x62cf56: 8d86b0000000 LEA EAX,[ESI + 0xb0]
    s.ax = (s.si+0x000000b0u);
  }
  L0062cf5c: { // 0x62cf5c: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L0062cf5f: { // 0x62cf5f: 668910 MOV word ptr [EAX],DX
    m.w16((s.ax), (s.dx & 0xffffu));
  }
  L0062cf62: { // 0x62cf62: 8a4902 MOV CL,byte ptr [ECX + 0x2]
    s.cx = with_al(s.cx, m.r8((s.cx+0x00000002u)));
  }
  L0062cf65: { // 0x62cf65: 884802 MOV byte ptr [EAX + 0x2],CL
    m.w8((s.ax+0x00000002u), (s.cx & 0xffu));
  }
  L0062cf68: { // 0x62cf68: dc4e38 FMUL double ptr [ESI + 0x38]
    const auto address=(s.si+0x00000038u);
    s.fp.multiply64(read64(m,address));
  }
  L0062cf6b: { // 0x62cf6b: dd5e70 FSTP double ptr [ESI + 0x70]
    const auto address=(s.si+0x00000070u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cf6e: { // 0x62cf6e: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L0062cf74: { // 0x62cf74: dc5e58 FCOMP double ptr [ESI + 0x58]
    const auto address=(s.si+0x00000058u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0062cf77: { // 0x62cf77: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0062cf79: { // 0x62cf79: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0062cf7c: { // 0x62cf7c: 0f8425010000 JZ 0x0062d0a7
    if(integer::condition("JZ",flags)) goto L0062d0a7;
  }
  L0062cf82: { // 0x62cf82: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062cf84: { // 0x62cf84: e847020000 CALL 0x0062d1d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062d1d0u,6475657u); flags=s.arithmetic_flags;
  }
  L0062cf89: { // 0x62cf89: 8a96b2000000 MOV DL,byte ptr [ESI + 0xb2]
    s.dx = with_al(s.dx, m.r8((s.si+0x000000b2u)));
  }
  L0062cf8f: { // 0x62cf8f: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L0062cf95: { // 0x62cf95: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L0062cf97: { // 0x62cf97: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L0062cf9d: { // 0x62cf9d: 8a86b1000000 MOV AL,byte ptr [ESI + 0xb1]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000b1u)));
  }
  L0062cfa3: { // 0x62cfa3: 6633db XOR BX,BX
    s.bx = with_ax(s.bx, integer::logical(((s.bx & 0xffffu))^((s.bx & 0xffffu)),16,flags));
  }
  L0062cfa6: { // 0x62cfa6: 8ada MOV BL,DL
    s.bx = with_al(s.bx, (s.dx & 0xffu));
  }
  L0062cfa8: { // 0x62cfa8: 6633d2 XOR DX,DX
    s.dx = with_ax(s.dx, integer::logical(((s.dx & 0xffffu))^((s.dx & 0xffffu)),16,flags));
  }
  L0062cfab: { // 0x62cfab: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062cfad: { // 0x62cfad: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L0062cfb3: { // 0x62cfb3: d2e8 SHR AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L0062cfb5: { // 0x62cfb5: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L0062cfbb: { // 0x62cfbb: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0062cfbd: { // 0x62cfbd: 8a86b0000000 MOV AL,byte ptr [ESI + 0xb0]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000b0u)));
  }
  L0062cfc3: { // 0x62cfc3: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062cfc5: { // 0x62cfc5: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L0062cfcb: { // 0x62cfcb: d2e8 SHR AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L0062cfcd: { // 0x62cfcd: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L0062cfd3: { // 0x62cfd3: 0bda OR EBX,EDX
    s.bx = integer::logical((s.bx)|(s.dx),32,flags);
  }
  L0062cfd5: { // 0x62cfd5: 6633d2 XOR DX,DX
    s.dx = with_ax(s.dx, integer::logical(((s.dx & 0xffffu))^((s.dx & 0xffffu)),16,flags));
  }
  L0062cfd8: { // 0x62cfd8: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0062cfda: { // 0x62cfda: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0062cfde: { // 0x62cfde: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062cfe0: { // 0x62cfe0: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0062cfe6: { // 0x62cfe6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062cfe7: { // 0x62cfe7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062cfe8: { // 0x62cfe8: 0bda OR EBX,EDX
    s.bx = integer::logical((s.bx)|(s.dx),32,flags);
  }
  L0062cfea: { // 0x62cfea: e821b00600 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6475759u); flags=s.arithmetic_flags;
  }
  L0062cfef: { // 0x62cfef: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0062cff3: { // 0x62cff3: 8d8698000000 LEA EAX,[ESI + 0x98]
    s.ax = (s.si+0x00000098u);
  }
  L0062cff9: { // 0x62cff9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0062cffa: { // 0x62cffa: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0062d000: { // 0x62d000: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062d001: { // 0x62d001: e80ab00600 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6475782u); flags=s.arithmetic_flags;
  }
  L0062d006: { // 0x62d006: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L0062d00c: { // 0x62d00c: a174198200 MOV EAX,[0x00821974]
    s.ax = m.r32((0x00821974u));
  }
  L0062d011: { // 0x62d011: 8b0d78198200 MOV ECX,dword ptr [0x00821978]
    s.cx = m.r32((0x00821978u));
  }
  L0062d017: { // 0x62d017: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0062d01b: { // 0x62d01b: 8b157c198200 MOV EDX,dword ptr [0x0082197c]
    s.dx = m.r32((0x0082197cu));
  }
  L0062d021: { // 0x62d021: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0062d025: { // 0x62d025: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L0062d029: { // 0x62d029: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0062d02d: { // 0x62d02d: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0062d031: { // 0x62d031: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062d032: { // 0x62d032: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L0062d036: { // 0x62d036: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0062d03a: { // 0x62d03a: e8213f1300 CALL 0x00760f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760f60u,6475839u); flags=s.arithmetic_flags;
  }
  L0062d03f: { // 0x62d03f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062d041: { // 0x62d041: 7444 JZ 0x0062d087
    if(integer::condition("JZ",flags)) goto L0062d087;
  }
  L0062d043: { // 0x62d043: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0062d046: { // 0x62d046: e865af0600 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6475851u); flags=s.arithmetic_flags;
  }
  L0062d04b: { // 0x62d04b: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0062d04e: { // 0x62d04e: 8b8ea0000000 MOV ECX,dword ptr [ESI + 0xa0]
    s.cx = m.r32((s.si+0x000000a0u));
  }
  L0062d054: { // 0x62d054: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0062d056: { // 0x62d056: 83ef02 SUB EDI,0x2
    s.di = integer::sub(s.di,0x00000002u,32,flags);
  }
  L0062d059: { // 0x62d059: e852af0600 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6475870u); flags=s.arithmetic_flags;
  }
  L0062d05e: { // 0x62d05e: bafeffffff MOV EDX,0xfffffffe
    s.dx = 0xfffffffeu;
  }
  L0062d063: { // 0x62d063: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062d065: { // 0x62d065: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L0062d067: { // 0x62d067: 8b0d9c1c8200 MOV ECX,dword ptr [0x00821c9c]
    s.cx = m.r32((0x00821c9cu));
  }
  L0062d06d: { // 0x62d06d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d06e: { // 0x62d06e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062d06f: { // 0x62d06f: 0fbfd3 MOVSX EDX,BX
    s.dx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L0062d072: { // 0x62d072: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0062d074: { // 0x62d074: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d075: { // 0x62d075: 8d542428 LEA EDX,[ESP + 0x28]
    s.dx = (f.sp+0x00000028u);
  }
  L0062d079: { // 0x62d079: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d07a: { // 0x62d07a: 8d542434 LEA EDX,[ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L0062d07e: { // 0x62d07e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d07f: { // 0x62d07f: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L0062d084: { // 0x62d084: ff5034 CALL dword ptr [EAX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000034u)),6475911u); flags=s.arithmetic_flags;
  }
  L0062d087: { // 0x62d087: 8b4678 MOV EAX,dword ptr [ESI + 0x78]
    s.ax = m.r32((s.si+0x00000078u));
  }
  L0062d08a: { // 0x62d08a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062d08b: { // 0x62d08b: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0062d08f: { // 0x62d08f: 894678 MOV dword ptr [ESI + 0x78],EAX
    m.w32((s.si+0x00000078u), s.ax);
  }
  L0062d092: { // 0x62d092: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062d096: { // 0x62d096: dc4e10 FMUL double ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    s.fp.multiply64(read64(m,address));
  }
  L0062d099: { // 0x62d099: dc5e58 FCOMP double ptr [ESI + 0x58]
    const auto address=(s.si+0x00000058u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0062d09c: { // 0x62d09c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0062d09e: { // 0x62d09e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0062d0a1: { // 0x62d0a1: 0f85dbfeffff JNZ 0x0062cf82
    if(integer::condition("JNZ",flags)) goto L0062cf82;
  }
  L0062d0a7: { // 0x62d0a7: 8b7e6c MOV EDI,dword ptr [ESI + 0x6c]
    s.di = m.r32((s.si+0x0000006cu));
  }
  L0062d0aa: { // 0x62d0aa: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L0062d0ad: { // 0x62d0ad: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0062d0ae: { // 0x62d0ae: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0062d0b0: { // 0x62d0b0: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0062d0b2: { // 0x62d0b2: 897e6c MOV dword ptr [ESI + 0x6c],EDI
    m.w32((s.si+0x0000006cu), s.di);
  }
  L0062d0b5: { // 0x62d0b5: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0062d0b7: { // 0x62d0b7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062d0b8: { // 0x62d0b8: 0f9dc1 SETGE CL
    s.cx = with_al(s.cx, (integer::condition("JGE",flags)?1u:0u));
  }
  L0062d0bb: { // 0x62d0bb: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L0062d0bd: { // 0x62d0bd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062d0be: { // 0x62d0be: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062d0bf: { // 0x62d0bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062d0c0: { // 0x62d0c0: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0062d0c2: { // 0x62d0c2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062d0c3: { // 0x62d0c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0022d3a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062d3a0: { // 0x62d3a0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0062d3a3: { // 0x62d3a3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062d3a4: { // 0x62d3a4: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062d3a5: { // 0x62d3a5: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062d3a7: { // 0x62d3a7: 803f00 CMP byte ptr [EDI],0x0
    (void)integer::sub(m.r8((s.di)),0x00000000u,8,flags);
  }
  L0062d3aa: { // 0x62d3aa: 7508 JNZ 0x0062d3b4
    if(integer::condition("JNZ",flags)) goto L0062d3b4;
  }
  L0062d3ac: { // 0x62d3ac: c60701 MOV byte ptr [EDI],0x1
    m.w8((s.di), 0x00000001u);
  }
  L0062d3af: { // 0x62d3af: e86c010000 CALL 0x0062d520
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062d520u,6476724u); flags=s.arithmetic_flags;
  }
  L0062d3b4: { // 0x62d3b4: 8a4701 MOV AL,byte ptr [EDI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000001u)));
  }
  L0062d3b7: { // 0x62d3b7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062d3b9: { // 0x62d3b9: 0f8438010000 JZ 0x0062d4f7
    if(integer::condition("JZ",flags)) goto L0062d4f7;
  }
  L0062d3bf: { // 0x62d3bf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0062d3c1: { // 0x62d3c1: e8fa010000 CALL 0x0062d5c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062d5c0u,6476742u); flags=s.arithmetic_flags;
  }
  L0062d3c6: { // 0x62d3c6: 8b477c MOV EAX,dword ptr [EDI + 0x7c]
    s.ax = m.r32((s.di+0x0000007cu));
  }
  L0062d3c9: { // 0x62d3c9: c7477800000000 MOV dword ptr [EDI + 0x78],0x0
    m.w32((s.di+0x00000078u), 0x00000000u);
  }
  L0062d3d0: { // 0x62d3d0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062d3d2: { // 0x62d3d2: 0f8e1f010000 JLE 0x0062d4f7
    if(integer::condition("JLE",flags)) goto L0062d4f7;
  }
  L0062d3d8: { // 0x62d3d8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062d3d9: { // 0x62d3d9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062d3da: { // 0x62d3da: 8daf98000000 LEA EBP,[EDI + 0x98]
    s.bp = (s.di+0x00000098u);
  }
  L0062d3e0: { // 0x62d3e0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0062d3e2: { // 0x62d3e2: e8e9020000 CALL 0x0062d6d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062d6d0u,6476775u); flags=s.arithmetic_flags;
  }
  L0062d3e7: { // 0x62d3e7: 8a87b2000000 MOV AL,byte ptr [EDI + 0xb2]
    s.ax = with_al(s.ax, m.r8((s.di+0x000000b2u)));
  }
  L0062d3ed: { // 0x62d3ed: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L0062d3f3: { // 0x62d3f3: d2e8 SHR AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L0062d3f5: { // 0x62d3f5: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L0062d3fb: { // 0x62d3fb: 8a97b1000000 MOV DL,byte ptr [EDI + 0xb1]
    s.dx = with_al(s.dx, m.r8((s.di+0x000000b1u)));
  }
  L0062d401: { // 0x62d401: 6633db XOR BX,BX
    s.bx = with_ax(s.bx, integer::logical(((s.bx & 0xffffu))^((s.bx & 0xffffu)),16,flags));
  }
  L0062d404: { // 0x62d404: 8db78c000000 LEA ESI,[EDI + 0x8c]
    s.si = (s.di+0x0000008cu);
  }
  L0062d40a: { // 0x62d40a: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0062d40c: { // 0x62d40c: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  L0062d40f: { // 0x62d40f: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062d411: { // 0x62d411: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L0062d417: { // 0x62d417: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L0062d419: { // 0x62d419: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L0062d41f: { // 0x62d41f: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L0062d421: { // 0x62d421: 8a97b0000000 MOV DL,byte ptr [EDI + 0xb0]
    s.dx = with_al(s.dx, m.r8((s.di+0x000000b0u)));
  }
  L0062d427: { // 0x62d427: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062d429: { // 0x62d429: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L0062d42f: { // 0x62d42f: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L0062d431: { // 0x62d431: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L0062d437: { // 0x62d437: 0bd8 OR EBX,EAX
    s.bx = integer::logical((s.bx)|(s.ax),32,flags);
  }
  L0062d439: { // 0x62d439: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  L0062d43c: { // 0x62d43c: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L0062d43e: { // 0x62d43e: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062d440: { // 0x62d440: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0062d444: { // 0x62d444: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0062d445: { // 0x62d445: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0062d44b: { // 0x62d44b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062d44c: { // 0x62d44c: 0bd8 OR EBX,EAX
    s.bx = integer::logical((s.bx)|(s.ax),32,flags);
  }
  L0062d44e: { // 0x62d44e: e8bdab0600 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6476883u); flags=s.arithmetic_flags;
  }
  L0062d453: { // 0x62d453: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0062d459: { // 0x62d459: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0062d45d: { // 0x62d45d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d45e: { // 0x62d45e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062d45f: { // 0x62d45f: e8acab0600 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6476900u); flags=s.arithmetic_flags;
  }
  L0062d464: { // 0x62d464: 8b0d74198200 MOV ECX,dword ptr [0x00821974]
    s.cx = m.r32((0x00821974u));
  }
  L0062d46a: { // 0x62d46a: a170198200 MOV EAX,[0x00821970]
    s.ax = m.r32((0x00821970u));
  }
  L0062d46f: { // 0x62d46f: 8b1578198200 MOV EDX,dword ptr [0x00821978]
    s.dx = m.r32((0x00821978u));
  }
  L0062d475: { // 0x62d475: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0062d479: { // 0x62d479: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L0062d47d: { // 0x62d47d: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0062d481: { // 0x62d481: a17c198200 MOV EAX,[0x0082197c]
    s.ax = m.r32((0x0082197cu));
  }
  L0062d486: { // 0x62d486: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0062d48a: { // 0x62d48a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0062d48b: { // 0x62d48b: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0062d48f: { // 0x62d48f: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0062d493: { // 0x62d493: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0062d497: { // 0x62d497: e8c43a1300 CALL 0x00760f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760f60u,6476956u); flags=s.arithmetic_flags;
  }
  L0062d49c: { // 0x62d49c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062d49e: { // 0x62d49e: 7441 JZ 0x0062d4e1
    if(integer::condition("JZ",flags)) goto L0062d4e1;
  }
  L0062d4a0: { // 0x62d4a0: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0062d4a3: { // 0x62d4a3: e808ab0600 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6476968u); flags=s.arithmetic_flags;
  }
  L0062d4a8: { // 0x62d4a8: 8b7704 MOV ESI,dword ptr [EDI + 0x4]
    s.si = m.r32((s.di+0x00000004u));
  }
  L0062d4ab: { // 0x62d4ab: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0062d4ae: { // 0x62d4ae: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0062d4b0: { // 0x62d4b0: 83ee02 SUB ESI,0x2
    s.si = integer::sub(s.si,0x00000002u,32,flags);
  }
  L0062d4b3: { // 0x62d4b3: e8f8aa0600 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6476984u); flags=s.arithmetic_flags;
  }
  L0062d4b8: { // 0x62d4b8: bafeffffff MOV EDX,0xfffffffe
    s.dx = 0xfffffffeu;
  }
  L0062d4bd: { // 0x62d4bd: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062d4bf: { // 0x62d4bf: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L0062d4c1: { // 0x62d4c1: 8b0d9c1c8200 MOV ECX,dword ptr [0x00821c9c]
    s.cx = m.r32((0x00821c9cu));
  }
  L0062d4c7: { // 0x62d4c7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d4c8: { // 0x62d4c8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062d4c9: { // 0x62d4c9: 0fbfd3 MOVSX EDX,BX
    s.dx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L0062d4cc: { // 0x62d4cc: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0062d4ce: { // 0x62d4ce: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d4cf: { // 0x62d4cf: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0062d4d3: { // 0x62d4d3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d4d4: { // 0x62d4d4: 8d54242c LEA EDX,[ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L0062d4d8: { // 0x62d4d8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062d4d9: { // 0x62d4d9: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L0062d4de: { // 0x62d4de: ff5034 CALL dword ptr [EAX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000034u)),6477025u); flags=s.arithmetic_flags;
  }
  L0062d4e1: { // 0x62d4e1: 8b5778 MOV EDX,dword ptr [EDI + 0x78]
    s.dx = m.r32((s.di+0x00000078u));
  }
  L0062d4e4: { // 0x62d4e4: 8b4f7c MOV ECX,dword ptr [EDI + 0x7c]
    s.cx = m.r32((s.di+0x0000007cu));
  }
  L0062d4e7: { // 0x62d4e7: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062d4e8: { // 0x62d4e8: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0062d4ea: { // 0x62d4ea: 895778 MOV dword ptr [EDI + 0x78],EDX
    m.w32((s.di+0x00000078u), s.dx);
  }
  L0062d4ed: { // 0x62d4ed: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062d4ef: { // 0x62d4ef: 0f8cebfeffff JL 0x0062d3e0
    if(integer::condition("JL",flags)) goto L0062d3e0;
  }
  L0062d4f5: { // 0x62d4f5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062d4f6: { // 0x62d4f6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062d4f7: { // 0x62d4f7: 8b776c MOV ESI,dword ptr [EDI + 0x6c]
    s.si = m.r32((s.di+0x0000006cu));
  }
  L0062d4fa: { // 0x62d4fa: 8b5734 MOV EDX,dword ptr [EDI + 0x34]
    s.dx = m.r32((s.di+0x00000034u));
  }
  L0062d4fd: { // 0x62d4fd: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062d4fe: { // 0x62d4fe: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0062d500: { // 0x62d500: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062d502: { // 0x62d502: 89776c MOV dword ptr [EDI + 0x6c],ESI
    m.w32((s.di+0x0000006cu), s.si);
  }
  L0062d505: { // 0x62d505: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0062d507: { // 0x62d507: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062d508: { // 0x62d508: 0f9dc1 SETGE CL
    s.cx = with_al(s.cx, (integer::condition("JGE",flags)?1u:0u));
  }
  L0062d50b: { // 0x62d50b: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L0062d50d: { // 0x62d50d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062d50e: { // 0x62d50e: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0062d511: { // 0x62d511: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_0036d67b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076d67b: { // 0x76d67b: ff742404 PUSH dword ptr [ESP + 0x4]
    f.push(m,m.r32((f.sp+0x00000004u)));
  }
  L0076d67f: { // 0x76d67f: e8a4080000 CALL 0x0076df28
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076df28u,7788164u); flags=s.arithmetic_flags;
  }
  L0076d684: { // 0x76d684: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0076d685: { // 0x76d685: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6474368u:f_0022ca80(m,s,child,{});break;
case 6475376u:f_0022ce70(m,s,child,{});break;
case 6476704u:f_0022d3a0(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 7788155u:f_0036d67b(m,s,child,{});break;
default:throw std::domain_error("recovery1543 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1543 no reviewed tail"); } }

std::uint32_t fun_0062ca80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062ca80: { // 0x62ca80: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062ca81: { // 0x62ca81: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0062ca83: { // 0x62ca83: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0062ca86: { // 0x62ca86: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0062ca89: { // 0x62ca89: a138e0a900 MOV EAX,[0x00a9e038]
    s.ax = m.r32((0x00a9e038u));
  }
  L0062ca8e: { // 0x62ca8e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062ca8f: { // 0x62ca8f: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062ca90: { // 0x62ca90: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062ca91: { // 0x62ca91: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L0062ca94: { // 0x62ca94: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0062ca96: { // 0x62ca96: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0062ca98: { // 0x62ca98: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062ca99: { // 0x62ca99: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062ca9b: { // 0x62ca9b: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0062ca9f: { // 0x62ca9f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0062caa3: { // 0x62caa3: 7c2a JL 0x0062cacf
    if(integer::condition("JL",flags)) goto L0062cacf;
  }
  L0062caa5: { // 0x62caa5: a12ce0a900 MOV EAX,[0x00a9e02c]
    s.ax = m.r32((0x00a9e02cu));
  }
  L0062caaa: { // 0x62caaa: 8d7901 LEA EDI,[ECX + 0x1]
    s.di = (s.cx+0x00000001u);
  }
  L0062caad: { // 0x62caad: 8d1488 LEA EDX,[EAX + ECX*0x4]
    s.dx = (s.ax+(s.cx * 0x00000004u));
  }
  L0062cab0: { // 0x62cab0: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0062cab2: { // 0x62cab2: 83780802 CMP dword ptr [EAX + 0x8],0x2
    (void)integer::sub(m.r32((s.ax+0x00000008u)),0x00000002u,32,flags);
  }
  L0062cab6: { // 0x62cab6: 7509 JNZ 0x0062cac1
    if(integer::condition("JNZ",flags)) goto L0062cac1;
  }
  L0062cab8: { // 0x62cab8: 8a5801 MOV BL,byte ptr [EAX + 0x1]
    s.bx = with_al(s.bx, m.r8((s.ax+0x00000001u)));
  }
  L0062cabb: { // 0x62cabb: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062cabc: { // 0x62cabc: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L0062cabe: { // 0x62cabe: 7401 JZ 0x0062cac1
    if(integer::condition("JZ",flags)) goto L0062cac1;
  }
  L0062cac0: { // 0x62cac0: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0062cac1: { // 0x62cac1: 83ea04 SUB EDX,0x4
    s.dx = integer::sub(s.dx,0x00000004u,32,flags);
  }
  L0062cac4: { // 0x62cac4: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0062cac5: { // 0x62cac5: 75e9 JNZ 0x0062cab0
    if(integer::condition("JNZ",flags)) goto L0062cab0;
  }
  L0062cac7: { // 0x62cac7: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0062cacb: { // 0x62cacb: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0062cacf: { // 0x62cacf: 8b154c67a500 MOV EDX,dword ptr [0x00a5674c]
    s.dx = m.r32((0x00a5674cu));
  }
  L0062cad5: { // 0x62cad5: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  L0062cadd: { // 0x62cadd: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0062cae1: { // 0x62cae1: df6c2420 FILD qword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0062cae5: { // 0x62cae5: db059858a200 FILD dword ptr [0x00a25898]
    const auto address=(0x00a25898u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062caeb: { // 0x62caeb: def9 FDIVP
    numeric_b88::detail::reg<0xdef9>(s.fp);
  }
  L0062caed: { // 0x62caed: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062caef: { // 0x62caef: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L0062caf1: { // 0x62caf1: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L0062caf3: { // 0x62caf3: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062caf7: { // 0x62caf7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062cafb: { // 0x62cafb: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062caff: { // 0x62caff: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062cb01: { // 0x62cb01: dc742420 FDIV double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.divide64(read64(m,address));
  }
  L0062cb05: { // 0x62cb05: d8e2 FSUB ST0,ST2
    numeric_b88::detail::reg<0xd8e2>(s.fp);
  }
  L0062cb07: { // 0x62cb07: dd5c2418 FSTP double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb0b: { // 0x62cb0b: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L0062cb11: { // 0x62cb11: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L0062cb15: { // 0x62cb15: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0062cb1b: { // 0x62cb1b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0062cb1d: { // 0x62cb1d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0062cb20: { // 0x62cb20: 750a JNZ 0x0062cb2c
    if(integer::condition("JNZ",flags)) goto L0062cb2c;
  }
  L0062cb22: { // 0x62cb22: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062cb24: { // 0x62cb24: dd442420 FLD double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L0062cb28: { // 0x62cb28: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L0062cb2c: { // 0x62cb2c: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0062cb2e: { // 0x62cb2e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062cb30: { // 0x62cb30: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0062cb32: { // 0x62cb32: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb36: { // 0x62cb36: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062cb38: { // 0x62cb38: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L0062cb3e: { // 0x62cb3e: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L0062cb40: { // 0x62cb40: dd5c2420 FSTP double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb44: { // 0x62cb44: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062cb46: { // 0x62cb46: 0f8cf7000000 JL 0x0062cc43
    if(integer::condition("JL",flags)) goto L0062cc43;
  }
  L0062cb4c: { // 0x62cb4c: bd64000000 MOV EBP,0x64
    s.bp = 0x00000064u;
  }
  L0062cb51: { // 0x62cb51: a12ce0a900 MOV EAX,[0x00a9e02c]
    s.ax = m.r32((0x00a9e02cu));
  }
  L0062cb56: { // 0x62cb56: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0062cb59: { // 0x62cb59: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0062cb5d: { // 0x62cb5d: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0062cb60: { // 0x62cb60: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0062cb63: { // 0x62cb63: 753c JNZ 0x0062cba1
    if(integer::condition("JNZ",flags)) goto L0062cba1;
  }
  L0062cb65: { // 0x62cb65: dd442420 FLD double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L0062cb69: { // 0x62cb69: dc0d30817800 FMUL double ptr [0x00788130]
    const auto address=(0x00788130u);
    s.fp.multiply64(read64(m,address));
  }
  L0062cb6f: { // 0x62cb6f: e8dcde1300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6474612u); flags=s.arithmetic_flags;
  }
  L0062cb74: { // 0x62cb74: 83f80a CMP EAX,0xa
    (void)integer::sub(s.ax,0x0000000au,32,flags);
  }
  L0062cb77: { // 0x62cb77: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0062cb7b: { // 0x62cb7b: 7d0a JGE 0x0062cb87
    if(integer::condition("JGE",flags)) goto L0062cb87;
  }
  L0062cb7d: { // 0x62cb7d: c74424180a000000 MOV dword ptr [ESP + 0x18],0xa
    m.w32((f.sp+0x00000018u), 0x0000000au);
  }
  L0062cb85: { // 0x62cb85: eb08 JMP 0x0062cb8f
    goto L0062cb8f;
  }
  L0062cb87: { // 0x62cb87: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0062cb89: { // 0x62cb89: 7e04 JLE 0x0062cb8f
    if(integer::condition("JLE",flags)) goto L0062cb8f;
  }
  L0062cb8b: { // 0x62cb8b: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0062cb8f: { // 0x62cb8f: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062cb93: { // 0x62cb93: dd5e10 FSTP double ptr [ESI + 0x10]
    const auto address=(s.si+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0062cb96: { // 0x62cb96: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0062cb9a: { // 0x62cb9a: e8d1020000 CALL 0x0062ce70
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062ce70u,6474655u); flags=s.arithmetic_flags;
  }
  L0062cb9f: { // 0x62cb9f: eb46 JMP 0x0062cbe7
    goto L0062cbe7;
  }
  L0062cba1: { // 0x62cba1: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0062cba4: { // 0x62cba4: 0f8592000000 JNZ 0x0062cc3c
    if(integer::condition("JNZ",flags)) goto L0062cc3c;
  }
  L0062cbaa: { // 0x62cbaa: 8a4601 MOV AL,byte ptr [ESI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000001u)));
  }
  L0062cbad: { // 0x62cbad: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062cbaf: { // 0x62cbaf: 742f JZ 0x0062cbe0
    if(integer::condition("JZ",flags)) goto L0062cbe0;
  }
  L0062cbb1: { // 0x62cbb1: 6a63 PUSH 0x63
    f.push(m,0x00000063u);
  }
  L0062cbb3: { // 0x62cbb3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062cbb5: { // 0x62cbb5: b958158200 MOV ECX,0x821558
    s.cx = 0x00821558u;
  }
  L0062cbba: { // 0x62cbba: e881320000 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6474687u); flags=s.arithmetic_flags;
  }
  L0062cbbf: { // 0x62cbbf: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0062cbc1: { // 0x62cbc1: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0062cbc5: { // 0x62cbc5: dc0df0677800 FMUL double ptr [0x007867f0]
    const auto address=(0x007867f0u);
    s.fp.multiply64(read64(m,address));
  }
  L0062cbcb: { // 0x62cbcb: e880de1300 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6474704u); flags=s.arithmetic_flags;
  }
  L0062cbd0: { // 0x62cbd0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0062cbd2: { // 0x62cbd2: 7d08 JGE 0x0062cbdc
    if(integer::condition("JGE",flags)) goto L0062cbdc;
  }
  L0062cbd4: { // 0x62cbd4: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0062cbd8: { // 0x62cbd8: c6410100 MOV byte ptr [ECX + 0x1],0x0
    m.w8((s.cx+0x00000001u), 0x00000000u);
  }
  L0062cbdc: { // 0x62cbdc: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0062cbe0: { // 0x62cbe0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062cbe2: { // 0x62cbe2: e8b9070000 CALL 0x0062d3a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062d3a0u,6474727u); flags=s.arithmetic_flags;
  }
  L0062cbe7: { // 0x62cbe7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0062cbe9: { // 0x62cbe9: 7451 JZ 0x0062cc3c
    if(integer::condition("JZ",flags)) goto L0062cc3c;
  }
  L0062cbeb: { // 0x62cbeb: a128e0a900 MOV EAX,[0x00a9e028]
    s.ax = m.r32((0x00a9e028u));
  }
  L0062cbf0: { // 0x62cbf0: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0062cbf4: { // 0x62cbf4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062cbf5: { // 0x62cbf5: b928e0a900 MOV ECX,0xa9e028
    s.cx = 0x00a9e028u;
  }
  L0062cbfa: { // 0x62cbfa: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6474749u); flags=s.arithmetic_flags;
  }
  L0062cbfd: { // 0x62cbfd: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0062cc00: { // 0x62cc00: 742d JZ 0x0062cc2f
    if(integer::condition("JZ",flags)) goto L0062cc2f;
  }
  L0062cc02: { // 0x62cc02: 8b0d38e0a900 MOV ECX,dword ptr [0x00a9e038]
    s.cx = m.r32((0x00a9e038u));
  }
  L0062cc08: { // 0x62cc08: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062cc0a: { // 0x62cc0a: 7d23 JGE 0x0062cc2f
    if(integer::condition("JGE",flags)) goto L0062cc2f;
  }
  L0062cc0c: { // 0x62cc0c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062cc0d: { // 0x62cc0d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062cc0f: { // 0x62cc0f: 890d38e0a900 MOV dword ptr [0x00a9e038],ECX
    m.w32((0x00a9e038u), s.cx);
  }
  L0062cc15: { // 0x62cc15: 7d18 JGE 0x0062cc2f
    if(integer::condition("JGE",flags)) goto L0062cc2f;
  }
  L0062cc17: { // 0x62cc17: 8b0d2ce0a900 MOV ECX,dword ptr [0x00a9e02c]
    s.cx = m.r32((0x00a9e02cu));
  }
  L0062cc1d: { // 0x62cc1d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062cc1e: { // 0x62cc1e: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0062cc21: { // 0x62cc21: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0062cc25: { // 0x62cc25: 8b0d38e0a900 MOV ECX,dword ptr [0x00a9e038]
    s.cx = m.r32((0x00a9e038u));
  }
  L0062cc2b: { // 0x62cc2b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062cc2d: { // 0x62cc2d: 7ce8 JL 0x0062cc17
    if(integer::condition("JL",flags)) goto L0062cc17;
  }
  L0062cc2f: { // 0x62cc2f: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0062cc33: { // 0x62cc33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062cc34: { // 0x62cc34: e8420a1400 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6474809u); flags=s.arithmetic_flags;
  }
  L0062cc39: { // 0x62cc39: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0062cc3c: { // 0x62cc3c: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0062cc3d: { // 0x62cc3d: 0f890effffff JNS 0x0062cb51
    if(integer::condition("JNS",flags)) goto L0062cb51;
  }
  L0062cc43: { // 0x62cc43: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062cc44: { // 0x62cc44: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062cc45: { // 0x62cc45: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062cc46: { // 0x62cc46: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062cc47: { // 0x62cc47: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0062cc49: { // 0x62cc49: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062cc4a: { // 0x62cc4a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
