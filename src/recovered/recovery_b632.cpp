#include "recovered/recovery_b632_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b632 {
namespace {
void f_0022de60(Memory&,State&,Frame&,const Operations&);
void f_001cab90(Memory&,State&,Frame&,const Operations&);
void f_0000ff60(Memory&,State&,Frame&,const Operations&);
void f_00023f60(Memory&,State&,Frame&,const Operations&);
void f_0006cc20(Memory&,State&,Frame&,const Operations&);
void f_000ce770(Memory&,State&,Frame&,const Operations&);
void f_00005bf0(Memory&,State&,Frame&,const Operations&);
void f_001ce110(Memory&,State&,Frame&,const Operations&);
void f_000106e0(Memory&,State&,Frame&,const Operations&);
void f_002d4e00(Memory&,State&,Frame&,const Operations&);
void f_002d4e10(Memory&,State&,Frame&,const Operations&);
void f_002d4e20(Memory&,State&,Frame&,const Operations&);
void f_002d4ea0(Memory&,State&,Frame&,const Operations&);
void f_0010a6a0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022de60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062de60: { // 0x0062de60: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0062de64: { // 0x0062de64: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062de65: { // 0x0062de65: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0062de67: { // 0x0062de67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0062de68: { // 0x0062de68: e823cdf9ff CALL 0x005cab90
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cab90u,6479469u); flags=s.arithmetic_flags;
  }
  L0062de6d: { // 0x0062de6d: c786c8000000fc577800 MOV dword ptr [ESI + 0xc8],0x7857fc
    m.w32((s.si+0x000000c8u), 0x007857fcu);
  }
  L0062de77: { // 0x0062de77: c706a8387900 MOV dword ptr [ESI],0x7938a8
    m.w32((s.si), 0x007938a8u);
  }
  L0062de7d: { // 0x0062de7d: c746048c387900 MOV dword ptr [ESI + 0x4],0x79388c
    m.w32((s.si+0x00000004u), 0x0079388cu);
  }
  L0062de84: { // 0x0062de84: c7460884387900 MOV dword ptr [ESI + 0x8],0x793884
    m.w32((s.si+0x00000008u), 0x00793884u);
  }
  L0062de8b: { // 0x0062de8b: c7460c7c387900 MOV dword ptr [ESI + 0xc],0x79387c
    m.w32((s.si+0x0000000cu), 0x0079387cu);
  }
  L0062de92: { // 0x0062de92: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062de94: { // 0x0062de94: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062de95: { // 0x0062de95: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001cab90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cab90: { // 0x005cab90: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cab94: { // 0x005cab94: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cab95: { // 0x005cab95: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005cab97: { // 0x005cab97: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005cab98: { // 0x005cab98: e8c353e4ff CALL 0x0040ff60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff60u,6073245u); flags=s.arithmetic_flags;
  }
  L005cab9d: { // 0x005cab9d: c70658247900 MOV dword ptr [ESI],0x792458
    m.w32((s.si), 0x00792458u);
  }
  L005caba3: { // 0x005caba3: c746043c247900 MOV dword ptr [ESI + 0x4],0x79243c
    m.w32((s.si+0x00000004u), 0x0079243cu);
  }
  L005cabaa: { // 0x005cabaa: c7460834247900 MOV dword ptr [ESI + 0x8],0x792434
    m.w32((s.si+0x00000008u), 0x00792434u);
  }
  L005cabb1: { // 0x005cabb1: c7460c2c247900 MOV dword ptr [ESI + 0xc],0x79242c
    m.w32((s.si+0x0000000cu), 0x0079242cu);
  }
  L005cabb8: { // 0x005cabb8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005cabba: { // 0x005cabba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cabbb: { // 0x005cabbb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0000ff60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff60: { // 0x40ff60: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0040ff62: { // 0x40ff62: c74008445e7800 MOV dword ptr [EAX + 0x8],0x785e44
    m.w32((s.ax+0x00000008u), 0x00785e44u);
  }
  L0040ff69: { // 0x40ff69: c7400c3c5e7800 MOV dword ptr [EAX + 0xc],0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff70: { // 0x40ff70: c700d85d7800 MOV dword ptr [EAX],0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff76: { // 0x40ff76: c74004bc5d7800 MOV dword ptr [EAX + 0x4],0x785dbc
    m.w32((s.ax+0x00000004u), 0x00785dbcu);
  }
  L0040ff7d: { // 0x40ff7d: c74008b45d7800 MOV dword ptr [EAX + 0x8],0x785db4
    m.w32((s.ax+0x00000008u), 0x00785db4u);
  }
  L0040ff84: { // 0x40ff84: c7400cac5d7800 MOV dword ptr [EAX + 0xc],0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff8b: { // 0x40ff8b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00023f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00423f60: { // 0x423f60: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00423f62: { // 0x423f62: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0006cc20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046cc20: { // 0x46cc20: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0046cc24: { // 0x46cc24: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046cc25: { // 0x46cc25: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046cc27: { // 0x46cc27: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0046cc29: { // 0x46cc29: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0046cc2b: { // 0x46cc2b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L0046cc2e: { // 0x46cc2e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L0046cc31: { // 0x46cc31: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L0046cc35: { // 0x46cc35: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L0046cc38: { // 0x46cc38: c706d4897800 MOV dword ptr [ESI],0x7889d4
    m.w32((s.si), 0x007889d4u);
  }
  L0046cc3e: { // 0x46cc3e: 7424 JZ 0x0046cc64
    if(integer::condition("JZ",flags)) goto L0046cc64;
  }
  L0046cc40: { // 0x46cc40: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0046cc44: { // 0x46cc44: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0046cc46: { // 0x46cc46: 7409 JZ 0x0046cc51
    if(integer::condition("JZ",flags)) goto L0046cc51;
  }
  L0046cc48: { // 0x46cc48: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L0046cc4b: { // 0x46cc4b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0046cc4d: { // 0x46cc4d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cc4e: { // 0x46cc4e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0046cc51: { // 0x46cc51: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L0046cc54: { // 0x46cc54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0046cc55: { // 0x46cc55: e8fd0c3000 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4639834u); flags=s.arithmetic_flags;
  }
  L0046cc5a: { // 0x46cc5a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0046cc5d: { // 0x46cc5d: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L0046cc60: { // 0x46cc60: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L0046cc64: { // 0x46cc64: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0046cc66: { // 0x46cc66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046cc67: { // 0x46cc67: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000ce770(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ce770: { // 0x4ce770: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004ce774: { // 0x4ce774: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ce775: { // 0x4ce775: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004ce777: { // 0x4ce777: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004ce779: { // 0x4ce779: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004ce77b: { // 0x4ce77b: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L004ce77e: { // 0x4ce77e: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L004ce781: { // 0x4ce781: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L004ce785: { // 0x4ce785: 88560d MOV byte ptr [ESI + 0xd],DL
    m.w8((s.si+0x0000000du), (s.dx & 0xffu));
  }
  L004ce788: { // 0x4ce788: c7069cc77800 MOV dword ptr [ESI],0x78c79c
    m.w32((s.si), 0x0078c79cu);
  }
  L004ce78e: { // 0x4ce78e: 7424 JZ 0x004ce7b4
    if(integer::condition("JZ",flags)) goto L004ce7b4;
  }
  L004ce790: { // 0x4ce790: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L004ce794: { // 0x4ce794: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004ce796: { // 0x4ce796: 7409 JZ 0x004ce7a1
    if(integer::condition("JZ",flags)) goto L004ce7a1;
  }
  L004ce798: { // 0x4ce798: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L004ce79b: { // 0x4ce79b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ce79d: { // 0x4ce79d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ce79e: { // 0x4ce79e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004ce7a1: { // 0x4ce7a1: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L004ce7a4: { // 0x4ce7a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ce7a5: { // 0x4ce7a5: e8adf12900 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,5040042u); flags=s.arithmetic_flags;
  }
  L004ce7aa: { // 0x4ce7aa: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004ce7ad: { // 0x4ce7ad: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L004ce7b0: { // 0x4ce7b0: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L004ce7b4: { // 0x4ce7b4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004ce7b6: { // 0x4ce7b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004ce7b7: { // 0x4ce7b7: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00005bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405bf0: { // 0x405bf0: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00405bf2: { // 0x405bf2: c7410cec928100 MOV dword ptr [ECX + 0xc],0x8192ec
    m.w32((s.cx+0x0000000cu), 0x008192ecu);
  }
  L00405bf9: { // 0x405bf9: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00405bfb: { // 0x405bfb: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00405bfe: { // 0x405bfe: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L00405c01: { // 0x405c01: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_001ce110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ce110: { // 0x5ce110: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005ce114: { // 0x5ce114: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ce115: { // 0x5ce115: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005ce117: { // 0x5ce117: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005ce118: { // 0x5ce118: e8c325e4ff CALL 0x004106e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004106e0u,6086941u); flags=s.arithmetic_flags;
  }
  L005ce11d: { // 0x5ce11d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005ce11f: { // 0x5ce11f: 8d86c8000000 LEA EAX,[ESI + 0xc8]
    s.ax = (s.si+0x000000c8u);
  }
  L005ce125: { // 0x5ce125: 898ea4000000 MOV dword ptr [ESI + 0xa4],ECX
    m.w32((s.si+0x000000a4u), s.cx);
  }
  L005ce12b: { // 0x5ce12b: ba0f000000 MOV EDX,0xf
    s.dx = 0x0000000fu;
  }
  L005ce130: { // 0x5ce130: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005ce132: { // 0x5ce132: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L005ce135: { // 0x5ce135: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005ce138: { // 0x5ce138: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005ce139: { // 0x5ce139: 75f5 JNZ 0x005ce130
    if(integer::condition("JNZ",flags)) goto L005ce130;
  }
  L005ce13b: { // 0x5ce13b: 8d8640010000 LEA EAX,[ESI + 0x140]
    s.ax = (s.si+0x00000140u);
  }
  L005ce141: { // 0x5ce141: ba0f000000 MOV EDX,0xf
    s.dx = 0x0000000fu;
  }
  L005ce146: { // 0x5ce146: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L005ce148: { // 0x5ce148: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L005ce14b: { // 0x5ce14b: 83c008 ADD EAX,0x8
    s.ax = integer::add(s.ax,0x00000008u,32,flags);
  }
  L005ce14e: { // 0x5ce14e: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005ce14f: { // 0x5ce14f: 75f5 JNZ 0x005ce146
    if(integer::condition("JNZ",flags)) goto L005ce146;
  }
  L005ce151: { // 0x5ce151: 898e14020000 MOV dword ptr [ESI + 0x214],ECX
    m.w32((s.si+0x00000214u), s.cx);
  }
  L005ce157: { // 0x5ce157: 898e18020000 MOV dword ptr [ESI + 0x218],ECX
    m.w32((s.si+0x00000218u), s.cx);
  }
  L005ce15d: { // 0x5ce15d: 898e1c020000 MOV dword ptr [ESI + 0x21c],ECX
    m.w32((s.si+0x0000021cu), s.cx);
  }
  L005ce163: { // 0x5ce163: 888e20020000 MOV byte ptr [ESI + 0x220],CL
    m.w8((s.si+0x00000220u), (s.cx & 0xffu));
  }
  L005ce169: { // 0x5ce169: 898e24020000 MOV dword ptr [ESI + 0x224],ECX
    m.w32((s.si+0x00000224u), s.cx);
  }
  L005ce16f: { // 0x5ce16f: 898e28020000 MOV dword ptr [ESI + 0x228],ECX
    m.w32((s.si+0x00000228u), s.cx);
  }
  L005ce175: { // 0x5ce175: 898e2c020000 MOV dword ptr [ESI + 0x22c],ECX
    m.w32((s.si+0x0000022cu), s.cx);
  }
  L005ce17b: { // 0x5ce17b: 898e30020000 MOV dword ptr [ESI + 0x230],ECX
    m.w32((s.si+0x00000230u), s.cx);
  }
  L005ce181: { // 0x5ce181: 888e34020000 MOV byte ptr [ESI + 0x234],CL
    m.w8((s.si+0x00000234u), (s.cx & 0xffu));
  }
  L005ce187: { // 0x5ce187: 898e38020000 MOV dword ptr [ESI + 0x238],ECX
    m.w32((s.si+0x00000238u), s.cx);
  }
  L005ce18d: { // 0x5ce18d: 898e3c020000 MOV dword ptr [ESI + 0x23c],ECX
    m.w32((s.si+0x0000023cu), s.cx);
  }
  L005ce193: { // 0x5ce193: 898e40020000 MOV dword ptr [ESI + 0x240],ECX
    m.w32((s.si+0x00000240u), s.cx);
  }
  L005ce199: { // 0x5ce199: 898e44020000 MOV dword ptr [ESI + 0x244],ECX
    m.w32((s.si+0x00000244u), s.cx);
  }
  L005ce19f: { // 0x5ce19f: 888e48020000 MOV byte ptr [ESI + 0x248],CL
    m.w8((s.si+0x00000248u), (s.cx & 0xffu));
  }
  L005ce1a5: { // 0x5ce1a5: 898e4c020000 MOV dword ptr [ESI + 0x24c],ECX
    m.w32((s.si+0x0000024cu), s.cx);
  }
  L005ce1ab: { // 0x5ce1ab: 898e50020000 MOV dword ptr [ESI + 0x250],ECX
    m.w32((s.si+0x00000250u), s.cx);
  }
  L005ce1b1: { // 0x5ce1b1: 898e54020000 MOV dword ptr [ESI + 0x254],ECX
    m.w32((s.si+0x00000254u), s.cx);
  }
  L005ce1b7: { // 0x5ce1b7: 898e58020000 MOV dword ptr [ESI + 0x258],ECX
    m.w32((s.si+0x00000258u), s.cx);
  }
  L005ce1bd: { // 0x5ce1bd: 888e5c020000 MOV byte ptr [ESI + 0x25c],CL
    m.w8((s.si+0x0000025cu), (s.cx & 0xffu));
  }
  L005ce1c3: { // 0x5ce1c3: 898e60020000 MOV dword ptr [ESI + 0x260],ECX
    m.w32((s.si+0x00000260u), s.cx);
  }
  L005ce1c9: { // 0x5ce1c9: c706b8267900 MOV dword ptr [ESI],0x7926b8
    m.w32((s.si), 0x007926b8u);
  }
  L005ce1cf: { // 0x5ce1cf: c746049c267900 MOV dword ptr [ESI + 0x4],0x79269c
    m.w32((s.si+0x00000004u), 0x0079269cu);
  }
  L005ce1d6: { // 0x5ce1d6: c7460894267900 MOV dword ptr [ESI + 0x8],0x792694
    m.w32((s.si+0x00000008u), 0x00792694u);
  }
  L005ce1dd: { // 0x5ce1dd: c7460c8c267900 MOV dword ptr [ESI + 0xc],0x79268c
    m.w32((s.si+0x0000000cu), 0x0079268cu);
  }
  L005ce1e4: { // 0x5ce1e4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L005ce1e6: { // 0x5ce1e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ce1e7: { // 0x5ce1e7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000106e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004106e0: { // 0x4106e0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L004106e4: { // 0x4106e4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004106e5: { // 0x4106e5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004106e7: { // 0x4106e7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004106e8: { // 0x4106e8: e873f8ffff CALL 0x0040ff60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff60u,4261613u); flags=s.arithmetic_flags;
  }
  L004106ed: { // 0x4106ed: 8a463d MOV AL,byte ptr [ESI + 0x3d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000003du)));
  }
  L004106f0: { // 0x4106f0: 8d4e3d LEA ECX,[ESI + 0x3d]
    s.cx = (s.si+0x0000003du);
  }
  L004106f3: { // 0x4106f3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004106f5: { // 0x4106f5: c706885e7800 MOV dword ptr [ESI],0x785e88
    m.w32((s.si), 0x00785e88u);
  }
  L004106fb: { // 0x4106fb: c746046c5e7800 MOV dword ptr [ESI + 0x4],0x785e6c
    m.w32((s.si+0x00000004u), 0x00785e6cu);
  }
  L00410702: { // 0x410702: c74608645e7800 MOV dword ptr [ESI + 0x8],0x785e64
    m.w32((s.si+0x00000008u), 0x00785e64u);
  }
  L00410709: { // 0x410709: c7460c5c5e7800 MOV dword ptr [ESI + 0xc],0x785e5c
    m.w32((s.si+0x0000000cu), 0x00785e5cu);
  }
  L00410710: { // 0x410710: 7417 JZ 0x00410729
    if(integer::condition("JZ",flags)) goto L00410729;
  }
  L00410712: { // 0x410712: 6a7f PUSH 0x7f
    f.push(m,0x0000007fu);
  }
  L00410714: { // 0x410714: 6818927b00 PUSH 0x7b9218
    f.push(m,0x007b9218u);
  }
  L00410719: { // 0x410719: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0041071b: { // 0x41071b: e840e42d00 CALL 0x006eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,4261664u); flags=s.arithmetic_flags;
  }
  L00410720: { // 0x410720: 894660 MOV dword ptr [ESI + 0x60],EAX
    m.w32((s.si+0x00000060u), s.ax);
  }
  L00410723: { // 0x410723: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00410725: { // 0x410725: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00410726: { // 0x410726: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00410729: { // 0x410729: c746608c208200 MOV dword ptr [ESI + 0x60],0x82208c
    m.w32((s.si+0x00000060u), 0x0082208cu);
  }
  L00410730: { // 0x410730: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00410732: { // 0x410732: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00410733: { // 0x410733: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4e00: { // 0x6d4e00: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006d4e02: { // 0x6d4e02: c7002c407900 MOV dword ptr [EAX],0x79402c
    m.w32((s.ax), 0x0079402cu);
  }
  L006d4e08: { // 0x6d4e08: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4e10: { // 0x6d4e10: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006d4e12: { // 0x6d4e12: c700948a7800 MOV dword ptr [EAX],0x788a94
    m.w32((s.ax), 0x00788a94u);
  }
  L006d4e18: { // 0x6d4e18: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4e20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4e20: { // 0x6d4e20: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006d4e22: { // 0x6d4e22: c70028df7800 MOV dword ptr [EAX],0x78df28
    m.w32((s.ax), 0x0078df28u);
  }
  L006d4e28: { // 0x6d4e28: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4ea0: { // 0x6d4ea0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L006d4ea4: { // 0x6d4ea4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d4ea5: { // 0x6d4ea5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006d4ea7: { // 0x6d4ea7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d4ea9: { // 0x6d4ea9: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L006d4eb0: { // 0x6d4eb0: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L006d4eb3: { // 0x6d4eb3: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  L006d4eb7: { // 0x6d4eb7: c6460d00 MOV byte ptr [ESI + 0xd],0x0
    m.w8((s.si+0x0000000du), 0x00000000u);
  }
  L006d4ebb: { // 0x6d4ebb: c706ac807800 MOV dword ptr [ESI],0x7880ac
    m.w32((s.si), 0x007880acu);
  }
  L006d4ec1: { // 0x6d4ec1: 7420 JZ 0x006d4ee3
    if(integer::condition("JZ",flags)) goto L006d4ee3;
  }
  L006d4ec3: { // 0x6d4ec3: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006d4ec7: { // 0x6d4ec7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006d4ec9: { // 0x6d4ec9: 7405 JZ 0x006d4ed0
    if(integer::condition("JZ",flags)) goto L006d4ed0;
  }
  L006d4ecb: { // 0x6d4ecb: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L006d4ece: { // 0x6d4ece: eb13 JMP 0x006d4ee3
    goto L006d4ee3;
  }
  L006d4ed0: { // 0x6d4ed0: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  L006d4ed3: { // 0x6d4ed3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d4ed4: { // 0x6d4ed4: e87e8a0900 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,7163609u); flags=s.arithmetic_flags;
  }
  L006d4ed9: { // 0x6d4ed9: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006d4edc: { // 0x6d4edc: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L006d4edf: { // 0x6d4edf: c6460d01 MOV byte ptr [ESI + 0xd],0x1
    m.w8((s.si+0x0000000du), 0x00000001u);
  }
  L006d4ee3: { // 0x6d4ee3: c706cc807800 MOV dword ptr [ESI],0x7880cc
    m.w32((s.si), 0x007880ccu);
  }
  L006d4ee9: { // 0x6d4ee9: c746140a000000 MOV dword ptr [ESI + 0x14],0xa
    m.w32((s.si+0x00000014u), 0x0000000au);
  }
  L006d4ef0: { // 0x6d4ef0: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  L006d4ef7: { // 0x6d4ef7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006d4ef9: { // 0x6d4ef9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d4efa: { // 0x6d4efa: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_0010a6a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0050a6a0: { // 0x50a6a0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0050a6a2: { // 0x50a6a2: c7007ceb7800 MOV dword ptr [EAX],0x78eb7c
    m.w32((s.ax), 0x0078eb7cu);
  }
  L0050a6a8: { // 0x50a6a8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6479456u:f_0022de60(m,s,child,{});break;
case 6073232u:f_001cab90(m,s,child,{});break;
case 4259680u:f_0000ff60(m,s,child,{});break;
case 4341600u:f_00023f60(m,s,child,{});break;
case 4639776u:f_0006cc20(m,s,child,{});break;
case 5039984u:f_000ce770(m,s,child,{});break;
case 4217840u:f_00005bf0(m,s,child,{});break;
case 6086928u:f_001ce110(m,s,child,{});break;
case 4261600u:f_000106e0(m,s,child,{});break;
case 7163392u:f_002d4e00(m,s,child,{});break;
case 7163408u:f_002d4e10(m,s,child,{});break;
case 7163424u:f_002d4e20(m,s,child,{});break;
case 7163552u:f_002d4ea0(m,s,child,{});break;
case 5285536u:f_0010a6a0(m,s,child,{});break;
default:throw std::domain_error("recovery632 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006b7580(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b7580: { // 0x6b7580: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b7581: { // 0x6b7581: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b7582: { // 0x6b7582: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  L006b7586: { // 0x6b7586: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006b7587: { // 0x6b7587: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006b7588: { // 0x6b7588: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006b758a: { // 0x6b758a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b758b: { // 0x6b758b: e8d068f7ff CALL 0x0062de60
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062de60u,7042448u); flags=s.arithmetic_flags;
  }
  L006b7590: { // 0x6b7590: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006b7592: { // 0x6b7592: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L006b7597: { // 0x6b7597: 899ebc010000 MOV dword ptr [ESI + 0x1bc],EBX
    m.w32((s.si+0x000001bcu), s.bx);
  }
  L006b759d: { // 0x6b759d: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006b75a2: { // 0x6b75a2: 8986c0010000 MOV dword ptr [ESI + 0x1c0],EAX
    m.w32((s.si+0x000001c0u), s.ax);
  }
  L006b75a8: { // 0x6b75a8: 899ec8010000 MOV dword ptr [ESI + 0x1c8],EBX
    m.w32((s.si+0x000001c8u), s.bx);
  }
  L006b75ae: { // 0x6b75ae: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006b75af: { // 0x6b75af: 8d8eb0020000 LEA ECX,[ESI + 0x2b0]
    s.cx = (s.si+0x000002b0u);
  }
  L006b75b5: { // 0x6b75b5: 899ecc010000 MOV dword ptr [ESI + 0x1cc],EBX
    m.w32((s.si+0x000001ccu), s.bx);
  }
  L006b75bb: { // 0x6b75bb: 89bed0010000 MOV dword ptr [ESI + 0x1d0],EDI
    m.w32((s.si+0x000001d0u), s.di);
  }
  L006b75c1: { // 0x6b75c1: e89ac9d6ff CALL 0x00423f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00423f60u,7042502u); flags=s.arithmetic_flags;
  }
  L006b75c6: { // 0x6b75c6: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L006b75cb: { // 0x6b75cb: 89be34030000 MOV dword ptr [ESI + 0x334],EDI
    m.w32((s.si+0x00000334u), s.di);
  }
  L006b75d1: { // 0x6b75d1: 898630030000 MOV dword ptr [ESI + 0x330],EAX
    m.w32((s.si+0x00000330u), s.ax);
  }
  L006b75d7: { // 0x6b75d7: 89be38030000 MOV dword ptr [ESI + 0x338],EDI
    m.w32((s.si+0x00000338u), s.di);
  }
  L006b75dd: { // 0x6b75dd: 89be3c030000 MOV dword ptr [ESI + 0x33c],EDI
    m.w32((s.si+0x0000033cu), s.di);
  }
  L006b75e3: { // 0x6b75e3: 899e44030000 MOV dword ptr [ESI + 0x344],EBX
    m.w32((s.si+0x00000344u), s.bx);
  }
  L006b75e9: { // 0x6b75e9: 899e48030000 MOV dword ptr [ESI + 0x348],EBX
    m.w32((s.si+0x00000348u), s.bx);
  }
  L006b75ef: { // 0x6b75ef: 89be54030000 MOV dword ptr [ESI + 0x354],EDI
    m.w32((s.si+0x00000354u), s.di);
  }
  L006b75f5: { // 0x6b75f5: 89be58030000 MOV dword ptr [ESI + 0x358],EDI
    m.w32((s.si+0x00000358u), s.di);
  }
  L006b75fb: { // 0x6b75fb: 89be5c030000 MOV dword ptr [ESI + 0x35c],EDI
    m.w32((s.si+0x0000035cu), s.di);
  }
  L006b7601: { // 0x6b7601: 8dbe90030000 LEA EDI,[ESI + 0x390]
    s.di = (s.si+0x00000390u);
  }
  L006b7607: { // 0x6b7607: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b7608: { // 0x6b7608: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b7609: { // 0x6b7609: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b760b: { // 0x6b760b: 898650030000 MOV dword ptr [ESI + 0x350],EAX
    m.w32((s.si+0x00000350u), s.ax);
  }
  L006b7611: { // 0x6b7611: 899e64030000 MOV dword ptr [ESI + 0x364],EBX
    m.w32((s.si+0x00000364u), s.bx);
  }
  L006b7617: { // 0x6b7617: 899e68030000 MOV dword ptr [ESI + 0x368],EBX
    m.w32((s.si+0x00000368u), s.bx);
  }
  L006b761d: { // 0x6b761d: e8fe55dbff CALL 0x0046cc20
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046cc20u,7042594u); flags=s.arithmetic_flags;
  }
  L006b7622: { // 0x6b7622: bd0a000000 MOV EBP,0xa
    s.bp = 0x0000000au;
  }
  L006b7627: { // 0x6b7627: c707948a7800 MOV dword ptr [EDI],0x788a94
    m.w32((s.di), 0x00788a94u);
  }
  L006b762d: { // 0x6b762d: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L006b7630: { // 0x6b7630: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L006b7633: { // 0x6b7633: 8dbea8030000 LEA EDI,[ESI + 0x3a8]
    s.di = (s.si+0x000003a8u);
  }
  L006b7639: { // 0x6b7639: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b763a: { // 0x6b763a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b763b: { // 0x6b763b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b763d: { // 0x6b763d: e82e71e1ff CALL 0x004ce770
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ce770u,7042626u); flags=s.arithmetic_flags;
  }
  L006b7642: { // 0x6b7642: c7077cc77800 MOV dword ptr [EDI],0x78c77c
    m.w32((s.di), 0x0078c77cu);
  }
  L006b7648: { // 0x6b7648: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L006b764b: { // 0x6b764b: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L006b764e: { // 0x6b764e: 8dbec0030000 LEA EDI,[ESI + 0x3c0]
    s.di = (s.si+0x000003c0u);
  }
  L006b7654: { // 0x6b7654: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b7655: { // 0x6b7655: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b7656: { // 0x6b7656: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006b7658: { // 0x6b7658: e81371e1ff CALL 0x004ce770
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ce770u,7042653u); flags=s.arithmetic_flags;
  }
  L006b765d: { // 0x6b765d: c7077cc77800 MOV dword ptr [EDI],0x78c77c
    m.w32((s.di), 0x0078c77cu);
  }
  L006b7663: { // 0x6b7663: 896f14 MOV dword ptr [EDI + 0x14],EBP
    m.w32((s.di+0x00000014u), s.bp);
  }
  L006b7666: { // 0x6b7666: 895f10 MOV dword ptr [EDI + 0x10],EBX
    m.w32((s.di+0x00000010u), s.bx);
  }
  L006b7669: { // 0x6b7669: c706287a7900 MOV dword ptr [ESI],0x797a28
    m.w32((s.si), 0x00797a28u);
  }
  L006b766f: { // 0x6b766f: c746040c7a7900 MOV dword ptr [ESI + 0x4],0x797a0c
    m.w32((s.si+0x00000004u), 0x00797a0cu);
  }
  L006b7676: { // 0x6b7676: c74608047a7900 MOV dword ptr [ESI + 0x8],0x797a04
    m.w32((s.si+0x00000008u), 0x00797a04u);
  }
  L006b767d: { // 0x6b767d: c7460cfc797900 MOV dword ptr [ESI + 0xc],0x7979fc
    m.w32((s.si+0x0000000cu), 0x007979fcu);
  }
  L006b7684: { // 0x6b7684: a17088a200 MOV EAX,[0x00a28870]
    s.ax = m.r32((0x00a28870u));
  }
  L006b7689: { // 0x6b7689: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006b768b: { // 0x6b768b: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006b768d: { // 0x6b768d: 885c2414 MOV byte ptr [ESP + 0x14],BL
    m.w8((f.sp+0x00000014u), (s.bx & 0xffu));
  }
  L006b7691: { // 0x6b7691: 7e19 JLE 0x006b76ac
    if(integer::condition("JLE",flags)) goto L006b76ac;
  }
  L006b7693: { // 0x6b7693: 8b156488a200 MOV EDX,dword ptr [0x00a28864]
    s.dx = m.r32((0x00a28864u));
  }
  L006b7699: { // 0x6b7699: 3932 CMP dword ptr [EDX],ESI
    (void)integer::sub(m.r32((s.dx)),s.si,32,flags);
  }
  L006b769b: { // 0x6b769b: 740a JZ 0x006b76a7
    if(integer::condition("JZ",flags)) goto L006b76a7;
  }
  L006b769d: { // 0x6b769d: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006b769e: { // 0x6b769e: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L006b76a1: { // 0x6b76a1: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006b76a3: { // 0x6b76a3: 7cf4 JL 0x006b7699
    if(integer::condition("JL",flags)) goto L006b7699;
  }
  L006b76a5: { // 0x6b76a5: eb05 JMP 0x006b76ac
    goto L006b76ac;
  }
  L006b76a7: { // 0x6b76a7: c644241401 MOV byte ptr [ESP + 0x14],0x1
    m.w8((f.sp+0x00000014u), 0x00000001u);
  }
  L006b76ac: { // 0x6b76ac: 8d8ed8030000 LEA ECX,[ESI + 0x3d8]
    s.cx = (s.si+0x000003d8u);
  }
  L006b76b2: { // 0x6b76b2: e839e5d4ff CALL 0x00405bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405bf0u,7042743u); flags=s.arithmetic_flags;
  }
  L006b76b7: { // 0x6b76b7: 385c2414 CMP byte ptr [ESP + 0x14],BL
    (void)integer::sub(m.r8((f.sp+0x00000014u)),(s.bx & 0xffu),8,flags);
  }
  L006b76bb: { // 0x6b76bb: 7553 JNZ 0x006b7710
    if(integer::condition("JNZ",flags)) goto L006b7710;
  }
  L006b76bd: { // 0x6b76bd: a16888a200 MOV EAX,[0x00a28868]
    s.ax = m.r32((0x00a28868u));
  }
  L006b76c2: { // 0x6b76c2: 8b0d7088a200 MOV ECX,dword ptr [0x00a28870]
    s.cx = m.r32((0x00a28870u));
  }
  L006b76c8: { // 0x6b76c8: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006b76ca: { // 0x6b76ca: 7c2c JL 0x006b76f8
    if(integer::condition("JL",flags)) goto L006b76f8;
  }
  L006b76cc: { // 0x6b76cc: 381d6d88a200 CMP byte ptr [0x00a2886d],BL
    (void)integer::sub(m.r8((0x00a2886du)),(s.bx & 0xffu),8,flags);
  }
  L006b76d2: { // 0x6b76d2: 7504 JNZ 0x006b76d8
    if(integer::condition("JNZ",flags)) goto L006b76d8;
  }
  L006b76d4: { // 0x6b76d4: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006b76d6: { // 0x6b76d6: 7538 JNZ 0x006b7710
    if(integer::condition("JNZ",flags)) goto L006b7710;
  }
  L006b76d8: { // 0x6b76d8: 8b0d7488a200 MOV ECX,dword ptr [0x00a28874]
    s.cx = m.r32((0x00a28874u));
  }
  L006b76de: { // 0x6b76de: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006b76e0: { // 0x6b76e0: 7e2e JLE 0x006b7710
    if(integer::condition("JLE",flags)) goto L006b7710;
  }
  L006b76e2: { // 0x6b76e2: 8b156088a200 MOV EDX,dword ptr [0x00a28860]
    s.dx = m.r32((0x00a28860u));
  }
  L006b76e8: { // 0x6b76e8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006b76ea: { // 0x6b76ea: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006b76eb: { // 0x6b76eb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006b76ec: { // 0x6b76ec: b96088a200 MOV ECX,0xa28860
    s.cx = 0x00a28860u;
  }
  L006b76f1: { // 0x6b76f1: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),7042804u); flags=s.arithmetic_flags;
  }
  L006b76f4: { // 0x6b76f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006b76f6: { // 0x6b76f6: 7418 JZ 0x006b7710
    if(integer::condition("JZ",flags)) goto L006b7710;
  }
  L006b76f8: { // 0x6b76f8: 8b0d7088a200 MOV ECX,dword ptr [0x00a28870]
    s.cx = m.r32((0x00a28870u));
  }
  L006b76fe: { // 0x6b76fe: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006b7700: { // 0x6b7700: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006b7701: { // 0x6b7701: 890d7088a200 MOV dword ptr [0x00a28870],ECX
    m.w32((0x00a28870u), s.cx);
  }
  L006b7707: { // 0x6b7707: 8b0d6488a200 MOV ECX,dword ptr [0x00a28864]
    s.cx = m.r32((0x00a28864u));
  }
  L006b770d: { // 0x6b770d: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L006b7710: { // 0x6b7710: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006b7712: { // 0x6b7712: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006b7713: { // 0x6b7713: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006b7714: { // 0x6b7714: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006b7715: { // 0x6b7715: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006b7716: { // 0x6b7716: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006cfc50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cfc50: { // 0x6cfc50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfc51: { // 0x6cfc51: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006cfc52: { // 0x6cfc52: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cfc53: { // 0x6cfc53: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfc54: { // 0x6cfc54: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L006cfc58: { // 0x6cfc58: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006cfc5a: { // 0x6cfc5a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfc5b: { // 0x6cfc5b: e8b0e4efff CALL 0x005ce110
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ce110u,7142496u); flags=s.arithmetic_flags;
  }
  L006cfc60: { // 0x6cfc60: 8d9ee4020000 LEA EBX,[ESI + 0x2e4]
    s.bx = (s.si+0x000002e4u);
  }
  L006cfc66: { // 0x6cfc66: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfc67: { // 0x6cfc67: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006cfc69: { // 0x6cfc69: e892510000 CALL 0x006d4e00
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e00u,7142510u); flags=s.arithmetic_flags;
  }
  L006cfc6e: { // 0x6cfc6e: c703a03f7900 MOV dword ptr [EBX],0x793fa0
    m.w32((s.bx), 0x00793fa0u);
  }
  L006cfc74: { // 0x6cfc74: 8d9e00030000 LEA EBX,[ESI + 0x300]
    s.bx = (s.si+0x00000300u);
  }
  L006cfc7a: { // 0x6cfc7a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfc7b: { // 0x6cfc7b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006cfc7d: { // 0x6cfc7d: e88e510000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142530u); flags=s.arithmetic_flags;
  }
  L006cfc82: { // 0x6cfc82: c703f4897800 MOV dword ptr [EBX],0x7889f4
    m.w32((s.bx), 0x007889f4u);
  }
  L006cfc88: { // 0x6cfc88: 8daeac030000 LEA EBP,[ESI + 0x3ac]
    s.bp = (s.si+0x000003acu);
  }
  L006cfc8e: { // 0x6cfc8e: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L006cfc90: { // 0x6cfc90: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfc91: { // 0x6cfc91: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfc93: { // 0x6cfc93: 899e90030000 MOV dword ptr [ESI + 0x390],EBX
    m.w32((s.si+0x00000390u), s.bx);
  }
  L006cfc99: { // 0x6cfc99: e882510000 CALL 0x006d4e20
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e20u,7142558u); flags=s.arithmetic_flags;
  }
  L006cfc9e: { // 0x6cfc9e: c745002c0e7900 MOV dword ptr [EBP],0x790e2c
    m.w32((s.bp), 0x00790e2cu);
  }
  L006cfca5: { // 0x6cfca5: 8daed0030000 LEA EBP,[ESI + 0x3d0]
    s.bp = (s.si+0x000003d0u);
  }
  L006cfcab: { // 0x6cfcab: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfcac: { // 0x6cfcac: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfcae: { // 0x6cfcae: e85d510000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142579u); flags=s.arithmetic_flags;
  }
  L006cfcb3: { // 0x6cfcb3: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfcba: { // 0x6cfcba: 8daeec030000 LEA EBP,[ESI + 0x3ec]
    s.bp = (s.si+0x000003ecu);
  }
  L006cfcc0: { // 0x6cfcc0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfcc1: { // 0x6cfcc1: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfcc3: { // 0x6cfcc3: e848510000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142600u); flags=s.arithmetic_flags;
  }
  L006cfcc8: { // 0x6cfcc8: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfccf: { // 0x6cfccf: 8dae08040000 LEA EBP,[ESI + 0x408]
    s.bp = (s.si+0x00000408u);
  }
  L006cfcd5: { // 0x6cfcd5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfcd6: { // 0x6cfcd6: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfcd8: { // 0x6cfcd8: e833510000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142621u); flags=s.arithmetic_flags;
  }
  L006cfcdd: { // 0x6cfcdd: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfce4: { // 0x6cfce4: 8dae24040000 LEA EBP,[ESI + 0x424]
    s.bp = (s.si+0x00000424u);
  }
  L006cfcea: { // 0x6cfcea: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfceb: { // 0x6cfceb: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfced: { // 0x6cfced: e81e510000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142642u); flags=s.arithmetic_flags;
  }
  L006cfcf2: { // 0x6cfcf2: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfcf9: { // 0x6cfcf9: 8dae40040000 LEA EBP,[ESI + 0x440]
    s.bp = (s.si+0x00000440u);
  }
  L006cfcff: { // 0x6cfcff: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd00: { // 0x6cfd00: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd02: { // 0x6cfd02: e809510000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142663u); flags=s.arithmetic_flags;
  }
  L006cfd07: { // 0x6cfd07: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfd0e: { // 0x6cfd0e: 8dae5c040000 LEA EBP,[ESI + 0x45c]
    s.bp = (s.si+0x0000045cu);
  }
  L006cfd14: { // 0x6cfd14: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd15: { // 0x6cfd15: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd17: { // 0x6cfd17: e8f4500000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142684u); flags=s.arithmetic_flags;
  }
  L006cfd1c: { // 0x6cfd1c: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfd23: { // 0x6cfd23: 8dae78040000 LEA EBP,[ESI + 0x478]
    s.bp = (s.si+0x00000478u);
  }
  L006cfd29: { // 0x6cfd29: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd2a: { // 0x6cfd2a: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd2c: { // 0x6cfd2c: e8df500000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142705u); flags=s.arithmetic_flags;
  }
  L006cfd31: { // 0x6cfd31: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfd38: { // 0x6cfd38: 8dae94040000 LEA EBP,[ESI + 0x494]
    s.bp = (s.si+0x00000494u);
  }
  L006cfd3e: { // 0x6cfd3e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd3f: { // 0x6cfd3f: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd41: { // 0x6cfd41: e8ca500000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142726u); flags=s.arithmetic_flags;
  }
  L006cfd46: { // 0x6cfd46: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfd4d: { // 0x6cfd4d: 8dae10050000 LEA EBP,[ESI + 0x510]
    s.bp = (s.si+0x00000510u);
  }
  L006cfd53: { // 0x6cfd53: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd54: { // 0x6cfd54: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd56: { // 0x6cfd56: e845a9e3ff CALL 0x0050a6a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050a6a0u,7142747u); flags=s.arithmetic_flags;
  }
  L006cfd5b: { // 0x6cfd5b: c745003ceb7800 MOV dword ptr [EBP],0x78eb3c
    m.w32((s.bp), 0x0078eb3cu);
  }
  L006cfd62: { // 0x6cfd62: 8dae60050000 LEA EBP,[ESI + 0x560]
    s.bp = (s.si+0x00000560u);
  }
  L006cfd68: { // 0x6cfd68: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd69: { // 0x6cfd69: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd6b: { // 0x6cfd6b: e8a0500000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142768u); flags=s.arithmetic_flags;
  }
  L006cfd70: { // 0x6cfd70: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfd77: { // 0x6cfd77: 8dae7c050000 LEA EBP,[ESI + 0x57c]
    s.bp = (s.si+0x0000057cu);
  }
  L006cfd7d: { // 0x6cfd7d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd7e: { // 0x6cfd7e: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd80: { // 0x6cfd80: e88b500000 CALL 0x006d4e10
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4e10u,7142789u); flags=s.arithmetic_flags;
  }
  L006cfd85: { // 0x6cfd85: c74500f4897800 MOV dword ptr [EBP],0x7889f4
    m.w32((s.bp), 0x007889f4u);
  }
  L006cfd8c: { // 0x6cfd8c: 889ef2050000 MOV byte ptr [ESI + 0x5f2],BL
    m.w8((s.si+0x000005f2u), (s.bx & 0xffu));
  }
  L006cfd92: { // 0x6cfd92: 8dae44060000 LEA EBP,[ESI + 0x644]
    s.bp = (s.si+0x00000644u);
  }
  L006cfd98: { // 0x6cfd98: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfd99: { // 0x6cfd99: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfd9b: { // 0x6cfd9b: 889e11060000 MOV byte ptr [ESI + 0x611],BL
    m.w8((s.si+0x00000611u), (s.bx & 0xffu));
  }
  L006cfda1: { // 0x6cfda1: e8faa8e3ff CALL 0x0050a6a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050a6a0u,7142822u); flags=s.arithmetic_flags;
  }
  L006cfda6: { // 0x6cfda6: c745003ceb7800 MOV dword ptr [EBP],0x78eb3c
    m.w32((s.bp), 0x0078eb3cu);
  }
  L006cfdad: { // 0x6cfdad: 8dae60060000 LEA EBP,[ESI + 0x660]
    s.bp = (s.si+0x00000660u);
  }
  L006cfdb3: { // 0x6cfdb3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006cfdb4: { // 0x6cfdb4: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006cfdb6: { // 0x6cfdb6: e8e5a8e3ff CALL 0x0050a6a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0050a6a0u,7142843u); flags=s.arithmetic_flags;
  }
  L006cfdbb: { // 0x6cfdbb: 8dbe8c060000 LEA EDI,[ESI + 0x68c]
    s.di = (s.si+0x0000068cu);
  }
  L006cfdc1: { // 0x6cfdc1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfdc2: { // 0x6cfdc2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfdc3: { // 0x6cfdc3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cfdc5: { // 0x6cfdc5: c745003ceb7800 MOV dword ptr [EBP],0x78eb3c
    m.w32((s.bp), 0x0078eb3cu);
  }
  L006cfdcc: { // 0x6cfdcc: e8cf500000 CALL 0x006d4ea0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4ea0u,7142865u); flags=s.arithmetic_flags;
  }
  L006cfdd1: { // 0x6cfdd1: c707ec7f7900 MOV dword ptr [EDI],0x797fec
    m.w32((s.di), 0x00797fecu);
  }
  L006cfdd7: { // 0x6cfdd7: 8dbea8060000 LEA EDI,[ESI + 0x6a8]
    s.di = (s.si+0x000006a8u);
  }
  L006cfddd: { // 0x6cfddd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfdde: { // 0x6cfdde: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfddf: { // 0x6cfddf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006cfde1: { // 0x6cfde1: e8ba500000 CALL 0x006d4ea0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4ea0u,7142886u); flags=s.arithmetic_flags;
  }
  L006cfde6: { // 0x6cfde6: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L006cfdeb: { // 0x6cfdeb: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L006cfdf0: { // 0x6cfdf0: c707ec7f7900 MOV dword ptr [EDI],0x797fec
    m.w32((s.di), 0x00797fecu);
  }
  L006cfdf6: { // 0x6cfdf6: 898eb00a0000 MOV dword ptr [ESI + 0xab0],ECX
    m.w32((s.si+0x00000ab0u), s.cx);
  }
  L006cfdfc: { // 0x6cfdfc: 8986b40a0000 MOV dword ptr [ESI + 0xab4],EAX
    m.w32((s.si+0x00000ab4u), s.ax);
  }
  L006cfe02: { // 0x6cfe02: 8986b80a0000 MOV dword ptr [ESI + 0xab8],EAX
    m.w32((s.si+0x00000ab8u), s.ax);
  }
  L006cfe08: { // 0x6cfe08: 8986bc0a0000 MOV dword ptr [ESI + 0xabc],EAX
    m.w32((s.si+0x00000abcu), s.ax);
  }
  L006cfe0e: { // 0x6cfe0e: 889ec00a0000 MOV byte ptr [ESI + 0xac0],BL
    m.w8((s.si+0x00000ac0u), (s.bx & 0xffu));
  }
  L006cfe14: { // 0x6cfe14: 898ec40a0000 MOV dword ptr [ESI + 0xac4],ECX
    m.w32((s.si+0x00000ac4u), s.cx);
  }
  L006cfe1a: { // 0x6cfe1a: 8986c80a0000 MOV dword ptr [ESI + 0xac8],EAX
    m.w32((s.si+0x00000ac8u), s.ax);
  }
  L006cfe20: { // 0x6cfe20: 8986cc0a0000 MOV dword ptr [ESI + 0xacc],EAX
    m.w32((s.si+0x00000accu), s.ax);
  }
  L006cfe26: { // 0x6cfe26: 8986d00a0000 MOV dword ptr [ESI + 0xad0],EAX
    m.w32((s.si+0x00000ad0u), s.ax);
  }
  L006cfe2c: { // 0x6cfe2c: 889ed40a0000 MOV byte ptr [ESI + 0xad4],BL
    m.w8((s.si+0x00000ad4u), (s.bx & 0xffu));
  }
  L006cfe32: { // 0x6cfe32: c706287f7900 MOV dword ptr [ESI],0x797f28
    m.w32((s.si), 0x00797f28u);
  }
  L006cfe38: { // 0x6cfe38: c746040c7f7900 MOV dword ptr [ESI + 0x4],0x797f0c
    m.w32((s.si+0x00000004u), 0x00797f0cu);
  }
  L006cfe3f: { // 0x6cfe3f: c74608047f7900 MOV dword ptr [ESI + 0x8],0x797f04
    m.w32((s.si+0x00000008u), 0x00797f04u);
  }
  L006cfe46: { // 0x6cfe46: c7460cfc7e7900 MOV dword ptr [ESI + 0xc],0x797efc
    m.w32((s.si+0x0000000cu), 0x00797efcu);
  }
  L006cfe4d: { // 0x6cfe4d: a10887a200 MOV EAX,[0x00a28708]
    s.ax = m.r32((0x00a28708u));
  }
  L006cfe52: { // 0x6cfe52: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006cfe54: { // 0x6cfe54: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006cfe56: { // 0x6cfe56: 7e12 JLE 0x006cfe6a
    if(integer::condition("JLE",flags)) goto L006cfe6a;
  }
  L006cfe58: { // 0x6cfe58: 8b15fc86a200 MOV EDX,dword ptr [0x00a286fc]
    s.dx = m.r32((0x00a286fcu));
  }
  L006cfe5e: { // 0x6cfe5e: 3932 CMP dword ptr [EDX],ESI
    (void)integer::sub(m.r32((s.dx)),s.si,32,flags);
  }
  L006cfe60: { // 0x6cfe60: 7452 JZ 0x006cfeb4
    if(integer::condition("JZ",flags)) goto L006cfeb4;
  }
  L006cfe62: { // 0x6cfe62: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L006cfe63: { // 0x6cfe63: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L006cfe66: { // 0x6cfe66: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006cfe68: { // 0x6cfe68: 7cf4 JL 0x006cfe5e
    if(integer::condition("JL",flags)) goto L006cfe5e;
  }
  L006cfe6a: { // 0x6cfe6a: 8b0d0087a200 MOV ECX,dword ptr [0x00a28700]
    s.cx = m.r32((0x00a28700u));
  }
  L006cfe70: { // 0x6cfe70: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006cfe72: { // 0x6cfe72: 7c2f JL 0x006cfea3
    if(integer::condition("JL",flags)) goto L006cfea3;
  }
  L006cfe74: { // 0x6cfe74: 381d0587a200 CMP byte ptr [0x00a28705],BL
    (void)integer::sub(m.r8((0x00a28705u)),(s.bx & 0xffu),8,flags);
  }
  L006cfe7a: { // 0x6cfe7a: 7504 JNZ 0x006cfe80
    if(integer::condition("JNZ",flags)) goto L006cfe80;
  }
  L006cfe7c: { // 0x6cfe7c: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L006cfe7e: { // 0x6cfe7e: 7534 JNZ 0x006cfeb4
    if(integer::condition("JNZ",flags)) goto L006cfeb4;
  }
  L006cfe80: { // 0x6cfe80: a10c87a200 MOV EAX,[0x00a2870c]
    s.ax = m.r32((0x00a2870cu));
  }
  L006cfe85: { // 0x6cfe85: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006cfe87: { // 0x6cfe87: 7e2b JLE 0x006cfeb4
    if(integer::condition("JLE",flags)) goto L006cfeb4;
  }
  L006cfe89: { // 0x6cfe89: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006cfe8b: { // 0x6cfe8b: a1f886a200 MOV EAX,[0x00a286f8]
    s.ax = m.r32((0x00a286f8u));
  }
  L006cfe90: { // 0x6cfe90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006cfe91: { // 0x6cfe91: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006cfe92: { // 0x6cfe92: b9f886a200 MOV ECX,0xa286f8
    s.cx = 0x00a286f8u;
  }
  L006cfe97: { // 0x6cfe97: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),7143066u); flags=s.arithmetic_flags;
  }
  L006cfe9a: { // 0x6cfe9a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cfe9c: { // 0x6cfe9c: 7416 JZ 0x006cfeb4
    if(integer::condition("JZ",flags)) goto L006cfeb4;
  }
  L006cfe9e: { // 0x6cfe9e: a10887a200 MOV EAX,[0x00a28708]
    s.ax = m.r32((0x00a28708u));
  }
  L006cfea3: { // 0x6cfea3: 8b15fc86a200 MOV EDX,dword ptr [0x00a286fc]
    s.dx = m.r32((0x00a286fcu));
  }
  L006cfea9: { // 0x6cfea9: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006cfeab: { // 0x6cfeab: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006cfeac: { // 0x6cfeac: a30887a200 MOV [0x00a28708],EAX
    m.w32((0x00a28708u), s.ax);
  }
  L006cfeb1: { // 0x6cfeb1: 89348a MOV dword ptr [EDX + ECX*0x4],ESI
    m.w32((s.dx+(s.cx * 0x00000004u)), s.si);
  }
  L006cfeb4: { // 0x6cfeb4: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L006cfeb6: { // 0x6cfeb6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006cfeb7: { // 0x6cfeb7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cfeb8: { // 0x6cfeb8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006cfeb9: { // 0x6cfeb9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006cfeba: { // 0x6cfeba: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
