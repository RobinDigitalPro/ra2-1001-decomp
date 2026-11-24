#include "recovered/recovery_b586_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b586 {
namespace {
void f_00208da0(Memory&,State&,Frame&,const Operations&);
void f_00208eb0(Memory&,State&,Frame&,const Operations&);
void f_0020a150(Memory&,State&,Frame&,const Operations&);
void f_00298010(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0020f5f0(Memory&,State&,Frame&,const Operations&);
void f_002c69a0(Memory&,State&,Frame&,const Operations&);
void f_0035eff0(Memory&,State&,Frame&,const Operations&);
void f_0035f000(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00208da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00608da0: { // 0x608da0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00608da3: { // 0x608da3: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00608da6: { // 0x608da6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00608da8: { // 0x608da8: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00608dab: { // 0x608dab: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  L00608daf: { // 0x608daf: e8acf7ffff CALL 0x00608560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608560u,6327732u); flags=s.arithmetic_flags;
  }
  L00608db4: { // 0x608db4: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00608db6: { // 0x608db6: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L00608dba: { // 0x608dba: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00608dbd: { // 0x608dbd: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00608dc1: { // 0x608dc1: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L00608dc5: { // 0x608dc5: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00608dc8: { // 0x608dc8: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  L00608dcc: { // 0x608dcc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00608dcd: { // 0x608dcd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00608dce: { // 0x608dce: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00608dd4: { // 0x608dd4: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00608dd8: { // 0x608dd8: e833f20800 CALL 0x00698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,6327773u); flags=s.arithmetic_flags;
  }
  L00608ddd: { // 0x608ddd: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L00608de1: { // 0x608de1: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  L00608de7: { // 0x608de7: a174198200 MOV EAX,[0x00821974]
    s.ax = m.r32((0x00821974u));
  }
  L00608dec: { // 0x608dec: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00608dee: { // 0x608dee: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00608df2: { // 0x608df2: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00608df4: { // 0x608df4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00608df8: { // 0x608df8: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L00608dfa: { // 0x608dfa: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00608dfd: { // 0x608dfd: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00608e00: { // 0x608e00: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00208eb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00608eb0: { // 0x608eb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00608eb3: { // 0x608eb3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00608eb4: { // 0x608eb4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00608eb6: { // 0x608eb6: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00608eb8: { // 0x608eb8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00608eb9: { // 0x608eb9: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L00608ebd: { // 0x608ebd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00608ebe: { // 0x608ebe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00608ec0: { // 0x608ec0: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00608ec4: { // 0x608ec4: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00608ec6: { // 0x608ec6: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00608ec8: { // 0x608ec8: 897c2408 MOV dword ptr [ESP + 0x8],EDI
    m.w32((f.sp+0x00000008u), s.di);
  }
  L00608ecc: { // 0x608ecc: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00608ece: { // 0x608ece: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00608ed0: { // 0x608ed0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00608ed2: { // 0x608ed2: 8938 MOV dword ptr [EAX],EDI
    m.w32((s.ax), s.di);
  }
  L00608ed4: { // 0x608ed4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00608ed5: { // 0x608ed5: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L00608ed8: { // 0x608ed8: 897008 MOV dword ptr [EAX + 0x8],ESI
    m.w32((s.ax+0x00000008u), s.si);
  }
  L00608edb: { // 0x608edb: 89700c MOV dword ptr [EAX + 0xc],ESI
    m.w32((s.ax+0x0000000cu), s.si);
  }
  L00608ede: { // 0x608ede: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00608edf: { // 0x608edf: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00608ee2: { // 0x608ee2: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0020a150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060a150: { // 0x60a150: 8d0412 LEA EAX,[EDX + EDX*0x1]
    s.ax = (s.dx+(s.dx * 0x00000001u));
  }
  L0060a153: { // 0x60a153: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060a154: { // 0x60a154: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060a156: { // 0x60a156: 7d27 JGE 0x0060a17f
    if(integer::condition("JGE",flags)) goto L0060a17f;
  }
  L0060a158: { // 0x60a158: 3b4108 CMP EAX,dword ptr [ECX + 0x8]
    (void)integer::sub(s.ax,m.r32((s.cx+0x00000008u)),32,flags);
  }
  L0060a15b: { // 0x60a15b: 7d05 JGE 0x0060a162
    if(integer::condition("JGE",flags)) goto L0060a162;
  }
  L0060a15d: { // 0x60a15d: 3b410c CMP EAX,dword ptr [ECX + 0xc]
    (void)integer::sub(s.ax,m.r32((s.cx+0x0000000cu)),32,flags);
  }
  L0060a160: { // 0x60a160: 7c1d JL 0x0060a17f
    if(integer::condition("JL",flags)) goto L0060a17f;
  }
  L0060a162: { // 0x60a162: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L0060a168: { // 0x60a168: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0060a16f: { // 0x60a16f: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0060a176: { // 0x60a176: c7410c00000000 MOV dword ptr [ECX + 0xc],0x0
    m.w32((s.cx+0x0000000cu), 0x00000000u);
  }
  L0060a17d: { // 0x60a17d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060a17e: { // 0x60a17e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0060a17f: { // 0x60a17f: 8b39 MOV EDI,dword ptr [ECX]
    s.di = m.r32((s.cx));
  }
  L0060a181: { // 0x60a181: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060a182: { // 0x60a182: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L0060a185: { // 0x60a185: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0060a187: { // 0x60a187: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L0060a189: { // 0x60a189: 8b7908 MOV EDI,dword ptr [ECX + 0x8]
    s.di = m.r32((s.cx+0x00000008u));
  }
  L0060a18c: { // 0x60a18c: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  L0060a18e: { // 0x60a18e: 8b510c MOV EDX,dword ptr [ECX + 0xc]
    s.dx = m.r32((s.cx+0x0000000cu));
  }
  L0060a191: { // 0x60a191: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0060a193: { // 0x60a193: 897104 MOV dword ptr [ECX + 0x4],ESI
    m.w32((s.cx+0x00000004u), s.si);
  }
  L0060a196: { // 0x60a196: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0060a198: { // 0x60a198: 897908 MOV dword ptr [ECX + 0x8],EDI
    m.w32((s.cx+0x00000008u), s.di);
  }
  L0060a19b: { // 0x60a19b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060a19c: { // 0x60a19c: 89510c MOV dword ptr [ECX + 0xc],EDX
    m.w32((s.cx+0x0000000cu), s.dx);
  }
  L0060a19f: { // 0x60a19f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060a1a0: { // 0x60a1a0: c3 RET
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
void f_0020f5f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060f5f0: { // 0x60f5f0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0060f5f3: { // 0x60f5f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060f5f4: { // 0x60f5f4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060f5f5: { // 0x60f5f5: 8b2db088a200 MOV EBP,dword ptr [0x00a288b0]
    s.bp = m.r32((0x00a288b0u));
  }
  L0060f5fb: { // 0x60f5fb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060f5fc: { // 0x60f5fc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060f5fd: { // 0x60f5fd: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0060f5ff: { // 0x60f5ff: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0060f601: { // 0x60f601: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0060f603: { // 0x60f603: 0f8e92000000 JLE 0x0060f69b
    if(integer::condition("JLE",flags)) goto L0060f69b;
  }
  L0060f609: { // 0x60f609: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L0060f60e: { // 0x60f60e: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0060f611: { // 0x60f611: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0060f613: { // 0x60f613: 744b JZ 0x0060f660
    if(integer::condition("JZ",flags)) goto L0060f660;
  }
  L0060f615: { // 0x60f615: 8a5114 MOV DL,byte ptr [ECX + 0x14]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000014u)));
  }
  L0060f618: { // 0x60f618: 80e201 AND DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags));
  }
  L0060f61b: { // 0x60f61b: 88542413 MOV byte ptr [ESP + 0x13],DL
    m.w8((f.sp+0x00000013u), (s.dx & 0xffu));
  }
  L0060f61f: { // 0x60f61f: 743f JZ 0x0060f660
    if(integer::condition("JZ",flags)) goto L0060f660;
  }
  L0060f621: { // 0x60f621: e87a730b00 CALL 0x006c69a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c69a0u,6354470u); flags=s.arithmetic_flags;
  }
  L0060f626: { // 0x60f626: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0060f628: { // 0x60f628: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060f62a: { // 0x60f62a: 7434 JZ 0x0060f660
    if(integer::condition("JZ",flags)) goto L0060f660;
  }
  L0060f62c: { // 0x60f62c: 8b8694000000 MOV EAX,dword ptr [ESI + 0x94]
    s.ax = m.r32((s.si+0x00000094u));
  }
  L0060f632: { // 0x60f632: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060f634: { // 0x60f634: 7f31 JG 0x0060f667
    if(integer::condition("JG",flags)) goto L0060f667;
  }
  L0060f636: { // 0x60f636: 742f JZ 0x0060f667
    if(integer::condition("JZ",flags)) goto L0060f667;
  }
  L0060f638: { // 0x60f638: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0060f63b: { // 0x60f63b: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  L0060f63e: { // 0x60f63e: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0060f642: { // 0x60f642: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0060f646: { // 0x60f646: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060f647: { // 0x60f647: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6354506u); flags=s.arithmetic_flags;
  }
  L0060f64a: { // 0x60f64a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060f64d: { // 0x60f64d: 7425 JZ 0x0060f674
    if(integer::condition("JZ",flags)) goto L0060f674;
  }
  L0060f64f: { // 0x60f64f: 8b7614 MOV ESI,dword ptr [ESI + 0x14]
    s.si = m.r32((s.si+0x00000014u));
  }
  L0060f652: { // 0x60f652: 8d4eff LEA ECX,[ESI + -0x1]
    s.cx = (s.si-0x00000001u);
  }
  L0060f655: { // 0x60f655: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060f657: { // 0x60f657: 7428 JZ 0x0060f681
    if(integer::condition("JZ",flags)) goto L0060f681;
  }
  L0060f659: { // 0x60f659: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L0060f65c: { // 0x60f65c: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0060f65e: { // 0x60f65e: 742e JZ 0x0060f68e
    if(integer::condition("JZ",flags)) goto L0060f68e;
  }
  L0060f660: { // 0x60f660: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0060f661: { // 0x60f661: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0060f663: { // 0x60f663: 7d36 JGE 0x0060f69b
    if(integer::condition("JGE",flags)) goto L0060f69b;
  }
  L0060f665: { // 0x60f665: eba2 JMP 0x0060f609
    goto L0060f609;
  }
  L0060f667: { // 0x60f667: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f668: { // 0x60f668: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f669: { // 0x60f669: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f66a: { // 0x60f66a: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0060f66f: { // 0x60f66f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f670: { // 0x60f670: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f673: { // 0x60f673: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0060f674: { // 0x60f674: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f675: { // 0x60f675: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f676: { // 0x60f676: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f677: { // 0x60f677: b805000000 MOV EAX,0x5
    s.ax = 0x00000005u;
  }
  L0060f67c: { // 0x60f67c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f67d: { // 0x60f67d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f680: { // 0x60f680: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0060f681: { // 0x60f681: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f682: { // 0x60f682: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f683: { // 0x60f683: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f684: { // 0x60f684: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L0060f689: { // 0x60f689: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f68a: { // 0x60f68a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f68d: { // 0x60f68d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0060f68e: { // 0x60f68e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f68f: { // 0x60f68f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f690: { // 0x60f690: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f691: { // 0x60f691: b803000000 MOV EAX,0x3
    s.ax = 0x00000003u;
  }
  L0060f696: { // 0x60f696: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f697: { // 0x60f697: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f69a: { // 0x60f69a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0060f69b: { // 0x60f69b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f69c: { // 0x60f69c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f69d: { // 0x60f69d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f69e: { // 0x60f69e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0060f6a1: { // 0x60f6a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f6a2: { // 0x60f6a2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f6a5: { // 0x60f6a5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002c69a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c69a0: { // 0x6c69a0: 8b8108040000 MOV EAX,dword ptr [ECX + 0x408]
    s.ax = m.r32((s.cx+0x00000408u));
  }
  L006c69a6: { // 0x6c69a6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0035eff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075eff0: { // 0x75eff0: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  L0075eff3: { // 0x75eff3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0035f000(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f000: { // 0x75f000: 8b4120 MOV EAX,dword ptr [ECX + 0x20]
    s.ax = m.r32((s.cx+0x00000020u));
  }
  L0075f003: { // 0x75f003: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x608560u:{Inputs i;i.cx=s.cx;i.dx=s.dx;i.fp=s.fp;s.ax=ra2::recovered::recovery_b338::fun_00608560(m,i);s.fp=i.fp;finish(m,s,child,0);break;}
case 6327712u:f_00208da0(m,s,child,{});break;
case 6327984u:f_00208eb0(m,s,child,{});break;
case 6332752u:f_0020a150(m,s,child,{});break;
case 6914064u:f_00298010(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6354416u:f_0020f5f0(m,s,child,{});break;
case 7104928u:f_002c69a0(m,s,child,{});break;
case 7729136u:f_0035eff0(m,s,child,{});break;
case 7729152u:f_0035f000(m,s,child,{});break;
default:throw std::domain_error("recovery586 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0060d7e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060d7e0: { // 0x60d7e0: a0c8e2a500 MOV AL,[0x00a5e2c8]
    s.ax = with_al(s.ax, m.r8((0x00a5e2c8u)));
  }
  L0060d7e5: { // 0x60d7e5: 83ec2c SUB ESP,0x2c
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L0060d7e8: { // 0x60d7e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060d7ea: { // 0x60d7ea: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060d7eb: { // 0x60d7eb: 0f8510010000 JNZ 0x0060d901
    if(integer::condition("JNZ",flags)) goto L0060d901;
  }
  L0060d7f1: { // 0x60d7f1: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L0060d7f7: { // 0x60d7f7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060d7f8: { // 0x60d7f8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060d7f9: { // 0x60d7f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060d7fa: { // 0x60d7fa: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0060d7fc: { // 0x60d7fc: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),6346751u); flags=s.arithmetic_flags;
  }
  L0060d7ff: { // 0x60d7ff: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L0060d805: { // 0x60d805: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0060d807: { // 0x60d807: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0060d809: { // 0x60d809: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6346764u); flags=s.arithmetic_flags;
  }
  L0060d80c: { // 0x60d80c: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0060d80e: { // 0x60d80e: a140e2a500 MOV EAX,[0x00a5e240]
    s.ax = m.r32((0x00a5e240u));
  }
  L0060d813: { // 0x60d813: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0060d815: { // 0x60d815: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0060d819: { // 0x60d819: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060d81b: { // 0x60d81b: 7e7f JLE 0x0060d89c
    if(integer::condition("JLE",flags)) goto L0060d89c;
  }
  L0060d81d: { // 0x60d81d: a134e2a500 MOV EAX,[0x00a5e234]
    s.ax = m.r32((0x00a5e234u));
  }
  L0060d822: { // 0x60d822: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0060d826: { // 0x60d826: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060d827: { // 0x60d827: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0060d82a: { // 0x60d82a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d82c: { // 0x60d82c: e86fb5ffff CALL 0x00608da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608da0u,6346801u); flags=s.arithmetic_flags;
  }
  L0060d831: { // 0x60d831: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060d834: { // 0x60d834: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0060d838: { // 0x60d838: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060d839: { // 0x60d839: ba08000000 MOV EDX,0x8
    s.dx = 0x00000008u;
  }
  L0060d83e: { // 0x60d83e: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0060d840: { // 0x60d840: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060d841: { // 0x60d841: e86ab6ffff CALL 0x00608eb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608eb0u,6346822u); flags=s.arithmetic_flags;
  }
  L0060d846: { // 0x60d846: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0060d848: { // 0x60d848: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0060d84c: { // 0x60d84c: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060d84f: { // 0x60d84f: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0060d853: { // 0x60d853: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0060d856: { // 0x60d856: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0060d85a: { // 0x60d85a: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0060d85e: { // 0x60d85e: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0060d861: { // 0x60d861: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0060d865: { // 0x60d865: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  L0060d86a: { // 0x60d86a: e8e1c8ffff CALL 0x0060a150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060a150u,6346863u); flags=s.arithmetic_flags;
  }
  L0060d86f: { // 0x60d86f: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0060d873: { // 0x60d873: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0060d875: { // 0x60d875: 7c1c JL 0x0060d893
    if(integer::condition("JL",flags)) goto L0060d893;
  }
  L0060d877: { // 0x60d877: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0060d87b: { // 0x60d87b: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0060d87d: { // 0x60d87d: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0060d87f: { // 0x60d87f: 7d12 JGE 0x0060d893
    if(integer::condition("JGE",flags)) goto L0060d893;
  }
  L0060d881: { // 0x60d881: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0060d885: { // 0x60d885: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0060d887: { // 0x60d887: 7c0a JL 0x0060d893
    if(integer::condition("JL",flags)) goto L0060d893;
  }
  L0060d889: { // 0x60d889: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0060d88d: { // 0x60d88d: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0060d88f: { // 0x60d88f: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0060d891: { // 0x60d891: 7c0b JL 0x0060d89e
    if(integer::condition("JL",flags)) goto L0060d89e;
  }
  L0060d893: { // 0x60d893: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0060d897: { // 0x60d897: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0060d898: { // 0x60d898: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0060d89a: { // 0x60d89a: 7c81 JL 0x0060d81d
    if(integer::condition("JL",flags)) goto L0060d81d;
  }
  L0060d89c: { // 0x60d89c: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0060d89e: { // 0x60d89e: a1e4e2a500 MOV EAX,[0x00a5e2e4]
    s.ax = m.r32((0x00a5e2e4u));
  }
  L0060d8a3: { // 0x60d8a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d8a4: { // 0x60d8a4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060d8a5: { // 0x60d8a5: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0060d8a7: { // 0x60d8a7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060d8a8: { // 0x60d8a8: 7457 JZ 0x0060d901
    if(integer::condition("JZ",flags)) goto L0060d901;
  }
  L0060d8aa: { // 0x60d8aa: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060d8ac: { // 0x60d8ac: c70554e2a50000000000 MOV dword ptr [0x00a5e254],0x0
    m.w32((0x00a5e254u), 0x00000000u);
  }
  L0060d8b6: { // 0x60d8b6: 7438 JZ 0x0060d8f0
    if(integer::condition("JZ",flags)) goto L0060d8f0;
  }
  L0060d8b8: { // 0x60d8b8: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0060d8bb: { // 0x60d8bb: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0060d8bd: { // 0x60d8bd: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0060d8bf: { // 0x60d8bf: 8b0de4e0a100 MOV ECX,dword ptr [0x00a1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  L0060d8c5: { // 0x60d8c5: 8b82b4010000 MOV EAX,dword ptr [EDX + 0x1b4]
    s.ax = m.r32((s.dx+0x000001b4u));
  }
  L0060d8cb: { // 0x60d8cb: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060d8cd: { // 0x60d8cd: 7519 JNZ 0x0060d8e8
    if(integer::condition("JNZ",flags)) goto L0060d8e8;
  }
  L0060d8cf: { // 0x60d8cf: a150e2a500 MOV EAX,[0x00a5e250]
    s.ax = m.r32((0x00a5e250u));
  }
  L0060d8d4: { // 0x60d8d4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060d8d6: { // 0x60d8d6: 7404 JZ 0x0060d8dc
    if(integer::condition("JZ",flags)) goto L0060d8dc;
  }
  L0060d8d8: { // 0x60d8d8: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0060d8da: { // 0x60d8da: 750c JNZ 0x0060d8e8
    if(integer::condition("JNZ",flags)) goto L0060d8e8;
  }
  L0060d8dc: { // 0x60d8dc: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d8de: { // 0x60d8de: e80d1d0000 CALL 0x0060f5f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060f5f0u,6346979u); flags=s.arithmetic_flags;
  }
  L0060d8e3: { // 0x60d8e3: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060d8e6: { // 0x60d8e6: 7408 JZ 0x0060d8f0
    if(integer::condition("JZ",flags)) goto L0060d8f0;
  }
  L0060d8e8: { // 0x60d8e8: 893554e2a500 MOV dword ptr [0x00a5e254],ESI
    m.w32((0x00a5e254u), s.si);
  }
  L0060d8ee: { // 0x60d8ee: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0060d8f0: { // 0x60d8f0: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060d8f2: { // 0x60d8f2: 8935e4e2a500 MOV dword ptr [0x00a5e2e4],ESI
    m.w32((0x00a5e2e4u), s.si);
  }
  L0060d8f8: { // 0x60d8f8: 7407 JZ 0x0060d901
    if(integer::condition("JZ",flags)) goto L0060d901;
  }
  L0060d8fa: { // 0x60d8fa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d8fc: { // 0x60d8fc: e8bfbbffff CALL 0x006094c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006094c0u,6347009u); flags=s.arithmetic_flags;
  }
  L0060d901: { // 0x60d901: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d902: { // 0x60d902: 83c42c ADD ESP,0x2c
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L0060d905: { // 0x60d905: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0060f260(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060f260: { // 0x60f260: a0fce2a500 MOV AL,[0x00a5e2fc]
    s.ax = with_al(s.ax, m.r8((0x00a5e2fcu)));
  }
  L0060f265: { // 0x60f265: 83ec3c SUB ESP,0x3c
    f.sp = integer::sub(f.sp,0x0000003cu,32,flags);
  }
  L0060f268: { // 0x60f268: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060f26a: { // 0x60f26a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060f26b: { // 0x60f26b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060f26c: { // 0x60f26c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060f26d: { // 0x60f26d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060f26e: { // 0x60f26e: 750c JNZ 0x0060f27c
    if(integer::condition("JNZ",flags)) goto L0060f27c;
  }
  L0060f270: { // 0x60f270: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f271: { // 0x60f271: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f272: { // 0x60f272: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f273: { // 0x60f273: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0060f275: { // 0x60f275: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f276: { // 0x60f276: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L0060f279: { // 0x60f279: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f27c: { // 0x60f27c: 8b0de4e2a500 MOV ECX,dword ptr [0x00a5e2e4]
    s.cx = m.r32((0x00a5e2e4u));
  }
  L0060f282: { // 0x60f282: 8b3550e2a500 MOV ESI,dword ptr [0x00a5e250]
    s.si = m.r32((0x00a5e250u));
  }
  L0060f288: { // 0x60f288: 8b5c2450 MOV EBX,dword ptr [ESP + 0x50]
    s.bx = m.r32((f.sp+0x00000050u));
  }
  L0060f28c: { // 0x60f28c: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0060f28e: { // 0x60f28e: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L0060f290: { // 0x60f290: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0060f294: { // 0x60f294: 0f859e000000 JNZ 0x0060f338
    if(integer::condition("JNZ",flags)) goto L0060f338;
  }
  L0060f29a: { // 0x60f29a: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0060f29e: { // 0x60f29e: 8b2d98e1a500 MOV EBP,dword ptr [0x00a5e198]
    s.bp = m.r32((0x00a5e198u));
  }
  L0060f2a4: { // 0x60f2a4: 3bef CMP EBP,EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  L0060f2a6: { // 0x60f2a6: 0f8e5b010000 JLE 0x0060f407
    if(integer::condition("JLE",flags)) goto L0060f407;
  }
  L0060f2ac: { // 0x60f2ac: a18ce1a500 MOV EAX,[0x00a5e18c]
    s.ax = m.r32((0x00a5e18cu));
  }
  L0060f2b1: { // 0x60f2b1: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0060f2b5: { // 0x60f2b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060f2b6: { // 0x60f2b6: 8b34b8 MOV ESI,dword ptr [EAX + EDI*0x4]
    s.si = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0060f2b9: { // 0x60f2b9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060f2bb: { // 0x60f2bb: e8e09affff CALL 0x00608da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608da0u,6353600u); flags=s.arithmetic_flags;
  }
  L0060f2c0: { // 0x60f2c0: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060f2c3: { // 0x60f2c3: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L0060f2c7: { // 0x60f2c7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060f2c8: { // 0x60f2c8: ba08000000 MOV EDX,0x8
    s.dx = 0x00000008u;
  }
  L0060f2cd: { // 0x60f2cd: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0060f2cf: { // 0x60f2cf: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060f2d0: { // 0x60f2d0: e8db9bffff CALL 0x00608eb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608eb0u,6353621u); flags=s.arithmetic_flags;
  }
  L0060f2d5: { // 0x60f2d5: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0060f2d7: { // 0x60f2d7: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0060f2db: { // 0x60f2db: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060f2de: { // 0x60f2de: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0060f2e2: { // 0x60f2e2: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0060f2e5: { // 0x60f2e5: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L0060f2e9: { // 0x60f2e9: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L0060f2ed: { // 0x60f2ed: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0060f2f0: { // 0x60f2f0: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L0060f2f4: { // 0x60f2f4: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  L0060f2f9: { // 0x60f2f9: e852aeffff CALL 0x0060a150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060a150u,6353662u); flags=s.arithmetic_flags;
  }
  L0060f2fe: { // 0x60f2fe: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L0060f302: { // 0x60f302: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0060f304: { // 0x60f304: 7c24 JL 0x0060f32a
    if(integer::condition("JL",flags)) goto L0060f32a;
  }
  L0060f306: { // 0x60f306: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0060f30a: { // 0x60f30a: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0060f30c: { // 0x60f30c: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0060f30e: { // 0x60f30e: 7d1a JGE 0x0060f32a
    if(integer::condition("JGE",flags)) goto L0060f32a;
  }
  L0060f310: { // 0x60f310: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0060f314: { // 0x60f314: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L0060f318: { // 0x60f318: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0060f31a: { // 0x60f31a: 7c0e JL 0x0060f32a
    if(integer::condition("JL",flags)) goto L0060f32a;
  }
  L0060f31c: { // 0x60f31c: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0060f320: { // 0x60f320: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0060f322: { // 0x60f322: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0060f324: { // 0x60f324: 0f8cbb000000 JL 0x0060f3e5
    if(integer::condition("JL",flags)) goto L0060f3e5;
  }
  L0060f32a: { // 0x60f32a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0060f32b: { // 0x60f32b: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0060f32d: { // 0x60f32d: 0f8dce000000 JGE 0x0060f401
    if(integer::condition("JGE",flags)) goto L0060f401;
  }
  L0060f333: { // 0x60f333: e974ffffff JMP 0x0060f2ac
    goto L0060f2ac;
  }
  L0060f338: { // 0x60f338: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0060f33c: { // 0x60f33c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060f33d: { // 0x60f33d: e85e9affff CALL 0x00608da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608da0u,6353730u); flags=s.arithmetic_flags;
  }
  L0060f342: { // 0x60f342: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0060f345: { // 0x60f345: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060f346: { // 0x60f346: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0060f34a: { // 0x60f34a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0060f34c: { // 0x60f34c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060f34d: { // 0x60f34d: ba08000000 MOV EDX,0x8
    s.dx = 0x00000008u;
  }
  L0060f352: { // 0x60f352: e8599bffff CALL 0x00608eb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608eb0u,6353751u); flags=s.arithmetic_flags;
  }
  L0060f357: { // 0x60f357: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0060f359: { // 0x60f359: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0060f35d: { // 0x60f35d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060f360: { // 0x60f360: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L0060f364: { // 0x60f364: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0060f367: { // 0x60f367: 894c2424 MOV dword ptr [ESP + 0x24],ECX
    m.w32((f.sp+0x00000024u), s.cx);
  }
  L0060f36b: { // 0x60f36b: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0060f36f: { // 0x60f36f: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0060f372: { // 0x60f372: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L0060f376: { // 0x60f376: ba04000000 MOV EDX,0x4
    s.dx = 0x00000004u;
  }
  L0060f37b: { // 0x60f37b: e8d0adffff CALL 0x0060a150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060a150u,6353792u); flags=s.arithmetic_flags;
  }
  L0060f380: { // 0x60f380: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0060f384: { // 0x60f384: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0060f386: { // 0x60f386: 0f8c0effffff JL 0x0060f29a
    if(integer::condition("JL",flags)) goto L0060f29a;
  }
  L0060f38c: { // 0x60f38c: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0060f390: { // 0x60f390: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0060f392: { // 0x60f392: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0060f394: { // 0x60f394: 0f8d00ffffff JGE 0x0060f29a
    if(integer::condition("JGE",flags)) goto L0060f29a;
  }
  L0060f39a: { // 0x60f39a: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0060f39e: { // 0x60f39e: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L0060f3a2: { // 0x60f3a2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0060f3a4: { // 0x60f3a4: 0f8cf0feffff JL 0x0060f29a
    if(integer::condition("JL",flags)) goto L0060f29a;
  }
  L0060f3aa: { // 0x60f3aa: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L0060f3ae: { // 0x60f3ae: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0060f3b0: { // 0x60f3b0: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0060f3b2: { // 0x60f3b2: 0f8de2feffff JGE 0x0060f29a
    if(integer::condition("JGE",flags)) goto L0060f29a;
  }
  L0060f3b8: { // 0x60f3b8: a1e4e2a500 MOV EAX,[0x00a5e2e4]
    s.ax = m.r32((0x00a5e2e4u));
  }
  L0060f3bd: { // 0x60f3bd: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0060f3bf: { // 0x60f3bf: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0060f3c3: { // 0x60f3c3: 0f84d5feffff JZ 0x0060f29e
    if(integer::condition("JZ",flags)) goto L0060f29e;
  }
  L0060f3c9: { // 0x60f3c9: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0060f3cb: { // 0x60f3cb: 0f85cdfeffff JNZ 0x0060f29e
    if(integer::condition("JNZ",flags)) goto L0060f29e;
  }
  L0060f3d1: { // 0x60f3d1: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0060f3d3: { // 0x60f3d3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060f3d4: { // 0x60f3d4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0060f3d9: { // 0x60f3d9: e872caf8ff CALL 0x0059be50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0059be50u,6353886u); flags=s.arithmetic_flags;
  }
  L0060f3de: { // 0x60f3de: e8ed020000 CALL 0x0060f6d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060f6d0u,6353891u); flags=s.arithmetic_flags;
  }
  L0060f3e3: { // 0x60f3e3: eb28 JMP 0x0060f40d
    goto L0060f40d;
  }
  L0060f3e5: { // 0x60f3e5: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060f3e7: { // 0x60f3e7: 7418 JZ 0x0060f401
    if(integer::condition("JZ",flags)) goto L0060f401;
  }
  L0060f3e9: { // 0x60f3e9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060f3eb: { // 0x60f3eb: e800020000 CALL 0x0060f5f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060f5f0u,6353904u); flags=s.arithmetic_flags;
  }
  L0060f3f0: { // 0x60f3f0: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060f3f3: { // 0x60f3f3: 740c JZ 0x0060f401
    if(integer::condition("JZ",flags)) goto L0060f401;
  }
  L0060f3f5: { // 0x60f3f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f3f6: { // 0x60f3f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f3f7: { // 0x60f3f7: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f3f8: { // 0x60f3f8: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0060f3fa: { // 0x60f3fa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f3fb: { // 0x60f3fb: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L0060f3fe: { // 0x60f3fe: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f401: { // 0x60f401: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0060f405: { // 0x60f405: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0060f407: { // 0x60f407: 893d50e2a500 MOV dword ptr [0x00a5e250],EDI
    m.w32((0x00a5e250u), s.di);
  }
  L0060f40d: { // 0x60f40d: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L0060f40f: { // 0x60f40f: 7512 JNZ 0x0060f423
    if(integer::condition("JNZ",flags)) goto L0060f423;
  }
  L0060f411: { // 0x60f411: 397c2410 CMP dword ptr [ESP + 0x10],EDI
    (void)integer::sub(m.r32((f.sp+0x00000010u)),s.di,32,flags);
  }
  L0060f415: { // 0x60f415: 750c JNZ 0x0060f423
    if(integer::condition("JNZ",flags)) goto L0060f423;
  }
  L0060f417: { // 0x60f417: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f418: { // 0x60f418: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f419: { // 0x60f419: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f41a: { // 0x60f41a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0060f41c: { // 0x60f41c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f41d: { // 0x60f41d: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L0060f420: { // 0x60f420: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f423: { // 0x60f423: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f424: { // 0x60f424: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f425: { // 0x60f425: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f426: { // 0x60f426: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0060f42b: { // 0x60f42b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f42c: { // 0x60f42c: 83c43c ADD ESP,0x3c
    f.sp = integer::add(f.sp,0x0000003cu,32,flags);
  }
  L0060f42f: { // 0x60f42f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
