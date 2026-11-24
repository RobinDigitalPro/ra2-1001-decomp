#include "recovered/recovery_b111_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b111 {
namespace {
void f_0010ddf0(Memory&,State&,Frame&,const Operations&);
void f_00093da0(Memory&,State&,Frame&,const Operations&);
void f_0036dd10(Memory&,State&,Frame&,const Operations&);
void f_002e41d0(Memory&,State&,Frame&,const Operations&);
void f_00270910(Memory&,State&,Frame&,const Operations&);
void f_0036d860(Memory&,State&,Frame&,const Operations&);
void f_0010bf50(Memory&,State&,Frame&,const Operations&);
void f_0026ac80(Memory&,State&,Frame&,const Operations&);
void f_002de9e0(Memory&,State&,Frame&,const Operations&);
void f_00378f95(Memory&,State&,Frame&,const Operations&);
void f_00378dbe(Memory&,State&,Frame&,const Operations&);
void f_00110220(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0010ddf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0050ddf0: { // 0x50ddf0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0050ddf4: { // 0x50ddf4: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0050ddf7: { // 0x50ddf7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0050ddf8: { // 0x50ddf8: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0050ddfa: { // 0x50ddfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0050ddfb: { // 0x50ddfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0050ddfc: { // 0x50ddfc: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050ddfe: { // 0x50ddfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0050ddff: { // 0x50ddff: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0050de01: { // 0x50de01: 0f843d010000 JZ 0x0050df44
    if(integer::condition("JZ",flags)) goto L0050df44;
  }
  L0050de07: { // 0x50de07: 837c243002 CMP dword ptr [ESP + 0x30],0x2
    (void)integer::sub(m.r32((f.sp+0x00000030u)),0x00000002u,32,flags);
  }
  L0050de0c: { // 0x50de0c: 0f8c32010000 JL 0x0050df44
    if(integer::condition("JL",flags)) goto L0050df44;
  }
  L0050de12: { // 0x50de12: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0050de16: { // 0x50de16: 3bd3 CMP EDX,EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L0050de18: { // 0x50de18: 0f8426010000 JZ 0x0050df44
    if(integer::condition("JZ",flags)) goto L0050df44;
  }
  L0050de1e: { // 0x50de1e: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0050de22: { // 0x50de22: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L0050de24: { // 0x50de24: 0f841a010000 JZ 0x0050df44
    if(integer::condition("JZ",flags)) goto L0050df44;
  }
  L0050de2a: { // 0x50de2a: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0050de2c: { // 0x50de2c: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0050de2f: { // 0x50de2f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0050de31: { // 0x50de31: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0050de35: { // 0x50de35: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0050de37: { // 0x50de37: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L0050de39: { // 0x50de39: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0050de3a: { // 0x50de3a: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0050de3e: { // 0x50de3e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0050de3f: { // 0x50de3f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0050de40: { // 0x50de40: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0050de44: { // 0x50de44: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0050de48: { // 0x50de48: e8535ff8ff CALL 0x00493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,5299789u); flags=s.arithmetic_flags;
  }
  L0050de4d: { // 0x50de4d: 83c620 ADD ESI,0x20
    s.si = integer::add(s.si,0x00000020u,32,flags);
  }
  L0050de50: { // 0x50de50: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0050de52: { // 0x50de52: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L0050de56: { // 0x50de56: 395e04 CMP dword ptr [ESI + 0x4],EBX
    (void)integer::sub(m.r32((s.si+0x00000004u)),s.bx,32,flags);
  }
  L0050de59: { // 0x50de59: 0f84d7000000 JZ 0x0050df36
    if(integer::condition("JZ",flags)) goto L0050df36;
  }
  L0050de5f: { // 0x50de5f: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0050de62: { // 0x50de62: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050de64: { // 0x50de64: 7404 JZ 0x0050de6a
    if(integer::condition("JZ",flags)) goto L0050de6a;
  }
  L0050de66: { // 0x50de66: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L0050de68: { // 0x50de68: 7417 JZ 0x0050de81
    if(integer::condition("JZ",flags)) goto L0050de81;
  }
  L0050de6a: { // 0x50de6a: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0050de6e: { // 0x50de6e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0050de70: { // 0x50de70: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050de71: { // 0x50de71: e85a280000 CALL 0x005106d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005106d0u,5299830u); flags=s.arithmetic_flags;
  }
  L0050de76: { // 0x50de76: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050de78: { // 0x50de78: 0f84b8000000 JZ 0x0050df36
    if(integer::condition("JZ",flags)) goto L0050df36;
  }
  L0050de7e: { // 0x50de7e: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0050de81: { // 0x50de81: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0050de84: { // 0x50de84: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L0050de88: { // 0x50de88: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050de8a: { // 0x50de8a: 7426 JZ 0x0050deb2
    if(integer::condition("JZ",flags)) goto L0050deb2;
  }
  L0050de8c: { // 0x50de8c: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0050de8f: { // 0x50de8f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050de91: { // 0x50de91: 7404 JZ 0x0050de97
    if(integer::condition("JZ",flags)) goto L0050de97;
  }
  L0050de93: { // 0x50de93: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L0050de95: { // 0x50de95: 7413 JZ 0x0050deaa
    if(integer::condition("JZ",flags)) goto L0050deaa;
  }
  L0050de97: { // 0x50de97: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0050de9b: { // 0x50de9b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0050de9c: { // 0x50de9c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0050de9e: { // 0x50de9e: e82d280000 CALL 0x005106d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005106d0u,5299875u); flags=s.arithmetic_flags;
  }
  L0050dea3: { // 0x50dea3: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050dea5: { // 0x50dea5: 740b JZ 0x0050deb2
    if(integer::condition("JZ",flags)) goto L0050deb2;
  }
  L0050dea7: { // 0x50dea7: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0050deaa: { // 0x50deaa: 8b7610 MOV ESI,dword ptr [ESI + 0x10]
    s.si = m.r32((s.si+0x00000010u));
  }
  L0050dead: { // 0x50dead: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0050deb0: { // 0x50deb0: eb05 JMP 0x0050deb7
    goto L0050deb7;
  }
  L0050deb2: { // 0x50deb2: beac0ab100 MOV ESI,0xb10aac
    s.si = 0x00b10aacu;
  }
  L0050deb7: { // 0x50deb7: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L0050deb9: { // 0x50deb9: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0050debb: { // 0x50debb: 7479 JZ 0x0050df36
    if(integer::condition("JZ",flags)) goto L0050df36;
  }
  L0050debd: { // 0x50debd: 8bfd MOV EDI,EBP
    s.di = s.bp;
  }
  L0050debf: { // 0x50debf: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0050dec2: { // 0x50dec2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0050dec4: { // 0x50dec4: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0050dec8: { // 0x50dec8: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0050deca: { // 0x50deca: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L0050decc: { // 0x50decc: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0050decd: { // 0x50decd: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0050ded1: { // 0x50ded1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0050ded2: { // 0x50ded2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0050ded3: { // 0x50ded3: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0050ded7: { // 0x50ded7: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0050dedb: { // 0x50dedb: e8c05ef8ff CALL 0x00493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,5299936u); flags=s.arithmetic_flags;
  }
  L0050dee0: { // 0x50dee0: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  L0050dee3: { // 0x50dee3: 83c62c ADD ESI,0x2c
    s.si = integer::add(s.si,0x0000002cu,32,flags);
  }
  L0050dee6: { // 0x50dee6: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0050dee8: { // 0x50dee8: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0050deec: { // 0x50deec: 7448 JZ 0x0050df36
    if(integer::condition("JZ",flags)) goto L0050df36;
  }
  L0050deee: { // 0x50deee: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0050def1: { // 0x50def1: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0050def3: { // 0x50def3: 7404 JZ 0x0050def9
    if(integer::condition("JZ",flags)) goto L0050def9;
  }
  L0050def5: { // 0x50def5: 3901 CMP dword ptr [ECX],EAX
    (void)integer::sub(m.r32((s.cx)),s.ax,32,flags);
  }
  L0050def7: { // 0x50def7: 7413 JZ 0x0050df0c
    if(integer::condition("JZ",flags)) goto L0050df0c;
  }
  L0050def9: { // 0x50def9: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0050defd: { // 0x50defd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0050deff: { // 0x50deff: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0050df00: { // 0x50df00: e89b260000 CALL 0x005105a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005105a0u,5299973u); flags=s.arithmetic_flags;
  }
  L0050df05: { // 0x50df05: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050df07: { // 0x50df07: 742d JZ 0x0050df36
    if(integer::condition("JZ",flags)) goto L0050df36;
  }
  L0050df09: { // 0x50df09: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0050df0c: { // 0x50df0c: 8d442420 LEA EAX,[ESP + 0x20]
    s.ax = (f.sp+0x00000020u);
  }
  L0050df10: { // 0x50df10: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0050df12: { // 0x50df12: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050df13: { // 0x50df13: e808230000 CALL 0x00510220
    s.arithmetic_flags=flags; invoke(m,s,f,0x00510220u,5299992u); flags=s.arithmetic_flags;
  }
  L0050df18: { // 0x50df18: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0050df1a: { // 0x50df1a: 7408 JZ 0x0050df24
    if(integer::condition("JZ",flags)) goto L0050df24;
  }
  L0050df1c: { // 0x50df1c: 8b7610 MOV ESI,dword ptr [ESI + 0x10]
    s.si = m.r32((s.si+0x00000010u));
  }
  L0050df1f: { // 0x50df1f: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0050df22: { // 0x50df22: eb05 JMP 0x0050df29
    goto L0050df29;
  }
  L0050df24: { // 0x50df24: beb00ab100 MOV ESI,0xb10ab0
    s.si = 0x00b10ab0u;
  }
  L0050df29: { // 0x50df29: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L0050df2b: { // 0x50df2b: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L0050df2d: { // 0x50df2d: 7407 JZ 0x0050df36
    if(integer::condition("JZ",flags)) goto L0050df36;
  }
  L0050df2f: { // 0x50df2f: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0050df32: { // 0x50df32: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050df34: { // 0x50df34: 751a JNZ 0x0050df50
    if(integer::condition("JNZ",flags)) goto L0050df50;
  }
  L0050df36: { // 0x50df36: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0050df3a: { // 0x50df3a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0050df3c: { // 0x50df3c: 7512 JNZ 0x0050df50
    if(integer::condition("JNZ",flags)) goto L0050df50;
  }
  L0050df3e: { // 0x50df3e: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0050df42: { // 0x50df42: 8819 MOV byte ptr [ECX],BL
    m.w8((s.cx), (s.bx & 0xffu));
  }
  L0050df44: { // 0x50df44: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050df45: { // 0x50df45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050df46: { // 0x50df46: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0050df47: { // 0x50df47: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0050df49: { // 0x50df49: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0050df4a: { // 0x50df4a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0050df4d: { // 0x50df4d: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
  L0050df50: { // 0x50df50: 8b742430 MOV ESI,dword ptr [ESP + 0x30]
    s.si = m.r32((f.sp+0x00000030u));
  }
  L0050df54: { // 0x50df54: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  L0050df58: { // 0x50df58: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0050df59: { // 0x50df59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050df5a: { // 0x50df5a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0050df5b: { // 0x50df5b: e8b0fd2500 CALL 0x0076dd10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076dd10u,5300064u); flags=s.arithmetic_flags;
  }
  L0050df60: { // 0x50df60: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0050df63: { // 0x50df63: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0050df65: { // 0x50df65: 885c37ff MOV byte ptr [EDI + ESI*0x1 + -0x1],BL
    m.w8((s.di+(s.si * 0x00000001u)-0x00000001u), (s.bx & 0xffu));
  }
  L0050df69: { // 0x50df69: e862621d00 CALL 0x006e41d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e41d0u,5300078u); flags=s.arithmetic_flags;
  }
  L0050df6e: { // 0x50df6e: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0050df71: { // 0x50df71: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0050df73: { // 0x50df73: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0050df75: { // 0x50df75: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L0050df77: { // 0x50df77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050df78: { // 0x50df78: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0050df79: { // 0x50df79: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050df7a: { // 0x50df7a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0050df7b: { // 0x50df7b: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0050df7d: { // 0x50df7d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0050df7e: { // 0x50df7e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0050df81: { // 0x50df81: c21400 RET 0x14
    s.arithmetic_flags=flags; finish(m,s,f,20u); return;
  }
}
void f_00093da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00493da0: { // 0x493da0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00493da1: { // 0x493da1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00493da2: { // 0x493da2: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L00493da6: { // 0x493da6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493da8: { // 0x493da8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00493da9: { // 0x493da9: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L00493dab: { // 0x493dab: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00493dac: { // 0x493dac: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00493dae: { // 0x493dae: 0f844c010000 JZ 0x00493f00
    if(integer::condition("JZ",flags)) goto L00493f00;
  }
  L00493db4: { // 0x493db4: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00493db8: { // 0x493db8: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493dba: { // 0x493dba: 0f8e40010000 JLE 0x00493f00
    if(integer::condition("JLE",flags)) goto L00493f00;
  }
  L00493dc0: { // 0x493dc0: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493dc3: { // 0x493dc3: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493dc5: { // 0x493dc5: 7454 JZ 0x00493e1b
    if(integer::condition("JZ",flags)) goto L00493e1b;
  }
  L00493dc7: { // 0x493dc7: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  L00493dcc: { // 0x493dcc: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493dce: { // 0x493dce: 734b JNC 0x00493e1b
    if(integer::condition("JNC",flags)) goto L00493e1b;
  }
  L00493dd0: { // 0x493dd0: 8a4d00 MOV CL,byte ptr [EBP]
    s.cx = with_al(s.cx, m.r8((s.bp)));
  }
  L00493dd3: { // 0x493dd3: 884c3008 MOV byte ptr [EAX + ESI*0x1 + 0x8],CL
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493dd7: { // 0x493dd7: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00493dda: { // 0x493dda: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493ddb: { // 0x493ddb: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00493ddd: { // 0x493ddd: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00493de0: { // 0x493de0: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493de2: { // 0x493de2: 7531 JNZ 0x00493e15
    if(integer::condition("JNZ",flags)) goto L00493e15;
  }
  L00493de4: { // 0x493de4: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00493de6: { // 0x493de6: 88460c MOV byte ptr [ESI + 0xc],AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  L00493de9: { // 0x493de9: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493dec: { // 0x493dec: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493ded: { // 0x493ded: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493def: { // 0x493def: 730c JNC 0x00493dfd
    if(integer::condition("JNC",flags)) goto L00493dfd;
  }
  L00493df1: { // 0x493df1: 8a4e08 MOV CL,byte ptr [ESI + 0x8]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000008u)));
  }
  L00493df4: { // 0x493df4: 884c0608 MOV byte ptr [ESI + EAX*0x1 + 0x8],CL
    m.w8((s.si+(s.ax * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493df8: { // 0x493df8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493df9: { // 0x493df9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00493dfb: { // 0x493dfb: 72f4 JC 0x00493df1
    if(integer::condition("JC",flags)) goto L00493df1;
  }
  L00493dfd: { // 0x493dfd: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00493dff: { // 0x493dff: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00493e02: { // 0x493e02: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00493e03: { // 0x493e03: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00493e07: { // 0x493e07: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00493e0b: { // 0x493e0b: e860010000 CALL 0x00493f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493f70u,4800016u); flags=s.arithmetic_flags;
  }
  L00493e10: { // 0x493e10: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00493e12: { // 0x493e12: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00493e15: { // 0x493e15: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00493e16: { // 0x493e16: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493e17: { // 0x493e17: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493e19: { // 0x493e19: 7fa5 JG 0x00493dc0
    if(integer::condition("JG",flags)) goto L00493dc0;
  }
  L00493e1b: { // 0x493e1b: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00493e1d: { // 0x493e1d: c1e802 SHR EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::right);
  }
  L00493e20: { // 0x493e20: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00493e22: { // 0x493e22: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493e23: { // 0x493e23: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00493e25: { // 0x493e25: 744f JZ 0x00493e76
    if(integer::condition("JZ",flags)) goto L00493e76;
  }
  L00493e27: { // 0x493e27: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493e28: { // 0x493e28: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493e2c: { // 0x493e2c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00493e2e: { // 0x493e2e: 8d0487 LEA EAX,[EDI + EAX*0x4]
    s.ax = (s.di+(s.ax * 0x00000004u));
  }
  L00493e31: { // 0x493e31: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00493e35: { // 0x493e35: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493e37: { // 0x493e37: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00493e39: { // 0x493e39: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493e3b: { // 0x493e3b: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L00493e40: { // 0x493e40: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00493e42: { // 0x493e42: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493e44: { // 0x493e44: 8a19 MOV BL,byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00493e46: { // 0x493e46: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493e4c: { // 0x493e4c: 33d3 XOR EDX,EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493e4e: { // 0x493e4e: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00493e51: { // 0x493e51: 8b149534067c00 MOV EDX,dword ptr [EDX*0x4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x007c0634u));
  }
  L00493e58: { // 0x493e58: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493e5a: { // 0x493e5a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493e5b: { // 0x493e5b: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493e5c: { // 0x493e5c: 75e2 JNZ 0x00493e40
    if(integer::condition("JNZ",flags)) goto L00493e40;
  }
  L00493e5e: { // 0x493e5e: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493e60: { // 0x493e60: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00493e62: { // 0x493e62: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00493e66: { // 0x493e66: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L00493e69: { // 0x493e69: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493e6a: { // 0x493e6a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493e6e: { // 0x493e6e: 75c5 JNZ 0x00493e35
    if(integer::condition("JNZ",flags)) goto L00493e35;
  }
  L00493e70: { // 0x493e70: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L00493e74: { // 0x493e74: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493e76: { // 0x493e76: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L00493e78: { // 0x493e78: 0f8e82000000 JLE 0x00493f00
    if(integer::condition("JLE",flags)) goto L00493f00;
  }
  L00493e7e: { // 0x493e7e: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00493e82: { // 0x493e82: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493e85: { // 0x493e85: 8a4d00 MOV CL,byte ptr [EBP]
    s.cx = with_al(s.cx, m.r8((s.bp)));
  }
  L00493e88: { // 0x493e88: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493e8a: { // 0x493e8a: 7503 JNZ 0x00493e8f
    if(integer::condition("JNZ",flags)) goto L00493e8f;
  }
  L00493e8c: { // 0x493e8c: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L00493e8f: { // 0x493e8f: 884c3008 MOV byte ptr [EAX + ESI*0x1 + 0x8],CL
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493e93: { // 0x493e93: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00493e96: { // 0x493e96: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493e97: { // 0x493e97: bf04000000 MOV EDI,0x4
    s.di = 0x00000004u;
  }
  L00493e9c: { // 0x493e9c: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00493e9e: { // 0x493e9e: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00493ea1: { // 0x493ea1: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493ea3: { // 0x493ea3: 754f JNZ 0x00493ef4
    if(integer::condition("JNZ",flags)) goto L00493ef4;
  }
  L00493ea5: { // 0x493ea5: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L00493ea7: { // 0x493ea7: 88460c MOV byte ptr [ESI + 0xc],AL
    m.w8((s.si+0x0000000cu), (s.ax & 0xffu));
  }
  L00493eaa: { // 0x493eaa: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493ead: { // 0x493ead: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493eae: { // 0x493eae: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493eb0: { // 0x493eb0: 730c JNC 0x00493ebe
    if(integer::condition("JNC",flags)) goto L00493ebe;
  }
  L00493eb2: { // 0x493eb2: 8a4e08 MOV CL,byte ptr [ESI + 0x8]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000008u)));
  }
  L00493eb5: { // 0x493eb5: 884c0608 MOV byte ptr [ESI + EAX*0x1 + 0x8],CL
    m.w8((s.si+(s.ax * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493eb9: { // 0x493eb9: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493eba: { // 0x493eba: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00493ebc: { // 0x493ebc: 72f4 JC 0x00493eb2
    if(integer::condition("JC",flags)) goto L00493eb2;
  }
  L00493ebe: { // 0x493ebe: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L00493ec1: { // 0x493ec1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493ec3: { // 0x493ec3: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00493ec7: { // 0x493ec7: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00493ecb: { // 0x493ecb: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493ecd: { // 0x493ecd: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00493ecf: { // 0x493ecf: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493ed1: { // 0x493ed1: 8a19 MOV BL,byte ptr [ECX]
    s.bx = with_al(s.bx, m.r8((s.cx)));
  }
  L00493ed3: { // 0x493ed3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493ed9: { // 0x493ed9: 33d3 XOR EDX,EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493edb: { // 0x493edb: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  L00493ede: { // 0x493ede: 8b149534067c00 MOV EDX,dword ptr [EDX*0x4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x007c0634u));
  }
  L00493ee5: { // 0x493ee5: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00493ee7: { // 0x493ee7: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00493ee8: { // 0x493ee8: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00493ee9: { // 0x493ee9: 75e2 JNZ 0x00493ecd
    if(integer::condition("JNZ",flags)) goto L00493ecd;
  }
  L00493eeb: { // 0x493eeb: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  L00493eed: { // 0x493eed: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493eef: { // 0x493eef: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00493ef1: { // 0x493ef1: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00493ef4: { // 0x493ef4: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00493ef8: { // 0x493ef8: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00493ef9: { // 0x493ef9: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00493efa: { // 0x493efa: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493efe: { // 0x493efe: 7582 JNZ 0x00493e82
    if(integer::condition("JNZ",flags)) goto L00493e82;
  }
  L00493f00: { // 0x493f00: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493f03: { // 0x493f03: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00493f05: { // 0x493f05: 7459 JZ 0x00493f60
    if(integer::condition("JZ",flags)) goto L00493f60;
  }
  L00493f07: { // 0x493f07: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L00493f09: { // 0x493f09: 884c3008 MOV byte ptr [EAX + ESI*0x1 + 0x8],CL
    m.w8((s.ax+(s.si * 0x00000001u)+0x00000008u), (s.cx & 0xffu));
  }
  L00493f0d: { // 0x493f0d: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00493f10: { // 0x493f10: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f11: { // 0x493f11: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00493f14: { // 0x493f14: 730d JNC 0x00493f23
    if(integer::condition("JNC",flags)) goto L00493f23;
  }
  L00493f16: { // 0x493f16: 8a5608 MOV DL,byte ptr [ESI + 0x8]
    s.dx = with_al(s.dx, m.r8((s.si+0x00000008u)));
  }
  L00493f19: { // 0x493f19: 88540608 MOV byte ptr [ESI + EAX*0x1 + 0x8],DL
    m.w8((s.si+(s.ax * 0x00000001u)+0x00000008u), (s.dx & 0xffu));
  }
  L00493f1d: { // 0x493f1d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f1e: { // 0x493f1e: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00493f21: { // 0x493f21: 72f3 JC 0x00493f16
    if(integer::condition("JC",flags)) goto L00493f16;
  }
  L00493f23: { // 0x493f23: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00493f26: { // 0x493f26: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L00493f28: { // 0x493f28: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00493f2c: { // 0x493f2c: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00493f30: { // 0x493f30: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  L00493f32: { // 0x493f32: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L00493f37: { // 0x493f37: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00493f39: { // 0x493f39: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00493f3b: { // 0x493f3b: 8a18 MOV BL,byte ptr [EAX]
    s.bx = with_al(s.bx, m.r8((s.ax)));
  }
  L00493f3d: { // 0x493f3d: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00493f43: { // 0x493f43: 33d3 XOR EDX,EBX
    s.dx = integer::logical((s.dx)^(s.bx),32,flags);
  }
  L00493f45: { // 0x493f45: c1ee08 SHR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::right);
  }
  L00493f48: { // 0x493f48: 8b149534067c00 MOV EDX,dword ptr [EDX*0x4 + 0x7c0634]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x007c0634u));
  }
  L00493f4f: { // 0x493f4f: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L00493f51: { // 0x493f51: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00493f52: { // 0x493f52: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00493f53: { // 0x493f53: 75e2 JNZ 0x00493f37
    if(integer::condition("JNZ",flags)) goto L00493f37;
  }
  L00493f55: { // 0x493f55: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  L00493f57: { // 0x493f57: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00493f59: { // 0x493f59: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493f5a: { // 0x493f5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493f5b: { // 0x493f5b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493f5c: { // 0x493f5c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493f5d: { // 0x493f5d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00493f60: { // 0x493f60: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00493f62: { // 0x493f62: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00493f63: { // 0x493f63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00493f64: { // 0x493f64: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00493f65: { // 0x493f65: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00493f66: { // 0x493f66: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0036dd10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076dd10: { // 0x76dd10: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0076dd14: { // 0x76dd14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076dd15: { // 0x76dd15: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0076dd17: { // 0x76dd17: 747a JZ 0x0076dd93
    if(integer::condition("JZ",flags)) goto L0076dd93;
  }
  L0076dd19: { // 0x76dd19: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076dd1a: { // 0x76dd1a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076dd1b: { // 0x76dd1b: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd1d: { // 0x76dd1d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0076dd21: { // 0x76dd21: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd27: { // 0x76dd27: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0076dd2b: { // 0x76dd2b: 7507 JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd2d: { // 0x76dd2d: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd30: { // 0x76dd30: 756f JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd32: { // 0x76dd32: eb21 JMP 0x0076dd55
    goto L0076dd55;
  }
  L0076dd34: { // 0x76dd34: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd36: { // 0x76dd36: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd37: { // 0x76dd37: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd39: { // 0x76dd39: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd3a: { // 0x76dd3a: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd3b: { // 0x76dd3b: 7425 JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd3d: { // 0x76dd3d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd3f: { // 0x76dd3f: 7429 JZ 0x0076dd6a
    if(integer::condition("JZ",flags)) goto L0076dd6a;
  }
  L0076dd41: { // 0x76dd41: f7c603000000 TEST ESI,0x3
    (void)integer::logical((s.si)&(0x00000003u),32,flags);
  }
  L0076dd47: { // 0x76dd47: 75eb JNZ 0x0076dd34
    if(integer::condition("JNZ",flags)) goto L0076dd34;
  }
  L0076dd49: { // 0x76dd49: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd4b: { // 0x76dd4b: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd4e: { // 0x76dd4e: 7551 JNZ 0x0076dda1
    if(integer::condition("JNZ",flags)) goto L0076dda1;
  }
  L0076dd50: { // 0x76dd50: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076dd53: { // 0x76dd53: 740d JZ 0x0076dd62
    if(integer::condition("JZ",flags)) goto L0076dd62;
  }
  L0076dd55: { // 0x76dd55: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076dd57: { // 0x76dd57: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076dd58: { // 0x76dd58: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd5a: { // 0x76dd5a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd5b: { // 0x76dd5b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0076dd5d: { // 0x76dd5d: 742f JZ 0x0076dd8e
    if(integer::condition("JZ",flags)) goto L0076dd8e;
  }
  L0076dd5f: { // 0x76dd5f: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd60: { // 0x76dd60: 75f3 JNZ 0x0076dd55
    if(integer::condition("JNZ",flags)) goto L0076dd55;
  }
  L0076dd62: { // 0x76dd62: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076dd66: { // 0x76dd66: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd67: { // 0x76dd67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd68: { // 0x76dd68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd69: { // 0x76dd69: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd6a: { // 0x76dd6a: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd70: { // 0x76dd70: 7412 JZ 0x0076dd84
    if(integer::condition("JZ",flags)) goto L0076dd84;
  }
  L0076dd72: { // 0x76dd72: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd74: { // 0x76dd74: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd75: { // 0x76dd75: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd76: { // 0x76dd76: 0f848a000000 JZ 0x0076de06
    if(integer::condition("JZ",flags)) goto L0076de06;
  }
  L0076dd7c: { // 0x76dd7c: f7c703000000 TEST EDI,0x3
    (void)integer::logical((s.di)&(0x00000003u),32,flags);
  }
  L0076dd82: { // 0x76dd82: 75ee JNZ 0x0076dd72
    if(integer::condition("JNZ",flags)) goto L0076dd72;
  }
  L0076dd84: { // 0x76dd84: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0076dd86: { // 0x76dd86: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0076dd89: { // 0x76dd89: 756c JNZ 0x0076ddf7
    if(integer::condition("JNZ",flags)) goto L0076ddf7;
  }
  L0076dd8b: { // 0x76dd8b: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0076dd8d: { // 0x76dd8d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076dd8e: { // 0x76dd8e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0076dd8f: { // 0x76dd8f: 75fa JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076dd91: { // 0x76dd91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076dd92: { // 0x76dd92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076dd93: { // 0x76dd93: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0076dd97: { // 0x76dd97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076dd98: { // 0x76dd98: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076dd99: { // 0x76dd99: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dd9b: { // 0x76dd9b: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076dd9e: { // 0x76dd9e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076dd9f: { // 0x76dd9f: 74af JZ 0x0076dd50
    if(integer::condition("JZ",flags)) goto L0076dd50;
  }
  L0076dda1: { // 0x76dda1: bafffefe7e MOV EDX,0x7efefeff
    s.dx = 0x7efefeffu;
  }
  L0076dda6: { // 0x76dda6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0076dda8: { // 0x76dda8: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0076ddaa: { // 0x76ddaa: 83f0ff XOR EAX,0xffffffff
    s.ax = integer::logical((s.ax)^(0xffffffffu),32,flags);
  }
  L0076ddad: { // 0x76ddad: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0076ddaf: { // 0x76ddaf: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0076ddb1: { // 0x76ddb1: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0076ddb4: { // 0x76ddb4: a900010181 TEST EAX,0x81010100
    (void)integer::logical((s.ax)&(0x81010100u),32,flags);
  }
  L0076ddb9: { // 0x76ddb9: 74de JZ 0x0076dd99
    if(integer::condition("JZ",flags)) goto L0076dd99;
  }
  L0076ddbb: { // 0x76ddbb: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0076ddbd: { // 0x76ddbd: 742c JZ 0x0076ddeb
    if(integer::condition("JZ",flags)) goto L0076ddeb;
  }
  L0076ddbf: { // 0x76ddbf: 84f6 TEST DH,DH
    (void)integer::logical((((s.dx >> 8) & 0xffu))&(((s.dx >> 8) & 0xffu)),8,flags);
  }
  L0076ddc1: { // 0x76ddc1: 741e JZ 0x0076dde1
    if(integer::condition("JZ",flags)) goto L0076dde1;
  }
  L0076ddc3: { // 0x76ddc3: f7c20000ff00 TEST EDX,0xff0000
    (void)integer::logical((s.dx)&(0x00ff0000u),32,flags);
  }
  L0076ddc9: { // 0x76ddc9: 740c JZ 0x0076ddd7
    if(integer::condition("JZ",flags)) goto L0076ddd7;
  }
  L0076ddcb: { // 0x76ddcb: f7c2000000ff TEST EDX,0xff000000
    (void)integer::logical((s.dx)&(0xff000000u),32,flags);
  }
  L0076ddd1: { // 0x76ddd1: 75c6 JNZ 0x0076dd99
    if(integer::condition("JNZ",flags)) goto L0076dd99;
  }
  L0076ddd3: { // 0x76ddd3: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddd5: { // 0x76ddd5: eb18 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddd7: { // 0x76ddd7: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076dddd: { // 0x76dddd: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dddf: { // 0x76dddf: eb0e JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076dde1: { // 0x76dde1: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0076dde7: { // 0x76dde7: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076dde9: { // 0x76dde9: eb04 JMP 0x0076ddef
    goto L0076ddef;
  }
  L0076ddeb: { // 0x76ddeb: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0076dded: { // 0x76dded: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L0076ddef: { // 0x76ddef: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddf2: { // 0x76ddf2: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf4: { // 0x76ddf4: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddf5: { // 0x76ddf5: 740a JZ 0x0076de01
    if(integer::condition("JZ",flags)) goto L0076de01;
  }
  L0076ddf7: { // 0x76ddf7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0076ddf9: { // 0x76ddf9: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L0076ddfb: { // 0x76ddfb: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L0076ddfe: { // 0x76ddfe: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0076ddff: { // 0x76ddff: 75f8 JNZ 0x0076ddf9
    if(integer::condition("JNZ",flags)) goto L0076ddf9;
  }
  L0076de01: { // 0x76de01: 83e303 AND EBX,0x3
    s.bx = integer::logical((s.bx)&(0x00000003u),32,flags);
  }
  L0076de04: { // 0x76de04: 7585 JNZ 0x0076dd8b
    if(integer::condition("JNZ",flags)) goto L0076dd8b;
  }
  L0076de06: { // 0x76de06: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0076de0a: { // 0x76de0a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076de0b: { // 0x76de0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076de0c: { // 0x76de0c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076de0d: { // 0x76de0d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002e41d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e41d0: { // 0x6e41d0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L006e41d2: { // 0x6e41d2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006e41d3: { // 0x6e41d3: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006e41d5: { // 0x6e41d5: 745c JZ 0x006e4233
    if(integer::condition("JZ",flags)) goto L006e4233;
  }
  L006e41d7: { // 0x6e41d7: 8a02 MOV AL,byte ptr [EDX]
    s.ax = with_al(s.ax, m.r8((s.dx)));
  }
  L006e41d9: { // 0x6e41d9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e41da: { // 0x6e41da: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e41dc: { // 0x6e41dc: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L006e41de: { // 0x6e41de: 7431 JZ 0x006e4211
    if(integer::condition("JZ",flags)) goto L006e4211;
  }
  L006e41e0: { // 0x6e41e0: 3c20 CMP AL,0x20
    (void)integer::sub((s.ax & 0xffu),0x00000020u,8,flags);
  }
  L006e41e2: { // 0x6e41e2: 7708 JA 0x006e41ec
    if(integer::condition("JA",flags)) goto L006e41ec;
  }
  L006e41e4: { // 0x6e41e4: 8a4301 MOV AL,byte ptr [EBX + 0x1]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000001u)));
  }
  L006e41e7: { // 0x6e41e7: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L006e41e8: { // 0x6e41e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006e41ea: { // 0x6e41ea: 75f4 JNZ 0x006e41e0
    if(integer::condition("JNZ",flags)) goto L006e41e0;
  }
  L006e41ec: { // 0x6e41ec: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L006e41ee: { // 0x6e41ee: 7421 JZ 0x006e4211
    if(integer::condition("JZ",flags)) goto L006e4211;
  }
  L006e41f0: { // 0x6e41f0: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  L006e41f2: { // 0x6e41f2: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L006e41f5: { // 0x6e41f5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006e41f7: { // 0x6e41f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e41f8: { // 0x6e41f8: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L006e41fa: { // 0x6e41fa: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L006e41fc: { // 0x6e41fc: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006e41fe: { // 0x6e41fe: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006e4200: { // 0x6e4200: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L006e4202: { // 0x6e4202: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006e4204: { // 0x6e4204: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L006e4207: { // 0x6e4207: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L006e4209: { // 0x6e4209: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006e420b: { // 0x6e420b: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L006e420e: { // 0x6e420e: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L006e4210: { // 0x6e4210: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e4211: { // 0x6e4211: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006e4213: { // 0x6e4213: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L006e4216: { // 0x6e4216: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006e4218: { // 0x6e4218: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L006e421a: { // 0x6e421a: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L006e421c: { // 0x6e421c: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006e421d: { // 0x6e421d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e421e: { // 0x6e421e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006e421f: { // 0x6e421f: 7812 JS 0x006e4233
    if(integer::condition("JS",flags)) goto L006e4233;
  }
  L006e4221: { // 0x6e4221: 803b00 CMP byte ptr [EBX],0x0
    (void)integer::sub(m.r8((s.bx)),0x00000000u,8,flags);
  }
  L006e4224: { // 0x6e4224: 740d JZ 0x006e4233
    if(integer::condition("JZ",flags)) goto L006e4233;
  }
  L006e4226: { // 0x6e4226: 803c1120 CMP byte ptr [ECX + EDX*0x1],0x20
    (void)integer::sub(m.r8((s.cx+(s.dx * 0x00000001u))),0x00000020u,8,flags);
  }
  L006e422a: { // 0x6e422a: 7707 JA 0x006e4233
    if(integer::condition("JA",flags)) goto L006e4233;
  }
  L006e422c: { // 0x6e422c: c6041100 MOV byte ptr [ECX + EDX*0x1],0x0
    m.w8((s.cx+(s.dx * 0x00000001u)), 0x00000000u);
  }
  L006e4230: { // 0x6e4230: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L006e4231: { // 0x6e4231: 79ee JNS 0x006e4221
    if(integer::condition("JNS",flags)) goto L006e4221;
  }
  L006e4233: { // 0x6e4233: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L006e4235: { // 0x6e4235: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e4236: { // 0x6e4236: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00270910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00670910: { // 0x670910: a1f0e48400 MOV EAX,[0x0084e4f0]
    s.ax = m.r32((0x0084e4f0u));
  }
  L00670915: { // 0x670915: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00670916: { // 0x670916: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00670918: { // 0x670918: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00670919: { // 0x670919: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0067091b: { // 0x67091b: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0067091d: { // 0x67091d: 7e23 JLE 0x00670942
    if(integer::condition("JLE",flags)) goto L00670942;
  }
  L0067091f: { // 0x67091f: a1e4e48400 MOV EAX,[0x0084e4e4]
    s.ax = m.r32((0x0084e4e4u));
  }
  L00670924: { // 0x670924: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00670925: { // 0x670925: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L00670928: { // 0x670928: 83c124 ADD ECX,0x24
    s.cx = integer::add(s.cx,0x00000024u,32,flags);
  }
  L0067092b: { // 0x67092b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0067092c: { // 0x67092c: e82fcf0f00 CALL 0x0076d860
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d860u,6752561u); flags=s.arithmetic_flags;
  }
  L00670931: { // 0x670931: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00670934: { // 0x670934: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00670936: { // 0x670936: 7410 JZ 0x00670948
    if(integer::condition("JZ",flags)) goto L00670948;
  }
  L00670938: { // 0x670938: a1f0e48400 MOV EAX,[0x0084e4f0]
    s.ax = m.r32((0x0084e4f0u));
  }
  L0067093d: { // 0x67093d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0067093e: { // 0x67093e: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00670940: { // 0x670940: 7cdd JL 0x0067091f
    if(integer::condition("JL",flags)) goto L0067091f;
  }
  L00670942: { // 0x670942: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00670943: { // 0x670943: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00670946: { // 0x670946: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00670947: { // 0x670947: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00670948: { // 0x670948: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0067094a: { // 0x67094a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0067094b: { // 0x67094b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0067094c: { // 0x67094c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0036d860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076d860: { // 0x76d860: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0076d861: { // 0x76d861: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0076d863: { // 0x76d863: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0076d864: { // 0x76d864: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0076d865: { // 0x76d865: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076d866: { // 0x76d866: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0076d869: { // 0x76d869: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  L0076d86c: { // 0x76d86c: 8d052805b100 LEA EAX,[0xb10528]
    s.ax = (0x00b10528u);
  }
  L0076d872: { // 0x76d872: 83780800 CMP dword ptr [EAX + 0x8],0x0
    (void)integer::sub(m.r32((s.ax+0x00000008u)),0x00000000u,32,flags);
  }
  L0076d876: { // 0x76d876: 753b JNZ 0x0076d8b3
    if(integer::condition("JNZ",flags)) goto L0076d8b3;
  }
  L0076d878: { // 0x76d878: b0ff MOV AL,0xff
    s.ax = with_al(s.ax, 0x000000ffu);
  }
  L0076d87a: { // 0x76d87a: 8bff MOV EDI,EDI
    s.di = s.di;
  }
  L0076d87c: { // 0x76d87c: 0ac0 OR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L0076d87e: { // 0x76d87e: 742e JZ 0x0076d8ae
    if(integer::condition("JZ",flags)) goto L0076d8ae;
  }
  L0076d880: { // 0x76d880: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076d882: { // 0x76d882: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076d883: { // 0x76d883: 8a27 MOV AH,byte ptr [EDI]
    s.ax = (s.ax & 0xffff00ffu) | (((m.r8((s.di))) & 0xffu) << 8);
  }
  L0076d885: { // 0x76d885: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076d886: { // 0x76d886: 38c4 CMP AH,AL
    (void)integer::sub(((s.ax >> 8) & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0076d888: { // 0x76d888: 74f2 JZ 0x0076d87c
    if(integer::condition("JZ",flags)) goto L0076d87c;
  }
  L0076d88a: { // 0x76d88a: 2c41 SUB AL,0x41
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d88c: { // 0x76d88c: 3c1a CMP AL,0x1a
    (void)integer::sub((s.ax & 0xffu),0x0000001au,8,flags);
  }
  L0076d88e: { // 0x76d88e: 1ac9 SBB CL,CL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.cx & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d890: { // 0x76d890: 80e120 AND CL,0x20
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags));
  }
  L0076d893: { // 0x76d893: 02c1 ADD AL,CL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L0076d895: { // 0x76d895: 0441 ADD AL,0x41
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d897: { // 0x76d897: 86e0 XCHG AL,AH
    const auto left=(s.ax & 0xffu);const auto right=((s.ax >> 8) & 0xffu);s.ax = with_al(s.ax, right);s.ax = (s.ax & 0xffff00ffu) | (((left) & 0xffu) << 8);
  }
  L0076d899: { // 0x76d899: 2c41 SUB AL,0x41
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d89b: { // 0x76d89b: 3c1a CMP AL,0x1a
    (void)integer::sub((s.ax & 0xffu),0x0000001au,8,flags);
  }
  L0076d89d: { // 0x76d89d: 1ac9 SBB CL,CL
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.cx & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d89f: { // 0x76d89f: 80e120 AND CL,0x20
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x00000020u),8,flags));
  }
  L0076d8a2: { // 0x76d8a2: 02c1 ADD AL,CL
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),(s.cx & 0xffu),8,flags));
  }
  L0076d8a4: { // 0x76d8a4: 0441 ADD AL,0x41
    s.ax = with_al(s.ax, integer::add((s.ax & 0xffu),0x00000041u,8,flags));
  }
  L0076d8a6: { // 0x76d8a6: 38e0 CMP AL,AH
    (void)integer::sub((s.ax & 0xffu),((s.ax >> 8) & 0xffu),8,flags);
  }
  L0076d8a8: { // 0x76d8a8: 74d2 JZ 0x0076d87c
    if(integer::condition("JZ",flags)) goto L0076d87c;
  }
  L0076d8aa: { // 0x76d8aa: 1ac0 SBB AL,AL
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),(s.ax & 0xffu),8,flags,flags&integer::CF));
  }
  L0076d8ac: { // 0x76d8ac: 1cff SBB AL,0xff
    s.ax = with_al(s.ax, integer::sub((s.ax & 0xffu),0x000000ffu,8,flags,flags&integer::CF));
  }
  L0076d8ae: { // 0x76d8ae: 0fbec0 MOVSX EAX,AL
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffu),8));
  }
  L0076d8b1: { // 0x76d8b1: eb78 JMP 0x0076d92b
    goto L0076d92b;
  }
  L0076d8b3: { // 0x76d8b3: f0ff05240eb100 INC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("excluded locale lock path");
  }
  L0076d8ba: { // 0x76d8ba: 833d200eb10000 CMP dword ptr [0x00b10e20],0x0
    (void)integer::sub(m.r32((0x00b10e20u)),0x00000000u,32,flags);
  }
  L0076d8c1: { // 0x76d8c1: 7f04 JG 0x0076d8c7
    if(integer::condition("JG",flags)) goto L0076d8c7;
  }
  L0076d8c3: { // 0x76d8c3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0076d8c5: { // 0x76d8c5: eb15 JMP 0x0076d8dc
    goto L0076d8dc;
  }
  L0076d8c7: { // 0x76d8c7: f0ff0d240eb100 DEC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("excluded locale lock path");
  }
  L0076d8ce: { // 0x76d8ce: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076d8d0: { // 0x76d8d0: e8e13c0000 CALL 0x007715b6
    s.arithmetic_flags=flags; invoke(m,s,f,0x007715b6u,7788757u); flags=s.arithmetic_flags;
  }
  L0076d8d5: { // 0x76d8d5: c7042401000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L0076d8dc: { // 0x76d8dc: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  L0076d8e1: { // 0x76d8e1: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0076d8e3: { // 0x76d8e3: 90 NOP
    ;
  }
  L0076d8e4: { // 0x76d8e4: 0ac0 OR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L0076d8e6: { // 0x76d8e6: 7427 JZ 0x0076d90f
    if(integer::condition("JZ",flags)) goto L0076d90f;
  }
  L0076d8e8: { // 0x76d8e8: 8a06 MOV AL,byte ptr [ESI]
    s.ax = with_al(s.ax, m.r8((s.si)));
  }
  L0076d8ea: { // 0x76d8ea: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0076d8eb: { // 0x76d8eb: 8a1f MOV BL,byte ptr [EDI]
    s.bx = with_al(s.bx, m.r8((s.di)));
  }
  L0076d8ed: { // 0x76d8ed: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0076d8ee: { // 0x76d8ee: 38d8 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  L0076d8f0: { // 0x76d8f0: 74f2 JZ 0x0076d8e4
    if(integer::condition("JZ",flags)) goto L0076d8e4;
  }
  L0076d8f2: { // 0x76d8f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0076d8f3: { // 0x76d8f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0076d8f4: { // 0x76d8f4: e8aa220000 CALL 0x0076fba3
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076fba3u,7788793u); flags=s.arithmetic_flags;
  }
  L0076d8f9: { // 0x76d8f9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076d8fb: { // 0x76d8fb: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d8fe: { // 0x76d8fe: e8a0220000 CALL 0x0076fba3
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076fba3u,7788803u); flags=s.arithmetic_flags;
  }
  L0076d903: { // 0x76d903: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d906: { // 0x76d906: 38c3 CMP BL,AL
    (void)integer::sub((s.bx & 0xffu),(s.ax & 0xffu),8,flags);
  }
  L0076d908: { // 0x76d908: 74da JZ 0x0076d8e4
    if(integer::condition("JZ",flags)) goto L0076d8e4;
  }
  L0076d90a: { // 0x76d90a: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0076d90c: { // 0x76d90c: 83d8ff SBB EAX,-0x1
    s.ax = integer::sub(s.ax,0xffffffffu,32,flags,flags&integer::CF);
  }
  L0076d90f: { // 0x76d90f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0076d911: { // 0x76d911: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L0076d912: { // 0x76d912: 0bc0 OR EAX,EAX
    s.ax = integer::logical((s.ax)|(s.ax),32,flags);
  }
  L0076d914: { // 0x76d914: 7509 JNZ 0x0076d91f
    if(integer::condition("JNZ",flags)) goto L0076d91f;
  }
  L0076d916: { // 0x76d916: f0ff0d240eb100 DEC.LOCK dword ptr [0x00b10e24]
    throw std::domain_error("excluded locale lock path");
  }
  L0076d91d: { // 0x76d91d: eb0a JMP 0x0076d929
    goto L0076d929;
  }
  L0076d91f: { // 0x76d91f: 6a13 PUSH 0x13
    f.push(m,0x00000013u);
  }
  L0076d921: { // 0x76d921: e8f13c0000 CALL 0x00771617
    s.arithmetic_flags=flags; invoke(m,s,f,0x00771617u,7788838u); flags=s.arithmetic_flags;
  }
  L0076d926: { // 0x76d926: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0076d929: { // 0x76d929: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0076d92b: { // 0x76d92b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0076d92c: { // 0x76d92c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0076d92d: { // 0x76d92d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0076d92e: { // 0x76d92e: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0076d92f: { // 0x76d92f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}


void f_0010bf50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0050bf50: { // 0x50bf50: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0050bf54: { // 0x50bf54: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0050bf57: { // 0x50bf57: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0050bf59: { // 0x50bf59: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0050bf5a: { // 0x50bf5a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0050bf5b: { // 0x50bf5b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0050bf5d: { // 0x50bf5d: 0f84a4000000 JZ 0x0050c007
    if(integer::condition("JZ",flags)) goto L0050c007;
  }
  L0050bf63: { // 0x50bf63: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0050bf65: { // 0x50bf65: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L0050bf68: { // 0x50bf68: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0050bf6a: { // 0x50bf6a: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  L0050bf72: { // 0x50bf72: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L0050bf74: { // 0x50bf74: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L0050bf76: { // 0x50bf76: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0050bf77: { // 0x50bf77: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L0050bf7f: { // 0x50bf7f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0050bf80: { // 0x50bf80: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0050bf81: { // 0x50bf81: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0050bf85: { // 0x50bf85: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L0050bf8d: { // 0x50bf8d: e80e7ef8ff CALL 0x00493da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00493da0u,5291922u); flags=s.arithmetic_flags;
  }
  L0050bf92: { // 0x50bf92: 83c620 ADD ESI,0x20
    s.si = integer::add(s.si,0x00000020u,32,flags);
  }
  L0050bf95: { // 0x50bf95: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0050bf97: { // 0x50bf97: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0050bf9b: { // 0x50bf9b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0050bf9e: { // 0x50bf9e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050bfa0: { // 0x50bfa0: 7465 JZ 0x0050c007
    if(integer::condition("JZ",flags)) goto L0050c007;
  }
  L0050bfa2: { // 0x50bfa2: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0050bfa5: { // 0x50bfa5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050bfa7: { // 0x50bfa7: 7404 JZ 0x0050bfad
    if(integer::condition("JZ",flags)) goto L0050bfad;
  }
  L0050bfa9: { // 0x50bfa9: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L0050bfab: { // 0x50bfab: 7413 JZ 0x0050bfc0
    if(integer::condition("JZ",flags)) goto L0050bfc0;
  }
  L0050bfad: { // 0x50bfad: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L0050bfb1: { // 0x50bfb1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0050bfb3: { // 0x50bfb3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0050bfb4: { // 0x50bfb4: e817470000 CALL 0x005106d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005106d0u,5291961u); flags=s.arithmetic_flags;
  }
  L0050bfb9: { // 0x50bfb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050bfbb: { // 0x50bfbb: 744a JZ 0x0050c007
    if(integer::condition("JZ",flags)) goto L0050c007;
  }
  L0050bfbd: { // 0x50bfbd: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0050bfc0: { // 0x50bfc0: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0050bfc3: { // 0x50bfc3: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0050bfc7: { // 0x50bfc7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050bfc9: { // 0x50bfc9: 7426 JZ 0x0050bff1
    if(integer::condition("JZ",flags)) goto L0050bff1;
  }
  L0050bfcb: { // 0x50bfcb: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L0050bfce: { // 0x50bfce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050bfd0: { // 0x50bfd0: 7404 JZ 0x0050bfd6
    if(integer::condition("JZ",flags)) goto L0050bfd6;
  }
  L0050bfd2: { // 0x50bfd2: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L0050bfd4: { // 0x50bfd4: 7413 JZ 0x0050bfe9
    if(integer::condition("JZ",flags)) goto L0050bfe9;
  }
  L0050bfd6: { // 0x50bfd6: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0050bfda: { // 0x50bfda: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0050bfdb: { // 0x50bfdb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0050bfdd: { // 0x50bfdd: e8ee460000 CALL 0x005106d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005106d0u,5292002u); flags=s.arithmetic_flags;
  }
  L0050bfe2: { // 0x50bfe2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0050bfe4: { // 0x50bfe4: 740b JZ 0x0050bff1
    if(integer::condition("JZ",flags)) goto L0050bff1;
  }
  L0050bfe6: { // 0x50bfe6: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L0050bfe9: { // 0x50bfe9: 8b7610 MOV ESI,dword ptr [ESI + 0x10]
    s.si = m.r32((s.si+0x00000010u));
  }
  L0050bfec: { // 0x50bfec: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0050bfef: { // 0x50bfef: eb05 JMP 0x0050bff6
    goto L0050bff6;
  }
  L0050bff1: { // 0x50bff1: beac0ab100 MOV ESI,0xb10aac
    s.si = 0x00b10aacu;
  }
  L0050bff6: { // 0x50bff6: 8b36 MOV ESI,dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L0050bff8: { // 0x50bff8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0050bffa: { // 0x50bffa: 740b JZ 0x0050c007
    if(integer::condition("JZ",flags)) goto L0050c007;
  }
  L0050bffc: { // 0x50bffc: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  L0050bfff: { // 0x50bfff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050c000: { // 0x50c000: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050c001: { // 0x50c001: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0050c004: { // 0x50c004: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0050c007: { // 0x50c007: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0050c008: { // 0x50c008: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0050c00a: { // 0x50c00a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0050c00b: { // 0x50c00b: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0050c00e: { // 0x50c00e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0026ac80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0066ac80: { // 0x66ac80: 8b5138 MOV EDX,dword ptr [ECX + 0x38]
    s.dx = m.r32((s.cx+0x00000038u));
  }
  L0066ac83: { // 0x66ac83: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0066ac85: { // 0x66ac85: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0066ac87: { // 0x66ac87: 740c JZ 0x0066ac95
    if(integer::condition("JZ",flags)) goto L0066ac95;
  }
  L0066ac89: { // 0x66ac89: 884134 MOV byte ptr [ECX + 0x34],AL
    m.w8((s.cx+0x00000034u), (s.ax & 0xffu));
  }
  L0066ac8c: { // 0x66ac8c: 89413c MOV dword ptr [ECX + 0x3c],EAX
    m.w32((s.cx+0x0000003cu), s.ax);
  }
  L0066ac8f: { // 0x66ac8f: 894138 MOV dword ptr [ECX + 0x38],EAX
    m.w32((s.cx+0x00000038u), s.ax);
  }
  L0066ac92: { // 0x66ac92: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0066ac94: { // 0x66ac94: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0066ac95: { // 0x66ac95: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0066ac97: { // 0x66ac97: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002de9e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006de9e0: { // 0x6de9e0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L006de9e3: { // 0x6de9e3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006de9e4: { // 0x6de9e4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L006de9e6: { // 0x6de9e6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006de9e7: { // 0x6de9e7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006de9e8: { // 0x6de9e8: 8b83f4000000 MOV EAX,dword ptr [EBX + 0xf4]
    s.ax = m.r32((s.bx+0x000000f4u));
  }
  L006de9ee: { // 0x6de9ee: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006de9ef: { // 0x6de9ef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006de9f1: { // 0x6de9f1: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L006de9f5: { // 0x6de9f5: 0f8404030000 JZ 0x006decff
    if(integer::condition("JZ",flags)) goto L006decff;
  }
  L006de9fb: { // 0x6de9fb: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006de9fd: { // 0x6de9fd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006de9ff: { // 0x6de9ff: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006dea03: { // 0x6dea03: 0f84f6020000 JZ 0x006decff
    if(integer::condition("JZ",flags)) goto L006decff;
  }
  L006dea09: { // 0x6dea09: dd83a0000000 FLD double ptr [EBX + 0xa0]
    const auto address=(s.bx+0x000000a0u);
    s.fp.load64(read64(m,address));
  }
  L006dea0f: { // 0x6dea0f: dc1d20757800 FCOMP double ptr [0x00787520]
    const auto address=(0x00787520u);
    s.fp.compare_pop64(read64(m,address));
  }
  L006dea15: { // 0x6dea15: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006dea17: { // 0x6dea17: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006dea1a: { // 0x6dea1a: 0f85df020000 JNZ 0x006decff
    if(integer::condition("JNZ",flags)) goto L006decff;
  }
  L006dea20: { // 0x6dea20: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006dea24: { // 0x6dea24: dc8ba0000000 FMUL double ptr [EBX + 0xa0]
    const auto address=(s.bx+0x000000a0u);
    s.fp.multiply64(read64(m,address));
  }
  L006dea2a: { // 0x6dea2a: e821c00800 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7203375u); flags=s.arithmetic_flags;
  }
  L006dea2f: { // 0x6dea2f: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L006dea32: { // 0x6dea32: 7c11 JL 0x006dea45
    if(integer::condition("JL",flags)) goto L006dea45;
  }
  L006dea34: { // 0x6dea34: 83f819 CMP EAX,0x19
    (void)integer::sub(s.ax,0x00000019u,32,flags);
  }
  L006dea37: { // 0x6dea37: 7e07 JLE 0x006dea40
    if(integer::condition("JLE",flags)) goto L006dea40;
  }
  L006dea39: { // 0x6dea39: be19000000 MOV ESI,0x19
    s.si = 0x00000019u;
  }
  L006dea3e: { // 0x6dea3e: eb0e JMP 0x006dea4e
    goto L006dea4e;
  }
  L006dea40: { // 0x6dea40: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L006dea43: { // 0x6dea43: 7d07 JGE 0x006dea4c
    if(integer::condition("JGE",flags)) goto L006dea4c;
  }
  L006dea45: { // 0x6dea45: be05000000 MOV ESI,0x5
    s.si = 0x00000005u;
  }
  L006dea4a: { // 0x6dea4a: eb02 JMP 0x006dea4e
    goto L006dea4e;
  }
  L006dea4c: { // 0x6dea4c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006dea4e: { // 0x6dea4e: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006dea53: { // 0x6dea53: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L006dea59: { // 0x6dea59: e88213f5ff CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,7203422u); flags=s.arithmetic_flags;
  }
  L006dea5e: { // 0x6dea5e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006dea5f: { // 0x6dea5f: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L006dea61: { // 0x6dea61: 8b8bf4000000 MOV ECX,dword ptr [EBX + 0xf4]
    s.cx = m.r32((s.bx+0x000000f4u));
  }
  L006dea67: { // 0x6dea67: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006dea69: { // 0x6dea69: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006dea6a: { // 0x6dea6a: f7fe IDIV ESI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.si,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L006dea6c: { // 0x6dea6c: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L006dea6e: { // 0x6dea6e: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006dea70: { // 0x6dea70: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006dea71: { // 0x6dea71: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L006dea75: { // 0x6dea75: e846a0d4ff CALL 0x00428ac0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428ac0u,7203450u); flags=s.arithmetic_flags;
  }
  L006dea7a: { // 0x6dea7a: 83e814 SUB EAX,0x14
    s.ax = integer::sub(s.ax,0x00000014u,32,flags);
  }
  L006dea7d: { // 0x6dea7d: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006dea7f: { // 0x6dea7f: 7e07 JLE 0x006dea88
    if(integer::condition("JLE",flags)) goto L006dea88;
  }
  L006dea81: { // 0x6dea81: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006dea83: { // 0x6dea83: e8c8030000 CALL 0x006dee50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006dee50u,7203464u); flags=s.arithmetic_flags;
  }
  L006dea88: { // 0x6dea88: 8b8bf4000000 MOV ECX,dword ptr [EBX + 0xf4]
    s.cx = m.r32((s.bx+0x000000f4u));
  }
  L006dea8e: { // 0x6dea8e: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L006dea96: { // 0x6dea96: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006dea98: { // 0x6dea98: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006dea9a: { // 0x6dea9a: 7504 JNZ 0x006deaa0
    if(integer::condition("JNZ",flags)) goto L006deaa0;
  }
  L006dea9c: { // 0x6dea9c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006dea9e: { // 0x6dea9e: eb26 JMP 0x006deac6
    goto L006deac6;
  }
  L006deaa0: { // 0x6deaa0: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006deaa3: { // 0x6deaa3: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006deaa5: { // 0x6deaa5: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006deaa8: { // 0x6deaa8: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006deaab: { // 0x6deaab: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L006deaae: { // 0x6deaae: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006deab0: { // 0x6deab0: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006deab3: { // 0x6deab3: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L006deaba: { // 0x6deaba: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006deabc: { // 0x6deabc: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006deabd: { // 0x6deabd: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L006deabf: { // 0x6deabf: e8ccd3eaff CALL 0x0058be90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058be90u,7203524u); flags=s.arithmetic_flags;
  }
  L006deac4: { // 0x6deac4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006deac6: { // 0x6deac6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006deac8: { // 0x6deac8: 0f8e31020000 JLE 0x006decff
    if(integer::condition("JLE",flags)) goto L006decff;
  }
  L006deace: { // 0x6deace: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006dead0: { // 0x6dead0: 0f8429020000 JZ 0x006decff
    if(integer::condition("JZ",flags)) goto L006decff;
  }
  L006dead6: { // 0x6dead6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006dead7: { // 0x6dead7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006deadc: { // 0x6deadc: e81f6ae6ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7203553u); flags=s.arithmetic_flags;
  }
  L006deae1: { // 0x6deae1: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L006deae3: { // 0x6deae3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006deae5: { // 0x6deae5: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006deae7: { // 0x6deae7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006deae8: { // 0x6deae8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006deaea: { // 0x6deaea: e8d17bd9ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,7203567u); flags=s.arithmetic_flags;
  }
  L006deaef: { // 0x6deaef: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006deaf1: { // 0x6deaf1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006deaf3: { // 0x6deaf3: e8a89cd9ff CALL 0x004787a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004787a0u,7203576u); flags=s.arithmetic_flags;
  }
  L006deaf8: { // 0x6deaf8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006deafa: { // 0x6deafa: 7401 JZ 0x006deafd
    if(integer::condition("JZ",flags)) goto L006deafd;
  }
  L006deafc: { // 0x6deafc: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L006deafd: { // 0x6deafd: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L006deafe: { // 0x6deafe: 83ff08 CMP EDI,0x8
    (void)integer::sub(s.di,0x00000008u,32,flags);
  }
  L006deb01: { // 0x6deb01: 7ce4 JL 0x006deae7
    if(integer::condition("JL",flags)) goto L006deae7;
  }
  L006deb03: { // 0x6deb03: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006deb05: { // 0x6deb05: 0f84da000000 JZ 0x006debe5
    if(integer::condition("JZ",flags)) goto L006debe5;
  }
  L006deb0b: { // 0x6deb0b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006deb0d: { // 0x6deb0d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006deb0f: { // 0x6deb0f: e82c9bd9ff CALL 0x00478640
    s.arithmetic_flags=flags; invoke(m,s,f,0x00478640u,7203604u); flags=s.arithmetic_flags;
  }
  L006deb14: { // 0x6deb14: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006deb18: { // 0x6deb18: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006deb19: { // 0x6deb19: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L006deb1c: { // 0x6deb1c: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006deb20: { // 0x6deb20: 0f8ed1000000 JLE 0x006debf7
    if(integer::condition("JLE",flags)) goto L006debf7;
  }
  L006deb26: { // 0x6deb26: 8b83f0000000 MOV EAX,dword ptr [EBX + 0xf0]
    s.ax = m.r32((s.bx+0x000000f0u));
  }
  L006deb2c: { // 0x6deb2c: 8b8bfc000000 MOV ECX,dword ptr [EBX + 0xfc]
    s.cx = m.r32((s.bx+0x000000fcu));
  }
  L006deb32: { // 0x6deb32: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L006deb35: { // 0x6deb35: 8d6e24 LEA EBP,[ESI + 0x24]
    s.bp = (s.si+0x00000024u);
  }
  L006deb38: { // 0x6deb38: 8914c1 MOV dword ptr [ECX + EAX*0x8],EDX
    m.w32((s.cx+(s.ax * 0x00000008u)), s.dx);
  }
  L006deb3b: { // 0x6deb3b: 8b83f0000000 MOV EAX,dword ptr [EBX + 0xf0]
    s.ax = m.r32((s.bx+0x000000f0u));
  }
  L006deb41: { // 0x6deb41: 8b8bfc000000 MOV ECX,dword ptr [EBX + 0xfc]
    s.cx = m.r32((s.bx+0x000000fcu));
  }
  L006deb47: { // 0x6deb47: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L006deb4b: { // 0x6deb4b: c744c10400000000 MOV dword ptr [ECX + EAX*0x8 + 0x4],0x0
    m.w32((s.cx+(s.ax * 0x00000008u)+0x00000004u), 0x00000000u);
  }
  L006deb53: { // 0x6deb53: 8b83f0000000 MOV EAX,dword ptr [EBX + 0xf0]
    s.ax = m.r32((s.bx+0x000000f0u));
  }
  L006deb59: { // 0x6deb59: 8b93fc000000 MOV EDX,dword ptr [EBX + 0xfc]
    s.dx = m.r32((s.bx+0x000000fcu));
  }
  L006deb5f: { // 0x6deb5f: 8bbbf4000000 MOV EDI,dword ptr [EBX + 0xf4]
    s.di = m.r32((s.bx+0x000000f4u));
  }
  L006deb65: { // 0x6deb65: 8d0cc2 LEA ECX,[EDX + EAX*0x8]
    s.cx = (s.dx+(s.ax * 0x00000008u));
  }
  L006deb68: { // 0x6deb68: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006deb69: { // 0x6deb69: 8983f0000000 MOV dword ptr [EBX + 0xf0],EAX
    m.w32((s.bx+0x000000f0u), s.ax);
  }
  L006deb6f: { // 0x6deb6f: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006deb71: { // 0x6deb71: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006deb74: { // 0x6deb74: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006deb75: { // 0x6deb75: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L006deb77: { // 0x6deb77: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006deb7b: { // 0x6deb7b: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L006deb7e: { // 0x6deb7e: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L006deb82: { // 0x6deb82: d1ee SHR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::right);
  }
  L006deb84: { // 0x6deb84: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006deb86: { // 0x6deb86: 734a JNC 0x006debd2
    if(integer::condition("JNC",flags)) goto L006debd2;
  }
  L006deb88: { // 0x6deb88: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L006deb8b: { // 0x6deb8b: 7628 JBE 0x006debb5
    if(integer::condition("JBE",flags)) goto L006debb5;
  }
  L006deb8d: { // 0x6deb8d: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L006deb90: { // 0x6deb90: 8b2cb1 MOV EBP,dword ptr [ECX + ESI*0x4]
    s.bp = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L006deb93: { // 0x6deb93: d94504 FLD float ptr [EBP + 0x4]
    const auto address=(s.bp+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006deb96: { // 0x6deb96: d85c2414 FCOMP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.compare_pop32(m.r32(address));
  }
  L006deb9a: { // 0x6deb9a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006deb9c: { // 0x6deb9c: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006deb9f: { // 0x6deb9f: 750c JNZ 0x006debad
    if(integer::condition("JNZ",flags)) goto L006debad;
  }
  L006deba1: { // 0x6deba1: 892c91 MOV dword ptr [ECX + EDX*0x4],EBP
    m.w32((s.cx+(s.dx * 0x00000004u)), s.bp);
  }
  L006deba4: { // 0x6deba4: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L006deba6: { // 0x6deba6: d1ee SHR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::right);
  }
  L006deba8: { // 0x6deba8: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L006debab: { // 0x6debab: 77e0 JA 0x006deb8d
    if(integer::condition("JA",flags)) goto L006deb8d;
  }
  L006debad: { // 0x6debad: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L006debb1: { // 0x6debb1: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L006debb5: { // 0x6debb5: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L006debb8: { // 0x6debb8: 890c90 MOV dword ptr [EAX + EDX*0x4],ECX
    m.w32((s.ax+(s.dx * 0x00000004u)), s.cx);
  }
  L006debbb: { // 0x6debbb: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006debbd: { // 0x6debbd: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L006debc0: { // 0x6debc0: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L006debc1: { // 0x6debc1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006debc3: { // 0x6debc3: 8917 MOV dword ptr [EDI],EDX
    m.w32((s.di), s.dx);
  }
  L006debc5: { // 0x6debc5: 7603 JBE 0x006debca
    if(integer::condition("JBE",flags)) goto L006debca;
  }
  L006debc7: { // 0x6debc7: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L006debca: { // 0x6debca: 3b4f10 CMP ECX,dword ptr [EDI + 0x10]
    (void)integer::sub(s.cx,m.r32((s.di+0x00000010u)),32,flags);
  }
  L006debcd: { // 0x6debcd: 7303 JNC 0x006debd2
    if(integer::condition("JNC",flags)) goto L006debd2;
  }
  L006debcf: { // 0x6debcf: 894f10 MOV dword ptr [EDI + 0x10],ECX
    m.w32((s.di+0x00000010u), s.cx);
  }
  L006debd2: { // 0x6debd2: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006debd4: { // 0x6debd4: e8b79ed4ff CALL 0x00428a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428a90u,7203801u); flags=s.arithmetic_flags;
  }
  L006debd9: { // 0x6debd9: 8b8bf8000000 MOV ECX,dword ptr [EBX + 0xf8]
    s.cx = m.r32((s.bx+0x000000f8u));
  }
  L006debdf: { // 0x6debdf: c6040801 MOV byte ptr [EAX + ECX*0x1],0x1
    m.w8((s.ax+(s.cx * 0x00000001u)), 0x00000001u);
  }
  L006debe3: { // 0x6debe3: eb12 JMP 0x006debf7
    goto L006debf7;
  }
  L006debe5: { // 0x6debe5: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  L006debe8: { // 0x6debe8: e8a39ed4ff CALL 0x00428a90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00428a90u,7203821u); flags=s.arithmetic_flags;
  }
  L006debed: { // 0x6debed: 8b93f8000000 MOV EDX,dword ptr [EBX + 0xf8]
    s.dx = m.r32((s.bx+0x000000f8u));
  }
  L006debf3: { // 0x6debf3: c6041000 MOV byte ptr [EAX + EDX*0x1],0x0
    m.w8((s.ax+(s.dx * 0x00000001u)), 0x00000000u);
  }
  L006debf7: { // 0x6debf7: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006debfb: { // 0x6debfb: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L006debff: { // 0x6debff: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006dec01: { // 0x6dec01: 0f8df8000000 JGE 0x006decff
    if(integer::condition("JGE",flags)) goto L006decff;
  }
  L006dec07: { // 0x6dec07: 8b8bf4000000 MOV ECX,dword ptr [EBX + 0xf4]
    s.cx = m.r32((s.bx+0x000000f4u));
  }
  L006dec0d: { // 0x6dec0d: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006dec0f: { // 0x6dec0f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006dec11: { // 0x6dec11: 7507 JNZ 0x006dec1a
    if(integer::condition("JNZ",flags)) goto L006dec1a;
  }
  L006dec13: { // 0x6dec13: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006dec15: { // 0x6dec15: e9b4feffff JMP 0x006deace
    goto L006deace;
  }
  L006dec1a: { // 0x6dec1a: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006dec1d: { // 0x6dec1d: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L006dec22: { // 0x6dec22: 8b1490 MOV EDX,dword ptr [EAX + EDX*0x4]
    s.dx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006dec25: { // 0x6dec25: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006dec28: { // 0x6dec28: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L006dec2b: { // 0x6dec2b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006dec2d: { // 0x6dec2d: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L006dec30: { // 0x6dec30: 8974241c MOV dword ptr [ESP + 0x1c],ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L006dec34: { // 0x6dec34: c7048200000000 MOV dword ptr [EDX + EAX*0x4],0x0
    m.w32((s.dx+(s.ax * 0x00000004u)), 0x00000000u);
  }
  L006dec3b: { // 0x6dec3b: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006dec3d: { // 0x6dec3d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L006dec3e: { // 0x6dec3e: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L006dec40: { // 0x6dec40: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L006dec42: { // 0x6dec42: 83fe02 CMP ESI,0x2
    (void)integer::sub(s.si,0x00000002u,32,flags);
  }
  L006dec45: { // 0x6dec45: 7c1d JL 0x006dec64
    if(integer::condition("JL",flags)) goto L006dec64;
  }
  L006dec47: { // 0x6dec47: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006dec4a: { // 0x6dec4a: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L006dec4d: { // 0x6dec4d: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L006dec50: { // 0x6dec50: d94204 FLD float ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006dec53: { // 0x6dec53: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006dec56: { // 0x6dec56: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006dec58: { // 0x6dec58: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L006dec5d: { // 0x6dec5d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006dec5f: { // 0x6dec5f: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006dec62: { // 0x6dec62: 7405 JZ 0x006dec69
    if(integer::condition("JZ",flags)) goto L006dec69;
  }
  L006dec64: { // 0x6dec64: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L006dec69: { // 0x6dec69: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  L006dec6c: { // 0x6dec6c: 7c1f JL 0x006dec8d
    if(integer::condition("JL",flags)) goto L006dec8d;
  }
  L006dec6e: { // 0x6dec6e: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006dec71: { // 0x6dec71: 8b700c MOV ESI,dword ptr [EAX + 0xc]
    s.si = m.r32((s.ax+0x0000000cu));
  }
  L006dec74: { // 0x6dec74: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006dec77: { // 0x6dec77: d94604 FLD float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006dec7a: { // 0x6dec7a: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006dec7d: { // 0x6dec7d: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006dec7f: { // 0x6dec7f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006dec81: { // 0x6dec81: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006dec84: { // 0x6dec84: 7507 JNZ 0x006dec8d
    if(integer::condition("JNZ",flags)) goto L006dec8d;
  }
  L006dec86: { // 0x6dec86: ba03000000 MOV EDX,0x3
    s.dx = 0x00000003u;
  }
  L006dec8b: { // 0x6dec8b: eb05 JMP 0x006dec92
    goto L006dec92;
  }
  L006dec8d: { // 0x6dec8d: 83fa01 CMP EDX,0x1
    (void)integer::sub(s.dx,0x00000001u,32,flags);
  }
  L006dec90: { // 0x6dec90: 7464 JZ 0x006decf6
    if(integer::condition("JZ",flags)) goto L006decf6;
  }
  L006dec92: { // 0x6dec92: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006dec95: { // 0x6dec95: 8b1c90 MOV EBX,dword ptr [EAX + EDX*0x4]
    s.bx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006dec98: { // 0x6dec98: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L006dec9b: { // 0x6dec9b: 891cb8 MOV dword ptr [EAX + EDI*0x4],EBX
    m.w32((s.ax+(s.di * 0x00000004u)), s.bx);
  }
  L006dec9e: { // 0x6dec9e: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006deca1: { // 0x6deca1: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006deca3: { // 0x6deca3: 8d5c1201 LEA EBX,[EDX + EDX*0x1 + 0x1]
    s.bx = (s.dx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L006deca7: { // 0x6deca7: 893490 MOV dword ptr [EAX + EDX*0x4],ESI
    m.w32((s.ax+(s.dx * 0x00000004u)), s.si);
  }
  L006decaa: { // 0x6decaa: 8b29 MOV EBP,dword ptr [ECX]
    s.bp = m.r32((s.cx));
  }
  L006decac: { // 0x6decac: 8d3412 LEA ESI,[EDX + EDX*0x1]
    s.si = (s.dx+(s.dx * 0x00000001u));
  }
  L006decaf: { // 0x6decaf: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L006decb1: { // 0x6decb1: 7f1d JG 0x006decd0
    if(integer::condition("JG",flags)) goto L006decd0;
  }
  L006decb3: { // 0x6decb3: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006decb6: { // 0x6decb6: 8b04b0 MOV EAX,dword ptr [EAX + ESI*0x4]
    s.ax = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L006decb9: { // 0x6decb9: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006decbc: { // 0x6decbc: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006decbf: { // 0x6decbf: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006decc2: { // 0x6decc2: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006decc5: { // 0x6decc5: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006decc7: { // 0x6decc7: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006decc9: { // 0x6decc9: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006deccc: { // 0x6deccc: 7502 JNZ 0x006decd0
    if(integer::condition("JNZ",flags)) goto L006decd0;
  }
  L006decce: { // 0x6decce: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L006decd0: { // 0x6decd0: 3bdd CMP EBX,EBP
    (void)integer::sub(s.bx,s.bp,32,flags);
  }
  L006decd2: { // 0x6decd2: 7f1a JG 0x006decee
    if(integer::condition("JG",flags)) goto L006decee;
  }
  L006decd4: { // 0x6decd4: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L006decd7: { // 0x6decd7: 8b3498 MOV ESI,dword ptr [EAX + EBX*0x4]
    s.si = m.r32((s.ax+(s.bx * 0x00000004u)));
  }
  L006decda: { // 0x6decda: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L006decdd: { // 0x6decdd: d94604 FLD float ptr [ESI + 0x4]
    const auto address=(s.si+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006dece0: { // 0x6dece0: d94004 FLD float ptr [EAX + 0x4]
    const auto address=(s.ax+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L006dece3: { // 0x6dece3: ded9 FCOMPP
    numeric_b88::detail::reg<0xded9>(s.fp);
  }
  L006dece5: { // 0x6dece5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L006dece7: { // 0x6dece7: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L006decea: { // 0x6decea: 7502 JNZ 0x006decee
    if(integer::condition("JNZ",flags)) goto L006decee;
  }
  L006decec: { // 0x6decec: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L006decee: { // 0x6decee: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  L006decf0: { // 0x6decf0: 75a0 JNZ 0x006dec92
    if(integer::condition("JNZ",flags)) goto L006dec92;
  }
  L006decf2: { // 0x6decf2: 8b5c2424 MOV EBX,dword ptr [ESP + 0x24]
    s.bx = m.r32((f.sp+0x00000024u));
  }
  L006decf6: { // 0x6decf6: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006decfa: { // 0x6decfa: e9cffdffff JMP 0x006deace
    goto L006deace;
  }
  L006decff: { // 0x6decff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ded00: { // 0x6ded00: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ded01: { // 0x6ded01: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006ded02: { // 0x6ded02: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006ded03: { // 0x6ded03: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006ded06: { // 0x6ded06: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00378f95(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778f95: { // 0x778f95: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00778f96: { // 0x778f96: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00778f98: { // 0x778f98: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778f99: { // 0x778f99: 9bd97dfc FSTCW word ptr [EBP + -0x4]
    const auto address=(s.bp-0x00000004u);
    const auto value=s.fp.waiting_control();
    m.w16(address,value);
  }
  L00778f9d: { // 0x778f9d: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00778fa0: { // 0x778fa0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00778fa2: { // 0x778fa2: 234508 AND EAX,dword ptr [EBP + 0x8]
    s.ax = integer::logical((s.ax)&(m.r32((s.bp+0x00000008u))),32,flags);
  }
  L00778fa5: { // 0x778fa5: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L00778fa7: { // 0x778fa7: 234dfc AND ECX,dword ptr [EBP + -0x4]
    s.cx = integer::logical((s.cx)&(m.r32((s.bp-0x00000004u))),32,flags);
  }
  L00778faa: { // 0x778faa: 0bc8 OR ECX,EAX
    s.cx = integer::logical((s.cx)|(s.ax),32,flags);
  }
  L00778fac: { // 0x778fac: 894d0c MOV dword ptr [EBP + 0xc],ECX
    m.w32((s.bp+0x0000000cu), s.cx);
  }
  L00778faf: { // 0x778faf: d96d0c FLDCW word ptr [EBP + 0xc]
    const auto address=(s.bp+0x0000000cu);
    s.fp.load_control(m.r16(address));
  }
  L00778fb2: { // 0x778fb2: 0fbf45fc MOVSX EAX,word ptr [EBP + -0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp-0x00000004u)),16));
  }
  L00778fb6: { // 0x778fb6: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00778fb7: { // 0x778fb7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00378dbe(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00778dbe: { // 0x778dbe: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00778dbf: { // 0x778dbf: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00778dc1: { // 0x778dc1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778dc2: { // 0x778dc2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00778dc3: { // 0x778dc3: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00778dc6: { // 0x778dc6: d9fc FRNDINT
    numeric_b88::detail::reg<0xd9fc>(s.fp);
  }
  L00778dc8: { // 0x778dc8: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00778dcb: { // 0x778dcb: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00778dce: { // 0x778dce: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00778dcf: { // 0x778dcf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00110220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00510220: { // 0x510220: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00510221: { // 0x510221: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00510223: { // 0x510223: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00510224: { // 0x510224: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00510225: { // 0x510225: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00510228: { // 0x510228: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00510229: { // 0x510229: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0051022b: { // 0x51022b: 7471 JZ 0x0051029e
    if(integer::condition("JZ",flags)) goto L0051029e;
  }
  L0051022d: { // 0x51022d: 8b4310 MOV EAX,dword ptr [EBX + 0x10]
    s.ax = m.r32((s.bx+0x00000010u));
  }
  L00510230: { // 0x510230: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00510234: { // 0x510234: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00510236: { // 0x510236: 7411 JZ 0x00510249
    if(integer::condition("JZ",flags)) goto L00510249;
  }
  L00510238: { // 0x510238: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0051023a: { // 0x51023a: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0051023c: { // 0x51023c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0051023e: { // 0x51023e: 7509 JNZ 0x00510249
    if(integer::condition("JNZ",flags)) goto L00510249;
  }
  L00510240: { // 0x510240: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00510241: { // 0x510241: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00510242: { // 0x510242: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00510243: { // 0x510243: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00510245: { // 0x510245: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00510246: { // 0x510246: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00510249: { // 0x510249: 8a430c MOV AL,byte ptr [EBX + 0xc]
    s.ax = with_al(s.ax, m.r8((s.bx+0x0000000cu)));
  }
  L0051024c: { // 0x51024c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0051024e: { // 0x51024e: 751e JNZ 0x0051026e
    if(integer::condition("JNZ",flags)) goto L0051026e;
  }
  L00510250: { // 0x510250: 6850075100 PUSH 0x510750
    f.push(m,0x00510750u);
  }
  L00510255: { // 0x510255: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00510257: { // 0x510257: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00510258: { // 0x510258: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0051025a: { // 0x51025a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0051025b: { // 0x51025b: e826d42500 CALL 0x0076d686
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d686u,5309024u); flags=s.arithmetic_flags;
  }
  L00510260: { // 0x510260: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00510263: { // 0x510263: c7431000000000 MOV dword ptr [EBX + 0x10],0x0
    m.w32((s.bx+0x00000010u), 0x00000000u);
  }
  L0051026a: { // 0x51026a: c6430c01 MOV byte ptr [EBX + 0xc],0x1
    m.w8((s.bx+0x0000000cu), 0x00000001u);
  }
  L0051026e: { // 0x51026e: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00510271: { // 0x510271: 8b2e MOV EBP,dword ptr [ESI]
    s.bp = m.r32((s.si));
  }
  L00510273: { // 0x510273: 8b3b MOV EDI,dword ptr [EBX]
    s.di = m.r32((s.bx));
  }
  L00510275: { // 0x510275: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00510277: { // 0x510277: 7e25 JLE 0x0051029e
    if(integer::condition("JLE",flags)) goto L0051029e;
  }
  L00510279: { // 0x510279: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0051027b: { // 0x51027b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0051027c: { // 0x51027c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0051027e: { // 0x51027e: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00510280: { // 0x510280: 8b34c7 MOV ESI,dword ptr [EDI + EAX*0x8]
    s.si = m.r32((s.di+(s.ax * 0x00000008u)));
  }
  L00510283: { // 0x510283: 8d14c7 LEA EDX,[EDI + EAX*0x8]
    s.dx = (s.di+(s.ax * 0x00000008u));
  }
  L00510286: { // 0x510286: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00510288: { // 0x510288: 7e04 JLE 0x0051028e
    if(integer::condition("JLE",flags)) goto L0051028e;
  }
  L0051028a: { // 0x51028a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0051028c: { // 0x51028c: eb0c JMP 0x0051029a
    goto L0051029a;
  }
  L0051028e: { // 0x51028e: 7417 JZ 0x005102a7
    if(integer::condition("JZ",flags)) goto L005102a7;
  }
  L00510290: { // 0x510290: 8d7a08 LEA EDI,[EDX + 0x8]
    s.di = (s.dx+0x00000008u);
  }
  L00510293: { // 0x510293: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L00510296: { // 0x510296: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00510298: { // 0x510298: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0051029a: { // 0x51029a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0051029c: { // 0x51029c: 7fdb JG 0x00510279
    if(integer::condition("JG",flags)) goto L00510279;
  }
  L0051029e: { // 0x51029e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0051029f: { // 0x51029f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005102a0: { // 0x5102a0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005102a1: { // 0x5102a1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005102a3: { // 0x5102a3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005102a4: { // 0x5102a4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005102a7: { // 0x5102a7: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005102a9: { // 0x5102a9: 74f3 JZ 0x0051029e
    if(integer::condition("JZ",flags)) goto L0051029e;
  }
  L005102ab: { // 0x5102ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005102ac: { // 0x5102ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005102ad: { // 0x5102ad: 895310 MOV dword ptr [EBX + 0x10],EDX
    m.w32((s.bx+0x00000010u), s.dx);
  }
  L005102b0: { // 0x5102b0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005102b1: { // 0x5102b1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005102b3: { // 0x5102b3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005102b4: { // 0x5102b4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5299696u:f_0010ddf0(m,s,child,{});break;
case 4799904u:f_00093da0(m,s,child,{});break;
case 7789840u:f_0036dd10(m,s,child,{});break;
case 7225808u:f_002e41d0(m,s,child,{});break;
case 6752528u:f_00270910(m,s,child,{});break;
case 7788640u:f_0036d860(m,s,child,{});break;
case 5291856u:f_0010bf50(m,s,child,{});break;
case 6728832u:f_0026ac80(m,s,child,{});break;
case 7203296u:f_002de9e0(m,s,child,{});break;
case 7835541u:f_00378f95(m,s,child,{});break;
case 7835070u:f_00378dbe(m,s,child,{});break;
case 5308960u:f_00110220(m,s,child,{});break;
default:throw std::domain_error("recovery111 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0046a730(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046a730: { // 0x46a730: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0046a734: { // 0x46a734: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  L0046a73a: { // 0x46a73a: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L0046a73e: { // 0x46a73e: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  L0046a743: { // 0x46a743: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046a744: { // 0x46a744: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  L0046a74b: { // 0x46a74b: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  L0046a750: { // 0x46a750: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0046a751: { // 0x46a751: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046a752: { // 0x46a752: e899360a00 CALL 0x0050ddf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050ddf0u,4630359u); flags=s.arithmetic_flags;
  }
  L0046a757: { // 0x46a757: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0046a759: { // 0x46a759: 7467 JZ 0x0046a7c2
    if(integer::condition("JZ",flags)) goto L0046a7c2;
  }
  L0046a75b: { // 0x46a75b: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  L0046a75f: { // 0x46a75f: e8ac612000 CALL 0x00670910
    s.arithmetic_flags=flags; invoke(m,s,f,0x00670910u,4630372u); flags=s.arithmetic_flags;
  }
  L0046a764: { // 0x46a764: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0046a767: { // 0x46a767: 7560 JNZ 0x0046a7c9
    if(integer::condition("JNZ",flags)) goto L0046a7c9;
  }
  L0046a769: { // 0x46a769: 68b4000000 PUSH 0xb4
    f.push(m,0x000000b4u);
  }
  L0046a76e: { // 0x46a76e: e8e4313000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4630387u); flags=s.arithmetic_flags;
  }
  L0046a773: { // 0x46a773: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046a776: { // 0x46a776: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0046a778: { // 0x46a778: 740e JZ 0x0046a788
    if(integer::condition("JZ",flags)) goto L0046a788;
  }
  L0046a77a: { // 0x46a77a: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  L0046a77e: { // 0x46a77e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0046a77f: { // 0x46a77f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0046a781: { // 0x46a781: e80a602000 CALL 0x00670790
    s.arithmetic_flags=flags; invoke(m,s,f,0x00670790u,4630406u); flags=s.arithmetic_flags;
  }
  L0046a786: { // 0x46a786: eb02 JMP 0x0046a78a
    goto L0046a78a;
  }
  L0046a788: { // 0x46a788: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0046a78a: { // 0x46a78a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046a78b: { // 0x46a78b: 8b35f0e48400 MOV ESI,dword ptr [0x0084e4f0]
    s.si = m.r32((0x0084e4f0u));
  }
  L0046a791: { // 0x46a791: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0046a793: { // 0x46a793: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0046a795: { // 0x46a795: 7e12 JLE 0x0046a7a9
    if(integer::condition("JLE",flags)) goto L0046a7a9;
  }
  L0046a797: { // 0x46a797: 8b15e4e48400 MOV EDX,dword ptr [0x0084e4e4]
    s.dx = m.r32((0x0084e4e4u));
  }
  L0046a79d: { // 0x46a79d: 3902 CMP dword ptr [EDX],EAX
    (void)integer::sub(m.r32((s.dx)),s.ax,32,flags);
  }
  L0046a79f: { // 0x46a79f: 7415 JZ 0x0046a7b6
    if(integer::condition("JZ",flags)) goto L0046a7b6;
  }
  L0046a7a1: { // 0x46a7a1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0046a7a2: { // 0x46a7a2: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L0046a7a5: { // 0x46a7a5: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L0046a7a7: { // 0x46a7a7: 7cf4 JL 0x0046a79d
    if(integer::condition("JL",flags)) goto L0046a79d;
  }
  L0046a7a9: { // 0x46a7a9: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0046a7ac: { // 0x46a7ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046a7ad: { // 0x46a7ad: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  L0046a7b3: { // 0x46a7b3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0046a7b6: { // 0x46a7b6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0046a7b8: { // 0x46a7b8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046a7b9: { // 0x46a7b9: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  L0046a7bf: { // 0x46a7bf: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0046a7c2: { // 0x46a7c2: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  L0046a7c9: { // 0x46a7c9: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  L0046a7cf: { // 0x46a7cf: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00532be0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00532be0: { // 0x532be0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00532be1: { // 0x532be1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00532be3: { // 0x532be3: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00532be6: { // 0x532be6: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532be9: { // 0x532be9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00532beb: { // 0x532beb: 7c28 JL 0x00532c15
    if(integer::condition("JL",flags)) goto L00532c15;
  }
  L00532bed: { // 0x532bed: 8a460d MOV AL,byte ptr [ESI + 0xd]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000du)));
  }
  L00532bf0: { // 0x532bf0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532bf2: { // 0x532bf2: 7504 JNZ 0x00532bf8
    if(integer::condition("JNZ",flags)) goto L00532bf8;
  }
  L00532bf4: { // 0x532bf4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00532bf6: { // 0x532bf6: 7517 JNZ 0x00532c0f
    if(integer::condition("JNZ",flags)) goto L00532c0f;
  }
  L00532bf8: { // 0x532bf8: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  L00532bfb: { // 0x532bfb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00532bfd: { // 0x532bfd: 7e10 JLE 0x00532c0f
    if(integer::condition("JLE",flags)) goto L00532c0f;
  }
  L00532bff: { // 0x532bff: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00532c01: { // 0x532c01: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00532c03: { // 0x532c03: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00532c05: { // 0x532c05: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00532c06: { // 0x532c06: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00532c08: { // 0x532c08: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),5450763u); flags=s.arithmetic_flags;
  }
  L00532c0b: { // 0x532c0b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532c0d: { // 0x532c0d: 7506 JNZ 0x00532c15
    if(integer::condition("JNZ",flags)) goto L00532c15;
  }
  L00532c0f: { // 0x532c0f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00532c11: { // 0x532c11: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532c12: { // 0x532c12: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00532c15: { // 0x532c15: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c18: { // 0x532c18: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00532c19: { // 0x532c19: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L00532c1d: { // 0x532c1d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00532c1e: { // 0x532c1e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00532c20: { // 0x532c20: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00532c22: { // 0x532c22: 7e18 JLE 0x00532c3c
    if(integer::condition("JLE",flags)) goto L00532c3c;
  }
  L00532c24: { // 0x532c24: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00532c27: { // 0x532c27: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00532c28: { // 0x532c28: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L00532c2b: { // 0x532c2b: e840a50900 CALL 0x005cd170
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cd170u,5450800u); flags=s.arithmetic_flags;
  }
  L00532c30: { // 0x532c30: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00532c32: { // 0x532c32: 7508 JNZ 0x00532c3c
    if(integer::condition("JNZ",flags)) goto L00532c3c;
  }
  L00532c34: { // 0x532c34: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c37: { // 0x532c37: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00532c38: { // 0x532c38: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L00532c3a: { // 0x532c3a: 7ce8 JL 0x00532c24
    if(integer::condition("JL",flags)) goto L00532c24;
  }
  L00532c3c: { // 0x532c3c: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c3f: { // 0x532c3f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00532c40: { // 0x532c40: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00532c42: { // 0x532c42: 7c10 JL 0x00532c54
    if(integer::condition("JL",flags)) goto L00532c54;
  }
  L00532c44: { // 0x532c44: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00532c47: { // 0x532c47: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00532c48: { // 0x532c48: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L00532c4a: { // 0x532c4a: 8b548104 MOV EDX,dword ptr [ECX + EAX*0x4 + 0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)+0x00000004u));
  }
  L00532c4e: { // 0x532c4e: 89548108 MOV dword ptr [ECX + EAX*0x4 + 0x8],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)+0x00000008u), s.dx);
  }
  L00532c52: { // 0x532c52: 7df0 JGE 0x00532c44
    if(integer::condition("JGE",flags)) goto L00532c44;
  }
  L00532c54: { // 0x532c54: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00532c57: { // 0x532c57: 891cb8 MOV dword ptr [EAX + EDI*0x4],EBX
    m.w32((s.ax+(s.di * 0x00000004u)), s.bx);
  }
  L00532c5a: { // 0x532c5a: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00532c5d: { // 0x532c5d: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00532c5e: { // 0x532c5e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00532c5f: { // 0x532c5f: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  L00532c62: { // 0x532c62: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00532c63: { // 0x532c63: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00532c68: { // 0x532c68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00532c69: { // 0x532c69: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00658720(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00658720: { // 0x658720: 81ec8c000000 SUB ESP,0x8c
    f.sp = integer::sub(f.sp,0x0000008cu,32,flags);
  }
  L00658726: { // 0x658726: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00658727: { // 0x658727: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00658729: { // 0x658729: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0065872a: { // 0x65872a: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0065872e: { // 0x65872e: 8d83121a0000 LEA EAX,[EBX + 0x1a12]
    s.ax = (s.bx+0x00001a12u);
  }
  L00658734: { // 0x658734: b932000000 MOV ECX,0x32
    s.cx = 0x00000032u;
  }
  L00658739: { // 0x658739: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  L0065873c: { // 0x65873c: 83c029 ADD EAX,0x29
    s.ax = integer::add(s.ax,0x00000029u,32,flags);
  }
  L0065873f: { // 0x65873f: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00658740: { // 0x658740: 75f7 JNZ 0x00658739
    if(integer::condition("JNZ",flags)) goto L00658739;
  }
  L00658742: { // 0x658742: 8bac2498000000 MOV EBP,dword ptr [ESP + 0x98]
    s.bp = m.r32((f.sp+0x00000098u));
  }
  L00658749: { // 0x658749: 68f4b97d00 PUSH 0x7db9f4
    f.push(m,0x007db9f4u);
  }
  L0065874e: { // 0x65874e: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00658750: { // 0x658750: e8fb37ebff CALL 0x0050bf50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050bf50u,6653781u); flags=s.arithmetic_flags;
  }
  L00658755: { // 0x658755: 83f832 CMP EAX,0x32
    (void)integer::sub(s.ax,0x00000032u,32,flags);
  }
  L00658758: { // 0x658758: 7d12 JGE 0x0065876c
    if(integer::condition("JGE",flags)) goto L0065876c;
  }
  L0065875a: { // 0x65875a: 68f4b97d00 PUSH 0x7db9f4
    f.push(m,0x007db9f4u);
  }
  L0065875f: { // 0x65875f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00658761: { // 0x658761: e8ea37ebff CALL 0x0050bf50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050bf50u,6653798u); flags=s.arithmetic_flags;
  }
  L00658766: { // 0x658766: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L0065876a: { // 0x65876a: eb08 JMP 0x00658774
    goto L00658774;
  }
  L0065876c: { // 0x65876c: c744240832000000 MOV dword ptr [ESP + 0x8],0x32
    m.w32((f.sp+0x00000008u), 0x00000032u);
  }
  L00658774: { // 0x658774: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00658778: { // 0x658778: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  L00658780: { // 0x658780: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00658782: { // 0x658782: 0f8ec6000000 JLE 0x0065884e
    if(integer::condition("JLE",flags)) goto L0065884e;
  }
  L00658788: { // 0x658788: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00658789: { // 0x658789: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0065878a: { // 0x65878a: eb04 JMP 0x00658790
    goto L00658790;
  }
  L0065878c: { // 0x65878c: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00658790: { // 0x658790: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00658794: { // 0x658794: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00658796: { // 0x658796: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00658797: { // 0x658797: 68f4b97d00 PUSH 0x7db9f4
    f.push(m,0x007db9f4u);
  }
  L0065879c: { // 0x65879c: e8af3aebff CALL 0x0050c250
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050c250u,6653857u); flags=s.arithmetic_flags;
  }
  L006587a1: { // 0x6587a1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006587a3: { // 0x6587a3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006587a4: { // 0x6587a4: e8945f1100 CALL 0x0076e73d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e73du,6653865u); flags=s.arithmetic_flags;
  }
  L006587a9: { // 0x6587a9: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006587ac: { // 0x6587ac: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L006587b0: { // 0x6587b0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L006587b2: { // 0x6587b2: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  L006587b7: { // 0x6587b7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006587b8: { // 0x6587b8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006587ba: { // 0x6587ba: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006587bb: { // 0x6587bb: 68f4b97d00 PUSH 0x7db9f4
    f.push(m,0x007db9f4u);
  }
  L006587c0: { // 0x6587c0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006587c2: { // 0x6587c2: e82956ebff CALL 0x0050ddf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050ddf0u,6653895u); flags=s.arithmetic_flags;
  }
  L006587c7: { // 0x6587c7: 8d54241c LEA EDX,[ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  L006587cb: { // 0x6587cb: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  L006587d0: { // 0x6587d0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006587d1: { // 0x6587d1: e82c601100 CALL 0x0076e802
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e802u,6653910u); flags=s.arithmetic_flags;
  }
  L006587d6: { // 0x6587d6: 8d0cb6 LEA ECX,[ESI + ESI*0x4]
    s.cx = (s.si+(s.si * 0x00000004u));
  }
  L006587d9: { // 0x6587d9: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L006587db: { // 0x6587db: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006587dd: { // 0x6587dd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006587df: { // 0x6587df: 8d1ccb LEA EBX,[EBX + ECX*0x8]
    s.bx = (s.bx+(s.cx * 0x00000008u));
  }
  L006587e2: { // 0x6587e2: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  L006587e5: { // 0x6587e5: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L006587e7: { // 0x6587e7: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L006587e9: { // 0x6587e9: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006587eb: { // 0x6587eb: 8d93121a0000 LEA EDX,[EBX + 0x1a12]
    s.dx = (s.bx+0x00001a12u);
  }
  L006587f1: { // 0x6587f1: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006587f3: { // 0x6587f3: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L006587f5: { // 0x6587f5: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L006587f7: { // 0x6587f7: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  L006587fc: { // 0x6587fc: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L006587ff: { // 0x6587ff: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00658801: { // 0x658801: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00658803: { // 0x658803: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00658805: { // 0x658805: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L00658808: { // 0x658808: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L0065880a: { // 0x65880a: e8f35f1100 CALL 0x0076e802
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e802u,6653967u); flags=s.arithmetic_flags;
  }
  L0065880f: { // 0x65880f: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00658812: { // 0x658812: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00658814: { // 0x658814: 7414 JZ 0x0065882a
    if(integer::condition("JZ",flags)) goto L0065882a;
  }
  L00658816: { // 0x658816: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00658817: { // 0x658817: e8215f1100 CALL 0x0076e73d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e73du,6653980u); flags=s.arithmetic_flags;
  }
  L0065881c: { // 0x65881c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0065881f: { // 0x65881f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00658821: { // 0x658821: 0f95c1 SETNZ CL
    s.cx = with_al(s.cx, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L00658824: { // 0x658824: 888b3a1a0000 MOV byte ptr [EBX + 0x1a3a],CL
    m.w8((s.bx+0x00001a3au), (s.cx & 0xffu));
  }
  L0065882a: { // 0x65882a: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0065882e: { // 0x65882e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00658832: { // 0x658832: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00658833: { // 0x658833: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00658835: { // 0x658835: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00658839: { // 0x658839: 0f8c4dffffff JL 0x0065878c
    if(integer::condition("JL",flags)) goto L0065878c;
  }
  L0065883f: { // 0x65883f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00658840: { // 0x658840: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00658841: { // 0x658841: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00658842: { // 0x658842: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00658844: { // 0x658844: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00658845: { // 0x658845: 81c48c000000 ADD ESP,0x8c
    f.sp = integer::add(f.sp,0x0000008cu,32,flags);
  }
  L0065884b: { // 0x65884b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0065884e: { // 0x65884e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0065884f: { // 0x65884f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00658851: { // 0x658851: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00658852: { // 0x658852: 81c48c000000 ADD ESP,0x8c
    f.sp = integer::add(f.sp,0x0000008cu,32,flags);
  }
  L00658858: { // 0x658858: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00676f30(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00676f30: { // 0x676f30: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00676f31: { // 0x676f31: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00676f32: { // 0x676f32: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00676f33: { // 0x676f33: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00676f34: { // 0x676f34: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00676f36: { // 0x676f36: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L00676f38: { // 0x676f38: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00676f3a: { // 0x676f3a: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L00676f3d: { // 0x676f3d: c644240f01 MOV byte ptr [ESP + 0xf],0x1
    m.w8((f.sp+0x0000000fu), 0x00000001u);
  }
  L00676f42: { // 0x676f42: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00676f44: { // 0x676f44: 7e70 JLE 0x00676fb6
    if(integer::condition("JLE",flags)) goto L00676fb6;
  }
  L00676f46: { // 0x676f46: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00676f47: { // 0x676f47: 8d7760 LEA ESI,[EDI + 0x60]
    s.si = (s.di+0x00000060u);
  }
  L00676f4a: { // 0x676f4a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00676f4c: { // 0x676f4c: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00676f50: { // 0x676f50: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00676f52: { // 0x676f52: 7516 JNZ 0x00676f6a
    if(integer::condition("JNZ",flags)) goto L00676f6a;
  }
  L00676f54: { // 0x676f54: e8d724e4ff CALL 0x004b9430
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b9430u,6778713u); flags=s.arithmetic_flags;
  }
  L00676f59: { // 0x676f59: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L00676f5f: { // 0x676f5f: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L00676f61: { // 0x676f61: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00676f68: { // 0x676f68: eb09 JMP 0x00676f73
    goto L00676f73;
  }
  L00676f6a: { // 0x676f6a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00676f6c: { // 0x676f6c: 7405 JZ 0x00676f73
    if(integer::condition("JZ",flags)) goto L00676f73;
  }
  L00676f6e: { // 0x676f6e: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00676f73: { // 0x676f73: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  L00676f76: { // 0x676f76: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00676f77: { // 0x676f77: 83c630 ADD ESI,0x30
    s.si = integer::add(s.si,0x00000030u,32,flags);
  }
  L00676f7a: { // 0x676f7a: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00676f7c: { // 0x676f7c: 7ccc JL 0x00676f4a
    if(integer::condition("JL",flags)) goto L00676f4a;
  }
  L00676f7e: { // 0x676f7e: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00676f80: { // 0x676f80: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00676f81: { // 0x676f81: 742b JZ 0x00676fae
    if(integer::condition("JZ",flags)) goto L00676fae;
  }
  L00676f83: { // 0x676f83: 8b4734 MOV EAX,dword ptr [EDI + 0x34]
    s.ax = m.r32((s.di+0x00000034u));
  }
  L00676f86: { // 0x676f86: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00676f89: { // 0x676f89: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L00676f8c: { // 0x676f8c: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00676f92: { // 0x676f92: e8e93cffff CALL 0x0066ac80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0066ac80u,6778775u); flags=s.arithmetic_flags;
  }
  L00676f97: { // 0x676f97: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00676f99: { // 0x676f99: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00676f9e: { // 0x676f9e: c6473801 MOV byte ptr [EDI + 0x38],0x1
    m.w8((s.di+0x00000038u), 0x00000001u);
  }
  L00676fa2: { // 0x676fa2: e88990e6ff CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,6778791u); flags=s.arithmetic_flags;
  }
  L00676fa7: { // 0x676fa7: c60503f7810001 MOV byte ptr [0x0081f703],0x1
    m.w8((0x0081f703u), 0x00000001u);
  }
  L00676fae: { // 0x676fae: 8a44240f MOV AL,byte ptr [ESP + 0xf]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000fu)));
  }
  L00676fb2: { // 0x676fb2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00676fb4: { // 0x676fb4: 7418 JZ 0x00676fce
    if(integer::condition("JZ",flags)) goto L00676fce;
  }
  L00676fb6: { // 0x676fb6: 8b4734 MOV EAX,dword ptr [EDI + 0x34]
    s.ax = m.r32((s.di+0x00000034u));
  }
  L00676fb9: { // 0x676fb9: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  L00676fbc: { // 0x676fbc: c1e105 SHL ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::left);
  }
  L00676fbf: { // 0x676fbf: 81c10810aa00 ADD ECX,0xaa1008
    s.cx = integer::add(s.cx,0x00aa1008u,32,flags);
  }
  L00676fc5: { // 0x676fc5: e8b63cffff CALL 0x0066ac80
    s.arithmetic_flags=flags; invoke(m,s,f,0x0066ac80u,6778826u); flags=s.arithmetic_flags;
  }
  L00676fca: { // 0x676fca: c6473900 MOV byte ptr [EDI + 0x39],0x0
    m.w8((s.di+0x00000039u), 0x00000000u);
  }
  L00676fce: { // 0x676fce: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00676fcf: { // 0x676fcf: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L00676fd1: { // 0x676fd1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00676fd2: { // 0x676fd2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00676fd3: { // 0x676fd3: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00676fd4: { // 0x676fd4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006de750(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006de750: { // 0x6de750: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006de755: { // 0x6de755: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006de758: { // 0x6de758: 8a882a220000 MOV CL,byte ptr [EAX + 0x222a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000222au)));
  }
  L006de75e: { // 0x6de75e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006de75f: { // 0x6de75f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006de761: { // 0x6de761: 7473 JZ 0x006de7d6
    if(integer::condition("JZ",flags)) goto L006de7d6;
  }
  L006de763: { // 0x6de763: a14886aa00 MOV EAX,[0x00aa8648]
    s.ax = m.r32((0x00aa8648u));
  }
  L006de768: { // 0x6de768: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006de76a: { // 0x6de76a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006de76c: { // 0x6de76c: 7e68 JLE 0x006de7d6
    if(integer::condition("JLE",flags)) goto L006de7d6;
  }
  L006de76e: { // 0x6de76e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006de76f: { // 0x6de76f: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  L006de773: { // 0x6de773: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006de774: { // 0x6de774: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L006de77a: { // 0x6de77a: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L006de77d: { // 0x6de77d: 8bb900010000 MOV EDI,dword ptr [ECX + 0x100]
    s.di = m.r32((s.cx+0x00000100u));
  }
  L006de783: { // 0x6de783: 8b8108010000 MOV EAX,dword ptr [ECX + 0x108]
    s.ax = m.r32((s.cx+0x00000108u));
  }
  L006de789: { // 0x6de789: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L006de78c: { // 0x6de78c: 740e JZ 0x006de79c
    if(integer::condition("JZ",flags)) goto L006de79c;
  }
  L006de78e: { // 0x6de78e: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L006de794: { // 0x6de794: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L006de796: { // 0x6de796: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L006de798: { // 0x6de798: 7d06 JGE 0x006de7a0
    if(integer::condition("JGE",flags)) goto L006de7a0;
  }
  L006de79a: { // 0x6de79a: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006de79c: { // 0x6de79c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006de79e: { // 0x6de79e: 752a JNZ 0x006de7ca
    if(integer::condition("JNZ",flags)) goto L006de7ca;
  }
  L006de7a0: { // 0x6de7a0: e83b020000 CALL 0x006de9e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006de9e0u,7202725u); flags=s.arithmetic_flags;
  }
  L006de7a5: { // 0x6de7a5: 8b0d3c86aa00 MOV ECX,dword ptr [0x00aa863c]
    s.cx = m.r32((0x00aa863cu));
  }
  L006de7ab: { // 0x6de7ab: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006de7b0: { // 0x6de7b0: 8b14b1 MOV EDX,dword ptr [ECX + ESI*0x4]
    s.dx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L006de7b3: { // 0x6de7b3: 8b0cb1 MOV ECX,dword ptr [ECX + ESI*0x4]
    s.cx = m.r32((s.cx+(s.si * 0x00000004u)));
  }
  L006de7b6: { // 0x6de7b6: 81c100010000 ADD ECX,0x100
    s.cx = integer::add(s.cx,0x00000100u,32,flags);
  }
  L006de7bc: { // 0x6de7bc: 8b929c000000 MOV EDX,dword ptr [EDX + 0x9c]
    s.dx = m.r32((s.dx+0x0000009cu));
  }
  L006de7c2: { // 0x6de7c2: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L006de7c4: { // 0x6de7c4: 895904 MOV dword ptr [ECX + 0x4],EBX
    m.w32((s.cx+0x00000004u), s.bx);
  }
  L006de7c7: { // 0x6de7c7: 895108 MOV dword ptr [ECX + 0x8],EDX
    m.w32((s.cx+0x00000008u), s.dx);
  }
  L006de7ca: { // 0x6de7ca: a14886aa00 MOV EAX,[0x00aa8648]
    s.ax = m.r32((0x00aa8648u));
  }
  L006de7cf: { // 0x6de7cf: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006de7d0: { // 0x6de7d0: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006de7d2: { // 0x6de7d2: 7ca0 JL 0x006de774
    if(integer::condition("JL",flags)) goto L006de774;
  }
  L006de7d4: { // 0x6de7d4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006de7d5: { // 0x6de7d5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006de7d6: { // 0x6de7d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006de7d7: { // 0x6de7d7: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006de7da: { // 0x6de7da: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00770ea9(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00770ea9: { // 0x770ea9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00770eaa: { // 0x770eaa: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00770eac: { // 0x770eac: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770ead: { // 0x770ead: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770eae: { // 0x770eae: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00770eaf: { // 0x770eaf: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00770eb0: { // 0x770eb0: beffff0000 MOV ESI,0xffff
    s.si = 0x0000ffffu;
  }
  L00770eb5: { // 0x770eb5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00770eb6: { // 0x770eb6: ff3560728100 PUSH dword ptr [0x00817260]
    f.push(m,m.r32((0x00817260u)));
  }
  L00770ebc: { // 0x770ebc: e8d4800000 CALL 0x00778f95
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778f95u,7802561u); flags=s.arithmetic_flags;
  }
  L00770ec1: { // 0x770ec1: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770ec4: { // 0x770ec4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770ec5: { // 0x770ec5: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00770ec7: { // 0x770ec7: 8b450e MOV EAX,dword ptr [EBP + 0xe]
    s.ax = m.r32((s.bp+0x0000000eu));
  }
  L00770eca: { // 0x770eca: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770ecb: { // 0x770ecb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770ecc: { // 0x770ecc: 6625f07f AND AX,0x7ff0
    s.ax = with_ax(s.ax, integer::logical(((s.ax & 0xffffu))&(0x00007ff0u),16,flags));
  }
  L00770ed0: { // 0x770ed0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770ed1: { // 0x770ed1: 663df07f CMP AX,0x7ff0
    (void)integer::sub((s.ax & 0xffffu),0x00007ff0u,16,flags);
  }
  L00770ed5: { // 0x770ed5: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00770ed8: { // 0x770ed8: 7555 JNZ 0x00770f2f
    if(integer::condition("JNZ",flags)) goto L00770f2f;
  }
  L00770eda: { // 0x770eda: e87e7f0000 CALL 0x00778e5d
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778e5du,7802591u); flags=s.arithmetic_flags;
  }
  L00770edf: { // 0x770edf: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770ee0: { // 0x770ee0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00770ee2: { // 0x770ee2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770ee3: { // 0x770ee3: 7e2d JLE 0x00770f12
    if(integer::condition("JLE",flags)) goto L00770f12;
  }
  L00770ee5: { // 0x770ee5: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L00770ee8: { // 0x770ee8: 7e1a JLE 0x00770f04
    if(integer::condition("JLE",flags)) goto L00770f04;
  }
  L00770eea: { // 0x770eea: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00770eed: { // 0x770eed: 7523 JNZ 0x00770f12
    if(integer::condition("JNZ",flags)) goto L00770f12;
  }
  L00770eef: { // 0x770eef: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770ef2: { // 0x770ef2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00770ef3: { // 0x770ef3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770ef4: { // 0x770ef4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770ef5: { // 0x770ef5: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00770ef8: { // 0x770ef8: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  L00770efa: { // 0x770efa: e802770000 CALL 0x00778601
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778601u,7802623u); flags=s.arithmetic_flags;
  }
  L00770eff: { // 0x770eff: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00770f02: { // 0x770f02: eb70 JMP 0x00770f74
    goto L00770f74;
  }
  L00770f04: { // 0x770f04: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00770f05: { // 0x770f05: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00770f06: { // 0x770f06: e88a800000 CALL 0x00778f95
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778f95u,7802635u); flags=s.arithmetic_flags;
  }
  L00770f0b: { // 0x770f0b: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770f0e: { // 0x770f0e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770f0f: { // 0x770f0f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770f10: { // 0x770f10: eb62 JMP 0x00770f74
    goto L00770f74;
  }
  L00770f12: { // 0x770f12: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770f15: { // 0x770f15: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L00770f1b: { // 0x770f1b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00770f1c: { // 0x770f1c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f1d: { // 0x770f1d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f1e: { // 0x770f1e: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00770f21: { // 0x770f21: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770f24: { // 0x770f24: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f25: { // 0x770f25: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f26: { // 0x770f26: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00770f29: { // 0x770f29: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  L00770f2b: { // 0x770f2b: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  L00770f2d: { // 0x770f2d: eb3d JMP 0x00770f6c
    goto L00770f6c;
  }
  L00770f2f: { // 0x770f2f: e88a7e0000 CALL 0x00778dbe
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778dbeu,7802676u); flags=s.arithmetic_flags;
  }
  L00770f34: { // 0x770f34: dd5df8 FSTP double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00770f37: { // 0x770f37: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770f3a: { // 0x770f3a: dc5d08 FCOMP double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00770f3d: { // 0x770f3d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770f3e: { // 0x770f3e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770f3f: { // 0x770f3f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00770f41: { // 0x770f41: 9e SAHF
    flags=(flags&~0xd5u)|((s.ax>>8)&0xd5u);
  }
  L00770f42: { // 0x770f42: 750e JNZ 0x00770f52
    if(integer::condition("JNZ",flags)) goto L00770f52;
  }
  L00770f44: { // 0x770f44: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00770f45: { // 0x770f45: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00770f46: { // 0x770f46: e84a800000 CALL 0x00778f95
    s.arithmetic_flags=flags; invoke(m,s,f,0x00778f95u,7802699u); flags=s.arithmetic_flags;
  }
  L00770f4b: { // 0x770f4b: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770f4e: { // 0x770f4e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770f4f: { // 0x770f4f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00770f50: { // 0x770f50: eb22 JMP 0x00770f74
    goto L00770f74;
  }
  L00770f52: { // 0x770f52: f6c320 TEST BL,0x20
    (void)integer::logical(((s.bx & 0xffu))&(0x00000020u),8,flags);
  }
  L00770f55: { // 0x770f55: 75ed JNZ 0x00770f44
    if(integer::condition("JNZ",flags)) goto L00770f44;
  }
  L00770f57: { // 0x770f57: dd45f8 FLD double ptr [EBP + -0x8]
    const auto address=(s.bp-0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770f5a: { // 0x770f5a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00770f5b: { // 0x770f5b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f5c: { // 0x770f5c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f5d: { // 0x770f5d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00770f60: { // 0x770f60: dd4508 FLD double ptr [EBP + 0x8]
    const auto address=(s.bp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00770f63: { // 0x770f63: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f64: { // 0x770f64: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00770f65: { // 0x770f65: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00770f68: { // 0x770f68: 6a0b PUSH 0xb
    f.push(m,0x0000000bu);
  }
  L00770f6a: { // 0x770f6a: 6a10 PUSH 0x10
    f.push(m,0x00000010u);
  }
  L00770f6c: { // 0x770f6c: e844770000 CALL 0x007786b5
    s.arithmetic_flags=flags; invoke(m,s,f,0x007786b5u,7802737u); flags=s.arithmetic_flags;
  }
  L00770f71: { // 0x770f71: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00770f74: { // 0x770f74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00770f75: { // 0x770f75: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00770f76: { // 0x770f76: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L00770f77: { // 0x770f77: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
