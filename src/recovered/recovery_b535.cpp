#include "recovered/recovery_b535_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b535 {
namespace {
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_00011230(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_00011230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411230: { // 0x411230: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00411234: { // 0x411234: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411235: { // 0x411235: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00411237: { // 0x411237: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411238: { // 0x411238: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00411239: { // 0x411239: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041123d: { // 0x41123d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00411240: { // 0x411240: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00411241: { // 0x411241: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00411243: { // 0x411243: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000005cu)),4264518u); flags=s.arithmetic_flags;
  }
  L00411246: { // 0x411246: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00411249: { // 0x411249: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0041124b: { // 0x41124b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0041124d: { // 0x41124d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4264528u); flags=s.arithmetic_flags;
  }
  L00411250: { // 0x411250: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00411253: { // 0x411253: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00411256: { // 0x411256: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00411258: { // 0x411258: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041125a: { // 0x41125a: 7203 JC 0x0041125f
    if(integer::condition("JC",flags)) goto L0041125f;
  }
  L0041125c: { // 0x41125c: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L0041125f: { // 0x41125f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00411260: { // 0x411260: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00411261: { // 0x411261: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4324848u:f_0001fdf0(m,s,child,{});break;
case 4264496u:f_00011230(m,s,child,{});break;
case 4264816u:f_00011370(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
default:throw std::domain_error("recovery535 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0041f1c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041f1c0: { // 0x41f1c0: 81ecb8000000 SUB ESP,0xb8
    f.sp = integer::sub(f.sp,0x000000b8u,32,flags);
  }
  L0041f1c6: { // 0x41f1c6: a1a0498200 MOV EAX,[0x008249a0]
    s.ax = m.r32((0x008249a0u));
  }
  L0041f1cb: { // 0x41f1cb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041f1cc: { // 0x41f1cc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041f1cd: { // 0x41f1cd: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0041f1cf: { // 0x41f1cf: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0041f1d1: { // 0x41f1d1: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0041f1d5: { // 0x41f1d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041f1d7: { // 0x41f1d7: 897c2454 MOV dword ptr [ESP + 0x54],EDI
    m.w32((f.sp+0x00000054u), s.di);
  }
  L0041f1db: { // 0x41f1db: 896c2428 MOV dword ptr [ESP + 0x28],EBP
    m.w32((f.sp+0x00000028u), s.bp);
  }
  L0041f1df: { // 0x41f1df: 0f8eea030000 JLE 0x0041f5cf
    if(integer::condition("JLE",flags)) goto L0041f5cf;
  }
  L0041f1e5: { // 0x41f1e5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041f1e6: { // 0x41f1e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041f1e7: { // 0x41f1e7: eb04 JMP 0x0041f1ed
    goto L0041f1ed;
  }
  L0041f1e9: { // 0x41f1e9: 8b7c245c MOV EDI,dword ptr [ESP + 0x5c]
    s.di = m.r32((f.sp+0x0000005cu));
  }
  L0041f1ed: { // 0x41f1ed: a194498200 MOV EAX,[0x00824994]
    s.ax = m.r32((0x00824994u));
  }
  L0041f1f2: { // 0x41f1f2: 8b0ca8 MOV ECX,dword ptr [EAX + EBP*0x4]
    s.cx = m.r32((s.ax+(s.bp * 0x00000004u)));
  }
  L0041f1f5: { // 0x41f1f5: 8a513c MOV DL,byte ptr [ECX + 0x3c]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000003cu)));
  }
  L0041f1f8: { // 0x41f1f8: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0041f1fa: { // 0x41f1fa: 0f85bb030000 JNZ 0x0041f5bb
    if(integer::condition("JNZ",flags)) goto L0041f5bb;
  }
  L0041f200: { // 0x41f200: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0041f202: { // 0x41f202: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041f204: { // 0x41f204: 83c228 ADD EDX,0x28
    s.dx = integer::add(s.dx,0x00000028u,32,flags);
  }
  L0041f207: { // 0x41f207: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041f209: { // 0x41f209: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0041f20b: { // 0x41f20b: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0041f20f: { // 0x41f20f: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0041f212: { // 0x41f212: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0041f216: { // 0x41f216: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0041f219: { // 0x41f219: 89742448 MOV dword ptr [ESP + 0x48],ESI
    m.w32((f.sp+0x00000048u), s.si);
  }
  L0041f21d: { // 0x41f21d: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L0041f220: { // 0x41f220: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L0041f224: { // 0x41f224: 8b15ac1c8200 MOV EDX,dword ptr [0x00821cac]
    s.dx = m.r32((0x00821cacu));
  }
  L0041f22a: { // 0x41f22a: 8bb2b0000000 MOV ESI,dword ptr [EDX + 0xb0]
    s.si = m.r32((s.dx+0x000000b0u));
  }
  L0041f230: { // 0x41f230: 8b92b4000000 MOV EDX,dword ptr [EDX + 0xb4]
    s.dx = m.r32((s.dx+0x000000b4u));
  }
  L0041f236: { // 0x41f236: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0041f238: { // 0x41f238: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L0041f23e: { // 0x41f23e: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0041f240: { // 0x41f240: 8b3574198200 MOV ESI,dword ptr [0x00821974]
    s.si = m.r32((0x00821974u));
  }
  L0041f246: { // 0x41f246: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041f248: { // 0x41f248: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041f24a: { // 0x41f24a: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0041f24e: { // 0x41f24e: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L0041f252: { // 0x41f252: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0041f256: { // 0x41f256: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041f257: { // 0x41f257: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0041f25b: { // 0x41f25b: 8d8c24b4000000 LEA ECX,[ESP + 0xb4]
    s.cx = (f.sp+0x000000b4u);
  }
  L0041f262: { // 0x41f262: e8890b0000 CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4321895u); flags=s.arithmetic_flags;
  }
  L0041f267: { // 0x41f267: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0041f269: { // 0x41f269: 898c2480000000 MOV dword ptr [ESP + 0x80],ECX
    m.w32((f.sp+0x00000080u), s.cx);
  }
  L0041f270: { // 0x41f270: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041f272: { // 0x41f272: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0041f275: { // 0x41f275: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041f277: { // 0x41f277: 8994248c000000 MOV dword ptr [ESP + 0x8c],EDX
    m.w32((f.sp+0x0000008cu), s.dx);
  }
  L0041f27e: { // 0x41f27e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0041f281: { // 0x41f281: 898c2490000000 MOV dword ptr [ESP + 0x90],ECX
    m.w32((f.sp+0x00000090u), s.cx);
  }
  L0041f288: { // 0x41f288: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0041f28b: { // 0x41f28b: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0041f28e: { // 0x41f28e: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0041f290: { // 0x41f290: 89942494000000 MOV dword ptr [ESP + 0x94],EDX
    m.w32((f.sp+0x00000094u), s.dx);
  }
  L0041f297: { // 0x41f297: 8d542468 LEA EDX,[ESP + 0x68]
    s.dx = (f.sp+0x00000068u);
  }
  L0041f29b: { // 0x41f29b: 894c246c MOV dword ptr [ESP + 0x6c],ECX
    m.w32((f.sp+0x0000006cu), s.cx);
  }
  L0041f29f: { // 0x41f29f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0041f2a0: { // 0x41f2a0: 8d94248c000000 LEA EDX,[ESP + 0x8c]
    s.dx = (f.sp+0x0000008cu);
  }
  L0041f2a7: { // 0x41f2a7: 8d8c24c4000000 LEA ECX,[ESP + 0xc4]
    s.cx = (f.sp+0x000000c4u);
  }
  L0041f2ae: { // 0x41f2ae: 8944246c MOV dword ptr [ESP + 0x6c],EAX
    m.w32((f.sp+0x0000006cu), s.ax);
  }
  L0041f2b2: { // 0x41f2b2: c74424743c000000 MOV dword ptr [ESP + 0x74],0x3c
    m.w32((f.sp+0x00000074u), 0x0000003cu);
  }
  L0041f2ba: { // 0x41f2ba: c74424781e000000 MOV dword ptr [ESP + 0x78],0x1e
    m.w32((f.sp+0x00000078u), 0x0000001eu);
  }
  L0041f2c2: { // 0x41f2c2: e8290b0000 CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4321991u); flags=s.arithmetic_flags;
  }
  L0041f2c7: { // 0x41f2c7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0041f2c9: { // 0x41f2c9: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L0041f2cb: { // 0x41f2cb: 8b5904 MOV EBX,dword ptr [ECX + 0x4]
    s.bx = m.r32((s.cx+0x00000004u));
  }
  L0041f2ce: { // 0x41f2ce: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0041f2d1: { // 0x41f2d1: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041f2d3: { // 0x41f2d3: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L0041f2d6: { // 0x41f2d6: 89442478 MOV dword ptr [ESP + 0x78],EAX
    m.w32((f.sp+0x00000078u), s.ax);
  }
  L0041f2da: { // 0x41f2da: 894c247c MOV dword ptr [ESP + 0x7c],ECX
    m.w32((f.sp+0x0000007cu), s.cx);
  }
  L0041f2de: { // 0x41f2de: 0f8ed7020000 JLE 0x0041f5bb
    if(integer::condition("JLE",flags)) goto L0041f5bb;
  }
  L0041f2e4: { // 0x41f2e4: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0041f2e6: { // 0x41f2e6: 0f8ecf020000 JLE 0x0041f5bb
    if(integer::condition("JLE",flags)) goto L0041f5bb;
  }
  L0041f2ec: { // 0x41f2ec: 8b742460 MOV ESI,dword ptr [ESP + 0x60]
    s.si = m.r32((f.sp+0x00000060u));
  }
  L0041f2f0: { // 0x41f2f0: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0041f2f4: { // 0x41f2f4: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0041f2f6: { // 0x41f2f6: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L0041f2fa: { // 0x41f2fa: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0041f2fc: { // 0x41f2fc: 89542454 MOV dword ptr [ESP + 0x54],EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L0041f300: { // 0x41f300: 89842490000000 MOV dword ptr [ESP + 0x90],EAX
    m.w32((f.sp+0x00000090u), s.ax);
  }
  L0041f307: { // 0x41f307: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0041f309: { // 0x41f309: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0041f30b: { // 0x41f30b: 8b0d94498200 MOV ECX,dword ptr [0x00824994]
    s.cx = m.r32((0x00824994u));
  }
  L0041f311: { // 0x41f311: 8b14a9 MOV EDX,dword ptr [ECX + EBP*0x4]
    s.dx = m.r32((s.cx+(s.bp * 0x00000004u)));
  }
  L0041f314: { // 0x41f314: 8b4a38 MOV ECX,dword ptr [EDX + 0x38]
    s.cx = m.r32((s.dx+0x00000038u));
  }
  L0041f317: { // 0x41f317: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L0041f31b: { // 0x41f31b: 0fbf5106 MOVSX EDX,word ptr [ECX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0041f31f: { // 0x41f31f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041f321: { // 0x41f321: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0041f325: { // 0x41f325: 7618 JBE 0x0041f33f
    if(integer::condition("JBE",flags)) goto L0041f33f;
  }
  L0041f327: { // 0x41f327: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L0041f32a: { // 0x41f32a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0041f32c: { // 0x41f32c: 7411 JZ 0x0041f33f
    if(integer::condition("JZ",flags)) goto L0041f33f;
  }
  L0041f32e: { // 0x41f32e: 0fbf11 MOVSX EDX,word ptr [ECX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx)),16));
  }
  L0041f331: { // 0x41f331: 0fbf6902 MOVSX EBP,word ptr [ECX + 0x2]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000002u)),16));
  }
  L0041f335: { // 0x41f335: 0fbf7104 MOVSX ESI,word ptr [ECX + 0x4]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000004u)),16));
  }
  L0041f339: { // 0x41f339: 0fbf4906 MOVSX ECX,word ptr [ECX + 0x6]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0041f33d: { // 0x41f33d: eb18 JMP 0x0041f357
    goto L0041f357;
  }
  L0041f33f: { // 0x41f33f: 8b1548498200 MOV EDX,dword ptr [0x00824948]
    s.dx = m.r32((0x00824948u));
  }
  L0041f345: { // 0x41f345: 8b2d4c498200 MOV EBP,dword ptr [0x0082494c]
    s.bp = m.r32((0x0082494cu));
  }
  L0041f34b: { // 0x41f34b: 8b3550498200 MOV ESI,dword ptr [0x00824950]
    s.si = m.r32((0x00824950u));
  }
  L0041f351: { // 0x41f351: 8b0d54498200 MOV ECX,dword ptr [0x00824954]
    s.cx = m.r32((0x00824954u));
  }
  L0041f357: { // 0x41f357: 898c24a4000000 MOV dword ptr [ESP + 0xa4],ECX
    m.w32((f.sp+0x000000a4u), s.cx);
  }
  L0041f35e: { // 0x41f35e: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L0041f362: { // 0x41f362: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0041f364: { // 0x41f364: 895c2420 MOV dword ptr [ESP + 0x20],EBX
    m.w32((f.sp+0x00000020u), s.bx);
  }
  L0041f368: { // 0x41f368: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041f36a: { // 0x41f36a: 7f04 JG 0x0041f370
    if(integer::condition("JG",flags)) goto L0041f370;
  }
  L0041f36c: { // 0x41f36c: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0041f370: { // 0x41f370: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041f374: { // 0x41f374: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  L0041f376: { // 0x41f376: 2b4c2454 SUB ECX,dword ptr [ESP + 0x54]
    s.cx = integer::sub(s.cx,m.r32((f.sp+0x00000054u)),32,flags);
  }
  L0041f37a: { // 0x41f37a: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0041f37e: { // 0x41f37e: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0041f385: { // 0x41f385: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0041f387: { // 0x41f387: 8b6c2454 MOV EBP,dword ptr [ESP + 0x54]
    s.bp = m.r32((f.sp+0x00000054u));
  }
  L0041f38b: { // 0x41f38b: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0041f38d: { // 0x41f38d: 8b6c247c MOV EBP,dword ptr [ESP + 0x7c]
    s.bp = m.r32((f.sp+0x0000007cu));
  }
  L0041f391: { // 0x41f391: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0041f393: { // 0x41f393: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041f395: { // 0x41f395: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0041f399: { // 0x41f399: 7c04 JL 0x0041f39f
    if(integer::condition("JL",flags)) goto L0041f39f;
  }
  L0041f39b: { // 0x41f39b: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0041f39f: { // 0x41f39f: 8b6c2438 MOV EBP,dword ptr [ESP + 0x38]
    s.bp = m.r32((f.sp+0x00000038u));
  }
  L0041f3a3: { // 0x41f3a3: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0041f3a7: { // 0x41f3a7: 8d0c2a LEA ECX,[EDX + EBP*0x1]
    s.cx = (s.dx+(s.bp * 0x00000001u));
  }
  L0041f3aa: { // 0x41f3aa: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0041f3ac: { // 0x41f3ac: 7f04 JG 0x0041f3b2
    if(integer::condition("JG",flags)) goto L0041f3b2;
  }
  L0041f3ae: { // 0x41f3ae: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0041f3b2: { // 0x41f3b2: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L0041f3b6: { // 0x41f3b6: 8d0c16 LEA ECX,[ESI + EDX*0x1]
    s.cx = (s.si+(s.dx * 0x00000001u));
  }
  L0041f3b9: { // 0x41f3b9: 03cd ADD ECX,EBP
    s.cx = integer::add(s.cx,s.bp,32,flags);
  }
  L0041f3bb: { // 0x41f3bb: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0041f3bd: { // 0x41f3bd: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L0041f3c1: { // 0x41f3c1: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0041f3c5: { // 0x41f3c5: 03cf ADD ECX,EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L0041f3c7: { // 0x41f3c7: 8b7c2428 MOV EDI,dword ptr [ESP + 0x28]
    s.di = m.r32((f.sp+0x00000028u));
  }
  L0041f3cb: { // 0x41f3cb: 2bdd SUB EBX,EBP
    s.bx = integer::sub(s.bx,s.bp,32,flags);
  }
  L0041f3cd: { // 0x41f3cd: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0041f3cf: { // 0x41f3cf: 7d06 JGE 0x0041f3d7
    if(integer::condition("JGE",flags)) goto L0041f3d7;
  }
  L0041f3d1: { // 0x41f3d1: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0041f3d5: { // 0x41f3d5: eb06 JMP 0x0041f3dd
    goto L0041f3dd;
  }
  L0041f3d7: { // 0x41f3d7: 897c2418 MOV dword ptr [ESP + 0x18],EDI
    m.w32((f.sp+0x00000018u), s.di);
  }
  L0041f3db: { // 0x41f3db: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0041f3dd: { // 0x41f3dd: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  L0041f3df: { // 0x41f3df: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0041f3e2: { // 0x41f3e2: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L0041f3e4: { // 0x41f3e4: 03fa ADD EDI,EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L0041f3e6: { // 0x41f3e6: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L0041f3ec: { // 0x41f3ec: 03fb ADD EDI,EBX
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L0041f3ee: { // 0x41f3ee: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0041f3f1: { // 0x41f3f1: 8b5228 MOV EDX,dword ptr [EDX + 0x28]
    s.dx = m.r32((s.dx+0x00000028u));
  }
  L0041f3f4: { // 0x41f3f4: 03fd ADD EDI,EBP
    s.di = integer::add(s.di,s.bp,32,flags);
  }
  L0041f3f6: { // 0x41f3f6: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0041f3fa: { // 0x41f3fa: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L0041f3fc: { // 0x41f3fc: 8b4c2478 MOV ECX,dword ptr [ESP + 0x78]
    s.cx = m.r32((f.sp+0x00000078u));
  }
  L0041f400: { // 0x41f400: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L0041f402: { // 0x41f402: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0041f406: { // 0x41f406: ba3c000000 MOV EDX,0x3c
    s.dx = 0x0000003cu;
  }
  L0041f40b: { // 0x41f40b: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L0041f40d: { // 0x41f40d: 8b8c2490000000 MOV ECX,dword ptr [ESP + 0x90]
    s.cx = m.r32((f.sp+0x00000090u));
  }
  L0041f414: { // 0x41f414: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0041f418: { // 0x41f418: 8d948150687800 LEA EDX,[ECX + EAX*0x4 + 0x786850]
    s.dx = (s.cx+(s.ax * 0x00000004u)+0x00786850u);
  }
  L0041f41f: { // 0x41f41f: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0041f423: { // 0x41f423: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041f425: { // 0x41f425: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0041f429: { // 0x41f429: 7616 JBE 0x0041f441
    if(integer::condition("JBE",flags)) goto L0041f441;
  }
  L0041f42b: { // 0x41f42b: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  L0041f42f: { // 0x41f42f: 8d4108 LEA EAX,[ECX + 0x8]
    s.ax = (s.cx+0x00000008u);
  }
  L0041f432: { // 0x41f432: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041f434: { // 0x41f434: 740b JZ 0x0041f441
    if(integer::condition("JZ",flags)) goto L0041f441;
  }
  L0041f436: { // 0x41f436: 8b6814 MOV EBP,dword ptr [EAX + 0x14]
    s.bp = m.r32((s.ax+0x00000014u));
  }
  L0041f439: { // 0x41f439: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041f43b: { // 0x41f43b: 7404 JZ 0x0041f441
    if(integer::condition("JZ",flags)) goto L0041f441;
  }
  L0041f43d: { // 0x41f43d: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  L0041f43f: { // 0x41f43f: eb02 JMP 0x0041f443
    goto L0041f443;
  }
  L0041f441: { // 0x41f441: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0041f443: { // 0x41f443: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0041f447: { // 0x41f447: 8b0d74198200 MOV ECX,dword ptr [0x00821974]
    s.cx = m.r32((0x00821974u));
  }
  L0041f44d: { // 0x41f44d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0041f44f: { // 0x41f44f: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L0041f455: { // 0x41f455: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041f456: { // 0x41f456: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0041f45a: { // 0x41f45a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0041f45b: { // 0x41f45b: e8d01dffff CALL 0x00411230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4322400u); flags=s.arithmetic_flags;
  }
  L0041f460: { // 0x41f460: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L0041f466: { // 0x41f466: 0faf74244c IMUL ESI,dword ptr [ESP + 0x4c]
    s.si = integer::imul(s.si,m.r32((f.sp+0x0000004cu)),32,flags);
  }
  L0041f46b: { // 0x41f46b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0041f46f: { // 0x41f46f: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L0041f471: { // 0x41f471: 8b5c2420 MOV EBX,dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L0041f475: { // 0x41f475: 03ee ADD EBP,ESI
    s.bp = integer::add(s.bp,s.si,32,flags);
  }
  L0041f477: { // 0x41f477: 8b7128 MOV ESI,dword ptr [ECX + 0x28]
    s.si = m.r32((s.cx+0x00000028u));
  }
  L0041f47a: { // 0x41f47a: 2bd3 SUB EDX,EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L0041f47c: { // 0x41f47c: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0041f480: { // 0x41f480: 0faff2 IMUL ESI,EDX
    s.si = integer::imul(s.si,s.dx,32,flags);
  }
  L0041f483: { // 0x41f483: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041f487: { // 0x41f487: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  L0041f489: { // 0x41f489: f7db NEG EBX
    s.bx = integer::sub(0u,s.bx,32,flags);
  }
  L0041f48b: { // 0x41f48b: c1e31f SHL EBX,0x1f
    s.bx = integer::shift(s.bx,0x0000001fu,32,flags,integer::Shift::left);
  }
  L0041f48e: { // 0x41f48e: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L0041f490: { // 0x41f490: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0041f494: { // 0x41f494: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041f496: { // 0x41f496: 8b711c MOV ESI,dword ptr [ECX + 0x1c]
    s.si = m.r32((s.cx+0x0000001cu));
  }
  L0041f499: { // 0x41f499: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L0041f49b: { // 0x41f49b: 8d545804 LEA EDX,[EAX + EBX*0x2 + 0x4]
    s.dx = (s.ax+(s.bx * 0x00000002u)+0x00000004u);
  }
  L0041f49f: { // 0x41f49f: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0041f4a1: { // 0x41f4a1: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0041f4a5: { // 0x41f4a5: 0f829c000000 JC 0x0041f547
    if(integer::condition("JC",flags)) goto L0041f547;
  }
  L0041f4ab: { // 0x41f4ab: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  L0041f4af: { // 0x41f4af: 0f8d02010000 JGE 0x0041f5b7
    if(integer::condition("JGE",flags)) goto L0041f5b7;
  }
  L0041f4b5: { // 0x41f4b5: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0041f4b9: { // 0x41f4b9: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0041f4bd: { // 0x41f4bd: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0041f4c1: { // 0x41f4c1: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041f4c5: { // 0x41f4c5: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L0041f4c7: { // 0x41f4c7: 7d56 JGE 0x0041f51f
    if(integer::condition("JGE",flags)) goto L0041f51f;
  }
  L0041f4c9: { // 0x41f4c9: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0041f4cb: { // 0x41f4cb: 8a5500 MOV DL,byte ptr [EBP]
    s.dx = with_al(s.dx, m.r8((s.bp)));
  }
  L0041f4ce: { // 0x41f4ce: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0041f4cf: { // 0x41f4cf: 8854242c MOV byte ptr [ESP + 0x2c],DL
    m.w8((f.sp+0x0000002cu), (s.dx & 0xffu));
  }
  L0041f4d3: { // 0x41f4d3: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0041f4d7: { // 0x41f4d7: 8a1a MOV BL,byte ptr [EDX]
    s.bx = with_al(s.bx, m.r8((s.dx)));
  }
  L0041f4d9: { // 0x41f4d9: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0041f4da: { // 0x41f4da: 80fb20 CMP BL,0x20
    (void)integer::sub((s.bx & 0xffu),0x00000020u,8,flags);
  }
  L0041f4dd: { // 0x41f4dd: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0041f4e1: { // 0x41f4e1: 7424 JZ 0x0041f507
    if(integer::condition("JZ",flags)) goto L0041f507;
  }
  L0041f4e3: { // 0x41f4e3: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L0041f4e7: { // 0x41f4e7: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L0041f4ed: { // 0x41f4ed: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0041f4f0: { // 0x41f4f0: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0041f4f2: { // 0x41f4f2: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  L0041f4f5: { // 0x41f4f5: 660fb68c11b8498200 MOVZX CX,byte ptr [ECX + EDX*0x1 + 0x8249b8]
    s.cx = with_ax(s.cx, (m.r8((s.cx+(s.dx * 0x00000001u)+0x008249b8u))&integer::mask(8)));
  }
  L0041f4fe: { // 0x41f4fe: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L0041f501: { // 0x41f501: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L0041f507: { // 0x41f507: 8b511c MOV EDX,dword ptr [ECX + 0x1c]
    s.dx = m.r32((s.cx+0x0000001cu));
  }
  L0041f50a: { // 0x41f50a: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L0041f50d: { // 0x41f50d: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0041f50f: { // 0x41f50f: 7203 JC 0x0041f514
    if(integer::condition("JC",flags)) goto L0041f514;
  }
  L0041f511: { // 0x41f511: 2b4120 SUB EAX,dword ptr [ECX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L0041f514: { // 0x41f514: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0041f515: { // 0x41f515: 75b4 JNZ 0x0041f4cb
    if(integer::condition("JNZ",flags)) goto L0041f4cb;
  }
  L0041f517: { // 0x41f517: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0041f51b: { // 0x41f51b: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041f51f: { // 0x41f51f: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L0041f523: { // 0x41f523: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041f525: { // 0x41f525: 015c2414 ADD dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), integer::add(m.r32((f.sp+0x00000014u)),s.bx,32,flags));
  }
  L0041f529: { // 0x41f529: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L0041f52d: { // 0x41f52d: 8d0458 LEA EAX,[EAX + EBX*0x2]
    s.ax = (s.ax+(s.bx * 0x00000002u));
  }
  L0041f530: { // 0x41f530: 8b591c MOV EBX,dword ptr [ECX + 0x1c]
    s.bx = m.r32((s.cx+0x0000001cu));
  }
  L0041f533: { // 0x41f533: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0041f535: { // 0x41f535: 7203 JC 0x0041f53a
    if(integer::condition("JC",flags)) goto L0041f53a;
  }
  L0041f537: { // 0x41f537: 2b4120 SUB EAX,dword ptr [ECX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L0041f53a: { // 0x41f53a: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L0041f53e: { // 0x41f53e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L0041f53f: { // 0x41f53f: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L0041f543: { // 0x41f543: 7580 JNZ 0x0041f4c5
    if(integer::condition("JNZ",flags)) goto L0041f4c5;
  }
  L0041f545: { // 0x41f545: eb70 JMP 0x0041f5b7
    goto L0041f5b7;
  }
  L0041f547: { // 0x41f547: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  L0041f54b: { // 0x41f54b: 7d6a JGE 0x0041f5b7
    if(integer::condition("JGE",flags)) goto L0041f5b7;
  }
  L0041f54d: { // 0x41f54d: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041f551: { // 0x41f551: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0041f555: { // 0x41f555: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041f559: { // 0x41f559: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L0041f55b: { // 0x41f55b: 7d46 JGE 0x0041f5a3
    if(integer::condition("JGE",flags)) goto L0041f5a3;
  }
  L0041f55d: { // 0x41f55d: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0041f55f: { // 0x41f55f: 8a5500 MOV DL,byte ptr [EBP]
    s.dx = with_al(s.dx, m.r8((s.bp)));
  }
  L0041f562: { // 0x41f562: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0041f563: { // 0x41f563: 8854242c MOV byte ptr [ESP + 0x2c],DL
    m.w8((f.sp+0x0000002cu), (s.dx & 0xffu));
  }
  L0041f567: { // 0x41f567: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0041f56b: { // 0x41f56b: 8a1a MOV BL,byte ptr [EDX]
    s.bx = with_al(s.bx, m.r8((s.dx)));
  }
  L0041f56d: { // 0x41f56d: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0041f56e: { // 0x41f56e: 80fb20 CMP BL,0x20
    (void)integer::sub((s.bx & 0xffu),0x00000020u,8,flags);
  }
  L0041f571: { // 0x41f571: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0041f575: { // 0x41f575: 741e JZ 0x0041f595
    if(integer::condition("JZ",flags)) goto L0041f595;
  }
  L0041f577: { // 0x41f577: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L0041f57b: { // 0x41f57b: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041f581: { // 0x41f581: c1e208 SHL EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0041f584: { // 0x41f584: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0041f586: { // 0x41f586: 668b18 MOV BX,word ptr [EAX]
    s.bx = with_ax(s.bx, m.r16((s.ax)));
  }
  L0041f589: { // 0x41f589: 660fb6941ab8498200 MOVZX DX,byte ptr [EDX + EBX*0x1 + 0x8249b8]
    s.dx = with_ax(s.dx, (m.r8((s.dx+(s.bx * 0x00000001u)+0x008249b8u))&integer::mask(8)));
  }
  L0041f592: { // 0x41f592: 668910 MOV word ptr [EAX],DX
    m.w16((s.ax), (s.dx & 0xffffu));
  }
  L0041f595: { // 0x41f595: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  L0041f598: { // 0x41f598: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0041f599: { // 0x41f599: 75c4 JNZ 0x0041f55f
    if(integer::condition("JNZ",flags)) goto L0041f55f;
  }
  L0041f59b: { // 0x41f59b: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0041f59f: { // 0x41f59f: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041f5a3: { // 0x41f5a3: 8b5c2434 MOV EBX,dword ptr [ESP + 0x34]
    s.bx = m.r32((f.sp+0x00000034u));
  }
  L0041f5a7: { // 0x41f5a7: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041f5a9: { // 0x41f5a9: 8d0458 LEA EAX,[EAX + EBX*0x2]
    s.ax = (s.ax+(s.bx * 0x00000002u));
  }
  L0041f5ac: { // 0x41f5ac: 8b5c2428 MOV EBX,dword ptr [ESP + 0x28]
    s.bx = m.r32((f.sp+0x00000028u));
  }
  L0041f5b0: { // 0x41f5b0: 015c2414 ADD dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), integer::add(m.r32((f.sp+0x00000014u)),s.bx,32,flags));
  }
  L0041f5b4: { // 0x41f5b4: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L0041f5b5: { // 0x41f5b5: 75a2 JNZ 0x0041f559
    if(integer::condition("JNZ",flags)) goto L0041f559;
  }
  L0041f5b7: { // 0x41f5b7: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L0041f5bb: { // 0x41f5bb: a1a0498200 MOV EAX,[0x008249a0]
    s.ax = m.r32((0x008249a0u));
  }
  L0041f5c0: { // 0x41f5c0: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0041f5c1: { // 0x41f5c1: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0041f5c3: { // 0x41f5c3: 896c2430 MOV dword ptr [ESP + 0x30],EBP
    m.w32((f.sp+0x00000030u), s.bp);
  }
  L0041f5c7: { // 0x41f5c7: 0f8c1cfcffff JL 0x0041f1e9
    if(integer::condition("JL",flags)) goto L0041f1e9;
  }
  L0041f5cd: { // 0x41f5cd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041f5ce: { // 0x41f5ce: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041f5cf: { // 0x41f5cf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041f5d0: { // 0x41f5d0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041f5d1: { // 0x41f5d1: 81c4b8000000 ADD ESP,0xb8
    f.sp = integer::add(f.sp,0x000000b8u,32,flags);
  }
  L0041f5d7: { // 0x41f5d7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
