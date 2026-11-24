#include "recovered/recovery_b220_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b220 {
namespace {
void f_0001b630(Memory&,State&,Frame&,const Operations&);
void f_00298010(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00075040(Memory&,State&,Frame&,const Operations&);
void f_001d46d0(Memory&,State&,Frame&,const Operations&);
void f_001d57d0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_00298010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698010: { // 0x698010: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00698013: { // 0x698013: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00698014: { // 0x698014: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00698018: { // 0x698018: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00698019: { // 0x698019: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069801a: { // 0x69801a: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L0069801c: { // 0x69801c: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L0069801f: { // 0x69801f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00698023: { // 0x698023: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00698025: { // 0x698025: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698028: { // 0x698028: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698029: { // 0x698029: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0069802d: { // 0x69802d: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00698030: { // 0x698030: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698033: { // 0x698033: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069803b: { // 0x69803b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069803e: { // 0x69803e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069803f: { // 0x69803f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698041: { // 0x698041: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698043: { // 0x698043: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698046: { // 0x698046: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698048: { // 0x698048: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069804b: { // 0x69804b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069804d: { // 0x69804d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069804e: { // 0x69804e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698050: { // 0x698050: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698052: { // 0x698052: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698054: { // 0x698054: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00698057: { // 0x698057: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00698059: { // 0x698059: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069805b: { // 0x69805b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069805e: { // 0x69805e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069805f: { // 0x69805f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698061: { // 0x698061: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698063: { // 0x698063: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00698065: { // 0x698065: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00698068: { // 0x698068: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069806a: { // 0x69806a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069806d: { // 0x69806d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00698071: { // 0x698071: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00698073: { // 0x698073: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698074: { // 0x698074: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698076: { // 0x698076: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0069807a: { // 0x69807a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069807c: { // 0x69807c: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069807e: { // 0x69807e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698080: { // 0x698080: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698081: { // 0x698081: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698087: { // 0x698087: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698089: { // 0x698089: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069808b: { // 0x69808b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069808d: { // 0x69808d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069808e: { // 0x69808e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698094: { // 0x698094: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698096: { // 0x698096: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698098: { // 0x698098: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809b: { // 0x69809b: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809e: { // 0x69809e: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L006980a4: { // 0x6980a4: 7c08 JL 0x006980ae
    if(integer::condition("JL",flags)) goto L006980ae;
  }
  L006980a6: { // 0x6980a6: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L006980ae: { // 0x6980ae: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006980b2: { // 0x6980b2: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L006980b8: { // 0x6980b8: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006980bc: { // 0x6980bc: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L006980c2: { // 0x6980c2: e889290d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914247u); flags=s.arithmetic_flags;
  }
  L006980c7: { // 0x6980c7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006980c9: { // 0x6980c9: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006980cd: { // 0x6980cd: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980cf: { // 0x6980cf: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980d2: { // 0x6980d2: 8b8db0000000 MOV ECX,dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L006980d8: { // 0x6980d8: 8badb4000000 MOV EBP,dword ptr [EBP + 0xb4]
    s.bp = m.r32((s.bp+0x000000b4u));
  }
  L006980de: { // 0x6980de: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L006980e0: { // 0x6980e0: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006980e3: { // 0x6980e3: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006980e5: { // 0x6980e5: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L006980e7: { // 0x6980e7: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980e9: { // 0x6980e9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006980eb: { // 0x6980eb: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980ee: { // 0x6980ee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006980f0: { // 0x6980f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006980f1: { // 0x6980f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006980f2: { // 0x6980f2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006980f3: { // 0x6980f3: 81f998feffff CMP ECX,0xfffffe98
    (void)integer::sub(s.cx,0xfffffe98u,32,flags);
  }
  L006980f9: { // 0x6980f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006980fa: { // 0x6980fa: 7d08 JGE 0x00698104
    if(integer::condition("JGE",flags)) goto L00698104;
  }
  L006980fc: { // 0x6980fc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006980fe: { // 0x6980fe: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698101: { // 0x698101: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00698104: { // 0x698104: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
  L0069810a: { // 0x69810a: 81c268010000 ADD EDX,0x168
    s.dx = integer::add(s.dx,0x00000168u,32,flags);
  }
  L00698110: { // 0x698110: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00698112: { // 0x698112: 7e08 JLE 0x0069811c
    if(integer::condition("JLE",flags)) goto L0069811c;
  }
  L00698114: { // 0x698114: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698116: { // 0x698116: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698119: { // 0x698119: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069811c: { // 0x69811c: 3d4cffffff CMP EAX,0xffffff4c
    (void)integer::sub(s.ax,0xffffff4cu,32,flags);
  }
  L00698121: { // 0x698121: 7d08 JGE 0x0069812b
    if(integer::condition("JGE",flags)) goto L0069812b;
  }
  L00698123: { // 0x698123: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698125: { // 0x698125: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698128: { // 0x698128: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069812b: { // 0x69812b: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L00698131: { // 0x698131: 81c1b4000000 ADD ECX,0xb4
    s.cx = integer::add(s.cx,0x000000b4u,32,flags);
  }
  L00698137: { // 0x698137: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00698139: { // 0x698139: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0069813c: { // 0x69813c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069813f: { // 0x69813f: c20800 RET 0x8
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
void f_00075040(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00475040: { // 0x00475040: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00475043: { // 0x00475043: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00475044: { // 0x00475044: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00475046: { // 0x00475046: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L0047504a: { // 0x0047504a: 8b5644 MOV EDX,dword ptr [ESI + 0x44]
    s.dx = m.r32((s.si+0x00000044u));
  }
  L0047504d: { // 0x0047504d: e87ef61500 CALL 0x005d46d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d46d0u,4673618u); flags=s.arithmetic_flags;
  }
  L00475052: { // 0x00475052: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00475054: { // 0x00475054: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00475057: { // 0x00475057: 8a8640010000 MOV AL,byte ptr [ESI + 0x140]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000140u)));
  }
  L0047505d: { // 0x0047505d: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  L0047505f: { // 0x0047505f: 7413 JZ 0x00475074
    if(integer::condition("JZ",flags)) goto L00475074;
  }
  L00475061: { // 0x00475061: 8a861e010000 MOV AL,byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00475067: { // 0x00475067: 83e910 SUB ECX,0x10
    s.cx = integer::sub(s.cx,0x00000010u,32,flags);
  }
  L0047506a: { // 0x0047506a: 3c09 CMP AL,0x9
    (void)integer::sub((s.ax & 0xffu),0x00000009u,8,flags);
  }
  L0047506c: { // 0x0047506c: 7212 JC 0x00475080
    if(integer::condition("JC",flags)) goto L00475080;
  }
  L0047506e: { // 0x0047506e: 3c11 CMP AL,0x11
    (void)integer::sub((s.ax & 0xffu),0x00000011u,8,flags);
  }
  L00475070: { // 0x00475070: 770e JA 0x00475080
    if(integer::condition("JA",flags)) goto L00475080;
  }
  L00475072: { // 0x00475072: eb09 JMP 0x0047507d
    goto L0047507d;
  }
  L00475074: { // 0x00475074: 817e44ef000000 CMP dword ptr [ESI + 0x44],0xef
    (void)integer::sub(m.r32((s.si+0x00000044u)),0x000000efu,32,flags);
  }
  L0047507b: { // 0x0047507b: 7503 JNZ 0x00475080
    if(integer::condition("JNZ",flags)) goto L00475080;
  }
  L0047507d: { // 0x0047507d: 83e90f SUB ECX,0xf
    s.cx = integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L00475080: { // 0x00475080: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L00475087: { // 0x00475087: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  L0047508d: { // 0x0047508d: 83c21e ADD EDX,0x1e
    s.dx = integer::add(s.dx,0x0000001eu,32,flags);
  }
  L00475090: { // 0x00475090: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00475093: { // 0x00475093: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00475096: { // 0x00475096: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00475098: { // 0x00475098: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0047509c: { // 0x0047509c: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0047509e: { // 0x0047509e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047509f: { // 0x0047509f: 83c10f ADD ECX,0xf
    s.cx = integer::add(s.cx,0x0000000fu,32,flags);
  }
  L004750a2: { // 0x004750a2: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004750a4: { // 0x004750a4: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L004750a7: { // 0x004750a7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004750aa: { // 0x004750aa: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001d46d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d46d0: { // 0x5d46d0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005d46d2: { // 0x5d46d2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d46d3: { // 0x5d46d3: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L005d46d9: { // 0x5d46d9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d46da: { // 0x5d46da: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d46db: { // 0x5d46db: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005d46dd: { // 0x5d46dd: 8b3491 MOV ESI,dword ptr [ECX + EDX*0x4]
    s.si = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L005d46e0: { // 0x5d46e0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005d46e2: { // 0x5d46e2: 8a9e79020000 MOV BL,byte ptr [ESI + 0x279]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000279u)));
  }
  L005d46e8: { // 0x5d46e8: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005d46ea: { // 0x5d46ea: 751d JNZ 0x005d4709
    if(integer::condition("JNZ",flags)) goto L005d4709;
  }
  L005d46ec: { // 0x5d46ec: 8a9e78020000 MOV BL,byte ptr [ESI + 0x278]
    s.bx = with_al(s.bx, m.r8((s.si+0x00000278u)));
  }
  L005d46f2: { // 0x5d46f2: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005d46f4: { // 0x5d46f4: 7513 JNZ 0x005d4709
    if(integer::condition("JNZ",flags)) goto L005d4709;
  }
  L005d46f6: { // 0x5d46f6: 83be640200007e CMP dword ptr [ESI + 0x264],0x7e
    (void)integer::sub(m.r32((s.si+0x00000264u)),0x0000007eu,32,flags);
  }
  L005d46fd: { // 0x5d46fd: 740a JZ 0x005d4709
    if(integer::condition("JZ",flags)) goto L005d4709;
  }
  L005d46ff: { // 0x5d46ff: 8a9e7a020000 MOV BL,byte ptr [ESI + 0x27a]
    s.bx = with_al(s.bx, m.r8((s.si+0x0000027au)));
  }
  L005d4705: { // 0x5d4705: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005d4707: { // 0x5d4707: 7405 JZ 0x005d470e
    if(integer::condition("JZ",flags)) goto L005d470e;
  }
  L005d4709: { // 0x5d4709: b9f4ffffff MOV ECX,0xfffffff4
    s.cx = 0xfffffff4u;
  }
  L005d470e: { // 0x5d470e: 83be6802000009 CMP dword ptr [ESI + 0x268],0x9
    (void)integer::sub(m.r32((s.si+0x00000268u)),0x00000009u,32,flags);
  }
  L005d4715: { // 0x5d4715: 7501 JNZ 0x005d4718
    if(integer::condition("JNZ",flags)) goto L005d4718;
  }
  L005d4717: { // 0x5d4717: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005d4718: { // 0x5d4718: 83fa7e CMP EDX,0x7e
    (void)integer::sub(s.dx,0x0000007eu,32,flags);
  }
  L005d471b: { // 0x5d471b: 7501 JNZ 0x005d471e
    if(integer::condition("JNZ",flags)) goto L005d471e;
  }
  L005d471d: { // 0x5d471d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005d471e: { // 0x5d471e: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L005d4720: { // 0x5d4720: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d4721: { // 0x5d4721: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d4722: { // 0x5d4722: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L005d4725: { // 0x5d4725: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d4726: { // 0x5d4726: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001d57d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d57d0: { // 0x5d57d0: 81ec64020000 SUB ESP, 0x264
    f.sp = integer::sub(f.sp,0x00000264u,32,flags);
  }
  L005d57d6: { // 0x5d57d6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d57d7: { // 0x5d57d7: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005d57d9: { // 0x5d57d9: 8b86a4000000 MOV EAX, dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L005d57df: { // 0x5d57df: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d57e1: { // 0x5d57e1: 0f85f0000000 JNZ 0x5d58d7
    if(integer::condition("JNZ",flags)) goto L005d58d7;
  }
  L005d57e7: { // 0x5d57e7: 8a8e7f020000 MOV CL, byte ptr [ESI + 0x27f]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000027fu)));
  }
  L005d57ed: { // 0x5d57ed: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005d57ef: { // 0x5d57ef: 0f84e2000000 JZ 0x5d58d7
    if(integer::condition("JZ",flags)) goto L005d58d7;
  }
  L005d57f5: { // 0x5d57f5: 8d4664 LEA EAX, [ESI + 0x64]
    s.ax = (s.si+0x00000064u);
  }
  L005d57f8: { // 0x5d57f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d57f9: { // 0x5d57f9: 68a49f7b00 PUSH 0x7b9fa4
    f.push(m,0x007b9fa4u);
  }
  L005d57fe: { // 0x5d57fe: e8ed10e3ff CALL 0x4068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,6117379u); flags=s.arithmetic_flags;
  }
  L005d5803: { // 0x5d5803: 8a86fc010000 MOV AL, byte ptr [ESI + 0x1fc]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fcu)));
  }
  L005d5809: { // 0x5d5809: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005d580c: { // 0x5d580c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d580e: { // 0x5d580e: 7434 JZ 0x5d5844
    if(integer::condition("JZ",flags)) goto L005d5844;
  }
  L005d5810: { // 0x5d5810: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L005d5816: { // 0x5d5816: 8b8138080000 MOV EAX, dword ptr [ECX + 0x838]
    s.ax = m.r32((s.cx+0x00000838u));
  }
  L005d581c: { // 0x5d581c: 8d1440 LEA EDX, [EAX + EAX*2]
    s.dx = (s.ax+(s.ax * 2u));
  }
  L005d581f: { // 0x5d581f: 8d0490 LEA EAX, [EAX + EDX*4]
    s.ax = (s.ax+(s.dx * 4u));
  }
  L005d5822: { // 0x5d5822: 8d96c8010000 LEA EDX, [ESI + 0x1c8]
    s.dx = (s.si+0x000001c8u);
  }
  L005d5828: { // 0x5d5828: 8d0cc5ac5b7800 LEA ECX, [EAX*8 + 0x785bac]
    s.cx = ((s.ax * 8u)+0x00785bacu);
  }
  L005d582f: { // 0x5d582f: 8d442468 LEA EAX, [ESP + 0x68]
    s.ax = (f.sp+0x00000068u);
  }
  L005d5833: { // 0x5d5833: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5834: { // 0x5d5834: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d5835: { // 0x5d5835: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5837: { // 0x5d5837: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5839: { // 0x5d5839: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d583a: { // 0x5d583a: e8f1921900 CALL 0x76eb30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076eb30u,6117439u); flags=s.arithmetic_flags;
  }
  L005d583f: { // 0x5d583f: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005d5842: { // 0x5d5842: eb3b JMP 0x5d587f
    goto L005d587f;
  }
  L005d5844: { // 0x5d5844: 8a8607020000 MOV AL, byte ptr [ESI + 0x207]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000207u)));
  }
  L005d584a: { // 0x5d584a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d584c: { // 0x5d584c: 7431 JZ 0x5d587f
    if(integer::condition("JZ",flags)) goto L005d587f;
  }
  L005d584e: { // 0x5d584e: 8d8ec8010000 LEA ECX, [ESI + 0x1c8]
    s.cx = (s.si+0x000001c8u);
  }
  L005d5854: { // 0x5d5854: 68a49c7b00 PUSH 0x7b9ca4
    f.push(m,0x007b9ca4u);
  }
  L005d5859: { // 0x5d5859: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d585a: { // 0x5d585a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d585c: { // 0x5d585c: 8d542474 LEA EDX, [ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L005d5860: { // 0x5d5860: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5862: { // 0x5d5862: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d5863: { // 0x5d5863: e8c8921900 CALL 0x76eb30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076eb30u,6117480u); flags=s.arithmetic_flags;
  }
  L005d5868: { // 0x5d5868: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L005d586d: { // 0x5d586d: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005d5870: { // 0x5d5870: 8d4c2468 LEA ECX, [ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L005d5874: { // 0x5d5874: 8b9038080000 MOV EDX, dword ptr [EAX + 0x838]
    s.dx = m.r32((s.ax+0x00000838u));
  }
  L005d587a: { // 0x5d587a: e8e1a9ffff CALL 0x5d0260
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d0260u,6117503u); flags=s.arithmetic_flags;
  }
  L005d587f: { // 0x5d587f: 8d4c2468 LEA ECX, [ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L005d5883: { // 0x5d5883: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d5884: { // 0x5d5884: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5885: { // 0x5d5885: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L005d5889: { // 0x5d5889: e8e232e9ff CALL 0x468b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468b70u,6117518u); flags=s.arithmetic_flags;
  }
  L005d588e: { // 0x5d588e: 8d4c2408 LEA ECX, [ESP + 8]
    s.cx = (f.sp+8u);
  }
  L005d5892: { // 0x5d5892: e879f7ebff CALL 0x495010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00495010u,6117527u); flags=s.arithmetic_flags;
  }
  L005d5897: { // 0x5d5897: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L005d5899: { // 0x5d5899: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005d589b: { // 0x5d589b: 89bea4000000 MOV dword ptr [ESI + 0xa4], EDI
    m.w32((s.si+0x000000a4u), s.di);
  }
  L005d58a1: { // 0x5d58a1: 7407 JZ 0x5d58aa
    if(integer::condition("JZ",flags)) goto L005d58aa;
  }
  L005d58a3: { // 0x5d58a3: c686a800000001 MOV byte ptr [ESI + 0xa8], 1
    m.w8((s.si+0x000000a8u), 1u);
  }
  L005d58aa: { // 0x5d58aa: 8d4c245c LEA ECX, [ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L005d58ae: { // 0x5d58ae: c7442408a0567800 MOV dword ptr [ESP + 8], 0x7856a0
    m.w32((f.sp+8u), 0x007856a0u);
  }
  L005d58b6: { // 0x5d58b6: c744246800000000 MOV dword ptr [ESP + 0x68], 0
    m.w32((f.sp+0x00000068u), 0u);
  }
  L005d58be: { // 0x5d58be: e8cd29e6ff CALL 0x438290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,6117571u); flags=s.arithmetic_flags;
  }
  L005d58c3: { // 0x5d58c3: 8d4c2408 LEA ECX, [ESP + 8]
    s.cx = (f.sp+8u);
  }
  L005d58c7: { // 0x5d58c7: c744240858567800 MOV dword ptr [ESP + 8], 0x785658
    m.w32((f.sp+8u), 0x00785658u);
  }
  L005d58cf: { // 0x5d58cf: e87c99e5ff CALL 0x42f250
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042f250u,6117588u); flags=s.arithmetic_flags;
  }
  L005d58d4: { // 0x5d58d4: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L005d58d6: { // 0x5d58d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d58d7: { // 0x5d58d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d58d8: { // 0x5d58d8: 81c464020000 ADD ESP, 0x264
    f.sp = integer::add(f.sp,0x00000264u,32,flags);
  }
  L005d58de: { // 0x5d58de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4306480u:f_0001b630(m,s,child,{});break;
case 6914064u:f_00298010(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4673600u:f_00075040(m,s,child,{});break;
case 6112976u:f_001d46d0(m,s,child,{});break;
case 6117328u:f_001d57d0(m,s,child,{});break;
default:throw std::domain_error("recovery220 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00474d00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00474d00: { // 0x474d00: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L00474d03: { // 0x474d03: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00474d04: { // 0x474d04: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00474d05: { // 0x474d05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00474d06: { // 0x474d06: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00474d07: { // 0x474d07: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00474d09: { // 0x474d09: 8b4744 MOV EAX,dword ptr [EDI + 0x44]
    s.ax = m.r32((s.di+0x00000044u));
  }
  L00474d0c: { // 0x474d0c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00474d0f: { // 0x474d0f: 750d JNZ 0x00474d1e
    if(integer::condition("JNZ",flags)) goto L00474d1e;
  }
  L00474d11: { // 0x474d11: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474d13: { // 0x474d13: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474d15: { // 0x474d15: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474d17: { // 0x474d17: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474d19: { // 0x474d19: e974010000 JMP 0x00474e92
    goto L00474e92;
  }
  L00474d1e: { // 0x474d1e: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00474d24: { // 0x474d24: 8b3481 MOV ESI,dword ptr [ECX + EAX*0x4]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00474d27: { // 0x474d27: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00474d29: { // 0x474d29: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00474d2b: { // 0x474d2b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4672817u); flags=s.arithmetic_flags;
  }
  L00474d31: { // 0x474d31: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00474d33: { // 0x474d33: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00474d35: { // 0x474d35: 750d JNZ 0x00474d44
    if(integer::condition("JNZ",flags)) goto L00474d44;
  }
  L00474d37: { // 0x474d37: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474d39: { // 0x474d39: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474d3b: { // 0x474d3b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474d3d: { // 0x474d3d: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474d3f: { // 0x474d3f: e94e010000 JMP 0x00474e92
    goto L00474e92;
  }
  L00474d44: { // 0x474d44: 8a871e010000 MOV AL,byte ptr [EDI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011eu)));
  }
  L00474d4a: { // 0x474d4a: 88442410 MOV byte ptr [ESP + 0x10],AL
    m.w8((f.sp+0x00000010u), (s.ax & 0xffu));
  }
  L00474d4e: { // 0x474d4e: 8a867a020000 MOV AL,byte ptr [ESI + 0x27a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000027au)));
  }
  L00474d54: { // 0x474d54: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00474d56: { // 0x474d56: 7405 JZ 0x00474d5d
    if(integer::condition("JZ",flags)) goto L00474d5d;
  }
  L00474d58: { // 0x474d58: c644241000 MOV byte ptr [ESP + 0x10],0x0
    m.w8((f.sp+0x00000010u), 0x00000000u);
  }
  L00474d5d: { // 0x474d5d: 0fbf4506 MOVSX EAX,word ptr [EBP + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000006u)),16));
  }
  L00474d61: { // 0x474d61: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474d62: { // 0x474d62: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474d64: { // 0x474d64: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00474d68: { // 0x474d68: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00474d6a: { // 0x474d6a: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00474d70: { // 0x474d70: 0fbf4726 MOVSX EAX,word ptr [EDI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000026u)),16));
  }
  L00474d74: { // 0x474d74: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d77: { // 0x474d77: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00474d7c: { // 0x474d7c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00474d7e: { // 0x474d7e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474d7f: { // 0x474d7f: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474d81: { // 0x474d81: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00474d83: { // 0x474d83: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474d89: { // 0x474d89: 0fbf4f24 MOVSX ECX,word ptr [EDI + 0x24]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000024u)),16));
  }
  L00474d8d: { // 0x474d8d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474d8f: { // 0x474d8f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474d92: { // 0x474d92: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d95: { // 0x474d95: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474d98: { // 0x474d98: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00474d9e: { // 0x474d9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474d9f: { // 0x474d9f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00474da1: { // 0x474da1: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00474da5: { // 0x474da5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474da6: { // 0x474da6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474dac: { // 0x474dac: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474dae: { // 0x474dae: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474db1: { // 0x474db1: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474db4: { // 0x474db4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474db5: { // 0x474db5: e87668faff CALL 0x0041b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,4672954u); flags=s.arithmetic_flags;
  }
  L00474dba: { // 0x474dba: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00474dbe: { // 0x474dbe: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00474dc2: { // 0x474dc2: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00474dc6: { // 0x474dc6: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00474dca: { // 0x474dca: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00474dce: { // 0x474dce: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L00474dd2: { // 0x474dd2: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L00474dd6: { // 0x474dd6: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00474dda: { // 0x474dda: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00474de0: { // 0x474de0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474de1: { // 0x474de1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474de2: { // 0x474de2: e829322200 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,4672999u); flags=s.arithmetic_flags;
  }
  L00474de7: { // 0x474de7: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00474deb: { // 0x474deb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00474dec: { // 0x474dec: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00474dee: { // 0x474dee: e84d020000 CALL 0x00475040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475040u,4673011u); flags=s.arithmetic_flags;
  }
  L00474df3: { // 0x474df3: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00474df7: { // 0x474df7: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00474df9: { // 0x474df9: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00474dfb: { // 0x474dfb: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L00474dff: { // 0x474dff: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e03: { // 0x474e03: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00474e06: { // 0x474e06: 8a8740010000 MOV AL,byte ptr [EDI + 0x140]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000140u)));
  }
  L00474e0c: { // 0x474e0c: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00474e0e: { // 0x474e0e: 83e91e SUB ECX,0x1e
    s.cx = integer::sub(s.cx,0x0000001eu,32,flags);
  }
  L00474e11: { // 0x474e11: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00474e15: { // 0x474e15: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  L00474e17: { // 0x474e17: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e1b: { // 0x474e1b: 741c JZ 0x00474e39
    if(integer::condition("JZ",flags)) goto L00474e39;
  }
  L00474e1d: { // 0x474e1d: 8a871e010000 MOV AL,byte ptr [EDI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011eu)));
  }
  L00474e23: { // 0x474e23: 3c09 CMP AL,0x9
    (void)integer::sub((s.ax & 0xffu),0x00000009u,8,flags);
  }
  L00474e25: { // 0x474e25: 7212 JC 0x00474e39
    if(integer::condition("JC",flags)) goto L00474e39;
  }
  L00474e27: { // 0x474e27: 3c11 CMP AL,0x11
    (void)integer::sub((s.ax & 0xffu),0x00000011u,8,flags);
  }
  L00474e29: { // 0x474e29: 770e JA 0x00474e39
    if(integer::condition("JA",flags)) goto L00474e39;
  }
  L00474e2b: { // 0x474e2b: 83e90f SUB ECX,0xf
    s.cx = integer::sub(s.cx,0x0000000fu,32,flags);
  }
  L00474e2e: { // 0x474e2e: 83c307 ADD EBX,0x7
    s.bx = integer::add(s.bx,0x00000007u,32,flags);
  }
  L00474e31: { // 0x474e31: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00474e35: { // 0x474e35: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L00474e39: { // 0x474e39: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00474e3d: { // 0x474e3d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474e3e: { // 0x474e3e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474e40: { // 0x474e40: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474e42: { // 0x474e42: 0fbf4504 MOVSX EAX,word ptr [EBP + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000004u)),16));
  }
  L00474e46: { // 0x474e46: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474e47: { // 0x474e47: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474e49: { // 0x474e49: 0fbf5506 MOVSX EDX,word ptr [EBP + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000006u)),16));
  }
  L00474e4d: { // 0x474e4d: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474e4f: { // 0x474e4f: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474e51: { // 0x474e51: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00474e53: { // 0x474e53: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00474e55: { // 0x474e55: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00474e57: { // 0x474e57: 731e JNC 0x00474e77
    if(integer::condition("JNC",flags)) goto L00474e77;
  }
  L00474e59: { // 0x474e59: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00474e5c: { // 0x474e5c: 8d44c508 LEA EAX,[EBP + EAX*0x8 + 0x8]
    s.ax = (s.bp+(s.ax * 0x00000008u)+0x00000008u);
  }
  L00474e60: { // 0x474e60: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474e62: { // 0x474e62: 7413 JZ 0x00474e77
    if(integer::condition("JZ",flags)) goto L00474e77;
  }
  L00474e64: { // 0x474e64: 0fbf28 MOVSX EBP,word ptr [EAX]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00474e67: { // 0x474e67: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00474e6b: { // 0x474e6b: 0fbf7004 MOVSX ESI,word ptr [EAX + 0x4]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L00474e6f: { // 0x474e6f: 0fbf7806 MOVSX EDI,word ptr [EAX + 0x6]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L00474e73: { // 0x474e73: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00474e75: { // 0x474e75: eb17 JMP 0x00474e8e
    goto L00474e8e;
  }
  L00474e77: { // 0x474e77: a1008f8300 MOV EAX,[0x00838f00]
    s.ax = m.r32((0x00838f00u));
  }
  L00474e7c: { // 0x474e7c: 8b15048f8300 MOV EDX,dword ptr [0x00838f04]
    s.dx = m.r32((0x00838f04u));
  }
  L00474e82: { // 0x474e82: 8b35088f8300 MOV ESI,dword ptr [0x00838f08]
    s.si = m.r32((0x00838f08u));
  }
  L00474e88: { // 0x474e88: 8b3d0c8f8300 MOV EDI,dword ptr [0x00838f0c]
    s.di = m.r32((0x00838f0cu));
  }
  L00474e8e: { // 0x474e8e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00474e90: { // 0x474e90: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L00474e92: { // 0x474e92: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00474e96: { // 0x474e96: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474e98: { // 0x474e98: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L00474e9a: { // 0x474e9a: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00474e9d: { // 0x474e9d: 897308 MOV dword ptr [EBX + 0x8],ESI
    m.w32((s.bx+0x00000008u), s.si);
  }
  L00474ea0: { // 0x474ea0: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L00474ea3: { // 0x474ea3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474ea4: { // 0x474ea4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474ea5: { // 0x474ea5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474ea6: { // 0x474ea6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474ea7: { // 0x474ea7: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L00474eaa: { // 0x474eaa: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
