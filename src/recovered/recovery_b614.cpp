#include "recovered/recovery_b614_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b614 {
namespace {
void f_00298010(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00075040(Memory&,State&,Frame&,const Operations&);
void f_001d46d0(Memory&,State&,Frame&,const Operations&);
void f_001d57d0(Memory&,State&,Frame&,const Operations&);
void f_00074ab0(Memory&,State&,Frame&,const Operations&);
void f_00074d00(Memory&,State&,Frame&,const Operations&);
void f_00074eb0(Memory&,State&,Frame&,const Operations&);
void f_00228bf0(Memory&,State&,Frame&,const Operations&);
void f_00147f40(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00298660(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_0005ec50(Memory&,State&,Frame&,const Operations&);
void f_0001b630(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_00074ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00474ab0: { // 0x474ab0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00474ab3: { // 0x474ab3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00474ab4: { // 0x474ab4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00474ab5: { // 0x474ab5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00474ab6: { // 0x474ab6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00474ab8: { // 0x474ab8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00474ab9: { // 0x474ab9: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  L00474abc: { // 0x474abc: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L00474abf: { // 0x474abf: 0f8485010000 JZ 0x00474c4a
    if(integer::condition("JZ",flags)) goto L00474c4a;
  }
  L00474ac5: { // 0x474ac5: 8b151ce1a100 MOV EDX,dword ptr [0x00a1e11c]
    s.dx = m.r32((0x00a1e11cu));
  }
  L00474acb: { // 0x474acb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00474acd: { // 0x474acd: 8a861e010000 MOV AL,byte ptr [ESI + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011eu)));
  }
  L00474ad3: { // 0x474ad3: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00474ad7: { // 0x474ad7: 8b2c8a MOV EBP,dword ptr [EDX + ECX*0x4]
    s.bp = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L00474ada: { // 0x474ada: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00474adc: { // 0x474adc: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474ae0: { // 0x474ae0: 8a9579020000 MOV DL,byte ptr [EBP + 0x279]
    s.dx = with_al(s.dx, m.r8((s.bp+0x00000279u)));
  }
  L00474ae6: { // 0x474ae6: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00474ae8: { // 0x474ae8: 0f8495000000 JZ 0x00474b83
    if(integer::condition("JZ",flags)) goto L00474b83;
  }
  L00474aee: { // 0x474aee: e83dfc1500 CALL 0x005d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4672243u); flags=s.arithmetic_flags;
  }
  L00474af3: { // 0x474af3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00474af6: { // 0x474af6: 0f84bc000000 JZ 0x00474bb8
    if(integer::condition("JZ",flags)) goto L00474bb8;
  }
  L00474afc: { // 0x474afc: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L00474b02: { // 0x474b02: 8b3c81 MOV EDI,dword ptr [ECX + EAX*0x4]
    s.di = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00474b05: { // 0x474b05: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L00474b0b: { // 0x474b0b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00474b0d: { // 0x474b0d: 7443 JZ 0x00474b52
    if(integer::condition("JZ",flags)) goto L00474b52;
  }
  L00474b0f: { // 0x474b0f: 8b87ec000000 MOV EAX,dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  L00474b15: { // 0x474b15: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00474b1b: { // 0x474b1b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b1c: { // 0x474b1c: 83e203 AND EDX,0x3
    s.dx = integer::logical((s.dx)&(0x00000003u),32,flags);
  }
  L00474b1f: { // 0x474b1f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474b21: { // 0x474b21: 0fbf5624 MOVSX EDX,word ptr [ESI + 0x24]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474b25: { // 0x474b25: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474b27: { // 0x474b27: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474b2b: { // 0x474b2b: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00474b2e: { // 0x474b2e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b2f: { // 0x474b2f: c1fb02 SAR EBX,0x2
    s.bx = integer::shift(s.bx,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474b32: { // 0x474b32: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00474b34: { // 0x474b34: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00474b35: { // 0x474b35: 8b87e0000000 MOV EAX,dword ptr [EDI + 0xe0]
    s.ax = m.r32((s.di+0x000000e0u));
  }
  L00474b3b: { // 0x474b3b: 0fafcb IMUL ECX,EBX
    s.cx = integer::imul(s.cx,s.bx,32,flags);
  }
  L00474b3e: { // 0x474b3e: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00474b40: { // 0x474b40: 8b8864020000 MOV ECX,dword ptr [EAX + 0x264]
    s.cx = m.r32((s.ax+0x00000264u));
  }
  L00474b46: { // 0x474b46: 8b87e8000000 MOV EAX,dword ptr [EDI + 0xe8]
    s.ax = m.r32((s.di+0x000000e8u));
  }
  L00474b4c: { // 0x474b4c: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00474b4e: { // 0x474b4e: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00474b50: { // 0x474b50: eb1e JMP 0x00474b70
    goto L00474b70;
  }
  L00474b52: { // 0x474b52: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474b56: { // 0x474b56: 0fbf4e24 MOVSX ECX,word ptr [ESI + 0x24]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474b5a: { // 0x474b5a: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00474b5d: { // 0x474b5d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474b5e: { // 0x474b5e: f7bfe8000000 IDIV dword ptr [EDI + 0xe8]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((s.di+0x000000e8u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00474b64: { // 0x474b64: 8b87e0000000 MOV EAX,dword ptr [EDI + 0xe0]
    s.ax = m.r32((s.di+0x000000e0u));
  }
  L00474b6a: { // 0x474b6a: 039064020000 ADD EDX,dword ptr [EAX + 0x264]
    s.dx = integer::add(s.dx,m.r32((s.ax+0x00000264u)),32,flags);
  }
  L00474b70: { // 0x474b70: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00474b76: { // 0x474b76: 8b0c91 MOV ECX,dword ptr [ECX + EDX*0x4]
    s.cx = m.r32((s.cx+(s.dx * 0x00000004u)));
  }
  L00474b79: { // 0x474b79: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00474b7b: { // 0x474b7b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4672385u); flags=s.arithmetic_flags;
  }
  L00474b81: { // 0x474b81: eb31 JMP 0x00474bb4
    goto L00474bb4;
  }
  L00474b83: { // 0x474b83: 8a8d84020000 MOV CL,byte ptr [EBP + 0x284]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000284u)));
  }
  L00474b89: { // 0x474b89: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00474b8b: { // 0x474b8b: 741c JZ 0x00474ba9
    if(integer::condition("JZ",flags)) goto L00474ba9;
  }
  L00474b8d: { // 0x474b8d: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  L00474b90: { // 0x474b90: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474b94: { // 0x474b94: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00474b96: { // 0x474b96: 7420 JZ 0x00474bb8
    if(integer::condition("JZ",flags)) goto L00474bb8;
  }
  L00474b98: { // 0x474b98: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00474b9c: { // 0x474b9c: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L00474ba0: { // 0x474ba0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474ba1: { // 0x474ba1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474ba2: { // 0x474ba2: e8d93efeff CALL 0x00458a80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00458a80u,4672423u); flags=s.arithmetic_flags;
  }
  L00474ba7: { // 0x474ba7: eb0f JMP 0x00474bb8
    goto L00474bb8;
  }
  L00474ba9: { // 0x474ba9: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00474bac: { // 0x474bac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00474bae: { // 0x474bae: ff909c000000 CALL dword ptr [EAX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000009cu)),4672436u); flags=s.arithmetic_flags;
  }
  L00474bb4: { // 0x474bb4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00474bb8: { // 0x474bb8: 0fbf4624 MOVSX EAX,word ptr [ESI + 0x24]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474bbc: { // 0x474bbc: 0fbf4e26 MOVSX ECX,word ptr [ESI + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474bc0: { // 0x474bc0: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bc3: { // 0x474bc3: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00474bc8: { // 0x474bc8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474bc9: { // 0x474bc9: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474bcf: { // 0x474bcf: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bd2: { // 0x474bd2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474bd4: { // 0x474bd4: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00474bda: { // 0x474bda: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474bdc: { // 0x474bdc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00474bde: { // 0x474bde: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474bdf: { // 0x474bdf: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474be5: { // 0x474be5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474be7: { // 0x474be7: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474be9: { // 0x474be9: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00474bed: { // 0x474bed: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474bf0: { // 0x474bf0: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474bf3: { // 0x474bf3: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00474bf7: { // 0x474bf7: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00474bfb: { // 0x474bfb: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474bfe: { // 0x474bfe: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474c01: { // 0x474c01: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00474c02: { // 0x474c02: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00474c08: { // 0x474c08: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00474c09: { // 0x474c09: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L00474c0d: { // 0x474c0d: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00474c11: { // 0x474c11: e8fa332200 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,4672534u); flags=s.arithmetic_flags;
  }
  L00474c16: { // 0x474c16: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L00474c1a: { // 0x474c1a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00474c1c: { // 0x474c1c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474c1d: { // 0x474c1d: e81e040000 CALL 0x00475040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475040u,4672546u); flags=s.arithmetic_flags;
  }
  L00474c22: { // 0x474c22: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00474c26: { // 0x474c26: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00474c28: { // 0x474c28: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00474c2c: { // 0x474c2c: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00474c2e: { // 0x474c2e: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00474c32: { // 0x474c32: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00474c35: { // 0x474c35: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L00474c37: { // 0x474c37: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00474c3b: { // 0x474c3b: 83e91e SUB ECX,0x1e
    s.cx = integer::sub(s.cx,0x0000001eu,32,flags);
  }
  L00474c3e: { // 0x474c3e: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L00474c42: { // 0x474c42: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00474c44: { // 0x474c44: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00474c48: { // 0x474c48: 7523 JNZ 0x00474c6d
    if(integer::condition("JNZ",flags)) goto L00474c6d;
  }
  L00474c4a: { // 0x474c4a: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00474c4e: { // 0x474c4e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474c50: { // 0x474c50: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474c52: { // 0x474c52: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474c54: { // 0x474c54: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00474c56: { // 0x474c56: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00474c58: { // 0x474c58: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L00474c5a: { // 0x474c5a: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00474c5d: { // 0x474c5d: 897308 MOV dword ptr [EBX + 0x8],ESI
    m.w32((s.bx+0x00000008u), s.si);
  }
  L00474c60: { // 0x474c60: 897b0c MOV dword ptr [EBX + 0xc],EDI
    m.w32((s.bx+0x0000000cu), s.di);
  }
  L00474c63: { // 0x474c63: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474c64: { // 0x474c64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474c65: { // 0x474c65: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474c66: { // 0x474c66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474c67: { // 0x474c67: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00474c6a: { // 0x474c6a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00474c6d: { // 0x474c6d: 8a857a020000 MOV AL,byte ptr [EBP + 0x27a]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000027au)));
  }
  L00474c73: { // 0x474c73: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00474c75: { // 0x474c75: 7408 JZ 0x00474c7f
    if(integer::condition("JZ",flags)) goto L00474c7f;
  }
  L00474c77: { // 0x474c77: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00474c79: { // 0x474c79: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00474c7d: { // 0x474c7d: eb04 JMP 0x00474c83
    goto L00474c83;
  }
  L00474c7f: { // 0x474c7f: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00474c83: { // 0x474c83: 0fbf4702 MOVSX EAX,word ptr [EDI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00474c87: { // 0x474c87: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474c88: { // 0x474c88: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474c8a: { // 0x474c8a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00474c8c: { // 0x474c8c: 0fbf4704 MOVSX EAX,word ptr [EDI + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000004u)),16));
  }
  L00474c90: { // 0x474c90: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474c91: { // 0x474c91: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474c93: { // 0x474c93: 0fbf5706 MOVSX EDX,word ptr [EDI + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000006u)),16));
  }
  L00474c97: { // 0x474c97: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474c99: { // 0x474c99: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474c9b: { // 0x474c9b: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00474c9d: { // 0x474c9d: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L00474c9f: { // 0x474c9f: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00474ca1: { // 0x474ca1: 731f JNC 0x00474cc2
    if(integer::condition("JNC",flags)) goto L00474cc2;
  }
  L00474ca3: { // 0x474ca3: 8d446d00 LEA EAX,[EBP + EBP*0x2]
    s.ax = (s.bp+(s.bp * 0x00000002u));
  }
  L00474ca7: { // 0x474ca7: 8d44c708 LEA EAX,[EDI + EAX*0x8 + 0x8]
    s.ax = (s.di+(s.ax * 0x00000008u)+0x00000008u);
  }
  L00474cab: { // 0x474cab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474cad: { // 0x474cad: 7413 JZ 0x00474cc2
    if(integer::condition("JZ",flags)) goto L00474cc2;
  }
  L00474caf: { // 0x474caf: 0fbf28 MOVSX EBP,word ptr [EAX]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00474cb2: { // 0x474cb2: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00474cb6: { // 0x474cb6: 0fbf7804 MOVSX EDI,word ptr [EAX + 0x4]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L00474cba: { // 0x474cba: 0fbf5806 MOVSX EBX,word ptr [EAX + 0x6]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L00474cbe: { // 0x474cbe: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00474cc0: { // 0x474cc0: eb17 JMP 0x00474cd9
    goto L00474cd9;
  }
  L00474cc2: { // 0x474cc2: a1008f8300 MOV EAX,[0x00838f00]
    s.ax = m.r32((0x00838f00u));
  }
  L00474cc7: { // 0x474cc7: 8b15048f8300 MOV EDX,dword ptr [0x00838f04]
    s.dx = m.r32((0x00838f04u));
  }
  L00474ccd: { // 0x474ccd: 8b3d088f8300 MOV EDI,dword ptr [0x00838f08]
    s.di = m.r32((0x00838f08u));
  }
  L00474cd3: { // 0x474cd3: 8b1d0c8f8300 MOV EBX,dword ptr [0x00838f0c]
    s.bx = m.r32((0x00838f0cu));
  }
  L00474cd9: { // 0x474cd9: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00474cdb: { // 0x474cdb: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00474cdf: { // 0x474cdf: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00474ce1: { // 0x474ce1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00474ce3: { // 0x474ce3: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L00474ce5: { // 0x474ce5: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L00474ce8: { // 0x474ce8: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00474ceb: { // 0x474ceb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474cec: { // 0x474cec: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  L00474cef: { // 0x474cef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474cf0: { // 0x474cf0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474cf1: { // 0x474cf1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474cf2: { // 0x474cf2: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00474cf5: { // 0x474cf5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00074d00(Memory& m,State& s,Frame& f,const Operations& op) {
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
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00074eb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00474eb0: { // 0x474eb0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00474eb3: { // 0x474eb3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00474eb4: { // 0x474eb4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00474eb5: { // 0x474eb5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00474eb6: { // 0x474eb6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00474eb8: { // 0x474eb8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00474eb9: { // 0x474eb9: 0fbf4624 MOVSX EAX,word ptr [ESI + 0x24]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00474ebd: { // 0x474ebd: 0fbf4e26 MOVSX ECX,word ptr [ESI + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00474ec1: { // 0x474ec1: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474ec4: { // 0x474ec4: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00474ec9: { // 0x474ec9: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474eca: { // 0x474eca: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474ed0: { // 0x474ed0: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474ed3: { // 0x474ed3: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474ed5: { // 0x474ed5: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00474edb: { // 0x474edb: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474edd: { // 0x474edd: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00474edf: { // 0x474edf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00474ee0: { // 0x474ee0: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00474ee6: { // 0x474ee6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00474ee8: { // 0x474ee8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00474eea: { // 0x474eea: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00474eee: { // 0x474eee: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474ef1: { // 0x474ef1: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474ef4: { // 0x474ef4: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00474ef8: { // 0x474ef8: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00474efc: { // 0x474efc: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00474eff: { // 0x474eff: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00474f03: { // 0x474f03: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00474f04: { // 0x474f04: c1e708 SHL EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::left);
  }
  L00474f07: { // 0x474f07: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00474f08: { // 0x474f08: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00474f0e: { // 0x474f0e: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L00474f12: { // 0x474f12: e8f9302200 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,4673303u); flags=s.arithmetic_flags;
  }
  L00474f17: { // 0x474f17: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L00474f1e: { // 0x474f1e: 8b3d74198200 MOV EDI,dword ptr [0x00821974]
    s.di = m.r32((0x00821974u));
  }
  L00474f24: { // 0x474f24: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00474f28: { // 0x474f28: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00474f2b: { // 0x474f2b: 83e91e SUB ECX,0x1e
    s.cx = integer::sub(s.cx,0x0000001eu,32,flags);
  }
  L00474f2e: { // 0x474f2e: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00474f32: { // 0x474f32: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00474f34: { // 0x474f34: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L00474f37: { // 0x474f37: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00474f3b: { // 0x474f3b: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L00474f3d: { // 0x474f3d: b93c000000 MOV ECX,0x3c
    s.cx = 0x0000003cu;
  }
  L00474f42: { // 0x474f42: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00474f44: { // 0x474f44: bb1e000000 MOV EBX,0x1e
    s.bx = 0x0000001eu;
  }
  L00474f49: { // 0x474f49: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00474f4d: { // 0x474f4d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00474f4f: { // 0x474f4f: 8b4638 MOV EAX,dword ptr [ESI + 0x38]
    s.ax = m.r32((s.si+0x00000038u));
  }
  L00474f52: { // 0x474f52: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L00474f57: { // 0x474f57: 751b JNZ 0x00474f74
    if(integer::condition("JNZ",flags)) goto L00474f74;
  }
  L00474f59: { // 0x474f59: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00474f5d: { // 0x474f5d: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00474f5f: { // 0x474f5f: 892a MOV dword ptr [EDX],EBP
    m.w32((s.dx), s.bp);
  }
  L00474f61: { // 0x474f61: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L00474f64: { // 0x474f64: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474f65: { // 0x474f65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474f66: { // 0x474f66: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474f67: { // 0x474f67: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00474f6a: { // 0x474f6a: 895a0c MOV dword ptr [EDX + 0xc],EBX
    m.w32((s.dx+0x0000000cu), s.bx);
  }
  L00474f6d: { // 0x474f6d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474f6e: { // 0x474f6e: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00474f71: { // 0x474f71: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00474f74: { // 0x474f74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474f76: { // 0x474f76: 0f8c85000000 JL 0x00475001
    if(integer::condition("JL",flags)) goto L00475001;
  }
  L00474f7c: { // 0x474f7c: 3b052089a200 CMP EAX,dword ptr [0x00a28920]
    (void)integer::sub(s.ax,m.r32((0x00a28920u)),32,flags);
  }
  L00474f82: { // 0x474f82: 7d7d JGE 0x00475001
    if(integer::condition("JGE",flags)) goto L00475001;
  }
  L00474f84: { // 0x474f84: 8b0d1489a200 MOV ECX,dword ptr [0x00a28914]
    s.cx = m.r32((0x00a28914u));
  }
  L00474f8a: { // 0x474f8a: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00474f8c: { // 0x474f8c: 8a961a010000 MOV DL,byte ptr [ESI + 0x11a]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000011au)));
  }
  L00474f92: { // 0x474f92: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00474f95: { // 0x474f95: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00474f97: { // 0x474f97: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00474f99: { // 0x474f99: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00474f9b: { // 0x474f9b: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),4673441u); flags=s.arithmetic_flags;
  }
  L00474fa1: { // 0x474fa1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00474fa3: { // 0x474fa3: 752b JNZ 0x00474fd0
    if(integer::condition("JNZ",flags)) goto L00474fd0;
  }
  L00474fa5: { // 0x474fa5: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00474fa9: { // 0x474fa9: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00474fad: { // 0x474fad: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00474faf: { // 0x474faf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00474fb0: { // 0x474fb0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00474fb1: { // 0x474fb1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00474fb2: { // 0x474fb2: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00474fb4: { // 0x474fb4: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00474fb8: { // 0x474fb8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00474fb9: { // 0x474fb9: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L00474fbc: { // 0x474fbc: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00474fc0: { // 0x474fc0: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L00474fc3: { // 0x474fc3: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00474fc7: { // 0x474fc7: 89510c MOV dword ptr [ECX + 0xc],EDX
    m.w32((s.cx+0x0000000cu), s.dx);
  }
  L00474fca: { // 0x474fca: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00474fcd: { // 0x474fcd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00474fd0: { // 0x474fd0: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00474fd3: { // 0x474fd3: 0faf08 IMUL ECX,dword ptr [EAX]
    s.cx = integer::imul(s.cx,m.r32((s.ax)),32,flags);
  }
  L00474fd6: { // 0x474fd6: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00474fd7: { // 0x474fd7: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00474fd9: { // 0x474fd9: 7c02 JL 0x00474fdd
    if(integer::condition("JL",flags)) goto L00474fdd;
  }
  L00474fdb: { // 0x474fdb: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00474fdd: { // 0x474fdd: 8b4cb010 MOV ECX,dword ptr [EAX + ESI*0x4 + 0x10]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)+0x00000010u));
  }
  L00474fe1: { // 0x474fe1: f6412401 TEST byte ptr [ECX + 0x24],0x1
    (void)integer::logical((m.r8((s.cx+0x00000024u)))&(0x00000001u),8,flags);
  }
  L00474fe5: { // 0x474fe5: 7431 JZ 0x00475018
    if(integer::condition("JZ",flags)) goto L00475018;
  }
  L00474fe7: { // 0x474fe7: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00474fea: { // 0x474fea: 8b5118 MOV EDX,dword ptr [ECX + 0x18]
    s.dx = m.r32((s.cx+0x00000018u));
  }
  L00474fed: { // 0x474fed: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00474fef: { // 0x474fef: ba00000000 MOV EDX,0x0
    s.dx = 0x00000000u;
  }
  L00474ff4: { // 0x474ff4: 0f98c2 SETS DL
    s.dx = with_al(s.dx, (integer::condition("SETS",flags)?1u:0u));
  }
  L00474ff7: { // 0x474ff7: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00474ff8: { // 0x474ff8: 23c2 AND EAX,EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  L00474ffa: { // 0x474ffa: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00474ffc: { // 0x474ffc: 8d581e LEA EBX,[EAX + 0x1e]
    s.bx = (s.ax+0x0000001eu);
  }
  L00474fff: { // 0x474fff: eb17 JMP 0x00475018
    goto L00475018;
  }
  L00475001: { // 0x475001: 0fbf4626 MOVSX EAX,word ptr [ESI + 0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000026u)),16));
  }
  L00475005: { // 0x475005: 0fbf4e24 MOVSX ECX,word ptr [ESI + 0x24]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000024u)),16));
  }
  L00475009: { // 0x475009: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047500a: { // 0x47500a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0047500b: { // 0x47500b: 681cdc7b00 PUSH 0x7bdc1c
    f.push(m,0x007bdc1cu);
  }
  L00475010: { // 0x475010: e8db18f9ff CALL 0x004068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,4673557u); flags=s.arithmetic_flags;
  }
  L00475015: { // 0x475015: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00475018: { // 0x475018: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0047501c: { // 0x47501c: b93c000000 MOV ECX,0x3c
    s.cx = 0x0000003cu;
  }
  L00475021: { // 0x475021: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00475023: { // 0x475023: 892a MOV dword ptr [EDX],EBP
    m.w32((s.dx), s.bp);
  }
  L00475025: { // 0x475025: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L00475028: { // 0x475028: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00475029: { // 0x475029: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047502a: { // 0x47502a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047502b: { // 0x47502b: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0047502e: { // 0x47502e: 895a0c MOV dword ptr [EDX + 0xc],EBX
    m.w32((s.dx+0x0000000cu), s.bx);
  }
  L00475031: { // 0x475031: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00475032: { // 0x475032: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00475035: { // 0x475035: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00228bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00628bf0: { // 0x628bf0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00628bf1: { // 0x628bf1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00628bf2: { // 0x628bf2: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L00628bf6: { // 0x628bf6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00628bf7: { // 0x628bf7: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00628bf9: { // 0x628bf9: 8b8730120000 MOV EAX,dword ptr [EDI + 0x1230]
    s.ax = m.r32((s.di+0x00001230u));
  }
  L00628bff: { // 0x628bff: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00628c00: { // 0x628c00: 7823 JS 0x00628c25
    if(integer::condition("JS",flags)) goto L00628c25;
  }
  L00628c02: { // 0x628c02: 8b8f24120000 MOV ECX,dword ptr [EDI + 0x1224]
    s.cx = m.r32((s.di+0x00001224u));
  }
  L00628c08: { // 0x628c08: 668b13 MOV DX,word ptr [EBX]
    s.dx = with_ax(s.dx, m.r16((s.bx)));
  }
  L00628c0b: { // 0x628c0b: 8d0c81 LEA ECX,[ECX + EAX*0x4]
    s.cx = (s.cx+(s.ax * 0x00000004u));
  }
  L00628c0e: { // 0x628c0e: 663911 CMP word ptr [ECX],DX
    (void)integer::sub(m.r16((s.cx)),(s.dx & 0xffffu),16,flags);
  }
  L00628c11: { // 0x628c11: 750a JNZ 0x00628c1d
    if(integer::condition("JNZ",flags)) goto L00628c1d;
  }
  L00628c13: { // 0x628c13: 668b7102 MOV SI,word ptr [ECX + 0x2]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.cx+0x00000002u))) & 0xffffu);
  }
  L00628c17: { // 0x628c17: 663b7302 CMP SI,word ptr [EBX + 0x2]
    (void)integer::sub((s.si & 0xffffu),m.r16((s.bx+0x00000002u)),16,flags);
  }
  L00628c1b: { // 0x628c1b: 7458 JZ 0x00628c75
    if(integer::condition("JZ",flags)) goto L00628c75;
  }
  L00628c1d: { // 0x628c1d: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00628c1e: { // 0x628c1e: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L00628c21: { // 0x628c21: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00628c23: { // 0x628c23: 7de9 JGE 0x00628c0e
    if(integer::condition("JGE",flags)) goto L00628c0e;
  }
  L00628c25: { // 0x628c25: 8b8f28120000 MOV ECX,dword ptr [EDI + 0x1228]
    s.cx = m.r32((s.di+0x00001228u));
  }
  L00628c2b: { // 0x628c2b: 8b8730120000 MOV EAX,dword ptr [EDI + 0x1230]
    s.ax = m.r32((s.di+0x00001230u));
  }
  L00628c31: { // 0x628c31: 8db720120000 LEA ESI,[EDI + 0x1220]
    s.si = (s.di+0x00001220u);
  }
  L00628c37: { // 0x628c37: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00628c39: { // 0x628c39: 7c22 JL 0x00628c5d
    if(integer::condition("JL",flags)) goto L00628c5d;
  }
  L00628c3b: { // 0x628c3b: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L00628c3e: { // 0x628c3e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00628c40: { // 0x628c40: 7504 JNZ 0x00628c46
    if(integer::condition("JNZ",flags)) goto L00628c46;
  }
  L00628c42: { // 0x628c42: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00628c44: { // 0x628c44: 7528 JNZ 0x00628c6e
    if(integer::condition("JNZ",flags)) goto L00628c6e;
  }
  L00628c46: { // 0x628c46: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00628c49: { // 0x628c49: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00628c4b: { // 0x628c4b: 7e21 JLE 0x00628c6e
    if(integer::condition("JLE",flags)) goto L00628c6e;
  }
  L00628c4d: { // 0x628c4d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00628c4f: { // 0x628c4f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00628c51: { // 0x628c51: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00628c53: { // 0x628c53: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00628c54: { // 0x628c54: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00628c56: { // 0x628c56: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6458457u); flags=s.arithmetic_flags;
  }
  L00628c59: { // 0x628c59: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00628c5b: { // 0x628c5b: 7411 JZ 0x00628c6e
    if(integer::condition("JZ",flags)) goto L00628c6e;
  }
  L00628c5d: { // 0x628c5d: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00628c60: { // 0x628c60: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00628c63: { // 0x628c63: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L00628c66: { // 0x628c66: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  L00628c69: { // 0x628c69: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L00628c6b: { // 0x628c6b: 890c82 MOV dword ptr [EDX + EAX*0x4],ECX
    m.w32((s.dx+(s.ax * 0x00000004u)), s.cx);
  }
  L00628c6e: { // 0x628c6e: c687d514000001 MOV byte ptr [EDI + 0x14d5],0x1
    m.w8((s.di+0x000014d5u), 0x00000001u);
  }
  L00628c75: { // 0x628c75: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00628c76: { // 0x628c76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00628c77: { // 0x628c77: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00628c78: { // 0x628c78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00147f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547f40: { // 0x547f40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00547f44: { // 0x547f44: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L00547f4a: { // 0x547f4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547f4b: { // 0x547f4b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547f4c: { // 0x547f4c: 0fbf30 MOVSX ESI,word ptr [EAX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00547f4f: { // 0x547f4f: 0fbf4002 MOVSX EAX,word ptr [EAX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00547f53: { // 0x547f53: 8d3c30 LEA EDI,[EAX + ESI*0x1]
    s.di = (s.ax+(s.si * 0x00000001u));
  }
  L00547f56: { // 0x547f56: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00547f58: { // 0x547f58: 7e24 JLE 0x00547f7e
    if(integer::condition("JLE",flags)) goto L00547f7e;
  }
  L00547f5a: { // 0x547f5a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547f5b: { // 0x547f5b: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00547f5d: { // 0x547f5d: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00547f5f: { // 0x547f5f: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547f61: { // 0x547f61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547f62: { // 0x547f62: 7d1a JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f64: { // 0x547f64: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00547f66: { // 0x547f66: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00547f68: { // 0x547f68: 7d14 JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f6a: { // 0x547f6a: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L00547f70: { // 0x547f70: 8d0c42 LEA ECX,[EDX + EAX*0x2]
    s.cx = (s.dx+(s.ax * 0x00000002u));
  }
  L00547f73: { // 0x547f73: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00547f75: { // 0x547f75: 7f07 JG 0x00547f7e
    if(integer::condition("JG",flags)) goto L00547f7e;
  }
  L00547f77: { // 0x547f77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f78: { // 0x547f78: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00547f7a: { // 0x547f7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f7b: { // 0x547f7b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00547f7e: { // 0x547f7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f7f: { // 0x547f7f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00547f81: { // 0x547f81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f82: { // 0x547f82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00298660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698660: { // 0x698660: 83ec58 SUB ESP,0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L00698663: { // 0x698663: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L00698669: { // 0x698669: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069866a: { // 0x69866a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0069866c: { // 0x69866c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069866d: { // 0x69866d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069866e: { // 0x69866e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00698670: { // 0x698670: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698671: { // 0x698671: c7442418ffffffff MOV dword ptr [ESP + 0x18],0xffffffff
    m.w32((f.sp+0x00000018u), 0xffffffffu);
  }
  L00698679: { // 0x698679: c744241cffffff7f MOV dword ptr [ESP + 0x1c],0x7fffffff
    m.w32((f.sp+0x0000001cu), 0x7fffffffu);
  }
  L00698681: { // 0x698681: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00698685: { // 0x698685: 0f8e6d020000 JLE 0x006988f8
    if(integer::condition("JLE",flags)) goto L006988f8;
  }
  L0069868b: { // 0x69868b: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0069868f: { // 0x69868f: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L00698694: { // 0x698694: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00698698: { // 0x698698: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0069869a: { // 0x69869a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069869c: { // 0x69869c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0069869e: { // 0x69869e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006986a0: { // 0x6986a0: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L006986a4: { // 0x6986a4: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006986a7: { // 0x6986a7: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L006986ab: { // 0x6986ab: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006986ae: { // 0x6986ae: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L006986b2: { // 0x6986b2: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L006986b6: { // 0x6986b6: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L006986b9: { // 0x6986b9: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L006986bd: { // 0x6986bd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006986be: { // 0x6986be: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L006986c2: { // 0x6986c2: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L006986c6: { // 0x6986c6: e82577d8ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6915787u); flags=s.arithmetic_flags;
  }
  L006986cb: { // 0x6986cb: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006986cd: { // 0x6986cd: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L006986d1: { // 0x6986d1: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L006986d5: { // 0x6986d5: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L006986d9: { // 0x6986d9: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L006986dc: { // 0x6986dc: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006986e0: { // 0x6986e0: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L006986e4: { // 0x6986e4: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006986e7: { // 0x6986e7: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L006986eb: { // 0x6986eb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L006986ef: { // 0x6986ef: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L006986f2: { // 0x6986f2: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006986f4: { // 0x6986f4: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L006986f8: { // 0x6986f8: 0f8e92000000 JLE 0x00698790
    if(integer::condition("JLE",flags)) goto L00698790;
  }
  L006986fe: { // 0x6986fe: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00698700: { // 0x698700: 0f8e8a000000 JLE 0x00698790
    if(integer::condition("JLE",flags)) goto L00698790;
  }
  L00698706: { // 0x698706: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L0069870a: { // 0x69870a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0069870c: { // 0x69870c: 7e74 JLE 0x00698782
    if(integer::condition("JLE",flags)) goto L00698782;
  }
  L0069870e: { // 0x69870e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00698712: { // 0x698712: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698714: { // 0x698714: 7e6c JLE 0x00698782
    if(integer::condition("JLE",flags)) goto L00698782;
  }
  L00698716: { // 0x698716: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L00698718: { // 0x698718: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    s.bp = m.r32((f.sp+0x0000006cu));
  }
  L0069871c: { // 0x69871c: 3bd5 CMP EDX,EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L0069871e: { // 0x69871e: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698720: { // 0x698720: 7e06 JLE 0x00698728
    if(integer::condition("JLE",flags)) goto L00698728;
  }
  L00698722: { // 0x698722: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00698724: { // 0x698724: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698726: { // 0x698726: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00698728: { // 0x698728: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L0069872c: { // 0x69872c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069872e: { // 0x69872e: 7e06 JLE 0x00698736
    if(integer::condition("JLE",flags)) goto L00698736;
  }
  L00698730: { // 0x698730: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L00698732: { // 0x698732: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L00698734: { // 0x698734: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00698736: { // 0x698736: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0069873a: { // 0x69873a: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069873c: { // 0x69873c: 8d2c10 LEA EBP,[EAX + EDX*0x1]
    s.bp = (s.ax+(s.dx * 0x00000001u));
  }
  L0069873f: { // 0x69873f: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00698741: { // 0x698741: 7d0e JGE 0x00698751
    if(integer::condition("JGE",flags)) goto L00698751;
  }
  L00698743: { // 0x698743: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00698747: { // 0x698747: 8b5c246c MOV EBX,dword ptr [ESP + 0x6c]
    s.bx = m.r32((f.sp+0x0000006cu));
  }
  L0069874b: { // 0x69874b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0069874d: { // 0x69874d: 8d441801 LEA EAX,[EAX + EBX*0x1 + 0x1]
    s.ax = (s.ax+(s.bx * 0x00000001u)+0x00000001u);
  }
  L00698751: { // 0x698751: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L00698755: { // 0x698755: 8b6c2478 MOV EBP,dword ptr [ESP + 0x78]
    s.bp = m.r32((f.sp+0x00000078u));
  }
  L00698759: { // 0x698759: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069875b: { // 0x69875b: 8d2c0e LEA EBP,[ESI + ECX*0x1]
    s.bp = (s.si+(s.cx * 0x00000001u));
  }
  L0069875e: { // 0x69875e: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00698760: { // 0x698760: 7d0e JGE 0x00698770
    if(integer::condition("JGE",flags)) goto L00698770;
  }
  L00698762: { // 0x698762: 8b742470 MOV ESI,dword ptr [ESP + 0x70]
    s.si = m.r32((f.sp+0x00000070u));
  }
  L00698766: { // 0x698766: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L0069876a: { // 0x69876a: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0069876c: { // 0x69876c: 8d741e01 LEA ESI,[ESI + EBX*0x1 + 0x1]
    s.si = (s.si+(s.bx * 0x00000001u)+0x00000001u);
  }
  L00698770: { // 0x698770: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L00698774: { // 0x698774: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00698778: { // 0x698778: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0069877c: { // 0x69877c: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00698780: { // 0x698780: eb26 JMP 0x006987a8
    goto L006987a8;
  }
  L00698782: { // 0x698782: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00698786: { // 0x698786: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0069878a: { // 0x69878a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0069878c: { // 0x69878c: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0069878e: { // 0x69878e: eb18 JMP 0x006987a8
    goto L006987a8;
  }
  L00698790: { // 0x698790: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00698794: { // 0x698794: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00698798: { // 0x698798: 8b742478 MOV ESI,dword ptr [ESP + 0x78]
    s.si = m.r32((f.sp+0x00000078u));
  }
  L0069879c: { // 0x69879c: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L006987a0: { // 0x6987a0: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L006987a4: { // 0x6987a4: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006987a8: { // 0x6987a8: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006987ac: { // 0x6987ac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006987ae: { // 0x6987ae: 0f8e15010000 JLE 0x006988c9
    if(integer::condition("JLE",flags)) goto L006988c9;
  }
  L006987b4: { // 0x6987b4: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006987b8: { // 0x6987b8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006987ba: { // 0x6987ba: 0f8e09010000 JLE 0x006988c9
    if(integer::condition("JLE",flags)) goto L006988c9;
  }
  L006987c0: { // 0x6987c0: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L006987c4: { // 0x6987c4: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L006987c8: { // 0x6987c8: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L006987ca: { // 0x6987ca: 754b JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987cc: { // 0x6987cc: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L006987d0: { // 0x6987d0: 8b5c2470 MOV EBX,dword ptr [ESP + 0x70]
    s.bx = m.r32((f.sp+0x00000070u));
  }
  L006987d4: { // 0x6987d4: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987d6: { // 0x6987d6: 753f JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987d8: { // 0x6987d8: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006987dc: { // 0x6987dc: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L006987e0: { // 0x6987e0: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987e2: { // 0x6987e2: 7533 JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987e4: { // 0x6987e4: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L006987e8: { // 0x6987e8: 8b5c2478 MOV EBX,dword ptr [ESP + 0x78]
    s.bx = m.r32((f.sp+0x00000078u));
  }
  L006987ec: { // 0x6987ec: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006987ee: { // 0x6987ee: 7527 JNZ 0x00698817
    if(integer::condition("JNZ",flags)) goto L00698817;
  }
  L006987f0: { // 0x6987f0: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L006987f4: { // 0x6987f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006987f6: { // 0x6987f6: 0f840c020000 JZ 0x00698a08
    if(integer::condition("JZ",flags)) goto L00698a08;
  }
  L006987fc: { // 0x6987fc: 8b15bc60aa00 MOV EDX,dword ptr [0x00aa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00698802: { // 0x698802: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698806: { // 0x698806: 8a4c1010 MOV CL,byte ptr [EAX + EDX*0x1 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000001u)+0x00000010u)));
  }
  L0069880a: { // 0x69880a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069880c: { // 0x69880c: 0f85f6010000 JNZ 0x00698a08
    if(integer::condition("JNZ",flags)) goto L00698a08;
  }
  L00698812: { // 0x698812: e9b2000000 JMP 0x006988c9
    goto L006988c9;
  }
  L00698817: { // 0x698817: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  L0069881b: { // 0x69881b: 0f8581000000 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698821: { // 0x698821: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00698825: { // 0x698825: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00698829: { // 0x698829: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0069882b: { // 0x69882b: 7575 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L0069882d: { // 0x69882d: 397c2428 CMP dword ptr [ESP + 0x28],EDI
    (void)integer::sub(m.r32((f.sp+0x00000028u)),s.di,32,flags);
  }
  L00698831: { // 0x698831: 756f JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698833: { // 0x698833: 396c242c CMP dword ptr [ESP + 0x2c],EBP
    (void)integer::sub(m.r32((f.sp+0x0000002cu)),s.bp,32,flags);
  }
  L00698837: { // 0x698837: 7569 JNZ 0x006988a2
    if(integer::condition("JNZ",flags)) goto L006988a2;
  }
  L00698839: { // 0x698839: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L0069883d: { // 0x69883d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069883f: { // 0x69883f: 7512 JNZ 0x00698853
    if(integer::condition("JNZ",flags)) goto L00698853;
  }
  L00698841: { // 0x698841: 8b15bc60aa00 MOV EDX,dword ptr [0x00aa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00698847: { // 0x698847: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0069884b: { // 0x69884b: 8a4c1010 MOV CL,byte ptr [EAX + EDX*0x1 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000001u)+0x00000010u)));
  }
  L0069884f: { // 0x69884f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00698851: { // 0x698851: 7576 JNZ 0x006988c9
    if(integer::condition("JNZ",flags)) goto L006988c9;
  }
  L00698853: { // 0x698853: a1c860aa00 MOV EAX,[0x00aa60c8]
    s.ax = m.r32((0x00aa60c8u));
  }
  L00698858: { // 0x698858: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069885c: { // 0x69885c: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0069885e: { // 0x69885e: 7d30 JGE 0x00698890
    if(integer::condition("JGE",flags)) goto L00698890;
  }
  L00698860: { // 0x698860: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00698861: { // 0x698861: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00698863: { // 0x698863: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00698865: { // 0x698865: a3c860aa00 MOV [0x00aa60c8],EAX
    m.w32((0x00aa60c8u), s.ax);
  }
  L0069886a: { // 0x69886a: 7d24 JGE 0x00698890
    if(integer::condition("JGE",flags)) goto L00698890;
  }
  L0069886c: { // 0x69886c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698870: { // 0x698870: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L00698876: { // 0x698876: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00698877: { // 0x698877: 8d740814 LEA ESI,[EAX + ECX*0x1 + 0x14]
    s.si = (s.ax+(s.cx * 0x00000001u)+0x00000014u);
  }
  L0069887b: { // 0x69887b: 8d3c08 LEA EDI,[EAX + ECX*0x1]
    s.di = (s.ax+(s.cx * 0x00000001u));
  }
  L0069887e: { // 0x69887e: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L00698883: { // 0x698883: 83c014 ADD EAX,0x14
    s.ax = integer::add(s.ax,0x00000014u,32,flags);
  }
  L00698886: { // 0x698886: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00698888: { // 0x698888: 3b15c860aa00 CMP EDX,dword ptr [0x00aa60c8]
    (void)integer::sub(s.dx,m.r32((0x00aa60c8u)),32,flags);
  }
  L0069888e: { // 0x69888e: 7ce0 JL 0x00698870
    if(integer::condition("JL",flags)) goto L00698870;
  }
  L00698890: { // 0x698890: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00698894: { // 0x698894: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00698895: { // 0x698895: 83e814 SUB EAX,0x14
    s.ax = integer::sub(s.ax,0x00000014u,32,flags);
  }
  L00698898: { // 0x698898: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0069889c: { // 0x69889c: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006988a0: { // 0x6988a0: eb27 JMP 0x006988c9
    goto L006988c9;
  }
  L006988a2: { // 0x6988a2: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L006988a6: { // 0x6988a6: 0fafef IMUL EBP,EDI
    s.bp = integer::imul(s.bp,s.di,32,flags);
  }
  L006988a9: { // 0x6988a9: 0faf4c2474 IMUL ECX,dword ptr [ESP + 0x74]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x00000074u)),32,flags);
  }
  L006988ae: { // 0x6988ae: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L006988b1: { // 0x6988b1: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L006988b3: { // 0x6988b3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006988b5: { // 0x6988b5: 7d12 JGE 0x006988c9
    if(integer::condition("JGE",flags)) goto L006988c9;
  }
  L006988b7: { // 0x6988b7: 3b44241c CMP EAX,dword ptr [ESP + 0x1c]
    (void)integer::sub(s.ax,m.r32((f.sp+0x0000001cu)),32,flags);
  }
  L006988bb: { // 0x6988bb: 7d0c JGE 0x006988c9
    if(integer::condition("JGE",flags)) goto L006988c9;
  }
  L006988bd: { // 0x6988bd: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L006988c1: { // 0x6988c1: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006988c5: { // 0x6988c5: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006988c9: { // 0x6988c9: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006988cd: { // 0x6988cd: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L006988d1: { // 0x6988d1: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L006988d7: { // 0x6988d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006988d8: { // 0x6988d8: 83c614 ADD ESI,0x14
    s.si = integer::add(s.si,0x00000014u,32,flags);
  }
  L006988db: { // 0x6988db: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006988dd: { // 0x6988dd: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006988e1: { // 0x6988e1: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006988e5: { // 0x6988e5: 0f8ca4fdffff JL 0x0069868f
    if(integer::condition("JL",flags)) goto L0069868f;
  }
  L006988eb: { // 0x6988eb: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006988ef: { // 0x6988ef: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006988f2: { // 0x6988f2: 0f859c000000 JNZ 0x00698994
    if(integer::condition("JNZ",flags)) goto L00698994;
  }
  L006988f8: { // 0x6988f8: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    s.ax = m.r32((f.sp+0x0000006cu));
  }
  L006988fc: { // 0x6988fc: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00698900: { // 0x698900: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00698904: { // 0x698904: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00698908: { // 0x698908: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0069890c: { // 0x69890c: 8a44247c MOV AL,byte ptr [ESP + 0x7c]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000007cu)));
  }
  L00698910: { // 0x698910: 88442464 MOV byte ptr [ESP + 0x64],AL
    m.w8((f.sp+0x00000064u), (s.ax & 0xffu));
  }
  L00698914: { // 0x698914: a1c060aa00 MOV EAX,[0x00aa60c0]
    s.ax = m.r32((0x00aa60c0u));
  }
  L00698919: { // 0x698919: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0069891d: { // 0x69891d: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L00698921: { // 0x698921: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00698923: { // 0x698923: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00698927: { // 0x698927: 7c3b JL 0x00698964
    if(integer::condition("JL",flags)) goto L00698964;
  }
  L00698929: { // 0x698929: 8a0dc560aa00 MOV CL,byte ptr [0x00aa60c5]
    s.cx = with_al(s.cx, m.r8((0x00aa60c5u)));
  }
  L0069892f: { // 0x69892f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00698931: { // 0x698931: 7508 JNZ 0x0069893b
    if(integer::condition("JNZ",flags)) goto L0069893b;
  }
  L00698933: { // 0x698933: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00698935: { // 0x698935: 0f85cd000000 JNZ 0x00698a08
    if(integer::condition("JNZ",flags)) goto L00698a08;
  }
  L0069893b: { // 0x69893b: 8b0dcc60aa00 MOV ECX,dword ptr [0x00aa60cc]
    s.cx = m.r32((0x00aa60ccu));
  }
  L00698941: { // 0x698941: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00698943: { // 0x698943: 0f8ebf000000 JLE 0x00698a08
    if(integer::condition("JLE",flags)) goto L00698a08;
  }
  L00698949: { // 0x698949: 8b15b860aa00 MOV EDX,dword ptr [0x00aa60b8]
    s.dx = m.r32((0x00aa60b8u));
  }
  L0069894f: { // 0x69894f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00698951: { // 0x698951: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00698953: { // 0x698953: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00698954: { // 0x698954: b9b860aa00 MOV ECX,0xaa60b8
    s.cx = 0x00aa60b8u;
  }
  L00698959: { // 0x698959: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6916444u); flags=s.arithmetic_flags;
  }
  L0069895c: { // 0x69895c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069895e: { // 0x69895e: 0f84a4000000 JZ 0x00698a08
    if(integer::condition("JZ",flags)) goto L00698a08;
  }
  L00698964: { // 0x698964: 8b0dc860aa00 MOV ECX,dword ptr [0x00aa60c8]
    s.cx = m.r32((0x00aa60c8u));
  }
  L0069896a: { // 0x69896a: 8d742454 LEA ESI,[ESP + 0x54]
    s.si = (f.sp+0x00000054u);
  }
  L0069896e: { // 0x69896e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698970: { // 0x698970: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00698971: { // 0x698971: 890dc860aa00 MOV dword ptr [0x00aa60c8],ECX
    m.w32((0x00aa60c8u), s.cx);
  }
  L00698977: { // 0x698977: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L0069897d: { // 0x69897d: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698980: { // 0x698980: 8d3c81 LEA EDI,[ECX + EAX*0x4]
    s.di = (s.cx+(s.ax * 0x00000004u));
  }
  L00698983: { // 0x698983: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L00698988: { // 0x698988: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0069898a: { // 0x69898a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069898b: { // 0x69898b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069898c: { // 0x69898c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069898d: { // 0x69898d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069898e: { // 0x69898e: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00698991: { // 0x698991: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00698994: { // 0x698994: 8a4c247c MOV CL,byte ptr [ESP + 0x7c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000007cu)));
  }
  L00698998: { // 0x698998: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0069899a: { // 0x69899a: 7514 JNZ 0x006989b0
    if(integer::condition("JNZ",flags)) goto L006989b0;
  }
  L0069899c: { // 0x69899c: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0069899f: { // 0x69899f: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L006989a4: { // 0x6989a4: 8a4c9010 MOV CL,byte ptr [EAX + EDX*0x4 + 0x10]
    s.cx = with_al(s.cx, m.r8((s.ax+(s.dx * 0x00000004u)+0x00000010u)));
  }
  L006989a8: { // 0x6989a8: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006989aa: { // 0x6989aa: 7504 JNZ 0x006989b0
    if(integer::condition("JNZ",flags)) goto L006989b0;
  }
  L006989ac: { // 0x6989ac: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006989ae: { // 0x6989ae: eb05 JMP 0x006989b5
    goto L006989b5;
  }
  L006989b0: { // 0x6989b0: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006989b5: { // 0x6989b5: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L006989b9: { // 0x6989b9: 8b0dbc60aa00 MOV ECX,dword ptr [0x00aa60bc]
    s.cx = m.r32((0x00aa60bcu));
  }
  L006989bf: { // 0x6989bf: 8d34b6 LEA ESI,[ESI + ESI*0x4]
    s.si = (s.si+(s.si * 0x00000004u));
  }
  L006989c2: { // 0x6989c2: c1e602 SHL ESI,0x2
    s.si = integer::shift(s.si,0x00000002u,32,flags,integer::Shift::left);
  }
  L006989c5: { // 0x6989c5: 8d140e LEA EDX,[ESI + ECX*0x1]
    s.dx = (s.si+(s.cx * 0x00000001u));
  }
  L006989c8: { // 0x6989c8: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L006989cc: { // 0x6989cc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006989cd: { // 0x6989cd: 8d542470 LEA EDX,[ESP + 0x70]
    s.dx = (f.sp+0x00000070u);
  }
  L006989d1: { // 0x6989d1: e87a62dcff CALL 0x0045ec50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0045ec50u,6916566u); flags=s.arithmetic_flags;
  }
  L006989d6: { // 0x6989d6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006989d8: { // 0x6989d8: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006989db: { // 0x6989db: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006989df: { // 0x6989df: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006989e2: { // 0x6989e2: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L006989e6: { // 0x6989e6: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006989e9: { // 0x6989e9: a1bc60aa00 MOV EAX,[0x00aa60bc]
    s.ax = m.r32((0x00aa60bcu));
  }
  L006989ee: { // 0x6989ee: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L006989f2: { // 0x6989f2: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L006989f7: { // 0x6989f7: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L006989fb: { // 0x6989fb: 8d3c06 LEA EDI,[ESI + EAX*0x1]
    s.di = (s.si+(s.ax * 0x00000001u));
  }
  L006989fe: { // 0x6989fe: 8d742440 LEA ESI,[ESP + 0x40]
    s.si = (f.sp+0x00000040u);
  }
  L00698a02: { // 0x698a02: 885c2450 MOV byte ptr [ESP + 0x50],BL
    m.w8((f.sp+0x00000050u), (s.bx & 0xffu));
  }
  L00698a06: { // 0x698a06: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00698a08: { // 0x698a08: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00698a09: { // 0x698a09: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00698a0a: { // 0x698a0a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00698a0b: { // 0x698a0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00698a0c: { // 0x698a0c: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L00698a0f: { // 0x698a0f: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_0001fdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041fdf0: { // 0x41fdf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0041fdf3: { // 0x41fdf3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041fdf5: { // 0x41fdf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041fdf6: { // 0x41fdf6: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fdfa: { // 0x41fdfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041fdfb: { // 0x41fdfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041fdfc: { // 0x41fdfc: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041fdfe: { // 0x41fdfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041fdff: { // 0x41fdff: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L0041fe01: { // 0x41fe01: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0041fe04: { // 0x41fe04: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L0041fe07: { // 0x41fe07: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe0b: { // 0x41fe0b: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  L0041fe0e: { // 0x41fe0e: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0041fe12: { // 0x41fe12: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0041fe15: { // 0x41fe15: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041fe17: { // 0x41fe17: 0f8edb000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe1d: { // 0x41fe1d: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0041fe20: { // 0x41fe20: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe22: { // 0x41fe22: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0041fe26: { // 0x41fe26: 0f8ecc000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe2c: { // 0x41fe2c: 8b6908 MOV EBP,dword ptr [ECX + 0x8]
    s.bp = m.r32((s.cx+0x00000008u));
  }
  L0041fe2f: { // 0x41fe2f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe31: { // 0x41fe31: 0f8ec1000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe37: { // 0x41fe37: 8b690c MOV EBP,dword ptr [ECX + 0xc]
    s.bp = m.r32((s.cx+0x0000000cu));
  }
  L0041fe3a: { // 0x41fe3a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe3c: { // 0x41fe3c: 0f8eb6000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe42: { // 0x41fe42: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0041fe44: { // 0x41fe44: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe46: { // 0x41fe46: 7d0e JGE 0x0041fe56
    if(integer::condition("JGE",flags)) goto L0041fe56;
  }
  L0041fe48: { // 0x41fe48: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe4c: { // 0x41fe4c: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe4e: { // 0x41fe4e: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe50: { // 0x41fe50: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0041fe52: { // 0x41fe52: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe56: { // 0x41fe56: 837c242001 CMP dword ptr [ESP + 0x20],0x1
    (void)integer::sub(m.r32((f.sp+0x00000020u)),0x00000001u,32,flags);
  }
  L0041fe5b: { // 0x41fe5b: 0f8c97000000 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe61: { // 0x41fe61: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L0041fe64: { // 0x41fe64: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe66: { // 0x41fe66: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0041fe6a: { // 0x41fe6a: 7d0e JGE 0x0041fe7a
    if(integer::condition("JGE",flags)) goto L0041fe7a;
  }
  L0041fe6c: { // 0x41fe6c: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0041fe70: { // 0x41fe70: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe72: { // 0x41fe72: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041fe74: { // 0x41fe74: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0041fe76: { // 0x41fe76: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0041fe7a: { // 0x41fe7a: 837c242401 CMP dword ptr [ESP + 0x24],0x1
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x00000001u,32,flags);
  }
  L0041fe7f: { // 0x41fe7f: 7c77 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe81: { // 0x41fe81: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe85: { // 0x41fe85: 8d1431 LEA EDX,[ECX + ESI*0x1]
    s.dx = (s.cx+(s.si * 0x00000001u));
  }
  L0041fe88: { // 0x41fe88: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe8a: { // 0x41fe8a: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041fe8c: { // 0x41fe8c: 7e06 JLE 0x0041fe94
    if(integer::condition("JLE",flags)) goto L0041fe94;
  }
  L0041fe8e: { // 0x41fe8e: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0041fe90: { // 0x41fe90: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041fe92: { // 0x41fe92: eb04 JMP 0x0041fe98
    goto L0041fe98;
  }
  L0041fe94: { // 0x41fe94: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fe98: { // 0x41fe98: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0041fe9b: { // 0x41fe9b: 7c5b JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe9d: { // 0x41fe9d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041fea1: { // 0x41fea1: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0041fea5: { // 0x41fea5: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041fea7: { // 0x41fea7: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041feab: { // 0x41feab: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  L0041feae: { // 0x41feae: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041feb0: { // 0x41feb0: 7e04 JLE 0x0041feb6
    if(integer::condition("JLE",flags)) goto L0041feb6;
  }
  L0041feb2: { // 0x41feb2: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0041feb4: { // 0x41feb4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0041feb6: { // 0x41feb6: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0041feb9: { // 0x41feb9: 7c3d JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041febb: { // 0x41febb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0041febf: { // 0x41febf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fec1: { // 0x41fec1: 740b JZ 0x0041fece
    if(integer::condition("JZ",flags)) goto L0041fece;
  }
  L0041fec3: { // 0x41fec3: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041fec7: { // 0x41fec7: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L0041feca: { // 0x41feca: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0041fecc: { // 0x41fecc: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fece: { // 0x41fece: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0041fed2: { // 0x41fed2: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fed4: { // 0x41fed4: 740b JZ 0x0041fee1
    if(integer::condition("JZ",flags)) goto L0041fee1;
  }
  L0041fed6: { // 0x41fed6: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041feda: { // 0x41feda: 8b6d04 MOV EBP,dword ptr [EBP + 0x4]
    s.bp = m.r32((s.bp+0x00000004u));
  }
  L0041fedd: { // 0x41fedd: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0041fedf: { // 0x41fedf: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fee1: { // 0x41fee1: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fee3: { // 0x41fee3: 891a MOV dword ptr [EDX],EBX
    m.w32((s.dx), s.bx);
  }
  L0041fee5: { // 0x41fee5: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0041fee8: { // 0x41fee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fee9: { // 0x41fee9: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041feec: { // 0x41feec: 89720c MOV dword ptr [EDX + 0xc],ESI
    m.w32((s.dx+0x0000000cu), s.si);
  }
  L0041feef: { // 0x41feef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fef0: { // 0x41fef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041fef1: { // 0x41fef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041fef2: { // 0x41fef2: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041fef5: { // 0x41fef5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041fef8: { // 0x41fef8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fefa: { // 0x41fefa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041fefc: { // 0x41fefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fefd: { // 0x41fefd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fefe: { // 0x41fefe: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0041ff00: { // 0x41ff00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ff01: { // 0x41ff01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ff02: { // 0x41ff02: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0041ff05: { // 0x41ff05: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041ff08: { // 0x41ff08: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L0041ff0b: { // 0x41ff0b: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041ff0e: { // 0x41ff0e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0005ec50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045ec50: { // 0x45ec50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0045ec53: { // 0x45ec53: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L0045ec56: { // 0x45ec56: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0045ec57: { // 0x45ec57: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0045ec58: { // 0x45ec58: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0045ec5a: { // 0x45ec5a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045ec5c: { // 0x45ec5c: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0045ec60: { // 0x45ec60: 0f8eb4000000 JLE 0x0045ed1a
    if(integer::condition("JLE",flags)) goto L0045ed1a;
  }
  L0045ec66: { // 0x45ec66: 8b420c MOV EAX,dword ptr [EDX + 0xc]
    s.ax = m.r32((s.dx+0x0000000cu));
  }
  L0045ec69: { // 0x45ec69: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045ec6b: { // 0x45ec6b: 0f8ea9000000 JLE 0x0045ed1a
    if(integer::condition("JLE",flags)) goto L0045ed1a;
  }
  L0045ec71: { // 0x45ec71: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0045ec75: { // 0x45ec75: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0045ec78: { // 0x45ec78: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0045ec7a: { // 0x45ec7a: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0045ec7e: { // 0x45ec7e: 7e7a JLE 0x0045ecfa
    if(integer::condition("JLE",flags)) goto L0045ecfa;
  }
  L0045ec80: { // 0x45ec80: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  L0045ec83: { // 0x45ec83: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0045ec85: { // 0x45ec85: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0045ec89: { // 0x45ec89: 7e6f JLE 0x0045ecfa
    if(integer::condition("JLE",flags)) goto L0045ecfa;
  }
  L0045ec8b: { // 0x45ec8b: 8b3a MOV EDI,dword ptr [EDX]
    s.di = m.r32((s.dx));
  }
  L0045ec8d: { // 0x45ec8d: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L0045ec8f: { // 0x45ec8f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0045ec90: { // 0x45ec90: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  L0045ec93: { // 0x45ec93: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0045ec94: { // 0x45ec94: 8b6a08 MOV EBP,dword ptr [EDX + 0x8]
    s.bp = m.r32((s.dx+0x00000008u));
  }
  L0045ec97: { // 0x45ec97: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L0045ec9a: { // 0x45ec9a: 3bfe CMP EDI,ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  L0045ec9c: { // 0x45ec9c: 7e06 JLE 0x0045eca4
    if(integer::condition("JLE",flags)) goto L0045eca4;
  }
  L0045ec9e: { // 0x45ec9e: 2bfe SUB EDI,ESI
    s.di = integer::sub(s.di,s.si,32,flags);
  }
  L0045eca0: { // 0x45eca0: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0045eca2: { // 0x45eca2: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0045eca4: { // 0x45eca4: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0045eca7: { // 0x45eca7: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0045eca9: { // 0x45eca9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0045ecad: { // 0x45ecad: 7e06 JLE 0x0045ecb5
    if(integer::condition("JLE",flags)) goto L0045ecb5;
  }
  L0045ecaf: { // 0x45ecaf: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0045ecb1: { // 0x45ecb1: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L0045ecb3: { // 0x45ecb3: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0045ecb5: { // 0x45ecb5: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0045ecb7: { // 0x45ecb7: 8d0c2f LEA ECX,[EDI + EBP*0x1]
    s.cx = (s.di+(s.bp * 0x00000001u));
  }
  L0045ecba: { // 0x45ecba: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0045ecbc: { // 0x45ecbc: 7d0a JGE 0x0045ecc8
    if(integer::condition("JGE",flags)) goto L0045ecc8;
  }
  L0045ecbe: { // 0x45ecbe: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0045ecc2: { // 0x45ecc2: 2bf7 SUB ESI,EDI
    s.si = integer::sub(s.si,s.di,32,flags);
  }
  L0045ecc4: { // 0x45ecc4: 8d6c0601 LEA EBP,[ESI + EAX*0x1 + 0x1]
    s.bp = (s.si+(s.ax * 0x00000001u)+0x00000001u);
  }
  L0045ecc8: { // 0x45ecc8: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0045eccc: { // 0x45eccc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0045ecd0: { // 0x45ecd0: 8d3401 LEA ESI,[ECX + EAX*0x1]
    s.si = (s.cx+(s.ax * 0x00000001u));
  }
  L0045ecd3: { // 0x45ecd3: 8d0c1a LEA ECX,[EDX + EBX*0x1]
    s.cx = (s.dx+(s.bx * 0x00000001u));
  }
  L0045ecd6: { // 0x45ecd6: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L0045ecd8: { // 0x45ecd8: 7d05 JGE 0x0045ecdf
    if(integer::condition("JGE",flags)) goto L0045ecdf;
  }
  L0045ecda: { // 0x45ecda: 2bf3 SUB ESI,EBX
    s.si = integer::sub(s.si,s.bx,32,flags);
  }
  L0045ecdc: { // 0x45ecdc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0045ecdd: { // 0x45ecdd: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0045ecdf: { // 0x45ecdf: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0045ece3: { // 0x45ece3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0045ece5: { // 0x45ece5: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L0045ece7: { // 0x45ece7: 895904 MOV dword ptr [ECX + 0x4],EBX
    m.w32((s.cx+0x00000004u), s.bx);
  }
  L0045ecea: { // 0x45ecea: 896908 MOV dword ptr [ECX + 0x8],EBP
    m.w32((s.cx+0x00000008u), s.bp);
  }
  L0045eced: { // 0x45eced: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0045ecee: { // 0x45ecee: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0045ecef: { // 0x45ecef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045ecf0: { // 0x45ecf0: 89510c MOV dword ptr [ECX + 0xc],EDX
    m.w32((s.cx+0x0000000cu), s.dx);
  }
  L0045ecf3: { // 0x45ecf3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045ecf4: { // 0x45ecf4: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0045ecf7: { // 0x45ecf7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0045ecfa: { // 0x45ecfa: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0045ecfc: { // 0x45ecfc: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0045ecfe: { // 0x45ecfe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045ecff: { // 0x45ecff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045ed00: { // 0x45ed00: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0045ed02: { // 0x45ed02: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0045ed05: { // 0x45ed05: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0045ed08: { // 0x45ed08: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0045ed0b: { // 0x45ed0b: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0045ed0e: { // 0x45ed0e: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L0045ed11: { // 0x45ed11: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0045ed14: { // 0x45ed14: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0045ed17: { // 0x45ed17: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0045ed1a: { // 0x45ed1a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0045ed1e: { // 0x45ed1e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0045ed20: { // 0x45ed20: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0045ed22: { // 0x45ed22: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0045ed24: { // 0x45ed24: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0045ed27: { // 0x45ed27: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0045ed2a: { // 0x45ed2a: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0045ed2d: { // 0x45ed2d: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L0045ed30: { // 0x45ed30: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0045ed33: { // 0x45ed33: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L0045ed36: { // 0x45ed36: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0045ed38: { // 0x45ed38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0045ed39: { // 0x45ed39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0045ed3a: { // 0x45ed3a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0045ed3d: { // 0x45ed3d: c20400 RET 0x4
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

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6914064u:f_00298010(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4673600u:f_00075040(m,s,child,{});break;
case 6112976u:f_001d46d0(m,s,child,{});break;
case 6117328u:f_001d57d0(m,s,child,{});break;
case 4672176u:f_00074ab0(m,s,child,{});break;
case 4672768u:f_00074d00(m,s,child,{});break;
case 4673200u:f_00074eb0(m,s,child,{});break;
case 6458352u:f_00228bf0(m,s,child,{});break;
case 5537600u:f_00147f40(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 6915680u:f_00298660(m,s,child,{});break;
case 4324848u:f_0001fdf0(m,s,child,{});break;
case 4582480u:f_0005ec50(m,s,child,{});break;
case 4306480u:f_0001b630(m,s,child,{});break;
default:throw std::domain_error("recovery614 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0047bc80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047bc80: { // 0x47bc80: 83ec40 SUB ESP,0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L0047bc83: { // 0x47bc83: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047bc84: { // 0x47bc84: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0047bc85: { // 0x47bc85: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047bc86: { // 0x47bc86: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0047bc8a: { // 0x47bc8a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047bc8b: { // 0x47bc8b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0047bc8d: { // 0x47bc8d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047bc8e: { // 0x47bc8e: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L0047bc92: { // 0x47bc92: e81992ffff CALL 0x00474eb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474eb0u,4701335u); flags=s.arithmetic_flags;
  }
  L0047bc97: { // 0x47bc97: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0047bc9b: { // 0x47bc9b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0047bc9d: { // 0x47bc9d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0047bc9e: { // 0x47bc9e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0047bca0: { // 0x47bca0: e80b8effff CALL 0x00474ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474ab0u,4701349u); flags=s.arithmetic_flags;
  }
  L0047bca5: { // 0x47bca5: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L0047bca8: { // 0x47bca8: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0047bcaa: { // 0x47bcaa: 7e7d JLE 0x0047bd29
    if(integer::condition("JLE",flags)) goto L0047bd29;
  }
  L0047bcac: { // 0x47bcac: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L0047bcaf: { // 0x47bcaf: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0047bcb1: { // 0x47bcb1: 7e76 JLE 0x0047bd29
    if(integer::condition("JLE",flags)) goto L0047bd29;
  }
  L0047bcb3: { // 0x47bcb3: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0047bcb6: { // 0x47bcb6: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0047bcb8: { // 0x47bcb8: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0047bcbc: { // 0x47bcbc: 7e5e JLE 0x0047bd1c
    if(integer::condition("JLE",flags)) goto L0047bd1c;
  }
  L0047bcbe: { // 0x47bcbe: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L0047bcc1: { // 0x47bcc1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0047bcc3: { // 0x47bcc3: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0047bcc7: { // 0x47bcc7: 7e53 JLE 0x0047bd1c
    if(integer::condition("JLE",flags)) goto L0047bd1c;
  }
  L0047bcc9: { // 0x47bcc9: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L0047bccb: { // 0x47bccb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0047bccd: { // 0x47bccd: 8b6f04 MOV EBP,dword ptr [EDI + 0x4]
    s.bp = m.r32((s.di+0x00000004u));
  }
  L0047bcd0: { // 0x47bcd0: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L0047bcd3: { // 0x47bcd3: 8b7f0c MOV EDI,dword ptr [EDI + 0xc]
    s.di = m.r32((s.di+0x0000000cu));
  }
  L0047bcd6: { // 0x47bcd6: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0047bcd8: { // 0x47bcd8: 7e06 JLE 0x0047bce0
    if(integer::condition("JLE",flags)) goto L0047bce0;
  }
  L0047bcda: { // 0x47bcda: 2bf1 SUB ESI,ECX
    s.si = integer::sub(s.si,s.cx,32,flags);
  }
  L0047bcdc: { // 0x47bcdc: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L0047bcde: { // 0x47bcde: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0047bce0: { // 0x47bce0: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L0047bce3: { // 0x47bce3: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0047bce5: { // 0x47bce5: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0047bce9: { // 0x47bce9: 7e06 JLE 0x0047bcf1
    if(integer::condition("JLE",flags)) goto L0047bcf1;
  }
  L0047bceb: { // 0x47bceb: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L0047bced: { // 0x47bced: 03fd ADD EDI,EBP
    s.di = integer::add(s.di,s.bp,32,flags);
  }
  L0047bcef: { // 0x47bcef: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0047bcf1: { // 0x47bcf1: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0047bcf3: { // 0x47bcf3: 8d0433 LEA EAX,[EBX + ESI*0x1]
    s.ax = (s.bx+(s.si * 0x00000001u));
  }
  L0047bcf6: { // 0x47bcf6: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0047bcf8: { // 0x47bcf8: 7d0a JGE 0x0047bd04
    if(integer::condition("JGE",flags)) goto L0047bd04;
  }
  L0047bcfa: { // 0x47bcfa: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0047bcfe: { // 0x47bcfe: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0047bd00: { // 0x47bd00: 8d5c1101 LEA EBX,[ECX + EDX*0x1 + 0x1]
    s.bx = (s.cx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0047bd04: { // 0x47bd04: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0047bd08: { // 0x47bd08: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0047bd0c: { // 0x47bd0c: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0047bd0e: { // 0x47bd0e: 8d142f LEA EDX,[EDI + EBP*0x1]
    s.dx = (s.di+(s.bp * 0x00000001u));
  }
  L0047bd11: { // 0x47bd11: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0047bd13: { // 0x47bd13: 7d1f JGE 0x0047bd34
    if(integer::condition("JGE",flags)) goto L0047bd34;
  }
  L0047bd15: { // 0x47bd15: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0047bd17: { // 0x47bd17: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0047bd18: { // 0x47bd18: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0047bd1a: { // 0x47bd1a: eb18 JMP 0x0047bd34
    goto L0047bd34;
  }
  L0047bd1c: { // 0x47bd1c: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L0047bd1e: { // 0x47bd1e: 8b6f04 MOV EBP,dword ptr [EDI + 0x4]
    s.bp = m.r32((s.di+0x00000004u));
  }
  L0047bd21: { // 0x47bd21: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L0047bd24: { // 0x47bd24: 8b7f0c MOV EDI,dword ptr [EDI + 0xc]
    s.di = m.r32((s.di+0x0000000cu));
  }
  L0047bd27: { // 0x47bd27: eb0b JMP 0x0047bd34
    goto L0047bd34;
  }
  L0047bd29: { // 0x47bd29: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0047bd2b: { // 0x47bd2b: 8b6804 MOV EBP,dword ptr [EAX + 0x4]
    s.bp = m.r32((s.ax+0x00000004u));
  }
  L0047bd2e: { // 0x47bd2e: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L0047bd31: { // 0x47bd31: 8b780c MOV EDI,dword ptr [EAX + 0xc]
    s.di = m.r32((s.ax+0x0000000cu));
  }
  L0047bd34: { // 0x47bd34: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0047bd38: { // 0x47bd38: 8d442440 LEA EAX,[ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L0047bd3c: { // 0x47bd3c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047bd3d: { // 0x47bd3d: e8be8fffff CALL 0x00474d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474d00u,4701506u); flags=s.arithmetic_flags;
  }
  L0047bd42: { // 0x47bd42: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0047bd44: { // 0x47bd44: 7e68 JLE 0x0047bdae
    if(integer::condition("JLE",flags)) goto L0047bdae;
  }
  L0047bd46: { // 0x47bd46: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0047bd48: { // 0x47bd48: 7e64 JLE 0x0047bdae
    if(integer::condition("JLE",flags)) goto L0047bdae;
  }
  L0047bd4a: { // 0x47bd4a: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0047bd4d: { // 0x47bd4d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0047bd4f: { // 0x47bd4f: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0047bd53: { // 0x47bd53: 7e53 JLE 0x0047bda8
    if(integer::condition("JLE",flags)) goto L0047bda8;
  }
  L0047bd55: { // 0x47bd55: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0047bd58: { // 0x47bd58: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0047bd5a: { // 0x47bd5a: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0047bd5e: { // 0x47bd5e: 7e48 JLE 0x0047bda8
    if(integer::condition("JLE",flags)) goto L0047bda8;
  }
  L0047bd60: { // 0x47bd60: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0047bd62: { // 0x47bd62: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L0047bd64: { // 0x47bd64: 7e08 JLE 0x0047bd6e
    if(integer::condition("JLE",flags)) goto L0047bd6e;
  }
  L0047bd66: { // 0x47bd66: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0047bd68: { // 0x47bd68: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L0047bd6a: { // 0x47bd6a: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L0047bd6c: { // 0x47bd6c: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0047bd6e: { // 0x47bd6e: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L0047bd71: { // 0x47bd71: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0047bd73: { // 0x47bd73: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0047bd77: { // 0x47bd77: 7e06 JLE 0x0047bd7f
    if(integer::condition("JLE",flags)) goto L0047bd7f;
  }
  L0047bd79: { // 0x47bd79: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L0047bd7b: { // 0x47bd7b: 03fd ADD EDI,EBP
    s.di = integer::add(s.di,s.bp,32,flags);
  }
  L0047bd7d: { // 0x47bd7d: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0047bd7f: { // 0x47bd7f: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0047bd81: { // 0x47bd81: 8d0433 LEA EAX,[EBX + ESI*0x1]
    s.ax = (s.bx+(s.si * 0x00000001u));
  }
  L0047bd84: { // 0x47bd84: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047bd86: { // 0x47bd86: 7d0a JGE 0x0047bd92
    if(integer::condition("JGE",flags)) goto L0047bd92;
  }
  L0047bd88: { // 0x47bd88: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0047bd8c: { // 0x47bd8c: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L0047bd8e: { // 0x47bd8e: 8d5c0a01 LEA EBX,[EDX + ECX*0x1 + 0x1]
    s.bx = (s.dx+(s.cx * 0x00000001u)+0x00000001u);
  }
  L0047bd92: { // 0x47bd92: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0047bd96: { // 0x47bd96: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0047bd9a: { // 0x47bd9a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0047bd9c: { // 0x47bd9c: 8d0c2f LEA ECX,[EDI + EBP*0x1]
    s.cx = (s.di+(s.bp * 0x00000001u));
  }
  L0047bd9f: { // 0x47bd9f: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0047bda1: { // 0x47bda1: 7d05 JGE 0x0047bda8
    if(integer::condition("JGE",flags)) goto L0047bda8;
  }
  L0047bda3: { // 0x47bda3: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0047bda5: { // 0x47bda5: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0047bda6: { // 0x47bda6: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0047bda8: { // 0x47bda8: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0047bdaa: { // 0x47bdaa: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0047bdac: { // 0x47bdac: eb0b JMP 0x0047bdb9
    goto L0047bdb9;
  }
  L0047bdae: { // 0x47bdae: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0047bdb0: { // 0x47bdb0: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0047bdb3: { // 0x47bdb3: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L0047bdb6: { // 0x47bdb6: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0047bdb9: { // 0x47bdb9: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L0047bdbf: { // 0x47bdbf: 8b3d74198200 MOV EDI,dword ptr [0x00821974]
    s.di = m.r32((0x00821974u));
  }
  L0047bdc5: { // 0x47bdc5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0047bdc7: { // 0x47bdc7: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0047bdc9: { // 0x47bdc9: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0047bdcc: { // 0x47bdcc: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L0047bdce: { // 0x47bdce: 8bd4 MOV EDX,ESP
    s.dx = f.sp;
  }
  L0047bdd0: { // 0x47bdd0: 8932 MOV dword ptr [EDX],ESI
    m.w32((s.dx), s.si);
  }
  L0047bdd2: { // 0x47bdd2: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0047bdd5: { // 0x47bdd5: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L0047bddb: { // 0x47bddb: 895a08 MOV dword ptr [EDX + 0x8],EBX
    m.w32((s.dx+0x00000008u), s.bx);
  }
  L0047bdde: { // 0x47bdde: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L0047bde1: { // 0x47bde1: e87ac82100 CALL 0x00698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,4701670u); flags=s.arithmetic_flags;
  }
  L0047bde6: { // 0x47bde6: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0047bdea: { // 0x47bdea: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0047bdef: { // 0x47bdef: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  L0047bdf2: { // 0x47bdf2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047bdf3: { // 0x47bdf3: e8f8cd1a00 CALL 0x00628bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00628bf0u,4701688u); flags=s.arithmetic_flags;
  }
  L0047bdf8: { // 0x47bdf8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047bdf9: { // 0x47bdf9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047bdfa: { // 0x47bdfa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047bdfb: { // 0x47bdfb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0047bdfc: { // 0x47bdfc: 83c440 ADD ESP,0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L0047bdff: { // 0x47bdff: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00493a60(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493a60: { // 0x493a60: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L00493a63: { // 0x493a63: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493a64: { // 0x493a64: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00493a65: { // 0x493a65: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493a66: { // 0x493a66: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00493a68: { // 0x493a68: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493a69: { // 0x493a69: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493a6a: { // 0x493a6a: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00493a6f: { // 0x493a6f: e8cc440b00 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,4799092u); flags=s.arithmetic_flags;
  }
  L00493a74: { // 0x493a74: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00493a76: { // 0x493a76: 0f843d010000 JZ 0x00493bb9
    if(integer::condition("JZ",flags)) goto L00493bb9;
  }
  L00493a7c: { // 0x493a7c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493a7d: { // 0x493a7d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00493a82: { // 0x493a82: e8791a0b00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4799111u); flags=s.arithmetic_flags;
  }
  L00493a87: { // 0x493a87: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00493a89: { // 0x493a89: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L00493a8d: { // 0x493a8d: 8b4344 MOV EAX,dword ptr [EBX + 0x44]
    s.ax = m.r32((s.bx+0x00000044u));
  }
  L00493a90: { // 0x493a90: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00493a93: { // 0x493a93: 0f8420010000 JZ 0x00493bb9
    if(integer::condition("JZ",flags)) goto L00493bb9;
  }
  L00493a99: { // 0x493a99: 8b0d1ce1a100 MOV ECX,dword ptr [0x00a1e11c]
    s.cx = m.r32((0x00a1e11cu));
  }
  L00493a9f: { // 0x493a9f: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00493aa2: { // 0x493aa2: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L00493aa8: { // 0x493aa8: 3b81f0000000 CMP EAX,dword ptr [ECX + 0xf0]
    (void)integer::sub(s.ax,m.r32((s.cx+0x000000f0u)),32,flags);
  }
  L00493aae: { // 0x493aae: 7414 JZ 0x00493ac4
    if(integer::condition("JZ",flags)) goto L00493ac4;
  }
  L00493ab0: { // 0x493ab0: 3b81f4000000 CMP EAX,dword ptr [ECX + 0xf4]
    (void)integer::sub(s.ax,m.r32((s.cx+0x000000f4u)),32,flags);
  }
  L00493ab6: { // 0x493ab6: 740c JZ 0x00493ac4
    if(integer::condition("JZ",flags)) goto L00493ac4;
  }
  L00493ab8: { // 0x493ab8: 3b81f8000000 CMP EAX,dword ptr [ECX + 0xf8]
    (void)integer::sub(s.ax,m.r32((s.cx+0x000000f8u)),32,flags);
  }
  L00493abe: { // 0x493abe: 0f85f5000000 JNZ 0x00493bb9
    if(integer::condition("JNZ",flags)) goto L00493bb9;
  }
  L00493ac4: { // 0x493ac4: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00493ac8: { // 0x493ac8: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00493aca: { // 0x493aca: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00493acb: { // 0x493acb: e83012feff CALL 0x00474d00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474d00u,4799184u); flags=s.arithmetic_flags;
  }
  L00493ad0: { // 0x493ad0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00493ad2: { // 0x493ad2: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L00493ad6: { // 0x493ad6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00493ad7: { // 0x493ad7: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00493ad9: { // 0x493ad9: e8d20ffeff CALL 0x00474ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00474ab0u,4799198u); flags=s.arithmetic_flags;
  }
  L00493ade: { // 0x493ade: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00493ae1: { // 0x493ae1: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00493ae3: { // 0x493ae3: 0f8e84000000 JLE 0x00493b6d
    if(integer::condition("JLE",flags)) goto L00493b6d;
  }
  L00493ae9: { // 0x493ae9: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00493aec: { // 0x493aec: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00493aee: { // 0x493aee: 7e7d JLE 0x00493b6d
    if(integer::condition("JLE",flags)) goto L00493b6d;
  }
  L00493af0: { // 0x493af0: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L00493af3: { // 0x493af3: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00493af5: { // 0x493af5: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L00493af9: { // 0x493af9: 7e65 JLE 0x00493b60
    if(integer::condition("JLE",flags)) goto L00493b60;
  }
  L00493afb: { // 0x493afb: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00493afe: { // 0x493afe: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00493b00: { // 0x493b00: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00493b04: { // 0x493b04: 7e5a JLE 0x00493b60
    if(integer::condition("JLE",flags)) goto L00493b60;
  }
  L00493b06: { // 0x493b06: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L00493b08: { // 0x493b08: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00493b0a: { // 0x493b0a: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00493b0d: { // 0x493b0d: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00493b10: { // 0x493b10: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00493b13: { // 0x493b13: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00493b15: { // 0x493b15: 7e06 JLE 0x00493b1d
    if(integer::condition("JLE",flags)) goto L00493b1d;
  }
  L00493b17: { // 0x493b17: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00493b19: { // 0x493b19: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00493b1b: { // 0x493b1b: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L00493b1d: { // 0x493b1d: 8b7604 MOV ESI,dword ptr [ESI + 0x4]
    s.si = m.r32((s.si+0x00000004u));
  }
  L00493b20: { // 0x493b20: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00493b22: { // 0x493b22: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00493b26: { // 0x493b26: 7e06 JLE 0x00493b2e
    if(integer::condition("JLE",flags)) goto L00493b2e;
  }
  L00493b28: { // 0x493b28: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L00493b2a: { // 0x493b2a: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00493b2c: { // 0x493b2c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00493b2e: { // 0x493b2e: 8d342a LEA ESI,[EDX + EBP*0x1]
    s.si = (s.dx+(s.bp * 0x00000001u));
  }
  L00493b31: { // 0x493b31: 8d2c1f LEA EBP,[EDI + EBX*0x1]
    s.bp = (s.di+(s.bx * 0x00000001u));
  }
  L00493b34: { // 0x493b34: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L00493b36: { // 0x493b36: 7d0a JGE 0x00493b42
    if(integer::condition("JGE",flags)) goto L00493b42;
  }
  L00493b38: { // 0x493b38: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00493b3c: { // 0x493b3c: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00493b3e: { // 0x493b3e: 8d7c3201 LEA EDI,[EDX + ESI*0x1 + 0x1]
    s.di = (s.dx+(s.si * 0x00000001u)+0x00000001u);
  }
  L00493b42: { // 0x493b42: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00493b46: { // 0x493b46: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L00493b4a: { // 0x493b4a: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00493b4c: { // 0x493b4c: 8d3408 LEA ESI,[EAX + ECX*0x1]
    s.si = (s.ax+(s.cx * 0x00000001u));
  }
  L00493b4f: { // 0x493b4f: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00493b51: { // 0x493b51: 7d05 JGE 0x00493b58
    if(integer::condition("JGE",flags)) goto L00493b58;
  }
  L00493b53: { // 0x493b53: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00493b55: { // 0x493b55: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00493b56: { // 0x493b56: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00493b58: { // 0x493b58: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00493b5a: { // 0x493b5a: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L00493b5e: { // 0x493b5e: eb18 JMP 0x00493b78
    goto L00493b78;
  }
  L00493b60: { // 0x493b60: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00493b62: { // 0x493b62: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00493b65: { // 0x493b65: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L00493b68: { // 0x493b68: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00493b6b: { // 0x493b6b: eb0b JMP 0x00493b78
    goto L00493b78;
  }
  L00493b6d: { // 0x493b6d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00493b6f: { // 0x493b6f: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00493b72: { // 0x493b72: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  L00493b75: { // 0x493b75: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00493b78: { // 0x493b78: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  L00493b7e: { // 0x493b7e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00493b80: { // 0x493b80: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L00493b84: { // 0x493b84: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00493b87: { // 0x493b87: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L00493b89: { // 0x493b89: 8bf4 MOV ESI,ESP
    s.si = f.sp;
  }
  L00493b8b: { // 0x493b8b: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L00493b8d: { // 0x493b8d: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00493b90: { // 0x493b90: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00493b96: { // 0x493b96: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00493b99: { // 0x493b99: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00493b9c: { // 0x493b9c: e8bf4a2000 CALL 0x00698660
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698660u,4799393u); flags=s.arithmetic_flags;
  }
  L00493ba1: { // 0x493ba1: c74344ffffffff MOV dword ptr [EBX + 0x44],0xffffffff
    m.w32((s.bx+0x00000044u), 0xffffffffu);
  }
  L00493ba8: { // 0x493ba8: c6831e01000000 MOV byte ptr [EBX + 0x11e],0x0
    m.w8((s.bx+0x0000011eu), 0x00000000u);
  }
  L00493baf: { // 0x493baf: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00493bb1: { // 0x493bb1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493bb2: { // 0x493bb2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493bb3: { // 0x493bb3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493bb4: { // 0x493bb4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493bb5: { // 0x493bb5: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00493bb8: { // 0x493bb8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00493bb9: { // 0x493bb9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493bba: { // 0x493bba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493bbb: { // 0x493bbb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493bbc: { // 0x493bbc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00493bbe: { // 0x493bbe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493bbf: { // 0x493bbf: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00493bc2: { // 0x493bc2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
