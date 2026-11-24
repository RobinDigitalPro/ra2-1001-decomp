#include "recovered/recovery_b610_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b610 {
namespace {
void f_000cde40(Memory&,State&,Frame&,const Operations&);
void f_0000cdf0(Memory&,State&,Frame&,const Operations&);
void f_00005d50(Memory&,State&,Frame&,const Operations&);
void f_00005c10(Memory&,State&,Frame&,const Operations&);
void f_0000ff90(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000cde40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004cde40: { // 0x4cde40: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L004cde43: { // 0x4cde43: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004cde45: { // 0x4cde45: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004cde46: { // 0x4cde46: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L004cde48: { // 0x4cde48: 7e15 JLE 0x4cde5f
    if(integer::condition("JLE",flags)) goto L004cde5f;
  }
  L004cde4a: { // 0x4cde4a: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L004cde4e: { // 0x4cde4e: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L004cde51: { // 0x4cde51: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L004cde53: { // 0x4cde53: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L004cde55: { // 0x4cde55: 740b JZ 0x4cde62
    if(integer::condition("JZ",flags)) goto L004cde62;
  }
  L004cde57: { // 0x4cde57: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004cde58: { // 0x4cde58: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L004cde5b: { // 0x4cde5b: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004cde5d: { // 0x4cde5d: 7cf4 JL 0x4cde53
    if(integer::condition("JL",flags)) goto L004cde53;
  }
  L004cde5f: { // 0x4cde5f: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L004cde62: { // 0x4cde62: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004cde63: { // 0x4cde63: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0000cdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040cdf0: { // 0x40cdf0: 8b5110 MOV EDX, dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  L0040cdf3: { // 0x40cdf3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0040cdf5: { // 0x40cdf5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0040cdf6: { // 0x40cdf6: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0040cdf8: { // 0x40cdf8: 7e15 JLE 0x40ce0f
    if(integer::condition("JLE",flags)) goto L0040ce0f;
  }
  L0040cdfa: { // 0x40cdfa: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L0040cdfe: { // 0x40cdfe: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L0040ce01: { // 0x40ce01: 8b36 MOV ESI, dword ptr [ESI]
    s.si = m.r32((s.si));
  }
  L0040ce03: { // 0x40ce03: 3931 CMP dword ptr [ECX], ESI
    (void)integer::sub(m.r32((s.cx)),s.si,32,flags);
  }
  L0040ce05: { // 0x40ce05: 740b JZ 0x40ce12
    if(integer::condition("JZ",flags)) goto L0040ce12;
  }
  L0040ce07: { // 0x40ce07: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0040ce08: { // 0x40ce08: 83c104 ADD ECX, 4
    s.cx = integer::add(s.cx,4u,32,flags);
  }
  L0040ce0b: { // 0x40ce0b: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0040ce0d: { // 0x40ce0d: 7cf4 JL 0x40ce03
    if(integer::condition("JL",flags)) goto L0040ce03;
  }
  L0040ce0f: { // 0x40ce0f: 83c8ff OR EAX, 0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0040ce12: { // 0x40ce12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0040ce13: { // 0x40ce13: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00005d50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405d50: { // 0x405d50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00405d51: { // 0x405d51: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00405d53: { // 0x405d53: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00405d54: { // 0x405d54: 8b0df8928100 MOV ECX,dword ptr [0x008192f8]
    s.cx = m.r32((0x008192f8u));
  }
  L00405d5a: { // 0x405d5a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00405d5c: { // 0x405d5c: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405d5e: { // 0x405d5e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00405d5f: { // 0x405d5f: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00405d63: { // 0x405d63: 0f8418010000 JZ 0x00405e81
    if(integer::condition("JZ",flags)) goto L00405e81;
  }
  L00405d69: { // 0x405d69: 81780cec928100 CMP dword ptr [EAX + 0xc],0x8192ec
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),0x008192ecu,32,flags);
  }
  L00405d70: { // 0x405d70: 0f850b010000 JNZ 0x00405e81
    if(integer::condition("JNZ",flags)) goto L00405e81;
  }
  L00405d76: { // 0x405d76: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00405d78: { // 0x405d78: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00405d7a: { // 0x405d7a: 0f8401010000 JZ 0x00405e81
    if(integer::condition("JZ",flags)) goto L00405e81;
  }
  L00405d80: { // 0x405d80: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00405d83: { // 0x405d83: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L00405d86: { // 0x405d86: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00405d88: { // 0x405d88: 0f85f1000000 JNZ 0x00405e7f
    if(integer::condition("JNZ",flags)) goto L00405e7f;
  }
  L00405d8e: { // 0x405d8e: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00405d91: { // 0x405d91: 8b8e38010000 MOV ECX,dword ptr [ESI + 0x138]
    s.cx = m.r32((s.si+0x00000138u));
  }
  L00405d97: { // 0x405d97: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00405d99: { // 0x405d99: 0f85e0000000 JNZ 0x00405e7f
    if(integer::condition("JNZ",flags)) goto L00405e7f;
  }
  L00405d9f: { // 0x405d9f: f6461801 TEST byte ptr [ESI + 0x18],0x1
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000001u),8,flags);
  }
  L00405da3: { // 0x405da3: 0f85d6000000 JNZ 0x00405e7f
    if(integer::condition("JNZ",flags)) goto L00405e7f;
  }
  L00405da9: { // 0x405da9: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405daf: { // 0x405daf: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405db1: { // 0x405db1: 747c JZ 0x00405e2f
    if(integer::condition("JZ",flags)) goto L00405e2f;
  }
  L00405db3: { // 0x405db3: 3bb1c0000000 CMP ESI,dword ptr [ECX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.cx+0x000000c0u)),32,flags);
  }
  L00405db9: { // 0x405db9: 7574 JNZ 0x00405e2f
    if(integer::condition("JNZ",flags)) goto L00405e2f;
  }
  L00405dbb: { // 0x405dbb: f6461802 TEST byte ptr [ESI + 0x18],0x2
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000002u),8,flags);
  }
  L00405dbf: { // 0x405dbf: 7405 JZ 0x00405dc6
    if(integer::condition("JZ",flags)) goto L00405dc6;
  }
  L00405dc1: { // 0x405dc1: e8eac7ffff CALL 0x004025b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004025b0u,4218310u); flags=s.arithmetic_flags;
  }
  L00405dc6: { // 0x405dc6: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405dcc: { // 0x405dcc: e81fc9ffff CALL 0x004026f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026f0u,4218321u); flags=s.arithmetic_flags;
  }
  L00405dd1: { // 0x405dd1: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405dd7: { // 0x405dd7: 89a8c0000000 MOV dword ptr [EAX + 0xc0],EBP
    m.w32((s.ax+0x000000c0u), s.bp);
  }
  L00405ddd: { // 0x405ddd: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405de3: { // 0x405de3: 89a9bc000000 MOV dword ptr [ECX + 0xbc],EBP
    m.w32((s.cx+0x000000bcu), s.bp);
  }
  L00405de9: { // 0x405de9: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00405def: { // 0x405def: 89aab4000000 MOV dword ptr [EDX + 0xb4],EBP
    m.w32((s.dx+0x000000b4u), s.bp);
  }
  L00405df5: { // 0x405df5: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405dfb: { // 0x405dfb: 89a8b8000000 MOV dword ptr [EAX + 0xb8],EBP
    m.w32((s.ax+0x000000b8u), s.bp);
  }
  L00405e01: { // 0x405e01: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405e07: { // 0x405e07: 89a990000000 MOV dword ptr [ECX + 0x90],EBP
    m.w32((s.cx+0x00000090u), s.bp);
  }
  L00405e0d: { // 0x405e0d: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00405e13: { // 0x405e13: 89aa98000000 MOV dword ptr [EDX + 0x98],EBP
    m.w32((s.dx+0x00000098u), s.bp);
  }
  L00405e19: { // 0x405e19: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405e1f: { // 0x405e1f: 89a89c000000 MOV dword ptr [EAX + 0x9c],EBP
    m.w32((s.ax+0x0000009cu), s.bp);
  }
  L00405e25: { // 0x405e25: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00405e29: { // 0x405e29: 89aeb0000000 MOV dword ptr [ESI + 0xb0],EBP
    m.w32((s.si+0x000000b0u), s.bp);
  }
  L00405e2f: { // 0x405e2f: 8b8ea8000000 MOV ECX,dword ptr [ESI + 0xa8]
    s.cx = m.r32((s.si+0x000000a8u));
  }
  L00405e35: { // 0x405e35: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00405e36: { // 0x405e36: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00405e38: { // 0x405e38: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405e3a: { // 0x405e3a: 7e20 JLE 0x00405e5c
    if(integer::condition("JLE",flags)) goto L00405e5c;
  }
  L00405e3c: { // 0x405e3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00405e3d: { // 0x405e3d: 8d7e28 LEA EDI,[ESI + 0x28]
    s.di = (s.si+0x00000028u);
  }
  L00405e40: { // 0x405e40: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00405e42: { // 0x405e42: e849c1ffff CALL 0x00401f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00401f90u,4218439u); flags=s.arithmetic_flags;
  }
  L00405e47: { // 0x405e47: 892f MOV dword ptr [EDI],EBP
    m.w32((s.di), s.bp);
  }
  L00405e49: { // 0x405e49: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00405e4f: { // 0x405e4f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00405e50: { // 0x405e50: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00405e53: { // 0x405e53: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00405e55: { // 0x405e55: 7ce9 JL 0x00405e40
    if(integer::condition("JL",flags)) goto L00405e40;
  }
  L00405e57: { // 0x405e57: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00405e5b: { // 0x405e5b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00405e5c: { // 0x405e5c: 89aea8000000 MOV dword ptr [ESI + 0xa8],EBP
    m.w32((s.si+0x000000a8u), s.bp);
  }
  L00405e62: { // 0x405e62: c7461c04000000 MOV dword ptr [ESI + 0x1c],0x4
    m.w32((s.si+0x0000001cu), 0x00000004u);
  }
  L00405e69: { // 0x405e69: 89ae38010000 MOV dword ptr [ESI + 0x138],EBP
    m.w32((s.si+0x00000138u), s.bp);
  }
  L00405e6f: { // 0x405e6f: 89ae78020000 MOV dword ptr [ESI + 0x278],EBP
    m.w32((s.si+0x00000278u), s.bp);
  }
  L00405e75: { // 0x405e75: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L00405e78: { // 0x405e78: 83c901 OR ECX,0x1
    s.cx = integer::logical((s.cx)|(0x00000001u),32,flags);
  }
  L00405e7b: { // 0x405e7b: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  L00405e7e: { // 0x405e7e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00405e7f: { // 0x405e7f: 8928 MOV dword ptr [EAX],EBP
    m.w32((s.ax), s.bp);
  }
  L00405e81: { // 0x405e81: 896808 MOV dword ptr [EAX + 0x8],EBP
    m.w32((s.ax+0x00000008u), s.bp);
  }
  L00405e84: { // 0x405e84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00405e85: { // 0x405e85: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00405e86: { // 0x405e86: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00405e87: { // 0x405e87: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00005c10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405c10: { // 0x405c10: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00405c11: { // 0x405c11: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00405c13: { // 0x405c13: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00405c14: { // 0x405c14: 8b0df8928100 MOV ECX,dword ptr [0x008192f8]
    s.cx = m.r32((0x008192f8u));
  }
  L00405c1a: { // 0x405c1a: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00405c1c: { // 0x405c1c: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405c1e: { // 0x405c1e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00405c1f: { // 0x405c1f: 89442408 MOV dword ptr [ESP + 0x8],EAX
    m.w32((f.sp+0x00000008u), s.ax);
  }
  L00405c23: { // 0x405c23: 0f8418010000 JZ 0x00405d41
    if(integer::condition("JZ",flags)) goto L00405d41;
  }
  L00405c29: { // 0x405c29: 81780cec928100 CMP dword ptr [EAX + 0xc],0x8192ec
    (void)integer::sub(m.r32((s.ax+0x0000000cu)),0x008192ecu,32,flags);
  }
  L00405c30: { // 0x405c30: 0f850b010000 JNZ 0x00405d41
    if(integer::condition("JNZ",flags)) goto L00405d41;
  }
  L00405c36: { // 0x405c36: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00405c38: { // 0x405c38: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  L00405c3a: { // 0x405c3a: 0f8401010000 JZ 0x00405d41
    if(integer::condition("JZ",flags)) goto L00405d41;
  }
  L00405c40: { // 0x405c40: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00405c43: { // 0x405c43: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L00405c46: { // 0x405c46: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00405c48: { // 0x405c48: 0f85f1000000 JNZ 0x00405d3f
    if(integer::condition("JNZ",flags)) goto L00405d3f;
  }
  L00405c4e: { // 0x405c4e: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00405c51: { // 0x405c51: 8b8e38010000 MOV ECX,dword ptr [ESI + 0x138]
    s.cx = m.r32((s.si+0x00000138u));
  }
  L00405c57: { // 0x405c57: 3bd1 CMP EDX,ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00405c59: { // 0x405c59: 0f85e0000000 JNZ 0x00405d3f
    if(integer::condition("JNZ",flags)) goto L00405d3f;
  }
  L00405c5f: { // 0x405c5f: f6461801 TEST byte ptr [ESI + 0x18],0x1
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000001u),8,flags);
  }
  L00405c63: { // 0x405c63: 0f85d6000000 JNZ 0x00405d3f
    if(integer::condition("JNZ",flags)) goto L00405d3f;
  }
  L00405c69: { // 0x405c69: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405c6f: { // 0x405c6f: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405c71: { // 0x405c71: 747c JZ 0x00405cef
    if(integer::condition("JZ",flags)) goto L00405cef;
  }
  L00405c73: { // 0x405c73: 3bb1c0000000 CMP ESI,dword ptr [ECX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.cx+0x000000c0u)),32,flags);
  }
  L00405c79: { // 0x405c79: 7574 JNZ 0x00405cef
    if(integer::condition("JNZ",flags)) goto L00405cef;
  }
  L00405c7b: { // 0x405c7b: f6461802 TEST byte ptr [ESI + 0x18],0x2
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000002u),8,flags);
  }
  L00405c7f: { // 0x405c7f: 7405 JZ 0x00405c86
    if(integer::condition("JZ",flags)) goto L00405c86;
  }
  L00405c81: { // 0x405c81: e82ac9ffff CALL 0x004025b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004025b0u,4217990u); flags=s.arithmetic_flags;
  }
  L00405c86: { // 0x405c86: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405c8c: { // 0x405c8c: e85fcaffff CALL 0x004026f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026f0u,4218001u); flags=s.arithmetic_flags;
  }
  L00405c91: { // 0x405c91: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405c97: { // 0x405c97: 89a8c0000000 MOV dword ptr [EAX + 0xc0],EBP
    m.w32((s.ax+0x000000c0u), s.bp);
  }
  L00405c9d: { // 0x405c9d: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405ca3: { // 0x405ca3: 89a9bc000000 MOV dword ptr [ECX + 0xbc],EBP
    m.w32((s.cx+0x000000bcu), s.bp);
  }
  L00405ca9: { // 0x405ca9: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00405caf: { // 0x405caf: 89aab4000000 MOV dword ptr [EDX + 0xb4],EBP
    m.w32((s.dx+0x000000b4u), s.bp);
  }
  L00405cb5: { // 0x405cb5: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405cbb: { // 0x405cbb: 89a8b8000000 MOV dword ptr [EAX + 0xb8],EBP
    m.w32((s.ax+0x000000b8u), s.bp);
  }
  L00405cc1: { // 0x405cc1: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00405cc7: { // 0x405cc7: 89a990000000 MOV dword ptr [ECX + 0x90],EBP
    m.w32((s.cx+0x00000090u), s.bp);
  }
  L00405ccd: { // 0x405ccd: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00405cd3: { // 0x405cd3: 89aa98000000 MOV dword ptr [EDX + 0x98],EBP
    m.w32((s.dx+0x00000098u), s.bp);
  }
  L00405cd9: { // 0x405cd9: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00405cdf: { // 0x405cdf: 89a89c000000 MOV dword ptr [EAX + 0x9c],EBP
    m.w32((s.ax+0x0000009cu), s.bp);
  }
  L00405ce5: { // 0x405ce5: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00405ce9: { // 0x405ce9: 89aeb0000000 MOV dword ptr [ESI + 0xb0],EBP
    m.w32((s.si+0x000000b0u), s.bp);
  }
  L00405cef: { // 0x405cef: 8b8ea8000000 MOV ECX,dword ptr [ESI + 0xa8]
    s.cx = m.r32((s.si+0x000000a8u));
  }
  L00405cf5: { // 0x405cf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00405cf6: { // 0x405cf6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00405cf8: { // 0x405cf8: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00405cfa: { // 0x405cfa: 7e20 JLE 0x00405d1c
    if(integer::condition("JLE",flags)) goto L00405d1c;
  }
  L00405cfc: { // 0x405cfc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00405cfd: { // 0x405cfd: 8d7e28 LEA EDI,[ESI + 0x28]
    s.di = (s.si+0x00000028u);
  }
  L00405d00: { // 0x405d00: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00405d02: { // 0x405d02: e889c2ffff CALL 0x00401f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00401f90u,4218119u); flags=s.arithmetic_flags;
  }
  L00405d07: { // 0x405d07: 892f MOV dword ptr [EDI],EBP
    m.w32((s.di), s.bp);
  }
  L00405d09: { // 0x405d09: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00405d0f: { // 0x405d0f: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00405d10: { // 0x405d10: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00405d13: { // 0x405d13: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00405d15: { // 0x405d15: 7ce9 JL 0x00405d00
    if(integer::condition("JL",flags)) goto L00405d00;
  }
  L00405d17: { // 0x405d17: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00405d1b: { // 0x405d1b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00405d1c: { // 0x405d1c: 89aea8000000 MOV dword ptr [ESI + 0xa8],EBP
    m.w32((s.si+0x000000a8u), s.bp);
  }
  L00405d22: { // 0x405d22: c7461c04000000 MOV dword ptr [ESI + 0x1c],0x4
    m.w32((s.si+0x0000001cu), 0x00000004u);
  }
  L00405d29: { // 0x405d29: 89ae38010000 MOV dword ptr [ESI + 0x138],EBP
    m.w32((s.si+0x00000138u), s.bp);
  }
  L00405d2f: { // 0x405d2f: 89ae78020000 MOV dword ptr [ESI + 0x278],EBP
    m.w32((s.si+0x00000278u), s.bp);
  }
  L00405d35: { // 0x405d35: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L00405d38: { // 0x405d38: 83c901 OR ECX,0x1
    s.cx = integer::logical((s.cx)|(0x00000001u),32,flags);
  }
  L00405d3b: { // 0x405d3b: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  L00405d3e: { // 0x405d3e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00405d3f: { // 0x405d3f: 8928 MOV dword ptr [EAX],EBP
    m.w32((s.ax), s.bp);
  }
  L00405d41: { // 0x405d41: 896808 MOV dword ptr [EAX + 0x8],EBP
    m.w32((s.ax+0x00000008u), s.bp);
  }
  L00405d44: { // 0x405d44: 89680c MOV dword ptr [EAX + 0xc],EBP
    m.w32((s.ax+0x0000000cu), s.bp);
  }
  L00405d47: { // 0x405d47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00405d48: { // 0x405d48: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00405d49: { // 0x405d49: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00405d4a: { // 0x405d4a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0000ff90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff90: { // 0x40ff90: c701d85d7800 MOV dword ptr [ECX],0x785dd8
    m.w32((s.cx), 0x00785dd8u);
  }
  L0040ff96: { // 0x40ff96: c74104bc5d7800 MOV dword ptr [ECX + 0x4],0x785dbc
    m.w32((s.cx+0x00000004u), 0x00785dbcu);
  }
  L0040ff9d: { // 0x40ff9d: c74108b45d7800 MOV dword ptr [ECX + 0x8],0x785db4
    m.w32((s.cx+0x00000008u), 0x00785db4u);
  }
  L0040ffa4: { // 0x40ffa4: c7410cac5d7800 MOV dword ptr [ECX + 0xc],0x785dac
    m.w32((s.cx+0x0000000cu), 0x00785dacu);
  }
  L0040ffab: { // 0x40ffab: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5037632u:f_000cde40(m,s,child,{});break;
case 4247024u:f_0000cdf0(m,s,child,{});break;
case 4218192u:f_00005d50(m,s,child,{});break;
case 4217872u:f_00005c10(m,s,child,{});break;
case 4259728u:f_0000ff90(m,s,child,{});break;
default:throw std::domain_error("recovery610 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005cabc0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cabc0: { // 0x5cabc0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005cabc1: { // 0x5cabc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cabc2: { // 0x5cabc2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cabc4: { // 0x5cabc4: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L005cabc8: { // 0x5cabc8: b9e087aa00 MOV ECX,0xaa87e0
    s.cx = 0x00aa87e0u;
  }
  L005cabcd: { // 0x5cabcd: c70658247900 MOV dword ptr [ESI],0x792458
    m.w32((s.si), 0x00792458u);
  }
  L005cabd3: { // 0x5cabd3: c746043c247900 MOV dword ptr [ESI + 0x4],0x79243c
    m.w32((s.si+0x00000004u), 0x0079243cu);
  }
  L005cabda: { // 0x5cabda: c7460834247900 MOV dword ptr [ESI + 0x8],0x792434
    m.w32((s.si+0x00000008u), 0x00792434u);
  }
  L005cabe1: { // 0x5cabe1: c7460c2c247900 MOV dword ptr [ESI + 0xc],0x79242c
    m.w32((s.si+0x0000000cu), 0x0079242cu);
  }
  L005cabe8: { // 0x5cabe8: 8b15e087aa00 MOV EDX,dword ptr [0x00aa87e0]
    s.dx = m.r32((0x00aa87e0u));
  }
  L005cabee: { // 0x5cabee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cabef: { // 0x5cabef: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L005cabf3: { // 0x5cabf3: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6073334u); flags=s.arithmetic_flags;
  }
  L005cabf6: { // 0x5cabf6: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cabf9: { // 0x5cabf9: 742d JZ 0x005cac28
    if(integer::condition("JZ",flags)) goto L005cac28;
  }
  L005cabfb: { // 0x5cabfb: 8b0df087aa00 MOV ECX,dword ptr [0x00aa87f0]
    s.cx = m.r32((0x00aa87f0u));
  }
  L005cac01: { // 0x5cac01: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac03: { // 0x5cac03: 7d23 JGE 0x005cac28
    if(integer::condition("JGE",flags)) goto L005cac28;
  }
  L005cac05: { // 0x5cac05: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cac06: { // 0x5cac06: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac08: { // 0x5cac08: 890df087aa00 MOV dword ptr [0x00aa87f0],ECX
    m.w32((0x00aa87f0u), s.cx);
  }
  L005cac0e: { // 0x5cac0e: 7d18 JGE 0x005cac28
    if(integer::condition("JGE",flags)) goto L005cac28;
  }
  L005cac10: { // 0x5cac10: 8b0de487aa00 MOV ECX,dword ptr [0x00aa87e4]
    s.cx = m.r32((0x00aa87e4u));
  }
  L005cac16: { // 0x5cac16: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005cac17: { // 0x5cac17: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005cac1a: { // 0x5cac1a: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L005cac1e: { // 0x5cac1e: 8b0df087aa00 MOV ECX,dword ptr [0x00aa87f0]
    s.cx = m.r32((0x00aa87f0u));
  }
  L005cac24: { // 0x5cac24: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac26: { // 0x5cac26: 7ce8 JL 0x005cac10
    if(integer::condition("JL",flags)) goto L005cac10;
  }
  L005cac28: { // 0x5cac28: 8b15b87fa200 MOV EDX,dword ptr [0x00a27fb8]
    s.dx = m.r32((0x00a27fb8u));
  }
  L005cac2e: { // 0x5cac2e: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L005cac32: { // 0x5cac32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cac33: { // 0x5cac33: b9b87fa200 MOV ECX,0xa27fb8
    s.cx = 0x00a27fb8u;
  }
  L005cac38: { // 0x5cac38: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L005cac3c: { // 0x5cac3c: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6073407u); flags=s.arithmetic_flags;
  }
  L005cac3f: { // 0x5cac3f: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cac42: { // 0x5cac42: 742d JZ 0x005cac71
    if(integer::condition("JZ",flags)) goto L005cac71;
  }
  L005cac44: { // 0x5cac44: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005cac4a: { // 0x5cac4a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac4c: { // 0x5cac4c: 7d23 JGE 0x005cac71
    if(integer::condition("JGE",flags)) goto L005cac71;
  }
  L005cac4e: { // 0x5cac4e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cac4f: { // 0x5cac4f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac51: { // 0x5cac51: 890dc87fa200 MOV dword ptr [0x00a27fc8],ECX
    m.w32((0x00a27fc8u), s.cx);
  }
  L005cac57: { // 0x5cac57: 7d18 JGE 0x005cac71
    if(integer::condition("JGE",flags)) goto L005cac71;
  }
  L005cac59: { // 0x5cac59: 8b0dbc7fa200 MOV ECX,dword ptr [0x00a27fbc]
    s.cx = m.r32((0x00a27fbcu));
  }
  L005cac5f: { // 0x5cac5f: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005cac60: { // 0x5cac60: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005cac63: { // 0x5cac63: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L005cac67: { // 0x5cac67: 8b0dc87fa200 MOV ECX,dword ptr [0x00a27fc8]
    s.cx = m.r32((0x00a27fc8u));
  }
  L005cac6d: { // 0x5cac6d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac6f: { // 0x5cac6f: 7ce8 JL 0x005cac59
    if(integer::condition("JL",flags)) goto L005cac59;
  }
  L005cac71: { // 0x5cac71: 8b156888aa00 MOV EDX,dword ptr [0x00aa8868]
    s.dx = m.r32((0x00aa8868u));
  }
  L005cac77: { // 0x5cac77: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L005cac7b: { // 0x5cac7b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cac7c: { // 0x5cac7c: b96888aa00 MOV ECX,0xaa8868
    s.cx = 0x00aa8868u;
  }
  L005cac81: { // 0x5cac81: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L005cac85: { // 0x5cac85: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6073480u); flags=s.arithmetic_flags;
  }
  L005cac88: { // 0x5cac88: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cac8b: { // 0x5cac8b: 742d JZ 0x005cacba
    if(integer::condition("JZ",flags)) goto L005cacba;
  }
  L005cac8d: { // 0x5cac8d: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005cac93: { // 0x5cac93: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac95: { // 0x5cac95: 7d23 JGE 0x005cacba
    if(integer::condition("JGE",flags)) goto L005cacba;
  }
  L005cac97: { // 0x5cac97: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cac98: { // 0x5cac98: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cac9a: { // 0x5cac9a: 890d7888aa00 MOV dword ptr [0x00aa8878],ECX
    m.w32((0x00aa8878u), s.cx);
  }
  L005caca0: { // 0x5caca0: 7d18 JGE 0x005cacba
    if(integer::condition("JGE",flags)) goto L005cacba;
  }
  L005caca2: { // 0x5caca2: 8b0d6c88aa00 MOV ECX,dword ptr [0x00aa886c]
    s.cx = m.r32((0x00aa886cu));
  }
  L005caca8: { // 0x5caca8: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005caca9: { // 0x5caca9: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005cacac: { // 0x5cacac: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L005cacb0: { // 0x5cacb0: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L005cacb6: { // 0x5cacb6: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cacb8: { // 0x5cacb8: 7ce8 JL 0x005caca2
    if(integer::condition("JL",flags)) goto L005caca2;
  }
  L005cacba: { // 0x5cacba: 8b15b887aa00 MOV EDX,dword ptr [0x00aa87b8]
    s.dx = m.r32((0x00aa87b8u));
  }
  L005cacc0: { // 0x5cacc0: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L005cacc4: { // 0x5cacc4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cacc5: { // 0x5cacc5: b9b887aa00 MOV ECX,0xaa87b8
    s.cx = 0x00aa87b8u;
  }
  L005cacca: { // 0x5cacca: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L005cacce: { // 0x5cacce: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6073553u); flags=s.arithmetic_flags;
  }
  L005cacd1: { // 0x5cacd1: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cacd4: { // 0x5cacd4: 742d JZ 0x005cad03
    if(integer::condition("JZ",flags)) goto L005cad03;
  }
  L005cacd6: { // 0x5cacd6: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005cacdc: { // 0x5cacdc: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cacde: { // 0x5cacde: 7d23 JGE 0x005cad03
    if(integer::condition("JGE",flags)) goto L005cad03;
  }
  L005cace0: { // 0x5cace0: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cace1: { // 0x5cace1: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cace3: { // 0x5cace3: 890dc887aa00 MOV dword ptr [0x00aa87c8],ECX
    m.w32((0x00aa87c8u), s.cx);
  }
  L005cace9: { // 0x5cace9: 7d18 JGE 0x005cad03
    if(integer::condition("JGE",flags)) goto L005cad03;
  }
  L005caceb: { // 0x5caceb: 8b0dbc87aa00 MOV ECX,dword ptr [0x00aa87bc]
    s.cx = m.r32((0x00aa87bcu));
  }
  L005cacf1: { // 0x5cacf1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005cacf2: { // 0x5cacf2: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005cacf5: { // 0x5cacf5: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L005cacf9: { // 0x5cacf9: 8b0dc887aa00 MOV ECX,dword ptr [0x00aa87c8]
    s.cx = m.r32((0x00aa87c8u));
  }
  L005cacff: { // 0x5cacff: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cad01: { // 0x5cad01: 7ce8 JL 0x005caceb
    if(integer::condition("JL",flags)) goto L005caceb;
  }
  L005cad03: { // 0x5cad03: 8b156087aa00 MOV EDX,dword ptr [0x00aa8760]
    s.dx = m.r32((0x00aa8760u));
  }
  L005cad09: { // 0x5cad09: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L005cad0d: { // 0x5cad0d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cad0e: { // 0x5cad0e: b96087aa00 MOV ECX,0xaa8760
    s.cx = 0x00aa8760u;
  }
  L005cad13: { // 0x5cad13: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L005cad17: { // 0x5cad17: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6073626u); flags=s.arithmetic_flags;
  }
  L005cad1a: { // 0x5cad1a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005cad1d: { // 0x5cad1d: 742d JZ 0x005cad4c
    if(integer::condition("JZ",flags)) goto L005cad4c;
  }
  L005cad1f: { // 0x5cad1f: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cad25: { // 0x5cad25: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cad27: { // 0x5cad27: 7d23 JGE 0x005cad4c
    if(integer::condition("JGE",flags)) goto L005cad4c;
  }
  L005cad29: { // 0x5cad29: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005cad2a: { // 0x5cad2a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cad2c: { // 0x5cad2c: 890d7087aa00 MOV dword ptr [0x00aa8770],ECX
    m.w32((0x00aa8770u), s.cx);
  }
  L005cad32: { // 0x5cad32: 7d18 JGE 0x005cad4c
    if(integer::condition("JGE",flags)) goto L005cad4c;
  }
  L005cad34: { // 0x5cad34: 8b0d6487aa00 MOV ECX,dword ptr [0x00aa8764]
    s.cx = m.r32((0x00aa8764u));
  }
  L005cad3a: { // 0x5cad3a: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005cad3b: { // 0x5cad3b: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005cad3e: { // 0x5cad3e: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L005cad42: { // 0x5cad42: 8b0d7087aa00 MOV ECX,dword ptr [0x00aa8770]
    s.cx = m.r32((0x00aa8770u));
  }
  L005cad48: { // 0x5cad48: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005cad4a: { // 0x5cad4a: 7ce8 JL 0x005cad34
    if(integer::condition("JL",flags)) goto L005cad34;
  }
  L005cad4c: { // 0x5cad4c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L005cad4d: { // 0x5cad4d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005cad4e: { // 0x5cad4e: 8d7e3c LEA EDI,[ESI + 0x3c]
    s.di = (s.si+0x0000003cu);
  }
  L005cad51: { // 0x5cad51: c7463000000000 MOV dword ptr [ESI + 0x30],0x0
    m.w32((s.si+0x00000030u), 0x00000000u);
  }
  L005cad58: { // 0x5cad58: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cad5a: { // 0x5cad5a: c6467d00 MOV byte ptr [ESI + 0x7d],0x0
    m.w8((s.si+0x0000007du), 0x00000000u);
  }
  L005cad5e: { // 0x5cad5e: e8edafe3ff CALL 0x00405d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405d50u,6073699u); flags=s.arithmetic_flags;
  }
  L005cad63: { // 0x5cad63: 8d6e50 LEA EBP,[ESI + 0x50]
    s.bp = (s.si+0x00000050u);
  }
  L005cad66: { // 0x5cad66: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005cad68: { // 0x5cad68: e8e3afe3ff CALL 0x00405d50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405d50u,6073709u); flags=s.arithmetic_flags;
  }
  L005cad6d: { // 0x5cad6d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L005cad6f: { // 0x5cad6f: e89caee3ff CALL 0x00405c10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405c10u,6073716u); flags=s.arithmetic_flags;
  }
  L005cad74: { // 0x5cad74: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L005cad76: { // 0x5cad76: e895aee3ff CALL 0x00405c10
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405c10u,6073723u); flags=s.arithmetic_flags;
  }
  L005cad7b: { // 0x5cad7b: 8b8e94000000 MOV ECX,dword ptr [ESI + 0x94]
    s.cx = m.r32((s.si+0x00000094u));
  }
  L005cad81: { // 0x5cad81: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005cad82: { // 0x5cad82: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005cad84: { // 0x5cad84: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005cad85: { // 0x5cad85: 740f JZ 0x005cad96
    if(integer::condition("JZ",flags)) goto L005cad96;
  }
  L005cad87: { // 0x5cad87: e844c9f6ff CALL 0x005376d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005376d0u,6073740u); flags=s.arithmetic_flags;
  }
  L005cad8c: { // 0x5cad8c: c7869400000000000000 MOV dword ptr [ESI + 0x94],0x0
    m.w32((s.si+0x00000094u), 0x00000000u);
  }
  L005cad96: { // 0x5cad96: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L005cad98: { // 0x5cad98: e8f351e4ff CALL 0x0040ff90
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff90u,6073757u); flags=s.arithmetic_flags;
  }
  L005cad9d: { // 0x5cad9d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cad9e: { // 0x5cad9e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005cad9f: { // 0x5cad9f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
