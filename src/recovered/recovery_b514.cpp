#include "recovery_b514.hpp"
#include "recovery_b238_machine.hpp"
#include "recovery_b240_machine.hpp"
#include <limits>

namespace ra2::recovered::b514_238 {
using namespace recovery_b238;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_0009ebd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049ebd0: { // 0x49ebd0: 83ec6c SUB ESP,0x6c
    f.sp = integer::sub(f.sp,0x0000006cu,32,flags);
  }
  L0049ebd3: { // 0x49ebd3: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    s.ax = m.r32((f.sp+0x00000084u));
  }
  L0049ebda: { // 0x49ebda: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0049ebdb: { // 0x49ebdb: 8b5c2474 MOV EBX,dword ptr [ESP + 0x74]
    s.bx = m.r32((f.sp+0x00000074u));
  }
  L0049ebdf: { // 0x49ebdf: 89827c010000 MOV dword ptr [EDX + 0x17c],EAX
    m.w32((s.dx+0x0000017cu), s.ax);
  }
  L0049ebe5: { // 0x49ebe5: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    s.ax = m.r32((f.sp+0x0000007cu));
  }
  L0049ebe9: { // 0x49ebe9: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0049ebed: { // 0x49ebed: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ebf1: { // 0x49ebf1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ebf2: { // 0x49ebf2: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0049ebf4: { // 0x49ebf4: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0049ebf7: { // 0x49ebf7: 0fbf4306 MOVSX EAX,word ptr [EBX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000006u)),16));
  }
  L0049ebfb: { // 0x49ebfb: 8b6c247c MOV EBP,dword ptr [ESP + 0x7c]
    s.bp = m.r32((f.sp+0x0000007cu));
  }
  L0049ebff: { // 0x49ebff: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ec00: { // 0x49ec00: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0049ec02: { // 0x49ec02: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049ec03: { // 0x49ec03: 898c2488000000 MOV dword ptr [ESP + 0x88],ECX
    m.w32((f.sp+0x00000088u), s.cx);
  }
  L0049ec0a: { // 0x49ec0a: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ec0e: { // 0x49ec0e: 7337 JNC 0x0049ec47
    if(integer::condition("JNC",flags)) goto L0049ec47;
  }
  L0049ec10: { // 0x49ec10: 8d4c6d00 LEA ECX,[EBP + EBP*0x2]
    s.cx = (s.bp+(s.bp * 0x00000002u));
  }
  L0049ec14: { // 0x49ec14: 8d44cb08 LEA EAX,[EBX + ECX*0x8 + 0x8]
    s.ax = (s.bx+(s.cx * 0x00000008u)+0x00000008u);
  }
  L0049ec18: { // 0x49ec18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec1a: { // 0x49ec1a: 742b JZ 0x0049ec47
    if(integer::condition("JZ",flags)) goto L0049ec47;
  }
  L0049ec1c: { // 0x49ec1c: 0fbf5006 MOVSX EDX,word ptr [EAX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L0049ec20: { // 0x49ec20: 0fbf4804 MOVSX ECX,word ptr [EAX + 0x4]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L0049ec24: { // 0x49ec24: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ec25: { // 0x49ec25: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ec26: { // 0x49ec26: 0fbf5002 MOVSX EDX,word ptr [EAX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L0049ec2a: { // 0x49ec2a: 0fbf00 MOVSX EAX,word ptr [EAX]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0049ec2d: { // 0x49ec2d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ec2e: { // 0x49ec2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049ec2f: { // 0x49ec2f: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L0049ec33: { // 0x49ec33: e898d0f8ff CALL 0x0042bcd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042bcd0u,4844600u); flags=s.arithmetic_flags;
  }
  L0049ec38: { // 0x49ec38: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049ec3a: { // 0x49ec3a: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0049ec3c: { // 0x49ec3c: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0049ec3f: { // 0x49ec3f: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0049ec42: { // 0x49ec42: 8b7a0c MOV EDI,dword ptr [EDX + 0xc]
    s.di = m.r32((s.dx+0x0000000cu));
  }
  L0049ec45: { // 0x49ec45: eb17 JMP 0x0049ec5e
    goto L0049ec5e;
  }
  L0049ec47: { // 0x49ec47: a180ac8300 MOV EAX,[0x0083ac80]
    s.ax = m.r32((0x0083ac80u));
  }
  L0049ec4c: { // 0x49ec4c: 8b0d84ac8300 MOV ECX,dword ptr [0x0083ac84]
    s.cx = m.r32((0x0083ac84u));
  }
  L0049ec52: { // 0x49ec52: 8b3588ac8300 MOV ESI,dword ptr [0x0083ac88]
    s.si = m.r32((0x0083ac88u));
  }
  L0049ec58: { // 0x49ec58: 8b3d8cac8300 MOV EDI,dword ptr [0x0083ac8c]
    s.di = m.r32((0x0083ac8cu));
  }
  L0049ec5e: { // 0x49ec5e: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L0049ec62: { // 0x49ec62: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L0049ec66: { // 0x49ec66: 0fbf4306 MOVSX EAX,word ptr [EBX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000006u)),16));
  }
  L0049ec6a: { // 0x49ec6a: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0049ec6c: { // 0x49ec6c: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0049ec70: { // 0x49ec70: 897c2438 MOV dword ptr [ESP + 0x38],EDI
    m.w32((f.sp+0x00000038u), s.di);
  }
  L0049ec74: { // 0x49ec74: 7318 JNC 0x0049ec8e
    if(integer::condition("JNC",flags)) goto L0049ec8e;
  }
  L0049ec76: { // 0x49ec76: 8d4c6d00 LEA ECX,[EBP + EBP*0x2]
    s.cx = (s.bp+(s.bp * 0x00000002u));
  }
  L0049ec7a: { // 0x49ec7a: 8d44cb08 LEA EAX,[EBX + ECX*0x8 + 0x8]
    s.ax = (s.bx+(s.cx * 0x00000008u)+0x00000008u);
  }
  L0049ec7e: { // 0x49ec7e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec80: { // 0x49ec80: 740c JZ 0x0049ec8e
    if(integer::condition("JZ",flags)) goto L0049ec8e;
  }
  L0049ec82: { // 0x49ec82: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    s.ax = m.r32((s.ax+0x00000014u));
  }
  L0049ec85: { // 0x49ec85: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ec87: { // 0x49ec87: 7405 JZ 0x0049ec8e
    if(integer::condition("JZ",flags)) goto L0049ec8e;
  }
  L0049ec89: { // 0x49ec89: 8d2c18 LEA EBP,[EAX + EBX*0x1]
    s.bp = (s.ax+(s.bx * 0x00000001u));
  }
  L0049ec8c: { // 0x49ec8c: eb02 JMP 0x0049ec90
    goto L0049ec90;
  }
  L0049ec8e: { // 0x49ec8e: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0049ec90: { // 0x49ec90: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L0049ec94: { // 0x49ec94: 0fbf4304 MOVSX EAX,word ptr [EBX + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000004u)),16));
  }
  L0049ec98: { // 0x49ec98: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049ec99: { // 0x49ec99: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ec9a: { // 0x49ec9a: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L0049ec9e: { // 0x49ec9e: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L0049eca2: { // 0x49eca2: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0049eca6: { // 0x49eca6: e8a5040000 CALL 0x0049f150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049f150u,4844715u); flags=s.arithmetic_flags;
  }
  L0049ecab: { // 0x49ecab: 0faff7 IMUL ESI,EDI
    s.si = integer::imul(s.si,s.di,32,flags);
  }
  L0049ecae: { // 0x49ecae: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049ecaf: { // 0x49ecaf: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049ecb0: { // 0x49ecb0: 8d4c2478 LEA ECX,[ESP + 0x78]
    s.cx = (f.sp+0x00000078u);
  }
  L0049ecb4: { // 0x49ecb4: c744247401000000 MOV dword ptr [ESP + 0x74],0x1
    m.w32((f.sp+0x00000074u), 0x00000001u);
  }
  L0049ecbc: { // 0x49ecbc: e87f94f9ff CALL 0x00438140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,4844737u); flags=s.arithmetic_flags;
  }
  L0049ecc1: { // 0x49ecc1: c744245cf85e7800 MOV dword ptr [ESP + 0x5c],0x785ef8
    m.w32((f.sp+0x0000005cu), 0x00785ef8u);
  }
  L0049ecc9: { // 0x49ecc9: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049ecd0: { // 0x49ecd0: 8b9c24ac000000 MOV EBX,dword ptr [ESP + 0xac]
    s.bx = m.r32((f.sp+0x000000acu));
  }
  L0049ecd7: { // 0x49ecd7: 8bb424b0000000 MOV ESI,dword ptr [ESP + 0xb0]
    s.si = m.r32((f.sp+0x000000b0u));
  }
  L0049ecde: { // 0x49ecde: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049ece2: { // 0x49ece2: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ece4: { // 0x49ece4: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0049ece8: { // 0x49ece8: 0f8410010000 JZ 0x0049edfe
    if(integer::condition("JZ",flags)) goto L0049edfe;
  }
  L0049ecee: { // 0x49ecee: 0fbf5106 MOVSX EDX,word ptr [ECX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0049ecf2: { // 0x49ecf2: 8b8424a8000000 MOV EAX,dword ptr [ESP + 0xa8]
    s.ax = m.r32((f.sp+0x000000a8u));
  }
  L0049ecf9: { // 0x49ecf9: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ecfb: { // 0x49ecfb: 7336 JNC 0x0049ed33
    if(integer::condition("JNC",flags)) goto L0049ed33;
  }
  L0049ecfd: { // 0x49ecfd: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ed00: { // 0x49ed00: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ed04: { // 0x49ed04: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed06: { // 0x49ed06: 742b JZ 0x0049ed33
    if(integer::condition("JZ",flags)) goto L0049ed33;
  }
  L0049ed08: { // 0x49ed08: 0fbf4806 MOVSX ECX,word ptr [EAX + 0x6]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L0049ed0c: { // 0x49ed0c: 0fbf5004 MOVSX EDX,word ptr [EAX + 0x4]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L0049ed10: { // 0x49ed10: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ed11: { // 0x49ed11: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ed12: { // 0x49ed12: 0fbf4802 MOVSX ECX,word ptr [EAX + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L0049ed16: { // 0x49ed16: 0fbf10 MOVSX EDX,word ptr [EAX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L0049ed19: { // 0x49ed19: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049ed1a: { // 0x49ed1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ed1b: { // 0x49ed1b: 8d4c245c LEA ECX,[ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L0049ed1f: { // 0x49ed1f: e8accff8ff CALL 0x0042bcd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042bcd0u,4844836u); flags=s.arithmetic_flags;
  }
  L0049ed24: { // 0x49ed24: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0049ed26: { // 0x49ed26: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0049ed28: { // 0x49ed28: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0049ed2b: { // 0x49ed2b: 8b7a08 MOV EDI,dword ptr [EDX + 0x8]
    s.di = m.r32((s.dx+0x00000008u));
  }
  L0049ed2e: { // 0x49ed2e: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0049ed31: { // 0x49ed31: eb17 JMP 0x0049ed4a
    goto L0049ed4a;
  }
  L0049ed33: { // 0x49ed33: a180ac8300 MOV EAX,[0x0083ac80]
    s.ax = m.r32((0x0083ac80u));
  }
  L0049ed38: { // 0x49ed38: 8b0d84ac8300 MOV ECX,dword ptr [0x0083ac84]
    s.cx = m.r32((0x0083ac84u));
  }
  L0049ed3e: { // 0x49ed3e: 8b3d88ac8300 MOV EDI,dword ptr [0x0083ac88]
    s.di = m.r32((0x0083ac88u));
  }
  L0049ed44: { // 0x49ed44: 8b2d8cac8300 MOV EBP,dword ptr [0x0083ac8c]
    s.bp = m.r32((0x0083ac8cu));
  }
  L0049ed4a: { // 0x49ed4a: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  L0049ed4c: { // 0x49ed4c: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0049ed50: { // 0x49ed50: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0049ed54: { // 0x49ed54: 897c2448 MOV dword ptr [ESP + 0x48],EDI
    m.w32((f.sp+0x00000048u), s.di);
  }
  L0049ed58: { // 0x49ed58: 896c244c MOV dword ptr [ESP + 0x4c],EBP
    m.w32((f.sp+0x0000004cu), s.bp);
  }
  L0049ed5c: { // 0x49ed5c: e8f6eb2c00 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4844897u); flags=s.arithmetic_flags;
  }
  L0049ed61: { // 0x49ed61: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0049ed63: { // 0x49ed63: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0049ed66: { // 0x49ed66: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0049ed68: { // 0x49ed68: 747c JZ 0x0049ede6
    if(integer::condition("JZ",flags)) goto L0049ede6;
  }
  L0049ed6a: { // 0x49ed6a: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049ed71: { // 0x49ed71: 8b8424a8000000 MOV EAX,dword ptr [ESP + 0xa8]
    s.ax = m.r32((f.sp+0x000000a8u));
  }
  L0049ed78: { // 0x49ed78: 0fbf5106 MOVSX EDX,word ptr [ECX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0049ed7c: { // 0x49ed7c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ed7e: { // 0x49ed7e: 731d JNC 0x0049ed9d
    if(integer::condition("JNC",flags)) goto L0049ed9d;
  }
  L0049ed80: { // 0x49ed80: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ed83: { // 0x49ed83: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ed87: { // 0x49ed87: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed89: { // 0x49ed89: 7412 JZ 0x0049ed9d
    if(integer::condition("JZ",flags)) goto L0049ed9d;
  }
  L0049ed8b: { // 0x49ed8b: 8b4014 MOV EAX,dword ptr [EAX + 0x14]
    s.ax = m.r32((s.ax+0x00000014u));
  }
  L0049ed8e: { // 0x49ed8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ed90: { // 0x49ed90: 740b JZ 0x0049ed9d
    if(integer::condition("JZ",flags)) goto L0049ed9d;
  }
  L0049ed92: { // 0x49ed92: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0049ed94: { // 0x49ed94: 898424a8000000 MOV dword ptr [ESP + 0xa8],EAX
    m.w32((f.sp+0x000000a8u), s.ax);
  }
  L0049ed9b: { // 0x49ed9b: eb0b JMP 0x0049eda8
    goto L0049eda8;
  }
  L0049ed9d: { // 0x49ed9d: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049eda8: { // 0x49eda8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0049eda9: { // 0x49eda9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049edaa: { // 0x49edaa: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049edac: { // 0x49edac: e89f030000 CALL 0x0049f150
    s.arithmetic_flags=flags; invoke(m,s,f,0x0049f150u,4844977u); flags=s.arithmetic_flags;
  }
  L0049edb1: { // 0x49edb1: 0faffd IMUL EDI,EBP
    s.di = integer::imul(s.di,s.bp,32,flags);
  }
  L0049edb4: { // 0x49edb4: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    s.cx = m.r32((f.sp+0x000000a8u));
  }
  L0049edbb: { // 0x49edbb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0049edbc: { // 0x49edbc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049edbd: { // 0x49edbd: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  L0049edc0: { // 0x49edc0: c7461001000000 MOV dword ptr [ESI + 0x10],0x1
    m.w32((s.si+0x00000010u), 0x00000001u);
  }
  L0049edc7: { // 0x49edc7: e87493f9ff CALL 0x00438140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,4845004u); flags=s.arithmetic_flags;
  }
  L0049edcc: { // 0x49edcc: c706f85e7800 MOV dword ptr [ESI],0x785ef8
    m.w32((s.si), 0x00785ef8u);
  }
  L0049edd2: { // 0x49edd2: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049edd9: { // 0x49edd9: 89b424a8000000 MOV dword ptr [ESP + 0xa8],ESI
    m.w32((f.sp+0x000000a8u), s.si);
  }
  L0049ede0: { // 0x49ede0: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0049ede4: { // 0x49ede4: eb49 JMP 0x0049ee2f
    goto L0049ee2f;
  }
  L0049ede6: { // 0x49ede6: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L0049edea: { // 0x49edea: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049edf1: { // 0x49edf1: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049edfc: { // 0x49edfc: eb31 JMP 0x0049ee2f
    goto L0049ee2f;
  }
  L0049edfe: { // 0x49edfe: 8b1580ac8300 MOV EDX,dword ptr [0x0083ac80]
    s.dx = m.r32((0x0083ac80u));
  }
  L0049ee04: { // 0x49ee04: a184ac8300 MOV EAX,[0x0083ac84]
    s.ax = m.r32((0x0083ac84u));
  }
  L0049ee09: { // 0x49ee09: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L0049ee0d: { // 0x49ee0d: 8b1588ac8300 MOV EDX,dword ptr [0x0083ac88]
    s.dx = m.r32((0x0083ac88u));
  }
  L0049ee13: { // 0x49ee13: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L0049ee17: { // 0x49ee17: a18cac8300 MOV EAX,[0x0083ac8c]
    s.ax = m.r32((0x0083ac8cu));
  }
  L0049ee1c: { // 0x49ee1c: c78424a800000000000000 MOV dword ptr [ESP + 0xa8],0x0
    m.w32((f.sp+0x000000a8u), 0x00000000u);
  }
  L0049ee27: { // 0x49ee27: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L0049ee2b: { // 0x49ee2b: 89442448 MOV dword ptr [ESP + 0x48],EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0049ee2f: { // 0x49ee2f: 8b842490000000 MOV EAX,dword ptr [ESP + 0x90]
    s.ax = m.r32((f.sp+0x00000090u));
  }
  L0049ee36: { // 0x49ee36: f6c402 TEST AH,0x2
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000002u),8,flags);
  }
  L0049ee39: { // 0x49ee39: 7430 JZ 0x0049ee6b
    if(integer::condition("JZ",flags)) goto L0049ee6b;
  }
  L0049ee3b: { // 0x49ee3b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0049ee3f: { // 0x49ee3f: 8bac2488000000 MOV EBP,dword ptr [ESP + 0x88]
    s.bp = m.r32((f.sp+0x00000088u));
  }
  L0049ee46: { // 0x49ee46: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee47: { // 0x49ee47: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee49: { // 0x49ee49: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee4b: { // 0x49ee4b: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049ee4d: { // 0x49ee4d: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L0049ee4f: { // 0x49ee4f: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0049ee53: { // 0x49ee53: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee54: { // 0x49ee54: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee56: { // 0x49ee56: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049ee5a: { // 0x49ee5a: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee5c: { // 0x49ee5c: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049ee5e: { // 0x49ee5e: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0049ee60: { // 0x49ee60: 89ac2488000000 MOV dword ptr [ESP + 0x88],EBP
    m.w32((f.sp+0x00000088u), s.bp);
  }
  L0049ee67: { // 0x49ee67: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049ee6b: { // 0x49ee6b: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  L0049ee6f: { // 0x49ee6f: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L0049ee73: { // 0x49ee73: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ee75: { // 0x49ee75: 7427 JZ 0x0049ee9e
    if(integer::condition("JZ",flags)) goto L0049ee9e;
  }
  L0049ee77: { // 0x49ee77: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0049ee7b: { // 0x49ee7b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee7c: { // 0x49ee7c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee7e: { // 0x49ee7e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049ee80: { // 0x49ee80: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0049ee84: { // 0x49ee84: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0049ee85: { // 0x49ee85: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee87: { // 0x49ee87: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0049ee89: { // 0x49ee89: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L0049ee8b: { // 0x49ee8b: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0049ee8d: { // 0x49ee8d: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0049ee8f: { // 0x49ee8f: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0049ee91: { // 0x49ee91: 8b8c24a4000000 MOV ECX,dword ptr [ESP + 0xa4]
    s.cx = m.r32((f.sp+0x000000a4u));
  }
  L0049ee98: { // 0x49ee98: 895c2424 MOV dword ptr [ESP + 0x24],EBX
    m.w32((f.sp+0x00000024u), s.bx);
  }
  L0049ee9c: { // 0x49ee9c: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0049ee9e: { // 0x49ee9e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049eea2: { // 0x49eea2: 8b9c2488000000 MOV EBX,dword ptr [ESP + 0x88]
    s.bx = m.r32((f.sp+0x00000088u));
  }
  L0049eea9: { // 0x49eea9: 03d5 ADD EDX,EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L0049eeab: { // 0x49eeab: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L0049eead: { // 0x49eead: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0049eeb1: { // 0x49eeb1: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0049eeb3: { // 0x49eeb3: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0049eeb5: { // 0x49eeb5: 899c2488000000 MOV dword ptr [ESP + 0x88],EBX
    m.w32((f.sp+0x00000088u), s.bx);
  }
  L0049eebc: { // 0x49eebc: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0049eec0: { // 0x49eec0: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L0049eec4: { // 0x49eec4: 7473 JZ 0x0049ef39
    if(integer::condition("JZ",flags)) goto L0049ef39;
  }
  L0049eec6: { // 0x49eec6: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    s.di = m.r32((f.sp+0x00000040u));
  }
  L0049eeca: { // 0x49eeca: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L0049eece: { // 0x49eece: 8b5c243c MOV EBX,dword ptr [ESP + 0x3c]
    s.bx = m.r32((f.sp+0x0000003cu));
  }
  L0049eed2: { // 0x49eed2: 03f7 ADD ESI,EDI
    s.si = integer::add(s.si,s.di,32,flags);
  }
  L0049eed4: { // 0x49eed4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0049eed6: { // 0x49eed6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0049eed8: { // 0x49eed8: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0049eeda: { // 0x49eeda: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L0049eede: { // 0x49eede: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049eedf: { // 0x49eedf: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0049eee1: { // 0x49eee1: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0049eee5: { // 0x49eee5: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0049eee9: { // 0x49eee9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049eeea: { // 0x49eeea: 8d542454 LEA EDX,[ESP + 0x54]
    s.dx = (f.sp+0x00000054u);
  }
  L0049eeee: { // 0x49eeee: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L0049eef2: { // 0x49eef2: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  L0049eef6: { // 0x49eef6: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0049eefa: { // 0x49eefa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049eefb: { // 0x49eefb: 8d542438 LEA EDX,[ESP + 0x38]
    s.dx = (f.sp+0x00000038u);
  }
  L0049eeff: { // 0x49eeff: 8d4c2448 LEA ECX,[ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L0049ef03: { // 0x49ef03: 89442460 MOV dword ptr [ESP + 0x60],EAX
    m.w32((f.sp+0x00000060u), s.ax);
  }
  L0049ef07: { // 0x49ef07: e8e40ef8ff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,4845324u); flags=s.arithmetic_flags;
  }
  L0049ef0c: { // 0x49ef0c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0049ef0e: { // 0x49ef0e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0049ef10: { // 0x49ef10: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0049ef14: { // 0x49ef14: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0049ef17: { // 0x49ef17: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0049ef1b: { // 0x49ef1b: 8b4108 MOV EAX,dword ptr [ECX + 0x8]
    s.ax = m.r32((s.cx+0x00000008u));
  }
  L0049ef1e: { // 0x49ef1e: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L0049ef22: { // 0x49ef22: 8b490c MOV ECX,dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L0049ef25: { // 0x49ef25: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef27: { // 0x49ef27: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L0049ef2b: { // 0x49ef2b: 0f8e6b010000 JLE 0x0049f09c
    if(integer::condition("JLE",flags)) goto L0049f09c;
  }
  L0049ef31: { // 0x49ef31: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049ef33: { // 0x49ef33: 0f8e63010000 JLE 0x0049f09c
    if(integer::condition("JLE",flags)) goto L0049f09c;
  }
  L0049ef39: { // 0x49ef39: 8b842494000000 MOV EAX,dword ptr [ESP + 0x94]
    s.ax = m.r32((f.sp+0x00000094u));
  }
  L0049ef40: { // 0x49ef40: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  L0049ef47: { // 0x49ef47: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef49: { // 0x49ef49: 7403 JZ 0x0049ef4e
    if(integer::condition("JZ",flags)) goto L0049ef4e;
  }
  L0049ef4b: { // 0x49ef4b: 83ca10 OR EDX,0x10
    s.dx = integer::logical((s.dx)|(0x00000010u),32,flags);
  }
  L0049ef4e: { // 0x49ef4e: 8b8c2480000000 MOV ECX,dword ptr [ESP + 0x80]
    s.cx = m.r32((f.sp+0x00000080u));
  }
  L0049ef55: { // 0x49ef55: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    s.ax = m.r32((f.sp+0x00000084u));
  }
  L0049ef5c: { // 0x49ef5c: 0fbf7906 MOVSX EDI,word ptr [ECX + 0x6]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.cx+0x00000006u)),16));
  }
  L0049ef60: { // 0x49ef60: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0049ef62: { // 0x49ef62: 0f83a8000000 JNC 0x0049f010
    if(integer::condition("JNC",flags)) goto L0049f010;
  }
  L0049ef68: { // 0x49ef68: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0049ef6b: { // 0x49ef6b: 8d44c108 LEA EAX,[ECX + EAX*0x8 + 0x8]
    s.ax = (s.cx+(s.ax * 0x00000008u)+0x00000008u);
  }
  L0049ef6f: { // 0x49ef6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef71: { // 0x49ef71: 0f8499000000 JZ 0x0049f010
    if(integer::condition("JZ",flags)) goto L0049f010;
  }
  L0049ef77: { // 0x49ef77: 8a4008 MOV AL,byte ptr [EAX + 0x8]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000008u)));
  }
  L0049ef7a: { // 0x49ef7a: d1e8 SHR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::right);
  }
  L0049ef7c: { // 0x49ef7c: 2401 AND AL,0x1
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags));
  }
  L0049ef7e: { // 0x49ef7e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0049ef80: { // 0x49ef80: 0f848a000000 JZ 0x0049f010
    if(integer::condition("JZ",flags)) goto L0049f010;
  }
  L0049ef86: { // 0x49ef86: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0049ef8a: { // 0x49ef8a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049ef8b: { // 0x49ef8b: e8b06bfeff CALL 0x00485b40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485b40u,4845456u); flags=s.arithmetic_flags;
  }
  L0049ef90: { // 0x49ef90: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049ef92: { // 0x49ef92: 0f8404010000 JZ 0x0049f09c
    if(integer::condition("JZ",flags)) goto L0049f09c;
  }
  L0049ef98: { // 0x49ef98: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L0049ef9f: { // 0x49ef9f: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049efa3: { // 0x49efa3: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0049efa7: { // 0x49efa7: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0049efab: { // 0x49efab: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0049efaf: { // 0x49efaf: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0049efb3: { // 0x49efb3: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0049efb7: { // 0x49efb7: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L0049efbb: { // 0x49efbb: 89542458 MOV dword ptr [ESP + 0x58],EDX
    m.w32((f.sp+0x00000058u), s.dx);
  }
  L0049efbf: { // 0x49efbf: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    s.dx = m.r32((f.sp+0x000000a8u));
  }
  L0049efc6: { // 0x49efc6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0049efc7: { // 0x49efc7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049efc8: { // 0x49efc8: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    s.cx = m.r32((f.sp+0x000000a8u));
  }
  L0049efcf: { // 0x49efcf: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efd0: { // 0x49efd0: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    s.dx = m.r32((f.sp+0x000000a8u));
  }
  L0049efd7: { // 0x49efd7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049efd9: { // 0x49efd9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049efda: { // 0x49efda: 8b8c24ac000000 MOV ECX,dword ptr [ESP + 0xac]
    s.cx = m.r32((f.sp+0x000000acu));
  }
  L0049efe1: { // 0x49efe1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efe2: { // 0x49efe2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049efe3: { // 0x49efe3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049efe4: { // 0x49efe4: 8d54244c LEA EDX,[ESP + 0x4c]
    s.dx = (f.sp+0x0000004cu);
  }
  L0049efe8: { // 0x49efe8: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L0049efec: { // 0x49efec: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efed: { // 0x49efed: 8d8c2480000000 LEA ECX,[ESP + 0x80]
    s.cx = (f.sp+0x00000080u);
  }
  L0049eff4: { // 0x49eff4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049eff5: { // 0x49eff5: 8d542474 LEA EDX,[ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L0049eff9: { // 0x49eff9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049effa: { // 0x49effa: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0049effe: { // 0x49effe: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049efff: { // 0x49efff: 8b9424bc000000 MOV EDX,dword ptr [ESP + 0xbc]
    s.dx = m.r32((f.sp+0x000000bcu));
  }
  L0049f006: { // 0x49f006: e8755ff9ff CALL 0x00434f80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434f80u,4845579u); flags=s.arithmetic_flags;
  }
  L0049f00b: { // 0x49f00b: e98c000000 JMP 0x0049f09c
    goto L0049f09c;
  }
  L0049f010: { // 0x49f010: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0049f014: { // 0x49f014: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f015: { // 0x49f015: e86668feff CALL 0x00485880
    s.arithmetic_flags=flags; invoke(m,s,f,0x00485880u,4845594u); flags=s.arithmetic_flags;
  }
  L0049f01a: { // 0x49f01a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0049f01c: { // 0x49f01c: 747e JZ 0x0049f09c
    if(integer::condition("JZ",flags)) goto L0049f09c;
  }
  L0049f01e: { // 0x49f01e: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0049f020: { // 0x49f020: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0049f022: { // 0x49f022: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L0049f026: { // 0x49f026: 8b8c2488000000 MOV ECX,dword ptr [ESP + 0x88]
    s.cx = m.r32((f.sp+0x00000088u));
  }
  L0049f02d: { // 0x49f02d: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L0049f031: { // 0x49f031: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0049f035: { // 0x49f035: 894c243c MOV dword ptr [ESP + 0x3c],ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L0049f039: { // 0x49f039: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L0049f03d: { // 0x49f03d: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L0049f041: { // 0x49f041: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0049f045: { // 0x49f045: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L0049f049: { // 0x49f049: 8b8c24a0000000 MOV ECX,dword ptr [ESP + 0xa0]
    s.cx = m.r32((f.sp+0x000000a0u));
  }
  L0049f050: { // 0x49f050: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L0049f054: { // 0x49f054: 8b94249c000000 MOV EDX,dword ptr [ESP + 0x9c]
    s.dx = m.r32((f.sp+0x0000009cu));
  }
  L0049f05b: { // 0x49f05b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0049f05d: { // 0x49f05d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f05e: { // 0x49f05e: 8b8c24a0000000 MOV ECX,dword ptr [ESP + 0xa0]
    s.cx = m.r32((f.sp+0x000000a0u));
  }
  L0049f065: { // 0x49f065: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  L0049f069: { // 0x49f069: 8b6c246c MOV EBP,dword ptr [ESP + 0x6c]
    s.bp = m.r32((f.sp+0x0000006cu));
  }
  L0049f06d: { // 0x49f06d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f06e: { // 0x49f06e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f06f: { // 0x49f06f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f070: { // 0x49f070: 8d542440 LEA EDX,[ESP + 0x40]
    s.dx = (f.sp+0x00000040u);
  }
  L0049f074: { // 0x49f074: 8d442460 LEA EAX,[ESP + 0x60]
    s.ax = (f.sp+0x00000060u);
  }
  L0049f078: { // 0x49f078: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f079: { // 0x49f079: 8d4c2474 LEA ECX,[ESP + 0x74]
    s.cx = (f.sp+0x00000074u);
  }
  L0049f07d: { // 0x49f07d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0049f07e: { // 0x49f07e: 8d542458 LEA EDX,[ESP + 0x58]
    s.dx = (f.sp+0x00000058u);
  }
  L0049f082: { // 0x49f082: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0049f083: { // 0x49f083: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L0049f087: { // 0x49f087: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0049f088: { // 0x49f088: 8b9424b0000000 MOV EDX,dword ptr [ESP + 0xb0]
    s.dx = m.r32((f.sp+0x000000b0u));
  }
  L0049f08f: { // 0x49f08f: 897c2478 MOV dword ptr [ESP + 0x78],EDI
    m.w32((f.sp+0x00000078u), s.di);
  }
  L0049f093: { // 0x49f093: 896c247c MOV dword ptr [ESP + 0x7c],EBP
    m.w32((f.sp+0x0000007cu), s.bp);
  }
  L0049f097: { // 0x49f097: e86459f9ff CALL 0x00434a00
    s.arithmetic_flags=flags; invoke(m,s,f,0x00434a00u,4845724u); flags=s.arithmetic_flags;
  }
  L0049f09c: { // 0x49f09c: 8b8c24a8000000 MOV ECX,dword ptr [ESP + 0xa8]
    s.cx = m.r32((f.sp+0x000000a8u));
  }
  L0049f0a3: { // 0x49f0a3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0049f0a4: { // 0x49f0a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0049f0a5: { // 0x49f0a5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0049f0a6: { // 0x49f0a6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0049f0a8: { // 0x49f0a8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0049f0a9: { // 0x49f0a9: 7406 JZ 0x0049f0b1
    if(integer::condition("JZ",flags)) goto L0049f0b1;
  }
  L0049f0ab: { // 0x49f0ab: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0049f0ad: { // 0x49f0ad: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0049f0af: { // 0x49f0af: ff10 CALL dword ptr [EAX]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax)),4845745u); flags=s.arithmetic_flags;
  }
  L0049f0b1: { // 0x49f0b1: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L0049f0b5: { // 0x49f0b5: e8d691f9ff CALL 0x00438290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,4845754u); flags=s.arithmetic_flags;
  }
  L0049f0ba: { // 0x49f0ba: 83c46c ADD ESP,0x6c
    f.sp = integer::add(f.sp,0x0000006cu,32,flags);
  }
  L0049f0bd: { // 0x49f0bd: c23400 RET 0x34
    s.arithmetic_flags=flags; finish(m,s,f,52u); return;
  }
}
void f_0002bcd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042bcd0: { // 0x42bcd0: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0042bcd4: { // 0x42bcd4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042bcd6: { // 0x42bcd6: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0042bcda: { // 0x42bcda: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0042bcdc: { // 0x42bcdc: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0042bce0: { // 0x42bce0: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0042bce3: { // 0x42bce3: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0042bce7: { // 0x42bce7: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0042bcea: { // 0x42bcea: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0042bced: { // 0x42bced: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}
void f_0009f150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0049f150: { // 0x49f150: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L0049f154: { // 0x49f154: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0049f156: { // 0x49f156: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0049f15a: { // 0x49f15a: 894804 MOV dword ptr [EAX + 0x4],ECX
    m.w32((s.ax+0x00000004u), s.cx);
  }
  L0049f15d: { // 0x49f15d: 895008 MOV dword ptr [EAX + 0x8],EDX
    m.w32((s.ax+0x00000008u), s.dx);
  }
  L0049f160: { // 0x49f160: c7400c00000000 MOV dword ptr [EAX + 0xc],0x0
    m.w32((s.ax+0x0000000cu), 0x00000000u);
  }
  L0049f167: { // 0x49f167: c7008c5f7800 MOV dword ptr [EAX],0x785f8c
    m.w32((s.ax), 0x00785f8cu);
  }
  L0049f16d: { // 0x49f16d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00038140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438140: { // 0x438140: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00438144: { // 0x438144: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00438145: { // 0x438145: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00438147: { // 0x438147: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0043814b: { // 0x43814b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043814d: { // 0x43814d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0043814f: { // 0x43814f: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00438152: { // 0x438152: c6460800 MOV byte ptr [ESI + 0x8],0x0
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  L00438156: { // 0x438156: 7513 JNZ 0x0043816b
    if(integer::condition("JNZ",flags)) goto L0043816b;
  }
  L00438158: { // 0x438158: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043815a: { // 0x43815a: 7e0f JLE 0x0043816b
    if(integer::condition("JLE",flags)) goto L0043816b;
  }
  L0043815c: { // 0x43815c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043815d: { // 0x43815d: e8f5573300 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4424034u); flags=s.arithmetic_flags;
  }
  L00438162: { // 0x438162: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00438165: { // 0x438165: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00438167: { // 0x438167: c6460801 MOV byte ptr [ESI + 0x8],0x1
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L0043816b: { // 0x43816b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0043816d: { // 0x43816d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043816e: { // 0x43816e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00038290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438290: { // 0x438290: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00438291: { // 0x438291: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00438293: { // 0x438293: 8a4608 MOV AL,byte ptr [ESI + 0x8]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000008u)));
  }
  L00438296: { // 0x438296: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00438298: { // 0x438298: 740b JZ 0x004382a5
    if(integer::condition("JZ",flags)) goto L004382a5;
  }
  L0043829a: { // 0x43829a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0043829c: { // 0x43829c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043829d: { // 0x43829d: e8d9533300 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4424354u); flags=s.arithmetic_flags;
  }
  L004382a2: { // 0x4382a2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L004382a5: { // 0x4382a5: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L004382ab: { // 0x4382ab: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L004382b2: { // 0x4382b2: c6460800 MOV byte ptr [ESI + 0x8],0x0
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  L004382b6: { // 0x4382b6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004382b7: { // 0x4382b7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00085b40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00485b40: { // 0x485b40: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00485b41: { // 0x485b41: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00485b43: { // 0x485b43: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00485b46: { // 0x485b46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00485b48: { // 0x485b48: 7505 JNZ 0x00485b4f
    if(integer::condition("JNZ",flags)) goto L00485b4f;
  }
  L00485b4a: { // 0x485b4a: e891ddffff CALL 0x004838e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004838e0u,4741967u); flags=s.arithmetic_flags;
  }
  L00485b4f: { // 0x485b4f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00485b53: { // 0x485b53: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00485b55: { // 0x485b55: 7458 JZ 0x00485baf
    if(integer::condition("JZ",flags)) goto L00485baf;
  }
  L00485b57: { // 0x485b57: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485b5a: { // 0x485b5a: 7419 JZ 0x00485b75
    if(integer::condition("JZ",flags)) goto L00485b75;
  }
  L00485b5c: { // 0x485b5c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b5f: { // 0x485b5f: 740a JZ 0x00485b6b
    if(integer::condition("JZ",flags)) goto L00485b6b;
  }
  L00485b61: { // 0x485b61: 8b865c010000 MOV EAX,dword ptr [ESI + 0x15c]
    s.ax = m.r32((s.si+0x0000015cu));
  }
  L00485b67: { // 0x485b67: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b68: { // 0x485b68: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b6b: { // 0x485b6b: 8b8610010000 MOV EAX,dword ptr [ESI + 0x110]
    s.ax = m.r32((s.si+0x00000110u));
  }
  L00485b71: { // 0x485b71: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b72: { // 0x485b72: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b75: { // 0x485b75: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485b7b: { // 0x485b7b: 7419 JZ 0x00485b96
    if(integer::condition("JZ",flags)) goto L00485b96;
  }
  L00485b7d: { // 0x485b7d: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b80: { // 0x485b80: 740a JZ 0x00485b8c
    if(integer::condition("JZ",flags)) goto L00485b8c;
  }
  L00485b82: { // 0x485b82: 8b863c010000 MOV EAX,dword ptr [ESI + 0x13c]
    s.ax = m.r32((s.si+0x0000013cu));
  }
  L00485b88: { // 0x485b88: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b89: { // 0x485b89: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b8c: { // 0x485b8c: 8b86ec000000 MOV EAX,dword ptr [ESI + 0xec]
    s.ax = m.r32((s.si+0x000000ecu));
  }
  L00485b92: { // 0x485b92: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485b93: { // 0x485b93: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485b96: { // 0x485b96: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485b99: { // 0x485b99: 740a JZ 0x00485ba5
    if(integer::condition("JZ",flags)) goto L00485ba5;
  }
  L00485b9b: { // 0x485b9b: 8b8628010000 MOV EAX,dword ptr [ESI + 0x128]
    s.ax = m.r32((s.si+0x00000128u));
  }
  L00485ba1: { // 0x485ba1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ba2: { // 0x485ba2: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ba5: { // 0x485ba5: 8b86d8000000 MOV EAX,dword ptr [ESI + 0xd8]
    s.ax = m.r32((s.si+0x000000d8u));
  }
  L00485bab: { // 0x485bab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bac: { // 0x485bac: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485baf: { // 0x485baf: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00485bb1: { // 0x485bb1: 83e106 AND ECX,0x6
    s.cx = integer::logical((s.cx)&(0x00000006u),32,flags);
  }
  L00485bb4: { // 0x485bb4: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bb7: { // 0x485bb7: 0f84b2010000 JZ 0x00485d6f
    if(integer::condition("JZ",flags)) goto L00485d6f;
  }
  L00485bbd: { // 0x485bbd: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc0: { // 0x485bc0: 0f8434010000 JZ 0x00485cfa
    if(integer::condition("JZ",flags)) goto L00485cfa;
  }
  L00485bc6: { // 0x485bc6: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  L00485bc9: { // 0x485bc9: 0f84b6000000 JZ 0x00485c85
    if(integer::condition("JZ",flags)) goto L00485c85;
  }
  L00485bcf: { // 0x485bcf: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00485bd1: { // 0x485bd1: 742b JZ 0x00485bfe
    if(integer::condition("JZ",flags)) goto L00485bfe;
  }
  L00485bd3: { // 0x485bd3: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485bd6: { // 0x485bd6: 740a JZ 0x00485be2
    if(integer::condition("JZ",flags)) goto L00485be2;
  }
  L00485bd8: { // 0x485bd8: 8b8614010000 MOV EAX,dword ptr [ESI + 0x114]
    s.ax = m.r32((s.si+0x00000114u));
  }
  L00485bde: { // 0x485bde: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bdf: { // 0x485bdf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485be2: { // 0x485be2: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485be8: { // 0x485be8: 740a JZ 0x00485bf4
    if(integer::condition("JZ",flags)) goto L00485bf4;
  }
  L00485bea: { // 0x485bea: 8b86f0000000 MOV EAX,dword ptr [ESI + 0xf0]
    s.ax = m.r32((s.si+0x000000f0u));
  }
  L00485bf0: { // 0x485bf0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bf1: { // 0x485bf1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bf4: { // 0x485bf4: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L00485bfa: { // 0x485bfa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485bfb: { // 0x485bfb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485bfe: { // 0x485bfe: a820 TEST AL,0x20
    (void)integer::logical(((s.ax & 0xffu))&(0x00000020u),8,flags);
  }
  L00485c00: { // 0x485c00: 742b JZ 0x00485c2d
    if(integer::condition("JZ",flags)) goto L00485c2d;
  }
  L00485c02: { // 0x485c02: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c05: { // 0x485c05: 740f JZ 0x00485c16
    if(integer::condition("JZ",flags)) goto L00485c16;
  }
  L00485c07: { // 0x485c07: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c0a: { // 0x485c0a: 7435 JZ 0x00485c41
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c0c: { // 0x485c0c: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  L00485c12: { // 0x485c12: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c13: { // 0x485c13: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c16: { // 0x485c16: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c1c: { // 0x485c1c: 744e JZ 0x00485c6c
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c1e: { // 0x485c1e: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c21: { // 0x485c21: 743f JZ 0x00485c62
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c23: { // 0x485c23: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00485c29: { // 0x485c29: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c2a: { // 0x485c2a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c2d: { // 0x485c2d: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c30: { // 0x485c30: 7419 JZ 0x00485c4b
    if(integer::condition("JZ",flags)) goto L00485c4b;
  }
  L00485c32: { // 0x485c32: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c35: { // 0x485c35: 740a JZ 0x00485c41
    if(integer::condition("JZ",flags)) goto L00485c41;
  }
  L00485c37: { // 0x485c37: 8b8658010000 MOV EAX,dword ptr [ESI + 0x158]
    s.ax = m.r32((s.si+0x00000158u));
  }
  L00485c3d: { // 0x485c3d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c3e: { // 0x485c3e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c41: { // 0x485c41: 8b860c010000 MOV EAX,dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L00485c47: { // 0x485c47: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c48: { // 0x485c48: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c4b: { // 0x485c4b: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485c51: { // 0x485c51: 7419 JZ 0x00485c6c
    if(integer::condition("JZ",flags)) goto L00485c6c;
  }
  L00485c53: { // 0x485c53: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c56: { // 0x485c56: 740a JZ 0x00485c62
    if(integer::condition("JZ",flags)) goto L00485c62;
  }
  L00485c58: { // 0x485c58: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00485c5e: { // 0x485c5e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c5f: { // 0x485c5f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c62: { // 0x485c62: 8b86e8000000 MOV EAX,dword ptr [ESI + 0xe8]
    s.ax = m.r32((s.si+0x000000e8u));
  }
  L00485c68: { // 0x485c68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c69: { // 0x485c69: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c6c: { // 0x485c6c: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c6f: { // 0x485c6f: 740a JZ 0x00485c7b
    if(integer::condition("JZ",flags)) goto L00485c7b;
  }
  L00485c71: { // 0x485c71: 8b8624010000 MOV EAX,dword ptr [ESI + 0x124]
    s.ax = m.r32((s.si+0x00000124u));
  }
  L00485c77: { // 0x485c77: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c78: { // 0x485c78: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c7b: { // 0x485c7b: 8b86d0000000 MOV EAX,dword ptr [ESI + 0xd0]
    s.ax = m.r32((s.si+0x000000d0u));
  }
  L00485c81: { // 0x485c81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c82: { // 0x485c82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c85: { // 0x485c85: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485c88: { // 0x485c88: 7419 JZ 0x00485ca3
    if(integer::condition("JZ",flags)) goto L00485ca3;
  }
  L00485c8a: { // 0x485c8a: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485c8d: { // 0x485c8d: 740a JZ 0x00485c99
    if(integer::condition("JZ",flags)) goto L00485c99;
  }
  L00485c8f: { // 0x485c8f: 8b8660010000 MOV EAX,dword ptr [ESI + 0x160]
    s.ax = m.r32((s.si+0x00000160u));
  }
  L00485c95: { // 0x485c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485c96: { // 0x485c96: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485c99: { // 0x485c99: 8b8618010000 MOV EAX,dword ptr [ESI + 0x118]
    s.ax = m.r32((s.si+0x00000118u));
  }
  L00485c9f: { // 0x485c9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ca0: { // 0x485ca0: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ca3: { // 0x485ca3: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485ca9: { // 0x485ca9: 7436 JZ 0x00485ce1
    if(integer::condition("JZ",flags)) goto L00485ce1;
  }
  L00485cab: { // 0x485cab: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cad: { // 0x485cad: 7419 JZ 0x00485cc8
    if(integer::condition("JZ",flags)) goto L00485cc8;
  }
  L00485caf: { // 0x485caf: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485cb2: { // 0x485cb2: 740a JZ 0x00485cbe
    if(integer::condition("JZ",flags)) goto L00485cbe;
  }
  L00485cb4: { // 0x485cb4: 8b864c010000 MOV EAX,dword ptr [ESI + 0x14c]
    s.ax = m.r32((s.si+0x0000014cu));
  }
  L00485cba: { // 0x485cba: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cbb: { // 0x485cbb: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cbe: { // 0x485cbe: 8b8600010000 MOV EAX,dword ptr [ESI + 0x100]
    s.ax = m.r32((s.si+0x00000100u));
  }
  L00485cc4: { // 0x485cc4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cc5: { // 0x485cc5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cc8: { // 0x485cc8: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ccb: { // 0x485ccb: 740a JZ 0x00485cd7
    if(integer::condition("JZ",flags)) goto L00485cd7;
  }
  L00485ccd: { // 0x485ccd: 8b8640010000 MOV EAX,dword ptr [ESI + 0x140]
    s.ax = m.r32((s.si+0x00000140u));
  }
  L00485cd3: { // 0x485cd3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cd4: { // 0x485cd4: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cd7: { // 0x485cd7: 8b86f4000000 MOV EAX,dword ptr [ESI + 0xf4]
    s.ax = m.r32((s.si+0x000000f4u));
  }
  L00485cdd: { // 0x485cdd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cde: { // 0x485cde: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485ce1: { // 0x485ce1: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485ce4: { // 0x485ce4: 740a JZ 0x00485cf0
    if(integer::condition("JZ",flags)) goto L00485cf0;
  }
  L00485ce6: { // 0x485ce6: 8b862c010000 MOV EAX,dword ptr [ESI + 0x12c]
    s.ax = m.r32((s.si+0x0000012cu));
  }
  L00485cec: { // 0x485cec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485ced: { // 0x485ced: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cf0: { // 0x485cf0: 8b86dc000000 MOV EAX,dword ptr [ESI + 0xdc]
    s.ax = m.r32((s.si+0x000000dcu));
  }
  L00485cf6: { // 0x485cf6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485cf7: { // 0x485cf7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485cfa: { // 0x485cfa: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485cfd: { // 0x485cfd: 7419 JZ 0x00485d18
    if(integer::condition("JZ",flags)) goto L00485d18;
  }
  L00485cff: { // 0x485cff: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d02: { // 0x485d02: 740a JZ 0x00485d0e
    if(integer::condition("JZ",flags)) goto L00485d0e;
  }
  L00485d04: { // 0x485d04: 8b8664010000 MOV EAX,dword ptr [ESI + 0x164]
    s.ax = m.r32((s.si+0x00000164u));
  }
  L00485d0a: { // 0x485d0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d0b: { // 0x485d0b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d0e: { // 0x485d0e: 8b861c010000 MOV EAX,dword ptr [ESI + 0x11c]
    s.ax = m.r32((s.si+0x0000011cu));
  }
  L00485d14: { // 0x485d14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d15: { // 0x485d15: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d18: { // 0x485d18: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d1e: { // 0x485d1e: 7436 JZ 0x00485d56
    if(integer::condition("JZ",flags)) goto L00485d56;
  }
  L00485d20: { // 0x485d20: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d22: { // 0x485d22: 7419 JZ 0x00485d3d
    if(integer::condition("JZ",flags)) goto L00485d3d;
  }
  L00485d24: { // 0x485d24: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d27: { // 0x485d27: 740a JZ 0x00485d33
    if(integer::condition("JZ",flags)) goto L00485d33;
  }
  L00485d29: { // 0x485d29: 8b8650010000 MOV EAX,dword ptr [ESI + 0x150]
    s.ax = m.r32((s.si+0x00000150u));
  }
  L00485d2f: { // 0x485d2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d30: { // 0x485d30: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d33: { // 0x485d33: 8b8604010000 MOV EAX,dword ptr [ESI + 0x104]
    s.ax = m.r32((s.si+0x00000104u));
  }
  L00485d39: { // 0x485d39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d3a: { // 0x485d3a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d3d: { // 0x485d3d: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d40: { // 0x485d40: 740a JZ 0x00485d4c
    if(integer::condition("JZ",flags)) goto L00485d4c;
  }
  L00485d42: { // 0x485d42: 8b8644010000 MOV EAX,dword ptr [ESI + 0x144]
    s.ax = m.r32((s.si+0x00000144u));
  }
  L00485d48: { // 0x485d48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d49: { // 0x485d49: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d4c: { // 0x485d4c: 8b86f8000000 MOV EAX,dword ptr [ESI + 0xf8]
    s.ax = m.r32((s.si+0x000000f8u));
  }
  L00485d52: { // 0x485d52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d53: { // 0x485d53: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d56: { // 0x485d56: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d59: { // 0x485d59: 740a JZ 0x00485d65
    if(integer::condition("JZ",flags)) goto L00485d65;
  }
  L00485d5b: { // 0x485d5b: 8b8630010000 MOV EAX,dword ptr [ESI + 0x130]
    s.ax = m.r32((s.si+0x00000130u));
  }
  L00485d61: { // 0x485d61: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d62: { // 0x485d62: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d65: { // 0x485d65: 8b86e0000000 MOV EAX,dword ptr [ESI + 0xe0]
    s.ax = m.r32((s.si+0x000000e0u));
  }
  L00485d6b: { // 0x485d6b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d6c: { // 0x485d6c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d6f: { // 0x485d6f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00485d72: { // 0x485d72: 7419 JZ 0x00485d8d
    if(integer::condition("JZ",flags)) goto L00485d8d;
  }
  L00485d74: { // 0x485d74: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d77: { // 0x485d77: 740a JZ 0x00485d83
    if(integer::condition("JZ",flags)) goto L00485d83;
  }
  L00485d79: { // 0x485d79: 8b8668010000 MOV EAX,dword ptr [ESI + 0x168]
    s.ax = m.r32((s.si+0x00000168u));
  }
  L00485d7f: { // 0x485d7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d80: { // 0x485d80: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d83: { // 0x485d83: 8b8620010000 MOV EAX,dword ptr [ESI + 0x120]
    s.ax = m.r32((s.si+0x00000120u));
  }
  L00485d89: { // 0x485d89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485d8a: { // 0x485d8a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485d8d: { // 0x485d8d: 8505aceb7b00 TEST dword ptr [0x007bebac],EAX
    (void)integer::logical((m.r32((0x007bebacu)))&(s.ax),32,flags);
  }
  L00485d93: { // 0x485d93: 7436 JZ 0x00485dcb
    if(integer::condition("JZ",flags)) goto L00485dcb;
  }
  L00485d95: { // 0x485d95: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d97: { // 0x485d97: 7419 JZ 0x00485db2
    if(integer::condition("JZ",flags)) goto L00485db2;
  }
  L00485d99: { // 0x485d99: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485d9c: { // 0x485d9c: 740a JZ 0x00485da8
    if(integer::condition("JZ",flags)) goto L00485da8;
  }
  L00485d9e: { // 0x485d9e: 8b8654010000 MOV EAX,dword ptr [ESI + 0x154]
    s.ax = m.r32((s.si+0x00000154u));
  }
  L00485da4: { // 0x485da4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485da5: { // 0x485da5: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485da8: { // 0x485da8: 8b8608010000 MOV EAX,dword ptr [ESI + 0x108]
    s.ax = m.r32((s.si+0x00000108u));
  }
  L00485dae: { // 0x485dae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485daf: { // 0x485daf: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485db2: { // 0x485db2: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485db5: { // 0x485db5: 740a JZ 0x00485dc1
    if(integer::condition("JZ",flags)) goto L00485dc1;
  }
  L00485db7: { // 0x485db7: 8b8648010000 MOV EAX,dword ptr [ESI + 0x148]
    s.ax = m.r32((s.si+0x00000148u));
  }
  L00485dbd: { // 0x485dbd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dbe: { // 0x485dbe: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dc1: { // 0x485dc1: 8b86fc000000 MOV EAX,dword ptr [ESI + 0xfc]
    s.ax = m.r32((s.si+0x000000fcu));
  }
  L00485dc7: { // 0x485dc7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dc8: { // 0x485dc8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dcb: { // 0x485dcb: f6c408 TEST AH,0x8
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000008u),8,flags);
  }
  L00485dce: { // 0x485dce: 740a JZ 0x00485dda
    if(integer::condition("JZ",flags)) goto L00485dda;
  }
  L00485dd0: { // 0x485dd0: 8b8634010000 MOV EAX,dword ptr [ESI + 0x134]
    s.ax = m.r32((s.si+0x00000134u));
  }
  L00485dd6: { // 0x485dd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485dd7: { // 0x485dd7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00485dda: { // 0x485dda: 8b86e4000000 MOV EAX,dword ptr [ESI + 0xe4]
    s.ax = m.r32((s.si+0x000000e4u));
  }
  L00485de0: { // 0x485de0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00485de1: { // 0x485de1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00034f80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00434f80: { // 0x434f80: 83ec68 SUB ESP,0x68
    f.sp = integer::sub(f.sp,0x00000068u,32,flags);
  }
  L00434f83: { // 0x434f83: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434f87: { // 0x434f87: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434f88: { // 0x434f88: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434f89: { // 0x434f89: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00434f8d: { // 0x434f8d: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00434f8f: { // 0x434f8f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00434f90: { // 0x434f90: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434f91: { // 0x434f91: 8b6c247c MOV EBP,dword ptr [ESP + 0x7c]
    s.bp = m.r32((f.sp+0x0000007cu));
  }
  L00434f95: { // 0x434f95: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00434f97: { // 0x434f97: 894c2468 MOV dword ptr [ESP + 0x68],ECX
    m.w32((f.sp+0x00000068u), s.cx);
  }
  L00434f9b: { // 0x434f9b: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00434f9e: { // 0x434f9e: 8b9c2484000000 MOV EBX,dword ptr [ESP + 0x84]
    s.bx = m.r32((f.sp+0x00000084u));
  }
  L00434fa5: { // 0x434fa5: 8954246c MOV dword ptr [ESP + 0x6c],EDX
    m.w32((f.sp+0x0000006cu), s.dx);
  }
  L00434fa9: { // 0x434fa9: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434faa: { // 0x434faa: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00434fad: { // 0x434fad: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00434faf: { // 0x434faf: 894c2474 MOV dword ptr [ESP + 0x74],ECX
    m.w32((f.sp+0x00000074u), s.cx);
  }
  L00434fb3: { // 0x434fb3: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L00434fb7: { // 0x434fb7: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00434fba: { // 0x434fba: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00434fbc: { // 0x434fbc: 89542478 MOV dword ptr [ESP + 0x78],EDX
    m.w32((f.sp+0x00000078u), s.dx);
  }
  L00434fc0: { // 0x434fc0: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L00434fc4: { // 0x434fc4: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00434fc6: { // 0x434fc6: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00434fca: { // 0x434fca: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434fce: { // 0x434fce: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00434fd2: { // 0x434fd2: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00434fd5: { // 0x434fd5: 89742438 MOV dword ptr [ESP + 0x38],ESI
    m.w32((f.sp+0x00000038u), s.si);
  }
  L00434fd9: { // 0x434fd9: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00434fdd: { // 0x434fdd: 89b4248c000000 MOV dword ptr [ESP + 0x8c],ESI
    m.w32((f.sp+0x0000008cu), s.si);
  }
  L00434fe4: { // 0x434fe4: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00434fe7: { // 0x434fe7: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L00434feb: { // 0x434feb: 894c2464 MOV dword ptr [ESP + 0x64],ECX
    m.w32((f.sp+0x00000064u), s.cx);
  }
  L00434fef: { // 0x434fef: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L00434ff3: { // 0x434ff3: 8b500c MOV EDX,dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L00434ff6: { // 0x434ff6: 8b842498000000 MOV EAX,dword ptr [ESP + 0x98]
    s.ax = m.r32((f.sp+0x00000098u));
  }
  L00434ffd: { // 0x434ffd: 89542468 MOV dword ptr [ESP + 0x68],EDX
    m.w32((f.sp+0x00000068u), s.dx);
  }
  L00435001: { // 0x435001: 8d54246c LEA EDX,[ESP + 0x6c]
    s.dx = (f.sp+0x0000006cu);
  }
  L00435005: { // 0x435005: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00435008: { // 0x435008: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435009: { // 0x435009: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L0043500b: { // 0x43500b: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0043500f: { // 0x43500f: 8d0cc5f8907b00 LEA ECX,[EAX*0x8 + 0x7b90f8]
    s.cx = ((s.ax * 0x00000008u)+0x007b90f8u);
  }
  L00435016: { // 0x435016: 898c2484000000 MOV dword ptr [ESP + 0x84],ECX
    m.w32((f.sp+0x00000084u), s.cx);
  }
  L0043501d: { // 0x43501d: 8d4c2460 LEA ECX,[ESP + 0x60]
    s.cx = (f.sp+0x00000060u);
  }
  L00435021: { // 0x435021: e8aaba3200 CALL 0x00760ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760ad0u,4411430u); flags=s.arithmetic_flags;
  }
  L00435026: { // 0x435026: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00435028: { // 0x435028: 750a JNZ 0x00435034
    if(integer::condition("JNZ",flags)) goto L00435034;
  }
  L0043502a: { // 0x43502a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043502b: { // 0x43502b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043502c: { // 0x43502c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043502d: { // 0x43502d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0043502e: { // 0x43502e: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L00435031: { // 0x435031: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L00435034: { // 0x435034: 8b442468 MOV EAX,dword ptr [ESP + 0x68]
    s.ax = m.r32((f.sp+0x00000068u));
  }
  L00435038: { // 0x435038: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0043503a: { // 0x43503a: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L0043503d: { // 0x43503d: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0043503f: { // 0x43503f: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00435043: { // 0x435043: 8b44246c MOV EAX,dword ptr [ESP + 0x6c]
    s.ax = m.r32((f.sp+0x0000006cu));
  }
  L00435047: { // 0x435047: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00435049: { // 0x435049: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  L0043504d: { // 0x43504d: 89842484000000 MOV dword ptr [ESP + 0x84],EAX
    m.w32((f.sp+0x00000084u), s.ax);
  }
  L00435054: { // 0x435054: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00435058: { // 0x435058: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435059: { // 0x435059: e8c2030000 CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,4411486u); flags=s.arithmetic_flags;
  }
  L0043505e: { // 0x43505e: 8d4c2440 LEA ECX,[ESP + 0x40]
    s.cx = (f.sp+0x00000040u);
  }
  L00435062: { // 0x435062: 8d542448 LEA EDX,[ESP + 0x48]
    s.dx = (f.sp+0x00000048u);
  }
  L00435066: { // 0x435066: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435067: { // 0x435067: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435068: { // 0x435068: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435069: { // 0x435069: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0043506b: { // 0x43506b: e8b0030000 CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,4411504u); flags=s.arithmetic_flags;
  }
  L00435070: { // 0x435070: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00435072: { // 0x435072: e889030000 CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,4411511u); flags=s.arithmetic_flags;
  }
  L00435077: { // 0x435077: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00435079: { // 0x435079: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0043507c: { // 0x43507c: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L0043507e: { // 0x43507e: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00435080: { // 0x435080: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00435083: { // 0x435083: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00435086: { // 0x435086: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0043508a: { // 0x43508a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0043508c: { // 0x43508c: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4411535u); flags=s.arithmetic_flags;
  }
  L0043508f: { // 0x43508f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435091: { // 0x435091: 89842494000000 MOV dword ptr [ESP + 0x94],EAX
    m.w32((f.sp+0x00000094u), s.ax);
  }
  L00435098: { // 0x435098: 750c JNZ 0x004350a6
    if(integer::condition("JNZ",flags)) goto L004350a6;
  }
  L0043509a: { // 0x43509a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0043509c: { // 0x43509c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043509d: { // 0x43509d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043509e: { // 0x43509e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0043509f: { // 0x43509f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004350a0: { // 0x4350a0: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L004350a3: { // 0x4350a3: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L004350a6: { // 0x4350a6: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L004350ac: { // 0x4350ac: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004350ae: { // 0x4350ae: 0f8471010000 JZ 0x00435225
    if(integer::condition("JZ",flags)) goto L00435225;
  }
  L004350b4: { // 0x4350b4: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L004350b6: { // 0x4350b6: 8b5c2458 MOV EBX,dword ptr [ESP + 0x58]
    s.bx = m.r32((f.sp+0x00000058u));
  }
  L004350ba: { // 0x4350ba: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L004350be: { // 0x4350be: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L004350c1: { // 0x4350c1: 03f3 ADD ESI,EBX
    s.si = integer::add(s.si,s.bx,32,flags);
  }
  L004350c3: { // 0x4350c3: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004350c5: { // 0x4350c5: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L004350c7: { // 0x4350c7: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L004350ca: { // 0x4350ca: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L004350ce: { // 0x4350ce: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L004350d0: { // 0x4350d0: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004350d2: { // 0x4350d2: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004350d3: { // 0x4350d3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004350d4: { // 0x4350d4: e8a7cb3200 CALL 0x00761c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761c80u,4411609u); flags=s.arithmetic_flags;
  }
  L004350d9: { // 0x4350d9: 8b1dac1f8200 MOV EBX,dword ptr [0x00821fac]
    s.bx = m.r32((0x00821facu));
  }
  L004350df: { // 0x4350df: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004350e3: { // 0x4350e3: c784248800000000000000 MOV dword ptr [ESP + 0x88],0x0
    m.w32((f.sp+0x00000088u), 0x00000000u);
  }
  L004350ee: { // 0x4350ee: 8b4328 MOV EAX,dword ptr [EBX + 0x28]
    s.ax = m.r32((s.bx+0x00000028u));
  }
  L004350f1: { // 0x4350f1: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L004350f5: { // 0x4350f5: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    s.ax = m.r32((f.sp+0x0000007cu));
  }
  L004350f9: { // 0x4350f9: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L004350fc: { // 0x4350fc: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L004350ff: { // 0x4350ff: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00435103: { // 0x435103: 894c2430 MOV dword ptr [ESP + 0x30],ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00435107: { // 0x435107: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435108: { // 0x435108: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0043510a: { // 0x43510a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0043510c: { // 0x43510c: 8b44247c MOV EAX,dword ptr [ESP + 0x7c]
    s.ax = m.r32((f.sp+0x0000007cu));
  }
  L00435110: { // 0x435110: 8a5014 MOV DL,byte ptr [EAX + 0x14]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000014u)));
  }
  L00435113: { // 0x435113: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00435115: { // 0x435115: 0f8486000000 JZ 0x004351a1
    if(integer::condition("JZ",flags)) goto L004351a1;
  }
  L0043511b: { // 0x43511b: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L0043511e: { // 0x43511e: 668b4324 MOV AX,word ptr [EBX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.bx+0x00000024u)));
  }
  L00435122: { // 0x435122: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  L00435129: { // 0x435129: 662bc6 SUB AX,SI
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),(s.si & 0xffffu),16,flags));
  }
  L0043512c: { // 0x43512c: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00435131: { // 0x435131: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435133: { // 0x435133: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435134: { // 0x435134: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00435136: { // 0x435136: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00435138: { // 0x435138: 8b8424a0000000 MOV EAX,dword ptr [ESP + 0xa0]
    s.ax = m.r32((f.sp+0x000000a0u));
  }
  L0043513f: { // 0x43513f: 0faff1 IMUL ESI,ECX
    s.si = integer::imul(s.si,s.cx,32,flags);
  }
  L00435142: { // 0x435142: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00435144: { // 0x435144: 0f84d3000000 JZ 0x0043521d
    if(integer::condition("JZ",flags)) goto L0043521d;
  }
  L0043514a: { // 0x43514a: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0043514c: { // 0x43514c: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0043514e: { // 0x43514e: 8d442448 LEA EAX,[ESP + 0x48]
    s.ax = (f.sp+0x00000048u);
  }
  L00435152: { // 0x435152: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435153: { // 0x435153: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00435155: { // 0x435155: ff5278 CALL dword ptr [EDX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000078u)),4411736u); flags=s.arithmetic_flags;
  }
  L00435158: { // 0x435158: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0043515a: { // 0x43515a: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L0043515d: { // 0x43515d: 8b4d04 MOV ECX,dword ptr [EBP + 0x4]
    s.cx = m.r32((s.bp+0x00000004u));
  }
  L00435160: { // 0x435160: 8b5508 MOV EDX,dword ptr [EBP + 0x8]
    s.dx = m.r32((s.bp+0x00000008u));
  }
  L00435163: { // 0x435163: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00435167: { // 0x435167: 8b9424a4000000 MOV EDX,dword ptr [ESP + 0xa4]
    s.dx = m.r32((f.sp+0x000000a4u));
  }
  L0043516e: { // 0x43516e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435170: { // 0x435170: 8b9424a8000000 MOV EDX,dword ptr [ESP + 0xa8]
    s.dx = m.r32((f.sp+0x000000a8u));
  }
  L00435177: { // 0x435177: 8b6d0c MOV EBP,dword ptr [EBP + 0xc]
    s.bp = m.r32((s.bp+0x0000000cu));
  }
  L0043517a: { // 0x43517a: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043517c: { // 0x43517c: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00435180: { // 0x435180: 896c2454 MOV dword ptr [ESP + 0x54],EBP
    m.w32((f.sp+0x00000054u), s.bp);
  }
  L00435184: { // 0x435184: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435186: { // 0x435186: 8b942484000000 MOV EDX,dword ptr [ESP + 0x84]
    s.dx = m.r32((f.sp+0x00000084u));
  }
  L0043518d: { // 0x43518d: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043518f: { // 0x43518f: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00435191: { // 0x435191: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435192: { // 0x435192: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435193: { // 0x435193: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00435195: { // 0x435195: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4411800u); flags=s.arithmetic_flags;
  }
  L00435198: { // 0x435198: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0043519c: { // 0x43519c: e98b000000 JMP 0x0043522c
    goto L0043522c;
  }
  L004351a1: { // 0x4351a1: 668b7324 MOV SI,word ptr [EBX + 0x24]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.bx+0x00000024u))) & 0xffffu);
  }
  L004351a5: { // 0x4351a5: 8b942490000000 MOV EDX,dword ptr [ESP + 0x90]
    s.dx = m.r32((f.sp+0x00000090u));
  }
  L004351ac: { // 0x4351ac: 66037304 ADD SI,word ptr [EBX + 0x4]
    s.si = (s.si & 0xffff0000u) | ((integer::add((s.si & 0xffffu),m.r16((s.bx+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351b0: { // 0x4351b0: 8b9c24a0000000 MOV EBX,dword ptr [ESP + 0xa0]
    s.bx = m.r32((f.sp+0x000000a0u));
  }
  L004351b7: { // 0x4351b7: 662b7704 SUB SI,word ptr [EDI + 0x4]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.di+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351bb: { // 0x4351bb: 662b750c SUB SI,word ptr [EBP + 0xc]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.bp+0x0000000cu)),16,flags)) & 0xffffu);
  }
  L004351bf: { // 0x4351bf: 662b7504 SUB SI,word ptr [EBP + 0x4]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.bp+0x00000004u)),16,flags)) & 0xffffu);
  }
  L004351c3: { // 0x4351c3: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L004351c4: { // 0x4351c4: 81e6ffff0000 AND ESI,0xffff
    s.si = integer::logical((s.si)&(0x0000ffffu),32,flags);
  }
  L004351ca: { // 0x4351ca: 03f2 ADD ESI,EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L004351cc: { // 0x4351cc: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L004351ce: { // 0x4351ce: 0f8578ffffff JNZ 0x0043514c
    if(integer::condition("JNZ",flags)) goto L0043514c;
  }
  L004351d4: { // 0x4351d4: 8b5d0c MOV EBX,dword ptr [EBP + 0xc]
    s.bx = m.r32((s.bp+0x0000000cu));
  }
  L004351d7: { // 0x4351d7: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L004351db: { // 0x4351db: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L004351de: { // 0x4351de: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L004351e0: { // 0x4351e0: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L004351e2: { // 0x4351e2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L004351e4: { // 0x4351e4: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351e5: { // 0x4351e5: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351e7: { // 0x4351e7: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L004351e9: { // 0x4351e9: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004351eb: { // 0x4351eb: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351ec: { // 0x4351ec: 0faff1 IMUL ESI,ECX
    s.si = integer::imul(s.si,s.cx,32,flags);
  }
  L004351ef: { // 0x4351ef: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351f1: { // 0x4351f1: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L004351f3: { // 0x4351f3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L004351f5: { // 0x4351f5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004351f6: { // 0x4351f6: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L004351f8: { // 0x4351f8: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004351fc: { // 0x4351fc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004351fe: { // 0x4351fe: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00435200: { // 0x435200: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00435202: { // 0x435202: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L00435209: { // 0x435209: 7512 JNZ 0x0043521d
    if(integer::condition("JNZ",flags)) goto L0043521d;
  }
  L0043520b: { // 0x43520b: 8b4c247c MOV ECX,dword ptr [ESP + 0x7c]
    s.cx = m.r32((f.sp+0x0000007cu));
  }
  L0043520f: { // 0x43520f: c784248800000000000000 MOV dword ptr [ESP + 0x88],0x0
    m.w32((f.sp+0x00000088u), 0x00000000u);
  }
  L0043521a: { // 0x43521a: 037110 ADD ESI,dword ptr [ECX + 0x10]
    s.si = integer::add(s.si,m.r32((s.cx+0x00000010u)),32,flags);
  }
  L0043521d: { // 0x43521d: c7442410c06d8300 MOV dword ptr [ESP + 0x10],0x836dc0
    m.w32((f.sp+0x00000010u), 0x00836dc0u);
  }
  L00435225: { // 0x435225: 8b9c24a0000000 MOV EBX,dword ptr [ESP + 0xa0]
    s.bx = m.r32((f.sp+0x000000a0u));
  }
  L0043522c: { // 0x43522c: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00435232: { // 0x435232: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00435234: { // 0x435234: 7435 JZ 0x0043526b
    if(integer::condition("JZ",flags)) goto L0043526b;
  }
  L00435236: { // 0x435236: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00435238: { // 0x435238: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L0043523c: { // 0x43523c: 8b7f04 MOV EDI,dword ptr [EDI + 0x4]
    s.di = m.r32((s.di+0x00000004u));
  }
  L0043523f: { // 0x43523f: 8b6904 MOV EBP,dword ptr [ECX + 0x4]
    s.bp = m.r32((s.cx+0x00000004u));
  }
  L00435242: { // 0x435242: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00435244: { // 0x435244: 8b44245c MOV EAX,dword ptr [ESP + 0x5c]
    s.ax = m.r32((f.sp+0x0000005cu));
  }
  L00435248: { // 0x435248: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L0043524a: { // 0x43524a: 898424a8000000 MOV dword ptr [ESP + 0xa8],EAX
    m.w32((f.sp+0x000000a8u), s.ax);
  }
  L00435251: { // 0x435251: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00435253: { // 0x435253: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435254: { // 0x435254: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435255: { // 0x435255: e8d6bffdff CALL 0x00411230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4411994u); flags=s.arithmetic_flags;
  }
  L0043525a: { // 0x43525a: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00435260: { // 0x435260: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00435264: { // 0x435264: 8b5128 MOV EDX,dword ptr [ECX + 0x28]
    s.dx = m.r32((s.cx+0x00000028u));
  }
  L00435267: { // 0x435267: 89542434 MOV dword ptr [ESP + 0x34],EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L0043526b: { // 0x43526b: 8bac2480000000 MOV EBP,dword ptr [ESP + 0x80]
    s.bp = m.r32((f.sp+0x00000080u));
  }
  L00435272: { // 0x435272: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00435274: { // 0x435274: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00435276: { // 0x435276: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435277: { // 0x435277: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L0043527a: { // 0x43527a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0043527b: { // 0x43527b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L0043527d: { // 0x43527d: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),4412032u); flags=s.arithmetic_flags;
  }
  L00435280: { // 0x435280: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00435282: { // 0x435282: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00435284: { // 0x435284: 7515 JNZ 0x0043529b
    if(integer::condition("JNZ",flags)) goto L0043529b;
  }
  L00435286: { // 0x435286: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043528a: { // 0x43528a: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0043528c: { // 0x43528c: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4412047u); flags=s.arithmetic_flags;
  }
  L0043528f: { // 0x43528f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00435291: { // 0x435291: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00435292: { // 0x435292: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00435293: { // 0x435293: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00435294: { // 0x435294: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00435295: { // 0x435295: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L00435298: { // 0x435298: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
  L0043529b: { // 0x43529b: 8b842484000000 MOV EAX,dword ptr [ESP + 0x84]
    s.ax = m.r32((f.sp+0x00000084u));
  }
  L004352a2: { // 0x4352a2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004352a4: { // 0x4352a4: 7e0a JLE 0x004352b0
    if(integer::condition("JLE",flags)) goto L004352b0;
  }
  L004352a6: { // 0x4352a6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004352a8: { // 0x4352a8: 668b0f MOV CX,word ptr [EDI]
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L004352ab: { // 0x4352ab: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L004352ad: { // 0x4352ad: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004352ae: { // 0x4352ae: 75f6 JNZ 0x004352a6
    if(integer::condition("JNZ",flags)) goto L004352a6;
  }
  L004352b0: { // 0x4352b0: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004352b4: { // 0x4352b4: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004352b6: { // 0x4352b6: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4412089u); flags=s.arithmetic_flags;
  }
  L004352b9: { // 0x4352b9: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L004352bd: { // 0x4352bd: 89842490000000 MOV dword ptr [ESP + 0x90],EAX
    m.w32((f.sp+0x00000090u), s.ax);
  }
  L004352c4: { // 0x4352c4: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L004352c8: { // 0x4352c8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L004352ca: { // 0x4352ca: 7c02 JL 0x004352ce
    if(integer::condition("JL",flags)) goto L004352ce;
  }
  L004352cc: { // 0x4352cc: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L004352ce: { // 0x4352ce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004352d0: { // 0x4352d0: 0f8efe000000 JLE 0x004353d4
    if(integer::condition("JLE",flags)) goto L004353d4;
  }
  L004352d6: { // 0x4352d6: 898424a0000000 MOV dword ptr [ESP + 0xa0],EAX
    m.w32((f.sp+0x000000a0u), s.ax);
  }
  L004352dd: { // 0x4352dd: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L004352e1: { // 0x4352e1: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L004352e5: { // 0x4352e5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004352e6: { // 0x4352e6: 8b94249c000000 MOV EDX,dword ptr [ESP + 0x9c]
    s.dx = m.r32((f.sp+0x0000009cu));
  }
  L004352ed: { // 0x4352ed: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L004352ef: { // 0x4352ef: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004352f0: { // 0x4352f0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L004352f4: { // 0x4352f4: 8b8c2498000000 MOV ECX,dword ptr [ESP + 0x98]
    s.cx = m.r32((f.sp+0x00000098u));
  }
  L004352fb: { // 0x4352fb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004352fc: { // 0x4352fc: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L00435300: { // 0x435300: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00435301: { // 0x435301: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435302: { // 0x435302: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00435304: { // 0x435304: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435305: { // 0x435305: 8b94248c000000 MOV EDX,dword ptr [ESP + 0x8c]
    s.dx = m.r32((f.sp+0x0000008cu));
  }
  L0043530c: { // 0x43530c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0043530d: { // 0x43530d: 8d5702 LEA EDX,[EDI + 0x2]
    s.dx = (s.di+0x00000002u);
  }
  L00435310: { // 0x435310: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435311: { // 0x435311: 8b9424b8000000 MOV EDX,dword ptr [ESP + 0xb8]
    s.dx = m.r32((f.sp+0x000000b8u));
  }
  L00435318: { // 0x435318: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435319: { // 0x435319: ff5004 CALL dword ptr [EAX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000004u)),4412188u); flags=s.arithmetic_flags;
  }
  L0043531c: { // 0x43531c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043531e: { // 0x43531e: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00435321: { // 0x435321: 8b8c2490000000 MOV ECX,dword ptr [ESP + 0x90]
    s.cx = m.r32((f.sp+0x00000090u));
  }
  L00435328: { // 0x435328: 8b942494000000 MOV EDX,dword ptr [ESP + 0x94]
    s.dx = m.r32((f.sp+0x00000094u));
  }
  L0043532f: { // 0x43532f: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00435331: { // 0x435331: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00435336: { // 0x435336: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00435338: { // 0x435338: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043533a: { // 0x43533a: 89942494000000 MOV dword ptr [ESP + 0x94],EDX
    m.w32((f.sp+0x00000094u), s.dx);
  }
  L00435341: { // 0x435341: 7475 JZ 0x004353b8
    if(integer::condition("JZ",flags)) goto L004353b8;
  }
  L00435343: { // 0x435343: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00435347: { // 0x435347: 8d4c5500 LEA ECX,[EBP + EDX*0x2]
    s.cx = (s.bp+(s.dx * 0x00000002u));
  }
  L0043534b: { // 0x43534b: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L0043534e: { // 0x43534e: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00435350: { // 0x435350: 7203 JC 0x00435355
    if(integer::condition("JC",flags)) goto L00435355;
  }
  L00435352: { // 0x435352: 2b4820 SUB ECX,dword ptr [EAX + 0x20]
    s.cx = integer::sub(s.cx,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00435355: { // 0x435355: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00435357: { // 0x435357: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L0043535b: { // 0x43535b: 7410 JZ 0x0043536d
    if(integer::condition("JZ",flags)) goto L0043536d;
  }
  L0043535d: { // 0x43535d: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00435361: { // 0x435361: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00435365: { // 0x435365: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00435367: { // 0x435367: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L0043536b: { // 0x43536b: eb2e JMP 0x0043539b
    goto L0043539b;
  }
  L0043536d: { // 0x43536d: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  L00435374: { // 0x435374: 8b6c2430 MOV EBP,dword ptr [ESP + 0x30]
    s.bp = m.r32((f.sp+0x00000030u));
  }
  L00435378: { // 0x435378: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0043537c: { // 0x43537c: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L0043537e: { // 0x43537e: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00435380: { // 0x435380: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L00435387: { // 0x435387: 7c12 JL 0x0043539b
    if(integer::condition("JL",flags)) goto L0043539b;
  }
  L00435389: { // 0x435389: 8b54247c MOV EDX,dword ptr [ESP + 0x7c]
    s.dx = m.r32((f.sp+0x0000007cu));
  }
  L0043538d: { // 0x43538d: 8b6a10 MOV EBP,dword ptr [EDX + 0x10]
    s.bp = m.r32((s.dx+0x00000010u));
  }
  L00435390: { // 0x435390: 03f5 ADD ESI,EBP
    s.si = integer::add(s.si,s.bp,32,flags);
  }
  L00435392: { // 0x435392: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00435394: { // 0x435394: 89842488000000 MOV dword ptr [ESP + 0x88],EAX
    m.w32((f.sp+0x00000088u), s.ax);
  }
  L0043539b: { // 0x43539b: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0043539f: { // 0x43539f: 8b4c2434 MOV ECX,dword ptr [ESP + 0x34]
    s.cx = m.r32((f.sp+0x00000034u));
  }
  L004353a3: { // 0x4353a3: 8d0448 LEA EAX,[EAX + ECX*0x2]
    s.ax = (s.ax+(s.cx * 0x00000002u));
  }
  L004353a6: { // 0x4353a6: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L004353ac: { // 0x4353ac: 3b411c CMP EAX,dword ptr [ECX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L004353af: { // 0x4353af: 7203 JC 0x004353b4
    if(integer::condition("JC",flags)) goto L004353b4;
  }
  L004353b1: { // 0x4353b1: 2b4120 SUB EAX,dword ptr [ECX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L004353b4: { // 0x4353b4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L004353b8: { // 0x4353b8: 8b8424a0000000 MOV EAX,dword ptr [ESP + 0xa0]
    s.ax = m.r32((f.sp+0x000000a0u));
  }
  L004353bf: { // 0x4353bf: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004353c0: { // 0x4353c0: 898424a0000000 MOV dword ptr [ESP + 0xa0],EAX
    m.w32((f.sp+0x000000a0u), s.ax);
  }
  L004353c7: { // 0x4353c7: 0f8510ffffff JNZ 0x004352dd
    if(integer::condition("JNZ",flags)) goto L004352dd;
  }
  L004353cd: { // 0x4353cd: 8bac2480000000 MOV EBP,dword ptr [ESP + 0x80]
    s.bp = m.r32((f.sp+0x00000080u));
  }
  L004353d4: { // 0x4353d4: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004353d8: { // 0x4353d8: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004353da: { // 0x4353da: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4412381u); flags=s.arithmetic_flags;
  }
  L004353dd: { // 0x4353dd: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  L004353e0: { // 0x4353e0: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L004353e2: { // 0x4353e2: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4412389u); flags=s.arithmetic_flags;
  }
  L004353e5: { // 0x4353e5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004353e7: { // 0x4353e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004353e8: { // 0x4353e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004353e9: { // 0x4353e9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004353ea: { // 0x4353ea: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004353eb: { // 0x4353eb: 83c468 ADD ESP,0x68
    f.sp = integer::add(f.sp,0x00000068u,32,flags);
  }
  L004353ee: { // 0x4353ee: c23000 RET 0x30
    s.arithmetic_flags=flags; finish(m,s,f,48u); return;
  }
}
void f_00360ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760ad0: { // 0x760ad0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00760ad3: { // 0x760ad3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760ad4: { // 0x760ad4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760ad5: { // 0x760ad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760ad6: { // 0x760ad6: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00760ada: { // 0x760ada: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00760adc: { // 0x760adc: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760adf: { // 0x760adf: 394e08 CMP dword ptr [ESI + 0x8],ECX
    (void)integer::sub(m.r32((s.si+0x00000008u)),s.cx,32,flags);
  }
  L00760ae2: { // 0x760ae2: 0f852e010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760ae8: { // 0x760ae8: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760aeb: { // 0x760aeb: 8b5f0c MOV EBX,dword ptr [EDI + 0xc]
    s.bx = m.r32((s.di+0x0000000cu));
  }
  L00760aee: { // 0x760aee: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760af0: { // 0x760af0: 0f8520010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760af6: { // 0x760af6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760af8: { // 0x760af8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760afa: { // 0x760afa: 7d1d JGE 0x00760b19
    if(integer::condition("JGE",flags)) goto L00760b19;
  }
  L00760afc: { // 0x760afc: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760afe: { // 0x760afe: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b00: { // 0x760b00: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L00760b02: { // 0x760b02: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b04: { // 0x760b04: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b06: { // 0x760b06: 894708 MOV dword ptr [EDI + 0x8],EAX
    m.w32((s.di+0x00000008u), s.ax);
  }
  L00760b09: { // 0x760b09: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00760b0b: { // 0x760b0b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760b0e: { // 0x760b0e: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L00760b14: { // 0x760b14: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b16: { // 0x760b16: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00760b19: { // 0x760b19: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b1c: { // 0x760b1c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b1e: { // 0x760b1e: 7d25 JGE 0x00760b45
    if(integer::condition("JGE",flags)) goto L00760b45;
  }
  L00760b20: { // 0x760b20: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L00760b23: { // 0x760b23: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760b26: { // 0x760b26: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b28: { // 0x760b28: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00760b2b: { // 0x760b2b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b2e: { // 0x760b2e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760b30: { // 0x760b30: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760b33: { // 0x760b33: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00760b36: { // 0x760b36: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b39: { // 0x760b39: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00760b40: { // 0x760b40: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b42: { // 0x760b42: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00760b45: { // 0x760b45: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b47: { // 0x760b47: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L00760b4a: { // 0x760b4a: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L00760b4d: { // 0x760b4d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00760b4f: { // 0x760b4f: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760b51: { // 0x760b51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b53: { // 0x760b53: 7e10 JLE 0x00760b65
    if(integer::condition("JLE",flags)) goto L00760b65;
  }
  L00760b55: { // 0x760b55: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L00760b58: { // 0x760b58: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b5a: { // 0x760b5a: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L00760b5d: { // 0x760b5d: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b60: { // 0x760b60: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b62: { // 0x760b62: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760b65: { // 0x760b65: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b68: { // 0x760b68: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760b6b: { // 0x760b6b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00760b6e: { // 0x760b6e: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760b70: { // 0x760b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00760b72: { // 0x760b72: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b74: { // 0x760b74: 7e10 JLE 0x00760b86
    if(integer::condition("JLE",flags)) goto L00760b86;
  }
  L00760b76: { // 0x760b76: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760b79: { // 0x760b79: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00760b7b: { // 0x760b7b: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760b7e: { // 0x760b7e: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760b81: { // 0x760b81: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b83: { // 0x760b83: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760b86: { // 0x760b86: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b88: { // 0x760b88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b8a: { // 0x760b8a: 7d1e JGE 0x00760baa
    if(integer::condition("JGE",flags)) goto L00760baa;
  }
  L00760b8c: { // 0x760b8c: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L00760b8e: { // 0x760b8e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b90: { // 0x760b90: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L00760b92: { // 0x760b92: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b94: { // 0x760b94: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00760b97: { // 0x760b97: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760b99: { // 0x760b99: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00760b9c: { // 0x760b9c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b9f: { // 0x760b9f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760ba1: { // 0x760ba1: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760ba4: { // 0x760ba4: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L00760baa: { // 0x760baa: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bad: { // 0x760bad: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760baf: { // 0x760baf: 7d22 JGE 0x00760bd3
    if(integer::condition("JGE",flags)) goto L00760bd3;
  }
  L00760bb1: { // 0x760bb1: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L00760bb4: { // 0x760bb4: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760bb6: { // 0x760bb6: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00760bb9: { // 0x760bb9: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bbc: { // 0x760bbc: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760bbf: { // 0x760bbf: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760bc1: { // 0x760bc1: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760bc4: { // 0x760bc4: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760bc7: { // 0x760bc7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760bc9: { // 0x760bc9: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760bcc: { // 0x760bcc: c7470400000000 MOV dword ptr [EDI + 0x4],0x0
    m.w32((s.di+0x00000004u), 0x00000000u);
  }
  L00760bd3: { // 0x760bd3: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00760bd7: { // 0x760bd7: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760bda: { // 0x760bda: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00760bdc: { // 0x760bdc: 8b5a08 MOV EBX,dword ptr [EDX + 0x8]
    s.bx = m.r32((s.dx+0x00000008u));
  }
  L00760bdf: { // 0x760bdf: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760be1: { // 0x760be1: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760be3: { // 0x760be3: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760be5: { // 0x760be5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760be7: { // 0x760be7: 7e0d JLE 0x00760bf6
    if(integer::condition("JLE",flags)) goto L00760bf6;
  }
  L00760be9: { // 0x760be9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760beb: { // 0x760beb: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  L00760bee: { // 0x760bee: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760bf1: { // 0x760bf1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760bf3: { // 0x760bf3: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760bf6: { // 0x760bf6: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bf9: { // 0x760bf9: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760bfc: { // 0x760bfc: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760bff: { // 0x760bff: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760c01: { // 0x760c01: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760c03: { // 0x760c03: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c05: { // 0x760c05: 7e63 JLE 0x00760c6a
    if(integer::condition("JLE",flags)) goto L00760c6a;
  }
  L00760c07: { // 0x760c07: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c09: { // 0x760c09: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760c0c: { // 0x760c0c: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760c0f: { // 0x760c0f: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c11: { // 0x760c11: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760c14: { // 0x760c14: eb54 JMP 0x00760c6a
    goto L00760c6a;
  }
  L00760c16: { // 0x760c16: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c18: { // 0x760c18: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c1a: { // 0x760c1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760c1b: { // 0x760c1b: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c1d: { // 0x760c1d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c21: { // 0x760c21: e8caf1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736358u); flags=s.arithmetic_flags;
  }
  L00760c26: { // 0x760c26: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c28: { // 0x760c28: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c2a: { // 0x760c2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2c: { // 0x760c2c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2e: { // 0x760c2e: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c30: { // 0x760c30: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c33: { // 0x760c33: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c36: { // 0x760c36: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c39: { // 0x760c39: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c3c: { // 0x760c3c: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c3f: { // 0x760c3f: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00760c43: { // 0x760c43: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c46: { // 0x760c46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760c47: { // 0x760c47: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c49: { // 0x760c49: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c4d: { // 0x760c4d: e89ef1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736402u); flags=s.arithmetic_flags;
  }
  L00760c52: { // 0x760c52: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c54: { // 0x760c54: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c56: { // 0x760c56: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c58: { // 0x760c58: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c5b: { // 0x760c5b: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c5e: { // 0x760c5e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c61: { // 0x760c61: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c64: { // 0x760c64: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c67: { // 0x760c67: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c6a: { // 0x760c6a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760c6d: { // 0x760c6d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c6f: { // 0x760c6f: 7e23 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c71: { // 0x760c71: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760c74: { // 0x760c74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c76: { // 0x760c76: 7e1c JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c78: { // 0x760c78: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760c7b: { // 0x760c7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c7d: { // 0x760c7d: 7e15 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c7f: { // 0x760c7f: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760c82: { // 0x760c82: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c84: { // 0x760c84: 7e0e JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c86: { // 0x760c86: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c87: { // 0x760c87: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c88: { // 0x760c88: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00760c8d: { // 0x760c8d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c8e: { // 0x760c8e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c91: { // 0x760c91: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00760c94: { // 0x760c94: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c95: { // 0x760c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c96: { // 0x760c96: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00760c98: { // 0x760c98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c99: { // 0x760c99: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c9c: { // 0x760c9c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00035400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435400: { // 0x435400: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435404: { // 0x435404: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435405: { // 0x435405: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00435407: { // 0x435407: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00435409: { // 0x435409: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0043540b: { // 0x43540b: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0043540e: { // 0x43540e: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00435411: { // 0x435411: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00435413: { // 0x435413: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435417: { // 0x435417: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00435419: { // 0x435419: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L0043541c: { // 0x43541c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043541d: { // 0x43541d: c20800 RET 0x8
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
void f_00361c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761c80: { // 0x761c80: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00761c84: { // 0x761c84: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00761c85: { // 0x761c85: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00761c87: { // 0x761c87: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00761c88: { // 0x761c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c89: { // 0x761c89: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00761c8d: { // 0x761c8d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c90: { // 0x761c90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c91: { // 0x761c91: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c93: { // 0x761c93: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000005cu)),7740566u); flags=s.arithmetic_flags;
  }
  L00761c96: { // 0x761c96: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c99: { // 0x761c99: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00761c9b: { // 0x761c9b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c9d: { // 0x761c9d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),7740576u); flags=s.arithmetic_flags;
  }
  L00761ca0: { // 0x761ca0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00761ca3: { // 0x761ca3: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00761ca6: { // 0x761ca6: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00761ca8: { // 0x761ca8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00761caa: { // 0x761caa: 7203 JC 0x00761caf
    if(integer::condition("JC",flags)) goto L00761caf;
  }
  L00761cac: { // 0x761cac: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L00761caf: { // 0x761caf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761cb0: { // 0x761cb0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761cb1: { // 0x761cb1: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_00086a80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00486a80: { // 0x486a80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00486a81: { // 0x486a81: 8b542414 MOV EDX, dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L00486a85: { // 0x486a85: 8b44241c MOV EAX, dword ptr [ESP + 0x1C]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L00486a89: { // 0x486a89: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00486a8a: { // 0x486a8a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00486a8b: { // 0x486a8b: 8b6c2414 MOV EBP, dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L00486a8f: { // 0x486a8f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00486a90: { // 0x486a90: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00486a94: { // 0x486a94: 894c240c MOV dword ptr [ESP + 0xC], ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L00486a98: { // 0x486a98: 8b0dac1f8200 MOV ECX, dword ptr [0x821FAC]
    s.cx = m.r32((0x00821facu));
  }
  L00486a9e: { // 0x486a9e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00486a9f: { // 0x486a9f: 8b7c243c MOV EDI, dword ptr [ESP + 0x3C]
    s.di = m.r32((f.sp+0x0000003cu));
  }
  L00486aa3: { // 0x486aa3: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00486aa5: { // 0x486aa5: 7e30 JLE 0x486AD7
    if(integer::condition("JLE",flags)) goto L00486ad7;
  }
  L00486aa7: { // 0x486aa7: 8a5d00 MOV BL, byte ptr [EBP]
    s.bx = with_al(s.bx, m.r8((s.bp)));
  }
  L00486aaa: { // 0x486aaa: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00486aab: { // 0x486aab: 84db TEST BL, BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L00486aad: { // 0x486aad: 750a JNZ 0x486AB9
    if(integer::condition("JNZ",flags)) goto L00486ab9;
  }
  L00486aaf: { // 0x486aaf: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00486ab1: { // 0x486ab1: 8a5d00 MOV BL, byte ptr [EBP]
    s.bx = with_al(s.bx, m.r8((s.bp)));
  }
  L00486ab4: { // 0x486ab4: 2bd3 SUB EDX, EBX
    s.dx = integer::sub(s.dx,s.bx,32,flags);
  }
  L00486ab6: { // 0x486ab6: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00486ab7: { // 0x486ab7: eb01 JMP 0x486ABA
    goto L00486aba;
  }
  L00486ab9: { // 0x486ab9: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L00486aba: { // 0x486aba: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00486abc: { // 0x486abc: 7fe9 JG 0x486AA7
    if(integer::condition("JG",flags)) goto L00486aa7;
  }
  L00486abe: { // 0x486abe: 8b5c2420 MOV EBX, dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L00486ac2: { // 0x486ac2: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00486ac4: { // 0x486ac4: 03f2 ADD ESI, EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00486ac6: { // 0x486ac6: 2bda SUB EBX, EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00486ac8: { // 0x486ac8: 8d0450 LEA EAX, [EAX + EDX*2]
    s.ax = (s.ax+(s.dx * 2u));
  }
  L00486acb: { // 0x486acb: 8b511c MOV EDX, dword ptr [ECX + 0x1C]
    s.dx = m.r32((s.cx+0x0000001cu));
  }
  L00486ace: { // 0x486ace: 3bc2 CMP EAX, EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00486ad0: { // 0x486ad0: 7209 JC 0x486ADB
    if(integer::condition("JC",flags)) goto L00486adb;
  }
  L00486ad2: { // 0x486ad2: 2b4120 SUB EAX, dword ptr [ECX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L00486ad5: { // 0x486ad5: eb04 JMP 0x486ADB
    goto L00486adb;
  }
  L00486ad7: { // 0x486ad7: 8b5c2420 MOV EBX, dword ptr [ESP + 0x20]
    s.bx = m.r32((f.sp+0x00000020u));
  }
  L00486adb: { // 0x486adb: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00486add: { // 0x486add: 7e76 JLE 0x486B55
    if(integer::condition("JLE",flags)) goto L00486b55;
  }
  L00486adf: { // 0x486adf: 8a5500 MOV DL, byte ptr [EBP]
    s.dx = with_al(s.dx, m.r8((s.bp)));
  }
  L00486ae2: { // 0x486ae2: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00486ae3: { // 0x486ae3: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00486ae5: { // 0x486ae5: 751d JNZ 0x486B04
    if(integer::condition("JNZ",flags)) goto L00486b04;
  }
  L00486ae7: { // 0x486ae7: 8a5500 MOV DL, byte ptr [EBP]
    s.dx = with_al(s.dx, m.r8((s.bp)));
  }
  L00486aea: { // 0x486aea: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00486aeb: { // 0x486aeb: 88542420 MOV byte ptr [ESP + 0x20], DL
    m.w8((f.sp+0x00000020u), (s.dx & 0xffu));
  }
  L00486aef: { // 0x486aef: 8b542420 MOV EDX, dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00486af3: { // 0x486af3: 81e2ff000000 AND EDX, 0xFF
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00486af9: { // 0x486af9: 2bda SUB EBX, EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00486afb: { // 0x486afb: 03f2 ADD ESI, EDX
    s.si = integer::add(s.si,s.dx,32,flags);
  }
  L00486afd: { // 0x486afd: 03fa ADD EDI, EDX
    s.di = integer::add(s.di,s.dx,32,flags);
  }
  L00486aff: { // 0x486aff: 8d0450 LEA EAX, [EAX + EDX*2]
    s.ax = (s.ax+(s.dx * 2u));
  }
  L00486b02: { // 0x486b02: eb45 JMP 0x486B49
    goto L00486b49;
  }
  L00486b04: { // 0x486b04: 0fbe0f MOVSX ECX, byte ptr [EDI]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.di)),8));
  }
  L00486b07: { // 0x486b07: 8b542428 MOV EDX, dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00486b0b: { // 0x486b0b: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00486b0d: { // 0x486b0d: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00486b0f: { // 0x486b0f: 668b08 MOV CX, word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L00486b12: { // 0x486b12: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00486b13: { // 0x486b13: 3bd1 CMP EDX, ECX
    (void)integer::sub(s.dx,s.cx,32,flags);
  }
  L00486b15: { // 0x486b15: 7d26 JGE 0x486B3D
    if(integer::condition("JGE",flags)) goto L00486b3d;
  }
  L00486b17: { // 0x486b17: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00486b1b: { // 0x486b1b: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00486b1d: { // 0x486b1d: 8a16 MOV DL, byte ptr [ESI]
    s.dx = with_al(s.dx, m.r8((s.si)));
  }
  L00486b1f: { // 0x486b1f: 83c002 ADD EAX, 2
    s.ax = integer::add(s.ax,2u,32,flags);
  }
  L00486b22: { // 0x486b22: 8b4904 MOV ECX, dword ptr [ECX + 4]
    s.cx = m.r32((s.cx+4u));
  }
  L00486b25: { // 0x486b25: 8a1411 MOV DL, byte ptr [ECX + EDX]
    s.dx = with_al(s.dx, m.r8((s.cx+s.dx)));
  }
  L00486b28: { // 0x486b28: 8816 MOV byte ptr [ESI], DL
    m.w8((s.si), (s.dx & 0xffu));
  }
  L00486b2a: { // 0x486b2a: 8b542428 MOV EDX, dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00486b2e: { // 0x486b2e: 660fbe0f MOVSX CX, byte ptr [EDI]
    s.cx = with_ax(s.cx, std::uint32_t(integer::sign_extend(m.r8((s.di)),8)));
  }
  L00486b32: { // 0x486b32: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00486b34: { // 0x486b34: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00486b35: { // 0x486b35: 668950fe MOV word ptr [EAX - 2], DX
    m.w16((s.ax-2u), (s.dx & 0xffffu));
  }
  L00486b39: { // 0x486b39: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00486b3a: { // 0x486b3a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00486b3b: { // 0x486b3b: eb06 JMP 0x486B43
    goto L00486b43;
  }
  L00486b3d: { // 0x486b3d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L00486b3e: { // 0x486b3e: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L00486b3f: { // 0x486b3f: 83c002 ADD EAX, 2
    s.ax = integer::add(s.ax,2u,32,flags);
  }
  L00486b42: { // 0x486b42: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00486b43: { // 0x486b43: 8b0dac1f8200 MOV ECX, dword ptr [0x821FAC]
    s.cx = m.r32((0x00821facu));
  }
  L00486b49: { // 0x486b49: 3b411c CMP EAX, dword ptr [ECX + 0x1C]
    (void)integer::sub(s.ax,m.r32((s.cx+0x0000001cu)),32,flags);
  }
  L00486b4c: { // 0x486b4c: 7203 JC 0x486B51
    if(integer::condition("JC",flags)) goto L00486b51;
  }
  L00486b4e: { // 0x486b4e: 2b4120 SUB EAX, dword ptr [ECX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.cx+0x00000020u)),32,flags);
  }
  L00486b51: { // 0x486b51: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L00486b53: { // 0x486b53: 7f8a JG 0x486ADF
    if(integer::condition("JG",flags)) goto L00486adf;
  }
  L00486b55: { // 0x486b55: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00486b56: { // 0x486b56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00486b57: { // 0x486b57: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00486b58: { // 0x486b58: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00486b59: { // 0x486b59: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00486b5a: { // 0x486b5a: c22800 RET 0x28
    s.arithmetic_flags=flags; finish(m,s,f,40u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){f.push(m,continuation);Frame child{f.sp,f.sp,continuation};switch(target){
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
case 4745856u:f_00086a80(m,s,child,{});break;
default:throw std::domain_error("B514 unclosed call");}f.sp=child.sp;}
}
std::uint32_t run(Memory&original,const Inputs&i,std::uint32_t target){
 std::array<std::uint8_t,0x8000> stack{};const std::uint32_t base=i.cx-0x2000u+0x200000u,entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 s.bx=0x13579bdfu;s.si=0x2468ace0u;s.di=0x789abcdeu;
 Frame f{entry,entry,0x76543210u};m.w32(entry,0x76543210u);
 for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,i.arg[k]);
 m.w32(entry-8,i.stack_minus8);m.w32(((entry-4)&~7u)-8,i.stack_minus8);
 switch(target){case 0x34f80u:f_00034f80(m,s,f,{});break;case 0x9ebd0u:f_0009ebd0(m,s,f,{});break;default:throw std::domain_error("B514 invalid entry");}i.fp=s.fp;for(unsigned k=0;k<16;++k)i.arg[k]=m.r32(entry+4+4*k);return s.ax;}
}

namespace ra2::recovered::b514_240 {
using namespace recovery_b240;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00360ad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760ad0: { // 0x760ad0: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L00760ad3: { // 0x760ad3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760ad4: { // 0x760ad4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760ad5: { // 0x760ad5: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760ad6: { // 0x760ad6: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L00760ada: { // 0x760ada: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00760adc: { // 0x760adc: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760adf: { // 0x760adf: 394e08 CMP dword ptr [ESI + 0x8],ECX
    (void)integer::sub(m.r32((s.si+0x00000008u)),s.cx,32,flags);
  }
  L00760ae2: { // 0x760ae2: 0f852e010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760ae8: { // 0x760ae8: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760aeb: { // 0x760aeb: 8b5f0c MOV EBX,dword ptr [EDI + 0xc]
    s.bx = m.r32((s.di+0x0000000cu));
  }
  L00760aee: { // 0x760aee: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760af0: { // 0x760af0: 0f8520010000 JNZ 0x00760c16
    if(integer::condition("JNZ",flags)) goto L00760c16;
  }
  L00760af6: { // 0x760af6: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760af8: { // 0x760af8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760afa: { // 0x760afa: 7d1d JGE 0x00760b19
    if(integer::condition("JGE",flags)) goto L00760b19;
  }
  L00760afc: { // 0x760afc: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760afe: { // 0x760afe: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b00: { // 0x760b00: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L00760b02: { // 0x760b02: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b04: { // 0x760b04: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b06: { // 0x760b06: 894708 MOV dword ptr [EDI + 0x8],EAX
    m.w32((s.di+0x00000008u), s.ax);
  }
  L00760b09: { // 0x760b09: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00760b0b: { // 0x760b0b: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760b0e: { // 0x760b0e: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L00760b14: { // 0x760b14: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b16: { // 0x760b16: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  L00760b19: { // 0x760b19: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b1c: { // 0x760b1c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b1e: { // 0x760b1e: 7d25 JGE 0x00760b45
    if(integer::condition("JGE",flags)) goto L00760b45;
  }
  L00760b20: { // 0x760b20: 8b5f04 MOV EBX,dword ptr [EDI + 0x4]
    s.bx = m.r32((s.di+0x00000004u));
  }
  L00760b23: { // 0x760b23: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760b26: { // 0x760b26: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b28: { // 0x760b28: 895f04 MOV dword ptr [EDI + 0x4],EBX
    m.w32((s.di+0x00000004u), s.bx);
  }
  L00760b2b: { // 0x760b2b: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760b2e: { // 0x760b2e: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760b30: { // 0x760b30: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760b33: { // 0x760b33: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L00760b36: { // 0x760b36: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b39: { // 0x760b39: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  L00760b40: { // 0x760b40: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760b42: { // 0x760b42: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L00760b45: { // 0x760b45: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00760b47: { // 0x760b47: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L00760b4a: { // 0x760b4a: 8b5e08 MOV EBX,dword ptr [ESI + 0x8]
    s.bx = m.r32((s.si+0x00000008u));
  }
  L00760b4d: { // 0x760b4d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00760b4f: { // 0x760b4f: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760b51: { // 0x760b51: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b53: { // 0x760b53: 7e10 JLE 0x00760b65
    if(integer::condition("JLE",flags)) goto L00760b65;
  }
  L00760b55: { // 0x760b55: 8b5f08 MOV EBX,dword ptr [EDI + 0x8]
    s.bx = m.r32((s.di+0x00000008u));
  }
  L00760b58: { // 0x760b58: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b5a: { // 0x760b5a: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L00760b5d: { // 0x760b5d: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b60: { // 0x760b60: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b62: { // 0x760b62: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760b65: { // 0x760b65: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760b68: { // 0x760b68: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760b6b: { // 0x760b6b: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00760b6e: { // 0x760b6e: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760b70: { // 0x760b70: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00760b72: { // 0x760b72: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b74: { // 0x760b74: 7e10 JLE 0x00760b86
    if(integer::condition("JLE",flags)) goto L00760b86;
  }
  L00760b76: { // 0x760b76: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760b79: { // 0x760b79: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00760b7b: { // 0x760b7b: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760b7e: { // 0x760b7e: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760b81: { // 0x760b81: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760b83: { // 0x760b83: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760b86: { // 0x760b86: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b88: { // 0x760b88: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760b8a: { // 0x760b8a: 7d1e JGE 0x00760baa
    if(integer::condition("JGE",flags)) goto L00760baa;
  }
  L00760b8c: { // 0x760b8c: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L00760b8e: { // 0x760b8e: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760b90: { // 0x760b90: 891e MOV dword ptr [ESI],EBX
    m.w32((s.si), s.bx);
  }
  L00760b92: { // 0x760b92: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00760b94: { // 0x760b94: 8b5708 MOV EDX,dword ptr [EDI + 0x8]
    s.dx = m.r32((s.di+0x00000008u));
  }
  L00760b97: { // 0x760b97: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760b99: { // 0x760b99: 895708 MOV dword ptr [EDI + 0x8],EDX
    m.w32((s.di+0x00000008u), s.dx);
  }
  L00760b9c: { // 0x760b9c: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760b9f: { // 0x760b9f: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760ba1: { // 0x760ba1: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760ba4: { // 0x760ba4: c70700000000 MOV dword ptr [EDI],0x0
    m.w32((s.di), 0x00000000u);
  }
  L00760baa: { // 0x760baa: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bad: { // 0x760bad: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760baf: { // 0x760baf: 7d22 JGE 0x00760bd3
    if(integer::condition("JGE",flags)) goto L00760bd3;
  }
  L00760bb1: { // 0x760bb1: 8b5e04 MOV EBX,dword ptr [ESI + 0x4]
    s.bx = m.r32((s.si+0x00000004u));
  }
  L00760bb4: { // 0x760bb4: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00760bb6: { // 0x760bb6: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L00760bb9: { // 0x760bb9: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bbc: { // 0x760bbc: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  L00760bbf: { // 0x760bbf: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00760bc1: { // 0x760bc1: 89570c MOV dword ptr [EDI + 0xc],EDX
    m.w32((s.di+0x0000000cu), s.dx);
  }
  L00760bc4: { // 0x760bc4: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760bc7: { // 0x760bc7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00760bc9: { // 0x760bc9: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760bcc: { // 0x760bcc: c7470400000000 MOV dword ptr [EDI + 0x4],0x0
    m.w32((s.di+0x00000004u), 0x00000000u);
  }
  L00760bd3: { // 0x760bd3: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00760bd7: { // 0x760bd7: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00760bda: { // 0x760bda: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00760bdc: { // 0x760bdc: 8b5a08 MOV EBX,dword ptr [EDX + 0x8]
    s.bx = m.r32((s.dx+0x00000008u));
  }
  L00760bdf: { // 0x760bdf: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760be1: { // 0x760be1: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760be3: { // 0x760be3: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L00760be5: { // 0x760be5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760be7: { // 0x760be7: 7e0d JLE 0x00760bf6
    if(integer::condition("JLE",flags)) goto L00760bf6;
  }
  L00760be9: { // 0x760be9: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760beb: { // 0x760beb: 894f08 MOV dword ptr [EDI + 0x8],ECX
    m.w32((s.di+0x00000008u), s.cx);
  }
  L00760bee: { // 0x760bee: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760bf1: { // 0x760bf1: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760bf3: { // 0x760bf3: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  L00760bf6: { // 0x760bf6: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  L00760bf9: { // 0x760bf9: 8b5a0c MOV EBX,dword ptr [EDX + 0xc]
    s.bx = m.r32((s.dx+0x0000000cu));
  }
  L00760bfc: { // 0x760bfc: 8b4f0c MOV ECX,dword ptr [EDI + 0xc]
    s.cx = m.r32((s.di+0x0000000cu));
  }
  L00760bff: { // 0x760bff: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00760c01: { // 0x760c01: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00760c03: { // 0x760c03: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c05: { // 0x760c05: 7e63 JLE 0x00760c6a
    if(integer::condition("JLE",flags)) goto L00760c6a;
  }
  L00760c07: { // 0x760c07: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c09: { // 0x760c09: 894f0c MOV dword ptr [EDI + 0xc],ECX
    m.w32((s.di+0x0000000cu), s.cx);
  }
  L00760c0c: { // 0x760c0c: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L00760c0f: { // 0x760c0f: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00760c11: { // 0x760c11: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L00760c14: { // 0x760c14: eb54 JMP 0x00760c6a
    goto L00760c6a;
  }
  L00760c16: { // 0x760c16: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c18: { // 0x760c18: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c1a: { // 0x760c1a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760c1b: { // 0x760c1b: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c1d: { // 0x760c1d: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c21: { // 0x760c21: e8caf1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736358u); flags=s.arithmetic_flags;
  }
  L00760c26: { // 0x760c26: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c28: { // 0x760c28: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00760c2a: { // 0x760c2a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2c: { // 0x760c2c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00760c2e: { // 0x760c2e: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c30: { // 0x760c30: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c33: { // 0x760c33: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c36: { // 0x760c36: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c39: { // 0x760c39: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c3c: { // 0x760c3c: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c3f: { // 0x760c3f: 8b4c242c MOV ECX,dword ptr [ESP + 0x2c]
    s.cx = m.r32((f.sp+0x0000002cu));
  }
  L00760c43: { // 0x760c43: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c46: { // 0x760c46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760c47: { // 0x760c47: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c49: { // 0x760c49: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00760c4d: { // 0x760c4d: e89ef1cbff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7736402u); flags=s.arithmetic_flags;
  }
  L00760c52: { // 0x760c52: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00760c54: { // 0x760c54: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L00760c56: { // 0x760c56: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L00760c58: { // 0x760c58: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00760c5b: { // 0x760c5b: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00760c5e: { // 0x760c5e: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760c61: { // 0x760c61: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L00760c64: { // 0x760c64: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00760c67: { // 0x760c67: 89420c MOV dword ptr [EDX + 0xc],EAX
    m.w32((s.dx+0x0000000cu), s.ax);
  }
  L00760c6a: { // 0x760c6a: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760c6d: { // 0x760c6d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c6f: { // 0x760c6f: 7e23 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c71: { // 0x760c71: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760c74: { // 0x760c74: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c76: { // 0x760c76: 7e1c JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c78: { // 0x760c78: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760c7b: { // 0x760c7b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c7d: { // 0x760c7d: 7e15 JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c7f: { // 0x760c7f: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760c82: { // 0x760c82: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760c84: { // 0x760c84: 7e0e JLE 0x00760c94
    if(integer::condition("JLE",flags)) goto L00760c94;
  }
  L00760c86: { // 0x760c86: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c87: { // 0x760c87: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c88: { // 0x760c88: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00760c8d: { // 0x760c8d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c8e: { // 0x760c8e: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c91: { // 0x760c91: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L00760c94: { // 0x760c94: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760c95: { // 0x760c95: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760c96: { // 0x760c96: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00760c98: { // 0x760c98: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760c99: { // 0x760c99: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L00760c9c: { // 0x760c9c: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00034a00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00434a00: { // 0x434a00: 83ec48 SUB ESP,0x48
    f.sp = integer::sub(f.sp,0x00000048u,32,flags);
  }
  L00434a03: { // 0x434a03: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00434a07: { // 0x434a07: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434a08: { // 0x434a08: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434a09: { // 0x434a09: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00434a0a: { // 0x434a0a: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00434a0c: { // 0x434a0c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434a0d: { // 0x434a0d: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00434a0f: { // 0x434a0f: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L00434a11: { // 0x434a11: 89542448 MOV dword ptr [ESP + 0x48],EDX
    m.w32((f.sp+0x00000048u), s.dx);
  }
  L00434a15: { // 0x434a15: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434a17: { // 0x434a17: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00434a1a: { // 0x434a1a: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00434a1e: { // 0x434a1e: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00434a22: { // 0x434a22: c644246800 MOV byte ptr [ESP + 0x68],0x0
    m.w8((f.sp+0x00000068u), 0x00000000u);
  }
  L00434a27: { // 0x434a27: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00434a2a: { // 0x434a2a: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00434a2e: { // 0x434a2e: 89542450 MOV dword ptr [ESP + 0x50],EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L00434a32: { // 0x434a32: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00434a36: { // 0x434a36: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00434a39: { // 0x434a39: 897c245c MOV dword ptr [ESP + 0x5c],EDI
    m.w32((f.sp+0x0000005cu), s.di);
  }
  L00434a3d: { // 0x434a3d: 89442454 MOV dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), s.ax);
  }
  L00434a41: { // 0x434a41: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00434a43: { // 0x434a43: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00434a47: { // 0x434a47: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00434a49: { // 0x434a49: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L00434a4c: { // 0x434a4c: 897c2414 MOV dword ptr [ESP + 0x14],EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L00434a50: { // 0x434a50: 8944243c MOV dword ptr [ESP + 0x3c],EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00434a54: { // 0x434a54: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  L00434a58: { // 0x434a58: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00434a5b: { // 0x434a5b: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  L00434a5f: { // 0x434a5f: 89442440 MOV dword ptr [ESP + 0x40],EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00434a63: { // 0x434a63: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00434a67: { // 0x434a67: 8b520c MOV EDX,dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L00434a6a: { // 0x434a6a: 895c2430 MOV dword ptr [ESP + 0x30],EBX
    m.w32((f.sp+0x00000030u), s.bx);
  }
  L00434a6e: { // 0x434a6e: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L00434a71: { // 0x434a71: 89542444 MOV dword ptr [ESP + 0x44],EDX
    m.w32((f.sp+0x00000044u), s.dx);
  }
  L00434a75: { // 0x434a75: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  L00434a79: { // 0x434a79: 897c2428 MOV dword ptr [ESP + 0x28],EDI
    m.w32((f.sp+0x00000028u), s.di);
  }
  L00434a7d: { // 0x434a7d: 8d14c5f8907b00 LEA EDX,[EAX*0x8 + 0x7b90f8]
    s.dx = ((s.ax * 0x00000008u)+0x007b90f8u);
  }
  L00434a84: { // 0x434a84: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L00434a88: { // 0x434a88: 89542474 MOV dword ptr [ESP + 0x74],EDX
    m.w32((f.sp+0x00000074u), s.dx);
  }
  L00434a8c: { // 0x434a8c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434a8d: { // 0x434a8d: 8d542460 LEA EDX,[ESP + 0x60]
    s.dx = (f.sp+0x00000060u);
  }
  L00434a91: { // 0x434a91: 8d44246c LEA EAX,[ESP + 0x6c]
    s.ax = (f.sp+0x0000006cu);
  }
  L00434a95: { // 0x434a95: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434a96: { // 0x434a96: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434a97: { // 0x434a97: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00434a9b: { // 0x434a9b: 8d542454 LEA EDX,[ESP + 0x54]
    s.dx = (f.sp+0x00000054u);
  }
  L00434a9f: { // 0x434a9f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434aa0: { // 0x434aa0: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434aa4: { // 0x434aa4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434aa5: { // 0x434aa5: 8d44244c LEA EAX,[ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L00434aa9: { // 0x434aa9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434aaa: { // 0x434aaa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434aab: { // 0x434aab: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00434aad: { // 0x434aad: e83ec23200 CALL 0x00760cf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760cf0u,4410034u); flags=s.arithmetic_flags;
  }
  L00434ab2: { // 0x434ab2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00434ab4: { // 0x434ab4: 750a JNZ 0x00434ac0
    if(integer::condition("JNZ",flags)) goto L00434ac0;
  }
  L00434ab6: { // 0x434ab6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00434ab7: { // 0x434ab7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00434ab8: { // 0x434ab8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00434ab9: { // 0x434ab9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00434aba: { // 0x434aba: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00434abd: { // 0x434abd: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
  L00434ac0: { // 0x434ac0: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00434ac6: { // 0x434ac6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434ac8: { // 0x434ac8: 7429 JZ 0x00434af3
    if(integer::condition("JZ",flags)) goto L00434af3;
  }
  L00434aca: { // 0x434aca: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434acc: { // 0x434acc: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L00434ad0: { // 0x434ad0: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00434ad4: { // 0x434ad4: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  L00434ad6: { // 0x434ad6: 8b5604 MOV EDX,dword ptr [ESI + 0x4]
    s.dx = m.r32((s.si+0x00000004u));
  }
  L00434ad9: { // 0x434ad9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434adb: { // 0x434adb: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L00434ade: { // 0x434ade: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00434ae2: { // 0x434ae2: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434ae4: { // 0x434ae4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434ae5: { // 0x434ae5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00434ae6: { // 0x434ae6: e845c7fdff CALL 0x00411230
    s.arithmetic_flags=flags; invoke(m,s,f,0x00411230u,4410091u); flags=s.arithmetic_flags;
  }
  L00434aeb: { // 0x434aeb: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L00434aef: { // 0x434aef: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434af3: { // 0x434af3: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L00434af9: { // 0x434af9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434afb: { // 0x434afb: 0f84c6000000 JZ 0x00434bc7
    if(integer::condition("JZ",flags)) goto L00434bc7;
  }
  L00434b01: { // 0x434b01: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00434b05: { // 0x434b05: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L00434b08: { // 0x434b08: 8b6904 MOV EBP,dword ptr [ECX + 0x4]
    s.bp = m.r32((s.cx+0x00000004u));
  }
  L00434b0b: { // 0x434b0b: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434b0d: { // 0x434b0d: 8b5c2438 MOV EBX,dword ptr [ESP + 0x38]
    s.bx = m.r32((f.sp+0x00000038u));
  }
  L00434b11: { // 0x434b11: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00434b13: { // 0x434b13: 89442434 MOV dword ptr [ESP + 0x34],EAX
    m.w32((f.sp+0x00000034u), s.ax);
  }
  L00434b17: { // 0x434b17: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L00434b19: { // 0x434b19: 03d3 ADD EDX,EBX
    s.dx = integer::add(s.dx,s.bx,32,flags);
  }
  L00434b1b: { // 0x434b1b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434b1c: { // 0x434b1c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434b1d: { // 0x434b1d: e85ed13200 CALL 0x00761c80
    s.arithmetic_flags=flags; invoke(m,s,f,0x00761c80u,4410146u); flags=s.arithmetic_flags;
  }
  L00434b22: { // 0x434b22: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L00434b24: { // 0x434b24: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434b26: { // 0x434b26: 8b7c2474 MOV EDI,dword ptr [ESP + 0x74]
    s.di = m.r32((f.sp+0x00000074u));
  }
  L00434b2a: { // 0x434b2a: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00434b2d: { // 0x434b2d: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  L00434b30: { // 0x434b30: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L00434b34: { // 0x434b34: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00434b38: { // 0x434b38: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b39: { // 0x434b39: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434b3b: { // 0x434b3b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00434b3d: { // 0x434b3d: 8a4714 MOV AL,byte ptr [EDI + 0x14]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000014u)));
  }
  L00434b40: { // 0x434b40: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00434b42: { // 0x434b42: 7430 JZ 0x00434b74
    if(integer::condition("JZ",flags)) goto L00434b74;
  }
  L00434b44: { // 0x434b44: 8b15ac1f8200 MOV EDX,dword ptr [0x00821fac]
    s.dx = m.r32((0x00821facu));
  }
  L00434b4a: { // 0x434b4a: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00434b4d: { // 0x434b4d: 668b4224 MOV AX,word ptr [EDX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.dx+0x00000024u)));
  }
  L00434b51: { // 0x434b51: 66034204 ADD AX,word ptr [EDX + 0x4]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000004u)),16,flags));
  }
  L00434b55: { // 0x434b55: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00434b59: { // 0x434b59: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434b5b: { // 0x434b5b: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434b5f: { // 0x434b5f: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L00434b63: { // 0x434b63: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00434b68: { // 0x434b68: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434b6a: { // 0x434b6a: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b6b: { // 0x434b6b: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434b6d: { // 0x434b6d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00434b6f: { // 0x434b6f: 0faff9 IMUL EDI,ECX
    s.di = integer::imul(s.di,s.cx,32,flags);
  }
  L00434b72: { // 0x434b72: eb53 JMP 0x00434bc7
    goto L00434bc7;
  }
  L00434b74: { // 0x434b74: 8b15ac1f8200 MOV EDX,dword ptr [0x00821fac]
    s.dx = m.r32((0x00821facu));
  }
  L00434b7a: { // 0x434b7a: 8b5c2444 MOV EBX,dword ptr [ESP + 0x44]
    s.bx = m.r32((f.sp+0x00000044u));
  }
  L00434b7e: { // 0x434b7e: 668b4224 MOV AX,word ptr [EDX + 0x24]
    s.ax = with_ax(s.ax, m.r16((s.dx+0x00000024u)));
  }
  L00434b82: { // 0x434b82: 66034204 ADD AX,word ptr [EDX + 0x4]
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),m.r16((s.dx+0x00000004u)),16,flags));
  }
  L00434b86: { // 0x434b86: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00434b8a: { // 0x434b8a: 2bc3 SUB EAX,EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00434b8c: { // 0x434b8c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00434b8e: { // 0x434b8e: 662b4604 SUB AX,word ptr [ESI + 0x4]
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),m.r16((s.si+0x00000004u)),16,flags));
  }
  L00434b92: { // 0x434b92: 8b742470 MOV ESI,dword ptr [ESP + 0x70]
    s.si = m.r32((f.sp+0x00000070u));
  }
  L00434b96: { // 0x434b96: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00434b97: { // 0x434b97: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L00434b9c: { // 0x434b9c: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00434b9e: { // 0x434b9e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434b9f: { // 0x434b9f: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434ba1: { // 0x434ba1: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00434ba3: { // 0x434ba3: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00434ba5: { // 0x434ba5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434ba6: { // 0x434ba6: 0faff9 IMUL EDI,ECX
    s.di = integer::imul(s.di,s.cx,32,flags);
  }
  L00434ba9: { // 0x434ba9: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434bab: { // 0x434bab: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L00434bad: { // 0x434bad: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00434baf: { // 0x434baf: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00434bb0: { // 0x434bb0: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00434bb2: { // 0x434bb2: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434bb6: { // 0x434bb6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00434bb8: { // 0x434bb8: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00434bba: { // 0x434bba: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434bbc: { // 0x434bbc: 7509 JNZ 0x00434bc7
    if(integer::condition("JNZ",flags)) goto L00434bc7;
  }
  L00434bbe: { // 0x434bbe: 8b4c2474 MOV ECX,dword ptr [ESP + 0x74]
    s.cx = m.r32((f.sp+0x00000074u));
  }
  L00434bc2: { // 0x434bc2: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00434bc4: { // 0x434bc4: 037910 ADD EDI,dword ptr [ECX + 0x10]
    s.di = integer::add(s.di,m.r32((s.cx+0x00000010u)),32,flags);
  }
  L00434bc7: { // 0x434bc7: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434bcb: { // 0x434bcb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bcd: { // 0x434bcd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434bcf: { // 0x434bcf: ff5270 CALL dword ptr [EDX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000070u)),4410322u); flags=s.arithmetic_flags;
  }
  L00434bd2: { // 0x434bd2: 0faf442440 IMUL EAX,dword ptr [ESP + 0x40]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000040u)),32,flags);
  }
  L00434bd7: { // 0x434bd7: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L00434bdb: { // 0x434bdb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434bdd: { // 0x434bdd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bdf: { // 0x434bdf: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410338u); flags=s.arithmetic_flags;
  }
  L00434be2: { // 0x434be2: 39442470 CMP dword ptr [ESP + 0x70],EAX
    (void)integer::sub(m.r32((f.sp+0x00000070u)),s.ax,32,flags);
  }
  L00434be6: { // 0x434be6: 757e JNZ 0x00434c66
    if(integer::condition("JNZ",flags)) goto L00434c66;
  }
  L00434be8: { // 0x434be8: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434bea: { // 0x434bea: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434bec: { // 0x434bec: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410351u); flags=s.arithmetic_flags;
  }
  L00434bef: { // 0x434bef: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434bf3: { // 0x434bf3: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00434bf5: { // 0x434bf5: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00434bf7: { // 0x434bf7: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410362u); flags=s.arithmetic_flags;
  }
  L00434bfa: { // 0x434bfa: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00434bfc: { // 0x434bfc: 7564 JNZ 0x00434c62
    if(integer::condition("JNZ",flags)) goto L00434c62;
  }
  L00434bfe: { // 0x434bfe: 8b442450 MOV EAX,dword ptr [ESP + 0x50]
    s.ax = m.r32((f.sp+0x00000050u));
  }
  L00434c02: { // 0x434c02: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00434c06: { // 0x434c06: 0faf442454 IMUL EAX,dword ptr [ESP + 0x54]
    s.ax = integer::imul(s.ax,m.r32((f.sp+0x00000054u)),32,flags);
  }
  L00434c0b: { // 0x434c0b: 0faf4c2444 IMUL ECX,dword ptr [ESP + 0x44]
    s.cx = integer::imul(s.cx,m.r32((f.sp+0x00000044u)),32,flags);
  }
  L00434c10: { // 0x434c10: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00434c12: { // 0x434c12: 7c02 JL 0x00434c16
    if(integer::condition("JL",flags)) goto L00434c16;
  }
  L00434c14: { // 0x434c14: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00434c16: { // 0x434c16: 8a4c2468 MOV CL,byte ptr [ESP + 0x68]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000068u)));
  }
  L00434c1a: { // 0x434c1a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00434c1c: { // 0x434c1c: 8b4c246c MOV ECX,dword ptr [ESP + 0x6c]
    s.cx = m.r32((f.sp+0x0000006cu));
  }
  L00434c20: { // 0x434c20: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434c22: { // 0x434c22: 741e JZ 0x00434c42
    if(integer::condition("JZ",flags)) goto L00434c42;
  }
  L00434c24: { // 0x434c24: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L00434c29: { // 0x434c29: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2b: { // 0x434c2b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2d: { // 0x434c2d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c2f: { // 0x434c2f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c30: { // 0x434c30: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434c34: { // 0x434c34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c35: { // 0x434c35: 8b442474 MOV EAX,dword ptr [ESP + 0x74]
    s.ax = m.r32((f.sp+0x00000074u));
  }
  L00434c39: { // 0x434c39: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c3a: { // 0x434c3a: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4410429u); flags=s.arithmetic_flags;
  }
  L00434c3d: { // 0x434c3d: e9b5020000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434c42: { // 0x434c42: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c44: { // 0x434c44: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  L00434c49: { // 0x434c49: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4b: { // 0x434c4b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4d: { // 0x434c4d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434c4f: { // 0x434c4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c50: { // 0x434c50: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434c54: { // 0x434c54: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c55: { // 0x434c55: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434c59: { // 0x434c59: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434c5a: { // 0x434c5a: ff5204 CALL dword ptr [EDX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000004u)),4410461u); flags=s.arithmetic_flags;
  }
  L00434c5d: { // 0x434c5d: e995020000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434c62: { // 0x434c62: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434c66: { // 0x434c66: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434c6a: { // 0x434c6a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434c6c: { // 0x434c6c: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410479u); flags=s.arithmetic_flags;
  }
  L00434c6f: { // 0x434c6f: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L00434c73: { // 0x434c73: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434c75: { // 0x434c75: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434c77: { // 0x434c77: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),4410490u); flags=s.arithmetic_flags;
  }
  L00434c7a: { // 0x434c7a: 8b0dac1f8200 MOV ECX,dword ptr [0x00821fac]
    s.cx = m.r32((0x00821facu));
  }
  L00434c80: { // 0x434c80: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00434c84: { // 0x434c84: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434c86: { // 0x434c86: 7407 JZ 0x00434c8f
    if(integer::condition("JZ",flags)) goto L00434c8f;
  }
  L00434c88: { // 0x434c88: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  L00434c8b: { // 0x434c8b: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00434c8f: { // 0x434c8f: 8b0df4988100 MOV ECX,dword ptr [0x008198f4]
    s.cx = m.r32((0x008198f4u));
  }
  L00434c95: { // 0x434c95: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00434c97: { // 0x434c97: 7407 JZ 0x00434ca0
    if(integer::condition("JZ",flags)) goto L00434ca0;
  }
  L00434c99: { // 0x434c99: 8b5128 MOV EDX,dword ptr [ECX + 0x28]
    s.dx = m.r32((s.cx+0x00000028u));
  }
  L00434c9c: { // 0x434c9c: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00434ca0: { // 0x434ca0: 8a4c2468 MOV CL,byte ptr [ESP + 0x68]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000068u)));
  }
  L00434ca4: { // 0x434ca4: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00434ca6: { // 0x434ca6: 0f84c4000000 JZ 0x00434d70
    if(integer::condition("JZ",flags)) goto L00434d70;
  }
  L00434cac: { // 0x434cac: 8b4c2470 MOV ECX,dword ptr [ESP + 0x70]
    s.cx = m.r32((f.sp+0x00000070u));
  }
  L00434cb0: { // 0x434cb0: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434cb4: { // 0x434cb4: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L00434cb6: { // 0x434cb6: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00434cb8: { // 0x434cb8: 894c2470 MOV dword ptr [ESP + 0x70],ECX
    m.w32((f.sp+0x00000070u), s.cx);
  }
  L00434cbc: { // 0x434cbc: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434cc0: { // 0x434cc0: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00434cc4: { // 0x434cc4: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434cc8: { // 0x434cc8: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434cca: { // 0x434cca: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00434cce: { // 0x434cce: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434cd0: { // 0x434cd0: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00434cd2: { // 0x434cd2: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00434cd6: { // 0x434cd6: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410585u); flags=s.arithmetic_flags;
  }
  L00434cd9: { // 0x434cd9: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00434cdd: { // 0x434cdd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434cdf: { // 0x434cdf: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00434ce0: { // 0x434ce0: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00434ce3: { // 0x434ce3: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L00434ce7: { // 0x434ce7: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434ce9: { // 0x434ce9: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L00434ced: { // 0x434ced: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434cef: { // 0x434cef: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),4410610u); flags=s.arithmetic_flags;
  }
  L00434cf2: { // 0x434cf2: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00434cf6: { // 0x434cf6: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00434cf7: { // 0x434cf7: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L00434cfa: { // 0x434cfa: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434cfe: { // 0x434cfe: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434d00: { // 0x434d00: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434d05: { // 0x434d05: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d07: { // 0x434d07: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434d0b: { // 0x434d0b: 742d JZ 0x00434d3a
    if(integer::condition("JZ",flags)) goto L00434d3a;
  }
  L00434d0d: { // 0x434d0d: 8b4828 MOV ECX,dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L00434d10: { // 0x434d10: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00434d12: { // 0x434d12: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434d14: { // 0x434d14: c1e21f SHL EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::left);
  }
  L00434d17: { // 0x434d17: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00434d19: { // 0x434d19: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L00434d1d: { // 0x434d1d: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00434d1f: { // 0x434d1f: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434d23: { // 0x434d23: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L00434d26: { // 0x434d26: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434d28: { // 0x434d28: 7203 JC 0x00434d2d
    if(integer::condition("JC",flags)) goto L00434d2d;
  }
  L00434d2a: { // 0x434d2a: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434d2d: { // 0x434d2d: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L00434d32: { // 0x434d32: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00434d34: { // 0x434d34: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434d38: { // 0x434d38: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L00434d3a: { // 0x434d3a: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434d3f: { // 0x434d3f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d41: { // 0x434d41: 7431 JZ 0x00434d74
    if(integer::condition("JZ",flags)) goto L00434d74;
  }
  L00434d43: { // 0x434d43: 8b4028 MOV EAX,dword ptr [EAX + 0x28]
    s.ax = m.r32((s.ax+0x00000028u));
  }
  L00434d46: { // 0x434d46: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00434d48: { // 0x434d48: f7da NEG EDX
    s.dx = integer::sub(0u,s.dx,32,flags);
  }
  L00434d4a: { // 0x434d4a: c1e21f SHL EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::left);
  }
  L00434d4d: { // 0x434d4d: 2bd0 SUB EDX,EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L00434d4f: { // 0x434d4f: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00434d53: { // 0x434d53: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00434d55: { // 0x434d55: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434d59: { // 0x434d59: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434d5c: { // 0x434d5c: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434d62: { // 0x434d62: 3b421c CMP EAX,dword ptr [EDX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000001cu)),32,flags);
  }
  L00434d65: { // 0x434d65: 7203 JC 0x00434d6a
    if(integer::condition("JC",flags)) goto L00434d6a;
  }
  L00434d67: { // 0x434d67: 2b4220 SUB EAX,dword ptr [EDX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434d6a: { // 0x434d6a: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434d6e: { // 0x434d6e: eb04 JMP 0x00434d74
    goto L00434d74;
  }
  L00434d70: { // 0x434d70: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434d74: { // 0x434d74: 8b442454 MOV EAX,dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L00434d78: { // 0x434d78: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L00434d7c: { // 0x434d7c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00434d7e: { // 0x434d7e: 7c02 JL 0x00434d82
    if(integer::condition("JL",flags)) goto L00434d82;
  }
  L00434d80: { // 0x434d80: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00434d82: { // 0x434d82: 8a542468 MOV DL,byte ptr [ESP + 0x68]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000068u)));
  }
  L00434d86: { // 0x434d86: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00434d88: { // 0x434d88: 0f84b6000000 JZ 0x00434e44
    if(integer::condition("JZ",flags)) goto L00434e44;
  }
  L00434d8e: { // 0x434d8e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434d90: { // 0x434d90: 0f8e65010000 JLE 0x00434efb
    if(integer::condition("JLE",flags)) goto L00434efb;
  }
  L00434d96: { // 0x434d96: 8b74246c MOV ESI,dword ptr [ESP + 0x6c]
    s.si = m.r32((f.sp+0x0000006cu));
  }
  L00434d9a: { // 0x434d9a: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434d9e: { // 0x434d9e: 8b442478 MOV EAX,dword ptr [ESP + 0x78]
    s.ax = m.r32((f.sp+0x00000078u));
  }
  L00434da2: { // 0x434da2: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00434da4: { // 0x434da4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434da5: { // 0x434da5: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00434da9: { // 0x434da9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434daa: { // 0x434daa: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  L00434dae: { // 0x434dae: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434daf: { // 0x434daf: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434db0: { // 0x434db0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434db1: { // 0x434db1: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  L00434db5: { // 0x434db5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00434db6: { // 0x434db6: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00434db7: { // 0x434db7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434db9: { // 0x434db9: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4410812u); flags=s.arithmetic_flags;
  }
  L00434dbc: { // 0x434dbc: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434dc0: { // 0x434dc0: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L00434dc4: { // 0x434dc4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00434dc8: { // 0x434dc8: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00434dca: { // 0x434dca: 8b542470 MOV EDX,dword ptr [ESP + 0x70]
    s.dx = m.r32((f.sp+0x00000070u));
  }
  L00434dce: { // 0x434dce: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434dd2: { // 0x434dd2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00434dd4: { // 0x434dd4: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00434dd8: { // 0x434dd8: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434ddd: { // 0x434ddd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434ddf: { // 0x434ddf: 7429 JZ 0x00434e0a
    if(integer::condition("JZ",flags)) goto L00434e0a;
  }
  L00434de1: { // 0x434de1: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434de5: { // 0x434de5: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434de9: { // 0x434de9: 8b5018 MOV EDX,dword ptr [EAX + 0x18]
    s.dx = m.r32((s.ax+0x00000018u));
  }
  L00434dec: { // 0x434dec: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434dee: { // 0x434dee: 7303 JNC 0x00434df3
    if(integer::condition("JNC",flags)) goto L00434df3;
  }
  L00434df0: { // 0x434df0: 036820 ADD EBP,dword ptr [EAX + 0x20]
    s.bp = integer::add(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434df3: { // 0x434df3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00434df7: { // 0x434df7: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00434df9: { // 0x434df9: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434dfd: { // 0x434dfd: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434dff: { // 0x434dff: 7c09 JL 0x00434e0a
    if(integer::condition("JL",flags)) goto L00434e0a;
  }
  L00434e01: { // 0x434e01: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00434e05: { // 0x434e05: 037a10 ADD EDI,dword ptr [EDX + 0x10]
    s.di = integer::add(s.di,m.r32((s.dx+0x00000010u)),32,flags);
  }
  L00434e08: { // 0x434e08: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00434e0a: { // 0x434e0a: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434e0f: { // 0x434e0f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e11: { // 0x434e11: 741d JZ 0x00434e30
    if(integer::condition("JZ",flags)) goto L00434e30;
  }
  L00434e13: { // 0x434e13: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434e17: { // 0x434e17: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00434e1b: { // 0x434e1b: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434e1e: { // 0x434e1e: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434e24: { // 0x434e24: 3b4218 CMP EAX,dword ptr [EDX + 0x18]
    (void)integer::sub(s.ax,m.r32((s.dx+0x00000018u)),32,flags);
  }
  L00434e27: { // 0x434e27: 7303 JNC 0x00434e2c
    if(integer::condition("JNC",flags)) goto L00434e2c;
  }
  L00434e29: { // 0x434e29: 034220 ADD EAX,dword ptr [EDX + 0x20]
    s.ax = integer::add(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434e2c: { // 0x434e2c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434e30: { // 0x434e30: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00434e34: { // 0x434e34: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00434e35: { // 0x434e35: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434e39: { // 0x434e39: 0f855fffffff JNZ 0x00434d9e
    if(integer::condition("JNZ",flags)) goto L00434d9e;
  }
  L00434e3f: { // 0x434e3f: e9b3000000 JMP 0x00434ef7
    goto L00434ef7;
  }
  L00434e44: { // 0x434e44: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e46: { // 0x434e46: 0f8eaf000000 JLE 0x00434efb
    if(integer::condition("JLE",flags)) goto L00434efb;
  }
  L00434e4c: { // 0x434e4c: 8b74246c MOV ESI,dword ptr [ESP + 0x6c]
    s.si = m.r32((f.sp+0x0000006cu));
  }
  L00434e50: { // 0x434e50: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434e54: { // 0x434e54: 8b542478 MOV EDX,dword ptr [ESP + 0x78]
    s.dx = m.r32((f.sp+0x00000078u));
  }
  L00434e58: { // 0x434e58: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00434e5a: { // 0x434e5a: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e5b: { // 0x434e5b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00434e5f: { // 0x434e5f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434e61: { // 0x434e61: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e62: { // 0x434e62: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  L00434e66: { // 0x434e66: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00434e67: { // 0x434e67: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00434e68: { // 0x434e68: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e69: { // 0x434e69: 8b542428 MOV EDX,dword ptr [ESP + 0x28]
    s.dx = m.r32((f.sp+0x00000028u));
  }
  L00434e6d: { // 0x434e6d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00434e6e: { // 0x434e6e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00434e6f: { // 0x434e6f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434e71: { // 0x434e71: ff5004 CALL dword ptr [EAX + 0x4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000004u)),4410996u); flags=s.arithmetic_flags;
  }
  L00434e74: { // 0x434e74: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L00434e78: { // 0x434e78: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L00434e7c: { // 0x434e7c: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00434e80: { // 0x434e80: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00434e82: { // 0x434e82: 8b442470 MOV EAX,dword ptr [ESP + 0x70]
    s.ax = m.r32((f.sp+0x00000070u));
  }
  L00434e86: { // 0x434e86: 894c245c MOV dword ptr [ESP + 0x5c],ECX
    m.w32((f.sp+0x0000005cu), s.cx);
  }
  L00434e8a: { // 0x434e8a: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L00434e8c: { // 0x434e8c: a1ac1f8200 MOV EAX,[0x00821fac]
    s.ax = m.r32((0x00821facu));
  }
  L00434e91: { // 0x434e91: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434e93: { // 0x434e93: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00434e97: { // 0x434e97: 7429 JZ 0x00434ec2
    if(integer::condition("JZ",flags)) goto L00434ec2;
  }
  L00434e99: { // 0x434e99: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L00434e9d: { // 0x434e9d: 8d6c5500 LEA EBP,[EBP + EDX*0x2]
    s.bp = (s.bp+(s.dx * 0x00000002u));
  }
  L00434ea1: { // 0x434ea1: 8b501c MOV EDX,dword ptr [EAX + 0x1c]
    s.dx = m.r32((s.ax+0x0000001cu));
  }
  L00434ea4: { // 0x434ea4: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00434ea6: { // 0x434ea6: 7203 JC 0x00434eab
    if(integer::condition("JC",flags)) goto L00434eab;
  }
  L00434ea8: { // 0x434ea8: 2b6820 SUB EBP,dword ptr [EAX + 0x20]
    s.bp = integer::sub(s.bp,m.r32((s.ax+0x00000020u)),32,flags);
  }
  L00434eab: { // 0x434eab: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00434eaf: { // 0x434eaf: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00434eb1: { // 0x434eb1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00434eb5: { // 0x434eb5: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00434eb7: { // 0x434eb7: 7c09 JL 0x00434ec2
    if(integer::condition("JL",flags)) goto L00434ec2;
  }
  L00434eb9: { // 0x434eb9: 8b542474 MOV EDX,dword ptr [ESP + 0x74]
    s.dx = m.r32((f.sp+0x00000074u));
  }
  L00434ebd: { // 0x434ebd: 037a10 ADD EDI,dword ptr [EDX + 0x10]
    s.di = integer::add(s.di,m.r32((s.dx+0x00000010u)),32,flags);
  }
  L00434ec0: { // 0x434ec0: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00434ec2: { // 0x434ec2: a1f4988100 MOV EAX,[0x008198f4]
    s.ax = m.r32((0x008198f4u));
  }
  L00434ec7: { // 0x434ec7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00434ec9: { // 0x434ec9: 741d JZ 0x00434ee8
    if(integer::condition("JZ",flags)) goto L00434ee8;
  }
  L00434ecb: { // 0x434ecb: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00434ecf: { // 0x434ecf: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00434ed3: { // 0x434ed3: 8d0450 LEA EAX,[EAX + EDX*0x2]
    s.ax = (s.ax+(s.dx * 0x00000002u));
  }
  L00434ed6: { // 0x434ed6: 8b15f4988100 MOV EDX,dword ptr [0x008198f4]
    s.dx = m.r32((0x008198f4u));
  }
  L00434edc: { // 0x434edc: 3b421c CMP EAX,dword ptr [EDX + 0x1c]
    (void)integer::sub(s.ax,m.r32((s.dx+0x0000001cu)),32,flags);
  }
  L00434edf: { // 0x434edf: 7203 JC 0x00434ee4
    if(integer::condition("JC",flags)) goto L00434ee4;
  }
  L00434ee1: { // 0x434ee1: 2b4220 SUB EAX,dword ptr [EDX + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.dx+0x00000020u)),32,flags);
  }
  L00434ee4: { // 0x434ee4: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00434ee8: { // 0x434ee8: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00434eec: { // 0x434eec: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00434eed: { // 0x434eed: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00434ef1: { // 0x434ef1: 0f855dffffff JNZ 0x00434e54
    if(integer::condition("JNZ",flags)) goto L00434e54;
  }
  L00434ef7: { // 0x434ef7: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L00434efb: { // 0x434efb: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00434efd: { // 0x434efd: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00434eff: { // 0x434eff: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),4411138u); flags=s.arithmetic_flags;
  }
  L00434f02: { // 0x434f02: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L00434f06: { // 0x434f06: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00434f08: { // 0x434f08: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),4411147u); flags=s.arithmetic_flags;
  }
  L00434f0b: { // 0x434f0b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00434f0d: { // 0x434f0d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00434f0e: { // 0x434f0e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00434f0f: { // 0x434f0f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00434f10: { // 0x434f10: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00434f11: { // 0x434f11: 83c448 ADD ESP,0x48
    f.sp = integer::add(f.sp,0x00000048u,32,flags);
  }
  L00434f14: { // 0x434f14: c22400 RET 0x24
    s.arithmetic_flags=flags; finish(m,s,f,36u); return;
  }
}
void f_00360cf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760cf0: { // 0x760cf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L00760cf3: { // 0x760cf3: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00760cf7: { // 0x760cf7: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760cf8: { // 0x760cf8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760cf9: { // 0x760cf9: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L00760cfb: { // 0x760cfb: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00760cff: { // 0x760cff: 8bea MOV EBP,EDX
    s.bp = s.dx;
  }
  L00760d01: { // 0x760d01: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00760d05: { // 0x760d05: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760d06: { // 0x760d06: 8b742428 MOV ESI,dword ptr [ESP + 0x28]
    s.si = m.r32((f.sp+0x00000028u));
  }
  L00760d0a: { // 0x760d0a: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  L00760d0d: { // 0x760d0d: c70100000000 MOV dword ptr [ECX],0x0
    m.w32((s.cx), 0x00000000u);
  }
  L00760d13: { // 0x760d13: c70200000000 MOV dword ptr [EDX],0x0
    m.w32((s.dx), 0x00000000u);
  }
  L00760d19: { // 0x760d19: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00760d1c: { // 0x760d1c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760d1d: { // 0x760d1d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d1f: { // 0x760d1f: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00760d23: { // 0x760d23: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00760d27: { // 0x760d27: 0f8e53010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d2d: { // 0x760d2d: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L00760d30: { // 0x760d30: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d32: { // 0x760d32: 0f8e48010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d38: { // 0x760d38: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00760d3b: { // 0x760d3b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d3d: { // 0x760d3d: 0f8e3d010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d43: { // 0x760d43: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L00760d46: { // 0x760d46: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d48: { // 0x760d48: 0f8e32010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d4e: { // 0x760d4e: 8b7c2438 MOV EDI,dword ptr [ESP + 0x38]
    s.di = m.r32((f.sp+0x00000038u));
  }
  L00760d52: { // 0x760d52: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00760d55: { // 0x760d55: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d57: { // 0x760d57: 0f8e23010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d5d: { // 0x760d5d: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  L00760d60: { // 0x760d60: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760d62: { // 0x760d62: 0f8e18010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d68: { // 0x760d68: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00760d6c: { // 0x760d6c: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00760d6f: { // 0x760d6f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00760d71: { // 0x760d71: 0f8e09010000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d77: { // 0x760d77: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00760d7a: { // 0x760d7a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00760d7c: { // 0x760d7c: 0f8efe000000 JLE 0x00760e80
    if(integer::condition("JLE",flags)) goto L00760e80;
  }
  L00760d82: { // 0x760d82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760d83: { // 0x760d83: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760d84: { // 0x760d84: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  L00760d86: { // 0x760d86: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760d88: { // 0x760d88: e843fdffff CALL 0x00760ad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760ad0u,7736717u); flags=s.arithmetic_flags;
  }
  L00760d8d: { // 0x760d8d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00760d8f: { // 0x760d8f: 0f84eb000000 JZ 0x00760e80
    if(integer::condition("JZ",flags)) goto L00760e80;
  }
  L00760d95: { // 0x760d95: 8b44243c MOV EAX,dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L00760d99: { // 0x760d99: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  L00760d9c: { // 0x760d9c: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L00760da0: { // 0x760da0: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00760da2: { // 0x760da2: 7547 JNZ 0x00760deb
    if(integer::condition("JNZ",flags)) goto L00760deb;
  }
  L00760da4: { // 0x760da4: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00760da6: { // 0x760da6: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  L00760da9: { // 0x760da9: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L00760dab: { // 0x760dab: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00760dad: { // 0x760dad: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00760daf: { // 0x760daf: 7d36 JGE 0x00760de7
    if(integer::condition("JGE",flags)) goto L00760de7;
  }
  L00760db1: { // 0x760db1: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00760db4: { // 0x760db4: 8b6e0c MOV EBP,dword ptr [ESI + 0xc]
    s.bp = m.r32((s.si+0x0000000cu));
  }
  L00760db7: { // 0x760db7: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L00760dba: { // 0x760dba: 03e8 ADD EBP,EAX
    s.bp = integer::add(s.bp,s.ax,32,flags);
  }
  L00760dbc: { // 0x760dbc: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00760dbe: { // 0x760dbe: 7d23 JGE 0x00760de3
    if(integer::condition("JGE",flags)) goto L00760de3;
  }
  L00760dc0: { // 0x760dc0: 8beb MOV EBP,EBX
    s.bp = s.bx;
  }
  L00760dc2: { // 0x760dc2: 036f08 ADD EBP,dword ptr [EDI + 0x8]
    s.bp = integer::add(s.bp,m.r32((s.di+0x00000008u)),32,flags);
  }
  L00760dc5: { // 0x760dc5: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L00760dc7: { // 0x760dc7: 7e1a JLE 0x00760de3
    if(integer::condition("JLE",flags)) goto L00760de3;
  }
  L00760dc9: { // 0x760dc9: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L00760dcb: { // 0x760dcb: 036f0c ADD EBP,dword ptr [EDI + 0xc]
    s.bp = integer::add(s.bp,m.r32((s.di+0x0000000cu)),32,flags);
  }
  L00760dce: { // 0x760dce: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00760dd0: { // 0x760dd0: 7e11 JLE 0x00760de3
    if(integer::condition("JLE",flags)) goto L00760de3;
  }
  L00760dd2: { // 0x760dd2: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00760dd4: { // 0x760dd4: 7c06 JL 0x00760ddc
    if(integer::condition("JL",flags)) goto L00760ddc;
  }
  L00760dd6: { // 0x760dd6: 750b JNZ 0x00760de3
    if(integer::condition("JNZ",flags)) goto L00760de3;
  }
  L00760dd8: { // 0x760dd8: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00760dda: { // 0x760dda: 7d07 JGE 0x00760de3
    if(integer::condition("JGE",flags)) goto L00760de3;
  }
  L00760ddc: { // 0x760ddc: 8b54243c MOV EDX,dword ptr [ESP + 0x3c]
    s.dx = m.r32((f.sp+0x0000003cu));
  }
  L00760de0: { // 0x760de0: c60201 MOV byte ptr [EDX],0x1
    m.w8((s.dx), 0x00000001u);
  }
  L00760de3: { // 0x760de3: 8b6c2418 MOV EBP,dword ptr [ESP + 0x18]
    s.bp = m.r32((f.sp+0x00000018u));
  }
  L00760de7: { // 0x760de7: 8b5c2410 MOV EBX,dword ptr [ESP + 0x10]
    s.bx = m.r32((f.sp+0x00000010u));
  }
  L00760deb: { // 0x760deb: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L00760def: { // 0x760def: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00760df1: { // 0x760df1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760df2: { // 0x760df2: e82946cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736823u); flags=s.arithmetic_flags;
  }
  L00760df7: { // 0x760df7: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00760dfb: { // 0x760dfb: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00760dff: { // 0x760dff: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e00: { // 0x760e00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760e01: { // 0x760e01: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760e02: { // 0x760e02: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00760e04: { // 0x760e04: e81746cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736841u); flags=s.arithmetic_flags;
  }
  L00760e09: { // 0x760e09: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00760e0b: { // 0x760e0b: e8f045cdff CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,7736848u); flags=s.arithmetic_flags;
  }
  L00760e10: { // 0x760e10: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00760e12: { // 0x760e12: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00760e15: { // 0x760e15: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00760e17: { // 0x760e17: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00760e19: { // 0x760e19: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00760e1c: { // 0x760e1c: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00760e1f: { // 0x760e1f: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00760e21: { // 0x760e21: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00760e23: { // 0x760e23: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7736870u); flags=s.arithmetic_flags;
  }
  L00760e26: { // 0x760e26: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760e28: { // 0x760e28: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00760e2c: { // 0x760e2c: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00760e2e: { // 0x760e2e: 7450 JZ 0x00760e80
    if(integer::condition("JZ",flags)) goto L00760e80;
  }
  L00760e30: { // 0x760e30: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L00760e34: { // 0x760e34: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00760e36: { // 0x760e36: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00760e37: { // 0x760e37: e8e445cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736892u); flags=s.arithmetic_flags;
  }
  L00760e3c: { // 0x760e3c: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L00760e40: { // 0x760e40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e41: { // 0x760e41: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L00760e45: { // 0x760e45: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00760e46: { // 0x760e46: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00760e47: { // 0x760e47: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00760e4b: { // 0x760e4b: e8d045cdff CALL 0x00435420
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435420u,7736912u); flags=s.arithmetic_flags;
  }
  L00760e50: { // 0x760e50: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00760e52: { // 0x760e52: e8a945cdff CALL 0x00435400
    s.arithmetic_flags=flags; invoke(m,s,f,0x00435400u,7736919u); flags=s.arithmetic_flags;
  }
  L00760e57: { // 0x760e57: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00760e59: { // 0x760e59: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00760e5c: { // 0x760e5c: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L00760e5e: { // 0x760e5e: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L00760e60: { // 0x760e60: 8b4004 MOV EAX,dword ptr [EAX + 0x4]
    s.ax = m.r32((s.ax+0x00000004u));
  }
  L00760e63: { // 0x760e63: 894104 MOV dword ptr [ECX + 0x4],EAX
    m.w32((s.cx+0x00000004u), s.ax);
  }
  L00760e66: { // 0x760e66: 8b4c2438 MOV ECX,dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L00760e6a: { // 0x760e6a: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00760e6c: { // 0x760e6c: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7736943u); flags=s.arithmetic_flags;
  }
  L00760e6f: { // 0x760e6f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00760e71: { // 0x760e71: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00760e75: { // 0x760e75: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00760e77: { // 0x760e77: 7513 JNZ 0x00760e8c
    if(integer::condition("JNZ",flags)) goto L00760e8c;
  }
  L00760e79: { // 0x760e79: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00760e7b: { // 0x760e7b: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L00760e7d: { // 0x760e7d: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7736960u); flags=s.arithmetic_flags;
  }
  L00760e80: { // 0x760e80: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00760e82: { // 0x760e82: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760e83: { // 0x760e83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760e84: { // 0x760e84: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00760e85: { // 0x760e85: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760e86: { // 0x760e86: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00760e89: { // 0x760e89: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
  }
  L00760e8c: { // 0x760e8c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00760e8d: { // 0x760e8d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00760e8e: { // 0x760e8e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00760e8f: { // 0x760e8f: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00760e91: { // 0x760e91: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00760e92: { // 0x760e92: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L00760e95: { // 0x760e95: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); return;
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
void f_00035400(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435400: { // 0x435400: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435404: { // 0x435404: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435405: { // 0x435405: 8b31 MOV ESI,dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00435407: { // 0x435407: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00435409: { // 0x435409: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0043540b: { // 0x43540b: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0043540e: { // 0x43540e: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00435411: { // 0x435411: 03f0 ADD ESI,EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L00435413: { // 0x435413: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L00435417: { // 0x435417: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00435419: { // 0x435419: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L0043541c: { // 0x43541c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043541d: { // 0x43541d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00361c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761c80: { // 0x761c80: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L00761c84: { // 0x761c84: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00761c85: { // 0x761c85: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00761c87: { // 0x761c87: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00761c88: { // 0x761c88: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c89: { // 0x761c89: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L00761c8d: { // 0x761c8d: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c90: { // 0x761c90: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00761c91: { // 0x761c91: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c93: { // 0x761c93: ff505c CALL dword ptr [EAX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000005cu)),7740566u); flags=s.arithmetic_flags;
  }
  L00761c96: { // 0x761c96: 8b4e14 MOV ECX,dword ptr [ESI + 0x14]
    s.cx = m.r32((s.si+0x00000014u));
  }
  L00761c99: { // 0x761c99: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00761c9b: { // 0x761c9b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00761c9d: { // 0x761c9d: ff5060 CALL dword ptr [EAX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000060u)),7740576u); flags=s.arithmetic_flags;
  }
  L00761ca0: { // 0x761ca0: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L00761ca3: { // 0x761ca3: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  L00761ca6: { // 0x761ca6: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00761ca8: { // 0x761ca8: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00761caa: { // 0x761caa: 7203 JC 0x00761caf
    if(integer::condition("JC",flags)) goto L00761caf;
  }
  L00761cac: { // 0x761cac: 2b4620 SUB EAX,dword ptr [ESI + 0x20]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x00000020u)),32,flags);
  }
  L00761caf: { // 0x761caf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761cb0: { // 0x761cb0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761cb1: { // 0x761cb1: c20800 RET 0x8
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
void f_00361440(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00761440: { // 0x761440: 8b44240c MOV EAX, dword ptr [ESP + 0xC]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00761444: { // 0x761444: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00761446: { // 0x761446: 7e20 JLE 0x761468
    if(integer::condition("JLE",flags)) goto L00761468;
  }
  L00761448: { // 0x761448: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L0076144c: { // 0x76144c: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00761450: { // 0x761450: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00761451: { // 0x761451: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00761453: { // 0x761453: 668b01 MOV AX, word ptr [ECX]
    s.ax = with_ax(s.ax, m.r16((s.cx)));
  }
  L00761456: { // 0x761456: 83c102 ADD ECX, 2
    s.cx = integer::add(s.cx,2u,32,flags);
  }
  L00761459: { // 0x761459: 6685c0 TEST AX, AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  L0076145c: { // 0x76145c: 7403 JZ 0x761461
    if(integer::condition("JZ",flags)) goto L00761461;
  }
  L0076145e: { // 0x76145e: 668902 MOV word ptr [EDX], AX
    m.w16((s.dx), (s.ax & 0xffffu));
  }
  L00761461: { // 0x761461: 83c202 ADD EDX, 2
    s.dx = integer::add(s.dx,2u,32,flags);
  }
  L00761464: { // 0x761464: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00761465: { // 0x761465: 75ec JNZ 0x761453
    if(integer::condition("JNZ",flags)) goto L00761453;
  }
  L00761467: { // 0x761467: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761468: { // 0x761468: c22000 RET 0x20
    s.arithmetic_flags=flags; finish(m,s,f,32u); return;
  }
}
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){f.push(m,continuation);Frame child{f.sp,f.sp,continuation};switch(target){
case 7736016u:f_00360ad0(m,s,child,{});break;
case 4409856u:f_00034a00(m,s,child,{});break;
case 7736560u:f_00360cf0(m,s,child,{});break;
case 4412448u:f_00035420(m,s,child,{});break;
case 4412416u:f_00035400(m,s,child,{});break;
case 7740544u:f_00361c80(m,s,child,{});break;
case 4264816u:f_00011370(m,s,child,{});break;
case 4264688u:f_000112f0(m,s,child,{});break;
case 4264880u:f_000113b0(m,s,child,{});break;
case 4264896u:f_000113c0(m,s,child,{});break;
case 4264640u:f_000112c0(m,s,child,{});break;
case 4264592u:f_00011290(m,s,child,{});break;
case 7738432u:f_00361440(m,s,child,{});break;
default:throw std::domain_error("B514 unclosed call");}f.sp=child.sp;}
}
std::uint32_t run(Memory&original,const Inputs&i,std::uint32_t target){
 std::array<std::uint8_t,0x8000> stack{};const std::uint32_t base=i.cx-0x4000u+0x200000u,entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 s.bx=0x13579bdfu;s.si=0x2468ace0u;s.di=0x789abcdeu;
 Frame f{entry,entry,0x76543210u};m.w32(entry,0x76543210u);
 for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,i.arg[k]);
 m.w32(entry-8,i.stack_minus8);m.w32(((entry-4)&~7u)-8,i.stack_minus8);
 switch(target){case 0x34a00u:f_00034a00(m,s,f,{});break;default:throw std::domain_error("B514 invalid entry");}i.fp=s.fp;for(unsigned k=0;k<16;++k)i.arg[k]=m.r32(entry+4+4*k);return s.ax;}
}

namespace ra2::recovered::recovery_b514 {
std::uint32_t fun_00434a00(Memory&m,const Inputs&i){return b514_240::run(m,i,0x34a00u);}
std::uint32_t fun_00434f80(Memory&m,const Inputs&i){return b514_238::run(m,i,0x34f80u);}
std::uint32_t fun_0049ebd0(Memory&m,const Inputs&i){return b514_238::run(m,i,0x9ebd0u);}
}
