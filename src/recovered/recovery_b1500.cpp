#include "recovered/recovery_b1500_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
#ifdef __clang__
#pragma clang diagnostic ignored "-Wunused-label"
#endif
#include <sstream>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::b1500 {
namespace {
inline unsigned debug_va=0;
inline auto checked_r8(Memory&m,unsigned a){try{return m.r8(a);}catch(const std::exception&e){std::ostringstream o;o<<e.what()<<" read8 VA "<<std::hex<<debug_va<<" address "<<a;throw std::runtime_error(o.str());}}
inline auto checked_r16(Memory&m,unsigned a){try{return m.r16(a);}catch(const std::exception&e){std::ostringstream o;o<<e.what()<<" read16 VA "<<std::hex<<debug_va<<" address "<<a;throw std::runtime_error(o.str());}}
inline auto checked_r32(Memory&m,unsigned a){try{return m.r32(a);}catch(const std::exception&e){std::ostringstream o;o<<e.what()<<" read32 VA "<<std::hex<<debug_va<<" address "<<a;throw std::runtime_error(o.str());}}
void f_0009ebd0(Memory&,State&,Frame&,const Operations&);
void f_0002bcd0(Memory&,State&,Frame&,const Operations&);
void f_0009f150(Memory&,State&,Frame&,const Operations&);
void f_00038140(Memory&,State&,Frame&,const Operations&);
void f_00038290(Memory&,State&,Frame&,const Operations&);
void f_00085b40(Memory&,State&,Frame&,const Operations&);
void f_00034f80(Memory&,State&,Frame&,const Operations&);
void f_00360ad0(Memory&,State&,Frame&,const Operations&);
void f_00035420(Memory&,State&,Frame&,const Operations&);
void f_00035400(Memory&,State&,Frame&,const Operations&);
void f_00011370(Memory&,State&,Frame&,const Operations&);
void f_000112f0(Memory&,State&,Frame&,const Operations&);
void f_000113b0(Memory&,State&,Frame&,const Operations&);
void f_000113c0(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_00361c80(Memory&,State&,Frame&,const Operations&);
void f_00011230(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_00086460(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0009ebd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049ebd0: { // 0x49ebd0: 83ec6c SUB ESP,0x6c
    debug_va=0x0049ebd0u;
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L0049ebd3: { // 0x49ebd3: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    debug_va=0x0049ebd3u;
    s.ax = checked_r32(m,(f.sp+0x00000084u));
  }
  L0049ebda: { // 0x49ebda: 53 PUSH EBX
    debug_va=0x0049ebdau;
    f.push(m,s.bx);
  }
  L0049ebdb: { // 0x49ebdb: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    debug_va=0x0049ebdbu;
    s.bx = checked_r32(m,(f.sp+0x00000074u));
  }
  L0049ebdf: { // 0x49ebdf: 89827c010000 MOV dword ptr [EDX + 0x17c],EAX
    debug_va=0x0049ebdfu;
    m.w32((s.dx+0x0000017cu), s.ax);
  }
  L0049ebe5: { // 0x49ebe5: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    debug_va=0x0049ebe5u;
    s.ax = checked_r32(m,(f.sp+0x0000007cu));
  }
  L0049ebe9: { // 0x49ebe9: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    debug_va=0x0049ebe9u;
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0049ebed: { // 0x49ebed: 89542410 MOV dword ptr [ESP + 0x10],EDX
    debug_va=0x0049ebedu;
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ebf1: { // 0x49ebf1: 55 PUSH EBP
    debug_va=0x0049ebf1u;
    f.push(m,s.bp);
  }
  L0049ebf2: { // 0x49ebf2: 8b08 MOV ECX,dword ptr [EAX]
    debug_va=0x0049ebf2u;
    s.cx = checked_r32(m,(s.ax));
  }
  L0049ebf4: { // 0x49ebf4: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    debug_va=0x0049ebf4u;
    s.dx = checked_r32(m,(s.ax+0x00000004u));
  }
  L0049ebf7: { // 0x49ebf7: 0fbf4306 MOVSX EAX,word ptr [EBX + 0x6]
    debug_va=0x0049ebf7u;
    s.ax = std::uint32_t(integer::sign_extend(checked_r16(m,(s.bx+0x00000006u)),16));
  }
  L0049ebfb: { // 0x49ebfb: 8b6c247c MOV EBP,dword ptr [ESP + 0x7c]
    debug_va=0x0049ebfbu;
    s.bp = checked_r32(m,(f.sp+0x0000007cu));
  }
  L0049ebff: { // 0x49ebff: 56 PUSH ESI
    debug_va=0x0049ebffu;
    f.push(m,s.si);
  }
  L0049ec00: { // 0x49ec00: 3be8 CMP EBP,EAX
    debug_va=0x0049ec00u;
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0049ec02: { // 0x49ec02: 57 PUSH EDI
    debug_va=0x0049ec02u;
    f.push(m,s.di);
  }
  L0049ec03: { // 0x49ec03: 898c2488000000 MOV dword ptr [ESP + 0x88],ECX
    debug_va=0x0049ec03u;
    m.w32((f.sp+0x00000088u), s.cx);
  }
  L0049ec0a: { // 0x49ec0a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    debug_va=0x0049ec0au;
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ec0e: { // 0x49ec0e: 7337 JNC 0x0049ec47
    debug_va=0x0049ec0eu;
    if(integer::condition("JNC",flags)) goto L0049ec47;
  }
  L0049ec10: { // 0x49ec10: 8d4c6d00 LEA ECX,[EBP + EBP*0x2]
    debug_va=0x0049ec10u;
    s.cx = (s.bp+(s.bp * 0x00000002u));
  }
  L0049ec14: { // 0x49ec14: 8d44cb08 LEA EAX,[EBX + ECX*0x8 + 0x8]
    debug_va=0x0049ec14u;
    s.ax = (s.bx+(s.cx * 0x00000008u)+0x00000008u);
  }
  L0049ec18: { // 0x49ec18: 85c0 TEST EAX,EAX
    debug_va=0x0049ec18u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec1a: { // 0x49ec1a: 742b JZ 0x0049ec47
    debug_va=0x0049ec1au;
    if(integer::condition("JZ",flags)) goto L0049ec47;
  }
  L0049ec1c: { // 0x49ec1c: 0fbf5006 MOVSX EDX,word ptr [EAX + 0x6]
    debug_va=0x0049ec1cu;
    s.dx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax+0x00000006u)),16));
  }
  L0049ec20: { // 0x49ec20: 0fbf4804 MOVSX ECX,word ptr [EAX + 0x4]
    debug_va=0x0049ec20u;
    s.cx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax+0x00000004u)),16));
  }
  L0049ec24: { // 0x49ec24: 52 PUSH EDX
    debug_va=0x0049ec24u;
    f.push(m,s.dx);
  }
  L0049ec25: { // 0x49ec25: 51 PUSH ECX
    debug_va=0x0049ec25u;
    f.push(m,s.cx);
  }
  L0049ec26: { // 0x49ec26: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    debug_va=0x0049ec26u;
    s.dx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax+0x00000002u)),16));
  }
  L0049ec2a: { // 0x49ec2a: 0fbf00 MOVSX EAX,word ptr [EAX]
    debug_va=0x0049ec2au;
    s.ax = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax)),16));
  }
  L0049ec2d: { // 0x49ec2d: 52 PUSH EDX
    debug_va=0x0049ec2du;
    f.push(m,s.dx);
  }
  L0049ec2e: { // 0x49ec2e: 50 PUSH EAX
    debug_va=0x0049ec2eu;
    f.push(m,s.ax);
  }
  L0049ec2f: { // 0x49ec2f: 8d4c245c LEA ECX,[ESP + 0x5c]
    debug_va=0x0049ec2fu;
    s.cx = (f.sp+0x0000005cu);
  }
  L0049ec33: { // 0x49ec33: e898d0f8ff CALL 0x0042bcd0
    debug_va=0x0049ec33u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042bcd0u,4844600u); flags=s.arithmetic_flags;
  }
  L0049ec38: { // 0x49ec38: 8bd0 MOV EDX,EAX
    debug_va=0x0049ec38u;
    s.dx = s.ax;
  }
  L0049ec3a: { // 0x49ec3a: 8b02 MOV EAX,dword ptr [EDX]
    debug_va=0x0049ec3au;
    s.ax = checked_r32(m,(s.dx));
  }
  L0049ec3c: { // 0x49ec3c: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    debug_va=0x0049ec3cu;
    s.cx = checked_r32(m,(s.dx+0x00000004u));
  }
  L0049ec3f: { // 0x49ec3f: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    debug_va=0x0049ec3fu;
    s.si = checked_r32(m,(s.dx+0x00000008u));
  }
  L0049ec42: { // 0x49ec42: 8b7a0c MOV EDI,dword ptr [EDX + 0xc]
    debug_va=0x0049ec42u;
    s.di = checked_r32(m,(s.dx+0x0000000cu));
  }
  L0049ec45: { // 0x49ec45: eb17 JMP 0x0049ec5e
    debug_va=0x0049ec45u;
    goto L0049ec5e;
  }
  L0049ec47: { // 0x49ec47: a180ac8300 MOV EAX,[0x0083ac80]
    debug_va=0x0049ec47u;
    s.ax = checked_r32(m,(0x0083ac80u));
  }
  L0049ec4c: { // 0x49ec4c: 8b0d84ac8300 MOV ECX,dword ptr [0x0083ac84]
    debug_va=0x0049ec4cu;
    s.cx = checked_r32(m,(0x0083ac84u));
  }
  L0049ec52: { // 0x49ec52: 8b3588ac8300 MOV ESI,dword ptr [0x0083ac88]
    debug_va=0x0049ec52u;
    s.si = checked_r32(m,(0x0083ac88u));
  }
  L0049ec58: { // 0x49ec58: 8b3d8cac8300 MOV EDI,dword ptr [0x0083ac8c]
    debug_va=0x0049ec58u;
    s.di = checked_r32(m,(0x0083ac8cu));
  }
  L0049ec5e: { // 0x49ec5e: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    debug_va=0x0049ec5eu;
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0049ec62: { // 0x49ec62: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    debug_va=0x0049ec62u;
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0049ec66: { // 0x49ec66: 0fbf4306 MOVSX EAX,word ptr [EBX + 0x6]
    debug_va=0x0049ec66u;
    s.ax = std::uint32_t(integer::sign_extend(checked_r16(m,(s.bx+0x00000006u)),16));
  }
  L0049ec6a: { // 0x49ec6a: 3be8 CMP EBP,EAX
    debug_va=0x0049ec6au;
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0049ec6c: { // 0x49ec6c: 89742434 MOV dword ptr [ESP + 0x34],ESI
    debug_va=0x0049ec6cu;
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0049ec70: { // 0x49ec70: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    debug_va=0x0049ec70u;
    m.w32((f.sp+0x00000038u), s.di);
  }
  L0049ec74: { // 0x49ec74: 7318 JNC 0x0049ec8e
    debug_va=0x0049ec74u;
    if(integer::condition("JNC",flags)) goto L0049ec8e;
  }
  L0049ec76: { // 0x49ec76: 8d4c6d00 LEA ECX,[EBP + EBP*0x2]
    debug_va=0x0049ec76u;
    s.cx = (s.bp+(s.bp * 0x00000002u));
  }
  L0049ec7a: { // 0x49ec7a: 8d44cb08 LEA EAX,[EBX + ECX*0x8 + 0x8]
    debug_va=0x0049ec7au;
    s.ax = (s.bx+(s.cx * 0x00000008u)+0x00000008u);
  }
  L0049ec7e: { // 0x49ec7e: 85c0 TEST EAX,EAX
    debug_va=0x0049ec7eu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec80: { // 0x49ec80: 740c JZ 0x0049ec8e
    debug_va=0x0049ec80u;
    if(integer::condition("JZ",flags)) goto L0049ec8e;
  }
  L0049ec82: { // 0x49ec82: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    debug_va=0x0049ec82u;
    s.ax = checked_r32(m,(s.ax+0x00000014u));
  }
  L0049ec85: { // 0x49ec85: 85c0 TEST EAX,EAX
    debug_va=0x0049ec85u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec87: { // 0x49ec87: 7405 JZ 0x0049ec8e
    debug_va=0x0049ec87u;
    if(integer::condition("JZ",flags)) goto L0049ec8e;
  }
  L0049ec89: { // 0x49ec89: 8d2c18 LEA EBP,[EAX + EBX*0x1]
    debug_va=0x0049ec89u;
    s.bp = (s.ax+(s.bx * 0x00000001u));
  }
  L0049ec8c: { // 0x49ec8c: eb02 JMP 0x0049ec90
    debug_va=0x0049ec8cu;
    goto L0049ec90;
  }
  L0049ec8e: { // 0x49ec8e: 33ed XOR EBP,EBP
    debug_va=0x0049ec8eu;
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049ec90: { // 0x49ec90: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    debug_va=0x0049ec90u;
    s.dx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.bx+0x00000002u)),16));
  }
  L0049ec94: { // 0x49ec94: 0fbf4304 MOVSX EAX,word ptr [EBX + 0x4]
    debug_va=0x0049ec94u;
    s.ax = std::uint32_t(integer::sign_extend(checked_r16(m,(s.bx+0x00000004u)),16));
  }
  L0049ec98: { // 0x49ec98: 57 PUSH EDI
    debug_va=0x0049ec98u;
    f.push(m,s.di);
  }
  L0049ec99: { // 0x49ec99: 56 PUSH ESI
    debug_va=0x0049ec99u;
    f.push(m,s.si);
  }
  L0049ec9a: { // 0x49ec9a: 8d4c2464 LEA ECX,[ESP + 0x64]
    debug_va=0x0049ec9au;
    s.cx = (f.sp+0x00000064u);
  }
  L0049ec9e: { // 0x49ec9e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    debug_va=0x0049ec9eu;
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0049eca2: { // 0x49eca2: 89442420 MOV dword ptr [ESP + 0x20],EAX
    debug_va=0x0049eca2u;
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0049eca6: { // 0x49eca6: e8a5040000 CALL 0x0049f150
    debug_va=0x0049eca6u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049f150u,4844715u); flags=s.arithmetic_flags;
  }
  L0049ecab: { // 0x49ecab: 0faff7 IMUL ESI,EDI
    debug_va=0x0049ecabu;
    s.si = integer::imul(s.si,s.di,32,flags);
  }
  L0049ecae: { // 0x49ecae: 56 PUSH ESI
    debug_va=0x0049ecaeu;
    f.push(m,s.si);
  }
  L0049ecaf: { // 0x49ecaf: 55 PUSH EBP
    debug_va=0x0049ecafu;
    f.push(m,s.bp);
  }
  L0049ecb0: { // 0x49ecb0: 8d4c2478 LEA ECX,[ESP + 0x78]
    debug_va=0x0049ecb0u;
    s.cx = (f.sp+0x00000078u);
  }
  L0049ecb4: { // 0x49ecb4: c744247401000000 MOV dword ptr [ESP + 0x74],0x1
    debug_va=0x0049ecb4u;
    m.w32((f.sp+0x00000074u), 0x00000001u);
  }
  L0049ecbc: { // 0x49ecbc: e87f94f9ff CALL 0x00438140
    debug_va=0x0049ecbcu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,4844737u); flags=s.arithmetic_flags;
  }
  L0049ecc1: { // 0x49ecc1: c744245cf85e7800 MOV dword ptr [ESP + 0x5c],0x785ef8
    debug_va=0x0049ecc1u;
    m.w32((f.sp+0x0000005cu), 0x00785ef8u);
  }
  L0049ecc9: { // 0x49ecc9: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    debug_va=0x0049ecc9u;
    s.cx = checked_r32(m,(f.sp+0x000000a4u));
  }
  L0049ecd0: { // 0x49ecd0: 8b9c24ac000000 MOV EBX,dword ptr [ESP + 0xac]
    debug_va=0x0049ecd0u;
    s.bx = checked_r32(m,(f.sp+0x000000acu));
  }
  L0049ecd7: { // 0x49ecd7: 8bb424b0000000 MOV ESI,dword ptr [ESP + 0xb0]
    debug_va=0x0049ecd7u;
    s.si = checked_r32(m,(f.sp+0x000000b0u));
  }
  L0049ecde: { // 0x49ecde: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    debug_va=0x0049ecdeu;
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049ece2: { // 0x49ece2: 85c9 TEST ECX,ECX
    debug_va=0x0049ece2u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ece4: { // 0x49ece4: 89742428 MOV dword ptr [ESP + 0x28],ESI
    debug_va=0x0049ece4u;
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0049ece8: { // 0x49ece8: 0f8410010000 JZ 0x0049edfe
    debug_va=0x0049ece8u;
    if(integer::condition("JZ",flags)) goto L0049edfe;
  }
  L0049ecee: { // 0x49ecee: 0fbf5106 MOVSX EDX,word ptr [ECX + 0x6]
    debug_va=0x0049eceeu;
    s.dx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.cx+0x00000006u)),16));
  }
  L0049ecf2: { // 0x49ecf2: 8b8424a8000000 MOV EAX,dword ptr [ESP + 0xa8]
    debug_va=0x0049ecf2u;
    s.ax = checked_r32(m,(f.sp+0x000000a8u));
  }
  L0049ecf9: { // 0x49ecf9: 3bc2 CMP EAX,EDX
    debug_va=0x0049ecf9u;
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ecfb: { // 0x49ecfb: 7336 JNC 0x0049ed33
    debug_va=0x0049ecfbu;
    if(integer::condition("JNC",flags)) goto L0049ed33;
  }
  L0049ecfd: { // 0x49ecfd: 8d0440 LEA EAX,[EAX + EAX*0x2]
    debug_va=0x0049ecfdu;
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ed00: { // 0x49ed00: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    debug_va=0x0049ed00u;
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ed04: { // 0x49ed04: 85c0 TEST EAX,EAX
    debug_va=0x0049ed04u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed06: { // 0x49ed06: 742b JZ 0x0049ed33
    debug_va=0x0049ed06u;
    if(integer::condition("JZ",flags)) goto L0049ed33;
  }
  L0049ed08: { // 0x49ed08: 0fbf4806 MOVSX ECX,word ptr [EAX + 0x6]
    debug_va=0x0049ed08u;
    s.cx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax+0x00000006u)),16));
  }
  L0049ed0c: { // 0x49ed0c: 0fbf5004 MOVSX EDX,word ptr [EAX + 0x4]
    debug_va=0x0049ed0cu;
    s.dx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax+0x00000004u)),16));
  }
  L0049ed10: { // 0x49ed10: 51 PUSH ECX
    debug_va=0x0049ed10u;
    f.push(m,s.cx);
  }
  L0049ed11: { // 0x49ed11: 52 PUSH EDX
    debug_va=0x0049ed11u;
    f.push(m,s.dx);
  }
  L0049ed12: { // 0x49ed12: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    debug_va=0x0049ed12u;
    s.cx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax+0x00000002u)),16));
  }
  L0049ed16: { // 0x49ed16: 0fbf10 MOVSX EDX,word ptr [EAX]
    debug_va=0x0049ed16u;
    s.dx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.ax)),16));
  }
  L0049ed19: { // 0x49ed19: 51 PUSH ECX
    debug_va=0x0049ed19u;
    f.push(m,s.cx);
  }
  L0049ed1a: { // 0x49ed1a: 52 PUSH EDX
    debug_va=0x0049ed1au;
    f.push(m,s.dx);
  }
  L0049ed1b: { // 0x49ed1b: 8d4c245c LEA ECX,[ESP + 0x5c]
    debug_va=0x0049ed1bu;
    s.cx = (f.sp+0x0000005cu);
  }
  L0049ed1f: { // 0x49ed1f: e8accff8ff CALL 0x0042bcd0
    debug_va=0x0049ed1fu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042bcd0u,4844836u); flags=s.arithmetic_flags;
  }
  L0049ed24: { // 0x49ed24: 8bd0 MOV EDX,EAX
    debug_va=0x0049ed24u;
    s.dx = s.ax;
  }
  L0049ed26: { // 0x49ed26: 8b02 MOV EAX,dword ptr [EDX]
    debug_va=0x0049ed26u;
    s.ax = checked_r32(m,(s.dx));
  }
  L0049ed28: { // 0x49ed28: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    debug_va=0x0049ed28u;
    s.cx = checked_r32(m,(s.dx+0x00000004u));
  }
  L0049ed2b: { // 0x49ed2b: 8b7a08 MOV EDI,dword ptr [EDX + 0x8]
    debug_va=0x0049ed2bu;
    s.di = checked_r32(m,(s.dx+0x00000008u));
  }
  L0049ed2e: { // 0x49ed2e: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    debug_va=0x0049ed2eu;
    s.bp = checked_r32(m,(s.dx+0x0000000cu));
  }
  L0049ed31: { // 0x49ed31: eb17 JMP 0x0049ed4a
    debug_va=0x0049ed31u;
    goto L0049ed4a;
  }
  L0049ed33: { // 0x49ed33: a180ac8300 MOV EAX,[0x0083ac80]
    debug_va=0x0049ed33u;
    s.ax = checked_r32(m,(0x0083ac80u));
  }
  L0049ed38: { // 0x49ed38: 8b0d84ac8300 MOV ECX,dword ptr [0x0083ac84]
    debug_va=0x0049ed38u;
    s.cx = checked_r32(m,(0x0083ac84u));
  }
  L0049ed3e: { // 0x49ed3e: 8b3d88ac8300 MOV EDI,dword ptr [0x0083ac88]
    debug_va=0x0049ed3eu;
    s.di = checked_r32(m,(0x0083ac88u));
  }
  L0049ed44: { // 0x49ed44: 8b2d8cac8300 MOV EBP,dword ptr [0x0083ac8c]
    debug_va=0x0049ed44u;
    s.bp = checked_r32(m,(0x0083ac8cu));
  }
  L0049ed4a: { // 0x49ed4a: 6a20 PUSH 0x20
    debug_va=0x0049ed4au;
    f.push(m,0x00000020u);
  }
  L0049ed4c: { // 0x49ed4c: 89442440 MOV dword ptr [ESP + 0x40],EAX
    debug_va=0x0049ed4cu;
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0049ed50: { // 0x49ed50: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    debug_va=0x0049ed50u;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0049ed54: { // 0x49ed54: 897c2448 MOV dword ptr [ESP + 0x48],EDI
    debug_va=0x0049ed54u;
    m.w32((f.sp+0x00000048u), s.di);
  }
  L0049ed58: { // 0x49ed58: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    debug_va=0x0049ed58u;
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L0049ed5c: { // 0x49ed5c: e8f6eb2c00 CALL 0x0076d957
    debug_va=0x0049ed5cu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4844897u); flags=s.arithmetic_flags;
  }
  L0049ed61: { // 0x49ed61: 8bf0 MOV ESI,EAX
    debug_va=0x0049ed61u;
    s.si = s.ax;
  }
  L0049ed63: { // 0x49ed63: 83c404 ADD ESP,0x4
    debug_va=0x0049ed63u;
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0049ed66: { // 0x49ed66: 85f6 TEST ESI,ESI
    debug_va=0x0049ed66u;
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049ed68: { // 0x49ed68: 747c JZ 0x0049ede6
    debug_va=0x0049ed68u;
    if(integer::condition("JZ",flags)) goto L0049ede6;
  }
  L0049ed6a: { // 0x49ed6a: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    debug_va=0x0049ed6au;
    s.cx = checked_r32(m,(f.sp+0x000000a4u));
  }
  L0049ed71: { // 0x49ed71: 8b8424a8000000 MOV EAX,dword ptr [ESP + 0xa8]
    debug_va=0x0049ed71u;
    s.ax = checked_r32(m,(f.sp+0x000000a8u));
  }
  L0049ed78: { // 0x49ed78: 0fbf5106 MOVSX EDX,word ptr [ECX + 0x6]
    debug_va=0x0049ed78u;
    s.dx = std::uint32_t(integer::sign_extend(checked_r16(m,(s.cx+0x00000006u)),16));
  }
  L0049ed7c: { // 0x49ed7c: 3bc2 CMP EAX,EDX
    debug_va=0x0049ed7cu;
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ed7e: { // 0x49ed7e: 731d JNC 0x0049ed9d
    debug_va=0x0049ed7eu;
    if(integer::condition("JNC",flags)) goto L0049ed9d;
  }
  L0049ed80: { // 0x49ed80: 8d0440 LEA EAX,[EAX + EAX*0x2]
    debug_va=0x0049ed80u;
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ed83: { // 0x49ed83: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    debug_va=0x0049ed83u;
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ed87: { // 0x49ed87: 85c0 TEST EAX,EAX
    debug_va=0x0049ed87u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed89: { // 0x49ed89: 7412 JZ 0x0049ed9d
    debug_va=0x0049ed89u;
    if(integer::condition("JZ",flags)) goto L0049ed9d;
  }
  L0049ed8b: { // 0x49ed8b: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    debug_va=0x0049ed8bu;
    s.ax = checked_r32(m,(s.ax+0x00000014u));
  }
  L0049ed8e: { // 0x49ed8e: 85c0 TEST EAX,EAX
    debug_va=0x0049ed8eu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed90: { // 0x49ed90: 740b JZ 0x0049ed9d
    debug_va=0x0049ed90u;
    if(integer::condition("JZ",flags)) goto L0049ed9d;
  }
  L0049ed92: { // 0x49ed92: 03c1 ADD EAX,ECX
    debug_va=0x0049ed92u;
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0049ed94: { // 0x49ed94: 898424a8000000 MOV dword ptr [ESP + 0xa8],EAX
    debug_va=0x0049ed94u;
    m.w32((f.sp+0x000000a8u), s.ax);
  }
  L0049ed9b: { // 0x49ed9b: eb0b JMP 0x0049eda8
    debug_va=0x0049ed9bu;
    goto L0049eda8;
  }
  L0049ed9d: { // 0x49ed9d: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    debug_va=0x0049ed9du;
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049eda8: { // 0x49eda8: 55 PUSH EBP
    debug_va=0x0049eda8u;
    f.push(m,s.bp);
  }
  L0049eda9: { // 0x49eda9: 57 PUSH EDI
    debug_va=0x0049eda9u;
    f.push(m,s.di);
  }
  L0049edaa: { // 0x49edaa: 8bce MOV ECX,ESI
    debug_va=0x0049edaau;
    s.cx = s.si;
  }
  L0049edac: { // 0x49edac: e89f030000 CALL 0x0049f150
    debug_va=0x0049edacu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049f150u,4844977u); flags=s.arithmetic_flags;
  }
  L0049edb1: { // 0x49edb1: 0faffd IMUL EDI,EBP
    debug_va=0x0049edb1u;
    s.di = integer::imul(s.di,s.bp,32,flags);
  }
  L0049edb4: { // 0x49edb4: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    debug_va=0x0049edb4u;
    s.cx = checked_r32(m,(f.sp+0x000000a8u));
  }
  L0049edbb: { // 0x49edbb: 57 PUSH EDI
    debug_va=0x0049edbbu;
    f.push(m,s.di);
  }
  L0049edbc: { // 0x49edbc: 51 PUSH ECX
    debug_va=0x0049edbcu;
    f.push(m,s.cx);
  }
  L0049edbd: { // 0x49edbd: 8d4e14 LEA ECX,[ESI + 0x14]
    debug_va=0x0049edbdu;
    s.cx = (s.si+0x00000014u);
  }
  L0049edc0: { // 0x49edc0: c7461001000000 MOV dword ptr [ESI + 0x10],0x1
    debug_va=0x0049edc0u;
    m.w32((s.si+0x00000010u), 0x00000001u);
  }
  L0049edc7: { // 0x49edc7: e87493f9ff CALL 0x00438140
    debug_va=0x0049edc7u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,4845004u); flags=s.arithmetic_flags;
  }
  L0049edcc: { // 0x49edcc: c706f85e7800 MOV dword ptr [ESI],0x785ef8
    debug_va=0x0049edccu;
    m.w32((s.si), 0x00785ef8u);
  }
  L0049edd2: { // 0x49edd2: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    debug_va=0x0049edd2u;
    s.cx = checked_r32(m,(f.sp+0x000000a4u));
  }
  L0049edd9: { // 0x49edd9: 89b424a8000000 MOV dword ptr [ESP + 0xa8],ESI
    debug_va=0x0049edd9u;
    m.w32((f.sp+0x000000a8u), s.si);
  }
  L0049ede0: { // 0x49ede0: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    debug_va=0x0049ede0u;
    s.si = checked_r32(m,(f.sp+0x00000028u));
  }
  L0049ede4: { // 0x49ede4: eb49 JMP 0x0049ee2f
    debug_va=0x0049ede4u;
    goto L0049ee2f;
  }
  L0049ede6: { // 0x49ede6: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    debug_va=0x0049ede6u;
    s.si = checked_r32(m,(f.sp+0x00000028u));
  }
  L0049edea: { // 0x49edea: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    debug_va=0x0049edeau;
    s.cx = checked_r32(m,(f.sp+0x000000a4u));
  }
  L0049edf1: { // 0x49edf1: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    debug_va=0x0049edf1u;
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049edfc: { // 0x49edfc: eb31 JMP 0x0049ee2f
    debug_va=0x0049edfcu;
    goto L0049ee2f;
  }
  L0049edfe: { // 0x49edfe: 8b1580ac8300 MOV EDX,dword ptr [0x0083ac80]
    debug_va=0x0049edfeu;
    s.dx = checked_r32(m,(0x0083ac80u));
  }
  L0049ee04: { // 0x49ee04: a184ac8300 MOV EAX,[0x0083ac84]
    debug_va=0x0049ee04u;
    s.ax = checked_r32(m,(0x0083ac84u));
  }
  L0049ee09: { // 0x49ee09: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    debug_va=0x0049ee09u;
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0049ee0d: { // 0x49ee0d: 8b1588ac8300 MOV EDX,dword ptr [0x0083ac88]
    debug_va=0x0049ee0du;
    s.dx = checked_r32(m,(0x0083ac88u));
  }
  L0049ee13: { // 0x49ee13: 89442440 MOV dword ptr [ESP + 0x40],EAX
    debug_va=0x0049ee13u;
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0049ee17: { // 0x49ee17: a18cac8300 MOV EAX,[0x0083ac8c]
    debug_va=0x0049ee17u;
    s.ax = checked_r32(m,(0x0083ac8cu));
  }
  L0049ee1c: { // 0x49ee1c: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    debug_va=0x0049ee1cu;
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049ee27: { // 0x49ee27: 89542444 MOV dword ptr [ESP + 0x44],EDX
    debug_va=0x0049ee27u;
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L0049ee2b: { // 0x49ee2b: 89442448 MOV dword ptr [ESP + 0x48],EAX
    debug_va=0x0049ee2bu;
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0049ee2f: { // 0x49ee2f: 8b842490000000 MOV EAX,dword ptr [ESP + 0x90]
    debug_va=0x0049ee2fu;
    s.ax = checked_r32(m,(f.sp+0x00000090u));
  }
  L0049ee36: { // 0x49ee36: f6c402 TEST AH,0x2
    debug_va=0x0049ee36u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  L0049ee39: { // 0x49ee39: 7430 JZ 0x0049ee6b
    debug_va=0x0049ee39u;
    if(integer::condition("JZ",flags)) goto L0049ee6b;
  }
  L0049ee3b: { // 0x49ee3b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    debug_va=0x0049ee3bu;
    s.ax = checked_r32(m,(f.sp+0x00000014u));
  }
  L0049ee3f: { // 0x49ee3f: 8bac2488000000 MOV EBP,dword ptr [ESP + 0x88]
    debug_va=0x0049ee3fu;
    s.bp = checked_r32(m,(f.sp+0x00000088u));
  }
  L0049ee46: { // 0x49ee46: 99 CDQ
    debug_va=0x0049ee46u;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee47: { // 0x49ee47: 2bc2 SUB EAX,EDX
    debug_va=0x0049ee47u;
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee49: { // 0x49ee49: d1f8 SAR EAX,0x1
    debug_va=0x0049ee49u;
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee4b: { // 0x49ee4b: f7d8 NEG EAX
    debug_va=0x0049ee4bu;
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049ee4d: { // 0x49ee4d: 03e8 ADD EBP,EAX
    debug_va=0x0049ee4du;
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L0049ee4f: { // 0x49ee4f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    debug_va=0x0049ee4fu;
    s.ax = checked_r32(m,(f.sp+0x00000018u));
  }
  L0049ee53: { // 0x49ee53: 99 CDQ
    debug_va=0x0049ee53u;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee54: { // 0x49ee54: 2bc2 SUB EAX,EDX
    debug_va=0x0049ee54u;
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee56: { // 0x49ee56: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x0049ee56u;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L0049ee5a: { // 0x49ee5a: d1f8 SAR EAX,0x1
    debug_va=0x0049ee5au;
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee5c: { // 0x49ee5c: f7d8 NEG EAX
    debug_va=0x0049ee5cu;
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049ee5e: { // 0x49ee5e: 03d0 ADD EDX,EAX
    debug_va=0x0049ee5eu;
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0049ee60: { // 0x49ee60: 89ac2488000000 MOV dword ptr [ESP + 0x88],EBP
    debug_va=0x0049ee60u;
    m.w32((f.sp+0x00000088u), s.bp);
  }
  L0049ee67: { // 0x49ee67: 89542410 MOV dword ptr [ESP + 0x10],EDX
    debug_va=0x0049ee67u;
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ee6b: { // 0x49ee6b: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    debug_va=0x0049ee6bu;
    s.di = checked_r32(m,(f.sp+0x0000002cu));
  }
  L0049ee6f: { // 0x49ee6f: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    debug_va=0x0049ee6fu;
    s.bp = checked_r32(m,(f.sp+0x00000030u));
  }
  L0049ee73: { // 0x49ee73: 85c9 TEST ECX,ECX
    debug_va=0x0049ee73u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ee75: { // 0x49ee75: 7427 JZ 0x0049ee9e
    debug_va=0x0049ee75u;
    if(integer::condition("JZ",flags)) goto L0049ee9e;
  }
  L0049ee77: { // 0x49ee77: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    debug_va=0x0049ee77u;
    s.ax = checked_r32(m,(f.sp+0x00000014u));
  }
  L0049ee7b: { // 0x49ee7b: 99 CDQ
    debug_va=0x0049ee7bu;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee7c: { // 0x49ee7c: 2bc2 SUB EAX,EDX
    debug_va=0x0049ee7cu;
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee7e: { // 0x49ee7e: 8bc8 MOV ECX,EAX
    debug_va=0x0049ee7eu;
    s.cx = s.ax;
  }
  L0049ee80: { // 0x49ee80: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    debug_va=0x0049ee80u;
    s.ax = checked_r32(m,(f.sp+0x00000018u));
  }
  L0049ee84: { // 0x49ee84: 99 CDQ
    debug_va=0x0049ee84u;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee85: { // 0x49ee85: d1f9 SAR ECX,0x1
    debug_va=0x0049ee85u;
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee87: { // 0x49ee87: 2bc2 SUB EAX,EDX
    debug_va=0x0049ee87u;
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee89: { // 0x49ee89: 2bcf SUB ECX,EDI
    debug_va=0x0049ee89u;
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L0049ee8b: { // 0x49ee8b: d1f8 SAR EAX,0x1
    debug_va=0x0049ee8bu;
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee8d: { // 0x49ee8d: 2bc5 SUB EAX,EBP
    debug_va=0x0049ee8du;
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0049ee8f: { // 0x49ee8f: 2bd9 SUB EBX,ECX
    debug_va=0x0049ee8fu;
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0049ee91: { // 0x49ee91: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    debug_va=0x0049ee91u;
    s.cx = checked_r32(m,(f.sp+0x000000a4u));
  }
  L0049ee98: { // 0x49ee98: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    debug_va=0x0049ee98u;
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049ee9c: { // 0x49ee9c: 2bf0 SUB ESI,EAX
    debug_va=0x0049ee9cu;
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0049ee9e: { // 0x49ee9e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x0049ee9eu;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L0049eea2: { // 0x49eea2: 8b9c2488000000 MOV EBX,dword ptr [ESP + 0x88]
    debug_va=0x0049eea2u;
    s.bx = checked_r32(m,(f.sp+0x00000088u));
  }
  L0049eea9: { // 0x49eea9: 03d5 ADD EDX,EBP
    debug_va=0x0049eea9u;
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L0049eeab: { // 0x49eeab: 03df ADD EBX,EDI
    debug_va=0x0049eeabu;
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L0049eead: { // 0x49eead: 89542410 MOV dword ptr [ESP + 0x10],EDX
    debug_va=0x0049eeadu;
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049eeb1: { // 0x49eeb1: 33d2 XOR EDX,EDX
    debug_va=0x0049eeb1u;
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0049eeb3: { // 0x49eeb3: 3bca CMP ECX,EDX
    debug_va=0x0049eeb3u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0049eeb5: { // 0x49eeb5: 899c2488000000 MOV dword ptr [ESP + 0x88],EBX
    debug_va=0x0049eeb5u;
    m.w32((f.sp+0x00000088u), s.bx);
  }
  L0049eebc: { // 0x49eebc: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    debug_va=0x0049eebcu;
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0049eec0: { // 0x49eec0: 89542430 MOV dword ptr [ESP + 0x30],EDX
    debug_va=0x0049eec0u;
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0049eec4: { // 0x49eec4: 7473 JZ 0x0049ef39
    debug_va=0x0049eec4u;
    if(integer::condition("JZ",flags)) goto L0049ef39;
  }
  L0049eec6: { // 0x49eec6: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    debug_va=0x0049eec6u;
    s.di = checked_r32(m,(f.sp+0x00000040u));
  }
  L0049eeca: { // 0x49eeca: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    debug_va=0x0049eecau;
    s.ax = checked_r32(m,(f.sp+0x00000024u));
  }
  L0049eece: { // 0x49eece: 8b5c243c MOV EBX,dword ptr [ESP + 0x3c]
    debug_va=0x0049eeceu;
    s.bx = checked_r32(m,(f.sp+0x0000003cu));
  }
  L0049eed2: { // 0x49eed2: 03f7 ADD ESI,EDI
    debug_va=0x0049eed2u;
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0049eed4: { // 0x49eed4: 8bce MOV ECX,ESI
    debug_va=0x0049eed4u;
    s.cx = s.si;
  }
  L0049eed6: { // 0x49eed6: 03c3 ADD EAX,EBX
    debug_va=0x0049eed6u;
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0049eed8: { // 0x49eed8: f7d9 NEG ECX
    debug_va=0x0049eed8u;
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0049eeda: { // 0x49eeda: 89442424 MOV dword ptr [ESP + 0x24],EAX
    debug_va=0x0049eedau;
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0049eede: { // 0x49eede: 52 PUSH EDX
    debug_va=0x0049eedeu;
    f.push(m,s.dx);
  }
  L0049eedf: { // 0x49eedf: f7d8 NEG EAX
    debug_va=0x0049eedfu;
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049eee1: { // 0x49eee1: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    debug_va=0x0049eee1u;
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0049eee5: { // 0x49eee5: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    debug_va=0x0049eee5u;
    s.cx = checked_r32(m,(f.sp+0x0000004cu));
  }
  L0049eee9: { // 0x49eee9: 52 PUSH EDX
    debug_va=0x0049eee9u;
    f.push(m,s.dx);
  }
  L0049eeea: { // 0x49eeea: 8d542454 LEA EDX,[ESP + 0x54]
    debug_va=0x0049eeeau;
    s.dx = (f.sp+0x00000054u);
  }
  L0049eeee: { // 0x49eeee: 89442454 MOV dword ptr [ESP + 0x54],EAX
    debug_va=0x0049eeeeu;
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L0049eef2: { // 0x49eef2: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    debug_va=0x0049eef2u;
    s.ax = checked_r32(m,(f.sp+0x0000004cu));
  }
  L0049eef6: { // 0x49eef6: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    debug_va=0x0049eef6u;
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0049eefa: { // 0x49eefa: 52 PUSH EDX
    debug_va=0x0049eefau;
    f.push(m,s.dx);
  }
  L0049eefb: { // 0x49eefb: 8d542438 LEA EDX,[ESP + 0x38]
    debug_va=0x0049eefbu;
    s.dx = (f.sp+0x00000038u);
  }
  L0049eeff: { // 0x49eeff: 8d4c2448 LEA ECX,[ESP + 0x48]
    debug_va=0x0049eeffu;
    s.cx = (f.sp+0x00000048u);
  }
  L0049ef03: { // 0x49ef03: 89442460 MOV dword ptr [ESP + 0x60],EAX
    debug_va=0x0049ef03u;
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0049ef07: { // 0x49ef07: e8e40ef8ff CALL 0x0041fdf0
    debug_va=0x0049ef07u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4845324u); flags=s.arithmetic_flags;
  }
  L0049ef0c: { // 0x49ef0c: 8bc8 MOV ECX,EAX
    debug_va=0x0049ef0cu;
    s.cx = s.ax;
  }
  L0049ef0e: { // 0x49ef0e: 8b11 MOV EDX,dword ptr [ECX]
    debug_va=0x0049ef0eu;
    s.dx = checked_r32(m,(s.cx));
  }
  L0049ef10: { // 0x49ef10: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    debug_va=0x0049ef10u;
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0049ef14: { // 0x49ef14: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    debug_va=0x0049ef14u;
    s.ax = checked_r32(m,(s.cx+0x00000004u));
  }
  L0049ef17: { // 0x49ef17: 89442430 MOV dword ptr [ESP + 0x30],EAX
    debug_va=0x0049ef17u;
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0049ef1b: { // 0x49ef1b: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    debug_va=0x0049ef1bu;
    s.ax = checked_r32(m,(s.cx+0x00000008u));
  }
  L0049ef1e: { // 0x49ef1e: 89442434 MOV dword ptr [ESP + 0x34],EAX
    debug_va=0x0049ef1eu;
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0049ef22: { // 0x49ef22: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    debug_va=0x0049ef22u;
    s.cx = checked_r32(m,(s.cx+0x0000000cu));
  }
  L0049ef25: { // 0x49ef25: 85c0 TEST EAX,EAX
    debug_va=0x0049ef25u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef27: { // 0x49ef27: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    debug_va=0x0049ef27u;
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0049ef2b: { // 0x49ef2b: 0f8e6b010000 JLE 0x0049f09c
    debug_va=0x0049ef2bu;
    if(integer::condition("JLE",flags)) goto L0049f09c;
  }
  L0049ef31: { // 0x49ef31: 85c9 TEST ECX,ECX
    debug_va=0x0049ef31u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ef33: { // 0x49ef33: 0f8e63010000 JLE 0x0049f09c
    debug_va=0x0049ef33u;
    if(integer::condition("JLE",flags)) goto L0049f09c;
  }
  L0049ef39: { // 0x49ef39: 8b842494000000 MOV EAX,dword ptr [ESP + 0x94]
    debug_va=0x0049ef39u;
    s.ax = checked_r32(m,(f.sp+0x00000094u));
  }
  L0049ef40: { // 0x49ef40: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    debug_va=0x0049ef40u;
    s.dx = checked_r32(m,(f.sp+0x00000090u));
  }
  L0049ef47: { // 0x49ef47: 85c0 TEST EAX,EAX
    debug_va=0x0049ef47u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef49: { // 0x49ef49: 7403 JZ 0x0049ef4e
    debug_va=0x0049ef49u;
    if(integer::condition("JZ",flags)) goto L0049ef4e;
  }
  L0049ef4b: { // 0x49ef4b: 83ca10 OR EDX,0x10
    debug_va=0x0049ef4bu;
    s.dx = integer::logical((s.dx)|(0x00000010u),32,flags);
  }
  L0049ef4e: { // 0x49ef4e: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    debug_va=0x0049ef4eu;
    s.cx = checked_r32(m,(f.sp+0x00000080u));
  }
  L0049ef55: { // 0x49ef55: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    debug_va=0x0049ef55u;
    s.ax = checked_r32(m,(f.sp+0x00000084u));
  }
  L0049ef5c: { // 0x49ef5c: 0fbf7906 MOVSX EDI,word ptr [ECX + 0x6]
    debug_va=0x0049ef5cu;
    s.di = std::uint32_t(integer::sign_extend(checked_r16(m,(s.cx+0x00000006u)),16));
  }
  L0049ef60: { // 0x49ef60: 3bc7 CMP EAX,EDI
    debug_va=0x0049ef60u;
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0049ef62: { // 0x49ef62: 0f83a8000000 JNC 0x0049f010
    debug_va=0x0049ef62u;
    if(integer::condition("JNC",flags)) goto L0049f010;
  }
  L0049ef68: { // 0x49ef68: 8d0440 LEA EAX,[EAX + EAX*0x2]
    debug_va=0x0049ef68u;
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ef6b: { // 0x49ef6b: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    debug_va=0x0049ef6bu;
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ef6f: { // 0x49ef6f: 85c0 TEST EAX,EAX
    debug_va=0x0049ef6fu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef71: { // 0x49ef71: 0f8499000000 JZ 0x0049f010
    debug_va=0x0049ef71u;
    if(integer::condition("JZ",flags)) goto L0049f010;
  }
  L0049ef77: { // 0x49ef77: 8a4008 MOV AL,byte ptr [EAX + 0x8]
    debug_va=0x0049ef77u;
    s.ax = with_al(s.ax, checked_r8(m,(s.ax+0x00000008u)));
  }
  L0049ef7a: { // 0x49ef7a: d1e8 SHR EAX,0x1
    debug_va=0x0049ef7au;
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L0049ef7c: { // 0x49ef7c: 2401 AND AL,0x1
    debug_va=0x0049ef7cu;
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L0049ef7e: { // 0x49ef7e: 84c0 TEST AL,AL
    debug_va=0x0049ef7eu;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ef80: { // 0x49ef80: 0f848a000000 JZ 0x0049f010
    debug_va=0x0049ef80u;
    if(integer::condition("JZ",flags)) goto L0049f010;
  }
  L0049ef86: { // 0x49ef86: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    debug_va=0x0049ef86u;
    s.cx = checked_r32(m,(f.sp+0x0000001cu));
  }
  L0049ef8a: { // 0x49ef8a: 52 PUSH EDX
    debug_va=0x0049ef8au;
    f.push(m,s.dx);
  }
  L0049ef8b: { // 0x49ef8b: e8b06bfeff CALL 0x00485b40
    debug_va=0x0049ef8bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485b40u,4845456u); flags=s.arithmetic_flags;
  }
  L0049ef90: { // 0x49ef90: 85c0 TEST EAX,EAX
    debug_va=0x0049ef90u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef92: { // 0x49ef92: 0f8404010000 JZ 0x0049f09c
    debug_va=0x0049ef92u;
    if(integer::condition("JZ",flags)) goto L0049f09c;
  }
  L0049ef98: { // 0x49ef98: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    debug_va=0x0049ef98u;
    s.cx = checked_r32(m,(f.sp+0x00000088u));
  }
  L0049ef9f: { // 0x49ef9f: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x0049ef9fu;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L0049efa3: { // 0x49efa3: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    debug_va=0x0049efa3u;
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0049efa7: { // 0x49efa7: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    debug_va=0x0049efa7u;
    s.cx = checked_r32(m,(f.sp+0x00000034u));
  }
  L0049efab: { // 0x49efab: 89542450 MOV dword ptr [ESP + 0x50],EDX
    debug_va=0x0049efabu;
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0049efaf: { // 0x49efaf: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    debug_va=0x0049efafu;
    s.dx = checked_r32(m,(f.sp+0x00000038u));
  }
  L0049efb3: { // 0x49efb3: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    debug_va=0x0049efb3u;
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0049efb7: { // 0x49efb7: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    debug_va=0x0049efb7u;
    s.cx = checked_r32(m,(f.sp+0x00000024u));
  }
  L0049efbb: { // 0x49efbb: 89542458 MOV dword ptr [ESP + 0x58],EDX
    debug_va=0x0049efbbu;
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0049efbf: { // 0x49efbf: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    debug_va=0x0049efbfu;
    s.dx = checked_r32(m,(f.sp+0x000000a8u));
  }
  L0049efc6: { // 0x49efc6: 56 PUSH ESI
    debug_va=0x0049efc6u;
    f.push(m,s.si);
  }
  L0049efc7: { // 0x49efc7: 51 PUSH ECX
    debug_va=0x0049efc7u;
    f.push(m,s.cx);
  }
  L0049efc8: { // 0x49efc8: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    debug_va=0x0049efc8u;
    s.cx = checked_r32(m,(f.sp+0x000000a8u));
  }
  L0049efcf: { // 0x49efcf: 52 PUSH EDX
    debug_va=0x0049efcfu;
    f.push(m,s.dx);
  }
  L0049efd0: { // 0x49efd0: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    debug_va=0x0049efd0u;
    s.dx = checked_r32(m,(f.sp+0x000000a8u));
  }
  L0049efd7: { // 0x49efd7: 6a00 PUSH 0x0
    debug_va=0x0049efd7u;
    f.push(m,0x00000000u);
  }
  L0049efd9: { // 0x49efd9: 51 PUSH ECX
    debug_va=0x0049efd9u;
    f.push(m,s.cx);
  }
  L0049efda: { // 0x49efda: 8b8c24ac000000 MOV ECX,dword ptr [ESP + 0xac]
    debug_va=0x0049efdau;
    s.cx = checked_r32(m,(f.sp+0x000000acu));
  }
  L0049efe1: { // 0x49efe1: 52 PUSH EDX
    debug_va=0x0049efe1u;
    f.push(m,s.dx);
  }
  L0049efe2: { // 0x49efe2: 51 PUSH ECX
    debug_va=0x0049efe2u;
    f.push(m,s.cx);
  }
  L0049efe3: { // 0x49efe3: 50 PUSH EAX
    debug_va=0x0049efe3u;
    f.push(m,s.ax);
  }
  L0049efe4: { // 0x49efe4: 8d54244c LEA EDX,[ESP + 0x4c]
    debug_va=0x0049efe4u;
    s.dx = (f.sp+0x0000004cu);
  }
  L0049efe8: { // 0x49efe8: 8d44244c LEA EAX,[ESP + 0x4c]
    debug_va=0x0049efe8u;
    s.ax = (f.sp+0x0000004cu);
  }
  L0049efec: { // 0x49efec: 52 PUSH EDX
    debug_va=0x0049efecu;
    f.push(m,s.dx);
  }
  L0049efed: { // 0x49efed: 8d8c2480000000 LEA ECX,[ESP + 0x80]
    debug_va=0x0049efedu;
    s.cx = (f.sp+0x00000080u);
  }
  L0049eff4: { // 0x49eff4: 50 PUSH EAX
    debug_va=0x0049eff4u;
    f.push(m,s.ax);
  }
  L0049eff5: { // 0x49eff5: 8d542474 LEA EDX,[ESP + 0x74]
    debug_va=0x0049eff5u;
    s.dx = (f.sp+0x00000074u);
  }
  L0049eff9: { // 0x49eff9: 51 PUSH ECX
    debug_va=0x0049eff9u;
    f.push(m,s.cx);
  }
  L0049effa: { // 0x49effa: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    debug_va=0x0049effau;
    s.cx = checked_r32(m,(f.sp+0x0000004cu));
  }
  L0049effe: { // 0x49effe: 52 PUSH EDX
    debug_va=0x0049effeu;
    f.push(m,s.dx);
  }
  L0049efff: { // 0x49efff: 8b9424bc000000 MOV EDX,dword ptr [ESP + 0xbc]
    debug_va=0x0049efffu;
    s.dx = checked_r32(m,(f.sp+0x000000bcu));
  }
  L0049f006: { // 0x49f006: e8755ff9ff CALL 0x00434f80
    debug_va=0x0049f006u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434f80u,4845579u); flags=s.arithmetic_flags;
  }
  L0049f00b: { // 0x49f00b: e98c000000 JMP 0x0049f09c
    debug_va=0x0049f00bu;
    goto L0049f09c;
  }
  L0049f010: { // 0x49f010: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    debug_va=0x0049f010u;
    s.cx = checked_r32(m,(f.sp+0x0000001cu));
  }
  L0049f014: { // 0x49f014: 52 PUSH EDX
    debug_va=0x0049f014u;
    f.push(m,s.dx);
  }
  L0049f015: { // 0x49f015: e86668feff CALL 0x00485880
    debug_va=0x0049f015u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485880u,4845594u); flags=s.arithmetic_flags;
  }
  L0049f01a: { // 0x49f01a: 85c0 TEST EAX,EAX
    debug_va=0x0049f01au;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f01c: { // 0x49f01c: 747e JZ 0x0049f09c
    debug_va=0x0049f01cu;
    if(integer::condition("JZ",flags)) goto L0049f09c;
  }
  L0049f01e: { // 0x49f01e: 33c9 XOR ECX,ECX
    debug_va=0x0049f01eu;
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049f020: { // 0x49f020: 33d2 XOR EDX,EDX
    debug_va=0x0049f020u;
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0049f022: { // 0x49f022: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    debug_va=0x0049f022u;
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0049f026: { // 0x49f026: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    debug_va=0x0049f026u;
    s.cx = checked_r32(m,(f.sp+0x00000088u));
  }
  L0049f02d: { // 0x49f02d: 89542450 MOV dword ptr [ESP + 0x50],EDX
    debug_va=0x0049f02du;
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0049f031: { // 0x49f031: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x0049f031u;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L0049f035: { // 0x49f035: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    debug_va=0x0049f035u;
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0049f039: { // 0x49f039: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    debug_va=0x0049f039u;
    s.cx = checked_r32(m,(f.sp+0x00000034u));
  }
  L0049f03d: { // 0x49f03d: 89542440 MOV dword ptr [ESP + 0x40],EDX
    debug_va=0x0049f03du;
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0049f041: { // 0x49f041: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    debug_va=0x0049f041u;
    s.dx = checked_r32(m,(f.sp+0x00000038u));
  }
  L0049f045: { // 0x49f045: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    debug_va=0x0049f045u;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0049f049: { // 0x49f049: 8b8c24a0000000 MOV ECX,dword ptr [ESP + 0xa0]
    debug_va=0x0049f049u;
    s.cx = checked_r32(m,(f.sp+0x000000a0u));
  }
  L0049f050: { // 0x49f050: 89542448 MOV dword ptr [ESP + 0x48],EDX
    debug_va=0x0049f050u;
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L0049f054: { // 0x49f054: 8b94249c000000 MOV EDX,dword ptr [ESP + 0x9c]
    debug_va=0x0049f054u;
    s.dx = checked_r32(m,(f.sp+0x0000009cu));
  }
  L0049f05b: { // 0x49f05b: 6a00 PUSH 0x0
    debug_va=0x0049f05bu;
    f.push(m,0x00000000u);
  }
  L0049f05d: { // 0x49f05d: 51 PUSH ECX
    debug_va=0x0049f05du;
    f.push(m,s.cx);
  }
  L0049f05e: { // 0x49f05e: 8b8c24a0000000 MOV ECX,dword ptr [ESP + 0xa0]
    debug_va=0x0049f05eu;
    s.cx = checked_r32(m,(f.sp+0x000000a0u));
  }
  L0049f065: { // 0x49f065: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    debug_va=0x0049f065u;
    s.di = checked_r32(m,(f.sp+0x00000068u));
  }
  L0049f069: { // 0x49f069: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    debug_va=0x0049f069u;
    s.bp = checked_r32(m,(f.sp+0x0000006cu));
  }
  L0049f06d: { // 0x49f06d: 52 PUSH EDX
    debug_va=0x0049f06du;
    f.push(m,s.dx);
  }
  L0049f06e: { // 0x49f06e: 51 PUSH ECX
    debug_va=0x0049f06eu;
    f.push(m,s.cx);
  }
  L0049f06f: { // 0x49f06f: 50 PUSH EAX
    debug_va=0x0049f06fu;
    f.push(m,s.ax);
  }
  L0049f070: { // 0x49f070: 8d542440 LEA EDX,[ESP + 0x40]
    debug_va=0x0049f070u;
    s.dx = (f.sp+0x00000040u);
  }
  L0049f074: { // 0x49f074: 8d442460 LEA EAX,[ESP + 0x60]
    debug_va=0x0049f074u;
    s.ax = (f.sp+0x00000060u);
  }
  L0049f078: { // 0x49f078: 52 PUSH EDX
    debug_va=0x0049f078u;
    f.push(m,s.dx);
  }
  L0049f079: { // 0x49f079: 8d4c2474 LEA ECX,[ESP + 0x74]
    debug_va=0x0049f079u;
    s.cx = (f.sp+0x00000074u);
  }
  L0049f07d: { // 0x49f07d: 50 PUSH EAX
    debug_va=0x0049f07du;
    f.push(m,s.ax);
  }
  L0049f07e: { // 0x49f07e: 8d542458 LEA EDX,[ESP + 0x58]
    debug_va=0x0049f07eu;
    s.dx = (f.sp+0x00000058u);
  }
  L0049f082: { // 0x49f082: 51 PUSH ECX
    debug_va=0x0049f082u;
    f.push(m,s.cx);
  }
  L0049f083: { // 0x49f083: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    debug_va=0x0049f083u;
    s.cx = checked_r32(m,(f.sp+0x00000040u));
  }
  L0049f087: { // 0x49f087: 52 PUSH EDX
    debug_va=0x0049f087u;
    f.push(m,s.dx);
  }
  L0049f088: { // 0x49f088: 8b9424b0000000 MOV EDX,dword ptr [ESP + 0xb0]
    debug_va=0x0049f088u;
    s.dx = checked_r32(m,(f.sp+0x000000b0u));
  }
  L0049f08f: { // 0x49f08f: 897c2478 MOV dword ptr [ESP + 0x78],EDI
    debug_va=0x0049f08fu;
    m.w32((f.sp+0x00000078u), s.di);
  }
  L0049f093: { // 0x49f093: 896c247c MOV dword ptr [ESP + 0x7c],EBP
    debug_va=0x0049f093u;
    m.w32((f.sp+0x0000007cu), s.bp);
  }
  L0049f097: { // 0x49f097: e86459f9ff CALL 0x00434a00
    debug_va=0x0049f097u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434a00u,4845724u); flags=s.arithmetic_flags;
  }
  L0049f09c: { // 0x49f09c: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    debug_va=0x0049f09cu;
    s.cx = checked_r32(m,(f.sp+0x000000a8u));
  }
  L0049f0a3: { // 0x49f0a3: 5f POP EDI
    debug_va=0x0049f0a3u;
    const auto value=f.pop(m); s.di = value;
  }
  L0049f0a4: { // 0x49f0a4: 5e POP ESI
    debug_va=0x0049f0a4u;
    const auto value=f.pop(m); s.si = value;
  }
  L0049f0a5: { // 0x49f0a5: 5d POP EBP
    debug_va=0x0049f0a5u;
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f0a6: { // 0x49f0a6: 85c9 TEST ECX,ECX
    debug_va=0x0049f0a6u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049f0a8: { // 0x49f0a8: 5b POP EBX
    debug_va=0x0049f0a8u;
    const auto value=f.pop(m); s.bx = value;
  }
  L0049f0a9: { // 0x49f0a9: 7406 JZ 0x0049f0b1
    debug_va=0x0049f0a9u;
    if(integer::condition("JZ",flags)) goto L0049f0b1;
  }
  L0049f0ab: { // 0x49f0ab: 8b01 MOV EAX,dword ptr [ECX]
    debug_va=0x0049f0abu;
    s.ax = checked_r32(m,(s.cx));
  }
  L0049f0ad: { // 0x49f0ad: 6a01 PUSH 0x1
    debug_va=0x0049f0adu;
    f.push(m,0x00000001u);
  }
  L0049f0af: { // 0x49f0af: ff10 CALL dword ptr [EAX]
    debug_va=0x0049f0afu;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax)),4845745u); flags=s.arithmetic_flags;
  }
  L0049f0b1: { // 0x49f0b1: 8d4c2460 LEA ECX,[ESP + 0x60]
    debug_va=0x0049f0b1u;
    s.cx = (f.sp+0x00000060u);
  }
  L0049f0b5: { // 0x49f0b5: e8d691f9ff CALL 0x00438290
    debug_va=0x0049f0b5u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,4845754u); flags=s.arithmetic_flags;
  }
  L0049f0ba: { // 0x49f0ba: 83c46c ADD ESP,0x6c
    debug_va=0x0049f0bau;
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0049f0bd: { // 0x49f0bd: c23400 RET 0x34
    debug_va=0x0049f0bdu;
    s.arithmetic_flags=flags; finish(m,s,f,52u); return;
  }
}
void f_0002bcd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042bcd0: { // 0x42bcd0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    debug_va=0x0042bcd0u;
    s.dx = checked_r32(m,(f.sp+0x00000008u));
  }
  L0042bcd4: { // 0x42bcd4: 8bc1 MOV EAX,ECX
    debug_va=0x0042bcd4u;
    s.ax = s.cx;
  }
  L0042bcd6: { // 0x42bcd6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    debug_va=0x0042bcd6u;
    s.cx = checked_r32(m,(f.sp+0x00000004u));
  }
  L0042bcda: { // 0x42bcda: 8908 MOV dword ptr [EAX],ECX
    debug_va=0x0042bcdau;
    m.w32((s.ax), s.cx);
  }
  L0042bcdc: { // 0x42bcdc: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    debug_va=0x0042bcdcu;
    s.cx = checked_r32(m,(f.sp+0x0000000cu));
  }
  L0042bce0: { // 0x42bce0: 895004 MOV dword ptr [EAX + 0x4],EDX
    debug_va=0x0042bce0u;
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0042bce3: { // 0x42bce3: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x0042bce3u;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L0042bce7: { // 0x42bce7: 894808 MOV dword ptr [EAX + 0x8],ECX
    debug_va=0x0042bce7u;
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0042bcea: { // 0x42bcea: 89500c MOV dword ptr [EAX + 0xc],EDX
    debug_va=0x0042bceau;
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0042bced: { // 0x42bced: c21000 RET 0x10
    debug_va=0x0042bcedu;
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_0009f150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049f150: { // 0x49f150: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    debug_va=0x0049f150u;
    s.dx = checked_r32(m,(f.sp+0x00000008u));
  }
  L0049f154: { // 0x49f154: 8bc1 MOV EAX,ECX
    debug_va=0x0049f154u;
    s.ax = s.cx;
  }
  L0049f156: { // 0x49f156: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    debug_va=0x0049f156u;
    s.cx = checked_r32(m,(f.sp+0x00000004u));
  }
  L0049f15a: { // 0x49f15a: 894804 MOV dword ptr [EAX + 0x4],ECX
    debug_va=0x0049f15au;
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0049f15d: { // 0x49f15d: 895008 MOV dword ptr [EAX + 0x8],EDX
    debug_va=0x0049f15du;
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L0049f160: { // 0x49f160: c7400c00000000 MOV dword ptr [EAX + 0xc],0x0
    debug_va=0x0049f160u;
    m.w32((s.ax+0x0000000cu), 0x00000000u);
  }
  L0049f167: { // 0x49f167: c7008c5f7800 MOV dword ptr [EAX],0x785f8c
    debug_va=0x0049f167u;
    m.w32((s.ax), 0x00785f8cu);
  }
  L0049f16d: { // 0x49f16d: c20800 RET 0x8
    debug_va=0x0049f16du;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00038140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438140: { // 0x438140: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    debug_va=0x00438140u;
    s.ax = checked_r32(m,(f.sp+0x00000004u));
  }
  L00438144: { // 0x438144: 56 PUSH ESI
    debug_va=0x00438144u;
    f.push(m,s.si);
  }
  L00438145: { // 0x438145: 8bf1 MOV ESI,ECX
    debug_va=0x00438145u;
    s.si = s.cx;
  }
  L00438147: { // 0x438147: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    debug_va=0x00438147u;
    s.cx = checked_r32(m,(f.sp+0x0000000cu));
  }
  L0043814b: { // 0x43814b: 85c0 TEST EAX,EAX
    debug_va=0x0043814bu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043814d: { // 0x43814d: 8906 MOV dword ptr [ESI],EAX
    debug_va=0x0043814du;
    m.w32((s.si), s.ax);
  }
  L0043814f: { // 0x43814f: 894e04 MOV dword ptr [ESI + 0x4],ECX
    debug_va=0x0043814fu;
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00438152: { // 0x438152: c6460800 MOV byte ptr [ESI + 0x8],0x0
    debug_va=0x00438152u;
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  L00438156: { // 0x438156: 7513 JNZ 0x0043816b
    debug_va=0x00438156u;
    if(integer::condition("JNZ",flags)) goto L0043816b;
  }
  L00438158: { // 0x438158: 85c9 TEST ECX,ECX
    debug_va=0x00438158u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043815a: { // 0x43815a: 7e0f JLE 0x0043816b
    debug_va=0x0043815au;
    if(integer::condition("JLE",flags)) goto L0043816b;
  }
  L0043815c: { // 0x43815c: 51 PUSH ECX
    debug_va=0x0043815cu;
    f.push(m,s.cx);
  }
  L0043815d: { // 0x43815d: e8f5573300 CALL 0x0076d957
    debug_va=0x0043815du;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4424034u); flags=s.arithmetic_flags;
  }
  L00438162: { // 0x438162: 83c404 ADD ESP,0x4
    debug_va=0x00438162u;
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00438165: { // 0x438165: 8906 MOV dword ptr [ESI],EAX
    debug_va=0x00438165u;
    m.w32((s.si), s.ax);
  }
  L00438167: { // 0x438167: c6460801 MOV byte ptr [ESI + 0x8],0x1
    debug_va=0x00438167u;
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L0043816b: { // 0x43816b: 8bc6 MOV EAX,ESI
    debug_va=0x0043816bu;
    s.ax = s.si;
  }
  L0043816d: { // 0x43816d: 5e POP ESI
    debug_va=0x0043816du;
    const auto value=f.pop(m); s.si = value;
  }
  L0043816e: { // 0x43816e: c20800 RET 0x8
    debug_va=0x0043816eu;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00038290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438290: { // 0x438290: 56 PUSH ESI
    debug_va=0x00438290u;
    f.push(m,s.si);
  }
  L00438291: { // 0x438291: 8bf1 MOV ESI,ECX
    debug_va=0x00438291u;
    s.si = s.cx;
  }
  L00438293: { // 0x438293: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    debug_va=0x00438293u;
    s.ax = with_al(s.ax, checked_r8(m,(s.si+0x00000008u)));
  }
  L00438296: { // 0x438296: 84c0 TEST AL,AL
    debug_va=0x00438296u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00438298: { // 0x438298: 740b JZ 0x004382a5
    debug_va=0x00438298u;
    if(integer::condition("JZ",flags)) goto L004382a5;
  }
  L0043829a: { // 0x43829a: 8b06 MOV EAX,dword ptr [ESI]
    debug_va=0x0043829au;
    s.ax = checked_r32(m,(s.si));
  }
  L0043829c: { // 0x43829c: 50 PUSH EAX
    debug_va=0x0043829cu;
    f.push(m,s.ax);
  }
  L0043829d: { // 0x43829d: e8d9533300 CALL 0x0076d67b
    debug_va=0x0043829du;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4424354u); flags=s.arithmetic_flags;
  }
  L004382a2: { // 0x4382a2: 83c404 ADD ESP,0x4
    debug_va=0x004382a2u;
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004382a5: { // 0x4382a5: c70600000000 MOV dword ptr [ESI],0x0
    debug_va=0x004382a5u;
    m.w32((s.si), 0x00000000u);
  }
  L004382ab: { // 0x4382ab: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    debug_va=0x004382abu;
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L004382b2: { // 0x4382b2: c6460800 MOV byte ptr [ESI + 0x8],0x0
    debug_va=0x004382b2u;
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  L004382b6: { // 0x4382b6: 5e POP ESI
    debug_va=0x004382b6u;
    const auto value=f.pop(m); s.si = value;
  }
  L004382b7: { // 0x4382b7: c3 RET
    debug_va=0x004382b7u;
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00085b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00485b40: { // 0x485b40: 56 PUSH ESI
    debug_va=0x00485b40u;
    f.push(m,s.si);
  }
  L00485b41: { // 0x485b41: 8bf1 MOV ESI,ECX
    debug_va=0x00485b41u;
    s.si = s.cx;
  }
  L00485b43: { // 0x485b43: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    debug_va=0x00485b43u;
    s.ax = checked_r32(m,(s.si+0x00000008u));
  }
  L00485b46: { // 0x485b46: 85c0 TEST EAX,EAX
    debug_va=0x00485b46u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00485b48: { // 0x485b48: 7505 JNZ 0x00485b4f
    debug_va=0x00485b48u;
    if(integer::condition("JNZ",flags)) goto L00485b4f;
  }
  L00485b4a: { // 0x485b4a: e891ddffff CALL 0x004838e0
    debug_va=0x00485b4au;
    s.arithmetic_flags=flags; invoke(m,s,f,0x004838e0u,4741967u); flags=s.arithmetic_flags;
  }
  L00485b4f: { // 0x485b4f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    debug_va=0x00485b4fu;
    s.ax = checked_r32(m,(f.sp+0x00000008u));
  }
  L00485b53: { // 0x485b53: a810 TEST AL,0x10
    debug_va=0x00485b53u;
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00485b55: { // 0x485b55: 7458 JZ 0x00485baf
    debug_va=0x00485b55u;
    if(integer::condition("JZ",flags)) goto L00485baf;
  }
  L00485b57: { // 0x485b57: f6c440 TEST AH,0x40
    debug_va=0x00485b57u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485b5a: { // 0x485b5a: 7419 JZ 0x00485b75
    debug_va=0x00485b5au;
    if(integer::condition("JZ",flags)) goto L00485b75;
  }
  L00485b5c: { // 0x485b5c: f6c408 TEST AH,0x8
    debug_va=0x00485b5cu;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b5f: { // 0x485b5f: 740a JZ 0x00485b6b
    debug_va=0x00485b5fu;
    if(integer::condition("JZ",flags)) goto L00485b6b;
  }
  L00485b61: { // 0x485b61: 8b865c010000 MOV EAX,dword ptr [ESI + 0x15c]
    debug_va=0x00485b61u;
    s.ax = checked_r32(m,(s.si+0x0000015cu));
  }
  L00485b67: { // 0x485b67: 5e POP ESI
    debug_va=0x00485b67u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485b68: { // 0x485b68: c20400 RET 0x4
    debug_va=0x00485b68u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b6b: { // 0x485b6b: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    debug_va=0x00485b6bu;
    s.ax = checked_r32(m,(s.si+0x00000110u));
  }
  L00485b71: { // 0x485b71: 5e POP ESI
    debug_va=0x00485b71u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485b72: { // 0x485b72: c20400 RET 0x4
    debug_va=0x00485b72u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b75: { // 0x485b75: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    debug_va=0x00485b75u;
    (void)integer::logical((checked_r32(m,(0x007bebacu)))&(s.ax),32,flags);
  }
  L00485b7b: { // 0x485b7b: 7419 JZ 0x00485b96
    debug_va=0x00485b7bu;
    if(integer::condition("JZ",flags)) goto L00485b96;
  }
  L00485b7d: { // 0x485b7d: f6c408 TEST AH,0x8
    debug_va=0x00485b7du;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b80: { // 0x485b80: 740a JZ 0x00485b8c
    debug_va=0x00485b80u;
    if(integer::condition("JZ",flags)) goto L00485b8c;
  }
  L00485b82: { // 0x485b82: 8b863c010000 MOV EAX,dword ptr [ESI + 0x13c]
    debug_va=0x00485b82u;
    s.ax = checked_r32(m,(s.si+0x0000013cu));
  }
  L00485b88: { // 0x485b88: 5e POP ESI
    debug_va=0x00485b88u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485b89: { // 0x485b89: c20400 RET 0x4
    debug_va=0x00485b89u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b8c: { // 0x485b8c: 8b86ec000000 MOV EAX,dword ptr [ESI + 0xec]
    debug_va=0x00485b8cu;
    s.ax = checked_r32(m,(s.si+0x000000ecu));
  }
  L00485b92: { // 0x485b92: 5e POP ESI
    debug_va=0x00485b92u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485b93: { // 0x485b93: c20400 RET 0x4
    debug_va=0x00485b93u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b96: { // 0x485b96: f6c408 TEST AH,0x8
    debug_va=0x00485b96u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b99: { // 0x485b99: 740a JZ 0x00485ba5
    debug_va=0x00485b99u;
    if(integer::condition("JZ",flags)) goto L00485ba5;
  }
  L00485b9b: { // 0x485b9b: 8b8628010000 MOV EAX,dword ptr [ESI + 0x128]
    debug_va=0x00485b9bu;
    s.ax = checked_r32(m,(s.si+0x00000128u));
  }
  L00485ba1: { // 0x485ba1: 5e POP ESI
    debug_va=0x00485ba1u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485ba2: { // 0x485ba2: c20400 RET 0x4
    debug_va=0x00485ba2u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ba5: { // 0x485ba5: 8b86d8000000 MOV EAX,dword ptr [ESI + 0xd8]
    debug_va=0x00485ba5u;
    s.ax = checked_r32(m,(s.si+0x000000d8u));
  }
  L00485bab: { // 0x485bab: 5e POP ESI
    debug_va=0x00485babu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485bac: { // 0x485bac: c20400 RET 0x4
    debug_va=0x00485bacu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485baf: { // 0x485baf: 8bc8 MOV ECX,EAX
    debug_va=0x00485bafu;
    s.cx = s.ax;
  }
  L00485bb1: { // 0x485bb1: 83e106 AND ECX,0x6
    debug_va=0x00485bb1u;
    s.cx = integer::logical((s.cx)&(0x00000006u),32,flags);
  }
  L00485bb4: { // 0x485bb4: 83e902 SUB ECX,0x2
    debug_va=0x00485bb4u;
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bb7: { // 0x485bb7: 0f84b2010000 JZ 0x00485d6f
    debug_va=0x00485bb7u;
    if(integer::condition("JZ",flags)) goto L00485d6f;
  }
  L00485bbd: { // 0x485bbd: 83e902 SUB ECX,0x2
    debug_va=0x00485bbdu;
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc0: { // 0x485bc0: 0f8434010000 JZ 0x00485cfa
    debug_va=0x00485bc0u;
    if(integer::condition("JZ",flags)) goto L00485cfa;
  }
  L00485bc6: { // 0x485bc6: 83e902 SUB ECX,0x2
    debug_va=0x00485bc6u;
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc9: { // 0x485bc9: 0f84b6000000 JZ 0x00485c85
    debug_va=0x00485bc9u;
    if(integer::condition("JZ",flags)) goto L00485c85;
  }
  L00485bcf: { // 0x485bcf: a801 TEST AL,0x1
    debug_va=0x00485bcfu;
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00485bd1: { // 0x485bd1: 742b JZ 0x00485bfe
    debug_va=0x00485bd1u;
    if(integer::condition("JZ",flags)) goto L00485bfe;
  }
  L00485bd3: { // 0x485bd3: f6c440 TEST AH,0x40
    debug_va=0x00485bd3u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485bd6: { // 0x485bd6: 740a JZ 0x00485be2
    debug_va=0x00485bd6u;
    if(integer::condition("JZ",flags)) goto L00485be2;
  }
  L00485bd8: { // 0x485bd8: 8b8614010000 MOV EAX,dword ptr [ESI + 0x114]
    debug_va=0x00485bd8u;
    s.ax = checked_r32(m,(s.si+0x00000114u));
  }
  L00485bde: { // 0x485bde: 5e POP ESI
    debug_va=0x00485bdeu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485bdf: { // 0x485bdf: c20400 RET 0x4
    debug_va=0x00485bdfu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485be2: { // 0x485be2: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    debug_va=0x00485be2u;
    (void)integer::logical((checked_r32(m,(0x007bebacu)))&(s.ax),32,flags);
  }
  L00485be8: { // 0x485be8: 740a JZ 0x00485bf4
    debug_va=0x00485be8u;
    if(integer::condition("JZ",flags)) goto L00485bf4;
  }
  L00485bea: { // 0x485bea: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    debug_va=0x00485beau;
    s.ax = checked_r32(m,(s.si+0x000000f0u));
  }
  L00485bf0: { // 0x485bf0: 5e POP ESI
    debug_va=0x00485bf0u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485bf1: { // 0x485bf1: c20400 RET 0x4
    debug_va=0x00485bf1u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bf4: { // 0x485bf4: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    debug_va=0x00485bf4u;
    s.ax = checked_r32(m,(s.si+0x000000d4u));
  }
  L00485bfa: { // 0x485bfa: 5e POP ESI
    debug_va=0x00485bfau;
    const auto value=f.pop(m); s.si = value;
  }
  L00485bfb: { // 0x485bfb: c20400 RET 0x4
    debug_va=0x00485bfbu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bfe: { // 0x485bfe: a820 TEST AL,0x20
    debug_va=0x00485bfeu;
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L00485c00: { // 0x485c00: 742b JZ 0x00485c2d
    debug_va=0x00485c00u;
    if(integer::condition("JZ",flags)) goto L00485c2d;
  }
  L00485c02: { // 0x485c02: f6c440 TEST AH,0x40
    debug_va=0x00485c02u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c05: { // 0x485c05: 740f JZ 0x00485c16
    debug_va=0x00485c05u;
    if(integer::condition("JZ",flags)) goto L00485c16;
  }
  L00485c07: { // 0x485c07: f6c408 TEST AH,0x8
    debug_va=0x00485c07u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c0a: { // 0x485c0a: 7435 JZ 0x00485c41
    debug_va=0x00485c0au;
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c0c: { // 0x485c0c: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    debug_va=0x00485c0cu;
    s.ax = checked_r32(m,(s.si+0x00000158u));
  }
  L00485c12: { // 0x485c12: 5e POP ESI
    debug_va=0x00485c12u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c13: { // 0x485c13: c20400 RET 0x4
    debug_va=0x00485c13u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c16: { // 0x485c16: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    debug_va=0x00485c16u;
    (void)integer::logical((checked_r32(m,(0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c1c: { // 0x485c1c: 744e JZ 0x00485c6c
    debug_va=0x00485c1cu;
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c1e: { // 0x485c1e: f6c408 TEST AH,0x8
    debug_va=0x00485c1eu;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c21: { // 0x485c21: 743f JZ 0x00485c62
    debug_va=0x00485c21u;
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c23: { // 0x485c23: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    debug_va=0x00485c23u;
    s.ax = checked_r32(m,(s.si+0x00000138u));
  }
  L00485c29: { // 0x485c29: 5e POP ESI
    debug_va=0x00485c29u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c2a: { // 0x485c2a: c20400 RET 0x4
    debug_va=0x00485c2au;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c2d: { // 0x485c2d: f6c440 TEST AH,0x40
    debug_va=0x00485c2du;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c30: { // 0x485c30: 7419 JZ 0x00485c4b
    debug_va=0x00485c30u;
    if(integer::condition("JZ",flags)) goto L00485c4b;
  }
  L00485c32: { // 0x485c32: f6c408 TEST AH,0x8
    debug_va=0x00485c32u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c35: { // 0x485c35: 740a JZ 0x00485c41
    debug_va=0x00485c35u;
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c37: { // 0x485c37: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    debug_va=0x00485c37u;
    s.ax = checked_r32(m,(s.si+0x00000158u));
  }
  L00485c3d: { // 0x485c3d: 5e POP ESI
    debug_va=0x00485c3du;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c3e: { // 0x485c3e: c20400 RET 0x4
    debug_va=0x00485c3eu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c41: { // 0x485c41: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    debug_va=0x00485c41u;
    s.ax = checked_r32(m,(s.si+0x0000010cu));
  }
  L00485c47: { // 0x485c47: 5e POP ESI
    debug_va=0x00485c47u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c48: { // 0x485c48: c20400 RET 0x4
    debug_va=0x00485c48u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c4b: { // 0x485c4b: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    debug_va=0x00485c4bu;
    (void)integer::logical((checked_r32(m,(0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c51: { // 0x485c51: 7419 JZ 0x00485c6c
    debug_va=0x00485c51u;
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c53: { // 0x485c53: f6c408 TEST AH,0x8
    debug_va=0x00485c53u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c56: { // 0x485c56: 740a JZ 0x00485c62
    debug_va=0x00485c56u;
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c58: { // 0x485c58: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    debug_va=0x00485c58u;
    s.ax = checked_r32(m,(s.si+0x00000138u));
  }
  L00485c5e: { // 0x485c5e: 5e POP ESI
    debug_va=0x00485c5eu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c5f: { // 0x485c5f: c20400 RET 0x4
    debug_va=0x00485c5fu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c62: { // 0x485c62: 8b86e8000000 MOV EAX,dword ptr [ESI + 0xe8]
    debug_va=0x00485c62u;
    s.ax = checked_r32(m,(s.si+0x000000e8u));
  }
  L00485c68: { // 0x485c68: 5e POP ESI
    debug_va=0x00485c68u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c69: { // 0x485c69: c20400 RET 0x4
    debug_va=0x00485c69u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c6c: { // 0x485c6c: f6c408 TEST AH,0x8
    debug_va=0x00485c6cu;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c6f: { // 0x485c6f: 740a JZ 0x00485c7b
    debug_va=0x00485c6fu;
    if(integer::condition("JZ",flags)) goto L00485c7b;
  }
  L00485c71: { // 0x485c71: 8b8624010000 MOV EAX,dword ptr [ESI + 0x124]
    debug_va=0x00485c71u;
    s.ax = checked_r32(m,(s.si+0x00000124u));
  }
  L00485c77: { // 0x485c77: 5e POP ESI
    debug_va=0x00485c77u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c78: { // 0x485c78: c20400 RET 0x4
    debug_va=0x00485c78u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c7b: { // 0x485c7b: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    debug_va=0x00485c7bu;
    s.ax = checked_r32(m,(s.si+0x000000d0u));
  }
  L00485c81: { // 0x485c81: 5e POP ESI
    debug_va=0x00485c81u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c82: { // 0x485c82: c20400 RET 0x4
    debug_va=0x00485c82u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c85: { // 0x485c85: f6c440 TEST AH,0x40
    debug_va=0x00485c85u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c88: { // 0x485c88: 7419 JZ 0x00485ca3
    debug_va=0x00485c88u;
    if(integer::condition("JZ",flags)) goto L00485ca3;
  }
  L00485c8a: { // 0x485c8a: f6c408 TEST AH,0x8
    debug_va=0x00485c8au;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c8d: { // 0x485c8d: 740a JZ 0x00485c99
    debug_va=0x00485c8du;
    if(integer::condition("JZ",flags)) goto L00485c99;
  }
  L00485c8f: { // 0x485c8f: 8b8660010000 MOV EAX,dword ptr [ESI + 0x160]
    debug_va=0x00485c8fu;
    s.ax = checked_r32(m,(s.si+0x00000160u));
  }
  L00485c95: { // 0x485c95: 5e POP ESI
    debug_va=0x00485c95u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485c96: { // 0x485c96: c20400 RET 0x4
    debug_va=0x00485c96u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c99: { // 0x485c99: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    debug_va=0x00485c99u;
    s.ax = checked_r32(m,(s.si+0x00000118u));
  }
  L00485c9f: { // 0x485c9f: 5e POP ESI
    debug_va=0x00485c9fu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485ca0: { // 0x485ca0: c20400 RET 0x4
    debug_va=0x00485ca0u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ca3: { // 0x485ca3: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    debug_va=0x00485ca3u;
    (void)integer::logical((checked_r32(m,(0x007bebacu)))&(s.ax),32,flags);
  }
  L00485ca9: { // 0x485ca9: 7436 JZ 0x00485ce1
    debug_va=0x00485ca9u;
    if(integer::condition("JZ",flags)) goto L00485ce1;
  }
  L00485cab: { // 0x485cab: a808 TEST AL,0x8
    debug_va=0x00485cabu;
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cad: { // 0x485cad: 7419 JZ 0x00485cc8
    debug_va=0x00485cadu;
    if(integer::condition("JZ",flags)) goto L00485cc8;
  }
  L00485caf: { // 0x485caf: f6c408 TEST AH,0x8
    debug_va=0x00485cafu;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cb2: { // 0x485cb2: 740a JZ 0x00485cbe
    debug_va=0x00485cb2u;
    if(integer::condition("JZ",flags)) goto L00485cbe;
  }
  L00485cb4: { // 0x485cb4: 8b864c010000 MOV EAX,dword ptr [ESI + 0x14c]
    debug_va=0x00485cb4u;
    s.ax = checked_r32(m,(s.si+0x0000014cu));
  }
  L00485cba: { // 0x485cba: 5e POP ESI
    debug_va=0x00485cbau;
    const auto value=f.pop(m); s.si = value;
  }
  L00485cbb: { // 0x485cbb: c20400 RET 0x4
    debug_va=0x00485cbbu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cbe: { // 0x485cbe: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    debug_va=0x00485cbeu;
    s.ax = checked_r32(m,(s.si+0x00000100u));
  }
  L00485cc4: { // 0x485cc4: 5e POP ESI
    debug_va=0x00485cc4u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485cc5: { // 0x485cc5: c20400 RET 0x4
    debug_va=0x00485cc5u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cc8: { // 0x485cc8: f6c408 TEST AH,0x8
    debug_va=0x00485cc8u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ccb: { // 0x485ccb: 740a JZ 0x00485cd7
    debug_va=0x00485ccbu;
    if(integer::condition("JZ",flags)) goto L00485cd7;
  }
  L00485ccd: { // 0x485ccd: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    debug_va=0x00485ccdu;
    s.ax = checked_r32(m,(s.si+0x00000140u));
  }
  L00485cd3: { // 0x485cd3: 5e POP ESI
    debug_va=0x00485cd3u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485cd4: { // 0x485cd4: c20400 RET 0x4
    debug_va=0x00485cd4u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cd7: { // 0x485cd7: 8b86f4000000 MOV EAX,dword ptr [ESI + 0xf4]
    debug_va=0x00485cd7u;
    s.ax = checked_r32(m,(s.si+0x000000f4u));
  }
  L00485cdd: { // 0x485cdd: 5e POP ESI
    debug_va=0x00485cddu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485cde: { // 0x485cde: c20400 RET 0x4
    debug_va=0x00485cdeu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ce1: { // 0x485ce1: f6c408 TEST AH,0x8
    debug_va=0x00485ce1u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ce4: { // 0x485ce4: 740a JZ 0x00485cf0
    debug_va=0x00485ce4u;
    if(integer::condition("JZ",flags)) goto L00485cf0;
  }
  L00485ce6: { // 0x485ce6: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    debug_va=0x00485ce6u;
    s.ax = checked_r32(m,(s.si+0x0000012cu));
  }
  L00485cec: { // 0x485cec: 5e POP ESI
    debug_va=0x00485cecu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485ced: { // 0x485ced: c20400 RET 0x4
    debug_va=0x00485cedu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cf0: { // 0x485cf0: 8b86dc000000 MOV EAX,dword ptr [ESI + 0xdc]
    debug_va=0x00485cf0u;
    s.ax = checked_r32(m,(s.si+0x000000dcu));
  }
  L00485cf6: { // 0x485cf6: 5e POP ESI
    debug_va=0x00485cf6u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485cf7: { // 0x485cf7: c20400 RET 0x4
    debug_va=0x00485cf7u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cfa: { // 0x485cfa: f6c440 TEST AH,0x40
    debug_va=0x00485cfau;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485cfd: { // 0x485cfd: 7419 JZ 0x00485d18
    debug_va=0x00485cfdu;
    if(integer::condition("JZ",flags)) goto L00485d18;
  }
  L00485cff: { // 0x485cff: f6c408 TEST AH,0x8
    debug_va=0x00485cffu;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d02: { // 0x485d02: 740a JZ 0x00485d0e
    debug_va=0x00485d02u;
    if(integer::condition("JZ",flags)) goto L00485d0e;
  }
  L00485d04: { // 0x485d04: 8b8664010000 MOV EAX,dword ptr [ESI + 0x164]
    debug_va=0x00485d04u;
    s.ax = checked_r32(m,(s.si+0x00000164u));
  }
  L00485d0a: { // 0x485d0a: 5e POP ESI
    debug_va=0x00485d0au;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d0b: { // 0x485d0b: c20400 RET 0x4
    debug_va=0x00485d0bu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d0e: { // 0x485d0e: 8b861c010000 MOV EAX,dword ptr [ESI + 0x11c]
    debug_va=0x00485d0eu;
    s.ax = checked_r32(m,(s.si+0x0000011cu));
  }
  L00485d14: { // 0x485d14: 5e POP ESI
    debug_va=0x00485d14u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d15: { // 0x485d15: c20400 RET 0x4
    debug_va=0x00485d15u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d18: { // 0x485d18: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    debug_va=0x00485d18u;
    (void)integer::logical((checked_r32(m,(0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d1e: { // 0x485d1e: 7436 JZ 0x00485d56
    debug_va=0x00485d1eu;
    if(integer::condition("JZ",flags)) goto L00485d56;
  }
  L00485d20: { // 0x485d20: a808 TEST AL,0x8
    debug_va=0x00485d20u;
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d22: { // 0x485d22: 7419 JZ 0x00485d3d
    debug_va=0x00485d22u;
    if(integer::condition("JZ",flags)) goto L00485d3d;
  }
  L00485d24: { // 0x485d24: f6c408 TEST AH,0x8
    debug_va=0x00485d24u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d27: { // 0x485d27: 740a JZ 0x00485d33
    debug_va=0x00485d27u;
    if(integer::condition("JZ",flags)) goto L00485d33;
  }
  L00485d29: { // 0x485d29: 8b8650010000 MOV EAX,dword ptr [ESI + 0x150]
    debug_va=0x00485d29u;
    s.ax = checked_r32(m,(s.si+0x00000150u));
  }
  L00485d2f: { // 0x485d2f: 5e POP ESI
    debug_va=0x00485d2fu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d30: { // 0x485d30: c20400 RET 0x4
    debug_va=0x00485d30u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d33: { // 0x485d33: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    debug_va=0x00485d33u;
    s.ax = checked_r32(m,(s.si+0x00000104u));
  }
  L00485d39: { // 0x485d39: 5e POP ESI
    debug_va=0x00485d39u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d3a: { // 0x485d3a: c20400 RET 0x4
    debug_va=0x00485d3au;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d3d: { // 0x485d3d: f6c408 TEST AH,0x8
    debug_va=0x00485d3du;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d40: { // 0x485d40: 740a JZ 0x00485d4c
    debug_va=0x00485d40u;
    if(integer::condition("JZ",flags)) goto L00485d4c;
  }
  L00485d42: { // 0x485d42: 8b8644010000 MOV EAX,dword ptr [ESI + 0x144]
    debug_va=0x00485d42u;
    s.ax = checked_r32(m,(s.si+0x00000144u));
  }
  L00485d48: { // 0x485d48: 5e POP ESI
    debug_va=0x00485d48u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d49: { // 0x485d49: c20400 RET 0x4
    debug_va=0x00485d49u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d4c: { // 0x485d4c: 8b86f8000000 MOV EAX,dword ptr [ESI + 0xf8]
    debug_va=0x00485d4cu;
    s.ax = checked_r32(m,(s.si+0x000000f8u));
  }
  L00485d52: { // 0x485d52: 5e POP ESI
    debug_va=0x00485d52u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d53: { // 0x485d53: c20400 RET 0x4
    debug_va=0x00485d53u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d56: { // 0x485d56: f6c408 TEST AH,0x8
    debug_va=0x00485d56u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d59: { // 0x485d59: 740a JZ 0x00485d65
    debug_va=0x00485d59u;
    if(integer::condition("JZ",flags)) goto L00485d65;
  }
  L00485d5b: { // 0x485d5b: 8b8630010000 MOV EAX,dword ptr [ESI + 0x130]
    debug_va=0x00485d5bu;
    s.ax = checked_r32(m,(s.si+0x00000130u));
  }
  L00485d61: { // 0x485d61: 5e POP ESI
    debug_va=0x00485d61u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d62: { // 0x485d62: c20400 RET 0x4
    debug_va=0x00485d62u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d65: { // 0x485d65: 8b86e0000000 MOV EAX,dword ptr [ESI + 0xe0]
    debug_va=0x00485d65u;
    s.ax = checked_r32(m,(s.si+0x000000e0u));
  }
  L00485d6b: { // 0x485d6b: 5e POP ESI
    debug_va=0x00485d6bu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d6c: { // 0x485d6c: c20400 RET 0x4
    debug_va=0x00485d6cu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d6f: { // 0x485d6f: f6c440 TEST AH,0x40
    debug_va=0x00485d6fu;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485d72: { // 0x485d72: 7419 JZ 0x00485d8d
    debug_va=0x00485d72u;
    if(integer::condition("JZ",flags)) goto L00485d8d;
  }
  L00485d74: { // 0x485d74: f6c408 TEST AH,0x8
    debug_va=0x00485d74u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d77: { // 0x485d77: 740a JZ 0x00485d83
    debug_va=0x00485d77u;
    if(integer::condition("JZ",flags)) goto L00485d83;
  }
  L00485d79: { // 0x485d79: 8b8668010000 MOV EAX,dword ptr [ESI + 0x168]
    debug_va=0x00485d79u;
    s.ax = checked_r32(m,(s.si+0x00000168u));
  }
  L00485d7f: { // 0x485d7f: 5e POP ESI
    debug_va=0x00485d7fu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d80: { // 0x485d80: c20400 RET 0x4
    debug_va=0x00485d80u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d83: { // 0x485d83: 8b8620010000 MOV EAX,dword ptr [ESI + 0x120]
    debug_va=0x00485d83u;
    s.ax = checked_r32(m,(s.si+0x00000120u));
  }
  L00485d89: { // 0x485d89: 5e POP ESI
    debug_va=0x00485d89u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485d8a: { // 0x485d8a: c20400 RET 0x4
    debug_va=0x00485d8au;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d8d: { // 0x485d8d: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    debug_va=0x00485d8du;
    (void)integer::logical((checked_r32(m,(0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d93: { // 0x485d93: 7436 JZ 0x00485dcb
    debug_va=0x00485d93u;
    if(integer::condition("JZ",flags)) goto L00485dcb;
  }
  L00485d95: { // 0x485d95: a808 TEST AL,0x8
    debug_va=0x00485d95u;
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d97: { // 0x485d97: 7419 JZ 0x00485db2
    debug_va=0x00485d97u;
    if(integer::condition("JZ",flags)) goto L00485db2;
  }
  L00485d99: { // 0x485d99: f6c408 TEST AH,0x8
    debug_va=0x00485d99u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d9c: { // 0x485d9c: 740a JZ 0x00485da8
    debug_va=0x00485d9cu;
    if(integer::condition("JZ",flags)) goto L00485da8;
  }
  L00485d9e: { // 0x485d9e: 8b8654010000 MOV EAX,dword ptr [ESI + 0x154]
    debug_va=0x00485d9eu;
    s.ax = checked_r32(m,(s.si+0x00000154u));
  }
  L00485da4: { // 0x485da4: 5e POP ESI
    debug_va=0x00485da4u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485da5: { // 0x485da5: c20400 RET 0x4
    debug_va=0x00485da5u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485da8: { // 0x485da8: 8b8608010000 MOV EAX,dword ptr [ESI + 0x108]
    debug_va=0x00485da8u;
    s.ax = checked_r32(m,(s.si+0x00000108u));
  }
  L00485dae: { // 0x485dae: 5e POP ESI
    debug_va=0x00485daeu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485daf: { // 0x485daf: c20400 RET 0x4
    debug_va=0x00485dafu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485db2: { // 0x485db2: f6c408 TEST AH,0x8
    debug_va=0x00485db2u;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485db5: { // 0x485db5: 740a JZ 0x00485dc1
    debug_va=0x00485db5u;
    if(integer::condition("JZ",flags)) goto L00485dc1;
  }
  L00485db7: { // 0x485db7: 8b8648010000 MOV EAX,dword ptr [ESI + 0x148]
    debug_va=0x00485db7u;
    s.ax = checked_r32(m,(s.si+0x00000148u));
  }
  L00485dbd: { // 0x485dbd: 5e POP ESI
    debug_va=0x00485dbdu;
    const auto value=f.pop(m); s.si = value;
  }
  L00485dbe: { // 0x485dbe: c20400 RET 0x4
    debug_va=0x00485dbeu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dc1: { // 0x485dc1: 8b86fc000000 MOV EAX,dword ptr [ESI + 0xfc]
    debug_va=0x00485dc1u;
    s.ax = checked_r32(m,(s.si+0x000000fcu));
  }
  L00485dc7: { // 0x485dc7: 5e POP ESI
    debug_va=0x00485dc7u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485dc8: { // 0x485dc8: c20400 RET 0x4
    debug_va=0x00485dc8u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dcb: { // 0x485dcb: f6c408 TEST AH,0x8
    debug_va=0x00485dcbu;
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485dce: { // 0x485dce: 740a JZ 0x00485dda
    debug_va=0x00485dceu;
    if(integer::condition("JZ",flags)) goto L00485dda;
  }
  L00485dd0: { // 0x485dd0: 8b8634010000 MOV EAX,dword ptr [ESI + 0x134]
    debug_va=0x00485dd0u;
    s.ax = checked_r32(m,(s.si+0x00000134u));
  }
  L00485dd6: { // 0x485dd6: 5e POP ESI
    debug_va=0x00485dd6u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485dd7: { // 0x485dd7: c20400 RET 0x4
    debug_va=0x00485dd7u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dda: { // 0x485dda: 8b86e4000000 MOV EAX,dword ptr [ESI + 0xe4]
    debug_va=0x00485ddau;
    s.ax = checked_r32(m,(s.si+0x000000e4u));
  }
  L00485de0: { // 0x485de0: 5e POP ESI
    debug_va=0x00485de0u;
    const auto value=f.pop(m); s.si = value;
  }
  L00485de1: { // 0x485de1: c20400 RET 0x4
    debug_va=0x00485de1u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00034f80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00434f80: { // 0x434f80: 83ec68 SUB ESP,0x68
    debug_va=0x00434f80u;
    f.sp = integer::sub(f.sp,0x00000068u,32,flags);
  }
  L00434f83: { // 0x434f83: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    debug_va=0x00434f83u;
    s.ax = checked_r32(m,(f.sp+0x00000078u));
  }
  L00434f87: { // 0x434f87: 53 PUSH EBX
    debug_va=0x00434f87u;
    f.push(m,s.bx);
  }
  L00434f88: { // 0x434f88: 55 PUSH EBP
    debug_va=0x00434f88u;
    f.push(m,s.bp);
  }
  L00434f89: { // 0x434f89: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    debug_va=0x00434f89u;
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00434f8d: { // 0x434f8d: 8b08 MOV ECX,dword ptr [EAX]
    debug_va=0x00434f8du;
    s.cx = checked_r32(m,(s.ax));
  }
  L00434f8f: { // 0x434f8f: 56 PUSH ESI
    debug_va=0x00434f8fu;
    f.push(m,s.si);
  }
  L00434f90: { // 0x434f90: 57 PUSH EDI
    debug_va=0x00434f90u;
    f.push(m,s.di);
  }
  L00434f91: { // 0x434f91: 8b6c247c MOV EBP,dword ptr [ESP + 0x7c]
    debug_va=0x00434f91u;
    s.bp = checked_r32(m,(f.sp+0x0000007cu));
  }
  L00434f95: { // 0x434f95: 8bfa MOV EDI,EDX
    debug_va=0x00434f95u;
    s.di = s.dx;
  }
  L00434f97: { // 0x434f97: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    debug_va=0x00434f97u;
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L00434f9b: { // 0x434f9b: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    debug_va=0x00434f9bu;
    s.dx = checked_r32(m,(s.ax+0x00000004u));
  }
  L00434f9e: { // 0x434f9e: 8b9c2484000000 MOV EBX,dword ptr [ESP + 0x84]
    debug_va=0x00434f9eu;
    s.bx = checked_r32(m,(f.sp+0x00000084u));
  }
  L00434fa5: { // 0x434fa5: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    debug_va=0x00434fa5u;
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L00434fa9: { // 0x434fa9: 53 PUSH EBX
    debug_va=0x00434fa9u;
    f.push(m,s.bx);
  }
  L00434faa: { // 0x434faa: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    debug_va=0x00434faau;
    s.cx = checked_r32(m,(s.ax+0x00000008u));
  }
  L00434fad: { // 0x434fad: 33f6 XOR ESI,ESI
    debug_va=0x00434fadu;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00434faf: { // 0x434faf: 894c2474 MOV dword ptr [ESP + 0x74],ECX
    debug_va=0x00434fafu;
    m.w32((f.sp+0x00000074u), s.cx);
  }
  L00434fb3: { // 0x434fb3: 89742420 MOV dword ptr [ESP + 0x20],ESI
    debug_va=0x00434fb3u;
    m.w32((f.sp+0x00000020u), s.si);
  }
  L00434fb7: { // 0x434fb7: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    debug_va=0x00434fb7u;
    s.dx = checked_r32(m,(s.ax+0x0000000cu));
  }
  L00434fba: { // 0x434fba: 8bc5 MOV EAX,EBP
    debug_va=0x00434fbau;
    s.ax = s.bp;
  }
  L00434fbc: { // 0x434fbc: 89542478 MOV dword ptr [ESP + 0x78],EDX
    debug_va=0x00434fbcu;
    m.w32((f.sp+0x00000078u), s.dx);
  }
  L00434fc0: { // 0x434fc0: 89742418 MOV dword ptr [ESP + 0x18],ESI
    debug_va=0x00434fc0u;
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00434fc4: { // 0x434fc4: 8b08 MOV ECX,dword ptr [EAX]
    debug_va=0x00434fc4u;
    s.cx = checked_r32(m,(s.ax));
  }
  L00434fc6: { // 0x434fc6: 89742414 MOV dword ptr [ESP + 0x14],ESI
    debug_va=0x00434fc6u;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00434fca: { // 0x434fca: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    debug_va=0x00434fcau;
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434fce: { // 0x434fce: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    debug_va=0x00434fceu;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00434fd2: { // 0x434fd2: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    debug_va=0x00434fd2u;
    s.dx = checked_r32(m,(s.ax+0x00000004u));
  }
  L00434fd5: { // 0x434fd5: 89742438 MOV dword ptr [ESP + 0x38],ESI
    debug_va=0x00434fd5u;
    m.w32((f.sp+0x00000038u), s.si);
  }
  L00434fd9: { // 0x434fd9: 89542460 MOV dword ptr [ESP + 0x60],EDX
    debug_va=0x00434fd9u;
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00434fdd: { // 0x434fdd: 89b4248c000000 MOV dword ptr [ESP + 0x8c],ESI
    debug_va=0x00434fddu;
    m.w32((f.sp+0x0000008cu), s.si);
  }
  L00434fe4: { // 0x434fe4: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    debug_va=0x00434fe4u;
    s.cx = checked_r32(m,(s.ax+0x00000008u));
  }
  L00434fe7: { // 0x434fe7: 89742434 MOV dword ptr [ESP + 0x34],ESI
    debug_va=0x00434fe7u;
    m.w32((f.sp+0x00000034u), s.si);
  }
  L00434feb: { // 0x434feb: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    debug_va=0x00434febu;
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L00434fef: { // 0x434fef: 89742424 MOV dword ptr [ESP + 0x24],ESI
    debug_va=0x00434fefu;
    m.w32((f.sp+0x00000024u), s.si);
  }
  L00434ff3: { // 0x434ff3: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    debug_va=0x00434ff3u;
    s.dx = checked_r32(m,(s.ax+0x0000000cu));
  }
  L00434ff6: { // 0x434ff6: 8b842498000000 MOV EAX,dword ptr [ESP + 0x98]
    debug_va=0x00434ff6u;
    s.ax = checked_r32(m,(f.sp+0x00000098u));
  }
  L00434ffd: { // 0x434ffd: 89542468 MOV dword ptr [ESP + 0x68],EDX
    debug_va=0x00434ffdu;
    m.w32((f.sp+0x00000068u), s.dx);
  }
  L00435001: { // 0x435001: 8d54246c LEA EDX,[ESP + 0x6c]
    debug_va=0x00435001u;
    s.dx = (f.sp+0x0000006cu);
  }
  L00435005: { // 0x435005: 8d0440 LEA EAX,[EAX + EAX*0x2]
    debug_va=0x00435005u;
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00435008: { // 0x435008: 52 PUSH EDX
    debug_va=0x00435008u;
    f.push(m,s.dx);
  }
  L00435009: { // 0x435009: 8bd7 MOV EDX,EDI
    debug_va=0x00435009u;
    s.dx = s.di;
  }
  L0043500b: { // 0x43500b: 89742434 MOV dword ptr [ESP + 0x34],ESI
    debug_va=0x0043500bu;
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0043500f: { // 0x43500f: 8d0cc5f8907b00 LEA ECX,[EAX*0x8 + 0x7b90f8]
    debug_va=0x0043500fu;
    s.cx = ((s.ax * 0x00000008u)+0x007b90f8u);
  }
  L00435016: { // 0x435016: 898c2484000000 MOV dword ptr [ESP + 0x84],ECX
    debug_va=0x00435016u;
    m.w32((f.sp+0x00000084u), s.cx);
  }
  L0043501d: { // 0x43501d: 8d4c2460 LEA ECX,[ESP + 0x60]
    debug_va=0x0043501du;
    s.cx = (f.sp+0x00000060u);
  }
  L00435021: { // 0x435021: e8aaba3200 CALL 0x00760ad0
    debug_va=0x00435021u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760ad0u,4411430u); flags=s.arithmetic_flags;
  }
  L00435026: { // 0x435026: 84c0 TEST AL,AL
    debug_va=0x00435026u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00435028: { // 0x435028: 750a JNZ 0x00435034
    debug_va=0x00435028u;
    if(integer::condition("JNZ",flags)) goto L00435034;
  }
  L0043502a: { // 0x43502a: 5f POP EDI
    debug_va=0x0043502au;
    const auto value=f.pop(m); s.di = value;
  }
  L0043502b: { // 0x43502b: 5e POP ESI
    debug_va=0x0043502bu;
    const auto value=f.pop(m); s.si = value;
  }
  L0043502c: { // 0x43502c: 5d POP EBP
    debug_va=0x0043502cu;
    const auto value=f.pop(m); s.bp = value;
  }
  L0043502d: { // 0x43502d: 5b POP EBX
    debug_va=0x0043502du;
    const auto value=f.pop(m); s.bx = value;
  }
  L0043502e: { // 0x43502e: 83c468 ADD ESP,0x68
    debug_va=0x0043502eu;
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L00435031: { // 0x435031: c23000 RET 0x30
    debug_va=0x00435031u;
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L00435034: { // 0x435034: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    debug_va=0x00435034u;
    s.ax = checked_r32(m,(f.sp+0x00000068u));
  }
  L00435038: { // 0x435038: 8b13 MOV EDX,dword ptr [EBX]
    debug_va=0x00435038u;
    s.dx = checked_r32(m,(s.bx));
  }
  L0043503a: { // 0x43503a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    debug_va=0x0043503au;
    s.cx = checked_r32(m,(s.bx+0x00000004u));
  }
  L0043503d: { // 0x43503d: 2bc2 SUB EAX,EDX
    debug_va=0x0043503du;
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0043503f: { // 0x43503f: 89442424 MOV dword ptr [ESP + 0x24],EAX
    debug_va=0x0043503fu;
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00435043: { // 0x435043: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    debug_va=0x00435043u;
    s.ax = checked_r32(m,(f.sp+0x0000006cu));
  }
  L00435047: { // 0x435047: 2bc1 SUB EAX,ECX
    debug_va=0x00435047u;
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00435049: { // 0x435049: 8d4c2458 LEA ECX,[ESP + 0x58]
    debug_va=0x00435049u;
    s.cx = (f.sp+0x00000058u);
  }
  L0043504d: { // 0x43504d: 89842484000000 MOV dword ptr [ESP + 0x84],EAX
    debug_va=0x0043504du;
    m.w32((f.sp+0x00000084u), s.ax);
  }
  L00435054: { // 0x435054: 8d442438 LEA EAX,[ESP + 0x38]
    debug_va=0x00435054u;
    s.ax = (f.sp+0x00000038u);
  }
  L00435058: { // 0x435058: 50 PUSH EAX
    debug_va=0x00435058u;
    f.push(m,s.ax);
  }
  L00435059: { // 0x435059: e8c2030000 CALL 0x00435420
    debug_va=0x00435059u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,4411486u); flags=s.arithmetic_flags;
  }
  L0043505e: { // 0x43505e: 8d4c2440 LEA ECX,[ESP + 0x40]
    debug_va=0x0043505eu;
    s.cx = (f.sp+0x00000040u);
  }
  L00435062: { // 0x435062: 8d542448 LEA EDX,[ESP + 0x48]
    debug_va=0x00435062u;
    s.dx = (f.sp+0x00000048u);
  }
  L00435066: { // 0x435066: 50 PUSH EAX
    debug_va=0x00435066u;
    f.push(m,s.ax);
  }
  L00435067: { // 0x435067: 51 PUSH ECX
    debug_va=0x00435067u;
    f.push(m,s.cx);
  }
  L00435068: { // 0x435068: 52 PUSH EDX
    debug_va=0x00435068u;
    f.push(m,s.dx);
  }
  L00435069: { // 0x435069: 8bcf MOV ECX,EDI
    debug_va=0x00435069u;
    s.cx = s.di;
  }
  L0043506b: { // 0x43506b: e8b0030000 CALL 0x00435420
    debug_va=0x0043506bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,4411504u); flags=s.arithmetic_flags;
  }
  L00435070: { // 0x435070: 8bc8 MOV ECX,EAX
    debug_va=0x00435070u;
    s.cx = s.ax;
  }
  L00435072: { // 0x435072: e889030000 CALL 0x00435400
    debug_va=0x00435072u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,4411511u); flags=s.arithmetic_flags;
  }
  L00435077: { // 0x435077: 8b10 MOV EDX,dword ptr [EAX]
    debug_va=0x00435077u;
    s.dx = checked_r32(m,(s.ax));
  }
  L00435079: { // 0x435079: 83ec08 SUB ESP,0x8
    debug_va=0x00435079u;
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0043507c: { // 0x43507c: 8bcc MOV ECX,ESP
    debug_va=0x0043507cu;
    s.cx = f.sp;
  }
  L0043507e: { // 0x43507e: 8911 MOV dword ptr [ECX],EDX
    debug_va=0x0043507eu;
    m.w32((s.cx), s.dx);
  }
  L00435080: { // 0x435080: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    debug_va=0x00435080u;
    s.ax = checked_r32(m,(s.ax+0x00000004u));
  }
  L00435083: { // 0x435083: 894104 MOV dword ptr [ECX + 0x4],EAX
    debug_va=0x00435083u;
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00435086: { // 0x435086: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    debug_va=0x00435086u;
    s.cx = checked_r32(m,(f.sp+0x00000020u));
  }
  L0043508a: { // 0x43508a: 8b11 MOV EDX,dword ptr [ECX]
    debug_va=0x0043508au;
    s.dx = checked_r32(m,(s.cx));
  }
  L0043508c: { // 0x43508c: ff525c CALL dword ptr [EDX + 0x5c]
    debug_va=0x0043508cu;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.dx+0x0000005cu)),4411535u); flags=s.arithmetic_flags;
  }
  L0043508f: { // 0x43508f: 85c0 TEST EAX,EAX
    debug_va=0x0043508fu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435091: { // 0x435091: 89842494000000 MOV dword ptr [ESP + 0x94],EAX
    debug_va=0x00435091u;
    m.w32((f.sp+0x00000094u), s.ax);
  }
  L00435098: { // 0x435098: 750c JNZ 0x004350a6
    debug_va=0x00435098u;
    if(integer::condition("JNZ",flags)) goto L004350a6;
  }
  L0043509a: { // 0x43509a: 32c0 XOR AL,AL
    debug_va=0x0043509au;
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043509c: { // 0x43509c: 5f POP EDI
    debug_va=0x0043509cu;
    const auto value=f.pop(m); s.di = value;
  }
  L0043509d: { // 0x43509d: 5e POP ESI
    debug_va=0x0043509du;
    const auto value=f.pop(m); s.si = value;
  }
  L0043509e: { // 0x43509e: 5d POP EBP
    debug_va=0x0043509eu;
    const auto value=f.pop(m); s.bp = value;
  }
  L0043509f: { // 0x43509f: 5b POP EBX
    debug_va=0x0043509fu;
    const auto value=f.pop(m); s.bx = value;
  }
  L004350a0: { // 0x4350a0: 83c468 ADD ESP,0x68
    debug_va=0x004350a0u;
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L004350a3: { // 0x4350a3: c23000 RET 0x30
    debug_va=0x004350a3u;
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L004350a6: { // 0x4350a6: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    debug_va=0x004350a6u;
    s.cx = checked_r32(m,(0x00821facu));
  }
  L004350ac: { // 0x4350ac: 85c9 TEST ECX,ECX
    debug_va=0x004350acu;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004350ae: { // 0x4350ae: 0f8471010000 JZ 0x00435225
    debug_va=0x004350aeu;
    if(integer::condition("JZ",flags)) goto L00435225;
  }
  L004350b4: { // 0x4350b4: 8b37 MOV ESI,dword ptr [EDI]
    debug_va=0x004350b4u;
    s.si = checked_r32(m,(s.di));
  }
  L004350b6: { // 0x4350b6: 8b5c2458 MOV EBX,dword ptr [ESP + 0x58]
    debug_va=0x004350b6u;
    s.bx = checked_r32(m,(f.sp+0x00000058u));
  }
  L004350ba: { // 0x4350ba: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    debug_va=0x004350bau;
    s.dx = checked_r32(m,(f.sp+0x0000005cu));
  }
  L004350be: { // 0x4350be: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    debug_va=0x004350beu;
    s.ax = checked_r32(m,(s.di+0x00000004u));
  }
  L004350c1: { // 0x4350c1: 03f3 ADD ESI,EBX
    debug_va=0x004350c1u;
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L004350c3: { // 0x4350c3: 03c2 ADD EAX,EDX
    debug_va=0x004350c3u;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004350c5: { // 0x4350c5: 8bd6 MOV EDX,ESI
    debug_va=0x004350c5u;
    s.dx = s.si;
  }
  L004350c7: { // 0x4350c7: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    debug_va=0x004350c7u;
    s.si = checked_r32(m,(s.cx+0x00000004u));
  }
  L004350ca: { // 0x4350ca: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    debug_va=0x004350cau;
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L004350ce: { // 0x4350ce: 2bc6 SUB EAX,ESI
    debug_va=0x004350ceu;
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L004350d0: { // 0x4350d0: 8bf0 MOV ESI,EAX
    debug_va=0x004350d0u;
    s.si = s.ax;
  }
  L004350d2: { // 0x4350d2: 56 PUSH ESI
    debug_va=0x004350d2u;
    f.push(m,s.si);
  }
  L004350d3: { // 0x4350d3: 52 PUSH EDX
    debug_va=0x004350d3u;
    f.push(m,s.dx);
  }
  L004350d4: { // 0x4350d4: e8a7cb3200 CALL 0x00761c80
    debug_va=0x004350d4u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761c80u,4411609u); flags=s.arithmetic_flags;
  }
  L004350d9: { // 0x4350d9: 8b1dac1f8200 MOV EBX,dword ptr [0x00821fac]
    debug_va=0x004350d9u;
    s.bx = checked_r32(m,(0x00821facu));
  }
  L004350df: { // 0x4350df: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    debug_va=0x004350dfu;
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004350e3: { // 0x4350e3: c784248800000000000000 MOV dword ptr [ESP + 0x88],0x0
    debug_va=0x004350e3u;
    m.w32((f.sp+0x00000088u), 0x00000000u);
  }
  L004350ee: { // 0x4350ee: 8b4328 MOV EAX,dword ptr [EBX + 0x28]
    debug_va=0x004350eeu;
    s.ax = checked_r32(m,(s.bx+0x00000028u));
  }
  L004350f1: { // 0x4350f1: 89442428 MOV dword ptr [ESP + 0x28],EAX
    debug_va=0x004350f1u;
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004350f5: { // 0x4350f5: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    debug_va=0x004350f5u;
    s.ax = checked_r32(m,(f.sp+0x0000007cu));
  }
  L004350f9: { // 0x4350f9: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    debug_va=0x004350f9u;
    s.cx = checked_r32(m,(s.ax+0x00000008u));
  }
  L004350fc: { // 0x4350fc: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    debug_va=0x004350fcu;
    s.ax = checked_r32(m,(s.ax+0x0000000cu));
  }
  L004350ff: { // 0x4350ff: 89442420 MOV dword ptr [ESP + 0x20],EAX
    debug_va=0x004350ffu;
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00435103: { // 0x435103: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    debug_va=0x00435103u;
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00435107: { // 0x435107: 99 CDQ
    debug_va=0x00435107u;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435108: { // 0x435108: f7f9 IDIV ECX
    debug_va=0x00435108u;
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0043510a: { // 0x43510a: 8bc8 MOV ECX,EAX
    debug_va=0x0043510au;
    s.cx = s.ax;
  }
  L0043510c: { // 0x43510c: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    debug_va=0x0043510cu;
    s.ax = checked_r32(m,(f.sp+0x0000007cu));
  }
  L00435110: { // 0x435110: 8a5014 MOV DL,byte ptr [EAX + 0x14]
    debug_va=0x00435110u;
    s.dx = with_al(s.dx, checked_r8(m,(s.ax+0x00000014u)));
  }
  L00435113: { // 0x435113: 84d2 TEST DL,DL
    debug_va=0x00435113u;
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00435115: { // 0x435115: 0f8486000000 JZ 0x004351a1
    debug_va=0x00435115u;
    if(integer::condition("JZ",flags)) goto L004351a1;
  }
  L0043511b: { // 0x43511b: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    debug_va=0x0043511bu;
    s.cx = checked_r32(m,(s.ax+0x00000004u));
  }
  L0043511e: { // 0x43511e: 668b4324 MOV AX,word ptr [EBX + 0x24]
    debug_va=0x0043511eu;
    s.ax = with_ax(s.ax, checked_r16(m,(s.bx+0x00000024u)));
  }
  L00435122: { // 0x435122: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    debug_va=0x00435122u;
    s.dx = checked_r32(m,(f.sp+0x00000090u));
  }
  L00435129: { // 0x435129: 662bc6 SUB AX,SI
    debug_va=0x00435129u;
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L0043512c: { // 0x43512c: 25ffff0000 AND EAX,0xffff
    debug_va=0x0043512cu;
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00435131: { // 0x435131: 03c2 ADD EAX,EDX
    debug_va=0x00435131u;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435133: { // 0x435133: 99 CDQ
    debug_va=0x00435133u;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435134: { // 0x435134: f7f9 IDIV ECX
    debug_va=0x00435134u;
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00435136: { // 0x435136: 8bf0 MOV ESI,EAX
    debug_va=0x00435136u;
    s.si = s.ax;
  }
  L00435138: { // 0x435138: 8b8424a0000000 MOV EAX,dword ptr [ESP + 0xa0]
    debug_va=0x00435138u;
    s.ax = checked_r32(m,(f.sp+0x000000a0u));
  }
  L0043513f: { // 0x43513f: 0faff1 IMUL ESI,ECX
    debug_va=0x0043513fu;
    s.si = integer::imul(s.si,s.cx,32,flags);
  }
  L00435142: { // 0x435142: 85c0 TEST EAX,EAX
    debug_va=0x00435142u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435144: { // 0x435144: 0f84d3000000 JZ 0x0043521d
    debug_va=0x00435144u;
    if(integer::condition("JZ",flags)) goto L0043521d;
  }
  L0043514a: { // 0x43514a: 8bd8 MOV EBX,EAX
    debug_va=0x0043514au;
    s.bx = s.ax;
  }
  L0043514c: { // 0x43514c: 8b13 MOV EDX,dword ptr [EBX]
    debug_va=0x0043514cu;
    s.dx = checked_r32(m,(s.bx));
  }
  L0043514e: { // 0x43514e: 8d442448 LEA EAX,[ESP + 0x48]
    debug_va=0x0043514eu;
    s.ax = (f.sp+0x00000048u);
  }
  L00435152: { // 0x435152: 50 PUSH EAX
    debug_va=0x00435152u;
    f.push(m,s.ax);
  }
  L00435153: { // 0x435153: 8bcb MOV ECX,EBX
    debug_va=0x00435153u;
    s.cx = s.bx;
  }
  L00435155: { // 0x435155: ff5278 CALL dword ptr [EDX + 0x78]
    debug_va=0x00435155u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.dx+0x00000078u)),4411736u); flags=s.arithmetic_flags;
  }
  L00435158: { // 0x435158: 8be8 MOV EBP,EAX
    debug_va=0x00435158u;
    s.bp = s.ax;
  }
  L0043515a: { // 0x43515a: 8b4500 MOV EAX,dword ptr [EBP]
    debug_va=0x0043515au;
    s.ax = checked_r32(m,(s.bp));
  }
  L0043515d: { // 0x43515d: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    debug_va=0x0043515du;
    s.cx = checked_r32(m,(s.bp+0x00000004u));
  }
  L00435160: { // 0x435160: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    debug_va=0x00435160u;
    s.dx = checked_r32(m,(s.bp+0x00000008u));
  }
  L00435163: { // 0x435163: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    debug_va=0x00435163u;
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00435167: { // 0x435167: 8b9424a4000000 MOV EDX,dword ptr [ESP + 0xa4]
    debug_va=0x00435167u;
    s.dx = checked_r32(m,(f.sp+0x000000a4u));
  }
  L0043516e: { // 0x43516e: 03c2 ADD EAX,EDX
    debug_va=0x0043516eu;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435170: { // 0x435170: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    debug_va=0x00435170u;
    s.dx = checked_r32(m,(f.sp+0x000000a8u));
  }
  L00435177: { // 0x435177: 8b6d0c MOV EBP,dword ptr [EBP + 0xc]
    debug_va=0x00435177u;
    s.bp = checked_r32(m,(s.bp+0x0000000cu));
  }
  L0043517a: { // 0x43517a: 03ca ADD ECX,EDX
    debug_va=0x0043517au;
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043517c: { // 0x43517c: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    debug_va=0x0043517cu;
    s.dx = checked_r32(m,(f.sp+0x00000024u));
  }
  L00435180: { // 0x435180: 896c2454 MOV dword ptr [ESP + 0x54],EBP
    debug_va=0x00435180u;
    m.w32((f.sp+0x00000054u), s.bp);
  }
  L00435184: { // 0x435184: 03c2 ADD EAX,EDX
    debug_va=0x00435184u;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435186: { // 0x435186: 8b942484000000 MOV EDX,dword ptr [ESP + 0x84]
    debug_va=0x00435186u;
    s.dx = checked_r32(m,(f.sp+0x00000084u));
  }
  L0043518d: { // 0x43518d: 03ca ADD ECX,EDX
    debug_va=0x0043518du;
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043518f: { // 0x43518f: 8b13 MOV EDX,dword ptr [EBX]
    debug_va=0x0043518fu;
    s.dx = checked_r32(m,(s.bx));
  }
  L00435191: { // 0x435191: 51 PUSH ECX
    debug_va=0x00435191u;
    f.push(m,s.cx);
  }
  L00435192: { // 0x435192: 50 PUSH EAX
    debug_va=0x00435192u;
    f.push(m,s.ax);
  }
  L00435193: { // 0x435193: 8bcb MOV ECX,EBX
    debug_va=0x00435193u;
    s.cx = s.bx;
  }
  L00435195: { // 0x435195: ff525c CALL dword ptr [EDX + 0x5c]
    debug_va=0x00435195u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.dx+0x0000005cu)),4411800u); flags=s.arithmetic_flags;
  }
  L00435198: { // 0x435198: 89442410 MOV dword ptr [ESP + 0x10],EAX
    debug_va=0x00435198u;
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0043519c: { // 0x43519c: e98b000000 JMP 0x0043522c
    debug_va=0x0043519cu;
    goto L0043522c;
  }
  L004351a1: { // 0x4351a1: 668b7324 MOV SI,word ptr [EBX + 0x24]
    debug_va=0x004351a1u;
    s.si = (s.si & 0xffff0000u) | ((checked_r16(m,(s.bx+0x00000024u))) & 0xffffu);
  }
  L004351a5: { // 0x4351a5: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    debug_va=0x004351a5u;
    s.dx = checked_r32(m,(f.sp+0x00000090u));
  }
  L004351ac: { // 0x4351ac: 66037304 ADD SI,word ptr [EBX + 0x4]
    debug_va=0x004351acu;
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),checked_r16(m,(s.bx+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351b0: { // 0x4351b0: 8b9c24a0000000 MOV EBX,dword ptr [ESP + 0xa0]
    debug_va=0x004351b0u;
    s.bx = checked_r32(m,(f.sp+0x000000a0u));
  }
  L004351b7: { // 0x4351b7: 662b7704 SUB SI,word ptr [EDI + 0x4]
    debug_va=0x004351b7u;
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),checked_r16(m,(s.di+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351bb: { // 0x4351bb: 662b750c SUB SI,word ptr [EBP + 0xc]
    debug_va=0x004351bbu;
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),checked_r16(m,(s.bp+0x0000000cu)),16,flags)) & 0xffffu);
  }
  L004351bf: { // 0x4351bf: 662b7504 SUB SI,word ptr [EBP + 0x4]
    debug_va=0x004351bfu;
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),checked_r16(m,(s.bp+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351c3: { // 0x4351c3: 46 INC ESI
    debug_va=0x004351c3u;
    s.si = integer::increment(s.si,32,flags);
  }
  L004351c4: { // 0x4351c4: 81e6ffff0000 AND ESI,0xffff
    debug_va=0x004351c4u;
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L004351ca: { // 0x4351ca: 03f2 ADD ESI,EDX
    debug_va=0x004351cau;
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004351cc: { // 0x4351cc: 85db TEST EBX,EBX
    debug_va=0x004351ccu;
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004351ce: { // 0x4351ce: 0f8578ffffff JNZ 0x0043514c
    debug_va=0x004351ceu;
    if(integer::condition("JNZ",flags)) goto L0043514c;
  }
  L004351d4: { // 0x4351d4: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    debug_va=0x004351d4u;
    s.bx = checked_r32(m,(s.bp+0x0000000cu));
  }
  L004351d7: { // 0x4351d7: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    debug_va=0x004351d7u;
    s.dx = checked_r32(m,(f.sp+0x0000005cu));
  }
  L004351db: { // 0x4351db: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    debug_va=0x004351dbu;
    s.ax = checked_r32(m,(s.bp+0x00000004u));
  }
  L004351de: { // 0x4351de: 2bda SUB EBX,EDX
    debug_va=0x004351deu;
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L004351e0: { // 0x4351e0: 03d8 ADD EBX,EAX
    debug_va=0x004351e0u;
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L004351e2: { // 0x4351e2: 8bc6 MOV EAX,ESI
    debug_va=0x004351e2u;
    s.ax = s.si;
  }
  L004351e4: { // 0x4351e4: 99 CDQ
    debug_va=0x004351e4u;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351e5: { // 0x4351e5: f7f9 IDIV ECX
    debug_va=0x004351e5u;
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351e7: { // 0x4351e7: 8bf0 MOV ESI,EAX
    debug_va=0x004351e7u;
    s.si = s.ax;
  }
  L004351e9: { // 0x4351e9: 8bc3 MOV EAX,EBX
    debug_va=0x004351e9u;
    s.ax = s.bx;
  }
  L004351eb: { // 0x4351eb: 99 CDQ
    debug_va=0x004351ebu;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351ec: { // 0x4351ec: 0faff1 IMUL ESI,ECX
    debug_va=0x004351ecu;
    s.si = integer::imul(s.si,s.cx,32,flags);
  }
  L004351ef: { // 0x4351ef: f7f9 IDIV ECX
    debug_va=0x004351efu;
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351f1: { // 0x4351f1: 2bf0 SUB ESI,EAX
    debug_va=0x004351f1u;
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L004351f3: { // 0x4351f3: 8bc3 MOV EAX,EBX
    debug_va=0x004351f3u;
    s.ax = s.bx;
  }
  L004351f5: { // 0x4351f5: 99 CDQ
    debug_va=0x004351f5u;
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351f6: { // 0x4351f6: f7f9 IDIV ECX
    debug_va=0x004351f6u;
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351f8: { // 0x4351f8: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    debug_va=0x004351f8u;
    s.cx = checked_r32(m,(f.sp+0x00000020u));
  }
  L004351fc: { // 0x4351fc: 8bc1 MOV EAX,ECX
    debug_va=0x004351fcu;
    s.ax = s.cx;
  }
  L004351fe: { // 0x4351fe: 2bc2 SUB EAX,EDX
    debug_va=0x004351feu;
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00435200: { // 0x435200: 3bc1 CMP EAX,ECX
    debug_va=0x00435200u;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00435202: { // 0x435202: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    debug_va=0x00435202u;
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L00435209: { // 0x435209: 7512 JNZ 0x0043521d
    debug_va=0x00435209u;
    if(integer::condition("JNZ",flags)) goto L0043521d;
  }
  L0043520b: { // 0x43520b: 8b4c247c MOV ECX,dword ptr [ESP + 0x7c]
    debug_va=0x0043520bu;
    s.cx = checked_r32(m,(f.sp+0x0000007cu));
  }
  L0043520f: { // 0x43520f: c784248800000000000000 MOV dword ptr [ESP + 0x88],0x0
    debug_va=0x0043520fu;
    m.w32((f.sp+0x00000088u), 0x00000000u);
  }
  L0043521a: { // 0x43521a: 037110 ADD ESI,dword ptr [ECX + 0x10]
    debug_va=0x0043521au;
    s.si = integer::add(s.si,checked_r32(m,(s.cx+0x00000010u)),32,flags);
  }
  L0043521d: { // 0x43521d: c7442410c06d8300 MOV dword ptr [ESP + 0x10],0x836dc0
    debug_va=0x0043521du;
    m.w32((f.sp+0x00000010u), 0x00836dc0u);
  }
  L00435225: { // 0x435225: 8b9c24a0000000 MOV EBX,dword ptr [ESP + 0xa0]
    debug_va=0x00435225u;
    s.bx = checked_r32(m,(f.sp+0x000000a0u));
  }
  L0043522c: { // 0x43522c: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    debug_va=0x0043522cu;
    s.cx = checked_r32(m,(0x008198f4u));
  }
  L00435232: { // 0x435232: 85c9 TEST ECX,ECX
    debug_va=0x00435232u;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00435234: { // 0x435234: 7435 JZ 0x0043526b
    debug_va=0x00435234u;
    if(integer::condition("JZ",flags)) goto L0043526b;
  }
  L00435236: { // 0x435236: 8b17 MOV EDX,dword ptr [EDI]
    debug_va=0x00435236u;
    s.dx = checked_r32(m,(s.di));
  }
  L00435238: { // 0x435238: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    debug_va=0x00435238u;
    s.ax = checked_r32(m,(f.sp+0x00000058u));
  }
  L0043523c: { // 0x43523c: 8b7f04 MOV EDI,dword ptr [EDI + 0x4]
    debug_va=0x0043523cu;
    s.di = checked_r32(m,(s.di+0x00000004u));
  }
  L0043523f: { // 0x43523f: 8b6904 MOV EBP,dword ptr [ECX + 0x4]
    debug_va=0x0043523fu;
    s.bp = checked_r32(m,(s.cx+0x00000004u));
  }
  L00435242: { // 0x435242: 03d0 ADD EDX,EAX
    debug_va=0x00435242u;
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00435244: { // 0x435244: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    debug_va=0x00435244u;
    s.ax = checked_r32(m,(f.sp+0x0000005cu));
  }
  L00435248: { // 0x435248: 03c7 ADD EAX,EDI
    debug_va=0x00435248u;
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0043524a: { // 0x43524a: 898424a8000000 MOV dword ptr [ESP + 0xa8],EAX
    debug_va=0x0043524au;
    m.w32((f.sp+0x000000a8u), s.ax);
  }
  L00435251: { // 0x435251: 2bc5 SUB EAX,EBP
    debug_va=0x00435251u;
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00435253: { // 0x435253: 50 PUSH EAX
    debug_va=0x00435253u;
    f.push(m,s.ax);
  }
  L00435254: { // 0x435254: 52 PUSH EDX
    debug_va=0x00435254u;
    f.push(m,s.dx);
  }
  L00435255: { // 0x435255: e8d6bffdff CALL 0x00411230
    debug_va=0x00435255u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4411994u); flags=s.arithmetic_flags;
  }
  L0043525a: { // 0x43525a: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    debug_va=0x0043525au;
    s.cx = checked_r32(m,(0x008198f4u));
  }
  L00435260: { // 0x435260: 89442414 MOV dword ptr [ESP + 0x14],EAX
    debug_va=0x00435260u;
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00435264: { // 0x435264: 8b5128 MOV EDX,dword ptr [ECX + 0x28]
    debug_va=0x00435264u;
    s.dx = checked_r32(m,(s.cx+0x00000028u));
  }
  L00435267: { // 0x435267: 89542434 MOV dword ptr [ESP + 0x34],EDX
    debug_va=0x00435267u;
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0043526b: { // 0x43526b: 8bac2480000000 MOV EBP,dword ptr [ESP + 0x80]
    debug_va=0x0043526bu;
    s.bp = checked_r32(m,(f.sp+0x00000080u));
  }
  L00435272: { // 0x435272: 33c9 XOR ECX,ECX
    debug_va=0x00435272u;
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00435274: { // 0x435274: 33c0 XOR EAX,EAX
    debug_va=0x00435274u;
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00435276: { // 0x435276: 51 PUSH ECX
    debug_va=0x00435276u;
    f.push(m,s.cx);
  }
  L00435277: { // 0x435277: 8b5500 MOV EDX,dword ptr [EBP]
    debug_va=0x00435277u;
    s.dx = checked_r32(m,(s.bp));
  }
  L0043527a: { // 0x43527a: 50 PUSH EAX
    debug_va=0x0043527au;
    f.push(m,s.ax);
  }
  L0043527b: { // 0x43527b: 8bcd MOV ECX,EBP
    debug_va=0x0043527bu;
    s.cx = s.bp;
  }
  L0043527d: { // 0x43527d: ff525c CALL dword ptr [EDX + 0x5c]
    debug_va=0x0043527du;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.dx+0x0000005cu)),4412032u); flags=s.arithmetic_flags;
  }
  L00435280: { // 0x435280: 8bf8 MOV EDI,EAX
    debug_va=0x00435280u;
    s.di = s.ax;
  }
  L00435282: { // 0x435282: 85ff TEST EDI,EDI
    debug_va=0x00435282u;
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00435284: { // 0x435284: 7515 JNZ 0x0043529b
    debug_va=0x00435284u;
    if(integer::condition("JNZ",flags)) goto L0043529b;
  }
  L00435286: { // 0x435286: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    debug_va=0x00435286u;
    s.cx = checked_r32(m,(f.sp+0x00000018u));
  }
  L0043528a: { // 0x43528a: 8b01 MOV EAX,dword ptr [ECX]
    debug_va=0x0043528au;
    s.ax = checked_r32(m,(s.cx));
  }
  L0043528c: { // 0x43528c: ff5060 CALL dword ptr [EAX + 0x60]
    debug_va=0x0043528cu;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x00000060u)),4412047u); flags=s.arithmetic_flags;
  }
  L0043528f: { // 0x43528f: 32c0 XOR AL,AL
    debug_va=0x0043528fu;
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00435291: { // 0x435291: 5f POP EDI
    debug_va=0x00435291u;
    const auto value=f.pop(m); s.di = value;
  }
  L00435292: { // 0x435292: 5e POP ESI
    debug_va=0x00435292u;
    const auto value=f.pop(m); s.si = value;
  }
  L00435293: { // 0x435293: 5d POP EBP
    debug_va=0x00435293u;
    const auto value=f.pop(m); s.bp = value;
  }
  L00435294: { // 0x435294: 5b POP EBX
    debug_va=0x00435294u;
    const auto value=f.pop(m); s.bx = value;
  }
  L00435295: { // 0x435295: 83c468 ADD ESP,0x68
    debug_va=0x00435295u;
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L00435298: { // 0x435298: c23000 RET 0x30
    debug_va=0x00435298u;
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L0043529b: { // 0x43529b: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    debug_va=0x0043529bu;
    s.ax = checked_r32(m,(f.sp+0x00000084u));
  }
  L004352a2: { // 0x4352a2: 85c0 TEST EAX,EAX
    debug_va=0x004352a2u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004352a4: { // 0x4352a4: 7e0a JLE 0x004352b0
    debug_va=0x004352a4u;
    if(integer::condition("JLE",flags)) goto L004352b0;
  }
  L004352a6: { // 0x4352a6: 33c9 XOR ECX,ECX
    debug_va=0x004352a6u;
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004352a8: { // 0x4352a8: 668b0f MOV CX,word ptr [EDI]
    debug_va=0x004352a8u;
    s.cx = with_ax(s.cx, checked_r16(m,(s.di)));
  }
  L004352ab: { // 0x4352ab: 03f9 ADD EDI,ECX
    debug_va=0x004352abu;
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L004352ad: { // 0x4352ad: 48 DEC EAX
    debug_va=0x004352adu;
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004352ae: { // 0x4352ae: 75f6 JNZ 0x004352a6
    debug_va=0x004352aeu;
    if(integer::condition("JNZ",flags)) goto L004352a6;
  }
  L004352b0: { // 0x4352b0: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    debug_va=0x004352b0u;
    s.cx = checked_r32(m,(f.sp+0x00000018u));
  }
  L004352b4: { // 0x4352b4: 8b11 MOV EDX,dword ptr [ECX]
    debug_va=0x004352b4u;
    s.dx = checked_r32(m,(s.cx));
  }
  L004352b6: { // 0x4352b6: ff5274 CALL dword ptr [EDX + 0x74]
    debug_va=0x004352b6u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.dx+0x00000074u)),4412089u); flags=s.arithmetic_flags;
  }
  L004352b9: { // 0x4352b9: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    debug_va=0x004352b9u;
    s.cx = checked_r32(m,(f.sp+0x00000064u));
  }
  L004352bd: { // 0x4352bd: 89842490000000 MOV dword ptr [ESP + 0x90],EAX
    debug_va=0x004352bdu;
    m.w32((f.sp+0x00000090u), s.ax);
  }
  L004352c4: { // 0x4352c4: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    debug_va=0x004352c4u;
    s.ax = checked_r32(m,(f.sp+0x00000074u));
  }
  L004352c8: { // 0x4352c8: 3bc1 CMP EAX,ECX
    debug_va=0x004352c8u;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004352ca: { // 0x4352ca: 7c02 JL 0x004352ce
    debug_va=0x004352cau;
    if(integer::condition("JL",flags)) goto L004352ce;
  }
  L004352cc: { // 0x4352cc: 8bc1 MOV EAX,ECX
    debug_va=0x004352ccu;
    s.ax = s.cx;
  }
  L004352ce: { // 0x4352ce: 85c0 TEST EAX,EAX
    debug_va=0x004352ceu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004352d0: { // 0x4352d0: 0f8efe000000 JLE 0x004353d4
    debug_va=0x004352d0u;
    if(integer::condition("JLE",flags)) goto L004353d4;
  }
  L004352d6: { // 0x4352d6: 898424a0000000 MOV dword ptr [ESP + 0xa0],EAX
    debug_va=0x004352d6u;
    m.w32((f.sp+0x000000a0u), s.ax);
  }
  L004352dd: { // 0x4352dd: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x004352ddu;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L004352e1: { // 0x4352e1: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    debug_va=0x004352e1u;
    s.bp = checked_r32(m,(f.sp+0x0000001cu));
  }
  L004352e5: { // 0x4352e5: 52 PUSH EDX
    debug_va=0x004352e5u;
    f.push(m,s.dx);
  }
  L004352e6: { // 0x4352e6: 8b94249c000000 MOV EDX,dword ptr [ESP + 0x9c]
    debug_va=0x004352e6u;
    s.dx = checked_r32(m,(f.sp+0x0000009cu));
  }
  L004352ed: { // 0x4352ed: 6a00 PUSH 0x0
    debug_va=0x004352edu;
    f.push(m,0x00000000u);
  }
  L004352ef: { // 0x4352ef: 52 PUSH EDX
    debug_va=0x004352efu;
    f.push(m,s.dx);
  }
  L004352f0: { // 0x4352f0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    debug_va=0x004352f0u;
    s.dx = checked_r32(m,(f.sp+0x00000020u));
  }
  L004352f4: { // 0x4352f4: 8b8c2498000000 MOV ECX,dword ptr [ESP + 0x98]
    debug_va=0x004352f4u;
    s.cx = checked_r32(m,(f.sp+0x00000098u));
  }
  L004352fb: { // 0x4352fb: 52 PUSH EDX
    debug_va=0x004352fbu;
    f.push(m,s.dx);
  }
  L004352fc: { // 0x4352fc: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    debug_va=0x004352fcu;
    s.dx = checked_r32(m,(f.sp+0x00000034u));
  }
  L00435300: { // 0x435300: 55 PUSH EBP
    debug_va=0x00435300u;
    f.push(m,s.bp);
  }
  L00435301: { // 0x435301: 56 PUSH ESI
    debug_va=0x00435301u;
    f.push(m,s.si);
  }
  L00435302: { // 0x435302: 8b01 MOV EAX,dword ptr [ECX]
    debug_va=0x00435302u;
    s.ax = checked_r32(m,(s.cx));
  }
  L00435304: { // 0x435304: 52 PUSH EDX
    debug_va=0x00435304u;
    f.push(m,s.dx);
  }
  L00435305: { // 0x435305: 8b94248c000000 MOV EDX,dword ptr [ESP + 0x8c]
    debug_va=0x00435305u;
    s.dx = checked_r32(m,(f.sp+0x0000008cu));
  }
  L0043530c: { // 0x43530c: 52 PUSH EDX
    debug_va=0x0043530cu;
    f.push(m,s.dx);
  }
  L0043530d: { // 0x43530d: 8d5702 LEA EDX,[EDI + 0x2]
    debug_va=0x0043530du;
    s.dx = (s.di+0x00000002u);
  }
  L00435310: { // 0x435310: 52 PUSH EDX
    debug_va=0x00435310u;
    f.push(m,s.dx);
  }
  L00435311: { // 0x435311: 8b9424b8000000 MOV EDX,dword ptr [ESP + 0xb8]
    debug_va=0x00435311u;
    s.dx = checked_r32(m,(f.sp+0x000000b8u));
  }
  L00435318: { // 0x435318: 52 PUSH EDX
    debug_va=0x00435318u;
    f.push(m,s.dx);
  }
  L00435319: { // 0x435319: ff5004 CALL dword ptr [EAX + 0x4]
    debug_va=0x00435319u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x00000004u)),4412188u); flags=s.arithmetic_flags;
  }
  L0043531c: { // 0x43531c: 33c0 XOR EAX,EAX
    debug_va=0x0043531cu;
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043531e: { // 0x43531e: 668b07 MOV AX,word ptr [EDI]
    debug_va=0x0043531eu;
    s.ax = with_ax(s.ax, checked_r16(m,(s.di)));
  }
  L00435321: { // 0x435321: 8b8c2490000000 MOV ECX,dword ptr [ESP + 0x90]
    debug_va=0x00435321u;
    s.cx = checked_r32(m,(f.sp+0x00000090u));
  }
  L00435328: { // 0x435328: 8b942494000000 MOV EDX,dword ptr [ESP + 0x94]
    debug_va=0x00435328u;
    s.dx = checked_r32(m,(f.sp+0x00000094u));
  }
  L0043532f: { // 0x43532f: 03f8 ADD EDI,EAX
    debug_va=0x0043532fu;
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00435331: { // 0x435331: a1ac1f8200 MOV EAX,[0x00821fac]
    debug_va=0x00435331u;
    s.ax = checked_r32(m,(0x00821facu));
  }
  L00435336: { // 0x435336: 03d1 ADD EDX,ECX
    debug_va=0x00435336u;
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00435338: { // 0x435338: 85c0 TEST EAX,EAX
    debug_va=0x00435338u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043533a: { // 0x43533a: 89942494000000 MOV dword ptr [ESP + 0x94],EDX
    debug_va=0x0043533au;
    m.w32((f.sp+0x00000094u), s.dx);
  }
  L00435341: { // 0x435341: 7475 JZ 0x004353b8
    debug_va=0x00435341u;
    if(integer::condition("JZ",flags)) goto L004353b8;
  }
  L00435343: { // 0x435343: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    debug_va=0x00435343u;
    s.dx = checked_r32(m,(f.sp+0x00000028u));
  }
  L00435347: { // 0x435347: 8d4c5500 LEA ECX,[EBP + EDX*0x2]
    debug_va=0x00435347u;
    s.cx = (s.bp+(s.dx * 0x00000002u));
  }
  L0043534b: { // 0x43534b: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    debug_va=0x0043534bu;
    s.dx = checked_r32(m,(s.ax+0x0000001cu));
  }
  L0043534e: { // 0x43534e: 3bca CMP ECX,EDX
    debug_va=0x0043534eu;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00435350: { // 0x435350: 7203 JC 0x00435355
    debug_va=0x00435350u;
    if(integer::condition("JC",flags)) goto L00435355;
  }
  L00435352: { // 0x435352: 2b4820 SUB ECX,dword ptr [EAX + 0x20]
    debug_va=0x00435352u;
    s.cx = integer::sub(s.cx,checked_r32(m,(s.ax+0x00000020u)),32,flags);
  }
  L00435355: { // 0x435355: 85db TEST EBX,EBX
    debug_va=0x00435355u;
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00435357: { // 0x435357: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    debug_va=0x00435357u;
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0043535b: { // 0x43535b: 7410 JZ 0x0043536d
    debug_va=0x0043535bu;
    if(integer::condition("JZ",flags)) goto L0043536d;
  }
  L0043535d: { // 0x43535d: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    debug_va=0x0043535du;
    s.ax = checked_r32(m,(f.sp+0x0000002cu));
  }
  L00435361: { // 0x435361: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    debug_va=0x00435361u;
    s.cx = checked_r32(m,(f.sp+0x00000010u));
  }
  L00435365: { // 0x435365: 03c8 ADD ECX,EAX
    debug_va=0x00435365u;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00435367: { // 0x435367: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    debug_va=0x00435367u;
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0043536b: { // 0x43536b: eb2e JMP 0x0043539b
    debug_va=0x0043536bu;
    goto L0043539b;
  }
  L0043536d: { // 0x43536d: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    debug_va=0x0043536du;
    s.ax = checked_r32(m,(f.sp+0x00000088u));
  }
  L00435374: { // 0x435374: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    debug_va=0x00435374u;
    s.bp = checked_r32(m,(f.sp+0x00000030u));
  }
  L00435378: { // 0x435378: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    debug_va=0x00435378u;
    s.cx = checked_r32(m,(f.sp+0x00000020u));
  }
  L0043537c: { // 0x43537c: 03c5 ADD EAX,EBP
    debug_va=0x0043537cu;
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0043537e: { // 0x43537e: 3bc1 CMP EAX,ECX
    debug_va=0x0043537eu;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00435380: { // 0x435380: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    debug_va=0x00435380u;
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L00435387: { // 0x435387: 7c12 JL 0x0043539b
    debug_va=0x00435387u;
    if(integer::condition("JL",flags)) goto L0043539b;
  }
  L00435389: { // 0x435389: 8b54247c MOV EDX,dword ptr [ESP + 0x7c]
    debug_va=0x00435389u;
    s.dx = checked_r32(m,(f.sp+0x0000007cu));
  }
  L0043538d: { // 0x43538d: 8b6a10 MOV EBP,dword ptr [EDX + 0x10]
    debug_va=0x0043538du;
    s.bp = checked_r32(m,(s.dx+0x00000010u));
  }
  L00435390: { // 0x435390: 03f5 ADD ESI,EBP
    debug_va=0x00435390u;
    s.si = integer::add(s.si,s.bp,32,flags);
  }
  L00435392: { // 0x435392: 2bc1 SUB EAX,ECX
    debug_va=0x00435392u;
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00435394: { // 0x435394: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    debug_va=0x00435394u;
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L0043539b: { // 0x43539b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    debug_va=0x0043539bu;
    s.ax = checked_r32(m,(f.sp+0x00000014u));
  }
  L0043539f: { // 0x43539f: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    debug_va=0x0043539fu;
    s.cx = checked_r32(m,(f.sp+0x00000034u));
  }
  L004353a3: { // 0x4353a3: 8d0448 LEA EAX,[EAX + ECX*0x2]
    debug_va=0x004353a3u;
    s.ax = (s.ax+(s.cx * 0x00000002u));
  }
  L004353a6: { // 0x4353a6: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    debug_va=0x004353a6u;
    s.cx = checked_r32(m,(0x008198f4u));
  }
  L004353ac: { // 0x4353ac: 3b411c CMP EAX,dword ptr [ECX + 0x1c]
    debug_va=0x004353acu;
    (void)integer::sub(s.ax,checked_r32(m,(s.cx+0x0000001cu)),32,flags);
  }
  L004353af: { // 0x4353af: 7203 JC 0x004353b4
    debug_va=0x004353afu;
    if(integer::condition("JC",flags)) goto L004353b4;
  }
  L004353b1: { // 0x4353b1: 2b4120 SUB EAX,dword ptr [ECX + 0x20]
    debug_va=0x004353b1u;
    s.ax = integer::sub(s.ax,checked_r32(m,(s.cx+0x00000020u)),32,flags);
  }
  L004353b4: { // 0x4353b4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    debug_va=0x004353b4u;
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004353b8: { // 0x4353b8: 8b8424a0000000 MOV EAX,dword ptr [ESP + 0xa0]
    debug_va=0x004353b8u;
    s.ax = checked_r32(m,(f.sp+0x000000a0u));
  }
  L004353bf: { // 0x4353bf: 48 DEC EAX
    debug_va=0x004353bfu;
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004353c0: { // 0x4353c0: 898424a0000000 MOV dword ptr [ESP + 0xa0],EAX
    debug_va=0x004353c0u;
    m.w32((f.sp+0x000000a0u), s.ax);
  }
  L004353c7: { // 0x4353c7: 0f8510ffffff JNZ 0x004352dd
    debug_va=0x004353c7u;
    if(integer::condition("JNZ",flags)) goto L004352dd;
  }
  L004353cd: { // 0x4353cd: 8bac2480000000 MOV EBP,dword ptr [ESP + 0x80]
    debug_va=0x004353cdu;
    s.bp = checked_r32(m,(f.sp+0x00000080u));
  }
  L004353d4: { // 0x4353d4: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    debug_va=0x004353d4u;
    s.cx = checked_r32(m,(f.sp+0x00000018u));
  }
  L004353d8: { // 0x4353d8: 8b11 MOV EDX,dword ptr [ECX]
    debug_va=0x004353d8u;
    s.dx = checked_r32(m,(s.cx));
  }
  L004353da: { // 0x4353da: ff5260 CALL dword ptr [EDX + 0x60]
    debug_va=0x004353dau;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.dx+0x00000060u)),4412381u); flags=s.arithmetic_flags;
  }
  L004353dd: { // 0x4353dd: 8b4500 MOV EAX,dword ptr [EBP]
    debug_va=0x004353ddu;
    s.ax = checked_r32(m,(s.bp));
  }
  L004353e0: { // 0x4353e0: 8bcd MOV ECX,EBP
    debug_va=0x004353e0u;
    s.cx = s.bp;
  }
  L004353e2: { // 0x4353e2: ff5060 CALL dword ptr [EAX + 0x60]
    debug_va=0x004353e2u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x00000060u)),4412389u); flags=s.arithmetic_flags;
  }
  L004353e5: { // 0x4353e5: b001 MOV AL,0x1
    debug_va=0x004353e5u;
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004353e7: { // 0x4353e7: 5f POP EDI
    debug_va=0x004353e7u;
    const auto value=f.pop(m); s.di = value;
  }
  L004353e8: { // 0x4353e8: 5e POP ESI
    debug_va=0x004353e8u;
    const auto value=f.pop(m); s.si = value;
  }
  L004353e9: { // 0x4353e9: 5d POP EBP
    debug_va=0x004353e9u;
    const auto value=f.pop(m); s.bp = value;
  }
  L004353ea: { // 0x4353ea: 5b POP EBX
    debug_va=0x004353eau;
    const auto value=f.pop(m); s.bx = value;
  }
  L004353eb: { // 0x4353eb: 83c468 ADD ESP,0x68
    debug_va=0x004353ebu;
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L004353ee: { // 0x4353ee: c23000 RET 0x30
    debug_va=0x004353eeu;
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
}
void f_00360ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760ad0: { // 0x760ad0: 83ec10 SUB ESP,0x10
    debug_va=0x00760ad0u;
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00760ad3: { // 0x760ad3: 53 PUSH EBX
    debug_va=0x00760ad3u;
    f.push(m,s.bx);
  }
  L00760ad4: { // 0x760ad4: 56 PUSH ESI
    debug_va=0x00760ad4u;
    f.push(m,s.si);
  }
  L00760ad5: { // 0x760ad5: 57 PUSH EDI
    debug_va=0x00760ad5u;
    f.push(m,s.di);
  }
  L00760ad6: { // 0x760ad6: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    debug_va=0x00760ad6u;
    s.di = checked_r32(m,(f.sp+0x00000020u));
  }
  L00760ada: { // 0x760ada: 8bf1 MOV ESI,ECX
    debug_va=0x00760adau;
    s.si = s.cx;
  }
  L00760adc: { // 0x760adc: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    debug_va=0x00760adcu;
    s.cx = checked_r32(m,(s.di+0x00000008u));
  }
  L00760adf: { // 0x760adf: 394e08 CMP dword ptr [ESI + 0x8],ECX
    debug_va=0x00760adfu;
    (void)integer::sub(checked_r32(m,(s.si+0x00000008u)),s.cx,32,flags);
  }
  L00760ae2: { // 0x760ae2: 0f852e010000 JNZ 0x00760c16
    debug_va=0x00760ae2u;
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760ae8: { // 0x760ae8: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    debug_va=0x00760ae8u;
    s.ax = checked_r32(m,(s.si+0x0000000cu));
  }
  L00760aeb: { // 0x760aeb: 8b5f0c MOV EBX,dword ptr [EDI + 0xc]
    debug_va=0x00760aebu;
    s.bx = checked_r32(m,(s.di+0x0000000cu));
  }
  L00760aee: { // 0x760aee: 3bc3 CMP EAX,EBX
    debug_va=0x00760aeeu;
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760af0: { // 0x760af0: 0f8520010000 JNZ 0x00760c16
    debug_va=0x00760af0u;
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760af6: { // 0x760af6: 8b06 MOV EAX,dword ptr [ESI]
    debug_va=0x00760af6u;
    s.ax = checked_r32(m,(s.si));
  }
  L00760af8: { // 0x760af8: 85c0 TEST EAX,EAX
    debug_va=0x00760af8u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760afa: { // 0x760afa: 7d1d JGE 0x00760b19
    debug_va=0x00760afau;
    if(integer::condition("JGE",flags)) goto L00760b19;
  }
  L00760afc: { // 0x760afc: 8b1f MOV EBX,dword ptr [EDI]
    debug_va=0x00760afcu;
    s.bx = checked_r32(m,(s.di));
  }
  L00760afe: { // 0x760afe: 2bd8 SUB EBX,EAX
    debug_va=0x00760afeu;
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b00: { // 0x760b00: 891f MOV dword ptr [EDI],EBX
    debug_va=0x00760b00u;
    m.w32((s.di), s.bx);
  }
  L00760b02: { // 0x760b02: 8b06 MOV EAX,dword ptr [ESI]
    debug_va=0x00760b02u;
    s.ax = checked_r32(m,(s.si));
  }
  L00760b04: { // 0x760b04: 03c1 ADD EAX,ECX
    debug_va=0x00760b04u;
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b06: { // 0x760b06: 894708 MOV dword ptr [EDI + 0x8],EAX
    debug_va=0x00760b06u;
    m.w32((s.di+0x00000008u), s.ax);
  }
  L00760b09: { // 0x760b09: 8b0e MOV ECX,dword ptr [ESI]
    debug_va=0x00760b09u;
    s.cx = checked_r32(m,(s.si));
  }
  L00760b0b: { // 0x760b0b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    debug_va=0x00760b0bu;
    s.ax = checked_r32(m,(s.si+0x00000008u));
  }
  L00760b0e: { // 0x760b0e: c70600000000 MOV dword ptr [ESI],0x0
    debug_va=0x00760b0eu;
    m.w32((s.si), 0x00000000u);
  }
  L00760b14: { // 0x760b14: 03c1 ADD EAX,ECX
    debug_va=0x00760b14u;
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b16: { // 0x760b16: 894608 MOV dword ptr [ESI + 0x8],EAX
    debug_va=0x00760b16u;
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00760b19: { // 0x760b19: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    debug_va=0x00760b19u;
    s.ax = checked_r32(m,(s.si+0x00000004u));
  }
  L00760b1c: { // 0x760b1c: 85c0 TEST EAX,EAX
    debug_va=0x00760b1cu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b1e: { // 0x760b1e: 7d25 JGE 0x00760b45
    debug_va=0x00760b1eu;
    if(integer::condition("JGE",flags)) goto L00760b45;
  }
  L00760b20: { // 0x760b20: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    debug_va=0x00760b20u;
    s.bx = checked_r32(m,(s.di+0x00000004u));
  }
  L00760b23: { // 0x760b23: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    debug_va=0x00760b23u;
    s.cx = checked_r32(m,(s.di+0x0000000cu));
  }
  L00760b26: { // 0x760b26: 2bd8 SUB EBX,EAX
    debug_va=0x00760b26u;
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b28: { // 0x760b28: 895f04 MOV dword ptr [EDI + 0x4],EBX
    debug_va=0x00760b28u;
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00760b2b: { // 0x760b2b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    debug_va=0x00760b2bu;
    s.ax = checked_r32(m,(s.si+0x00000004u));
  }
  L00760b2e: { // 0x760b2e: 03c8 ADD ECX,EAX
    debug_va=0x00760b2eu;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760b30: { // 0x760b30: 894f0c MOV dword ptr [EDI + 0xc],ECX
    debug_va=0x00760b30u;
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760b33: { // 0x760b33: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    debug_va=0x00760b33u;
    s.cx = checked_r32(m,(s.si+0x00000004u));
  }
  L00760b36: { // 0x760b36: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    debug_va=0x00760b36u;
    s.ax = checked_r32(m,(s.si+0x0000000cu));
  }
  L00760b39: { // 0x760b39: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    debug_va=0x00760b39u;
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00760b40: { // 0x760b40: 03c1 ADD EAX,ECX
    debug_va=0x00760b40u;
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b42: { // 0x760b42: 89460c MOV dword ptr [ESI + 0xc],EAX
    debug_va=0x00760b42u;
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00760b45: { // 0x760b45: 8b06 MOV EAX,dword ptr [ESI]
    debug_va=0x00760b45u;
    s.ax = checked_r32(m,(s.si));
  }
  L00760b47: { // 0x760b47: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    debug_va=0x00760b47u;
    s.cx = checked_r32(m,(s.dx+0x00000008u));
  }
  L00760b4a: { // 0x760b4a: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    debug_va=0x00760b4au;
    s.bx = checked_r32(m,(s.si+0x00000008u));
  }
  L00760b4d: { // 0x760b4d: 2bc1 SUB EAX,ECX
    debug_va=0x00760b4du;
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00760b4f: { // 0x760b4f: 03c3 ADD EAX,EBX
    debug_va=0x00760b4fu;
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760b51: { // 0x760b51: 85c0 TEST EAX,EAX
    debug_va=0x00760b51u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b53: { // 0x760b53: 7e10 JLE 0x00760b65
    debug_va=0x00760b53u;
    if(integer::condition("JLE",flags)) goto L00760b65;
  }
  L00760b55: { // 0x760b55: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    debug_va=0x00760b55u;
    s.bx = checked_r32(m,(s.di+0x00000008u));
  }
  L00760b58: { // 0x760b58: 2bd8 SUB EBX,EAX
    debug_va=0x00760b58u;
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b5a: { // 0x760b5a: 895f08 MOV dword ptr [EDI + 0x8],EBX
    debug_va=0x00760b5au;
    m.w32((s.di+0x00000008u), s.bx);
  }
  L00760b5d: { // 0x760b5d: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    debug_va=0x00760b5du;
    s.cx = checked_r32(m,(s.si+0x00000008u));
  }
  L00760b60: { // 0x760b60: 2bc8 SUB ECX,EAX
    debug_va=0x00760b60u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b62: { // 0x760b62: 894e08 MOV dword ptr [ESI + 0x8],ECX
    debug_va=0x00760b62u;
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760b65: { // 0x760b65: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    debug_va=0x00760b65u;
    s.ax = checked_r32(m,(s.si+0x0000000cu));
  }
  L00760b68: { // 0x760b68: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    debug_va=0x00760b68u;
    s.bx = checked_r32(m,(s.dx+0x0000000cu));
  }
  L00760b6b: { // 0x760b6b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    debug_va=0x00760b6bu;
    s.dx = checked_r32(m,(s.si+0x00000004u));
  }
  L00760b6e: { // 0x760b6e: 2bc3 SUB EAX,EBX
    debug_va=0x00760b6eu;
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760b70: { // 0x760b70: 03c2 ADD EAX,EDX
    debug_va=0x00760b70u;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00760b72: { // 0x760b72: 85c0 TEST EAX,EAX
    debug_va=0x00760b72u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b74: { // 0x760b74: 7e10 JLE 0x00760b86
    debug_va=0x00760b74u;
    if(integer::condition("JLE",flags)) goto L00760b86;
  }
  L00760b76: { // 0x760b76: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    debug_va=0x00760b76u;
    s.dx = checked_r32(m,(s.di+0x0000000cu));
  }
  L00760b79: { // 0x760b79: 2bd0 SUB EDX,EAX
    debug_va=0x00760b79u;
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00760b7b: { // 0x760b7b: 89570c MOV dword ptr [EDI + 0xc],EDX
    debug_va=0x00760b7bu;
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760b7e: { // 0x760b7e: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    debug_va=0x00760b7eu;
    s.cx = checked_r32(m,(s.si+0x0000000cu));
  }
  L00760b81: { // 0x760b81: 2bc8 SUB ECX,EAX
    debug_va=0x00760b81u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b83: { // 0x760b83: 894e0c MOV dword ptr [ESI + 0xc],ECX
    debug_va=0x00760b83u;
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760b86: { // 0x760b86: 8b07 MOV EAX,dword ptr [EDI]
    debug_va=0x00760b86u;
    s.ax = checked_r32(m,(s.di));
  }
  L00760b88: { // 0x760b88: 85c0 TEST EAX,EAX
    debug_va=0x00760b88u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b8a: { // 0x760b8a: 7d1e JGE 0x00760baa
    debug_va=0x00760b8au;
    if(integer::condition("JGE",flags)) goto L00760baa;
  }
  L00760b8c: { // 0x760b8c: 8b1e MOV EBX,dword ptr [ESI]
    debug_va=0x00760b8cu;
    s.bx = checked_r32(m,(s.si));
  }
  L00760b8e: { // 0x760b8e: 2bd8 SUB EBX,EAX
    debug_va=0x00760b8eu;
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b90: { // 0x760b90: 891e MOV dword ptr [ESI],EBX
    debug_va=0x00760b90u;
    m.w32((s.si), s.bx);
  }
  L00760b92: { // 0x760b92: 8b07 MOV EAX,dword ptr [EDI]
    debug_va=0x00760b92u;
    s.ax = checked_r32(m,(s.di));
  }
  L00760b94: { // 0x760b94: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    debug_va=0x00760b94u;
    s.dx = checked_r32(m,(s.di+0x00000008u));
  }
  L00760b97: { // 0x760b97: 03d0 ADD EDX,EAX
    debug_va=0x00760b97u;
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760b99: { // 0x760b99: 895708 MOV dword ptr [EDI + 0x8],EDX
    debug_va=0x00760b99u;
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00760b9c: { // 0x760b9c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    debug_va=0x00760b9cu;
    s.cx = checked_r32(m,(s.si+0x00000008u));
  }
  L00760b9f: { // 0x760b9f: 03c8 ADD ECX,EAX
    debug_va=0x00760b9fu;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760ba1: { // 0x760ba1: 894e08 MOV dword ptr [ESI + 0x8],ECX
    debug_va=0x00760ba1u;
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760ba4: { // 0x760ba4: c70700000000 MOV dword ptr [EDI],0x0
    debug_va=0x00760ba4u;
    m.w32((s.di), 0x00000000u);
  }
  L00760baa: { // 0x760baa: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    debug_va=0x00760baau;
    s.ax = checked_r32(m,(s.di+0x00000004u));
  }
  L00760bad: { // 0x760bad: 85c0 TEST EAX,EAX
    debug_va=0x00760badu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760baf: { // 0x760baf: 7d22 JGE 0x00760bd3
    debug_va=0x00760bafu;
    if(integer::condition("JGE",flags)) goto L00760bd3;
  }
  L00760bb1: { // 0x760bb1: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    debug_va=0x00760bb1u;
    s.bx = checked_r32(m,(s.si+0x00000004u));
  }
  L00760bb4: { // 0x760bb4: 2bd8 SUB EBX,EAX
    debug_va=0x00760bb4u;
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760bb6: { // 0x760bb6: 895e04 MOV dword ptr [ESI + 0x4],EBX
    debug_va=0x00760bb6u;
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00760bb9: { // 0x760bb9: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    debug_va=0x00760bb9u;
    s.ax = checked_r32(m,(s.di+0x00000004u));
  }
  L00760bbc: { // 0x760bbc: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    debug_va=0x00760bbcu;
    s.dx = checked_r32(m,(s.di+0x0000000cu));
  }
  L00760bbf: { // 0x760bbf: 03d0 ADD EDX,EAX
    debug_va=0x00760bbfu;
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760bc1: { // 0x760bc1: 89570c MOV dword ptr [EDI + 0xc],EDX
    debug_va=0x00760bc1u;
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760bc4: { // 0x760bc4: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    debug_va=0x00760bc4u;
    s.cx = checked_r32(m,(s.si+0x0000000cu));
  }
  L00760bc7: { // 0x760bc7: 03c8 ADD ECX,EAX
    debug_va=0x00760bc7u;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760bc9: { // 0x760bc9: 894e0c MOV dword ptr [ESI + 0xc],ECX
    debug_va=0x00760bc9u;
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760bcc: { // 0x760bcc: c7470400000000 MOV dword ptr [EDI + 0x4],0x0
    debug_va=0x00760bccu;
    m.w32((s.di+0x00000004u), 0x00000000u);
  }
  L00760bd3: { // 0x760bd3: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    debug_va=0x00760bd3u;
    s.dx = checked_r32(m,(f.sp+0x00000024u));
  }
  L00760bd7: { // 0x760bd7: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    debug_va=0x00760bd7u;
    s.cx = checked_r32(m,(s.di+0x00000008u));
  }
  L00760bda: { // 0x760bda: 8bc1 MOV EAX,ECX
    debug_va=0x00760bdau;
    s.ax = s.cx;
  }
  L00760bdc: { // 0x760bdc: 8b5a08 MOV EBX,dword ptr [EDX + 0x8]
    debug_va=0x00760bdcu;
    s.bx = checked_r32(m,(s.dx+0x00000008u));
  }
  L00760bdf: { // 0x760bdf: 2bc3 SUB EAX,EBX
    debug_va=0x00760bdfu;
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760be1: { // 0x760be1: 8b1f MOV EBX,dword ptr [EDI]
    debug_va=0x00760be1u;
    s.bx = checked_r32(m,(s.di));
  }
  L00760be3: { // 0x760be3: 03c3 ADD EAX,EBX
    debug_va=0x00760be3u;
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760be5: { // 0x760be5: 85c0 TEST EAX,EAX
    debug_va=0x00760be5u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760be7: { // 0x760be7: 7e0d JLE 0x00760bf6
    debug_va=0x00760be7u;
    if(integer::condition("JLE",flags)) goto L00760bf6;
  }
  L00760be9: { // 0x760be9: 2bc8 SUB ECX,EAX
    debug_va=0x00760be9u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760beb: { // 0x760beb: 894f08 MOV dword ptr [EDI + 0x8],ECX
    debug_va=0x00760bebu;
    m.w32((s.di+0x00000008u), s.cx);
  }
  L00760bee: { // 0x760bee: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    debug_va=0x00760beeu;
    s.cx = checked_r32(m,(s.si+0x00000008u));
  }
  L00760bf1: { // 0x760bf1: 2bc8 SUB ECX,EAX
    debug_va=0x00760bf1u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760bf3: { // 0x760bf3: 894e08 MOV dword ptr [ESI + 0x8],ECX
    debug_va=0x00760bf3u;
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760bf6: { // 0x760bf6: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    debug_va=0x00760bf6u;
    s.ax = checked_r32(m,(s.di+0x00000004u));
  }
  L00760bf9: { // 0x760bf9: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    debug_va=0x00760bf9u;
    s.bx = checked_r32(m,(s.dx+0x0000000cu));
  }
  L00760bfc: { // 0x760bfc: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    debug_va=0x00760bfcu;
    s.cx = checked_r32(m,(s.di+0x0000000cu));
  }
  L00760bff: { // 0x760bff: 2bc3 SUB EAX,EBX
    debug_va=0x00760bffu;
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760c01: { // 0x760c01: 03c1 ADD EAX,ECX
    debug_va=0x00760c01u;
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760c03: { // 0x760c03: 85c0 TEST EAX,EAX
    debug_va=0x00760c03u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c05: { // 0x760c05: 7e63 JLE 0x00760c6a
    debug_va=0x00760c05u;
    if(integer::condition("JLE",flags)) goto L00760c6a;
  }
  L00760c07: { // 0x760c07: 2bc8 SUB ECX,EAX
    debug_va=0x00760c07u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c09: { // 0x760c09: 894f0c MOV dword ptr [EDI + 0xc],ECX
    debug_va=0x00760c09u;
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760c0c: { // 0x760c0c: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    debug_va=0x00760c0cu;
    s.cx = checked_r32(m,(s.si+0x0000000cu));
  }
  L00760c0f: { // 0x760c0f: 2bc8 SUB ECX,EAX
    debug_va=0x00760c0fu;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c11: { // 0x760c11: 894e0c MOV dword ptr [ESI + 0xc],ECX
    debug_va=0x00760c11u;
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760c14: { // 0x760c14: eb54 JMP 0x00760c6a
    debug_va=0x00760c14u;
    goto L00760c6a;
  }
  L00760c16: { // 0x760c16: 6a00 PUSH 0x0
    debug_va=0x00760c16u;
    f.push(m,0x00000000u);
  }
  L00760c18: { // 0x760c18: 6a00 PUSH 0x0
    debug_va=0x00760c18u;
    f.push(m,0x00000000u);
  }
  L00760c1a: { // 0x760c1a: 52 PUSH EDX
    debug_va=0x00760c1au;
    f.push(m,s.dx);
  }
  L00760c1b: { // 0x760c1b: 8bd6 MOV EDX,ESI
    debug_va=0x00760c1bu;
    s.dx = s.si;
  }
  L00760c1d: { // 0x760c1d: 8d4c2418 LEA ECX,[ESP + 0x18]
    debug_va=0x00760c1du;
    s.cx = (f.sp+0x00000018u);
  }
  L00760c21: { // 0x760c21: e8caf1cbff CALL 0x0041fdf0
    debug_va=0x00760c21u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736358u); flags=s.arithmetic_flags;
  }
  L00760c26: { // 0x760c26: 8b08 MOV ECX,dword ptr [EAX]
    debug_va=0x00760c26u;
    s.cx = checked_r32(m,(s.ax));
  }
  L00760c28: { // 0x760c28: 8bd6 MOV EDX,ESI
    debug_va=0x00760c28u;
    s.dx = s.si;
  }
  L00760c2a: { // 0x760c2a: 6a00 PUSH 0x0
    debug_va=0x00760c2au;
    f.push(m,0x00000000u);
  }
  L00760c2c: { // 0x760c2c: 6a00 PUSH 0x0
    debug_va=0x00760c2cu;
    f.push(m,0x00000000u);
  }
  L00760c2e: { // 0x760c2e: 890a MOV dword ptr [EDX],ECX
    debug_va=0x00760c2eu;
    m.w32((s.dx), s.cx);
  }
  L00760c30: { // 0x760c30: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    debug_va=0x00760c30u;
    s.cx = checked_r32(m,(s.ax+0x00000004u));
  }
  L00760c33: { // 0x760c33: 894a04 MOV dword ptr [EDX + 0x4],ECX
    debug_va=0x00760c33u;
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c36: { // 0x760c36: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    debug_va=0x00760c36u;
    s.cx = checked_r32(m,(s.ax+0x00000008u));
  }
  L00760c39: { // 0x760c39: 894a08 MOV dword ptr [EDX + 0x8],ECX
    debug_va=0x00760c39u;
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c3c: { // 0x760c3c: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    debug_va=0x00760c3cu;
    s.ax = checked_r32(m,(s.ax+0x0000000cu));
  }
  L00760c3f: { // 0x760c3f: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    debug_va=0x00760c3fu;
    s.cx = checked_r32(m,(f.sp+0x0000002cu));
  }
  L00760c43: { // 0x760c43: 89420c MOV dword ptr [EDX + 0xc],EAX
    debug_va=0x00760c43u;
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c46: { // 0x760c46: 51 PUSH ECX
    debug_va=0x00760c46u;
    f.push(m,s.cx);
  }
  L00760c47: { // 0x760c47: 8bd7 MOV EDX,EDI
    debug_va=0x00760c47u;
    s.dx = s.di;
  }
  L00760c49: { // 0x760c49: 8d4c2418 LEA ECX,[ESP + 0x18]
    debug_va=0x00760c49u;
    s.cx = (f.sp+0x00000018u);
  }
  L00760c4d: { // 0x760c4d: e89ef1cbff CALL 0x0041fdf0
    debug_va=0x00760c4du;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736402u); flags=s.arithmetic_flags;
  }
  L00760c52: { // 0x760c52: 8b08 MOV ECX,dword ptr [EAX]
    debug_va=0x00760c52u;
    s.cx = checked_r32(m,(s.ax));
  }
  L00760c54: { // 0x760c54: 8bd7 MOV EDX,EDI
    debug_va=0x00760c54u;
    s.dx = s.di;
  }
  L00760c56: { // 0x760c56: 890a MOV dword ptr [EDX],ECX
    debug_va=0x00760c56u;
    m.w32((s.dx), s.cx);
  }
  L00760c58: { // 0x760c58: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    debug_va=0x00760c58u;
    s.cx = checked_r32(m,(s.ax+0x00000004u));
  }
  L00760c5b: { // 0x760c5b: 894a04 MOV dword ptr [EDX + 0x4],ECX
    debug_va=0x00760c5bu;
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c5e: { // 0x760c5e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    debug_va=0x00760c5eu;
    s.cx = checked_r32(m,(s.ax+0x00000008u));
  }
  L00760c61: { // 0x760c61: 894a08 MOV dword ptr [EDX + 0x8],ECX
    debug_va=0x00760c61u;
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c64: { // 0x760c64: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    debug_va=0x00760c64u;
    s.ax = checked_r32(m,(s.ax+0x0000000cu));
  }
  L00760c67: { // 0x760c67: 89420c MOV dword ptr [EDX + 0xc],EAX
    debug_va=0x00760c67u;
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c6a: { // 0x760c6a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    debug_va=0x00760c6au;
    s.ax = checked_r32(m,(s.si+0x00000008u));
  }
  L00760c6d: { // 0x760c6d: 85c0 TEST EAX,EAX
    debug_va=0x00760c6du;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c6f: { // 0x760c6f: 7e23 JLE 0x00760c94
    debug_va=0x00760c6fu;
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c71: { // 0x760c71: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    debug_va=0x00760c71u;
    s.ax = checked_r32(m,(s.si+0x0000000cu));
  }
  L00760c74: { // 0x760c74: 85c0 TEST EAX,EAX
    debug_va=0x00760c74u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c76: { // 0x760c76: 7e1c JLE 0x00760c94
    debug_va=0x00760c76u;
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c78: { // 0x760c78: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    debug_va=0x00760c78u;
    s.ax = checked_r32(m,(s.di+0x00000008u));
  }
  L00760c7b: { // 0x760c7b: 85c0 TEST EAX,EAX
    debug_va=0x00760c7bu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c7d: { // 0x760c7d: 7e15 JLE 0x00760c94
    debug_va=0x00760c7du;
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c7f: { // 0x760c7f: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    debug_va=0x00760c7fu;
    s.ax = checked_r32(m,(s.di+0x0000000cu));
  }
  L00760c82: { // 0x760c82: 85c0 TEST EAX,EAX
    debug_va=0x00760c82u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c84: { // 0x760c84: 7e0e JLE 0x00760c94
    debug_va=0x00760c84u;
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c86: { // 0x760c86: 5f POP EDI
    debug_va=0x00760c86u;
    const auto value=f.pop(m); s.di = value;
  }
  L00760c87: { // 0x760c87: 5e POP ESI
    debug_va=0x00760c87u;
    const auto value=f.pop(m); s.si = value;
  }
  L00760c88: { // 0x760c88: b801000000 MOV EAX,0x1
    debug_va=0x00760c88u;
    s.ax = 0x00000001u;
  }
  L00760c8d: { // 0x760c8d: 5b POP EBX
    debug_va=0x00760c8du;
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c8e: { // 0x760c8e: 83c410 ADD ESP,0x10
    debug_va=0x00760c8eu;
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c91: { // 0x760c91: c20800 RET 0x8
    debug_va=0x00760c91u;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00760c94: { // 0x760c94: 5f POP EDI
    debug_va=0x00760c94u;
    const auto value=f.pop(m); s.di = value;
  }
  L00760c95: { // 0x760c95: 5e POP ESI
    debug_va=0x00760c95u;
    const auto value=f.pop(m); s.si = value;
  }
  L00760c96: { // 0x760c96: 33c0 XOR EAX,EAX
    debug_va=0x00760c96u;
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00760c98: { // 0x760c98: 5b POP EBX
    debug_va=0x00760c98u;
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c99: { // 0x760c99: 83c410 ADD ESP,0x10
    debug_va=0x00760c99u;
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c9c: { // 0x760c9c: c20800 RET 0x8
    debug_va=0x00760c9cu;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00035420(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435420: { // 0x435420: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    debug_va=0x00435420u;
    s.ax = checked_r32(m,(f.sp+0x00000004u));
  }
  L00435424: { // 0x435424: 8b11 MOV EDX,dword ptr [ECX]
    debug_va=0x00435424u;
    s.dx = checked_r32(m,(s.cx));
  }
  L00435426: { // 0x435426: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    debug_va=0x00435426u;
    s.cx = checked_r32(m,(s.cx+0x00000004u));
  }
  L00435429: { // 0x435429: 8910 MOV dword ptr [EAX],EDX
    debug_va=0x00435429u;
    m.w32((s.ax), s.dx);
  }
  L0043542b: { // 0x43542b: 894804 MOV dword ptr [EAX + 0x4],ECX
    debug_va=0x0043542bu;
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0043542e: { // 0x43542e: c20400 RET 0x4
    debug_va=0x0043542eu;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00035400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435400: { // 0x435400: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    debug_va=0x00435400u;
    s.ax = checked_r32(m,(f.sp+0x00000008u));
  }
  L00435404: { // 0x435404: 56 PUSH ESI
    debug_va=0x00435404u;
    f.push(m,s.si);
  }
  L00435405: { // 0x435405: 8b31 MOV ESI,dword ptr [ECX]
    debug_va=0x00435405u;
    s.si = checked_r32(m,(s.cx));
  }
  L00435407: { // 0x435407: 8b10 MOV EDX,dword ptr [EAX]
    debug_va=0x00435407u;
    s.dx = checked_r32(m,(s.ax));
  }
  L00435409: { // 0x435409: 03d6 ADD EDX,ESI
    debug_va=0x00435409u;
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0043540b: { // 0x43540b: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    debug_va=0x0043540bu;
    s.si = checked_r32(m,(s.ax+0x00000004u));
  }
  L0043540e: { // 0x43540e: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    debug_va=0x0043540eu;
    s.ax = checked_r32(m,(s.cx+0x00000004u));
  }
  L00435411: { // 0x435411: 03f0 ADD ESI,EAX
    debug_va=0x00435411u;
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00435413: { // 0x435413: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    debug_va=0x00435413u;
    s.ax = checked_r32(m,(f.sp+0x00000008u));
  }
  L00435417: { // 0x435417: 8910 MOV dword ptr [EAX],EDX
    debug_va=0x00435417u;
    m.w32((s.ax), s.dx);
  }
  L00435419: { // 0x435419: 897004 MOV dword ptr [EAX + 0x4],ESI
    debug_va=0x00435419u;
    m.w32((s.ax+0x00000004u), s.si);
  }
  L0043541c: { // 0x43541c: 5e POP ESI
    debug_va=0x0043541cu;
    const auto value=f.pop(m); s.si = value;
  }
  L0043541d: { // 0x43541d: c20800 RET 0x8
    debug_va=0x0043541du;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00011370(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411370: { // 0x411370: 53 PUSH EBX
    debug_va=0x00411370u;
    f.push(m,s.bx);
  }
  L00411371: { // 0x411371: 56 PUSH ESI
    debug_va=0x00411371u;
    f.push(m,s.si);
  }
  L00411372: { // 0x411372: 8bf1 MOV ESI,ECX
    debug_va=0x00411372u;
    s.si = s.cx;
  }
  L00411374: { // 0x411374: 57 PUSH EDI
    debug_va=0x00411374u;
    f.push(m,s.di);
  }
  L00411375: { // 0x411375: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    debug_va=0x00411375u;
    s.di = checked_r32(m,(s.si+0x0000000cu));
  }
  L00411378: { // 0x411378: 8b06 MOV EAX,dword ptr [ESI]
    debug_va=0x00411378u;
    s.ax = checked_r32(m,(s.si));
  }
  L0041137a: { // 0x41137a: 47 INC EDI
    debug_va=0x0041137au;
    s.di = integer::increment(s.di,32,flags);
  }
  L0041137b: { // 0x41137b: 897e0c MOV dword ptr [ESI + 0xc],EDI
    debug_va=0x0041137bu;
    m.w32((s.si+0x0000000cu), s.di);
  }
  L0041137e: { // 0x41137e: 8b7e14 MOV EDI,dword ptr [ESI + 0x14]
    debug_va=0x0041137eu;
    s.di = checked_r32(m,(s.si+0x00000014u));
  }
  L00411381: { // 0x411381: ff5070 CALL dword ptr [EAX + 0x70]
    debug_va=0x00411381u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x00000070u)),4264836u); flags=s.arithmetic_flags;
  }
  L00411384: { // 0x411384: 8b16 MOV EDX,dword ptr [ESI]
    debug_va=0x00411384u;
    s.dx = checked_r32(m,(s.si));
  }
  L00411386: { // 0x411386: 8bd8 MOV EBX,EAX
    debug_va=0x00411386u;
    s.bx = s.ax;
  }
  L00411388: { // 0x411388: 0faf5c2410 IMUL EBX,dword ptr [ESP + 0x10]
    debug_va=0x00411388u;
    s.bx = integer::imul(s.bx,checked_r32(m,(f.sp+0x00000010u)),32,flags);
  }
  L0041138d: { // 0x41138d: 8bce MOV ECX,ESI
    debug_va=0x0041138du;
    s.cx = s.si;
  }
  L0041138f: { // 0x41138f: ff5274 CALL dword ptr [EDX + 0x74]
    debug_va=0x0041138fu;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.dx+0x00000074u)),4264850u); flags=s.arithmetic_flags;
  }
  L00411392: { // 0x411392: 0faf442414 IMUL EAX,dword ptr [ESP + 0x14]
    debug_va=0x00411392u;
    s.ax = integer::imul(s.ax,checked_r32(m,(f.sp+0x00000014u)),32,flags);
  }
  L00411397: { // 0x411397: 03fb ADD EDI,EBX
    debug_va=0x00411397u;
    s.di = integer::add(s.di,s.bx,32,flags);
  }
  L00411399: { // 0x411399: 03c7 ADD EAX,EDI
    debug_va=0x00411399u;
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0041139b: { // 0x41139b: 5f POP EDI
    debug_va=0x0041139bu;
    const auto value=f.pop(m); s.di = value;
  }
  L0041139c: { // 0x41139c: 5e POP ESI
    debug_va=0x0041139cu;
    const auto value=f.pop(m); s.si = value;
  }
  L0041139d: { // 0x41139d: 5b POP EBX
    debug_va=0x0041139du;
    const auto value=f.pop(m); s.bx = value;
  }
  L0041139e: { // 0x41139e: c20800 RET 0x8
    debug_va=0x0041139eu;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_000112f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112f0: { // 0x4112f0: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    debug_va=0x004112f0u;
    s.ax = checked_r32(m,(s.cx+0x0000000cu));
  }
  L004112f3: { // 0x4112f3: 48 DEC EAX
    debug_va=0x004112f3u;
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004112f4: { // 0x4112f4: 89410c MOV dword ptr [ECX + 0xc],EAX
    debug_va=0x004112f4u;
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L004112f7: { // 0x4112f7: b001 MOV AL,0x1
    debug_va=0x004112f7u;
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004112f9: { // 0x4112f9: c3 RET
    debug_va=0x004112f9u;
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113b0: { // 0x4113b0: 8b4110 MOV EAX,dword ptr [ECX + 0x10]
    debug_va=0x004113b0u;
    s.ax = checked_r32(m,(s.cx+0x00000010u));
  }
  L004113b3: { // 0x4113b3: c3 RET
    debug_va=0x004113b3u;
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000113c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004113c0: { // 0x004113c0: 56 PUSH ESI
    debug_va=0x004113c0u;
    f.push(m,s.si);
  }
  L004113c1: { // 0x004113c1: 8bf1 MOV ESI,ECX
    debug_va=0x004113c1u;
    s.si = s.cx;
  }
  L004113c3: { // 0x004113c3: 8b06 MOV EAX,dword ptr [ESI]
    debug_va=0x004113c3u;
    s.ax = checked_r32(m,(s.si));
  }
  L004113c5: { // 0x004113c5: ff507c CALL dword ptr [EAX + 0x7c]
    debug_va=0x004113c5u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x0000007cu)),4264904u); flags=s.arithmetic_flags;
  }
  L004113c8: { // 0x004113c8: 0faf4610 IMUL EAX,dword ptr [ESI + 0x10]
    debug_va=0x004113c8u;
    s.ax = integer::imul(s.ax,checked_r32(m,(s.si+0x00000010u)),32,flags);
  }
  L004113cc: { // 0x004113cc: 5e POP ESI
    debug_va=0x004113ccu;
    const auto value=f.pop(m); s.si = value;
  }
  L004113cd: { // 0x004113cd: c3 RET
    debug_va=0x004113cdu;
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    debug_va=0x004112c0u;
    s.ax = checked_r32(m,(s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    debug_va=0x004112c3u;
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00011290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411290: { // 0x411290: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    debug_va=0x00411290u;
    s.ax = checked_r32(m,(f.sp+0x00000004u));
  }
  L00411294: { // 0x411294: 53 PUSH EBX
    debug_va=0x00411294u;
    f.push(m,s.bx);
  }
  L00411295: { // 0x411295: 56 PUSH ESI
    debug_va=0x00411295u;
    f.push(m,s.si);
  }
  L00411296: { // 0x411296: 57 PUSH EDI
    debug_va=0x00411296u;
    f.push(m,s.di);
  }
  L00411297: { // 0x411297: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    debug_va=0x00411297u;
    s.di = checked_r32(m,(s.cx+0x00000004u));
  }
  L0041129a: { // 0x41129a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    debug_va=0x0041129au;
    s.cx = checked_r32(m,(s.cx+0x00000008u));
  }
  L0041129d: { // 0x41129d: 8bd8 MOV EBX,EAX
    debug_va=0x0041129du;
    s.bx = s.ax;
  }
  L0041129f: { // 0x41129f: 33d2 XOR EDX,EDX
    debug_va=0x0041129fu;
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004112a1: { // 0x4112a1: 33f6 XOR ESI,ESI
    debug_va=0x004112a1u;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004112a3: { // 0x4112a3: 8913 MOV dword ptr [EBX],EDX
    debug_va=0x004112a3u;
    m.w32((s.bx), s.dx);
  }
  L004112a5: { // 0x4112a5: 897304 MOV dword ptr [EBX + 0x4],ESI
    debug_va=0x004112a5u;
    m.w32((s.bx+0x00000004u), s.si);
  }
  L004112a8: { // 0x4112a8: 897b08 MOV dword ptr [EBX + 0x8],EDI
    debug_va=0x004112a8u;
    m.w32((s.bx+0x00000008u), s.di);
  }
  L004112ab: { // 0x4112ab: 5f POP EDI
    debug_va=0x004112abu;
    const auto value=f.pop(m); s.di = value;
  }
  L004112ac: { // 0x4112ac: 5e POP ESI
    debug_va=0x004112acu;
    const auto value=f.pop(m); s.si = value;
  }
  L004112ad: { // 0x4112ad: 894b0c MOV dword ptr [EBX + 0xc],ECX
    debug_va=0x004112adu;
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L004112b0: { // 0x4112b0: 5b POP EBX
    debug_va=0x004112b0u;
    const auto value=f.pop(m); s.bx = value;
  }
  L004112b1: { // 0x4112b1: c20400 RET 0x4
    debug_va=0x004112b1u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00361c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761c80: { // 0x761c80: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    debug_va=0x00761c80u;
    s.dx = checked_r32(m,(f.sp+0x00000008u));
  }
  L00761c84: { // 0x761c84: 56 PUSH ESI
    debug_va=0x00761c84u;
    f.push(m,s.si);
  }
  L00761c85: { // 0x761c85: 8bf1 MOV ESI,ECX
    debug_va=0x00761c85u;
    s.si = s.cx;
  }
  L00761c87: { // 0x761c87: 57 PUSH EDI
    debug_va=0x00761c87u;
    f.push(m,s.di);
  }
  L00761c88: { // 0x761c88: 52 PUSH EDX
    debug_va=0x00761c88u;
    f.push(m,s.dx);
  }
  L00761c89: { // 0x761c89: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x00761c89u;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L00761c8d: { // 0x761c8d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    debug_va=0x00761c8du;
    s.cx = checked_r32(m,(s.si+0x00000014u));
  }
  L00761c90: { // 0x761c90: 52 PUSH EDX
    debug_va=0x00761c90u;
    f.push(m,s.dx);
  }
  L00761c91: { // 0x761c91: 8b01 MOV EAX,dword ptr [ECX]
    debug_va=0x00761c91u;
    s.ax = checked_r32(m,(s.cx));
  }
  L00761c93: { // 0x761c93: ff505c CALL dword ptr [EAX + 0x5c]
    debug_va=0x00761c93u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x0000005cu)),7740566u); flags=s.arithmetic_flags;
  }
  L00761c96: { // 0x761c96: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    debug_va=0x00761c96u;
    s.cx = checked_r32(m,(s.si+0x00000014u));
  }
  L00761c99: { // 0x761c99: 8bf8 MOV EDI,EAX
    debug_va=0x00761c99u;
    s.di = s.ax;
  }
  L00761c9b: { // 0x761c9b: 8b01 MOV EAX,dword ptr [ECX]
    debug_va=0x00761c9bu;
    s.ax = checked_r32(m,(s.cx));
  }
  L00761c9d: { // 0x761c9d: ff5060 CALL dword ptr [EAX + 0x60]
    debug_va=0x00761c9du;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x00000060u)),7740576u); flags=s.arithmetic_flags;
  }
  L00761ca0: { // 0x761ca0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    debug_va=0x00761ca0u;
    s.ax = checked_r32(m,(s.si+0x00000010u));
  }
  L00761ca3: { // 0x761ca3: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    debug_va=0x00761ca3u;
    s.cx = checked_r32(m,(s.si+0x0000001cu));
  }
  L00761ca6: { // 0x761ca6: 03c7 ADD EAX,EDI
    debug_va=0x00761ca6u;
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00761ca8: { // 0x761ca8: 3bc1 CMP EAX,ECX
    debug_va=0x00761ca8u;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00761caa: { // 0x761caa: 7203 JC 0x00761caf
    debug_va=0x00761caau;
    if(integer::condition("JC",flags)) goto L00761caf;
  }
  L00761cac: { // 0x761cac: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    debug_va=0x00761cacu;
    s.ax = integer::sub(s.ax,checked_r32(m,(s.si+0x00000020u)),32,flags);
  }
  L00761caf: { // 0x761caf: 5f POP EDI
    debug_va=0x00761cafu;
    const auto value=f.pop(m); s.di = value;
  }
  L00761cb0: { // 0x761cb0: 5e POP ESI
    debug_va=0x00761cb0u;
    const auto value=f.pop(m); s.si = value;
  }
  L00761cb1: { // 0x761cb1: c20800 RET 0x8
    debug_va=0x00761cb1u;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00011230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411230: { // 0x411230: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    debug_va=0x00411230u;
    s.dx = checked_r32(m,(f.sp+0x00000008u));
  }
  L00411234: { // 0x411234: 56 PUSH ESI
    debug_va=0x00411234u;
    f.push(m,s.si);
  }
  L00411235: { // 0x411235: 8bf1 MOV ESI,ECX
    debug_va=0x00411235u;
    s.si = s.cx;
  }
  L00411237: { // 0x411237: 57 PUSH EDI
    debug_va=0x00411237u;
    f.push(m,s.di);
  }
  L00411238: { // 0x411238: 52 PUSH EDX
    debug_va=0x00411238u;
    f.push(m,s.dx);
  }
  L00411239: { // 0x411239: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    debug_va=0x00411239u;
    s.dx = checked_r32(m,(f.sp+0x00000010u));
  }
  L0041123d: { // 0x41123d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    debug_va=0x0041123du;
    s.cx = checked_r32(m,(s.si+0x00000014u));
  }
  L00411240: { // 0x411240: 52 PUSH EDX
    debug_va=0x00411240u;
    f.push(m,s.dx);
  }
  L00411241: { // 0x411241: 8b01 MOV EAX,dword ptr [ECX]
    debug_va=0x00411241u;
    s.ax = checked_r32(m,(s.cx));
  }
  L00411243: { // 0x411243: ff505c CALL dword ptr [EAX + 0x5c]
    debug_va=0x00411243u;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x0000005cu)),4264518u); flags=s.arithmetic_flags;
  }
  L00411246: { // 0x411246: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    debug_va=0x00411246u;
    s.cx = checked_r32(m,(s.si+0x00000014u));
  }
  L00411249: { // 0x411249: 8bf8 MOV EDI,EAX
    debug_va=0x00411249u;
    s.di = s.ax;
  }
  L0041124b: { // 0x41124b: 8b01 MOV EAX,dword ptr [ECX]
    debug_va=0x0041124bu;
    s.ax = checked_r32(m,(s.cx));
  }
  L0041124d: { // 0x41124d: ff5060 CALL dword ptr [EAX + 0x60]
    debug_va=0x0041124du;
    s.arithmetic_flags=flags; invoke(m,s,f,checked_r32(m,(s.ax+0x00000060u)),4264528u); flags=s.arithmetic_flags;
  }
  L00411250: { // 0x411250: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    debug_va=0x00411250u;
    s.ax = checked_r32(m,(s.si+0x00000010u));
  }
  L00411253: { // 0x411253: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    debug_va=0x00411253u;
    s.cx = checked_r32(m,(s.si+0x0000001cu));
  }
  L00411256: { // 0x411256: 03c7 ADD EAX,EDI
    debug_va=0x00411256u;
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00411258: { // 0x411258: 3bc1 CMP EAX,ECX
    debug_va=0x00411258u;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0041125a: { // 0x41125a: 7203 JC 0x0041125f
    debug_va=0x0041125au;
    if(integer::condition("JC",flags)) goto L0041125f;
  }
  L0041125c: { // 0x41125c: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    debug_va=0x0041125cu;
    s.ax = integer::sub(s.ax,checked_r32(m,(s.si+0x00000020u)),32,flags);
  }
  L0041125f: { // 0x41125f: 5f POP EDI
    debug_va=0x0041125fu;
    const auto value=f.pop(m); s.di = value;
  }
  L00411260: { // 0x411260: 5e POP ESI
    debug_va=0x00411260u;
    const auto value=f.pop(m); s.si = value;
  }
  L00411261: { // 0x411261: c20800 RET 0x8
    debug_va=0x00411261u;
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    debug_va=0x00545500u;
    s.dx = checked_r32(m,(f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    debug_va=0x00545504u;
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    debug_va=0x00545505u;
    s.ax = std::uint32_t(integer::sign_extend(checked_r16(m,(s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    debug_va=0x00545509u;
    s.si = std::uint32_t(integer::sign_extend(checked_r16(m,(s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    debug_va=0x0054550cu;
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    debug_va=0x0054550fu;
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    debug_va=0x00545511u;
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    debug_va=0x00545512u;
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    debug_va=0x00545514u;
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    debug_va=0x00545519u;
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    debug_va=0x0054551bu;
    s.cx = checked_r32(m,(s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    debug_va=0x00545521u;
    s.ax = checked_r32(m,(s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    debug_va=0x00545524u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    debug_va=0x00545526u;
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    debug_va=0x00545528u;
    s.dx = checked_r32(m,(s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    debug_va=0x0054552au;
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    debug_va=0x0054552fu;
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    debug_va=0x00545535u;
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}



void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    debug_va=0x0076aa50u;
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    debug_va=0x0076aa53u;
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    debug_va=0x0076aa56u;
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    debug_va=0x0076aa5au;
    s.dx = checked_r32(m,(f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    debug_va=0x0076aa5du;
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    debug_va=0x0076aa63u;
    (void)integer::sub(s.dx,checked_r32(m,(0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    debug_va=0x0076aa69u;
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    debug_va=0x0076aa6bu;
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    debug_va=0x0076aa6du;
    s.dx = checked_r32(m,(s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    debug_va=0x0076aa70u;
    s.ax = checked_r32(m,(s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    debug_va=0x0076aa72u;
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    debug_va=0x0076aa75u;
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    debug_va=0x0076aa76u;
    s.dx = checked_r32(m,(0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    debug_va=0x0076aa7cu;
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    debug_va=0x0076aa7fu;
    const auto address=(f.sp);
    s.fp.load_control(checked_r16(m,address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    debug_va=0x0076aa82u;
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    debug_va=0x0076aa84u;
    s.dx = checked_r32(m,(s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    debug_va=0x0076aa87u;
    s.ax = checked_r32(m,(s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    debug_va=0x0076aa89u;
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    debug_va=0x0076aa8cu;
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00086460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00486460: { // 0x486460: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    debug_va=0x00486460u;
    s.ax = checked_r32(m,(f.sp+0x00000010u));
  }
  L00486464: { // 0x486464: 8b542408 MOV EDX, dword ptr [ESP + 8]
    debug_va=0x00486464u;
    s.dx = checked_r32(m,(f.sp+8u));
  }
  L00486468: { // 0x486468: 55 PUSH EBP
    debug_va=0x00486468u;
    f.push(m,s.bp);
  }
  L00486469: { // 0x486469: 56 PUSH ESI
    debug_va=0x00486469u;
    f.push(m,s.si);
  }
  L0048646a: { // 0x48646a: 8b74240c MOV ESI, dword ptr [ESP + 0xC]
    debug_va=0x0048646au;
    s.si = checked_r32(m,(f.sp+0x0000000cu));
  }
  L0048646e: { // 0x48646e: 57 PUSH EDI
    debug_va=0x0048646eu;
    f.push(m,s.di);
  }
  L0048646f: { // 0x48646f: 85c0 TEST EAX, EAX
    debug_va=0x0048646fu;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00486471: { // 0x486471: 8be9 MOV EBP, ECX
    debug_va=0x00486471u;
    s.bp = s.cx;
  }
  L00486473: { // 0x486473: 7e21 JLE 0x486496
    debug_va=0x00486473u;
    if(integer::condition("JLE",flags)) goto L00486496;
  }
  L00486475: { // 0x486475: 8a0a MOV CL, byte ptr [EDX]
    debug_va=0x00486475u;
    s.cx = with_al(s.cx, checked_r8(m,(s.dx)));
  }
  L00486477: { // 0x486477: 42 INC EDX
    debug_va=0x00486477u;
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00486478: { // 0x486478: 84c9 TEST CL, CL
    debug_va=0x00486478u;
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0048647a: { // 0x48647a: 7509 JNZ 0x486485
    debug_va=0x0048647au;
    if(integer::condition("JNZ",flags)) goto L00486485;
  }
  L0048647c: { // 0x48647c: 33c9 XOR ECX, ECX
    debug_va=0x0048647cu;
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0048647e: { // 0x48647e: 8a0a MOV CL, byte ptr [EDX]
    debug_va=0x0048647eu;
    s.cx = with_al(s.cx, checked_r8(m,(s.dx)));
  }
  L00486480: { // 0x486480: 2bc1 SUB EAX, ECX
    debug_va=0x00486480u;
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00486482: { // 0x486482: 42 INC EDX
    debug_va=0x00486482u;
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00486483: { // 0x486483: eb01 JMP 0x486486
    debug_va=0x00486483u;
    goto L00486486;
  }
  L00486485: { // 0x486485: 48 DEC EAX
    debug_va=0x00486485u;
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00486486: { // 0x486486: 85c0 TEST EAX, EAX
    debug_va=0x00486486u;
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00486488: { // 0x486488: 7feb JG 0x486475
    debug_va=0x00486488u;
    if(integer::condition("JG",flags)) goto L00486475;
  }
  L0048648a: { // 0x48648a: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    debug_va=0x0048648au;
    s.di = checked_r32(m,(f.sp+0x00000018u));
  }
  L0048648e: { // 0x48648e: f7d8 NEG EAX
    debug_va=0x0048648eu;
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00486490: { // 0x486490: 03f0 ADD ESI, EAX
    debug_va=0x00486490u;
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00486492: { // 0x486492: 2bf8 SUB EDI, EAX
    debug_va=0x00486492u;
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00486494: { // 0x486494: eb04 JMP 0x48649A
    debug_va=0x00486494u;
    goto L0048649a;
  }
  L00486496: { // 0x486496: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    debug_va=0x00486496u;
    s.di = checked_r32(m,(f.sp+0x00000018u));
  }
  L0048649a: { // 0x48649a: 85ff TEST EDI, EDI
    debug_va=0x0048649au;
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0048649c: { // 0x48649c: 7e44 JLE 0x4864E2
    debug_va=0x0048649cu;
    if(integer::condition("JLE",flags)) goto L004864e2;
  }
  L0048649e: { // 0x48649e: 53 PUSH EBX
    debug_va=0x0048649eu;
    f.push(m,s.bx);
  }
  L0048649f: { // 0x48649f: 8a02 MOV AL, byte ptr [EDX]
    debug_va=0x0048649fu;
    s.ax = with_al(s.ax, checked_r8(m,(s.dx)));
  }
  L004864a1: { // 0x4864a1: 42 INC EDX
    debug_va=0x004864a1u;
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004864a2: { // 0x4864a2: 84c0 TEST AL, AL
    debug_va=0x004864a2u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004864a4: { // 0x4864a4: 8844241c MOV byte ptr [ESP + 0x1C], AL
    debug_va=0x004864a4u;
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L004864a8: { // 0x4864a8: 7516 JNZ 0x4864C0
    debug_va=0x004864a8u;
    if(integer::condition("JNZ",flags)) goto L004864c0;
  }
  L004864aa: { // 0x4864aa: 8a02 MOV AL, byte ptr [EDX]
    debug_va=0x004864aau;
    s.ax = with_al(s.ax, checked_r8(m,(s.dx)));
  }
  L004864ac: { // 0x4864ac: 42 INC EDX
    debug_va=0x004864acu;
    s.dx = integer::increment(s.dx,32,flags);
  }
  L004864ad: { // 0x4864ad: 8844241c MOV byte ptr [ESP + 0x1C], AL
    debug_va=0x004864adu;
    m.w8((f.sp+0x0000001cu), (s.ax & 0xffu));
  }
  L004864b1: { // 0x4864b1: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    debug_va=0x004864b1u;
    s.ax = checked_r32(m,(f.sp+0x0000001cu));
  }
  L004864b5: { // 0x4864b5: 25ff000000 AND EAX, 0xFF
    debug_va=0x004864b5u;
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L004864ba: { // 0x4864ba: 2bf8 SUB EDI, EAX
    debug_va=0x004864bau;
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L004864bc: { // 0x4864bc: 03f0 ADD ESI, EAX
    debug_va=0x004864bcu;
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L004864be: { // 0x4864be: eb1d JMP 0x4864DD
    debug_va=0x004864beu;
    goto L004864dd;
  }
  L004864c0: { // 0x4864c0: 8b4c241c MOV ECX, dword ptr [ESP + 0x1C]
    debug_va=0x004864c0u;
    s.cx = checked_r32(m,(f.sp+0x0000001cu));
  }
  L004864c4: { // 0x4864c4: 8b4504 MOV EAX, dword ptr [EBP + 4]
    debug_va=0x004864c4u;
    s.ax = checked_r32(m,(s.bp+4u));
  }
  L004864c7: { // 0x4864c7: 81e1ff000000 AND ECX, 0xFF
    debug_va=0x004864c7u;
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L004864cd: { // 0x4864cd: 33db XOR EBX, EBX
    debug_va=0x004864cdu;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004864cf: { // 0x4864cf: 46 INC ESI
    debug_va=0x004864cfu;
    s.si = integer::increment(s.si,32,flags);
  }
  L004864d0: { // 0x4864d0: 4f DEC EDI
    debug_va=0x004864d0u;
    s.di = integer::decrement(s.di,32,flags);
  }
  L004864d1: { // 0x4864d1: 8a1c08 MOV BL, byte ptr [EAX + ECX]
    debug_va=0x004864d1u;
    s.bx = with_al(s.bx, checked_r8(m,(s.ax+s.cx)));
  }
  L004864d4: { // 0x4864d4: 8b4d08 MOV ECX, dword ptr [EBP + 8]
    debug_va=0x004864d4u;
    s.cx = checked_r32(m,(s.bp+8u));
  }
  L004864d7: { // 0x4864d7: 8a040b MOV AL, byte ptr [EBX + ECX]
    debug_va=0x004864d7u;
    s.ax = with_al(s.ax, checked_r8(m,(s.bx+s.cx)));
  }
  L004864da: { // 0x4864da: 8846ff MOV byte ptr [ESI - 1], AL
    debug_va=0x004864dau;
    m.w8((s.si-1u), (s.ax & 0xffu));
  }
  L004864dd: { // 0x4864dd: 85ff TEST EDI, EDI
    debug_va=0x004864ddu;
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004864df: { // 0x4864df: 7fbe JG 0x48649F
    debug_va=0x004864dfu;
    if(integer::condition("JG",flags)) goto L0048649f;
  }
  L004864e1: { // 0x4864e1: 5b POP EBX
    debug_va=0x004864e1u;
    const auto value=f.pop(m); s.bx = value;
  }
  L004864e2: { // 0x4864e2: 5f POP EDI
    debug_va=0x004864e2u;
    const auto value=f.pop(m); s.di = value;
  }
  L004864e3: { // 0x4864e3: 5e POP ESI
    debug_va=0x004864e3u;
    const auto value=f.pop(m); s.si = value;
  }
  L004864e4: { // 0x4864e4: 5d POP EBP
    debug_va=0x004864e4u;
    const auto value=f.pop(m); s.bp = value;
  }
  L004864e5: { // 0x4864e5: c22800 RET 0x28
    debug_va=0x004864e5u;
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
}

} // namespace
namespace {


void f_0029b8d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x69b8d0: 83ec50 SUB ESP, 0x50
    f.sp = integer::sub(f.sp,0x00000050u,32,flags);
  }
  { // 0x69b8d3: a1c0b98100 MOV EAX, dword ptr [0x81b9c0]
    s.ax = m.r32((0x0081b9c0u));
  }
  { // 0x69b8d8: 894c2420 MOV dword ptr [ESP + 0x20], ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  { // 0x69b8dc: 8b8818040000 MOV ECX, dword ptr [EAX + 0x418]
    s.cx = m.r32((s.ax+0x00000418u));
  }
  { // 0x69b8e2: 8b81ec0b0000 MOV EAX, dword ptr [ECX + 0xbec]
    s.ax = m.r32((s.cx+0x00000becu));
  }
  { // 0x69b8e8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x69b8ea: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x69b8ee: 0f84b2020000 JZ 0x69bba6
    if(integer::condition("JZ",flags)) goto L0069bba6;
  }
  { // 0x69b8f4: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x69b8f5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x69b8f6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x69b8f8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x69b8f9: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x69b8fa: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0069b8fe: { // 0x69b8fe: 8b542468 MOV EDX, dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  { // 0x69b902: 8b0dc0b98100 MOV ECX, dword ptr [0x81b9c0]
    s.cx = m.r32((0x0081b9c0u));
  }
  { // 0x69b908: 89542414 MOV dword ptr [ESP + 0x14], EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  { // 0x69b90c: 33ff XOR EDI, EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x69b90e: 8ba918040000 MOV EBP, dword ptr [ECX + 0x418]
    s.bp = m.r32((s.cx+0x00000418u));
  }
  { // 0x69b914: 8bb504050000 MOV ESI, dword ptr [EBP + 0x504]
    s.si = m.r32((s.bp+0x00000504u));
  }
  { // 0x69b91a: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x69b91d: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x69b91f: 0f8e69020000 JLE 0x69bb8e
    if(integer::condition("JLE",flags)) goto L0069bb8e;
  }
  { // 0x69b925: 83e007 AND EAX, 7
    s.ax = integer::logical((s.ax)&(7u),32,flags);
  }
  { // 0x69b928: 8d1c85a09d8300 LEA EBX, [EAX*4 + 0x839da0]
    s.bx = ((s.ax * 4u)+0x00839da0u);
  }
  L0069b92f: { // 0x69b92f: 668b13 MOV DX, word ptr [EBX]
    s.dx = with_ax(s.dx, m.r16((s.bx)));
  }
  { // 0x69b932: 668b4302 MOV AX, word ptr [EBX + 2]
    s.ax = with_ax(s.ax, m.r16((s.bx+2u)));
  }
  { // 0x69b936: 6603542414 ADD DX, word ptr [ESP + 0x14]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x00000014u)),16,flags));
  }
  { // 0x69b93b: 6603442416 ADD AX, word ptr [ESP + 0x16]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000016u)),16,flags));
  }
  { // 0x69b940: 6689542418 MOV word ptr [ESP + 0x18], DX
    m.w16((f.sp+0x00000018u), (s.dx & 0xffffu));
  }
  { // 0x69b945: 668944241a MOV word ptr [ESP + 0x1a], AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  { // 0x69b94a: 8b4c2418 MOV ECX, dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x69b94e: 8d542414 LEA EDX, [ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x69b952: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  { // 0x69b956: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x69b957: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x69b95c: e89f9beaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6928737u); flags=s.arithmetic_flags;
  }
  { // 0x69b961: 8b4044 MOV EAX, dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  { // 0x69b964: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  { // 0x69b967: 742b JZ 0x69b994
    if(integer::condition("JZ",flags)) goto L0069b994;
  }
  { // 0x69b969: 8b4c242c MOV ECX, dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  { // 0x69b96d: 398164020000 CMP dword ptr [ECX + 0x264], EAX
    (void)integer::sub(m.r32((s.cx+0x00000264u)),s.ax,32,flags);
  }
  { // 0x69b973: 751f JNZ 0x69b994
    if(integer::condition("JNZ",flags)) goto L0069b994;
  }
  { // 0x69b975: 8d542414 LEA EDX, [ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  { // 0x69b979: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x69b97e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x69b97f: e87c9beaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6928772u); flags=s.arithmetic_flags;
  }
  { // 0x69b984: 8b0de4e0a100 MOV ECX, dword ptr [0xa1e0e4]
    s.cx = m.r32((0x00a1e0e4u));
  }
  { // 0x69b98a: 8b5130 MOV EDX, dword ptr [ECX + 0x30]
    s.dx = m.r32((s.cx+0x00000030u));
  }
  { // 0x69b98d: 8b4850 MOV ECX, dword ptr [EAX + 0x50]
    s.cx = m.r32((s.ax+0x00000050u));
  }
  { // 0x69b990: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x69b992: 743a JZ 0x69b9ce
    if(integer::condition("JZ",flags)) goto L0069b9ce;
  }
  L0069b994: { // 0x69b994: a1e4e0a100 MOV EAX, dword ptr [0xa1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  { // 0x69b999: 8b8da4050000 MOV ECX, dword ptr [EBP + 0x5a4]
    s.cx = m.r32((s.bp+0x000005a4u));
  }
  { // 0x69b99f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69b9a0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x69b9a1: 8d54241c LEA EDX, [ESP + 0x1c]
    s.dx = (f.sp+0x0000001cu);
  }
  { // 0x69b9a5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x69b9a6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x69b9a7: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x69b9ac: e84f9beaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6928817u); flags=s.arithmetic_flags;
  }
  { // 0x69b9b1: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  { // 0x69b9b3: e8f85addff CALL 0x4714b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004714b0u,6928824u); flags=s.arithmetic_flags;
  }
  { // 0x69b9b8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x69b9ba: 0f84ce010000 JZ 0x69bb8e
    if(integer::condition("JZ",flags)) goto L0069bb8e;
  }
  { // 0x69b9c0: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x69b9c1: 3bfe CMP EDI, ESI
    (void)integer::sub(s.di,s.si,32,flags);
  }
  { // 0x69b9c3: 0f8c66ffffff JL 0x69b92f
    if(integer::condition("JL",flags)) goto L0069b92f;
  }
  { // 0x69b9c9: e9c0010000 JMP 0x69bb8e
    goto L0069bb8e;
  }
  L0069b9ce: { // 0x69b9ce: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x69b9d0: 0f8eb8010000 JLE 0x69bb8e
    if(integer::condition("JLE",flags)) goto L0069bb8e;
  }
  { // 0x69b9d6: 8a442464 MOV AL, byte ptr [ESP + 0x64]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000064u)));
  }
  { // 0x69b9da: 668b0b MOV CX, word ptr [EBX]
    s.cx = with_ax(s.cx, m.r16((s.bx)));
  }
  { // 0x69b9dd: 668b5302 MOV DX, word ptr [EBX + 2]
    s.dx = with_ax(s.dx, m.r16((s.bx+2u)));
  }
  { // 0x69b9e1: f6d8 NEG AL
    s.ax = with_al(s.ax, integer::sub(0u,(s.ax & 0xffu),8,flags));
  }
  { // 0x69b9e3: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x69b9e5: 66034c2468 ADD CX, word ptr [ESP + 0x68]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000068u)),16,flags));
  }
  { // 0x69b9ea: 660354246a ADD DX, word ptr [ESP + 0x6a]
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),m.r16((f.sp+0x0000006au)),16,flags));
  }
  { // 0x69b9ef: 250000ffff AND EAX, 0xffff0000
    s.ax = integer::logical((s.ax)&(0xffff0000u),32,flags);
  }
  { // 0x69b9f4: 0506060200 ADD EAX, 0x20606
    s.ax = integer::add(s.ax,0x00020606u,32,flags);
  }
  { // 0x69b9f9: 66894c241c MOV word ptr [ESP + 0x1c], CX
    m.w16((f.sp+0x0000001cu), (s.cx & 0xffffu));
  }
  { // 0x69b9fe: 89442434 MOV dword ptr [ESP + 0x34], EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  { // 0x69ba02: 668954241e MOV word ptr [ESP + 0x1e], DX
    m.w16((f.sp+0x0000001eu), (s.dx & 0xffffu));
  }
  { // 0x69ba07: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x69ba0b: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x69ba0d: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  { // 0x69ba11: 0f8e77010000 JLE 0x69bb8e
    if(integer::condition("JLE",flags)) goto L0069bb8e;
  }
  { // 0x69ba17: 897c2424 MOV dword ptr [ESP + 0x24], EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L0069ba1b: { // 0x69ba1b: 8d4c2410 LEA ECX, [ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x69ba1f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x69ba20: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x69ba25: e8d69aeaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6928938u); flags=s.arithmetic_flags;
  }
  { // 0x69ba2a: 0fbe801b010000 MOVSX EAX, byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x69ba31: 8d542410 LEA EDX, [ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  { // 0x69ba35: 83cfff OR EDI, 0xffffffff
    s.di = integer::logical((s.di)|(0xffffffffu),32,flags);
  }
  { // 0x69ba38: 8d0440 LEA EAX, [EAX + EAX*2]
    s.ax = (s.ax+(s.ax * 2u));
  }
  { // 0x69ba3b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x69ba3c: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x69ba41: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  { // 0x69ba44: 2bf8 SUB EDI, EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x69ba46: e8b59aeaff CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,6928971u); flags=s.arithmetic_flags;
  }
  { // 0x69ba4b: 0fbe801b010000 MOVSX EAX, byte ptr [EAX + 0x11b]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x69ba52: bdfeffffff MOV EBP, 0xfffffffe
    s.bp = 0xfffffffeu;
  }
  { // 0x69ba57: 8d0440 LEA EAX, [EAX + EAX*2]
    s.ax = (s.ax+(s.ax * 2u));
  }
  { // 0x69ba5a: 0fbf4c2412 MOVSX ECX, word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  { // 0x69ba5f: 8d0480 LEA EAX, [EAX + EAX*4]
    s.ax = (s.ax+(s.ax * 4u));
  }
  { // 0x69ba62: 2be8 SUB EBP, EAX
    s.bp = integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x69ba64: 0fbf442410 MOVSX EAX, word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  { // 0x69ba69: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  { // 0x69ba6c: 0580000000 ADD EAX, 0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  { // 0x69ba71: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x69ba72: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x69ba78: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  { // 0x69ba7b: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x69ba7d: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  { // 0x69ba83: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  { // 0x69ba85: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  { // 0x69ba87: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x69ba88: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x69ba8e: 8d4c2458 LEA ECX, [ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  { // 0x69ba92: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x69ba94: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x69ba97: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x69ba9a: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  { // 0x69ba9d: c1e608 SHL ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::left);
  }
  { // 0x69baa0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69baa1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x69baa2: e8d9c2ffff CALL 0x697d80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697d80u,6929063u); flags=s.arithmetic_flags;
  }
  { // 0x69baa7: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  { // 0x69baa9: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x69baab: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  { // 0x69baae: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x69bab0: 89542454 MOV dword ptr [ESP + 0x54], EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  { // 0x69bab4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x69bab5: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x69babb: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x69babd: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  { // 0x69babf: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x69bac2: e8e9c4ffff CALL 0x697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6929095u); flags=s.arithmetic_flags;
  }
  { // 0x69bac7: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  { // 0x69bac9: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  { // 0x69bacd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x69bace: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x69bad4: 89742438 MOV dword ptr [ESP + 0x38], ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  { // 0x69bad8: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x69bada: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x69badd: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x69badf: 8d4c2440 LEA ECX, [ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  { // 0x69bae3: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  { // 0x69bae7: 8b442430 MOV EAX, dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  { // 0x69baeb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x69baec: 8d4c243c LEA ECX, [ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  { // 0x69baf0: 8b90b0000000 MOV EDX, dword ptr [EAX + 0xb0]
    s.dx = m.r32((s.ax+0x000000b0u));
  }
  { // 0x69baf6: 8b80b4000000 MOV EAX, dword ptr [EAX + 0xb4]
    s.ax = m.r32((s.ax+0x000000b4u));
  }
  { // 0x69bafc: 89542444 MOV dword ptr [ESP + 0x44], EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  { // 0x69bb00: 89442448 MOV dword ptr [ESP + 0x48], EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  { // 0x69bb04: e897630000 CALL 0x6a1ea0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006a1ea0u,6929161u); flags=s.arithmetic_flags;
  }
  { // 0x69bb09: 8b442438 MOV EAX, dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  { // 0x69bb0d: 8b54243c MOV EDX, dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  { // 0x69bb11: 83e81e SUB EAX, 0x1e
    s.ax = integer::sub(s.ax,0x0000001eu,32,flags);
  }
  { // 0x69bb14: 03fa ADD EDI, EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  { // 0x69bb16: 89442438 MOV dword ptr [ESP + 0x38], EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  { // 0x69bb1a: 83c01e ADD EAX, 0x1e
    s.ax = integer::add(s.ax,0x0000001eu,32,flags);
  }
  { // 0x69bb1d: 89442448 MOV dword ptr [ESP + 0x48], EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  { // 0x69bb21: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x69bb23: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69bb24: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69bb25: 897c2454 MOV dword ptr [ESP + 0x54], EDI
    m.w32((f.sp+0x00000054u), s.di);
  }
  { // 0x69bb29: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69bb2a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69bb2b: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x69bb30: 8b1544a98300 MOV EDX, dword ptr [0x83a944]
    s.dx = m.r32((0x0083a944u));
  }
  { // 0x69bb36: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69bb37: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x69bb38: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69bb39: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  { // 0x69bb3d: 8d4c2468 LEA ECX, [ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  { // 0x69bb41: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69bb42: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  { // 0x69bb47: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x69bb48: 8b0d9c1c8200 MOV ECX, dword ptr [0x821c9c]
    s.cx = m.r32((0x00821c9cu));
  }
  { // 0x69bb4e: 6a00 PUSH 0
    f.push(m,0u);
  }
  { // 0x69bb50: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x69bb51: 8b1504a78100 MOV EDX, dword ptr [0x81a704]
    s.dx = m.r32((0x0081a704u));
  }
  { // 0x69bb57: e87430e0ff CALL 0x49ebd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049ebd0u,6929244u); flags=s.arithmetic_flags;
  }
  { // 0x69bb5c: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  { // 0x69bb5f: 668b4b02 MOV CX, word ptr [EBX + 2]
    s.cx = with_ax(s.cx, m.r16((s.bx+2u)));
  }
  { // 0x69bb63: 6603442410 ADD AX, word ptr [ESP + 0x10]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((f.sp+0x00000010u)),16,flags));
  }
  { // 0x69bb68: 66034c2412 ADD CX, word ptr [ESP + 0x12]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((f.sp+0x00000012u)),16,flags));
  }
  { // 0x69bb6d: 6689442420 MOV word ptr [ESP + 0x20], AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  { // 0x69bb72: 8b442424 MOV EAX, dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  { // 0x69bb76: 66894c2422 MOV word ptr [ESP + 0x22], CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  { // 0x69bb7b: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x69bb7f: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x69bb80: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  { // 0x69bb84: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  { // 0x69bb88: 0f858dfeffff JNZ 0x69ba1b
    if(integer::condition("JNZ",flags)) goto L0069ba1b;
  }
  L0069bb8e: { // 0x69bb8e: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x69bb92: 83c002 ADD EAX, 2
    s.ax = integer::add(s.ax,2u,32,flags);
  }
  { // 0x69bb95: 83f808 CMP EAX, 8
    (void)integer::sub(s.ax,8u,32,flags);
  }
  { // 0x69bb98: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  { // 0x69bb9c: 0f8c5cfdffff JL 0x69b8fe
    if(integer::condition("JL",flags)) goto L0069b8fe;
  }
  { // 0x69bba2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x69bba3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x69bba4: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x69bba5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069bba6: { // 0x69bba6: 83c450 ADD ESP, 0x50
    f.sp = integer::add(f.sp,0x00000050u,32,flags);
  }
  { // 0x69bba9: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00297d80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x697d80: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x697d81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x697d82: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x697d83: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x697d87: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x697d8b: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  { // 0x697d8e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x697d91: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x697d94: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x697d95: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x697d97: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x697d99: 8d047f LEA EAX,[EDI + EDI*0x2]
    s.ax = (s.di+(s.di * 0x00000002u));
  }
  { // 0x697d9c: d1fe SAR ESI,0x1
    s.si = integer::shift(s.si,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x697d9e: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x697da1: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x697da3: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x697da4: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x697da6: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x697da8: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x697daa: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x697dad: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x697daf: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x697db1: c1e002 SHL EAX,0x2
    s.ax = integer::shift(s.ax,0x00000002u,32,flags,integer::Shift::left);
  }
  { // 0x697db4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x697db5: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x697db7: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x697db9: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  { // 0x697dbb: 8d045b LEA EAX,[EBX + EBX*0x2]
    s.ax = (s.bx+(s.bx * 0x00000002u));
  }
  { // 0x697dbe: d1ff SAR EDI,0x1
    s.di = integer::shift(s.di,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x697dc0: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  { // 0x697dc3: 8931 MOV dword ptr [ECX],ESI
    m.w32((s.cx), s.si);
  }
  { // 0x697dc5: d1e0 SHL EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x697dc7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x697dc8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x697dca: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x697dcc: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  { // 0x697dce: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x697dd0: 897904 MOV dword ptr [ECX + 0x4],EDI
    m.w32((s.cx+0x00000004u), s.di);
  }
  { // 0x697dd3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x697dd4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x697dd5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x697dd6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00297fb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x697fb0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x697fb3: 81f9d8020000 CMP ECX,0x2d8
    (void)integer::sub(s.cx,0x000002d8u,32,flags);
  }
  { // 0x697fb9: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x697fbd: c744240000000000 MOV dword ptr [ESP],0x0
    m.w32((f.sp), 0x00000000u);
  }
  { // 0x697fc5: 7c08 JL 0x00697fcf
    if(integer::condition("JL",flags)) goto L00697fcf;
  }
  { // 0x697fc7: c744240001000000 MOV dword ptr [ESP],0x1
    m.w32((f.sp), 0x00000001u);
  }
  L00697fcf: { // 0x697fcf: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  { // 0x697fd3: dc0d905faa00 FMUL double ptr [0x00aa5f90]
    const auto address=(0x00aa5f90u);
    s.fp.multiply64(read64(m,address));
  }
  { // 0x697fd9: da442400 FIADD dword ptr [ESP]
    const auto address=(f.sp);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  { // 0x697fdd: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  { // 0x697fe3: e8682a0d00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6914024u); flags=s.arithmetic_flags;
  }
  { // 0x697fe8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x697feb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002a1ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a1ea0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x6a1ea2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a1ea3: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6a1ea7: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  { // 0x6a1ea9: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x6a1eab: 2bf2 SUB ESI,EDX
    s.si = integer::sub(s.si,s.dx,32,flags);
  }
  { // 0x6a1ead: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x6a1eb0: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  { // 0x6a1eb2: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  { // 0x6a1eb5: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x6a1eb7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a1eb8: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  { // 0x6a1ebb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000714b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x4714b0: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  { // 0x4714b5: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x4714b8: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x4714b9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4714ba: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  { // 0x4714bc: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x4714bd: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x4714be: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x4714c0: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x4714c2: 0f8538040000 JNZ 0x00471900
    if(integer::condition("JNZ",flags)) goto L00471900;
  }
  { // 0x4714c8: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x4714cc: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x4714ce: 7460 JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  { // 0x4714d0: 8a8859130000 MOV CL,byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  { // 0x4714d6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4714d8: 0f848f000000 JZ 0x0047156d
    if(integer::condition("JZ",flags)) goto L0047156d;
  }
  { // 0x4714de: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x4714e3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x4714e5: 7449 JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  { // 0x4714e7: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  { // 0x4714ed: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x4714ef: 7419 JZ 0x0047150a
    if(integer::condition("JZ",flags)) goto L0047150a;
  }
  L004714f1: { // 0x4714f1: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4714f3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4714f5: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658424u); flags=s.arithmetic_flags;
  }
  { // 0x4714f8: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x4714fb: 7409 JZ 0x00471506
    if(integer::condition("JZ",flags)) goto L00471506;
  }
  { // 0x4714fd: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x471500: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x471502: 75ed JNZ 0x004714f1
    if(integer::condition("JNZ",flags)) goto L004714f1;
  }
  { // 0x471504: eb04 JMP 0x0047150a
    goto L0047150a;
  }
  L00471506: { // 0x471506: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x471508: 7557 JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L0047150a: { // 0x47150a: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x47150f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471511: 741d JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  { // 0x471513: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  { // 0x471519: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x47151b: 7413 JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L0047151d: { // 0x47151d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47151f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x471521: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4658468u); flags=s.arithmetic_flags;
  }
  { // 0x471524: 83f824 CMP EAX,0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  { // 0x471527: 7434 JZ 0x0047155d
    if(integer::condition("JZ",flags)) goto L0047155d;
  }
  { // 0x471529: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x47152c: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x47152e: 75ed JNZ 0x0047151d
    if(integer::condition("JNZ",flags)) goto L0047151d;
  }
  L00471530: { // 0x471530: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  { // 0x471535: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471537: 0f84cb010000 JZ 0x00471708
    if(integer::condition("JZ",flags)) goto L00471708;
  }
  { // 0x47153d: 8d4724 LEA EAX,[EDI + 0x24]
    s.ax = (s.di+0x00000024u);
  }
  { // 0x471540: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x471545: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x471546: e8f5690d00 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,4658507u); flags=s.arithmetic_flags;
  }
  { // 0x47154b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47154d: 0f85ca010000 JNZ 0x0047171d
    if(integer::condition("JNZ",flags)) goto L0047171d;
  }
  { // 0x471553: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x471554: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x471555: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x471556: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x471557: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x47155a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047155d: { // 0x47155d: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x47155f: 74cf JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L00471561: { // 0x471561: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x471562: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x471563: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x471564: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x471566: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x471567: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x47156a: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047156d: { // 0x47156d: 8a8858130000 MOV CL,byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  { // 0x471573: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x471575: 0f85dd000000 JNZ 0x00471658
    if(integer::condition("JNZ",flags)) goto L00471658;
  }
  { // 0x47157b: 8a8851130000 MOV CL,byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  { // 0x471581: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x471583: 0f85cf000000 JNZ 0x00471658
    if(integer::condition("JNZ",flags)) goto L00471658;
  }
  { // 0x471589: 39a8f00b0000 CMP dword ptr [EAX + 0xbf0],EBP
    (void)integer::sub(m.r32((s.ax+0x00000bf0u)),s.bp,32,flags);
  }
  { // 0x47158f: 756a JNZ 0x004715fb
    if(integer::condition("JNZ",flags)) goto L004715fb;
  }
  { // 0x471591: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x471596: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x47159a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47159c: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  { // 0x4715a0: 741d JZ 0x004715bf
    if(integer::condition("JZ",flags)) goto L004715bf;
  }
  { // 0x4715a2: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  { // 0x4715a8: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x4715aa: 7413 JZ 0x004715bf
    if(integer::condition("JZ",flags)) goto L004715bf;
  }
  L004715ac: { // 0x4715ac: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x4715ae: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4715b0: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658611u); flags=s.arithmetic_flags;
  }
  { // 0x4715b3: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x4715b6: 743b JZ 0x004715f3
    if(integer::condition("JZ",flags)) goto L004715f3;
  }
  { // 0x4715b8: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x4715bb: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x4715bd: 75ed JNZ 0x004715ac
    if(integer::condition("JNZ",flags)) goto L004715ac;
  }
  L004715bf: { // 0x4715bf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4715c0: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x4715c4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4715c5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x4715c6: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4715c8: e893fcffff CALL 0x00471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4658637u); flags=s.arithmetic_flags;
  }
  { // 0x4715cd: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x4715cf: 0f850e010000 JNZ 0x004716e3
    if(integer::condition("JNZ",flags)) goto L004716e3;
  }
  { // 0x4715d5: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x4715d6: 6a24 PUSH 0x24
    f.push(m,0x00000024u);
  }
  { // 0x4715d8: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4715da: e881fdffff CALL 0x00471360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471360u,4658655u); flags=s.arithmetic_flags;
  }
  L004715df: { // 0x4715df: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x4715e1: 0f8408010000 JZ 0x004716ef
    if(integer::condition("JZ",flags)) goto L004716ef;
  }
  { // 0x4715e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4715e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4715e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4715ea: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4715ec: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4715ed: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4715f0: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004715f3: { // 0x4715f3: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x4715f5: 74c8 JZ 0x004715bf
    if(integer::condition("JZ",flags)) goto L004715bf;
  }
  { // 0x4715f7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4715f9: ebe4 JMP 0x004715df
    goto L004715df;
  }
  L004715fb: { // 0x4715fb: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  { // 0x4715fe: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x471600: 7c1f JL 0x00471621
    if(integer::condition("JL",flags)) goto L00471621;
  }
  { // 0x471602: 3b052089a200 CMP EAX,dword ptr [0x00a28920]
    (void)integer::sub(s.ax,m.r32((0x00a28920u)),32,flags);
  }
  { // 0x471608: 7d17 JGE 0x00471621
    if(integer::condition("JGE",flags)) goto L00471621;
  }
  { // 0x47160a: 8b151489a200 MOV EDX,dword ptr [0x00a28914]
    s.dx = m.r32((0x00a28914u));
  }
  { // 0x471610: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  { // 0x471613: 8a88b0020000 MOV CL,byte ptr [EAX + 0x2b0]
    s.cx = with_al(s.cx, m.r8((s.ax+0x000002b0u)));
  }
  { // 0x471619: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x47161b: 0f84db000000 JZ 0x004716fc
    if(integer::condition("JZ",flags)) goto L004716fc;
  }
  L00471621: { // 0x471621: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x471626: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471628: 0f8402ffffff JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  { // 0x47162e: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  { // 0x471634: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x471636: 0f84f4feffff JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L0047163c: { // 0x47163c: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x47163e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x471640: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4658755u); flags=s.arithmetic_flags;
  }
  { // 0x471643: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x471646: 0f8411ffffff JZ 0x0047155d
    if(integer::condition("JZ",flags)) goto L0047155d;
  }
  { // 0x47164c: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x47164f: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x471651: 75e9 JNZ 0x0047163c
    if(integer::condition("JNZ",flags)) goto L0047163c;
  }
  { // 0x471653: e9d8feffff JMP 0x00471530
    goto L00471530;
  }
  L00471658: { // 0x471658: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x47165d: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  { // 0x471661: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471663: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  { // 0x471667: 7423 JZ 0x0047168c
    if(integer::condition("JZ",flags)) goto L0047168c;
  }
  { // 0x471669: 8bb7e4000000 MOV ESI,dword ptr [EDI + 0xe4]
    s.si = m.r32((s.di+0x000000e4u));
  }
  { // 0x47166f: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x471671: 7419 JZ 0x0047168c
    if(integer::condition("JZ",flags)) goto L0047168c;
  }
  L00471673: { // 0x471673: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x471675: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x471677: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658810u); flags=s.arithmetic_flags;
  }
  { // 0x47167a: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x47167d: 7409 JZ 0x00471688
    if(integer::condition("JZ",flags)) goto L00471688;
  }
  { // 0x47167f: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x471682: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x471684: 75ed JNZ 0x00471673
    if(integer::condition("JNZ",flags)) goto L00471673;
  }
  { // 0x471686: eb04 JMP 0x0047168c
    goto L0047168c;
  }
  L00471688: { // 0x471688: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x47168a: 7522 JNZ 0x004716ae
    if(integer::condition("JNZ",flags)) goto L004716ae;
  }
  L0047168c: { // 0x47168c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x47168d: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  { // 0x471691: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x471692: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x471693: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x471695: e8c6fbffff CALL 0x00471260
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471260u,4658842u); flags=s.arithmetic_flags;
  }
  { // 0x47169a: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x47169c: 750a JNZ 0x004716a8
    if(integer::condition("JNZ",flags)) goto L004716a8;
  }
  { // 0x47169e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x47169f: 6a24 PUSH 0x24
    f.push(m,0x00000024u);
  }
  { // 0x4716a1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x4716a3: e8b8fcffff CALL 0x00471360
    s.arithmetic_flags=flags; invoke(m,s,f,0x00471360u,4658856u); flags=s.arithmetic_flags;
  }
  L004716a8: { // 0x4716a8: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x4716aa: 3bf5 CMP ESI,EBP
    (void)integer::sub(s.si,s.bp,32,flags);
  }
  { // 0x4716ac: 7441 JZ 0x004716ef
    if(integer::condition("JZ",flags)) goto L004716ef;
  }
  L004716ae: { // 0x4716ae: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4716b0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4716b2: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),4658869u); flags=s.arithmetic_flags;
  }
  { // 0x4716b5: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  { // 0x4716b8: 740c JZ 0x004716c6
    if(integer::condition("JZ",flags)) goto L004716c6;
  }
  { // 0x4716ba: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4716bb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4716bc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4716bd: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4716bf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4716c0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4716c3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004716c6: { // 0x4716c6: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  { // 0x4716cc: 8a8859130000 MOV CL,byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  { // 0x4716d2: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x4716d4: 740d JZ 0x004716e3
    if(integer::condition("JZ",flags)) goto L004716e3;
  }
  { // 0x4716d6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4716d8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4716da: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),4658909u); flags=s.arithmetic_flags;
  }
  { // 0x4716dd: 3b442424 CMP EAX,dword ptr [ESP + 0x24]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000024u)),32,flags);
  }
  { // 0x4716e1: 740c JZ 0x004716ef
    if(integer::condition("JZ",flags)) goto L004716ef;
  }
  L004716e3: { // 0x4716e3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4716e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4716e5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4716e6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4716e8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4716e9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4716ec: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004716ef: { // 0x4716ef: f687240100003f TEST byte ptr [EDI + 0x124],0x3f
    (void)integer::logical((m.r8((s.di+0x00000124u)))&(0x0000003fu),8,flags);
  }
  { // 0x4716f6: 0f8434feffff JZ 0x00471530
    if(integer::condition("JZ",flags)) goto L00471530;
  }
  L004716fc: { // 0x4716fc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4716fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4716fe: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4716ff: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x471701: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x471702: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x471705: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00471708: { // 0x471708: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x47170a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47170b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x471710: e81b5e0e00 CALL 0x00557530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557530u,4658965u); flags=s.arithmetic_flags;
  }
  { // 0x471715: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471717: 0f8444feffff JZ 0x00471561
    if(integer::condition("JZ",flags)) goto L00471561;
  }
  L0047171d: { // 0x47171d: 8b4f44 MOV ECX,dword ptr [EDI + 0x44]
    s.cx = m.r32((s.di+0x00000044u));
  }
  { // 0x471720: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x471723: 0f8434010000 JZ 0x0047185d
    if(integer::condition("JZ",flags)) goto L0047185d;
  }
  { // 0x471729: 8b4750 MOV EAX,dword ptr [EDI + 0x50]
    s.ax = m.r32((s.di+0x00000050u));
  }
  { // 0x47172c: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x47172e: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x471730: 7c09 JL 0x0047173b
    if(integer::condition("JL",flags)) goto L0047173b;
  }
  { // 0x471732: 8b15cca5a100 MOV EDX,dword ptr [0x00a1a5cc]
    s.dx = m.r32((0x00a1a5ccu));
  }
  { // 0x471738: 8b3482 MOV ESI,dword ptr [EDX + EAX*0x4]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0047173b: { // 0x47173b: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  { // 0x471741: 83f902 CMP ECX,0x2
    (void)integer::sub(s.cx,0x00000002u,32,flags);
  }
  { // 0x471744: 7404 JZ 0x0047174a
    if(integer::condition("JZ",flags)) goto L0047174a;
  }
  { // 0x471746: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  { // 0x471748: 7549 JNZ 0x00471793
    if(integer::condition("JNZ",flags)) goto L00471793;
  }
  L0047174a: { // 0x47174a: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x47174e: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x471750: 7441 JZ 0x00471793
    if(integer::condition("JZ",flags)) goto L00471793;
  }
  { // 0x471752: 8b80ec0b0000 MOV EAX,dword ptr [EAX + 0xbec]
    s.ax = m.r32((s.ax+0x00000becu));
  }
  { // 0x471758: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x47175a: 7411 JZ 0x0047176d
    if(integer::condition("JZ",flags)) goto L0047176d;
  }
  { // 0x47175c: 398864020000 CMP dword ptr [EAX + 0x264],ECX
    (void)integer::sub(m.r32((s.ax+0x00000264u)),s.cx,32,flags);
  }
  { // 0x471762: 7509 JNZ 0x0047176d
    if(integer::condition("JNZ",flags)) goto L0047176d;
  }
  { // 0x471764: 80bf1e01000010 CMP byte ptr [EDI + 0x11e],0x10
    (void)integer::sub(m.r8((s.di+0x0000011eu)),0x00000010u,8,flags);
  }
  { // 0x47176b: 731c JNC 0x00471789
    if(integer::condition("JNC",flags)) goto L00471789;
  }
  L0047176d: { // 0x47176d: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x471771: 3b828c070000 CMP EAX,dword ptr [EDX + 0x78c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000078cu)),32,flags);
  }
  { // 0x471777: 7410 JZ 0x00471789
    if(integer::condition("JZ",flags)) goto L00471789;
  }
  { // 0x471779: 3b827c070000 CMP EAX,dword ptr [EDX + 0x77c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000077cu)),32,flags);
  }
  { // 0x47177f: 7408 JZ 0x00471789
    if(integer::condition("JZ",flags)) goto L00471789;
  }
  { // 0x471781: 3b8280070000 CMP EAX,dword ptr [EDX + 0x780]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000780u)),32,flags);
  }
  { // 0x471787: 750a JNZ 0x00471793
    if(integer::condition("JNZ",flags)) goto L00471793;
  }
  L00471789: { // 0x471789: 3b742424 CMP ESI,dword ptr [ESP + 0x24]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000024u)),32,flags);
  }
  { // 0x47178d: 0f846d010000 JZ 0x00471900
    if(integer::condition("JZ",flags)) goto L00471900;
  }
  L00471793: { // 0x471793: 83f91a CMP ECX,0x1a
    (void)integer::sub(s.cx,0x0000001au,32,flags);
  }
  { // 0x471796: 7547 JNZ 0x004717df
    if(integer::condition("JNZ",flags)) goto L004717df;
  }
  { // 0x471798: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x47179c: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x47179e: 0f8493000000 JZ 0x00471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  { // 0x4717a4: 8b80ec0b0000 MOV EAX,dword ptr [EAX + 0xbec]
    s.ax = m.r32((s.ax+0x00000becu));
  }
  { // 0x4717aa: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x4717ac: 7411 JZ 0x004717bf
    if(integer::condition("JZ",flags)) goto L004717bf;
  }
  { // 0x4717ae: 398864020000 CMP dword ptr [EAX + 0x264],ECX
    (void)integer::sub(m.r32((s.ax+0x00000264u)),s.cx,32,flags);
  }
  { // 0x4717b4: 7509 JNZ 0x004717bf
    if(integer::condition("JNZ",flags)) goto L004717bf;
  }
  { // 0x4717b6: 80bf1e01000010 CMP byte ptr [EDI + 0x11e],0x10
    (void)integer::sub(m.r8((s.di+0x0000011eu)),0x00000010u,8,flags);
  }
  { // 0x4717bd: 7316 JNC 0x004717d5
    if(integer::condition("JNC",flags)) goto L004717d5;
  }
  L004717bf: { // 0x4717bf: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x4717c3: 8b9a84070000 MOV EBX,dword ptr [EDX + 0x784]
    s.bx = m.r32((s.dx+0x00000784u));
  }
  { // 0x4717c9: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x4717cb: 7408 JZ 0x004717d5
    if(integer::condition("JZ",flags)) goto L004717d5;
  }
  { // 0x4717cd: 3b8288070000 CMP EAX,dword ptr [EDX + 0x788]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000788u)),32,flags);
  }
  { // 0x4717d3: 750a JNZ 0x004717df
    if(integer::condition("JNZ",flags)) goto L004717df;
  }
  L004717d5: { // 0x4717d5: 3b742424 CMP ESI,dword ptr [ESP + 0x24]
    (void)integer::sub(s.si,m.r32((f.sp+0x00000024u)),32,flags);
  }
  { // 0x4717d9: 0f8421010000 JZ 0x00471900
    if(integer::condition("JZ",flags)) goto L00471900;
  }
  L004717df: { // 0x4717df: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x4717e3: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  { // 0x4717e5: 7450 JZ 0x00471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  { // 0x4717e7: 8a9059130000 MOV DL,byte ptr [EAX + 0x1359]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00001359u)));
  }
  { // 0x4717ed: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  { // 0x4717ef: 7446 JZ 0x00471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  { // 0x4717f1: 83f97e CMP ECX,0x7e
    (void)integer::sub(s.cx,0x0000007eu,32,flags);
  }
  { // 0x4717f4: 740a JZ 0x00471800
    if(integer::condition("JZ",flags)) goto L00471800;
  }
  { // 0x4717f6: e8352f1600 CALL 0x005d4730
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d4730u,4659195u); flags=s.arithmetic_flags;
  }
  { // 0x4717fb: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x4717fe: 7437 JZ 0x00471837
    if(integer::condition("JZ",flags)) goto L00471837;
  }
  L00471800: { // 0x471800: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  { // 0x471806: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x471808: c1e908 SHR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::right);
  }
  { // 0x47180b: f6c101 TEST CL,0x1
    (void)integer::logical(((s.cx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x47180e: 0f854dfdffff JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  { // 0x471814: f6c404 TEST AH,0x4
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  { // 0x471817: 0f8544fdffff JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  { // 0x47181d: 8a871c010000 MOV AL,byte ptr [EDI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  { // 0x471823: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471825: 0f84d5000000 JZ 0x00471900
    if(integer::condition("JZ",flags)) goto L00471900;
  }
  { // 0x47182b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x47182c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x47182d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x47182e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x471830: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x471831: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x471834: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00471837: { // 0x471837: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  { // 0x47183c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47183e: 0f841dfdffff JZ 0x00471561
    if(integer::condition("JZ",flags)) goto L00471561;
  }
  { // 0x471844: 8b5744 MOV EDX,dword ptr [EDI + 0x44]
    s.dx = m.r32((s.di+0x00000044u));
  }
  { // 0x471847: a11ce1a100 MOV EAX,[0x00a1e11c]
    s.ax = m.r32((0x00a1e11cu));
  }
  { // 0x47184c: 8b0c90 MOV ECX,dword ptr [EAX + EDX*0x4]
    s.cx = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  { // 0x47184f: 8a8178020000 MOV AL,byte ptr [ECX + 0x278]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000278u)));
  }
  { // 0x471855: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471857: 0f8504fdffff JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L0047185d: { // 0x47185d: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x471861: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x471864: 7577 JNZ 0x004718dd
    if(integer::condition("JNZ",flags)) goto L004718dd;
  }
  { // 0x471866: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  { // 0x47186c: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x47186e: c1ea08 SHR EDX,0x8
    s.dx = integer::shift(s.dx,0x00000008u,32,flags,integer::Shift::right);
  }
  { // 0x471871: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x471874: 0f85e7fcffff JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  { // 0x47187a: f6c404 TEST AH,0x4
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000004u),8,flags);
  }
  { // 0x47187d: 0f85defcffff JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  { // 0x471883: 8a871c010000 MOV AL,byte ptr [EDI + 0x11c]
    s.ax = with_al(s.ax, m.r8((s.di+0x0000011cu)));
  }
  { // 0x471889: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x47188b: 0f85d0fcffff JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  { // 0x471891: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x471895: 8a88da0a0000 MOV CL,byte ptr [EAX + 0xada]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000adau)));
  }
  { // 0x47189b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x47189d: 7424 JZ 0x004718c3
    if(integer::condition("JZ",flags)) goto L004718c3;
  }
  { // 0x47189f: 8b4738 MOV EAX,dword ptr [EDI + 0x38]
    s.ax = m.r32((s.di+0x00000038u));
  }
  { // 0x4718a2: 8b0db8a1a300 MOV ECX,dword ptr [0x00a3a1b8]
    s.cx = m.r32((0x00a3a1b8u));
  }
  { // 0x4718a8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4718aa: 0f8cb1fcffff JL 0x00471561
    if(integer::condition("JL",flags)) goto L00471561;
  }
  { // 0x4718b0: 83c10e ADD ECX,0xe
    s.cx = integer::add(s.cx,0x0000000eu,32,flags);
  }
  { // 0x4718b3: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x4718b5: 7c49 JL 0x00471900
    if(integer::condition("JL",flags)) goto L00471900;
  }
  { // 0x4718b7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4718b8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4718b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4718ba: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x4718bc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4718bd: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4718c0: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004718c3: { // 0x4718c3: 8b87ec000000 MOV EAX,dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  { // 0x4718c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4718ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4718cb: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4718cc: 8d0cc0 LEA ECX,[EAX + EAX*0x8]
    s.cx = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x4718cf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4718d0: 8a048df0918300 MOV AL,byte ptr [ECX*0x4 + 0x8391f0]
    s.ax = with_al(s.ax, m.r8(((s.cx * 0x00000004u)+0x008391f0u)));
  }
  { // 0x4718d7: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x4718da: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L004718dd: { // 0x4718dd: 8b87ec000000 MOV EAX,dword ptr [EDI + 0xec]
    s.ax = m.r32((s.di+0x000000ecu));
  }
  { // 0x4718e3: 8d14c1 LEA EDX,[ECX + EAX*0x8]
    s.dx = (s.cx+(s.ax * 0x00000008u));
  }
  { // 0x4718e6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x4718e8: d90485d0918300 FLD float ptr [EAX*0x4 + 0x8391d0]
    const auto address=((s.ax * 0x00000004u)+0x008391d0u);
    s.fp.load32(m.r32(address));
  }
  { // 0x4718ef: d81d38577800 FCOMP float ptr [0x00785738]
    const auto address=(0x00785738u);
    s.fp.compare_pop32(m.r32(address));
  }
  { // 0x4718f5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  { // 0x4718f7: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  { // 0x4718fa: 0f8561fcffff JNZ 0x00471561
    if(integer::condition("JNZ",flags)) goto L00471561;
  }
  L00471900: { // 0x471900: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x471901: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x471902: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x471903: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x471905: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x471906: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x471909: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00071260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x471260: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x471261: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x471263: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  { // 0x471266: 83ec34 SUB ESP,0x34
    f.sp = integer::sub(f.sp,0x00000034u,32,flags);
  }
  { // 0x471269: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  { // 0x47126c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x47126d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x47126e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x47126f: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x471271: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x471273: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  { // 0x471277: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  { // 0x47127b: 8d3cc500000000 LEA EDI,[EAX*0x8 + 0x0]
    s.di = ((s.ax * 0x00000008u)+0x00000000u);
  }
  { // 0x471282: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x471284: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  { // 0x471287: 8d1cc500000000 LEA EBX,[EAX*0x8 + 0x0]
    s.bx = ((s.ax * 0x00000008u)+0x00000000u);
  }
  { // 0x47128e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x471290: 8a450c MOV AL,byte ptr [EBP + 0xc]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000000cu)));
  }
  { // 0x471293: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x471295: 7408 JZ 0x0047129f
    if(integer::condition("JZ",flags)) goto L0047129f;
  }
  { // 0x471297: 8b89e8000000 MOV ECX,dword ptr [ECX + 0xe8]
    s.cx = m.r32((s.cx+0x000000e8u));
  }
  { // 0x47129d: eb06 JMP 0x004712a5
    goto L004712a5;
  }
  L0047129f: { // 0x47129f: 8b89e4000000 MOV ECX,dword ptr [ECX + 0xe4]
    s.cx = m.r32((s.cx+0x000000e4u));
  }
  L004712a5: { // 0x4712a5: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x4712a7: 0f84a2000000 JZ 0x0047134f
    if(integer::condition("JZ",flags)) goto L0047134f;
  }
  { // 0x4712ad: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x4712af: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x4712b1: 0f8480000000 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  L004712b7: { // 0x4712b7: 8a4614 MOV AL,byte ptr [ESI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000014u)));
  }
  { // 0x4712ba: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  { // 0x4712bc: 88442413 MOV byte ptr [ESP + 0x13],AL
    m.w8((f.sp+0x00000013u), (s.ax & 0xffu));
  }
  { // 0x4712c0: 7475 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  { // 0x4712c2: 3b7510 CMP ESI,dword ptr [EBP + 0x10]
    (void)integer::sub(s.si,m.r32((s.bp+0x00000010u)),32,flags);
  }
  { // 0x4712c5: 7470 JZ 0x00471337
    if(integer::condition("JZ",flags)) goto L00471337;
  }
  { // 0x4712c7: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x4712c9: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  { // 0x4712cd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4712ce: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x4712d0: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4657875u); flags=s.arithmetic_flags;
  }
  { // 0x4712d3: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x4712d5: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x4712d8: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x4712da: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4712df: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  { // 0x4712e2: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x4712e4: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  { // 0x4712ea: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  { // 0x4712ee: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  { // 0x4712f0: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  { // 0x4712f3: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  { // 0x4712f7: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  { // 0x4712fb: db442428 FILD dword ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load_integer32(m.r32(address));
  }
  { // 0x4712ff: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  { // 0x471303: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  { // 0x471305: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  { // 0x471307: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  { // 0x471309: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  { // 0x47130b: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  { // 0x47130d: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  { // 0x471310: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  { // 0x471312: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  { // 0x471314: e8678d0400 CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,4657945u); flags=s.arithmetic_flags;
  }
  { // 0x471319: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x47131c: e82f972f00 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,4657953u); flags=s.arithmetic_flags;
  }
  { // 0x471321: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x471325: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x471327: 7406 JZ 0x0047132f
    if(integer::condition("JZ",flags)) goto L0047132f;
  }
  { // 0x471329: 3b442418 CMP EAX,dword ptr [ESP + 0x18]
    (void)integer::sub(s.ax,m.r32((f.sp+0x00000018u)),32,flags);
  }
  { // 0x47132d: 7d08 JGE 0x00471337
    if(integer::condition("JGE",flags)) goto L00471337;
  }
  L0047132f: { // 0x47132f: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  { // 0x471333: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00471337: { // 0x471337: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x47133a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x47133c: 0f8575ffffff JNZ 0x004712b7
    if(integer::condition("JNZ",flags)) goto L004712b7;
  }
  { // 0x471342: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x471346: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x471347: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x471348: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x471349: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  { // 0x47134b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x47134c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0047134f: { // 0x47134f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x471351: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x471352: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x471353: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x471354: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  { // 0x471356: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x471357: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00071360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x00471360: a0a885a200 MOV AL,[0x00a285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  { // 0x00471365: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x00471366: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x00471368: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x00471369: 7430 JZ 0x0047139b
    if(integer::condition("JZ",flags)) goto L0047139b;
  }
  { // 0x0047136b: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  { // 0x0047136f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x00471371: 7408 JZ 0x0047137b
    if(integer::condition("JZ",flags)) goto L0047137b;
  }
  { // 0x00471373: 8bb1e8000000 MOV ESI,dword ptr [ECX + 0xe8]
    s.si = m.r32((s.cx+0x000000e8u));
  }
  { // 0x00471379: eb06 JMP 0x00471381
    goto L00471381;
  }
  L0047137b: { // 0x0047137b: 8bb1e4000000 MOV ESI,dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L00471381: { // 0x00471381: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x00471383: 7416 JZ 0x0047139b
    if(integer::condition("JZ",flags)) goto L0047139b;
  }
  { // 0x00471385: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00471389: { // 0x00471389: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x0047138b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x0047138d: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4658064u); flags=s.arithmetic_flags;
  }
  { // 0x00471390: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x00471392: 740e JZ 0x004713a2
    if(integer::condition("JZ",flags)) goto L004713a2;
  }
  { // 0x00471394: 8b7630 MOV ESI,dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  { // 0x00471397: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x00471399: 75ee JNZ 0x00471389
    if(integer::condition("JNZ",flags)) goto L00471389;
  }
  L0047139b: { // 0x0047139b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x0047139c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x0047139e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x0047139f: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L004713a2: { // 0x004713a2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x004713a4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x004713a5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x004713a6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00157530(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x557530: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x557534: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x557535: 8a5c240c MOV BL,byte ptr [ESP + 0xc]
    s.bx = with_al(s.bx, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x557539: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x55753a: 0fbf5026 MOVSX EDX,word ptr [EAX + 0x26]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000026u)),16));
  }
  { // 0x55753e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x55753f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x557541: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x557542: 0fbf7824 MOVSX EDI,word ptr [EAX + 0x24]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000024u)),16));
  }
  { // 0x557546: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x557548: 742b JZ 0x00557575
    if(integer::condition("JZ",flags)) goto L00557575;
  }
  { // 0x55754a: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  { // 0x557550: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  { // 0x557557: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x557559: 741a JZ 0x00557575
    if(integer::condition("JZ",flags)) goto L00557575;
  }
  { // 0x55755b: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  { // 0x557561: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  { // 0x557567: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  { // 0x55756b: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  { // 0x55756e: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x557570: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  { // 0x557572: 7d01 JGE 0x00557575
    if(integer::condition("JGE",flags)) goto L00557575;
  }
  { // 0x557574: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00557575: { // 0x557575: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  { // 0x55757b: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  { // 0x557581: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  { // 0x557584: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  { // 0x557587: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  { // 0x557589: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  { // 0x55758b: 7e49 JLE 0x005575d6
    if(integer::condition("JLE",flags)) goto L005575d6;
  }
  { // 0x55758d: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  { // 0x557593: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  { // 0x557599: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  { // 0x55759b: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  { // 0x55759f: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  { // 0x5575a1: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  { // 0x5575a4: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x5575a6: 7f2e JG 0x005575d6
    if(integer::condition("JG",flags)) goto L005575d6;
  }
  { // 0x5575a8: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  { // 0x5575ae: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  { // 0x5575b4: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  { // 0x5575b6: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  { // 0x5575b8: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  { // 0x5575ba: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x5575bc: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  { // 0x5575be: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x5575c0: 7d14 JGE 0x005575d6
    if(integer::condition("JGE",flags)) goto L005575d6;
  }
  { // 0x5575c2: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  { // 0x5575c5: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x5575c7: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5575c9: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  { // 0x5575cb: 7d09 JGE 0x005575d6
    if(integer::condition("JGE",flags)) goto L005575d6;
  }
  { // 0x5575cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5575ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5575cf: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5575d0: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5575d2: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5575d3: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L005575d6: { // 0x5575d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5575d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5575d8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x5575d9: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5575db: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5575dc: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 0x0069b8d0u:f_0029b8d0(m,s,child,{});break;
case 0x00697d80u:f_00297d80(m,s,child,{});break;
case 0x00697fb0u:f_00297fb0(m,s,child,{});break;
case 0x006a1ea0u:f_002a1ea0(m,s,child,{});break;
case 0x004714b0u:f_000714b0(m,s,child,{});break;
case 0x00471260u:f_00071260(m,s,child,{});break;
case 0x00471360u:f_00071360(m,s,child,{});break;
case 0x00557530u:f_00157530(m,s,child,{});break;
case 4844496u:f_0009ebd0(m,s,child,{});break;
case 4373712u:f_0002bcd0(m,s,child,{});break;
case 4845904u:f_0009f150(m,s,child,{});break;
case 4424000u:f_00038140(m,s,child,{});break;
case 4424336u:f_00038290(m,s,child,{});break;
case 4741952u:f_00085b40(m,s,child,{});break;
case 4411264u:f_00034f80(m,s,child,{});break;
case 7736016u:f_00360ad0(m,s,child,{});break;
case 4412448u:f_00035420(m,s,child,{});break;
case 4412416u:f_00035400(m,s,child,{});break;
case 4264816u:f_00011370(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264592u:f_00011290(m,s,child,{});break;
case 7740544u:f_00361c80(m,s,child,{});break;
case 4264496u:f_00011230(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 4744288u:f_00086460(m,s,child,{});break;
default:throw std::domain_error("recovery241 unreviewed original call");}
f.sp=child.sp;
}
}



namespace {
void domain(Memory&m,const Inputs&i){
 auto need=[](bool x,const char*s){if(!x)throw std::domain_error(s);};
 need(i.fp.image.word(4)==0&&i.fp.image.word(8)==0xffff,"1500 requires empty TOP0/SW0 stack before execution");
 constexpr unsigned short controls[]{0x037f,0x077f,0x0b7f,0x0f7f,0x027f,0x067f,0x0a7f,0x0e7f,0x007f,0x047f,0x087f,0x0c7f};bool valid=false;for(auto c:controls)valid|=i.fp.image.word(0)==c;need(valid,"1500 twelve predeclared masked controlwords");
 const U a=i.cx-0x1000,t=a+0x7000,overlay=a+0xb000,house=a+0x120000;
 need(i.arg[0]<=1&&i.arg[1]==((60u<<16)|60)&&m.r32(i.cx+0xb0)==30&&m.r32(i.cx+0xb4)==1784,"1500 exact caller/camera projection");
 need(m.r32(0x81b9c0)==a+0x6000&&m.r32(a+0x6418)==t&&m.r32(0x81b9c4)==t&&m.r32(t)==0x7881f8&&m.r32(t+0xbec)==overlay&&m.r32(t+0x504)==0x200&&m.r32(t+0x5a4)==0&&m.r32(t+0xbf0)==0&&m.r8(t+0x1351)==0&&m.r8(t+0x1358)==0&&m.r8(t+0x1359)==0,"1500 original configured ToOverlay/fresh query fields");
 need(m.r32(overlay)==0x7929c8&&m.r32(overlay+0x264)==0&&m.r8(overlay+0x278)==1&&m.r32(0xa1e11c)==a+0xd000&&m.r32(0xa1e120)==4&&m.r32(0xa1e128)==1&&m.r32(a+0xd000)==overlay,"1500 real Wall Yes registryindex0 overlay");
 constexpr char name[]="WallType";for(U k=0;k<sizeof(name);++k)need(m.r8(overlay+0x24+k)==U(name[k]),"1500 actual nonempty registered name");
 need(m.r32(0xa1e0e4)==house&&m.r32(house+0x30)==2&&m.r32(0x81b9c8)==2,"1500 actual stable currentHouse property/publication, not equal-zero fiction");
 need(m.r32(0xa283c4)==0&&m.r8(0xa28953)==0&&m.r8(0xa285a8)==1&&m.r32(0x81a958)==a+0x10000,"1500 normal active query/map");
 need(m.r32(0x81a910)==64&&m.r32(0x81a918)==0&&m.r32(0x81a91c)==0&&m.r32(0x81a920)==64&&m.r32(0x81a924)==64&&m.r32(0x8391d0)==0x3f800000&&m.r32(0x785738)==0,"1500 actual map64 geometry and B179 coefficient1");
 const int dx[]{0,1,0,-1},dy[]{-1,0,1,0};for(U d=0;d<4;++d){need(m.r16(0x839da0+d*8)==U(dx[d]&65535)&&m.r16(0x839da2+d*8)==U(dy[d]&65535),"1500 borrowed cardinal table");for(U step=1;step<=2;++step){U x=60+dx[d]*int(step),y=60+dy[d]*int(step),c=a+0xa000+(d*2+step-1)*0x200;const bool endpoint=d==0&&step==2;need(m.r32(a+0x10000+(y*512+x)*4)==c&&m.r32(c)==0x788b04&&m.r16(c+0x24)==x&&m.r16(c+0x26)==y&&m.r32(c+0x44)==(endpoint?0u:0xffffffffu)&&m.r32(c+0x50)==(endpoint?2u:0xffffffffu)&&m.r32(c+0xec)==0&&m.r32(c+0xe4)==0&&m.r32(c+0xe8)==0&&m.r8(c+0x124)==0&&m.r8(c+0x11b)==0&&m.r8(c+0x11c)==0,"1500 constructor clearcell and actual matching placed wall/owner");}}
 need(m.r32(0x81a704)==a+0x4000&&m.r32(0x821c9c)==a+0x2000&&m.r32(0x83a944)==a+0x5000&&m.r32(0x821fac)==0&&m.r32(0x8198f4)==0,"1500 same genuine renderer without auxiliary rings");
 need(m.r32(a+0x40dc)==a+0x3000&&m.r32(a+0x3000)==0x7894ac&&m.r32(0x7894b0)==0x486460&&m.r32(a+0x3004)==a+0x5600&&m.r32(a+0x3008)==a+0x5700&&m.r32(a+0x4008)!=0,"1500 actual original DC decoder");
 need(m.r32(0x7bebac)==0x3000&&m.r32(0x7c3a04)==0xe7f&&read64(m,0xaa5f90)==0&&read64(m,0x785728)==0x3fe0000000000000ull,"1500 exact immutable flag/FP literals");
 need(m.r32(a+0x2000)==0x785ef8&&m.r32(a+0x2004)==1&&m.r32(a+0x2008)==1&&m.r32(a+0x2010)==1&&m.r32(a+0x2014)==a+0x5500&&m.r32(a+0x2018)==1&&m.r8(a+0x201c)==1,"1500 genuine one-byte BSurface");
 need(m.r32(0x821970)==0&&m.r32(0x821974)==0&&m.r32(0x821978)==1&&m.r32(0x82197c)==1,"1500 nonempty one-pixel clip");
 need(m.r16(a+0x5002)==1&&m.r16(a+0x5004)==1&&m.r16(a+0x5006)==1&&m.r16(a+0x5008)==0&&m.r16(a+0x500a)==0&&m.r16(a+0x500c)==1&&m.r16(a+0x500e)==1&&m.r8(a+0x5010)==2&&m.r32(a+0x501c)==0x100&&m.r16(a+0x5100)==3&&m.r8(a+0x5102)>=1&&m.r8(a+0x5102)<=211,"1500 genuine one-frame RLE literal");
 for(U k=0;k<256;++k)need(m.r8(a+0x5600+k)==((k+7)&255)&&m.r8(a+0x5700+k)==((k+37)&255),"1500 two bounded remaps");
}
}
U fun_0069b8d0(Memory&original,const Inputs&i){
 domain(original,i);std::array<std::uint8_t,0x8000>stack{};constexpr U base=0x7d000000,entry=base+0x6004;leaf::Memory local(stack.data(),base,stack.size());Memory m=original;m.add(local);State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.bx=0x13579bdf;s.si=0x2468ace0;s.di=0x789abcde;s.bp=0x89abcdef;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry,entry,0x76543210};m.w32(entry,f.outer_return);for(U k=0;k<16;++k)m.w32(entry+4+4*k,i.arg[k]);f_0029b8d0(m,s,f,{});if(s.bx!=0x13579bdf||s.si!=0x2468ace0||s.di!=0x789abcde||s.bp!=0x89abcdef||f.sp!=entry+12)throw std::runtime_error("1500 source saved-register/RET8 mismatch");i.fp=s.fp;for(U k=0;k<16;++k)i.arg[k]=m.r32(entry+4+4*k);return s.ax;
}
}
