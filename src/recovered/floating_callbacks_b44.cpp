#include "recovered/floating_callbacks_b44_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::floating_callbacks_b44 {
namespace {
void f_00068640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x468640: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x468641: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x468642: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  { // 0x468644: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  { // 0x468647: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x468649: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x46864a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x46864b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x46864d: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x468651: 7435 JZ 0x00468688
    if(integer::condition("JZ",flags)) goto L00468688;
  }
  { // 0x468653: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x468655: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x468657: 742f JZ 0x00468688
    if(integer::condition("JZ",flags)) goto L00468688;
  }
  { // 0x468659: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x46865b: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x46865d: 7e29 JLE 0x00468688
    if(integer::condition("JLE",flags)) goto L00468688;
  }
  L0046865f: { // 0x46865f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x468661: 7425 JZ 0x00468688
    if(integer::condition("JZ",flags)) goto L00468688;
  }
  { // 0x468663: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x468665: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x468667: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000080u));
    invoke_external(m,s,f,op,0u,target,0x0046866du);
    flags=s.arithmetic_flags;
  }
  { // 0x46866d: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x468671: dc8050030000 FADD double ptr [EAX + 0x350]
    const auto address=(s.ax+0x00000350u);
    const auto operand=read64(m,address);
    s.fp.add64(operand);
  }
  { // 0x468677: e8d4233000 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x0046867cu);
    flags=s.arithmetic_flags;
  }
  { // 0x46867c: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x46867f: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x468680: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  { // 0x468682: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x468686: 7cd7 JL 0x0046865f
    if(integer::condition("JL",flags)) goto L0046865f;
  }
  L00468688: { // 0x468688: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x468689: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x46868a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x46868b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x46868c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00069700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x469700: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x469704: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x469708: 680000f0bf PUSH 0xbff00000
    f.push(m,0xbff00000u);
  }
  { // 0x46970d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x46970f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x469710: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x469711: e8da400a00 CALL 0x0050d7f0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0050d7f0u;
    invoke_external(m,s,f,op,0u,target,0x00469716u);
    flags=s.arithmetic_flags;
  }
  { // 0x469716: dc1578857800 FCOM double ptr [0x00788578]
    const auto address=(0x00788578u);
    const auto operand=read64(m,address);
    extended::compare64(s.fp,operand);
  }
  { // 0x46971c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x46971e: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x469721: 7409 JZ 0x0046972c
    if(integer::condition("JZ",flags)) goto L0046972c;
  }
  { // 0x469723: ddd8 FSTP ST0
    s.fp.pop_st0();
  }
  { // 0x469725: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x469729: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0046972c: { // 0x46972c: dc0d00577800 FMUL double ptr [0x00785700]
    const auto address=(0x00785700u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x469732: e819133000 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x00469737u);
    flags=s.arithmetic_flags;
  }
  { // 0x469737: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_000784e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4784e0: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x4784e5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4784e6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4784e8: 8a882a220000 MOV CL,byte ptr [EAX + 0x222a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000222au)));
  }
  { // 0x4784ee: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4784f0: 7504 JNZ 0x004784f6
    if(integer::condition("JNZ",flags)) goto L004784f6;
  }
  { // 0x4784f2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4784f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4784f5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004784f6: { // 0x4784f6: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x4784f9: e832c21500 CALL 0x005d4730
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x005d4730u;
    invoke_external(m,s,f,op,0u,target,0x004784feu);
    flags=s.arithmetic_flags;
  }
  { // 0x4784fe: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x478501: 7504 JNZ 0x00478507
    if(integer::condition("JNZ",flags)) goto L00478507;
  }
  { // 0x478503: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x478505: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x478506: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00478507: { // 0x478507: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  { // 0x47850d: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x478510: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  { // 0x478516: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x478518: 7404 JZ 0x0047851e
    if(integer::condition("JZ",flags)) goto L0047851e;
  }
  { // 0x47851a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47851c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47851d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047851e: { // 0x47851e: 8b88e4000000 MOV ECX,dword ptr [EAX + 0xe4]
    s.cx = m.r32((s.ax+0x000000e4u));
  }
  { // 0x478524: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x478526: 8a961e010000 MOV DL,byte ptr [ESI + 0x11e]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000011eu)));
  }
  { // 0x47852c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x47852d: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x47852f: 7c04 JL 0x00478535
    if(integer::condition("JL",flags)) goto L00478535;
  }
  { // 0x478531: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x478533: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x478534: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00478535: { // 0x478535: dd80b0000000 FLD double ptr [EAX + 0xb0]
    const auto address=(s.ax+0x000000b0u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x47853b: dc1d20757800 FCOMP double ptr [0x00787520]
    const auto address=(0x00787520u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x478541: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x478543: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x478546: 7404 JZ 0x0047854c
    if(integer::condition("JZ",flags)) goto L0047854c;
  }
  { // 0x478548: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47854a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47854b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047854c: { // 0x47854c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x47854e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47854f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00078550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x478550: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x478555: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x478556: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x478558: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x478559: f60080 TEST byte ptr [EAX],0x80
    (void)integer::logical((m.r8((s.ax)))&(0x00000080u),8,flags);
  }
  { // 0x47855c: 7505 JNZ 0x00478563
    if(integer::condition("JNZ",flags)) goto L00478563;
  }
  { // 0x47855e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47855f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x478561: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x478562: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00478563: { // 0x478563: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x478566: e8c5c11500 CALL 0x005d4730
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x005d4730u;
    invoke_external(m,s,f,op,0u,target,0x0047856bu);
    flags=s.arithmetic_flags;
  }
  { // 0x47856b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x47856d: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x478570: 7505 JNZ 0x00478577
    if(integer::condition("JNZ",flags)) goto L00478577;
  }
  { // 0x478572: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x478573: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x478575: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x478576: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00478577: { // 0x478577: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x478579: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x47857b: 8a8e1e010000 MOV CL,byte ptr [ESI + 0x11e]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011eu)));
  }
  { // 0x478581: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x478582: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x478584: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x478586: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x478588: 7f05 JG 0x0047858f
    if(integer::condition("JG",flags)) goto L0047858f;
  }
  { // 0x47858a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47858b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47858d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47858e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047858f: { // 0x47858f: 8a861c010000 MOV AL,byte ptr [ESI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000011cu)));
  }
  { // 0x478595: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x478597: 7405 JZ 0x0047859e
    if(integer::condition("JZ",flags)) goto L0047859e;
  }
  { // 0x478599: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47859a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47859c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47859d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047859e: { // 0x47859e: 8b153c86aa00 MOV EDX,dword ptr [0x00aa863c]
    s.dx = m.r32((0x00aa863cu));
  }
  { // 0x4785a4: 8b04ba MOV EAX,dword ptr [EDX + EDI*0x4]
    s.ax = m.r32((s.dx+(s.di * 0x00000004u)));
  }
  { // 0x4785a7: dd80a0000000 FLD double ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4785ad: dc1d20757800 FCOMP double ptr [0x00787520]
    const auto address=(0x00787520u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x4785b3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4785b5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4785b8: 7405 JZ 0x004785bf
    if(integer::condition("JZ",flags)) goto L004785bf;
  }
  { // 0x4785ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4785bb: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4785bd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4785be: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004785bf: { // 0x4785bf: 8b86e4000000 MOV EAX,dword ptr [ESI + 0xe4]
    s.ax = m.r32((s.si+0x000000e4u));
  }
  { // 0x4785c5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4785c6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4785c8: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  { // 0x4785cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4785cc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000785d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4785d0: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  { // 0x4785d5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4785d6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4785d8: 8a882a220000 MOV CL,byte ptr [EAX + 0x222a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000222au)));
  }
  { // 0x4785de: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4785e0: 745a JZ 0x0047863c
    if(integer::condition("JZ",flags)) goto L0047863c;
  }
  { // 0x4785e2: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x4785e5: e846c11500 CALL 0x005d4730
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x005d4730u;
    invoke_external(m,s,f,op,0u,target,0x004785eau);
    flags=s.arithmetic_flags;
  }
  { // 0x4785ea: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4785ed: 744d JZ 0x0047863c
    if(integer::condition("JZ",flags)) goto L0047863c;
  }
  { // 0x4785ef: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  { // 0x4785f5: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  { // 0x4785f8: 8a8e1c010000 MOV CL,byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  { // 0x4785fe: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x478600: 753a JNZ 0x0047863c
    if(integer::condition("JNZ",flags)) goto L0047863c;
  }
  { // 0x478602: 8b88e4000000 MOV ECX,dword ptr [EAX + 0xe4]
    s.cx = m.r32((s.ax+0x000000e4u));
  }
  { // 0x478608: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x47860a: 8a961e010000 MOV DL,byte ptr [ESI + 0x11e]
    s.dx = with_al(s.dx, m.r8((s.si+0x0000011eu)));
  }
  { // 0x478610: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x478611: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x478613: 7d27 JGE 0x0047863c
    if(integer::condition("JGE",flags)) goto L0047863c;
  }
  { // 0x478615: dd80b0000000 FLD double ptr [EAX + 0xb0]
    const auto address=(s.ax+0x000000b0u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x47861b: dc1d20757800 FCOMP double ptr [0x00787520]
    const auto address=(0x00787520u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x478621: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x478623: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x478626: 7514 JNZ 0x0047863c
    if(integer::condition("JNZ",flags)) goto L0047863c;
  }
  { // 0x478628: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x47862b: e800c11500 CALL 0x005d4730
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x005d4730u;
    invoke_external(m,s,f,op,1u,target,0x00478630u);
    flags=s.arithmetic_flags;
  }
  { // 0x478630: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x478632: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x478633: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x478635: e866390000 CALL 0x0047bfa0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0047bfa0u;
    invoke_external(m,s,f,op,2u,target,0x0047863au);
    flags=s.arithmetic_flags;
  }
  { // 0x47863a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47863b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047863c: { // 0x47863c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x47863e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47863f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000bf210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4bf210: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4bf211: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4bf215: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x4bf218: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4bf21a: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000080u));
    invoke_external(m,s,f,op,0u,target,0x004bf220u);
    flags=s.arithmetic_flags;
  }
  { // 0x4bf220: db80a0050000 FILD dword ptr [EAX + 0x5a0]
    const auto address=(s.ax+0x000005a0u);
    const auto operand=m.r32(address);
    s.fp.load_integer32(operand);
  }
  { // 0x4bf226: dc4e44 FMUL double ptr [ESI + 0x44]
    const auto address=(s.si+0x00000044u);
    const auto operand=read64(m,address);
    s.fp.multiply64(operand);
  }
  { // 0x4bf229: e822b82a00 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x004bf22eu);
    flags=s.arithmetic_flags;
  }
  { // 0x4bf22e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4bf22f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000f4da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f4da0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f4da1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f4da2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4f4da6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4f4da8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4f4daa: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4f4dac: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x0000002cu));
    invoke_external(m,s,f,op,0u,target,0x004f4dafu);
    flags=s.arithmetic_flags;
  }
  { // 0x4f4daf: 83c0fd ADD EAX,-0x3
    s.ax = integer::add(s.ax,0xfffffffdu,32,flags);
  }
  { // 0x4f4db2: 83f825 CMP EAX,0x25
    (void)integer::sub(s.ax,0x00000025u,32,flags);
  }
  { // 0x4f4db5: 775e JA 0x004f4e15
    if(integer::condition("JA",flags)) goto L004f4e15;
  }
  { // 0x4f4db7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4f4db9: 8a88344e4f00 MOV CL,byte ptr [EAX + 0x4f4e34]
    s.cx = with_al(s.cx, m.r8((s.ax+0x004f4e34u)));
  }
  { // 0x4f4dbf: ff248d204e4f00 JMP dword ptr [ECX*0x4 + 0x4f4e20]
    const auto destination=m.r32(((s.cx * 0x00000004u)+0x004f4e20u));
    switch(destination){
    case 0x004f4dc6u:goto L004f4dc6;
    case 0x004f4dd4u:goto L004f4dd4;
    case 0x004f4de2u:goto L004f4de2;
    case 0x004f4df0u:goto L004f4df0;
    case 0x004f4e15u:goto L004f4e15;
    default:throw std::invalid_argument("F44 foreign switch destination");}
  }
  L004f4dc6: { // 0x4f4dc6: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4dc9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4dca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4dcb: d98200010000 FLD float ptr [EDX + 0x100]
    const auto address=(s.dx+0x00000100u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4dd1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4dd4: { // 0x4f4dd4: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4dd7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4dd8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4dd9: d98004010000 FLD float ptr [EAX + 0x104]
    const auto address=(s.ax+0x00000104u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4ddf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4de2: { // 0x4f4de2: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4de5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4de6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4de7: d98108010000 FLD float ptr [ECX + 0x108]
    const auto address=(s.cx+0x00000108u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4ded: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4df0: { // 0x4f4df0: 83bfa00b000005 CMP dword ptr [EDI + 0xba0],0x5
    (void)integer::sub(m.r32((s.di+0x00000ba0u)),0x00000005u,32,flags);
  }
  { // 0x4f4df7: 750e JNZ 0x004f4e07
    if(integer::condition("JNZ",flags)) goto L004f4e07;
  }
  { // 0x4f4df9: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4dfc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4dfd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4dfe: d98210010000 FLD float ptr [EDX + 0x110]
    const auto address=(s.dx+0x00000110u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4e04: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4e07: { // 0x4f4e07: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4e0a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4e0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4e0c: d9800c010000 FLD float ptr [EAX + 0x10c]
    const auto address=(s.ax+0x0000010cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4e12: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4e15: { // 0x4f4e15: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4e1b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4e1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4e1d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000f4e60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f4e60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f4e61: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f4e62: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4f4e66: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4f4e68: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4f4e6a: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4f4e6c: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x0000002cu));
    invoke_external(m,s,f,op,0u,target,0x004f4e6fu);
    flags=s.arithmetic_flags;
  }
  { // 0x4f4e6f: 83c0fd ADD EAX,-0x3
    s.ax = integer::add(s.ax,0xfffffffdu,32,flags);
  }
  { // 0x4f4e72: 83f825 CMP EAX,0x25
    (void)integer::sub(s.ax,0x00000025u,32,flags);
  }
  { // 0x4f4e75: 775e JA 0x004f4ed5
    if(integer::condition("JA",flags)) goto L004f4ed5;
  }
  { // 0x4f4e77: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4f4e79: 8a88f44e4f00 MOV CL,byte ptr [EAX + 0x4f4ef4]
    s.cx = with_al(s.cx, m.r8((s.ax+0x004f4ef4u)));
  }
  { // 0x4f4e7f: ff248de04e4f00 JMP dword ptr [ECX*0x4 + 0x4f4ee0]
    const auto destination=m.r32(((s.cx * 0x00000004u)+0x004f4ee0u));
    switch(destination){
    case 0x004f4e86u:goto L004f4e86;
    case 0x004f4e94u:goto L004f4e94;
    case 0x004f4ea2u:goto L004f4ea2;
    case 0x004f4eb0u:goto L004f4eb0;
    case 0x004f4ed5u:goto L004f4ed5;
    default:throw std::invalid_argument("F44 foreign switch destination");}
  }
  L004f4e86: { // 0x4f4e86: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4e89: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4e8a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4e8b: d98214010000 FLD float ptr [EDX + 0x114]
    const auto address=(s.dx+0x00000114u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4e91: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4e94: { // 0x4f4e94: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4e97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4e98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4e99: d98018010000 FLD float ptr [EAX + 0x118]
    const auto address=(s.ax+0x00000118u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4e9f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4ea2: { // 0x4f4ea2: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4ea5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4ea6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4ea7: d9811c010000 FLD float ptr [ECX + 0x11c]
    const auto address=(s.cx+0x0000011cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4ead: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4eb0: { // 0x4f4eb0: 83bfa00b000005 CMP dword ptr [EDI + 0xba0],0x5
    (void)integer::sub(m.r32((s.di+0x00000ba0u)),0x00000005u,32,flags);
  }
  { // 0x4f4eb7: 750e JNZ 0x004f4ec7
    if(integer::condition("JNZ",flags)) goto L004f4ec7;
  }
  { // 0x4f4eb9: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4ebc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4ebd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4ebe: d98224010000 FLD float ptr [EDX + 0x124]
    const auto address=(s.dx+0x00000124u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4ec4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4ec7: { // 0x4f4ec7: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4eca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4ecb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4ecc: d98020010000 FLD float ptr [EAX + 0x120]
    const auto address=(s.ax+0x00000120u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4ed2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4ed5: { // 0x4f4ed5: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4edb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4edc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4edd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000f4f20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f4f20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f4f21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4f4f23: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x4f4f27: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x4f4f29: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x0000002cu));
    invoke_external(m,s,f,op,0u,target,0x004f4f2cu);
    flags=s.arithmetic_flags;
  }
  { // 0x4f4f2c: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x4f4f2f: 742e JZ 0x004f4f5f
    if(integer::condition("JZ",flags)) goto L004f4f5f;
  }
  { // 0x4f4f31: 83f810 CMP EAX,0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  { // 0x4f4f34: 741c JZ 0x004f4f52
    if(integer::condition("JZ",flags)) goto L004f4f52;
  }
  { // 0x4f4f36: 83f828 CMP EAX,0x28
    (void)integer::sub(s.ax,0x00000028u,32,flags);
  }
  { // 0x4f4f39: 740a JZ 0x004f4f45
    if(integer::condition("JZ",flags)) goto L004f4f45;
  }
  { // 0x4f4f3b: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4f41: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4f42: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4f45: { // 0x4f4f45: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4f48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4f49: d9812c010000 FLD float ptr [ECX + 0x12c]
    const auto address=(s.cx+0x0000012cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4f4f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4f52: { // 0x4f4f52: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4f55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4f56: d98228010000 FLD float ptr [EDX + 0x128]
    const auto address=(s.dx+0x00000128u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4f5c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4f5f: { // 0x4f4f5f: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4f62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4f63: d98030010000 FLD float ptr [EAX + 0x130]
    const auto address=(s.ax+0x00000130u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4f69: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000f4f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4f4f70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4f4f71: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4f4f72: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x4f4f76: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4f4f78: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4f4f7a: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x4f4f7c: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x0000002cu));
    invoke_external(m,s,f,op,0u,target,0x004f4f7fu);
    flags=s.arithmetic_flags;
  }
  { // 0x4f4f7f: 83c0fd ADD EAX,-0x3
    s.ax = integer::add(s.ax,0xfffffffdu,32,flags);
  }
  { // 0x4f4f82: 83f825 CMP EAX,0x25
    (void)integer::sub(s.ax,0x00000025u,32,flags);
  }
  { // 0x4f4f85: 775e JA 0x004f4fe5
    if(integer::condition("JA",flags)) goto L004f4fe5;
  }
  { // 0x4f4f87: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4f4f89: 8a8804504f00 MOV CL,byte ptr [EAX + 0x4f5004]
    s.cx = with_al(s.cx, m.r8((s.ax+0x004f5004u)));
  }
  { // 0x4f4f8f: ff248df04f4f00 JMP dword ptr [ECX*0x4 + 0x4f4ff0]
    const auto destination=m.r32(((s.cx * 0x00000004u)+0x004f4ff0u));
    switch(destination){
    case 0x004f4f96u:goto L004f4f96;
    case 0x004f4fa4u:goto L004f4fa4;
    case 0x004f4fb2u:goto L004f4fb2;
    case 0x004f4fc0u:goto L004f4fc0;
    case 0x004f4fe5u:goto L004f4fe5;
    default:throw std::invalid_argument("F44 foreign switch destination");}
  }
  L004f4f96: { // 0x4f4f96: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4f99: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4f9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4f9b: d98234010000 FLD float ptr [EDX + 0x134]
    const auto address=(s.dx+0x00000134u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4fa1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4fa4: { // 0x4f4fa4: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4fa7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4fa8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4fa9: d98038010000 FLD float ptr [EAX + 0x138]
    const auto address=(s.ax+0x00000138u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4faf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4fb2: { // 0x4f4fb2: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4fb5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4fb6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4fb7: d9813c010000 FLD float ptr [ECX + 0x13c]
    const auto address=(s.cx+0x0000013cu);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4fbd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4fc0: { // 0x4f4fc0: 83bfa00b000005 CMP dword ptr [EDI + 0xba0],0x5
    (void)integer::sub(m.r32((s.di+0x00000ba0u)),0x00000005u,32,flags);
  }
  { // 0x4f4fc7: 750e JNZ 0x004f4fd7
    if(integer::condition("JNZ",flags)) goto L004f4fd7;
  }
  { // 0x4f4fc9: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4fcc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4fcd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4fce: d98244010000 FLD float ptr [EDX + 0x144]
    const auto address=(s.dx+0x00000144u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4fd4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4fd7: { // 0x4f4fd7: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  { // 0x4f4fda: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4fdb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4fdc: d98040010000 FLD float ptr [EAX + 0x140]
    const auto address=(s.ax+0x00000140u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4fe2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4fe5: { // 0x4f4fe5: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x4f4feb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4f4fec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4f4fed: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000fbdd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4fbdd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fbdd1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x4fbdd5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4fbdd6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4fbdd8: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000010u));
    invoke_external(m,s,f,op,0u,target,0x004fbddbu);
    flags=s.arithmetic_flags;
  }
  { // 0x4fbddb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4fbddd: 7419 JZ 0x004fbdf8
    if(integer::condition("JZ",flags)) goto L004fbdf8;
  }
  { // 0x4fbddf: dd4644 FLD double ptr [ESI + 0x44]
    const auto address=(s.si+0x00000044u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x4fbde2: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x4fbde8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4fbdea: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4fbded: 7509 JNZ 0x004fbdf8
    if(integer::condition("JNZ",flags)) goto L004fbdf8;
  }
  { // 0x4fbdef: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x4fbdf4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fbdf5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004fbdf8: { // 0x4fbdf8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4fbdfa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4fbdfb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0023ee90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x63ee90: a1f83e7900 MOV EAX,[0x00793ef8]
    s.ax = m.r32((0x00793ef8u));
  }
  { // 0x63ee95: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x63ee96: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x63ee97: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x63ee9b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x63ee9d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x63ee9e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x63eea0: e85bcfecff CALL 0x0050be00
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0050be00u;
    invoke_external(m,s,f,op,0u,target,0x0063eea5u);
    flags=s.arithmetic_flags;
  }
  { // 0x63eea5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x63eea7: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x63eeaa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x63eeac: 744e JZ 0x0063eefc
    if(integer::condition("JZ",flags)) goto L0063eefc;
  }
  { // 0x63eeae: 8a8e98140000 MOV CL,byte ptr [ESI + 0x1498]
    s.cx = with_al(s.cx, m.r8((s.si+0x00001498u)));
  }
  { // 0x63eeb4: 8b15f83e7900 MOV EDX,dword ptr [0x00793ef8]
    s.dx = m.r32((0x00793ef8u));
  }
  { // 0x63eeba: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x63eebb: 68949b7d00 PUSH 0x7d9b94
    f.push(m,0x007d9b94u);
  }
  { // 0x63eec0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x63eec1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x63eec3: e898f9ecff CALL 0x0050e860
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0050e860u;
    invoke_external(m,s,f,op,1u,target,0x0063eec8u);
    flags=s.arithmetic_flags;
  }
  { // 0x63eec8: 8b8ea0140000 MOV ECX,dword ptr [ESI + 0x14a0]
    s.cx = m.r32((s.si+0x000014a0u));
  }
  { // 0x63eece: 888698140000 MOV byte ptr [ESI + 0x1498],AL
    m.w8((s.si+0x00001498u), (s.ax & 0xffu));
  }
  { // 0x63eed4: 8b86a4140000 MOV EAX,dword ptr [ESI + 0x14a4]
    s.ax = m.r32((s.si+0x000014a4u));
  }
  { // 0x63eeda: 8b15f83e7900 MOV EDX,dword ptr [0x00793ef8]
    s.dx = m.r32((0x00793ef8u));
  }
  { // 0x63eee0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x63eee1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x63eee2: 687c9b7d00 PUSH 0x7d9b7c
    f.push(m,0x007d9b7cu);
  }
  { // 0x63eee7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x63eee8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x63eeea: e801e9ecff CALL 0x0050d7f0
    s.arithmetic_flags=flags;
    const std::uint32_t target=0x0050d7f0u;
    invoke_external(m,s,f,op,2u,target,0x0063eeefu);
    flags=s.arithmetic_flags;
  }
  { // 0x63eeef: dd9ea0140000 FSTP double ptr [ESI + 0x14a0]
    const auto address=(s.si+0x000014a0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x63eef5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63eef6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x63eef8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63eef9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0063eefc: { // 0x63eefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63eefd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x63eeff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63ef00: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002cbcc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cbcc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cbcc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cbcc3: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  { // 0x6cbcc6: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cbcc7: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  { // 0x6cbcca: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6cbccb: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.cx+0x00000010u));
    invoke_external(m,s,f,op,0u,target,0x006cbcceu);
    flags=s.arithmetic_flags;
  }
  { // 0x6cbcce: d986e0010000 FLD float ptr [ESI + 0x1e0]
    const auto address=(s.si+0x000001e0u);
    const auto operand=m.r32(address);
    s.fp.load32(operand);
  }
  { // 0x6cbcd4: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x6cbcd6: e875ed0900 CALL 0x0076aa50
    s.arithmetic_flags=flags;
    invoke_conversion(m,s,f,0x006cbcdbu);
    flags=s.arithmetic_flags;
  }
  { // 0x6cbcdb: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x6cbcdd: b990010000 MOV ECX,0x190
    s.cx = 0x00000190u;
  }
  { // 0x6cbce2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6cbce3: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x6cbce5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cbce6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cbce7: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x6cbce9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00312a70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x712a70: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x712a71: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x712a75: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x712a76: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x712a78: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags;
    const std::uint32_t target=m.r32((s.ax+0x00000010u));
    invoke_external(m,s,f,op,0u,target,0x00712a7bu);
    flags=s.arithmetic_flags;
  }
  { // 0x712a7b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x712a7d: 7441 JZ 0x00712ac0
    if(integer::condition("JZ",flags)) goto L00712ac0;
  }
  { // 0x712a7f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x712a82: dd8168040000 FLD double ptr [ECX + 0x468]
    const auto address=(s.cx+0x00000468u);
    const auto operand=read64(m,address);
    s.fp.load64(operand);
  }
  { // 0x712a88: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    const auto operand=read64(m,address);
    s.fp.compare_pop64(operand);
  }
  { // 0x712a8e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x712a90: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  { // 0x712a93: 752b JNZ 0x00712ac0
    if(integer::condition("JNZ",flags)) goto L00712ac0;
  }
  { // 0x712a95: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  { // 0x712a98: a1e00aae00 MOV EAX,[0x00ae0ae0]
    s.ax = m.r32((0x00ae0ae0u));
  }
  { // 0x712a9d: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x712a9f: 7519 JNZ 0x00712aba
    if(integer::condition("JNZ",flags)) goto L00712aba;
  }
  { // 0x712aa1: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x712aa4: 8b0de40aae00 MOV ECX,dword ptr [0x00ae0ae4]
    s.cx = m.r32((0x00ae0ae4u));
  }
  { // 0x712aaa: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x712aac: 750c JNZ 0x00712aba
    if(integer::condition("JNZ",flags)) goto L00712aba;
  }
  { // 0x712aae: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x712ab1: a1e80aae00 MOV EAX,[0x00ae0ae8]
    s.ax = m.r32((0x00ae0ae8u));
  }
  { // 0x712ab6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x712ab8: 7406 JZ 0x00712ac0
    if(integer::condition("JZ",flags)) goto L00712ac0;
  }
  L00712aba: { // 0x712aba: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x712abc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x712abd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00712ac0: { // 0x712ac0: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x712ac2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x712ac3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
const std::array<Entry,14>& entries_a() {
  static const std::array<Entry,14> entries{{
    {0x68640u,f_00068640},
    {0x69700u,f_00069700},
    {0x784e0u,f_000784e0},
    {0x78550u,f_00078550},
    {0x785d0u,f_000785d0},
    {0xbf210u,f_000bf210},
    {0xf4da0u,f_000f4da0},
    {0xf4e60u,f_000f4e60},
    {0xf4f20u,f_000f4f20},
    {0xf4f70u,f_000f4f70},
    {0xfbdd0u,f_000fbdd0},
    {0x23ee90u,f_0023ee90},
    {0x2cbcc0u,f_002cbcc0},
    {0x312a70u,f_00312a70},
  }}; return entries;
}
} // namespace ra2::recovered::floating_callbacks_b44
