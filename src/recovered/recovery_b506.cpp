#include "recovery_b212.cpp"
#include "recovery_b506.hpp"
namespace ra2::recovered::recovery_b212 {
namespace {
void invoke506(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00165310(Memory&,State&,Frame&,const Operations&);
void f_00229f70(Memory&,State&,Frame&,const Operations&);
void f_00071260(Memory&,State&,Frame&,const Operations&);
void f_00165310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00565310: { // 0x565310: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00565313: { // 0x565313: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00565317: { // 0x565317: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00565318: { // 0x565318: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00565319: { // 0x565319: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0056531a: { // 0x56531a: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L0056531d: { // 0x56531d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0056531e: { // 0x56531e: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00565322: { // 0x565322: 668b5c241e MOV BX,word ptr [ESP + 0x1e]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x0000001eu)));
  }
  L00565327: { // 0x565327: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L0056532c: { // 0x56532c: 668be9 MOV BP,CX
    s.bp = (s.bp & 0xffff0000u) | (((s.cx & 0xffffu)) & 0xffffu);
  }
  L0056532f: { // 0x56532f: 0fbfc3 MOVSX EAX,BX
    s.ax = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L00565332: { // 0x565332: 0fbfd5 MOVSX EDX,BP
    s.dx = std::uint32_t(integer::sign_extend((s.bp & 0xffffu),16));
  }
  L00565335: { // 0x565335: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00565338: { // 0x565338: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0056533a: { // 0x56533a: 7818 JS 0x00565354
    if(integer::condition("JS",flags)) goto L00565354;
  }
  L0056533c: { // 0x56533c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00565341: { // 0x565341: 7d11 JGE 0x00565354
    if(integer::condition("JGE",flags)) goto L00565354;
  }
  L00565343: { // 0x565343: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L00565349: { // 0x565349: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0056534c: { // 0x56534c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056534e: { // 0x56534e: 7404 JZ 0x00565354
    if(integer::condition("JZ",flags)) goto L00565354;
  }
  L00565350: { // 0x565350: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00565352: { // 0x565352: eb0f JMP 0x00565363
    goto L00565363;
  }
  L00565354: { // 0x565354: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00565358: { // 0x565358: be1076a500 MOV ESI,0xa57610
    s.si = 0x00a57610u;
  }
  L0056535d: { // 0x56535d: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00565363: { // 0x565363: 0fbe861b010000 MOVSX EAX,byte ptr [ESI + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L0056536a: { // 0x56536a: 8d4ffe LEA ECX,[EDI + -0x2]
    s.cx = (s.di-0x00000002u);
  }
  L0056536d: { // 0x56536d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0056536f: { // 0x56536f: 7c45 JL 0x005653b6
    if(integer::condition("JL",flags)) goto L005653b6;
  }
  L00565371: { // 0x565371: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00565373: { // 0x565373: 7f41 JG 0x005653b6
    if(integer::condition("JG",flags)) goto L005653b6;
  }
  L00565375: { // 0x565375: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L00565379: { // 0x565379: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0056537b: { // 0x56537b: 740e JZ 0x0056538b
    if(integer::condition("JZ",flags)) goto L0056538b;
  }
  L0056537d: { // 0x56537d: 8d5624 LEA EDX,[ESI + 0x24]
    s.dx = (s.si+0x00000024u);
  }
  L00565380: { // 0x565380: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00565385: { // 0x565385: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00565386: { // 0x565386: e8e54b0c00 CALL 0x00629f70
    s.arithmetic_flags=flags; invoke506(m,s,f,0x00629f70u,5657483u); flags=s.arithmetic_flags;
  }
  L0056538b: { // 0x56538b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0056538d: { // 0x56538d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0056538f: { // 0x56538f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00565390: { // 0x565390: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00565394: { // 0x565394: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00565398: { // 0x565398: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00565399: { // 0x565399: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0056539d: { // 0x56539d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0056539e: { // 0x56539e: e8bdbef0ff CALL 0x00471260
    s.arithmetic_flags=flags; invoke506(m,s,f,0x00471260u,5657507u); flags=s.arithmetic_flags;
  }
  L005653a3: { // 0x5653a3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005653a5: { // 0x5653a5: 740f JZ 0x005653b6
    if(integer::condition("JZ",flags)) goto L005653b6;
  }
  L005653a7: { // 0x5653a7: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005653ab: { // 0x5653ab: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005653ad: { // 0x5653ad: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005653ae: { // 0x5653ae: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005653b0: { // 0x5653b0: ff9280010000 CALL dword ptr [EDX + 0x180]
    s.arithmetic_flags=flags; invoke506(m,s,f,m.r32((s.dx+0x00000180u)),5657526u); flags=s.arithmetic_flags;
  }
  L005653b6: { // 0x5653b6: 6645 INC BP
    s.bp = (s.bp & 0xffff0000u) | ((integer::increment((s.bp & 0xffffu),16,flags)) & 0xffffu);
  }
  L005653b8: { // 0x5653b8: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L005653bb: { // 0x5653bb: 6643 INC BX
    s.bx = with_ax(s.bx, integer::increment((s.bx & 0xffffu),16,flags));
  }
  L005653bd: { // 0x5653bd: 83ff0f CMP EDI,0xf
    (void)integer::sub(s.di,0x0000000fu,32,flags);
  }
  L005653c0: { // 0x5653c0: 66896c241c MOV word ptr [ESP + 0x1c],BP
    m.w16((f.sp+0x0000001cu), (s.bp & 0xffffu));
  }
  L005653c5: { // 0x5653c5: 66895c241e MOV word ptr [ESP + 0x1e],BX
    m.w16((f.sp+0x0000001eu), (s.bx & 0xffffu));
  }
  L005653ca: { // 0x5653ca: 0f8c5fffffff JL 0x0056532f
    if(integer::condition("JL",flags)) goto L0056532f;
  }
  L005653d0: { // 0x5653d0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005653d1: { // 0x5653d1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005653d2: { // 0x5653d2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005653d3: { // 0x5653d3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005653d4: { // 0x5653d4: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005653d7: { // 0x5653d7: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00229f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00629f70: { // 0x629f70: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00629f73: { // 0x629f73: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00629f74: { // 0x629f74: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00629f75: { // 0x629f75: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00629f76: { // 0x629f76: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00629f78: { // 0x629f78: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00629f7a: { // 0x629f7a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00629f7b: { // 0x629f7b: 39ae18120000 CMP dword ptr [ESI + 0x1218],EBP
    (void)integer::sub(m.r32((s.si+0x00001218u)),s.bp,32,flags);
  }
  L00629f81: { // 0x629f81: 0f848d010000 JZ 0x0062a114
    if(integer::condition("JZ",flags)) goto L0062a114;
  }
  L00629f87: { // 0x629f87: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00629f8b: { // 0x629f8b: 8bbe94140000 MOV EDI,dword ptr [ESI + 0x1494]
    s.di = m.r32((s.si+0x00001494u));
  }
  L00629f91: { // 0x629f91: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00629f95: { // 0x629f95: 0fbf10 MOVSX EDX,word ptr [EAX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00629f98: { // 0x629f98: 8b868c140000 MOV EAX,dword ptr [ESI + 0x148c]
    s.ax = m.r32((s.si+0x0000148cu));
  }
  L00629f9e: { // 0x629f9e: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00629fa0: { // 0x629fa0: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00629fa2: { // 0x629fa2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00629fa4: { // 0x629fa4: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00629fa6: { // 0x629fa6: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00629fa9: { // 0x629fa9: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00629fae: { // 0x629fae: 7504 JNZ 0x00629fb4
    if(integer::condition("JNZ",flags)) goto L00629fb4;
  }
  L00629fb0: { // 0x629fb0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00629fb2: { // 0x629fb2: eb0e JMP 0x00629fc2
    goto L00629fc2;
  }
  L00629fb4: { // 0x629fb4: 8bbe00010000 MOV EDI,dword ptr [ESI + 0x100]
    s.di = m.r32((s.si+0x00000100u));
  }
  L00629fba: { // 0x629fba: 8d7c3fff LEA EDI,[EDI + EDI*0x1 + -0x1]
    s.di = (s.di+(s.di * 0x00000001u)-0x00000001u);
  }
  L00629fbe: { // 0x629fbe: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00629fc0: { // 0x629fc0: 7505 JNZ 0x00629fc7
    if(integer::condition("JNZ",flags)) goto L00629fc7;
  }
  L00629fc2: { // 0x629fc2: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00629fc7: { // 0x629fc7: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00629fcb: { // 0x629fcb: 8b8e40120000 MOV ECX,dword ptr [ESI + 0x1240]
    s.cx = m.r32((s.si+0x00001240u));
  }
  L00629fd1: { // 0x629fd1: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00629fd5: { // 0x629fd5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00629fd6: { // 0x629fd6: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00629fda: { // 0x629fda: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00629fde: { // 0x629fde: 8b863c120000 MOV EAX,dword ptr [ESI + 0x123c]
    s.ax = m.r32((s.si+0x0000123cu));
  }
  L00629fe4: { // 0x629fe4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00629fe5: { // 0x629fe5: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L00629fea: { // 0x629fea: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L00629fee: { // 0x629fee: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00629fef: { // 0x629fef: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L00629ff3: { // 0x629ff3: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00629ff7: { // 0x629ff7: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L00629ffb: { // 0x629ffb: 896c241c MOV dword ptr [ESP + 0x1c],EBP
    m.w32((f.sp+0x0000001cu), s.bp);
  }
  L00629fff: { // 0x629fff: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0062a003: { // 0x62a003: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0062a007: { // 0x62a007: e8e45ddfff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke506(m,s,f,0x0041fdf0u,6463500u); flags=s.arithmetic_flags;
  }
  L0062a00c: { // 0x62a00c: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0062a00e: { // 0x62a00e: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0062a012: { // 0x62a012: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0062a015: { // 0x62a015: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0062a019: { // 0x62a019: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0062a01c: { // 0x62a01c: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0062a020: { // 0x62a020: 8b8e18120000 MOV ECX,dword ptr [ESI + 0x1218]
    s.cx = m.r32((s.si+0x00001218u));
  }
  L0062a026: { // 0x62a026: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0062a029: { // 0x62a029: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0062a02d: { // 0x62a02d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0062a02f: { // 0x62a02f: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke506(m,s,f,m.r32((s.ax+0x0000007cu)),6463538u); flags=s.arithmetic_flags;
  }
  L0062a032: { // 0x62a032: 8b8e18120000 MOV ECX,dword ptr [ESI + 0x1218]
    s.cx = m.r32((s.si+0x00001218u));
  }
  L0062a038: { // 0x62a038: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0062a03a: { // 0x62a03a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0062a03c: { // 0x62a03c: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke506(m,s,f,m.r32((s.dx+0x00000080u)),6463554u); flags=s.arithmetic_flags;
  }
  L0062a042: { // 0x62a042: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L0062a046: { // 0x62a046: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0062a04a: { // 0x62a04a: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L0062a04c: { // 0x62a04c: 0f8ec2000000 JLE 0x0062a114
    if(integer::condition("JLE",flags)) goto L0062a114;
  }
  L0062a052: { // 0x62a052: 396c2430 CMP dword ptr [ESP + 0x30],EBP
    (void)integer::sub(m.r32((f.sp+0x00000030u)),s.bp,32,flags);
  }
  L0062a056: { // 0x62a056: 0f8eb8000000 JLE 0x0062a114
    if(integer::condition("JLE",flags)) goto L0062a114;
  }
  L0062a05c: { // 0x62a05c: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a060: { // 0x62a060: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a066: { // 0x62a066: e8e5091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke506(m,s,f,0x0076aa50u,6463595u); flags=s.arithmetic_flags;
  }
  L0062a06b: { // 0x62a06b: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0062a06f: { // 0x62a06f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062a070: { // 0x62a070: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0062a072: { // 0x62a072: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L0062a074: { // 0x62a074: 0f9cc1 SETL CL
    s.cx = with_al(s.cx, (integer::condition("JL",flags)?1u:0u));
  }
  L0062a077: { // 0x62a077: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0062a079: { // 0x62a079: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062a07a: { // 0x62a07a: 895c2448 MOV dword ptr [ESP + 0x48],EBX
    m.w32((f.sp+0x00000048u), s.bx);
  }
  L0062a07e: { // 0x62a07e: 23c8 AND ECX,EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L0062a080: { // 0x62a080: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a084: { // 0x62a084: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0062a088: { // 0x62a088: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a08e: { // 0x62a08e: e8bd091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke506(m,s,f,0x0076aa50u,6463635u); flags=s.arithmetic_flags;
  }
  L0062a093: { // 0x62a093: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062a094: { // 0x62a094: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062a096: { // 0x62a096: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0062a098: { // 0x62a098: 7c02 JL 0x0062a09c
    if(integer::condition("JL",flags)) goto L0062a09c;
  }
  L0062a09a: { // 0x62a09a: 8bef MOV EBP,EDI
    s.bp = s.di;
  }
  L0062a09c: { // 0x62a09c: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a0a0: { // 0x62a0a0: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a0a6: { // 0x62a0a6: e8a5091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke506(m,s,f,0x0076aa50u,6463659u); flags=s.arithmetic_flags;
  }
  L0062a0ab: { // 0x62a0ab: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062a0ac: { // 0x62a0ac: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0062a0ae: { // 0x62a0ae: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0062a0b2: { // 0x62a0b2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062a0b4: { // 0x62a0b4: 0f9cc3 SETL BL
    s.bx = with_al(s.bx, (integer::condition("JL",flags)?1u:0u));
  }
  L0062a0b7: { // 0x62a0b7: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0062a0b8: { // 0x62a0b8: 23d8 AND EBX,EAX
    s.bx = integer::logical((s.bx)&(s.ax),32,flags);
  }
  L0062a0ba: { // 0x62a0ba: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0062a0be: { // 0x62a0be: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0062a0c0: { // 0x62a0c0: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0062a0c4: { // 0x62a0c4: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a0c8: { // 0x62a0c8: d88e84140000 FMUL float ptr [ESI + 0x1484]
    const auto address=(s.si+0x00001484u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a0ce: { // 0x62a0ce: e87d091400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke506(m,s,f,0x0076aa50u,6463699u); flags=s.arithmetic_flags;
  }
  L0062a0d3: { // 0x62a0d3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0062a0d7: { // 0x62a0d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062a0d8: { // 0x62a0d8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062a0da: { // 0x62a0da: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0062a0de: { // 0x62a0de: 7c04 JL 0x0062a0e4
    if(integer::condition("JL",flags)) goto L0062a0e4;
  }
  L0062a0e0: { // 0x62a0e0: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0062a0e4: { // 0x62a0e4: 3b5c2448 CMP EBX,dword ptr [ESP + 0x48]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000048u)),32,flags);
  }
  L0062a0e8: { // 0x62a0e8: 7d2a JGE 0x0062a114
    if(integer::condition("JGE",flags)) goto L0062a114;
  }
  L0062a0ea: { // 0x62a0ea: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L0062a0ee: { // 0x62a0ee: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0062a0f0: { // 0x62a0f0: 7d19 JGE 0x0062a10b
    if(integer::condition("JGE",flags)) goto L0062a10b;
  }
  L0062a0f2: { // 0x62a0f2: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L0062a0f6: { // 0x62a0f6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0062a0f8: { // 0x62a0f8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0062a0f9: { // 0x62a0f9: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0062a0fd: { // 0x62a0fd: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L0062a101: { // 0x62a101: e89afbffff CALL 0x00629ca0
    s.arithmetic_flags=flags; invoke506(m,s,f,0x00629ca0u,6463750u); flags=s.arithmetic_flags;
  }
  L0062a106: { // 0x62a106: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0062a107: { // 0x62a107: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0062a109: { // 0x62a109: 7ce7 JL 0x0062a0f2
    if(integer::condition("JL",flags)) goto L0062a0f2;
  }
  L0062a10b: { // 0x62a10b: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0062a10f: { // 0x62a10f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0062a110: { // 0x62a110: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0062a112: { // 0x62a112: 7cd6 JL 0x0062a0ea
    if(integer::condition("JL",flags)) goto L0062a0ea;
  }
  L0062a114: { // 0x62a114: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062a115: { // 0x62a115: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062a116: { // 0x62a116: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062a117: { // 0x62a117: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062a118: { // 0x62a118: 83c434 ADD ESP,0x34
    f.sp = integer::add(f.sp,0x00000034u,32,flags);
  }
  L0062a11b: { // 0x62a11b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00071260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00471260: { // 0x471260: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00471261: { // 0x471261: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00471263: { // 0x471263: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00471266: { // 0x471266: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  L00471269: { // 0x471269: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0047126c: { // 0x47126c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0047126d: { // 0x47126d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047126e: { // 0x47126e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047126f: { // 0x47126f: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00471271: { // 0x471271: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00471273: { // 0x471273: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471277: { // 0x471277: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0047127b: { // 0x47127b: 8d3cc500000000 LEA EDI,[EAX*0x8 + 0x0]
    s.di = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L00471282: { // 0x471282: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00471284: { // 0x471284: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00471287: { // 0x471287: 8d1cc500000000 LEA EBX,[EAX*0x8 + 0x0]
    s.bx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  L0047128e: { // 0x47128e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00471290: { // 0x471290: 8a450c MOV AL,byte ptr [EBP + 0xc]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000000cu)));
  }
  L00471293: { // 0x471293: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00471295: { // 0x471295: 7408 JZ 0x0047129f
    if(integer::condition("JZ",flags)) goto L0047129f;
  }
  L00471297: { // 0x471297: 8b89e8000000 MOV ECX,dword ptr [ECX + 0xe8]
    s.cx = m.r32((s.cx+0x000000e8u));
  }
  L0047129d: { // 0x47129d: eb06 JMP 0x004712a5
    goto L004712a5;
  }
  L0047129f: { // 0x47129f: 8b89e4000000 MOV ECX,dword ptr [ECX + 0xe4]
    s.cx = m.r32((s.cx+0x000000e4u));
  }
  L004712a5: { // 0x4712a5: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L004712a7: { // 0x4712a7: 0f84a2000000 JZ 0x0047134f
    if(integer::condition("JZ",flags)) goto L0047134f;
  }
  L004712ad: { // 0x4712ad: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004712af: { // 0x4712af: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004712b1: { // 0x4712b1: 0f8480000000 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712b7: { // 0x4712b7: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  L004712ba: { // 0x4712ba: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L004712bc: { // 0x4712bc: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  L004712c0: { // 0x4712c0: 7475 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c2: { // 0x4712c2: 3b7510 CMP ESI,dword ptr [EBP + 0x10]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  L004712c5: { // 0x4712c5: 7470 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712c7: { // 0x4712c7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004712c9: { // 0x4712c9: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L004712cd: { // 0x4712cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004712ce: { // 0x4712ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004712d0: { // 0x4712d0: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke506(m,s,f,m.r32((s.dx+0x00000048u)),4657875u); flags=s.arithmetic_flags;
  }
  L004712d3: { // 0x4712d3: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L004712d5: { // 0x4712d5: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004712d8: { // 0x4712d8: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L004712da: { // 0x4712da: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004712df: { // 0x4712df: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L004712e2: { // 0x4712e2: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L004712e4: { // 0x4712e4: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004712ea: { // 0x4712ea: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004712ee: { // 0x4712ee: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L004712f0: { // 0x4712f0: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L004712f3: { // 0x4712f3: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L004712f7: { // 0x4712f7: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L004712fb: { // 0x4712fb: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  L004712ff: { // 0x4712ff: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00471303: { // 0x471303: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00471305: { // 0x471305: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L00471307: { // 0x471307: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00471309: { // 0x471309: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L0047130b: { // 0x47130b: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0047130d: { // 0x47130d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00471310: { // 0x471310: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471312: { // 0x471312: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00471314: { // 0x471314: e8678d0400 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke506(m,s,f,0x004ba080u,4657945u); flags=s.arithmetic_flags;
  }
  L00471319: { // 0x471319: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0047131c: { // 0x47131c: e82f972f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke506(m,s,f,0x0076aa50u,4657953u); flags=s.arithmetic_flags;
  }
  L00471321: { // 0x471321: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L00471325: { // 0x471325: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00471327: { // 0x471327: 7406 JZ 0x0047132f
    if(integer::condition("JZ",flags)) goto L0047132f;
  }
  L00471329: { // 0x471329: 3b442418 CMP EAX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  L0047132d: { // 0x47132d: 7d08 JGE 0x00471337
    if(integer::condition("JGE",flags)) goto L00471337;
  }
  L0047132f: { // 0x47132f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00471333: { // 0x471333: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00471337: { // 0x471337: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L0047133a: { // 0x47133a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047133c: { // 0x47133c: 0f8575ffffff JNZ 0x004712b7
    if(integer::condition("JNZ",flags)) goto L004712b7;
  }
  L00471342: { // 0x471342: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00471346: { // 0x471346: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471347: { // 0x471347: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471348: { // 0x471348: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471349: { // 0x471349: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0047134b: { // 0x47134b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0047134c: { // 0x47134c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047134f: { // 0x47134f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00471351: { // 0x471351: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00471352: { // 0x471352: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00471353: { // 0x471353: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00471354: { // 0x471354: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00471356: { // 0x471356: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00471357: { // 0x471357: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void invoke506(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 if(target!=0x629f70&&target!=0x471260){invoke(m,s,f,target,continuation);return;}
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 if(target==0x629f70)f_00229f70(m,s,child,{});else f_00071260(m,s,child,{});
 f.sp=child.sp;
}
std::uint32_t run506(Memory&original,const Inputs&i,bool scan){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry,entry,0x76543210u};m.w32(entry,f.outer_return);
 for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,i.arg[k]);
 if(scan)f_00165310(m,s,f,{});else f_00229f70(m,s,f,{});
 i.fp=s.fp;for(unsigned k=0;k<16;++k)i.arg[k]=m.r32(entry+4+4*k);
 return s.ax;
}
}
}
namespace ra2::recovered::recovery_b506 {
std::uint32_t fun_00629f70(Memory&m,const Inputs&i){return recovery_b212::run506(m,i,false);}
std::uint32_t fun_00565310(Memory&m,const Inputs&i){return recovery_b212::run506(m,i,true);}
}
