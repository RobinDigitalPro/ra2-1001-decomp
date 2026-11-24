void invoke(Memory&,State&,Frame&,unsigned,unsigned,const Operations&);
void f_0017eeb0(Memory&,State&,Frame&,const Operations&);
void f_0007b190(Memory&,State&,Frame&,const Operations&);
void f_0017ece0(Memory&,State&,Frame&,const Operations&);
void f_0018a920(Memory&,State&,Frame&,const Operations&);
void f_0018be90(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0002d3e0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00176620(Memory&,State&,Frame&,const Operations&);
void f_00157340(Memory&,State&,Frame&,const Operations&);
void f_00157280(Memory&,State&,Frame&,const Operations&);
void f_0002add0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0002d4a0(Memory&,State&,Frame&,const Operations&);
void f_0002d050(Memory&,State&,Frame&,const Operations&);

void f_0017eeb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057eeb0: { // 0x57eeb0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0057eeb1: { // 0x57eeb1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0057eeb3: { // 0x57eeb3: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L0057eeb6: { // 0x57eeb6: 83ec4c SUB ESP,0x4c
    f.sp = integer::sub(f.sp,0x0000004cu,32,flags);
  }
  L0057eeb9: { // 0x57eeb9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0057eeba: { // 0x57eeba: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0057eebc: { // 0x57eebc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057eebd: { // 0x57eebd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057eebe: { // 0x57eebe: 8b8380010000 MOV EAX,dword ptr [EBX + 0x180]
    s.ax = m.r32((s.bx+0x00000180u));
  }
  L0057eec4: { // 0x57eec4: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L0057eec8: { // 0x57eec8: 0faf8384010000 IMUL EAX,dword ptr [EBX + 0x184]
    s.ax = integer::imul(s.ax,m.r32((s.bx+0x00000184u)),32,flags);
  }
  L0057eecf: { // 0x57eecf: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0057eed1: { // 0x57eed1: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  L0057eed4: { // 0x57eed4: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0057eed6: { // 0x57eed6: 7f05 JG 0x0057eedd
    if(integer::condition("JG",flags)) goto L0057eedd;
  }
  L0057eed8: { // 0x57eed8: be64000000 MOV ESI,0x64
    s.si = 0x00000064u;
  }
  L0057eedd: { // 0x57eedd: 8d04f500000000 LEA EAX,[ESI*0x8 + 0x0]
    s.ax = ((s.si * 0x00000008u)+0x00000000u);
  }
  L0057eee4: { // 0x57eee4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057eee5: { // 0x57eee5: e86dea1e00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5762794u,op); flags=s.arithmetic_flags;
  }
  L0057eeea: { // 0x57eeea: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057eeec: { // 0x57eeec: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057eeef: { // 0x57eeef: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057eef1: { // 0x57eef1: 740b JZ 0x0057eefe
    if(integer::condition("JZ",flags)) goto L0057eefe;
  }
  L0057eef3: { // 0x57eef3: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0057eef4: { // 0x57eef4: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0057eef8: { // 0x57eef8: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L0057eefc: { // 0x57eefc: eb04 JMP 0x0057ef02
    goto L0057ef02;
  }
  L0057eefe: { // 0x57eefe: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L0057ef02: { // 0x57ef02: 6a14 PUSH 0x14
    f.push(m,0x00000014u);
  }
  L0057ef04: { // 0x57ef04: e84eea1e00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5762825u,op); flags=s.arithmetic_flags;
  }
  L0057ef09: { // 0x57ef09: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0057ef0b: { // 0x57ef0b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057ef0e: { // 0x57ef0e: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L0057ef10: { // 0x57ef10: 7455 JZ 0x0057ef67
    if(integer::condition("JZ",flags)) goto L0057ef67;
  }
  L0057ef12: { // 0x57ef12: 8b8380010000 MOV EAX,dword ptr [EBX + 0x180]
    s.ax = m.r32((s.bx+0x00000180u));
  }
  L0057ef18: { // 0x57ef18: 0faf8384010000 IMUL EAX,dword ptr [EBX + 0x184]
    s.ax = integer::imul(s.ax,m.r32((s.bx+0x00000184u)),32,flags);
  }
  L0057ef1f: { // 0x57ef1f: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0057ef21: { // 0x57ef21: 83f864 CMP EAX,0x64
    (void)integer::sub(s.ax,0x00000064u,32,flags);
  }
  L0057ef24: { // 0x57ef24: 7f05 JG 0x0057ef2b
    if(integer::condition("JG",flags)) goto L0057ef2b;
  }
  L0057ef26: { // 0x57ef26: b864000000 MOV EAX,0x64
    s.ax = 0x00000064u;
  }
  L0057ef2b: { // 0x57ef2b: 8d0c8504000000 LEA ECX,[EAX*0x4 + 0x4]
    s.cx = ((s.ax * 0x00000004u)+0x00000004u);
  }
  L0057ef32: { // 0x57ef32: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0057ef35: { // 0x57ef35: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057ef36: { // 0x57ef36: c74610ffffffff MOV dword ptr [ESI + 0x10],0xffffffff
    m.w32((s.si+0x00000010u), 0xffffffffu);
  }
  L0057ef3d: { // 0x57ef3d: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  L0057ef3f: { // 0x57ef3f: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0057ef42: { // 0x57ef42: e810ea1e00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5762887u,op); flags=s.arithmetic_flags;
  }
  L0057ef47: { // 0x57ef47: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0057ef4a: { // 0x57ef4a: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0057ef4d: { // 0x57ef4d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057ef50: { // 0x57ef50: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057ef52: { // 0x57ef52: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057ef54: { // 0x57ef54: 7c13 JL 0x0057ef69
    if(integer::condition("JL",flags)) goto L0057ef69;
  }
  L0057ef56: { // 0x57ef56: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057ef59: { // 0x57ef59: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057ef5a: { // 0x57ef5a: 897c82fc MOV dword ptr [EDX + EAX*0x4 + -0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000004u)-0x00000004u), s.di);
  }
  L0057ef5e: { // 0x57ef5e: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0057ef61: { // 0x57ef61: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057ef63: { // 0x57ef63: 7ef1 JLE 0x0057ef56
    if(integer::condition("JLE",flags)) goto L0057ef56;
  }
  L0057ef65: { // 0x57ef65: eb02 JMP 0x0057ef69
    goto L0057ef69;
  }
  L0057ef67: { // 0x57ef67: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057ef69: { // 0x57ef69: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0057ef6c: { // 0x57ef6c: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0057ef70: { // 0x57ef70: c644240f01 MOV byte ptr [ESP + 0xf],0x1
    m.w8((f.sp+0x0000000fu), 0x00000001u);
  }
  L0057ef75: { // 0x57ef75: c744244800000000 MOV dword ptr [ESP + 0x48],0x0
    m.w32((f.sp+0x00000048u), 0x00000000u);
  }
  L0057ef7d: { // 0x57ef7d: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0057ef7f: { // 0x57ef7f: c744244c00000000 MOV dword ptr [ESP + 0x4c],0x0
    m.w32((f.sp+0x0000004cu), 0x00000000u);
  }
  L0057ef87: { // 0x57ef87: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057ef89: { // 0x57ef89: b800020000 MOV EAX,0x200
    s.ax = 0x00000200u;
  }
  L0057ef8e: { // 0x57ef8e: 7412 JZ 0x0057efa2
    if(integer::condition("JZ",flags)) goto L0057efa2;
  }
  L0057ef90: { // 0x57ef90: c744244800000000 MOV dword ptr [ESP + 0x48],0x0
    m.w32((f.sp+0x00000048u), 0x00000000u);
  }
  L0057ef98: { // 0x57ef98: c744244c00000000 MOV dword ptr [ESP + 0x4c],0x0
    m.w32((f.sp+0x0000004cu), 0x00000000u);
  }
  L0057efa0: { // 0x57efa0: eb15 JMP 0x0057efb7
    goto L0057efb7;
  }
  L0057efa2: { // 0x57efa2: 394308 CMP dword ptr [EBX + 0x8],EAX
    (void)integer::sub(m.r32((s.bx+0x00000008u)),s.ax,32,flags);
  }
  L0057efa5: { // 0x57efa5: 7410 JZ 0x0057efb7
    if(integer::condition("JZ",flags)) goto L0057efb7;
  }
  L0057efa7: { // 0x57efa7: c7442448182d4454 MOV dword ptr [ESP + 0x48],0x54442d18
    m.w32((f.sp+0x00000048u), 0x54442d18u);
  }
  L0057efaf: { // 0x57efaf: c744244cfb210940 MOV dword ptr [ESP + 0x4c],0x400921fb
    m.w32((f.sp+0x0000004cu), 0x400921fbu);
  }
  L0057efb7: { // 0x57efb7: 397b04 CMP dword ptr [EBX + 0x4],EDI
    (void)integer::sub(m.r32((s.bx+0x00000004u)),s.di,32,flags);
  }
  L0057efba: { // 0x57efba: 7412 JZ 0x0057efce
    if(integer::condition("JZ",flags)) goto L0057efce;
  }
  L0057efbc: { // 0x57efbc: c7442448d221337f MOV dword ptr [ESP + 0x48],0x7f3321d2
    m.w32((f.sp+0x00000048u), 0x7f3321d2u);
  }
  L0057efc4: { // 0x57efc4: c744244c7cd91240 MOV dword ptr [ESP + 0x4c],0x4012d97c
    m.w32((f.sp+0x0000004cu), 0x4012d97cu);
  }
  L0057efcc: { // 0x57efcc: eb15 JMP 0x0057efe3
    goto L0057efe3;
  }
  L0057efce: { // 0x57efce: 39430c CMP dword ptr [EBX + 0xc],EAX
    (void)integer::sub(m.r32((s.bx+0x0000000cu)),s.ax,32,flags);
  }
  L0057efd1: { // 0x57efd1: 7410 JZ 0x0057efe3
    if(integer::condition("JZ",flags)) goto L0057efe3;
  }
  L0057efd3: { // 0x57efd3: c7442448182d4454 MOV dword ptr [ESP + 0x48],0x54442d18
    m.w32((f.sp+0x00000048u), 0x54442d18u);
  }
  L0057efdb: { // 0x57efdb: c744244cfb21f93f MOV dword ptr [ESP + 0x4c],0x3ff921fb
    m.w32((f.sp+0x0000004cu), 0x3ff921fbu);
  }
  L0057efe3: { // 0x57efe3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057efe8: { // 0x57efe8: e85383fdff CALL 0x00557340
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557340u,5763053u,op); flags=s.arithmetic_flags;
  }
  L0057efed: { // 0x57efed: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057eff2: { // 0x57eff2: e88982fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5763063u,op); flags=s.arithmetic_flags;
  }
  L0057eff7: { // 0x57eff7: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057eff9: { // 0x57eff9: 7435 JZ 0x0057f030
    if(integer::condition("JZ",flags)) goto L0057f030;
  }
  L0057effb: { // 0x57effb: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L0057effe: { // 0x57effe: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0057f002: { // 0x57f002: 0fbf44242e MOVSX EAX,word ptr [ESP + 0x2e]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000002eu)),16));
  }
  L0057f007: { // 0x57f007: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057f00e: { // 0x57f00e: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057f011: { // 0x57f011: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f013: { // 0x57f013: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057f018: { // 0x57f018: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0057f01b: { // 0x57f01b: a13c86a500 MOV EAX,[0x00a5863c]
    s.ax = m.r32((0x00a5863cu));
  }
  L0057f020: { // 0x57f020: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057f023: { // 0x57f023: 897c023c MOV dword ptr [EDX + EAX*0x1 + 0x3c],EDI
    m.w32((s.dx+(s.ax * 0x00000001u)+0x0000003cu), s.di);
  }
  L0057f027: { // 0x57f027: e85482fdff CALL 0x00557280
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557280u,5763116u,op); flags=s.arithmetic_flags;
  }
  L0057f02c: { // 0x57f02c: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057f02e: { // 0x57f02e: 75cb JNZ 0x0057effb
    if(integer::condition("JNZ",flags)) goto L0057effb;
  }
  L0057f030: { // 0x57f030: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L0057f033: { // 0x57f033: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057f034: { // 0x57f034: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0057f038: { // 0x57f038: e8a3fcffff CALL 0x0057ece0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0057ece0u,5763133u,op); flags=s.arithmetic_flags;
  }
  L0057f03d: { // 0x57f03d: 8b4810 MOV ECX,dword ptr [EAX + 0x10]
    s.cx = m.r32((s.ax+0x00000010u));
  }
  L0057f040: { // 0x57f040: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0057f044: { // 0x57f044: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057f046: { // 0x57f046: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0057f04a: { // 0x57f04a: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L0057f04e: { // 0x57f04e: 0f8ec0010000 JLE 0x0057f214
    if(integer::condition("JLE",flags)) goto L0057f214;
  }
  L0057f054: { // 0x57f054: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L0057f058: { // 0x57f058: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0057f05c: { // 0x57f05c: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057f060: { // 0x57f060: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0057f063: { // 0x57f063: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0057f065: { // 0x57f065: 8b0488 MOV EAX,dword ptr [EAX + ECX*0x4]
    s.ax = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057f068: { // 0x57f068: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0057f06c: { // 0x57f06c: 0fbf4c2426 MOVSX ECX,word ptr [ESP + 0x26]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000026u)),16));
  }
  L0057f071: { // 0x57f071: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057f074: { // 0x57f074: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0057f076: { // 0x57f076: 0f8c7d010000 JL 0x0057f1f9
    if(integer::condition("JL",flags)) goto L0057f1f9;
  }
  L0057f07c: { // 0x57f07c: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L0057f07f: { // 0x57f07f: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0057f081: { // 0x57f081: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057f083: { // 0x57f083: 0f8d6d010000 JGE 0x0057f1f6
    if(integer::condition("JGE",flags)) goto L0057f1f6;
  }
  L0057f089: { // 0x57f089: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0057f08c: { // 0x57f08c: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L0057f08f: { // 0x57f08f: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0057f091: { // 0x57f091: 0f8c62010000 JL 0x0057f1f9
    if(integer::condition("JL",flags)) goto L0057f1f9;
  }
  L0057f097: { // 0x57f097: 8b5b0c MOV EBX,dword ptr [EBX + 0xc]
    s.bx = m.r32((s.bx+0x0000000cu));
  }
  L0057f09a: { // 0x57f09a: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0057f09c: { // 0x57f09c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057f09e: { // 0x57f09e: 0f8d52010000 JGE 0x0057f1f6
    if(integer::condition("JGE",flags)) goto L0057f1f6;
  }
  L0057f0a4: { // 0x57f0a4: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0057f0a8: { // 0x57f0a8: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0057f0aa: { // 0x57f0aa: 8b5514 MOV EDX,dword ptr [EBP + 0x14]
    s.dx = m.r32((s.bp+0x00000014u));
  }
  L0057f0ad: { // 0x57f0ad: 0fbf1a MOVSX EBX,word ptr [EDX]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0057f0b0: { // 0x57f0b0: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L0057f0b2: { // 0x57f0b2: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0057f0b4: { // 0x57f0b4: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L0057f0b8: { // 0x57f0b8: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0057f0ba: { // 0x57f0ba: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L0057f0be: { // 0x57f0be: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0057f0c0: { // 0x57f0c0: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0057f0c4: { // 0x57f0c4: 0f84ff000000 JZ 0x0057f1c9
    if(integer::condition("JZ",flags)) goto L0057f1c9;
  }
  L0057f0ca: { // 0x57f0ca: db44242c FILD dword ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0057f0ce: { // 0x57f0ce: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057f0d1: { // 0x57f0d1: da742430 FIDIV dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0057f0d5: { // 0x57f0d5: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0057f0d7: { // 0x57f0d7: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057f0da: { // 0x57f0da: e841b1f3ff CALL 0x004ba220
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba220u,5763295u,op); flags=s.arithmetic_flags;
  }
  L0057f0df: { // 0x57f0df: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057f0e2: { // 0x57f0e2: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0057f0e4: { // 0x57f0e4: 7d06 JGE 0x0057f0ec
    if(integer::condition("JGE",flags)) goto L0057f0ec;
  }
  L0057f0e6: { // 0x57f0e6: dc0558817800 FADD double ptr [0x00788158]
    const auto address=(0x00788158u);
    s.fp.add64(read64(m,address));
  }
  L0057f0ec: { // 0x57f0ec: dc642448 FSUB double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.subtract64(read64(m,address));
  }
  L0057f0f0: { // 0x57f0f0: d9e1 FABS
    numeric_b88::detail::reg<0xd9e1>(s.fp);
  }
  L0057f0f2: { // 0x57f0f2: dc15b8797800 FCOM double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057f0f8: { // 0x57f0f8: dd542440 FST double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057f0fc: { // 0x57f0fc: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f0fe: { // 0x57f0fe: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057f101: { // 0x57f101: 7517 JNZ 0x0057f11a
    if(integer::condition("JNZ",flags)) goto L0057f11a;
  }
  L0057f103: { // 0x57f103: dc25b8797800 FSUB double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    s.fp.subtract64(read64(m,address));
  }
  L0057f109: { // 0x57f109: dc15b8797800 FCOM double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057f10f: { // 0x57f10f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f111: { // 0x57f111: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057f114: { // 0x57f114: 74ed JZ 0x0057f103
    if(integer::condition("JZ",flags)) goto L0057f103;
  }
  L0057f116: { // 0x57f116: dd542440 FST double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057f11a: { // 0x57f11a: dc1558817800 FCOM double ptr [0x00788158]
    const auto address=(0x00788158u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057f120: { // 0x57f120: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f122: { // 0x57f122: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057f125: { // 0x57f125: 750c JNZ 0x0057f133
    if(integer::condition("JNZ",flags)) goto L0057f133;
  }
  L0057f127: { // 0x57f127: dd05b8797800 FLD double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    s.fp.load64(read64(m,address));
  }
  L0057f12d: { // 0x57f12d: d8e1 FSUB st0,st1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L0057f12f: { // 0x57f12f: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057f133: { // 0x57f133: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f138: { // 0x57f138: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057f13a: { // 0x57f13a: e8a10c0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5763391u,op); flags=s.arithmetic_flags;
  }
  L0057f13f: { // 0x57f13f: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L0057f143: { // 0x57f143: c744243c00000000 MOV dword ptr [ESP + 0x3c],0x0
    m.w32((f.sp+0x0000003cu), 0x00000000u);
  }
  L0057f14b: { // 0x57f14b: df6c2438 FILD qword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f14f: { // 0x57f14f: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0057f153: { // 0x57f153: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0057f155: { // 0x57f155: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057f156: { // 0x57f156: 83c708 ADD EDI,0x8
    s.di = integer::add(s.di,0x00000008u,32,flags);
  }
  L0057f159: { // 0x57f159: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f15f: { // 0x57f15f: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L0057f163: { // 0x57f163: dc0db00c7900 FMUL double ptr [0x00790cb0]
    const auto address=(0x00790cb0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f169: { // 0x57f169: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0057f16b: { // 0x57f16b: dc0da80c7900 FMUL double ptr [0x00790ca8]
    const auto address=(0x00790ca8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f171: { // 0x57f171: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0057f175: { // 0x57f175: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0057f179: { // 0x57f179: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L0057f17d: { // 0x57f17d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057f17f: { // 0x57f17f: d95ffc FSTP float ptr [EDI + -0x4]
    const auto address=(s.di-0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0057f182: { // 0x57f182: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f184: { // 0x57f184: 8b5804 MOV EBX,dword ptr [EAX + 0x4]
    s.bx = m.r32((s.ax+0x00000004u));
  }
  L0057f187: { // 0x57f187: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057f188: { // 0x57f188: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L0057f18c: { // 0x57f18c: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L0057f18f: { // 0x57f18f: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057f191: { // 0x57f191: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057f193: { // 0x57f193: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057f195: { // 0x57f195: 735f JNC 0x0057f1f6
    if(integer::condition("JNC",flags)) goto L0057f1f6;
  }
  L0057f197: { // 0x57f197: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057f19a: { // 0x57f19a: 7638 JBE 0x0057f1d4
    if(integer::condition("JBE",flags)) goto L0057f1d4;
  }
  L0057f19c: { // 0x57f19c: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  L0057f19f: { // 0x57f19f: 8b1c97 MOV EBX,dword ptr [EDI + EDX*0x4]
    s.bx = m.r32((s.di+(s.dx * 0x00000004u)));
  }
  L0057f1a2: { // 0x57f1a2: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0057f1a5: { // 0x57f1a5: d85c2430 FCOMP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0057f1a9: { // 0x57f1a9: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f1ab: { // 0x57f1ab: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057f1ae: { // 0x57f1ae: 750c JNZ 0x0057f1bc
    if(integer::condition("JNZ",flags)) goto L0057f1bc;
  }
  L0057f1b0: { // 0x57f1b0: 891c8f MOV dword ptr [EDI + ECX*0x4],EBX
    m.w32((s.di+(s.cx * 0x00000004u)), s.bx);
  }
  L0057f1b3: { // 0x57f1b3: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057f1b5: { // 0x57f1b5: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057f1b7: { // 0x57f1b7: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057f1ba: { // 0x57f1ba: 77e0 JA 0x0057f19c
    if(integer::condition("JA",flags)) goto L0057f19c;
  }
  L0057f1bc: { // 0x57f1bc: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0057f1bf: { // 0x57f1bf: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0057f1c3: { // 0x57f1c3: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0057f1c7: { // 0x57f1c7: eb0e JMP 0x0057f1d7
    goto L0057f1d7;
  }
  L0057f1c9: { // 0x57f1c9: dd0530667800 FLD double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.load64(read64(m,address));
  }
  L0057f1cf: { // 0x57f1cf: e918ffffff JMP 0x0057f0ec
    goto L0057f0ec;
  }
  L0057f1d4: { // 0x57f1d4: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0057f1d7: { // 0x57f1d7: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057f1da: { // 0x57f1da: 89048a MOV dword ptr [EDX + ECX*0x4],EAX
    m.w32((s.dx+(s.cx * 0x00000004u)), s.ax);
  }
  L0057f1dd: { // 0x57f1dd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057f1df: { // 0x57f1df: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L0057f1e2: { // 0x57f1e2: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0057f1e3: { // 0x57f1e3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057f1e5: { // 0x57f1e5: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0057f1e7: { // 0x57f1e7: 7603 JBE 0x0057f1ec
    if(integer::condition("JBE",flags)) goto L0057f1ec;
  }
  L0057f1e9: { // 0x57f1e9: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0057f1ec: { // 0x57f1ec: 3b4610 CMP EAX,dword ptr [ESI + 0x10]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L0057f1ef: { // 0x57f1ef: 7308 JNC 0x0057f1f9
    if(integer::condition("JNC",flags)) goto L0057f1f9;
  }
  L0057f1f1: { // 0x57f1f1: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0057f1f4: { // 0x57f1f4: eb03 JMP 0x0057f1f9
    goto L0057f1f9;
  }
  L0057f1f6: { // 0x57f1f6: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L0057f1f9: { // 0x57f1f9: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0057f1fd: { // 0x57f1fd: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0057f201: { // 0x57f201: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0057f202: { // 0x57f202: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057f204: { // 0x57f204: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0057f208: { // 0x57f208: 0f8c4afeffff JL 0x0057f058
    if(integer::condition("JL",flags)) goto L0057f058;
  }
  L0057f20e: { // 0x57f20e: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0057f212: { // 0x57f212: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057f214: { // 0x57f214: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057f216: { // 0x57f216: 7408 JZ 0x0057f220
    if(integer::condition("JZ",flags)) goto L0057f220;
  }
  L0057f218: { // 0x57f218: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0057f21a: { // 0x57f21a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057f21c: { // 0x57f21c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057f21e: { // 0x57f21e: ff12 CALL dword ptr [EDX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx)),5763616u,op); flags=s.arithmetic_flags;
  }
  L0057f220: { // 0x57f220: d9ed FLDLN2
    numeric_b88::detail::reg<0xd9ed>(s.fp);
  }
  L0057f222: { // 0x57f222: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057f226: { // 0x57f226: d9f1 FYL2X
    numeric_b88::detail::reg<0xd9f1>(s.fp);
  }
  L0057f228: { // 0x57f228: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L0057f22e: { // 0x57f22e: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L0057f230: { // 0x57f230: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f232: { // 0x57f232: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057f235: { // 0x57f235: 7508 JNZ 0x0057f23f
    if(integer::condition("JNZ",flags)) goto L0057f23f;
  }
  L0057f237: { // 0x57f237: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057f239: { // 0x57f239: dd0508577800 FLD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.load64(read64(m,address));
  }
  L0057f23f: { // 0x57f23f: dc3d08577800 FDIVR double ptr [0x00785708]
    const auto address=(0x00785708u);
    reverse_divide64(s.fp,read64(m,address));
  }
  L0057f245: { // 0x57f245: d84d0c FMUL float ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L0057f248: { // 0x57f248: d83df8677800 FDIVR float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    reverse_divide32(s.fp,m.r32(address));
  }
  L0057f24e: { // 0x57f24e: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
  L0057f254: { // 0x57f254: e8f7b71e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5763673u,op); flags=s.arithmetic_flags;
  }
  L0057f259: { // 0x57f259: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0057f25d: { // 0x57f25d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0057f25e: { // 0x57f25e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0057f260: { // 0x57f260: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0057f262: { // 0x57f262: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0057f264: { // 0x57f264: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057f266: { // 0x57f266: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L0057f269: { // 0x57f269: 895c2444 MOV dword ptr [ESP + 0x44],EBX
    m.w32((f.sp+0x00000044u), s.bx);
  }
  L0057f26d: { // 0x57f26d: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0057f271: { // 0x57f271: df6c2440 FILD qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f275: { // 0x57f275: dd5c2450 FSTP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057f279: { // 0x57f279: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f27e: { // 0x57f27e: e85d0b0b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5763715u,op); flags=s.arithmetic_flags;
  }
  L0057f283: { // 0x57f283: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0057f287: { // 0x57f287: 895c2444 MOV dword ptr [ESP + 0x44],EBX
    m.w32((f.sp+0x00000044u), s.bx);
  }
  L0057f28b: { // 0x57f28b: df6c2440 FILD qword ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f28f: { // 0x57f28f: dc4c2450 FMUL double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f293: { // 0x57f293: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f299: { // 0x57f299: e8b2b71e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5763742u,op); flags=s.arithmetic_flags;
  }
  L0057f29e: { // 0x57f29e: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057f2a0: { // 0x57f2a0: 77d7 JA 0x0057f279
    if(integer::condition("JA",flags)) goto L0057f279;
  }
  L0057f2a2: { // 0x57f2a2: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0057f2a6: { // 0x57f2a6: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0057f2a8: { // 0x57f2a8: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0057f2ac: { // 0x57f2ac: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f2ae: { // 0x57f2ae: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057f2b0: { // 0x57f2b0: 7508 JNZ 0x0057f2ba
    if(integer::condition("JNZ",flags)) goto L0057f2ba;
  }
  L0057f2b2: { // 0x57f2b2: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0057f2b4: { // 0x57f2b4: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0057f2b8: { // 0x57f2b8: eb28 JMP 0x0057f2e2
    goto L0057f2e2;
  }
  L0057f2ba: { // 0x57f2ba: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057f2bd: { // 0x57f2bd: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057f2bf: { // 0x57f2bf: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057f2c2: { // 0x57f2c2: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057f2c5: { // 0x57f2c5: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057f2c8: { // 0x57f2c8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057f2ca: { // 0x57f2ca: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057f2cd: { // 0x57f2cd: 891c90 MOV dword ptr [EAX + EDX*0x4],EBX
    m.w32((s.ax+(s.dx * 0x00000004u)), s.bx);
  }
  L0057f2d0: { // 0x57f2d0: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f2d2: { // 0x57f2d2: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057f2d3: { // 0x57f2d3: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057f2d5: { // 0x57f2d5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057f2d7: { // 0x57f2d7: e8b4cb0000 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5763804u,op); flags=s.arithmetic_flags;
  }
  L0057f2dc: { // 0x57f2dc: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0057f2e0: { // 0x57f2e0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057f2e2: { // 0x57f2e2: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0057f2e6: { // 0x57f2e6: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0057f2ea: { // 0x57f2ea: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057f2ec: { // 0x57f2ec: 0f8e93030000 JLE 0x0057f685
    if(integer::condition("JLE",flags)) goto L0057f685;
  }
  L0057f2f2: { // 0x57f2f2: eb04 JMP 0x0057f2f8
    goto L0057f2f8;
  }
  L0057f2f4: { // 0x57f2f4: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0057f2f8: { // 0x57f2f8: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L0057f2fc: { // 0x57f2fc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057f2fe: { // 0x57f2fe: 0f8481030000 JZ 0x0057f685
    if(integer::condition("JZ",flags)) goto L0057f685;
  }
  L0057f304: { // 0x57f304: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057f306: { // 0x57f306: 0f8479030000 JZ 0x0057f685
    if(integer::condition("JZ",flags)) goto L0057f685;
  }
  L0057f30c: { // 0x57f30c: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0057f310: { // 0x57f310: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057f317: { // 0x57f317: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0057f31a: { // 0x57f31a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057f31c: { // 0x57f31c: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057f322: { // 0x57f322: 8d3c80 LEA EDI,[EAX + EAX*0x4]
    s.di = (s.ax+(s.ax * 0x00000004u));
  }
  L0057f325: { // 0x57f325: c1e704 SHL EDI,0x4
    s.di = integer::shift(s.di,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057f328: { // 0x57f328: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L0057f32a: { // 0x57f32a: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  L0057f32d: { // 0x57f32d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057f32f: { // 0x57f32f: 7524 JNZ 0x0057f355
    if(integer::condition("JNZ",flags)) goto L0057f355;
  }
  L0057f331: { // 0x57f331: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057f332: { // 0x57f332: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057f337: { // 0x57f337: e8c461fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5763900u,op); flags=s.arithmetic_flags;
  }
  L0057f33c: { // 0x57f33c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057f33e: { // 0x57f33e: e84dbeefff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5763907u,op); flags=s.arithmetic_flags;
  }
  L0057f343: { // 0x57f343: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057f345: { // 0x57f345: 740a JZ 0x0057f351
    if(integer::condition("JZ",flags)) goto L0057f351;
  }
  L0057f347: { // 0x57f347: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0057f34a: { // 0x57f34a: c6474b01 MOV byte ptr [EDI + 0x4b],0x1
    m.w8((s.di+0x0000004bu), 0x00000001u);
  }
  L0057f34e: { // 0x57f34e: 894738 MOV dword ptr [EDI + 0x38],EAX
    m.w32((s.di+0x00000038u), s.ax);
  }
  L0057f351: { // 0x57f351: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0057f355: { // 0x57f355: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0057f359: { // 0x57f359: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L0057f35d: { // 0x57f35d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0057f35f: { // 0x57f35f: 8d14fa LEA EDX,[EDX + EDI*0x8]
    s.dx = (s.dx+(s.di * 0x00000008u));
  }
  L0057f362: { // 0x57f362: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0057f366: { // 0x57f366: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0057f36a: { // 0x57f36a: eb04 JMP 0x0057f370
    goto L0057f370;
  }
  L0057f36c: { // 0x57f36c: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0057f370: { // 0x57f370: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  L0057f373: { // 0x57f373: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L0057f377: { // 0x57f377: 8d0485a09d8300 LEA EAX,[EAX*0x4 + 0x839da0]
    s.ax = ((s.ax * 0x00000004u)+0x00839da0u);
  }
  L0057f37e: { // 0x57f37e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057f37f: { // 0x57f37f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0057f380: { // 0x57f380: e84bbaeaff CALL 0x0042add0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042add0u,5763973u,op); flags=s.arithmetic_flags;
  }
  L0057f385: { // 0x57f385: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0057f387: { // 0x57f387: 8b3d3486a500 MOV EDI,dword ptr [0x00a58634]
    s.di = m.r32((0x00a58634u));
  }
  L0057f38d: { // 0x57f38d: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0057f391: { // 0x57f391: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0057f395: { // 0x57f395: 0fbf542432 MOVSX EDX,word ptr [ESP + 0x32]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000032u)),16));
  }
  L0057f39a: { // 0x57f39a: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057f39d: { // 0x57f39d: 8d040a LEA EAX,[EDX + ECX*0x1]
    s.ax = (s.dx+(s.cx * 0x00000001u));
  }
  L0057f3a0: { // 0x57f3a0: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057f3a2: { // 0x57f3a2: 0f8e62020000 JLE 0x0057f60a
    if(integer::condition("JLE",flags)) goto L0057f60a;
  }
  L0057f3a8: { // 0x57f3a8: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0057f3aa: { // 0x57f3aa: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0057f3ac: { // 0x57f3ac: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0057f3ae: { // 0x57f3ae: 0f8d56020000 JGE 0x0057f60a
    if(integer::condition("JGE",flags)) goto L0057f60a;
  }
  L0057f3b4: { // 0x57f3b4: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0057f3b6: { // 0x57f3b6: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0057f3b8: { // 0x57f3b8: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0057f3ba: { // 0x57f3ba: 0f8d4a020000 JGE 0x0057f60a
    if(integer::condition("JGE",flags)) goto L0057f60a;
  }
  L0057f3c0: { // 0x57f3c0: 3b053886a500 CMP EAX,dword ptr [0x00a58638]
    (void)integer::sub(s.ax,m.r32((0x00a58638u)),32,flags);
  }
  L0057f3c6: { // 0x57f3c6: 0f8f3e020000 JG 0x0057f60a
    if(integer::condition("JG",flags)) goto L0057f60a;
  }
  L0057f3cc: { // 0x57f3cc: 8b3d3c86a500 MOV EDI,dword ptr [0x00a5863c]
    s.di = m.r32((0x00a5863cu));
  }
  L0057f3d2: { // 0x57f3d2: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057f3d4: { // 0x57f3d4: 0f8423020000 JZ 0x0057f5fd
    if(integer::condition("JZ",flags)) goto L0057f5fd;
  }
  L0057f3da: { // 0x57f3da: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0057f3dc: { // 0x57f3dc: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057f3e3: { // 0x57f3e3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f3e5: { // 0x57f3e5: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057f3e8: { // 0x57f3e8: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057f3eb: { // 0x57f3eb: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0057f3ed: { // 0x57f3ed: 8b5838 MOV EBX,dword ptr [EAX + 0x38]
    s.bx = m.r32((s.ax+0x00000038u));
  }
  L0057f3f0: { // 0x57f3f0: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0057f3f2: { // 0x57f3f2: 0f85de010000 JNZ 0x0057f5d6
    if(integer::condition("JNZ",flags)) goto L0057f5d6;
  }
  L0057f3f8: { // 0x57f3f8: 8b403c MOV EAX,dword ptr [EAX + 0x3c]
    s.ax = m.r32((s.ax+0x0000003cu));
  }
  L0057f3fb: { // 0x57f3fb: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0057f3fe: { // 0x57f3fe: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0057f400: { // 0x57f400: 0f84d0010000 JZ 0x0057f5d6
    if(integer::condition("JZ",flags)) goto L0057f5d6;
  }
  L0057f406: { // 0x57f406: 8b4510 MOV EAX,dword ptr [EBP + 0x10]
    s.ax = m.r32((s.bp+0x00000010u));
  }
  L0057f409: { // 0x57f409: 8b18 MOV EBX,dword ptr [EAX]
    s.bx = m.r32((s.ax));
  }
  L0057f40b: { // 0x57f40b: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057f40d: { // 0x57f40d: 0f8cc3010000 JL 0x0057f5d6
    if(integer::condition("JL",flags)) goto L0057f5d6;
  }
  L0057f413: { // 0x57f413: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L0057f416: { // 0x57f416: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L0057f418: { // 0x57f418: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057f41a: { // 0x57f41a: 0f8db0010000 JGE 0x0057f5d0
    if(integer::condition("JGE",flags)) goto L0057f5d0;
  }
  L0057f420: { // 0x57f420: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0057f423: { // 0x57f423: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0057f425: { // 0x57f425: 0f8ca5010000 JL 0x0057f5d0
    if(integer::condition("JL",flags)) goto L0057f5d0;
  }
  L0057f42b: { // 0x57f42b: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0057f42e: { // 0x57f42e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f430: { // 0x57f430: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0057f432: { // 0x57f432: 0f8d98010000 JGE 0x0057f5d0
    if(integer::condition("JGE",flags)) goto L0057f5d0;
  }
  L0057f438: { // 0x57f438: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0057f43c: { // 0x57f43c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057f43d: { // 0x57f43d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0057f442: { // 0x57f442: e8b960fcff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5764167u,op); flags=s.arithmetic_flags;
  }
  L0057f447: { // 0x57f447: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0057f449: { // 0x57f449: e842bdefff CALL 0x0047b190
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b190u,5764174u,op); flags=s.arithmetic_flags;
  }
  L0057f44e: { // 0x57f44e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057f450: { // 0x57f450: 0f847a010000 JZ 0x0057f5d0
    if(integer::condition("JZ",flags)) goto L0057f5d0;
  }
  L0057f456: { // 0x57f456: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L0057f45a: { // 0x57f45a: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0057f45e: { // 0x57f45e: 8b4d14 MOV ECX,dword ptr [EBP + 0x14]
    s.cx = m.r32((s.bp+0x00000014u));
  }
  L0057f461: { // 0x57f461: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0057f463: { // 0x57f463: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0057f466: { // 0x57f466: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057f469: { // 0x57f469: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0057f46d: { // 0x57f46d: 0fbf4c2416 MOVSX ECX,word ptr [ESP + 0x16]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0057f472: { // 0x57f472: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0057f474: { // 0x57f474: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0057f476: { // 0x57f476: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057f478: { // 0x57f478: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L0057f47c: { // 0x57f47c: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0057f480: { // 0x57f480: 0f843f010000 JZ 0x0057f5c5
    if(integer::condition("JZ",flags)) goto L0057f5c5;
  }
  L0057f486: { // 0x57f486: db442430 FILD dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load_integer32(m.r32(address));
  }
  L0057f48a: { // 0x57f48a: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057f48d: { // 0x57f48d: da742430 FIDIV dword ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0057f491: { // 0x57f491: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0057f493: { // 0x57f493: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057f496: { // 0x57f496: e885adf3ff CALL 0x004ba220
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba220u,5764251u,op); flags=s.arithmetic_flags;
  }
  L0057f49b: { // 0x57f49b: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0057f49e: { // 0x57f49e: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057f4a0: { // 0x57f4a0: 7d06 JGE 0x0057f4a8
    if(integer::condition("JGE",flags)) goto L0057f4a8;
  }
  L0057f4a2: { // 0x57f4a2: dc0558817800 FADD double ptr [0x00788158]
    const auto address=(0x00788158u);
    s.fp.add64(read64(m,address));
  }
  L0057f4a8: { // 0x57f4a8: dc642448 FSUB double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.subtract64(read64(m,address));
  }
  L0057f4ac: { // 0x57f4ac: d9e1 FABS
    numeric_b88::detail::reg<0xd9e1>(s.fp);
  }
  L0057f4ae: { // 0x57f4ae: dc15b8797800 FCOM double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057f4b4: { // 0x57f4b4: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057f4b8: { // 0x57f4b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f4ba: { // 0x57f4ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057f4bd: { // 0x57f4bd: 7517 JNZ 0x0057f4d6
    if(integer::condition("JNZ",flags)) goto L0057f4d6;
  }
  L0057f4bf: { // 0x57f4bf: dc25b8797800 FSUB double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    s.fp.subtract64(read64(m,address));
  }
  L0057f4c5: { // 0x57f4c5: dc15b8797800 FCOM double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057f4cb: { // 0x57f4cb: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f4cd: { // 0x57f4cd: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0057f4d0: { // 0x57f4d0: 74ed JZ 0x0057f4bf
    if(integer::condition("JZ",flags)) goto L0057f4bf;
  }
  L0057f4d2: { // 0x57f4d2: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057f4d6: { // 0x57f4d6: dc1558817800 FCOM double ptr [0x00788158]
    const auto address=(0x00788158u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057f4dc: { // 0x57f4dc: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f4de: { // 0x57f4de: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057f4e1: { // 0x57f4e1: 750c JNZ 0x0057f4ef
    if(integer::condition("JNZ",flags)) goto L0057f4ef;
  }
  L0057f4e3: { // 0x57f4e3: dd05b8797800 FLD double ptr [0x007879b8]
    const auto address=(0x007879b8u);
    s.fp.load64(read64(m,address));
  }
  L0057f4e9: { // 0x57f4e9: d8e1 FSUB st0,st1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L0057f4eb: { // 0x57f4eb: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057f4ef: { // 0x57f4ef: b9d881a500 MOV ECX,0xa581d8
    s.cx = 0x00a581d8u;
  }
  L0057f4f4: { // 0x57f4f4: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057f4f6: { // 0x57f4f6: e8e5080b00 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,5764347u,op); flags=s.arithmetic_flags;
  }
  L0057f4fb: { // 0x57f4fb: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0057f4ff: { // 0x57f4ff: c744245400000000 MOV dword ptr [ESP + 0x54],0x0
    m.w32((f.sp+0x00000054u), 0x00000000u);
  }
  L0057f507: { // 0x57f507: df6c2450 FILD qword ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    ra2::platform::x87_scalar_b46::load_integer64(s.fp,read64(m,address));
  }
  L0057f50b: { // 0x57f50b: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0057f510: { // 0x57f510: dc0db00d7900 FMUL double ptr [0x00790db0]
    const auto address=(0x00790db0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f516: { // 0x57f516: dd442430 FLD double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L0057f51a: { // 0x57f51a: dc0db00c7900 FMUL double ptr [0x00790cb0]
    const auto address=(0x00790cb0u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f520: { // 0x57f520: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0057f522: { // 0x57f522: dc0da80c7900 FMUL double ptr [0x00790ca8]
    const auto address=(0x00790ca8u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f528: { // 0x57f528: 0fbf542414 MOVSX EDX,word ptr [ESP + 0x14]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L0057f52d: { // 0x57f52d: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057f52f: { // 0x57f52f: d95b04 FSTP float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0057f532: { // 0x57f532: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057f539: { // 0x57f539: 8b0d3c86a500 MOV ECX,dword ptr [0x00a5863c]
    s.cx = m.r32((0x00a5863cu));
  }
  L0057f53f: { // 0x57f53f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057f541: { // 0x57f541: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L0057f544: { // 0x57f544: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057f547: { // 0x57f547: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057f54a: { // 0x57f54a: 8954083c MOV dword ptr [EAX + ECX*0x1 + 0x3c],EDX
    m.w32((s.ax+(s.cx * 0x00000001u)+0x0000003cu), s.dx);
  }
  L0057f54e: { // 0x57f54e: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0057f552: { // 0x57f552: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057f553: { // 0x57f553: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0057f555: { // 0x57f555: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0057f559: { // 0x57f559: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f55b: { // 0x57f55b: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057f55e: { // 0x57f55e: 83c308 ADD EBX,0x8
    s.bx = integer::add(s.bx,0x00000008u,32,flags);
  }
  L0057f561: { // 0x57f561: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057f562: { // 0x57f562: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L0057f566: { // 0x57f566: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0057f569: { // 0x57f569: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0057f56b: { // 0x57f56b: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057f56d: { // 0x57f56d: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0057f56f: { // 0x57f56f: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0057f573: { // 0x57f573: 895c2428 MOV dword ptr [ESP + 0x28],EBX
    m.w32((f.sp+0x00000028u), s.bx);
  }
  L0057f577: { // 0x57f577: 0f838d000000 JNC 0x0057f60a
    if(integer::condition("JNC",flags)) goto L0057f60a;
  }
  L0057f57d: { // 0x57f57d: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057f580: { // 0x57f580: 7624 JBE 0x0057f5a6
    if(integer::condition("JBE",flags)) goto L0057f5a6;
  }
  L0057f582: { // 0x57f582: 8b7e08 MOV EDI,dword ptr [ESI + 0x8]
    s.di = m.r32((s.si+0x00000008u));
  }
  L0057f585: { // 0x57f585: 8b1c97 MOV EBX,dword ptr [EDI + EDX*0x4]
    s.bx = m.r32((s.di+(s.dx * 0x00000004u)));
  }
  L0057f588: { // 0x57f588: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0057f58b: { // 0x57f58b: d85c2438 FCOMP float ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0057f58f: { // 0x57f58f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057f591: { // 0x57f591: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0057f594: { // 0x57f594: 750c JNZ 0x0057f5a2
    if(integer::condition("JNZ",flags)) goto L0057f5a2;
  }
  L0057f596: { // 0x57f596: 891c8f MOV dword ptr [EDI + ECX*0x4],EBX
    m.w32((s.di+(s.cx * 0x00000004u)), s.bx);
  }
  L0057f599: { // 0x57f599: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0057f59b: { // 0x57f59b: d1ea SHR EDX,0x1
    s.dx = integer::shift(s.dx,0x00000001u,32,flags,integer::Shift::right);
  }
  L0057f59d: { // 0x57f59d: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0057f5a0: { // 0x57f5a0: 77e0 JA 0x0057f582
    if(integer::condition("JA",flags)) goto L0057f582;
  }
  L0057f5a2: { // 0x57f5a2: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0057f5a6: { // 0x57f5a6: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0057f5a9: { // 0x57f5a9: 89048a MOV dword ptr [EDX + ECX*0x4],EAX
    m.w32((s.dx+(s.cx * 0x00000004u)), s.ax);
  }
  L0057f5ac: { // 0x57f5ac: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057f5ae: { // 0x57f5ae: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L0057f5b1: { // 0x57f5b1: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0057f5b2: { // 0x57f5b2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057f5b4: { // 0x57f5b4: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0057f5b6: { // 0x57f5b6: 7603 JBE 0x0057f5bb
    if(integer::condition("JBE",flags)) goto L0057f5bb;
  }
  L0057f5b8: { // 0x57f5b8: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0057f5bb: { // 0x57f5bb: 3b4610 CMP EAX,dword ptr [ESI + 0x10]
    (void)integer::sub(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L0057f5be: { // 0x57f5be: 734a JNC 0x0057f60a
    if(integer::condition("JNC",flags)) goto L0057f60a;
  }
  L0057f5c0: { // 0x57f5c0: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0057f5c3: { // 0x57f5c3: eb45 JMP 0x0057f60a
    goto L0057f60a;
  }
  L0057f5c5: { // 0x57f5c5: dd0530667800 FLD double ptr [0x00786630]
    const auto address=(0x00786630u);
    s.fp.load64(read64(m,address));
  }
  L0057f5cb: { // 0x57f5cb: e9d8feffff JMP 0x0057f4a8
    goto L0057f4a8;
  }
  L0057f5d0: { // 0x57f5d0: 8b3d3c86a500 MOV EDI,dword ptr [0x00a5863c]
    s.di = m.r32((0x00a5863cu));
  }
  L0057f5d6: { // 0x57f5d6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057f5d8: { // 0x57f5d8: 7423 JZ 0x0057f5fd
    if(integer::condition("JZ",flags)) goto L0057f5fd;
  }
  L0057f5da: { // 0x57f5da: 0fbf442416 MOVSX EAX,word ptr [ESP + 0x16]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000016u)),16));
  }
  L0057f5df: { // 0x57f5df: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057f5e6: { // 0x57f5e6: 0fbf4c2414 MOVSX ECX,word ptr [ESP + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000014u)),16));
  }
  L0057f5eb: { // 0x57f5eb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f5ed: { // 0x57f5ed: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0057f5f0: { // 0x57f5f0: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057f5f3: { // 0x57f5f3: 8b443a38 MOV EAX,dword ptr [EDX + EDI*0x1 + 0x38]
    s.ax = m.r32((s.dx+(s.di * 0x00000001u)+0x00000038u));
  }
  L0057f5f7: { // 0x57f5f7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057f5f9: { // 0x57f5f9: 740f JZ 0x0057f60a
    if(integer::condition("JZ",flags)) goto L0057f60a;
  }
  L0057f5fb: { // 0x57f5fb: eb03 JMP 0x0057f600
    goto L0057f600;
  }
  L0057f5fd: { // 0x57f5fd: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0057f600: { // 0x57f600: 3b4508 CMP EAX,dword ptr [EBP + 0x8]
    (void)integer::sub(s.ax,m.r32((s.bp+0x00000008u)),32,flags);
  }
  L0057f603: { // 0x57f603: 7405 JZ 0x0057f60a
    if(integer::condition("JZ",flags)) goto L0057f60a;
  }
  L0057f605: { // 0x57f605: c644240f00 MOV byte ptr [ESP + 0xf],0x0
    m.w8((f.sp+0x0000000fu), 0x00000000u);
  }
  L0057f60a: { // 0x57f60a: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0057f60e: { // 0x57f60e: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L0057f611: { // 0x57f611: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0057f614: { // 0x57f614: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0057f618: { // 0x57f618: 0f8c4efdffff JL 0x0057f36c
    if(integer::condition("JL",flags)) goto L0057f36c;
  }
  L0057f61e: { // 0x57f61e: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0057f622: { // 0x57f622: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0057f623: { // 0x57f623: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0057f627: { // 0x57f627: b96879a500 MOV ECX,0xa57968
    s.cx = 0x00a57968u;
  }
  L0057f62c: { // 0x57f62c: e8ef6fffff CALL 0x00576620
    s.arithmetic_flags=flags; invoke(m,s,f,0x00576620u,5764657u,op); flags=s.arithmetic_flags;
  }
  L0057f631: { // 0x57f631: dc0d807a7800 FMUL double ptr [0x00787a80]
    const auto address=(0x00787a80u);
    s.fp.multiply64(read64(m,address));
  }
  L0057f637: { // 0x57f637: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f639: { // 0x57f639: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057f63b: { // 0x57f63b: dc442448 FADD double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    s.fp.add64(read64(m,address));
  }
  L0057f63f: { // 0x57f63f: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057f643: { // 0x57f643: 7506 JNZ 0x0057f64b
    if(integer::condition("JNZ",flags)) goto L0057f64b;
  }
  L0057f645: { // 0x57f645: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0057f649: { // 0x57f649: eb2a JMP 0x0057f675
    goto L0057f675;
  }
  L0057f64b: { // 0x57f64b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057f64e: { // 0x57f64e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057f650: { // 0x57f650: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057f653: { // 0x57f653: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057f656: { // 0x57f656: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057f659: { // 0x57f659: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057f65b: { // 0x57f65b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057f65e: { // 0x57f65e: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057f665: { // 0x57f665: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f667: { // 0x57f667: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0057f668: { // 0x57f668: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L0057f66a: { // 0x57f66a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057f66c: { // 0x57f66c: e81fc80000 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5764721u,op); flags=s.arithmetic_flags;
  }
  L0057f671: { // 0x57f671: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0057f675: { // 0x57f675: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0057f679: { // 0x57f679: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0057f67d: { // 0x57f67d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0057f67f: { // 0x57f67f: 0f8c6ffcffff JL 0x0057f2f4
    if(integer::condition("JL",flags)) goto L0057f2f4;
  }
  L0057f685: { // 0x57f685: 8a4518 MOV AL,byte ptr [EBP + 0x18]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000018u)));
  }
  L0057f688: { // 0x57f688: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057f68a: { // 0x57f68a: 0f84af000000 JZ 0x0057f73f
    if(integer::condition("JZ",flags)) goto L0057f73f;
  }
  L0057f690: { // 0x57f690: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f692: { // 0x57f692: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057f694: { // 0x57f694: 0f84a5000000 JZ 0x0057f73f
    if(integer::condition("JZ",flags)) goto L0057f73f;
  }
  L0057f69a: { // 0x57f69a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057f69d: { // 0x57f69d: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057f69f: { // 0x57f69f: 8b1488 MOV EDX,dword ptr [EAX + ECX*0x4]
    s.dx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057f6a2: { // 0x57f6a2: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057f6a5: { // 0x57f6a5: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0057f6a8: { // 0x57f6a8: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0057f6aa: { // 0x57f6aa: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0057f6ad: { // 0x57f6ad: c7048100000000 MOV dword ptr [ECX + EAX*0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L0057f6b4: { // 0x57f6b4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057f6b6: { // 0x57f6b6: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0057f6b7: { // 0x57f6b7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057f6b9: { // 0x57f6b9: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0057f6bb: { // 0x57f6bb: e8d0c70000 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5764800u,op); flags=s.arithmetic_flags;
  }
  L0057f6c0: { // 0x57f6c0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057f6c2: { // 0x57f6c2: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057f6c4: { // 0x57f6c4: 7479 JZ 0x0057f73f
    if(integer::condition("JZ",flags)) goto L0057f73f;
  }
  L0057f6c6: { // 0x57f6c6: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0057f6c9: { // 0x57f6c9: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L0057f6cd: { // 0x57f6cd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057f6cf: { // 0x57f6cf: 746e JZ 0x0057f73f
    if(integer::condition("JZ",flags)) goto L0057f73f;
  }
  L0057f6d1: { // 0x57f6d1: 8b153c86a500 MOV EDX,dword ptr [0x00a5863c]
    s.dx = m.r32((0x00a5863cu));
  }
  L0057f6d7: { // 0x57f6d7: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0057f6d9: { // 0x57f6d9: 7426 JZ 0x0057f701
    if(integer::condition("JZ",flags)) goto L0057f701;
  }
  L0057f6db: { // 0x57f6db: 0fbf4102 MOVSX EAX,word ptr [ECX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0057f6df: { // 0x57f6df: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057f6e6: { // 0x57f6e6: 0fbf09 MOVSX ECX,word ptr [ECX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0057f6e9: { // 0x57f6e9: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057f6eb: { // 0x57f6eb: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057f6ee: { // 0x57f6ee: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057f6f1: { // 0x57f6f1: 8b4c1038 MOV ECX,dword ptr [EAX + EDX*0x1 + 0x38]
    s.cx = m.r32((s.ax+(s.dx * 0x00000001u)+0x00000038u));
  }
  L0057f6f5: { // 0x57f6f5: 8d441038 LEA EAX,[EAX + EDX*0x1 + 0x38]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000038u);
  }
  L0057f6f9: { // 0x57f6f9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057f6fb: { // 0x57f6fb: 7507 JNZ 0x0057f704
    if(integer::condition("JNZ",flags)) goto L0057f704;
  }
  L0057f6fd: { // 0x57f6fd: 8918 MOV dword ptr [EAX],EBX
    m.w32((s.ax), s.bx);
  }
  L0057f6ff: { // 0x57f6ff: eb0c JMP 0x0057f70d
    goto L0057f70d;
  }
  L0057f701: { // 0x57f701: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0057f704: { // 0x57f704: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0057f706: { // 0x57f706: 7405 JZ 0x0057f70d
    if(integer::condition("JZ",flags)) goto L0057f70d;
  }
  L0057f708: { // 0x57f708: c644240f00 MOV byte ptr [ESP + 0xf],0x0
    m.w8((f.sp+0x0000000fu), 0x00000000u);
  }
  L0057f70d: { // 0x57f70d: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0057f70f: { // 0x57f70f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057f711: { // 0x57f711: 742c JZ 0x0057f73f
    if(integer::condition("JZ",flags)) goto L0057f73f;
  }
  L0057f713: { // 0x57f713: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057f716: { // 0x57f716: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057f718: { // 0x57f718: 8b0c88 MOV ECX,dword ptr [EAX + ECX*0x4]
    s.cx = m.r32((s.ax+(s.cx * 0x00000004u)));
  }
  L0057f71b: { // 0x57f71b: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L0057f71e: { // 0x57f71e: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0057f721: { // 0x57f721: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057f723: { // 0x57f723: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0057f726: { // 0x57f726: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057f728: { // 0x57f728: c7049000000000 MOV dword ptr [EAX + EDX*0x4],0x0
    m.w32((s.ax+(s.dx * 0x00000004u)), 0x00000000u);
  }
  L0057f72f: { // 0x57f72f: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0057f731: { // 0x57f731: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0057f732: { // 0x57f732: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0057f734: { // 0x57f734: e857c70000 CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,5764921u,op); flags=s.arithmetic_flags;
  }
  L0057f739: { // 0x57f739: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0057f73b: { // 0x57f73b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0057f73d: { // 0x57f73d: 758a JNZ 0x0057f6c9
    if(integer::condition("JNZ",flags)) goto L0057f6c9;
  }
  L0057f73f: { // 0x57f73f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0057f743: { // 0x57f743: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0057f744: { // 0x57f744: e832df1e00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5764937u,op); flags=s.arithmetic_flags;
  }
  L0057f749: { // 0x57f749: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057f74c: { // 0x57f74c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0057f74e: { // 0x57f74e: 7409 JZ 0x0057f759
    if(integer::condition("JZ",flags)) goto L0057f759;
  }
  L0057f750: { // 0x57f750: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0057f752: { // 0x57f752: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057f754: { // 0x57f754: e8c7b10000 CALL 0x0058a920
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a920u,5764953u,op); flags=s.arithmetic_flags;
  }
  L0057f759: { // 0x57f759: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L0057f75d: { // 0x57f75d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057f75e: { // 0x57f75e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057f75f: { // 0x57f75f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057f760: { // 0x57f760: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057f762: { // 0x57f762: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057f763: { // 0x57f763: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}

void f_0007b190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047b190: { // 0x47b190: 8b4138 MOV EAX,dword ptr [ECX + 0x38]
    s.ax = m.r32((s.cx+0x00000038u));
  }
  L0047b193: { // 0x47b193: 3dffff0000 CMP EAX,0xffff
    (void)integer::sub(s.ax,0x0000ffffu,32,flags);
  }
  L0047b198: { // 0x47b198: 7407 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19a: { // 0x47b19a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0047b19c: { // 0x47b19c: 7403 JZ 0x0047b1a1
    if(integer::condition("JZ",flags)) goto L0047b1a1;
  }
  L0047b19e: { // 0x47b19e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047b1a0: { // 0x47b1a0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047b1a1: { // 0x47b1a1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047b1a3: { // 0x47b1a3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0017ece0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0057ece0: { // 0x57ece0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0057ece3: { // 0x57ece3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0057ece4: { // 0x57ece4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057ece5: { // 0x57ece5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057ece6: { // 0x57ece6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0057ece8: { // 0x57ece8: 6a18 PUSH 0x18
    f.push(m,0x00000018u);
  }
  L0057ecea: { // 0x57ecea: e868ec1e00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5762287u,op); flags=s.arithmetic_flags;
  }
  L0057ecef: { // 0x57ecef: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0057ecf1: { // 0x57ecf1: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0057ecf3: { // 0x57ecf3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0057ecf6: { // 0x57ecf6: 3bdf CMP EBX,EDI
    (void)integer::sub(s.bx,s.di,32,flags);
  }
  L0057ecf8: { // 0x57ecf8: 741b JZ 0x0057ed15
    if(integer::condition("JZ",flags)) goto L0057ed15;
  }
  L0057ecfa: { // 0x57ecfa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057ecfb: { // 0x57ecfb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0057ecfc: { // 0x57ecfc: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057ecfe: { // 0x57ecfe: e89de7eaff CALL 0x0042d4a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042d4a0u,5762307u,op); flags=s.arithmetic_flags;
  }
  L0057ed03: { // 0x57ed03: c703a0757800 MOV dword ptr [EBX],0x7875a0
    m.w32((s.bx), 0x007875a0u);
  }
  L0057ed09: { // 0x57ed09: c743140a000000 MOV dword ptr [EBX + 0x14],0xa
    m.w32((s.bx+0x00000014u), 0x0000000au);
  }
  L0057ed10: { // 0x57ed10: 897b10 MOV dword ptr [EBX + 0x10],EDI
    m.w32((s.bx+0x00000010u), s.di);
  }
  L0057ed13: { // 0x57ed13: eb02 JMP 0x0057ed17
    goto L0057ed17;
  }
  L0057ed15: { // 0x57ed15: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057ed17: { // 0x57ed17: 8b8684010000 MOV EAX,dword ptr [ESI + 0x184]
    s.ax = m.r32((s.si+0x00000184u));
  }
  L0057ed1d: { // 0x57ed1d: 895c240c MOV dword ptr [ESP + 0xc],EBX
    m.w32((f.sp+0x0000000cu), s.bx);
  }
  L0057ed21: { // 0x57ed21: 0faf8680010000 IMUL EAX,dword ptr [ESI + 0x180]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000180u)),32,flags);
  }
  L0057ed28: { // 0x57ed28: 894314 MOV dword ptr [EBX + 0x14],EAX
    m.w32((s.bx+0x00000014u), s.ax);
  }
  L0057ed2b: { // 0x57ed2b: 8b0d4c6b8300 MOV ECX,dword ptr [0x00836b4c]
    s.cx = m.r32((0x00836b4cu));
  }
  L0057ed31: { // 0x57ed31: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0057ed33: { // 0x57ed33: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L0057ed36: { // 0x57ed36: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0057ed38: { // 0x57ed38: 0f8e62010000 JLE 0x0057eea0
    if(integer::condition("JLE",flags)) goto L0057eea0;
  }
  L0057ed3e: { // 0x57ed3e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0057ed3f: { // 0x57ed3f: 8b2d3c86a500 MOV EBP,dword ptr [0x00a5863c]
    s.bp = m.r32((0x00a5863cu));
  }
  L0057ed45: { // 0x57ed45: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0057ed49: { // 0x57ed49: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0057ed4d: { // 0x57ed4d: eb06 JMP 0x0057ed55
    goto L0057ed55;
  }
  L0057ed4f: { // 0x57ed4f: 8b0d4c6b8300 MOV ECX,dword ptr [0x00836b4c]
    s.cx = m.r32((0x00836b4cu));
  }
  L0057ed55: { // 0x57ed55: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0057ed59: { // 0x57ed59: 8b3c2a MOV EDI,dword ptr [EDX + EBP*0x1]
    s.di = m.r32((s.dx+(s.bp * 0x00000001u)));
  }
  L0057ed5c: { // 0x57ed5c: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0057ed60: { // 0x57ed60: 668b54241a MOV DX,word ptr [ESP + 0x1a]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000001au)));
  }
  L0057ed65: { // 0x57ed65: 6685ff TEST di,di
    (void)integer::logical(((s.di & 0xffffu))&((s.di & 0xffffu)),16,flags);
  }
  L0057ed68: { // 0x57ed68: 7509 JNZ 0x0057ed73
    if(integer::condition("JNZ",flags)) goto L0057ed73;
  }
  L0057ed6a: { // 0x57ed6a: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  L0057ed6d: { // 0x57ed6d: 0f8407010000 JZ 0x0057ee7a
    if(integer::condition("JZ",flags)) goto L0057ee7a;
  }
  L0057ed73: { // 0x57ed73: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0057ed75: { // 0x57ed75: 7505 JNZ 0x0057ed7c
    if(integer::condition("JNZ",flags)) goto L0057ed7c;
  }
  L0057ed77: { // 0x57ed77: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0057ed7a: { // 0x57ed7a: eb15 JMP 0x0057ed91
    goto L0057ed91;
  }
  L0057ed7c: { // 0x57ed7c: 0fbfc2 MOVSX EAX,DX
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L0057ed7f: { // 0x57ed7f: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L0057ed82: { // 0x57ed82: 0fbfcf MOVSX ECX,di
    s.cx = std::uint32_t(integer::sign_extend((s.di & 0xffffu),16));
  }
  L0057ed85: { // 0x57ed85: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057ed87: { // 0x57ed87: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0057ed8a: { // 0x57ed8a: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057ed8d: { // 0x57ed8d: 8b442838 MOV EAX,dword ptr [EAX + EBP*0x1 + 0x38]
    s.ax = m.r32((s.ax+(s.bp * 0x00000001u)+0x00000038u));
  }
  L0057ed91: { // 0x57ed91: 3b442424 CMP EAX,dword ptr [ESP + 0x24]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L0057ed95: { // 0x57ed95: 0f85df000000 JNZ 0x0057ee7a
    if(integer::condition("JNZ",flags)) goto L0057ee7a;
  }
  L0057ed9b: { // 0x57ed9b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0057ed9d: { // 0x57ed9d: eb05 JMP 0x0057eda4
    goto L0057eda4;
  }
  L0057ed9f: { // 0x57ed9f: 668b54241a MOV DX,word ptr [ESP + 0x1a]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000001au)));
  }
  L0057eda4: { // 0x57eda4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0057eda6: { // 0x57eda6: 668bc7 MOV AX,di
    s.ax = with_ax(s.ax, (s.di & 0xffffu));
  }
  L0057eda9: { // 0x57eda9: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L0057edac: { // 0x57edac: 6603048da09d8300 ADD AX,word ptr [ECX*0x4 + 0x839da0]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16(((s.cx * 0x00000004u)+0x00839da0u)),16,flags));
  }
  L0057edb4: { // 0x57edb4: 8d0c8da09d8300 LEA ECX,[ECX*0x4 + 0x839da0]
    s.cx = ((s.cx * 0x00000004u)+0x00839da0u);
  }
  L0057edbb: { // 0x57edbb: 668b4902 MOV CX,word ptr [ECX + 0x2]
    s.cx = with_ax(s.cx, m.r16((s.cx+0x00000002u)));
  }
  L0057edbf: { // 0x57edbf: 6603ca ADD CX,DX
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),(s.dx & 0xffffu),16,flags));
  }
  L0057edc2: { // 0x57edc2: 0fbfd0 MOVSX EDX,AX
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0057edc5: { // 0x57edc5: 0fbfc1 MOVSX EAX,CX
    s.ax = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0057edc8: { // 0x57edc8: 8d0c02 LEA ECX,[EDX + EAX*0x1]
    s.cx = (s.dx+(s.ax * 0x00000001u));
  }
  L0057edcb: { // 0x57edcb: 3b0d3486a500 CMP ECX,dword ptr [0x00a58634]
    (void)integer::sub(s.cx,m.r32((0x00a58634u)),32,flags);
  }
  L0057edd1: { // 0x57edd1: 7e4a JLE 0x0057ee1d
    if(integer::condition("JLE",flags)) goto L0057ee1d;
  }
  L0057edd3: { // 0x57edd3: 8b1d3486a500 MOV EBX,dword ptr [0x00a58634]
    s.bx = m.r32((0x00a58634u));
  }
  L0057edd9: { // 0x57edd9: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L0057eddb: { // 0x57eddb: 2be8 SUB EBP,EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  L0057eddd: { // 0x57eddd: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0057eddf: { // 0x57eddf: 7d48 JGE 0x0057ee29
    if(integer::condition("JGE",flags)) goto L0057ee29;
  }
  L0057ede1: { // 0x57ede1: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0057ede3: { // 0x57ede3: 2bea SUB EBP,EDX
    s.bp = integer::sub(s.bp,s.dx,32,flags);
  }
  L0057ede5: { // 0x57ede5: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0057ede7: { // 0x57ede7: 7d40 JGE 0x0057ee29
    if(integer::condition("JGE",flags)) goto L0057ee29;
  }
  L0057ede9: { // 0x57ede9: 3b0d3886a500 CMP ECX,dword ptr [0x00a58638]
    (void)integer::sub(s.cx,m.r32((0x00a58638u)),32,flags);
  }
  L0057edef: { // 0x57edef: 7f38 JG 0x0057ee29
    if(integer::condition("JG",flags)) goto L0057ee29;
  }
  L0057edf1: { // 0x57edf1: 8b2d3c86a500 MOV EBP,dword ptr [0x00a5863c]
    s.bp = m.r32((0x00a5863cu));
  }
  L0057edf7: { // 0x57edf7: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0057edf9: { // 0x57edf9: 7505 JNZ 0x0057ee00
    if(integer::condition("JNZ",flags)) goto L0057ee00;
  }
  L0057edfb: { // 0x57edfb: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0057edfe: { // 0x57edfe: eb13 JMP 0x0057ee13
    goto L0057ee13;
  }
  L0057ee00: { // 0x57ee00: 0faf054c6b8300 IMUL EAX,dword ptr [0x00836b4c]
    s.ax = integer::imul(s.ax,m.r32((0x00836b4cu)),32,flags);
  }
  L0057ee07: { // 0x57ee07: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0057ee09: { // 0x57ee09: 8d1480 LEA EDX,[EAX + EAX*0x4]
    s.dx = (s.ax+(s.ax * 0x00000004u));
  }
  L0057ee0c: { // 0x57ee0c: c1e204 SHL EDX,0x4
    s.dx = integer::shift(s.dx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0057ee0f: { // 0x57ee0f: 8b442a38 MOV EAX,dword ptr [EDX + EBP*0x1 + 0x38]
    s.ax = m.r32((s.dx+(s.bp * 0x00000001u)+0x00000038u));
  }
  L0057ee13: { // 0x57ee13: 3b442424 CMP EAX,dword ptr [ESP + 0x24]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000024u)),32,flags);
  }
  L0057ee17: { // 0x57ee17: 751c JNZ 0x0057ee35
    if(integer::condition("JNZ",flags)) goto L0057ee35;
  }
  L0057ee19: { // 0x57ee19: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0057ee1d: { // 0x57ee1d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0057ee1e: { // 0x57ee1e: 83fe08 CMP ESI,0x8
    (void)integer::sub(s.si,0x00000008u,32,flags);
  }
  L0057ee21: { // 0x57ee21: 0f8c78ffffff JL 0x0057ed9f
    if(integer::condition("JL",flags)) goto L0057ed9f;
  }
  L0057ee27: { // 0x57ee27: eb51 JMP 0x0057ee7a
    goto L0057ee7a;
  }
  L0057ee29: { // 0x57ee29: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0057ee2d: { // 0x57ee2d: 8b2d3c86a500 MOV EBP,dword ptr [0x00a5863c]
    s.bp = m.r32((0x00a5863cu));
  }
  L0057ee33: { // 0x57ee33: ebe8 JMP 0x0057ee1d
    goto L0057ee1d;
  }
  L0057ee35: { // 0x57ee35: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0057ee39: { // 0x57ee39: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  L0057ee3c: { // 0x57ee3c: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  L0057ee3f: { // 0x57ee3f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0057ee41: { // 0x57ee41: 7c22 JL 0x0057ee65
    if(integer::condition("JL",flags)) goto L0057ee65;
  }
  L0057ee43: { // 0x57ee43: 8a430d MOV AL,byte ptr [EBX + 0xd]
    s.ax = with_al(s.ax, m.r8((s.bx+0x0000000du)));
  }
  L0057ee46: { // 0x57ee46: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057ee48: { // 0x57ee48: 7504 JNZ 0x0057ee4e
    if(integer::condition("JNZ",flags)) goto L0057ee4e;
  }
  L0057ee4a: { // 0x57ee4a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057ee4c: { // 0x57ee4c: 752c JNZ 0x0057ee7a
    if(integer::condition("JNZ",flags)) goto L0057ee7a;
  }
  L0057ee4e: { // 0x57ee4e: 8b4314 MOV EAX,dword ptr [EBX + 0x14]
    s.ax = m.r32((s.bx+0x00000014u));
  }
  L0057ee51: { // 0x57ee51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0057ee53: { // 0x57ee53: 7e25 JLE 0x0057ee7a
    if(integer::condition("JLE",flags)) goto L0057ee7a;
  }
  L0057ee55: { // 0x57ee55: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0057ee57: { // 0x57ee57: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0057ee59: { // 0x57ee59: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0057ee5b: { // 0x57ee5b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0057ee5c: { // 0x57ee5c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0057ee5e: { // 0x57ee5e: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5762657u,op); flags=s.arithmetic_flags;
  }
  L0057ee61: { // 0x57ee61: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0057ee63: { // 0x57ee63: 740f JZ 0x0057ee74
    if(integer::condition("JZ",flags)) goto L0057ee74;
  }
  L0057ee65: { // 0x57ee65: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  L0057ee68: { // 0x57ee68: 8b5304 MOV EDX,dword ptr [EBX + 0x4]
    s.dx = m.r32((s.bx+0x00000004u));
  }
  L0057ee6b: { // 0x57ee6b: 8d4801 LEA ECX,[EAX + 0x1]
    s.cx = (s.ax+0x00000001u);
  }
  L0057ee6e: { // 0x57ee6e: 894b10 MOV dword ptr [EBX + 0x10],ECX
    m.w32((s.bx+0x00000010u), s.cx);
  }
  L0057ee71: { // 0x57ee71: 893c82 MOV dword ptr [EDX + EAX*0x4],EDI
    m.w32((s.dx+(s.ax * 0x00000004u)), s.di);
  }
  L0057ee74: { // 0x57ee74: 8b2d3c86a500 MOV EBP,dword ptr [0x00a5863c]
    s.bp = m.r32((0x00a5863cu));
  }
  L0057ee7a: { // 0x57ee7a: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0057ee7e: { // 0x57ee7e: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0057ee82: { // 0x57ee82: 83c150 ADD ECX,0x50
    s.cx = integer::add(s.cx,0x00000050u,32,flags);
  }
  L0057ee85: { // 0x57ee85: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0057ee86: { // 0x57ee86: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0057ee8a: { // 0x57ee8a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0057ee8e: { // 0x57ee8e: 0f85bbfeffff JNZ 0x0057ed4f
    if(integer::condition("JNZ",flags)) goto L0057ed4f;
  }
  L0057ee94: { // 0x57ee94: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057ee95: { // 0x57ee95: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057ee96: { // 0x57ee96: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0057ee98: { // 0x57ee98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057ee99: { // 0x57ee99: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057ee9a: { // 0x57ee9a: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0057ee9d: { // 0x57ee9d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0057eea0: { // 0x57eea0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0057eea1: { // 0x57eea1: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0057eea3: { // 0x57eea3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0057eea4: { // 0x57eea4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0057eea5: { // 0x57eea5: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0057eea8: { // 0x57eea8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0018a920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058a920: { // 0x58a920: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058a921: { // 0x58a921: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0058a923: { // 0x58a923: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0058a926: { // 0x58a926: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0058a927: { // 0x58a927: e84f2d1e00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5810476u,op); flags=s.arithmetic_flags;
  }
  L0058a92c: { // 0x58a92c: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  L0058a930: { // 0x58a930: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0058a933: { // 0x58a933: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0058a935: { // 0x58a935: 7409 JZ 0x0058a940
    if(integer::condition("JZ",flags)) goto L0058a940;
  }
  L0058a937: { // 0x58a937: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058a938: { // 0x58a938: e83e2d1e00 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,5810493u,op); flags=s.arithmetic_flags;
  }
  L0058a93d: { // 0x58a93d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0058a940: { // 0x58a940: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0058a942: { // 0x58a942: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058a943: { // 0x58a943: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0018be90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0058be90: { // 0x58be90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0058be91: { // 0x58be91: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  L0058be93: { // 0x58be93: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0058be94: { // 0x58be94: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0058be95: { // 0x58be95: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L0058be99: { // 0x58be99: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0058be9a: { // 0x58be9a: 8d1436 LEA EDX,[ESI + ESI*0x1]
    s.dx = (s.si+(s.si * 0x00000001u));
  }
  L0058be9d: { // 0x58be9d: 8d7c3601 LEA EDI,[ESI + ESI*0x1 + 0x1]
    s.di = (s.si+(s.si * 0x00000001u)+0x00000001u);
  }
  L0058bea1: { // 0x58bea1: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0058bea3: { // 0x58bea3: 7f18 JG 0x0058bebd
    if(integer::condition("JG",flags)) goto L0058bebd;
  }
  L0058bea5: { // 0x58bea5: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bea8: { // 0x58bea8: 8b2c90 MOV EBP,dword ptr [EAX + EDX*0x4]
    s.bp = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058beab: { // 0x58beab: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0058beae: { // 0x58beae: d94504 FLD float ptr [EBP + 0x4]
    const auto address=(s.bp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058beb1: { // 0x58beb1: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058beb4: { // 0x58beb4: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058beb6: { // 0x58beb6: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058beb8: { // 0x58beb8: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bebb: { // 0x58bebb: 7402 JZ 0x0058bebf
    if(integer::condition("JZ",flags)) goto L0058bebf;
  }
  L0058bebd: { // 0x58bebd: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0058bebf: { // 0x58bebf: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0058bec1: { // 0x58bec1: 7f1a JG 0x0058bedd
    if(integer::condition("JG",flags)) goto L0058bedd;
  }
  L0058bec3: { // 0x58bec3: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bec6: { // 0x58bec6: 8b1cb8 MOV EBX,dword ptr [EAX + EDI*0x4]
    s.bx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0058bec9: { // 0x58bec9: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058becc: { // 0x58becc: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058becf: { // 0x58becf: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bed2: { // 0x58bed2: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058bed4: { // 0x58bed4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058bed6: { // 0x58bed6: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bed9: { // 0x58bed9: 7502 JNZ 0x0058bedd
    if(integer::condition("JNZ",flags)) goto L0058bedd;
  }
  L0058bedb: { // 0x58bedb: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0058bedd: { // 0x58bedd: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0058bedf: { // 0x58bedf: 7460 JZ 0x0058bf41
    if(integer::condition("JZ",flags)) goto L0058bf41;
  }
  L0058bee1: { // 0x58bee1: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bee4: { // 0x58bee4: 8d6c1201 LEA EBP,[EDX + EDX*0x1 + 0x1]
    s.bp = (s.dx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0058bee8: { // 0x58bee8: 8b1c90 MOV EBX,dword ptr [EAX + EDX*0x4]
    s.bx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058beeb: { // 0x58beeb: 8b3cb0 MOV EDI,dword ptr [EAX + ESI*0x4]
    s.di = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0058beee: { // 0x58beee: 891cb0 MOV dword ptr [EAX + ESI*0x4],EBX
    m.w32((s.ax+(s.si * 0x00000004u)), s.bx);
  }
  L0058bef1: { // 0x58bef1: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bef4: { // 0x58bef4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0058bef6: { // 0x58bef6: 893c90 MOV dword ptr [EAX + EDX*0x4],EDI
    m.w32((s.ax+(s.dx * 0x00000004u)), s.di);
  }
  L0058bef9: { // 0x58bef9: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  L0058befb: { // 0x58befb: 8d3c12 LEA EDI,[EDX + EDX*0x1]
    s.di = (s.dx+(s.dx * 0x00000001u));
  }
  L0058befe: { // 0x58befe: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0058bf00: { // 0x58bf00: 7f1d JG 0x0058bf1f
    if(integer::condition("JG",flags)) goto L0058bf1f;
  }
  L0058bf02: { // 0x58bf02: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bf05: { // 0x58bf05: 8b04b8 MOV EAX,dword ptr [EAX + EDI*0x4]
    s.ax = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0058bf08: { // 0x58bf08: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf0b: { // 0x58bf0b: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bf0e: { // 0x58bf0e: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058bf11: { // 0x58bf11: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf14: { // 0x58bf14: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058bf16: { // 0x58bf16: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058bf18: { // 0x58bf18: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bf1b: { // 0x58bf1b: 7502 JNZ 0x0058bf1f
    if(integer::condition("JNZ",flags)) goto L0058bf1f;
  }
  L0058bf1d: { // 0x58bf1d: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0058bf1f: { // 0x58bf1f: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0058bf21: { // 0x58bf21: 7f1a JG 0x0058bf3d
    if(integer::condition("JG",flags)) goto L0058bf3d;
  }
  L0058bf23: { // 0x58bf23: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0058bf26: { // 0x58bf26: 8b3ca8 MOV EDI,dword ptr [EAX + EBP*0x4]
    s.di = m.r32((s.ax+(s.bp * 0x00000004u)));
  }
  L0058bf29: { // 0x58bf29: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L0058bf2c: { // 0x58bf2c: d94704 FLD float ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf2f: { // 0x58bf2f: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L0058bf32: { // 0x58bf32: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L0058bf34: { // 0x58bf34: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0058bf36: { // 0x58bf36: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0058bf39: { // 0x58bf39: 7502 JNZ 0x0058bf3d
    if(integer::condition("JNZ",flags)) goto L0058bf3d;
  }
  L0058bf3b: { // 0x58bf3b: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L0058bf3d: { // 0x58bf3d: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0058bf3f: { // 0x58bf3f: 75a0 JNZ 0x0058bee1
    if(integer::condition("JNZ",flags)) goto L0058bee1;
  }
  L0058bf41: { // 0x58bf41: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0058bf42: { // 0x58bf42: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0058bf43: { // 0x58bf43: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0058bf44: { // 0x58bf44: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0058bf45: { // 0x58bf45: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0002d3e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042d3e0: { // 0x42d3e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042d3e1: { // 0x42d3e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042d3e3: { // 0x42d3e3: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0042d3e6: { // 0x42d3e6: c706e0757800 MOV dword ptr [ESI],0x7875e0
    m.w32((s.si), 0x007875e0u);
  }
  L0042d3ec: { // 0x42d3ec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d3ee: { // 0x42d3ee: 7417 JZ 0x0042d407
    if(integer::condition("JZ",flags)) goto L0042d407;
  }
  L0042d3f0: { // 0x42d3f0: 8a4e0d MOV CL,byte ptr [ESI + 0xd]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000000du)));
  }
  L0042d3f3: { // 0x42d3f3: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0042d3f5: { // 0x42d3f5: 7410 JZ 0x0042d407
    if(integer::condition("JZ",flags)) goto L0042d407;
  }
  L0042d3f7: { // 0x42d3f7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042d3f8: { // 0x42d3f8: e87e023400 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4379645u,op); flags=s.arithmetic_flags;
  }
  L0042d3fd: { // 0x42d3fd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d400: { // 0x42d400: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042d407: { // 0x42d407: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L0042d40b: { // 0x42d40b: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0042d40f: { // 0x42d40f: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0042d411: { // 0x42d411: c7460800000000 MOV dword ptr [ESI + 0x8],0x0
    m.w32((s.si+0x00000008u), 0x00000000u);
  }
  L0042d418: { // 0x42d418: 7409 JZ 0x0042d423
    if(integer::condition("JZ",flags)) goto L0042d423;
  }
  L0042d41a: { // 0x42d41a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042d41b: { // 0x42d41b: e85b023400 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4379680u,op); flags=s.arithmetic_flags;
  }
  L0042d420: { // 0x42d420: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d423: { // 0x42d423: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d425: { // 0x42d425: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d426: { // 0x42d426: c20400 RET 0x4
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

void f_00176620(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00576620: { // 0x576620: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00576621: { // 0x576621: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00576623: { // 0x576623: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00576626: { // 0x576626: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L00576629: { // 0x576629: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057662a: { // 0x57662a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0057662c: { // 0x57662c: 803e00 CMP byte ptr [ESI],0x0
    (void)integer::sub(m.r8((s.si)),0x00000000u,8,flags);
  }
  L0057662f: { // 0x57662f: 740d JZ 0x0057663e
    if(integer::condition("JZ",flags)) goto L0057663e;
  }
  L00576631: { // 0x576631: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  L00576634: { // 0x576634: dd4608 FLD double ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00576637: { // 0x576637: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00576638: { // 0x576638: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057663a: { // 0x57663a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057663b: { // 0x57663b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0057663c: { // 0x57663c: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057663e: { // 0x57663e: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727809u,op); flags=s.arithmetic_flags;
  }
  L00576641: { // 0x576641: dcc0 FADD st0,st0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576643: { // 0x576643: dc2508577800 FSUB double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576649: { // 0x576649: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057664d: { // 0x57664d: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727824u,op); flags=s.arithmetic_flags;
  }
  L00576650: { // 0x576650: dcc0 FADD st0,st0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576652: { // 0x576652: dc2508577800 FSUB double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576658: { // 0x576658: dd542410 FST double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057665c: { // 0x57665c: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0057665e: { // 0x57665e: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L00576660: { // 0x576660: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00576664: { // 0x576664: dc4c2408 FMUL double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.multiply64(read64(m,address));
  }
  L00576668: { // 0x576668: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057666a: { // 0x57666a: dc1508577800 FCOM double ptr [0x00785708]
    const auto address=(0x00785708u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00576670: { // 0x576670: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00576672: { // 0x576672: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00576675: { // 0x576675: 74c5 JZ 0x0057663c
    if(integer::condition("JZ",flags)) goto L0057663c;
  }
  L00576677: { // 0x576677: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057667d: { // 0x57667d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057667f: { // 0x57667f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00576682: { // 0x576682: 75b8 JNZ 0x0057663c
    if(integer::condition("JNZ",flags)) goto L0057663c;
  }
  L00576684: { // 0x576684: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576686: { // 0x576686: d9ed FLDLN2
    numeric_b88::detail::reg<0xd9ed>(s.fp);
  }
  L00576688: { // 0x576688: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057668b: { // 0x57668b: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0057668d: { // 0x57668d: d9f1 FYL2X
    numeric_b88::detail::reg<0xd9f1>(s.fp);
  }
  L0057668f: { // 0x57668f: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576691: { // 0x576691: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00576693: { // 0x576693: d8e1 FSUB st0,st1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00576695: { // 0x576695: d8f2 FDIV st0,st2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L00576697: { // 0x576697: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057669a: { // 0x57669a: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669c: { // 0x57669c: ddd8 FSTP st0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669e: { // 0x57669e: e8dd39f4ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5727907u,op); flags=s.arithmetic_flags;
  }
  L005766a3: { // 0x5766a3: d9c0 FLD st0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L005766a5: { // 0x5766a5: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L005766a9: { // 0x5766a9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005766ac: { // 0x5766ac: c60601 MOV byte ptr [ESI],0x1
    m.w8((s.si), 0x00000001u);
  }
  L005766af: { // 0x5766af: dd5e08 FSTP double ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005766b2: { // 0x5766b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005766b3: { // 0x5766b3: dc4c2404 FMUL double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.multiply64(read64(m,address));
  }
  L005766b7: { // 0x5766b7: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L005766b9: { // 0x5766b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005766ba: { // 0x5766ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00157340(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557340: { // 0x557340: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L00557346: { // 0x557346: c7810801000001000000 MOV dword ptr [ECX + 0x108],0x1
    m.w32((s.cx+0x00000108u), 0x00000001u);
  }
  L00557350: { // 0x557350: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L00557356: { // 0x557356: 8d50ff LEA EDX,[EAX + -0x1]
    s.dx = (s.ax-0x00000001u);
  }
  L00557359: { // 0x557359: 899110010000 MOV dword ptr [ECX + 0x110],EDX
    m.w32((s.cx+0x00000110u), s.dx);
  }
  L0055735f: { // 0x55735f: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557365: { // 0x557365: c1e00b SHL EAX,0xb
    s.ax = integer::shift(s.ax,0x0000000bu,32,flags,integer::Shift::left);
  }
  L00557368: { // 0x557368: 8d441004 LEA EAX,[EAX + EDX*0x1 + 0x4]
    s.ax = (s.ax+(s.dx * 0x00000001u)+0x00000004u);
  }
  L0055736c: { // 0x55736c: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L00557372: { // 0x557372: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00157280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557280: { // 0x557280: 8b8110010000 MOV EAX,dword ptr [ECX + 0x110]
    s.ax = m.r32((s.cx+0x00000110u));
  }
  L00557286: { // 0x557286: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00557287: { // 0x557287: 8ba914010000 MOV EBP,dword ptr [ECX + 0x114]
    s.bp = m.r32((s.cx+0x00000114u));
  }
  L0055728d: { // 0x55728d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055728e: { // 0x55728e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557290: { // 0x557290: 7433 JZ 0x005572c5
    if(integer::condition("JZ",flags)) goto L005572c5;
  }
  L00557292: { // 0x557292: 8bb108010000 MOV ESI,dword ptr [ECX + 0x108]
    s.si = m.r32((s.cx+0x00000108u));
  }
  L00557298: { // 0x557298: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L0055729e: { // 0x55729e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0055729f: { // 0x55729f: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005572a0: { // 0x5572a0: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L005572a1: { // 0x5572a1: 89b108010000 MOV dword ptr [ECX + 0x108],ESI
    m.w32((s.cx+0x00000108u), s.si);
  }
  L005572a7: { // 0x5572a7: 898110010000 MOV dword ptr [ECX + 0x110],EAX
    m.w32((s.cx+0x00000110u), s.ax);
  }
  L005572ad: { // 0x5572ad: 8d8504f8ffff LEA EAX,[EBP + 0xfffff804]
    s.ax = (s.bp+0xfffff804u);
  }
  L005572b3: { // 0x5572b3: 89910c010000 MOV dword ptr [ECX + 0x10c],EDX
    m.w32((s.cx+0x0000010cu), s.dx);
  }
  L005572b9: { // 0x5572b9: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L005572bf: { // 0x5572bf: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L005572c2: { // 0x5572c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005572c3: { // 0x5572c3: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005572c4: { // 0x5572c4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L005572c5: { // 0x5572c5: 8b910c010000 MOV EDX,dword ptr [ECX + 0x10c]
    s.dx = m.r32((s.cx+0x0000010cu));
  }
  L005572cb: { // 0x5572cb: 8b8108010000 MOV EAX,dword ptr [ECX + 0x108]
    s.ax = m.r32((s.cx+0x00000108u));
  }
  L005572d1: { // 0x5572d1: 8bb1f0000000 MOV ESI,dword ptr [ECX + 0xf0]
    s.si = m.r32((s.cx+0x000000f0u));
  }
  L005572d7: { // 0x5572d7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005572d8: { // 0x5572d8: 899108010000 MOV dword ptr [ECX + 0x108],EDX
    m.w32((s.cx+0x00000108u), s.dx);
  }
  L005572de: { // 0x5572de: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005572e0: { // 0x5572e0: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L005572e2: { // 0x5572e2: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572e8: { // 0x5572e8: 8d5402ff LEA EDX,[EDX + EAX*0x1 + -0x1]
    s.dx = (s.dx+(s.ax * 0x00000001u)-0x00000001u);
  }
  L005572ec: { // 0x5572ec: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  L005572ef: { // 0x5572ef: 740a JZ 0x005572fb
    if(integer::condition("JZ",flags)) goto L005572fb;
  }
  L005572f1: { // 0x5572f1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005572f2: { // 0x5572f2: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L005572f3: { // 0x5572f3: 89810c010000 MOV dword ptr [ECX + 0x10c],EAX
    m.w32((s.cx+0x0000010cu), s.ax);
  }
  L005572f9: { // 0x5572f9: eb0a JMP 0x00557305
    goto L00557305;
  }
  L005572fb: { // 0x5572fb: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L005572fc: { // 0x5572fc: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L005572ff: { // 0x5572ff: 89b908010000 MOV dword ptr [ECX + 0x108],EDI
    m.w32((s.cx+0x00000108u), s.di);
  }
  L00557305: { // 0x557305: 8b810c010000 MOV EAX,dword ptr [ECX + 0x10c]
    s.ax = m.r32((s.cx+0x0000010cu));
  }
  L0055730b: { // 0x55730b: 8b9108010000 MOV EDX,dword ptr [ECX + 0x108]
    s.dx = m.r32((s.cx+0x00000108u));
  }
  L00557311: { // 0x557311: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00557314: { // 0x557314: 89b110010000 MOV dword ptr [ECX + 0x110],ESI
    m.w32((s.cx+0x00000110u), s.si);
  }
  L0055731a: { // 0x55731a: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055731c: { // 0x55731c: 8b9138010000 MOV EDX,dword ptr [ECX + 0x138]
    s.dx = m.r32((s.cx+0x00000138u));
  }
  L00557322: { // 0x557322: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557323: { // 0x557323: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557324: { // 0x557324: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L00557327: { // 0x557327: 898114010000 MOV dword ptr [ECX + 0x114],EAX
    m.w32((s.cx+0x00000114u), s.ax);
  }
  L0055732d: { // 0x55732d: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L00557330: { // 0x557330: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557331: { // 0x557331: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0002add0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042add0: { // 0x42add0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0042add4: { // 0x42add4: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0042add7: { // 0x42add7: 668b4002 MOV AX,word ptr [EAX + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x00000002u)));
  }
  L0042addb: { // 0x42addb: 66034102 ADD AX,word ptr [ECX + 0x2]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.cx+0x00000002u)),16,flags));
  }
  L0042addf: { // 0x42addf: 660311 ADD DX,word ptr [ECX]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((s.cx)),16,flags));
  }
  L0042ade2: { // 0x42ade2: 668944240a MOV word ptr [ESP + 0xa],AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L0042ade7: { // 0x42ade7: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0042adeb: { // 0x42adeb: 6689542408 MOV word ptr [ESP + 0x8],DX
    m.w16((f.sp+0x00000008u), (s.dx & 0xffffu));
  }
  L0042adf0: { // 0x42adf0: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0042adf4: { // 0x42adf4: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042adf6: { // 0x42adf6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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

void f_0002d4a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042d4a0: { // 0x42d4a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042d4a1: { // 0x42d4a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042d4a2: { // 0x42d4a2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L0042d4a6: { // 0x42d4a6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042d4a8: { // 0x42d4a8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042d4aa: { // 0x42d4aa: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042d4b1: { // 0x42d4b1: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L0042d4b4: { // 0x42d4b4: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0042d4b8: { // 0x42d4b8: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L0042d4bc: { // 0x42d4bc: c706e0757800 MOV dword ptr [ESI],0x7875e0
    m.w32((s.si), 0x007875e0u);
  }
  L0042d4c2: { // 0x42d4c2: 7447 JZ 0x0042d50b
    if(integer::condition("JZ",flags)) goto L0042d50b;
  }
  L0042d4c4: { // 0x42d4c4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0042d4c8: { // 0x42d4c8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d4ca: { // 0x42d4ca: 740f JZ 0x0042d4db
    if(integer::condition("JZ",flags)) goto L0042d4db;
  }
  L0042d4cc: { // 0x42d4cc: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d4cd: { // 0x42d4cd: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d4d0: { // 0x42d4d0: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d4d4: { // 0x42d4d4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d4d6: { // 0x42d4d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d4d7: { // 0x42d4d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d4d8: { // 0x42d4d8: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d4db: { // 0x42d4db: 8d04bd00000000 LEA EAX,[EDI*0x4 + 0x0]
    s.ax = ((s.di * 0x00000004u)+0x00000000u);
  }
  L0042d4e2: { // 0x42d4e2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042d4e3: { // 0x42d4e3: e86f043400 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4379880u,op); flags=s.arithmetic_flags;
  }
  L0042d4e8: { // 0x42d4e8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d4eb: { // 0x42d4eb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d4ed: { // 0x42d4ed: 7413 JZ 0x0042d502
    if(integer::condition("JZ",flags)) goto L0042d502;
  }
  L0042d4ef: { // 0x42d4ef: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L0042d4f0: { // 0x42d4f0: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d4f3: { // 0x42d4f3: 897c240c MOV dword ptr [ESP + 0xc],EDI
    m.w32((f.sp+0x0000000cu), s.di);
  }
  L0042d4f7: { // 0x42d4f7: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d4fb: { // 0x42d4fb: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d4fd: { // 0x42d4fd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d4fe: { // 0x42d4fe: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d4ff: { // 0x42d4ff: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d502: { // 0x42d502: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042d504: { // 0x42d504: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0042d508: { // 0x42d508: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0042d50b: { // 0x42d50b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0042d50d: { // 0x42d50d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d50e: { // 0x42d50e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d50f: { // 0x42d50f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

void f_0002d050(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042d050: { // 0x42d050: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0042d051: { // 0x42d051: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0042d052: { // 0x42d052: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L0042d056: { // 0x42d056: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0042d057: { // 0x42d057: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0042d059: { // 0x42d059: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0042d05a: { // 0x42d05a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0042d05c: { // 0x42d05c: 0f8492000000 JZ 0x0042d0f4
    if(integer::condition("JZ",flags)) goto L0042d0f4;
  }
  L0042d062: { // 0x42d062: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0042d066: { // 0x42d066: c6460c00 MOV byte ptr [ESI + 0xc],0x0
    m.w8((s.si+0x0000000cu), 0x00000000u);
  }
  L0042d06a: { // 0x42d06a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0042d06c: { // 0x42d06c: 7523 JNZ 0x0042d091
    if(integer::condition("JNZ",flags)) goto L0042d091;
  }
  L0042d06e: { // 0x42d06e: 8d04ad00000000 LEA EAX,[EBP*0x4 + 0x0]
    s.ax = ((s.bp * 0x00000004u)+0x00000000u);
  }
  L0042d075: { // 0x42d075: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042d076: { // 0x42d076: e8dc083400 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4378747u,op); flags=s.arithmetic_flags;
  }
  L0042d07b: { // 0x42d07b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d07e: { // 0x42d07e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d080: { // 0x42d080: 740b JZ 0x0042d08d
    if(integer::condition("JZ",flags)) goto L0042d08d;
  }
  L0042d082: { // 0x42d082: 8d4dff LEA ECX,[EBP + -0x1]
    s.cx = (s.bp-0x00000001u);
  }
  L0042d085: { // 0x42d085: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0042d087: { // 0x42d087: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0042d08b: { // 0x42d08b: eb0d JMP 0x0042d09a
    goto L0042d09a;
  }
  L0042d08d: { // 0x42d08d: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0042d08f: { // 0x42d08f: eb09 JMP 0x0042d09a
    goto L0042d09a;
  }
  L0042d091: { // 0x42d091: 8d55ff LEA EDX,[EBP + -0x1]
    s.dx = (s.bp-0x00000001u);
  }
  L0042d094: { // 0x42d094: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L0042d096: { // 0x42d096: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0042d09a: { // 0x42d09a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0042d09c: { // 0x42d09c: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0042d0a0: { // 0x42d0a0: 746f JZ 0x0042d111
    if(integer::condition("JZ",flags)) goto L0042d111;
  }
  L0042d0a2: { // 0x42d0a2: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0042d0a5: { // 0x42d0a5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0042d0a7: { // 0x42d0a7: 7439 JZ 0x0042d0e2
    if(integer::condition("JZ",flags)) goto L0042d0e2;
  }
  L0042d0a9: { // 0x42d0a9: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L0042d0ac: { // 0x42d0ac: 3be9 CMP EBP,ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L0042d0ae: { // 0x42d0ae: 7d02 JGE 0x0042d0b2
    if(integer::condition("JGE",flags)) goto L0042d0b2;
  }
  L0042d0b0: { // 0x42d0b0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0042d0b2: { // 0x42d0b2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042d0b4: { // 0x42d0b4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0042d0b6: { // 0x42d0b6: 7e10 JLE 0x0042d0c8
    if(integer::condition("JLE",flags)) goto L0042d0c8;
  }
  L0042d0b8: { // 0x42d0b8: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L0042d0bb: { // 0x42d0bb: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0042d0bc: { // 0x42d0bc: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042d0be: { // 0x42d0be: 8b5482fc MOV EDX,dword ptr [EDX + EAX*0x4 + -0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)-0x00000004u));
  }
  L0042d0c2: { // 0x42d0c2: 895487fc MOV dword ptr [EDI + EAX*0x4 + -0x4],EDX
    m.w32((s.di+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L0042d0c6: { // 0x42d0c6: 7cf0 JL 0x0042d0b8
    if(integer::condition("JL",flags)) goto L0042d0b8;
  }
  L0042d0c8: { // 0x42d0c8: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L0042d0cb: { // 0x42d0cb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0042d0cd: { // 0x42d0cd: 7413 JZ 0x0042d0e2
    if(integer::condition("JZ",flags)) goto L0042d0e2;
  }
  L0042d0cf: { // 0x42d0cf: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0042d0d2: { // 0x42d0d2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0042d0d3: { // 0x42d0d3: e8a3053400 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4378840u,op); flags=s.arithmetic_flags;
  }
  L0042d0d8: { // 0x42d0d8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0042d0db: { // 0x42d0db: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L0042d0e2: { // 0x42d0e2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0042d0e4: { // 0x42d0e4: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  L0042d0e7: { // 0x42d0e7: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L0042d0e9: { // 0x42d0e9: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L0042d0ec: { // 0x42d0ec: 896e08 MOV dword ptr [ESI + 0x8],EBP
    m.w32((s.si+0x00000008u), s.bp);
  }
  L0042d0ef: { // 0x42d0ef: 88460d MOV byte ptr [ESI + 0xd],AL
    m.w8((s.si+0x0000000du), (s.ax & 0xffu));
  }
  L0042d0f2: { // 0x42d0f2: eb07 JMP 0x0042d0fb
    goto L0042d0fb;
  }
  L0042d0f4: { // 0x42d0f4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0042d0f6: { // 0x42d0f6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0042d0f8: { // 0x42d0f8: ff520c CALL dword ptr [EDX + 0xc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000000cu)),4378875u,op); flags=s.arithmetic_flags;
  }
  L0042d0fb: { // 0x42d0fb: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0042d0fe: { // 0x42d0fe: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0042d101: { // 0x42d101: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0042d103: { // 0x42d103: 7d03 JGE 0x0042d108
    if(integer::condition("JGE",flags)) goto L0042d108;
  }
  L0042d105: { // 0x42d105: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0042d108: { // 0x42d108: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d109: { // 0x42d109: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d10a: { // 0x42d10a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042d10b: { // 0x42d10b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0042d10d: { // 0x42d10d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042d10e: { // 0x42d10e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0042d111: { // 0x42d111: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0042d112: { // 0x42d112: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0042d113: { // 0x42d113: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0042d114: { // 0x42d114: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0042d116: { // 0x42d116: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0042d117: { // 0x42d117: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
