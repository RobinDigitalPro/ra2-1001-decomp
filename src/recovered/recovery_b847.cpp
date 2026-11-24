#include "recovered/recovery_b847_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b847 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_0005e970(Memory&,State&,Frame&,const Operations&);
void f_00307f60(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_000f4da0(Memory&,State&,Frame&,const Operations&);
void f_0007ddc0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void tail(Memory&,State&,Frame&,std::uint32_t);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // 0x6b6912: ffa084000000 JMP dword ptr [EAX + 0x84]
    switch(m.r32((s.ax+0x00000084u))){
    case 7039248u:goto L006b6910;
    case 7039250u:goto L006b6912;
    default:s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.ax+0x00000084u))); return;}
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0005e970(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e970: { // 0x45e970: b807000000 MOV EAX, 7
    s.ax = 7u;
  }
  L0045e975: { // 0x45e975: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707f60: { // 0x707f60: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f62: { // 0x707f62: dc1d08577800 FCOMP qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f68: { // 0x707f68: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f6a: { // 0x707f6a: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f6d: { // 0x707f6d: 7515 JNZ 0x707f84
    if(integer::condition("JNZ",flags)) goto L00707f84;
  }
  L00707f6f: { // 0x707f6f: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f71: { // 0x707f71: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f77: { // 0x707f77: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f79: { // 0x707f79: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f7c: { // 0x707f7c: 7406 JZ 0x707f84
    if(integer::condition("JZ",flags)) goto L00707f84;
  }
  L00707f7e: { // 0x707f7e: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707f83: { // 0x707f83: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707f84: { // 0x707f84: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707f86: { // 0x707f86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
void f_000f4da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f4da0: { // 0x4f4da0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004f4da1: { // 0x4f4da1: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004f4da2: { // 0x4f4da2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L004f4da6: { // 0x4f4da6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L004f4da8: { // 0x4f4da8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L004f4daa: { // 0x4f4daa: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L004f4dac: { // 0x4f4dac: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5197231u); flags=s.arithmetic_flags;
  }
  L004f4daf: { // 0x4f4daf: 83c0fd ADD EAX,-0x3
    s.ax = integer::add(s.ax,0xfffffffdu,32,flags);
  }
  L004f4db2: { // 0x4f4db2: 83f825 CMP EAX,0x25
    (void)integer::sub(s.ax,0x00000025u,32,flags);
  }
  L004f4db5: { // 0x4f4db5: 775e JA 0x004f4e15
    if(integer::condition("JA",flags)) goto L004f4e15;
  }
  L004f4db7: { // 0x4f4db7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004f4db9: { // 0x4f4db9: 8a88344e4f00 MOV CL,byte ptr [EAX + 0x4f4e34]
    s.cx = with_al(s.cx, m.r8((s.ax+0x004f4e34u)));
  }
  L004f4dbf: { // 0x4f4dbf: ff248d204e4f00 JMP dword ptr [ECX*0x4 + 0x4f4e20]
    switch(m.r32(((s.cx * 0x00000004u)+0x004f4e20u))){
    case 5197216u:goto L004f4da0;
    case 5197217u:goto L004f4da1;
    case 5197218u:goto L004f4da2;
    case 5197222u:goto L004f4da6;
    case 5197224u:goto L004f4da8;
    case 5197226u:goto L004f4daa;
    case 5197228u:goto L004f4dac;
    case 5197231u:goto L004f4daf;
    case 5197234u:goto L004f4db2;
    case 5197237u:goto L004f4db5;
    case 5197239u:goto L004f4db7;
    case 5197241u:goto L004f4db9;
    case 5197247u:goto L004f4dbf;
    case 5197254u:goto L004f4dc6;
    case 5197257u:goto L004f4dc9;
    case 5197258u:goto L004f4dca;
    case 5197259u:goto L004f4dcb;
    case 5197265u:goto L004f4dd1;
    case 5197268u:goto L004f4dd4;
    case 5197271u:goto L004f4dd7;
    case 5197272u:goto L004f4dd8;
    case 5197273u:goto L004f4dd9;
    case 5197279u:goto L004f4ddf;
    case 5197282u:goto L004f4de2;
    case 5197285u:goto L004f4de5;
    case 5197286u:goto L004f4de6;
    case 5197287u:goto L004f4de7;
    case 5197293u:goto L004f4ded;
    case 5197296u:goto L004f4df0;
    case 5197303u:goto L004f4df7;
    case 5197305u:goto L004f4df9;
    case 5197308u:goto L004f4dfc;
    case 5197309u:goto L004f4dfd;
    case 5197310u:goto L004f4dfe;
    case 5197316u:goto L004f4e04;
    case 5197319u:goto L004f4e07;
    case 5197322u:goto L004f4e0a;
    case 5197323u:goto L004f4e0b;
    case 5197324u:goto L004f4e0c;
    case 5197330u:goto L004f4e12;
    case 5197333u:goto L004f4e15;
    case 5197339u:goto L004f4e1b;
    case 5197340u:goto L004f4e1c;
    case 5197341u:goto L004f4e1d;
    default:s.arithmetic_flags=flags; tail(m,s,f,m.r32(((s.cx * 0x00000004u)+0x004f4e20u))); return;}
  }
  L004f4dc6: { // 0x4f4dc6: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004f4dc9: { // 0x4f4dc9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4dca: { // 0x4f4dca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4dcb: { // 0x4f4dcb: d98200010000 FLD float ptr [EDX + 0x100]
    const auto address=(s.dx+0x00000100u);
    s.fp.load32(m.r32(address));
  }
  L004f4dd1: { // 0x4f4dd1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4dd4: { // 0x4f4dd4: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L004f4dd7: { // 0x4f4dd7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4dd8: { // 0x4f4dd8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4dd9: { // 0x4f4dd9: d98004010000 FLD float ptr [EAX + 0x104]
    const auto address=(s.ax+0x00000104u);
    s.fp.load32(m.r32(address));
  }
  L004f4ddf: { // 0x4f4ddf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4de2: { // 0x4f4de2: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  L004f4de5: { // 0x4f4de5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4de6: { // 0x4f4de6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4de7: { // 0x4f4de7: d98108010000 FLD float ptr [ECX + 0x108]
    const auto address=(s.cx+0x00000108u);
    s.fp.load32(m.r32(address));
  }
  L004f4ded: { // 0x4f4ded: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4df0: { // 0x4f4df0: 83bfa00b000005 CMP dword ptr [EDI + 0xba0],0x5
    (void)integer::sub(m.r32((s.di+0x00000ba0u)),0x00000005u,32,flags);
  }
  L004f4df7: { // 0x4f4df7: 750e JNZ 0x004f4e07
    if(integer::condition("JNZ",flags)) goto L004f4e07;
  }
  L004f4df9: { // 0x4f4df9: 8b5634 MOV EDX,dword ptr [ESI + 0x34]
    s.dx = m.r32((s.si+0x00000034u));
  }
  L004f4dfc: { // 0x4f4dfc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4dfd: { // 0x4f4dfd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4dfe: { // 0x4f4dfe: d98210010000 FLD float ptr [EDX + 0x110]
    const auto address=(s.dx+0x00000110u);
    s.fp.load32(m.r32(address));
  }
  L004f4e04: { // 0x4f4e04: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4e07: { // 0x4f4e07: 8b4634 MOV EAX,dword ptr [ESI + 0x34]
    s.ax = m.r32((s.si+0x00000034u));
  }
  L004f4e0a: { // 0x4f4e0a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4e0b: { // 0x4f4e0b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4e0c: { // 0x4f4e0c: d9800c010000 FLD float ptr [EAX + 0x10c]
    const auto address=(s.ax+0x0000010cu);
    s.fp.load32(m.r32(address));
  }
  L004f4e12: { // 0x4f4e12: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004f4e15: { // 0x4f4e15: d905f8677800 FLD float ptr [0x007867f8]
    const auto address=(0x007867f8u);
    s.fp.load32(m.r32(address));
  }
  L004f4e1b: { // 0x4f4e1b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004f4e1c: { // 0x4f4e1c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004f4e1d: { // 0x4f4e1d: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_0007ddc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047ddc0: { // 0x47ddc0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0047ddc3: { // 0x47ddc3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0047ddc4: { // 0x47ddc4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0047ddc6: { // 0x47ddc6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0047ddc7: { // 0x47ddc7: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0047ddc9: { // 0x47ddc9: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047ddcb: { // 0x47ddcb: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L0047ddcf: { // 0x47ddcf: 0f84ce000000 JZ 0x0047dea3
    if(integer::condition("JZ",flags)) goto L0047dea3;
  }
  L0047ddd5: { // 0x47ddd5: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0047ddda: { // 0x47ddda: f60020 TEST byte ptr [EAX],0x20
    (void)integer::logical((m.r8((s.ax)))&(0x00000020u),8,flags);
  }
  L0047dddd: { // 0x47dddd: 0f85c0000000 JNZ 0x0047dea3
    if(integer::condition("JNZ",flags)) goto L0047dea3;
  }
  L0047dde3: { // 0x47dde3: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0047dde5: { // 0x47dde5: 0f84b8000000 JZ 0x0047dea3
    if(integer::condition("JZ",flags)) goto L0047dea3;
  }
  L0047ddeb: { // 0x47ddeb: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047dded: { // 0x47dded: 7d17 JGE 0x0047de06
    if(integer::condition("JGE",flags)) goto L0047de06;
  }
  L0047ddef: { // 0x47ddef: 8b7c241c MOV EDI,dword ptr [ESP + 0x1c]
    s.di = m.r32((f.sp+0x0000001cu));
  }
  L0047ddf3: { // 0x47ddf3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0047ddf5: { // 0x47ddf5: 83ff08 CMP EDI,0x8
    (void)integer::sub(s.di,0x00000008u,32,flags);
  }
  L0047ddf8: { // 0x47ddf8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047ddf9: { // 0x47ddf9: 0f9dc0 SETGE AL
    s.ax = with_al(s.ax, (integer::condition("JGE",flags)?1u:0u));
  }
  L0047ddfc: { // 0x47ddfc: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0047ddfd: { // 0x47ddfd: 23c6 AND EAX,ESI
    s.ax = integer::logical((s.ax)&(s.si),32,flags);
  }
  L0047ddff: { // 0x47ddff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047de00: { // 0x47de00: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0047de03: { // 0x47de03: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0047de06: { // 0x47de06: db44240c FILD dword ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0047de0a: { // 0x47de0a: d9542408 FST float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.store32();
    m.w32(address,value);
  }
  L0047de0e: { // 0x47de0e: d88f2c010000 FMUL float ptr [EDI + 0x12c]
    const auto address=(s.di+0x0000012cu);
    s.fp.multiply32(m.r32(address));
  }
  L0047de14: { // 0x47de14: d95c240c FSTP float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L0047de18: { // 0x47de18: d98724010000 FLD float ptr [EDI + 0x124]
    const auto address=(s.di+0x00000124u);
    s.fp.load32(m.r32(address));
  }
  L0047de1e: { // 0x47de1e: d80dac607800 FMUL float ptr [0x007860ac]
    const auto address=(0x007860acu);
    s.fp.multiply32(m.r32(address));
  }
  L0047de24: { // 0x47de24: e827cc2e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4709929u); flags=s.arithmetic_flags;
  }
  L0047de29: { // 0x47de29: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L0047de2d: { // 0x47de2d: d85c2408 FCOMP float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.compare_pop32(m.r32(address));
  }
  L0047de31: { // 0x47de31: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0047de33: { // 0x47de33: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0047de37: { // 0x47de37: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0047de39: { // 0x47de39: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L0047de3c: { // 0x47de3c: 7529 JNZ 0x0047de67
    if(integer::condition("JNZ",flags)) goto L0047de67;
  }
  L0047de3e: { // 0x47de3e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0047de40: { // 0x47de40: 7425 JZ 0x0047de67
    if(integer::condition("JZ",flags)) goto L0047de67;
  }
  L0047de42: { // 0x47de42: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0047de46: { // 0x47de46: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L0047de4a: { // 0x47de4a: d864240c FSUB float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.subtract32(m.r32(address));
  }
  L0047de4e: { // 0x47de4e: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0047de50: { // 0x47de50: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0047de54: { // 0x47de54: da4c241c FIMUL dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    multiply_integer32(s.fp,m.r32(address));
  }
  L0047de58: { // 0x47de58: da742410 FIDIV dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.divide_integer32(m.r32(address));
  }
  L0047de5c: { // 0x47de5c: d844240c FADD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.add32(m.r32(address));
  }
  L0047de60: { // 0x47de60: e8ebcb2e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4709989u); flags=s.arithmetic_flags;
  }
  L0047de65: { // 0x47de65: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0047de67: { // 0x47de67: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0047de69: { // 0x47de69: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0047de6d: { // 0x47de6d: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0047de6f: { // 0x47de6f: 0f9ec1 SETLE CL
    s.cx = with_al(s.cx, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0047de72: { // 0x47de72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0047de73: { // 0x47de73: 23ce AND ECX,ESI
    s.cx = integer::logical((s.cx)&(s.si),32,flags);
  }
  L0047de75: { // 0x47de75: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0047de79: { // 0x47de79: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L0047de7d: { // 0x47de7d: dc8cd7a0000000 FMUL double ptr [EDI + EDX*0x8 + 0xa0]
    const auto address=(s.di+(s.dx * 0x00000008u)+0x000000a0u);
    s.fp.multiply64(read64(m,address));
  }
  L0047de84: { // 0x47de84: e8c7cb2e00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4710025u); flags=s.arithmetic_flags;
  }
  L0047de89: { // 0x47de89: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0047de8f: { // 0x47de8f: 8b8930130000 MOV ECX,dword ptr [ECX + 0x1330]
    s.cx = m.r32((s.cx+0x00001330u));
  }
  L0047de95: { // 0x47de95: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0047de97: { // 0x47de97: 7c0c JL 0x0047dea5
    if(integer::condition("JL",flags)) goto L0047dea5;
  }
  L0047de99: { // 0x47de99: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047de9a: { // 0x47de9a: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047de9c: { // 0x47de9c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047de9d: { // 0x47de9d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0047dea0: { // 0x47dea0: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0047dea3: { // 0x47dea3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0047dea5: { // 0x47dea5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0047dea6: { // 0x47dea6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0047dea7: { // 0x47dea7: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0047deaa: { // 0x47deaa: c20800 RET 0x8
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7039248u:f_002b6910(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4581744u:f_0005e970(m,s,child,{});break;
case 7372640u:f_00307f60(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 5197216u:f_000f4da0(m,s,child,{});break;
case 4709824u:f_0007ddc0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery847 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){switch(target){case 7039248u:f_002b6910(m,s,f,{});return;case 4536496u:f_000538b0(m,s,f,{});return;case 4581744u:f_0005e970(m,s,f,{});return;case 7372640u:f_00307f60(m,s,f,{});return;case 7372768u:f_00307fe0(m,s,f,{});return;case 5197216u:f_000f4da0(m,s,f,{});return;case 4709824u:f_0007ddc0(m,s,f,{});return;case 7776848u:f_0036aa50(m,s,f,{});return;default:throw std::domain_error("B847 unexpected tail target");}}}

std::uint32_t fun_006bfc80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 std::array<std::uint8_t,58> table{226,77,79,0,240,77,79,0,198,77,79,0,212,77,79,0,21,78,79,0,0,4,4,4,1,4,4,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3};
 leaf::Memory jump_table(table.data(),0x4f4e20u,58);m.add(jump_table);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006bfc80: { // 0x6bfc80: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L006bfc83: { // 0x6bfc83: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006bfc84: { // 0x6bfc84: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006bfc85: { // 0x6bfc85: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  L006bfc89: { // 0x6bfc89: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006bfc8b: { // 0x6bfc8b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006bfc8d: { // 0x6bfc8d: 0f84a5010000 JZ 0x006bfe38
    if(integer::condition("JZ",flags)) goto L006bfe38;
  }
  L006bfc93: { // 0x6bfc93: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L006bfc97: { // 0x6bfc97: 8a910c010000 MOV DL,byte ptr [ECX + 0x10c]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000010cu)));
  }
  L006bfc9d: { // 0x6bfc9d: 8b81a4000000 MOV EAX,dword ptr [ECX + 0xa4]
    s.ax = m.r32((s.cx+0x000000a4u));
  }
  L006bfca3: { // 0x6bfca3: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006bfca5: { // 0x6bfca5: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L006bfca9: { // 0x6bfca9: 0f8589010000 JNZ 0x006bfe38
    if(integer::condition("JNZ",flags)) goto L006bfe38;
  }
  L006bfcaf: { // 0x6bfcaf: 8a9105010000 MOV DL,byte ptr [ECX + 0x105]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000105u)));
  }
  L006bfcb5: { // 0x6bfcb5: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006bfcb7: { // 0x6bfcb7: 0f857b010000 JNZ 0x006bfe38
    if(integer::condition("JNZ",flags)) goto L006bfe38;
  }
  L006bfcbd: { // 0x6bfcbd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006bfcbf: { // 0x6bfcbf: 0f8e75010000 JLE 0x006bfe3a
    if(integer::condition("JLE",flags)) goto L006bfe3a;
  }
  L006bfcc5: { // 0x6bfcc5: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006bfccb: { // 0x6bfccb: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006bfccc: { // 0x6bfccc: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006bfccd: { // 0x6bfccd: dd80d0000000 FLD double ptr [EAX + 0xd0]
    const auto address=(s.ax+0x000000d0u);
    s.fp.load64(read64(m,address));
  }
  L006bfcd3: { // 0x6bfcd3: dc8e28010000 FMUL double ptr [ESI + 0x128]
    const auto address=(s.si+0x00000128u);
    s.fp.multiply64(read64(m,address));
  }
  L006bfcd9: { // 0x6bfcd9: da4c241c FIMUL dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    multiply_integer32(s.fp,m.r32(address));
  }
  L006bfcdd: { // 0x6bfcdd: e86ead0a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7077090u); flags=s.arithmetic_flags;
  }
  L006bfce2: { // 0x6bfce2: 8dae18010000 LEA EBP,[ESI + 0x118]
    s.bp = (s.si+0x00000118u);
  }
  L006bfce8: { // 0x6bfce8: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006bfcec: { // 0x6bfcec: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bfcee: { // 0x6bfcee: e86d820400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7077107u); flags=s.arithmetic_flags;
  }
  L006bfcf3: { // 0x6bfcf3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfcf5: { // 0x6bfcf5: 750b JNZ 0x006bfd02
    if(integer::condition("JNZ",flags)) goto L006bfd02;
  }
  L006bfcf7: { // 0x6bfcf7: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bfcf9: { // 0x6bfcf9: e8e2820400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7077118u); flags=s.arithmetic_flags;
  }
  L006bfcfe: { // 0x6bfcfe: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfd00: { // 0x6bfd00: 7458 JZ 0x006bfd5a
    if(integer::condition("JZ",flags)) goto L006bfd5a;
  }
  L006bfd02: { // 0x6bfd02: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006bfd04: { // 0x6bfd04: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bfd06: { // 0x6bfd06: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7077132u); flags=s.arithmetic_flags;
  }
  L006bfd0c: { // 0x6bfd0c: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bfd0e: { // 0x6bfd0e: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006bfd10: { // 0x6bfd10: e84b820400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7077141u); flags=s.arithmetic_flags;
  }
  L006bfd15: { // 0x6bfd15: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfd17: { // 0x6bfd17: 740a JZ 0x006bfd23
    if(integer::condition("JZ",flags)) goto L006bfd23;
  }
  L006bfd19: { // 0x6bfd19: 8a836e020000 MOV AL,byte ptr [EBX + 0x26e]
    s.ax = with_al(s.ax, m.r8((s.bx+0x0000026eu)));
  }
  L006bfd1f: { // 0x6bfd1f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfd21: { // 0x6bfd21: 751f JNZ 0x006bfd42
    if(integer::condition("JNZ",flags)) goto L006bfd42;
  }
  L006bfd23: { // 0x6bfd23: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L006bfd25: { // 0x6bfd25: e8b6820400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7077162u); flags=s.arithmetic_flags;
  }
  L006bfd2a: { // 0x6bfd2a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfd2c: { // 0x6bfd2c: 742c JZ 0x006bfd5a
    if(integer::condition("JZ",flags)) goto L006bfd5a;
  }
  L006bfd2e: { // 0x6bfd2e: 8a836e020000 MOV AL,byte ptr [EBX + 0x26e]
    s.ax = with_al(s.ax, m.r8((s.bx+0x0000026eu)));
  }
  L006bfd34: { // 0x6bfd34: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfd36: { // 0x6bfd36: 750a JNZ 0x006bfd42
    if(integer::condition("JNZ",flags)) goto L006bfd42;
  }
  L006bfd38: { // 0x6bfd38: 8a8380020000 MOV AL,byte ptr [EBX + 0x280]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000280u)));
  }
  L006bfd3e: { // 0x6bfd3e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfd40: { // 0x6bfd40: 7418 JZ 0x006bfd5a
    if(integer::condition("JZ",flags)) goto L006bfd5a;
  }
  L006bfd42: { // 0x6bfd42: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006bfd46: { // 0x6bfd46: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006bfd4b: { // 0x6bfd4b: dc8890050000 FMUL double ptr [EAX + 0x590]
    const auto address=(s.ax+0x00000590u);
    s.fp.multiply64(read64(m,address));
  }
  L006bfd51: { // 0x6bfd51: e8faac0a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7077206u); flags=s.arithmetic_flags;
  }
  L006bfd56: { // 0x6bfd56: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006bfd5a: { // 0x6bfd5a: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006bfd5e: { // 0x6bfd5e: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006bfd60: { // 0x6bfd60: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bfd62: { // 0x6bfd62: dd5c2410 FSTP double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006bfd66: { // 0x6bfd66: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7077228u); flags=s.arithmetic_flags;
  }
  L006bfd6c: { // 0x6bfd6c: 8b8fb4010000 MOV ECX,dword ptr [EDI + 0x1b4]
    s.cx = m.r32((s.di+0x000001b4u));
  }
  L006bfd72: { // 0x6bfd72: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006bfd73: { // 0x6bfd73: e82850e3ff CALL 0x004f4da0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f4da0u,7077240u); flags=s.arithmetic_flags;
  }
  L006bfd78: { // 0x6bfd78: dc8e20010000 FMUL double ptr [ESI + 0x120]
    const auto address=(s.si+0x00000120u);
    s.fp.multiply64(read64(m,address));
  }
  L006bfd7e: { // 0x6bfd7e: dc7c2410 FDIVR double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    reverse_divide64(s.fp,read64(m,address));
  }
  L006bfd82: { // 0x6bfd82: e8c9ac0a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7077255u); flags=s.arithmetic_flags;
  }
  L006bfd87: { // 0x6bfd87: 8db718010000 LEA ESI,[EDI + 0x118]
    s.si = (s.di+0x00000118u);
  }
  L006bfd8d: { // 0x6bfd8d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006bfd8f: { // 0x6bfd8f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bfd91: { // 0x6bfd91: 895c241c MOV dword ptr [ESP + 0x1c],EBX
    m.w32((f.sp+0x0000001cu), s.bx);
  }
  L006bfd95: { // 0x6bfd95: e8c6810400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7077274u); flags=s.arithmetic_flags;
  }
  L006bfd9a: { // 0x6bfd9a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfd9c: { // 0x6bfd9c: 750b JNZ 0x006bfda9
    if(integer::condition("JNZ",flags)) goto L006bfda9;
  }
  L006bfd9e: { // 0x6bfd9e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bfda0: { // 0x6bfda0: e83b820400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7077285u); flags=s.arithmetic_flags;
  }
  L006bfda5: { // 0x6bfda5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfda7: { // 0x6bfda7: 7457 JZ 0x006bfe00
    if(integer::condition("JZ",flags)) goto L006bfe00;
  }
  L006bfda9: { // 0x6bfda9: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006bfdab: { // 0x6bfdab: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bfdad: { // 0x6bfdad: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7077299u); flags=s.arithmetic_flags;
  }
  L006bfdb3: { // 0x6bfdb3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bfdb5: { // 0x6bfdb5: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L006bfdb7: { // 0x6bfdb7: e8a4810400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7077308u); flags=s.arithmetic_flags;
  }
  L006bfdbc: { // 0x6bfdbc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfdbe: { // 0x6bfdbe: 740a JZ 0x006bfdca
    if(integer::condition("JZ",flags)) goto L006bfdca;
  }
  L006bfdc0: { // 0x6bfdc0: 8a856d020000 MOV AL,byte ptr [EBP + 0x26d]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000026du)));
  }
  L006bfdc6: { // 0x6bfdc6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfdc8: { // 0x6bfdc8: 751f JNZ 0x006bfde9
    if(integer::condition("JNZ",flags)) goto L006bfde9;
  }
  L006bfdca: { // 0x6bfdca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006bfdcc: { // 0x6bfdcc: e80f820400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7077329u); flags=s.arithmetic_flags;
  }
  L006bfdd1: { // 0x6bfdd1: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfdd3: { // 0x6bfdd3: 742b JZ 0x006bfe00
    if(integer::condition("JZ",flags)) goto L006bfe00;
  }
  L006bfdd5: { // 0x6bfdd5: 8a856d020000 MOV AL,byte ptr [EBP + 0x26d]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000026du)));
  }
  L006bfddb: { // 0x6bfddb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfddd: { // 0x6bfddd: 750a JNZ 0x006bfde9
    if(integer::condition("JNZ",flags)) goto L006bfde9;
  }
  L006bfddf: { // 0x6bfddf: 8a857f020000 MOV AL,byte ptr [EBP + 0x27f]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000027fu)));
  }
  L006bfde5: { // 0x6bfde5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006bfde7: { // 0x6bfde7: 7417 JZ 0x006bfe00
    if(integer::condition("JZ",flags)) goto L006bfe00;
  }
  L006bfde9: { // 0x6bfde9: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006bfded: { // 0x6bfded: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006bfdf3: { // 0x6bfdf3: dcb1a8050000 FDIV double ptr [ECX + 0x5a8]
    const auto address=(s.cx+0x000005a8u);
    s.fp.divide64(read64(m,address));
  }
  L006bfdf9: { // 0x6bfdf9: e852ac0a00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7077374u); flags=s.arithmetic_flags;
  }
  L006bfdfe: { // 0x6bfdfe: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006bfe00: { // 0x6bfe00: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  L006bfe03: { // 0x6bfe03: 7d05 JGE 0x006bfe0a
    if(integer::condition("JGE",flags)) goto L006bfe0a;
  }
  L006bfe05: { // 0x6bfe05: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  L006bfe0a: { // 0x6bfe0a: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006bfe0c: { // 0x6bfe0c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006bfe0e: { // 0x6bfe0e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006bfe10: { // 0x6bfe10: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),7077398u); flags=s.arithmetic_flags;
  }
  L006bfe16: { // 0x6bfe16: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L006bfe1a: { // 0x6bfe1a: 8b809c000000 MOV EAX,dword ptr [EAX + 0x9c]
    s.ax = m.r32((s.ax+0x0000009cu));
  }
  L006bfe20: { // 0x6bfe20: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006bfe21: { // 0x6bfe21: 8b91ac000000 MOV EDX,dword ptr [ECX + 0xac]
    s.dx = m.r32((s.cx+0x000000acu));
  }
  L006bfe27: { // 0x6bfe27: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006bfe29: { // 0x6bfe29: e892dfdbff CALL 0x0047ddc0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047ddc0u,7077422u); flags=s.arithmetic_flags;
  }
  L006bfe2e: { // 0x6bfe2e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006bfe2f: { // 0x6bfe2f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006bfe30: { // 0x6bfe30: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bfe31: { // 0x6bfe31: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bfe32: { // 0x6bfe32: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006bfe35: { // 0x6bfe35: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006bfe38: { // 0x6bfe38: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006bfe3a: { // 0x6bfe3a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006bfe3b: { // 0x6bfe3b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006bfe3c: { // 0x6bfe3c: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006bfe3f: { // 0x6bfe3f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
