void f_00361c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)op;
  { // 0x761c80: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx=m.r32(f.sp+0x8u);
  }
  { // 0x761c84: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x761c85: 8bf1 MOV ESI,ECX
    s.si=s.cx;
  }
  { // 0x761c87: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x761c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x761c89: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx=m.r32(f.sp+0x10u);
  }
  { // 0x761c8d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx=m.r32(s.si+0x14u);
  }
  { // 0x761c90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x761c91: 8b01 MOV EAX,dword ptr [ECX]
    s.ax=m.r32(s.cx);
  }
  { // 0x761c93: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags;
    invoke(m,s,f,m.r32(s.ax+0x5cu),0x761c96u);
    flags=s.arithmetic_flags;
  }
  { // 0x761c96: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx=m.r32(s.si+0x14u);
  }
  { // 0x761c99: 8bf8 MOV EDI,EAX
    s.di=s.ax;
  }
  { // 0x761c9b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax=m.r32(s.cx);
  }
  { // 0x761c9d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags;
    invoke(m,s,f,m.r32(s.ax+0x60u),0x761ca0u);
    flags=s.arithmetic_flags;
  }
  { // 0x761ca0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax=m.r32(s.si+0x10u);
  }
  { // 0x761ca3: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx=m.r32(s.si+0x1cu);
  }
  { // 0x761ca6: 03c7 ADD EAX,EDI
    s.ax=integer::add(s.ax,s.di,32,flags);
  }
  { // 0x761ca8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x761caa: 7203 JC 0x00761caf
    if(integer::condition("JC",flags)) goto L00761caf;
  }
  { // 0x761cac: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax=integer::sub(s.ax,m.r32(s.si+0x20u),32,flags);
  }
 L00761caf:
  { // 0x761caf: 5f POP EDI
    const auto value=f.pop(m); s.di=value;
  }
  { // 0x761cb0: 5e POP ESI
    const auto value=f.pop(m); s.si=value;
  }
  { // 0x761cb1: c20800 RET 0x8
    s.arithmetic_flags=flags;
    finish(m,s,f,8u);
    return;
  }
}