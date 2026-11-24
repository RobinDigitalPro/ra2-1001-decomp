void f_002b69d0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);

void invoke_candidate(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_002ccac0(Memory&,State&,Frame&,const Operations&);
void f_001ccbd0(Memory&,State&,Frame&,const Operations&);
void f_000ba080(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);

void f_002ccac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ccac0: { // 0x6ccac0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006ccac1: { // 0x6ccac1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L006ccac3: { // 0x6ccac3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L006ccac6: { // 0x6ccac6: 83ec4c SUB ESP,0x4c
    f.sp = integer::sub(f.sp,0x0000004cu,32,flags);
  }
  L006ccac9: { // 0x6ccac9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006ccaca: { // 0x6ccaca: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ccacb: { // 0x6ccacb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ccacc: { // 0x6ccacc: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L006ccace: { // 0x6ccace: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006ccad0: { // 0x6ccad0: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x00000080u)),7129814u,op); flags=s.arithmetic_flags;
  }
  L006ccad6: { // 0x6ccad6: 8b7508 MOV ESI,dword ptr [EBP + 0x8]
    s.si = m.r32((s.bp+0x00000008u));
  }
  L006ccad9: { // 0x6ccad9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006ccadb: { // 0x6ccadb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccadd: { // 0x6ccadd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006ccadf: { // 0x6ccadf: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000084u)),7129829u,op); flags=s.arithmetic_flags;
  }
  L006ccae5: { // 0x6ccae5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ccae7: { // 0x6ccae7: 750f JNZ 0x006ccaf8
    if(integer::condition("JNZ",flags)) goto L006ccaf8;
  }
  L006ccae9: { // 0x6ccae9: dd0510667800 FLD double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L006ccaef: { // 0x6ccaef: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ccaf0: { // 0x6ccaf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ccaf1: { // 0x6ccaf1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ccaf2: { // 0x6ccaf2: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006ccaf4: { // 0x6ccaf4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006ccaf5: { // 0x6ccaf5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L006ccaf8: { // 0x6ccaf8: 8b87b4010000 MOV EAX,dword ptr [EDI + 0x1b4]
    s.ax = m.r32((s.di+0x000001b4u));
  }
  L006ccafe: { // 0x6ccafe: 8a8843010000 MOV CL,byte ptr [EAX + 0x143]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000143u)));
  }
  L006ccb04: { // 0x6ccb04: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006ccb06: { // 0x6ccb06: 7466 JZ 0x006ccb6e
    if(integer::condition("JZ",flags)) goto L006ccb6e;
  }
  L006ccb08: { // 0x6ccb08: 8b8b98020000 MOV ECX,dword ptr [EBX + 0x298]
    s.cx = m.r32((s.bx+0x00000298u));
  }
  L006ccb0e: { // 0x6ccb0e: 8b939c020000 MOV EDX,dword ptr [EBX + 0x29c]
    s.dx = m.r32((s.bx+0x0000029cu));
  }
  L006ccb14: { // 0x6ccb14: 8b83a0020000 MOV EAX,dword ptr [EBX + 0x2a0]
    s.ax = m.r32((s.bx+0x000002a0u));
  }
  L006ccb1a: { // 0x6ccb1a: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L006ccb1e: { // 0x6ccb1e: 8b8ba4020000 MOV ECX,dword ptr [EBX + 0x2a4]
    s.cx = m.r32((s.bx+0x000002a4u));
  }
  L006ccb24: { // 0x6ccb24: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L006ccb28: { // 0x6ccb28: 8b93a8020000 MOV EDX,dword ptr [EBX + 0x2a8]
    s.dx = m.r32((s.bx+0x000002a8u));
  }
  L006ccb2e: { // 0x6ccb2e: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006ccb32: { // 0x6ccb32: 8b83ac020000 MOV EAX,dword ptr [EBX + 0x2ac]
    s.ax = m.r32((s.bx+0x000002acu));
  }
  L006ccb38: { // 0x6ccb38: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L006ccb3c: { // 0x6ccb3c: 8b8bb0020000 MOV ECX,dword ptr [EBX + 0x2b0]
    s.cx = m.r32((s.bx+0x000002b0u));
  }
  L006ccb42: { // 0x6ccb42: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L006ccb46: { // 0x6ccb46: 8b93b4020000 MOV EDX,dword ptr [EBX + 0x2b4]
    s.dx = m.r32((s.bx+0x000002b4u));
  }
  L006ccb4c: { // 0x6ccb4c: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L006ccb50: { // 0x6ccb50: 8b83b8020000 MOV EAX,dword ptr [EBX + 0x2b8]
    s.ax = m.r32((s.bx+0x000002b8u));
  }
  L006ccb56: { // 0x6ccb56: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006ccb5a: { // 0x6ccb5a: 8b8bbc020000 MOV ECX,dword ptr [EBX + 0x2bc]
    s.cx = m.r32((s.bx+0x000002bcu));
  }
  L006ccb60: { // 0x6ccb60: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L006ccb64: { // 0x6ccb64: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L006ccb68: { // 0x6ccb68: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L006ccb6c: { // 0x6ccb6c: eb69 JMP 0x006ccbd7
    goto L006ccbd7;
  }
  L006ccb6e: { // 0x6ccb6e: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006ccb73: { // 0x6ccb73: 8b90280d0000 MOV EDX,dword ptr [EAX + 0xd28]
    s.dx = m.r32((s.ax+0x00000d28u));
  }
  L006ccb79: { // 0x6ccb79: 8b882c0d0000 MOV ECX,dword ptr [EAX + 0xd2c]
    s.cx = m.r32((s.ax+0x00000d2cu));
  }
  L006ccb7f: { // 0x6ccb7f: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L006ccb83: { // 0x6ccb83: 8b90300d0000 MOV EDX,dword ptr [EAX + 0xd30]
    s.dx = m.r32((s.ax+0x00000d30u));
  }
  L006ccb89: { // 0x6ccb89: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L006ccb8d: { // 0x6ccb8d: 8b88340d0000 MOV ECX,dword ptr [EAX + 0xd34]
    s.cx = m.r32((s.ax+0x00000d34u));
  }
  L006ccb93: { // 0x6ccb93: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006ccb97: { // 0x6ccb97: 8b90380d0000 MOV EDX,dword ptr [EAX + 0xd38]
    s.dx = m.r32((s.ax+0x00000d38u));
  }
  L006ccb9d: { // 0x6ccb9d: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L006ccba1: { // 0x6ccba1: 8b883c0d0000 MOV ECX,dword ptr [EAX + 0xd3c]
    s.cx = m.r32((s.ax+0x00000d3cu));
  }
  L006ccba7: { // 0x6ccba7: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L006ccbab: { // 0x6ccbab: 8b90400d0000 MOV EDX,dword ptr [EAX + 0xd40]
    s.dx = m.r32((s.ax+0x00000d40u));
  }
  L006ccbb1: { // 0x6ccbb1: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L006ccbb5: { // 0x6ccbb5: 8b88440d0000 MOV ECX,dword ptr [EAX + 0xd44]
    s.cx = m.r32((s.ax+0x00000d44u));
  }
  L006ccbbb: { // 0x6ccbbb: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L006ccbbf: { // 0x6ccbbf: 8b90480d0000 MOV EDX,dword ptr [EAX + 0xd48]
    s.dx = m.r32((s.ax+0x00000d48u));
  }
  L006ccbc5: { // 0x6ccbc5: 8b804c0d0000 MOV EAX,dword ptr [EAX + 0xd4c]
    s.ax = m.r32((s.ax+0x00000d4cu));
  }
  L006ccbcb: { // 0x6ccbcb: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L006ccbcf: { // 0x6ccbcf: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L006ccbd3: { // 0x6ccbd3: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L006ccbd7: { // 0x6ccbd7: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006ccbd9: { // 0x6ccbd9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ccbda: { // 0x6ccbda: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ccbdc: { // 0x6ccbdc: ff92b8020000 CALL dword ptr [EDX + 0x2b8]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x000002b8u)),7130082u,op); flags=s.arithmetic_flags;
  }
  L006ccbe2: { // 0x6ccbe2: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006ccbe4: { // 0x6ccbe4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ccbe5: { // 0x6ccbe5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ccbe7: { // 0x6ccbe7: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x0000039cu)),7130093u,op); flags=s.arithmetic_flags;
  }
  L006ccbed: { // 0x6ccbed: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006ccbef: { // 0x6ccbef: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006ccbf1: { // 0x6ccbf1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccbf3: { // 0x6ccbf3: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L006ccbf7: { // 0x6ccbf7: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L006ccbff: { // 0x6ccbff: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L006ccc07: { // 0x6ccc07: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x0000002cu)),7130122u,op); flags=s.arithmetic_flags;
  }
  L006ccc0a: { // 0x6ccc0a: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006ccc0d: { // 0x6ccc0d: 7413 JZ 0x006ccc22
    if(integer::condition("JZ",flags)) goto L006ccc22;
  }
  L006ccc0f: { // 0x6ccc0f: 83f80f CMP EAX,0xf
    (void)integer::sub(s.ax,0x0000000fu,32,flags);
  }
  L006ccc12: { // 0x6ccc12: 740e JZ 0x006ccc22
    if(integer::condition("JZ",flags)) goto L006ccc22;
  }
  L006ccc14: { // 0x6ccc14: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L006ccc17: { // 0x6ccc17: 7409 JZ 0x006ccc22
    if(integer::condition("JZ",flags)) goto L006ccc22;
  }
  L006ccc19: { // 0x6ccc19: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L006ccc1c: { // 0x6ccc1c: 0f85ab000000 JNZ 0x006ccccd
    if(integer::condition("JNZ",flags)) goto L006ccccd;
  }
  L006ccc22: { // 0x6ccc22: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ccc24: { // 0x6ccc24: 0f84a3000000 JZ 0x006ccccd
    if(integer::condition("JZ",flags)) goto L006ccccd;
  }
  L006ccc2a: { // 0x6ccc2a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ccc2c: { // 0x6ccc2c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ccc2d: { // 0x6ccc2d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccc2f: { // 0x6ccc2f: ff90b8020000 CALL dword ptr [EAX + 0x2b8]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x000002b8u)),7130165u,op); flags=s.arithmetic_flags;
  }
  L006ccc35: { // 0x6ccc35: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006ccc37: { // 0x6ccc37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ccc38: { // 0x6ccc38: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccc3a: { // 0x6ccc3a: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x0000039cu)),7130176u,op); flags=s.arithmetic_flags;
  }
  L006ccc40: { // 0x6ccc40: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006ccc42: { // 0x6ccc42: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ccc44: { // 0x6ccc44: 743c JZ 0x006ccc82
    if(integer::condition("JZ",flags)) goto L006ccc82;
  }
  L006ccc46: { // 0x6ccc46: 8b80ac000000 MOV EAX,dword ptr [EAX + 0xac]
    s.ax = m.r32((s.ax+0x000000acu));
  }
  L006ccc4c: { // 0x6ccc4c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ccc4e: { // 0x6ccc4e: 7432 JZ 0x006ccc82
    if(integer::condition("JZ",flags)) goto L006ccc82;
  }
  L006ccc50: { // 0x6ccc50: 39be28020000 CMP dword ptr [ESI + 0x228],EDI
    (void)integer::sub(m.r32((s.si+0x00000228u)),s.di,32,flags);
  }
  L006ccc56: { // 0x6ccc56: 7515 JNZ 0x006ccc6d
    if(integer::condition("JNZ",flags)) goto L006ccc6d;
  }
  L006ccc58: { // 0x6ccc58: 8b8b9c000000 MOV ECX,dword ptr [EBX + 0x9c]
    s.cx = m.r32((s.bx+0x0000009cu));
  }
  L006ccc5e: { // 0x6ccc5e: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L006ccc62: { // 0x6ccc62: dc8cc8a0000000 FMUL double ptr [EAX + ECX*0x8 + 0xa0]
    const auto address=(s.ax+(s.cx * 0x00000008u)+0x000000a0u);
    s.fp.multiply64(read64(m,address));
  }
  L006ccc69: { // 0x6ccc69: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L006ccc6b: { // 0x6ccc6b: eb11 JMP 0x006ccc7e
    goto L006ccc7e;
  }
  L006ccc6d: { // 0x6ccc6d: 8b939c000000 MOV EDX,dword ptr [EBX + 0x9c]
    s.dx = m.r32((s.bx+0x0000009cu));
  }
  L006ccc73: { // 0x6ccc73: dd442418 FLD double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load64(read64(m,address));
  }
  L006ccc77: { // 0x6ccc77: dc8cd0a0000000 FMUL double ptr [EAX + EDX*0x8 + 0xa0]
    const auto address=(s.ax+(s.dx * 0x00000008u)+0x000000a0u);
    s.fp.multiply64(read64(m,address));
  }
  L006ccc7e: { // 0x6ccc7e: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006ccc82: { // 0x6ccc82: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ccc84: { // 0x6ccc84: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccc86: { // 0x6ccc86: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x00000080u)),7130252u,op); flags=s.arithmetic_flags;
  }
  L006ccc8c: { // 0x6ccc8c: dd442420 FLD double ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load64(read64(m,address));
  }
  L006ccc90: { // 0x6ccc90: dc8890020000 FMUL double ptr [EAX + 0x290]
    const auto address=(s.ax+0x00000290u);
    s.fp.multiply64(read64(m,address));
  }
  L006ccc96: { // 0x6ccc96: 8b8fb4010000 MOV ECX,dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006ccc9c: { // 0x6ccc9c: dc442410 FADD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L006ccca0: { // 0x6ccca0: 8b81f0540000 MOV EAX,dword ptr [ECX + 0x54f0]
    s.ax = m.r32((s.cx+0x000054f0u));
  }
  L006ccca6: { // 0x6ccca6: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L006ccca9: { // 0x6ccca9: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006cccad: { // 0x6cccad: 741e JZ 0x006ccccd
    if(integer::condition("JZ",flags)) goto L006ccccd;
  }
  L006cccaf: { // 0x6cccaf: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L006cccb5: { // 0x6cccb5: 3b4230 CMP EAX,dword ptr [EDX + 0x30]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000030u)),32,flags);
  }
  L006cccb8: { // 0x6cccb8: 7513 JNZ 0x006ccccd
    if(integer::condition("JNZ",flags)) goto L006ccccd;
  }
  L006cccba: { // 0x6cccba: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006cccbf: { // 0x6cccbf: dd442410 FLD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load64(read64(m,address));
  }
  L006cccc3: { // 0x6cccc3: dc80500d0000 FADD double ptr [EAX + 0xd50]
    const auto address=(s.ax+0x00000d50u);
    s.fp.add64(read64(m,address));
  }
  L006cccc9: { // 0x6cccc9: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006ccccd: { // 0x6ccccd: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L006cccd1: { // 0x6cccd1: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006cccd3: { // 0x6cccd3: 7433 JZ 0x006ccd08
    if(integer::condition("JZ",flags)) goto L006ccd08;
  }
  L006cccd5: { // 0x6cccd5: 8b83ac000000 MOV EAX,dword ptr [EBX + 0xac]
    s.ax = m.r32((s.bx+0x000000acu));
  }
  L006cccdb: { // 0x6cccdb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cccdd: { // 0x6cccdd: 7429 JZ 0x006ccd08
    if(integer::condition("JZ",flags)) goto L006ccd08;
  }
  L006cccdf: { // 0x6cccdf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006ccce1: { // 0x6ccce1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccce3: { // 0x6ccce3: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000084u)),7130345u,op); flags=s.arithmetic_flags;
  }
  L006ccce9: { // 0x6ccce9: 8b809c000000 MOV EAX,dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006cccef: { // 0x6cccef: 8b8bac000000 MOV ECX,dword ptr [EBX + 0xac]
    s.cx = m.r32((s.bx+0x000000acu));
  }
  L006cccf5: { // 0x6cccf5: dd442430 FLD double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L006cccf9: { // 0x6cccf9: dc8cc1a0000000 FMUL double ptr [ECX + EAX*0x8 + 0xa0]
    const auto address=(s.cx+(s.ax * 0x00000008u)+0x000000a0u);
    s.fp.multiply64(read64(m,address));
  }
  L006ccd00: { // 0x6ccd00: dc442410 FADD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L006ccd04: { // 0x6ccd04: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006ccd08: { // 0x6ccd08: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccd0a: { // 0x6ccd0a: e8c1feefff CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x005ccbd0u,7130383u,op); flags=s.arithmetic_flags;
  }
  L006ccd0f: { // 0x6ccd0f: dc4c2440 FMUL double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.multiply64(read64(m,address));
  }
  L006ccd13: { // 0x6ccd13: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006ccd15: { // 0x6ccd15: dc442410 FADD double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.add64(read64(m,address));
  }
  L006ccd19: { // 0x6ccd19: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006ccd1d: { // 0x6ccd1d: 7408 JZ 0x006ccd27
    if(integer::condition("JZ",flags)) goto L006ccd27;
  }
  L006ccd1f: { // 0x6ccd1f: 8b83b4000000 MOV EAX,dword ptr [EBX + 0xb4]
    s.ax = m.r32((s.bx+0x000000b4u));
  }
  L006ccd25: { // 0x6ccd25: eb10 JMP 0x006ccd37
    goto L006ccd37;
  }
  L006ccd27: { // 0x6ccd27: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006ccd29: { // 0x6ccd29: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ccd2b: { // 0x6ccd2b: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000080u)),7130417u,op); flags=s.arithmetic_flags;
  }
  L006ccd31: { // 0x6ccd31: 8b8004050000 MOV EAX,dword ptr [EAX + 0x504]
    s.ax = m.r32((s.ax+0x00000504u));
  }
  L006ccd37: { // 0x6ccd37: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L006ccd3a: { // 0x6ccd3a: 8b0d907caa00 MOV ECX,dword ptr [0x00aa7c90]
    s.cx = m.r32((0x00aa7c90u));
  }
  L006ccd40: { // 0x6ccd40: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006ccd41: { // 0x6ccd41: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006ccd47: { // 0x6ccd47: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006ccd49: { // 0x6ccd49: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006ccd4c: { // 0x6ccd4c: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L006ccd50: { // 0x6ccd50: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L006ccd52: { // 0x6ccd52: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006ccd54: { // 0x6ccd54: 7518 JNZ 0x006ccd6e
    if(integer::condition("JNZ",flags)) goto L006ccd6e;
  }
  L006ccd56: { // 0x6ccd56: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L006ccd59: { // 0x6ccd59: a1947caa00 MOV EAX,[0x00aa7c94]
    s.ax = m.r32((0x00aa7c94u));
  }
  L006ccd5e: { // 0x6ccd5e: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006ccd60: { // 0x6ccd60: 750c JNZ 0x006ccd6e
    if(integer::condition("JNZ",flags)) goto L006ccd6e;
  }
  L006ccd62: { // 0x6ccd62: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L006ccd65: { // 0x6ccd65: a1987caa00 MOV EAX,[0x00aa7c98]
    s.ax = m.r32((0x00aa7c98u));
  }
  L006ccd6a: { // 0x6ccd6a: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006ccd6c: { // 0x6ccd6c: 7465 JZ 0x006ccdd3
    if(integer::condition("JZ",flags)) goto L006ccdd3;
  }
  L006ccd6e: { // 0x6ccd6e: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ccd70: { // 0x6ccd70: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L006ccd74: { // 0x6ccd74: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006ccd75: { // 0x6ccd75: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccd77: { // 0x6ccd77: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x00000048u)),7130490u,op); flags=s.arithmetic_flags;
  }
  L006ccd7a: { // 0x6ccd7a: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L006ccd7c: { // 0x6ccd7c: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006ccd7e: { // 0x6ccd7e: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L006ccd81: { // 0x6ccd81: 8b7008 MOV ESI,dword ptr [EAX + 0x8]
    s.si = m.r32((s.ax+0x00000008u));
  }
  L006ccd84: { // 0x6ccd84: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L006ccd86: { // 0x6ccd86: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L006ccd89: { // 0x6ccd89: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L006ccd8d: { // 0x6ccd8d: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L006ccd90: { // 0x6ccd90: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L006ccd92: { // 0x6ccd92: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L006ccd94: { // 0x6ccd94: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L006ccd98: { // 0x6ccd98: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L006ccd9c: { // 0x6ccd9c: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L006ccda0: { // 0x6ccda0: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L006ccda4: { // 0x6ccda4: db442440 FILD dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load_integer32(m.r32(address));
  }
  L006ccda8: { // 0x6ccda8: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L006ccdab: { // 0x6ccdab: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L006ccdad: { // 0x6ccdad: d8c9 FMUL st1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L006ccdaf: { // 0x6ccdaf: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L006ccdb1: { // 0x6ccdb1: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L006ccdb3: { // 0x6ccdb3: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006ccdb5: { // 0x6ccdb5: d9c3 FLD st3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L006ccdb7: { // 0x6ccdb7: d8cc FMUL st4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L006ccdb9: { // 0x6ccdb9: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006ccdbb: { // 0x6ccdbb: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006ccdbe: { // 0x6ccdbe: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006ccdc0: { // 0x6ccdc0: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006ccdc2: { // 0x6ccdc2: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006ccdc4: { // 0x6ccdc4: e8b7d2deff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x004ba080u,7130569u,op); flags=s.arithmetic_flags;
  }
  L006ccdc9: { // 0x6ccdc9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006ccdcc: { // 0x6ccdcc: e87fdc0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x0076aa50u,7130577u,op); flags=s.arithmetic_flags;
  }
  L006ccdd1: { // 0x6ccdd1: eb7d JMP 0x006cce50
    goto L006cce50;
  }
  L006ccdd3: { // 0x6ccdd3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ccdd5: { // 0x6ccdd5: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L006ccdd9: { // 0x6ccdd9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006ccdda: { // 0x6ccdda: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ccddc: { // 0x6ccddc: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x00000048u)),7130591u,op); flags=s.arithmetic_flags;
  }
  L006ccddf: { // 0x6ccddf: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006ccde1: { // 0x6ccde1: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006ccde3: { // 0x6ccde3: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L006ccde7: { // 0x6ccde7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ccde9: { // 0x6ccde9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ccdea: { // 0x6ccdea: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000048u)),7130605u,op); flags=s.arithmetic_flags;
  }
  L006ccded: { // 0x6ccded: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006ccdef: { // 0x6ccdef: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L006ccdf1: { // 0x6ccdf1: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006ccdf4: { // 0x6ccdf4: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L006ccdf7: { // 0x6ccdf7: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006ccdfa: { // 0x6ccdfa: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L006ccdfc: { // 0x6ccdfc: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006cce00: { // 0x6cce00: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L006cce03: { // 0x6cce03: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L006cce05: { // 0x6cce05: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006cce07: { // 0x6cce07: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L006cce0b: { // 0x6cce0b: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L006cce0f: { // 0x6cce0f: db442444 FILD dword ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cce13: { // 0x6cce13: db442448 FILD dword ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cce17: { // 0x6cce17: db442440 FILD dword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load_integer32(m.r32(address));
  }
  L006cce1b: { // 0x6cce1b: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L006cce1e: { // 0x6cce1e: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L006cce20: { // 0x6cce20: d8c9 FMUL st1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L006cce22: { // 0x6cce22: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L006cce24: { // 0x6cce24: d8cb FMUL st3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L006cce26: { // 0x6cce26: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006cce28: { // 0x6cce28: d9c3 FLD st3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L006cce2a: { // 0x6cce2a: d8cc FMUL st4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L006cce2c: { // 0x6cce2c: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006cce2e: { // 0x6cce2e: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006cce31: { // 0x6cce31: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006cce33: { // 0x6cce33: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006cce35: { // 0x6cce35: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006cce37: { // 0x6cce37: e844d2deff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x004ba080u,7130684u,op); flags=s.arithmetic_flags;
  }
  L006cce3c: { // 0x6cce3c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006cce3f: { // 0x6cce3f: e80cdc0900 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x0076aa50u,7130692u,op); flags=s.arithmetic_flags;
  }
  L006cce44: { // 0x6cce44: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006cce45: { // 0x6cce45: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006cce4b: { // 0x6cce4b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006cce4d: { // 0x6cce4d: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006cce50: { // 0x6cce50: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006cce54: { // 0x6cce54: b900000000 MOV ECX,0x0
    s.cx = 0x00000000u;
  }
  L006cce59: { // 0x6cce59: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L006cce5b: { // 0x6cce5b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cce5c: { // 0x6cce5c: 0f98c1 SETS CL
    s.cx = with_al(s.cx, (integer::condition("SETS",flags)?1u:0u));
  }
  L006cce5f: { // 0x6cce5f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006cce60: { // 0x6cce60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cce61: { // 0x6cce61: 23c8 AND ECX,EAX
    s.cx = integer::logical((s.cx)&(s.ax),32,flags);
  }
  L006cce63: { // 0x6cce63: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cce64: { // 0x6cce64: 894c2400 MOV dword ptr [ESP],ECX
    m.w32((f.sp), s.cx);
  }
  L006cce68: { // 0x6cce68: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_integer32(m.r32(address));
  }
  L006cce6c: { // 0x6cce6c: dc4c2444 FMUL double ptr [ESP + 0x44]
    const auto address=(f.sp+0x00000044u);
    s.fp.multiply64(read64(m,address));
  }
  L006cce70: { // 0x6cce70: dc442404 FADD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.add64(read64(m,address));
  }
  L006cce74: { // 0x6cce74: dc05e07e7900 FADD double ptr [0x00797ee0]
    const auto address=(0x00797ee0u);
    s.fp.add64(read64(m,address));
  }
  L006cce7a: { // 0x6cce7a: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L006cce7c: { // 0x6cce7c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006cce7d: { // 0x6cce7d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_001ccbd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ccbd0: { // 0x5ccbd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L005ccbd3: { // 0x5ccbd3: db416c FILD dword ptr [ECX + 0x6c]
    const auto address=(s.cx+0x0000006cu);
    s.fp.load_integer32(m.r32(address));
  }
  L005ccbd6: { // 0x5ccbd6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005ccbd8: { // 0x5ccbd8: dd5c2400 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005ccbdc: { // 0x5ccbdc: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x00000084u)),6081506u,op); flags=s.arithmetic_flags;
  }
  L005ccbe2: { // 0x5ccbe2: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
  L005ccbe8: { // 0x5ccbe8: dc7c2400 FDIVR double ptr [ESP]
    const auto address=(f.sp);
    reverse_divide64(s.fp,read64(m,address));
  }
  L005ccbec: { // 0x5ccbec: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005ccbef: { // 0x5ccbef: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000ba080(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ba080: { // 0x4ba080: dd442404 FLD double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load64(read64(m,address));
  }
  L004ba084: { // 0x4ba084: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba08a: { // 0x4ba08a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba08c: { // 0x4ba08c: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L004ba08f: { // 0x4ba08f: 7409 JZ 0x004ba09a
    if(integer::condition("JZ",flags)) goto L004ba09a;
  }
  L004ba091: { // 0x4ba091: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004ba093: { // 0x4ba093: d90538577800 FLD float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.load32(m.r32(address));
  }
  L004ba099: { // 0x4ba099: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004ba09a: { // 0x4ba09a: d81538577800 FCOM float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare32(m.r32(address));
  }
  L004ba0a0: { // 0x4ba0a0: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L004ba0a2: { // 0x4ba0a2: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L004ba0a5: { // 0x4ba0a5: 7406 JZ 0x004ba0ad
    if(integer::condition("JZ",flags)) goto L004ba0ad;
  }
  L004ba0a7: { // 0x4ba0a7: dc0d78857800 FMUL double ptr [0x00788578]
    const auto address=(0x00788578u);
    s.fp.multiply64(read64(m,address));
  }
  L004ba0ad: { // 0x4ba0ad: d95c2404 FSTP float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L004ba0b1: { // 0x4ba0b1: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L004ba0b5: { // 0x4ba0b5: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004ba0b7: { // 0x4ba0b7: 81e1ffff7f00 AND ECX,0x7fffff
    s.cx = integer::logical((s.cx)&(0x007fffffu),32,flags);
  }
  L004ba0bd: { // 0x4ba0bd: c1e817 SHR EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::right);
  }
  L004ba0c0: { // 0x4ba0c0: 83e87f SUB EAX,0x7f
    s.ax = integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004ba0c3: { // 0x4ba0c3: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L004ba0c5: { // 0x4ba0c5: 7406 JZ 0x004ba0cd
    if(integer::condition("JZ",flags)) goto L004ba0cd;
  }
  L004ba0c7: { // 0x4ba0c7: 81c900008000 OR ECX,0x800000
    s.cx = integer::logical((s.cx)|(0x00800000u),32,flags);
  }
  L004ba0cd: { // 0x4ba0cd: 66d1f8 SAR AX,0x1
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),0x00000001u,16,flags,integer::Shift::arithmetic_right));
  }
  L004ba0d0: { // 0x4ba0d0: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004ba0d3: { // 0x4ba0d3: c1e90a SHR ECX,0xa
    s.cx = integer::shift(s.cx,0x0000000au,32,flags,integer::Shift::right);
  }
  L004ba0d6: { // 0x4ba0d6: 83c07f ADD EAX,0x7f
    s.ax = integer::add(s.ax,0x0000007fu,32,flags);
  }
  L004ba0d9: { // 0x4ba0d9: 8b0c8d3c018000 MOV ECX,dword ptr [ECX*0x4 + 0x80013c]
    s.cx = m.r32(((s.cx * 0x00000004u)+0x0080013cu));
  }
  L004ba0e0: { // 0x4ba0e0: c1e017 SHL EAX,0x17
    s.ax = integer::shift(s.ax,0x00000017u,32,flags,integer::Shift::left);
  }
  L004ba0e3: { // 0x4ba0e3: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L004ba0e5: { // 0x4ba0e5: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L004ba0e9: { // 0x4ba0e9: d9442404 FLD float ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
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


void f_002b69d0(Memory&m,State&s,Frame&f,const Operations&op){
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b69d0: { // 0x6b69d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b69d1: { // 0x6b69d1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b69d2: { // 0x6b69d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b69d3: { // 0x6b69d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b69d4: { // 0x6b69d4: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L006b69d6: { // 0x6b69d6: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b69d8: { // 0x6b69d8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x00000080u)),7039454u,op); flags=s.arithmetic_flags;
  }
  L006b69de: { // 0x6b69de: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006b69e0: { // 0x6b69e0: e80be20100 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x006d4bf0u,7039461u,op); flags=s.arithmetic_flags;
  }
  L006b69e5: { // 0x6b69e5: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b69e7: { // 0x6b69e7: 7416 JZ 0x6b69ff
    if(integer::condition("JZ",flags)) goto L006b69ff;
  }
  L006b69e9: { // 0x6b69e9: 8bbf0c010000 MOV EDI, dword ptr [EDI + 0x10c]
    s.di = m.r32((s.di+0x0000010cu));
  }
  L006b69ef: { // 0x6b69ef: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L006b69f1: { // 0x6b69f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006b69f2: { // 0x6b69f2: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L006b69f4: { // 0x6b69f4: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L006b69f6: { // 0x6b69f6: 23c7 AND EAX, EDI
    s.ax = integer::logical((s.ax)&(s.di),32,flags);
  }
  L006b69f8: { // 0x6b69f8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b69f9: { // 0x6b69f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b69fa: { // 0x6b69fa: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b69fb: { // 0x6b69fb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b69fc: { // 0x6b69fc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b69ff: { // 0x6b69ff: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a01: { // 0x6b6a01: 6a01 PUSH 1
    f.push(m,1u);
  }
  L006b6a03: { // 0x6b6a03: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a05: { // 0x6b6a05: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x0000039cu)),7039499u,op); flags=s.arithmetic_flags;
  }
  L006b6a0b: { // 0x6b6a0b: 8b28 MOV EBP, dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  L006b6a0d: { // 0x6b6a0d: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006b6a0f: { // 0x6b6a0f: 0f84db010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6a15: { // 0x6b6a15: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6a17: { // 0x6b6a17: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006b6a19: { // 0x6b6a19: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a1b: { // 0x6b6a1b: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x0000039cu)),7039521u,op); flags=s.arithmetic_flags;
  }
  L006b6a21: { // 0x6b6a21: 8b18 MOV EBX, dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L006b6a23: { // 0x6b6a23: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006b6a25: { // 0x6b6a25: 0f84c5010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6a2b: { // 0x6b6a2b: 8a8512010000 MOV AL, byte ptr [EBP + 0x112]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000112u)));
  }
  L006b6a31: { // 0x6b6a31: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a33: { // 0x6b6a33: 0f85b7010000 JNZ 0x6b6bf0
    if(integer::condition("JNZ",flags)) goto L006b6bf0;
  }
  L006b6a39: { // 0x6b6a39: 8a8526010000 MOV AL, byte ptr [EBP + 0x126]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000126u)));
  }
  L006b6a3f: { // 0x6b6a3f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a41: { // 0x6b6a41: 741b JZ 0x6b6a5e
    if(integer::condition("JZ",flags)) goto L006b6a5e;
  }
  L006b6a43: { // 0x6b6a43: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a45: { // 0x6b6a45: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a47: { // 0x6b6a47: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x0000016cu)),7039565u,op); flags=s.arithmetic_flags;
  }
  L006b6a4d: { // 0x6b6a4d: 83f810 CMP EAX, 0x10
    (void)integer::sub(s.ax,0x00000010u,32,flags);
  }
  L006b6a50: { // 0x6b6a50: 750c JNZ 0x6b6a5e
    if(integer::condition("JNZ",flags)) goto L006b6a5e;
  }
  L006b6a52: { // 0x6b6a52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a53: { // 0x6b6a53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a54: { // 0x6b6a54: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6a55: { // 0x6b6a55: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6a5a: { // 0x6b6a5a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6a5b: { // 0x6b6a5b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6a5e: { // 0x6b6a5e: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6a60: { // 0x6b6a60: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a62: { // 0x6b6a62: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x0000002cu)),7039589u,op); flags=s.arithmetic_flags;
  }
  L006b6a65: { // 0x6b6a65: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6a68: { // 0x6b6a68: 7516 JNZ 0x6b6a80
    if(integer::condition("JNZ",flags)) goto L006b6a80;
  }
  L006b6a6a: { // 0x6b6a6a: 8a8731050000 MOV AL, byte ptr [EDI + 0x531]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000531u)));
  }
  L006b6a70: { // 0x6b6a70: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6a72: { // 0x6b6a72: 740c JZ 0x6b6a80
    if(integer::condition("JZ",flags)) goto L006b6a80;
  }
  L006b6a74: { // 0x6b6a74: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a75: { // 0x6b6a75: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a76: { // 0x6b6a76: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6a77: { // 0x6b6a77: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6a7c: { // 0x6b6a7c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6a7d: { // 0x6b6a7d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6a80: { // 0x6b6a80: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006b6a82: { // 0x6b6a82: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a84: { // 0x6b6a84: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x0000002cu)),7039623u,op); flags=s.arithmetic_flags;
  }
  L006b6a87: { // 0x6b6a87: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6a8a: { // 0x6b6a8a: 752c JNZ 0x6b6ab8
    if(integer::condition("JNZ",flags)) goto L006b6ab8;
  }
  L006b6a8c: { // 0x6b6a8c: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6a8e: { // 0x6b6a8e: e8cdc4d9ff CALL 0x452f60
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x00452f60u,7039635u,op); flags=s.arithmetic_flags;
  }
  L006b6a93: { // 0x6b6a93: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b6a95: { // 0x6b6a95: 7e21 JLE 0x6b6ab8
    if(integer::condition("JLE",flags)) goto L006b6ab8;
  }
  L006b6a97: { // 0x6b6a97: 8b8758050000 MOV EAX, dword ptr [EDI + 0x558]
    s.ax = m.r32((s.di+0x00000558u));
  }
  L006b6a9d: { // 0x6b6a9d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6a9e: { // 0x6b6a9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6a9f: { // 0x6b6a9f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6aa0: { // 0x6b6aa0: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b6aa2: { // 0x6b6aa2: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b6aa4: { // 0x6b6aa4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6aa5: { // 0x6b6aa5: 8b91b4010000 MOV EDX, dword ptr [ECX + 0x1b4]
    s.dx = m.r32((s.cx+0x000001b4u));
  }
  L006b6aab: { // 0x6b6aab: 83ba3001000001 CMP dword ptr [EDX + 0x130], 1
    (void)integer::sub(m.r32((s.dx+0x00000130u)),1u,32,flags);
  }
  L006b6ab2: { // 0x6b6ab2: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L006b6ab5: { // 0x6b6ab5: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6ab8: { // 0x6b6ab8: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L006b6abc: { // 0x6b6abc: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006b6abe: { // 0x6b6abe: 0f842c010000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6ac4: { // 0x6b6ac4: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6ac6: { // 0x6b6ac6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6ac8: { // 0x6b6ac8: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x0000002cu)),7039691u,op); flags=s.arithmetic_flags;
  }
  L006b6acb: { // 0x6b6acb: 83f806 CMP EAX, 6
    (void)integer::sub(s.ax,6u,32,flags);
  }
  L006b6ace: { // 0x6b6ace: 753c JNZ 0x6b6b0c
    if(integer::condition("JNZ",flags)) goto L006b6b0c;
  }
  L006b6ad0: { // 0x6b6ad0: 8b8fb4010000 MOV ECX, dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006b6ad6: { // 0x6b6ad6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6ad7: { // 0x6b6ad7: e8a4e1e2ff CALL 0x4e4c80
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x004e4c80u,7039708u,op); flags=s.arithmetic_flags;
  }
  L006b6adc: { // 0x6b6adc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6ade: { // 0x6b6ade: 742c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6ae0: { // 0x6b6ae0: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006b6ae6: { // 0x6b6ae6: 8a8155010000 MOV AL, byte ptr [ECX + 0x155]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000155u)));
  }
  L006b6aec: { // 0x6b6aec: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6aee: { // 0x6b6aee: 741c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6af0: { // 0x6b6af0: 8b9618040000 MOV EDX, dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L006b6af6: { // 0x6b6af6: 8a8218120000 MOV AL, byte ptr [EDX + 0x1218]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001218u)));
  }
  L006b6afc: { // 0x6b6afc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6afe: { // 0x6b6afe: 740c JZ 0x6b6b0c
    if(integer::condition("JZ",flags)) goto L006b6b0c;
  }
  L006b6b00: { // 0x6b6b00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b01: { // 0x6b6b01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b02: { // 0x6b6b02: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b03: { // 0x6b6b03: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b08: { // 0x6b6b08: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b09: { // 0x6b6b09: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6b0c: { // 0x6b6b0c: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6b0e: { // 0x6b6b0e: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6b10: { // 0x6b6b10: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x0000002cu)),7039763u,op); flags=s.arithmetic_flags;
  }
  L006b6b13: { // 0x6b6b13: 83f802 CMP EAX, 2
    (void)integer::sub(s.ax,2u,32,flags);
  }
  L006b6b16: { // 0x6b6b16: 7516 JNZ 0x6b6b2e
    if(integer::condition("JNZ",flags)) goto L006b6b2e;
  }
  L006b6b18: { // 0x6b6b18: 8a87b2050000 MOV AL, byte ptr [EDI + 0x5b2]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005b2u)));
  }
  L006b6b1e: { // 0x6b6b1e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6b20: { // 0x6b6b20: 740c JZ 0x6b6b2e
    if(integer::condition("JZ",flags)) goto L006b6b2e;
  }
  L006b6b22: { // 0x6b6b22: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b23: { // 0x6b6b23: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b24: { // 0x6b6b24: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b25: { // 0x6b6b25: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b2a: { // 0x6b6b2a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b2b: { // 0x6b6b2b: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6b2e: { // 0x6b6b2e: f6461401 TEST byte ptr [ESI + 0x14], 1
    (void)integer::logical((m.r8((s.si+0x00000014u)))&(1u),8,flags);
  }
  L006b6b32: { // 0x6b6b32: 0f84b8000000 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6b38: { // 0x6b6b38: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b3a: { // 0x6b6b3a: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6b3c: { // 0x6b6b3c: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000080u)),7039810u,op); flags=s.arithmetic_flags;
  }
  L006b6b42: { // 0x6b6b42: 8b809c000000 MOV EAX, dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006b6b48: { // 0x6b6b48: 8b8dac000000 MOV ECX, dword ptr [EBP + 0xac]
    s.cx = m.r32((s.bp+0x000000acu));
  }
  L006b6b4e: { // 0x6b6b4e: dd84c1a0000000 FLD qword ptr [ECX + EAX*8 + 0xa0]
    const auto address=(s.cx+(s.ax * 8u)+0x000000a0u);
    s.fp.load64(read64(m,address));
  }
  L006b6b55: { // 0x6b6b55: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006b6b5b: { // 0x6b6b5b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006b6b5d: { // 0x6b6b5d: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L006b6b60: { // 0x6b6b60: 0f858a000000 JNZ 0x6b6bf0
    if(integer::condition("JNZ",flags)) goto L006b6bf0;
  }
  L006b6b66: { // 0x6b6b66: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b68: { // 0x6b6b68: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6b6a: { // 0x6b6b6a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000080u)),7039856u,op); flags=s.arithmetic_flags;
  }
  L006b6b70: { // 0x6b6b70: 8b809c000000 MOV EAX, dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006b6b76: { // 0x6b6b76: 8b8bac000000 MOV ECX, dword ptr [EBX + 0xac]
    s.cx = m.r32((s.bx+0x000000acu));
  }
  L006b6b7c: { // 0x6b6b7c: dd84c1a0000000 FLD qword ptr [ECX + EAX*8 + 0xa0]
    const auto address=(s.cx+(s.ax * 8u)+0x000000a0u);
    s.fp.load64(read64(m,address));
  }
  L006b6b83: { // 0x6b6b83: dc1d10667800 FCOMP qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006b6b89: { // 0x6b6b89: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006b6b8b: { // 0x6b6b8b: f6c440 TEST AH, 0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L006b6b8e: { // 0x6b6b8e: 740c JZ 0x6b6b9c
    if(integer::condition("JZ",flags)) goto L006b6b9c;
  }
  L006b6b90: { // 0x6b6b90: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6b91: { // 0x6b6b91: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6b92: { // 0x6b6b92: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6b93: { // 0x6b6b93: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6b98: { // 0x6b6b98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6b99: { // 0x6b6b99: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6b9c: { // 0x6b6b9c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6b9e: { // 0x6b6b9e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6ba0: { // 0x6b6ba0: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x000001a4u)),7039910u,op); flags=s.arithmetic_flags;
  }
  L006b6ba6: { // 0x6b6ba6: 83b8ec00000002 CMP dword ptr [EAX + 0xec], 2
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),2u,32,flags);
  }
  L006b6bad: { // 0x6b6bad: 7417 JZ 0x6b6bc6
    if(integer::condition("JZ",flags)) goto L006b6bc6;
  }
  L006b6baf: { // 0x6b6baf: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b6bb1: { // 0x6b6bb1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6bb3: { // 0x6b6bb3: ff90a4010000 CALL dword ptr [EAX + 0x1a4]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x000001a4u)),7039929u,op); flags=s.arithmetic_flags;
  }
  L006b6bb9: { // 0x6b6bb9: 83b8ec00000006 CMP dword ptr [EAX + 0xec], 6
    (void)integer::sub(m.r32((s.ax+0x000000ecu)),6u,32,flags);
  }
  L006b6bc0: { // 0x6b6bc0: 7404 JZ 0x6b6bc6
    if(integer::condition("JZ",flags)) goto L006b6bc6;
  }
  L006b6bc2: { // 0x6b6bc2: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006b6bc4: { // 0x6b6bc4: eb02 JMP 0x6b6bc8
    goto L006b6bc8;
  }
  L006b6bc6: { // 0x6b6bc6: b301 MOV BL, 1
    s.bx = with_al(s.bx, 1u);
  }
  L006b6bc8: { // 0x6b6bc8: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6bca: { // 0x6b6bca: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6bcc: { // 0x6b6bcc: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000054u)),7039951u,op); flags=s.arithmetic_flags;
  }
  L006b6bcf: { // 0x6b6bcf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6bd1: { // 0x6b6bd1: 7402 JZ 0x6b6bd5
    if(integer::condition("JZ",flags)) goto L006b6bd5;
  }
  L006b6bd3: { // 0x6b6bd3: 32db XOR BL, BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006b6bd5: { // 0x6b6bd5: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L006b6bd8: { // 0x6b6bd8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6bda: { // 0x6b6bda: 751d JNZ 0x6b6bf9
    if(integer::condition("JNZ",flags)) goto L006b6bf9;
  }
  L006b6bdc: { // 0x6b6bdc: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006b6bde: { // 0x6b6bde: 7419 JZ 0x6b6bf9
    if(integer::condition("JZ",flags)) goto L006b6bf9;
  }
  L006b6be0: { // 0x6b6be0: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006b6be2: { // 0x6b6be2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b6be3: { // 0x6b6be3: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006b6be5: { // 0x6b6be5: ff90bc020000 CALL dword ptr [EAX + 0x2bc]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.ax+0x000002bcu)),7039979u,op); flags=s.arithmetic_flags;
  }
  L006b6beb: { // 0x6b6beb: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L006b6bee: { // 0x6b6bee: 7502 JNZ 0x6b6bf2
    if(integer::condition("JNZ",flags)) goto L006b6bf2;
  }
  L006b6bf0: { // 0x6b6bf0: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b6bf2: { // 0x6b6bf2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6bf3: { // 0x6b6bf3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6bf4: { // 0x6b6bf4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6bf5: { // 0x6b6bf5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6bf6: { // 0x6b6bf6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006b6bf9: { // 0x6b6bf9: 8b8da0000000 MOV ECX, dword ptr [EBP + 0xa0]
    s.cx = m.r32((s.bp+0x000000a0u));
  }
  L006b6bff: { // 0x6b6bff: 8a8174020000 MOV AL, byte ptr [ECX + 0x274]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000274u)));
  }
  L006b6c05: { // 0x6b6c05: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6c07: { // 0x6b6c07: 74e7 JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6c09: { // 0x6b6c09: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b6c0b: { // 0x6b6c0b: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006b6c0d: { // 0x6b6c0d: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,m.r32((s.dx+0x00000054u)),7040016u,op); flags=s.arithmetic_flags;
  }
  L006b6c10: { // 0x6b6c10: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b6c12: { // 0x6b6c12: 74dc JZ 0x6b6bf0
    if(integer::condition("JZ",flags)) goto L006b6bf0;
  }
  L006b6c14: { // 0x6b6c14: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b6c15: { // 0x6b6c15: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b6c16: { // 0x6b6c16: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b6c17: { // 0x6b6c17: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006b6c1c: { // 0x6b6c1c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b6c1d: { // 0x6b6c1d: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("705 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}

void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002d4bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4bf0: { // 0x6d4bf0: 8b9104070000 MOV EDX, dword ptr [ECX + 0x704]
    s.dx = m.r32((s.cx+0x00000704u));
  }
  L006d4bf6: { // 0x6d4bf6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d4bf8: { // 0x6d4bf8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d4bfa: { // 0x6d4bfa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006d4bfd: { // 0x6d4bfd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0004d670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d670: { // 0x44d670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d671: { // 0x44d671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d672: { // 0x44d672: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d673: { // 0x44d673: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044d677: { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d678: { // 0x44d678: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044d67a: { // 0x44d67a: 8a87c6050000 MOV AL, byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0044d680: { // 0x44d680: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d682: { // 0x44d682: 742c JZ 0x44d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  L0044d684: { // 0x44d684: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d686: { // 0x44d686: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d688: { // 0x44d688: 7e26 JLE 0x44d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  L0044d68a: { // 0x44d68a: 8db7c0040000 LEA ESI, [EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0044d692: { // 0x44d692: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d694: { // 0x44d694: 740b JZ 0x44d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  L0044d696: { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d697: { // 0x44d697: e894742800 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x006d4b30u,4511388u,op); flags=s.arithmetic_flags;
  }
  L0044d69c: { // 0x44d69c: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L0044d69f: { // 0x44d69f: 7517 JNZ 0x44d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX, byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0044d6a8: { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d6a9: { // 0x44d6a9: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L0044d6ac: { // 0x44d6ac: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d6ae: { // 0x44d6ae: 7ce0 JL 0x44d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d6b1: { // 0x44d6b1: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d6b3: { // 0x44d6b3: e8f8032800 CALL 0x6cdab0
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x006cdab0u,4511416u,op); flags=s.arithmetic_flags;
  }
  L0044d6b8: { // 0x44d6b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d6b9: { // 0x44d6b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d6ba: { // 0x44d6ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d6bb: { // 0x44d6bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d6bc: { // 0x44d6bc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX, [ECX + EDX*4 + 0x74c]
    s.ax = (s.cx+(s.dx * 4u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00043e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00443e10: { // 0x443e10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00443e11: { // 0x443e11: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00443e12: { // 0x443e12: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00443e14: { // 0x443e14: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00443e16: { // 0x443e16: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e1c: { // 0x443e1c: e89f470100 CALL 0x4585c0
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x004585c0u,4472353u,op); flags=s.arithmetic_flags;
  }
  L00443e21: { // 0x443e21: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e27: { // 0x443e27: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00443e29: { // 0x443e29: c1e607 SHL ESI, 7
    s.si = integer::shift(s.si,7u,32,flags,integer::Shift::left);
  }
  L00443e2c: { // 0x443e2c: 81ee80000000 SUB ESI, 0x80
    s.si = integer::sub(s.si,0x00000080u,32,flags);
  }
  L00443e32: { // 0x443e32: e879470100 CALL 0x4585b0
    s.arithmetic_flags=flags; invoke_candidate(m,s,f,0x004585b0u,4472375u,op); flags=s.arithmetic_flags;
  }
  L00443e37: { // 0x443e37: 81c788000000 ADD EDI, 0x88
    s.di = integer::add(s.di,0x00000088u,32,flags);
  }
  L00443e3d: { // 0x443e3d: c1e007 SHL EAX, 7
    s.ax = integer::shift(s.ax,7u,32,flags,integer::Shift::left);
  }
  L00443e40: { // 0x443e40: 8b0f MOV ECX, dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00443e42: { // 0x443e42: 2d80000000 SUB EAX, 0x80
    s.ax = integer::sub(s.ax,0x00000080u,32,flags);
  }
  L00443e47: { // 0x443e47: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00443e49: { // 0x443e49: 8b44240c MOV EAX, dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00443e4d: { // 0x443e4d: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L00443e50: { // 0x443e50: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00443e52: { // 0x443e52: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00443e54: { // 0x443e54: 8b7f08 MOV EDI, dword ptr [EDI + 8]
    s.di = m.r32((s.di+8u));
  }
  L00443e57: { // 0x443e57: 890e MOV dword ptr [ESI], ECX
    m.w32((s.si), s.cx);
  }
  L00443e59: { // 0x443e59: 895604 MOV dword ptr [ESI + 4], EDX
    m.w32((s.si+4u), s.dx);
  }
  L00443e5c: { // 0x443e5c: 897e08 MOV dword ptr [ESI + 8], EDI
    m.w32((s.si+8u), s.di);
  }
  L00443e5f: { // 0x443e5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00443e60: { // 0x443e60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00443e61: { // 0x443e61: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000585b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585b0: { // 0x4585b0: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585b6: { // 0x4585b6: 8b048508ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac08]
    s.ax = m.r32(((s.ax * 4u)+0x007bac08u));
  }
  L004585bd: { // 0x4585bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_000585c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585c0: { // 0x4585c0: 8a442404 MOV AL, byte ptr [ESP + 4]
    s.ax = with_al(s.ax, m.r8((f.sp+4u)));
  }
  L004585c4: { // 0x4585c4: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585c6: { // 0x4585c6: 7421 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585c8: { // 0x4585c8: 8a8114120000 MOV AL, byte ptr [ECX + 0x1214]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001214u)));
  }
  L004585ce: { // 0x4585ce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585d0: { // 0x4585d0: 7417 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585d2: { // 0x4585d2: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585d8: { // 0x4585d8: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004585dd: { // 0x4585dd: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585e4: { // 0x4585e4: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585e6: { // 0x4585e6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004585e9: { // 0x4585e9: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585ef: { // 0x4585ef: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004585f1: { // 0x4585f1: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585f8: { // 0x4585f8: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585fa: { // 0x4585fa: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
