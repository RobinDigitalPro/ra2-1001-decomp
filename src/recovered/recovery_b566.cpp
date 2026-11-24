#include "recovered/recovery_b566_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b566 {
namespace {
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_00053ab0(Memory&,State&,Frame&,const Operations&);
void f_00035420(Memory&,State&,Frame&,const Operations&);
void f_0035fd00(Memory&,State&,Frame&,const Operations&);
void f_00360f60(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0035f2c0(Memory&,State&,Frame&,const Operations&);
void f_0035fa70(Memory&,State&,Frame&,const Operations&);
void f_002e7010(Memory&,State&,Frame&,const Operations&);
void f_00208380(Memory&,State&,Frame&,const Operations&);
void f_00298010(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),4264836u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4264850u); flags=s.arithmetic_flags;
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
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000007cu)),4264904u); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    s.ax = integer::imul(s.ax,m.r32((s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7732530u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7732548u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453ab0u,7732612u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7732654u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7732703u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7732718u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7732740u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),7732760u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732846u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732945u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7732999u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7733108u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7733206u); flags=s.arithmetic_flags;
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
  L00760f99: { // 0x760f99: d9c0 FLD ST0
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
  L00760fbb: { // 0x760fbb: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fbd: { // 0x760fbd: d8e1 FSUB ST0,ST1
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
  L00760fc7: { // 0x760fc7: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fc9: { // 0x760fc9: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fcb: { // 0x760fcb: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fcf: { // 0x760fcf: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fd1: { // 0x760fd1: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fd5: { // 0x760fd5: ddd8 FSTP ST0
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
  L00760fea: { // 0x760fea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fec: { // 0x760fec: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00760ff1: { // 0x760ff1: eb0e JMP 0x00761001
    goto L00761001;
  }
  L00760ff3: { // 0x760ff3: d8dc FCOMP ST4
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
  L0076102a: { // 0x76102a: d8db FCOMP ST3
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
  L00761043: { // 0x761043: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761045: { // 0x761045: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0076104a: { // 0x76104a: eb0e JMP 0x0076105a
    goto L0076105a;
  }
  L0076104c: { // 0x76104c: d8db FCOMP ST3
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
  L00761072: { // 0x761072: d8da FCOMP ST2
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
  L0076109e: { // 0x76109e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610a0: { // 0x7610a0: d9c0 FLD ST0
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
  L007610b2: { // 0x7610b2: d9c0 FLD ST0
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
  L007610bf: { // 0x7610bf: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610c1: { // 0x7610c1: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610c5: { // 0x7610c5: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610c9: { // 0x7610c9: d9c0 FLD ST0
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
  L007610e2: { // 0x7610e2: ddd8 FSTP ST0
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
  L00761112: { // 0x761112: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761114: { // 0x761114: d9c1 FLD ST1
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
  L00761122: { // 0x761122: d9c2 FLD ST2
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
  L00761134: { // 0x761134: d9c1 FLD ST1
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
  L00761147: { // 0x761147: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761149: { // 0x761149: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0076114e: { // 0x76114e: eb0e JMP 0x0076115e
    goto L0076115e;
  }
  L00761150: { // 0x761150: d8db FCOMP ST3
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
  L0076118a: { // 0x76118a: d9c1 FLD ST1
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
  L0076119d: { // 0x76119d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076119f: { // 0x76119f: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L007611a4: { // 0x7611a4: eb0e JMP 0x007611b4
    goto L007611b4;
  }
  L007611a6: { // 0x7611a6: d8db FCOMP ST3
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
  L007611d9: { // 0x7611d9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611db: { // 0x7611db: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611dd: { // 0x7611dd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611df: { // 0x7611df: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L007611e3: { // 0x7611e3: e868980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737832u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737847u); flags=s.arithmetic_flags;
  }
  L007611f7: { // 0x7611f7: dd442468 FLD double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.load64(read64(m,address));
  }
  L007611fb: { // 0x7611fb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L007611fe: { // 0x7611fe: e84d980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737859u); flags=s.arithmetic_flags;
  }
  L00761203: { // 0x761203: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761207: { // 0x761207: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L00761209: { // 0x761209: e842980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737870u); flags=s.arithmetic_flags;
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
  L0076121c: { // 0x76121c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076121e: { // 0x76121e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761220: { // 0x761220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761221: { // 0x761221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761222: { // 0x761222: ddd8 FSTP ST0
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7729877u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7729895u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760f60u,7729982u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),7730033u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7730056u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730131u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730193u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730228u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),7730241u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730295u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730322u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730430u); flags=s.arithmetic_flags;
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
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730517u); flags=s.arithmetic_flags;
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
void f_0035fa70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075fa70: { // 0x75fa70: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  L0075fa73: { // 0x75fa73: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L0075fa77: { // 0x75fa77: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fa78: { // 0x75fa78: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075fa79: { // 0x75fa79: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0075fa7b: { // 0x75fa7b: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0075fa7d: { // 0x75fa7d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0075fa80: { // 0x75fa80: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fa81: { // 0x75fa81: 8b7808 MOV EDI,dword ptr [EAX + 0x8]
    s.di = m.r32((s.ax+0x00000008u));
  }
  L0075fa84: { // 0x75fa84: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075fa87: { // 0x75fa87: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L0075fa8b: { // 0x75fa8b: 8d7c0fff LEA EDI,[EDI + ECX*0x1 + -0x1]
    s.di = (s.di+(s.cx * 0x00000001u)-0x00000001u);
  }
  L0075fa8f: { // 0x75fa8f: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L0075fa93: { // 0x75fa93: 8d4410ff LEA EAX,[EAX + EDX*0x1 + -0x1]
    s.ax = (s.ax+(s.dx * 0x00000001u)-0x00000001u);
  }
  L0075fa97: { // 0x75fa97: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L0075fa9b: { // 0x75fa9b: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L0075fa9f: { // 0x75fa9f: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L0075faa3: { // 0x75faa3: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0075faa7: { // 0x75faa7: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0075faab: { // 0x75faab: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0075faaf: { // 0x75faaf: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0075fab3: { // 0x75fab3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fab4: { // 0x75fab4: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0075fab8: { // 0x75fab8: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0075fabc: { // 0x75fabc: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0075fac0: { // 0x75fac0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075fac2: { // 0x75fac2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fac3: { // 0x75fac3: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fac4: { // 0x75fac4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fac5: { // 0x75fac5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075fac7: { // 0x75fac7: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731914u); flags=s.arithmetic_flags;
  }
  L0075faca: { // 0x75faca: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075facc: { // 0x75facc: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0075fad0: { // 0x75fad0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fad1: { // 0x75fad1: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0075fad5: { // 0x75fad5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fad6: { // 0x75fad6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fad7: { // 0x75fad7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fad8: { // 0x75fad8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075fada: { // 0x75fada: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731933u); flags=s.arithmetic_flags;
  }
  L0075fadd: { // 0x75fadd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075fadf: { // 0x75fadf: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0075fae3: { // 0x75fae3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075fae4: { // 0x75fae4: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0075fae8: { // 0x75fae8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fae9: { // 0x75fae9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075faea: { // 0x75faea: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075faeb: { // 0x75faeb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075faed: { // 0x75faed: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731952u); flags=s.arithmetic_flags;
  }
  L0075faf0: { // 0x75faf0: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0075faf2: { // 0x75faf2: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0075faf6: { // 0x75faf6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075faf7: { // 0x75faf7: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L0075fafb: { // 0x75fafb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075fafc: { // 0x75fafc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075fafd: { // 0x75fafd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075fafe: { // 0x75fafe: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075fb00: { // 0x75fb00: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7731971u); flags=s.arithmetic_flags;
  }
  L0075fb03: { // 0x75fb03: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075fb04: { // 0x75fb04: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075fb05: { // 0x75fb05: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075fb07: { // 0x75fb07: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075fb08: { // 0x75fb08: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  L0075fb0b: { // 0x75fb0b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_002e7010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006e7010: { // 0x6e7010: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L006e7013: { // 0x6e7013: 8b1584198200 MOV EDX,dword ptr [0x00821984]
    s.dx = m.r32((0x00821984u));
  }
  L006e7019: { // 0x6e7019: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006e701b: { // 0x6e701b: 8b0d80198200 MOV ECX,dword ptr [0x00821980]
    s.cx = m.r32((0x00821980u));
  }
  L006e7021: { // 0x6e7021: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006e7022: { // 0x6e7022: 8a1d7087a200 MOV BL,byte ptr [0x00a28770]
    s.bx = with_al(s.bx, m.r8((0x00a28770u)));
  }
  L006e7028: { // 0x6e7028: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006e7029: { // 0x6e7029: 8b358c198200 MOV ESI,dword ptr [0x0082198c]
    s.si = m.r32((0x0082198cu));
  }
  L006e702f: { // 0x6e702f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006e7030: { // 0x6e7030: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L006e7034: { // 0x6e7034: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006e7036: { // 0x6e7036: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006e7038: { // 0x6e7038: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006e703c: { // 0x6e703c: 8b1588198200 MOV EDX,dword ptr [0x00821988]
    s.dx = m.r32((0x00821988u));
  }
  L006e7042: { // 0x6e7042: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006e7044: { // 0x6e7044: 750f JNZ 0x006e7055
    if(integer::condition("JNZ",flags)) goto L006e7055;
  }
  L006e7046: { // 0x6e7046: 8a1d5389a200 MOV BL,byte ptr [0x00a28953]
    s.bx = with_al(s.bx, m.r8((0x00a28953u)));
  }
  L006e704c: { // 0x6e704c: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006e704e: { // 0x6e704e: 7505 JNZ 0x006e7055
    if(integer::condition("JNZ",flags)) goto L006e7055;
  }
  L006e7050: { // 0x6e7050: b9a8000000 MOV ECX,0xa8
    s.cx = 0x000000a8u;
  }
  L006e7055: { // 0x6e7055: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006e7057: { // 0x6e7057: 81eaa8000000 SUB EDX,0xa8
    s.dx = integer::sub(s.dx,0x000000a8u,32,flags);
  }
  L006e705d: { // 0x6e705d: 83ee20 SUB ESI,0x20
    s.si = integer::sub(s.si,0x00000020u,32,flags);
  }
  L006e7060: { // 0x6e7060: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L006e7062: { // 0x6e7062: 897b04 MOV dword ptr [EBX + 0x4],EDI
    m.w32((s.bx+0x00000004u), s.di);
  }
  L006e7065: { // 0x6e7065: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006e7066: { // 0x6e7066: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  L006e7069: { // 0x6e7069: 89730c MOV dword ptr [EBX + 0xc],ESI
    m.w32((s.bx+0x0000000cu), s.si);
  }
  L006e706c: { // 0x6e706c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006e706d: { // 0x6e706d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006e706e: { // 0x6e706e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L006e7071: { // 0x6e7071: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00208380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00608380: { // 0x00608380: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00608383: { // 0x00608383: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L00608387: { // 0x00608387: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00608388: { // 0x00608388: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0060838a: { // 0x0060838a: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00608390: { // 0x00608390: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00608391: { // 0x00608391: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00608392: { // 0x00608392: e879fc0800 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6325143u); flags=s.arithmetic_flags;
  }
  L00608397: { // 0x00608397: 8b0d70198200 MOV ECX,dword ptr [0x00821970]
    s.cx = m.r32((0x00821970u));
  }
  L0060839d: { // 0x0060839d: 8b1574198200 MOV EDX,dword ptr [0x00821974]
    s.dx = m.r32((0x00821974u));
  }
  L006083a3: { // 0x006083a3: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006083a7: { // 0x006083a7: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L006083a9: { // 0x006083a9: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L006083ad: { // 0x006083ad: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006083af: { // 0x006083af: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L006083b1: { // 0x006083b1: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L006083b4: { // 0x006083b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006083b6: { // 0x006083b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006083b7: { // 0x006083b7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006083ba: { // 0x006083ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00298010(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00698010: { // 0x698010: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00698013: { // 0x698013: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00698014: { // 0x698014: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00698018: { // 0x698018: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00698019: { // 0x698019: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069801a: { // 0x69801a: 8b33 MOV ESI,dword ptr [EBX]
    s.si = m.r32((s.bx));
  }
  L0069801c: { // 0x69801c: 8b4304 MOV EAX,dword ptr [EBX + 0x4]
    s.ax = m.r32((s.bx+0x00000004u));
  }
  L0069801f: { // 0x69801f: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00698023: { // 0x698023: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00698025: { // 0x698025: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698028: { // 0x698028: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00698029: { // 0x698029: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L0069802d: { // 0x69802d: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00698030: { // 0x698030: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L00698033: { // 0x698033: c744241c00000000 MOV dword ptr [ESP + 0x1c],0x0
    m.w32((f.sp+0x0000001cu), 0x00000000u);
  }
  L0069803b: { // 0x69803b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069803e: { // 0x69803e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069803f: { // 0x69803f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698041: { // 0x698041: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00698043: { // 0x698043: 8d0476 LEA EAX,[ESI + ESI*0x2]
    s.ax = (s.si+(s.si * 0x00000002u));
  }
  L00698046: { // 0x698046: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698048: { // 0x698048: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069804b: { // 0x69804b: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L0069804d: { // 0x69804d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069804e: { // 0x69804e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698050: { // 0x698050: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698052: { // 0x698052: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L00698054: { // 0x698054: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L00698057: { // 0x698057: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00698059: { // 0x698059: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0069805b: { // 0x69805b: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0069805e: { // 0x69805e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069805f: { // 0x69805f: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698061: { // 0x698061: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00698063: { // 0x698063: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00698065: { // 0x698065: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  L00698068: { // 0x698068: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069806a: { // 0x69806a: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0069806d: { // 0x69806d: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00698071: { // 0x698071: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  L00698073: { // 0x698073: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698074: { // 0x698074: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00698076: { // 0x698076: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L0069807a: { // 0x69807a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069807c: { // 0x69807c: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L0069807e: { // 0x69807e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00698080: { // 0x698080: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00698081: { // 0x698081: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698087: { // 0x698087: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698089: { // 0x698089: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0069808b: { // 0x69808b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0069808d: { // 0x69808d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0069808e: { // 0x69808e: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00698094: { // 0x698094: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00698096: { // 0x698096: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00698098: { // 0x698098: c1ff08 SAR EDI,0x8
    s.di = integer::shift(s.di,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809b: { // 0x69809b: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0069809e: { // 0x69809e: 81fbd8020000 CMP EBX,0x2d8
    (void)integer::sub(s.bx,0x000002d8u,32,flags);
  }
  L006980a4: { // 0x6980a4: 7c08 JL 0x006980ae
    if(integer::condition("JL",flags)) goto L006980ae;
  }
  L006980a6: { // 0x6980a6: c744241c01000000 MOV dword ptr [ESP + 0x1c],0x1
    m.w32((f.sp+0x0000001cu), 0x00000001u);
  }
  L006980ae: { // 0x6980ae: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L006980b2: { // 0x6980b2: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  L006980b8: { // 0x6980b8: da44241c FIADD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L006980bc: { // 0x6980bc: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L006980c2: { // 0x6980c2: e889290d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914247u); flags=s.arithmetic_flags;
  }
  L006980c7: { // 0x6980c7: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006980c9: { // 0x6980c9: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L006980cd: { // 0x6980cd: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980cf: { // 0x6980cf: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980d2: { // 0x6980d2: 8b8db0000000 MOV ECX,dword ptr [EBP + 0xb0]
    s.cx = m.r32((s.bp+0x000000b0u));
  }
  L006980d8: { // 0x6980d8: 8badb4000000 MOV EBP,dword ptr [EBP + 0xb4]
    s.bp = m.r32((s.bp+0x000000b4u));
  }
  L006980de: { // 0x6980de: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L006980e0: { // 0x6980e0: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L006980e3: { // 0x6980e3: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L006980e5: { // 0x6980e5: 2bf5 SUB ESI,EBP
    s.si = integer::sub(s.si,s.bp,32,flags);
  }
  L006980e7: { // 0x6980e7: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L006980e9: { // 0x6980e9: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006980eb: { // 0x6980eb: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L006980ee: { // 0x6980ee: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006980f0: { // 0x6980f0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006980f1: { // 0x6980f1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006980f2: { // 0x6980f2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006980f3: { // 0x6980f3: 81f998feffff CMP ECX,0xfffffe98
    (void)integer::sub(s.cx,0xfffffe98u,32,flags);
  }
  L006980f9: { // 0x6980f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006980fa: { // 0x6980fa: 7d08 JGE 0x00698104
    if(integer::condition("JGE",flags)) goto L00698104;
  }
  L006980fc: { // 0x6980fc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006980fe: { // 0x6980fe: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698101: { // 0x698101: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00698104: { // 0x698104: 8b157060aa00 MOV EDX,dword ptr [0x00aa6070]
    s.dx = m.r32((0x00aa6070u));
  }
  L0069810a: { // 0x69810a: 81c268010000 ADD EDX,0x168
    s.dx = integer::add(s.dx,0x00000168u,32,flags);
  }
  L00698110: { // 0x698110: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00698112: { // 0x698112: 7e08 JLE 0x0069811c
    if(integer::condition("JLE",flags)) goto L0069811c;
  }
  L00698114: { // 0x698114: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698116: { // 0x698116: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698119: { // 0x698119: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069811c: { // 0x69811c: 3d4cffffff CMP EAX,0xffffff4c
    (void)integer::sub(s.ax,0xffffff4cu,32,flags);
  }
  L00698121: { // 0x698121: 7d08 JGE 0x0069812b
    if(integer::condition("JGE",flags)) goto L0069812b;
  }
  L00698123: { // 0x698123: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00698125: { // 0x698125: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00698128: { // 0x698128: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0069812b: { // 0x69812b: 8b0d7460aa00 MOV ECX,dword ptr [0x00aa6074]
    s.cx = m.r32((0x00aa6074u));
  }
  L00698131: { // 0x698131: 81c1b4000000 ADD ECX,0xb4
    s.cx = integer::add(s.cx,0x000000b4u,32,flags);
  }
  L00698137: { // 0x698137: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00698139: { // 0x698139: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0069813c: { // 0x69813c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0069813f: { // 0x69813f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x608560u:{Inputs i;i.cx=s.cx;i.dx=s.dx;i.fp=s.fp;s.ax=ra2::recovered::recovery_b338::fun_00608560(m,i);s.fp=i.fp;finish(m,s,child,0);break;}
case 4264592u:f_00011290(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
case 4264816u:f_00011370(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4324848u:f_0001fdf0(m,s,child,{});break;
case 4537008u:f_00053ab0(m,s,child,{});break;
case 4412448u:f_00035420(m,s,child,{});break;
case 7732480u:f_0035fd00(m,s,child,{});break;
case 7737184u:f_00360f60(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 7729856u:f_0035f2c0(m,s,child,{});break;
case 7731824u:f_0035fa70(m,s,child,{});break;
case 7237648u:f_002e7010(m,s,child,{});break;
case 6325120u:f_00208380(m,s,child,{});break;
case 6914064u:f_00298010(m,s,child,{});break;
default:throw std::domain_error("recovery566 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004ab230(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ab230: { // 0x4ab230: 81ecb4000000 SUB ESP,0xb4
    f.sp = integer::sub(f.sp,0x000000b4u,32,flags);
  }
  L004ab236: { // 0x4ab236: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ab237: { // 0x4ab237: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ab238: { // 0x4ab238: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004ab23a: { // 0x4ab23a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ab23b: { // 0x4ab23b: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab23e: { // 0x4ab23e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab240: { // 0x4ab240: 0f84ea010000 JZ 0x004ab430
    if(integer::condition("JZ",flags)) goto L004ab430;
  }
  L004ab246: { // 0x4ab246: 8bbc24c8000000 MOV EDI,dword ptr [ESP + 0xc8]
    s.di = m.r32((f.sp+0x000000c8u));
  }
  L004ab24d: { // 0x4ab24d: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L004ab250: { // 0x4ab250: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab252: { // 0x4ab252: 0f8ed8010000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab258: { // 0x4ab258: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L004ab25b: { // 0x4ab25b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab25d: { // 0x4ab25d: 0f8ecd010000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab263: { // 0x4ab263: a0c4137c00 MOV AL,[0x007c13c4]
    s.ax = with_al(s.ax, m.r8((0x007c13c4u)));
  }
  L004ab268: { // 0x4ab268: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab26a: { // 0x4ab26a: 0f849c010000 JZ 0x004ab40c
    if(integer::condition("JZ",flags)) goto L004ab40c;
  }
  L004ab270: { // 0x4ab270: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ab272: { // 0x4ab272: ff506c CALL dword ptr [EAX + 0x6c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000006cu)),4895349u); flags=s.arithmetic_flags;
  }
  L004ab275: { // 0x4ab275: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab277: { // 0x4ab277: 0f858f010000 JNZ 0x004ab40c
    if(integer::condition("JNZ",flags)) goto L004ab40c;
  }
  L004ab27d: { // 0x4ab27d: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab280: { // 0x4ab280: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L004ab282: { // 0x4ab282: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab283: { // 0x4ab283: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ab285: { // 0x4ab285: ff5134 CALL dword ptr [ECX + 0x34]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000034u)),4895368u); flags=s.arithmetic_flags;
  }
  L004ab288: { // 0x4ab288: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab28a: { // 0x4ab28a: 0f857c010000 JNZ 0x004ab40c
    if(integer::condition("JNZ",flags)) goto L004ab40c;
  }
  L004ab290: { // 0x4ab290: a0e09f8300 MOV AL,[0x00839fe0]
    s.ax = with_al(s.ax, m.r8((0x00839fe0u)));
  }
  L004ab295: { // 0x4ab295: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab297: { // 0x4ab297: 750d JNZ 0x004ab2a6
    if(integer::condition("JNZ",flags)) goto L004ab2a6;
  }
  L004ab299: { // 0x4ab299: a06889a200 MOV AL,[0x00a28968]
    s.ax = with_al(s.ax, m.r8((0x00a28968u)));
  }
  L004ab29e: { // 0x4ab29e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ab2a0: { // 0x4ab2a0: 0f848a010000 JZ 0x004ab430
    if(integer::condition("JZ",flags)) goto L004ab430;
  }
  L004ab2a6: { // 0x4ab2a6: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab2a9: { // 0x4ab2a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab2ab: { // 0x4ab2ab: 7455 JZ 0x004ab302
    if(integer::condition("JZ",flags)) goto L004ab302;
  }
  L004ab2ad: { // 0x4ab2ad: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004ab2af: { // 0x4ab2af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2b0: { // 0x4ab2b0: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4895411u); flags=s.arithmetic_flags;
  }
  L004ab2b3: { // 0x4ab2b3: 3dc2017688 CMP EAX,0x887601c2
    (void)integer::sub(s.ax,0x887601c2u,32,flags);
  }
  L004ab2b8: { // 0x4ab2b8: 7548 JNZ 0x004ab302
    if(integer::condition("JNZ",flags)) goto L004ab302;
  }
  L004ab2ba: { // 0x4ab2ba: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab2bd: { // 0x4ab2bd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2be: { // 0x4ab2be: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ab2c0: { // 0x4ab2c0: ff516c CALL dword ptr [ECX + 0x6c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x0000006cu)),4895427u); flags=s.arithmetic_flags;
  }
  L004ab2c3: { // 0x4ab2c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab2c5: { // 0x4ab2c5: 0f8565010000 JNZ 0x004ab430
    if(integer::condition("JNZ",flags)) goto L004ab430;
  }
  L004ab2cb: { // 0x4ab2cb: 8b461c MOV EAX,dword ptr [ESI + 0x1c]
    s.ax = m.r32((s.si+0x0000001cu));
  }
  L004ab2ce: { // 0x4ab2ce: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2cf: { // 0x4ab2cf: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004ab2d1: { // 0x4ab2d1: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4895444u); flags=s.arithmetic_flags;
  }
  L004ab2d4: { // 0x4ab2d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab2d6: { // 0x4ab2d6: 0f8554010000 JNZ 0x004ab430
    if(integer::condition("JNZ",flags)) goto L004ab430;
  }
  L004ab2dc: { // 0x4ab2dc: 8b5e0c MOV EBX,dword ptr [ESI + 0xc]
    s.bx = m.r32((s.si+0x0000000cu));
  }
  L004ab2df: { // 0x4ab2df: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004ab2e1: { // 0x4ab2e1: 7e1f JLE 0x004ab302
    if(integer::condition("JLE",flags)) goto L004ab302;
  }
  L004ab2e3: { // 0x4ab2e3: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ab2e5: { // 0x4ab2e5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004ab2e7: { // 0x4ab2e7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ab2e8: { // 0x4ab2e8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab2e9: { // 0x4ab2e9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab2eb: { // 0x4ab2eb: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L004ab2ee: { // 0x4ab2ee: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4895473u); flags=s.arithmetic_flags;
  }
  L004ab2f1: { // 0x4ab2f1: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L004ab2f4: { // 0x4ab2f4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab2f6: { // 0x4ab2f6: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ab2f7: { // 0x4ab2f7: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L004ab2fa: { // 0x4ab2fa: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ab2fc: { // 0x4ab2fc: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4895487u); flags=s.arithmetic_flags;
  }
  L004ab2ff: { // 0x4ab2ff: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  L004ab302: { // 0x4ab302: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ab304: { // 0x4ab304: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L004ab308: { // 0x4ab308: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab309: { // 0x4ab309: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab30b: { // 0x4ab30b: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),4895502u); flags=s.arithmetic_flags;
  }
  L004ab30e: { // 0x4ab30e: 8b9c24c4000000 MOV EBX,dword ptr [ESP + 0xc4]
    s.bx = m.r32((f.sp+0x000000c4u));
  }
  L004ab315: { // 0x4ab315: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab317: { // 0x4ab317: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab319: { // 0x4ab319: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab31a: { // 0x4ab31a: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L004ab31c: { // 0x4ab31c: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L004ab320: { // 0x4ab320: e8cb4af7ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4895525u); flags=s.arithmetic_flags;
  }
  L004ab325: { // 0x4ab325: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004ab327: { // 0x4ab327: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab329: { // 0x4ab329: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L004ab32d: { // 0x4ab32d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab32f: { // 0x4ab32f: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L004ab332: { // 0x4ab332: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L004ab336: { // 0x4ab336: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L004ab339: { // 0x4ab339: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L004ab33d: { // 0x4ab33d: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L004ab33f: { // 0x4ab33f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L004ab342: { // 0x4ab342: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L004ab344: { // 0x4ab344: 8b5b04 MOV EBX,dword ptr [EBX + 0x4]
    s.bx = m.r32((s.bx+0x00000004u));
  }
  L004ab347: { // 0x4ab347: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L004ab34b: { // 0x4ab34b: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L004ab34e: { // 0x4ab34e: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ab350: { // 0x4ab350: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004ab354: { // 0x4ab354: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L004ab358: { // 0x4ab358: 8d0c13 LEA ECX,[EBX + EDX*0x1]
    s.cx = (s.bx+(s.dx * 0x00000001u));
  }
  L004ab35b: { // 0x4ab35b: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L004ab35e: { // 0x4ab35e: 8b7f0c MOV EDI,dword ptr [EDI + 0xc]
    s.di = m.r32((s.di+0x0000000cu));
  }
  L004ab361: { // 0x4ab361: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L004ab365: { // 0x4ab365: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L004ab369: { // 0x4ab369: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab36a: { // 0x4ab36a: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L004ab36e: { // 0x4ab36e: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L004ab372: { // 0x4ab372: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L004ab376: { // 0x4ab376: e8754af7ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4895611u); flags=s.arithmetic_flags;
  }
  L004ab37b: { // 0x4ab37b: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L004ab37d: { // 0x4ab37d: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L004ab37f: { // 0x4ab37f: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L004ab383: { // 0x4ab383: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L004ab386: { // 0x4ab386: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L004ab38a: { // 0x4ab38a: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L004ab38d: { // 0x4ab38d: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004ab391: { // 0x4ab391: 8b7f0c MOV EDI,dword ptr [EDI + 0xc]
    s.di = m.r32((s.di+0x0000000cu));
  }
  L004ab394: { // 0x4ab394: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ab396: { // 0x4ab396: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L004ab39a: { // 0x4ab39a: 0f8e90000000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab3a0: { // 0x4ab3a0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004ab3a2: { // 0x4ab3a2: 0f8e88000000 JLE 0x004ab430
    if(integer::condition("JLE",flags)) goto L004ab430;
  }
  L004ab3a8: { // 0x4ab3a8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L004ab3aa: { // 0x4ab3aa: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L004ab3ac: { // 0x4ab3ac: 8b761c MOV ESI,dword ptr [ESI + 0x1c]
    s.si = m.r32((s.si+0x0000001cu));
  }
  L004ab3af: { // 0x4ab3af: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L004ab3b3: { // 0x4ab3b3: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L004ab3b7: { // 0x4ab3b7: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L004ab3bb: { // 0x4ab3bb: b919000000 MOV ECX,0x19
    s.cx = 0x00000019u;
  }
  L004ab3c0: { // 0x4ab3c0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004ab3c2: { // 0x4ab3c2: 8d7c245c LEA EDI,[ESP + 0x5c]
    s.di = (f.sp+0x0000005cu);
  }
  L004ab3c6: { // 0x4ab3c6: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L004ab3ca: { // 0x4ab3ca: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L004ab3cc: { // 0x4ab3cc: 8b8c24cc000000 MOV ECX,dword ptr [ESP + 0xcc]
    s.cx = m.r32((f.sp+0x000000ccu));
  }
  L004ab3d3: { // 0x4ab3d3: 8d44245c LEA EAX,[ESP + 0x5c]
    s.ax = (f.sp+0x0000005cu);
  }
  L004ab3d7: { // 0x4ab3d7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab3d8: { // 0x4ab3d8: 898c24b0000000 MOV dword ptr [ESP + 0xb0],ECX
    m.w32((f.sp+0x000000b0u), s.cx);
  }
  L004ab3df: { // 0x4ab3df: 6800040001 PUSH 0x1000400
    f.push(m,0x01000400u);
  }
  L004ab3e4: { // 0x4ab3e4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab3e6: { // 0x4ab3e6: 8d4c2428 LEA ECX,[ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L004ab3ea: { // 0x4ab3ea: c744246864000000 MOV dword ptr [ESP + 0x68],0x64
    m.w32((f.sp+0x00000068u), 0x00000064u);
  }
  L004ab3f2: { // 0x4ab3f2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ab3f4: { // 0x4ab3f4: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004ab3f6: { // 0x4ab3f6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ab3f7: { // 0x4ab3f7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ab3f8: { // 0x4ab3f8: ff5214 CALL dword ptr [EDX + 0x14]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000014u)),4895739u); flags=s.arithmetic_flags;
  }
  L004ab3fb: { // 0x4ab3fb: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L004ab3fd: { // 0x4ab3fd: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L004ab3ff: { // 0x4ab3ff: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ab400: { // 0x4ab400: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ab401: { // 0x4ab401: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004ab402: { // 0x4ab402: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ab403: { // 0x4ab403: 81c4b4000000 ADD ESP,0xb4
    f.sp = integer::add(f.sp,0x000000b4u,32,flags);
  }
  L004ab409: { // 0x4ab409: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004ab40c: { // 0x4ab40c: 8b9424cc000000 MOV EDX,dword ptr [ESP + 0xcc]
    s.dx = m.r32((f.sp+0x000000ccu));
  }
  L004ab413: { // 0x4ab413: 8b8424c4000000 MOV EAX,dword ptr [ESP + 0xc4]
    s.ax = m.r32((f.sp+0x000000c4u));
  }
  L004ab41a: { // 0x4ab41a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004ab41b: { // 0x4ab41b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ab41c: { // 0x4ab41c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ab41d: { // 0x4ab41d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004ab41f: { // 0x4ab41f: e8dc482b00 CALL 0x0075fd00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0075fd00u,4895780u); flags=s.arithmetic_flags;
  }
  L004ab424: { // 0x4ab424: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ab425: { // 0x4ab425: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ab426: { // 0x4ab426: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ab427: { // 0x4ab427: 81c4b4000000 ADD ESP,0xb4
    f.sp = integer::add(f.sp,0x000000b4u,32,flags);
  }
  L004ab42d: { // 0x4ab42d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004ab430: { // 0x4ab430: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004ab431: { // 0x4ab431: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ab432: { // 0x4ab432: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004ab434: { // 0x4ab434: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004ab435: { // 0x4ab435: 81c4b4000000 ADD ESP,0xb4
    f.sp = integer::add(f.sp,0x000000b4u,32,flags);
  }
  L004ab43b: { // 0x4ab43b: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00609cd0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00609cd0: { // 0x609cd0: 83ec44 SUB ESP,0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L00609cd3: { // 0x609cd3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00609cd4: { // 0x609cd4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00609cd5: { // 0x609cd5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00609cd6: { // 0x609cd6: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00609cd8: { // 0x609cd8: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00609cdc: { // 0x609cdc: e82fd30d00 CALL 0x006e7010
    s.arithmetic_flags=flags; invoke(m,s,f,0x006e7010u,6331617u); flags=s.arithmetic_flags;
  }
  L00609ce1: { // 0x609ce1: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00609ce3: { // 0x609ce3: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00609ce7: { // 0x609ce7: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00609cea: { // 0x609cea: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L00609cee: { // 0x609cee: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00609cf1: { // 0x609cf1: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L00609cf5: { // 0x609cf5: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00609cf8: { // 0x609cf8: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00609cfb: { // 0x609cfb: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00609cff: { // 0x609cff: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00609d01: { // 0x609d01: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00609d04: { // 0x609d04: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00609d08: { // 0x609d08: e853e8ffff CALL 0x00608560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608560u,6331661u); flags=s.arithmetic_flags;
  }
  L00609d0d: { // 0x609d0d: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00609d0f: { // 0x609d0f: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00609d13: { // 0x609d13: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00609d16: { // 0x609d16: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00609d1a: { // 0x609d1a: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00609d1e: { // 0x609d1e: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00609d21: { // 0x609d21: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00609d25: { // 0x609d25: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00609d29: { // 0x609d29: e852e6ffff CALL 0x00608380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608380u,6331694u); flags=s.arithmetic_flags;
  }
  L00609d2e: { // 0x609d2e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00609d30: { // 0x609d30: ba08000000 MOV EDX,0x8
    s.dx = 0x00000008u;
  }
  L00609d35: { // 0x609d35: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00609d37: { // 0x609d37: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00609d39: { // 0x609d39: 83e804 SUB EAX,0x4
    s.ax = integer::sub(s.ax,0x00000004u,32,flags);
  }
  L00609d3c: { // 0x609d3c: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00609d3f: { // 0x609d3f: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00609d43: { // 0x609d43: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00609d47: { // 0x609d47: 83e904 SUB ECX,0x4
    s.cx = integer::sub(s.cx,0x00000004u,32,flags);
  }
  L00609d4a: { // 0x609d4a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00609d4b: { // 0x609d4b: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L00609d4f: { // 0x609d4f: 8b0da41c8200 MOV ECX,dword ptr [0x00821ca4]
    s.cx = m.r32((0x00821ca4u));
  }
  L00609d55: { // 0x609d55: 8d442434 LEA EAX,[ESP + 0x34]
    s.ax = (f.sp+0x00000034u);
  }
  L00609d59: { // 0x609d59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00609d5a: { // 0x609d5a: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00609d5e: { // 0x609d5e: 89742444 MOV dword ptr [ESP + 0x44],ESI
    m.w32((f.sp+0x00000044u), s.si);
  }
  L00609d62: { // 0x609d62: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00609d64: { // 0x609d64: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00609d68: { // 0x609d68: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00609d69: { // 0x609d69: ff5254 CALL dword ptr [EDX + 0x54]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000054u)),6331756u); flags=s.arithmetic_flags;
  }
  L00609d6c: { // 0x609d6c: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00609d70: { // 0x609d70: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00609d74: { // 0x609d74: 8d1408 LEA EDX,[EAX + ECX*0x1]
    s.dx = (s.ax+(s.cx * 0x00000001u));
  }
  L00609d77: { // 0x609d77: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00609d7b: { // 0x609d7b: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00609d7d: { // 0x609d7d: 7d7d JGE 0x00609dfc
    if(integer::condition("JGE",flags)) goto L00609dfc;
  }
  L00609d7f: { // 0x609d7f: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00609d83: { // 0x609d83: 8b74243c MOV ESI,dword ptr [ESP + 0x3c]
    s.si = m.r32((f.sp+0x0000003cu));
  }
  L00609d87: { // 0x609d87: 8d1c32 LEA EBX,[EDX + ESI*0x1]
    s.bx = (s.dx+(s.si * 0x00000001u));
  }
  L00609d8a: { // 0x609d8a: 8b742444 MOV ESI,dword ptr [ESP + 0x44]
    s.si = m.r32((f.sp+0x00000044u));
  }
  L00609d8e: { // 0x609d8e: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00609d90: { // 0x609d90: 7d6a JGE 0x00609dfc
    if(integer::condition("JGE",flags)) goto L00609dfc;
  }
  L00609d92: { // 0x609d92: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L00609d96: { // 0x609d96: 03d9 ADD EBX,ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  L00609d98: { // 0x609d98: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00609d9a: { // 0x609d9a: 7e60 JLE 0x00609dfc
    if(integer::condition("JLE",flags)) goto L00609dfc;
  }
  L00609d9c: { // 0x609d9c: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L00609da0: { // 0x609da0: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00609da2: { // 0x609da2: 3bf2 CMP ESI,EDX
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00609da4: { // 0x609da4: 7e56 JLE 0x00609dfc
    if(integer::condition("JLE",flags)) goto L00609dfc;
  }
  L00609da6: { // 0x609da6: a138e2a500 MOV EAX,[0x00a5e238]
    s.ax = m.r32((0x00a5e238u));
  }
  L00609dab: { // 0x609dab: 8b0d40e2a500 MOV ECX,dword ptr [0x00a5e240]
    s.cx = m.r32((0x00a5e240u));
  }
  L00609db1: { // 0x609db1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00609db3: { // 0x609db3: 7c2f JL 0x00609de4
    if(integer::condition("JL",flags)) goto L00609de4;
  }
  L00609db5: { // 0x609db5: 8a0d3de2a500 MOV CL,byte ptr [0x00a5e23d]
    s.cx = with_al(s.cx, m.r8((0x00a5e23du)));
  }
  L00609dbb: { // 0x609dbb: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00609dbd: { // 0x609dbd: 7504 JNZ 0x00609dc3
    if(integer::condition("JNZ",flags)) goto L00609dc3;
  }
  L00609dbf: { // 0x609dbf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00609dc1: { // 0x609dc1: 7539 JNZ 0x00609dfc
    if(integer::condition("JNZ",flags)) goto L00609dfc;
  }
  L00609dc3: { // 0x609dc3: 8b0d44e2a500 MOV ECX,dword ptr [0x00a5e244]
    s.cx = m.r32((0x00a5e244u));
  }
  L00609dc9: { // 0x609dc9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00609dcb: { // 0x609dcb: 7e2f JLE 0x00609dfc
    if(integer::condition("JLE",flags)) goto L00609dfc;
  }
  L00609dcd: { // 0x609dcd: 8b1530e2a500 MOV EDX,dword ptr [0x00a5e230]
    s.dx = m.r32((0x00a5e230u));
  }
  L00609dd3: { // 0x609dd3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00609dd5: { // 0x609dd5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00609dd7: { // 0x609dd7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00609dd8: { // 0x609dd8: b930e2a500 MOV ECX,0xa5e230
    s.cx = 0x00a5e230u;
  }
  L00609ddd: { // 0x609ddd: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6331872u); flags=s.arithmetic_flags;
  }
  L00609de0: { // 0x609de0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00609de2: { // 0x609de2: 7418 JZ 0x00609dfc
    if(integer::condition("JZ",flags)) goto L00609dfc;
  }
  L00609de4: { // 0x609de4: 8b0d40e2a500 MOV ECX,dword ptr [0x00a5e240]
    s.cx = m.r32((0x00a5e240u));
  }
  L00609dea: { // 0x609dea: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00609dec: { // 0x609dec: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00609ded: { // 0x609ded: 890d40e2a500 MOV dword ptr [0x00a5e240],ECX
    m.w32((0x00a5e240u), s.cx);
  }
  L00609df3: { // 0x609df3: 8b0d34e2a500 MOV ECX,dword ptr [0x00a5e234]
    s.cx = m.r32((0x00a5e234u));
  }
  L00609df9: { // 0x609df9: 893c81 MOV dword ptr [ECX + EAX*0x4],EDI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.di);
  }
  L00609dfc: { // 0x609dfc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00609dfd: { // 0x609dfd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00609dfe: { // 0x609dfe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00609dff: { // 0x609dff: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L00609e02: { // 0x609e02: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
