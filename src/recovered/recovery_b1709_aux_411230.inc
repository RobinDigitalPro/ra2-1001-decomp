// Private exact411230 projection for inclusion inside child/surface.cpp anonymous namespace.
// Uses existing b566 aliases and invoke(m,s,f,actual_target,actual_continuation).
// Normal provider/ring validity is a separate preflight contract; no callback results.
void f_00011230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x411230: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x411234: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x411235: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x411237: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x411238: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x411239: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x41123d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x411240: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x411241: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x411243: ff505c CALL dword ptr [EAX + 0x5c]
    const std::uint32_t call_target=m.r32((s.ax+0x0000005cu));
    s.arithmetic_flags = flags;
    invoke(m,s,f,call_target,0x00411246u);
    flags = s.arithmetic_flags;
  }
  { // 0x411246: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  { // 0x411249: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x41124b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x41124d: ff5060 CALL dword ptr [EAX + 0x60]
    const std::uint32_t call_target=m.r32((s.ax+0x00000060u));
    s.arithmetic_flags = flags;
    invoke(m,s,f,call_target,0x00411250u);
    flags = s.arithmetic_flags;
  }
  { // 0x411250: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x411253: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x411256: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  { // 0x411258: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x41125a: 7203 JC 0x0041125f
    if(integer::condition("JC",flags)) goto L0041125f;
  }
  { // 0x41125c: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L0041125f: { // 0x41125f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x411260: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x411261: c20800 RET 0x8
    s.arithmetic_flags = flags;
    finish(m,s,f,8u); return;
  }
}
