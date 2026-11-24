void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_001f84d0(Memory&,State&,Frame&,const Operations&);
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112d0(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_000312f0(Memory&,State&,Frame&,const Operations&);
void f_00031310(Memory&,State&,Frame&,const Operations&);
void f_00031320(Memory&,State&,Frame&,const Operations&);
void f_00031370(Memory&,State&,Frame&,const Operations&);
void f_00031550(Memory&,State&,Frame&,const Operations&);
void f_000315d0(Memory&,State&,Frame&,const Operations&);
void f_00031790(Memory&,State&,Frame&,const Operations&);
void f_000317a0(Memory&,State&,Frame&,const Operations&);
void f_00031b80(Memory&,State&,Frame&,const Operations&);
void f_00031ec0(Memory&,State&,Frame&,const Operations&);
void f_00031f70(Memory&,State&,Frame&,const Operations&);
void f_00032010(Memory&,State&,Frame&,const Operations&);
void f_00032210(Memory&,State&,Frame&,const Operations&);
void f_00035420(Memory&,State&,Frame&,const Operations&);
void f_00053ab0(Memory&,State&,Frame&,const Operations&);
void f_001f5e90(Memory&,State&,Frame&,const Operations&);
void f_00234310(Memory&,State&,Frame&,const Operations&);
void f_0035fcd0(Memory&,State&,Frame&,const Operations&);
void f_0035fd00(Memory&,State&,Frame&,const Operations&);
void f_0036ef45(Memory&,State&,Frame&,const Operations&);
void f_0036ef62(Memory&,State&,Frame&,const Operations&);
void f_0036f190(Memory&,State&,Frame&,const Operations&);

void f_001f84d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005f84d0: { // 0x5f84d0: b830100000 MOV EAX, 0x1030
    s.ax = 0x00001030u;
  }
  L005f84d5: { // 0x5f84d5: e8b66c1700 CALL 0x76f190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076f190u,6259930u,op); flags=s.arithmetic_flags;
  }
  L005f84da: { // 0x5f84da: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005f84de: { // 0x5f84de: c7442410ffffffff MOV dword ptr [ESP + 0x10], 0xffffffff
    m.w32((f.sp+0x00000010u), 0xffffffffu);
  }
  L005f84e6: { // 0x5f84e6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f84e7: { // 0x5f84e7: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f84e8: { // 0x5f84e8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f84e9: { // 0x5f84e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f84ea: { // 0x5f84ea: 8bbc2444100000 MOV EDI, dword ptr [ESP + 0x1044]
    s.di = m.r32((f.sp+0x00001044u));
  }
  L005f84f1: { // 0x5f84f1: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005f84f3: { // 0x5f84f3: 3bfb CMP EDI, EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L005f84f5: { // 0x5f84f5: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L005f84f7: { // 0x5f84f7: 895c2410 MOV dword ptr [ESP + 0x10], EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005f84fb: { // 0x5f84fb: 895c2418 MOV dword ptr [ESP + 0x18], EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L005f84ff: { // 0x5f84ff: 7505 JNZ 0x5f8506
    if(integer::condition("JNZ",flags)) goto L005f8506;
  }
  L005f8501: { // 0x5f8501: bf8c208200 MOV EDI, 0x82208c
    s.di = 0x0082208cu;
  }
  L005f8506: { // 0x5f8506: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f8507: { // 0x5f8507: e8396a1700 CALL 0x76ef45
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef45u,6259980u,op); flags=s.arithmetic_flags;
  }
  L005f850c: { // 0x5f850c: 8bac244c100000 MOV EBP, dword ptr [ESP + 0x104c]
    s.bp = m.r32((f.sp+0x0000104cu));
  }
  L005f8513: { // 0x5f8513: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L005f8516: { // 0x5f8516: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L005f8518: { // 0x5f8518: 7c04 JL 0x5f851e
    if(integer::condition("JL",flags)) goto L005f851e;
  }
  L005f851a: { // 0x5f851a: 3be8 CMP EBP, EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L005f851c: { // 0x5f851c: 7e02 JLE 0x5f8520
    if(integer::condition("JLE",flags)) goto L005f8520;
  }
  L005f851e: { // 0x5f851e: 33ed XOR EBP, EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L005f8520: { // 0x5f8520: 8b842458100000 MOV EAX, dword ptr [ESP + 0x1058]
    s.ax = m.r32((f.sp+0x00001058u));
  }
  L005f8527: { // 0x5f8527: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f8529: { // 0x5f8529: 741a JZ 0x5f8545
    if(integer::condition("JZ",flags)) goto L005f8545;
  }
  L005f852b: { // 0x5f852b: e8c0441300 CALL 0x72c9f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0072c9f0u,6260016u,op); flags=s.arithmetic_flags;
  }
  L005f8530: { // 0x5f8530: a164deb000 MOV EAX, dword ptr [0xb0de64]
    s.ax = m.r32((0x00b0de64u));
  }
  L005f8535: { // 0x5f8535: 8b0d6cdeb000 MOV ECX, dword ptr [0xb0de6c]
    s.cx = m.r32((0x00b0de6cu));
  }
  L005f853b: { // 0x5f853b: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005f853f: { // 0x5f853f: 894c2418 MOV dword ptr [ESP + 0x18], ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005f8543: { // 0x5f8543: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L005f8545: { // 0x5f8545: 6800080000 PUSH 0x800
    f.push(m,0x00000800u);
  }
  L005f854a: { // 0x5f854a: 8d542444 LEA EDX, [ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L005f854e: { // 0x5f854e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f854f: { // 0x5f854f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f8550: { // 0x5f8550: 66c744244c0000 MOV word ptr [ESP + 0x4c], 0
    m.w16((f.sp+0x0000004cu), 0u);
  }
  L005f8557: { // 0x5f8557: e8066a1700 CALL 0x76ef62
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef62u,6260060u,op); flags=s.arithmetic_flags;
  }
  L005f855c: { // 0x5f855c: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005f855f: { // 0x5f855f: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005f8561: { // 0x5f8561: 7435 JZ 0x5f8598
    if(integer::condition("JZ",flags)) goto L005f8598;
  }
  L005f8563: { // 0x5f8563: b800080000 MOV EAX, 0x800
    s.ax = 0x00000800u;
  }
  L005f8568: { // 0x5f8568: 8d4c6c40 LEA ECX, [ESP + EBP*2 + 0x40]
    s.cx = (f.sp+(s.bp * 2u)+0x00000040u);
  }
  L005f856c: { // 0x5f856c: 2bc5 SUB EAX, EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L005f856e: { // 0x5f856e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f856f: { // 0x5f856f: 6820dcb000 PUSH 0xb0dc20
    f.push(m,0x00b0dc20u);
  }
  L005f8574: { // 0x5f8574: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f8575: { // 0x5f8575: e8e8691700 CALL 0x76ef62
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef62u,6260090u,op); flags=s.arithmetic_flags;
  }
  L005f857a: { // 0x5f857a: ba00080000 MOV EDX, 0x800
    s.dx = 0x00000800u;
  }
  L005f857f: { // 0x5f857f: 8d0c2b LEA ECX, [EBX + EBP]
    s.cx = (s.bx+s.bp);
  }
  L005f8582: { // 0x5f8582: 2bd3 SUB EDX, EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L005f8584: { // 0x5f8584: 8d046f LEA EAX, [EDI + EBP*2]
    s.ax = (s.di+(s.bp * 2u));
  }
  L005f8587: { // 0x5f8587: 2bd5 SUB EDX, EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L005f8589: { // 0x5f8589: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f858a: { // 0x5f858a: 8d544c50 LEA EDX, [ESP + ECX*2 + 0x50]
    s.dx = (f.sp+(s.cx * 2u)+0x00000050u);
  }
  L005f858e: { // 0x5f858e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f858f: { // 0x5f858f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f8590: { // 0x5f8590: e8cd691700 CALL 0x76ef62
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef62u,6260117u,op); flags=s.arithmetic_flags;
  }
  L005f8595: { // 0x5f8595: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L005f8598: { // 0x5f8598: 8d442440 LEA EAX, [ESP + 0x40]
    s.ax = (f.sp+0x00000040u);
  }
  L005f859c: { // 0x5f859c: 66c784243e1000000000 MOV word ptr [ESP + 0x103e], 0
    m.w16((f.sp+0x0000103eu), 0u);
  }
  L005f85a6: { // 0x5f85a6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f85a7: { // 0x5f85a7: e899691700 CALL 0x76ef45
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef45u,6260140u,op); flags=s.arithmetic_flags;
  }
  L005f85ac: { // 0x5f85ac: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005f85ae: { // 0x5f85ae: 8b842460100000 MOV EAX, dword ptr [ESP + 0x1060]
    s.ax = m.r32((f.sp+0x00001060u));
  }
  L005f85b5: { // 0x5f85b5: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L005f85b8: { // 0x5f85b8: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L005f85bc: { // 0x5f85bc: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f85be: { // 0x5f85be: 7418 JZ 0x5f85d8
    if(integer::condition("JZ",flags)) goto L005f85d8;
  }
  L005f85c0: { // 0x5f85c0: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005f85c2: { // 0x5f85c2: 7e14 JLE 0x5f85d8
    if(integer::condition("JLE",flags)) goto L005f85d8;
  }
  L005f85c4: { // 0x5f85c4: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L005f85c6: { // 0x5f85c6: b82a002a00 MOV EAX, 0x2a002a
    s.ax = 0x002a002au;
  }
  L005f85cb: { // 0x5f85cb: 8d7c2440 LEA EDI, [ESP + 0x40]
    s.di = (f.sp+0x00000040u);
  }
  L005f85cf: { // 0x5f85cf: d1e9 SHR ECX, 1
    s.cx = integer::shift(s.cx,1u,32,flags,integer::Shift::right);
  }
  L005f85d1: { // 0x5f85d1: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L005f85d3: { // 0x5f85d3: 13c9 ADC ECX, ECX
    s.cx = integer::add(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  L005f85d5: { // 0x5f85d5: 66f3ab STOSW.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,16u,Repeat::count);
  }
  L005f85d8: { // 0x5f85d8: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005f85dc: { // 0x5f85dc: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f85de: { // 0x5f85de: 750c JNZ 0x5f85ec
    if(integer::condition("JNZ",flags)) goto L005f85ec;
  }
  L005f85e0: { // 0x5f85e0: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005f85e2: { // 0x5f85e2: 7508 JNZ 0x5f85ec
    if(integer::condition("JNZ",flags)) goto L005f85ec;
  }
  L005f85e4: { // 0x5f85e4: 8bc5 MOV EAX, EBP
    s.ax = s.bp;
  }
  L005f85e6: { // 0x5f85e6: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005f85ea: { // 0x5f85ea: eb0e JMP 0x5f85fa
    goto L005f85fa;
  }
  L005f85ec: { // 0x5f85ec: 8b0d68deb000 MOV ECX, dword ptr [0xb0de68]
    s.cx = m.r32((0x00b0de68u));
  }
  L005f85f2: { // 0x5f85f2: 03cd ADD ECX, EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L005f85f4: { // 0x5f85f4: 894c2428 MOV dword ptr [ESP + 0x28], ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005f85f8: { // 0x5f85f8: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L005f85fa: { // 0x5f85fa: 8b9c2454100000 MOV EBX, dword ptr [ESP + 0x1054]
    s.bx = m.r32((f.sp+0x00001054u));
  }
  L005f8601: { // 0x5f8601: 8b0b MOV ECX, dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L005f8603: { // 0x5f8603: 83c105 ADD ECX, 5
    s.cx = integer::add(s.cx,5u,32,flags);
  }
  L005f8606: { // 0x5f8606: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005f8608: { // 0x5f8608: 7d12 JGE 0x5f861c
    if(integer::condition("JGE",flags)) goto L005f861c;
  }
  L005f860a: { // 0x5f860a: 83f805 CMP EAX, 5
    (void)integer::sub(s.ax,5u,32,flags);
  }
  L005f860d: { // 0x5f860d: 7c07 JL 0x5f8616
    if(integer::condition("JL",flags)) goto L005f8616;
  }
  L005f860f: { // 0x5f860f: 83c0fb ADD EAX, -5
    s.ax = integer::add(s.ax,4294967291u,32,flags);
  }
  L005f8612: { // 0x5f8612: 8903 MOV dword ptr [EBX], EAX
    m.w32((s.bx), s.ax);
  }
  L005f8614: { // 0x5f8614: eb06 JMP 0x5f861c
    goto L005f861c;
  }
  L005f8616: { // 0x5f8616: c70300000000 MOV dword ptr [EBX], 0
    m.w32((s.bx), 0u);
  }
  L005f861c: { // 0x5f861c: 3913 CMP dword ptr [EBX], EDX
    (void)integer::sub(m.r32((s.bx)),s.dx,32,flags);
  }
  L005f861e: { // 0x5f861e: 7d39 JGE 0x5f8659
    if(integer::condition("JGE",flags)) goto L005f8659;
  }
  L005f8620: { // 0x5f8620: 8b3b MOV EDI, dword ptr [EBX]
    s.di = m.r32((s.bx));
  }
  L005f8622: { // 0x5f8622: 8b5608 MOV EDX, dword ptr [ESI + 8]
    s.dx = m.r32((s.si+8u));
  }
  L005f8625: { // 0x5f8625: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L005f8627: { // 0x5f8627: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f8629: { // 0x5f8629: 83ea05 SUB EDX, 5
    s.dx = integer::sub(s.dx,5u,32,flags);
  }
  L005f862c: { // 0x5f862c: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f862e: { // 0x5f862e: 8d4c4448 LEA ECX, [ESP + EAX*2 + 0x48]
    s.cx = (f.sp+(s.ax * 2u)+0x00000048u);
  }
  L005f8632: { // 0x5f8632: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f8633: { // 0x5f8633: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f8634: { // 0x5f8634: 8b8c245c100000 MOV ECX, dword ptr [ESP + 0x105c]
    s.cx = m.r32((f.sp+0x0000105cu));
  }
  L005f863b: { // 0x5f863b: e8908fe3ff CALL 0x4315d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004315d0u,6260288u,op); flags=s.arithmetic_flags;
  }
  L005f8640: { // 0x5f8640: 8b542428 MOV EDX, dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L005f8644: { // 0x5f8644: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L005f8646: { // 0x5f8646: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L005f8648: { // 0x5f8648: 7d0b JGE 0x5f8655
    if(integer::condition("JGE",flags)) goto L005f8655;
  }
  L005f864a: { // 0x5f864a: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005f864e: { // 0x5f864e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005f864f: { // 0x5f864f: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L005f8651: { // 0x5f8651: 893b MOV dword ptr [EBX], EDI
    m.w32((s.bx), s.di);
  }
  L005f8653: { // 0x5f8653: 7ccb JL 0x5f8620
    if(integer::condition("JL",flags)) goto L005f8620;
  }
  L005f8655: { // 0x5f8655: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005f8659: { // 0x5f8659: 8b0b MOV ECX, dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L005f865b: { // 0x5f865b: 8bc5 MOV EAX, EBP
    s.ax = s.bp;
  }
  L005f865d: { // 0x5f865d: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005f865f: { // 0x5f865f: 8b7c2410 MOV EDI, dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L005f8663: { // 0x5f8663: b900000000 MOV ECX, 0
    s.cx = 0u;
  }
  L005f8668: { // 0x5f8668: 0f98c1 SETS CL
    s.cx = with_al(s.cx, (integer::condition("SETS",flags)?1u:0u));
  }
  L005f866b: { // 0x5f866b: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005f866c: { // 0x5f866c: 23c8 AND ECX, EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L005f866e: { // 0x5f866e: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005f8672: { // 0x5f8672: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L005f8674: { // 0x5f8674: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f8676: { // 0x5f8676: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005f867a: { // 0x5f867a: 7d11 JGE 0x5f868d
    if(integer::condition("JGE",flags)) goto L005f868d;
  }
  L005f867c: { // 0x5f867c: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L005f867e: { // 0x5f867e: b900000000 MOV ECX, 0
    s.cx = 0u;
  }
  L005f8683: { // 0x5f8683: 0f98c1 SETS CL
    s.cx = with_al(s.cx, (integer::condition("SETS",flags)?1u:0u));
  }
  L005f8686: { // 0x5f8686: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005f8687: { // 0x5f8687: 23c8 AND ECX, EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L005f8689: { // 0x5f8689: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005f868d: { // 0x5f868d: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L005f868f: { // 0x5f868f: 2bd5 SUB EDX, EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L005f8691: { // 0x5f8691: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f8693: { // 0x5f8693: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005f8697: { // 0x5f8697: 7d06 JGE 0x5f869f
    if(integer::condition("JGE",flags)) goto L005f869f;
  }
  L005f8699: { // 0x5f8699: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f869b: { // 0x5f869b: 89542418 MOV dword ptr [ESP + 0x18], EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005f869f: { // 0x5f869f: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005f86a1: { // 0x5f86a1: 7d08 JGE 0x5f86ab
    if(integer::condition("JGE",flags)) goto L005f86ab;
  }
  L005f86a3: { // 0x5f86a3: c744241800000000 MOV dword ptr [ESP + 0x18], 0
    m.w32((f.sp+0x00000018u), 0u);
  }
  L005f86ab: { // 0x5f86ab: 8b03 MOV EAX, dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L005f86ad: { // 0x5f86ad: 8d7c4440 LEA EDI, [ESP + EAX*2 + 0x40]
    s.di = (f.sp+(s.ax * 2u)+0x00000040u);
  }
  L005f86b1: { // 0x5f86b1: 8b842460100000 MOV EAX, dword ptr [ESP + 0x1060]
    s.ax = m.r32((f.sp+0x00001060u));
  }
  L005f86b8: { // 0x5f86b8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f86ba: { // 0x5f86ba: 7443 JZ 0x5f86ff
    if(integer::condition("JZ",flags)) goto L005f86ff;
  }
  L005f86bc: { // 0x5f86bc: 8b6e0c MOV EBP, dword ptr [ESI + 0xc]
    s.bp = m.r32((s.si+0x0000000cu));
  }
  L005f86bf: { // 0x5f86bf: 8b8c244c100000 MOV ECX, dword ptr [ESP + 0x104c]
    s.cx = m.r32((f.sp+0x0000104cu));
  }
  L005f86c6: { // 0x5f86c6: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f86c8: { // 0x5f86c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f86c9: { // 0x5f86c9: 83c502 ADD EBP, 2
    s.bp = integer::add(s.bp,2u,32,flags);
  }
  L005f86cc: { // 0x5f86cc: e87f8ee3ff CALL 0x431550
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431550u,6260433u,op); flags=s.arithmetic_flags;
  }
  L005f86d1: { // 0x5f86d1: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f86d3: { // 0x5f86d3: 8b4e04 MOV ECX, dword ptr [ESI + 4]
    s.cx = m.r32((s.si+4u));
  }
  L005f86d6: { // 0x5f86d6: 83c005 ADD EAX, 5
    s.ax = integer::add(s.ax,5u,32,flags);
  }
  L005f86d9: { // 0x5f86d9: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005f86da: { // 0x5f86da: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005f86db: { // 0x5f86db: 89442438 MOV dword ptr [ESP + 0x38], EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L005f86df: { // 0x5f86df: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L005f86e3: { // 0x5f86e3: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005f86e7: { // 0x5f86e7: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L005f86eb: { // 0x5f86eb: 8d442430 LEA EAX, [ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L005f86ef: { // 0x5f86ef: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005f86f1: { // 0x5f86f1: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f86f3: { // 0x5f86f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f86f4: { // 0x5f86f4: 896c2444 MOV dword ptr [ESP + 0x44], EBP
    m.w32((f.sp+0x00000044u), s.bp);
  }
  L005f86f8: { // 0x5f86f8: ff5214 CALL dword ptr [EDX + 0x14]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000014u)),6260475u,op); flags=s.arithmetic_flags;
  }
  L005f86fb: { // 0x5f86fb: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f86ff: { // 0x5f86ff: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005f8703: { // 0x5f8703: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f8705: { // 0x5f8705: 744b JZ 0x5f8752
    if(integer::condition("JZ",flags)) goto L005f8752;
  }
  L005f8707: { // 0x5f8707: 8b8c2464100000 MOV ECX, dword ptr [ESP + 0x1064]
    s.cx = m.r32((f.sp+0x00001064u));
  }
  L005f870e: { // 0x5f870e: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L005f8712: { // 0x5f8712: 8b94244c100000 MOV EDX, dword ptr [ESP + 0x104c]
    s.dx = m.r32((f.sp+0x0000104cu));
  }
  L005f8719: { // 0x5f8719: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f871a: { // 0x5f871a: 8b8c2454100000 MOV ECX, dword ptr [ESP + 0x1054]
    s.cx = m.r32((f.sp+0x00001054u));
  }
  L005f8721: { // 0x5f8721: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f8722: { // 0x5f8722: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f8724: { // 0x5f8724: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f8726: { // 0x5f8726: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f8727: { // 0x5f8727: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f8728: { // 0x5f8728: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f8729: { // 0x5f8729: e862d7ffff CALL 0x5f5e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f5e90u,6260526u,op); flags=s.arithmetic_flags;
  }
  L005f872e: { // 0x5f872e: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f8730: { // 0x5f8730: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L005f8733: { // 0x5f8733: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f8735: { // 0x5f8735: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005f8737: { // 0x5f8737: 8916 MOV dword ptr [ESI], EDX
    m.w32((s.si), s.dx);
  }
  L005f8739: { // 0x5f8739: 894e08 MOV dword ptr [ESI + 8], ECX
    m.w32((s.si+8u), s.cx);
  }
  L005f873c: { // 0x5f873c: 7907 JNS 0x5f8745
    if(integer::condition("JNS",flags)) goto L005f8745;
  }
  L005f873e: { // 0x5f873e: c7460800000000 MOV dword ptr [ESI + 8], 0
    m.w32((s.si+8u), 0u);
  }
  L005f8745: { // 0x5f8745: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005f8749: { // 0x5f8749: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f874d: { // 0x5f874d: 8d3c57 LEA EDI, [EDI + EDX*2]
    s.di = (s.di+(s.dx * 2u));
  }
  L005f8750: { // 0x5f8750: eb04 JMP 0x5f8756
    goto L005f8756;
  }
  L005f8752: { // 0x5f8752: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L005f8756: { // 0x5f8756: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005f8758: { // 0x5f8758: 0f84b1000000 JZ 0x5f880f
    if(integer::condition("JZ",flags)) goto L005f880f;
  }
  L005f875e: { // 0x5f875e: 8b13 MOV EDX, dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L005f8760: { // 0x5f8760: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005f8764: { // 0x5f8764: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f8766: { // 0x5f8766: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005f876a: { // 0x5f876a: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f876c: { // 0x5f876c: 7810 JS 0x5f877e
    if(integer::condition("JS",flags)) goto L005f877e;
  }
  L005f876e: { // 0x5f876e: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005f8770: { // 0x5f8770: 7f0c JG 0x5f877e
    if(integer::condition("JG",flags)) goto L005f877e;
  }
  L005f8772: { // 0x5f8772: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L005f8774: { // 0x5f8774: 2bd8 SUB EBX, EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L005f8776: { // 0x5f8776: 2bcb SUB ECX, EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L005f8778: { // 0x5f8778: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005f877c: { // 0x5f877c: eb03 JMP 0x5f8781
    goto L005f8781;
  }
  L005f877e: { // 0x5f877e: 83cbff OR EBX, 0xffffffff
    s.bx = integer::logical((s.bx)|(0xffffffffu),32,flags);
  }
  L005f8781: { // 0x5f8781: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005f8783: { // 0x5f8783: 7e40 JLE 0x5f87c5
    if(integer::condition("JLE",flags)) goto L005f87c5;
  }
  L005f8785: { // 0x5f8785: 8b842464100000 MOV EAX, dword ptr [ESP + 0x1064]
    s.ax = m.r32((f.sp+0x00001064u));
  }
  L005f878c: { // 0x5f878c: 8b94244c100000 MOV EDX, dword ptr [ESP + 0x104c]
    s.dx = m.r32((f.sp+0x0000104cu));
  }
  L005f8793: { // 0x5f8793: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f8794: { // 0x5f8794: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f8795: { // 0x5f8795: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f8797: { // 0x5f8797: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f8799: { // 0x5f8799: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f879a: { // 0x5f879a: 8b0da8dca500 MOV ECX, dword ptr [0xa5dca8]
    s.cx = m.r32((0x00a5dca8u));
  }
  L005f87a0: { // 0x5f87a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f87a1: { // 0x5f87a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f87a2: { // 0x5f87a2: e8e9d6ffff CALL 0x5f5e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f5e90u,6260647u,op); flags=s.arithmetic_flags;
  }
  L005f87a7: { // 0x5f87a7: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f87a9: { // 0x5f87a9: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L005f87ac: { // 0x5f87ac: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f87ae: { // 0x5f87ae: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005f87b0: { // 0x5f87b0: 8916 MOV dword ptr [ESI], EDX
    m.w32((s.si), s.dx);
  }
  L005f87b2: { // 0x5f87b2: 894e08 MOV dword ptr [ESI + 8], ECX
    m.w32((s.si+8u), s.cx);
  }
  L005f87b5: { // 0x5f87b5: 7907 JNS 0x5f87be
    if(integer::condition("JNS",flags)) goto L005f87be;
  }
  L005f87b7: { // 0x5f87b7: c7460800000000 MOV dword ptr [ESI + 8], 0
    m.w32((s.si+8u), 0u);
  }
  L005f87be: { // 0x5f87be: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f87c2: { // 0x5f87c2: 8d3c4f LEA EDI, [EDI + ECX*2]
    s.di = (s.di+(s.cx * 2u));
  }
  L005f87c5: { // 0x5f87c5: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005f87c7: { // 0x5f87c7: 7c4c JL 0x5f8815
    if(integer::condition("JL",flags)) goto L005f8815;
  }
  L005f87c9: { // 0x5f87c9: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f87cb: { // 0x5f87cb: 89542420 MOV dword ptr [ESP + 0x20], EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L005f87cf: { // 0x5f87cf: 7444 JZ 0x5f8815
    if(integer::condition("JZ",flags)) goto L005f8815;
  }
  L005f87d1: { // 0x5f87d1: 8b842464100000 MOV EAX, dword ptr [ESP + 0x1064]
    s.ax = m.r32((f.sp+0x00001064u));
  }
  L005f87d8: { // 0x5f87d8: 8b94244c100000 MOV EDX, dword ptr [ESP + 0x104c]
    s.dx = m.r32((f.sp+0x0000104cu));
  }
  L005f87df: { // 0x5f87df: 8b0da8dca500 MOV ECX, dword ptr [0xa5dca8]
    s.cx = m.r32((0x00a5dca8u));
  }
  L005f87e5: { // 0x5f87e5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f87e6: { // 0x5f87e6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f87e7: { // 0x5f87e7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f87e9: { // 0x5f87e9: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f87eb: { // 0x5f87eb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f87ec: { // 0x5f87ec: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f87ed: { // 0x5f87ed: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f87ee: { // 0x5f87ee: e89dd6ffff CALL 0x5f5e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f5e90u,6260723u,op); flags=s.arithmetic_flags;
  }
  L005f87f3: { // 0x5f87f3: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f87f5: { // 0x5f87f5: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L005f87f8: { // 0x5f87f8: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f87fa: { // 0x5f87fa: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005f87fc: { // 0x5f87fc: 8916 MOV dword ptr [ESI], EDX
    m.w32((s.si), s.dx);
  }
  L005f87fe: { // 0x5f87fe: 894e08 MOV dword ptr [ESI + 8], ECX
    m.w32((s.si+8u), s.cx);
  }
  L005f8801: { // 0x5f8801: 7907 JNS 0x5f880a
    if(integer::condition("JNS",flags)) goto L005f880a;
  }
  L005f8803: { // 0x5f8803: c7460800000000 MOV dword ptr [ESI + 8], 0
    m.w32((s.si+8u), 0u);
  }
  L005f880a: { // 0x5f880a: 8d3c5f LEA EDI, [EDI + EBX*2]
    s.di = (s.di+(s.bx * 2u));
  }
  L005f880d: { // 0x5f880d: eb06 JMP 0x5f8815
    goto L005f8815;
  }
  L005f880f: { // 0x5f880f: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005f8811: { // 0x5f8811: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L005f8815: { // 0x5f8815: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005f8819: { // 0x5f8819: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f881b: { // 0x5f881b: 743a JZ 0x5f8857
    if(integer::condition("JZ",flags)) goto L005f8857;
  }
  L005f881d: { // 0x5f881d: 8b942464100000 MOV EDX, dword ptr [ESP + 0x1064]
    s.dx = m.r32((f.sp+0x00001064u));
  }
  L005f8824: { // 0x5f8824: 8b8c2450100000 MOV ECX, dword ptr [ESP + 0x1050]
    s.cx = m.r32((f.sp+0x00001050u));
  }
  L005f882b: { // 0x5f882b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f882c: { // 0x5f882c: 8b942450100000 MOV EDX, dword ptr [ESP + 0x1050]
    s.dx = m.r32((f.sp+0x00001050u));
  }
  L005f8833: { // 0x5f8833: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f8834: { // 0x5f8834: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f8836: { // 0x5f8836: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005f8838: { // 0x5f8838: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f8839: { // 0x5f8839: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f883a: { // 0x5f883a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f883b: { // 0x5f883b: e850d6ffff CALL 0x5f5e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f5e90u,6260800u,op); flags=s.arithmetic_flags;
  }
  L005f8840: { // 0x5f8840: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f8842: { // 0x5f8842: 8b4e08 MOV ECX, dword ptr [ESI + 8]
    s.cx = m.r32((s.si+8u));
  }
  L005f8845: { // 0x5f8845: 03d0 ADD EDX, EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f8847: { // 0x5f8847: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005f8849: { // 0x5f8849: 8916 MOV dword ptr [ESI], EDX
    m.w32((s.si), s.dx);
  }
  L005f884b: { // 0x5f884b: 894e08 MOV dword ptr [ESI + 8], ECX
    m.w32((s.si+8u), s.cx);
  }
  L005f884e: { // 0x5f884e: 7907 JNS 0x5f8857
    if(integer::condition("JNS",flags)) goto L005f8857;
  }
  L005f8850: { // 0x5f8850: c7460800000000 MOV dword ptr [ESI + 8], 0
    m.w32((s.si+8u), 0u);
  }
  L005f8857: { // 0x5f8857: 8b8c2458100000 MOV ECX, dword ptr [ESP + 0x1058]
    s.cx = m.r32((f.sp+0x00001058u));
  }
  L005f885e: { // 0x5f885e: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f8860: { // 0x5f8860: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L005f8862: { // 0x5f8862: 0f849c000000 JZ 0x5f8904
    if(integer::condition("JZ",flags)) goto L005f8904;
  }
  L005f8868: { // 0x5f8868: 8b7c2420 MOV EDI, dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L005f886c: { // 0x5f886c: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L005f886e: { // 0x5f886e: 0f8e90000000 JLE 0x5f8904
    if(integer::condition("JLE",flags)) goto L005f8904;
  }
  L005f8874: { // 0x5f8874: 390540dfa500 CMP dword ptr [0xa5df40], EAX
    (void)integer::sub(m.r32((0x00a5df40u)),s.ax,32,flags);
  }
  L005f887a: { // 0x5f887a: 0f8584000000 JNZ 0x5f8904
    if(integer::condition("JNZ",flags)) goto L005f8904;
  }
  L005f8880: { // 0x5f8880: 8b4604 MOV EAX, dword ptr [ESI + 4]
    s.ax = m.r32((s.si+4u));
  }
  L005f8883: { // 0x5f8883: 8b4e0c MOV ECX, dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L005f8886: { // 0x5f8886: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L005f888a: { // 0x5f888a: 68ff000000 PUSH 0xff
    f.push(m,0x000000ffu);
  }
  L005f888f: { // 0x5f888f: 8d5408fe LEA EDX, [EAX + ECX - 2]
    s.dx = (s.ax+s.cx-2u);
  }
  L005f8893: { // 0x5f8893: a1ecaea500 MOV EAX, dword ptr [0xa5aeec]
    s.ax = m.r32((0x00a5aeecu));
  }
  L005f8898: { // 0x5f8898: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L005f889c: { // 0x5f889c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f889d: { // 0x5f889d: 8954242c MOV dword ptr [ESP + 0x2c], EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005f88a1: { // 0x5f88a1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f88a2: { // 0x5f88a2: 8d542424 LEA EDX, [ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005f88a6: { // 0x5f88a6: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005f88a8: { // 0x5f88a8: 897c242c MOV dword ptr [ESP + 0x2c], EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L005f88ac: { // 0x5f88ac: 897c2424 MOV dword ptr [ESP + 0x24], EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L005f88b0: { // 0x5f88b0: e8bbc6ffff CALL 0x5f4f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f4f70u,6260917u,op); flags=s.arithmetic_flags;
  }
  L005f88b5: { // 0x5f88b5: 8b4e04 MOV ECX, dword ptr [ESI + 4]
    s.cx = m.r32((s.si+4u));
  }
  L005f88b8: { // 0x5f88b8: 8b560c MOV EDX, dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L005f88bb: { // 0x5f88bb: 8d4701 LEA EAX, [EDI + 1]
    s.ax = (s.di+1u);
  }
  L005f88be: { // 0x5f88be: 894c241c MOV dword ptr [ESP + 0x1c], ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005f88c2: { // 0x5f88c2: 89442420 MOV dword ptr [ESP + 0x20], EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005f88c6: { // 0x5f88c6: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005f88ca: { // 0x5f88ca: a1ecaea500 MOV EAX, dword ptr [0xa5aeec]
    s.ax = m.r32((0x00a5aeecu));
  }
  L005f88cf: { // 0x5f88cf: 8d5411fe LEA EDX, [ECX + EDX - 2]
    s.dx = (s.cx+s.dx-2u);
  }
  L005f88d3: { // 0x5f88d3: 68ff000000 PUSH 0xff
    f.push(m,0x000000ffu);
  }
  L005f88d8: { // 0x5f88d8: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L005f88dc: { // 0x5f88dc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f88dd: { // 0x5f88dd: 8954242c MOV dword ptr [ESP + 0x2c], EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L005f88e1: { // 0x5f88e1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f88e2: { // 0x5f88e2: 8d542424 LEA EDX, [ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L005f88e6: { // 0x5f88e6: 8bcd MOV ECX, EBP
    s.cx = s.bp;
  }
  L005f88e8: { // 0x5f88e8: e883c6ffff CALL 0x5f4f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f4f70u,6260973u,op); flags=s.arithmetic_flags;
  }
  L005f88ed: { // 0x5f88ed: c70540dfa50000000000 MOV dword ptr [0xa5df40], 0
    m.w32((0x00a5df40u), 0u);
  }
  L005f88f7: { // 0x5f88f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f88f8: { // 0x5f88f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f88f9: { // 0x5f88f9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f88fa: { // 0x5f88fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f88fb: { // 0x5f88fb: 81c430100000 ADD ESP, 0x1030
    f.sp = integer::add(f.sp,0x00001030u,32,flags);
  }
  L005f8901: { // 0x5f8901: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
  L005f8904: { // 0x5f8904: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f8905: { // 0x5f8905: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f8906: { // 0x5f8906: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f8907: { // 0x5f8907: a340dfa500 MOV dword ptr [0xa5df40], EAX
    m.w32((0x00a5df40u), s.ax);
  }
  L005f890c: { // 0x5f890c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f890d: { // 0x5f890d: 81c430100000 ADD ESP, 0x1030
    f.sp = integer::add(f.sp,0x00001030u,32,flags);
  }
  L005f8913: { // 0x5f8913: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
}

void f_00011290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411290: { // 0x411290: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00411294: { // 0x411294: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411295: { // 0x411295: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411296: { // 0x411296: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411297: { // 0x411297: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0041129a: { // 0x41129a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L0041129d: { // 0x41129d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0041129f: { // 0x41129f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004112a1: { // 0x4112a1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004112a3: { // 0x4112a3: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L004112a5: { // 0x4112a5: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L004112a8: { // 0x4112a8: 897b08 MOV dword ptr [EBX + 0x8],EDI
    m.w32((s.bx+0x00000008u), s.di);
  }
  L004112ab: { // 0x4112ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004112ac: { // 0x4112ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004112ad: { // 0x4112ad: 894b0c MOV dword ptr [EBX + 0xc],ECX
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L004112b0: { // 0x4112b0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004112b1: { // 0x4112b1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000112d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112d0: { // 0x4112d0: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L004112d3: { // 0x4112d3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000112f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112f0: { // 0x4112f0: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L004112f3: { // 0x4112f3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004112f4: { // 0x4112f4: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004112f7: { // 0x4112f7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004112f9: { // 0x4112f9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    s.di = m.r32((s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u,op); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    s.bx = integer::imul(s.bx,m.r32((f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u,op); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x4113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x4113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x4113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x4113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u,op); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x4113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x4113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x4113cd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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

void f_000312f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004312f0: { // 0x4312f0: 668b542404 MOV DX,word ptr [ESP + 0x4]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000004u)));
  }
  L004312f5: { // 0x4312f5: 668b4124 MOV AX,word ptr [ECX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.cx+0x00000024u)));
  }
  L004312f9: { // 0x4312f9: 66895124 MOV word ptr [ECX + 0x24],DX
    m.w16((s.cx+0x00000024u), (s.dx & 0xffffu));
  }
  L004312fd: { // 0x4312fd: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431310: { // 0x431310: 8a542404 MOV DL,byte ptr [ESP + 0x4]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000004u)));
  }
  L00431314: { // 0x431314: 8a4141 MOV AL,byte ptr [ECX + 0x41]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000041u)));
  }
  L00431317: { // 0x431317: 885141 MOV byte ptr [ECX + 0x41],DL
    m.w8((s.cx+0x00000041u), (s.dx & 0xffu));
  }
  L0043131a: { // 0x43131a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431320: { // 0x431320: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00431324: { // 0x431324: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431326: { // 0x431326: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00431328: { // 0x431328: 741a JZ 0x00431344
    if(integer::condition("JZ",flags)) goto L00431344;
  }
  L0043132a: { // 0x43132a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0043132c: { // 0x43132c: 895130 MOV dword ptr [ECX + 0x30],EDX
    m.w32((s.cx+0x00000030u), s.dx);
  }
  L0043132f: { // 0x43132f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00431332: { // 0x431332: 895134 MOV dword ptr [ECX + 0x34],EDX
    m.w32((s.cx+0x00000034u), s.dx);
  }
  L00431335: { // 0x431335: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00431338: { // 0x431338: 895138 MOV dword ptr [ECX + 0x38],EDX
    m.w32((s.cx+0x00000038u), s.dx);
  }
  L0043133b: { // 0x43133b: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0043133e: { // 0x43133e: 89413c MOV dword ptr [ECX + 0x3c],EAX
    m.w32((s.cx+0x0000003cu), s.ax);
  }
  L00431341: { // 0x431341: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00431344: { // 0x431344: 89513c MOV dword ptr [ECX + 0x3c],EDX
    m.w32((s.cx+0x0000003cu), s.dx);
  }
  L00431347: { // 0x431347: 895138 MOV dword ptr [ECX + 0x38],EDX
    m.w32((s.cx+0x00000038u), s.dx);
  }
  L0043134a: { // 0x43134a: 895134 MOV dword ptr [ECX + 0x34],EDX
    m.w32((s.cx+0x00000034u), s.dx);
  }
  L0043134d: { // 0x43134d: 895130 MOV dword ptr [ECX + 0x30],EDX
    m.w32((s.cx+0x00000030u), s.dx);
  }
  L00431350: { // 0x431350: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00031370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431370: { // 0x431370: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00431373: { // 0x431373: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00431376: { // 0x431376: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431378: { // 0x431378: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043137a: { // 0x43137a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0043137b: { // 0x43137b: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L0043137f: { // 0x43137f: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00431383: { // 0x431383: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431387: { // 0x431387: 0f847b010000 JZ 0x00431508
    if(integer::condition("JZ",flags)) goto L00431508;
  }
  L0043138d: { // 0x43138d: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L00431391: { // 0x431391: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00431393: { // 0x431393: 0f846f010000 JZ 0x00431508
    if(integer::condition("JZ",flags)) goto L00431508;
  }
  L00431399: { // 0x431399: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  L0043139c: { // 0x43139c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0043139d: { // 0x43139d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043139e: { // 0x43139e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043139f: { // 0x43139f: 668b3b MOV DI,word ptr [EBX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L004313a2: { // 0x4313a2: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004313a4: { // 0x4313a4: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004313a6: { // 0x4313a6: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L004313a9: { // 0x4313a9: 6685ff TEST DI,DI
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L004313ac: { // 0x4313ac: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L004313b0: { // 0x4313b0: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004313b4: { // 0x4313b4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004313b8: { // 0x4313b8: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L004313bc: { // 0x4313bc: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004313c0: { // 0x4313c0: 0f841a010000 JZ 0x004314e0
    if(integer::condition("JZ",flags)) goto L004314e0;
  }
  L004313c6: { // 0x4313c6: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L004313cc: { // 0x4313cc: 8d47f7 LEA EAX,[EDI + -0x9]
    s.ax = (s.di-0x00000009u);
  }
  L004313cf: { // 0x4313cf: 83f817 CMP EAX,0x17
    (void)integer::sub(s.ax,0x00000017u,32,flags);
  }
  L004313d2: { // 0x4313d2: 7751 JA 0x00431425
    if(integer::condition("JA",flags)) goto L00431425;
  }
  L004313d4: { // 0x4313d4: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004313d6: { // 0x4313d6: 8a8838154300 MOV CL,byte ptr [EAX + 0x431538]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00431538u)));
  }
  L004313dc: { // 0x4313dc: ff248d28154300 JMP dword ptr [ECX*0x4 + 0x431528]
    switch(m.r32(((s.cx * 0x00000004u)+0x00431528u))){
    case 0x00431370u: goto L00431370;
    case 0x00431373u: goto L00431373;
    case 0x00431376u: goto L00431376;
    case 0x00431378u: goto L00431378;
    case 0x0043137au: goto L0043137a;
    case 0x0043137bu: goto L0043137b;
    case 0x0043137fu: goto L0043137f;
    case 0x00431383u: goto L00431383;
    case 0x00431387u: goto L00431387;
    case 0x0043138du: goto L0043138d;
    case 0x00431391u: goto L00431391;
    case 0x00431393u: goto L00431393;
    case 0x00431399u: goto L00431399;
    case 0x0043139cu: goto L0043139c;
    case 0x0043139du: goto L0043139d;
    case 0x0043139eu: goto L0043139e;
    case 0x0043139fu: goto L0043139f;
    case 0x004313a2u: goto L004313a2;
    case 0x004313a4u: goto L004313a4;
    case 0x004313a6u: goto L004313a6;
    case 0x004313a9u: goto L004313a9;
    case 0x004313acu: goto L004313ac;
    case 0x004313b0u: goto L004313b0;
    case 0x004313b4u: goto L004313b4;
    case 0x004313b8u: goto L004313b8;
    case 0x004313bcu: goto L004313bc;
    case 0x004313c0u: goto L004313c0;
    case 0x004313c6u: goto L004313c6;
    case 0x004313ccu: goto L004313cc;
    case 0x004313cfu: goto L004313cf;
    case 0x004313d2u: goto L004313d2;
    case 0x004313d4u: goto L004313d4;
    case 0x004313d6u: goto L004313d6;
    case 0x004313dcu: goto L004313dc;
    case 0x004313e3u: goto L004313e3;
    case 0x004313e7u: goto L004313e7;
    case 0x004313edu: goto L004313ed;
    case 0x004313f1u: goto L004313f1;
    case 0x004313f5u: goto L004313f5;
    case 0x004313f7u: goto L004313f7;
    case 0x004313f9u: goto L004313f9;
    case 0x004313fbu: goto L004313fb;
    case 0x004313ffu: goto L004313ff;
    case 0x00431404u: goto L00431404;
    case 0x00431408u: goto L00431408;
    case 0x0043140bu: goto L0043140b;
    case 0x0043140du: goto L0043140d;
    case 0x0043140fu: goto L0043140f;
    case 0x00431410u: goto L00431410;
    case 0x00431412u: goto L00431412;
    case 0x00431414u: goto L00431414;
    case 0x00431419u: goto L00431419;
    case 0x0043141du: goto L0043141d;
    case 0x00431421u: goto L00431421;
    case 0x00431425u: goto L00431425;
    case 0x00431429u: goto L00431429;
    case 0x0043142bu: goto L0043142b;
    case 0x0043142du: goto L0043142d;
    case 0x0043142fu: goto L0043142f;
    case 0x00431432u: goto L00431432;
    case 0x00431434u: goto L00431434;
    case 0x00431438u: goto L00431438;
    case 0x0043143au: goto L0043143a;
    case 0x0043143cu: goto L0043143c;
    case 0x00431440u: goto L00431440;
    case 0x00431441u: goto L00431441;
    case 0x00431444u: goto L00431444;
    case 0x00431447u: goto L00431447;
    case 0x0043144au: goto L0043144a;
    case 0x0043144cu: goto L0043144c;
    case 0x0043144eu: goto L0043144e;
    case 0x00431452u: goto L00431452;
    case 0x00431455u: goto L00431455;
    case 0x00431457u: goto L00431457;
    case 0x00431459u: goto L00431459;
    case 0x0043145du: goto L0043145d;
    case 0x0043145fu: goto L0043145f;
    case 0x00431461u: goto L00431461;
    case 0x00431462u: goto L00431462;
    case 0x00431465u: goto L00431465;
    case 0x00431467u: goto L00431467;
    case 0x0043146au: goto L0043146a;
    case 0x0043146cu: goto L0043146c;
    case 0x00431470u: goto L00431470;
    case 0x00431472u: goto L00431472;
    case 0x00431474u: goto L00431474;
    case 0x00431476u: goto L00431476;
    case 0x00431478u: goto L00431478;
    case 0x0043147cu: goto L0043147c;
    case 0x0043147eu: goto L0043147e;
    case 0x00431480u: goto L00431480;
    case 0x00431483u: goto L00431483;
    case 0x00431485u: goto L00431485;
    case 0x00431489u: goto L00431489;
    case 0x0043148bu: goto L0043148b;
    case 0x0043148fu: goto L0043148f;
    case 0x00431491u: goto L00431491;
    case 0x00431494u: goto L00431494;
    case 0x00431496u: goto L00431496;
    case 0x00431498u: goto L00431498;
    case 0x0043149au: goto L0043149a;
    case 0x0043149du: goto L0043149d;
    case 0x004314a1u: goto L004314a1;
    case 0x004314a3u: goto L004314a3;
    case 0x004314a7u: goto L004314a7;
    case 0x004314abu: goto L004314ab;
    case 0x004314afu: goto L004314af;
    case 0x004314b1u: goto L004314b1;
    case 0x004314b3u: goto L004314b3;
    case 0x004314b5u: goto L004314b5;
    case 0x004314b9u: goto L004314b9;
    case 0x004314bdu: goto L004314bd;
    case 0x004314bfu: goto L004314bf;
    case 0x004314c3u: goto L004314c3;
    case 0x004314c5u: goto L004314c5;
    case 0x004314c9u: goto L004314c9;
    case 0x004314ccu: goto L004314cc;
    case 0x004314d0u: goto L004314d0;
    case 0x004314d3u: goto L004314d3;
    case 0x004314d7u: goto L004314d7;
    case 0x004314dau: goto L004314da;
    case 0x004314e0u: goto L004314e0;
    case 0x004314e4u: goto L004314e4;
    case 0x004314e5u: goto L004314e5;
    case 0x004314e6u: goto L004314e6;
    case 0x004314e7u: goto L004314e7;
    case 0x004314e9u: goto L004314e9;
    case 0x004314ebu: goto L004314eb;
    case 0x004314efu: goto L004314ef;
    case 0x004314f1u: goto L004314f1;
    case 0x004314f5u: goto L004314f5;
    case 0x004314f7u: goto L004314f7;
    case 0x004314f9u: goto L004314f9;
    case 0x004314fdu: goto L004314fd;
    case 0x004314ffu: goto L004314ff;
    case 0x00431501u: goto L00431501;
    case 0x00431502u: goto L00431502;
    case 0x00431505u: goto L00431505;
    case 0x00431508u: goto L00431508;
    case 0x0043150cu: goto L0043150c;
    case 0x0043150eu: goto L0043150e;
    case 0x00431510u: goto L00431510;
    case 0x00431512u: goto L00431512;
    case 0x00431516u: goto L00431516;
    case 0x00431518u: goto L00431518;
    case 0x0043151au: goto L0043151a;
    case 0x0043151cu: goto L0043151c;
    case 0x0043151eu: goto L0043151e;
    case 0x0043151fu: goto L0043151f;
    case 0x00431522u: goto L00431522;
    default:throw std::domain_error("recovery107 unsupported switch destination");}
  }
  L004313e3: { // 0x4313e3: 6683fa0d CMP DX,0xd
    (void)integer::sub((s.dx & 0xffffu),0x0000000du,16,flags);
  }
  L004313e7: { // 0x4313e7: 0f84dc000000 JZ 0x004314c9
    if(integer::condition("JZ",flags)) goto L004314c9;
  }
  L004313ed: { // 0x4313ed: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L004313f1: { // 0x4313f1: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004313f5: { // 0x4313f5: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004313f7: { // 0x4313f7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004313f9: { // 0x4313f9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004313fb: { // 0x4313fb: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004313ff: { // 0x4313ff: e9c5000000 JMP 0x004314c9
    goto L004314c9;
  }
  L00431404: { // 0x431404: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00431408: { // 0x431408: 8b7828 MOV EDI,dword ptr [EAX + 0x28]
    s.di = m.r32((s.ax+0x00000028u));
  }
  L0043140b: { // 0x43140b: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0043140d: { // 0x43140d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0043140f: { // 0x43140f: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00431410: { // 0x431410: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00431412: { // 0x431412: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L00431414: { // 0x431414: e9b0000000 JMP 0x004314c9
    goto L004314c9;
  }
  L00431419: { // 0x431419: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L0043141d: { // 0x43141d: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L00431421: { // 0x431421: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00431425: { // 0x431425: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00431429: { // 0x431429: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043142b: { // 0x43142b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043142d: { // 0x43142d: 741b JZ 0x0043144a
    if(integer::condition("JZ",flags)) goto L0043144a;
  }
  L0043142f: { // 0x43142f: 8b4918 MOV ECX,dword ptr [ECX + 0x18]
    s.cx = m.r32((s.cx+0x00000018u));
  }
  L00431432: { // 0x431432: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431434: { // 0x431434: 668b1479 MOV DX,word ptr [ECX + EDI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+(s.di * 0x00000002u))));
  }
  L00431438: { // 0x431438: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043143a: { // 0x43143a: 740e JZ 0x0043144a
    if(integer::condition("JZ",flags)) goto L0043144a;
  }
  L0043143c: { // 0x43143c: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00431440: { // 0x431440: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00431441: { // 0x431441: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L00431444: { // 0x431444: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00431447: { // 0x431447: 03411c ADD EAX,dword ptr [ECX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L0043144a: { // 0x43144a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043144c: { // 0x43144c: 750b JNZ 0x00431459
    if(integer::condition("JNZ",flags)) goto L00431459;
  }
  L0043144e: { // 0x43144e: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00431452: { // 0x431452: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00431455: { // 0x431455: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431457: { // 0x431457: 7470 JZ 0x004314c9
    if(integer::condition("JZ",flags)) goto L004314c9;
  }
  L00431459: { // 0x431459: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0043145d: { // 0x43145d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0043145f: { // 0x43145f: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  L00431461: { // 0x431461: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00431462: { // 0x431462: 8b522c MOV EDX,dword ptr [EDX + 0x2c]
    s.dx = m.r32((s.dx+0x0000002cu));
  }
  L00431465: { // 0x431465: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00431467: { // 0x431467: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L0043146a: { // 0x43146a: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0043146c: { // 0x43146c: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L00431470: { // 0x431470: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431472: { // 0x431472: 744b JZ 0x004314bf
    if(integer::condition("JZ",flags)) goto L004314bf;
  }
  L00431474: { // 0x431474: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431476: { // 0x431476: 7e47 JLE 0x004314bf
    if(integer::condition("JLE",flags)) goto L004314bf;
  }
  L00431478: { // 0x431478: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043147c: { // 0x43147c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043147e: { // 0x43147e: 7411 JZ 0x00431491
    if(integer::condition("JZ",flags)) goto L00431491;
  }
  L00431480: { // 0x431480: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00431483: { // 0x431483: 7e22 JLE 0x004314a7
    if(integer::condition("JLE",flags)) goto L004314a7;
  }
  L00431485: { // 0x431485: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00431489: { // 0x431489: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0043148b: { // 0x43148b: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0043148f: { // 0x43148f: eb16 JMP 0x004314a7
    goto L004314a7;
  }
  L00431491: { // 0x431491: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L00431494: { // 0x431494: 7e07 JLE 0x0043149d
    if(integer::condition("JLE",flags)) goto L0043149d;
  }
  L00431496: { // 0x431496: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00431498: { // 0x431498: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0043149a: { // 0x43149a: 83eb02 SUB EBX,0x2
    s.bx = integer::sub(s.bx,0x00000002u,32,flags);
  }
  L0043149d: { // 0x43149d: 3b742430 CMP ESI,dword ptr [ESP + 0x30]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004314a1: { // 0x4314a1: 7e04 JLE 0x004314a7
    if(integer::condition("JLE",flags)) goto L004314a7;
  }
  L004314a3: { // 0x4314a3: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L004314a7: { // 0x4314a7: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L004314ab: { // 0x4314ab: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L004314af: { // 0x4314af: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004314b1: { // 0x4314b1: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004314b3: { // 0x4314b3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004314b5: { // 0x4314b5: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L004314b9: { // 0x4314b9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L004314bd: { // 0x4314bd: eb0a JMP 0x004314c9
    goto L004314c9;
  }
  L004314bf: { // 0x4314bf: 3b742430 CMP ESI,dword ptr [ESP + 0x30]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000030u)),32,flags);
  }
  L004314c3: { // 0x4314c3: 7e04 JLE 0x004314c9
    if(integer::condition("JLE",flags)) goto L004314c9;
  }
  L004314c5: { // 0x4314c5: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L004314c9: { // 0x4314c9: 668b3b MOV DI,word ptr [EBX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L004314cc: { // 0x4314cc: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L004314d0: { // 0x4314d0: 83c302 ADD EBX,0x2
    s.bx = integer::add(s.bx,0x00000002u,32,flags);
  }
  L004314d3: { // 0x4314d3: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004314d7: { // 0x4314d7: 6685ff TEST DI,DI
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L004314da: { // 0x4314da: 0f85e6feffff JNZ 0x004313c6
    if(integer::condition("JNZ",flags)) goto L004313c6;
  }
  L004314e0: { // 0x4314e0: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L004314e4: { // 0x4314e4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004314e5: { // 0x4314e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004314e6: { // 0x4314e6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004314e7: { // 0x4314e7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004314e9: { // 0x4314e9: 7406 JZ 0x004314f1
    if(integer::condition("JZ",flags)) goto L004314f1;
  }
  L004314eb: { // 0x4314eb: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L004314ef: { // 0x4314ef: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004314f1: { // 0x4314f1: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L004314f5: { // 0x4314f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004314f7: { // 0x4314f7: 7406 JZ 0x004314ff
    if(integer::condition("JZ",flags)) goto L004314ff;
  }
  L004314f9: { // 0x4314f9: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L004314fd: { // 0x4314fd: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004314ff: { // 0x4314ff: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00431501: { // 0x431501: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431502: { // 0x431502: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00431505: { // 0x431505: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00431508: { // 0x431508: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0043150c: { // 0x43150c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0043150e: { // 0x43150e: 7402 JZ 0x00431512
    if(integer::condition("JZ",flags)) goto L00431512;
  }
  L00431510: { // 0x431510: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00431512: { // 0x431512: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00431516: { // 0x431516: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00431518: { // 0x431518: 7402 JZ 0x0043151c
    if(integer::condition("JZ",flags)) goto L0043151c;
  }
  L0043151a: { // 0x43151a: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0043151c: { // 0x43151c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043151e: { // 0x43151e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043151f: { // 0x43151f: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00431522: { // 0x431522: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00031550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431550: { // 0x431550: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431554: { // 0x431554: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L00431558: { // 0x431558: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431559: { // 0x431559: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0043155d: { // 0x43155d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0043155f: { // 0x43155f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00431560: { // 0x431560: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431561: { // 0x431561: e80afeffff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,4396390u,op); flags=s.arithmetic_flags;
  }
  L00431566: { // 0x431566: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0043156a: { // 0x43156a: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_000315d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004315d0: { // 0x4315d0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L004315d3: { // 0x4315d3: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L004315d5: { // 0x4315d5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004315d6: { // 0x4315d6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004315d7: { // 0x4315d7: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L004315d9: { // 0x4315d9: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  L004315dc: { // 0x4315dc: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L004315e0: { // 0x4315e0: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L004315e2: { // 0x4315e2: 896c2408 MOV dword ptr [ESP + 0x8],EBP
    m.w32((f.sp+0x00000008u), s.bp);
  }
  L004315e6: { // 0x4315e6: 0f8425010000 JZ 0x00431711
    if(integer::condition("JZ",flags)) goto L00431711;
  }
  L004315ec: { // 0x4315ec: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L004315f0: { // 0x4315f0: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L004315f2: { // 0x4315f2: 0f8419010000 JZ 0x00431711
    if(integer::condition("JZ",flags)) goto L00431711;
  }
  L004315f8: { // 0x4315f8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004315f9: { // 0x4315f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004315fa: { // 0x4315fa: 668b39 MOV DI,word ptr [ECX]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.cx))) & 0xffffu);
  }
  L004315fd: { // 0x4315fd: 663bfd CMP DI,BP
    (void)integer::sub((s.di & 0xffffu),(s.bp & 0xffffu),16,flags);
  }
  L00431600: { // 0x431600: 0f84fd000000 JZ 0x00431703
    if(integer::condition("JZ",flags)) goto L00431703;
  }
  L00431606: { // 0x431606: eb04 JMP 0x0043160c
    goto L0043160c;
  }
  L00431608: { // 0x431608: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0043160c: { // 0x43160c: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0043160e: { // 0x43160e: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L00431614: { // 0x431614: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00431616: { // 0x431616: 83e809 SUB EAX,0x9
    s.ax = integer::sub(s.ax,0x00000009u,32,flags);
  }
  L00431619: { // 0x431619: 7449 JZ 0x00431664
    if(integer::condition("JZ",flags)) goto L00431664;
  }
  L0043161b: { // 0x43161b: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0043161c: { // 0x43161c: 7452 JZ 0x00431670
    if(integer::condition("JZ",flags)) goto L00431670;
  }
  L0043161e: { // 0x43161e: 83e803 SUB EAX,0x3
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00431621: { // 0x431621: 744d JZ 0x00431670
    if(integer::condition("JZ",flags)) goto L00431670;
  }
  L00431623: { // 0x431623: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00431625: { // 0x431625: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00431627: { // 0x431627: 741b JZ 0x00431644
    if(integer::condition("JZ",flags)) goto L00431644;
  }
  L00431629: { // 0x431629: 8b4b18 MOV ECX,dword ptr [EBX + 0x18]
    s.cx = m.r32((s.bx+0x00000018u));
  }
  L0043162c: { // 0x43162c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043162e: { // 0x43162e: 668b1471 MOV DX,word ptr [ECX + ESI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+(s.si * 0x00000002u))));
  }
  L00431632: { // 0x431632: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431634: { // 0x431634: 740a JZ 0x00431640
    if(integer::condition("JZ",flags)) goto L00431640;
  }
  L00431636: { // 0x431636: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L00431639: { // 0x431639: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0043163a: { // 0x43163a: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L0043163d: { // 0x43163d: 03431c ADD EAX,dword ptr [EBX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.bx+0x0000001cu)),32,flags);
  }
  L00431640: { // 0x431640: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L00431644: { // 0x431644: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431646: { // 0x431646: 750b JNZ 0x00431653
    if(integer::condition("JNZ",flags)) goto L00431653;
  }
  L00431648: { // 0x431648: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0043164c: { // 0x43164c: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L0043164f: { // 0x43164f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431651: { // 0x431651: 741d JZ 0x00431670
    if(integer::condition("JZ",flags)) goto L00431670;
  }
  L00431653: { // 0x431653: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431655: { // 0x431655: 8a10 MOV DL,byte ptr [EAX]
    s.dx = with_al(s.dx, m.r8((s.ax)));
  }
  L00431657: { // 0x431657: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0043165b: { // 0x43165b: 8b402c MOV EAX,dword ptr [EAX + 0x2c]
    s.ax = m.r32((s.ax+0x0000002cu));
  }
  L0043165e: { // 0x43165e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00431660: { // 0x431660: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L00431662: { // 0x431662: eb0c JMP 0x00431670
    goto L00431670;
  }
  L00431664: { // 0x431664: 8b7228 MOV ESI,dword ptr [EDX + 0x28]
    s.si = m.r32((s.dx+0x00000028u));
  }
  L00431667: { // 0x431667: 03ee ADD EBP,ESI
    s.bp = integer::add(s.bp,s.si,32,flags);
  }
  L00431669: { // 0x431669: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L0043166b: { // 0x43166b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0043166c: { // 0x43166c: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0043166e: { // 0x43166e: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L00431670: { // 0x431670: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431674: { // 0x431674: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00431678: { // 0x431678: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00431679: { // 0x431679: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0043167b: { // 0x43167b: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0043167f: { // 0x43167f: 7f42 JG 0x004316c3
    if(integer::condition("JG",flags)) goto L004316c3;
  }
  L00431681: { // 0x431681: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00431685: { // 0x431685: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431687: { // 0x431687: 7404 JZ 0x0043168d
    if(integer::condition("JZ",flags)) goto L0043168d;
  }
  L00431689: { // 0x431689: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0043168b: { // 0x43168b: 7476 JZ 0x00431703
    if(integer::condition("JZ",flags)) goto L00431703;
  }
  L0043168d: { // 0x43168d: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00431691: { // 0x431691: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431693: { // 0x431693: 740c JZ 0x004316a1
    if(integer::condition("JZ",flags)) goto L004316a1;
  }
  L00431695: { // 0x431695: 6683ff0d CMP DI,0xd
    (void)integer::sub((s.di & 0xffffu),0x0000000du,16,flags);
  }
  L00431699: { // 0x431699: 7468 JZ 0x00431703
    if(integer::condition("JZ",flags)) goto L00431703;
  }
  L0043169b: { // 0x43169b: 6683ff0a CMP DI,0xa
    (void)integer::sub((s.di & 0xffffu),0x0000000au,16,flags);
  }
  L0043169f: { // 0x43169f: 7462 JZ 0x00431703
    if(integer::condition("JZ",flags)) goto L00431703;
  }
  L004316a1: { // 0x4316a1: 668b7902 MOV DI,word ptr [ECX + 0x2]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.cx+0x00000002u))) & 0xffffu);
  }
  L004316a5: { // 0x4316a5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L004316a8: { // 0x4316a8: 6685ff TEST DI,DI
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L004316ab: { // 0x4316ab: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L004316af: { // 0x4316af: 0f8553ffffff JNZ 0x00431608
    if(integer::condition("JNZ",flags)) goto L00431608;
  }
  L004316b5: { // 0x4316b5: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004316b9: { // 0x4316b9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004316ba: { // 0x4316ba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004316bb: { // 0x4316bb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004316bc: { // 0x4316bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004316bd: { // 0x4316bd: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004316c0: { // 0x4316c0: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004316c3: { // 0x4316c3: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004316c7: { // 0x4316c7: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L004316c8: { // 0x4316c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004316ca: { // 0x4316ca: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004316ce: { // 0x4316ce: 7433 JZ 0x00431703
    if(integer::condition("JZ",flags)) goto L00431703;
  }
  L004316d0: { // 0x4316d0: 6683ff20 CMP DI,0x20
    (void)integer::sub((s.di & 0xffffu),0x00000020u,16,flags);
  }
  L004316d4: { // 0x4316d4: 762d JBE 0x00431703
    if(integer::condition("JBE",flags)) goto L00431703;
  }
  L004316d6: { // 0x4316d6: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004316d9: { // 0x4316d9: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004316db: { // 0x4316db: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004316dd: { // 0x4316dd: 7424 JZ 0x00431703
    if(integer::condition("JZ",flags)) goto L00431703;
  }
  L004316df: { // 0x4316df: 66833920 CMP word ptr [ECX],0x20
    (void)integer::sub(m.r16((s.cx)),0x00000020u,16,flags);
  }
  L004316e3: { // 0x4316e3: 7616 JBE 0x004316fb
    if(integer::condition("JBE",flags)) goto L004316fb;
  }
  L004316e5: { // 0x4316e5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004316e6: { // 0x4316e6: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L004316e9: { // 0x4316e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004316eb: { // 0x4316eb: 75f2 JNZ 0x004316df
    if(integer::condition("JNZ",flags)) goto L004316df;
  }
  L004316ed: { // 0x4316ed: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004316f1: { // 0x4316f1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004316f2: { // 0x4316f2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004316f3: { // 0x4316f3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004316f4: { // 0x4316f4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004316f5: { // 0x4316f5: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L004316f8: { // 0x4316f8: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004316fb: { // 0x4316fb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004316fd: { // 0x4316fd: 7404 JZ 0x00431703
    if(integer::condition("JZ",flags)) goto L00431703;
  }
  L004316ff: { // 0x4316ff: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431703: { // 0x431703: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00431707: { // 0x431707: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431708: { // 0x431708: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431709: { // 0x431709: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043170a: { // 0x43170a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043170b: { // 0x43170b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0043170e: { // 0x43170e: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00431711: { // 0x431711: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431712: { // 0x431712: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00431714: { // 0x431714: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431715: { // 0x431715: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00431718: { // 0x431718: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00031790(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431790: { // 0x431790: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00431794: { // 0x431794: 894120 MOV dword ptr [ECX + 0x20],EAX
    m.w32((s.cx+0x00000020u), s.ax);
  }
  L00431797: { // 0x431797: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000317a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004317a0: { // 0x4317a0: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L004317a3: { // 0x4317a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004317a4: { // 0x4317a4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004317a5: { // 0x4317a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004317a6: { // 0x4317a6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004317a7: { // 0x4317a7: 8b7c2444 MOV EDI,dword ptr [ESP + 0x44]
    s.di = m.r32((f.sp+0x00000044u));
  }
  L004317ab: { // 0x4317ab: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004317ad: { // 0x4317ad: 6683ff09 CMP DI,0x9
    (void)integer::sub((s.di & 0xffffu),0x00000009u,16,flags);
  }
  L004317b1: { // 0x4317b1: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004317b5: { // 0x4317b5: 7521 JNZ 0x004317d8
    if(integer::condition("JNZ",flags)) goto L004317d8;
  }
  L004317b7: { // 0x4317b7: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  L004317ba: { // 0x4317ba: 8b7c2448 MOV EDI,dword ptr [ESP + 0x48]
    s.di = m.r32((f.sp+0x00000048u));
  }
  L004317be: { // 0x4317be: 8b5620 MOV EDX,dword ptr [ESI + 0x20]
    s.dx = m.r32((s.si+0x00000020u));
  }
  L004317c1: { // 0x4317c1: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L004317c3: { // 0x4317c3: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004317c5: { // 0x4317c5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004317c7: { // 0x4317c7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004317c8: { // 0x4317c8: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004317ca: { // 0x4317ca: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004317cc: { // 0x4317cc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004317cd: { // 0x4317cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004317ce: { // 0x4317ce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004317cf: { // 0x4317cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004317d0: { // 0x4317d0: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004317d2: { // 0x4317d2: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004317d5: { // 0x4317d5: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004317d8: { // 0x4317d8: 668b4624 MOV AX,word ptr [ESI + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000024u)));
  }
  L004317dc: { // 0x4317dc: 6689442444 MOV word ptr [ESP + 0x44],AX
    m.w16((f.sp+0x00000044u), (s.ax & 0xffffu));
  }
  L004317e1: { // 0x4317e1: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L004317e5: { // 0x4317e5: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L004317e8: { // 0x4317e8: 7404 JZ 0x004317ee
    if(integer::condition("JZ",flags)) goto L004317ee;
  }
  L004317ea: { // 0x4317ea: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L004317ee: { // 0x4317ee: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L004317f1: { // 0x4317f1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004317f3: { // 0x4317f3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004317f5: { // 0x4317f5: 741d JZ 0x00431814
    if(integer::condition("JZ",flags)) goto L00431814;
  }
  L004317f7: { // 0x4317f7: 8b5918 MOV EBX,dword ptr [ECX + 0x18]
    s.bx = m.r32((s.cx+0x00000018u));
  }
  L004317fa: { // 0x4317fa: 81e7ffff0000 AND EDI,0xffff
    s.di = integer::logical((s.di)&(0x0000ffffu),32,flags);
  }
  L00431800: { // 0x431800: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00431802: { // 0x431802: 668b147b MOV DX,word ptr [EBX + EDI*0x2]
    s.dx = with_ax(s.dx, m.r16((s.bx+(s.di * 0x00000002u))));
  }
  L00431806: { // 0x431806: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431808: { // 0x431808: 740a JZ 0x00431814
    if(integer::condition("JZ",flags)) goto L00431814;
  }
  L0043180a: { // 0x43180a: 8b4114 MOV EAX,dword ptr [ECX + 0x14]
    s.ax = m.r32((s.cx+0x00000014u));
  }
  L0043180d: { // 0x43180d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0043180e: { // 0x43180e: 0fafc2 IMUL EAX,EDX
    s.ax = integer::imul(s.ax,s.dx,32,flags);
  }
  L00431811: { // 0x431811: 03411c ADD EAX,dword ptr [ECX + 0x1c]
    s.ax = integer::add(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L00431814: { // 0x431814: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431816: { // 0x431816: 7525 JNZ 0x0043183d
    if(integer::condition("JNZ",flags)) goto L0043183d;
  }
  L00431818: { // 0x431818: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0043181c: { // 0x43181c: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0043181e: { // 0x43181e: 7408 JZ 0x00431828
    if(integer::condition("JZ",flags)) goto L00431828;
  }
  L00431820: { // 0x431820: 8174244455550000 XOR dword ptr [ESP + 0x44],0x5555
    m.w32((f.sp+0x00000044u), integer::logical((m.r32((f.sp+0x00000044u)))^(0x00005555u),32,flags));
  }
  L00431828: { // 0x431828: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0043182b: { // 0x43182b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043182d: { // 0x43182d: 750e JNZ 0x0043183d
    if(integer::condition("JNZ",flags)) goto L0043183d;
  }
  L0043182f: { // 0x43182f: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431833: { // 0x431833: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431834: { // 0x431834: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431835: { // 0x431835: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431836: { // 0x431836: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431837: { // 0x431837: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0043183a: { // 0x43183a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0043183d: { // 0x43183d: 8b560c MOV EDX,dword ptr [ESI + 0xc]
    s.dx = m.r32((s.si+0x0000000cu));
  }
  L00431840: { // 0x431840: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00431842: { // 0x431842: 750e JNZ 0x00431852
    if(integer::condition("JNZ",flags)) goto L00431852;
  }
  L00431844: { // 0x431844: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431848: { // 0x431848: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431849: { // 0x431849: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043184a: { // 0x43184a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043184b: { // 0x43184b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043184c: { // 0x43184c: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0043184f: { // 0x43184f: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L00431852: { // 0x431852: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L00431855: { // 0x431855: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00431858: { // 0x431858: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0043185c: { // 0x43185c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0043185e: { // 0x43185e: 8a10 MOV DL,byte ptr [EAX]
    s.dx = with_al(s.dx, m.r8((s.ax)));
  }
  L00431860: { // 0x431860: 8a4641 MOV AL,byte ptr [ESI + 0x41]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000041u)));
  }
  L00431863: { // 0x431863: 8b74244c MOV ESI,dword ptr [ESP + 0x4c]
    s.si = m.r32((f.sp+0x0000004cu));
  }
  L00431867: { // 0x431867: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0043186b: { // 0x43186b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0043186d: { // 0x43186d: 0f8405020000 JZ 0x00431a78
    if(integer::condition("JZ",flags)) goto L00431a78;
  }
  L00431873: { // 0x431873: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L00431877: { // 0x431877: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00431879: { // 0x431879: 8d4437ff LEA EAX,[EDI + ESI*0x1 + -0x1]
    s.ax = (s.di+(s.si * 0x00000001u)-0x00000001u);
  }
  L0043187d: { // 0x43187d: 8d5419ff LEA EDX,[ECX + EBX*0x1 + -0x1]
    s.dx = (s.cx+(s.bx * 0x00000001u)-0x00000001u);
  }
  L00431881: { // 0x431881: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431882: { // 0x431882: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00431883: { // 0x431883: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431884: { // 0x431884: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L00431888: { // 0x431888: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00431889: { // 0x431889: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043188a: { // 0x43188a: ff15a8547800 CALL dword ptr [0x007854a8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007854a8u)),4397200u,op); flags=s.arithmetic_flags;
  }
  L00431890: { // 0x431890: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L00431894: { // 0x431894: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00431898: { // 0x431898: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0043189c: { // 0x43189c: 8d4d30 LEA ECX,[EBP + 0x30]
    s.cx = (s.bp+0x00000030u);
  }
  L0043189f: { // 0x43189f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004318a0: { // 0x4318a0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004318a1: { // 0x4318a1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004318a2: { // 0x4318a2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004318a4: { // 0x4318a4: e817060000 CALL 0x00431ec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431ec0u,4397225u,op); flags=s.arithmetic_flags;
  }
  L004318a9: { // 0x4318a9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004318ab: { // 0x4318ab: 7515 JNZ 0x004318c2
    if(integer::condition("JNZ",flags)) goto L004318c2;
  }
  L004318ad: { // 0x4318ad: 8b452c MOV EAX,dword ptr [EBP + 0x2c]
    s.ax = m.r32((s.bp+0x0000002cu));
  }
  L004318b0: { // 0x4318b0: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L004318b4: { // 0x4318b4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004318b6: { // 0x4318b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004318b7: { // 0x4318b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004318b8: { // 0x4318b8: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L004318ba: { // 0x4318ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004318bb: { // 0x4318bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004318bc: { // 0x4318bc: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L004318bf: { // 0x4318bf: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L004318c2: { // 0x4318c2: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L004318c6: { // 0x4318c6: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004318ca: { // 0x4318ca: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L004318ce: { // 0x4318ce: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L004318d2: { // 0x4318d2: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L004318d6: { // 0x4318d6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004318d8: { // 0x4318d8: 7c18 JL 0x004318f2
    if(integer::condition("JL",flags)) goto L004318f2;
  }
  L004318da: { // 0x4318da: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L004318de: { // 0x4318de: 3b442438 CMP EAX,dword ptr [ESP + 0x38]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000038u)),32,flags);
  }
  L004318e2: { // 0x4318e2: 7f0e JG 0x004318f2
    if(integer::condition("JG",flags)) goto L004318f2;
  }
  L004318e4: { // 0x4318e4: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L004318e6: { // 0x4318e6: 7c0a JL 0x004318f2
    if(integer::condition("JL",flags)) goto L004318f2;
  }
  L004318e8: { // 0x4318e8: 394c242c CMP dword ptr [ESP + 0x2c],ECX
    (void)integer::sub(m.r32((f.sp+0x0000002cu)),s.cx,32,flags);
  }
  L004318ec: { // 0x4318ec: 0f8e86010000 JLE 0x00431a78
    if(integer::condition("JLE",flags)) goto L00431a78;
  }
  L004318f2: { // 0x4318f2: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L004318f4: { // 0x4318f4: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004318f6: { // 0x4318f6: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004318fa: { // 0x4318fa: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L004318fc: { // 0x4318fc: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L004318fe: { // 0x4318fe: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00431902: { // 0x431902: 8b7a18 MOV EDI,dword ptr [EDX + 0x18]
    s.di = m.r32((s.dx+0x00000018u));
  }
  L00431905: { // 0x431905: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00431906: { // 0x431906: 0faff8 IMUL EDI,EAX
    s.di = integer::imul(s.di,s.ax,32,flags);
  }
  L00431909: { // 0x431909: 8b4210 MOV EAX,dword ptr [EDX + 0x10]
    s.ax = m.r32((s.dx+0x00000010u));
  }
  L0043190c: { // 0x43190c: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0043190e: { // 0x43190e: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00431911: { // 0x431911: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00431915: { // 0x431915: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00431919: { // 0x431919: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0043191b: { // 0x43191b: 8b720c MOV ESI,dword ptr [EDX + 0xc]
    s.si = m.r32((s.dx+0x0000000cu));
  }
  L0043191e: { // 0x43191e: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00431922: { // 0x431922: 8d3446 LEA ESI,[ESI + EAX*0x2]
    s.si = (s.si+(s.ax * 0x00000002u));
  }
  L00431925: { // 0x431925: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00431927: { // 0x431927: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431928: { // 0x431928: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0043192c: { // 0x43192c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043192e: { // 0x43192e: 0f8430020000 JZ 0x00431b64
    if(integer::condition("JZ",flags)) goto L00431b64;
  }
  L00431934: { // 0x431934: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00431935: { // 0x431935: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00431939: { // 0x431939: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L0043193d: { // 0x43193d: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00431941: { // 0x431941: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00431945: { // 0x431945: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  L00431949: { // 0x431949: 8a5500 MOV DL,byte ptr [EBP]
    s.dx = with_al(s.dx, m.r8((s.bp)));
  }
  L0043194c: { // 0x43194c: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0043194d: { // 0x43194d: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0043194f: { // 0x43194f: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L00431953: { // 0x431953: 750e JNZ 0x00431963
    if(integer::condition("JNZ",flags)) goto L00431963;
  }
  L00431955: { // 0x431955: 83c610 ADD ESI,0x10
    s.si = integer::add(s.si,0x00000010u,32,flags);
  }
  L00431958: { // 0x431958: 83e908 SUB ECX,0x8
    s.cx = integer::sub(s.cx,0x00000008u,32,flags);
  }
  L0043195b: { // 0x43195b: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L0043195e: { // 0x43195e: e9da000000 JMP 0x00431a3d
    goto L00431a3d;
  }
  L00431963: { // 0x431963: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431965: { // 0x431965: 7c12 JL 0x00431979
    if(integer::condition("JL",flags)) goto L00431979;
  }
  L00431967: { // 0x431967: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431969: { // 0x431969: 7f0e JG 0x00431979
    if(integer::condition("JG",flags)) goto L00431979;
  }
  L0043196b: { // 0x43196b: f6c280 TEST DL,0x80
    (void)integer::logical(((s.dx & 0xffu))&(0x00000080u),8,flags);
  }
  L0043196e: { // 0x43196e: 7409 JZ 0x00431979
    if(integer::condition("JZ",flags)) goto L00431979;
  }
  L00431970: { // 0x431970: 8b6c2444 MOV EBP,dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L00431974: { // 0x431974: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431977: { // 0x431977: eb04 JMP 0x0043197d
    goto L0043197d;
  }
  L00431979: { // 0x431979: 8b6c2444 MOV EBP,dword ptr [ESP + 0x44]
    s.bp = m.r32((f.sp+0x00000044u));
  }
  L0043197d: { // 0x43197d: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431980: { // 0x431980: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431981: { // 0x431981: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431982: { // 0x431982: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431984: { // 0x431984: 0f8ebb000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L0043198a: { // 0x43198a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0043198c: { // 0x43198c: 7c0c JL 0x0043199a
    if(integer::condition("JL",flags)) goto L0043199a;
  }
  L0043198e: { // 0x43198e: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431990: { // 0x431990: 7f08 JG 0x0043199a
    if(integer::condition("JG",flags)) goto L0043199a;
  }
  L00431992: { // 0x431992: f6c240 TEST DL,0x40
    (void)integer::logical(((s.dx & 0xffu))&(0x00000040u),8,flags);
  }
  L00431995: { // 0x431995: 7403 JZ 0x0043199a
    if(integer::condition("JZ",flags)) goto L0043199a;
  }
  L00431997: { // 0x431997: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L0043199a: { // 0x43199a: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L0043199d: { // 0x43199d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0043199e: { // 0x43199e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0043199f: { // 0x43199f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319a1: { // 0x4319a1: 0f8e9e000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319a7: { // 0x4319a7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319a9: { // 0x4319a9: 7c0c JL 0x004319b7
    if(integer::condition("JL",flags)) goto L004319b7;
  }
  L004319ab: { // 0x4319ab: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319ad: { // 0x4319ad: 7f08 JG 0x004319b7
    if(integer::condition("JG",flags)) goto L004319b7;
  }
  L004319af: { // 0x4319af: f6c220 TEST DL,0x20
    (void)integer::logical(((s.dx & 0xffu))&(0x00000020u),8,flags);
  }
  L004319b2: { // 0x4319b2: 7403 JZ 0x004319b7
    if(integer::condition("JZ",flags)) goto L004319b7;
  }
  L004319b4: { // 0x4319b4: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319b7: { // 0x4319b7: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319ba: { // 0x4319ba: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319bb: { // 0x4319bb: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319bc: { // 0x4319bc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319be: { // 0x4319be: 0f8e81000000 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319c4: { // 0x4319c4: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319c6: { // 0x4319c6: 7c0c JL 0x004319d4
    if(integer::condition("JL",flags)) goto L004319d4;
  }
  L004319c8: { // 0x4319c8: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319ca: { // 0x4319ca: 7f08 JG 0x004319d4
    if(integer::condition("JG",flags)) goto L004319d4;
  }
  L004319cc: { // 0x4319cc: f6c210 TEST DL,0x10
    (void)integer::logical(((s.dx & 0xffu))&(0x00000010u),8,flags);
  }
  L004319cf: { // 0x4319cf: 7403 JZ 0x004319d4
    if(integer::condition("JZ",flags)) goto L004319d4;
  }
  L004319d1: { // 0x4319d1: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319d4: { // 0x4319d4: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319d7: { // 0x4319d7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319d8: { // 0x4319d8: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319d9: { // 0x4319d9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319db: { // 0x4319db: 7e68 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319dd: { // 0x4319dd: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319df: { // 0x4319df: 7c0c JL 0x004319ed
    if(integer::condition("JL",flags)) goto L004319ed;
  }
  L004319e1: { // 0x4319e1: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319e3: { // 0x4319e3: 7f08 JG 0x004319ed
    if(integer::condition("JG",flags)) goto L004319ed;
  }
  L004319e5: { // 0x4319e5: f6c208 TEST DL,0x8
    (void)integer::logical(((s.dx & 0xffu))&(0x00000008u),8,flags);
  }
  L004319e8: { // 0x4319e8: 7403 JZ 0x004319ed
    if(integer::condition("JZ",flags)) goto L004319ed;
  }
  L004319ea: { // 0x4319ea: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L004319ed: { // 0x4319ed: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L004319f0: { // 0x4319f0: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004319f1: { // 0x4319f1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004319f2: { // 0x4319f2: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004319f4: { // 0x4319f4: 7e4f JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L004319f6: { // 0x4319f6: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L004319f8: { // 0x4319f8: 7c0c JL 0x00431a06
    if(integer::condition("JL",flags)) goto L00431a06;
  }
  L004319fa: { // 0x4319fa: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004319fc: { // 0x4319fc: 7f08 JG 0x00431a06
    if(integer::condition("JG",flags)) goto L00431a06;
  }
  L004319fe: { // 0x4319fe: f6c204 TEST DL,0x4
    (void)integer::logical(((s.dx & 0xffu))&(0x00000004u),8,flags);
  }
  L00431a01: { // 0x431a01: 7403 JZ 0x00431a06
    if(integer::condition("JZ",flags)) goto L00431a06;
  }
  L00431a03: { // 0x431a03: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a06: { // 0x431a06: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a09: { // 0x431a09: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a0a: { // 0x431a0a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a0b: { // 0x431a0b: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a0d: { // 0x431a0d: 7e36 JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L00431a0f: { // 0x431a0f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431a11: { // 0x431a11: 7c0c JL 0x00431a1f
    if(integer::condition("JL",flags)) goto L00431a1f;
  }
  L00431a13: { // 0x431a13: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431a15: { // 0x431a15: 7f08 JG 0x00431a1f
    if(integer::condition("JG",flags)) goto L00431a1f;
  }
  L00431a17: { // 0x431a17: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  L00431a1a: { // 0x431a1a: 7403 JZ 0x00431a1f
    if(integer::condition("JZ",flags)) goto L00431a1f;
  }
  L00431a1c: { // 0x431a1c: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a1f: { // 0x431a1f: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a22: { // 0x431a22: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a23: { // 0x431a23: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a24: { // 0x431a24: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a26: { // 0x431a26: 7e1d JLE 0x00431a45
    if(integer::condition("JLE",flags)) goto L00431a45;
  }
  L00431a28: { // 0x431a28: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00431a2a: { // 0x431a2a: 7c0c JL 0x00431a38
    if(integer::condition("JL",flags)) goto L00431a38;
  }
  L00431a2c: { // 0x431a2c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00431a2e: { // 0x431a2e: 7f08 JG 0x00431a38
    if(integer::condition("JG",flags)) goto L00431a38;
  }
  L00431a30: { // 0x431a30: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L00431a33: { // 0x431a33: 7403 JZ 0x00431a38
    if(integer::condition("JZ",flags)) goto L00431a38;
  }
  L00431a35: { // 0x431a35: 66892e MOV word ptr [ESI],BP
    m.w16((s.si), (s.bp & 0xffffu));
  }
  L00431a38: { // 0x431a38: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  L00431a3b: { // 0x431a3b: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431a3c: { // 0x431a3c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00431a3d: { // 0x431a3d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431a3f: { // 0x431a3f: 0f8f00ffffff JG 0x00431945
    if(integer::condition("JG",flags)) goto L00431945;
  }
  L00431a45: { // 0x431a45: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431a49: { // 0x431a49: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00431a4d: { // 0x431a4d: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00431a51: { // 0x431a51: 8b4a18 MOV ECX,dword ptr [EDX + 0x18]
    s.cx = m.r32((s.dx+0x00000018u));
  }
  L00431a54: { // 0x431a54: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L00431a56: { // 0x431a56: 8b4a10 MOV ECX,dword ptr [EDX + 0x10]
    s.cx = m.r32((s.dx+0x00000010u));
  }
  L00431a59: { // 0x431a59: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L00431a5d: { // 0x431a5d: 8d3448 LEA ESI,[EAX + ECX*0x2]
    s.si = (s.ax+(s.cx * 0x00000002u));
  }
  L00431a60: { // 0x431a60: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00431a64: { // 0x431a64: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431a65: { // 0x431a65: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00431a69: { // 0x431a69: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431a6d: { // 0x431a6d: 0f85c6feffff JNZ 0x00431939
    if(integer::condition("JNZ",flags)) goto L00431939;
  }
  L00431a73: { // 0x431a73: e9ec000000 JMP 0x00431b64
    goto L00431b64;
  }
  L00431a78: { // 0x431a78: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00431a7c: { // 0x431a7c: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00431a7f: { // 0x431a7f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00431a82: { // 0x431a82: 0fafce IMUL ECX,ESI
    s.cx = integer::imul(s.cx,s.si,32,flags);
  }
  L00431a85: { // 0x431a85: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  L00431a89: { // 0x431a89: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00431a8b: { // 0x431a8b: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L00431a8d: { // 0x431a8d: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00431a8e: { // 0x431a8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431a90: { // 0x431a90: 8d2c4a LEA EBP,[EDX + ECX*0x2]
    s.bp = (s.dx+(s.cx * 0x00000002u));
  }
  L00431a93: { // 0x431a93: 0f84c7000000 JZ 0x00431b60
    if(integer::condition("JZ",flags)) goto L00431b60;
  }
  L00431a99: { // 0x431a99: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L00431a9d: { // 0x431a9d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00431a9e: { // 0x431a9e: 897c244c MOV dword ptr [ESP + 0x4c],EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L00431aa2: { // 0x431aa2: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00431aa6: { // 0x431aa6: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00431aaa: { // 0x431aaa: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00431aac: { // 0x431aac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00431aae: { // 0x431aae: 8a13 MOV DL,byte ptr [EBX]
    s.dx = with_al(s.dx, m.r8((s.bx)));
  }
  L00431ab0: { // 0x431ab0: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00431ab1: { // 0x431ab1: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00431ab3: { // 0x431ab3: 7508 JNZ 0x00431abd
    if(integer::condition("JNZ",flags)) goto L00431abd;
  }
  L00431ab5: { // 0x431ab5: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L00431ab8: { // 0x431ab8: 83e808 SUB EAX,0x8
    s.ax = integer::sub(s.ax,0x00000008u,32,flags);
  }
  L00431abb: { // 0x431abb: eb7c JMP 0x00431b39
    goto L00431b39;
  }
  L00431abd: { // 0x431abd: f6c280 TEST DL,0x80
    (void)integer::logical(((s.dx & 0xffu))&(0x00000080u),8,flags);
  }
  L00431ac0: { // 0x431ac0: 7403 JZ 0x00431ac5
    if(integer::condition("JZ",flags)) goto L00431ac5;
  }
  L00431ac2: { // 0x431ac2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ac5: { // 0x431ac5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ac8: { // 0x431ac8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ac9: { // 0x431ac9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431acb: { // 0x431acb: 7e74 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431acd: { // 0x431acd: f6c240 TEST DL,0x40
    (void)integer::logical(((s.dx & 0xffu))&(0x00000040u),8,flags);
  }
  L00431ad0: { // 0x431ad0: 7403 JZ 0x00431ad5
    if(integer::condition("JZ",flags)) goto L00431ad5;
  }
  L00431ad2: { // 0x431ad2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ad5: { // 0x431ad5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ad8: { // 0x431ad8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ad9: { // 0x431ad9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431adb: { // 0x431adb: 7e64 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431add: { // 0x431add: f6c220 TEST DL,0x20
    (void)integer::logical(((s.dx & 0xffu))&(0x00000020u),8,flags);
  }
  L00431ae0: { // 0x431ae0: 7403 JZ 0x00431ae5
    if(integer::condition("JZ",flags)) goto L00431ae5;
  }
  L00431ae2: { // 0x431ae2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431ae5: { // 0x431ae5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431ae8: { // 0x431ae8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ae9: { // 0x431ae9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431aeb: { // 0x431aeb: 7e54 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431aed: { // 0x431aed: f6c210 TEST DL,0x10
    (void)integer::logical(((s.dx & 0xffu))&(0x00000010u),8,flags);
  }
  L00431af0: { // 0x431af0: 7403 JZ 0x00431af5
    if(integer::condition("JZ",flags)) goto L00431af5;
  }
  L00431af2: { // 0x431af2: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431af5: { // 0x431af5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431af8: { // 0x431af8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431af9: { // 0x431af9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431afb: { // 0x431afb: 7e44 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431afd: { // 0x431afd: f6c208 TEST DL,0x8
    (void)integer::logical(((s.dx & 0xffu))&(0x00000008u),8,flags);
  }
  L00431b00: { // 0x431b00: 7403 JZ 0x00431b05
    if(integer::condition("JZ",flags)) goto L00431b05;
  }
  L00431b02: { // 0x431b02: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b05: { // 0x431b05: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b08: { // 0x431b08: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b09: { // 0x431b09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b0b: { // 0x431b0b: 7e34 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b0d: { // 0x431b0d: f6c204 TEST DL,0x4
    (void)integer::logical(((s.dx & 0xffu))&(0x00000004u),8,flags);
  }
  L00431b10: { // 0x431b10: 7403 JZ 0x00431b15
    if(integer::condition("JZ",flags)) goto L00431b15;
  }
  L00431b12: { // 0x431b12: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b15: { // 0x431b15: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b18: { // 0x431b18: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b19: { // 0x431b19: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b1b: { // 0x431b1b: 7e24 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b1d: { // 0x431b1d: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  L00431b20: { // 0x431b20: 7403 JZ 0x00431b25
    if(integer::condition("JZ",flags)) goto L00431b25;
  }
  L00431b22: { // 0x431b22: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b25: { // 0x431b25: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b28: { // 0x431b28: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b29: { // 0x431b29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b2b: { // 0x431b2b: 7e14 JLE 0x00431b41
    if(integer::condition("JLE",flags)) goto L00431b41;
  }
  L00431b2d: { // 0x431b2d: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L00431b30: { // 0x431b30: 7403 JZ 0x00431b35
    if(integer::condition("JZ",flags)) goto L00431b35;
  }
  L00431b32: { // 0x431b32: 668931 MOV word ptr [ECX],SI
    m.w16((s.cx), (s.si & 0xffffu));
  }
  L00431b35: { // 0x431b35: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L00431b38: { // 0x431b38: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b39: { // 0x431b39: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431b3b: { // 0x431b3b: 0f8f6dffffff JG 0x00431aae
    if(integer::condition("JG",flags)) goto L00431aae;
  }
  L00431b41: { // 0x431b41: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00431b45: { // 0x431b45: 8b4818 MOV ECX,dword ptr [EAX + 0x18]
    s.cx = m.r32((s.ax+0x00000018u));
  }
  L00431b48: { // 0x431b48: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L00431b4a: { // 0x431b4a: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L00431b4d: { // 0x431b4d: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00431b51: { // 0x431b51: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431b52: { // 0x431b52: 8d6c4d00 LEA EBP,[EBP + ECX*0x2]
    s.bp = (s.bp+(s.cx * 0x00000002u));
  }
  L00431b56: { // 0x431b56: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L00431b5a: { // 0x431b5a: 0f8546ffffff JNZ 0x00431aa6
    if(integer::condition("JNZ",flags)) goto L00431aa6;
  }
  L00431b60: { // 0x431b60: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431b64: { // 0x431b64: 8b422c MOV EAX,dword ptr [EDX + 0x2c]
    s.ax = m.r32((s.dx+0x0000002cu));
  }
  L00431b67: { // 0x431b67: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L00431b6b: { // 0x431b6b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00431b6f: { // 0x431b6f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431b70: { // 0x431b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00431b72: { // 0x431b72: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431b73: { // 0x431b73: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431b74: { // 0x431b74: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00431b76: { // 0x431b76: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431b77: { // 0x431b77: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L00431b7a: { // 0x431b7a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00031b80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431b80: { // 0x431b80: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00431b83: { // 0x431b83: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00431b87: { // 0x431b87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00431b88: { // 0x431b88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00431b89: { // 0x431b89: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431b8a: { // 0x431b8a: 668b32 MOV SI,word ptr [EDX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00431b8d: { // 0x431b8d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431b8e: { // 0x431b8e: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00431b90: { // 0x431b90: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L00431b93: { // 0x431b93: 6685f6 TEST SI,SI
    (void)integer::logical(((s.si & 0xffffu))&((s.si & 0xffffu)),16,flags);
  }
  L00431b96: { // 0x431b96: 668b5f24 MOV BX,word ptr [EDI + 0x24]
    s.bx = with_ax(s.bx, m.r16((s.di+0x00000024u)));
  }
  L00431b9a: { // 0x431b9a: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L00431ba2: { // 0x431ba2: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00431ba6: { // 0x431ba6: 0f844f010000 JZ 0x00431cfb
    if(integer::condition("JZ",flags)) goto L00431cfb;
  }
  L00431bac: { // 0x431bac: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431bb0: { // 0x431bb0: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L00431bb3: { // 0x431bb3: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431bb7: { // 0x431bb7: b809000000 MOV EAX,0x9
    s.ax = 0x00000009u;
  }
  L00431bbc: { // 0x431bbc: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00431bbe: { // 0x431bbe: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00431bc0: { // 0x431bc0: c1e505 SHL EBP,0x5
    s.bp = integer::shift(s.bp,0x00000005u,32,flags,integer::Shift::left);
  }
  L00431bc3: { // 0x431bc3: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L00431bc5: { // 0x431bc5: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00431bc7: { // 0x431bc7: 0f84e0000000 JZ 0x00431cad
    if(integer::condition("JZ",flags)) goto L00431cad;
  }
  L00431bcd: { // 0x431bcd: 394c2418 CMP dword ptr [ESP + 0x18],ECX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.cx,32,flags);
  }
  L00431bd1: { // 0x431bd1: 0f8d36010000 JGE 0x00431d0d
    if(integer::condition("JGE",flags)) goto L00431d0d;
  }
  L00431bd7: { // 0x431bd7: 837c241c08 CMP dword ptr [ESP + 0x1c],0x8
    (void)integer::sub(m.r32((f.sp+0x0000001cu)),0x00000008u,32,flags);
  }
  L00431bdc: { // 0x431bdc: 0f8db6000000 JGE 0x00431c98
    if(integer::condition("JGE",flags)) goto L00431c98;
  }
  L00431be2: { // 0x431be2: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  L00431be9: { // 0x431be9: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00431beb: { // 0x431beb: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431bee: { // 0x431bee: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L00431bf4: { // 0x431bf4: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00431bf6: { // 0x431bf6: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  L00431bfb: { // 0x431bfb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00431bfc: { // 0x431bfc: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431bfe: { // 0x431bfe: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  L00431c05: { // 0x431c05: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431c08: { // 0x431c08: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L00431c0e: { // 0x431c0e: 88542418 MOV byte ptr [ESP + 0x18],DL
    m.w8((f.sp+0x00000018u), (s.dx & 0xffu));
  }
  L00431c12: { // 0x431c12: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431c14: { // 0x431c14: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  L00431c1b: { // 0x431c1b: 88442419 MOV byte ptr [ESP + 0x19],AL
    m.w8((f.sp+0x00000019u), (s.ax & 0xffu));
  }
  L00431c1f: { // 0x431c1f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00431c21: { // 0x431c21: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  L00431c24: { // 0x431c24: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L00431c2a: { // 0x431c2a: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L00431c2c: { // 0x431c2c: 668b4c2418 MOV CX,word ptr [ESP + 0x18]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000018u)));
  }
  L00431c31: { // 0x431c31: 66894c241c MOV word ptr [ESP + 0x1c],CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  L00431c36: { // 0x431c36: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00431c3a: { // 0x431c3a: 8844241e MOV byte ptr [ESP + 0x1e],AL
    m.w8((f.sp+0x0000001eu), (s.ax & 0xffu));
  }
  L00431c3e: { // 0x431c3e: e8cd262000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,4398147u,op); flags=s.arithmetic_flags;
  }
  L00431c43: { // 0x431c43: 8a542415 MOV DL,byte ptr [ESP + 0x15]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000015u)));
  }
  L00431c47: { // 0x431c47: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L00431c4d: { // 0x431c4d: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c4f: { // 0x431c4f: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L00431c55: { // 0x431c55: 6633c0 XOR AX,AX
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))^((s.ax & 0xffffu)),16,flags));
  }
  L00431c58: { // 0x431c58: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L00431c5a: { // 0x431c5a: 8a542416 MOV DL,byte ptr [ESP + 0x16]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000016u)));
  }
  L00431c5e: { // 0x431c5e: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c60: { // 0x431c60: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L00431c66: { // 0x431c66: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c68: { // 0x431c68: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L00431c6e: { // 0x431c6e: 660fb6d2 MOVZX DX,DL
    s.dx = with_ax(s.dx, ((s.dx & 0xffu)&integer::mask(8)));
  }
  L00431c72: { // 0x431c72: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c74: { // 0x431c74: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L00431c7a: { // 0x431c7a: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00431c7c: { // 0x431c7c: 8a542414 MOV DL,byte ptr [ESP + 0x14]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000014u)));
  }
  L00431c80: { // 0x431c80: d2ea SHR DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::right));
  }
  L00431c82: { // 0x431c82: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L00431c88: { // 0x431c88: 660fb6d2 MOVZX DX,DL
    s.dx = with_ax(s.dx, ((s.dx & 0xffu)&integer::mask(8)));
  }
  L00431c8c: { // 0x431c8c: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L00431c8e: { // 0x431c8e: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431c92: { // 0x431c92: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00431c94: { // 0x431c94: 66894724 MOV word ptr [EDI + 0x24],AX
    m.w16((s.di+0x00000024u), (s.ax & 0xffffu));
  }
  L00431c98: { // 0x431c98: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00431c9c: { // 0x431c9c: 83c51f ADD EBP,0x1f
    s.bp = integer::add(s.bp,0x0000001fu,32,flags);
  }
  L00431c9f: { // 0x431c9f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00431ca0: { // 0x431ca0: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00431ca4: { // 0x431ca4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00431ca8: { // 0x431ca8: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431ca9: { // 0x431ca9: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00431cad: { // 0x431cad: 6683fe0d CMP SI,0xd
    (void)integer::sub((s.si & 0xffffu),0x0000000du,16,flags);
  }
  L00431cb1: { // 0x431cb1: 7422 JZ 0x00431cd5
    if(integer::condition("JZ",flags)) goto L00431cd5;
  }
  L00431cb3: { // 0x431cb3: 6683fe0a CMP SI,0xa
    (void)integer::sub((s.si & 0xffffu),0x0000000au,16,flags);
  }
  L00431cb7: { // 0x431cb7: 741c JZ 0x00431cd5
    if(integer::condition("JZ",flags)) goto L00431cd5;
  }
  L00431cb9: { // 0x431cb9: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00431cbd: { // 0x431cbd: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00431cc1: { // 0x431cc1: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00431cc3: { // 0x431cc3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431cc4: { // 0x431cc4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431cc5: { // 0x431cc5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431cc6: { // 0x431cc6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431cc8: { // 0x431cc8: e8d3faffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,4398285u,op); flags=s.arithmetic_flags;
  }
  L00431ccd: { // 0x431ccd: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L00431cd1: { // 0x431cd1: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00431cd5: { // 0x431cd5: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00431cd9: { // 0x431cd9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00431cdb: { // 0x431cdb: 7407 JZ 0x00431ce4
    if(integer::condition("JZ",flags)) goto L00431ce4;
  }
  L00431cdd: { // 0x431cdd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431cde: { // 0x431cde: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00431ce2: { // 0x431ce2: 7417 JZ 0x00431cfb
    if(integer::condition("JZ",flags)) goto L00431cfb;
  }
  L00431ce4: { // 0x431ce4: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00431ce8: { // 0x431ce8: 668b32 MOV SI,word ptr [EDX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00431ceb: { // 0x431ceb: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L00431cee: { // 0x431cee: 6685f6 TEST SI,SI
    (void)integer::logical(((s.si & 0xffffu))&((s.si & 0xffffu)),16,flags);
  }
  L00431cf1: { // 0x431cf1: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00431cf5: { // 0x431cf5: 0f85cafeffff JNZ 0x00431bc5
    if(integer::condition("JNZ",flags)) goto L00431bc5;
  }
  L00431cfb: { // 0x431cfb: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00431cff: { // 0x431cff: 66895f24 MOV word ptr [EDI + 0x24],BX
    m.w16((s.di+0x00000024u), (s.bx & 0xffffu));
  }
  L00431d03: { // 0x431d03: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431d04: { // 0x431d04: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431d05: { // 0x431d05: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431d06: { // 0x431d06: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431d07: { // 0x431d07: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431d0a: { // 0x431d0a: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L00431d0d: { // 0x431d0d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00431d0f: { // 0x431d0f: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00431d13: { // 0x431d13: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00431d15: { // 0x431d15: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431d16: { // 0x431d16: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00431d17: { // 0x431d17: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431d19: { // 0x431d19: 66895f24 MOV word ptr [EDI + 0x24],BX
    m.w16((s.di+0x00000024u), (s.bx & 0xffffu));
  }
  L00431d1d: { // 0x431d1d: e84ef6ffff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,4398370u,op); flags=s.arithmetic_flags;
  }
  L00431d22: { // 0x431d22: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00431d26: { // 0x431d26: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00431d2a: { // 0x431d2a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431d2b: { // 0x431d2b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431d2c: { // 0x431d2c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00431d2d: { // 0x431d2d: 8d0411 LEA EAX,[ECX + EDX*0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u));
  }
  L00431d30: { // 0x431d30: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00431d31: { // 0x431d31: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431d34: { // 0x431d34: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}

void f_00031ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431ec0: { // 0x431ec0: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L00431ec4: { // 0x431ec4: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00431ec8: { // 0x431ec8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431ec9: { // 0x431ec9: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00431ecc: { // 0x431ecc: 8b720c MOV ESI,dword ptr [EDX + 0xc]
    s.si = m.r32((s.dx+0x0000000cu));
  }
  L00431ecf: { // 0x431ecf: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ed1: { // 0x431ed1: 7f6f JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ed3: { // 0x431ed3: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00431ed6: { // 0x431ed6: 8b710c MOV ESI,dword ptr [ECX + 0xc]
    s.si = m.r32((s.cx+0x0000000cu));
  }
  L00431ed9: { // 0x431ed9: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431edb: { // 0x431edb: 7f65 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431edd: { // 0x431edd: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00431edf: { // 0x431edf: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L00431ee2: { // 0x431ee2: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431ee4: { // 0x431ee4: 7f5c JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431ee6: { // 0x431ee6: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00431ee8: { // 0x431ee8: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L00431eeb: { // 0x431eeb: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L00431eed: { // 0x431eed: 7f53 JG 0x00431f42
    if(integer::condition("JG",flags)) goto L00431f42;
  }
  L00431eef: { // 0x431eef: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431ef3: { // 0x431ef3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431ef4: { // 0x431ef4: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431ef6: { // 0x431ef6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00431ef8: { // 0x431ef8: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L00431efa: { // 0x431efa: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L00431efd: { // 0x431efd: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L00431f00: { // 0x431f00: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L00431f03: { // 0x431f03: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00431f06: { // 0x431f06: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00431f09: { // 0x431f09: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431f0a: { // 0x431f0a: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00431f0d: { // 0x431f0d: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00431f10: { // 0x431f10: 394804 CMP dword ptr [EAX + 0x4],ECX
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.cx,32,flags);
  }
  L00431f13: { // 0x431f13: 7d03 JGE 0x00431f18
    if(integer::condition("JGE",flags)) goto L00431f18;
  }
  L00431f15: { // 0x431f15: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00431f18: { // 0x431f18: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00431f1a: { // 0x431f1a: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00431f1c: { // 0x431f1c: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f1e: { // 0x431f1e: 7d02 JGE 0x00431f22
    if(integer::condition("JGE",flags)) goto L00431f22;
  }
  L00431f20: { // 0x431f20: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00431f22: { // 0x431f22: 8b4a0c MOV ECX,dword ptr [EDX + 0xc]
    s.cx = m.r32((s.dx+0x0000000cu));
  }
  L00431f25: { // 0x431f25: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  L00431f28: { // 0x431f28: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L00431f2a: { // 0x431f2a: 7e03 JLE 0x00431f2f
    if(integer::condition("JLE",flags)) goto L00431f2f;
  }
  L00431f2c: { // 0x431f2c: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f2f: { // 0x431f2f: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L00431f32: { // 0x431f32: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00431f35: { // 0x431f35: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00431f37: { // 0x431f37: 7e03 JLE 0x00431f3c
    if(integer::condition("JLE",flags)) goto L00431f3c;
  }
  L00431f39: { // 0x431f39: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00431f3c: { // 0x431f3c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00431f3e: { // 0x431f3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f3f: { // 0x431f3f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00431f42: { // 0x431f42: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00431f46: { // 0x431f46: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L00431f49: { // 0x431f49: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431f4a: { // 0x431f4a: c70000000000 MOV dword ptr [EAX],0x0
    m.w32((s.ax), 0x00000000u);
  }
  L00431f50: { // 0x431f50: c7400400000000 MOV dword ptr [EAX + 0x4],0x0
    m.w32((s.ax+0x00000004u), 0x00000000u);
  }
  L00431f57: { // 0x431f57: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L00431f5a: { // 0x431f5a: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00431f5d: { // 0x431f5d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00431f5f: { // 0x431f5f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_00031f70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00431f70: { // 0x431f70: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00431f73: { // 0x431f73: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00431f74: { // 0x431f74: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00431f75: { // 0x431f75: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L00431f79: { // 0x431f79: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00431f7b: { // 0x431f7b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00431f7d: { // 0x431f7d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00431f7f: { // 0x431f7f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f81: { // 0x431f81: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431f82: { // 0x431f82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431f83: { // 0x431f83: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f85: { // 0x431f85: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4398984u,op); flags=s.arithmetic_flags;
  }
  L00431f88: { // 0x431f88: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00431f8b: { // 0x431f8b: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431f8d: { // 0x431f8d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f8f: { // 0x431f8f: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4398994u,op); flags=s.arithmetic_flags;
  }
  L00431f92: { // 0x431f92: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L00431f94: { // 0x431f94: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00431f97: { // 0x431f97: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00431f99: { // 0x431f99: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431f9b: { // 0x431f9b: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L00431fa3: { // 0x431fa3: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L00431fab: { // 0x431fab: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),4399022u,op); flags=s.arithmetic_flags;
  }
  L00431fae: { // 0x431fae: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431faf: { // 0x431faf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00431fb1: { // 0x431fb1: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00431fb5: { // 0x431fb5: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00431fb7: { // 0x431fb7: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),4399037u,op); flags=s.arithmetic_flags;
  }
  L00431fbd: { // 0x431fbd: 8b5638 MOV EDX,dword ptr [ESI + 0x38]
    s.dx = m.r32((s.si+0x00000038u));
  }
  L00431fc0: { // 0x431fc0: 8b7e3c MOV EDI,dword ptr [ESI + 0x3c]
    s.di = m.r32((s.si+0x0000003cu));
  }
  L00431fc3: { // 0x431fc3: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fc5: { // 0x431fc5: 8b7e34 MOV EDI,dword ptr [ESI + 0x34]
    s.di = m.r32((s.si+0x00000034u));
  }
  L00431fc8: { // 0x431fc8: 8d4e30 LEA ECX,[ESI + 0x30]
    s.cx = (s.si+0x00000030u);
  }
  L00431fcb: { // 0x431fcb: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fcd: { // 0x431fcd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00431fce: { // 0x431fce: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L00431fd0: { // 0x431fd0: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00431fd4: { // 0x431fd4: 0bd7 OR EDX,EDI
    s.dx = integer::logical((s.dx)|(s.di),32,flags);
  }
  L00431fd6: { // 0x431fd6: 751f JNZ 0x00431ff7
    if(integer::condition("JNZ",flags)) goto L00431ff7;
  }
  L00431fd8: { // 0x431fd8: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00431fdc: { // 0x431fdc: 89463c MOV dword ptr [ESI + 0x3c],EAX
    m.w32((s.si+0x0000003cu), s.ax);
  }
  L00431fdf: { // 0x431fdf: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00431fe1: { // 0x431fe1: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00431fe5: { // 0x431fe5: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00431fe9: { // 0x431fe9: 894e34 MOV dword ptr [ESI + 0x34],ECX
    m.w32((s.si+0x00000034u), s.cx);
  }
  L00431fec: { // 0x431fec: 895638 MOV dword ptr [ESI + 0x38],EDX
    m.w32((s.si+0x00000038u), s.dx);
  }
  L00431fef: { // 0x431fef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00431ff0: { // 0x431ff0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00431ff1: { // 0x431ff1: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00431ff4: { // 0x431ff4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00431ff7: { // 0x431ff7: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L00431ffb: { // 0x431ffb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00431ffc: { // 0x431ffc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffd: { // 0x431ffd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00431ffe: { // 0x431ffe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432000: { // 0x432000: e8bbfeffff CALL 0x00431ec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431ec0u,4399109u,op); flags=s.arithmetic_flags;
  }
  L00432005: { // 0x432005: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432006: { // 0x432006: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432007: { // 0x432007: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0043200a: { // 0x43200a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00032010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00432010: { // 0x432010: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00432011: { // 0x432011: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00432013: { // 0x432013: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L00432017: { // 0x432017: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00432019: { // 0x432019: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4399132u,op); flags=s.arithmetic_flags;
  }
  L0043201c: { // 0x43201c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043201e: { // 0x43201e: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00432021: { // 0x432021: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00432024: { // 0x432024: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432025: { // 0x432025: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00032210(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00432210: { // 0x432210: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00432211: { // 0x432211: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00432215: { // 0x432215: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00432216: { // 0x432216: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L0043221a: { // 0x43221a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0043221c: { // 0x43221c: 7443 JZ 0x00432261
    if(integer::condition("JZ",flags)) goto L00432261;
  }
  L0043221e: { // 0x43221e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0043221f: { // 0x43221f: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L00432223: { // 0x432223: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00432224: { // 0x432224: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432226: { // 0x432226: e845fdffff CALL 0x00431f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431f70u,4399659u,op); flags=s.arithmetic_flags;
  }
  L0043222b: { // 0x43222b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043222c: { // 0x43222c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043222e: { // 0x43222e: e85df5ffff CALL 0x00431790
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431790u,4399667u,op); flags=s.arithmetic_flags;
  }
  L00432233: { // 0x432233: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00432237: { // 0x432237: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0043223b: { // 0x43223b: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0043223f: { // 0x43223f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432240: { // 0x432240: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00432244: { // 0x432244: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00432245: { // 0x432245: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00432246: { // 0x432246: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00432247: { // 0x432247: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00432248: { // 0x432248: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043224a: { // 0x43224a: e831f9ffff CALL 0x00431b80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431b80u,4399695u,op); flags=s.arithmetic_flags;
  }
  L0043224f: { // 0x43224f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00432250: { // 0x432250: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00432252: { // 0x432252: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00432254: { // 0x432254: e8b7fdffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,4399705u,op); flags=s.arithmetic_flags;
  }
  L00432259: { // 0x432259: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0043225b: { // 0x43225b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043225c: { // 0x43225c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043225d: { // 0x43225d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043225e: { // 0x43225e: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L00432261: { // 0x432261: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00432263: { // 0x432263: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00432264: { // 0x432264: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00432265: { // 0x432265: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00035420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435420: { // 0x435420: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00435424: { // 0x435424: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00435426: { // 0x435426: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00435429: { // 0x435429: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0043542b: { // 0x43542b: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0043542e: { // 0x43542e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00053ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453ab0: { // 0x453ab0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00453ab2: { // 0x453ab2: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L00453ab6: { // 0x453ab6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00453ab8: { // 0x453ab8: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00453aba: { // 0x453aba: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00453abd: { // 0x453abd: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00453ac1: { // 0x453ac1: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L00453ac4: { // 0x453ac4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00453ac8: { // 0x453ac8: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L00453acb: { // 0x453acb: 89480c MOV dword ptr [EAX + 0xc],ECX
    m.w32((s.ax+0x0000000cu), s.cx);
  }
  L00453ace: { // 0x453ace: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_001f5e90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005f5e90: { // 0x5f5e90: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005f5e92: { // 0x5f5e92: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L005f5e95: { // 0x5f5e95: 8a0d6889a200 MOV CL,byte ptr [0x00a28968]
    s.cx = with_al(s.cx, m.r8((0x00a28968u)));
  }
  L005f5e9b: { // 0x5f5e9b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f5e9c: { // 0x5f5e9c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005f5e9e: { // 0x5f5e9e: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005f5ea0: { // 0x5f5ea0: 7509 JNZ 0x005f5eab
    if(integer::condition("JNZ",flags)) goto L005f5eab;
  }
  L005f5ea2: { // 0x5f5ea2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f5ea4: { // 0x5f5ea4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f5ea5: { // 0x5f5ea5: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L005f5ea8: { // 0x5f5ea8: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L005f5eab: { // 0x5f5eab: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L005f5eaf: { // 0x5f5eaf: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005f5eb1: { // 0x5f5eb1: 750a JNZ 0x005f5ebd
    if(integer::condition("JNZ",flags)) goto L005f5ebd;
  }
  L005f5eb3: { // 0x5f5eb3: 8b0d981c8200 MOV ECX,dword ptr [0x00821c98]
    s.cx = m.r32((0x00821c98u));
  }
  L005f5eb9: { // 0x5f5eb9: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L005f5ebd: { // 0x5f5ebd: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  L005f5ec3: { // 0x5f5ec3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f5ec4: { // 0x5f5ec4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f5ec5: { // 0x5f5ec5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f5ec6: { // 0x5f5ec6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005f5ec8: { // 0x5f5ec8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005f5eca: { // 0x5f5eca: c1ee10 SHR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::right);
  }
  L005f5ecd: { // 0x5f5ecd: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L005f5ed3: { // 0x5f5ed3: 8ad4 MOV DL,AH
    s.dx = with_al(s.dx, ((s.ax >> 8) & 0xffu));
  }
  L005f5ed5: { // 0x5f5ed5: d3ee SHR ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005f5ed7: { // 0x5f5ed7: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L005f5edd: { // 0x5f5edd: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005f5ee3: { // 0x5f5ee3: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L005f5ee8: { // 0x5f5ee8: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L005f5eec: { // 0x5f5eec: d3e6 SHL ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005f5eee: { // 0x5f5eee: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  L005f5ef4: { // 0x5f5ef4: 8b2b MOV EBP,dword ptr [EBX]
    s.bp = m.r32((s.bx));
  }
  L005f5ef6: { // 0x5f5ef6: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005f5ef8: { // 0x5f5ef8: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L005f5efe: { // 0x5f5efe: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005f5f00: { // 0x5f5f00: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  L005f5f06: { // 0x5f5f06: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005f5f08: { // 0x5f5f08: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L005f5f0e: { // 0x5f5f0e: 0bf2 OR ESI,EDX
    s.si = integer::logical((s.si)|(s.dx),32,flags);
  }
  L005f5f10: { // 0x5f5f10: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005f5f12: { // 0x5f5f12: 8b4b0c MOV ECX,dword ptr [EBX + 0xc]
    s.cx = m.r32((s.bx+0x0000000cu));
  }
  L005f5f15: { // 0x5f5f15: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L005f5f19: { // 0x5f5f19: 0bf0 OR ESI,EAX
    s.si = integer::logical((s.si)|(s.ax),32,flags);
  }
  L005f5f1b: { // 0x5f5f1b: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L005f5f1e: { // 0x5f5f1e: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L005f5f22: { // 0x5f5f22: 8b4308 MOV EAX,dword ptr [EBX + 0x8]
    s.ax = m.r32((s.bx+0x00000008u));
  }
  L005f5f25: { // 0x5f5f25: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005f5f27: { // 0x5f5f27: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L005f5f2b: { // 0x5f5f2b: 7506 JNZ 0x005f5f33
    if(integer::condition("JNZ",flags)) goto L005f5f33;
  }
  L005f5f2d: { // 0x5f5f2d: 8b3d306d8300 MOV EDI,dword ptr [0x00836d30]
    s.di = m.r32((0x00836d30u));
  }
  L005f5f33: { // 0x5f5f33: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L005f5f37: { // 0x5f5f37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f5f38: { // 0x5f5f38: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L005f5f3c: { // 0x5f5f3c: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L005f5f40: { // 0x5f5f40: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f5f41: { // 0x5f5f41: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f5f42: { // 0x5f5f42: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f5f43: { // 0x5f5f43: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f5f45: { // 0x5f5f45: e826b4e3ff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,6250314u,op); flags=s.arithmetic_flags;
  }
  L005f5f4a: { // 0x5f5f4a: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L005f5f4e: { // 0x5f5f4e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005f5f51: { // 0x5f5f51: 7514 JNZ 0x005f5f67
    if(integer::condition("JNZ",flags)) goto L005f5f67;
  }
  L005f5f53: { // 0x5f5f53: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L005f5f57: { // 0x5f5f57: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f5f5b: { // 0x5f5f5b: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005f5f5d: { // 0x5f5f5d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005f5f5e: { // 0x5f5f5e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f5f5f: { // 0x5f5f5f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f5f61: { // 0x5f5f61: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f5f63: { // 0x5f5f63: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L005f5f65: { // 0x5f5f65: eb3c JMP 0x005f5fa3
    goto L005f5fa3;
  }
  L005f5f67: { // 0x5f5f67: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005f5f6a: { // 0x5f5f6a: 7512 JNZ 0x005f5f7e
    if(integer::condition("JNZ",flags)) goto L005f5f7e;
  }
  L005f5f6c: { // 0x5f5f6c: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005f5f70: { // 0x5f5f70: 8d4201 LEA EAX,[EDX + 0x1]
    s.ax = (s.dx+0x00000001u);
  }
  L005f5f73: { // 0x5f5f73: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f5f74: { // 0x5f5f74: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f5f76: { // 0x5f5f76: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f5f78: { // 0x5f5f78: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L005f5f7a: { // 0x5f5f7a: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L005f5f7c: { // 0x5f5f7c: eb25 JMP 0x005f5fa3
    goto L005f5fa3;
  }
  L005f5f7e: { // 0x5f5f7e: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005f5f81: { // 0x5f5f81: 750d JNZ 0x005f5f90
    if(integer::condition("JNZ",flags)) goto L005f5f90;
  }
  L005f5f83: { // 0x5f5f83: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005f5f87: { // 0x5f5f87: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005f5f8a: { // 0x5f5f8a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f5f8c: { // 0x5f5f8c: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L005f5f8e: { // 0x5f5f8e: eb13 JMP 0x005f5fa3
    goto L005f5fa3;
  }
  L005f5f90: { // 0x5f5f90: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L005f5f93: { // 0x5f5f93: 750e JNZ 0x005f5fa3
    if(integer::condition("JNZ",flags)) goto L005f5fa3;
  }
  L005f5f95: { // 0x5f5f95: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L005f5f99: { // 0x5f5f99: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005f5f9d: { // 0x5f5f9d: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L005f5f9f: { // 0x5f5f9f: 8d6c29ff LEA EBP,[ECX + EBP*0x1 + -0x1]
    s.bp = (s.cx+(s.bp * 0x00000001u)-0x00000001u);
  }
  L005f5fa3: { // 0x5f5fa3: 8b442444 MOV EAX,dword ptr [ESP + 0x44]
    s.ax = m.r32((f.sp+0x00000044u));
  }
  L005f5fa7: { // 0x5f5fa7: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005f5faa: { // 0x5f5faa: 7512 JNZ 0x005f5fbe
    if(integer::condition("JNZ",flags)) goto L005f5fbe;
  }
  L005f5fac: { // 0x5f5fac: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L005f5fb0: { // 0x5f5fb0: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005f5fb4: { // 0x5f5fb4: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005f5fb6: { // 0x5f5fb6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005f5fb7: { // 0x5f5fb7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f5fb8: { // 0x5f5fb8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f5fba: { // 0x5f5fba: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f5fbc: { // 0x5f5fbc: eb23 JMP 0x005f5fe1
    goto L005f5fe1;
  }
  L005f5fbe: { // 0x5f5fbe: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005f5fc1: { // 0x5f5fc1: 7510 JNZ 0x005f5fd3
    if(integer::condition("JNZ",flags)) goto L005f5fd3;
  }
  L005f5fc3: { // 0x5f5fc3: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005f5fc7: { // 0x5f5fc7: 8d4201 LEA EAX,[EDX + 0x1]
    s.ax = (s.dx+0x00000001u);
  }
  L005f5fca: { // 0x5f5fca: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f5fcb: { // 0x5f5fcb: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f5fcd: { // 0x5f5fcd: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f5fcf: { // 0x5f5fcf: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L005f5fd1: { // 0x5f5fd1: eb0e JMP 0x005f5fe1
    goto L005f5fe1;
  }
  L005f5fd3: { // 0x5f5fd3: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005f5fd6: { // 0x5f5fd6: 750d JNZ 0x005f5fe5
    if(integer::condition("JNZ",flags)) goto L005f5fe5;
  }
  L005f5fd8: { // 0x5f5fd8: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005f5fdc: { // 0x5f5fdc: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L005f5fdf: { // 0x5f5fdf: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f5fe1: { // 0x5f5fe1: 01442434 ADD dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), integer::add(m.r32((f.sp+0x00000034u)),s.ax,32,flags));
  }
  L005f5fe5: { // 0x5f5fe5: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L005f5fe7: { // 0x5f5fe7: 8b5b04 MOV EBX,dword ptr [EBX + 0x4]
    s.bx = m.r32((s.bx+0x00000004u));
  }
  L005f5fea: { // 0x5f5fea: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L005f5fee: { // 0x5f5fee: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L005f5ff2: { // 0x5f5ff2: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005f5ff6: { // 0x5f5ff6: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L005f5ffa: { // 0x5f5ffa: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L005f5ffc: { // 0x5f5ffc: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L005f5ffe: { // 0x5f5ffe: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005f6000: { // 0x5f6000: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f6002: { // 0x5f6002: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L005f6006: { // 0x5f6006: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L005f600a: { // 0x5f600a: e801b3e3ff CALL 0x00431310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431310u,6250511u,op); flags=s.arithmetic_flags;
  }
  L005f600f: { // 0x5f600f: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L005f6013: { // 0x5f6013: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f6015: { // 0x5f6015: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f6016: { // 0x5f6016: e805b3e3ff CALL 0x00431320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431320u,6250523u,op); flags=s.arithmetic_flags;
  }
  L005f601b: { // 0x5f601b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f601d: { // 0x5f601d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f601e: { // 0x5f601e: e8cdb2e3ff CALL 0x004312f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004312f0u,6250531u,op); flags=s.arithmetic_flags;
  }
  L005f6023: { // 0x5f6023: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L005f6027: { // 0x5f6027: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L005f602b: { // 0x5f602b: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L005f602f: { // 0x5f602f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f6030: { // 0x5f6030: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L005f6034: { // 0x5f6034: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f6035: { // 0x5f6035: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  L005f6039: { // 0x5f6039: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f603a: { // 0x5f603a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f603b: { // 0x5f603b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f603c: { // 0x5f603c: 8b0d186d8300 MOV ECX,dword ptr [0x00836d18]
    s.cx = m.r32((0x00836d18u));
  }
  L005f6042: { // 0x5f6042: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f6043: { // 0x5f6043: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f6044: { // 0x5f6044: e8c7c1e3ff CALL 0x00432210
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432210u,6250569u,op); flags=s.arithmetic_flags;
  }
  L005f6049: { // 0x5f6049: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L005f604b: { // 0x5f604b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f604c: { // 0x5f604c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f604d: { // 0x5f604d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f604e: { // 0x5f604e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f604f: { // 0x5f604f: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L005f6052: { // 0x5f6052: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
}

void f_00234310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00634310: { // 0x634310: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00634311: { // 0x634311: 8a19 MOV BL,byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00634313: { // 0x634313: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00634314: { // 0x634314: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L00634318: { // 0x634318: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00634319: { // 0x634319: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0063431d: { // 0x63431d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0063431f: { // 0x63431f: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00634321: { // 0x634321: 8a07 MOV AL,byte ptr [EDI]
    s.ax = with_al(s.ax, m.r8((s.di)));
  }
  L00634323: { // 0x634323: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00634329: { // 0x634329: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L0063432f: { // 0x63432f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00634331: { // 0x634331: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00634334: { // 0x634334: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00634335: { // 0x634335: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0063433b: { // 0x63433b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0063433d: { // 0x63433d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00634340: { // 0x634340: 02c3 ADD AL,BL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00634342: { // 0x634342: 8a5901 MOV BL,byte ptr [ECX + 0x1]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000001u)));
  }
  L00634345: { // 0x634345: 8801 MOV byte ptr [ECX],AL
    m.w8((s.cx), (s.ax & 0xffu));
  }
  L00634347: { // 0x634347: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00634349: { // 0x634349: 8a4701 MOV AL,byte ptr [EDI + 0x1]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000001u)));
  }
  L0063434c: { // 0x63434c: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0063434e: { // 0x63434e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00634354: { // 0x634354: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00634356: { // 0x634356: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00634359: { // 0x634359: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0063435a: { // 0x63435a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00634360: { // 0x634360: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00634362: { // 0x634362: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00634365: { // 0x634365: 02c3 ADD AL,BL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00634367: { // 0x634367: 8a5902 MOV BL,byte ptr [ECX + 0x2]
    s.bx = with_al(s.bx, m.r8((s.cx+0x00000002u)));
  }
  L0063436a: { // 0x63436a: 884101 MOV byte ptr [ECX + 0x1],AL
    m.w8((s.cx+0x00000001u), (s.ax & 0xffu));
  }
  L0063436d: { // 0x63436d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0063436f: { // 0x63436f: 8a4702 MOV AL,byte ptr [EDI + 0x2]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000002u)));
  }
  L00634372: { // 0x634372: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L00634374: { // 0x634374: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0063437a: { // 0x63437a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0063437b: { // 0x63437b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0063437d: { // 0x63437d: 0fafc6 IMUL EAX,ESI
    s.ax = integer::imul(s.ax,s.si,32,flags);
  }
  L00634380: { // 0x634380: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00634381: { // 0x634381: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00634387: { // 0x634387: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00634388: { // 0x634388: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0063438a: { // 0x63438a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0063438d: { // 0x63438d: 02c3 ADD AL,BL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L0063438f: { // 0x63438f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00634390: { // 0x634390: 884102 MOV byte ptr [ECX + 0x2],AL
    m.w8((s.cx+0x00000002u), (s.ax & 0xffu));
  }
  L00634393: { // 0x634393: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_0035fcd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075fcd0: { // 0x75fcd0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0075fcd4: { // 0x75fcd4: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0075fcd7: { // 0x75fcd7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075fcd8: { // 0x75fcd8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0075fcda: { // 0x75fcda: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fcdb: { // 0x75fcdb: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0075fcdf: { // 0x75fcdf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075fce1: { // 0x75fce1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fce2: { // 0x75fce2: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),7732453u,op); flags=s.arithmetic_flags;
  }
  L0075fce5: { // 0x75fce5: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075fce9: { // 0x75fce9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fcea: { // 0x75fcea: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fceb: { // 0x75fceb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075fced: { // 0x75fced: e80e000000 CALL 0x0075fd00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0075fd00u,7732466u,op); flags=s.arithmetic_flags;
  }
  L0075fcf2: { // 0x75fcf2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075fcf3: { // 0x75fcf3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0075fcf6: { // 0x75fcf6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_0035fd00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075fd00: { // 0x75fd00: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0075fd01: { // 0x75fd01: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0075fd03: { // 0x75fd03: 83ec6c SUB ESP,0x6c
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L0075fd06: { // 0x75fd06: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fd07: { // 0x75fd07: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075fd08: { // 0x75fd08: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0075fd0b: { // 0x75fd0b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fd0c: { // 0x75fd0c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0075fd0e: { // 0x75fd0e: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0075fd11: { // 0x75fd11: 897dfc MOV dword ptr [EBP + -0x4],EDI
    m.w32((s.bp-0x00000004u), s.di);
  }
  L0075fd14: { // 0x75fd14: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fd16: { // 0x75fd16: 0f8ec5020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fd1c: { // 0x75fd1c: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0075fd1f: { // 0x75fd1f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fd21: { // 0x75fd21: 0f8eba020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fd27: { // 0x75fd27: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0075fd29: { // 0x75fd29: 8d4db4 LEA ECX,[EBP + -0x4c]
    s.cx = (s.bp-0x0000004cu);
  }
  L0075fd2c: { // 0x75fd2c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fd2d: { // 0x75fd2d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fd2f: { // 0x75fd2f: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7732530u,op); flags=s.arithmetic_flags;
  }
  L0075fd32: { // 0x75fd32: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0075fd35: { // 0x75fd35: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd37: { // 0x75fd37: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd39: { // 0x75fd39: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fd3a: { // 0x75fd3a: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0075fd3c: { // 0x75fd3c: 8d4de4 LEA ECX,[EBP + -0x1c]
    s.cx = (s.bp-0x0000001cu);
  }
  L0075fd3f: { // 0x75fd3f: e8ac00ccff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7732548u,op); flags=s.arithmetic_flags;
  }
  L0075fd44: { // 0x75fd44: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0075fd46: { // 0x75fd46: 8955c4 MOV dword ptr [EBP + -0x3c],EDX
    m.w32((s.bp-0x0000003cu), s.dx);
  }
  L0075fd49: { // 0x75fd49: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0075fd4c: { // 0x75fd4c: 894dc8 MOV dword ptr [EBP + -0x38],ECX
    m.w32((s.bp-0x00000038u), s.cx);
  }
  L0075fd4f: { // 0x75fd4f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0075fd51: { // 0x75fd51: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0075fd54: { // 0x75fd54: 8955cc MOV dword ptr [EBP + -0x34],EDX
    m.w32((s.bp-0x00000034u), s.dx);
  }
  L0075fd57: { // 0x75fd57: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0075fd5a: { // 0x75fd5a: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075fd5d: { // 0x75fd5d: 8945d0 MOV dword ptr [EBP + -0x30],EAX
    m.w32((s.bp-0x00000030u), s.ax);
  }
  L0075fd60: { // 0x75fd60: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075fd62: { // 0x75fd62: 8b5b04 MOV EBX,dword ptr [EBX + 0x4]
    s.bx = m.r32((s.bx+0x00000004u));
  }
  L0075fd65: { // 0x75fd65: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0075fd67: { // 0x75fd67: 8945ec MOV dword ptr [EBP + -0x14],EAX
    m.w32((s.bp-0x00000014u), s.ax);
  }
  L0075fd6a: { // 0x75fd6a: 8d45ec LEA EAX,[EBP + -0x14]
    s.ax = (s.bp-0x00000014u);
  }
  L0075fd6d: { // 0x75fd6d: 8d0c1a LEA ECX,[EDX + EBX*0x1]
    s.cx = (s.dx+(s.bx * 0x00000001u));
  }
  L0075fd70: { // 0x75fd70: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0075fd73: { // 0x75fd73: 894df0 MOV dword ptr [EBP + -0x10],ECX
    m.w32((s.bp-0x00000010u), s.cx);
  }
  L0075fd76: { // 0x75fd76: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L0075fd79: { // 0x75fd79: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fd7a: { // 0x75fd7a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0075fd7b: { // 0x75fd7b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fd7c: { // 0x75fd7c: 8d4da4 LEA ECX,[EBP + -0x5c]
    s.cx = (s.bp-0x0000005cu);
  }
  L0075fd7f: { // 0x75fd7f: e82c3dcfff CALL 0x00453ab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ab0u,7732612u,op); flags=s.arithmetic_flags;
  }
  L0075fd84: { // 0x75fd84: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0075fd86: { // 0x75fd86: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd88: { // 0x75fd88: 894db4 MOV dword ptr [EBP + -0x4c],ECX
    m.w32((s.bp-0x0000004cu), s.cx);
  }
  L0075fd8b: { // 0x75fd8b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075fd8d: { // 0x75fd8d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0075fd90: { // 0x75fd90: 8955b8 MOV dword ptr [EBP + -0x48],EDX
    m.w32((s.bp-0x00000048u), s.dx);
  }
  L0075fd93: { // 0x75fd93: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0075fd96: { // 0x75fd96: 894dbc MOV dword ptr [EBP + -0x44],ECX
    m.w32((s.bp-0x00000044u), s.cx);
  }
  L0075fd99: { // 0x75fd99: 8d4d94 LEA ECX,[EBP + -0x6c]
    s.cx = (s.bp-0x0000006cu);
  }
  L0075fd9c: { // 0x75fd9c: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0075fd9f: { // 0x75fd9f: 8d45b4 LEA EAX,[EBP + -0x4c]
    s.ax = (s.bp-0x0000004cu);
  }
  L0075fda2: { // 0x75fda2: 8955c0 MOV dword ptr [EBP + -0x40],EDX
    m.w32((s.bp-0x00000040u), s.dx);
  }
  L0075fda5: { // 0x75fda5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fda6: { // 0x75fda6: 8d55c4 LEA EDX,[EBP + -0x3c]
    s.dx = (s.bp-0x0000003cu);
  }
  L0075fda9: { // 0x75fda9: e84200ccff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7732654u,op); flags=s.arithmetic_flags;
  }
  L0075fdae: { // 0x75fdae: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0075fdb0: { // 0x75fdb0: 894dd4 MOV dword ptr [EBP + -0x2c],ECX
    m.w32((s.bp-0x0000002cu), s.cx);
  }
  L0075fdb3: { // 0x75fdb3: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0075fdb6: { // 0x75fdb6: 8955d8 MOV dword ptr [EBP + -0x28],EDX
    m.w32((s.bp-0x00000028u), s.dx);
  }
  L0075fdb9: { // 0x75fdb9: 8b5808 MOV EBX,dword ptr [EAX + 0x8]
    s.bx = m.r32((s.ax+0x00000008u));
  }
  L0075fdbc: { // 0x75fdbc: 895ddc MOV dword ptr [EBP + -0x24],EBX
    m.w32((s.bp-0x00000024u), s.bx);
  }
  L0075fdbf: { // 0x75fdbf: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075fdc2: { // 0x75fdc2: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0075fdc4: { // 0x75fdc4: 8945e0 MOV dword ptr [EBP + -0x20],EAX
    m.w32((s.bp-0x00000020u), s.ax);
  }
  L0075fdc7: { // 0x75fdc7: 0f8e14020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fdcd: { // 0x75fdcd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fdcf: { // 0x75fdcf: 0f8e0c020000 JLE 0x0075ffe1
    if(integer::condition("JLE",flags)) goto L0075ffe1;
  }
  L0075fdd5: { // 0x75fdd5: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fdd8: { // 0x75fdd8: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0075fdda: { // 0x75fdda: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fddc: { // 0x75fddc: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7732703u,op); flags=s.arithmetic_flags;
  }
  L0075fddf: { // 0x75fddf: 8d4dec LEA ECX,[EBP + -0x14]
    s.cx = (s.bp-0x00000014u);
  }
  L0075fde2: { // 0x75fde2: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L0075fde5: { // 0x75fde5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fde6: { // 0x75fde6: 8d4dd4 LEA ECX,[EBP + -0x2c]
    s.cx = (s.bp-0x0000002cu);
  }
  L0075fde9: { // 0x75fde9: e83256cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7732718u,op); flags=s.arithmetic_flags;
  }
  L0075fdee: { // 0x75fdee: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0075fdf0: { // 0x75fdf0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0075fdf3: { // 0x75fdf3: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L0075fdf5: { // 0x75fdf5: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0075fdf7: { // 0x75fdf7: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L0075fdfa: { // 0x75fdfa: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L0075fdfd: { // 0x75fdfd: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075fdff: { // 0x75fdff: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fe01: { // 0x75fe01: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7732740u,op); flags=s.arithmetic_flags;
  }
  L0075fe04: { // 0x75fe04: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0075fe06: { // 0x75fe06: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0075fe08: { // 0x75fe08: 8975f4 MOV dword ptr [EBP + -0xc],ESI
    m.w32((s.bp-0x0000000cu), s.si);
  }
  L0075fe0b: { // 0x75fe0b: 0f84d0010000 JZ 0x0075ffe1
    if(integer::condition("JZ",flags)) goto L0075ffe1;
  }
  L0075fe11: { // 0x75fe11: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0075fe13: { // 0x75fe13: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fe15: { // 0x75fe15: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),7732760u,op); flags=s.arithmetic_flags;
  }
  L0075fe18: { // 0x75fe18: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0075fe1b: { // 0x75fe1b: 755c JNZ 0x0075fe79
    if(integer::condition("JNZ",flags)) goto L0075fe79;
  }
  L0075fe1d: { // 0x75fe1d: 8b45e0 MOV EAX,dword ptr [EBP + -0x20]
    s.ax = m.r32((s.bp-0x00000020u));
  }
  L0075fe20: { // 0x75fe20: c7450800000000 MOV dword ptr [EBP + 0x8],0x0
    m.w32((s.bp+0x00000008u), 0x00000000u);
  }
  L0075fe27: { // 0x75fe27: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fe29: { // 0x75fe29: 0f8ea0010000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075fe2f: { // 0x75fe2f: 8a4510 MOV AL,byte ptr [EBP + 0x10]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000010u)));
  }
  L0075fe32: { // 0x75fe32: 8b4ddc MOV ECX,dword ptr [EBP + -0x24]
    s.cx = m.r32((s.bp-0x00000024u));
  }
  L0075fe35: { // 0x75fe35: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L0075fe37: { // 0x75fe37: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0075fe39: { // 0x75fe39: 8afb MOV BH,BL
    s.bx = (s.bx & 0xffff00ffu) | ((((s.bx & 0xffu)) & 0xffu) << 8);
  }
  L0075fe3b: { // 0x75fe3b: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0075fe3d: { // 0x75fe3d: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0075fe3f: { // 0x75fe3f: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075fe42: { // 0x75fe42: 668bc3 MOV AX,BX
    s.ax = with_ax(s.ax, (s.bx & 0xffffu));
  }
  L0075fe45: { // 0x75fe45: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0075fe48: { // 0x75fe48: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075fe4a: { // 0x75fe4a: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0075fe4c: { // 0x75fe4c: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0075fe4f: { // 0x75fe4f: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L0075fe51: { // 0x75fe51: 8b7d0c MOV EDI,dword ptr [EBP + 0xc]
    s.di = m.r32((s.bp+0x0000000cu));
  }
  L0075fe54: { // 0x75fe54: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075fe57: { // 0x75fe57: 8b4de0 MOV ECX,dword ptr [EBP + -0x20]
    s.cx = m.r32((s.bp-0x00000020u));
  }
  L0075fe5a: { // 0x75fe5a: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0075fe5c: { // 0x75fe5c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0075fe5d: { // 0x75fe5d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0075fe5f: { // 0x75fe5f: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fe62: { // 0x75fe62: 7ccb JL 0x0075fe2f
    if(integer::condition("JL",flags)) goto L0075fe2f;
  }
  L0075fe64: { // 0x75fe64: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075fe67: { // 0x75fe67: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fe69: { // 0x75fe69: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075fe6b: { // 0x75fe6b: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732846u,op); flags=s.arithmetic_flags;
  }
  L0075fe6e: { // 0x75fe6e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075fe70: { // 0x75fe70: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075fe71: { // 0x75fe71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075fe72: { // 0x75fe72: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075fe73: { // 0x75fe73: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075fe75: { // 0x75fe75: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075fe76: { // 0x75fe76: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075fe79: { // 0x75fe79: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0075fe7b: { // 0x75fe7b: 83e003 AND EAX,0x3
    s.ax = integer::logical((s.ax)&(0x00000003u),32,flags);
  }
  L0075fe7e: { // 0x75fe7e: 83e800 SUB EAX,0x0
    s.ax = integer::sub(s.ax,0x00000000u,32,flags);
  }
  L0075fe81: { // 0x75fe81: 0f84f8000000 JZ 0x0075ff7f
    if(integer::condition("JZ",flags)) goto L0075ff7f;
  }
  L0075fe87: { // 0x75fe87: 83e802 SUB EAX,0x2
    s.ax = integer::sub(s.ax,0x00000002u,32,flags);
  }
  L0075fe8a: { // 0x75fe8a: 7450 JZ 0x0075fedc
    if(integer::condition("JZ",flags)) goto L0075fedc;
  }
  L0075fe8c: { // 0x75fe8c: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075fe8f: { // 0x75fe8f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075fe91: { // 0x75fe91: 0f8e38010000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075fe97: { // 0x75fe97: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fe9a: { // 0x75fe9a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0075fe9c: { // 0x75fe9c: 7e1e JLE 0x0075febc
    if(integer::condition("JLE",flags)) goto L0075febc;
  }
  L0075fe9e: { // 0x75fe9e: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0075fea1: { // 0x75fea1: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075fea3: { // 0x75fea3: 668bd0 MOV DX,AX
    s.dx = with_ax(s.dx, (s.ax & 0xffffu));
  }
  L0075fea6: { // 0x75fea6: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0075fea8: { // 0x75fea8: c1e210 SHL EDX,0x10
    s.dx = integer::shift(s.dx,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075feab: { // 0x75feab: 668bd0 MOV DX,AX
    s.dx = with_ax(s.dx, (s.ax & 0xffffu));
  }
  L0075feae: { // 0x75feae: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0075feb0: { // 0x75feb0: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0075feb2: { // 0x75feb2: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075feb4: { // 0x75feb4: 13c9 ADC ECX,ECX
    s.cx = integer::add(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  L0075feb6: { // 0x75feb6: 66f3ab STOSW.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,16u,Repeat::count);
  }
  L0075feb9: { // 0x75feb9: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075febc: { // 0x75febc: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0075febf: { // 0x75febf: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075fec2: { // 0x75fec2: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0075fec4: { // 0x75fec4: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075fec5: { // 0x75fec5: 894508 MOV dword ptr [EBP + 0x8],EAX
    m.w32((s.bp+0x00000008u), s.ax);
  }
  L0075fec8: { // 0x75fec8: 75d0 JNZ 0x0075fe9a
    if(integer::condition("JNZ",flags)) goto L0075fe9a;
  }
  L0075feca: { // 0x75feca: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075fecc: { // 0x75fecc: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075fece: { // 0x75fece: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732945u,op); flags=s.arithmetic_flags;
  }
  L0075fed1: { // 0x75fed1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075fed3: { // 0x75fed3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075fed4: { // 0x75fed4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075fed5: { // 0x75fed5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075fed6: { // 0x75fed6: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075fed8: { // 0x75fed8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075fed9: { // 0x75fed9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075fedc: { // 0x75fedc: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L0075fedf: { // 0x75fedf: 7f31 JG 0x0075ff12
    if(integer::condition("JG",flags)) goto L0075ff12;
  }
  L0075fee1: { // 0x75fee1: 0f85e8000000 JNZ 0x0075ffcf
    if(integer::condition("JNZ",flags)) goto L0075ffcf;
  }
  L0075fee7: { // 0x75fee7: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075feea: { // 0x75feea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075feec: { // 0x75feec: 0f8edd000000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075fef2: { // 0x75fef2: 8b4d10 MOV ECX,dword ptr [EBP + 0x10]
    s.cx = m.r32((s.bp+0x00000010u));
  }
  L0075fef5: { // 0x75fef5: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L0075fef8: { // 0x75fef8: 66890e MOV word ptr [ESI],CX
    m.w16((s.si), (s.cx & 0xffffu));
  }
  L0075fefb: { // 0x75fefb: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L0075fefd: { // 0x75fefd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075fefe: { // 0x75fefe: 75f5 JNZ 0x0075fef5
    if(integer::condition("JNZ",flags)) goto L0075fef5;
  }
  L0075ff00: { // 0x75ff00: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075ff02: { // 0x75ff02: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075ff04: { // 0x75ff04: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732999u,op); flags=s.arithmetic_flags;
  }
  L0075ff07: { // 0x75ff07: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075ff09: { // 0x75ff09: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ff0a: { // 0x75ff0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ff0b: { // 0x75ff0b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ff0c: { // 0x75ff0c: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ff0e: { // 0x75ff0e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ff0f: { // 0x75ff0f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075ff12: { // 0x75ff12: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0075ff13: { // 0x75ff13: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0075ff15: { // 0x75ff15: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0075ff17: { // 0x75ff17: 895df8 MOV dword ptr [EBP + -0x8],EBX
    m.w32((s.bp-0x00000008u), s.bx);
  }
  L0075ff1a: { // 0x75ff1a: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0075ff1d: { // 0x75ff1d: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0075ff1f: { // 0x75ff1f: 83e201 AND EDX,0x1
    s.dx = integer::logical((s.dx)&(0x00000001u),32,flags);
  }
  L0075ff22: { // 0x75ff22: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075ff25: { // 0x75ff25: 0bc3 OR EAX,EBX
    s.ax = integer::logical((s.ax)|(s.bx),32,flags);
  }
  L0075ff27: { // 0x75ff27: 8945f4 MOV dword ptr [EBP + -0xc],EAX
    m.w32((s.bp-0x0000000cu), s.ax);
  }
  L0075ff2a: { // 0x75ff2a: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075ff2d: { // 0x75ff2d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075ff2f: { // 0x75ff2f: 0f8e9a000000 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075ff35: { // 0x75ff35: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ff38: { // 0x75ff38: 8d4e02 LEA ECX,[ESI + 0x2]
    s.cx = (s.si+0x00000002u);
  }
  L0075ff3b: { // 0x75ff3b: 66891e MOV word ptr [ESI],BX
    m.w16((s.si), (s.bx & 0xffffu));
  }
  L0075ff3e: { // 0x75ff3e: 894d08 MOV dword ptr [EBP + 0x8],ECX
    m.w32((s.bp+0x00000008u), s.cx);
  }
  L0075ff41: { // 0x75ff41: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075ff42: { // 0x75ff42: 8b4df8 MOV ECX,dword ptr [EBP + -0x8]
    s.cx = m.r32((s.bp-0x00000008u));
  }
  L0075ff45: { // 0x75ff45: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0075ff48: { // 0x75ff48: 83f900 CMP ECX,0x0
    (void)integer::sub(s.cx,0x00000000u,32,flags);
  }
  L0075ff4b: { // 0x75ff4b: 7e05 JLE 0x0075ff52
    if(integer::condition("JLE",flags)) goto L0075ff52;
  }
  L0075ff4d: { // 0x75ff4d: 8b45f4 MOV EAX,dword ptr [EBP + -0xc]
    s.ax = m.r32((s.bp-0x0000000cu));
  }
  L0075ff50: { // 0x75ff50: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075ff52: { // 0x75ff52: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0075ff54: { // 0x75ff54: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ff55: { // 0x75ff55: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0075ff57: { // 0x75ff57: 7403 JZ 0x0075ff5c
    if(integer::condition("JZ",flags)) goto L0075ff5c;
  }
  L0075ff59: { // 0x75ff59: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L0075ff5c: { // 0x75ff5c: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0075ff5f: { // 0x75ff5f: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0075ff62: { // 0x75ff62: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0075ff64: { // 0x75ff64: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075ff65: { // 0x75ff65: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ff68: { // 0x75ff68: 75ce JNZ 0x0075ff38
    if(integer::condition("JNZ",flags)) goto L0075ff38;
  }
  L0075ff6a: { // 0x75ff6a: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075ff6d: { // 0x75ff6d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075ff6f: { // 0x75ff6f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075ff71: { // 0x75ff71: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7733108u,op); flags=s.arithmetic_flags;
  }
  L0075ff74: { // 0x75ff74: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075ff76: { // 0x75ff76: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ff77: { // 0x75ff77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ff78: { // 0x75ff78: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ff79: { // 0x75ff79: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ff7b: { // 0x75ff7b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ff7c: { // 0x75ff7c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075ff7f: { // 0x75ff7f: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L0075ff81: { // 0x75ff81: d1fb SAR EBX,0x1
    s.bx = integer::shift(s.bx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0075ff83: { // 0x75ff83: 895df8 MOV dword ptr [EBP + -0x8],EBX
    m.w32((s.bp-0x00000008u), s.bx);
  }
  L0075ff86: { // 0x75ff86: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0075ff89: { // 0x75ff89: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0075ff8b: { // 0x75ff8b: 83e201 AND EDX,0x1
    s.dx = integer::logical((s.dx)&(0x00000001u),32,flags);
  }
  L0075ff8e: { // 0x75ff8e: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075ff91: { // 0x75ff91: 0bc3 OR EAX,EBX
    s.ax = integer::logical((s.ax)|(s.bx),32,flags);
  }
  L0075ff93: { // 0x75ff93: 8945f0 MOV dword ptr [EBP + -0x10],EAX
    m.w32((s.bp-0x00000010u), s.ax);
  }
  L0075ff96: { // 0x75ff96: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0075ff99: { // 0x75ff99: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075ff9b: { // 0x75ff9b: 7e32 JLE 0x0075ffcf
    if(integer::condition("JLE",flags)) goto L0075ffcf;
  }
  L0075ff9d: { // 0x75ff9d: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ffa0: { // 0x75ffa0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075ffa1: { // 0x75ffa1: 8b4df8 MOV ECX,dword ptr [EBP + -0x8]
    s.cx = m.r32((s.bp-0x00000008u));
  }
  L0075ffa4: { // 0x75ffa4: 8b7df4 MOV EDI,dword ptr [EBP + -0xc]
    s.di = m.r32((s.bp-0x0000000cu));
  }
  L0075ffa7: { // 0x75ffa7: 83f900 CMP ECX,0x0
    (void)integer::sub(s.cx,0x00000000u,32,flags);
  }
  L0075ffaa: { // 0x75ffaa: 7e05 JLE 0x0075ffb1
    if(integer::condition("JLE",flags)) goto L0075ffb1;
  }
  L0075ffac: { // 0x75ffac: 8b45f0 MOV EAX,dword ptr [EBP + -0x10]
    s.ax = m.r32((s.bp-0x00000010u));
  }
  L0075ffaf: { // 0x75ffaf: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075ffb1: { // 0x75ffb1: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0075ffb3: { // 0x75ffb3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ffb4: { // 0x75ffb4: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0075ffb6: { // 0x75ffb6: 7403 JZ 0x0075ffbb
    if(integer::condition("JZ",flags)) goto L0075ffbb;
  }
  L0075ffb8: { // 0x75ffb8: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L0075ffbb: { // 0x75ffbb: 8b4d0c MOV ECX,dword ptr [EBP + 0xc]
    s.cx = m.r32((s.bp+0x0000000cu));
  }
  L0075ffbe: { // 0x75ffbe: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0075ffc1: { // 0x75ffc1: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0075ffc3: { // 0x75ffc3: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0075ffc4: { // 0x75ffc4: 8975f4 MOV dword ptr [EBP + -0xc],ESI
    m.w32((s.bp-0x0000000cu), s.si);
  }
  L0075ffc7: { // 0x75ffc7: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0075ffca: { // 0x75ffca: 75d4 JNZ 0x0075ffa0
    if(integer::condition("JNZ",flags)) goto L0075ffa0;
  }
  L0075ffcc: { // 0x75ffcc: 8b7dfc MOV EDI,dword ptr [EBP + -0x4]
    s.di = m.r32((s.bp-0x00000004u));
  }
  L0075ffcf: { // 0x75ffcf: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0075ffd1: { // 0x75ffd1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0075ffd3: { // 0x75ffd3: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7733206u,op); flags=s.arithmetic_flags;
  }
  L0075ffd6: { // 0x75ffd6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075ffd8: { // 0x75ffd8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ffd9: { // 0x75ffd9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ffda: { // 0x75ffda: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ffdb: { // 0x75ffdb: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ffdd: { // 0x75ffdd: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ffde: { // 0x75ffde: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0075ffe1: { // 0x75ffe1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075ffe2: { // 0x75ffe2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075ffe3: { // 0x75ffe3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0075ffe5: { // 0x75ffe5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075ffe6: { // 0x75ffe6: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0075ffe8: { // 0x75ffe8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075ffe9: { // 0x75ffe9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_0036ef45(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076ef45: { // 0x76ef45: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0076ef49: { // 0x76ef49: 66833900 CMP word ptr [ECX],0x0
    (void)integer::sub(m.r16((s.cx)),0x00000000u,16,flags);
  }
  L0076ef4d: { // 0x76ef4d: 8d4102 LEA EAX,[ECX + 0x2]
    s.ax = (s.cx+0x00000002u);
  }
  L0076ef50: { // 0x76ef50: 740a JZ 0x0076ef5c
    if(integer::condition("JZ",flags)) goto L0076ef5c;
  }
  L0076ef52: { // 0x76ef52: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0076ef55: { // 0x76ef55: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0076ef56: { // 0x76ef56: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0076ef57: { // 0x76ef57: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L0076ef5a: { // 0x76ef5a: 75f6 JNZ 0x0076ef52
    if(integer::condition("JNZ",flags)) goto L0076ef52;
  }
  L0076ef5c: { // 0x76ef5c: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0076ef5e: { // 0x76ef5e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0076ef60: { // 0x76ef60: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0076ef61: { // 0x76ef61: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0036ef62(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076ef62: { // 0x76ef62: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0076ef66: { // 0x76ef66: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076ef67: { // 0x76ef67: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076ef68: { // 0x76ef68: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0076ef6c: { // 0x76ef6c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0076ef6e: { // 0x76ef6e: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L0076ef70: { // 0x76ef70: 7428 JZ 0x0076ef9a
    if(integer::condition("JZ",flags)) goto L0076ef9a;
  }
  L0076ef72: { // 0x76ef72: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0076ef76: { // 0x76ef76: 668b02 MOV AX,word ptr [EDX]
    s.ax = with_ax(s.ax, m.r16((s.dx)));
  }
  L0076ef79: { // 0x76ef79: 668907 MOV word ptr [EDI],AX
    m.w16((s.di), (s.ax & 0xffffu));
  }
  L0076ef7c: { // 0x76ef7c: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076ef7d: { // 0x76ef7d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076ef7e: { // 0x76ef7e: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0076ef7f: { // 0x76ef7f: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0076ef80: { // 0x76ef80: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L0076ef83: { // 0x76ef83: 7403 JZ 0x0076ef88
    if(integer::condition("JZ",flags)) goto L0076ef88;
  }
  L0076ef85: { // 0x76ef85: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ef86: { // 0x76ef86: 75ee JNZ 0x0076ef76
    if(integer::condition("JNZ",flags)) goto L0076ef76;
  }
  L0076ef88: { // 0x76ef88: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0076ef8a: { // 0x76ef8a: 740e JZ 0x0076ef9a
    if(integer::condition("JZ",flags)) goto L0076ef9a;
  }
  L0076ef8c: { // 0x76ef8c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ef8d: { // 0x76ef8d: 740b JZ 0x0076ef9a
    if(integer::condition("JZ",flags)) goto L0076ef9a;
  }
  L0076ef8f: { // 0x76ef8f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ef91: { // 0x76ef91: d1e9 SHR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0076ef93: { // 0x76ef93: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0076ef95: { // 0x76ef95: 13c9 ADC ECX,ECX
    s.cx = integer::add(s.cx,s.cx,32,flags,flags&integer::CF);
  }
  L0076ef97: { // 0x76ef97: 66f3ab STOSW.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,16u,Repeat::count);
  }
  L0076ef9a: { // 0x76ef9a: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0076ef9c: { // 0x76ef9c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076ef9d: { // 0x76ef9d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076ef9e: { // 0x76ef9e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0036f190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076f190: { // 0x76f190: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0076f191: { // 0x76f191: 3d00100000 CMP EAX,0x1000
    (void)integer::sub(s.ax,0x00001000u,32,flags);
  }
  L0076f196: { // 0x76f196: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L0076f19a: { // 0x76f19a: 7214 JC 0x0076f1b0
    if(integer::condition("JC",flags)) goto L0076f1b0;
  }
  L0076f19c: { // 0x76f19c: 81e900100000 SUB ECX,0x1000
    s.cx = integer::sub(s.cx,0x00001000u,32,flags);
  }
  L0076f1a2: { // 0x76f1a2: 2d00100000 SUB EAX,0x1000
    s.ax = integer::sub(s.ax,0x00001000u,32,flags);
  }
  L0076f1a7: { // 0x76f1a7: 8501 TEST dword ptr [ECX],EAX
    if(!op.probe_context||!op.access_probe)throw std::domain_error("genuine owned access-probe required");
    op.access_probe(op.probe_context,m,0x76f1a7u,s.cx,s.ax);
  }
  L0076f1a9: { // 0x76f1a9: 3d00100000 CMP EAX,0x1000
    (void)integer::sub(s.ax,0x00001000u,32,flags);
  }
  L0076f1ae: { // 0x76f1ae: 73ec JNC 0x0076f19c
    if(integer::condition("JNC",flags)) goto L0076f19c;
  }
  L0076f1b0: { // 0x76f1b0: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0076f1b2: { // 0x76f1b2: 8bc4 MOV EAX,ESP
    s.ax = f.sp;
  }
  L0076f1b4: { // 0x76f1b4: 8501 TEST dword ptr [ECX],EAX
    if(!op.probe_context||!op.access_probe)throw std::domain_error("genuine owned access-probe required");
    op.access_probe(op.probe_context,m,0x76f1b4u,s.cx,s.ax);
  }
  L0076f1b6: { // 0x76f1b6: 8be1 MOV ESP,ECX
    f.sp = s.cx;
  }
  L0076f1b8: { // 0x76f1b8: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0076f1ba: { // 0x76f1ba: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L0076f1bd: { // 0x76f1bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076f1be: { // 0x76f1be: c3 RET
    s.arithmetic_flags=flags; finish_stack_probe(m,s,f,0u,0x76f1beu); return;
  }
}
