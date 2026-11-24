#include "recovered/recovery_b1552_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1552 {
namespace {
void f_00013ca0(Memory&,State&,Frame&,const Operations&);
void f_002b72a0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_0001b600(Memory&,State&,Frame&,const Operations&);
void f_002cdab0(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_0001b580(Memory&,State&,Frame&,const Operations&);
void f_000b8b00(Memory&,State&,Frame&,const Operations&);
void f_000b8850(Memory&,State&,Frame&,const Operations&);
void f_000b8780(Memory&,State&,Frame&,const Operations&);
void f_002d4b70(Memory&,State&,Frame&,const Operations&);
void f_001ccef0(Memory&,State&,Frame&,const Operations&);
void f_00157070(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_00013ca0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00413ca0: { // 0x413ca0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00413ca1: { // 0x413ca1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00413ca2: { // 0x413ca2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00413ca3: { // 0x413ca3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00413ca5: { // 0x413ca5: e8f6352a00 CALL 0x006b72a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b72a0u,4275370u); flags=s.arithmetic_flags;
  }
  L00413caa: { // 0x413caa: 8bbeac050000 MOV EDI,dword ptr [ESI + 0x5ac]
    s.di = m.r32((s.si+0x000005acu));
  }
  L00413cb0: { // 0x413cb0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00413cb2: { // 0x413cb2: 0f84c5000000 JZ 0x00413d7d
    if(integer::condition("JZ",flags)) goto L00413d7d;
  }
  L00413cb8: { // 0x413cb8: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00413cbe: { // 0x413cbe: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00413cbf: { // 0x413cbf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00413cc1: { // 0x413cc1: 742f JZ 0x00413cf2
    if(integer::condition("JZ",flags)) goto L00413cf2;
  }
  L00413cc3: { // 0x413cc3: 8b4034 MOV EAX,dword ptr [EAX + 0x34]
    s.ax = m.r32((s.ax+0x00000034u));
  }
  L00413cc6: { // 0x413cc6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00413cc8: { // 0x413cc8: 0584010000 ADD EAX,0x184
    s.ax = integer::add(s.ax,0x00000184u,32,flags);
  }
  L00413ccd: { // 0x413ccd: 8b5010 MOV EDX,dword ptr [EAX + 0x10]
    s.dx = m.r32((s.ax+0x00000010u));
  }
  L00413cd0: { // 0x413cd0: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00413cd2: { // 0x413cd2: 7e1e JLE 0x00413cf2
    if(integer::condition("JLE",flags)) goto L00413cf2;
  }
  L00413cd4: { // 0x413cd4: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00413cd7: { // 0x413cd7: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L00413cd9: { // 0x413cd9: 740a JZ 0x00413ce5
    if(integer::condition("JZ",flags)) goto L00413ce5;
  }
  L00413cdb: { // 0x413cdb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00413cdc: { // 0x413cdc: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00413cdf: { // 0x413cdf: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00413ce1: { // 0x413ce1: 7cf4 JL 0x00413cd7
    if(integer::condition("JL",flags)) goto L00413cd7;
  }
  L00413ce3: { // 0x413ce3: eb0d JMP 0x00413cf2
    goto L00413cf2;
  }
  L00413ce5: { // 0x413ce5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00413ce7: { // 0x413ce7: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L00413ced: { // 0x413ced: e8ee432f00 CALL 0x007080e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007080e0u,4275442u); flags=s.arithmetic_flags;
  }
  L00413cf2: { // 0x413cf2: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L00413cf8: { // 0x413cf8: 8dbee0020000 LEA EDI,[ESI + 0x2e0]
    s.di = (s.si+0x000002e0u);
  }
  L00413cfe: { // 0x413cfe: 8b8838060000 MOV ECX,dword ptr [EAX + 0x638]
    s.cx = m.r32((s.ax+0x00000638u));
  }
  L00413d04: { // 0x413d04: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00413d05: { // 0x413d05: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00413d07: { // 0x413d07: e8f44d0a00 CALL 0x004b8b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8b00u,4275468u); flags=s.arithmetic_flags;
  }
  L00413d0c: { // 0x413d0c: 8b96ac050000 MOV EDX,dword ptr [ESI + 0x5ac]
    s.dx = m.r32((s.si+0x000005acu));
  }
  L00413d12: { // 0x413d12: 8d9ef8020000 LEA EBX,[ESI + 0x2f8]
    s.bx = (s.si+0x000002f8u);
  }
  L00413d18: { // 0x413d18: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00413d1a: { // 0x413d1a: 8b8238060000 MOV EAX,dword ptr [EDX + 0x638]
    s.ax = m.r32((s.dx+0x00000638u));
  }
  L00413d20: { // 0x413d20: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00413d21: { // 0x413d21: e8da4d0a00 CALL 0x004b8b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8b00u,4275494u); flags=s.arithmetic_flags;
  }
  L00413d26: { // 0x413d26: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00413d2a: { // 0x413d2a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00413d2b: { // 0x413d2b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00413d2d: { // 0x413d2d: e81e4b0a00 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4275506u); flags=s.arithmetic_flags;
  }
  L00413d32: { // 0x413d32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00413d33: { // 0x413d33: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00413d35: { // 0x413d35: e8464a0a00 CALL 0x004b8780
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8780u,4275514u); flags=s.arithmetic_flags;
  }
  L00413d3a: { // 0x413d3a: 8b8eac050000 MOV ECX,dword ptr [ESI + 0x5ac]
    s.cx = m.r32((s.si+0x000005acu));
  }
  L00413d40: { // 0x413d40: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L00413d42: { // 0x413d42: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00413d44: { // 0x413d44: ff92bc000000 CALL dword ptr [EDX + 0xbc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000bcu)),4275530u); flags=s.arithmetic_flags;
  }
  L00413d4a: { // 0x413d4a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00413d4b: { // 0x413d4b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00413d4d: { // 0x413d4d: ff97b4010000 CALL dword ptr [EDI + 0x1b4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.di+0x000001b4u)),4275539u); flags=s.arithmetic_flags;
  }
  L00413d53: { // 0x413d53: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L00413d59: { // 0x413d59: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00413d5a: { // 0x413d5a: 8b88a8050000 MOV ECX,dword ptr [EAX + 0x5a8]
    s.cx = m.r32((s.ax+0x000005a8u));
  }
  L00413d60: { // 0x413d60: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L00413d63: { // 0x413d63: 7506 JNZ 0x00413d6b
    if(integer::condition("JNZ",flags)) goto L00413d6b;
  }
  L00413d65: { // 0x413d65: 8b88ac050000 MOV ECX,dword ptr [EAX + 0x5ac]
    s.cx = m.r32((s.ax+0x000005acu));
  }
  L00413d6b: { // 0x413d6b: 898e54020000 MOV dword ptr [ESI + 0x254],ECX
    m.w32((s.si+0x00000254u), s.cx);
  }
  L00413d71: { // 0x413d71: 8b80a0000000 MOV EAX,dword ptr [EAX + 0xa0]
    s.ax = m.r32((s.ax+0x000000a0u));
  }
  L00413d77: { // 0x413d77: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L00413d7a: { // 0x413d7a: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  L00413d7d: { // 0x413d7d: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L00413d83: { // 0x413d83: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00413d85: { // 0x413d85: 7406 JZ 0x00413d8d
    if(integer::condition("JZ",flags)) goto L00413d8d;
  }
  L00413d87: { // 0x413d87: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00413d88: { // 0x413d88: e803610d00 CALL 0x004e9e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e9e90u,4275597u); flags=s.arithmetic_flags;
  }
  L00413d8d: { // 0x413d8d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00413d8e: { // 0x413d8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00413d8f: { // 0x413d8f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00413d90: { // 0x413d90: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b72a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b72a0: { // 0x6b72a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b72a1: { // 0x6b72a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b72a3: { // 0x6b72a3: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006b72a9: { // 0x6b72a9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b72ab: { // 0x6b72ab: 7418 JZ 0x006b72c5
    if(integer::condition("JZ",flags)) goto L006b72c5;
  }
  L006b72ad: { // 0x6b72ad: 3905e4e0a100 CMP dword ptr [0x00a1e0e4],EAX
    (void)integer::sub(m.r32((0x00a1e0e4u)),s.ax,32,flags);
  }
  L006b72b3: { // 0x6b72b3: 7509 JNZ 0x006b72be
    if(integer::condition("JNZ",flags)) goto L006b72be;
  }
  L006b72b5: { // 0x6b72b5: c6867203000001 MOV byte ptr [ESI + 0x372],0x1
    m.w8((s.si+0x00000372u), 0x00000001u);
  }
  L006b72bc: { // 0x6b72bc: eb07 JMP 0x006b72c5
    goto L006b72c5;
  }
  L006b72be: { // 0x6b72be: c6867203000000 MOV byte ptr [ESI + 0x372],0x0
    m.w8((s.si+0x00000372u), 0x00000000u);
  }
  L006b72c5: { // 0x6b72c5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b72c7: { // 0x6b72c7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72c9: { // 0x6b72c9: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7041743u); flags=s.arithmetic_flags;
  }
  L006b72cf: { // 0x6b72cf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b72d1: { // 0x6b72d1: 0f849b020000 JZ 0x006b7572
    if(integer::condition("JZ",flags)) goto L006b7572;
  }
  L006b72d7: { // 0x6b72d7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b72d9: { // 0x6b72d9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72db: { // 0x6b72db: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041761u); flags=s.arithmetic_flags;
  }
  L006b72e1: { // 0x6b72e1: 8b8840050000 MOV ECX,dword ptr [EAX + 0x540]
    s.cx = m.r32((s.ax+0x00000540u));
  }
  L006b72e7: { // 0x6b72e7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b72e9: { // 0x6b72e9: 740b JZ 0x006b72f6
    if(integer::condition("JZ",flags)) goto L006b72f6;
  }
  L006b72eb: { // 0x6b72eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b72ec: { // 0x6b72ec: b920a68100 MOV ECX,0x81a620
    s.cx = 0x0081a620u;
  }
  L006b72f1: { // 0x6b72f1: e80af2d7ff CALL 0x00436500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00436500u,7041782u); flags=s.arithmetic_flags;
  }
  L006b72f6: { // 0x6b72f6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b72f8: { // 0x6b72f8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b72fa: { // 0x6b72fa: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7041792u); flags=s.arithmetic_flags;
  }
  L006b7300: { // 0x6b7300: 8b88080b0000 MOV ECX,dword ptr [EAX + 0xb08]
    s.cx = m.r32((s.ax+0x00000b08u));
  }
  L006b7306: { // 0x6b7306: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b7308: { // 0x6b7308: 7468 JZ 0x006b7372
    if(integer::condition("JZ",flags)) goto L006b7372;
  }
  L006b730a: { // 0x6b730a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b730b: { // 0x6b730b: 6a74 PUSH 0x74
    f.push(m,0x00000074u);
  }
  L006b730d: { // 0x6b730d: e845660b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7041810u); flags=s.arithmetic_flags;
  }
  L006b7312: { // 0x6b7312: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006b7314: { // 0x6b7314: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7317: { // 0x6b7317: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006b7319: { // 0x6b7319: 744e JZ 0x006b7369
    if(integer::condition("JZ",flags)) goto L006b7369;
  }
  L006b731b: { // 0x6b731b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b731d: { // 0x6b731d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b731f: { // 0x6b731f: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041829u); flags=s.arithmetic_flags;
  }
  L006b7325: { // 0x6b7325: 8b80140b0000 MOV EAX,dword ptr [EAX + 0xb14]
    s.ax = m.r32((s.ax+0x00000b14u));
  }
  L006b732b: { // 0x6b732b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b732d: { // 0x6b732d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b732e: { // 0x6b732e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7330: { // 0x6b7330: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041846u); flags=s.arithmetic_flags;
  }
  L006b7336: { // 0x6b7336: 8b80100b0000 MOV EAX,dword ptr [EAX + 0xb10]
    s.ax = m.r32((s.ax+0x00000b10u));
  }
  L006b733c: { // 0x6b733c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b733e: { // 0x6b733e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b733f: { // 0x6b733f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7341: { // 0x6b7341: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041863u); flags=s.arithmetic_flags;
  }
  L006b7347: { // 0x6b7347: 8b800c0b0000 MOV EAX,dword ptr [EAX + 0xb0c]
    s.ax = m.r32((s.ax+0x00000b0cu));
  }
  L006b734d: { // 0x6b734d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b734f: { // 0x6b734f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b7350: { // 0x6b7350: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7352: { // 0x6b7352: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7041880u); flags=s.arithmetic_flags;
  }
  L006b7358: { // 0x6b7358: 8b80080b0000 MOV EAX,dword ptr [EAX + 0xb08]
    s.ax = m.r32((s.ax+0x00000b08u));
  }
  L006b735e: { // 0x6b735e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b7360: { // 0x6b7360: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006b7361: { // 0x6b7361: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b7362: { // 0x6b7362: e8a97afcff CALL 0x0067ee10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0067ee10u,7041895u); flags=s.arithmetic_flags;
  }
  L006b7367: { // 0x6b7367: eb02 JMP 0x006b736b
    goto L006b736b;
  }
  L006b7369: { // 0x6b7369: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b736b: { // 0x6b736b: 898638020000 MOV dword ptr [ESI + 0x238],EAX
    m.w32((s.si+0x00000238u), s.ax);
  }
  L006b7371: { // 0x6b7371: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b7372: { // 0x6b7372: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b7374: { // 0x6b7374: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7376: { // 0x6b7376: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7378: { // 0x6b7378: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7041918u); flags=s.arithmetic_flags;
  }
  L006b737e: { // 0x6b737e: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b7381: { // 0x6b7381: 743e JZ 0x006b73c1
    if(integer::condition("JZ",flags)) goto L006b73c1;
  }
  L006b7383: { // 0x6b7383: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b7385: { // 0x6b7385: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7387: { // 0x6b7387: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7389: { // 0x6b7389: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7041935u); flags=s.arithmetic_flags;
  }
  L006b738f: { // 0x6b738f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b7391: { // 0x6b7391: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  L006b7397: { // 0x6b7397: 8a8253010000 MOV AL,byte ptr [EDX + 0x153]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000153u)));
  }
  L006b739d: { // 0x6b739d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b739f: { // 0x6b739f: 7420 JZ 0x006b73c1
    if(integer::condition("JZ",flags)) goto L006b73c1;
  }
  L006b73a1: { // 0x6b73a1: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  L006b73a3: { // 0x6b73a3: e8af650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7041960u); flags=s.arithmetic_flags;
  }
  L006b73a8: { // 0x6b73a8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b73ab: { // 0x6b73ab: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b73ad: { // 0x6b73ad: 740a JZ 0x006b73b9
    if(integer::condition("JZ",flags)) goto L006b73b9;
  }
  L006b73af: { // 0x6b73af: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b73b0: { // 0x6b73b0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b73b2: { // 0x6b73b2: e82906dbff CALL 0x004679e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004679e0u,7041975u); flags=s.arithmetic_flags;
  }
  L006b73b7: { // 0x6b73b7: eb02 JMP 0x006b73bb
    goto L006b73bb;
  }
  L006b73b9: { // 0x6b73b9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b73bb: { // 0x6b73bb: 898630020000 MOV dword ptr [ESI + 0x230],EAX
    m.w32((s.si+0x00000230u), s.ax);
  }
  L006b73c1: { // 0x6b73c1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b73c3: { // 0x6b73c3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73c5: { // 0x6b73c5: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7041992u); flags=s.arithmetic_flags;
  }
  L006b73c8: { // 0x6b73c8: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006b73cb: { // 0x6b73cb: 744f JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73cd: { // 0x6b73cd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b73cf: { // 0x6b73cf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b73d1: { // 0x6b73d1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73d3: { // 0x6b73d3: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042009u); flags=s.arithmetic_flags;
  }
  L006b73d9: { // 0x6b73d9: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b73dc: { // 0x6b73dc: 743e JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73de: { // 0x6b73de: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b73e0: { // 0x6b73e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b73e2: { // 0x6b73e2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b73e4: { // 0x6b73e4: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7042026u); flags=s.arithmetic_flags;
  }
  L006b73ea: { // 0x6b73ea: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006b73ec: { // 0x6b73ec: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  L006b73f2: { // 0x6b73f2: 8a8256010000 MOV AL,byte ptr [EDX + 0x156]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00000156u)));
  }
  L006b73f8: { // 0x6b73f8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b73fa: { // 0x6b73fa: 7420 JZ 0x006b741c
    if(integer::condition("JZ",flags)) goto L006b741c;
  }
  L006b73fc: { // 0x6b73fc: 6a58 PUSH 0x58
    f.push(m,0x00000058u);
  }
  L006b73fe: { // 0x6b73fe: e854650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7042051u); flags=s.arithmetic_flags;
  }
  L006b7403: { // 0x6b7403: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7406: { // 0x6b7406: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b7408: { // 0x6b7408: 740a JZ 0x006b7414
    if(integer::condition("JZ",flags)) goto L006b7414;
  }
  L006b740a: { // 0x6b740a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b740b: { // 0x6b740b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b740d: { // 0x6b740d: e80e6af4ff CALL 0x005fde20
    s.arithmetic_flags=flags; invoke(m,s,f,0x005fde20u,7042066u); flags=s.arithmetic_flags;
  }
  L006b7412: { // 0x6b7412: eb02 JMP 0x006b7416
    goto L006b7416;
  }
  L006b7414: { // 0x6b7414: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b7416: { // 0x6b7416: 898688050000 MOV dword ptr [ESI + 0x588],EAX
    m.w32((s.si+0x00000588u), s.ax);
  }
  L006b741c: { // 0x6b741c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b741e: { // 0x6b741e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7420: { // 0x6b7420: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7422: { // 0x6b7422: ff909c030000 CALL dword ptr [EAX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000039cu)),7042088u); flags=s.arithmetic_flags;
  }
  L006b7428: { // 0x6b7428: 833800 CMP dword ptr [EAX],0x0
    (void)integer::sub(m.r32((s.ax)),0x00000000u,32,flags);
  }
  L006b742b: { // 0x6b742b: 745b JZ 0x006b7488
    if(integer::condition("JZ",flags)) goto L006b7488;
  }
  L006b742d: { // 0x6b742d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b742f: { // 0x6b742f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7431: { // 0x6b7431: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b7433: { // 0x6b7433: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042105u); flags=s.arithmetic_flags;
  }
  L006b7439: { // 0x6b7439: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b743b: { // 0x6b743b: 8b88ac000000 MOV ECX,dword ptr [EAX + 0xac]
    s.cx = m.r32((s.ax+0x000000acu));
  }
  L006b7441: { // 0x6b7441: 8a8157010000 MOV AL,byte ptr [ECX + 0x157]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000157u)));
  }
  L006b7447: { // 0x6b7447: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b7449: { // 0x6b7449: 743d JZ 0x006b7488
    if(integer::condition("JZ",flags)) goto L006b7488;
  }
  L006b744b: { // 0x6b744b: 6a50 PUSH 0x50
    f.push(m,0x00000050u);
  }
  L006b744d: { // 0x6b744d: e805650b00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7042130u); flags=s.arithmetic_flags;
  }
  L006b7452: { // 0x6b7452: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006b7455: { // 0x6b7455: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006b7457: { // 0x6b7457: 740a JZ 0x006b7463
    if(integer::condition("JZ",flags)) goto L006b7463;
  }
  L006b7459: { // 0x6b7459: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b745a: { // 0x6b745a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006b745c: { // 0x6b745c: e86fff0100 CALL 0x006d73d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d73d0u,7042145u); flags=s.arithmetic_flags;
  }
  L006b7461: { // 0x6b7461: eb02 JMP 0x006b7465
    goto L006b7465;
  }
  L006b7463: { // 0x6b7463: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006b7465: { // 0x6b7465: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b7467: { // 0x6b7467: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006b7469: { // 0x6b7469: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b746b: { // 0x6b746b: 898608020000 MOV dword ptr [ESI + 0x208],EAX
    m.w32((s.si+0x00000208u), s.ax);
  }
  L006b7471: { // 0x6b7471: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7042167u); flags=s.arithmetic_flags;
  }
  L006b7477: { // 0x6b7477: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L006b7479: { // 0x6b7479: 8b8e08020000 MOV ECX,dword ptr [ESI + 0x208]
    s.cx = m.r32((s.si+0x00000208u));
  }
  L006b747f: { // 0x6b747f: 8b90a4000000 MOV EDX,dword ptr [EAX + 0xa4]
    s.dx = m.r32((s.ax+0x000000a4u));
  }
  L006b7485: { // 0x6b7485: 89514c MOV dword ptr [ECX + 0x4c],EDX
    m.w32((s.cx+0x0000004cu), s.dx);
  }
  L006b7488: { // 0x6b7488: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b748a: { // 0x6b748a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b748c: { // 0x6b748c: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7042194u); flags=s.arithmetic_flags;
  }
  L006b7492: { // 0x6b7492: 8a88f70a0000 MOV CL,byte ptr [EAX + 0xaf7]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af7u)));
  }
  L006b7498: { // 0x6b7498: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b749a: { // 0x6b749a: 7456 JZ 0x006b74f2
    if(integer::condition("JZ",flags)) goto L006b74f2;
  }
  L006b749c: { // 0x6b749c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b749e: { // 0x6b749e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b74a0: { // 0x6b74a0: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7042214u); flags=s.arithmetic_flags;
  }
  L006b74a6: { // 0x6b74a6: 8a88f80a0000 MOV CL,byte ptr [EAX + 0xaf8]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000af8u)));
  }
  L006b74ac: { // 0x6b74ac: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006b74ae: { // 0x6b74ae: 7442 JZ 0x006b74f2
    if(integer::condition("JZ",flags)) goto L006b74f2;
  }
  L006b74b0: { // 0x6b74b0: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006b74b6: { // 0x6b74b6: c6867001000001 MOV byte ptr [ESI + 0x170],0x1
    m.w8((s.si+0x00000170u), 0x00000001u);
  }
  L006b74bd: { // 0x6b74bd: 898610040000 MOV dword ptr [ESI + 0x410],EAX
    m.w32((s.si+0x00000410u), s.ax);
  }
  L006b74c3: { // 0x6b74c3: 8b8830010000 MOV ECX,dword ptr [EAX + 0x130]
    s.cx = m.r32((s.ax+0x00000130u));
  }
  L006b74c9: { // 0x6b74c9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006b74cb: { // 0x6b74cb: 7513 JNZ 0x006b74e0
    if(integer::condition("JNZ",flags)) goto L006b74e0;
  }
  L006b74cd: { // 0x6b74cd: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006b74d2: { // 0x6b74d2: 8b886c0b0000 MOV ECX,dword ptr [EAX + 0xb6c]
    s.cx = m.r32((s.ax+0x00000b6cu));
  }
  L006b74d8: { // 0x6b74d8: 898e0c040000 MOV dword ptr [ESI + 0x40c],ECX
    m.w32((s.si+0x0000040cu), s.cx);
  }
  L006b74de: { // 0x6b74de: eb12 JMP 0x006b74f2
    goto L006b74f2;
  }
  L006b74e0: { // 0x6b74e0: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L006b74e6: { // 0x6b74e6: 8b82700b0000 MOV EAX,dword ptr [EDX + 0xb70]
    s.ax = m.r32((s.dx+0x00000b70u));
  }
  L006b74ec: { // 0x6b74ec: 89860c040000 MOV dword ptr [ESI + 0x40c],EAX
    m.w32((s.si+0x0000040cu), s.ax);
  }
  L006b74f2: { // 0x6b74f2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006b74f4: { // 0x6b74f4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b74f6: { // 0x6b74f6: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7042300u); flags=s.arithmetic_flags;
  }
  L006b74fc: { // 0x6b74fc: 8b88b00a0000 MOV ECX,dword ptr [EAX + 0xab0]
    s.cx = m.r32((s.ax+0x00000ab0u));
  }
  L006b7502: { // 0x6b7502: 05b00a0000 ADD EAX,0xab0
    s.ax = integer::add(s.ax,0x00000ab0u,32,flags);
  }
  L006b7507: { // 0x6b7507: 898e30030000 MOV dword ptr [ESI + 0x330],ECX
    m.w32((s.si+0x00000330u), s.cx);
  }
  L006b750d: { // 0x6b750d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7510: { // 0x6b7510: 899634030000 MOV dword ptr [ESI + 0x334],EDX
    m.w32((s.si+0x00000334u), s.dx);
  }
  L006b7516: { // 0x6b7516: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006b7519: { // 0x6b7519: 898e38030000 MOV dword ptr [ESI + 0x338],ECX
    m.w32((s.si+0x00000338u), s.cx);
  }
  L006b751f: { // 0x6b751f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006b7522: { // 0x6b7522: 89963c030000 MOV dword ptr [ESI + 0x33c],EDX
    m.w32((s.si+0x0000033cu), s.dx);
  }
  L006b7528: { // 0x6b7528: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006b752a: { // 0x6b752a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006b752c: { // 0x6b752c: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7042354u); flags=s.arithmetic_flags;
  }
  L006b7532: { // 0x6b7532: 8b88c40a0000 MOV ECX,dword ptr [EAX + 0xac4]
    s.cx = m.r32((s.ax+0x00000ac4u));
  }
  L006b7538: { // 0x6b7538: 05c40a0000 ADD EAX,0xac4
    s.ax = integer::add(s.ax,0x00000ac4u,32,flags);
  }
  L006b753d: { // 0x6b753d: 898e50030000 MOV dword ptr [ESI + 0x350],ECX
    m.w32((s.si+0x00000350u), s.cx);
  }
  L006b7543: { // 0x6b7543: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006b7546: { // 0x6b7546: 899654030000 MOV dword ptr [ESI + 0x354],EDX
    m.w32((s.si+0x00000354u), s.dx);
  }
  L006b754c: { // 0x6b754c: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L006b754f: { // 0x6b754f: 898e58030000 MOV dword ptr [ESI + 0x358],ECX
    m.w32((s.si+0x00000358u), s.cx);
  }
  L006b7555: { // 0x6b7555: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L006b7558: { // 0x6b7558: 89965c030000 MOV dword ptr [ESI + 0x35c],EDX
    m.w32((s.si+0x0000035cu), s.dx);
  }
  L006b755e: { // 0x6b755e: c786ec03000001000000 MOV dword ptr [ESI + 0x3ec],0x1
    m.w32((s.si+0x000003ecu), 0x00000001u);
  }
  L006b7568: { // 0x6b7568: c786f003000000000000 MOV dword ptr [ESI + 0x3f0],0x0
    m.w32((s.si+0x000003f0u), 0x00000000u);
  }
  L006b7572: { // 0x6b7572: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b7573: { // 0x6b7573: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // 0x6b6912: ffa084000000 JMP dword ptr [EAX + 0x84]
    switch(m.r32((s.ax+0x00000084u))){
    case 0x006b6910u: goto L006b6910;
    case 0x006b6912u: goto L006b6912;
    default:s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.ax+0x00000084u))); return;}
  }
}
void f_0001b600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b600: { // 0x41b600: 8b81ac050000 MOV EAX, dword ptr [ECX + 0x5ac]
    s.ax = m.r32((s.cx+0x000005acu));
  }
  L0041b606: { // 0x41b606: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdab0: { // 0x6cdab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdab1: { // 0x6cdab1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdab2: { // 0x6cdab2: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L006cdab6: { // 0x6cdab6: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdab8: { // 0x6cdab8: 83ffff CMP EDI, -1
    (void)integer::sub(s.di,4294967295u,32,flags);
  }
  L006cdabb: { // 0x6cdabb: 7507 JNZ 0x6cdac4
    if(integer::condition("JNZ",flags)) goto L006cdac4;
  }
  L006cdabd: { // 0x6cdabd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdabe: { // 0x6cdabe: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdac0: { // 0x6cdac0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdac1: { // 0x6cdac1: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006cdac4: { // 0x6cdac4: 8d8e18010000 LEA ECX, [ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L006cdaca: { // 0x6cdaca: e811a50300 CALL 0x707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7133903u); flags=s.arithmetic_flags;
  }
  L006cdacf: { // 0x6cdacf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdad1: { // 0x6cdad1: 741b JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdad3: { // 0x6cdad3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdad5: { // 0x6cdad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdad6: { // 0x6cdad6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdad8: { // 0x6cdad8: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133918u); flags=s.arithmetic_flags;
  }
  L006cdade: { // 0x6cdade: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdae0: { // 0x6cdae0: e86b700000 CALL 0x6d4b50
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b50u,7133925u); flags=s.arithmetic_flags;
  }
  L006cdae5: { // 0x6cdae5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cdae7: { // 0x6cdae7: 7405 JZ 0x6cdaee
    if(integer::condition("JZ",flags)) goto L006cdaee;
  }
  L006cdae9: { // 0x6cdae9: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L006cdaec: { // 0x6cdaec: 7512 JNZ 0x6cdb00
    if(integer::condition("JNZ",flags)) goto L006cdb00;
  }
  L006cdaee: { // 0x6cdaee: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdaf0: { // 0x6cdaf0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cdaf1: { // 0x6cdaf1: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdaf3: { // 0x6cdaf3: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7133945u); flags=s.arithmetic_flags;
  }
  L006cdaf9: { // 0x6cdaf9: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdafb: { // 0x6cdafb: e830700000 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,7133952u); flags=s.arithmetic_flags;
  }
  L006cdb00: { // 0x6cdb00: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cdb01: { // 0x6cdb01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb02: { // 0x6cdb02: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_0001b580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b580: { // 0x41b580: b802000000 MOV EAX, 2
    s.ax = 2u;
  }
  L0041b585: { // 0x41b585: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000b8b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8b00: { // 0x4b8b00: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004b8b04: { // 0x4b8b04: 83f87f CMP EAX,0x7f
    (void)integer::sub(s.ax,0x0000007fu,32,flags);
  }
  L004b8b07: { // 0x4b8b07: 7c05 JL 0x004b8b0e
    if(integer::condition("JL",flags)) goto L004b8b0e;
  }
  L004b8b09: { // 0x4b8b09: b87f000000 MOV EAX,0x7f
    s.ax = 0x0000007fu;
  }
  L004b8b0e: { // 0x4b8b0e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004b8b10: { // 0x4b8b10: 8af0 MOV DH,AL
    s.dx = (s.dx & 0xffff00ffu) | ((((s.ax & 0xffu)) & 0xffu) << 8);
  }
  L004b8b12: { // 0x4b8b12: 66895114 MOV word ptr [ECX + 0x14],DX
    m.w16((s.cx+0x00000014u), (s.dx & 0xffffu));
  }
  L004b8b16: { // 0x4b8b16: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000b8850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8850: { // 0x4b8850: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004b8851: { // 0x4b8851: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004b8852: { // 0x4b8852: 668b5914 MOV BX,word ptr [ECX + 0x14]
    s.bx = with_ax(s.bx, m.r16((s.cx+0x00000014u)));
  }
  L004b8856: { // 0x4b8856: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b8857: { // 0x4b8857: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b8858: { // 0x4b8858: 6685db TEST BX,BX
    (void)integer::logical(((s.bx & 0xffffu))&((s.bx & 0xffffu)),16,flags);
  }
  L004b885b: { // 0x4b885b: 7e7d JLE 0x004b88da
    if(integer::condition("JLE",flags)) goto L004b88da;
  }
  L004b885d: { // 0x4b885d: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L004b8860: { // 0x4b8860: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    s.ax = m.r32((s.cx+0x00000010u));
  }
  L004b8863: { // 0x4b8863: 8b3d6c89a200 MOV EDI,dword ptr [0x00a2896c]
    s.di = m.r32((0x00a2896cu));
  }
  L004b8869: { // 0x4b8869: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L004b886c: { // 0x4b886c: 740a JZ 0x004b8878
    if(integer::condition("JZ",flags)) goto L004b8878;
  }
  L004b886e: { // 0x4b886e: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L004b8870: { // 0x4b8870: 2bd6 SUB EDX,ESI
    s.dx = integer::sub(s.dx,s.si,32,flags);
  }
  L004b8872: { // 0x4b8872: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L004b8874: { // 0x4b8874: 7d64 JGE 0x004b88da
    if(integer::condition("JGE",flags)) goto L004b88da;
  }
  L004b8876: { // 0x4b8876: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8878: { // 0x4b8878: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004b887a: { // 0x4b887a: 745e JZ 0x004b88da
    if(integer::condition("JZ",flags)) goto L004b88da;
  }
  L004b887c: { // 0x4b887c: 668b01 MOV AX,word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L004b887f: { // 0x4b887f: 662b4104 SUB AX,word ptr [ECX + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.cx+0x00000004u)),16,flags));
  }
  L004b8883: { // 0x4b8883: 0fbfdb MOVSX EBX,BX
    s.bx = std::uint32_t(integer::sign_extend((s.bx & 0xffffu),16));
  }
  L004b8886: { // 0x4b8886: 0fbff0 MOVSX ESI,AX
    s.si = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b8889: { // 0x4b8889: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b888b: { // 0x4b888b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b888c: { // 0x4b888c: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004b888e: { // 0x4b888e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b8890: { // 0x4b8890: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b8891: { // 0x4b8891: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b8893: { // 0x4b8893: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b8895: { // 0x4b8895: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L004b8899: { // 0x4b8899: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L004b889c: { // 0x4b889c: 7e27 JLE 0x004b88c5
    if(integer::condition("JLE",flags)) goto L004b88c5;
  }
  L004b889e: { // 0x4b889e: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004b88a1: { // 0x4b88a1: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L004b88a4: { // 0x4b88a4: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L004b88a7: { // 0x4b88a7: 740a JZ 0x004b88b3
    if(integer::condition("JZ",flags)) goto L004b88b3;
  }
  L004b88a9: { // 0x4b88a9: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L004b88ab: { // 0x4b88ab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004b88ad: { // 0x4b88ad: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004b88af: { // 0x4b88af: 7d25 JGE 0x004b88d6
    if(integer::condition("JGE",flags)) goto L004b88d6;
  }
  L004b88b1: { // 0x4b88b1: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L004b88b3: { // 0x4b88b3: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004b88b5: { // 0x4b88b5: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b88b8: { // 0x4b88b8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004b88ba: { // 0x4b88ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b88bb: { // 0x4b88bb: f7ff IDIV EDI
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.di,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b88bd: { // 0x4b88bd: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L004b88c0: { // 0x4b88c0: 662944240c SUB word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), integer::sub(m.r16((f.sp+0x0000000cu)),(s.ax & 0xffffu),16,flags));
  }
  L004b88c5: { // 0x4b88c5: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88c9: { // 0x4b88c9: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004b88cd: { // 0x4b88cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88ce: { // 0x4b88ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88cf: { // 0x4b88cf: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L004b88d1: { // 0x4b88d1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88d2: { // 0x4b88d2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88d3: { // 0x4b88d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004b88d6: { // 0x4b88d6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b88d8: { // 0x4b88d8: ebdb JMP 0x004b88b5
    goto L004b88b5;
  }
  L004b88da: { // 0x4b88da: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004b88de: { // 0x4b88de: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004b88e0: { // 0x4b88e0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b88e1: { // 0x4b88e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b88e2: { // 0x4b88e2: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L004b88e4: { // 0x4b88e4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b88e5: { // 0x4b88e5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004b88e6: { // 0x4b88e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000b8780(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004b8780: { // 0x4b8780: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004b8783: { // 0x4b8783: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004b8784: { // 0x4b8784: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004b8785: { // 0x4b8785: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004b8787: { // 0x4b8787: 66837e1400 CMP word ptr [ESI + 0x14],0x0
    (void)integer::sub(m.r16((s.si+0x00000014u)),0x00000000u,16,flags);
  }
  L004b878c: { // 0x4b878c: 7e67 JLE 0x004b87f5
    if(integer::condition("JLE",flags)) goto L004b87f5;
  }
  L004b878e: { // 0x4b878e: 8d5e08 LEA EBX,[ESI + 0x8]
    s.bx = (s.si+0x00000008u);
  }
  L004b8791: { // 0x4b8791: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L004b8793: { // 0x4b8793: e898b3f9ff CALL 0x00453b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00453b30u,4949912u); flags=s.arithmetic_flags;
  }
  L004b8798: { // 0x4b8798: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004b879a: { // 0x4b879a: 7459 JZ 0x004b87f5
    if(integer::condition("JZ",flags)) goto L004b87f5;
  }
  L004b879c: { // 0x4b879c: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L004b879f: { // 0x4b879f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004b87a0: { // 0x4b87a0: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L004b87a4: { // 0x4b87a4: 0fbf4e14 MOVSX ECX,word ptr [ESI + 0x14]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000014u)),16));
  }
  L004b87a8: { // 0x4b87a8: 0fbff8 MOVSX EDI,AX
    s.di = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b87ab: { // 0x4b87ab: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004b87ad: { // 0x4b87ad: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b87ae: { // 0x4b87ae: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L004b87b0: { // 0x4b87b0: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L004b87b2: { // 0x4b87b2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b87b3: { // 0x4b87b3: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b87b5: { // 0x4b87b5: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004b87b7: { // 0x4b87b7: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L004b87bb: { // 0x4b87bb: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L004b87be: { // 0x4b87be: 7e2a JLE 0x004b87ea
    if(integer::condition("JLE",flags)) goto L004b87ea;
  }
  L004b87c0: { // 0x4b87c0: 8b5308 MOV EDX,dword ptr [EBX + 0x8]
    s.dx = m.r32((s.bx+0x00000008u));
  }
  L004b87c3: { // 0x4b87c3: 8b1b MOV EBX,dword ptr [EBX]
    s.bx = m.r32((s.bx));
  }
  L004b87c5: { // 0x4b87c5: 83fbff CMP EBX,-0x1
    (void)integer::sub(s.bx,0xffffffffu,32,flags);
  }
  L004b87c8: { // 0x4b87c8: 740e JZ 0x004b87d8
    if(integer::condition("JZ",flags)) goto L004b87d8;
  }
  L004b87ca: { // 0x4b87ca: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L004b87d0: { // 0x4b87d0: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L004b87d2: { // 0x4b87d2: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004b87d4: { // 0x4b87d4: 7d1b JGE 0x004b87f1
    if(integer::condition("JGE",flags)) goto L004b87f1;
  }
  L004b87d6: { // 0x4b87d6: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L004b87d8: { // 0x4b87d8: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L004b87da: { // 0x4b87da: 0fbfd8 MOVSX EBX,AX
    s.bx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L004b87dd: { // 0x4b87dd: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L004b87df: { // 0x4b87df: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004b87e0: { // 0x4b87e0: f7fb IDIV EBX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.bx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004b87e2: { // 0x4b87e2: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L004b87e5: { // 0x4b87e5: 662944240c SUB word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), integer::sub(m.r16((f.sp+0x0000000cu)),(s.ax & 0xffffu),16,flags));
  }
  L004b87ea: { // 0x4b87ea: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004b87ee: { // 0x4b87ee: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004b87ef: { // 0x4b87ef: eb06 JMP 0x004b87f7
    goto L004b87f7;
  }
  L004b87f1: { // 0x4b87f1: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b87f3: { // 0x4b87f3: ebe5 JMP 0x004b87da
    goto L004b87da;
  }
  L004b87f5: { // 0x4b87f5: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L004b87f7: { // 0x4b87f7: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004b87fb: { // 0x4b87fb: 663b08 CMP CX,word ptr [EAX]
    (void)integer::sub((s.cx & 0xffffu),m.r16((s.ax)),16,flags);
  }
  L004b87fe: { // 0x4b87fe: 7429 JZ 0x004b8829
    if(integer::condition("JZ",flags)) goto L004b8829;
  }
  L004b8800: { // 0x4b8800: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L004b8802: { // 0x4b8802: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L004b8804: { // 0x4b8804: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L004b8806: { // 0x4b8806: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004b8809: { // 0x4b8809: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L004b880e: { // 0x4b880e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004b8810: { // 0x4b8810: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  L004b8813: { // 0x4b8813: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L004b8815: { // 0x4b8815: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004b8819: { // 0x4b8819: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004b881c: { // 0x4b881c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004b881e: { // 0x4b881e: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L004b8821: { // 0x4b8821: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b8822: { // 0x4b8822: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b8823: { // 0x4b8823: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004b8826: { // 0x4b8826: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004b8829: { // 0x4b8829: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L004b882f: { // 0x4b882f: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004b8833: { // 0x4b8833: 83c608 ADD ESI,0x8
    s.si = integer::add(s.si,0x00000008u,32,flags);
  }
  L004b8836: { // 0x4b8836: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004b8838: { // 0x4b8838: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L004b883a: { // 0x4b883a: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004b883d: { // 0x4b883d: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004b8840: { // 0x4b8840: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004b8841: { // 0x4b8841: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004b8843: { // 0x4b8843: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004b8844: { // 0x4b8844: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004b8847: { // 0x4b8847: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b70: { // 0x6d4b70: 8b8158050000 MOV EAX, dword ptr [ECX + 0x558]
    s.ax = m.r32((s.cx+0x00000558u));
  }
  L006d4b76: { // 0x6d4b76: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L006d4b79: { // 0x6d4b79: 750b JNZ 0x6d4b86
    if(integer::condition("JNZ",flags)) goto L006d4b86;
  }
  L006d4b7b: { // 0x6d4b7b: a1881b8200 MOV EAX, dword ptr [0x821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006d4b80: { // 0x6d4b80: 8b80dc060000 MOV EAX, dword ptr [EAX + 0x6dc]
    s.ax = m.r32((s.ax+0x000006dcu));
  }
  L006d4b86: { // 0x6d4b86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001ccef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ccef0: { // 0x5ccef0: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L005ccef3: { // 0x5ccef3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ccef4: { // 0x5ccef4: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005ccef6: { // 0x5ccef6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005ccef7: { // 0x5ccef7: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L005ccefb: { // 0x5ccefb: 8a4679 MOV AL, byte ptr [ESI + 0x79]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000079u)));
  }
  L005ccefe: { // 0x5ccefe: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ccf00: { // 0x5ccf00: 7406 JZ 0x5ccf08
    if(integer::condition("JZ",flags)) goto L005ccf08;
  }
  L005ccf02: { // 0x5ccf02: 033d98aaa500 ADD EDI, dword ptr [0xa5aa98]
    s.di = integer::add(s.di,m.r32((0x00a5aa98u)),32,flags);
  }
  L005ccf08: { // 0x5ccf08: 8a4674 MOV AL, byte ptr [ESI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000074u)));
  }
  L005ccf0b: { // 0x5ccf0b: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005ccf0d: { // 0x5ccf0d: 7455 JZ 0x5ccf64
    if(integer::condition("JZ",flags)) goto L005ccf64;
  }
  L005ccf0f: { // 0x5ccf0f: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005ccf11: { // 0x5ccf11: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005ccf13: { // 0x5ccf13: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005ccf15: { // 0x5ccf15: ff901c010000 CALL dword ptr [EAX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000011cu)),6082331u); flags=s.arithmetic_flags;
  }
  L005ccf1b: { // 0x5ccf1b: 8d8e88000000 LEA ECX, [ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L005ccf21: { // 0x5ccf21: 8b9688000000 MOV EDX, dword ptr [ESI + 0x88]
    s.dx = m.r32((s.si+0x00000088u));
  }
  L005ccf27: { // 0x5ccf27: 89542408 MOV dword ptr [ESP + 8], EDX
    m.w32((f.sp+8u), s.dx);
  }
  L005ccf2b: { // 0x5ccf2b: 8d542408 LEA EDX, [ESP + 8]
    s.dx = (f.sp+8u);
  }
  L005ccf2f: { // 0x5ccf2f: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L005ccf32: { // 0x5ccf32: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005ccf33: { // 0x5ccf33: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005ccf37: { // 0x5ccf37: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L005ccf3a: { // 0x5ccf3a: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005ccf3e: { // 0x5ccf3e: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005ccf43: { // 0x5ccf43: e828a1f8ff CALL 0x557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6082376u); flags=s.arithmetic_flags;
  }
  L005ccf48: { // 0x5ccf48: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L005ccf4a: { // 0x5ccf4a: 6a01 PUSH 1
    f.push(m,1u);
  }
  L005ccf4c: { // 0x5ccf4c: 898690000000 MOV dword ptr [ESI + 0x90], EAX
    m.w32((s.si+0x00000090u), s.ax);
  }
  L005ccf52: { // 0x5ccf52: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005ccf54: { // 0x5ccf54: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005ccf56: { // 0x5ccf56: ff901c010000 CALL dword ptr [EAX + 0x11c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000011cu)),6082396u); flags=s.arithmetic_flags;
  }
  L005ccf5c: { // 0x5ccf5c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ccf5d: { // 0x5ccf5d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ccf5e: { // 0x5ccf5e: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005ccf61: { // 0x5ccf61: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005ccf64: { // 0x5ccf64: 8d8e88000000 LEA ECX, [ESI + 0x88]
    s.cx = (s.si+0x00000088u);
  }
  L005ccf6a: { // 0x5ccf6a: 8b9688000000 MOV EDX, dword ptr [ESI + 0x88]
    s.dx = m.r32((s.si+0x00000088u));
  }
  L005ccf70: { // 0x5ccf70: 89542408 MOV dword ptr [ESP + 8], EDX
    m.w32((f.sp+8u), s.dx);
  }
  L005ccf74: { // 0x5ccf74: 8d542408 LEA EDX, [ESP + 8]
    s.dx = (f.sp+8u);
  }
  L005ccf78: { // 0x5ccf78: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L005ccf7b: { // 0x5ccf7b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005ccf7c: { // 0x5ccf7c: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L005ccf80: { // 0x5ccf80: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L005ccf83: { // 0x5ccf83: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L005ccf87: { // 0x5ccf87: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L005ccf8c: { // 0x5ccf8c: e8dfa0f8ff CALL 0x557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6082449u); flags=s.arithmetic_flags;
  }
  L005ccf91: { // 0x5ccf91: 03c7 ADD EAX, EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L005ccf93: { // 0x5ccf93: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005ccf94: { // 0x5ccf94: 898690000000 MOV dword ptr [ESI + 0x90], EAX
    m.w32((s.si+0x00000090u), s.ax);
  }
  L005ccf9a: { // 0x5ccf9a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ccf9b: { // 0x5ccf9b: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L005ccf9e: { // 0x5ccf9e: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557070: { // 0x557070: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L00557073: { // 0x557073: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L00557077: { // 0x557077: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00557078: { // 0x557078: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055707a: { // 0x55707a: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  L0055707d: { // 0x55707d: 89442404 MOV dword ptr [ESP + 4], EAX
    m.w32((f.sp+4u), s.ax);
  }
  L00557081: { // 0x557081: 89542408 MOV dword ptr [ESP + 8], EDX
    m.w32((f.sp+8u), s.dx);
  }
  L00557085: { // 0x557085: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557086: { // 0x557086: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055708c: { // 0x55708c: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055708e: { // 0x55708e: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00557090: { // 0x557090: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00557093: { // 0x557093: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00557094: { // 0x557094: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055709a: { // 0x55709a: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055709c: { // 0x55709c: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055709f: { // 0x55709f: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L005570a1: { // 0x5570a1: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005570a4: { // 0x5570a4: c1e109 SHL ECX, 9
    s.cx = integer::shift(s.cx,9u,32,flags,integer::Shift::left);
  }
  L005570a7: { // 0x5570a7: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005570a9: { // 0x5570a9: 7815 JS 0x5570c0
    if(integer::condition("JS",flags)) goto L005570c0;
  }
  L005570ab: { // 0x5570ab: 3b0d5ca98100 CMP ECX, dword ptr [0x81a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  L005570b1: { // 0x5570b1: 7d0d JGE 0x5570c0
    if(integer::condition("JGE",flags)) goto L005570c0;
  }
  L005570b3: { // 0x5570b3: 8b1558a98100 MOV EDX, dword ptr [0x81a958]
    s.dx = m.r32((0x0081a958u));
  }
  L005570b9: { // 0x5570b9: 8b0c8a MOV ECX, dword ptr [EDX + ECX*4]
    s.cx = m.r32((s.dx+(s.cx * 4u)));
  }
  L005570bc: { // 0x5570bc: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005570be: { // 0x5570be: 7518 JNZ 0x5570d8
    if(integer::condition("JNZ",flags)) goto L005570d8;
  }
  L005570c0: { // 0x5570c0: 6689742410 MOV word ptr [ESP + 0x10], SI
    m.w16((f.sp+0x00000010u), (s.si & 0xffffu));
  }
  L005570c5: { // 0x5570c5: 6689442412 MOV word ptr [ESP + 0x12], AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L005570ca: { // 0x5570ca: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005570ce: { // 0x5570ce: b91076a500 MOV ECX, 0xa57610
    s.cx = 0x00a57610u;
  }
  L005570d3: { // 0x5570d3: a33476a500 MOV dword ptr [0xa57634], EAX
    m.w32((0x00a57634u), s.ax);
  }
  L005570d8: { // 0x5570d8: 8d542404 LEA EDX, [ESP + 4]
    s.dx = (f.sp+4u);
  }
  L005570dc: { // 0x5570dc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005570dd: { // 0x5570dd: e8de91f1ff CALL 0x4702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5599458u); flags=s.arithmetic_flags;
  }
  L005570e2: { // 0x5570e2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005570e3: { // 0x5570e3: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005570e6: { // 0x5570e6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000702c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004702c0: { // 0x4702c0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004702c1: { // 0x4702c1: 8bec MOV EBP, ESP
    s.bp = f.sp;
  }
  L004702c3: { // 0x4702c3: 83e4f8 AND ESP, 0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L004702c6: { // 0x4702c6: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004702c9: { // 0x4702c9: a0708f8300 MOV AL, byte ptr [0x838f70]
    s.ax = with_al(s.ax, m.r8((0x00838f70u)));
  }
  L004702ce: { // 0x4702ce: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004702cf: { // 0x4702cf: a801 TEST AL, 1
    (void)integer::logical(((s.ax & 0xffu))&(1u),8,flags);
  }
  L004702d1: { // 0x4702d1: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L004702d3: { // 0x4702d3: 7513 JNZ 0x4702e8
    if(integer::condition("JNZ",flags)) goto L004702e8;
  }
  L004702d5: { // 0x4702d5: db05808f8300 FILD dword ptr [0x838f80]
    const auto address=(0x00838f80u);
    s.fp.load_integer32(m.r32(address));
  }
  L004702db: { // 0x4702db: 0c01 OR AL, 1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(1u),8,flags));
  }
  L004702dd: { // 0x4702dd: a2708f8300 MOV byte ptr [0x838f70], AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702e2: { // 0x4702e2: dd1df08e8300 FSTP qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004702e8: { // 0x4702e8: a802 TEST AL, 2
    (void)integer::logical(((s.ax & 0xffu))&(2u),8,flags);
  }
  L004702ea: { // 0x4702ea: 7519 JNZ 0x470305
    if(integer::condition("JNZ",flags)) goto L00470305;
  }
  L004702ec: { // 0x4702ec: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004702f2: { // 0x4702f2: dc0d30577800 FMUL qword ptr [0x785730]
    const auto address=(0x00785730u);
    s.fp.multiply64(read64(m,address));
  }
  L004702f8: { // 0x4702f8: 0c02 OR AL, 2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(2u),8,flags));
  }
  L004702fa: { // 0x4702fa: a2708f8300 MOV byte ptr [0x838f70], AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L004702ff: { // 0x4702ff: dd1d108f8300 FSTP qword ptr [0x838f10]
    const auto address=(0x00838f10u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00470305: { // 0x470305: a804 TEST AL, 4
    (void)integer::logical(((s.ax & 0xffu))&(4u),8,flags);
  }
  L00470307: { // 0x470307: 0f85a7060000 JNZ 0x4709b4
    if(integer::condition("JNZ",flags)) goto L004709b4;
  }
  L0047030d: { // 0x47030d: 8b0df48e8300 MOV ECX, dword ptr [0x838ef4]
    s.cx = m.r32((0x00838ef4u));
  }
  L00470313: { // 0x470313: 0c04 OR AL, 4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(4u),8,flags));
  }
  L00470315: { // 0x470315: a2708f8300 MOV byte ptr [0x838f70], AL
    m.w8((0x00838f70u), (s.ax & 0xffu));
  }
  L0047031a: { // 0x47031a: a1f08e8300 MOV EAX, dword ptr [0x838ef0]
    s.ax = m.r32((0x00838ef0u));
  }
  L0047031f: { // 0x47031f: a398d77b00 MOV dword ptr [0x7bd798], EAX
    m.w32((0x007bd798u), s.ax);
  }
  L00470324: { // 0x470324: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470326: { // 0x470326: 890d9cd77b00 MOV dword ptr [0x7bd79c], ECX
    m.w32((0x007bd79cu), s.cx);
  }
  L0047032c: { // 0x47032c: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047032e: { // 0x47032e: 8915c0d77b00 MOV dword ptr [0x7bd7c0], EDX
    m.w32((0x007bd7c0u), s.dx);
  }
  L00470334: { // 0x470334: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470336: { // 0x470336: a3c4d77b00 MOV dword ptr [0x7bd7c4], EAX
    m.w32((0x007bd7c4u), s.ax);
  }
  L0047033b: { // 0x47033b: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047033d: { // 0x47033d: 890de0d77b00 MOV dword ptr [0x7bd7e0], ECX
    m.w32((0x007bd7e0u), s.cx);
  }
  L00470343: { // 0x470343: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470345: { // 0x470345: 8915e4d77b00 MOV dword ptr [0x7bd7e4], EDX
    m.w32((0x007bd7e4u), s.dx);
  }
  L0047034b: { // 0x47034b: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L0047034d: { // 0x47034d: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470353: { // 0x470353: a3e8d77b00 MOV dword ptr [0x7bd7e8], EAX
    m.w32((0x007bd7e8u), s.ax);
  }
  L00470358: { // 0x470358: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047035a: { // 0x47035a: 890decd77b00 MOV dword ptr [0x7bd7ec], ECX
    m.w32((0x007bd7ecu), s.cx);
  }
  L00470360: { // 0x470360: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470362: { // 0x470362: 891508d87b00 MOV dword ptr [0x7bd808], EDX
    m.w32((0x007bd808u), s.dx);
  }
  L00470368: { // 0x470368: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L0047036a: { // 0x47036a: a30cd87b00 MOV dword ptr [0x7bd80c], EAX
    m.w32((0x007bd80cu), s.ax);
  }
  L0047036f: { // 0x47036f: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470371: { // 0x470371: 890d10d87b00 MOV dword ptr [0x7bd810], ECX
    m.w32((0x007bd810u), s.cx);
  }
  L00470377: { // 0x470377: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470379: { // 0x470379: 891514d87b00 MOV dword ptr [0x7bd814], EDX
    m.w32((0x007bd814u), s.dx);
  }
  L0047037f: { // 0x47037f: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470381: { // 0x470381: a338d87b00 MOV dword ptr [0x7bd838], EAX
    m.w32((0x007bd838u), s.ax);
  }
  L00470386: { // 0x470386: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470388: { // 0x470388: 890d3cd87b00 MOV dword ptr [0x7bd83c], ECX
    m.w32((0x007bd83cu), s.cx);
  }
  L0047038e: { // 0x47038e: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470390: { // 0x470390: 891560d87b00 MOV dword ptr [0x7bd860], EDX
    m.w32((0x007bd860u), s.dx);
  }
  L00470396: { // 0x470396: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470398: { // 0x470398: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L0047039a: { // 0x47039a: dd1d30d87b00 FSTP qword ptr [0x7bd830]
    const auto address=(0x007bd830u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004703a0: { // 0x4703a0: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004703a2: { // 0x4703a2: c705a0d77b0000000000 MOV dword ptr [0x7bd7a0], 0
    m.w32((0x007bd7a0u), 0u);
  }
  L004703ac: { // 0x4703ac: c705a4d77b0000000000 MOV dword ptr [0x7bd7a4], 0
    m.w32((0x007bd7a4u), 0u);
  }
  L004703b6: { // 0x4703b6: c705a8d77b0000000000 MOV dword ptr [0x7bd7a8], 0
    m.w32((0x007bd7a8u), 0u);
  }
  L004703c0: { // 0x4703c0: c705acd77b0000000000 MOV dword ptr [0x7bd7ac], 0
    m.w32((0x007bd7acu), 0u);
  }
  L004703ca: { // 0x4703ca: c705b0d77b0000000000 MOV dword ptr [0x7bd7b0], 0
    m.w32((0x007bd7b0u), 0u);
  }
  L004703d4: { // 0x4703d4: c705b4d77b000000f03f MOV dword ptr [0x7bd7b4], 0x3ff00000
    m.w32((0x007bd7b4u), 0x3ff00000u);
  }
  L004703de: { // 0x4703de: c705b8d77b0000000000 MOV dword ptr [0x7bd7b8], 0
    m.w32((0x007bd7b8u), 0u);
  }
  L004703e8: { // 0x4703e8: c705bcd77b0000000000 MOV dword ptr [0x7bd7bc], 0
    m.w32((0x007bd7bcu), 0u);
  }
  L004703f2: { // 0x4703f2: c705c8d77b0000000000 MOV dword ptr [0x7bd7c8], 0
    m.w32((0x007bd7c8u), 0u);
  }
  L004703fc: { // 0x4703fc: c705ccd77b0000000000 MOV dword ptr [0x7bd7cc], 0
    m.w32((0x007bd7ccu), 0u);
  }
  L00470406: { // 0x470406: c705d0d77b0000000000 MOV dword ptr [0x7bd7d0], 0
    m.w32((0x007bd7d0u), 0u);
  }
  L00470410: { // 0x470410: c705d4d77b000000f0bf MOV dword ptr [0x7bd7d4], 0xbff00000
    m.w32((0x007bd7d4u), 0xbff00000u);
  }
  L0047041a: { // 0x47041a: c705d8d77b0000000000 MOV dword ptr [0x7bd7d8], 0
    m.w32((0x007bd7d8u), 0u);
  }
  L00470424: { // 0x470424: c705dcd77b0000000000 MOV dword ptr [0x7bd7dc], 0
    m.w32((0x007bd7dcu), 0u);
  }
  L0047042e: { // 0x47042e: c705f0d77b0000000000 MOV dword ptr [0x7bd7f0], 0
    m.w32((0x007bd7f0u), 0u);
  }
  L00470438: { // 0x470438: c705f4d77b0000000000 MOV dword ptr [0x7bd7f4], 0
    m.w32((0x007bd7f4u), 0u);
  }
  L00470442: { // 0x470442: c705f8d77b0000000000 MOV dword ptr [0x7bd7f8], 0
    m.w32((0x007bd7f8u), 0u);
  }
  L0047044c: { // 0x47044c: c705fcd77b0000000000 MOV dword ptr [0x7bd7fc], 0
    m.w32((0x007bd7fcu), 0u);
  }
  L00470456: { // 0x470456: c70500d87b0000000000 MOV dword ptr [0x7bd800], 0
    m.w32((0x007bd800u), 0u);
  }
  L00470460: { // 0x470460: c70504d87b000000f0bf MOV dword ptr [0x7bd804], 0xbff00000
    m.w32((0x007bd804u), 0xbff00000u);
  }
  L0047046a: { // 0x47046a: c70518d87b0000000000 MOV dword ptr [0x7bd818], 0
    m.w32((0x007bd818u), 0u);
  }
  L00470474: { // 0x470474: c7051cd87b0000000000 MOV dword ptr [0x7bd81c], 0
    m.w32((0x007bd81cu), 0u);
  }
  L0047047e: { // 0x47047e: c70520d87b0000000000 MOV dword ptr [0x7bd820], 0
    m.w32((0x007bd820u), 0u);
  }
  L00470488: { // 0x470488: c70524d87b000000f03f MOV dword ptr [0x7bd824], 0x3ff00000
    m.w32((0x007bd824u), 0x3ff00000u);
  }
  L00470492: { // 0x470492: c70528d87b0000000000 MOV dword ptr [0x7bd828], 0
    m.w32((0x007bd828u), 0u);
  }
  L0047049c: { // 0x47049c: c7052cd87b000000f03f MOV dword ptr [0x7bd82c], 0x3ff00000
    m.w32((0x007bd82cu), 0x3ff00000u);
  }
  L004704a6: { // 0x4704a6: c70540d87b0000000000 MOV dword ptr [0x7bd840], 0
    m.w32((0x007bd840u), 0u);
  }
  L004704b0: { // 0x4704b0: c70544d87b0000000000 MOV dword ptr [0x7bd844], 0
    m.w32((0x007bd844u), 0u);
  }
  L004704ba: { // 0x4704ba: c70548d87b0000000000 MOV dword ptr [0x7bd848], 0
    m.w32((0x007bd848u), 0u);
  }
  L004704c4: { // 0x4704c4: c7054cd87b000000f0bf MOV dword ptr [0x7bd84c], 0xbff00000
    m.w32((0x007bd84cu), 0xbff00000u);
  }
  L004704ce: { // 0x4704ce: c70550d87b0000000000 MOV dword ptr [0x7bd850], 0
    m.w32((0x007bd850u), 0u);
  }
  L004704d8: { // 0x4704d8: c70554d87b000000f03f MOV dword ptr [0x7bd854], 0x3ff00000
    m.w32((0x007bd854u), 0x3ff00000u);
  }
  L004704e2: { // 0x4704e2: c70558d87b0000000000 MOV dword ptr [0x7bd858], 0
    m.w32((0x007bd858u), 0u);
  }
  L004704ec: { // 0x4704ec: c7055cd87b0000000000 MOV dword ptr [0x7bd85c], 0
    m.w32((0x007bd85cu), 0u);
  }
  L004704f6: { // 0x4704f6: a364d87b00 MOV dword ptr [0x7bd864], EAX
    m.w32((0x007bd864u), s.ax);
  }
  L004704fb: { // 0x4704fb: c70568d87b0000000000 MOV dword ptr [0x7bd868], 0
    m.w32((0x007bd868u), 0u);
  }
  L00470505: { // 0x470505: c7056cd87b0000000000 MOV dword ptr [0x7bd86c], 0
    m.w32((0x007bd86cu), 0u);
  }
  L0047050f: { // 0x47050f: c70570d87b0000000000 MOV dword ptr [0x7bd870], 0
    m.w32((0x007bd870u), 0u);
  }
  L00470519: { // 0x470519: c70574d87b000000f0bf MOV dword ptr [0x7bd874], 0xbff00000
    m.w32((0x007bd874u), 0xbff00000u);
  }
  L00470523: { // 0x470523: c70578d87b0000000000 MOV dword ptr [0x7bd878], 0
    m.w32((0x007bd878u), 0u);
  }
  L0047052d: { // 0x47052d: c7057cd87b000000f0bf MOV dword ptr [0x7bd87c], 0xbff00000
    m.w32((0x007bd87cu), 0xbff00000u);
  }
  L00470537: { // 0x470537: 890d80d87b00 MOV dword ptr [0x7bd880], ECX
    m.w32((0x007bd880u), s.cx);
  }
  L0047053d: { // 0x47053d: 891584d87b00 MOV dword ptr [0x7bd884], EDX
    m.w32((0x007bd884u), s.dx);
  }
  L00470543: { // 0x470543: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470545: { // 0x470545: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470547: { // 0x470547: a388d87b00 MOV dword ptr [0x7bd888], EAX
    m.w32((0x007bd888u), s.ax);
  }
  L0047054c: { // 0x47054c: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047054e: { // 0x47054e: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L00470554: { // 0x470554: 890d8cd87b00 MOV dword ptr [0x7bd88c], ECX
    m.w32((0x007bd88cu), s.cx);
  }
  L0047055a: { // 0x47055a: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047055c: { // 0x47055c: 8915b0d87b00 MOV dword ptr [0x7bd8b0], EDX
    m.w32((0x007bd8b0u), s.dx);
  }
  L00470562: { // 0x470562: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470564: { // 0x470564: a3b4d87b00 MOV dword ptr [0x7bd8b4], EAX
    m.w32((0x007bd8b4u), s.ax);
  }
  L00470569: { // 0x470569: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0047056b: { // 0x47056b: 890dd8d87b00 MOV dword ptr [0x7bd8d8], ECX
    m.w32((0x007bd8d8u), s.cx);
  }
  L00470571: { // 0x470571: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L00470573: { // 0x470573: 8915dcd87b00 MOV dword ptr [0x7bd8dc], EDX
    m.w32((0x007bd8dcu), s.dx);
  }
  L00470579: { // 0x470579: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L0047057b: { // 0x47057b: a3f8d87b00 MOV dword ptr [0x7bd8f8], EAX
    m.w32((0x007bd8f8u), s.ax);
  }
  L00470580: { // 0x470580: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470582: { // 0x470582: 890dfcd87b00 MOV dword ptr [0x7bd8fc], ECX
    m.w32((0x007bd8fcu), s.cx);
  }
  L00470588: { // 0x470588: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0047058a: { // 0x47058a: 891500d97b00 MOV dword ptr [0x7bd900], EDX
    m.w32((0x007bd900u), s.dx);
  }
  L00470590: { // 0x470590: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L00470592: { // 0x470592: a304d97b00 MOV dword ptr [0x7bd904], EAX
    m.w32((0x007bd904u), s.ax);
  }
  L00470597: { // 0x470597: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470599: { // 0x470599: dcc0 FADD st(0), st(0)
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L0047059b: { // 0x47059b: 890d28d97b00 MOV dword ptr [0x7bd928], ECX
    m.w32((0x007bd928u), s.cx);
  }
  L004705a1: { // 0x4705a1: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004705a3: { // 0x4705a3: 89152cd97b00 MOV dword ptr [0x7bd92c], EDX
    m.w32((0x007bd92cu), s.dx);
  }
  L004705a9: { // 0x4705a9: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004705ab: { // 0x4705ab: a348d97b00 MOV dword ptr [0x7bd948], EAX
    m.w32((0x007bd948u), s.ax);
  }
  L004705b0: { // 0x4705b0: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004705b2: { // 0x4705b2: dd1520d97b00 FST qword ptr [0x7bd920]
    const auto address=(0x007bd920u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705b8: { // 0x4705b8: dd1578d97b00 FST qword ptr [0x7bd978]
    const auto address=(0x007bd978u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004705be: { // 0x4705be: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004705c0: { // 0x4705c0: c70590d87b0000000000 MOV dword ptr [0x7bd890], 0
    m.w32((0x007bd890u), 0u);
  }
  L004705ca: { // 0x4705ca: c70594d87b0000000000 MOV dword ptr [0x7bd894], 0
    m.w32((0x007bd894u), 0u);
  }
  L004705d4: { // 0x4705d4: c70598d87b0000000000 MOV dword ptr [0x7bd898], 0
    m.w32((0x007bd898u), 0u);
  }
  L004705de: { // 0x4705de: c7059cd87b000000f03f MOV dword ptr [0x7bd89c], 0x3ff00000
    m.w32((0x007bd89cu), 0x3ff00000u);
  }
  L004705e8: { // 0x4705e8: c705a0d87b0000000000 MOV dword ptr [0x7bd8a0], 0
    m.w32((0x007bd8a0u), 0u);
  }
  L004705f2: { // 0x4705f2: c705a4d87b000000f0bf MOV dword ptr [0x7bd8a4], 0xbff00000
    m.w32((0x007bd8a4u), 0xbff00000u);
  }
  L004705fc: { // 0x4705fc: c705a8d87b0000000000 MOV dword ptr [0x7bd8a8], 0
    m.w32((0x007bd8a8u), 0u);
  }
  L00470606: { // 0x470606: c705acd87b0000000000 MOV dword ptr [0x7bd8ac], 0
    m.w32((0x007bd8acu), 0u);
  }
  L00470610: { // 0x470610: c705b8d87b0000000000 MOV dword ptr [0x7bd8b8], 0
    m.w32((0x007bd8b8u), 0u);
  }
  L0047061a: { // 0x47061a: c705bcd87b0000000000 MOV dword ptr [0x7bd8bc], 0
    m.w32((0x007bd8bcu), 0u);
  }
  L00470624: { // 0x470624: c705c0d87b0000000000 MOV dword ptr [0x7bd8c0], 0
    m.w32((0x007bd8c0u), 0u);
  }
  L0047062e: { // 0x47062e: c705c4d87b000000f03f MOV dword ptr [0x7bd8c4], 0x3ff00000
    m.w32((0x007bd8c4u), 0x3ff00000u);
  }
  L00470638: { // 0x470638: c705c8d87b0000000000 MOV dword ptr [0x7bd8c8], 0
    m.w32((0x007bd8c8u), 0u);
  }
  L00470642: { // 0x470642: c705ccd87b000000f03f MOV dword ptr [0x7bd8cc], 0x3ff00000
    m.w32((0x007bd8ccu), 0x3ff00000u);
  }
  L0047064c: { // 0x47064c: c705d0d87b0000000000 MOV dword ptr [0x7bd8d0], 0
    m.w32((0x007bd8d0u), 0u);
  }
  L00470656: { // 0x470656: c705d4d87b0000000000 MOV dword ptr [0x7bd8d4], 0
    m.w32((0x007bd8d4u), 0u);
  }
  L00470660: { // 0x470660: c705e0d87b0000000000 MOV dword ptr [0x7bd8e0], 0
    m.w32((0x007bd8e0u), 0u);
  }
  L0047066a: { // 0x47066a: c705e4d87b0000000000 MOV dword ptr [0x7bd8e4], 0
    m.w32((0x007bd8e4u), 0u);
  }
  L00470674: { // 0x470674: c705e8d87b0000000000 MOV dword ptr [0x7bd8e8], 0
    m.w32((0x007bd8e8u), 0u);
  }
  L0047067e: { // 0x47067e: c705ecd87b000000f0bf MOV dword ptr [0x7bd8ec], 0xbff00000
    m.w32((0x007bd8ecu), 0xbff00000u);
  }
  L00470688: { // 0x470688: c705f0d87b0000000000 MOV dword ptr [0x7bd8f0], 0
    m.w32((0x007bd8f0u), 0u);
  }
  L00470692: { // 0x470692: c705f4d87b000000f03f MOV dword ptr [0x7bd8f4], 0x3ff00000
    m.w32((0x007bd8f4u), 0x3ff00000u);
  }
  L0047069c: { // 0x47069c: c70508d97b0000000000 MOV dword ptr [0x7bd908], 0
    m.w32((0x007bd908u), 0u);
  }
  L004706a6: { // 0x4706a6: c7050cd97b0000000000 MOV dword ptr [0x7bd90c], 0
    m.w32((0x007bd90cu), 0u);
  }
  L004706b0: { // 0x4706b0: c70510d97b0000000000 MOV dword ptr [0x7bd910], 0
    m.w32((0x007bd910u), 0u);
  }
  L004706ba: { // 0x4706ba: c70514d97b000000f0bf MOV dword ptr [0x7bd914], 0xbff00000
    m.w32((0x007bd914u), 0xbff00000u);
  }
  L004706c4: { // 0x4706c4: c70518d97b0000000000 MOV dword ptr [0x7bd918], 0
    m.w32((0x007bd918u), 0u);
  }
  L004706ce: { // 0x4706ce: c7051cd97b000000f0bf MOV dword ptr [0x7bd91c], 0xbff00000
    m.w32((0x007bd91cu), 0xbff00000u);
  }
  L004706d8: { // 0x4706d8: c70530d97b0000000000 MOV dword ptr [0x7bd930], 0
    m.w32((0x007bd930u), 0u);
  }
  L004706e2: { // 0x4706e2: c70534d97b0000000000 MOV dword ptr [0x7bd934], 0
    m.w32((0x007bd934u), 0u);
  }
  L004706ec: { // 0x4706ec: c70538d97b0000000000 MOV dword ptr [0x7bd938], 0
    m.w32((0x007bd938u), 0u);
  }
  L004706f6: { // 0x4706f6: c7053cd97b000000f03f MOV dword ptr [0x7bd93c], 0x3ff00000
    m.w32((0x007bd93cu), 0x3ff00000u);
  }
  L00470700: { // 0x470700: c70540d97b0000000000 MOV dword ptr [0x7bd940], 0
    m.w32((0x007bd940u), 0u);
  }
  L0047070a: { // 0x47070a: c70544d97b000000f0bf MOV dword ptr [0x7bd944], 0xbff00000
    m.w32((0x007bd944u), 0xbff00000u);
  }
  L00470714: { // 0x470714: 890d4cd97b00 MOV dword ptr [0x7bd94c], ECX
    m.w32((0x007bd94cu), s.cx);
  }
  L0047071a: { // 0x47071a: 891550d97b00 MOV dword ptr [0x7bd950], EDX
    m.w32((0x007bd950u), s.dx);
  }
  L00470720: { // 0x470720: a354d97b00 MOV dword ptr [0x7bd954], EAX
    m.w32((0x007bd954u), s.ax);
  }
  L00470725: { // 0x470725: c70558d97b0000000000 MOV dword ptr [0x7bd958], 0
    m.w32((0x007bd958u), 0u);
  }
  L0047072f: { // 0x47072f: c7055cd97b0000000000 MOV dword ptr [0x7bd95c], 0
    m.w32((0x007bd95cu), 0u);
  }
  L00470739: { // 0x470739: c70560d97b0000000000 MOV dword ptr [0x7bd960], 0
    m.w32((0x007bd960u), 0u);
  }
  L00470743: { // 0x470743: c70564d97b000000f03f MOV dword ptr [0x7bd964], 0x3ff00000
    m.w32((0x007bd964u), 0x3ff00000u);
  }
  L0047074d: { // 0x47074d: c70568d97b0000000000 MOV dword ptr [0x7bd968], 0
    m.w32((0x007bd968u), 0u);
  }
  L00470757: { // 0x470757: c7056cd97b000000f03f MOV dword ptr [0x7bd96c], 0x3ff00000
    m.w32((0x007bd96cu), 0x3ff00000u);
  }
  L00470761: { // 0x470761: c70570d97b0000000000 MOV dword ptr [0x7bd970], 0
    m.w32((0x007bd970u), 0u);
  }
  L0047076b: { // 0x47076b: c70574d97b0000000000 MOV dword ptr [0x7bd974], 0
    m.w32((0x007bd974u), 0u);
  }
  L00470775: { // 0x470775: c70580d97b0000000000 MOV dword ptr [0x7bd980], 0
    m.w32((0x007bd980u), 0u);
  }
  L0047077f: { // 0x47077f: c70584d97b0000000000 MOV dword ptr [0x7bd984], 0
    m.w32((0x007bd984u), 0u);
  }
  L00470789: { // 0x470789: c70588d97b0000000000 MOV dword ptr [0x7bd988], 0
    m.w32((0x007bd988u), 0u);
  }
  L00470793: { // 0x470793: dd15a0d97b00 FST qword ptr [0x7bd9a0]
    const auto address=(0x007bd9a0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470799: { // 0x470799: dd15c0d97b00 FST qword ptr [0x7bd9c0]
    const auto address=(0x007bd9c0u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047079f: { // 0x47079f: dd15c8d97b00 FST qword ptr [0x7bd9c8]
    const auto address=(0x007bd9c8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707a5: { // 0x4707a5: dd1df0d97b00 FSTP qword ptr [0x7bd9f0]
    const auto address=(0x007bd9f0u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004707ab: { // 0x4707ab: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707b1: { // 0x4707b1: dc0d28577800 FMUL qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.multiply64(read64(m,address));
  }
  L004707b7: { // 0x4707b7: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004707b9: { // 0x4707b9: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004707bb: { // 0x4707bb: 890d98d97b00 MOV dword ptr [0x7bd998], ECX
    m.w32((0x007bd998u), s.cx);
  }
  L004707c1: { // 0x4707c1: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004707c3: { // 0x4707c3: 89159cd97b00 MOV dword ptr [0x7bd99c], EDX
    m.w32((0x007bd99cu), s.dx);
  }
  L004707c9: { // 0x4707c9: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004707cb: { // 0x4707cb: dd1518da7b00 FST qword ptr [0x7bda18]
    const auto address=(0x007bda18u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d1: { // 0x4707d1: dd1520da7b00 FST qword ptr [0x7bda20]
    const auto address=(0x007bda20u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707d7: { // 0x4707d7: dd1540da7b00 FST qword ptr [0x7bda40]
    const auto address=(0x007bda40u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L004707dd: { // 0x4707dd: dd05f08e8300 FLD qword ptr [0x838ef0]
    const auto address=(0x00838ef0u);
    s.fp.load64(read64(m,address));
  }
  L004707e3: { // 0x4707e3: dc0db0797800 FMUL qword ptr [0x7879b0]
    const auto address=(0x007879b0u);
    s.fp.multiply64(read64(m,address));
  }
  L004707e9: { // 0x4707e9: a3e8d97b00 MOV dword ptr [0x7bd9e8], EAX
    m.w32((0x007bd9e8u), s.ax);
  }
  L004707ee: { // 0x4707ee: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L004707f0: { // 0x4707f0: 890decd97b00 MOV dword ptr [0x7bd9ec], ECX
    m.w32((0x007bd9ecu), s.cx);
  }
  L004707f6: { // 0x4707f6: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L004707f8: { // 0x4707f8: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L004707fa: { // 0x4707fa: 891538da7b00 MOV dword ptr [0x7bda38], EDX
    m.w32((0x007bda38u), s.dx);
  }
  L00470800: { // 0x470800: dd542408 FST qword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470804: { // 0x470804: dd1d48da7b00 FSTP qword ptr [0x7bda48]
    const auto address=(0x007bda48u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047080a: { // 0x47080a: a33cda7b00 MOV dword ptr [0x7bda3c], EAX
    m.w32((0x007bda3cu), s.ax);
  }
  L0047080f: { // 0x47080f: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00470811: { // 0x470811: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L00470815: { // 0x470815: 890d88da7b00 MOV dword ptr [0x7bda88], ECX
    m.w32((0x007bda88u), s.cx);
  }
  L0047081b: { // 0x47081b: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0047081f: { // 0x47081f: c7058cd97b000000f0bf MOV dword ptr [0x7bd98c], 0xbff00000
    m.w32((0x007bd98cu), 0xbff00000u);
  }
  L00470829: { // 0x470829: dd1568da7b00 FST qword ptr [0x7bda68]
    const auto address=(0x007bda68u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0047082f: { // 0x47082f: dd1570da7b00 FST qword ptr [0x7bda70]
    const auto address=(0x007bda70u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00470835: { // 0x470835: dd1d90da7b00 FSTP qword ptr [0x7bda90]
    const auto address=(0x007bda90u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0047083b: { // 0x47083b: c70590d97b0000000000 MOV dword ptr [0x7bd990], 0
    m.w32((0x007bd990u), 0u);
  }
  L00470845: { // 0x470845: c70594d97b000000f03f MOV dword ptr [0x7bd994], 0x3ff00000
    m.w32((0x007bd994u), 0x3ff00000u);
  }
  L0047084f: { // 0x47084f: c705a8d97b0000000000 MOV dword ptr [0x7bd9a8], 0
    m.w32((0x007bd9a8u), 0u);
  }
  L00470859: { // 0x470859: c705acd97b0000000000 MOV dword ptr [0x7bd9ac], 0
    m.w32((0x007bd9acu), 0u);
  }
  L00470863: { // 0x470863: c705b0d97b0000000000 MOV dword ptr [0x7bd9b0], 0
    m.w32((0x007bd9b0u), 0u);
  }
  L0047086d: { // 0x47086d: c705b4d97b000000f0bf MOV dword ptr [0x7bd9b4], 0xbff00000
    m.w32((0x007bd9b4u), 0xbff00000u);
  }
  L00470877: { // 0x470877: c705b8d97b0000000000 MOV dword ptr [0x7bd9b8], 0
    m.w32((0x007bd9b8u), 0u);
  }
  L00470881: { // 0x470881: c705bcd97b000000f0bf MOV dword ptr [0x7bd9bc], 0xbff00000
    m.w32((0x007bd9bcu), 0xbff00000u);
  }
  L0047088b: { // 0x47088b: c705d0d97b0000000000 MOV dword ptr [0x7bd9d0], 0
    m.w32((0x007bd9d0u), 0u);
  }
  L00470895: { // 0x470895: c705d4d97b0000000000 MOV dword ptr [0x7bd9d4], 0
    m.w32((0x007bd9d4u), 0u);
  }
  L0047089f: { // 0x47089f: c705d8d97b0000000000 MOV dword ptr [0x7bd9d8], 0
    m.w32((0x007bd9d8u), 0u);
  }
  L004708a9: { // 0x4708a9: c705dcd97b000000f03f MOV dword ptr [0x7bd9dc], 0x3ff00000
    m.w32((0x007bd9dcu), 0x3ff00000u);
  }
  L004708b3: { // 0x4708b3: c705e0d97b0000000000 MOV dword ptr [0x7bd9e0], 0
    m.w32((0x007bd9e0u), 0u);
  }
  L004708bd: { // 0x4708bd: c705e4d97b000000f0bf MOV dword ptr [0x7bd9e4], 0xbff00000
    m.w32((0x007bd9e4u), 0xbff00000u);
  }
  L004708c7: { // 0x4708c7: c705f8d97b0000000000 MOV dword ptr [0x7bd9f8], 0
    m.w32((0x007bd9f8u), 0u);
  }
  L004708d1: { // 0x4708d1: c705fcd97b0000000000 MOV dword ptr [0x7bd9fc], 0
    m.w32((0x007bd9fcu), 0u);
  }
  L004708db: { // 0x4708db: c70500da7b0000000000 MOV dword ptr [0x7bda00], 0
    m.w32((0x007bda00u), 0u);
  }
  L004708e5: { // 0x4708e5: c70504da7b0000000000 MOV dword ptr [0x7bda04], 0
    m.w32((0x007bda04u), 0u);
  }
  L004708ef: { // 0x4708ef: c70508da7b0000000000 MOV dword ptr [0x7bda08], 0
    m.w32((0x007bda08u), 0u);
  }
  L004708f9: { // 0x4708f9: c7050cda7b0000000000 MOV dword ptr [0x7bda0c], 0
    m.w32((0x007bda0cu), 0u);
  }
  L00470903: { // 0x470903: c70510da7b0000000000 MOV dword ptr [0x7bda10], 0
    m.w32((0x007bda10u), 0u);
  }
  L0047090d: { // 0x47090d: c70514da7b0000000000 MOV dword ptr [0x7bda14], 0
    m.w32((0x007bda14u), 0u);
  }
  L00470917: { // 0x470917: c70528da7b0000000000 MOV dword ptr [0x7bda28], 0
    m.w32((0x007bda28u), 0u);
  }
  L00470921: { // 0x470921: c7052cda7b0000000000 MOV dword ptr [0x7bda2c], 0
    m.w32((0x007bda2cu), 0u);
  }
  L0047092b: { // 0x47092b: c70530da7b0000000000 MOV dword ptr [0x7bda30], 0
    m.w32((0x007bda30u), 0u);
  }
  L00470935: { // 0x470935: c70534da7b0000000000 MOV dword ptr [0x7bda34], 0
    m.w32((0x007bda34u), 0u);
  }
  L0047093f: { // 0x47093f: c70550da7b0000000000 MOV dword ptr [0x7bda50], 0
    m.w32((0x007bda50u), 0u);
  }
  L00470949: { // 0x470949: c70554da7b0000000000 MOV dword ptr [0x7bda54], 0
    m.w32((0x007bda54u), 0u);
  }
  L00470953: { // 0x470953: c70558da7b0000000000 MOV dword ptr [0x7bda58], 0
    m.w32((0x007bda58u), 0u);
  }
  L0047095d: { // 0x47095d: c7055cda7b0000000000 MOV dword ptr [0x7bda5c], 0
    m.w32((0x007bda5cu), 0u);
  }
  L00470967: { // 0x470967: c70560da7b0000000000 MOV dword ptr [0x7bda60], 0
    m.w32((0x007bda60u), 0u);
  }
  L00470971: { // 0x470971: c70564da7b0000000000 MOV dword ptr [0x7bda64], 0
    m.w32((0x007bda64u), 0u);
  }
  L0047097b: { // 0x47097b: c70578da7b0000000000 MOV dword ptr [0x7bda78], 0
    m.w32((0x007bda78u), 0u);
  }
  L00470985: { // 0x470985: c7057cda7b0000000000 MOV dword ptr [0x7bda7c], 0
    m.w32((0x007bda7cu), 0u);
  }
  L0047098f: { // 0x47098f: c70580da7b0000000000 MOV dword ptr [0x7bda80], 0
    m.w32((0x007bda80u), 0u);
  }
  L00470999: { // 0x470999: c70584da7b0000000000 MOV dword ptr [0x7bda84], 0
    m.w32((0x007bda84u), 0u);
  }
  L004709a3: { // 0x4709a3: 89158cda7b00 MOV dword ptr [0x7bda8c], EDX
    m.w32((0x007bda8cu), s.dx);
  }
  L004709a9: { // 0x4709a9: a398da7b00 MOV dword ptr [0x7bda98], EAX
    m.w32((0x007bda98u), s.ax);
  }
  L004709ae: { // 0x4709ae: 890d9cda7b00 MOV dword ptr [0x7bda9c], ECX
    m.w32((0x007bda9cu), s.cx);
  }
  L004709b4: { // 0x4709b4: 0fbe961b010000 MOVSX EDX, byte ptr [ESI + 0x11b]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011bu)),8));
  }
  L004709bb: { // 0x4709bb: 0faf15808f8300 IMUL EDX, dword ptr [0x838f80]
    s.dx = integer::imul(s.dx,m.r32((0x00838f80u)),32,flags);
  }
  L004709c2: { // 0x4709c2: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L004709c6: { // 0x4709c6: db442404 FILD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L004709ca: { // 0x4709ca: dc0528577800 FADD qword ptr [0x785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L004709d0: { // 0x4709d0: e87ba02f00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655573u); flags=s.arithmetic_flags;
  }
  L004709d5: { // 0x4709d5: 8a8e1c010000 MOV CL, byte ptr [ESI + 0x11c]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011cu)));
  }
  L004709db: { // 0x4709db: 89442408 MOV dword ptr [ESP + 8], EAX
    m.w32((f.sp+8u), s.ax);
  }
  L004709df: { // 0x4709df: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L004709e1: { // 0x4709e1: 0f868d000000 JBE 0x470a74
    if(integer::condition("JBE",flags)) goto L00470a74;
  }
  L004709e7: { // 0x4709e7: 8b4508 MOV EAX, dword ptr [EBP + 8]
    s.ax = m.r32((s.bp+8u));
  }
  L004709ea: { // 0x4709ea: 81e1ff000000 AND ECX, 0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004709f0: { // 0x4709f0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L004709f1: { // 0x4709f1: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L004709f4: { // 0x4709f4: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L004709f6: { // 0x4709f6: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004709fc: { // 0x4709fc: 8d0c89 LEA ECX, [ECX + ECX*4]
    s.cx = (s.cx+(s.cx * 4u));
  }
  L004709ff: { // 0x4709ff: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L00470a03: { // 0x470a03: 25ff000000 AND EAX, 0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L00470a08: { // 0x470a08: db442404 FILD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a0c: { // 0x470a0c: c1e103 SHL ECX, 3
    s.cx = integer::shift(s.cx,3u,32,flags,integer::Shift::left);
  }
  L00470a0f: { // 0x470a0f: 89442404 MOV dword ptr [ESP + 4], EAX
    m.w32((f.sp+4u), s.ax);
  }
  L00470a13: { // 0x470a13: dc8988d77b00 FMUL qword ptr [ECX + 0x7bd788]
    const auto address=(s.cx+0x007bd788u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a19: { // 0x470a19: dc0d108f8300 FMUL qword ptr [0x838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a1f: { // 0x470a1f: db442404 FILD dword ptr [ESP + 4]
    const auto address=(f.sp+4u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a23: { // 0x470a23: dc8980d77b00 FMUL qword ptr [ECX + 0x7bd780]
    const auto address=(s.cx+0x007bd780u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a29: { // 0x470a29: dc0d108f8300 FMUL qword ptr [0x838f10]
    const auto address=(0x00838f10u);
    s.fp.multiply64(read64(m,address));
  }
  L00470a2f: { // 0x470a2f: dec1 FADDP st(1)
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L00470a31: { // 0x470a31: dc8190d77b00 FADD qword ptr [ECX + 0x7bd790]
    const auto address=(s.cx+0x007bd790u);
    s.fp.add64(read64(m,address));
  }
  L00470a37: { // 0x470a37: dc81a0d77b00 FADD qword ptr [ECX + 0x7bd7a0]
    const auto address=(s.cx+0x007bd7a0u);
    s.fp.add64(read64(m,address));
  }
  L00470a3d: { // 0x470a3d: dc1510667800 FCOM qword ptr [0x786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a43: { // 0x470a43: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a45: { // 0x470a45: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00470a48: { // 0x470a48: 7408 JZ 0x470a52
    if(integer::condition("JZ",flags)) goto L00470a52;
  }
  L00470a4a: { // 0x470a4a: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a4c: { // 0x470a4c: dd0510667800 FLD qword ptr [0x786610]
    const auto address=(0x00786610u);
    s.fp.load64(read64(m,address));
  }
  L00470a52: { // 0x470a52: dc9198d77b00 FCOM qword ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00470a58: { // 0x470a58: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00470a5a: { // 0x470a5a: f6c441 TEST AH, 0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00470a5d: { // 0x470a5d: 7508 JNZ 0x470a67
    if(integer::condition("JNZ",flags)) goto L00470a67;
  }
  L00470a5f: { // 0x470a5f: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a61: { // 0x470a61: dd8198d77b00 FLD qword ptr [ECX + 0x7bd798]
    const auto address=(s.cx+0x007bd798u);
    s.fp.load64(read64(m,address));
  }
  L00470a67: { // 0x470a67: db442408 FILD dword ptr [ESP + 8]
    const auto address=(f.sp+8u);
    s.fp.load_integer32(m.r32(address));
  }
  L00470a6b: { // 0x470a6b: d8c1 FADD st(1)
    numeric_b88::detail::reg<0xd8c1>(s.fp);
  }
  L00470a6d: { // 0x470a6d: e8de9f2f00 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4655730u); flags=s.arithmetic_flags;
  }
  L00470a72: { // 0x470a72: ddd8 FSTP st(0)
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00470a74: { // 0x470a74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00470a75: { // 0x470a75: 8be5 MOV ESP, EBP
    f.sp = s.bp;
  }
  L00470a77: { // 0x470a77: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00470a78: { // 0x470a78: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX, dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX, 0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX, dword ptr [0x7c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x76aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX, dword ptr [0x7c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP], EDX
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
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX, dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4275360u:f_00013ca0(m,s,child,{});break;
case 7041696u:f_002b72a0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4306432u:f_0001b600(m,s,child,{});break;
case 7133872u:f_002cdab0(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 4306304u:f_0001b580(m,s,child,{});break;
case 4950784u:f_000b8b00(m,s,child,{});break;
case 4950096u:f_000b8850(m,s,child,{});break;
case 4949888u:f_000b8780(m,s,child,{});break;
case 7162736u:f_002d4b70(m,s,child,{});break;
case 6082288u:f_001ccef0(m,s,child,{});break;
case 5599344u:f_00157070(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery1552 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ if(target==0x41b600u){f_0001b600(m,s,f,{});return;}throw std::domain_error("B1552 unreviewed tail"); } }

std::uint32_t fun_00413ca0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00413ca0: { // 0x413ca0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00413ca1: { // 0x413ca1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00413ca2: { // 0x413ca2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00413ca3: { // 0x413ca3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00413ca5: { // 0x413ca5: e8f6352a00 CALL 0x006b72a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006b72a0u,4275370u); flags=s.arithmetic_flags;
  }
  L00413caa: { // 0x413caa: 8bbeac050000 MOV EDI,dword ptr [ESI + 0x5ac]
    s.di = m.r32((s.si+0x000005acu));
  }
  L00413cb0: { // 0x413cb0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00413cb2: { // 0x413cb2: 0f84c5000000 JZ 0x00413d7d
    if(integer::condition("JZ",flags)) goto L00413d7d;
  }
  L00413cb8: { // 0x413cb8: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L00413cbe: { // 0x413cbe: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00413cbf: { // 0x413cbf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00413cc1: { // 0x413cc1: 742f JZ 0x00413cf2
    if(integer::condition("JZ",flags)) goto L00413cf2;
  }
  L00413cc3: { // 0x413cc3: 8b4034 MOV EAX,dword ptr [EAX + 0x34]
    s.ax = m.r32((s.ax+0x00000034u));
  }
  L00413cc6: { // 0x413cc6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00413cc8: { // 0x413cc8: 0584010000 ADD EAX,0x184
    s.ax = integer::add(s.ax,0x00000184u,32,flags);
  }
  L00413ccd: { // 0x413ccd: 8b5010 MOV EDX,dword ptr [EAX + 0x10]
    s.dx = m.r32((s.ax+0x00000010u));
  }
  L00413cd0: { // 0x413cd0: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00413cd2: { // 0x413cd2: 7e1e JLE 0x00413cf2
    if(integer::condition("JLE",flags)) goto L00413cf2;
  }
  L00413cd4: { // 0x413cd4: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00413cd7: { // 0x413cd7: 3938 CMP dword ptr [EAX],EDI
    (void)integer::sub(m.r32((s.ax)),s.di,32,flags);
  }
  L00413cd9: { // 0x413cd9: 740a JZ 0x00413ce5
    if(integer::condition("JZ",flags)) goto L00413ce5;
  }
  L00413cdb: { // 0x413cdb: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00413cdc: { // 0x413cdc: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L00413cdf: { // 0x413cdf: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00413ce1: { // 0x413ce1: 7cf4 JL 0x00413cd7
    if(integer::condition("JL",flags)) goto L00413cd7;
  }
  L00413ce3: { // 0x413ce3: eb0d JMP 0x00413cf2
    goto L00413cf2;
  }
  L00413ce5: { // 0x413ce5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00413ce7: { // 0x413ce7: 8d8e18010000 LEA ECX,[ESI + 0x118]
    s.cx = (s.si+0x00000118u);
  }
  L00413ced: { // 0x413ced: e8ee432f00 CALL 0x007080e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x007080e0u,4275442u); flags=s.arithmetic_flags;
  }
  L00413cf2: { // 0x413cf2: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L00413cf8: { // 0x413cf8: 8dbee0020000 LEA EDI,[ESI + 0x2e0]
    s.di = (s.si+0x000002e0u);
  }
  L00413cfe: { // 0x413cfe: 8b8838060000 MOV ECX,dword ptr [EAX + 0x638]
    s.cx = m.r32((s.ax+0x00000638u));
  }
  L00413d04: { // 0x413d04: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00413d05: { // 0x413d05: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00413d07: { // 0x413d07: e8f44d0a00 CALL 0x004b8b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8b00u,4275468u); flags=s.arithmetic_flags;
  }
  L00413d0c: { // 0x413d0c: 8b96ac050000 MOV EDX,dword ptr [ESI + 0x5ac]
    s.dx = m.r32((s.si+0x000005acu));
  }
  L00413d12: { // 0x413d12: 8d9ef8020000 LEA EBX,[ESI + 0x2f8]
    s.bx = (s.si+0x000002f8u);
  }
  L00413d18: { // 0x413d18: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00413d1a: { // 0x413d1a: 8b8238060000 MOV EAX,dword ptr [EDX + 0x638]
    s.ax = m.r32((s.dx+0x00000638u));
  }
  L00413d20: { // 0x413d20: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00413d21: { // 0x413d21: e8da4d0a00 CALL 0x004b8b00
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8b00u,4275494u); flags=s.arithmetic_flags;
  }
  L00413d26: { // 0x413d26: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00413d2a: { // 0x413d2a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00413d2b: { // 0x413d2b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00413d2d: { // 0x413d2d: e81e4b0a00 CALL 0x004b8850
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8850u,4275506u); flags=s.arithmetic_flags;
  }
  L00413d32: { // 0x413d32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00413d33: { // 0x413d33: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00413d35: { // 0x413d35: e8464a0a00 CALL 0x004b8780
    s.arithmetic_flags=flags; invoke(m,s,f,0x004b8780u,4275514u); flags=s.arithmetic_flags;
  }
  L00413d3a: { // 0x413d3a: 8b8eac050000 MOV ECX,dword ptr [ESI + 0x5ac]
    s.cx = m.r32((s.si+0x000005acu));
  }
  L00413d40: { // 0x413d40: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L00413d42: { // 0x413d42: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00413d44: { // 0x413d44: ff92bc000000 CALL dword ptr [EDX + 0xbc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000bcu)),4275530u); flags=s.arithmetic_flags;
  }
  L00413d4a: { // 0x413d4a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00413d4b: { // 0x413d4b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00413d4d: { // 0x413d4d: ff97b4010000 CALL dword ptr [EDI + 0x1b4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.di+0x000001b4u)),4275539u); flags=s.arithmetic_flags;
  }
  L00413d53: { // 0x413d53: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  L00413d59: { // 0x413d59: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00413d5a: { // 0x413d5a: 8b88a8050000 MOV ECX,dword ptr [EAX + 0x5a8]
    s.cx = m.r32((s.ax+0x000005a8u));
  }
  L00413d60: { // 0x413d60: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L00413d63: { // 0x413d63: 7506 JNZ 0x00413d6b
    if(integer::condition("JNZ",flags)) goto L00413d6b;
  }
  L00413d65: { // 0x413d65: 8b88ac050000 MOV ECX,dword ptr [EAX + 0x5ac]
    s.cx = m.r32((s.ax+0x000005acu));
  }
  L00413d6b: { // 0x413d6b: 898e54020000 MOV dword ptr [ESI + 0x254],ECX
    m.w32((s.si+0x00000254u), s.cx);
  }
  L00413d71: { // 0x413d71: 8b80a0000000 MOV EAX,dword ptr [EAX + 0xa0]
    s.ax = m.r32((s.ax+0x000000a0u));
  }
  L00413d77: { // 0x413d77: 89466c MOV dword ptr [ESI + 0x6c],EAX
    m.w32((s.si+0x0000006cu), s.ax);
  }
  L00413d7a: { // 0x413d7a: 894670 MOV dword ptr [ESI + 0x70],EAX
    m.w32((s.si+0x00000070u), s.ax);
  }
  L00413d7d: { // 0x413d7d: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L00413d83: { // 0x413d83: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00413d85: { // 0x413d85: 7406 JZ 0x00413d8d
    if(integer::condition("JZ",flags)) goto L00413d8d;
  }
  L00413d87: { // 0x413d87: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00413d88: { // 0x413d88: e803610d00 CALL 0x004e9e90
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e9e90u,4275597u); flags=s.arithmetic_flags;
  }
  L00413d8d: { // 0x413d8d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00413d8e: { // 0x413d8e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00413d8f: { // 0x413d8f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00413d90: { // 0x413d90: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
