#include "recovered/recovery_b236_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b236 {
namespace {
void f_00108c50(Memory&,State&,Frame&,const Operations&);
void f_001035b0(Memory&,State&,Frame&,const Operations&);
void f_00103bd0(Memory&,State&,Frame&,const Operations&);
void f_000101f0(Memory&,State&,Frame&,const Operations&);
void f_0000cd40(Memory&,State&,Frame&,const Operations&);
void f_0000dc20(Memory&,State&,Frame&,const Operations&);
void f_000cca70(Memory&,State&,Frame&,const Operations&);
void f_001cdaa0(Memory&,State&,Frame&,const Operations&);
void f_00191ed0(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_00105da0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00108c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00508c50: debug_va=0x00508c50; { // 0x508c50: b80f000000 MOV EAX, 0xF
    s.ax = 0x0000000fu;
  }
  L00508c55: debug_va=0x00508c55; { // 0x508c55: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001035b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005035b0: debug_va=0x005035b0; { // 0x5035b0: 83ec40 SUB ESP, 0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L005035b3: debug_va=0x005035b3; { // 0x5035b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005035b4: debug_va=0x005035b4; { // 0x5035b4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005035b5: debug_va=0x005035b5; { // 0x5035b5: 8a5c2450 MOV BL, byte ptr [ESP + 0x50]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000050u)));
  }
  L005035b9: debug_va=0x005035b9; { // 0x5035b9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005035ba: debug_va=0x005035ba; { // 0x5035ba: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005035bc: debug_va=0x005035bc; { // 0x5035bc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005035bd: debug_va=0x005035bd; { // 0x5035bd: 8b86ac050000 MOV EAX, dword ptr [ESI + 0x5AC]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L005035c3: debug_va=0x005035c3; { // 0x5035c3: 83f81b CMP EAX, 0x1B
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  L005035c6: debug_va=0x005035c6; { // 0x5035c6: 740f JZ 0x5035D7
    if(integer::condition("JZ",flags)) goto L005035d7;
  }
  L005035c8: debug_va=0x005035c8; { // 0x5035c8: 83f81c CMP EAX, 0x1C
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  L005035cb: debug_va=0x005035cb; { // 0x5035cb: 740a JZ 0x5035D7
    if(integer::condition("JZ",flags)) goto L005035d7;
  }
  L005035cd: debug_va=0x005035cd; { // 0x5035cd: 83f81d CMP EAX, 0x1D
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L005035d0: debug_va=0x005035d0; { // 0x5035d0: 7405 JZ 0x5035D7
    if(integer::condition("JZ",flags)) goto L005035d7;
  }
  L005035d2: debug_va=0x005035d2; { // 0x5035d2: 83f81e CMP EAX, 0x1E
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  L005035d5: debug_va=0x005035d5; { // 0x5035d5: 751e JNZ 0x5035F5
    if(integer::condition("JNZ",flags)) goto L005035f5;
  }
  L005035d7: debug_va=0x005035d7; { // 0x5035d7: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005035d9: debug_va=0x005035d9; { // 0x5035d9: 741a JZ 0x5035F5
    if(integer::condition("JZ",flags)) goto L005035f5;
  }
  L005035db: debug_va=0x005035db; { // 0x5035db: 8a44245c MOV AL, byte ptr [ESP + 0x5C]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000005cu)));
  }
  L005035df: debug_va=0x005035df; { // 0x5035df: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005035e1: debug_va=0x005035e1; { // 0x5035e1: 7412 JZ 0x5035F5
    if(integer::condition("JZ",flags)) goto L005035f5;
  }
  L005035e3: debug_va=0x005035e3; { // 0x5035e3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005035e5: debug_va=0x005035e5; { // 0x5035e5: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005035e7: debug_va=0x005035e7; { // 0x5035e7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005035e8: debug_va=0x005035e8; { // 0x5035e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005035e9: debug_va=0x005035e9; { // 0x5035e9: 6a1f PUSH 0x1F
    f.push(m,0x0000001fu);
  }
  L005035eb: debug_va=0x005035eb; { // 0x5035eb: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005035ed: debug_va=0x005035ed; { // 0x5035ed: ff90dc040000 CALL dword ptr [EAX + 0x4DC]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000004dcu)),5256691u); flags=s.arithmetic_flags;
  }
  L005035f3: debug_va=0x005035f3; { // 0x5035f3: eb3b JMP 0x503630
    goto L00503630;
  }
  L005035f5: debug_va=0x005035f5; { // 0x5035f5: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1B4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L005035fb: debug_va=0x005035fb; { // 0x5035fb: e8f011ffff CALL 0x4F47F0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,5256704u); flags=s.arithmetic_flags;
  }
  L00503600: debug_va=0x00503600; { // 0x503600: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503602: debug_va=0x00503602; { // 0x503602: 742a JZ 0x50362E
    if(integer::condition("JZ",flags)) goto L0050362e;
  }
  L00503604: debug_va=0x00503604; { // 0x503604: 8b86ac050000 MOV EAX, dword ptr [ESI + 0x5AC]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L0050360a: debug_va=0x0050360a; { // 0x50360a: 83f81b CMP EAX, 0x1B
    (void)integer::sub(s.ax,0x0000001bu,32,flags);
  }
  L0050360d: debug_va=0x0050360d; { // 0x50360d: 0f84ae050000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L00503613: debug_va=0x00503613; { // 0x503613: 83f81c CMP EAX, 0x1C
    (void)integer::sub(s.ax,0x0000001cu,32,flags);
  }
  L00503616: debug_va=0x00503616; { // 0x503616: 0f84a5050000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L0050361c: debug_va=0x0050361c; { // 0x50361c: 83f81d CMP EAX, 0x1D
    (void)integer::sub(s.ax,0x0000001du,32,flags);
  }
  L0050361f: debug_va=0x0050361f; { // 0x50361f: 0f849c050000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L00503625: debug_va=0x00503625; { // 0x503625: 83f81e CMP EAX, 0x1E
    (void)integer::sub(s.ax,0x0000001eu,32,flags);
  }
  L00503628: debug_va=0x00503628; { // 0x503628: 0f8493050000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L0050362e: debug_va=0x0050362e; { // 0x50362e: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00503630: debug_va=0x00503630; { // 0x503630: 39ae64050000 CMP dword ptr [ESI + 0x564], EBP
    (void)integer::sub(m.r32((s.si+0x00000564u)),s.bp,32,flags);
  }
  L00503636: debug_va=0x00503636; { // 0x503636: 750a JNZ 0x503642
    if(integer::condition("JNZ",flags)) goto L00503642;
  }
  L00503638: debug_va=0x00503638; { // 0x503638: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L0050363d: debug_va=0x0050363d; { // 0x50363d: e82edc2700 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5256770u); flags=s.arithmetic_flags;
  }
  L00503642: debug_va=0x00503642; { // 0x503642: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L00503648: debug_va=0x00503648; { // 0x503648: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503649: debug_va=0x00503649; { // 0x503649: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0050364b: debug_va=0x0050364b; { // 0x50364b: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),5256782u); flags=s.arithmetic_flags;
  }
  L0050364e: debug_va=0x0050364e; { // 0x50364e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503650: debug_va=0x00503650; { // 0x503650: 7402 JZ 0x503654
    if(integer::condition("JZ",flags)) goto L00503654;
  }
  L00503652: debug_va=0x00503652; { // 0x503652: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L00503654: debug_va=0x00503654; { // 0x503654: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503656: debug_va=0x00503656; { // 0x503656: e875e80800 CALL 0x591ED0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00591ed0u,5256795u); flags=s.arithmetic_flags;
  }
  L0050365b: debug_va=0x0050365b; { // 0x50365b: 8a4809 MOV CL, byte ptr [EAX + 9]
    s.cx = with_al(s.cx, m.r8((s.ax+9u)));
  }
  L0050365e: debug_va=0x0050365e; { // 0x50365e: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00503660: debug_va=0x00503660; { // 0x503660: 7508 JNZ 0x50366A
    if(integer::condition("JNZ",flags)) goto L0050366a;
  }
  L00503662: debug_va=0x00503662; { // 0x503662: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00503664: debug_va=0x00503664; { // 0x503664: 0f8457050000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L0050366a: debug_va=0x0050366a; { // 0x50366a: 8b96a8050000 MOV EDX, dword ptr [ESI + 0x5A8]
    s.dx = m.r32((s.si+0x000005a8u));
  }
  L00503670: debug_va=0x00503670; { // 0x503670: 8a820d0c0000 MOV AL, byte ptr [EDX + 0xC0D]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000c0du)));
  }
  L00503676: debug_va=0x00503676; { // 0x503676: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503678: debug_va=0x00503678; { // 0x503678: 7510 JNZ 0x50368A
    if(integer::condition("JNZ",flags)) goto L0050368a;
  }
  L0050367a: debug_va=0x0050367a; { // 0x50367a: 39ae28020000 CMP dword ptr [ESI + 0x228], EBP
    (void)integer::sub(m.r32((s.si+0x00000228u)),s.bp,32,flags);
  }
  L00503680: debug_va=0x00503680; { // 0x503680: 7408 JZ 0x50368A
    if(integer::condition("JZ",flags)) goto L0050368a;
  }
  L00503682: debug_va=0x00503682; { // 0x503682: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00503684: debug_va=0x00503684; { // 0x503684: 0f8437050000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L0050368a: debug_va=0x0050368a; { // 0x50368a: 8b86ac050000 MOV EAX, dword ptr [ESI + 0x5AC]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L00503690: debug_va=0x00503690; { // 0x503690: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L00503693: debug_va=0x00503693; { // 0x503693: 7414 JZ 0x5036A9
    if(integer::condition("JZ",flags)) goto L005036a9;
  }
  L00503695: debug_va=0x00503695; { // 0x503695: 83f81f CMP EAX, 0x1F
    (void)integer::sub(s.ax,0x0000001fu,32,flags);
  }
  L00503698: debug_va=0x00503698; { // 0x503698: 740f JZ 0x5036A9
    if(integer::condition("JZ",flags)) goto L005036a9;
  }
  L0050369a: debug_va=0x0050369a; { // 0x50369a: 8a0c8574e47800 MOV CL, byte ptr [EAX*4 + 0x78E474]
    s.cx = with_al(s.cx, m.r8(((s.ax * 4u)+0x0078e474u)));
  }
  L005036a1: debug_va=0x005036a1; { // 0x5036a1: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005036a3: debug_va=0x005036a3; { // 0x5036a3: 0f8418050000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L005036a9: debug_va=0x005036a9; { // 0x5036a9: a1881b8200 MOV EAX, dword ptr [0x821B88]
    s.ax = m.r32((0x00821b88u));
  }
  L005036ae: debug_va=0x005036ae; { // 0x5036ae: 8a8831140000 MOV CL, byte ptr [EAX + 0x1431]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001431u)));
  }
  L005036b4: debug_va=0x005036b4; { // 0x5036b4: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005036b6: debug_va=0x005036b6; { // 0x5036b6: 7536 JNZ 0x5036EE
    if(integer::condition("JNZ",flags)) goto L005036ee;
  }
  L005036b8: debug_va=0x005036b8; { // 0x5036b8: 6a03 PUSH 3
    f.push(m,3u);
  }
  L005036ba: debug_va=0x005036ba; { // 0x5036ba: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005036bc: debug_va=0x005036bc; { // 0x5036bc: e8bf971c00 CALL 0x6CCE80
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cce80u,5256897u); flags=s.arithmetic_flags;
  }
  L005036c1: debug_va=0x005036c1; { // 0x5036c1: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005036c3: debug_va=0x005036c3; { // 0x5036c3: 7529 JNZ 0x5036EE
    if(integer::condition("JNZ",flags)) goto L005036ee;
  }
  L005036c5: debug_va=0x005036c5; { // 0x5036c5: 8a44245c MOV AL, byte ptr [ESP + 0x5C]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000005cu)));
  }
  L005036c9: debug_va=0x005036c9; { // 0x5036c9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005036cb: debug_va=0x005036cb; { // 0x5036cb: 7521 JNZ 0x5036EE
    if(integer::condition("JNZ",flags)) goto L005036ee;
  }
  L005036cd: debug_va=0x005036cd; { // 0x5036cd: 8b8eb4010000 MOV ECX, dword ptr [ESI + 0x1B4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L005036d3: debug_va=0x005036d3; { // 0x5036d3: e81811ffff CALL 0x4F47F0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,5256920u); flags=s.arithmetic_flags;
  }
  L005036d8: debug_va=0x005036d8; { // 0x5036d8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005036da: debug_va=0x005036da; { // 0x5036da: 7412 JZ 0x5036EE
    if(integer::condition("JZ",flags)) goto L005036ee;
  }
  L005036dc: debug_va=0x005036dc; { // 0x5036dc: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005036de: debug_va=0x005036de; { // 0x5036de: 7526 JNZ 0x503706
    if(integer::condition("JNZ",flags)) goto L00503706;
  }
  L005036e0: debug_va=0x005036e0; { // 0x5036e0: 39aec4040000 CMP dword ptr [ESI + 0x4C4], EBP
    (void)integer::sub(m.r32((s.si+0x000004c4u)),s.bp,32,flags);
  }
  L005036e6: debug_va=0x005036e6; { // 0x5036e6: 0f84d5040000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L005036ec: debug_va=0x005036ec; { // 0x5036ec: eb04 JMP 0x5036F2
    goto L005036f2;
  }
  L005036ee: debug_va=0x005036ee; { // 0x5036ee: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005036f0: debug_va=0x005036f0; { // 0x5036f0: 7514 JNZ 0x503706
    if(integer::condition("JNZ",flags)) goto L00503706;
  }
  L005036f2: debug_va=0x005036f2; { // 0x5036f2: 8b8ea8050000 MOV ECX, dword ptr [ESI + 0x5A8]
    s.cx = m.r32((s.si+0x000005a8u));
  }
  L005036f8: debug_va=0x005036f8; { // 0x5036f8: 8a810d0c0000 MOV AL, byte ptr [ECX + 0xC0D]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000c0du)));
  }
  L005036fe: debug_va=0x005036fe; { // 0x5036fe: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503700: debug_va=0x00503700; { // 0x503700: 0f84bb040000 JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L00503706: debug_va=0x00503706; { // 0x503706: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L0050370a: debug_va=0x0050370a; { // 0x50370a: 8b15388da200 MOV EDX, dword ptr [0xA28D38]
    s.dx = m.r32((0x00a28d38u));
  }
  L00503710: debug_va=0x00503710; { // 0x503710: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00503712: debug_va=0x00503712; { // 0x503712: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00503714: debug_va=0x00503714; { // 0x503714: 894c245c MOV dword ptr [ESP + 0x5C], ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00503718: debug_va=0x00503718; { // 0x503718: 751e JNZ 0x503738
    if(integer::condition("JNZ",flags)) goto L00503738;
  }
  L0050371a: debug_va=0x0050371a; { // 0x50371a: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0050371d: debug_va=0x0050371d; { // 0x50371d: 8b0d3c8da200 MOV ECX, dword ptr [0xA28D3C]
    s.cx = m.r32((0x00a28d3cu));
  }
  L00503723: debug_va=0x00503723; { // 0x503723: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00503725: debug_va=0x00503725; { // 0x503725: 7511 JNZ 0x503738
    if(integer::condition("JNZ",flags)) goto L00503738;
  }
  L00503727: debug_va=0x00503727; { // 0x503727: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L0050372a: debug_va=0x0050372a; { // 0x50372a: 8b15408da200 MOV EDX, dword ptr [0xA28D40]
    s.dx = m.r32((0x00a28d40u));
  }
  L00503730: debug_va=0x00503730; { // 0x503730: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00503732: debug_va=0x00503732; { // 0x503732: 0f8481000000 JZ 0x5037B9
    if(integer::condition("JZ",flags)) goto L005037b9;
  }
  L00503738: debug_va=0x00503738; { // 0x503738: 8d9688000000 LEA EDX, [ESI + 0x88]
    s.dx = (s.si+0x00000088u);
  }
  L0050373e: debug_va=0x0050373e; { // 0x50373e: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00503741: debug_va=0x00503741; { // 0x503741: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00503744: debug_va=0x00503744; { // 0x503744: 8b0a MOV ECX, dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00503746: debug_va=0x00503746; { // 0x503746: 894c243c MOV dword ptr [ESP + 0x3C], ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0050374a: debug_va=0x0050374a; { // 0x50374a: db44243c FILD dword ptr [ESP + 0x3C]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0050374e: debug_va=0x0050374e; { // 0x50374e: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L00503751: debug_va=0x00503751; { // 0x503751: 894c2440 MOV dword ptr [ESP + 0x40], ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00503755: debug_va=0x00503755; { // 0x503755: da64246c FISUB dword ptr [ESP + 0x6C]
    const auto address=(f.sp+0x0000006cu);
    ra2::platform::x87_integer_subtract::subtract_integer32(s.fp,m.r32(address));
  }
  L00503759: debug_va=0x00503759; { // 0x503759: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L0050375c: debug_va=0x0050375c; { // 0x50375c: 89542444 MOV dword ptr [ESP + 0x44], EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L00503760: debug_va=0x00503760; { // 0x503760: dd5c2408 FSTP qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00503764: debug_va=0x00503764; { // 0x503764: db4004 FILD dword ptr [EAX + 4]
    const auto address=(s.ax+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00503767: debug_va=0x00503767; { // 0x503767: da642440 FISUB dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    ra2::platform::x87_integer_subtract::subtract_integer32(s.fp,m.r32(address));
  }
  L0050376b: debug_va=0x0050376b; { // 0x50376b: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0050376e: debug_va=0x0050376e; { // 0x50376e: e8fd6afbff CALL 0x4BA270
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba270u,5257075u); flags=s.arithmetic_flags;
  }
  L00503773: debug_va=0x00503773; { // 0x503773: dc2530667800 FSUB qword ptr [0x786630]
    const auto address=(0x00786630u);
    s.fp.subtract64(read64(m,address));
  }
  L00503779: debug_va=0x00503779; { // 0x503779: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0050377c: debug_va=0x0050377c; { // 0x50377c: dc0d28667800 FMUL qword ptr [0x786628]
    const auto address=(0x00786628u);
    s.fp.multiply64(read64(m,address));
  }
  L00503782: debug_va=0x00503782; { // 0x503782: e8c9722600 CALL 0x76AA50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5257095u); flags=s.arithmetic_flags;
  }
  L00503787: debug_va=0x00503787; { // 0x503787: 668944245c MOV word ptr [ESP + 0x5C], AX
    m.w16((f.sp+0x0000005cu), (s.ax & 0xffffu));
  }
  L0050378c: debug_va=0x0050378c; { // 0x50378c: a1c055a200 MOV EAX, dword ptr [0xA255C0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00503791: debug_va=0x00503791; { // 0x503791: 6a04 PUSH 4
    f.push(m,4u);
  }
  L00503793: debug_va=0x00503793; { // 0x503793: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00503794: debug_va=0x00503794; { // 0x503794: 8d8818020000 LEA ECX, [EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L0050379a: debug_va=0x0050379a; { // 0x50379a: e8a1c61200 CALL 0x62FE40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5257119u); flags=s.arithmetic_flags;
  }
  L0050379f: debug_va=0x0050379f; { // 0x50379f: 8b4c245c MOV ECX, dword ptr [ESP + 0x5C]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L005037a3: debug_va=0x005037a3; { // 0x5037a3: c1e90c SHR ECX, 0xC
    s.cx = integer::shift(s.cx,0x0000000cu,32,flags,integer::Shift::right);
  }
  L005037a6: debug_va=0x005037a6; { // 0x5037a6: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005037a7: debug_va=0x005037a7; { // 0x5037a7: d1e9 SHR ECX, 1
    s.cx = integer::shift(s.cx,1u,32,flags,integer::Shift::right);
  }
  L005037a9: debug_va=0x005037a9; { // 0x5037a9: 83e107 AND ECX, 7
    s.cx = integer::logical((s.cx)&(7u),32,flags);
  }
  L005037ac: debug_va=0x005037ac; { // 0x5037ac: 8d5408fe LEA EDX, [EAX + ECX - 2]
    s.dx = (s.ax+s.cx-2u);
  }
  L005037b0: debug_va=0x005037b0; { // 0x5037b0: 8954241c MOV dword ptr [ESP + 0x1C], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L005037b4: debug_va=0x005037b4; { // 0x5037b4: e9a9010000 JMP 0x503962
    goto L00503962;
  }
  L005037b9: debug_va=0x005037b9; { // 0x5037b9: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005037bb: debug_va=0x005037bb; { // 0x5037bb: 8d4c2444 LEA ECX, [ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L005037bf: debug_va=0x005037bf; { // 0x5037bf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005037c0: debug_va=0x005037c0; { // 0x5037c0: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005037c2: debug_va=0x005037c2; { // 0x5037c2: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5257157u); flags=s.arithmetic_flags;
  }
  L005037c5: debug_va=0x005037c5; { // 0x5037c5: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005037c7: debug_va=0x005037c7; { // 0x5037c7: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L005037c9: debug_va=0x005037c9; { // 0x5037c9: 8d442438 LEA EAX, [ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L005037cd: debug_va=0x005037cd; { // 0x5037cd: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005037cf: debug_va=0x005037cf; { // 0x5037cf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005037d0: debug_va=0x005037d0; { // 0x5037d0: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),5257171u); flags=s.arithmetic_flags;
  }
  L005037d3: debug_va=0x005037d3; { // 0x5037d3: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005037d5: debug_va=0x005037d5; { // 0x5037d5: 8b4f04 MOV ECX, dword ptr [EDI + 4]
    s.cx = m.r32((s.di+4u));
  }
  L005037d8: debug_va=0x005037d8; { // 0x5037d8: 25ff000000 AND EAX, 0xFF
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L005037dd: debug_va=0x005037dd; { // 0x5037dd: 81e1ff000000 AND ECX, 0xFF
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L005037e3: debug_va=0x005037e3; { // 0x5037e3: 3d80000000 CMP EAX, 0x80
    (void)integer::sub(s.ax,0x00000080u,32,flags);
  }
  L005037e8: debug_va=0x005037e8; { // 0x5037e8: 8944242c MOV dword ptr [ESP + 0x2C], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L005037ec: debug_va=0x005037ec; { // 0x5037ec: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L005037f0: debug_va=0x005037f0; { // 0x5037f0: 7504 JNZ 0x5037F6
    if(integer::condition("JNZ",flags)) goto L005037f6;
  }
  L005037f2: debug_va=0x005037f2; { // 0x5037f2: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005037f4: debug_va=0x005037f4; { // 0x5037f4: 7445 JZ 0x50383B
    if(integer::condition("JZ",flags)) goto L0050383b;
  }
  L005037f6: debug_va=0x005037f6; { // 0x5037f6: db44242c FILD dword ptr [ESP + 0x2C]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L005037fa: debug_va=0x005037fa; { // 0x5037fa: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L005037fd: debug_va=0x005037fd; { // 0x5037fd: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00503800: debug_va=0x00503800; { // 0x503800: dc2518667800 FSUB qword ptr [0x786618]
    const auto address=(0x00786618u);
    s.fp.subtract64(read64(m,address));
  }
  L00503806: debug_va=0x00503806; { // 0x503806: dd5c2408 FSTP qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0050380a: debug_va=0x0050380a; { // 0x50380a: db442440 FILD dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load_integer32(m.r32(address));
  }
  L0050380e: debug_va=0x0050380e; { // 0x50380e: dc2d18667800 FSUBR qword ptr [0x786618]
    const auto address=(0x00786618u);
    s.fp.reverse_subtract64(read64(m,address));
  }
  L00503814: debug_va=0x00503814; { // 0x503814: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00503817: debug_va=0x00503817; { // 0x503817: e8546afbff CALL 0x4BA270
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba270u,5257244u); flags=s.arithmetic_flags;
  }
  L0050381c: debug_va=0x0050381c; { // 0x50381c: dc2530667800 FSUB qword ptr [0x786630]
    const auto address=(0x00786630u);
    s.fp.subtract64(read64(m,address));
  }
  L00503822: debug_va=0x00503822; { // 0x503822: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00503825: debug_va=0x00503825; { // 0x503825: dc0d28667800 FMUL qword ptr [0x786628]
    const auto address=(0x00786628u);
    s.fp.multiply64(read64(m,address));
  }
  L0050382b: debug_va=0x0050382b; { // 0x50382b: e820722600 CALL 0x76AA50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5257264u); flags=s.arithmetic_flags;
  }
  L00503830: debug_va=0x00503830; { // 0x503830: 668944245c MOV word ptr [ESP + 0x5C], AX
    m.w16((f.sp+0x0000005cu), (s.ax & 0xffffu));
  }
  L00503835: debug_va=0x00503835; { // 0x503835: 8b7c245c MOV EDI, dword ptr [ESP + 0x5C]
    s.di = m.r32((f.sp+0x0000005cu));
  }
  L00503839: debug_va=0x00503839; { // 0x503839: eb12 JMP 0x50384D
    goto L0050384d;
  }
  L0050383b: debug_va=0x0050383b; { // 0x50383b: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0050383f: debug_va=0x0050383f; { // 0x50383f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00503840: debug_va=0x00503840; { // 0x503840: 8d8ee0020000 LEA ECX, [ESI + 0x2E0]
    s.cx = (s.si+0x000002e0u);
  }
  L00503846: debug_va=0x00503846; { // 0x503846: e80550fbff CALL 0x4B8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,5257291u); flags=s.arithmetic_flags;
  }
  L0050384b: debug_va=0x0050384b; { // 0x50384b: 8b38 MOV EDI, dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L0050384d: debug_va=0x0050384d; { // 0x50384d: 8b15c055a200 MOV EDX, dword ptr [0xA255C0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00503853: debug_va=0x00503853; { // 0x503853: 6a04 PUSH 4
    f.push(m,4u);
  }
  L00503855: debug_va=0x00503855; { // 0x503855: c1ef0c SHR EDI, 0xC
    s.di = integer::shift(s.di,0x0000000cu,32,flags,integer::Shift::right);
  }
  L00503858: debug_va=0x00503858; { // 0x503858: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00503859: debug_va=0x00503859; { // 0x503859: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0050385a: debug_va=0x0050385a; { // 0x50385a: d1ef SHR EDI, 1
    s.di = integer::shift(s.di,1u,32,flags,integer::Shift::right);
  }
  L0050385c: debug_va=0x0050385c; { // 0x50385c: 8d8a18020000 LEA ECX, [EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L00503862: debug_va=0x00503862; { // 0x503862: 83e707 AND EDI, 7
    s.di = integer::logical((s.di)&(7u),32,flags);
  }
  L00503865: debug_va=0x00503865; { // 0x503865: e8d6c51200 CALL 0x62FE40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5257322u); flags=s.arithmetic_flags;
  }
  L0050386a: debug_va=0x0050386a; { // 0x50386a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0050386c: debug_va=0x0050386c; { // 0x50386c: 8d4407fe LEA EAX, [EDI + EAX - 2]
    s.ax = (s.di+s.ax-2u);
  }
  L00503870: debug_va=0x00503870; { // 0x503870: 8944241c MOV dword ptr [ESP + 0x1C], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00503874: debug_va=0x00503874; { // 0x503874: 8d442444 LEA EAX, [ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00503878: debug_va=0x00503878; { // 0x503878: bf01000000 MOV EDI, 1
    s.di = 1u;
  }
  L0050387d: debug_va=0x0050387d; { // 0x50387d: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0050387f: debug_va=0x0050387f; { // 0x50387f: 66896c245c MOV word ptr [ESP + 0x5C], BP
    m.w16((f.sp+0x0000005cu), (s.bp & 0xffffu));
  }
  L00503884: debug_va=0x00503884; { // 0x503884: 66896c245e MOV word ptr [ESP + 0x5E], BP
    m.w16((f.sp+0x0000005eu), (s.bp & 0xffffu));
  }
  L00503889: debug_va=0x00503889; { // 0x503889: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050388a: debug_va=0x0050388a; { // 0x50388a: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0050388c: debug_va=0x0050388c; { // 0x50388c: 8bef MOV EBP, EDI
    s.bp = s.di;
  }
  L0050388e: debug_va=0x0050388e; { // 0x50388e: ff524c CALL dword ptr [EDX + 0x4C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000004cu)),5257361u); flags=s.arithmetic_flags;
  }
  L00503891: debug_va=0x00503891; { // 0x503891: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00503893: debug_va=0x00503893; { // 0x503893: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00503895: debug_va=0x00503895; { // 0x503895: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00503897: debug_va=0x00503897; { // 0x503897: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00503898: debug_va=0x00503898; { // 0x503898: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0050389e: debug_va=0x0050389e; { // 0x50389e: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005038a0: debug_va=0x005038a0; { // 0x5038a0: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005038a3: debug_va=0x005038a3; { // 0x5038a3: 6689442460 MOV word ptr [ESP + 0x60], AX
    m.w16((f.sp+0x00000060u), (s.ax & 0xffffu));
  }
  L005038a8: debug_va=0x005038a8; { // 0x5038a8: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L005038ab: debug_va=0x005038ab; { // 0x5038ab: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005038ac: debug_va=0x005038ac; { // 0x5038ac: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005038b2: debug_va=0x005038b2; { // 0x5038b2: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005038b4: debug_va=0x005038b4; { // 0x5038b4: 8d54245c LEA EDX, [ESP + 0x5C]
    s.dx = (f.sp+0x0000005cu);
  }
  L005038b8: debug_va=0x005038b8; { // 0x5038b8: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005038bb: debug_va=0x005038bb; { // 0x5038bb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005038bc: debug_va=0x005038bc; { // 0x5038bc: 6689442466 MOV word ptr [ESP + 0x66], AX
    m.w16((f.sp+0x00000066u), (s.ax & 0xffffu));
  }
  L005038c1: debug_va=0x005038c1; { // 0x5038c1: 8b4c2464 MOV ECX, dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L005038c5: debug_va=0x005038c5; { // 0x5038c5: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L005038c8: debug_va=0x005038c8; { // 0x5038c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005038c9: debug_va=0x005038c9; { // 0x5038c9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005038cb: debug_va=0x005038cb; { // 0x5038cb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005038cc: debug_va=0x005038cc; { // 0x5038cc: 894c2468 MOV dword ptr [ESP + 0x68], ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L005038d0: debug_va=0x005038d0; { // 0x5038d0: 8b8ea8050000 MOV ECX, dword ptr [ESI + 0x5A8]
    s.cx = m.r32((s.si+0x000005a8u));
  }
  L005038d6: debug_va=0x005038d6; { // 0x5038d6: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005038d8: debug_va=0x005038d8; { // 0x5038d8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005038d9: debug_va=0x005038d9; { // 0x5038d9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005038da: debug_va=0x005038da; { // 0x5038da: 8b91a4050000 MOV EDX, dword ptr [ECX + 0x5A4]
    s.dx = m.r32((s.cx+0x000005a4u));
  }
  L005038e0: debug_va=0x005038e0; { // 0x5038e0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005038e1: debug_va=0x005038e1; { // 0x5038e1: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005038e3: debug_va=0x005038e3; { // 0x5038e3: 6aff PUSH -1
    f.push(m,4294967295u);
  }
  L005038e5: debug_va=0x005038e5; { // 0x5038e5: 8d842480000000 LEA EAX, [ESP + 0x80]
    s.ax = (f.sp+0x00000080u);
  }
  L005038ec: debug_va=0x005038ec; { // 0x5038ec: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005038ed: debug_va=0x005038ed; { // 0x5038ed: 8d4c2454 LEA ECX, [ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L005038f1: debug_va=0x005038f1; { // 0x5038f1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005038f2: debug_va=0x005038f2; { // 0x5038f2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005038f3: debug_va=0x005038f3; { // 0x5038f3: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L005038f8: debug_va=0x005038f8; { // 0x5038f8: e8739e0400 CALL 0x54D770
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d770u,5257469u); flags=s.arithmetic_flags;
  }
  L005038fd: debug_va=0x005038fd; { // 0x5038fd: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L005038ff: debug_va=0x005038ff; { // 0x5038ff: 663b05188da200 CMP AX, word ptr [0xA28D18]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a28d18u)),16,flags);
  }
  L00503906: debug_va=0x00503906; { // 0x503906: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0050390a: debug_va=0x0050390a; { // 0x50390a: 750e JNZ 0x50391A
    if(integer::condition("JNZ",flags)) goto L0050391a;
  }
  L0050390c: debug_va=0x0050390c; { // 0x50390c: 668b54241a MOV DX, word ptr [ESP + 0x1A]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000001au)));
  }
  L00503911: debug_va=0x00503911; { // 0x503911: 663b151a8da200 CMP DX, word ptr [0xA28D1A]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a28d1au)),16,flags);
  }
  L00503918: debug_va=0x00503918; { // 0x503918: 7446 JZ 0x503960
    if(integer::condition("JZ",flags)) goto L00503960;
  }
  L0050391a: debug_va=0x0050391a; { // 0x50391a: 8b3e MOV EDI, dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L0050391c: debug_va=0x0050391c; { // 0x50391c: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00503920: debug_va=0x00503920; { // 0x503920: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00503922: debug_va=0x00503922; { // 0x503922: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503923: debug_va=0x00503923; { // 0x503923: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00503928: debug_va=0x00503928; { // 0x503928: e8d31b0400 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5257517u); flags=s.arithmetic_flags;
  }
  L0050392d: debug_va=0x0050392d; { // 0x50392d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050392e: debug_va=0x0050392e; { // 0x50392e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503930: debug_va=0x00503930; { // 0x503930: ff9710040000 CALL dword ptr [EDI + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.di+0x00000410u)),5257526u); flags=s.arithmetic_flags;
  }
  L00503936: debug_va=0x00503936; { // 0x503936: 8b8664050000 MOV EAX, dword ptr [ESI + 0x564]
    s.ax = m.r32((s.si+0x00000564u));
  }
  L0050393c: debug_va=0x0050393c; { // 0x50393c: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050393e: debug_va=0x0050393e; { // 0x50393e: 750a JNZ 0x50394A
    if(integer::condition("JNZ",flags)) goto L0050394a;
  }
  L00503940: debug_va=0x00503940; { // 0x503940: 6803400080 PUSH 0x80004003
    f.push(m,0x80004003u);
  }
  L00503945: debug_va=0x00503945; { // 0x503945: e826d92700 CALL 0x781270
    s.arithmetic_flags=flags; invoke(m,s,f,0x00781270u,5257546u); flags=s.arithmetic_flags;
  }
  L0050394a: debug_va=0x0050394a; { // 0x50394a: 8bb664050000 MOV ESI, dword ptr [ESI + 0x564]
    s.si = m.r32((s.si+0x00000564u));
  }
  L00503950: debug_va=0x00503950; { // 0x503950: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00503951: debug_va=0x00503951; { // 0x503951: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00503953: debug_va=0x00503953; { // 0x503953: ff5140 CALL dword ptr [ECX + 0x40]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000040u)),5257558u); flags=s.arithmetic_flags;
  }
  L00503956: debug_va=0x00503956; { // 0x503956: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00503957: debug_va=0x00503957; { // 0x503957: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00503958: debug_va=0x00503958; { // 0x503958: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00503959: debug_va=0x00503959; { // 0x503959: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0050395a: debug_va=0x0050395a; { // 0x50395a: 83c440 ADD ESP, 0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L0050395d: debug_va=0x0050395d; { // 0x50395d: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00503960: debug_va=0x00503960; { // 0x503960: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00503962: debug_va=0x00503962; { // 0x503962: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00503964: debug_va=0x00503964; { // 0x503964: 8d442444 LEA EAX, [ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00503968: debug_va=0x00503968; { // 0x503968: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00503969: debug_va=0x00503969; { // 0x503969: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050396a: debug_va=0x0050396a; { // 0x50396a: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0050396c: debug_va=0x0050396c; { // 0x50396c: 66896c245c MOV word ptr [ESP + 0x5C], BP
    m.w16((f.sp+0x0000005cu), (s.bp & 0xffffu));
  }
  L00503971: debug_va=0x00503971; { // 0x503971: 66896c245e MOV word ptr [ESP + 0x5E], BP
    m.w16((f.sp+0x0000005eu), (s.bp & 0xffffu));
  }
  L00503976: debug_va=0x00503976; { // 0x503976: 66896c2460 MOV word ptr [ESP + 0x60], BP
    m.w16((f.sp+0x00000060u), (s.bp & 0xffffu));
  }
  L0050397b: debug_va=0x0050397b; { // 0x50397b: 66896c2462 MOV word ptr [ESP + 0x62], BP
    m.w16((f.sp+0x00000062u), (s.bp & 0xffffu));
  }
  L00503980: debug_va=0x00503980; { // 0x503980: ff524c CALL dword ptr [EDX + 0x4C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000004cu)),5257603u); flags=s.arithmetic_flags;
  }
  L00503983: debug_va=0x00503983; { // 0x503983: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00503985: debug_va=0x00503985; { // 0x503985: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00503987: debug_va=0x00503987; { // 0x503987: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00503988: debug_va=0x00503988; { // 0x503988: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0050398e: debug_va=0x0050398e; { // 0x50398e: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00503990: debug_va=0x00503990; { // 0x503990: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L00503993: debug_va=0x00503993; { // 0x503993: 668944245c MOV word ptr [ESP + 0x5C], AX
    m.w16((f.sp+0x0000005cu), (s.ax & 0xffffu));
  }
  L00503998: debug_va=0x00503998; { // 0x503998: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0050399b: debug_va=0x0050399b; { // 0x50399b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0050399c: debug_va=0x0050399c; { // 0x50399c: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005039a2: debug_va=0x005039a2; { // 0x5039a2: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005039a4: debug_va=0x005039a4; { // 0x5039a4: 8d542410 LEA EDX, [ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L005039a8: debug_va=0x005039a8; { // 0x5039a8: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005039ab: debug_va=0x005039ab; { // 0x5039ab: 668944245e MOV word ptr [ESP + 0x5E], AX
    m.w16((f.sp+0x0000005eu), (s.ax & 0xffffu));
  }
  L005039b0: debug_va=0x005039b0; { // 0x5039b0: 8b4c245c MOV ECX, dword ptr [ESP + 0x5C]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L005039b4: debug_va=0x005039b4; { // 0x5039b4: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005039b8: debug_va=0x005039b8; { // 0x5039b8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005039b9: debug_va=0x005039b9; { // 0x5039b9: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L005039be: debug_va=0x005039be; { // 0x5039be: e83d1b0400 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5257667u); flags=s.arithmetic_flags;
  }
  L005039c3: debug_va=0x005039c3; { // 0x5039c3: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L005039c5: debug_va=0x005039c5; { // 0x5039c5: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005039c7: debug_va=0x005039c7; { // 0x5039c7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005039c8: debug_va=0x005039c8; { // 0x5039c8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005039ca: debug_va=0x005039ca; { // 0x5039ca: ff90b8000000 CALL dword ptr [EAX + 0xB8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000b8u)),5257680u); flags=s.arithmetic_flags;
  }
  L005039d0: debug_va=0x005039d0; { // 0x5039d0: 0fbe8f1b010000 MOVSX ECX, byte ptr [EDI + 0x11B]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x0000011bu)),8));
  }
  L005039d7: debug_va=0x005039d7; { // 0x5039d7: 25ff000000 AND EAX, 0xFF
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L005039dc: debug_va=0x005039dc; { // 0x5039dc: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005039de: debug_va=0x005039de; { // 0x5039de: 03c1 ADD EAX, ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005039e0: debug_va=0x005039e0; { // 0x5039e0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005039e1: debug_va=0x005039e1; { // 0x5039e1: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L005039e3: debug_va=0x005039e3; { // 0x5039e3: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L005039e5: debug_va=0x005039e5; { // 0x5039e5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005039e7: debug_va=0x005039e7; { // 0x5039e7: 83e004 AND EAX, 4
    s.ax = integer::logical((s.ax)&(4u),32,flags);
  }
  L005039ea: debug_va=0x005039ea; { // 0x5039ea: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L005039ec: debug_va=0x005039ec; { // 0x5039ec: 8d442448 LEA EAX, [ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L005039f0: debug_va=0x005039f0; { // 0x5039f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005039f1: debug_va=0x005039f1; { // 0x5039f1: ff524c CALL dword ptr [EDX + 0x4C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000004cu)),5257716u); flags=s.arithmetic_flags;
  }
  L005039f4: debug_va=0x005039f4; { // 0x5039f4: a1708da200 MOV EAX, dword ptr [0xA28D70]
    s.ax = m.r32((0x00a28d70u));
  }
  L005039f9: debug_va=0x005039f9; { // 0x5039f9: 0fafc7 IMUL EAX, EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  L005039fc: debug_va=0x005039fc; { // 0x5039fc: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L005039fe: debug_va=0x005039fe; { // 0x5039fe: 8944244c MOV dword ptr [ESP + 0x4C], EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00503a02: debug_va=0x00503a02; { // 0x503a02: 897c2424 MOV dword ptr [ESP + 0x24], EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L00503a06: debug_va=0x00503a06; { // 0x503a06: 8b4c241c MOV ECX, dword ptr [ESP + 0x1C]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00503a0a: debug_va=0x00503a0a; { // 0x503a0a: 03f9 ADD EDI, ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L00503a0c: debug_va=0x00503a0c; { // 0x503a0c: 668b4c2410 MOV CX, word ptr [ESP + 0x10]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000010u)));
  }
  L00503a11: debug_va=0x00503a11; { // 0x503a11: 83e707 AND EDI, 7
    s.di = integer::logical((s.di)&(7u),32,flags);
  }
  L00503a14: debug_va=0x00503a14; { // 0x503a14: 8bd7 MOV EDX, EDI
    s.dx = s.di;
  }
  L00503a16: debug_va=0x00503a16; { // 0x503a16: 83e207 AND EDX, 7
    s.dx = integer::logical((s.dx)&(7u),32,flags);
  }
  L00503a19: debug_va=0x00503a19; { // 0x503a19: 66030c95a09d8300 ADD CX, word ptr [EDX*4 + 0x839DA0]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16(((s.dx * 4u)+0x00839da0u)),16,flags));
  }
  L00503a21: debug_va=0x00503a21; { // 0x503a21: 8d0495a09d8300 LEA EAX, [EDX*4 + 0x839DA0]
    s.ax = ((s.dx * 4u)+0x00839da0u);
  }
  L00503a28: debug_va=0x00503a28; { // 0x503a28: 668b1495a29d8300 MOV DX, word ptr [EDX*4 + 0x839DA2]
    s.dx = with_ax(s.dx, m.r16(((s.dx * 4u)+0x00839da2u)));
  }
  L00503a30: debug_va=0x00503a30; { // 0x503a30: 66894c2420 MOV word ptr [ESP + 0x20], CX
    m.w16((f.sp+0x00000020u), (s.cx & 0xffffu));
  }
  L00503a35: debug_va=0x00503a35; { // 0x503a35: 6603542412 ADD DX, word ptr [ESP + 0x12]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  L00503a3a: debug_va=0x00503a3a; { // 0x503a3a: 8d4c245c LEA ECX, [ESP + 0x5C]
    s.cx = (f.sp+0x0000005cu);
  }
  L00503a3e: debug_va=0x00503a3e; { // 0x503a3e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00503a3f: debug_va=0x00503a3f; { // 0x503a3f: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00503a44: debug_va=0x00503a44; { // 0x503a44: 6689542426 MOV word ptr [ESP + 0x26], DX
    m.w16((f.sp+0x00000026u), (s.dx & 0xffffu));
  }
  L00503a49: debug_va=0x00503a49; { // 0x503a49: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00503a4d: debug_va=0x00503a4d; { // 0x503a4d: 89442460 MOV dword ptr [ESP + 0x60], EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L00503a51: debug_va=0x00503a51; { // 0x503a51: e8aa1a0400 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5257814u); flags=s.arithmetic_flags;
  }
  L00503a56: debug_va=0x00503a56; { // 0x503a56: 8d54245c LEA EDX, [ESP + 0x5C]
    s.dx = (f.sp+0x0000005cu);
  }
  L00503a5a: debug_va=0x00503a5a; { // 0x503a5a: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00503a5c: debug_va=0x00503a5c; { // 0x503a5c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00503a5d: debug_va=0x00503a5d; { // 0x503a5d: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00503a62: debug_va=0x00503a62; { // 0x503a62: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L00503a64: debug_va=0x00503a64; { // 0x503a64: e8e7390500 CALL 0x557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5257833u); flags=s.arithmetic_flags;
  }
  L00503a69: debug_va=0x00503a69; { // 0x503a69: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503a6b: debug_va=0x00503a6b; { // 0x503a6b: 0f84c8000000 JZ 0x503B39
    if(integer::condition("JZ",flags)) goto L00503b39;
  }
  L00503a71: debug_va=0x00503a71; { // 0x503a71: 8b1e MOV EBX, dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L00503a73: debug_va=0x00503a73; { // 0x503a73: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00503a75: debug_va=0x00503a75; { // 0x503a75: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00503a77: debug_va=0x00503a77; { // 0x503a77: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503a79: debug_va=0x00503a79; { // 0x503a79: e8e2930c00 CALL 0x5CCE60
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cce60u,5257854u); flags=s.arithmetic_flags;
  }
  L00503a7e: debug_va=0x00503a7e; { // 0x503a7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503a7f: debug_va=0x00503a7f; { // 0x503a7f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00503a80: debug_va=0x00503a80; { // 0x503a80: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00503a81: debug_va=0x00503a81; { // 0x503a81: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503a83: debug_va=0x00503a83; { // 0x503a83: ff9394010000 CALL dword ptr [EBX + 0x194]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000194u)),5257865u); flags=s.arithmetic_flags;
  }
  L00503a89: debug_va=0x00503a89; { // 0x503a89: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00503a8b: debug_va=0x00503a8b; { // 0x503a8b: 0f85a8000000 JNZ 0x503B39
    if(integer::condition("JNZ",flags)) goto L00503b39;
  }
  L00503a91: debug_va=0x00503a91; { // 0x503a91: 8b0d188da200 MOV ECX, dword ptr [0xA28D18]
    s.cx = m.r32((0x00a28d18u));
  }
  L00503a97: debug_va=0x00503a97; { // 0x503a97: 668b151a8da200 MOV DX, word ptr [0xA28D1A]
    s.dx = with_ax(s.dx, m.r16((0x00a28d1au)));
  }
  L00503a9e: debug_va=0x00503a9e; { // 0x503a9e: 66394c2454 CMP word ptr [ESP + 0x54], CX
    (void)integer::sub(m.r16((f.sp+0x00000054u)),(s.cx & 0xffffu),16,flags);
  }
  L00503aa3: debug_va=0x00503aa3; { // 0x503aa3: 8b44245c MOV EAX, dword ptr [ESP + 0x5C]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L00503aa7: debug_va=0x00503aa7; { // 0x503aa7: 750b JNZ 0x503AB4
    if(integer::condition("JNZ",flags)) goto L00503ab4;
  }
  L00503aa9: debug_va=0x00503aa9; { // 0x503aa9: 6639542456 CMP word ptr [ESP + 0x56], DX
    (void)integer::sub(m.r16((f.sp+0x00000056u)),(s.dx & 0xffffu),16,flags);
  }
  L00503aae: debug_va=0x00503aae; { // 0x503aae: 7504 JNZ 0x503AB4
    if(integer::condition("JNZ",flags)) goto L00503ab4;
  }
  L00503ab0: debug_va=0x00503ab0; { // 0x503ab0: 89442454 MOV dword ptr [ESP + 0x54], EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00503ab4: debug_va=0x00503ab4; { // 0x503ab4: 6685c9 TEST CX, CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  L00503ab7: debug_va=0x00503ab7; { // 0x503ab7: 0f8589000000 JNZ 0x503B46
    if(integer::condition("JNZ",flags)) goto L00503b46;
  }
  L00503abd: debug_va=0x00503abd; { // 0x503abd: 6685d2 TEST DX, DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L00503ac0: debug_va=0x00503ac0; { // 0x503ac0: 0f8580000000 JNZ 0x503B46
    if(integer::condition("JNZ",flags)) goto L00503b46;
  }
  L00503ac6: debug_va=0x00503ac6; { // 0x503ac6: 0fbf4c245e MOVSX ECX, word ptr [ESP + 0x5E]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000005eu)),16));
  }
  L00503acb: debug_va=0x00503acb; { // 0x503acb: 0fbfc0 MOVSX EAX, AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00503ace: debug_va=0x00503ace; { // 0x503ace: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L00503ad1: debug_va=0x00503ad1; { // 0x503ad1: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L00503ad4: debug_va=0x00503ad4; { // 0x503ad4: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L00503ada: debug_va=0x00503ada; { // 0x503ada: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00503adc: debug_va=0x00503adc; { // 0x503adc: 0580000000 ADD EAX, 0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L00503ae1: debug_va=0x00503ae1; { // 0x503ae1: 894c243c MOV dword ptr [ESP + 0x3C], ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L00503ae5: debug_va=0x00503ae5; { // 0x503ae5: 89542440 MOV dword ptr [ESP + 0x40], EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00503ae9: debug_va=0x00503ae9; { // 0x503ae9: 8d4c2438 LEA ECX, [ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L00503aed: debug_va=0x00503aed; { // 0x503aed: 89442438 MOV dword ptr [ESP + 0x38], EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00503af1: debug_va=0x00503af1; { // 0x503af1: 8b44244c MOV EAX, dword ptr [ESP + 0x4C]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00503af5: debug_va=0x00503af5; { // 0x503af5: 8d54242c LEA EDX, [ESP + 0x2C]
    s.dx = (f.sp+0x0000002cu);
  }
  L00503af9: debug_va=0x00503af9; { // 0x503af9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00503afa: debug_va=0x00503afa; { // 0x503afa: 8b0dac1c8200 MOV ECX, dword ptr [0x821CAC]
    s.cx = m.r32((0x00821cacu));
  }
  L00503b00: debug_va=0x00503b00; { // 0x503b00: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00503b01: debug_va=0x00503b01; { // 0x503b01: 89442448 MOV dword ptr [ESP + 0x48], EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L00503b05: debug_va=0x00503b05; { // 0x503b05: e886851900 CALL 0x69C090
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c090u,5257994u); flags=s.arithmetic_flags;
  }
  L00503b0a: debug_va=0x00503b0a; { // 0x503b0a: 668b4c245c MOV CX, word ptr [ESP + 0x5C]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000005cu)));
  }
  L00503b0f: debug_va=0x00503b0f; { // 0x503b0f: 663b08 CMP CX, word ptr [EAX]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.ax)),16,flags);
  }
  L00503b12: debug_va=0x00503b12; { // 0x503b12: 7525 JNZ 0x503B39
    if(integer::condition("JNZ",flags)) goto L00503b39;
  }
  L00503b14: debug_va=0x00503b14; { // 0x503b14: 668b54245e MOV DX, word ptr [ESP + 0x5E]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000005eu)));
  }
  L00503b19: debug_va=0x00503b19; { // 0x503b19: 663b5002 CMP DX, word ptr [EAX + 2]
    (void)integer::sub((s.dx & 0xffffu),m.r16((s.ax+2u)),16,flags);
  }
  L00503b1d: debug_va=0x00503b1d; { // 0x503b1d: 751a JNZ 0x503B39
    if(integer::condition("JNZ",flags)) goto L00503b39;
  }
  L00503b1f: debug_va=0x00503b1f; { // 0x503b1f: 8d44245c LEA EAX, [ESP + 0x5C]
    s.ax = (f.sp+0x0000005cu);
  }
  L00503b23: debug_va=0x00503b23; { // 0x503b23: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00503b28: debug_va=0x00503b28; { // 0x503b28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503b29: debug_va=0x00503b29; { // 0x503b29: e8d2190400 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5258030u); flags=s.arithmetic_flags;
  }
  L00503b2e: debug_va=0x00503b2e; { // 0x503b2e: 8b8840010000 MOV ECX, dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L00503b34: debug_va=0x00503b34; { // 0x503b34: f6c501 TEST CH, 1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(1u),8,flags);
  }
  L00503b37: debug_va=0x00503b37; { // 0x503b37: 7421 JZ 0x503B5A
    if(integer::condition("JZ",flags)) goto L00503b5a;
  }
  L00503b39: debug_va=0x00503b39; { // 0x503b39: 8b0d188da200 MOV ECX, dword ptr [0xA28D18]
    s.cx = m.r32((0x00a28d18u));
  }
  L00503b3f: debug_va=0x00503b3f; { // 0x503b3f: 668b151a8da200 MOV DX, word ptr [0xA28D1A]
    s.dx = with_ax(s.dx, m.r16((0x00a28d1au)));
  }
  L00503b46: debug_va=0x00503b46; { // 0x503b46: 8b7c2424 MOV EDI, dword ptr [ESP + 0x24]
    s.di = m.r32((f.sp+0x00000024u));
  }
  L00503b4a: debug_va=0x00503b4a; { // 0x503b4a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00503b4b: debug_va=0x00503b4b; { // 0x503b4b: 83ff08 CMP EDI, 8
    (void)integer::sub(s.di,8u,32,flags);
  }
  L00503b4e: debug_va=0x00503b4e; { // 0x503b4e: 897c2424 MOV dword ptr [ESP + 0x24], EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L00503b52: debug_va=0x00503b52; { // 0x503b52: 0f8caefeffff JL 0x503A06
    if(integer::condition("JL",flags)) goto L00503a06;
  }
  L00503b58: debug_va=0x00503b58; { // 0x503b58: eb15 JMP 0x503B6F
    goto L00503b6f;
  }
  L00503b5a: debug_va=0x00503b5a; { // 0x503b5a: 8b4c245c MOV ECX, dword ptr [ESP + 0x5C]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00503b5e: debug_va=0x00503b5e; { // 0x503b5e: 668b151a8da200 MOV DX, word ptr [0xA28D1A]
    s.dx = with_ax(s.dx, m.r16((0x00a28d1au)));
  }
  L00503b65: debug_va=0x00503b65; { // 0x503b65: 894c2458 MOV dword ptr [ESP + 0x58], ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L00503b69: debug_va=0x00503b69; { // 0x503b69: 8b0d188da200 MOV ECX, dword ptr [0xA28D18]
    s.cx = m.r32((0x00a28d18u));
  }
  L00503b6f: debug_va=0x00503b6f; { // 0x503b6f: 8b442458 MOV EAX, dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00503b73: debug_va=0x00503b73; { // 0x503b73: 663bc1 CMP AX, CX
    (void)integer::sub((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags);
  }
  L00503b76: debug_va=0x00503b76; { // 0x503b76: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00503b7a: debug_va=0x00503b7a; { // 0x503b7a: 751b JNZ 0x503B97
    if(integer::condition("JNZ",flags)) goto L00503b97;
  }
  L00503b7c: debug_va=0x00503b7c; { // 0x503b7c: 663954245a CMP word ptr [ESP + 0x5A], DX
    (void)integer::sub(m.r16((f.sp+0x0000005au)),(s.dx & 0xffffu),16,flags);
  }
  L00503b81: debug_va=0x00503b81; { // 0x503b81: 7508 JNZ 0x503B8B
    if(integer::condition("JNZ",flags)) goto L00503b8b;
  }
  L00503b83: debug_va=0x00503b83; { // 0x503b83: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00503b87: debug_va=0x00503b87; { // 0x503b87: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00503b8b: debug_va=0x00503b8b; { // 0x503b8b: 663bc1 CMP AX, CX
    (void)integer::sub((s.ax & 0xffffu),(s.cx & 0xffffu),16,flags);
  }
  L00503b8e: debug_va=0x00503b8e; { // 0x503b8e: 7507 JNZ 0x503B97
    if(integer::condition("JNZ",flags)) goto L00503b97;
  }
  L00503b90: debug_va=0x00503b90; { // 0x503b90: 6639542416 CMP word ptr [ESP + 0x16], DX
    (void)integer::sub(m.r16((f.sp+0x00000016u)),(s.dx & 0xffffu),16,flags);
  }
  L00503b95: debug_va=0x00503b95; { // 0x503b95: 742a JZ 0x503BC1
    if(integer::condition("JZ",flags)) goto L00503bc1;
  }
  L00503b97: debug_va=0x00503b97; { // 0x503b97: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00503b99: debug_va=0x00503b99; { // 0x503b99: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00503b9b: debug_va=0x00503b9b; { // 0x503b9b: 6a02 PUSH 2
    f.push(m,2u);
  }
  L00503b9d: debug_va=0x00503b9d; { // 0x503b9d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503b9f: debug_va=0x00503b9f; { // 0x503b9f: ff92d0010000 CALL dword ptr [EDX + 0x1D0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001d0u)),5258149u); flags=s.arithmetic_flags;
  }
  L00503ba5: debug_va=0x00503ba5; { // 0x503ba5: 8b3e MOV EDI, dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L00503ba7: debug_va=0x00503ba7; { // 0x503ba7: 8d442414 LEA EAX, [ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00503bab: debug_va=0x00503bab; { // 0x503bab: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00503bad: debug_va=0x00503bad; { // 0x503bad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503bae: debug_va=0x00503bae; { // 0x503bae: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00503bb3: debug_va=0x00503bb3; { // 0x503bb3: e848190400 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5258168u); flags=s.arithmetic_flags;
  }
  L00503bb8: debug_va=0x00503bb8; { // 0x503bb8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503bb9: debug_va=0x00503bb9; { // 0x503bb9: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503bbb: debug_va=0x00503bbb; { // 0x503bbb: ff9710040000 CALL dword ptr [EDI + 0x410]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.di+0x00000410u)),5258177u); flags=s.arithmetic_flags;
  }
  L00503bc1: debug_va=0x00503bc1; { // 0x503bc1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00503bc2: debug_va=0x00503bc2; { // 0x503bc2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00503bc3: debug_va=0x00503bc3; { // 0x503bc3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00503bc4: debug_va=0x00503bc4; { // 0x503bc4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00503bc5: debug_va=0x00503bc5; { // 0x503bc5: 83c440 ADD ESP, 0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L00503bc8: debug_va=0x00503bc8; { // 0x503bc8: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00103bd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00503bd0: debug_va=0x00503bd0; { // 0x503bd0: 83ec0c SUB ESP, 0xC
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00503bd3: debug_va=0x00503bd3; { // 0x503bd3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00503bd4: debug_va=0x00503bd4; { // 0x503bd4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00503bd5: debug_va=0x00503bd5; { // 0x503bd5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00503bd6: debug_va=0x00503bd6; { // 0x503bd6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00503bd7: debug_va=0x00503bd7; { // 0x503bd7: 8b7c2420 MOV EDI, dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00503bdb: debug_va=0x00503bdb; { // 0x503bdb: 83cbff OR EBX, 0xFFFFFFFF
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  L00503bde: debug_va=0x00503bde; { // 0x503bde: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00503be0: debug_va=0x00503be0; { // 0x503be0: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00503be2: debug_va=0x00503be2; { // 0x503be2: 0f846e030000 JZ 0x503F56
    if(integer::condition("JZ",flags)) goto L00503f56;
  }
  L00503be8: debug_va=0x00503be8; { // 0x503be8: 8b86a8050000 MOV EAX, dword ptr [ESI + 0x5A8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  L00503bee: debug_va=0x00503bee; { // 0x503bee: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L00503bf0: debug_va=0x00503bf0; { // 0x503bf0: c1e104 SHL ECX, 4
    s.cx = integer::shift(s.cx,4u,32,flags,integer::Shift::left);
  }
  L00503bf3: debug_va=0x00503bf3; { // 0x503bf3: 8b90980b0000 MOV EDX, dword ptr [EAX + 0xB98]
    s.dx = m.r32((s.ax+0x00000b98u));
  }
  L00503bf9: debug_va=0x00503bf9; { // 0x503bf9: 8b6c0a04 MOV EBP, dword ptr [EDX + ECX + 4]
    s.bp = m.r32((s.dx+s.cx+4u));
  }
  L00503bfd: debug_va=0x00503bfd; { // 0x503bfd: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00503bff: debug_va=0x00503bff; { // 0x503bff: 0f8451030000 JZ 0x503F56
    if(integer::condition("JZ",flags)) goto L00503f56;
  }
  L00503c05: debug_va=0x00503c05; { // 0x503c05: 83beac05000021 CMP dword ptr [ESI + 0x5AC], 0x21
    (void)integer::sub(m.r32((s.si+0x000005acu)),0x00000021u,32,flags);
  }
  L00503c0c: debug_va=0x00503c0c; { // 0x503c0c: 750b JNZ 0x503C19
    if(integer::condition("JNZ",flags)) goto L00503c19;
  }
  L00503c0e: debug_va=0x00503c0e; { // 0x503c0e: 8a4e7a MOV CL, byte ptr [ESI + 0x7A]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000007au)));
  }
  L00503c11: debug_va=0x00503c11; { // 0x503c11: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00503c13: debug_va=0x00503c13; { // 0x503c13: 0f853d030000 JNZ 0x503F56
    if(integer::condition("JNZ",flags)) goto L00503f56;
  }
  L00503c19: debug_va=0x00503c19; { // 0x503c19: 83b80005000003 CMP dword ptr [EAX + 0x500], 3
    (void)integer::sub(m.r32((s.ax+0x00000500u)),3u,32,flags);
  }
  L00503c20: debug_va=0x00503c20; { // 0x503c20: 0f8514010000 JNZ 0x503D3A
    if(integer::condition("JNZ",flags)) goto L00503d3a;
  }
  L00503c26: debug_va=0x00503c26; { // 0x503c26: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00503c28: debug_va=0x00503c28; { // 0x503c28: 8d4c2420 LEA ECX, [ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00503c2c: debug_va=0x00503c2c; { // 0x503c2c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00503c2d: debug_va=0x00503c2d; { // 0x503c2d: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503c2f: debug_va=0x00503c2f; { // 0x503c2f: ff90a0010000 CALL dword ptr [EAX + 0x1A0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),5258293u); flags=s.arithmetic_flags;
  }
  L00503c35: debug_va=0x00503c35; { // 0x503c35: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503c36: debug_va=0x00503c36; { // 0x503c36: b920a88100 MOV ECX, 0x81A820
    s.cx = 0x0081a820u;
  }
  L00503c3b: debug_va=0x00503c3b; { // 0x503c3b: e8c0180400 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5258304u); flags=s.arithmetic_flags;
  }
  L00503c40: debug_va=0x00503c40; { // 0x503c40: 8b80ec000000 MOV EAX, dword ptr [EAX + 0xEC]
    s.ax = m.r32((s.ax+0x000000ecu));
  }
  L00503c46: debug_va=0x00503c46; { // 0x503c46: bd01000000 MOV EBP, 1
    s.bp = 1u;
  }
  L00503c4b: debug_va=0x00503c4b; { // 0x503c4b: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L00503c4e: debug_va=0x00503c4e; { // 0x503c4e: 7405 JZ 0x503C55
    if(integer::condition("JZ",flags)) goto L00503c55;
  }
  L00503c50: debug_va=0x00503c50; { // 0x503c50: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L00503c53: debug_va=0x00503c53; { // 0x503c53: 7569 JNZ 0x503CBE
    if(integer::condition("JNZ",flags)) goto L00503cbe;
  }
  L00503c55: debug_va=0x00503c55; { // 0x503c55: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L00503c58: debug_va=0x00503c58; { // 0x503c58: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503c5a: debug_va=0x00503c5a; { // 0x503c5a: 7562 JNZ 0x503CBE
    if(integer::condition("JNZ",flags)) goto L00503cbe;
  }
  L00503c5c: debug_va=0x00503c5c; { // 0x503c5c: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00503c5e: debug_va=0x00503c5e; { // 0x503c5e: 83ff03 CMP EDI, 3
    (void)integer::sub(s.di,3u,32,flags);
  }
  L00503c61: debug_va=0x00503c61; { // 0x503c61: 7456 JZ 0x503CB9
    if(integer::condition("JZ",flags)) goto L00503cb9;
  }
  L00503c63: debug_va=0x00503c63; { // 0x503c63: 83ff06 CMP EDI, 6
    (void)integer::sub(s.di,6u,32,flags);
  }
  L00503c66: debug_va=0x00503c66; { // 0x503c66: 7451 JZ 0x503CB9
    if(integer::condition("JZ",flags)) goto L00503cb9;
  }
  L00503c68: debug_va=0x00503c68; { // 0x503c68: 83ff02 CMP EDI, 2
    (void)integer::sub(s.di,2u,32,flags);
  }
  L00503c6b: debug_va=0x00503c6b; { // 0x503c6b: 7445 JZ 0x503CB2
    if(integer::condition("JZ",flags)) goto L00503cb2;
  }
  L00503c6d: debug_va=0x00503c6d; { // 0x503c6d: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00503c6f: debug_va=0x00503c6f; { // 0x503c6f: 7441 JZ 0x503CB2
    if(integer::condition("JZ",flags)) goto L00503cb2;
  }
  L00503c71: debug_va=0x00503c71; { // 0x503c71: 83ff09 CMP EDI, 9
    (void)integer::sub(s.di,9u,32,flags);
  }
  L00503c74: debug_va=0x00503c74; { // 0x503c74: 7507 JNZ 0x503C7D
    if(integer::condition("JNZ",flags)) goto L00503c7d;
  }
  L00503c76: debug_va=0x00503c76; { // 0x503c76: bf12000000 MOV EDI, 0x12
    s.di = 0x00000012u;
  }
  L00503c7b: debug_va=0x00503c7b; { // 0x503c7b: eb41 JMP 0x503CBE
    goto L00503cbe;
  }
  L00503c7d: debug_va=0x00503c7d; { // 0x503c7d: 83ff0a CMP EDI, 0xA
    (void)integer::sub(s.di,0x0000000au,32,flags);
  }
  L00503c80: debug_va=0x00503c80; { // 0x503c80: 7507 JNZ 0x503C89
    if(integer::condition("JNZ",flags)) goto L00503c89;
  }
  L00503c82: debug_va=0x00503c82; { // 0x503c82: bf13000000 MOV EDI, 0x13
    s.di = 0x00000013u;
  }
  L00503c87: debug_va=0x00503c87; { // 0x503c87: eb35 JMP 0x503CBE
    goto L00503cbe;
  }
  L00503c89: debug_va=0x00503c89; { // 0x503c89: 83ff0b CMP EDI, 0xB
    (void)integer::sub(s.di,0x0000000bu,32,flags);
  }
  L00503c8c: debug_va=0x00503c8c; { // 0x503c8c: 7507 JNZ 0x503C95
    if(integer::condition("JNZ",flags)) goto L00503c95;
  }
  L00503c8e: debug_va=0x00503c8e; { // 0x503c8e: bf14000000 MOV EDI, 0x14
    s.di = 0x00000014u;
  }
  L00503c93: debug_va=0x00503c93; { // 0x503c93: eb29 JMP 0x503CBE
    goto L00503cbe;
  }
  L00503c95: debug_va=0x00503c95; { // 0x503c95: 83ff0c CMP EDI, 0xC
    (void)integer::sub(s.di,0x0000000cu,32,flags);
  }
  L00503c98: debug_va=0x00503c98; { // 0x503c98: 7507 JNZ 0x503CA1
    if(integer::condition("JNZ",flags)) goto L00503ca1;
  }
  L00503c9a: debug_va=0x00503c9a; { // 0x503c9a: bf15000000 MOV EDI, 0x15
    s.di = 0x00000015u;
  }
  L00503c9f: debug_va=0x00503c9f; { // 0x503c9f: eb1d JMP 0x503CBE
    goto L00503cbe;
  }
  L00503ca1: debug_va=0x00503ca1; { // 0x503ca1: 83ff04 CMP EDI, 4
    (void)integer::sub(s.di,4u,32,flags);
  }
  L00503ca4: debug_va=0x00503ca4; { // 0x503ca4: 7405 JZ 0x503CAB
    if(integer::condition("JZ",flags)) goto L00503cab;
  }
  L00503ca6: debug_va=0x00503ca6; { // 0x503ca6: 83ff08 CMP EDI, 8
    (void)integer::sub(s.di,8u,32,flags);
  }
  L00503ca9: debug_va=0x00503ca9; { // 0x503ca9: 7513 JNZ 0x503CBE
    if(integer::condition("JNZ",flags)) goto L00503cbe;
  }
  L00503cab: debug_va=0x00503cab; { // 0x503cab: bf16000000 MOV EDI, 0x16
    s.di = 0x00000016u;
  }
  L00503cb0: debug_va=0x00503cb0; { // 0x503cb0: eb0c JMP 0x503CBE
    goto L00503cbe;
  }
  L00503cb2: debug_va=0x00503cb2; { // 0x503cb2: bf10000000 MOV EDI, 0x10
    s.di = 0x00000010u;
  }
  L00503cb7: debug_va=0x00503cb7; { // 0x503cb7: eb05 JMP 0x503CBE
    goto L00503cbe;
  }
  L00503cb9: debug_va=0x00503cb9; { // 0x503cb9: bf11000000 MOV EDI, 0x11
    s.di = 0x00000011u;
  }
  L00503cbe: debug_va=0x00503cbe; { // 0x503cbe: 8b86d0050000 MOV EAX, dword ptr [ESI + 0x5D0]
    s.ax = m.r32((s.si+0x000005d0u));
  }
  L00503cc4: debug_va=0x00503cc4; { // 0x503cc4: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00503cc6: debug_va=0x00503cc6; { // 0x503cc6: 7533 JNZ 0x503CFB
    if(integer::condition("JNZ",flags)) goto L00503cfb;
  }
  L00503cc8: debug_va=0x00503cc8; { // 0x503cc8: 83fd01 CMP EBP, 1
    (void)integer::sub(s.bp,1u,32,flags);
  }
  L00503ccb: debug_va=0x00503ccb; { // 0x503ccb: 752e JNZ 0x503CFB
    if(integer::condition("JNZ",flags)) goto L00503cfb;
  }
  L00503ccd: debug_va=0x00503ccd; { // 0x503ccd: 8d9688000000 LEA EDX, [ESI + 0x88]
    s.dx = (s.si+0x00000088u);
  }
  L00503cd3: debug_va=0x00503cd3; { // 0x503cd3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00503cd5: debug_va=0x00503cd5; { // 0x503cd5: 8b02 MOV EAX, dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00503cd7: debug_va=0x00503cd7; { // 0x503cd7: 89442414 MOV dword ptr [ESP + 0x14], EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00503cdb: debug_va=0x00503cdb; { // 0x503cdb: 8b86a8050000 MOV EAX, dword ptr [ESI + 0x5A8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  L00503ce1: debug_va=0x00503ce1; { // 0x503ce1: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L00503ce4: debug_va=0x00503ce4; { // 0x503ce4: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00503ce8: debug_va=0x00503ce8; { // 0x503ce8: 8b5208 MOV EDX, dword ptr [EDX + 8]
    s.dx = m.r32((s.dx+8u));
  }
  L00503ceb: debug_va=0x00503ceb; { // 0x503ceb: 8954241c MOV dword ptr [ESP + 0x1C], EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00503cef: debug_va=0x00503cef; { // 0x503cef: 8b88fc0b0000 MOV ECX, dword ptr [EAX + 0xBFC]
    s.cx = m.r32((s.ax+0x00000bfcu));
  }
  L00503cf5: debug_va=0x00503cf5; { // 0x503cf5: 8d542414 LEA EDX, [ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00503cf9: debug_va=0x00503cf9; { // 0x503cf9: eb34 JMP 0x503D2F
    goto L00503d2f;
  }
  L00503cfb: debug_va=0x00503cfb; { // 0x503cfb: 83f801 CMP EAX, 1
    (void)integer::sub(s.ax,1u,32,flags);
  }
  L00503cfe: debug_va=0x00503cfe; { // 0x503cfe: 7534 JNZ 0x503D34
    if(integer::condition("JNZ",flags)) goto L00503d34;
  }
  L00503d00: debug_va=0x00503d00; { // 0x503d00: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L00503d02: debug_va=0x00503d02; { // 0x503d02: 7530 JNZ 0x503D34
    if(integer::condition("JNZ",flags)) goto L00503d34;
  }
  L00503d04: debug_va=0x00503d04; { // 0x503d04: 8d8e88000000 LEA ECX, [ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L00503d0a: debug_va=0x00503d0a; { // 0x503d0a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00503d0b: debug_va=0x00503d0b; { // 0x503d0b: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00503d0d: debug_va=0x00503d0d; { // 0x503d0d: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00503d11: debug_va=0x00503d11; { // 0x503d11: 8d542414 LEA EDX, [ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00503d15: debug_va=0x00503d15; { // 0x503d15: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00503d18: debug_va=0x00503d18; { // 0x503d18: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00503d1c: debug_va=0x00503d1c; { // 0x503d1c: 8b86a8050000 MOV EAX, dword ptr [ESI + 0x5A8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  L00503d22: debug_va=0x00503d22; { // 0x503d22: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L00503d25: debug_va=0x00503d25; { // 0x503d25: 894c241c MOV dword ptr [ESP + 0x1C], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00503d29: debug_va=0x00503d29; { // 0x503d29: 8b88f80b0000 MOV ECX, dword ptr [EAX + 0xBF8]
    s.cx = m.r32((s.ax+0x00000bf8u));
  }
  L00503d2f: debug_va=0x00503d2f; { // 0x503d2f: e8ec4c2000 CALL 0x708A20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708a20u,5258548u); flags=s.arithmetic_flags;
  }
  L00503d34: debug_va=0x00503d34; { // 0x503d34: 89aed0050000 MOV dword ptr [ESI + 0x5D0], EBP
    m.w32((s.si+0x000005d0u), s.bp);
  }
  L00503d3a: debug_va=0x00503d3a; { // 0x503d3a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00503d3c: debug_va=0x00503d3c; { // 0x503d3c: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503d3e: debug_va=0x00503d3e; { // 0x503d3e: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000054u)),5258561u); flags=s.arithmetic_flags;
  }
  L00503d41: debug_va=0x00503d41; { // 0x503d41: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503d43: debug_va=0x00503d43; { // 0x503d43: 7428 JZ 0x503D6D
    if(integer::condition("JZ",flags)) goto L00503d6d;
  }
  L00503d45: debug_va=0x00503d45; { // 0x503d45: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L00503d48: debug_va=0x00503d48; { // 0x503d48: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503d4a: debug_va=0x00503d4a; { // 0x503d4a: 7521 JNZ 0x503D6D
    if(integer::condition("JNZ",flags)) goto L00503d6d;
  }
  L00503d4c: debug_va=0x00503d4c; { // 0x503d4c: 8b86a8050000 MOV EAX, dword ptr [ESI + 0x5A8]
    s.ax = m.r32((s.si+0x000005a8u));
  }
  L00503d52: debug_va=0x00503d52; { // 0x503d52: 8b88980b0000 MOV ECX, dword ptr [EAX + 0xB98]
    s.cx = m.r32((s.ax+0x00000b98u));
  }
  L00503d58: debug_va=0x00503d58; { // 0x503d58: 8b8170010000 MOV EAX, dword ptr [ECX + 0x170]
    s.ax = m.r32((s.cx+0x00000170u));
  }
  L00503d5e: debug_va=0x00503d5e; { // 0x503d5e: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00503d60: debug_va=0x00503d60; { // 0x503d60: 7e0b JLE 0x503D6D
    if(integer::condition("JLE",flags)) goto L00503d6d;
  }
  L00503d62: debug_va=0x00503d62; { // 0x503d62: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00503d64: debug_va=0x00503d64; { // 0x503d64: 7507 JNZ 0x503D6D
    if(integer::condition("JNZ",flags)) goto L00503d6d;
  }
  L00503d66: debug_va=0x00503d66; { // 0x503d66: bf17000000 MOV EDI, 0x17
    s.di = 0x00000017u;
  }
  L00503d6b: debug_va=0x00503d6b; { // 0x503d6b: eb16 JMP 0x503D83
    goto L00503d83;
  }
  L00503d6d: debug_va=0x00503d6d; { // 0x503d6d: 83ff03 CMP EDI, 3
    (void)integer::sub(s.di,3u,32,flags);
  }
  L00503d70: debug_va=0x00503d70; { // 0x503d70: 7511 JNZ 0x503D83
    if(integer::condition("JNZ",flags)) goto L00503d83;
  }
  L00503d72: debug_va=0x00503d72; { // 0x503d72: 81bebc050000c8000000 CMP dword ptr [ESI + 0x5BC], 0xC8
    (void)integer::sub(m.r32((s.si+0x000005bcu)),0x000000c8u,32,flags);
  }
  L00503d7c: debug_va=0x00503d7c; { // 0x503d7c: 7c05 JL 0x503D83
    if(integer::condition("JL",flags)) goto L00503d83;
  }
  L00503d7e: debug_va=0x00503d7e; { // 0x503d7e: bf25000000 MOV EDI, 0x25
    s.di = 0x00000025u;
  }
  L00503d83: debug_va=0x00503d83; { // 0x503d83: 8b86ac050000 MOV EAX, dword ptr [ESI + 0x5AC]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L00503d89: debug_va=0x00503d89; { // 0x503d89: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00503d8b: debug_va=0x00503d8b; { // 0x503d8b: 0f84c5010000 JZ 0x503F56
    if(integer::condition("JZ",flags)) goto L00503f56;
  }
  L00503d91: debug_va=0x00503d91; { // 0x503d91: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00503d93: debug_va=0x00503d93; { // 0x503d93: 7417 JZ 0x503DAC
    if(integer::condition("JZ",flags)) goto L00503dac;
  }
  L00503d95: debug_va=0x00503d95; { // 0x503d95: 8a4c2424 MOV CL, byte ptr [ESP + 0x24]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000024u)));
  }
  L00503d99: debug_va=0x00503d99; { // 0x503d99: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00503d9b: debug_va=0x00503d9b; { // 0x503d9b: 750f JNZ 0x503DAC
    if(integer::condition("JNZ",flags)) goto L00503dac;
  }
  L00503d9d: debug_va=0x00503d9d; { // 0x503d9d: 8a0c8574e47800 MOV CL, byte ptr [EAX*4 + 0x78E474]
    s.cx = with_al(s.cx, m.r8(((s.ax * 4u)+0x0078e474u)));
  }
  L00503da4: debug_va=0x00503da4; { // 0x503da4: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00503da6: debug_va=0x00503da6; { // 0x503da6: 0f84aa010000 JZ 0x503F56
    if(integer::condition("JZ",flags)) goto L00503f56;
  }
  L00503dac: debug_va=0x00503dac; { // 0x503dac: 83ff1b CMP EDI, 0x1B
    (void)integer::sub(s.di,0x0000001bu,32,flags);
  }
  L00503daf: debug_va=0x00503daf; { // 0x503daf: 7548 JNZ 0x503DF9
    if(integer::condition("JNZ",flags)) goto L00503df9;
  }
  L00503db1: debug_va=0x00503db1; { // 0x503db1: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00503db3: debug_va=0x00503db3; { // 0x503db3: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503db5: debug_va=0x00503db5; { // 0x503db5: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),5258683u); flags=s.arithmetic_flags;
  }
  L00503dbb: debug_va=0x00503dbb; { // 0x503dbb: 3998f0040000 CMP dword ptr [EAX + 0x4F0], EBX
    (void)integer::sub(m.r32((s.ax+0x000004f0u)),s.bx,32,flags);
  }
  L00503dc1: debug_va=0x00503dc1; { // 0x503dc1: 0f8480000000 JZ 0x503E47
    if(integer::condition("JZ",flags)) goto L00503e47;
  }
  L00503dc7: debug_va=0x00503dc7; { // 0x503dc7: 8d8688000000 LEA EAX, [ESI + 0x88]
    s.ax = (s.si+0x00000088u);
  }
  L00503dcd: debug_va=0x00503dcd; { // 0x503dcd: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00503dcf: debug_va=0x00503dcf; { // 0x503dcf: 8d5c2414 LEA EBX, [ESP + 0x14]
    s.bx = (f.sp+0x00000014u);
  }
  L00503dd3: debug_va=0x00503dd3; { // 0x503dd3: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00503dd5: debug_va=0x00503dd5; { // 0x503dd5: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L00503dd9: debug_va=0x00503dd9; { // 0x503dd9: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503ddb: debug_va=0x00503ddb; { // 0x503ddb: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L00503dde: debug_va=0x00503dde; { // 0x503dde: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00503de2: debug_va=0x00503de2; { // 0x503de2: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00503de4: debug_va=0x00503de4; { // 0x503de4: 8b4008 MOV EAX, dword ptr [EAX + 8]
    s.ax = m.r32((s.ax+8u));
  }
  L00503de7: debug_va=0x00503de7; { // 0x503de7: 8944241c MOV dword ptr [ESP + 0x1C], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00503deb: debug_va=0x00503deb; { // 0x503deb: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),5258737u); flags=s.arithmetic_flags;
  }
  L00503df1: debug_va=0x00503df1; { // 0x503df1: 8b88f0040000 MOV ECX, dword ptr [EAX + 0x4F0]
    s.cx = m.r32((s.ax+0x000004f0u));
  }
  L00503df7: debug_va=0x00503df7; { // 0x503df7: eb47 JMP 0x503E40
    goto L00503e40;
  }
  L00503df9: debug_va=0x00503df9; { // 0x503df9: 83ff1f CMP EDI, 0x1F
    (void)integer::sub(s.di,0x0000001fu,32,flags);
  }
  L00503dfc: debug_va=0x00503dfc; { // 0x503dfc: 7549 JNZ 0x503E47
    if(integer::condition("JNZ",flags)) goto L00503e47;
  }
  L00503dfe: debug_va=0x00503dfe; { // 0x503dfe: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00503e00: debug_va=0x00503e00; { // 0x503e00: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503e02: debug_va=0x00503e02; { // 0x503e02: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),5258760u); flags=s.arithmetic_flags;
  }
  L00503e08: debug_va=0x00503e08; { // 0x503e08: 3998f4040000 CMP dword ptr [EAX + 0x4F4], EBX
    (void)integer::sub(m.r32((s.ax+0x000004f4u)),s.bx,32,flags);
  }
  L00503e0e: debug_va=0x00503e0e; { // 0x503e0e: 7437 JZ 0x503E47
    if(integer::condition("JZ",flags)) goto L00503e47;
  }
  L00503e10: debug_va=0x00503e10; { // 0x503e10: 8d8e88000000 LEA ECX, [ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L00503e16: debug_va=0x00503e16; { // 0x503e16: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00503e18: debug_va=0x00503e18; { // 0x503e18: 8d5c2414 LEA EBX, [ESP + 0x14]
    s.bx = (f.sp+0x00000014u);
  }
  L00503e1c: debug_va=0x00503e1c; { // 0x503e1c: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00503e1e: debug_va=0x00503e1e; { // 0x503e1e: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00503e22: debug_va=0x00503e22; { // 0x503e22: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00503e24: debug_va=0x00503e24; { // 0x503e24: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00503e27: debug_va=0x00503e27; { // 0x503e27: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00503e2b: debug_va=0x00503e2b; { // 0x503e2b: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L00503e2e: debug_va=0x00503e2e; { // 0x503e2e: 894c241c MOV dword ptr [ESP + 0x1C], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00503e32: debug_va=0x00503e32; { // 0x503e32: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503e34: debug_va=0x00503e34; { // 0x503e34: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),5258810u); flags=s.arithmetic_flags;
  }
  L00503e3a: debug_va=0x00503e3a; { // 0x503e3a: 8b88f4040000 MOV ECX, dword ptr [EAX + 0x4F4]
    s.cx = m.r32((s.ax+0x000004f4u));
  }
  L00503e40: debug_va=0x00503e40; { // 0x503e40: 8bd3 MOV EDX, EBX
    s.dx = s.bx;
  }
  L00503e42: debug_va=0x00503e42; { // 0x503e42: e8d94b2000 CALL 0x708A20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708a20u,5258823u); flags=s.arithmetic_flags;
  }
  L00503e47: debug_va=0x00503e47; { // 0x503e47: 83ff09 CMP EDI, 9
    (void)integer::sub(s.di,9u,32,flags);
  }
  L00503e4a: debug_va=0x00503e4a; { // 0x503e4a: 89beac050000 MOV dword ptr [ESI + 0x5AC], EDI
    m.w32((s.si+0x000005acu), s.di);
  }
  L00503e50: debug_va=0x00503e50; { // 0x503e50: 7419 JZ 0x503E6B
    if(integer::condition("JZ",flags)) goto L00503e6b;
  }
  L00503e52: debug_va=0x00503e52; { // 0x503e52: 83ff0a CMP EDI, 0xA
    (void)integer::sub(s.di,0x0000000au,32,flags);
  }
  L00503e55: debug_va=0x00503e55; { // 0x503e55: 7414 JZ 0x503E6B
    if(integer::condition("JZ",flags)) goto L00503e6b;
  }
  L00503e57: debug_va=0x00503e57; { // 0x503e57: 83ff12 CMP EDI, 0x12
    (void)integer::sub(s.di,0x00000012u,32,flags);
  }
  L00503e5a: debug_va=0x00503e5a; { // 0x503e5a: 740f JZ 0x503E6B
    if(integer::condition("JZ",flags)) goto L00503e6b;
  }
  L00503e5c: debug_va=0x00503e5c; { // 0x503e5c: 83ff13 CMP EDI, 0x13
    (void)integer::sub(s.di,0x00000013u,32,flags);
  }
  L00503e5f: debug_va=0x00503e5f; { // 0x503e5f: 740a JZ 0x503E6B
    if(integer::condition("JZ",flags)) goto L00503e6b;
  }
  L00503e61: debug_va=0x00503e61; { // 0x503e61: 83ff17 CMP EDI, 0x17
    (void)integer::sub(s.di,0x00000017u,32,flags);
  }
  L00503e64: debug_va=0x00503e64; { // 0x503e64: 7405 JZ 0x503E6B
    if(integer::condition("JZ",flags)) goto L00503e6b;
  }
  L00503e66: debug_va=0x00503e66; { // 0x503e66: 83ff20 CMP EDI, 0x20
    (void)integer::sub(s.di,0x00000020u,32,flags);
  }
  L00503e69: debug_va=0x00503e69; { // 0x503e69: 752c JNZ 0x503E97
    if(integer::condition("JNZ",flags)) goto L00503e97;
  }
  L00503e6b: debug_va=0x00503e6b; { // 0x503e6b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00503e6d: debug_va=0x00503e6d; { // 0x503e6d: b95887a200 MOV ECX, 0xA28758
    s.cx = 0x00a28758u;
  }
  L00503e72: debug_va=0x00503e72; { // 0x503e72: 8a04bd77e47800 MOV AL, byte ptr [EDI*4 + 0x78E477]
    s.ax = with_al(s.ax, m.r8(((s.di * 4u)+0x0078e477u)));
  }
  L00503e79: debug_va=0x00503e79; { // 0x503e79: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503e7a: debug_va=0x00503e7a; { // 0x503e7a: e861df0c00 CALL 0x5D1DE0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d1de0u,5258879u); flags=s.arithmetic_flags;
  }
  L00503e7f: debug_va=0x00503e7f; { // 0x503e7f: 8b0d6c89a200 MOV ECX, dword ptr [0xA2896C]
    s.cx = m.r32((0x00a2896cu));
  }
  L00503e85: debug_va=0x00503e85; { // 0x503e85: 8d96e4000000 LEA EDX, [ESI + 0xE4]
    s.dx = (s.si+0x000000e4u);
  }
  L00503e8b: debug_va=0x00503e8b; { // 0x503e8b: 898ee4000000 MOV dword ptr [ESI + 0xE4], ECX
    m.w32((s.si+0x000000e4u), s.cx);
  }
  L00503e91: debug_va=0x00503e91; { // 0x503e91: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00503e95: debug_va=0x00503e95; { // 0x503e95: eb1f JMP 0x503EB6
    goto L00503eb6;
  }
  L00503e97: debug_va=0x00503e97; { // 0x503e97: 8b0d6c89a200 MOV ECX, dword ptr [0xA2896C]
    s.cx = m.r32((0x00a2896cu));
  }
  L00503e9d: debug_va=0x00503e9d; { // 0x503e9d: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00503e9f: debug_va=0x00503e9f; { // 0x503e9f: 8a04bd77e47800 MOV AL, byte ptr [EDI*4 + 0x78E477]
    s.ax = with_al(s.ax, m.r8(((s.di * 4u)+0x0078e477u)));
  }
  L00503ea6: debug_va=0x00503ea6; { // 0x503ea6: 8d96e4000000 LEA EDX, [ESI + 0xE4]
    s.dx = (s.si+0x000000e4u);
  }
  L00503eac: debug_va=0x00503eac; { // 0x503eac: 898ee4000000 MOV dword ptr [ESI + 0xE4], ECX
    m.w32((s.si+0x000000e4u), s.cx);
  }
  L00503eb2: debug_va=0x00503eb2; { // 0x503eb2: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00503eb6: debug_va=0x00503eb6; { // 0x503eb6: 894a04 MOV dword ptr [EDX + 4], ECX
    m.w32((s.dx+4u), s.cx);
  }
  L00503eb9: debug_va=0x00503eb9; { // 0x503eb9: 894208 MOV dword ptr [EDX + 8], EAX
    m.w32((s.dx+8u), s.ax);
  }
  L00503ebc: debug_va=0x00503ebc; { // 0x503ebc: 8986f0000000 MOV dword ptr [ESI + 0xF0], EAX
    m.w32((s.si+0x000000f0u), s.ax);
  }
  L00503ec2: debug_va=0x00503ec2; { // 0x503ec2: 8a442428 MOV AL, byte ptr [ESP + 0x28]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000028u)));
  }
  L00503ec6: debug_va=0x00503ec6; { // 0x503ec6: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00503ec8: debug_va=0x00503ec8; { // 0x503ec8: 743c JZ 0x503F06
    if(integer::condition("JZ",flags)) goto L00503f06;
  }
  L00503eca: debug_va=0x00503eca; { // 0x503eca: 8b96a8050000 MOV EDX, dword ptr [ESI + 0x5A8]
    s.dx = m.r32((s.si+0x000005a8u));
  }
  L00503ed0: debug_va=0x00503ed0; { // 0x503ed0: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L00503ed2: debug_va=0x00503ed2; { // 0x503ed2: c1e004 SHL EAX, 4
    s.ax = integer::shift(s.ax,4u,32,flags,integer::Shift::left);
  }
  L00503ed5: debug_va=0x00503ed5; { // 0x503ed5: 8b8a980b0000 MOV ECX, dword ptr [EDX + 0xB98]
    s.cx = m.r32((s.dx+0x00000b98u));
  }
  L00503edb: debug_va=0x00503edb; { // 0x503edb: 8b440104 MOV EAX, dword ptr [ECX + EAX + 4]
    s.ax = m.r32((s.cx+s.ax+4u));
  }
  L00503edf: debug_va=0x00503edf; { // 0x503edf: 83f801 CMP EAX, 1
    (void)integer::sub(s.ax,1u,32,flags);
  }
  L00503ee2: debug_va=0x00503ee2; { // 0x503ee2: 7f05 JG 0x503EE9
    if(integer::condition("JG",flags)) goto L00503ee9;
  }
  L00503ee4: debug_va=0x00503ee4; { // 0x503ee4: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00503ee9: debug_va=0x00503ee9; { // 0x503ee9: 8b15c055a200 MOV EDX, dword ptr [0xA255C0]
    s.dx = m.r32((0x00a255c0u));
  }
  L00503eef: debug_va=0x00503eef; { // 0x503eef: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00503ef0: debug_va=0x00503ef0; { // 0x503ef0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00503ef1: debug_va=0x00503ef1; { // 0x503ef1: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00503ef3: debug_va=0x00503ef3; { // 0x503ef3: 8d8a18020000 LEA ECX, [EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L00503ef9: debug_va=0x00503ef9; { // 0x503ef9: e842bf1200 CALL 0x62FE40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5259006u); flags=s.arithmetic_flags;
  }
  L00503efe: debug_va=0x00503efe; { // 0x503efe: 8986e0000000 MOV dword ptr [ESI + 0xE0], EAX
    m.w32((s.si+0x000000e0u), s.ax);
  }
  L00503f04: debug_va=0x00503f04; { // 0x503f04: eb0a JMP 0x503F10
    goto L00503f10;
  }
  L00503f06: debug_va=0x00503f06; { // 0x503f06: c786e000000000000000 MOV dword ptr [ESI + 0xE0], 0
    m.w32((s.si+0x000000e0u), 0u);
  }
  L00503f10: debug_va=0x00503f10; { // 0x503f10: 8b466c MOV EAX, dword ptr [ESI + 0x6C]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00503f13: debug_va=0x00503f13; { // 0x503f13: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00503f15: debug_va=0x00503f15; { // 0x503f15: 750a JNZ 0x503F21
    if(integer::condition("JNZ",flags)) goto L00503f21;
  }
  L00503f17: debug_va=0x00503f17; { // 0x503f17: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00503f19: debug_va=0x00503f19; { // 0x503f19: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00503f1b: debug_va=0x00503f1b; { // 0x503f1b: ff908c040000 CALL dword ptr [EAX + 0x48C]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000048cu)),5259041u); flags=s.arithmetic_flags;
  }
  L00503f21: debug_va=0x00503f21; { // 0x503f21: 83ef05 SUB EDI, 5
    s.di = integer::sub(s.di,5u,32,flags);
  }
  L00503f24: debug_va=0x00503f24; { // 0x503f24: 741d JZ 0x503F43
    if(integer::condition("JZ",flags)) goto L00503f43;
  }
  L00503f26: debug_va=0x00503f26; { // 0x503f26: 83ef02 SUB EDI, 2
    s.di = integer::sub(s.di,2u,32,flags);
  }
  L00503f29: debug_va=0x00503f29; { // 0x503f29: 7405 JZ 0x503F30
    if(integer::condition("JZ",flags)) goto L00503f30;
  }
  L00503f2b: debug_va=0x00503f2b; { // 0x503f2b: 83ef14 SUB EDI, 0x14
    s.di = integer::sub(s.di,0x00000014u,32,flags);
  }
  L00503f2e: debug_va=0x00503f2e; { // 0x503f2e: 751a JNZ 0x503F4A
    if(integer::condition("JNZ",flags)) goto L00503f4a;
  }
  L00503f30: debug_va=0x00503f30; { // 0x503f30: c686c305000000 MOV byte ptr [ESI + 0x5C3], 0
    m.w8((s.si+0x000005c3u), 0u);
  }
  L00503f37: debug_va=0x00503f37; { // 0x503f37: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00503f38: debug_va=0x00503f38; { // 0x503f38: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00503f39: debug_va=0x00503f39; { // 0x503f39: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00503f3a: debug_va=0x00503f3a; { // 0x503f3a: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00503f3c: debug_va=0x00503f3c; { // 0x503f3c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00503f3d: debug_va=0x00503f3d; { // 0x503f3d: 83c40c ADD ESP, 0xC
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00503f40: debug_va=0x00503f40; { // 0x503f40: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00503f43: debug_va=0x00503f43; { // 0x503f43: c686c305000001 MOV byte ptr [ESI + 0x5C3], 1
    m.w8((s.si+0x000005c3u), 1u);
  }
  L00503f4a: debug_va=0x00503f4a; { // 0x503f4a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00503f4b: debug_va=0x00503f4b; { // 0x503f4b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00503f4c: debug_va=0x00503f4c; { // 0x503f4c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00503f4d: debug_va=0x00503f4d; { // 0x503f4d: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L00503f4f: debug_va=0x00503f4f; { // 0x503f4f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00503f50: debug_va=0x00503f50; { // 0x503f50: 83c40c ADD ESP, 0xC
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00503f53: debug_va=0x00503f53; { // 0x503f53: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00503f56: debug_va=0x00503f56; { // 0x503f56: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00503f57: debug_va=0x00503f57; { // 0x503f57: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00503f58: debug_va=0x00503f58; { // 0x503f58: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00503f59: debug_va=0x00503f59; { // 0x503f59: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00503f5b: debug_va=0x00503f5b; { // 0x503f5b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00503f5c: debug_va=0x00503f5c; { // 0x503f5c: 83c40c ADD ESP, 0xC
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00503f5f: debug_va=0x00503f5f; { // 0x503f5f: c20c00 RET 0xC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_000101f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004101f0: debug_va=0x004101f0; { // 0x4101f0: 8b4c2404 MOV ECX, dword ptr [ESP + 4]
    s.cx = m.r32((f.sp+4u));
  }
  L004101f4: debug_va=0x004101f4; { // 0x4101f4: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004101f6: debug_va=0x004101f6; { // 0x4101f6: 8a5120 MOV DL, byte ptr [ECX + 0x20]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000020u)));
  }
  L004101f9: debug_va=0x004101f9; { // 0x4101f9: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004101fb: debug_va=0x004101fb; { // 0x4101fb: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004101fe: debug_va=0x004101fe; { // 0x4101fe: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0000cd40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040cd40: debug_va=0x0040cd40; { // 0x40cd40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0040cd41: debug_va=0x0040cd41; { // 0x40cd41: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0040cd42: debug_va=0x0040cd42; { // 0x40cd42: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L0040cd46: debug_va=0x0040cd46; { // 0x40cd46: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040cd47: debug_va=0x0040cd47; { // 0x40cd47: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0040cd49: debug_va=0x0040cd49; { // 0x40cd49: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0040cd4a: debug_va=0x0040cd4a; { // 0x40cd4a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0040cd4c: debug_va=0x0040cd4c; { // 0x40cd4c: 747c JZ 0x0040cdca
    if(integer::condition("JZ",flags)) goto L0040cdca;
  }
  L0040cd4e: debug_va=0x0040cd4e; { // 0x40cd4e: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0040cd52: debug_va=0x0040cd52; { // 0x40cd52: c6460c00 MOV byte ptr [ESI + 0xc],0x0
    m.w8((s.si+0x0000000cu), 0x00000000u);
  }
  L0040cd56: debug_va=0x0040cd56; { // 0x40cd56: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0040cd58: debug_va=0x0040cd58; { // 0x40cd58: 7514 JNZ 0x0040cd6e
    if(integer::condition("JNZ",flags)) goto L0040cd6e;
  }
  L0040cd5a: debug_va=0x0040cd5a; { // 0x40cd5a: 8d04ad00000000 LEA EAX,[EBP*0x4 + 0x0]
    s.ax = ((s.bp * 0x00000004u)+0x00000000u);
  }
  L0040cd61: debug_va=0x0040cd61; { // 0x40cd61: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0040cd62: debug_va=0x0040cd62; { // 0x40cd62: e8f00b3600 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4246887u); flags=s.arithmetic_flags;
  }
  L0040cd67: debug_va=0x0040cd67; { // 0x40cd67: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0040cd6a: debug_va=0x0040cd6a; { // 0x40cd6a: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0040cd6c: debug_va=0x0040cd6c; { // 0x40cd6c: eb02 JMP 0x0040cd70
    goto L0040cd70;
  }
  L0040cd6e: debug_va=0x0040cd6e; { // 0x40cd6e: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0040cd70: debug_va=0x0040cd70; { // 0x40cd70: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0040cd72: debug_va=0x0040cd72; { // 0x40cd72: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0040cd76: debug_va=0x0040cd76; { // 0x40cd76: 746f JZ 0x0040cde7
    if(integer::condition("JZ",flags)) goto L0040cde7;
  }
  L0040cd78: debug_va=0x0040cd78; { // 0x40cd78: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0040cd7b: debug_va=0x0040cd7b; { // 0x40cd7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0040cd7d: debug_va=0x0040cd7d; { // 0x40cd7d: 7439 JZ 0x0040cdb8
    if(integer::condition("JZ",flags)) goto L0040cdb8;
  }
  L0040cd7f: debug_va=0x0040cd7f; { // 0x40cd7f: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0040cd82: debug_va=0x0040cd82; { // 0x40cd82: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L0040cd84: debug_va=0x0040cd84; { // 0x40cd84: 7d02 JGE 0x0040cd88
    if(integer::condition("JGE",flags)) goto L0040cd88;
  }
  L0040cd86: debug_va=0x0040cd86; { // 0x40cd86: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0040cd88: debug_va=0x0040cd88; { // 0x40cd88: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040cd8a: debug_va=0x0040cd8a; { // 0x40cd8a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0040cd8c: debug_va=0x0040cd8c; { // 0x40cd8c: 7e10 JLE 0x0040cd9e
    if(integer::condition("JLE",flags)) goto L0040cd9e;
  }
  L0040cd8e: debug_va=0x0040cd8e; { // 0x40cd8e: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0040cd91: debug_va=0x0040cd91; { // 0x40cd91: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0040cd92: debug_va=0x0040cd92; { // 0x40cd92: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0040cd94: debug_va=0x0040cd94; { // 0x40cd94: 8b5482fc MOV EDX,dword ptr [EDX + EAX*0x4 + -0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)-0x00000004u));
  }
  L0040cd98: debug_va=0x0040cd98; { // 0x40cd98: 895487fc MOV dword ptr [EDI + EAX*0x4 + -0x4],EDX
    m.w32((s.di+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0040cd9c: debug_va=0x0040cd9c; { // 0x40cd9c: 7cf0 JL 0x0040cd8e
    if(integer::condition("JL",flags)) goto L0040cd8e;
  }
  L0040cd9e: debug_va=0x0040cd9e; { // 0x40cd9e: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L0040cda1: debug_va=0x0040cda1; { // 0x40cda1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0040cda3: debug_va=0x0040cda3; { // 0x40cda3: 7413 JZ 0x0040cdb8
    if(integer::condition("JZ",flags)) goto L0040cdb8;
  }
  L0040cda5: debug_va=0x0040cda5; { // 0x40cda5: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0040cda8: debug_va=0x0040cda8; { // 0x40cda8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0040cda9: debug_va=0x0040cda9; { // 0x40cda9: e8cd083600 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4246958u); flags=s.arithmetic_flags;
  }
  L0040cdae: debug_va=0x0040cdae; { // 0x40cdae: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0040cdb1: debug_va=0x0040cdb1; { // 0x40cdb1: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0040cdb8: debug_va=0x0040cdb8; { // 0x40cdb8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040cdba: debug_va=0x0040cdba; { // 0x40cdba: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L0040cdbd: debug_va=0x0040cdbd; { // 0x40cdbd: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0040cdbf: debug_va=0x0040cdbf; { // 0x40cdbf: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0040cdc2: debug_va=0x0040cdc2; { // 0x40cdc2: 896e08 MOV dword ptr [ESI + 0x8],EBP
    m.w32((s.si+0x00000008u), s.bp);
  }
  L0040cdc5: debug_va=0x0040cdc5; { // 0x40cdc5: 88460d MOV byte ptr [ESI + 0xd],AL
    m.w8((s.si+0x0000000du), (s.ax & 0xffu));
  }
  L0040cdc8: debug_va=0x0040cdc8; { // 0x40cdc8: eb07 JMP 0x0040cdd1
    goto L0040cdd1;
  }
  L0040cdca: debug_va=0x0040cdca; { // 0x40cdca: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0040cdcc: debug_va=0x0040cdcc; { // 0x40cdcc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0040cdce: debug_va=0x0040cdce; { // 0x40cdce: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),4246993u); flags=s.arithmetic_flags;
  }
  L0040cdd1: debug_va=0x0040cdd1; { // 0x40cdd1: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0040cdd4: debug_va=0x0040cdd4; { // 0x40cdd4: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0040cdd7: debug_va=0x0040cdd7; { // 0x40cdd7: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0040cdd9: debug_va=0x0040cdd9; { // 0x40cdd9: 7d03 JGE 0x0040cdde
    if(integer::condition("JGE",flags)) goto L0040cdde;
  }
  L0040cddb: debug_va=0x0040cddb; { // 0x40cddb: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0040cdde: debug_va=0x0040cdde; { // 0x40cdde: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0040cddf: debug_va=0x0040cddf; { // 0x40cddf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040cde0: debug_va=0x0040cde0; { // 0x40cde0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0040cde1: debug_va=0x0040cde1; { // 0x40cde1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0040cde3: debug_va=0x0040cde3; { // 0x40cde3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0040cde4: debug_va=0x0040cde4; { // 0x40cde4: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0040cde7: debug_va=0x0040cde7; { // 0x40cde7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0040cde8: debug_va=0x0040cde8; { // 0x40cde8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040cde9: debug_va=0x0040cde9; { // 0x40cde9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0040cdea: debug_va=0x0040cdea; { // 0x40cdea: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0040cdec: debug_va=0x0040cdec; { // 0x40cdec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0040cded: debug_va=0x0040cded; { // 0x40cded: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0000dc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040dc20: debug_va=0x0040dc20; { // 0x40dc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040dc21: debug_va=0x0040dc21; { // 0x40dc21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0040dc23: debug_va=0x0040dc23; { // 0x40dc23: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0040dc25: debug_va=0x0040dc25; { // 0x40dc25: 741e JZ 0x0040dc45
    if(integer::condition("JZ",flags)) goto L0040dc45;
  }
  L0040dc27: debug_va=0x0040dc27; { // 0x40dc27: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0040dc29: debug_va=0x0040dc29; { // 0x40dc29: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4250668u); flags=s.arithmetic_flags;
  }
  L0040dc2c: debug_va=0x0040dc2c; { // 0x40dc2c: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0040dc2d: debug_va=0x0040dc2d; { // 0x40dc2d: 83f80e CMP EAX,0xe
    (void)integer::sub(s.ax,0x0000000eu,32,flags);
  }
  L0040dc30: debug_va=0x0040dc30; { // 0x40dc30: 7713 JA 0x0040dc45
    if(integer::condition("JA",flags)) goto L0040dc45;
  }
  L0040dc32: debug_va=0x0040dc32; { // 0x40dc32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040dc34: debug_va=0x0040dc34; { // 0x40dc34: 8a8854dc4000 MOV CL,byte ptr [EAX + 0x40dc54]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0040dc54u)));
  }
  L0040dc3a: debug_va=0x0040dc3a; { // 0x40dc3a: ff248d4cdc4000 JMP dword ptr [ECX*0x4 + 0x40dc4c]
    switch(m.r32(((s.cx * 0x00000004u)+0x0040dc4cu))){
    case 0x0040dc20u: goto L0040dc20;
    case 0x0040dc21u: goto L0040dc21;
    case 0x0040dc23u: goto L0040dc23;
    case 0x0040dc25u: goto L0040dc25;
    case 0x0040dc27u: goto L0040dc27;
    case 0x0040dc29u: goto L0040dc29;
    case 0x0040dc2cu: goto L0040dc2c;
    case 0x0040dc2du: goto L0040dc2d;
    case 0x0040dc30u: goto L0040dc30;
    case 0x0040dc32u: goto L0040dc32;
    case 0x0040dc34u: goto L0040dc34;
    case 0x0040dc3au: goto L0040dc3a;
    case 0x0040dc41u: goto L0040dc41;
    case 0x0040dc43u: goto L0040dc43;
    case 0x0040dc44u: goto L0040dc44;
    case 0x0040dc45u: goto L0040dc45;
    case 0x0040dc47u: goto L0040dc47;
    case 0x0040dc48u: goto L0040dc48;
    default:throw std::domain_error("recovery236 unsupported switch destination");}
  }
  L0040dc41: debug_va=0x0040dc41; { // 0x40dc41: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0040dc43: debug_va=0x0040dc43; { // 0x40dc43: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc44: debug_va=0x0040dc44; { // 0x40dc44: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0040dc45: debug_va=0x0040dc45; { // 0x40dc45: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040dc47: debug_va=0x0040dc47; { // 0x40dc47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040dc48: debug_va=0x0040dc48; { // 0x40dc48: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000cca70(Memory& m,State& s,Frame& f,const Operations& op) {
f_001cdaa0(m,s,f,op);
}
void f_001cdaa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cdaa0: debug_va=0x005cdaa0; { // 0x005cdaa0: 8a4174 MOV AL,byte ptr [ECX + 0x74]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000074u)));
  }
  L005cdaa3: debug_va=0x005cdaa3; { // 0x005cdaa3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005cdaa5: debug_va=0x005cdaa5; { // 0x005cdaa5: 7418 JZ 0x005cdabf
    if(integer::condition("JZ",flags)) goto L005cdabf;
  }
  L005cdaa7: debug_va=0x005cdaa7; { // 0x005cdaa7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005cdaa9: debug_va=0x005cdaa9; { // 0x005cdaa9: ff90b0010000 CALL dword ptr [EAX + 0x1b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001b0u)),6085295u); flags=s.arithmetic_flags;
  }
  L005cdaaf: debug_va=0x005cdaaf; { // 0x005cdaaf: 8b0da8aaa500 MOV ECX,dword ptr [0x00a5aaa8]
    s.cx = m.r32((0x00a5aaa8u));
  }
  L005cdab5: debug_va=0x005cdab5; { // 0x005cdab5: 8d1409 LEA EDX,[ECX + ECX*0x1]
    s.dx = (s.cx+(s.cx * 0x00000001u));
  }
  L005cdab8: debug_va=0x005cdab8; { // 0x005cdab8: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L005cdaba: debug_va=0x005cdaba; { // 0x005cdaba: 7c03 JL 0x005cdabf
    if(integer::condition("JL",flags)) goto L005cdabf;
  }
  L005cdabc: debug_va=0x005cdabc; { // 0x005cdabc: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005cdabe: debug_va=0x005cdabe; { // 0x005cdabe: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005cdabf: debug_va=0x005cdabf; { // 0x005cdabf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005cdac1: debug_va=0x005cdac1; { // 0x005cdac1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00191ed0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00591ed0: debug_va=0x00591ed0; { // 0x591ed0: 8b8198000000 MOV EAX,dword ptr [ECX + 0x98]
    s.ax = m.r32((s.cx+0x00000098u));
  }
  L00591ed6: debug_va=0x00591ed6; { // 0x591ed6: c1e005 SHL EAX,0x5
    s.ax = integer::shift(s.ax,0x00000005u,32,flags,integer::Shift::left);
  }
  L00591ed9: debug_va=0x00591ed9; { // 0x591ed9: 050080a200 ADD EAX,0xa28000
    s.ax = integer::add(s.ax,0x00a28000u,32,flags);
  }
  L00591ede: debug_va=0x00591ede; { // 0x591ede: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: debug_va=0x00707fe0; { // 0x707fe0: dd01 FLD double ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: debug_va=0x00707fe2; { // 0x707fe2: dc1df8567800 FCOMP double ptr [0x007856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: debug_va=0x00707fe8; { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: debug_va=0x00707fea; { // 0x707fea: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00707fed: debug_va=0x00707fed; { // 0x707fed: 7506 JNZ 0x00707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: debug_va=0x00707fef; { // 0x707fef: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00707ff4: debug_va=0x00707ff4; { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: debug_va=0x00707ff5; { // 0x707ff5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: debug_va=0x00707ff7; { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
s.ax=m.r32(s.cx);if(m.r32(s.ax+0x84)!=0x505da0)throw std::domain_error("236 tail target");f_00105da0(m,s,f,op);
}
void f_00105da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00505da0: debug_va=0x00505da0; { // 0x505da0: 8b81a8050000 MOV EAX, dword ptr [ECX + 0x5a8]
    s.ax = m.r32((s.cx+0x000005a8u));
  }
  L00505da6: debug_va=0x00505da6; { // 0x505da6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5278800u:f_00108c50(m,s,child,{});break;
case 5256624u:f_001035b0(m,s,child,{});break;
case 5258192u:f_00103bd0(m,s,child,{});break;
case 4260336u:f_000101f0(m,s,child,{});break;
case 4246848u:f_0000cd40(m,s,child,{});break;
case 4250656u:f_0000dc20(m,s,child,{});break;
case 5032560u:f_000cca70(m,s,child,{});break;
case 6085280u:f_001cdaa0(m,s,child,{});break;
case 5840592u:f_00191ed0(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 5266848u:f_00105da0(m,s,child,{});break;
case 0x76d957u:{if(m.r32(child.entry_sp+4)!=40)throw std::domain_error("236 exact request40");s.ax=s.heap->allocate(40);m.w32(child.entry_sp-0x58,child.entry_sp-0x2c);s.allocation.reset(new leaf::Memory(reinterpret_cast<unsigned char*>(std::uintptr_t(s.ax)),s.ax,40));m.add(*s.allocation);finish(m,s,child,0);break;}
case 0x76d67bu:{s.ax=m.r32(child.entry_sp+4);s.heap->release(s.ax);finish(m,s,child,0);break;}
default:throw std::domain_error("recovery236 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00476520(Memory& original,const Inputs& i,Heap& heap){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6000u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.heap=&heap;s.bx=0x13579bdf;s.si=0x2468ace0;s.di=0x789abcde;s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 std::array<std::uint8_t,23> table0{{65,220,64,0,69,220,64,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,0}};leaf::Memory tablemem0(table0.data(),4250700u,23u);m.add(tablemem0);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00476520: debug_va=0x00476520; { // 0x476520: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  L00476524: debug_va=0x00476524; { // 0x476524: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00476527: debug_va=0x00476527; { // 0x476527: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00476529: debug_va=0x00476529; { // 0x476529: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047652a: debug_va=0x0047652a; { // 0x47652a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047652b: debug_va=0x0047652b; { // 0x47652b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047652c: debug_va=0x0047652c; { // 0x47652c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0047652e: debug_va=0x0047652e; { // 0x47652e: 7408 JZ 0x00476538
    if(integer::condition("JZ",flags)) goto L00476538;
  }
  L00476530: debug_va=0x00476530; { // 0x476530: 8bb7e8000000 MOV ESI,dword ptr [EDI + 0xe8]
    s.si = m.r32((s.di+0x000000e8u));
  }
  L00476536: debug_va=0x00476536; { // 0x476536: eb06 JMP 0x0047653e
    goto L0047653e;
  }
  L00476538: debug_va=0x00476538; { // 0x476538: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L0047653e: debug_va=0x0047653e; { // 0x47653e: 8a442434 MOV AL,byte ptr [ESP + 0x34]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000034u)));
  }
  L00476542: debug_va=0x00476542; { // 0x476542: c644240f00 MOV byte ptr [ESP + 0xf],0x0
    m.w8((f.sp+0x0000000fu), 0x00000000u);
  }
  L00476547: debug_va=0x00476547; { // 0x476547: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00476549: debug_va=0x00476549; { // 0x476549: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L0047654b: debug_va=0x0047654b; { // 0x47654b: 752b JNZ 0x00476578
    if(integer::condition("JNZ",flags)) goto L00476578;
  }
  L0047654d: debug_va=0x0047654d; { // 0x47654d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047654f: debug_va=0x0047654f; { // 0x47654f: 7427 JZ 0x00476578
    if(integer::condition("JZ",flags)) goto L00476578;
  }
  L00476551: debug_va=0x00476551; { // 0x476551: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00476553: debug_va=0x00476553; { // 0x476553: e8c876f9ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,4679000u); flags=s.arithmetic_flags;
  }
  L00476558: debug_va=0x00476558; { // 0x476558: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047655a: debug_va=0x0047655a; { // 0x47655a: 740f JZ 0x0047656b
    if(integer::condition("JZ",flags)) goto L0047656b;
  }
  L0047655c: debug_va=0x0047655c; { // 0x47655c: 8d8818010000 LEA ECX,[EAX + 0x118]
    s.cx = (s.ax+0x00000118u);
  }
  L00476562: debug_va=0x00476562; { // 0x476562: e8791a2900 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,4679015u); flags=s.arithmetic_flags;
  }
  L00476567: debug_va=0x00476567; { // 0x476567: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00476569: debug_va=0x00476569; { // 0x476569: 7509 JNZ 0x00476574
    if(integer::condition("JNZ",flags)) goto L00476574;
  }
  L0047656b: debug_va=0x0047656b; { // 0x47656b: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047656e: debug_va=0x0047656e; { // 0x47656e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00476570: debug_va=0x00476570; { // 0x476570: 75df JNZ 0x00476551
    if(integer::condition("JNZ",flags)) goto L00476551;
  }
  L00476572: debug_va=0x00476572; { // 0x476572: eb04 JMP 0x00476578
    goto L00476578;
  }
  L00476574: debug_va=0x00476574; { // 0x476574: 885c240f MOV byte ptr [ESP + 0xf],BL
    m.w8((f.sp+0x0000000fu), (s.bx & 0xffu));
  }
  L00476578: debug_va=0x00476578; { // 0x476578: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L0047657c: debug_va=0x0047657c; { // 0x47657c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047657e: debug_va=0x0047657e; { // 0x47657e: 7408 JZ 0x00476588
    if(integer::condition("JZ",flags)) goto L00476588;
  }
  L00476580: debug_va=0x00476580; { // 0x476580: 8bb7e8000000 MOV ESI,dword ptr [EDI + 0xe8]
    s.si = m.r32((s.di+0x000000e8u));
  }
  L00476586: debug_va=0x00476586; { // 0x476586: eb06 JMP 0x0047658e
    goto L0047658e;
  }
  L00476588: debug_va=0x00476588; { // 0x476588: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  L0047658e: debug_va=0x0047658e; { // 0x47658e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00476590: debug_va=0x00476590; { // 0x476590: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00476592: debug_va=0x00476592; { // 0x476592: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  L00476597: debug_va=0x00476597; { // 0x476597: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00476599: debug_va=0x00476599; { // 0x476599: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0047659d: debug_va=0x0047659d; { // 0x47659d: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L004765a1: debug_va=0x004765a1; { // 0x4765a1: 885c241c MOV byte ptr [ESP + 0x1c],BL
    m.w8((f.sp+0x0000001cu), (s.bx & 0xffu));
  }
  L004765a5: debug_va=0x004765a5; { // 0x4765a5: 8844241d MOV byte ptr [ESP + 0x1d],AL
    m.w8((f.sp+0x0000001du), (s.ax & 0xffu));
  }
  L004765a9: debug_va=0x004765a9; { // 0x4765a9: c74424107c8b7800 MOV dword ptr [ESP + 0x10],0x788b7c
    m.w32((f.sp+0x00000010u), 0x00788b7cu);
  }
  L004765b1: debug_va=0x004765b1; { // 0x4765b1: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L004765b5: debug_va=0x004765b5; { // 0x4765b5: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L004765b9: debug_va=0x004765b9; { // 0x4765b9: 744c JZ 0x00476607
    if(integer::condition("JZ",flags)) goto L00476607;
  }
  L004765bb: debug_va=0x004765bb; { // 0x4765bb: eb04 JMP 0x004765c1
    goto L004765c1;
  }
  L004765bd: debug_va=0x004765bd; { // 0x4765bd: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004765c1: debug_va=0x004765c1; { // 0x4765c1: 39442420 CMP dword ptr [ESP + 0x20],EAX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.ax,32,flags);
  }
  L004765c5: debug_va=0x004765c5; { // 0x4765c5: 7c23 JL 0x004765ea
    if(integer::condition("JL",flags)) goto L004765ea;
  }
  L004765c7: debug_va=0x004765c7; { // 0x4765c7: 8a54241d MOV DL,byte ptr [ESP + 0x1d]
    s.dx = with_al(s.dx, m.r8((f.sp+0x0000001du)));
  }
  L004765cb: debug_va=0x004765cb; { // 0x4765cb: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004765cd: debug_va=0x004765cd; { // 0x4765cd: 7504 JNZ 0x004765d3
    if(integer::condition("JNZ",flags)) goto L004765d3;
  }
  L004765cf: debug_va=0x004765cf; { // 0x4765cf: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004765d1: debug_va=0x004765d1; { // 0x4765d1: 752d JNZ 0x00476600
    if(integer::condition("JNZ",flags)) goto L00476600;
  }
  L004765d3: debug_va=0x004765d3; { // 0x4765d3: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L004765d5: debug_va=0x004765d5; { // 0x4765d5: 7e29 JLE 0x00476600
    if(integer::condition("JLE",flags)) goto L00476600;
  }
  L004765d7: debug_va=0x004765d7; { // 0x4765d7: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004765d9: debug_va=0x004765d9; { // 0x4765d9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004765da: debug_va=0x004765da; { // 0x4765da: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004765db: debug_va=0x004765db; { // 0x4765db: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L004765df: debug_va=0x004765df; { // 0x4765df: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L004765e3: debug_va=0x004765e3; { // 0x4765e3: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),4679142u); flags=s.arithmetic_flags;
  }
  L004765e6: debug_va=0x004765e6; { // 0x4765e6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004765e8: debug_va=0x004765e8; { // 0x4765e8: 7412 JZ 0x004765fc
    if(integer::condition("JZ",flags)) goto L004765fc;
  }
  L004765ea: debug_va=0x004765ea; { // 0x4765ea: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004765ee: debug_va=0x004765ee; { // 0x4765ee: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004765f0: debug_va=0x004765f0; { // 0x4765f0: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004765f1: debug_va=0x004765f1; { // 0x4765f1: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L004765f5: debug_va=0x004765f5; { // 0x4765f5: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004765f9: debug_va=0x004765f9; { // 0x4765f9: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L004765fc: debug_va=0x004765fc; { // 0x4765fc: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00476600: debug_va=0x00476600; { // 0x476600: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00476603: debug_va=0x00476603; { // 0x476603: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L00476605: debug_va=0x00476605; { // 0x476605: 75b6 JNZ 0x004765bd
    if(integer::condition("JNZ",flags)) goto L004765bd;
  }
  L00476607: debug_va=0x00476607; { // 0x476607: 397c2420 CMP dword ptr [ESP + 0x20],EDI
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.di,32,flags);
  }
  L0047660b: debug_va=0x0047660b; { // 0x47660b: 0f8e82000000 JLE 0x00476693
    if(integer::condition("JLE",flags)) goto L00476693;
  }
  L00476611: debug_va=0x00476611; { // 0x476611: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L00476615: debug_va=0x00476615; { // 0x476615: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00476616: debug_va=0x00476616; { // 0x476616: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L0047661a: debug_va=0x0047661a; { // 0x47661a: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0047661e: debug_va=0x0047661e; { // 0x47661e: 8b0cba MOV ECX,dword ptr [EDX + EDI*0x4]
    s.cx = m.r32((s.dx+(s.di * 0x00000004u)));
  }
  L00476621: debug_va=0x00476621; { // 0x476621: e8fa75f9ff CALL 0x0040dc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040dc20u,4679206u); flags=s.arithmetic_flags;
  }
  L00476626: debug_va=0x00476626; { // 0x476626: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00476628: debug_va=0x00476628; { // 0x476628: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L0047662c: debug_va=0x0047662c; { // 0x47662c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0047662e: debug_va=0x0047662e; { // 0x47662e: 7543 JNZ 0x00476673
    if(integer::condition("JNZ",flags)) goto L00476673;
  }
  L00476630: debug_va=0x00476630; { // 0x476630: 8a442438 MOV AL,byte ptr [ESP + 0x38]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000038u)));
  }
  L00476634: debug_va=0x00476634; { // 0x476634: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00476636: debug_va=0x00476636; { // 0x476636: 753b JNZ 0x00476673
    if(integer::condition("JNZ",flags)) goto L00476673;
  }
  L00476638: debug_va=0x00476638; { // 0x476638: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L0047663d: debug_va=0x0047663d; { // 0x47663d: 8a8831140000 MOV CL,byte ptr [EAX + 0x1431]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001431u)));
  }
  L00476643: debug_va=0x00476643; { // 0x476643: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00476645: debug_va=0x00476645; { // 0x476645: 752c JNZ 0x00476673
    if(integer::condition("JNZ",flags)) goto L00476673;
  }
  L00476647: debug_va=0x00476647; { // 0x476647: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00476649: debug_va=0x00476649; { // 0x476649: 743e JZ 0x00476689
    if(integer::condition("JZ",flags)) goto L00476689;
  }
  L0047664b: debug_va=0x0047664b; { // 0x47664b: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L0047664d: debug_va=0x0047664d; { // 0x47664d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0047664f: debug_va=0x0047664f; { // 0x47664f: e82c682500 CALL 0x006cce80
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cce80u,4679252u); flags=s.arithmetic_flags;
  }
  L00476654: debug_va=0x00476654; { // 0x476654: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00476656: debug_va=0x00476656; { // 0x476656: 751b JNZ 0x00476673
    if(integer::condition("JNZ",flags)) goto L00476673;
  }
  L00476658: debug_va=0x00476658; { // 0x476658: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0047665e: debug_va=0x0047665e; { // 0x47665e: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00476663: debug_va=0x00476663; { // 0x476663: 8b9194010000 MOV EDX,dword ptr [ECX + 0x194]
    s.dx = m.r32((s.cx+0x00000194u));
  }
  L00476669: debug_va=0x00476669; { // 0x476669: 8b88b4100000 MOV ECX,dword ptr [EAX + 0x10b4]
    s.cx = m.r32((s.ax+0x000010b4u));
  }
  L0047666f: debug_va=0x0047666f; { // 0x47666f: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00476671: debug_va=0x00476671; { // 0x476671: 7c16 JL 0x00476689
    if(integer::condition("JL",flags)) goto L00476689;
  }
  L00476673: debug_va=0x00476673; { // 0x476673: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00476677: debug_va=0x00476677; { // 0x476677: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0047667b: debug_va=0x0047667b; { // 0x47667b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0047667c: debug_va=0x0047667c; { // 0x47667c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047667d: debug_va=0x0047667d; { // 0x47667d: 8b0cb9 MOV ECX,dword ptr [ECX + EDI*0x4]
    s.cx = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L00476680: debug_va=0x00476680; { // 0x476680: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00476681: debug_va=0x00476681; { // 0x476681: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00476683: debug_va=0x00476683; { // 0x476683: ff925c010000 CALL dword ptr [EDX + 0x15c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000015cu)),4679305u); flags=s.arithmetic_flags;
  }
  L00476689: debug_va=0x00476689; { // 0x476689: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0047668d: debug_va=0x0047668d; { // 0x47668d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0047668e: debug_va=0x0047668e; { // 0x47668e: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00476690: debug_va=0x00476690; { // 0x476690: 7c88 JL 0x0047661a
    if(integer::condition("JL",flags)) goto L0047661a;
  }
  L00476692: debug_va=0x00476692; { // 0x476692: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00476693: debug_va=0x00476693; { // 0x476693: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00476697: debug_va=0x00476697; { // 0x476697: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00476698: debug_va=0x00476698; { // 0x476698: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00476699: debug_va=0x00476699; { // 0x476699: c74424081c597800 MOV dword ptr [ESP + 0x8],0x78591c
    m.w32((f.sp+0x00000008u), 0x0078591cu);
  }
  L004766a1: debug_va=0x004766a1; { // 0x4766a1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004766a3: debug_va=0x004766a3; { // 0x4766a3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004766a4: debug_va=0x004766a4; { // 0x4766a4: 7411 JZ 0x004766b7
    if(integer::condition("JZ",flags)) goto L004766b7;
  }
  L004766a6: debug_va=0x004766a6; { // 0x4766a6: 8a4c2411 MOV CL,byte ptr [ESP + 0x11]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000011u)));
  }
  L004766aa: debug_va=0x004766aa; { // 0x4766aa: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004766ac: debug_va=0x004766ac; { // 0x4766ac: 7409 JZ 0x004766b7
    if(integer::condition("JZ",flags)) goto L004766b7;
  }
  L004766ae: debug_va=0x004766ae; { // 0x4766ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004766af: debug_va=0x004766af; { // 0x4766af: e8c76f2f00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4679348u); flags=s.arithmetic_flags;
  }
  L004766b4: debug_va=0x004766b4; { // 0x4766b4: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004766b7: debug_va=0x004766b7; { // 0x4766b7: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L004766ba: debug_va=0x004766ba; { // 0x4766ba: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
