void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_001e6200(Memory&,State&,Frame&,const Operations&);
void f_001f5e90(Memory&,State&,Frame&,const Operations&);
void f_001f5800(Memory&,State&,Frame&,const Operations&);
void f_001f6690(Memory&,State&,Frame&,const Operations&);
void f_0035fcd0(Memory&,State&,Frame&,const Operations&);
void f_0035fd00(Memory&,State&,Frame&,const Operations&);
void f_00234310(Memory&,State&,Frame&,const Operations&);
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
void f_00031790(Memory&,State&,Frame&,const Operations&);
void f_000317a0(Memory&,State&,Frame&,const Operations&);
void f_00031b80(Memory&,State&,Frame&,const Operations&);
void f_00031ec0(Memory&,State&,Frame&,const Operations&);
void f_00031f70(Memory&,State&,Frame&,const Operations&);
void f_00032010(Memory&,State&,Frame&,const Operations&);
void f_00032210(Memory&,State&,Frame&,const Operations&);
void f_00035420(Memory&,State&,Frame&,const Operations&);
void f_00053ab0(Memory&,State&,Frame&,const Operations&);
void f_0035f290(Memory&,State&,Frame&,const Operations&);
void f_0035f2c0(Memory&,State&,Frame&,const Operations&);
void f_00360f60(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0036ef45(Memory&,State&,Frame&,const Operations&);

void f_001e6200(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005e6200: { // 0x5e6200: a164b4a500 MOV EAX,[0x00a5b464]
    s.ax = m.r32((0x00a5b464u));
  }
  L005e6205: { // 0x5e6205: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L005e6208: { // 0x5e6208: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005e6209: { // 0x5e6209: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005e620b: { // 0x5e620b: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005e620d: { // 0x5e620d: 7507 JNZ 0x005e6216
    if(integer::condition("JNZ",flags)) goto L005e6216;
  }
  L005e620f: { // 0x5e620f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005e6211: { // 0x5e6211: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005e6212: { // 0x5e6212: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L005e6215: { // 0x5e6215: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005e6216: { // 0x5e6216: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005e6217: { // 0x5e6217: 3acb CMP CL,BL
    (void)integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L005e6219: { // 0x5e6219: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005e621a: { // 0x5e621a: 0f849b000000 JZ 0x005e62bb
    if(integer::condition("JZ",flags)) goto L005e62bb;
  }
  L005e6220: { // 0x5e6220: 8b0d60b3a500 MOV ECX,dword ptr [0x00a5b360]
    s.cx = m.r32((0x00a5b360u));
  }
  L005e6226: { // 0x5e6226: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005e6228: { // 0x5e6228: 7406 JZ 0x005e6230
    if(integer::condition("JZ",flags)) goto L005e6230;
  }
  L005e622a: { // 0x5e622a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005e622c: { // 0x5e622c: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005e622e: { // 0x5e622e: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),6185520u,op); flags=s.arithmetic_flags;
  }
  L005e6230: { // 0x5e6230: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  L005e6232: { // 0x5e6232: 891d60b3a500 MOV dword ptr [0x00a5b360],EBX
    m.w32((0x00a5b360u), s.bx);
  }
  L005e6238: { // 0x5e6238: e81a771800 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,6185533u,op); flags=s.arithmetic_flags;
  }
  L005e623d: { // 0x5e623d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005e623f: { // 0x5e623f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005e6242: { // 0x5e6242: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005e6244: { // 0x5e6244: 743a JZ 0x005e6280
    if(integer::condition("JZ",flags)) goto L005e6280;
  }
  L005e6246: { // 0x5e6246: a158b3a500 MOV EAX,[0x00a5b358]
    s.ax = m.r32((0x00a5b358u));
  }
  L005e624b: { // 0x5e624b: 8b0d5cb3a500 MOV ECX,dword ptr [0x00a5b35c]
    s.cx = m.r32((0x00a5b35cu));
  }
  L005e6251: { // 0x5e6251: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L005e6254: { // 0x5e6254: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L005e6257: { // 0x5e6257: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L005e6259: { // 0x5e6259: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L005e625c: { // 0x5e625c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005e625d: { // 0x5e625d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005e625e: { // 0x5e625e: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  L005e6261: { // 0x5e6261: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  L005e6264: { // 0x5e6264: c7068c5f7800 MOV dword ptr [ESI],0x785f8c
    m.w32((s.si), 0x00785f8cu);
  }
  L005e626a: { // 0x5e626a: c7461002000000 MOV dword ptr [ESI + 0x10],0x2
    m.w32((s.si+0x00000010u), 0x00000002u);
  }
  L005e6271: { // 0x5e6271: e8ca1ee5ff CALL 0x00438140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,6185590u,op); flags=s.arithmetic_flags;
  }
  L005e6276: { // 0x5e6276: c706f85e7800 MOV dword ptr [ESI],0x785ef8
    m.w32((s.si), 0x00785ef8u);
  }
  L005e627c: { // 0x5e627c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005e627e: { // 0x5e627e: eb02 JMP 0x005e6282
    goto L005e6282;
  }
  L005e6280: { // 0x5e6280: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005e6282: { // 0x5e6282: a15cb3a500 MOV EAX,[0x00a5b35c]
    s.ax = m.r32((0x00a5b35cu));
  }
  L005e6287: { // 0x5e6287: 8b1558b3a500 MOV EDX,dword ptr [0x00a5b358]
    s.dx = m.r32((0x00a5b358u));
  }
  L005e628d: { // 0x5e628d: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005e6291: { // 0x5e6291: a1901c8200 MOV EAX,[0x00821c90]
    s.ax = m.r32((0x00821c90u));
  }
  L005e6296: { // 0x5e6296: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005e6298: { // 0x5e6298: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005e6299: { // 0x5e6299: 6850b3a500 PUSH 0xa5b350
    f.push(m,0x00a5b350u);
  }
  L005e629e: { // 0x5e629e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005e629f: { // 0x5e629f: 890d60b3a500 MOV dword ptr [0x00a5b360],ECX
    m.w32((0x00a5b360u), s.cx);
  }
  L005e62a5: { // 0x5e62a5: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L005e62a9: { // 0x5e62a9: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L005e62ad: { // 0x5e62ad: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L005e62b1: { // 0x5e62b1: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005e62b3: { // 0x5e62b3: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L005e62b7: { // 0x5e62b7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005e62b8: { // 0x5e62b8: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6185659u,op); flags=s.arithmetic_flags;
  }
  L005e62bb: { // 0x5e62bb: a158b3a500 MOV EAX,[0x00a5b358]
    s.ax = m.r32((0x00a5b358u));
  }
  L005e62c0: { // 0x5e62c0: 8b0d50b3a500 MOV ECX,dword ptr [0x00a5b350]
    s.cx = m.r32((0x00a5b350u));
  }
  L005e62c6: { // 0x5e62c6: 8b1554b3a500 MOV EDX,dword ptr [0x00a5b354]
    s.dx = m.r32((0x00a5b354u));
  }
  L005e62cc: { // 0x5e62cc: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005e62d0: { // 0x5e62d0: a128dfa500 MOV EAX,[0x00a5df28]
    s.ax = m.r32((0x00a5df28u));
  }
  L005e62d5: { // 0x5e62d5: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L005e62d9: { // 0x5e62d9: 8b0d5cb3a500 MOV ECX,dword ptr [0x00a5b35c]
    s.cx = m.r32((0x00a5b35cu));
  }
  L005e62df: { // 0x5e62df: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005e62e2: { // 0x5e62e2: 891d68b4a500 MOV dword ptr [0x00a5b468],EBX
    m.w32((0x00a5b468u), s.bx);
  }
  L005e62e8: { // 0x5e62e8: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005e62ec: { // 0x5e62ec: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L005e62f0: { // 0x5e62f0: 7504 JNZ 0x005e62f6
    if(integer::condition("JNZ",flags)) goto L005e62f6;
  }
  L005e62f2: { // 0x5e62f2: 0bf0 OR ESI,EAX
    s.si = integer::logical((s.si)|(s.ax),32,flags);
  }
  L005e62f4: { // 0x5e62f4: eb49 JMP 0x005e633f
    goto L005e633f;
  }
  L005e62f6: { // 0x5e62f6: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L005e62fc: { // 0x5e62fc: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005e62fe: { // 0x5e62fe: 8a152adfa500 MOV DL,byte ptr [0x00a5df2a]
    s.dx = with_al(s.dx, m.r8((0x00a5df2au)));
  }
  L005e6304: { // 0x5e6304: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005e6306: { // 0x5e6306: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005e6308: { // 0x5e6308: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L005e630e: { // 0x5e630e: 8adc MOV BL,AH
    s.bx = with_al(s.bx, ((s.ax >> 8) & 0xffu));
  }
  L005e6310: { // 0x5e6310: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L005e6315: { // 0x5e6315: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e6317: { // 0x5e6317: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L005e631d: { // 0x5e631d: d3eb SHR EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005e631f: { // 0x5e631f: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L005e6325: { // 0x5e6325: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e6327: { // 0x5e6327: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L005e632d: { // 0x5e632d: d3f8 SAR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L005e632f: { // 0x5e632f: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L005e6335: { // 0x5e6335: 0bd3 OR EDX,EBX
    s.dx = integer::logical((s.dx)|(s.bx),32,flags);
  }
  L005e6337: { // 0x5e6337: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e6339: { // 0x5e6339: 0bd0 OR EDX,EAX
    s.dx = integer::logical((s.dx)|(s.ax),32,flags);
  }
  L005e633b: { // 0x5e633b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005e633d: { // 0x5e633d: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L005e633f: { // 0x5e633f: 8b0d901c8200 MOV ECX,dword ptr [0x00821c90]
    s.cx = m.r32((0x00821c90u));
  }
  L005e6345: { // 0x5e6345: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005e6347: { // 0x5e6347: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005e6349: { // 0x5e6349: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005e634a: { // 0x5e634a: 8b29 MOV EBP,dword ptr [ECX]
    s.bp = m.r32((s.cx));
  }
  L005e634c: { // 0x5e634c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005e634d: { // 0x5e634d: ff555c CALL dword ptr [EBP + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bp+0x0000005cu)),6185808u,op); flags=s.arithmetic_flags;
  }
  L005e6350: { // 0x5e6350: 8b0d901c8200 MOV ECX,dword ptr [0x00821c90]
    s.cx = m.r32((0x00821c90u));
  }
  L005e6356: { // 0x5e6356: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L005e635a: { // 0x5e635a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005e635b: { // 0x5e635b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005e635c: { // 0x5e635c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005e635e: { // 0x5e635e: ff5014 CALL dword ptr [EAX + 0x14]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000014u)),6185825u,op); flags=s.arithmetic_flags;
  }
  L005e6361: { // 0x5e6361: 8b0d901c8200 MOV ECX,dword ptr [0x00821c90]
    s.cx = m.r32((0x00821c90u));
  }
  L005e6367: { // 0x5e6367: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005e6369: { // 0x5e6369: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),6185836u,op); flags=s.arithmetic_flags;
  }
  L005e636c: { // 0x5e636c: 8b15901c8200 MOV EDX,dword ptr [0x00821c90]
    s.dx = m.r32((0x00821c90u));
  }
  L005e6372: { // 0x5e6372: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L005e6376: { // 0x5e6376: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  L005e6378: { // 0x5e6378: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L005e637a: { // 0x5e637a: e811030100 CALL 0x005f6690
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f6690u,6185855u,op); flags=s.arithmetic_flags;
  }
  L005e637f: { // 0x5e637f: 8b0d901c8200 MOV ECX,dword ptr [0x00821c90]
    s.cx = m.r32((0x00821c90u));
  }
  L005e6385: { // 0x5e6385: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005e6386: { // 0x5e6386: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005e6387: { // 0x5e6387: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005e6389: { // 0x5e6389: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005e638b: { // 0x5e638b: 6864b3a500 PUSH 0xa5b364
    f.push(m,0x00a5b364u);
  }
  L005e6390: { // 0x5e6390: e8b08b1800 CALL 0x0076ef45
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076ef45u,6185877u,op); flags=s.arithmetic_flags;
  }
  L005e6395: { // 0x5e6395: 8b0d44afa500 MOV ECX,dword ptr [0x00a5af44]
    s.cx = m.r32((0x00a5af44u));
  }
  L005e639b: { // 0x5e639b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005e639e: { // 0x5e639e: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L005e63a2: { // 0x5e63a2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005e63a3: { // 0x5e63a3: 6864b3a500 PUSH 0xa5b364
    f.push(m,0x00a5b364u);
  }
  L005e63a8: { // 0x5e63a8: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005e63a9: { // 0x5e63a9: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005e63ab: { // 0x5e63ab: e8e0fa0000 CALL 0x005f5e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f5e90u,6185904u,op); flags=s.arithmetic_flags;
  }
  L005e63b0: { // 0x5e63b0: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L005e63b4: { // 0x5e63b4: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L005e63b8: { // 0x5e63b8: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005e63bc: { // 0x5e63bc: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L005e63c0: { // 0x5e63c0: 8b0d901c8200 MOV ECX,dword ptr [0x00821c90]
    s.cx = m.r32((0x00821c90u));
  }
  L005e63c6: { // 0x5e63c6: 83ea02 SUB EDX,0x2
    s.dx = integer::sub(s.dx,0x00000002u,32,flags);
  }
  L005e63c9: { // 0x5e63c9: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L005e63ca: { // 0x5e63ca: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005e63cb: { // 0x5e63cb: 83ee02 SUB ESI,0x2
    s.si = integer::sub(s.si,0x00000002u,32,flags);
  }
  L005e63ce: { // 0x5e63ce: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005e63d2: { // 0x5e63d2: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L005e63d4: { // 0x5e63d4: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L005e63d6: { // 0x5e63d6: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L005e63da: { // 0x5e63da: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L005e63de: { // 0x5e63de: 895c2418 MOV dword ptr [ESP + 0x18],EBX
    m.w32((f.sp+0x00000018u), s.bx);
  }
  L005e63e2: { // 0x5e63e2: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L005e63e6: { // 0x5e63e6: e815f40000 CALL 0x005f5800
    s.arithmetic_flags=flags; invoke(m,s,f,0x005f5800u,6185963u,op); flags=s.arithmetic_flags;
  }
  L005e63eb: { // 0x5e63eb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005e63ed: { // 0x5e63ed: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e63ee: { // 0x5e63ee: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005e63ef: { // 0x5e63ef: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005e63f0: { // 0x5e63f0: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L005e63f3: { // 0x5e63f3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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

void f_001f5800(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005f5800: { // 0x5f5800: 83ec58 SUB ESP,0x58
    f.sp = integer::sub(f.sp,0x00000058u,32,flags);
  }
  L005f5803: { // 0x5f5803: 8b442460 MOV EAX,dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L005f5807: { // 0x5f5807: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f5808: { // 0x5f5808: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f5809: { // 0x5f5809: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f580a: { // 0x5f580a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005f580c: { // 0x5f580c: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L005f580f: { // 0x5f580f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f5810: { // 0x5f5810: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005f5812: { // 0x5f5812: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L005f5814: { // 0x5f5814: 7558 JNZ 0x005f586e
    if(integer::condition("JNZ",flags)) goto L005f586e;
  }
  L005f5816: { // 0x5f5816: a1acdca500 MOV EAX,[0x00a5dcac]
    s.ax = m.r32((0x00a5dcacu));
  }
  L005f581b: { // 0x5f581b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005f581d: { // 0x5f581d: 7506 JNZ 0x005f5825
    if(integer::condition("JNZ",flags)) goto L005f5825;
  }
  L005f581f: { // 0x5f581f: 894c2470 MOV dword ptr [ESP + 0x70],ECX
    m.w32((f.sp+0x00000070u), s.cx);
  }
  L005f5823: { // 0x5f5823: eb49 JMP 0x005f586e
    goto L005f586e;
  }
  L005f5825: { // 0x5f5825: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  L005f582b: { // 0x5f582b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005f582d: { // 0x5f582d: 8a15aedca500 MOV DL,byte ptr [0x00a5dcae]
    s.dx = with_al(s.dx, m.r8((0x00a5dcaeu)));
  }
  L005f5833: { // 0x5f5833: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005f5835: { // 0x5f5835: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005f5837: { // 0x5f5837: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  L005f583d: { // 0x5f583d: 8adc MOV BL,AH
    s.bx = with_al(s.bx, ((s.ax >> 8) & 0xffu));
  }
  L005f583f: { // 0x5f583f: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L005f5844: { // 0x5f5844: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005f5846: { // 0x5f5846: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  L005f584c: { // 0x5f584c: d3eb SHR EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  L005f584e: { // 0x5f584e: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  L005f5854: { // 0x5f5854: d3e3 SHL EBX,CL
    s.bx = integer::shift(s.bx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005f5856: { // 0x5f5856: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  L005f585c: { // 0x5f585c: d3f8 SAR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::arithmetic_right);
  }
  L005f585e: { // 0x5f585e: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  L005f5864: { // 0x5f5864: 0bd3 OR EDX,EBX
    s.dx = integer::logical((s.dx)|(s.bx),32,flags);
  }
  L005f5866: { // 0x5f5866: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005f5868: { // 0x5f5868: 0bd0 OR EDX,EAX
    s.dx = integer::logical((s.dx)|(s.ax),32,flags);
  }
  L005f586a: { // 0x5f586a: 89542470 MOV dword ptr [ESP + 0x70],EDX
    m.w32((f.sp+0x00000070u), s.dx);
  }
  L005f586e: { // 0x5f586e: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L005f5872: { // 0x5f5872: 8b7d00 MOV EDI,dword ptr [EBP]
    s.di = m.r32((s.bp));
  }
  L005f5875: { // 0x5f5875: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L005f5878: { // 0x5f5878: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L005f587b: { // 0x5f587b: 8b6d0c MOV EBP,dword ptr [EBP + 0xc]
    s.bp = m.r32((s.bp+0x0000000cu));
  }
  L005f587e: { // 0x5f587e: 8d1409 LEA EDX,[ECX + ECX*0x1]
    s.dx = (s.cx+(s.cx * 0x00000001u));
  }
  L005f5881: { // 0x5f5881: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L005f5883: { // 0x5f5883: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L005f5885: { // 0x5f5885: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L005f5887: { // 0x5f5887: 03ea ADD EBP,EDX
    s.bp = integer::add(s.bp,s.dx,32,flags);
  }
  L005f5889: { // 0x5f5889: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005f588b: { // 0x5f588b: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L005f588f: { // 0x5f588f: 896c2464 MOV dword ptr [ESP + 0x64],EBP
    m.w32((f.sp+0x00000064u), s.bp);
  }
  L005f5893: { // 0x5f5893: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L005f589b: { // 0x5f589b: 0f8ee3000000 JLE 0x005f5984
    if(integer::condition("JLE",flags)) goto L005f5984;
  }
  L005f58a1: { // 0x5f58a1: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L005f58a5: { // 0x5f58a5: 8d6c3bff LEA EBP,[EBX + EDI*0x1 + -0x1]
    s.bp = (s.bx+(s.di * 0x00000001u)-0x00000001u);
  }
  L005f58a9: { // 0x5f58a9: 8d5c01ff LEA EBX,[ECX + EAX*0x1 + -0x1]
    s.bx = (s.cx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L005f58ad: { // 0x5f58ad: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L005f58af: { // 0x5f58af: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L005f58b3: { // 0x5f58b3: eb04 JMP 0x005f58b9
    goto L005f58b9;
  }
  L005f58b5: { // 0x5f58b5: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L005f58b9: { // 0x5f58b9: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L005f58bd: { // 0x5f58bd: 8d55ff LEA EDX,[EBP + -0x1]
    s.dx = (s.bp-0x00000001u);
  }
  L005f58c0: { // 0x5f58c0: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L005f58c4: { // 0x5f58c4: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L005f58c6: { // 0x5f58c6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f58c7: { // 0x5f58c7: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L005f58cb: { // 0x5f58cb: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L005f58cf: { // 0x5f58cf: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L005f58d3: { // 0x5f58d3: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L005f58d7: { // 0x5f58d7: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005f58d9: { // 0x5f58d9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f58da: { // 0x5f58da: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f58db: { // 0x5f58db: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005f58dd: { // 0x5f58dd: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L005f58e1: { // 0x5f58e1: ff5030 CALL dword ptr [EAX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000030u)),6248676u,op); flags=s.arithmetic_flags;
  }
  L005f58e4: { // 0x5f58e4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f58e6: { // 0x5f58e6: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L005f58ea: { // 0x5f58ea: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L005f58ee: { // 0x5f58ee: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L005f58f2: { // 0x5f58f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f58f3: { // 0x5f58f3: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L005f58f7: { // 0x5f58f7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f58f8: { // 0x5f58f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f58f9: { // 0x5f58f9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005f58fb: { // 0x5f58fb: 895c2438 MOV dword ptr [ESP + 0x38],EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L005f58ff: { // 0x5f58ff: 897c243c MOV dword ptr [ESP + 0x3c],EDI
    m.w32((f.sp+0x0000003cu), s.di);
  }
  L005f5903: { // 0x5f5903: 895c2440 MOV dword ptr [ESP + 0x40],EBX
    m.w32((f.sp+0x00000040u), s.bx);
  }
  L005f5907: { // 0x5f5907: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6248714u,op); flags=s.arithmetic_flags;
  }
  L005f590a: { // 0x5f590a: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f590e: { // 0x5f590e: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L005f5912: { // 0x5f5912: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L005f5916: { // 0x5f5916: 895c243c MOV dword ptr [ESP + 0x3c],EBX
    m.w32((f.sp+0x0000003cu), s.bx);
  }
  L005f591a: { // 0x5f591a: 8d440a01 LEA EAX,[EDX + ECX*0x1 + 0x1]
    s.ax = (s.dx+(s.cx * 0x00000001u)+0x00000001u);
  }
  L005f591e: { // 0x5f591e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f5920: { // 0x5f5920: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L005f5924: { // 0x5f5924: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L005f5928: { // 0x5f5928: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f5929: { // 0x5f5929: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L005f592d: { // 0x5f592d: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L005f5931: { // 0x5f5931: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f5932: { // 0x5f5932: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f5933: { // 0x5f5933: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005f5935: { // 0x5f5935: 897c244c MOV dword ptr [ESP + 0x4c],EDI
    m.w32((f.sp+0x0000004cu), s.di);
  }
  L005f5939: { // 0x5f5939: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6248764u,op); flags=s.arithmetic_flags;
  }
  L005f593c: { // 0x5f593c: 8d4bff LEA ECX,[EBX + -0x1]
    s.cx = (s.bx-0x00000001u);
  }
  L005f593f: { // 0x5f593f: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005f5943: { // 0x5f5943: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L005f5947: { // 0x5f5947: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L005f594b: { // 0x5f594b: 896c2448 MOV dword ptr [ESP + 0x48],EBP
    m.w32((f.sp+0x00000048u), s.bp);
  }
  L005f594f: { // 0x5f594f: 8d043a LEA EAX,[EDX + EDI*0x1]
    s.ax = (s.dx+(s.di * 0x00000001u));
  }
  L005f5952: { // 0x5f5952: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f5953: { // 0x5f5953: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L005f5957: { // 0x5f5957: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  L005f595b: { // 0x5f595b: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L005f595f: { // 0x5f595f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005f5961: { // 0x5f5961: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005f5962: { // 0x5f5962: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f5963: { // 0x5f5963: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005f5965: { // 0x5f5965: 896c245c MOV dword ptr [ESP + 0x5c],EBP
    m.w32((f.sp+0x0000005cu), s.bp);
  }
  L005f5969: { // 0x5f5969: ff5030 CALL dword ptr [EAX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000030u)),6248812u,op); flags=s.arithmetic_flags;
  }
  L005f596c: { // 0x5f596c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005f5970: { // 0x5f5970: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L005f5974: { // 0x5f5974: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005f5975: { // 0x5f5975: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005f5976: { // 0x5f5976: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L005f5977: { // 0x5f5977: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L005f5978: { // 0x5f5978: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005f597a: { // 0x5f597a: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005f597e: { // 0x5f597e: 0f8c31ffffff JL 0x005f58b5
    if(integer::condition("JL",flags)) goto L005f58b5;
  }
  L005f5984: { // 0x5f5984: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f5985: { // 0x5f5985: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f5986: { // 0x5f5986: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f5987: { // 0x5f5987: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f5988: { // 0x5f5988: 83c458 ADD ESP,0x58
    f.sp = integer::add(f.sp,0x00000058u,32,flags);
  }
  L005f598b: { // 0x5f598b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_001f6690(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005f6690: { // 0x5f6690: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L005f6693: { // 0x5f6693: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005f6694: { // 0x5f6694: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005f6695: { // 0x5f6695: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005f6697: { // 0x5f6697: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005f6699: { // 0x5f6699: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005f669b: { // 0x5f669b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005f669d: { // 0x5f669d: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L005f669f: { // 0x5f669f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005f66a0: { // 0x5f66a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005f66a1: { // 0x5f66a1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f66a3: { // 0x5f66a3: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L005f66a7: { // 0x5f66a7: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),6252202u,op); flags=s.arithmetic_flags;
  }
  L005f66aa: { // 0x5f66aa: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005f66ac: { // 0x5f66ac: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L005f66b0: { // 0x5f66b0: 0f8476010000 JZ 0x005f682c
    if(integer::condition("JZ",flags)) goto L005f682c;
  }
  L005f66b6: { // 0x5f66b6: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005f66b8: { // 0x5f66b8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005f66b9: { // 0x5f66b9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005f66ba: { // 0x5f66ba: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f66bc: { // 0x5f66bc: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),6252223u,op); flags=s.arithmetic_flags;
  }
  L005f66bf: { // 0x5f66bf: 8b5e0c MOV EBX,dword ptr [ESI + 0xc]
    s.bx = m.r32((s.si+0x0000000cu));
  }
  L005f66c2: { // 0x5f66c2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005f66c3: { // 0x5f66c3: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L005f66c5: { // 0x5f66c5: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L005f66c8: { // 0x5f66c8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005f66ca: { // 0x5f66ca: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L005f66cc: { // 0x5f66cc: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L005f66d0: { // 0x5f66d0: 03cb ADD ECX,EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L005f66d2: { // 0x5f66d2: d1fd SAR EBP,0x1
    s.bp = integer::shift(s.bp,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L005f66d4: { // 0x5f66d4: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L005f66d6: { // 0x5f66d6: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L005f66da: { // 0x5f66da: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005f66de: { // 0x5f66de: 0f8d95000000 JGE 0x005f6779
    if(integer::condition("JGE",flags)) goto L005f6779;
  }
  L005f66e4: { // 0x5f66e4: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L005f66e6: { // 0x5f66e6: 0fafcd IMUL ECX,EBP
    s.cx = integer::imul(s.cx,s.bp,32,flags);
  }
  L005f66e9: { // 0x5f66e9: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005f66ed: { // 0x5f66ed: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L005f66ef: { // 0x5f66ef: 8d1c39 LEA EBX,[ECX + EDI*0x1]
    s.bx = (s.cx+(s.di * 0x00000001u));
  }
  L005f66f2: { // 0x5f66f2: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L005f66f6: { // 0x5f66f6: 8d1c07 LEA EBX,[EDI + EAX*0x1]
    s.bx = (s.di+(s.ax * 0x00000001u));
  }
  L005f66f9: { // 0x5f66f9: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L005f66fb: { // 0x5f66fb: 7d5d JGE 0x005f675a
    if(integer::condition("JGE",flags)) goto L005f675a;
  }
  L005f66fd: { // 0x5f66fd: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L005f6701: { // 0x5f6701: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L005f6705: { // 0x5f6705: 8d0c4a LEA ECX,[EDX + ECX*0x2]
    s.cx = (s.dx+(s.cx * 0x00000002u));
  }
  L005f6708: { // 0x5f6708: 668b1d32dfa500 MOV BX,word ptr [0x00a5df32]
    s.bx = with_ax(s.bx, m.r16((0x00a5df32u)));
  }
  L005f670f: { // 0x5f670f: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005f6712: { // 0x5f6712: 668beb MOV bp,BX
    s.bp = (s.bp & 0xffff0000u) | (((s.bx & 0xffffu)) & 0xffffu);
  }
  L005f6715: { // 0x5f6715: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005f6718: { // 0x5f6718: 66d1ed SHR bp,0x1
    s.bp = (s.bp & 0xffff0000u) | ((integer::shift((s.bp & 0xffffu),0x00000001u,16,flags,integer::Shift::right)) & 0xffffu);
  }
  L005f671b: { // 0x5f671b: 6623eb AND bp,BX
    s.bp = (s.bp & 0xffff0000u) | ((integer::logical(((s.bp & 0xffffu))&((s.bx & 0xffffu)),16,flags)) & 0xffffu);
  }
  L005f671e: { // 0x5f671e: 668b1d30dfa500 MOV BX,word ptr [0x00a5df30]
    s.bx = with_ax(s.bx, m.r16((0x00a5df30u)));
  }
  L005f6725: { // 0x5f6725: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f6728: { // 0x5f6728: 231d30dfa500 AND EBX,dword ptr [0x00a5df30]
    s.bx = integer::logical((s.bx)&(m.r32((0x00a5df30u))),32,flags);
  }
  L005f672e: { // 0x5f672e: 66d1ea SHR DX,0x1
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f6731: { // 0x5f6731: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f6733: { // 0x5f6733: 668b1d34dfa500 MOV BX,word ptr [0x00a5df34]
    s.bx = with_ax(s.bx, m.r16((0x00a5df34u)));
  }
  L005f673a: { // 0x5f673a: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f673d: { // 0x5f673d: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f673f: { // 0x5f673f: 23ea AND EBP,EDX
    s.bp = integer::logical((s.bp)&(s.dx),32,flags);
  }
  L005f6741: { // 0x5f6741: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005f6742: { // 0x5f6742: 668969fe MOV word ptr [ECX + -0x2],bp
    m.w16((s.cx-0x00000002u), (s.bp & 0xffffu));
  }
  L005f6746: { // 0x5f6746: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005f6748: { // 0x5f6748: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f674a: { // 0x5f674a: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L005f674c: { // 0x5f674c: 7cba JL 0x005f6708
    if(integer::condition("JL",flags)) goto L005f6708;
  }
  L005f674e: { // 0x5f674e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L005f6752: { // 0x5f6752: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L005f6756: { // 0x5f6756: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L005f675a: { // 0x5f675a: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L005f675d: { // 0x5f675d: 8b5e0c MOV EBX,dword ptr [ESI + 0xc]
    s.bx = m.r32((s.si+0x0000000cu));
  }
  L005f6760: { // 0x5f6760: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L005f6761: { // 0x5f6761: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L005f6763: { // 0x5f6763: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L005f6765: { // 0x5f6765: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L005f6767: { // 0x5f6767: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L005f676b: { // 0x5f676b: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L005f676f: { // 0x5f676f: 0f8c78ffffff JL 0x005f66ed
    if(integer::condition("JL",flags)) goto L005f66ed;
  }
  L005f6775: { // 0x5f6775: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L005f6779: { // 0x5f6779: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L005f677c: { // 0x5f677c: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L005f6780: { // 0x5f6780: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L005f6784: { // 0x5f6784: 8d140b LEA EDX,[EBX + ECX*0x1]
    s.dx = (s.bx+(s.cx * 0x00000001u));
  }
  L005f6787: { // 0x5f6787: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L005f6789: { // 0x5f6789: 0f8d94000000 JGE 0x005f6823
    if(integer::condition("JGE",flags)) goto L005f6823;
  }
  L005f678f: { // 0x5f678f: 0fafdd IMUL EBX,EBP
    s.bx = integer::imul(s.bx,s.bp,32,flags);
  }
  L005f6792: { // 0x5f6792: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L005f6796: { // 0x5f6796: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L005f6798: { // 0x5f6798: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L005f679b: { // 0x5f679b: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L005f679d: { // 0x5f679d: 8d140b LEA EDX,[EBX + ECX*0x1]
    s.dx = (s.bx+(s.cx * 0x00000001u));
  }
  L005f67a0: { // 0x5f67a0: 8d3c01 LEA EDI,[ECX + EAX*0x1]
    s.di = (s.cx+(s.ax * 0x00000001u));
  }
  L005f67a3: { // 0x5f67a3: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L005f67a5: { // 0x5f67a5: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L005f67a7: { // 0x5f67a7: 7d52 JGE 0x005f67fb
    if(integer::condition("JGE",flags)) goto L005f67fb;
  }
  L005f67a9: { // 0x5f67a9: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005f67ad: { // 0x5f67ad: 8d0c51 LEA ECX,[ECX + EDX*0x2]
    s.cx = (s.cx+(s.dx * 0x00000002u));
  }
  L005f67b0: { // 0x5f67b0: 668b1d32dfa500 MOV BX,word ptr [0x00a5df32]
    s.bx = with_ax(s.bx, m.r16((0x00a5df32u)));
  }
  L005f67b7: { // 0x5f67b7: 668b11 MOV DX,word ptr [ECX]
    s.dx = with_ax(s.dx, m.r16((s.cx)));
  }
  L005f67ba: { // 0x5f67ba: 668beb MOV bp,BX
    s.bp = (s.bp & 0xffff0000u) | (((s.bx & 0xffffu)) & 0xffffu);
  }
  L005f67bd: { // 0x5f67bd: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  L005f67c0: { // 0x5f67c0: 66d1ed SHR bp,0x1
    s.bp = (s.bp & 0xffff0000u) | ((integer::shift((s.bp & 0xffffu),0x00000001u,16,flags,integer::Shift::right)) & 0xffffu);
  }
  L005f67c3: { // 0x5f67c3: 6623eb AND bp,BX
    s.bp = (s.bp & 0xffff0000u) | ((integer::logical(((s.bp & 0xffffu))&((s.bx & 0xffffu)),16,flags)) & 0xffffu);
  }
  L005f67c6: { // 0x5f67c6: 668b1d30dfa500 MOV BX,word ptr [0x00a5df30]
    s.bx = with_ax(s.bx, m.r16((0x00a5df30u)));
  }
  L005f67cd: { // 0x5f67cd: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f67d0: { // 0x5f67d0: 231d30dfa500 AND EBX,dword ptr [0x00a5df30]
    s.bx = integer::logical((s.bx)&(m.r32((0x00a5df30u))),32,flags);
  }
  L005f67d6: { // 0x5f67d6: 66d1ea SHR DX,0x1
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f67d9: { // 0x5f67d9: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f67db: { // 0x5f67db: 668b1d34dfa500 MOV BX,word ptr [0x00a5df34]
    s.bx = with_ax(s.bx, m.r16((0x00a5df34u)));
  }
  L005f67e2: { // 0x5f67e2: 66d1eb SHR BX,0x1
    s.bx = with_ax(s.bx, integer::shift((s.bx & 0xffffu),0x00000001u,16,flags,integer::Shift::right));
  }
  L005f67e5: { // 0x5f67e5: 0beb OR EBP,EBX
    s.bp = integer::logical((s.bp)|(s.bx),32,flags);
  }
  L005f67e7: { // 0x5f67e7: 23ea AND EBP,EDX
    s.bp = integer::logical((s.bp)&(s.dx),32,flags);
  }
  L005f67e9: { // 0x5f67e9: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005f67ea: { // 0x5f67ea: 668969fe MOV word ptr [ECX + -0x2],bp
    m.w16((s.cx-0x00000002u), (s.bp & 0xffffu));
  }
  L005f67ee: { // 0x5f67ee: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L005f67f1: { // 0x5f67f1: 0316 ADD EDX,dword ptr [ESI]
    s.dx = integer::add(s.dx,m.r32((s.si)),32,flags);
  }
  L005f67f3: { // 0x5f67f3: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L005f67f5: { // 0x5f67f5: 7cb9 JL 0x005f67b0
    if(integer::condition("JL",flags)) goto L005f67b0;
  }
  L005f67f7: { // 0x5f67f7: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L005f67fb: { // 0x5f67fb: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L005f67ff: { // 0x5f67ff: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005f6803: { // 0x5f6803: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L005f6807: { // 0x5f6807: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L005f6809: { // 0x5f6809: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L005f680c: { // 0x5f680c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L005f680d: { // 0x5f680d: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L005f680f: { // 0x5f680f: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L005f6813: { // 0x5f6813: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005f6815: { // 0x5f6815: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L005f6819: { // 0x5f6819: 0f8c77ffffff JL 0x005f6796
    if(integer::condition("JL",flags)) goto L005f6796;
  }
  L005f681f: { // 0x5f681f: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L005f6823: { // 0x5f6823: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L005f6825: { // 0x5f6825: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005f6827: { // 0x5f6827: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),6252586u,op); flags=s.arithmetic_flags;
  }
  L005f682a: { // 0x5f682a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005f682b: { // 0x5f682b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005f682c: { // 0x5f682c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005f682d: { // 0x5f682d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005f682e: { // 0x5f682e: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005f6831: { // 0x5f6831: c20800 RET 0x8
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
  L0043139f: { // 0x43139f: 668b3b MOV di,word ptr [EBX]
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
  L004313a9: { // 0x4313a9: 6685ff TEST di,di
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
  L004314c9: { // 0x4314c9: 668b3b MOV di,word ptr [EBX]
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
  L004314d7: { // 0x4314d7: 6685ff TEST di,di
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
  L004317ad: { // 0x4317ad: 6683ff09 CMP di,0x9
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
  L00431974: { // 0x431974: 66892e MOV word ptr [ESI],bp
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
  L00431997: { // 0x431997: 66892e MOV word ptr [ESI],bp
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
  L004319b4: { // 0x4319b4: 66892e MOV word ptr [ESI],bp
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
  L004319d1: { // 0x4319d1: 66892e MOV word ptr [ESI],bp
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
  L004319ea: { // 0x4319ea: 66892e MOV word ptr [ESI],bp
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
  L00431a03: { // 0x431a03: 66892e MOV word ptr [ESI],bp
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
  L00431a1c: { // 0x431a1c: 66892e MOV word ptr [ESI],bp
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
  L00431a35: { // 0x431a35: 66892e MOV word ptr [ESI],bp
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
  L00431ac2: { // 0x431ac2: 668931 MOV word ptr [ECX],si
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
  L00431ad2: { // 0x431ad2: 668931 MOV word ptr [ECX],si
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
  L00431ae2: { // 0x431ae2: 668931 MOV word ptr [ECX],si
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
  L00431af2: { // 0x431af2: 668931 MOV word ptr [ECX],si
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
  L00431b02: { // 0x431b02: 668931 MOV word ptr [ECX],si
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
  L00431b12: { // 0x431b12: 668931 MOV word ptr [ECX],si
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
  L00431b22: { // 0x431b22: 668931 MOV word ptr [ECX],si
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
  L00431b32: { // 0x431b32: 668931 MOV word ptr [ECX],si
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
  L00431b8a: { // 0x431b8a: 668b32 MOV si,word ptr [EDX]
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
  L00431b93: { // 0x431b93: 6685f6 TEST si,si
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
  L00431cad: { // 0x431cad: 6683fe0d CMP si,0xd
    (void)integer::sub((s.si & 0xffffu),0x0000000du,16,flags);
  }
  L00431cb1: { // 0x431cb1: 7422 JZ 0x00431cd5
    if(integer::condition("JZ",flags)) goto L00431cd5;
  }
  L00431cb3: { // 0x431cb3: 6683fe0a CMP si,0xa
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
  L00431ce8: { // 0x431ce8: 668b32 MOV si,word ptr [EDX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx))) & 0xffffu);
  }
  L00431ceb: { // 0x431ceb: 83c202 ADD EDX,0x2
    s.dx = integer::add(s.dx,0x00000002u,32,flags);
  }
  L00431cee: { // 0x431cee: 6685f6 TEST si,si
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

void f_0035f290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f290: { // 0x75f290: 8b44240c MOV EAX, dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0075f294: { // 0x75f294: 83ec10 SUB ESP, 0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0075f297: { // 0x75f297: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f29b: { // 0x75f29b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075f29c: { // 0x75f29c: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0075f29e: { // 0x75f29e: 8b4c241c MOV ECX, dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f2a2: { // 0x75f2a2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2a3: { // 0x75f2a3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0075f2a5: { // 0x75f2a5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2a6: { // 0x75f2a6: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L0075f2aa: { // 0x75f2aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0075f2ab: { // 0x75f2ab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2ac: { // 0x75f2ac: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0075f2ae: { // 0x75f2ae: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7729841u,op); flags=s.arithmetic_flags;
  }
  L0075f2b1: { // 0x75f2b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2b2: { // 0x75f2b2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0075f2b4: { // 0x75f2b4: e807000000 CALL 0x75f2c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0075f2c0u,7729849u,op); flags=s.arithmetic_flags;
  }
  L0075f2b9: { // 0x75f2b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f2ba: { // 0x75f2ba: 83c410 ADD ESP, 0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0075f2bd: { // 0x75f2bd: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_0035f2c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f2c0: { // 0x75f2c0: 83ec44 SUB ESP,0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L0075f2c3: { // 0x75f2c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075f2c4: { // 0x75f2c4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0075f2c6: { // 0x75f2c6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0075f2c7: { // 0x75f2c7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075f2c8: { // 0x75f2c8: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f2ca: { // 0x75f2ca: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0075f2ce: { // 0x75f2ce: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075f2cf: { // 0x75f2cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2d0: { // 0x75f2d0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f2d2: { // 0x75f2d2: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7729877u,op); flags=s.arithmetic_flags;
  }
  L0075f2d5: { // 0x75f2d5: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L0075f2d9: { // 0x75f2d9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075f2db: { // 0x75f2db: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075f2dd: { // 0x75f2dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2de: { // 0x75f2de: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0075f2e2: { // 0x75f2e2: e8090bccff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7729895u,op); flags=s.arithmetic_flags;
  }
  L0075f2e7: { // 0x75f2e7: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0075f2e9: { // 0x75f2e9: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0075f2ed: { // 0x75f2ed: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0075f2f0: { // 0x75f2f0: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0075f2f4: { // 0x75f2f4: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0075f2f7: { // 0x75f2f7: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0075f2fb: { // 0x75f2fb: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L0075f2ff: { // 0x75f2ff: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075f302: { // 0x75f302: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0075f306: { // 0x75f306: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0075f308: { // 0x75f308: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0075f30b: { // 0x75f30b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0075f30d: { // 0x75f30d: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f30f: { // 0x75f30f: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0075f313: { // 0x75f313: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0075f317: { // 0x75f317: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L0075f31b: { // 0x75f31b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0075f31d: { // 0x75f31d: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0075f320: { // 0x75f320: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f322: { // 0x75f322: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0075f324: { // 0x75f324: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0075f328: { // 0x75f328: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0075f32c: { // 0x75f32c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f32d: { // 0x75f32d: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0075f331: { // 0x75f331: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0075f335: { // 0x75f335: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0075f339: { // 0x75f339: e8221c0000 CALL 0x00760f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760f60u,7729982u,op); flags=s.arithmetic_flags;
  }
  L0075f33e: { // 0x75f33e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0075f340: { // 0x75f340: 0f841b020000 JZ 0x0075f561
    if(integer::condition("JZ",flags)) goto L0075f561;
  }
  L0075f346: { // 0x75f346: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0075f34a: { // 0x75f34a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0075f34e: { // 0x75f34e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f350: { // 0x75f350: 7e18 JLE 0x0075f36a
    if(integer::condition("JLE",flags)) goto L0075f36a;
  }
  L0075f352: { // 0x75f352: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0075f356: { // 0x75f356: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0075f35a: { // 0x75f35a: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0075f35e: { // 0x75f35e: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0075f362: { // 0x75f362: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0075f366: { // 0x75f366: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0075f36a: { // 0x75f36a: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f36c: { // 0x75f36c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f36e: { // 0x75f36e: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),7730033u,op); flags=s.arithmetic_flags;
  }
  L0075f371: { // 0x75f371: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0075f375: { // 0x75f375: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f377: { // 0x75f377: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0075f379: { // 0x75f379: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0075f37d: { // 0x75f37d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f37e: { // 0x75f37e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f37f: { // 0x75f37f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f381: { // 0x75f381: 896c2464 MOV dword ptr [ESP + 0x64],EBP
    m.w32((f.sp+0x00000064u), s.bp);
  }
  L0075f385: { // 0x75f385: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7730056u,op); flags=s.arithmetic_flags;
  }
  L0075f388: { // 0x75f388: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0075f38a: { // 0x75f38a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0075f38c: { // 0x75f38c: 0f84cf010000 JZ 0x0075f561
    if(integer::condition("JZ",flags)) goto L0075f561;
  }
  L0075f392: { // 0x75f392: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0075f396: { // 0x75f396: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0075f39a: { // 0x75f39a: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0075f39c: { // 0x75f39c: 757f JNZ 0x0075f41d
    if(integer::condition("JNZ",flags)) goto L0075f41d;
  }
  L0075f39e: { // 0x75f39e: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L0075f3a1: { // 0x75f3a1: 753c JNZ 0x0075f3df
    if(integer::condition("JNZ",flags)) goto L0075f3df;
  }
  L0075f3a3: { // 0x75f3a3: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3a7: { // 0x75f3a7: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f3ab: { // 0x75f3ab: 8a442464 MOV AL,byte ptr [ESP + 0x64]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000064u)));
  }
  L0075f3af: { // 0x75f3af: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0075f3b1: { // 0x75f3b1: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0075f3b3: { // 0x75f3b3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0075f3b4: { // 0x75f3b4: 8af2 MOV DH,DL
    s.dx = (s.dx & 0xffff00ffu) | ((((s.dx & 0xffu)) & 0xffu) << 8);
  }
  L0075f3b6: { // 0x75f3b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0075f3b8: { // 0x75f3b8: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0075f3ba: { // 0x75f3ba: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075f3bd: { // 0x75f3bd: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L0075f3c0: { // 0x75f3c0: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0075f3c3: { // 0x75f3c3: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075f3c5: { // 0x75f3c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075f3c7: { // 0x75f3c7: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0075f3ca: { // 0x75f3ca: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L0075f3cc: { // 0x75f3cc: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f3ce: { // 0x75f3ce: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f3d0: { // 0x75f3d0: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730131u,op); flags=s.arithmetic_flags;
  }
  L0075f3d3: { // 0x75f3d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f3d4: { // 0x75f3d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f3d5: { // 0x75f3d5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f3d6: { // 0x75f3d6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f3d8: { // 0x75f3d8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f3d9: { // 0x75f3d9: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f3dc: { // 0x75f3dc: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f3df: { // 0x75f3df: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3e3: { // 0x75f3e3: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f3e7: { // 0x75f3e7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0075f3e9: { // 0x75f3e9: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0075f3eb: { // 0x75f3eb: 0f885d010000 JS 0x0075f54e
    if(integer::condition("JS",flags)) goto L0075f54e;
  }
  L0075f3f1: { // 0x75f3f1: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0075f3f5: { // 0x75f3f5: 66890f MOV word ptr [EDI],CX
    m.w16((s.di), (s.cx & 0xffffu));
  }
  L0075f3f8: { // 0x75f3f8: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3fc: { // 0x75f3fc: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0075f400: { // 0x75f400: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0075f401: { // 0x75f401: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L0075f403: { // 0x75f403: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L0075f406: { // 0x75f406: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f408: { // 0x75f408: 7eeb JLE 0x0075f3f5
    if(integer::condition("JLE",flags)) goto L0075f3f5;
  }
  L0075f40a: { // 0x75f40a: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f40c: { // 0x75f40c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f40e: { // 0x75f40e: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730193u,op); flags=s.arithmetic_flags;
  }
  L0075f411: { // 0x75f411: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f412: { // 0x75f412: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f413: { // 0x75f413: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f414: { // 0x75f414: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f416: { // 0x75f416: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f417: { // 0x75f417: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f41a: { // 0x75f41a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f41d: { // 0x75f41d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0075f421: { // 0x75f421: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f425: { // 0x75f425: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0075f427: { // 0x75f427: 755a JNZ 0x0075f483
    if(integer::condition("JNZ",flags)) goto L0075f483;
  }
  L0075f429: { // 0x75f429: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0075f42b: { // 0x75f42b: 7e0d JLE 0x0075f43a
    if(integer::condition("JLE",flags)) goto L0075f43a;
  }
  L0075f42d: { // 0x75f42d: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f42f: { // 0x75f42f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f431: { // 0x75f431: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730228u,op); flags=s.arithmetic_flags;
  }
  L0075f434: { // 0x75f434: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0075f436: { // 0x75f436: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0075f438: { // 0x75f438: eb09 JMP 0x0075f443
    goto L0075f443;
  }
  L0075f43a: { // 0x75f43a: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f43c: { // 0x75f43c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f43e: { // 0x75f43e: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),7730241u,op); flags=s.arithmetic_flags;
  }
  L0075f441: { // 0x75f441: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0075f443: { // 0x75f443: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0075f447: { // 0x75f447: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0075f44b: { // 0x75f44b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f44d: { // 0x75f44d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0075f44e: { // 0x75f44e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0075f450: { // 0x75f450: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f452: { // 0x75f452: 0f88f6000000 JS 0x0075f54e
    if(integer::condition("JS",flags)) goto L0075f54e;
  }
  L0075f458: { // 0x75f458: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L0075f45b: { // 0x75f45b: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f45f: { // 0x75f45f: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L0075f462: { // 0x75f462: 7504 JNZ 0x0075f468
    if(integer::condition("JNZ",flags)) goto L0075f468;
  }
  L0075f464: { // 0x75f464: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0075f466: { // 0x75f466: eb03 JMP 0x0075f46b
    goto L0075f46b;
  }
  L0075f468: { // 0x75f468: 668907 MOV word ptr [EDI],AX
    m.w16((s.di), (s.ax & 0xffffu));
  }
  L0075f46b: { // 0x75f46b: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0075f46d: { // 0x75f46d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0075f46e: { // 0x75f46e: 75ef JNZ 0x0075f45f
    if(integer::condition("JNZ",flags)) goto L0075f45f;
  }
  L0075f470: { // 0x75f470: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f472: { // 0x75f472: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f474: { // 0x75f474: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730295u,op); flags=s.arithmetic_flags;
  }
  L0075f477: { // 0x75f477: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f478: { // 0x75f478: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f479: { // 0x75f479: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f47a: { // 0x75f47a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f47c: { // 0x75f47c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f47d: { // 0x75f47d: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f480: { // 0x75f480: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f483: { // 0x75f483: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f485: { // 0x75f485: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0075f487: { // 0x75f487: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0075f489: { // 0x75f489: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f48b: { // 0x75f48b: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0075f48d: { // 0x75f48d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f48f: { // 0x75f48f: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730322u,op); flags=s.arithmetic_flags;
  }
  L0075f492: { // 0x75f492: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0075f494: { // 0x75f494: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0075f498: { // 0x75f498: 7d06 JGE 0x0075f4a0
    if(integer::condition("JGE",flags)) goto L0075f4a0;
  }
  L0075f49a: { // 0x75f49a: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0075f49c: { // 0x75f49c: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0075f4a0: { // 0x75f4a0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0075f4a2: { // 0x75f4a2: 8d742d00 LEA ESI,[EBP + EBP*0x1]
    s.si = (s.bp+(s.bp * 0x00000001u));
  }
  L0075f4a6: { // 0x75f4a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0075f4a7: { // 0x75f4a7: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0075f4a9: { // 0x75f4a9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f4ab: { // 0x75f4ab: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0075f4ad: { // 0x75f4ad: 8d0c00 LEA ECX,[EAX + EAX*0x1]
    s.cx = (s.ax+(s.ax * 0x00000001u));
  }
  L0075f4b0: { // 0x75f4b0: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0075f4b4: { // 0x75f4b4: 7e54 JLE 0x0075f50a
    if(integer::condition("JLE",flags)) goto L0075f50a;
  }
  L0075f4b6: { // 0x75f4b6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0075f4b8: { // 0x75f4b8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0075f4ba: { // 0x75f4ba: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0075f4bc: { // 0x75f4bc: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0075f4be: { // 0x75f4be: 0f8e8a000000 JLE 0x0075f54e
    if(integer::condition("JLE",flags)) goto L0075f54e;
  }
  L0075f4c4: { // 0x75f4c4: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0075f4c8: { // 0x75f4c8: 837c245c01 CMP dword ptr [ESP + 0x5c],0x1
    (void)integer::sub(m.r32((f.sp+0x0000005cu)),0x00000001u,32,flags);
  }
  L0075f4cd: { // 0x75f4cd: 7505 JNZ 0x0075f4d4
    if(integer::condition("JNZ",flags)) goto L0075f4d4;
  }
  L0075f4cf: { // 0x75f4cf: 881439 MOV byte ptr [ECX + EDI*0x1],DL
    m.w8((s.cx+(s.di * 0x00000001u)), (s.dx & 0xffu));
  }
  L0075f4d2: { // 0x75f4d2: eb08 JMP 0x0075f4dc
    goto L0075f4dc;
  }
  L0075f4d4: { // 0x75f4d4: 6689144f MOV word ptr [EDI + ECX*0x2],DX
    m.w16((s.di+(s.cx * 0x00000002u)), (s.dx & 0xffffu));
  }
  L0075f4d8: { // 0x75f4d8: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0075f4dc: { // 0x75f4dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075f4de: { // 0x75f4de: 7e0c JLE 0x0075f4ec
    if(integer::condition("JLE",flags)) goto L0075f4ec;
  }
  L0075f4e0: { // 0x75f4e0: 8b742458 MOV ESI,dword ptr [ESP + 0x58]
    s.si = m.r32((f.sp+0x00000058u));
  }
  L0075f4e4: { // 0x75f4e4: 03fe ADD EDI,ESI
    s.di = integer::add(s.di,s.si,32,flags);
  }
  L0075f4e6: { // 0x75f4e6: 8d742d00 LEA ESI,[EBP + EBP*0x1]
    s.si = (s.bp+(s.bp * 0x00000001u));
  }
  L0075f4ea: { // 0x75f4ea: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0075f4ec: { // 0x75f4ec: 8b742460 MOV ESI,dword ptr [ESP + 0x60]
    s.si = m.r32((f.sp+0x00000060u));
  }
  L0075f4f0: { // 0x75f4f0: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0075f4f2: { // 0x75f4f2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0075f4f3: { // 0x75f4f3: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L0075f4f5: { // 0x75f4f5: 7cd1 JL 0x0075f4c8
    if(integer::condition("JL",flags)) goto L0075f4c8;
  }
  L0075f4f7: { // 0x75f4f7: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f4f9: { // 0x75f4f9: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f4fb: { // 0x75f4fb: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730430u,op); flags=s.arithmetic_flags;
  }
  L0075f4fe: { // 0x75f4fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f4ff: { // 0x75f4ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f500: { // 0x75f500: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f501: { // 0x75f501: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f503: { // 0x75f503: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f504: { // 0x75f504: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f507: { // 0x75f507: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f50a: { // 0x75f50a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075f50c: { // 0x75f50c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0075f50e: { // 0x75f50e: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0075f510: { // 0x75f510: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075f512: { // 0x75f512: 7e3a JLE 0x0075f54e
    if(integer::condition("JLE",flags)) goto L0075f54e;
  }
  L0075f514: { // 0x75f514: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0075f518: { // 0x75f518: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f51c: { // 0x75f51c: 837c245c01 CMP dword ptr [ESP + 0x5c],0x1
    (void)integer::sub(m.r32((f.sp+0x0000005cu)),0x00000001u,32,flags);
  }
  L0075f521: { // 0x75f521: 7505 JNZ 0x0075f528
    if(integer::condition("JNZ",flags)) goto L0075f528;
  }
  L0075f523: { // 0x75f523: 88043a MOV byte ptr [EDX + EDI*0x1],AL
    m.w8((s.dx+(s.di * 0x00000001u)), (s.ax & 0xffu));
  }
  L0075f526: { // 0x75f526: eb08 JMP 0x0075f530
    goto L0075f530;
  }
  L0075f528: { // 0x75f528: 66890457 MOV word ptr [EDI + EDX*0x2],AX
    m.w16((s.di+(s.dx * 0x00000002u)), (s.ax & 0xffffu));
  }
  L0075f52c: { // 0x75f52c: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f530: { // 0x75f530: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0075f532: { // 0x75f532: 7e07 JLE 0x0075f53b
    if(integer::condition("JLE",flags)) goto L0075f53b;
  }
  L0075f534: { // 0x75f534: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L0075f538: { // 0x75f538: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0075f539: { // 0x75f539: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  L0075f53b: { // 0x75f53b: 8b6c2458 MOV EBP,dword ptr [ESP + 0x58]
    s.bp = m.r32((f.sp+0x00000058u));
  }
  L0075f53f: { // 0x75f53f: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f541: { // 0x75f541: 03fd ADD EDI,EBP
    s.di = integer::add(s.di,s.bp,32,flags);
  }
  L0075f543: { // 0x75f543: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0075f547: { // 0x75f547: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0075f548: { // 0x75f548: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0075f54c: { // 0x75f54c: 75ce JNZ 0x0075f51c
    if(integer::condition("JNZ",flags)) goto L0075f51c;
  }
  L0075f54e: { // 0x75f54e: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f550: { // 0x75f550: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f552: { // 0x75f552: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730517u,op); flags=s.arithmetic_flags;
  }
  L0075f555: { // 0x75f555: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f556: { // 0x75f556: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f557: { // 0x75f557: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f558: { // 0x75f558: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f55a: { // 0x75f55a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f55b: { // 0x75f55b: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f55e: { // 0x75f55e: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f561: { // 0x75f561: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f562: { // 0x75f562: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f563: { // 0x75f563: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f564: { // 0x75f564: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0075f566: { // 0x75f566: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f567: { // 0x75f567: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f56a: { // 0x75f56a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_00360f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760f60: { // 0x760f60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760f61: { // 0x760f61: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00760f63: { // 0x760f63: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00760f66: { // 0x760f66: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L00760f69: { // 0x760f69: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760f6a: { // 0x760f6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760f6b: { // 0x760f6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760f6c: { // 0x760f6c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00760f6e: { // 0x760f6e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00760f70: { // 0x760f70: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00760f73: { // 0x760f73: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00760f77: { // 0x760f77: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00760f79: { // 0x760f79: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L00760f7c: { // 0x760f7c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00760f80: { // 0x760f80: 8b5908 MOV EBX,dword ptr [ECX + 0x8]
    s.bx = m.r32((s.cx+0x00000008u));
  }
  L00760f83: { // 0x760f83: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f87: { // 0x760f87: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00760f8b: { // 0x760f8b: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00760f8d: { // 0x760f8d: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760f91: { // 0x760f91: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f95: { // 0x760f95: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00760f99: { // 0x760f99: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00760f9b: { // 0x760f9b: db02 FILD dword ptr [EDX]
    const auto address=(s.dx);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f9d: { // 0x760f9d: dd5c2438 FSTP double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fa1: { // 0x760fa1: db4204 FILD dword ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fa4: { // 0x760fa4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00760fa6: { // 0x760fa6: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760faa: { // 0x760faa: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fac: { // 0x760fac: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760fb0: { // 0x760fb0: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fb3: { // 0x760fb3: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fb7: { // 0x760fb7: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L00760fbb: { // 0x760fbb: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fbd: { // 0x760fbd: d8e1 FSUB st0,st1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00760fbf: { // 0x760fbf: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00760fc3: { // 0x760fc3: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L00760fc7: { // 0x760fc7: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fc9: { // 0x760fc9: d8f1 FDIV st0,st1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fcb: { // 0x760fcb: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fcf: { // 0x760fcf: d8f1 FDIV st0,st1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fd1: { // 0x760fd1: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fd5: { // 0x760fd5: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fd7: { // 0x760fd7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fdb: { // 0x760fdb: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fdf: { // 0x760fdf: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00760fe3: { // 0x760fe3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760fe5: { // 0x760fe5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760fe8: { // 0x760fe8: 7509 JNZ 0x00760ff3
    if(integer::condition("JNZ",flags)) goto L00760ff3;
  }
  L00760fea: { // 0x760fea: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fec: { // 0x760fec: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00760ff1: { // 0x760ff1: eb0e JMP 0x00761001
    goto L00761001;
  }
  L00760ff3: { // 0x760ff3: d8dc FCOMP st4
    numeric_b88::detail::reg<0xd8dc>(s.fp);
  }
  L00760ff5: { // 0x760ff5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760ff7: { // 0x760ff7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760ffa: { // 0x760ffa: 7405 JZ 0x00761001
    if(integer::condition("JZ",flags)) goto L00761001;
  }
  L00760ffc: { // 0x760ffc: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00761001: { // 0x761001: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00761004: { // 0x761004: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00761006: { // 0x761006: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076100a: { // 0x76100a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0076100e: { // 0x76100e: dd5c2450 FSTP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761012: { // 0x761012: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L00761016: { // 0x761016: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0076101a: { // 0x76101a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076101c: { // 0x76101c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076101f: { // 0x76101f: 7505 JNZ 0x00761026
    if(integer::condition("JNZ",flags)) goto L00761026;
  }
  L00761021: { // 0x761021: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L00761024: { // 0x761024: eb10 JMP 0x00761036
    goto L00761036;
  }
  L00761026: { // 0x761026: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0076102a: { // 0x76102a: d8db FCOMP st3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076102c: { // 0x76102c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076102e: { // 0x76102e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761031: { // 0x761031: 7403 JZ 0x00761036
    if(integer::condition("JZ",flags)) goto L00761036;
  }
  L00761033: { // 0x761033: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761036: { // 0x761036: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0076103a: { // 0x76103a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076103c: { // 0x76103c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076103e: { // 0x76103e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761041: { // 0x761041: 7509 JNZ 0x0076104c
    if(integer::condition("JNZ",flags)) goto L0076104c;
  }
  L00761043: { // 0x761043: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761045: { // 0x761045: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0076104a: { // 0x76104a: eb0e JMP 0x0076105a
    goto L0076105a;
  }
  L0076104c: { // 0x76104c: d8db FCOMP st3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076104e: { // 0x76104e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761050: { // 0x761050: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761053: { // 0x761053: 7405 JZ 0x0076105a
    if(integer::condition("JZ",flags)) goto L0076105a;
  }
  L00761055: { // 0x761055: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0076105a: { // 0x76105a: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L0076105e: { // 0x76105e: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00761062: { // 0x761062: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761064: { // 0x761064: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761067: { // 0x761067: 7505 JNZ 0x0076106e
    if(integer::condition("JNZ",flags)) goto L0076106e;
  }
  L00761069: { // 0x761069: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L0076106c: { // 0x76106c: eb10 JMP 0x0076107e
    goto L0076107e;
  }
  L0076106e: { // 0x76106e: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761072: { // 0x761072: d8da FCOMP st2
    numeric_b88::detail::reg<0xd8da>(s.fp);
  }
  L00761074: { // 0x761074: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761076: { // 0x761076: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761079: { // 0x761079: 7403 JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076107b: { // 0x76107b: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  L0076107e: { // 0x76107e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761080: { // 0x761080: 7508 JNZ 0x0076108a
    if(integer::condition("JNZ",flags)) goto L0076108a;
  }
  L00761082: { // 0x761082: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00761084: { // 0x761084: 0f844f010000 JZ 0x007611d9
    if(integer::condition("JZ",flags)) goto L007611d9;
  }
  L0076108a: { // 0x76108a: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076108c: { // 0x76108c: 0f858a010000 JNZ 0x0076121c
    if(integer::condition("JNZ",flags)) goto L0076121c;
  }
  L00761092: { // 0x761092: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761094: { // 0x761094: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00761096: { // 0x761096: 7502 JNZ 0x0076109a
    if(integer::condition("JNZ",flags)) goto L0076109a;
  }
  L00761098: { // 0x761098: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076109a: { // 0x76109a: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0076109c: { // 0x76109c: 7418 JZ 0x007610b6
    if(integer::condition("JZ",flags)) goto L007610b6;
  }
  L0076109e: { // 0x76109e: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610a0: { // 0x7610a0: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610a2: { // 0x7610a2: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610a6: { // 0x7610a6: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610aa: { // 0x7610aa: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610ae: { // 0x7610ae: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007610b2: { // 0x7610b2: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610b4: { // 0x7610b4: eb72 JMP 0x00761128
    goto L00761128;
  }
  L007610b6: { // 0x7610b6: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L007610b8: { // 0x7610b8: 741f JZ 0x007610d9
    if(integer::condition("JZ",flags)) goto L007610d9;
  }
  L007610ba: { // 0x7610ba: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L007610be: { // 0x7610be: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610bf: { // 0x7610bf: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610c1: { // 0x7610c1: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610c5: { // 0x7610c5: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610c9: { // 0x7610c9: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610cb: { // 0x7610cb: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610cf: { // 0x7610cf: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610d3: { // 0x7610d3: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610d7: { // 0x7610d7: eb4b JMP 0x00761124
    goto L00761124;
  }
  L007610d9: { // 0x7610d9: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L007610db: { // 0x7610db: 7431 JZ 0x0076110e
    if(integer::condition("JZ",flags)) goto L0076110e;
  }
  L007610dd: { // 0x7610dd: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007610e1: { // 0x7610e1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610e2: { // 0x7610e2: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610e4: { // 0x7610e4: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610e8: { // 0x7610e8: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610ec: { // 0x7610ec: dd542418 FST double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L007610f0: { // 0x7610f0: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L007610f4: { // 0x7610f4: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L007610f8: { // 0x7610f8: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007610fc: { // 0x7610fc: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L00761100: { // 0x761100: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L00761104: { // 0x761104: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L00761108: { // 0x761108: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L0076110c: { // 0x76110c: eb1a JMP 0x00761128
    goto L00761128;
  }
  L0076110e: { // 0x76110e: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00761110: { // 0x761110: 7416 JZ 0x00761128
    if(integer::condition("JZ",flags)) goto L00761128;
  }
  L00761112: { // 0x761112: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761114: { // 0x761114: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761116: { // 0x761116: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L0076111a: { // 0x76111a: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L0076111e: { // 0x76111e: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L00761122: { // 0x761122: d9c2 FLD st2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00761124: { // 0x761124: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761128: { // 0x761128: dd442430 FLD double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L0076112c: { // 0x76112c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0076112e: { // 0x76112e: 7556 JNZ 0x00761186
    if(integer::condition("JNZ",flags)) goto L00761186;
  }
  L00761130: { // 0x761130: dd542438 FST double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00761134: { // 0x761134: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761136: { // 0x761136: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00761138: { // 0x761138: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0076113c: { // 0x76113c: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761140: { // 0x761140: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761142: { // 0x761142: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761145: { // 0x761145: 7509 JNZ 0x00761150
    if(integer::condition("JNZ",flags)) goto L00761150;
  }
  L00761147: { // 0x761147: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761149: { // 0x761149: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0076114e: { // 0x76114e: eb0e JMP 0x0076115e
    goto L0076115e;
  }
  L00761150: { // 0x761150: d8db FCOMP st3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L00761152: { // 0x761152: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761154: { // 0x761154: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761157: { // 0x761157: 7405 JZ 0x0076115e
    if(integer::condition("JZ",flags)) goto L0076115e;
  }
  L00761159: { // 0x761159: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0076115e: { // 0x76115e: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761162: { // 0x761162: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761164: { // 0x761164: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761167: { // 0x761167: 7508 JNZ 0x00761171
    if(integer::condition("JNZ",flags)) goto L00761171;
  }
  L00761169: { // 0x761169: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L0076116c: { // 0x76116c: e90dffffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761171: { // 0x761171: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L00761173: { // 0x761173: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761175: { // 0x761175: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761178: { // 0x761178: 0f8400ffffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076117e: { // 0x76117e: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761181: { // 0x761181: e9f8feffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761186: { // 0x761186: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0076118a: { // 0x76118a: d9c1 FLD st1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0076118c: { // 0x76118c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076118e: { // 0x76118e: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761192: { // 0x761192: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761196: { // 0x761196: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761198: { // 0x761198: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076119b: { // 0x76119b: 7509 JNZ 0x007611a6
    if(integer::condition("JNZ",flags)) goto L007611a6;
  }
  L0076119d: { // 0x76119d: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076119f: { // 0x76119f: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L007611a4: { // 0x7611a4: eb0e JMP 0x007611b4
    goto L007611b4;
  }
  L007611a6: { // 0x7611a6: d8db FCOMP st3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L007611a8: { // 0x7611a8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611aa: { // 0x7611aa: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ad: { // 0x7611ad: 7405 JZ 0x007611b4
    if(integer::condition("JZ",flags)) goto L007611b4;
  }
  L007611af: { // 0x7611af: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L007611b4: { // 0x7611b4: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L007611b8: { // 0x7611b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611ba: { // 0x7611ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611bd: { // 0x7611bd: 7508 JNZ 0x007611c7
    if(integer::condition("JNZ",flags)) goto L007611c7;
  }
  L007611bf: { // 0x7611bf: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L007611c2: { // 0x7611c2: e9b7feffff JMP 0x0076107e
    goto L0076107e;
  }
  L007611c7: { // 0x7611c7: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L007611c9: { // 0x7611c9: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611cb: { // 0x7611cb: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ce: { // 0x7611ce: 0f84aafeffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L007611d4: { // 0x7611d4: e9a2feffff JMP 0x0076107b
    goto L0076107b;
  }
  L007611d9: { // 0x7611d9: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611db: { // 0x7611db: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611dd: { // 0x7611dd: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611df: { // 0x7611df: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L007611e3: { // 0x7611e3: e868980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737832u,op); flags=s.arithmetic_flags;
  }
  L007611e8: { // 0x7611e8: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L007611ec: { // 0x7611ec: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L007611f0: { // 0x7611f0: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L007611f2: { // 0x7611f2: e859980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737847u,op); flags=s.arithmetic_flags;
  }
  L007611f7: { // 0x7611f7: dd442468 FLD double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.load64(read64(m,address));
  }
  L007611fb: { // 0x7611fb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L007611fe: { // 0x7611fe: e84d980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737859u,op); flags=s.arithmetic_flags;
  }
  L00761203: { // 0x761203: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761207: { // 0x761207: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L00761209: { // 0x761209: e842980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737870u,op); flags=s.arithmetic_flags;
  }
  L0076120e: { // 0x76120e: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00761211: { // 0x761211: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00761213: { // 0x761213: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761214: { // 0x761214: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761215: { // 0x761215: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761216: { // 0x761216: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761218: { // 0x761218: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00761219: { // 0x761219: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0076121c: { // 0x76121c: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076121e: { // 0x76121e: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761220: { // 0x761220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761221: { // 0x761221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761222: { // 0x761222: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761224: { // 0x761224: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00761226: { // 0x761226: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761227: { // 0x761227: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761229: { // 0x761229: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076122a: { // 0x76122a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
    s.dx = m.r16((f.sp));
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
