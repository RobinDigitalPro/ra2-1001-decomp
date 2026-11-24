#include "recovered/recovery_b1553_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1553 {
namespace {
void f_0015f7c0(Memory&,State&,Frame&,const Operations&);
void f_00157450(Memory&,State&,Frame&,const Operations&);
void f_00164f30(Memory&,State&,Frame&,const Operations&);
void f_00145490(Memory&,State&,Frame&,const Operations&);
void f_000702c0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_001cd4d0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0015f7c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0055f7c0: { // 0x55f7c0: 81ece8000000 SUB ESP,0xe8
    f.sp = integer::sub(f.sp,0x000000e8u,32,flags);
  }
  L0055f7c6: { // 0x55f7c6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055f7c7: { // 0x55f7c7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0055f7c8: { // 0x55f7c8: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0055f7ca: { // 0x55f7ca: 8d542454 LEA EDX,[ESP + 0x54]
    s.dx = (f.sp+0x00000054u);
  }
  L0055f7ce: { // 0x55f7ce: 8b8c24f4000000 MOV ECX,dword ptr [ESP + 0xf4]
    s.cx = m.r32((f.sp+0x000000f4u));
  }
  L0055f7d5: { // 0x55f7d5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f7d6: { // 0x55f7d6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055f7d8: { // 0x55f7d8: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5634011u); flags=s.arithmetic_flags;
  }
  L0055f7db: { // 0x55f7db: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0055f7dd: { // 0x55f7dd: c744242020000000 MOV dword ptr [ESP + 0x20],0x20
    m.w32((f.sp+0x00000020u), 0x00000020u);
  }
  L0055f7e5: { // 0x55f7e5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0055f7e7: { // 0x55f7e7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055f7e8: { // 0x55f7e8: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055f7ee: { // 0x55f7ee: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055f7f0: { // 0x55f7f0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055f7f2: { // 0x55f7f2: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0055f7f5: { // 0x55f7f5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055f7f6: { // 0x55f7f6: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055f7f9: { // 0x55f7f9: 8bb7f0000000 MOV ESI,dword ptr [EDI + 0xf0]
    s.si = m.r32((s.di+0x000000f0u));
  }
  L0055f7ff: { // 0x55f7ff: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L0055f804: { // 0x55f804: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055f80a: { // 0x55f80a: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0055f80d: { // 0x55f80d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055f80f: { // 0x55f80f: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0055f813: { // 0x55f813: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055f816: { // 0x55f816: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0055f81b: { // 0x55f81b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055f81d: { // 0x55f81d: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0055f820: { // 0x55f820: 8b87f4000000 MOV EAX,dword ptr [EDI + 0xf4]
    s.ax = m.r32((s.di+0x000000f4u));
  }
  L0055f826: { // 0x55f826: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L0055f82a: { // 0x55f82a: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0055f82c: { // 0x55f82c: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f830: { // 0x55f830: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  L0055f833: { // 0x55f833: 7f04 JG 0x0055f839
    if(integer::condition("JG",flags)) goto L0055f839;
  }
  L0055f835: { // 0x55f835: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0055f839: { // 0x55f839: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0055f83d: { // 0x55f83d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0055f83f: { // 0x55f83f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0055f841: { // 0x55f841: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0055f845: { // 0x55f845: 0f8eff030000 JLE 0x0055fc4a
    if(integer::condition("JLE",flags)) goto L0055fc4a;
  }
  L0055f84b: { // 0x55f84b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0055f84c: { // 0x55f84c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055f84d: { // 0x55f84d: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0055f84f: { // 0x55f84f: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0055f853: { // 0x55f853: eb04 JMP 0x0055f859
    goto L0055f859;
  }
  L0055f855: { // 0x55f855: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0055f859: { // 0x55f859: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0055f85b: { // 0x55f85b: 0f8f7b010000 JG 0x0055f9dc
    if(integer::condition("JG",flags)) goto L0055f9dc;
  }
  L0055f861: { // 0x55f861: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0055f863: { // 0x55f863: 8d9c9498000000 LEA EBX,[ESP + EDX*0x4 + 0x98]
    s.bx = (f.sp+(s.dx * 0x00000004u)+0x00000098u);
  }
  L0055f86a: { // 0x55f86a: 66894c243e MOV word ptr [ESP + 0x3e],CX
    m.w16((f.sp+0x0000003eu), (s.cx & 0xffffu));
  }
  L0055f86f: { // 0x55f86f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0055f873: { // 0x55f873: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0055f877: { // 0x55f877: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055f879: { // 0x55f879: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055f87a: { // 0x55f87a: 8d3429 LEA ESI,[ECX + EBP*0x1]
    s.si = (s.cx+(s.bp * 0x00000001u));
  }
  L0055f87d: { // 0x55f87d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f87f: { // 0x55f87f: 6689742444 MOV word ptr [ESP + 0x44],SI
    m.w16((f.sp+0x00000044u), (s.si & 0xffffu));
  }
  L0055f884: { // 0x55f884: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L0055f888: { // 0x55f888: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0055f88c: { // 0x55f88c: e8bf7bffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634193u); flags=s.arithmetic_flags;
  }
  L0055f891: { // 0x55f891: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f893: { // 0x55f893: 747b JZ 0x0055f910
    if(integer::condition("JZ",flags)) goto L0055f910;
  }
  L0055f895: { // 0x55f895: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055f89a: { // 0x55f89a: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055f89f: { // 0x55f89f: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f8a2: { // 0x55f8a2: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055f8a8: { // 0x55f8a8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055f8aa: { // 0x55f8aa: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0055f8ae: { // 0x55f8ae: 898c2488000000 MOV dword ptr [ESP + 0x88],ECX
    m.w32((f.sp+0x00000088u), s.cx);
  }
  L0055f8b5: { // 0x55f8b5: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f8b8: { // 0x55f8b8: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L0055f8bc: { // 0x55f8bc: 8d8c2484000000 LEA ECX,[ESP + 0x84]
    s.cx = (f.sp+0x00000084u);
  }
  L0055f8c3: { // 0x55f8c3: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0055f8c7: { // 0x55f8c7: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055f8cc: { // 0x55f8cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055f8cd: { // 0x55f8cd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f8ce: { // 0x55f8ce: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0055f8d3: { // 0x55f8d3: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L0055f8d7: { // 0x55f8d7: 8984248c000000 MOV dword ptr [ESP + 0x8c],EAX
    m.w32((f.sp+0x0000008cu), s.ax);
  }
  L0055f8de: { // 0x55f8de: e8ad5bfeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5634275u); flags=s.arithmetic_flags;
  }
  L0055f8e3: { // 0x55f8e3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055f8e5: { // 0x55f8e5: e8d609f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634282u); flags=s.arithmetic_flags;
  }
  L0055f8ea: { // 0x55f8ea: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L0055f8ee: { // 0x55f8ee: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L0055f8f2: { // 0x55f8f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055f8f3: { // 0x55f8f3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f8f5: { // 0x55f8f5: e836560000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634298u); flags=s.arithmetic_flags;
  }
  L0055f8fa: { // 0x55f8fa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f8fc: { // 0x55f8fc: 7412 JZ 0x0055f910
    if(integer::condition("JZ",flags)) goto L0055f910;
  }
  L0055f8fe: { // 0x55f8fe: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0055f902: { // 0x55f902: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L0055f904: { // 0x55f904: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055f908: { // 0x55f908: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055f909: { // 0x55f909: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L0055f90c: { // 0x55f90c: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f910: { // 0x55f910: 837c241418 CMP dword ptr [ESP + 0x14],0x18
    (void)integer::sub(m.r32((f.sp+0x00000014u)),0x00000018u,32,flags);
  }
  L0055f915: { // 0x55f915: 0f84c3020000 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055f91b: { // 0x55f91b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0055f91f: { // 0x55f91f: 6689742438 MOV word ptr [ESP + 0x38],SI
    m.w16((f.sp+0x00000038u), (s.si & 0xffffu));
  }
  L0055f924: { // 0x55f924: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0055f928: { // 0x55f928: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055f92a: { // 0x55f92a: 8d0416 LEA EAX,[ESI + EDX*0x1]
    s.ax = (s.si+(s.dx * 0x00000001u));
  }
  L0055f92d: { // 0x55f92d: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0055f931: { // 0x55f931: 668944243e MOV word ptr [ESP + 0x3e],AX
    m.w16((f.sp+0x0000003eu), (s.ax & 0xffffu));
  }
  L0055f936: { // 0x55f936: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0055f93a: { // 0x55f93a: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f93e: { // 0x55f93e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f93f: { // 0x55f93f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f941: { // 0x55f941: e80a7bffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634374u); flags=s.arithmetic_flags;
  }
  L0055f946: { // 0x55f946: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f948: { // 0x55f948: 7472 JZ 0x0055f9bc
    if(integer::condition("JZ",flags)) goto L0055f9bc;
  }
  L0055f94a: { // 0x55f94a: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055f94f: { // 0x55f94f: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055f954: { // 0x55f954: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f957: { // 0x55f957: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f95a: { // 0x55f95a: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055f95f: { // 0x55f95f: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055f965: { // 0x55f965: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0055f969: { // 0x55f969: 89442474 MOV dword ptr [ESP + 0x74],EAX
    m.w32((f.sp+0x00000074u), s.ax);
  }
  L0055f96d: { // 0x55f96d: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0055f971: { // 0x55f971: 894c2478 MOV dword ptr [ESP + 0x78],ECX
    m.w32((f.sp+0x00000078u), s.cx);
  }
  L0055f975: { // 0x55f975: 8d442474 LEA EAX,[ESP + 0x74]
    s.ax = (f.sp+0x00000074u);
  }
  L0055f979: { // 0x55f979: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0055f97d: { // 0x55f97d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055f97e: { // 0x55f97e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055f980: { // 0x55f980: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055f981: { // 0x55f981: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0055f986: { // 0x55f986: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L0055f98a: { // 0x55f98a: e8015bfeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5634447u); flags=s.arithmetic_flags;
  }
  L0055f98f: { // 0x55f98f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055f991: { // 0x55f991: e82a09f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634454u); flags=s.arithmetic_flags;
  }
  L0055f996: { // 0x55f996: 8d542450 LEA EDX,[ESP + 0x50]
    s.dx = (f.sp+0x00000050u);
  }
  L0055f99a: { // 0x55f99a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f99c: { // 0x55f99c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f99d: { // 0x55f99d: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0055f9a1: { // 0x55f9a1: e88a550000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634470u); flags=s.arithmetic_flags;
  }
  L0055f9a6: { // 0x55f9a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f9a8: { // 0x55f9a8: 7412 JZ 0x0055f9bc
    if(integer::condition("JZ",flags)) goto L0055f9bc;
  }
  L0055f9aa: { // 0x55f9aa: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055f9ae: { // 0x55f9ae: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0055f9b2: { // 0x55f9b2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055f9b3: { // 0x55f9b3: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0055f9b5: { // 0x55f9b5: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f9b9: { // 0x55f9b9: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L0055f9bc: { // 0x55f9bc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0055f9c0: { // 0x55f9c0: 83f818 CMP EAX,0x18
    (void)integer::sub(s.ax,0x00000018u,32,flags);
  }
  L0055f9c3: { // 0x55f9c3: 0f8415020000 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055f9c9: { // 0x55f9c9: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0055f9ca: { // 0x55f9ca: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L0055f9cc: { // 0x55f9cc: 0f8e9dfeffff JLE 0x0055f86f
    if(integer::condition("JLE",flags)) goto L0055f86f;
  }
  L0055f9d2: { // 0x55f9d2: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0055f9d6: { // 0x55f9d6: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0055f9d8: { // 0x55f9d8: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055f9dc: { // 0x55f9dc: 83fa18 CMP EDX,0x18
    (void)integer::sub(s.dx,0x00000018u,32,flags);
  }
  L0055f9df: { // 0x55f9df: 0f84fd010000 JZ 0x0055fbe2
    if(integer::condition("JZ",flags)) goto L0055fbe2;
  }
  L0055f9e5: { // 0x55f9e5: 8d5d01 LEA EBX,[EBP + 0x1]
    s.bx = (s.bp+0x00000001u);
  }
  L0055f9e8: { // 0x55f9e8: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L0055f9eb: { // 0x55f9eb: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0055f9ed: { // 0x55f9ed: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0055f9f1: { // 0x55f9f1: 0f8fca010000 JG 0x0055fbc1
    if(integer::condition("JG",flags)) goto L0055fbc1;
  }
  L0055f9f7: { // 0x55f9f7: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0055f9fb: { // 0x55f9fb: 8dac9498000000 LEA EBP,[ESP + EDX*0x4 + 0x98]
    s.bp = (f.sp+(s.dx * 0x00000004u)+0x00000098u);
  }
  L0055fa02: { // 0x55fa02: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0055fa04: { // 0x55fa04: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L0055fa09: { // 0x55fa09: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0055fa0d: { // 0x55fa0d: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0055fa11: { // 0x55fa11: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055fa13: { // 0x55fa13: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055fa14: { // 0x55fa14: 8d3413 LEA ESI,[EBX + EDX*0x1]
    s.si = (s.bx+(s.dx * 0x00000001u));
  }
  L0055fa17: { // 0x55fa17: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fa19: { // 0x55fa19: 668974243a MOV word ptr [ESP + 0x3a],SI
    m.w16((f.sp+0x0000003au), (s.si & 0xffffu));
  }
  L0055fa1e: { // 0x55fa1e: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0055fa22: { // 0x55fa22: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0055fa26: { // 0x55fa26: e8257affff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634603u); flags=s.arithmetic_flags;
  }
  L0055fa2b: { // 0x55fa2b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fa2d: { // 0x55fa2d: 7476 JZ 0x0055faa5
    if(integer::condition("JZ",flags)) goto L0055faa5;
  }
  L0055fa2f: { // 0x55fa2f: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055fa34: { // 0x55fa34: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055fa39: { // 0x55fa39: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055fa3c: { // 0x55fa3c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055fa3e: { // 0x55fa3e: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055fa43: { // 0x55fa43: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055fa46: { // 0x55fa46: 89542470 MOV dword ptr [ESP + 0x70],EDX
    m.w32((f.sp+0x00000070u), s.dx);
  }
  L0055fa4a: { // 0x55fa4a: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055fa50: { // 0x55fa50: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L0055fa54: { // 0x55fa54: 8944247c MOV dword ptr [ESP + 0x7c],EAX
    m.w32((f.sp+0x0000007cu), s.ax);
  }
  L0055fa58: { // 0x55fa58: 8d54247c LEA EDX,[ESP + 0x7c]
    s.dx = (f.sp+0x0000007cu);
  }
  L0055fa5c: { // 0x55fa5c: 8d442468 LEA EAX,[ESP + 0x68]
    s.ax = (f.sp+0x00000068u);
  }
  L0055fa60: { // 0x55fa60: 894c246c MOV dword ptr [ESP + 0x6c],ECX
    m.w32((f.sp+0x0000006cu), s.cx);
  }
  L0055fa64: { // 0x55fa64: 898c2480000000 MOV dword ptr [ESP + 0x80],ECX
    m.w32((f.sp+0x00000080u), s.cx);
  }
  L0055fa6b: { // 0x55fa6b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055fa6c: { // 0x55fa6c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055fa6d: { // 0x55fa6d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0055fa72: { // 0x55fa72: e8195afeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5634679u); flags=s.arithmetic_flags;
  }
  L0055fa77: { // 0x55fa77: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055fa79: { // 0x55fa79: e84208f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634686u); flags=s.arithmetic_flags;
  }
  L0055fa7e: { // 0x55fa7e: 8d4c2468 LEA ECX,[ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L0055fa82: { // 0x55fa82: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L0055fa86: { // 0x55fa86: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055fa87: { // 0x55fa87: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fa89: { // 0x55fa89: e8a2540000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634702u); flags=s.arithmetic_flags;
  }
  L0055fa8e: { // 0x55fa8e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fa90: { // 0x55fa90: 7413 JZ 0x0055faa5
    if(integer::condition("JZ",flags)) goto L0055faa5;
  }
  L0055fa92: { // 0x55fa92: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055fa96: { // 0x55fa96: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0055fa9a: { // 0x55fa9a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055fa9b: { // 0x55fa9b: 895500 MOV dword ptr [EBP],EDX
    m.w32((s.bp), s.dx);
  }
  L0055fa9e: { // 0x55fa9e: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055faa2: { // 0x55faa2: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0055faa5: { // 0x55faa5: 837c241418 CMP dword ptr [ESP + 0x14],0x18
    (void)integer::sub(m.r32((f.sp+0x00000014u)),0x00000018u,32,flags);
  }
  L0055faaa: { // 0x55faaa: 0f842e010000 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055fab0: { // 0x55fab0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055fab4: { // 0x55fab4: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0055fab8: { // 0x55fab8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0055faba: { // 0x55faba: 6689742436 MOV word ptr [ESP + 0x36],SI
    m.w16((f.sp+0x00000036u), (s.si & 0xffffu));
  }
  L0055fabf: { // 0x55fabf: 6689442434 MOV word ptr [ESP + 0x34],AX
    m.w16((f.sp+0x00000034u), (s.ax & 0xffffu));
  }
  L0055fac4: { // 0x55fac4: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0055fac8: { // 0x55fac8: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0055facc: { // 0x55facc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055face: { // 0x55face: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055facf: { // 0x55facf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fad1: { // 0x55fad1: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0055fad5: { // 0x55fad5: e87679ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634778u); flags=s.arithmetic_flags;
  }
  L0055fada: { // 0x55fada: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fadc: { // 0x55fadc: 0f84bf000000 JZ 0x0055fba1
    if(integer::condition("JZ",flags)) goto L0055fba1;
  }
  L0055fae2: { // 0x55fae2: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055fae7: { // 0x55fae7: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055faec: { // 0x55faec: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055faef: { // 0x55faef: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055faf4: { // 0x55faf4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055faf6: { // 0x55faf6: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0055fafa: { // 0x55fafa: 89542464 MOV dword ptr [ESP + 0x64],EDX
    m.w32((f.sp+0x00000064u), s.dx);
  }
  L0055fafe: { // 0x55fafe: 8984248c000000 MOV dword ptr [ESP + 0x8c],EAX
    m.w32((f.sp+0x0000008cu), s.ax);
  }
  L0055fb05: { // 0x55fb05: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055fb06: { // 0x55fb06: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055fb0c: { // 0x55fb0c: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055fb0f: { // 0x55fb0f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055fb11: { // 0x55fb11: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055fb17: { // 0x55fb17: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0055fb19: { // 0x55fb19: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0055fb1b: { // 0x55fb1b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055fb1c: { // 0x55fb1c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055fb22: { // 0x55fb22: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0055fb26: { // 0x55fb26: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055fb28: { // 0x55fb28: 898c2490000000 MOV dword ptr [ESP + 0x90],ECX
    m.w32((f.sp+0x00000090u), s.cx);
  }
  L0055fb2f: { // 0x55fb2f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055fb32: { // 0x55fb32: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055fb34: { // 0x55fb34: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055fb37: { // 0x55fb37: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055fb3a: { // 0x55fb3a: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0055fb3c: { // 0x55fb3c: 7815 JS 0x0055fb53
    if(integer::condition("JS",flags)) goto L0055fb53;
  }
  L0055fb3e: { // 0x55fb3e: 3b0d5ca98100 CMP ECX,dword ptr [0x0081a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  L0055fb44: { // 0x55fb44: 7d0d JGE 0x0055fb53
    if(integer::condition("JGE",flags)) goto L0055fb53;
  }
  L0055fb46: { // 0x55fb46: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0055fb4c: { // 0x55fb4c: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L0055fb4f: { // 0x55fb4f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055fb51: { // 0x55fb51: 751a JNZ 0x0055fb6d
    if(integer::condition("JNZ",flags)) goto L0055fb6d;
  }
  L0055fb53: { // 0x55fb53: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055fb54: { // 0x55fb54: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055fb55: { // 0x55fb55: 8d8c249c000000 LEA ECX,[ESP + 0x9c]
    s.cx = (f.sp+0x0000009cu);
  }
  L0055fb5c: { // 0x55fb5c: e8cfb1ecff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5634913u); flags=s.arithmetic_flags;
  }
  L0055fb61: { // 0x55fb61: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0055fb63: { // 0x55fb63: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L0055fb68: { // 0x55fb68: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055fb6d: { // 0x55fb6d: 8d94248c000000 LEA EDX,[ESP + 0x8c]
    s.dx = (f.sp+0x0000008cu);
  }
  L0055fb74: { // 0x55fb74: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055fb75: { // 0x55fb75: e84607f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634938u); flags=s.arithmetic_flags;
  }
  L0055fb7a: { // 0x55fb7a: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L0055fb7e: { // 0x55fb7e: 8d44245c LEA EAX,[ESP + 0x5c]
    s.ax = (f.sp+0x0000005cu);
  }
  L0055fb82: { // 0x55fb82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055fb83: { // 0x55fb83: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fb85: { // 0x55fb85: e8a6530000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634954u); flags=s.arithmetic_flags;
  }
  L0055fb8a: { // 0x55fb8a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fb8c: { // 0x55fb8c: 7413 JZ 0x0055fba1
    if(integer::condition("JZ",flags)) goto L0055fba1;
  }
  L0055fb8e: { // 0x55fb8e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0055fb92: { // 0x55fb92: 894d00 MOV dword ptr [EBP],ECX
    m.w32((s.bp), s.cx);
  }
  L0055fb95: { // 0x55fb95: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055fb99: { // 0x55fb99: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055fb9a: { // 0x55fb9a: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0055fb9d: { // 0x55fb9d: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055fba1: { // 0x55fba1: 837c241418 CMP dword ptr [ESP + 0x14],0x18
    (void)integer::sub(m.r32((f.sp+0x00000014u)),0x00000018u,32,flags);
  }
  L0055fba6: { // 0x55fba6: 7436 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055fba8: { // 0x55fba8: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L0055fbac: { // 0x55fbac: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0055fbad: { // 0x55fbad: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0055fbaf: { // 0x55fbaf: 0f8e54feffff JLE 0x0055fa09
    if(integer::condition("JLE",flags)) goto L0055fa09;
  }
  L0055fbb5: { // 0x55fbb5: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0055fbb9: { // 0x55fbb9: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055fbbd: { // 0x55fbbd: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0055fbc1: { // 0x55fbc1: 83fa18 CMP EDX,0x18
    (void)integer::sub(s.dx,0x00000018u,32,flags);
  }
  L0055fbc4: { // 0x55fbc4: 741c JZ 0x0055fbe2
    if(integer::condition("JZ",flags)) goto L0055fbe2;
  }
  L0055fbc6: { // 0x55fbc6: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0055fbca: { // 0x55fbca: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0055fbcb: { // 0x55fbcb: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0055fbcc: { // 0x55fbcc: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0055fbce: { // 0x55fbce: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0055fbd2: { // 0x55fbd2: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0055fbd6: { // 0x55fbd6: 0f8c79fcffff JL 0x0055f855
    if(integer::condition("JL",flags)) goto L0055f855;
  }
  L0055fbdc: { // 0x55fbdc: eb04 JMP 0x0055fbe2
    goto L0055fbe2;
  }
  L0055fbde: { // 0x55fbde: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0055fbe2: { // 0x55fbe2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055fbe3: { // 0x55fbe3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055fbe4: { // 0x55fbe4: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0055fbe6: { // 0x55fbe6: 7e5e JLE 0x0055fc46
    if(integer::condition("JLE",flags)) goto L0055fc46;
  }
  L0055fbe8: { // 0x55fbe8: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0055fbe9: { // 0x55fbe9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055fbea: { // 0x55fbea: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L0055fbf0: { // 0x55fbf0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0055fbf2: { // 0x55fbf2: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L0055fbf8: { // 0x55fbf8: e843020d00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5635069u); flags=s.arithmetic_flags;
  }
  L0055fbfd: { // 0x55fbfd: 0fbf948490000000 MOVSX EDX,word ptr [ESP + EAX*0x4 + 0x90]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+(s.ax * 0x00000004u)+0x00000090u)),16));
  }
  L0055fc05: { // 0x55fc05: 8d8c8490000000 LEA ECX,[ESP + EAX*0x4 + 0x90]
    s.cx = (f.sp+(s.ax * 0x00000004u)+0x00000090u);
  }
  L0055fc0c: { // 0x55fc0c: 0fbf848492000000 MOVSX EAX,word ptr [ESP + EAX*0x4 + 0x92]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+(s.ax * 0x00000004u)+0x00000092u)),16));
  }
  L0055fc14: { // 0x55fc14: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055fc17: { // 0x55fc17: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055fc19: { // 0x55fc19: 7814 JS 0x0055fc2f
    if(integer::condition("JS",flags)) goto L0055fc2f;
  }
  L0055fc1b: { // 0x55fc1b: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055fc20: { // 0x55fc20: 7d0d JGE 0x0055fc2f
    if(integer::condition("JGE",flags)) goto L0055fc2f;
  }
  L0055fc22: { // 0x55fc22: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0055fc28: { // 0x55fc28: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0055fc2b: { // 0x55fc2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055fc2d: { // 0x55fc2d: 754b JNZ 0x0055fc7a
    if(integer::condition("JNZ",flags)) goto L0055fc7a;
  }
  L0055fc2f: { // 0x55fc2f: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055fc31: { // 0x55fc31: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055fc32: { // 0x55fc32: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055fc37: { // 0x55fc37: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0055fc3c: { // 0x55fc3c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055fc3d: { // 0x55fc3d: 81c4e8000000 ADD ESP,0xe8
    f.sp = integer::add(f.sp,0x000000e8u,32,flags);
  }
  L0055fc43: { // 0x55fc43: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0055fc46: { // 0x55fc46: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055fc4a: { // 0x55fc4a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055fc4e: { // 0x55fc4e: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055fc51: { // 0x55fc51: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0055fc53: { // 0x55fc53: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0055fc55: { // 0x55fc55: 7814 JS 0x0055fc6b
    if(integer::condition("JS",flags)) goto L0055fc6b;
  }
  L0055fc57: { // 0x55fc57: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055fc5c: { // 0x55fc5c: 7d0d JGE 0x0055fc6b
    if(integer::condition("JGE",flags)) goto L0055fc6b;
  }
  L0055fc5e: { // 0x55fc5e: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0055fc64: { // 0x55fc64: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0055fc67: { // 0x55fc67: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055fc69: { // 0x55fc69: 750f JNZ 0x0055fc7a
    if(integer::condition("JNZ",flags)) goto L0055fc7a;
  }
  L0055fc6b: { // 0x55fc6b: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0055fc6f: { // 0x55fc6f: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0055fc74: { // 0x55fc74: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0055fc7a: { // 0x55fc7a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055fc7b: { // 0x55fc7b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055fc7c: { // 0x55fc7c: 81c4e8000000 ADD ESP,0xe8
    f.sp = integer::add(f.sp,0x000000e8u,32,flags);
  }
  L0055fc82: { // 0x55fc82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00157450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00557450: { // 0x557450: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  L00557454: { // 0x557454: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00557455: { // 0x557455: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  L00557459: { // 0x557459: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055745a: { // 0x55745a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055745b: { // 0x55745b: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0055745d: { // 0x55745d: 0fbf5302 MOVSX EDX,word ptr [EBX + 0x2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bx+0x00000002u)),16));
  }
  L00557461: { // 0x557461: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00557462: { // 0x557462: 0fbf3b MOVSX EDI,word ptr [EBX]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.bx)),16));
  }
  L00557465: { // 0x557465: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00557467: { // 0x557467: 7454 JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L00557469: { // 0x557469: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0055746b: { // 0x55746b: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055746e: { // 0x55746e: 03c7 ADD EAX,EDI
    s.ax = integer::add(s.ax,s.di,32,flags);
  }
  L00557470: { // 0x557470: 7814 JS 0x00557486
    if(integer::condition("JS",flags)) goto L00557486;
  }
  L00557472: { // 0x557472: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00557477: { // 0x557477: 7d0d JGE 0x00557486
    if(integer::condition("JGE",flags)) goto L00557486;
  }
  L00557479: { // 0x557479: 8b3558a98100 MOV ESI,dword ptr [0x0081a958]
    s.si = m.r32((0x0081a958u));
  }
  L0055747f: { // 0x55747f: 8b0486 MOV EAX,dword ptr [ESI + EAX*0x4]
    s.ax = m.r32((s.si+(s.ax * 0x00000004u)));
  }
  L00557482: { // 0x557482: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00557484: { // 0x557484: 750c JNZ 0x00557492
    if(integer::condition("JNZ",flags)) goto L00557492;
  }
  L00557486: { // 0x557486: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00557488: { // 0x557488: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055748d: { // 0x55748d: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L00557492: { // 0x557492: 8a981c010000 MOV BL,byte ptr [EAX + 0x11c]
    s.bx = with_al(s.bx, m.r8((s.ax+0x0000011cu)));
  }
  L00557498: { // 0x557498: 0fbeb01b010000 MOVSX ESI,byte ptr [EAX + 0x11b]
    s.si = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0055749f: { // 0x55749f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L005574a1: { // 0x5574a1: 741a JZ 0x005574bd
    if(integer::condition("JZ",flags)) goto L005574bd;
  }
  L005574a3: { // 0x5574a3: 8b81fc000000 MOV EAX,dword ptr [ECX + 0xfc]
    s.ax = m.r32((s.cx+0x000000fcu));
  }
  L005574a9: { // 0x5574a9: 8b99f0000000 MOV EBX,dword ptr [ECX + 0xf0]
    s.bx = m.r32((s.cx+0x000000f0u));
  }
  L005574af: { // 0x5574af: 8d444304 LEA EAX,[EBX + EAX*0x2 + 0x4]
    s.ax = (s.bx+(s.ax * 0x00000002u)+0x00000004u);
  }
  L005574b3: { // 0x5574b3: 8d1c3a LEA EBX,[EDX + EDI*0x1]
    s.bx = (s.dx+(s.di * 0x00000001u));
  }
  L005574b6: { // 0x5574b6: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L005574b8: { // 0x5574b8: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L005574ba: { // 0x5574ba: 7d01 JGE 0x005574bd
    if(integer::condition("JGE",flags)) goto L005574bd;
  }
  L005574bc: { // 0x5574bc: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L005574bd: { // 0x5574bd: 8b99fc000000 MOV EBX,dword ptr [ECX + 0xfc]
    s.bx = m.r32((s.cx+0x000000fcu));
  }
  L005574c3: { // 0x5574c3: 8b81f0000000 MOV EAX,dword ptr [ECX + 0xf0]
    s.ax = m.r32((s.cx+0x000000f0u));
  }
  L005574c9: { // 0x5574c9: 8d2c3a LEA EBP,[EDX + EDI*0x1]
    s.bp = (s.dx+(s.di * 0x00000001u));
  }
  L005574cc: { // 0x5574cc: 8d1c58 LEA EBX,[EAX + EBX*0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u));
  }
  L005574cf: { // 0x5574cf: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574d1: { // 0x5574d1: 3beb CMP EBP,EBX
    (void)integer::sub(s.bp,s.bx,32,flags);
  }
  L005574d3: { // 0x5574d3: 7e49 JLE 0x0055751e
    if(integer::condition("JLE",flags)) goto L0055751e;
  }
  L005574d5: { // 0x5574d5: 8b9904010000 MOV EBX,dword ptr [ECX + 0x104]
    s.bx = m.r32((s.cx+0x00000104u));
  }
  L005574db: { // 0x5574db: 8ba9fc000000 MOV EBP,dword ptr [ECX + 0xfc]
    s.bp = m.r32((s.cx+0x000000fcu));
  }
  L005574e1: { // 0x5574e1: 03dd ADD EBX,EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L005574e3: { // 0x5574e3: 8d5c5802 LEA EBX,[EAX + EBX*0x2 + 0x2]
    s.bx = (s.ax+(s.bx * 0x00000002u)+0x00000002u);
  }
  L005574e7: { // 0x5574e7: 03de ADD EBX,ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L005574e9: { // 0x5574e9: 8d343a LEA ESI,[EDX + EDI*0x1]
    s.si = (s.dx+(s.di * 0x00000001u));
  }
  L005574ec: { // 0x5574ec: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L005574ee: { // 0x5574ee: 7f2e JG 0x0055751e
    if(integer::condition("JG",flags)) goto L0055751e;
  }
  L005574f0: { // 0x5574f0: 8bb1f8000000 MOV ESI,dword ptr [ECX + 0xf8]
    s.si = m.r32((s.cx+0x000000f8u));
  }
  L005574f6: { // 0x5574f6: 8b8900010000 MOV ECX,dword ptr [ECX + 0x100]
    s.cx = m.r32((s.cx+0x00000100u));
  }
  L005574fc: { // 0x5574fc: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L005574fe: { // 0x5574fe: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00557500: { // 0x557500: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L00557502: { // 0x557502: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00557504: { // 0x557504: 2bda SUB EBX,EDX
    s.bx = integer::sub(s.bx,s.dx,32,flags);
  }
  L00557506: { // 0x557506: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L00557508: { // 0x557508: 7d14 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L0055750a: { // 0x55750a: 8d0c36 LEA ECX,[ESI + ESI*0x1]
    s.cx = (s.si+(s.si * 0x00000001u));
  }
  L0055750d: { // 0x55750d: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0055750f: { // 0x55750f: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00557511: { // 0x557511: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00557513: { // 0x557513: 7d09 JGE 0x0055751e
    if(integer::condition("JGE",flags)) goto L0055751e;
  }
  L00557515: { // 0x557515: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00557516: { // 0x557516: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557517: { // 0x557517: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557518: { // 0x557518: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0055751a: { // 0x55751a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055751b: { // 0x55751b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0055751e: { // 0x55751e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055751f: { // 0x55751f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00557520: { // 0x557520: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00557521: { // 0x557521: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00557523: { // 0x557523: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00557524: { // 0x557524: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_00164f30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00564f30: { // 0x564f30: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L00564f33: { // 0x564f33: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00564f34: { // 0x564f34: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00564f38: { // 0x564f38: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L00564f3b: { // 0x564f3b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f3c: { // 0x564f3c: f73d4878a500 IDIV dword ptr [0x00a57848]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((0x00a57848u)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00564f42: { // 0x564f42: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00564f44: { // 0x564f44: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f45: { // 0x564f45: 0f848d000000 JZ 0x00564fd8
    if(integer::condition("JZ",flags)) goto L00564fd8;
  }
  L00564f4b: { // 0x564f4b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00564f4d: { // 0x564f4d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564f4f: { // 0x564f4f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00564f51: { // 0x564f51: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f52: { // 0x564f52: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564f58: { // 0x564f58: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564f5a: { // 0x564f5a: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f5d: { // 0x564f5d: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L00564f62: { // 0x564f62: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00564f65: { // 0x564f65: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564f66: { // 0x564f66: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564f6c: { // 0x564f6c: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564f6e: { // 0x564f6e: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f71: { // 0x564f71: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564f73: { // 0x564f73: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L00564f78: { // 0x564f78: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L00564f7c: { // 0x564f7c: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00564f80: { // 0x564f80: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00564f81: { // 0x564f81: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00564f83: { // 0x564f83: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00564f85: { // 0x564f85: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00564f8a: { // 0x564f8a: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L00564f8f: { // 0x564f8f: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00564f92: { // 0x564f92: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00564f95: { // 0x564f95: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00564f98: { // 0x564f98: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00564f9a: { // 0x564f9a: 7818 JS 0x00564fb4
    if(integer::condition("JS",flags)) goto L00564fb4;
  }
  L00564f9c: { // 0x564f9c: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00564fa1: { // 0x564fa1: 7d11 JGE 0x00564fb4
    if(integer::condition("JGE",flags)) goto L00564fb4;
  }
  L00564fa3: { // 0x564fa3: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00564fa9: { // 0x564fa9: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00564fac: { // 0x564fac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00564fae: { // 0x564fae: 7404 JZ 0x00564fb4
    if(integer::condition("JZ",flags)) goto L00564fb4;
  }
  L00564fb0: { // 0x564fb0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564fb2: { // 0x564fb2: eb0e JMP 0x00564fc2
    goto L00564fc2;
  }
  L00564fb4: { // 0x564fb4: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00564fb8: { // 0x564fb8: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L00564fbd: { // 0x564fbd: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00564fc2: { // 0x564fc2: f6812c01000008 TEST byte ptr [ECX + 0x12c],0x8
    (void)integer::logical((m.r8((s.cx+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00564fc9: { // 0x564fc9: 0f858d000000 JNZ 0x0056505c
    if(integer::condition("JNZ",flags)) goto L0056505c;
  }
  L00564fcf: { // 0x564fcf: 6a03 PUSH 0x3
    f.push(m,0x00000003u);
  }
  L00564fd1: { // 0x564fd1: e8ea16f1ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5656534u); flags=s.arithmetic_flags;
  }
  L00564fd6: { // 0x564fd6: eb72 JMP 0x0056504a
    goto L0056504a;
  }
  L00564fd8: { // 0x564fd8: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00564fda: { // 0x564fda: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00564fdc: { // 0x564fdc: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00564fde: { // 0x564fde: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564fdf: { // 0x564fdf: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564fe5: { // 0x564fe5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564fe7: { // 0x564fe7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564fea: { // 0x564fea: 6689442404 MOV word ptr [ESP + 0x4],AX
    m.w16((f.sp+0x00000004u), (s.ax & 0xffffu));
  }
  L00564fef: { // 0x564fef: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00564ff2: { // 0x564ff2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00564ff3: { // 0x564ff3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00564ff9: { // 0x564ff9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00564ffb: { // 0x564ffb: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00564ffe: { // 0x564ffe: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  L00565003: { // 0x565003: 8b442406 MOV EAX,dword ptr [ESP + 0x6]
    s.ax = m.r32((f.sp+0x00000006u));
  }
  L00565007: { // 0x565007: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L0056500b: { // 0x56500b: d1f9 SAR ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  L0056500d: { // 0x56500d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0056500f: { // 0x56500f: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00565011: { // 0x565011: 6689442412 MOV word ptr [ESP + 0x12],AX
    m.w16((f.sp+0x00000012u), (s.ax & 0xffffu));
  }
  L00565016: { // 0x565016: 6689542410 MOV word ptr [ESP + 0x10],DX
    m.w16((f.sp+0x00000010u), (s.dx & 0xffffu));
  }
  L0056501b: { // 0x56501b: 0fbfc0 MOVSX EAX,AX
    s.ax = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0056501e: { // 0x56501e: 0fbfca MOVSX ECX,DX
    s.cx = std::uint32_t(integer::sign_extend((s.dx & 0xffffu),16));
  }
  L00565021: { // 0x565021: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L00565024: { // 0x565024: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L00565026: { // 0x565026: 7814 JS 0x0056503c
    if(integer::condition("JS",flags)) goto L0056503c;
  }
  L00565028: { // 0x565028: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0056502d: { // 0x56502d: 7d0d JGE 0x0056503c
    if(integer::condition("JGE",flags)) goto L0056503c;
  }
  L0056502f: { // 0x56502f: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L00565035: { // 0x565035: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L00565038: { // 0x565038: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0056503a: { // 0x56503a: 750e JNZ 0x0056504a
    if(integer::condition("JNZ",flags)) goto L0056504a;
  }
  L0056503c: { // 0x56503c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00565040: { // 0x565040: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L00565045: { // 0x565045: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0056504a: { // 0x56504a: f6802c01000008 TEST byte ptr [EAX + 0x12c],0x8
    (void)integer::logical((m.r8((s.ax+0x0000012cu)))&(0x00000008u),8,flags);
  }
  L00565051: { // 0x565051: 7509 JNZ 0x0056505c
    if(integer::condition("JNZ",flags)) goto L0056505c;
  }
  L00565053: { // 0x565053: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00565055: { // 0x565055: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00565056: { // 0x565056: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565059: { // 0x565059: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0056505c: { // 0x56505c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0056505e: { // 0x56505e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0056505f: { // 0x56505f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00565062: { // 0x565062: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545490: { // 0x545490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545491: { // 0x545491: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00545492: { // 0x545492: 8b7c240c MOV EDI, dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  L00545496: { // 0x545496: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L00545498: { // 0x545498: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00545499: { // 0x545499: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0054549f: { // 0x54549f: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454a1: { // 0x5454a1: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L005454a3: { // 0x5454a3: 8b4704 MOV EAX, dword ptr [EDI + 4]
    s.ax = m.r32((s.di+4u));
  }
  L005454a6: { // 0x5454a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L005454a7: { // 0x5454a7: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L005454ad: { // 0x5454ad: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L005454af: { // 0x5454af: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b2: { // 0x5454b2: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005454b4: { // 0x5454b4: c1fe08 SAR ESI, 8
    s.si = integer::shift(s.si,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L005454b7: { // 0x5454b7: c1e209 SHL EDX, 9
    s.dx = integer::shift(s.dx,9u,32,flags,integer::Shift::left);
  }
  L005454ba: { // 0x5454ba: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L005454bc: { // 0x5454bc: 781c JS 0x5454da
    if(integer::condition("JS",flags)) goto L005454da;
  }
  L005454be: { // 0x5454be: 3b913c010000 CMP EDX, dword ptr [ECX + 0x13c]
    (void)integer::sub(s.dx,m.r32((s.cx+0x0000013cu)),32,flags);
  }
  L005454c4: { // 0x5454c4: 7d14 JGE 0x5454da
    if(integer::condition("JGE",flags)) goto L005454da;
  }
  L005454c6: { // 0x5454c6: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L005454cc: { // 0x5454cc: 8b1491 MOV EDX, dword ptr [ECX + EDX*4]
    s.dx = m.r32((s.cx+(s.dx * 4u)));
  }
  L005454cf: { // 0x5454cf: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L005454d1: { // 0x5454d1: 7407 JZ 0x5454da
    if(integer::condition("JZ",flags)) goto L005454da;
  }
  L005454d3: { // 0x5454d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454d4: { // 0x5454d4: 8bc2 MOV EAX, EDX
    s.ax = s.dx;
  }
  L005454d6: { // 0x5454d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454d7: { // 0x5454d7: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005454da: { // 0x5454da: 668974240c MOV word ptr [ESP + 0xc], SI
    m.w16((f.sp+0x0000000cu), (s.si & 0xffffu));
  }
  L005454df: { // 0x5454df: 668944240e MOV word ptr [ESP + 0xe], AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L005454e4: { // 0x5454e4: 8b54240c MOV EDX, dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L005454e8: { // 0x5454e8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005454e9: { // 0x5454e9: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L005454ef: { // 0x5454ef: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L005454f4: { // 0x5454f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005454f5: { // 0x5454f5: c20400 RET 4
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
void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX, ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX, dword ptr [ESP + 8]
    s.cx = m.r32((f.sp+8u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX, EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x62fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x62fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX, EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI, 0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX, 0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x62fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x62fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI, EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x62fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP, 0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP, CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX, [EDI + 1]
    s.ax = (s.di+1u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x62fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX], 0
    (void)integer::sub(m.r8((s.dx)),0u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x62fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x62fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI, dword ptr [EDX + ECX*4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 4u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX, [EDX + ECX*4 + 0xc]
    s.ax = (s.dx+(s.cx * 4u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX, dword ptr [EDX + ECX*4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 4u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI, ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX], ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX, dword ptr [EDX + 4]
    s.ax = m.r32((s.dx+4u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI, dword ptr [EDX + EAX*4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 4u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX, 0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 4], EAX
    m.w32((s.dx+4u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x62fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 4], 0
    m.w32((s.dx+4u), 0u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX, 0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x62fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 8], 0
    m.w32((s.dx+8u), 0u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX, EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x62fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX, EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_001cd4d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd4d0: { // 0x5cd4d0: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L005cd4d4: { // 0x5cd4d4: 81c188000000 ADD ECX, 0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L005cd4da: { // 0x5cd4da: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005cd4db: { // 0x5cd4db: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L005cd4dd: { // 0x5cd4dd: 8b31 MOV ESI, dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L005cd4df: { // 0x5cd4df: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L005cd4e1: { // 0x5cd4e1: 8b7104 MOV ESI, dword ptr [ECX + 4]
    s.si = m.r32((s.cx+4u));
  }
  L005cd4e4: { // 0x5cd4e4: 897204 MOV dword ptr [EDX + 4], ESI
    m.w32((s.dx+4u), s.si);
  }
  L005cd4e7: { // 0x5cd4e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005cd4e8: { // 0x5cd4e8: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L005cd4eb: { // 0x5cd4eb: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L005cd4ee: { // 0x5cd4ee: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5633984u:f_0015f7c0(m,s,child,{});break;
case 5600336u:f_00157450(m,s,child,{});break;
case 5656368u:f_00164f30(m,s,child,{});break;
case 5526672u:f_00145490(m,s,child,{});break;
case 4653760u:f_000702c0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6487616u:f_0022fe40(m,s,child,{});break;
case 6083792u:f_001cd4d0(m,s,child,{});break;
default:throw std::domain_error("recovery1553 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1553 unreviewed tail"); } }

std::uint32_t fun_0055f7c0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0055f7c0: { // 0x55f7c0: 81ece8000000 SUB ESP,0xe8
    f.sp = integer::sub(f.sp,0x000000e8u,32,flags);
  }
  L0055f7c6: { // 0x55f7c6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055f7c7: { // 0x55f7c7: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0055f7c8: { // 0x55f7c8: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0055f7ca: { // 0x55f7ca: 8d542454 LEA EDX,[ESP + 0x54]
    s.dx = (f.sp+0x00000054u);
  }
  L0055f7ce: { // 0x55f7ce: 8b8c24f4000000 MOV ECX,dword ptr [ESP + 0xf4]
    s.cx = m.r32((f.sp+0x000000f4u));
  }
  L0055f7d5: { // 0x55f7d5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f7d6: { // 0x55f7d6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055f7d8: { // 0x55f7d8: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5634011u); flags=s.arithmetic_flags;
  }
  L0055f7db: { // 0x55f7db: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0055f7dd: { // 0x55f7dd: c744242020000000 MOV dword ptr [ESP + 0x20],0x20
    m.w32((f.sp+0x00000020u), 0x00000020u);
  }
  L0055f7e5: { // 0x55f7e5: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0055f7e7: { // 0x55f7e7: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055f7e8: { // 0x55f7e8: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055f7ee: { // 0x55f7ee: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055f7f0: { // 0x55f7f0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055f7f2: { // 0x55f7f2: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0055f7f5: { // 0x55f7f5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055f7f6: { // 0x55f7f6: c1f908 SAR ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055f7f9: { // 0x55f7f9: 8bb7f0000000 MOV ESI,dword ptr [EDI + 0xf0]
    s.si = m.r32((s.di+0x000000f0u));
  }
  L0055f7ff: { // 0x55f7ff: 66894c2424 MOV word ptr [ESP + 0x24],CX
    m.w16((f.sp+0x00000024u), (s.cx & 0xffffu));
  }
  L0055f804: { // 0x55f804: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055f80a: { // 0x55f80a: 0fbfc9 MOVSX ECX,CX
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffffu),16));
  }
  L0055f80d: { // 0x55f80d: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055f80f: { // 0x55f80f: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0055f813: { // 0x55f813: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055f816: { // 0x55f816: 6689442426 MOV word ptr [ESP + 0x26],AX
    m.w16((f.sp+0x00000026u), (s.ax & 0xffffu));
  }
  L0055f81b: { // 0x55f81b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055f81d: { // 0x55f81d: 0fbfc8 MOVSX ECX,AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L0055f820: { // 0x55f820: 8b87f4000000 MOV EAX,dword ptr [EDI + 0xf4]
    s.ax = m.r32((s.di+0x000000f4u));
  }
  L0055f826: { // 0x55f826: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L0055f82a: { // 0x55f82a: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0055f82c: { // 0x55f82c: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f830: { // 0x55f830: 83f820 CMP EAX,0x20
    (void)integer::sub(s.ax,0x00000020u,32,flags);
  }
  L0055f833: { // 0x55f833: 7f04 JG 0x0055f839
    if(integer::condition("JG",flags)) goto L0055f839;
  }
  L0055f835: { // 0x55f835: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0055f839: { // 0x55f839: 8b742420 MOV ESI,dword ptr [ESP + 0x20]
    s.si = m.r32((f.sp+0x00000020u));
  }
  L0055f83d: { // 0x55f83d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0055f83f: { // 0x55f83f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0055f841: { // 0x55f841: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0055f845: { // 0x55f845: 0f8eff030000 JLE 0x0055fc4a
    if(integer::condition("JLE",flags)) goto L0055fc4a;
  }
  L0055f84b: { // 0x55f84b: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0055f84c: { // 0x55f84c: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0055f84d: { // 0x55f84d: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L0055f84f: { // 0x55f84f: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0055f853: { // 0x55f853: eb04 JMP 0x0055f859
    goto L0055f859;
  }
  L0055f855: { // 0x55f855: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0055f859: { // 0x55f859: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0055f85b: { // 0x55f85b: 0f8f7b010000 JG 0x0055f9dc
    if(integer::condition("JG",flags)) goto L0055f9dc;
  }
  L0055f861: { // 0x55f861: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0055f863: { // 0x55f863: 8d9c9498000000 LEA EBX,[ESP + EDX*0x4 + 0x98]
    s.bx = (f.sp+(s.dx * 0x00000004u)+0x00000098u);
  }
  L0055f86a: { // 0x55f86a: 66894c243e MOV word ptr [ESP + 0x3e],CX
    m.w16((f.sp+0x0000003eu), (s.cx & 0xffffu));
  }
  L0055f86f: { // 0x55f86f: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0055f873: { // 0x55f873: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0055f877: { // 0x55f877: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055f879: { // 0x55f879: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055f87a: { // 0x55f87a: 8d3429 LEA ESI,[ECX + EBP*0x1]
    s.si = (s.cx+(s.bp * 0x00000001u));
  }
  L0055f87d: { // 0x55f87d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f87f: { // 0x55f87f: 6689742444 MOV word ptr [ESP + 0x44],SI
    m.w16((f.sp+0x00000044u), (s.si & 0xffffu));
  }
  L0055f884: { // 0x55f884: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  L0055f888: { // 0x55f888: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0055f88c: { // 0x55f88c: e8bf7bffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634193u); flags=s.arithmetic_flags;
  }
  L0055f891: { // 0x55f891: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f893: { // 0x55f893: 747b JZ 0x0055f910
    if(integer::condition("JZ",flags)) goto L0055f910;
  }
  L0055f895: { // 0x55f895: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055f89a: { // 0x55f89a: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055f89f: { // 0x55f89f: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f8a2: { // 0x55f8a2: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055f8a8: { // 0x55f8a8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055f8aa: { // 0x55f8aa: 894c2448 MOV dword ptr [ESP + 0x48],ECX
    m.w32((f.sp+0x00000048u), s.cx);
  }
  L0055f8ae: { // 0x55f8ae: 898c2488000000 MOV dword ptr [ESP + 0x88],ECX
    m.w32((f.sp+0x00000088u), s.cx);
  }
  L0055f8b5: { // 0x55f8b5: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f8b8: { // 0x55f8b8: 8954244c MOV dword ptr [ESP + 0x4c],EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L0055f8bc: { // 0x55f8bc: 8d8c2484000000 LEA ECX,[ESP + 0x84]
    s.cx = (f.sp+0x00000084u);
  }
  L0055f8c3: { // 0x55f8c3: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0055f8c7: { // 0x55f8c7: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055f8cc: { // 0x55f8cc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055f8cd: { // 0x55f8cd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f8ce: { // 0x55f8ce: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0055f8d3: { // 0x55f8d3: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L0055f8d7: { // 0x55f8d7: 8984248c000000 MOV dword ptr [ESP + 0x8c],EAX
    m.w32((f.sp+0x0000008cu), s.ax);
  }
  L0055f8de: { // 0x55f8de: e8ad5bfeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5634275u); flags=s.arithmetic_flags;
  }
  L0055f8e3: { // 0x55f8e3: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055f8e5: { // 0x55f8e5: e8d609f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634282u); flags=s.arithmetic_flags;
  }
  L0055f8ea: { // 0x55f8ea: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L0055f8ee: { // 0x55f8ee: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L0055f8f2: { // 0x55f8f2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055f8f3: { // 0x55f8f3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f8f5: { // 0x55f8f5: e836560000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634298u); flags=s.arithmetic_flags;
  }
  L0055f8fa: { // 0x55f8fa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f8fc: { // 0x55f8fc: 7412 JZ 0x0055f910
    if(integer::condition("JZ",flags)) goto L0055f910;
  }
  L0055f8fe: { // 0x55f8fe: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0055f902: { // 0x55f902: 890b MOV dword ptr [EBX],ECX
    m.w32((s.bx), s.cx);
  }
  L0055f904: { // 0x55f904: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055f908: { // 0x55f908: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055f909: { // 0x55f909: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L0055f90c: { // 0x55f90c: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f910: { // 0x55f910: 837c241418 CMP dword ptr [ESP + 0x14],0x18
    (void)integer::sub(m.r32((f.sp+0x00000014u)),0x00000018u,32,flags);
  }
  L0055f915: { // 0x55f915: 0f84c3020000 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055f91b: { // 0x55f91b: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0055f91f: { // 0x55f91f: 6689742438 MOV word ptr [ESP + 0x38],SI
    m.w16((f.sp+0x00000038u), (s.si & 0xffffu));
  }
  L0055f924: { // 0x55f924: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L0055f928: { // 0x55f928: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055f92a: { // 0x55f92a: 8d0416 LEA EAX,[ESI + EDX*0x1]
    s.ax = (s.si+(s.dx * 0x00000001u));
  }
  L0055f92d: { // 0x55f92d: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0055f931: { // 0x55f931: 668944243e MOV word ptr [ESP + 0x3e],AX
    m.w16((f.sp+0x0000003eu), (s.ax & 0xffffu));
  }
  L0055f936: { // 0x55f936: 8b4c243c MOV ECX,dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L0055f93a: { // 0x55f93a: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f93e: { // 0x55f93e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f93f: { // 0x55f93f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f941: { // 0x55f941: e80a7bffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634374u); flags=s.arithmetic_flags;
  }
  L0055f946: { // 0x55f946: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f948: { // 0x55f948: 7472 JZ 0x0055f9bc
    if(integer::condition("JZ",flags)) goto L0055f9bc;
  }
  L0055f94a: { // 0x55f94a: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055f94f: { // 0x55f94f: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055f954: { // 0x55f954: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f957: { // 0x55f957: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055f95a: { // 0x55f95a: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055f95f: { // 0x55f95f: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055f965: { // 0x55f965: 89442450 MOV dword ptr [ESP + 0x50],EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L0055f969: { // 0x55f969: 89442474 MOV dword ptr [ESP + 0x74],EAX
    m.w32((f.sp+0x00000074u), s.ax);
  }
  L0055f96d: { // 0x55f96d: 894c2454 MOV dword ptr [ESP + 0x54],ECX
    m.w32((f.sp+0x00000054u), s.cx);
  }
  L0055f971: { // 0x55f971: 894c2478 MOV dword ptr [ESP + 0x78],ECX
    m.w32((f.sp+0x00000078u), s.cx);
  }
  L0055f975: { // 0x55f975: 8d442474 LEA EAX,[ESP + 0x74]
    s.ax = (f.sp+0x00000074u);
  }
  L0055f979: { // 0x55f979: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0055f97d: { // 0x55f97d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055f97e: { // 0x55f97e: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055f980: { // 0x55f980: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055f981: { // 0x55f981: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0055f986: { // 0x55f986: 89542460 MOV dword ptr [ESP + 0x60],EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L0055f98a: { // 0x55f98a: e8015bfeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5634447u); flags=s.arithmetic_flags;
  }
  L0055f98f: { // 0x55f98f: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055f991: { // 0x55f991: e82a09f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634454u); flags=s.arithmetic_flags;
  }
  L0055f996: { // 0x55f996: 8d542450 LEA EDX,[ESP + 0x50]
    s.dx = (f.sp+0x00000050u);
  }
  L0055f99a: { // 0x55f99a: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055f99c: { // 0x55f99c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055f99d: { // 0x55f99d: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0055f9a1: { // 0x55f9a1: e88a550000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634470u); flags=s.arithmetic_flags;
  }
  L0055f9a6: { // 0x55f9a6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055f9a8: { // 0x55f9a8: 7412 JZ 0x0055f9bc
    if(integer::condition("JZ",flags)) goto L0055f9bc;
  }
  L0055f9aa: { // 0x55f9aa: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055f9ae: { // 0x55f9ae: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0055f9b2: { // 0x55f9b2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055f9b3: { // 0x55f9b3: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L0055f9b5: { // 0x55f9b5: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055f9b9: { // 0x55f9b9: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L0055f9bc: { // 0x55f9bc: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0055f9c0: { // 0x55f9c0: 83f818 CMP EAX,0x18
    (void)integer::sub(s.ax,0x00000018u,32,flags);
  }
  L0055f9c3: { // 0x55f9c3: 0f8415020000 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055f9c9: { // 0x55f9c9: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L0055f9ca: { // 0x55f9ca: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L0055f9cc: { // 0x55f9cc: 0f8e9dfeffff JLE 0x0055f86f
    if(integer::condition("JLE",flags)) goto L0055f86f;
  }
  L0055f9d2: { // 0x55f9d2: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0055f9d6: { // 0x55f9d6: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0055f9d8: { // 0x55f9d8: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055f9dc: { // 0x55f9dc: 83fa18 CMP EDX,0x18
    (void)integer::sub(s.dx,0x00000018u,32,flags);
  }
  L0055f9df: { // 0x55f9df: 0f84fd010000 JZ 0x0055fbe2
    if(integer::condition("JZ",flags)) goto L0055fbe2;
  }
  L0055f9e5: { // 0x55f9e5: 8d5d01 LEA EBX,[EBP + 0x1]
    s.bx = (s.bp+0x00000001u);
  }
  L0055f9e8: { // 0x55f9e8: 8d48ff LEA ECX,[EAX + -0x1]
    s.cx = (s.ax-0x00000001u);
  }
  L0055f9eb: { // 0x55f9eb: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0055f9ed: { // 0x55f9ed: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L0055f9f1: { // 0x55f9f1: 0f8fca010000 JG 0x0055fbc1
    if(integer::condition("JG",flags)) goto L0055fbc1;
  }
  L0055f9f7: { // 0x55f9f7: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0055f9fb: { // 0x55f9fb: 8dac9498000000 LEA EBP,[ESP + EDX*0x4 + 0x98]
    s.bp = (f.sp+(s.dx * 0x00000004u)+0x00000098u);
  }
  L0055fa02: { // 0x55fa02: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0055fa04: { // 0x55fa04: 66894c2430 MOV word ptr [ESP + 0x30],CX
    m.w16((f.sp+0x00000030u), (s.cx & 0xffffu));
  }
  L0055fa09: { // 0x55fa09: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0055fa0d: { // 0x55fa0d: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  L0055fa11: { // 0x55fa11: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055fa13: { // 0x55fa13: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055fa14: { // 0x55fa14: 8d3413 LEA ESI,[EBX + EDX*0x1]
    s.si = (s.bx+(s.dx * 0x00000001u));
  }
  L0055fa17: { // 0x55fa17: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fa19: { // 0x55fa19: 668974243a MOV word ptr [ESP + 0x3a],SI
    m.w16((f.sp+0x0000003au), (s.si & 0xffffu));
  }
  L0055fa1e: { // 0x55fa1e: 8b442438 MOV EAX,dword ptr [ESP + 0x38]
    s.ax = m.r32((f.sp+0x00000038u));
  }
  L0055fa22: { // 0x55fa22: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0055fa26: { // 0x55fa26: e8257affff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634603u); flags=s.arithmetic_flags;
  }
  L0055fa2b: { // 0x55fa2b: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fa2d: { // 0x55fa2d: 7476 JZ 0x0055faa5
    if(integer::condition("JZ",flags)) goto L0055faa5;
  }
  L0055fa2f: { // 0x55fa2f: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055fa34: { // 0x55fa34: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055fa39: { // 0x55fa39: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055fa3c: { // 0x55fa3c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055fa3e: { // 0x55fa3e: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055fa43: { // 0x55fa43: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055fa46: { // 0x55fa46: 89542470 MOV dword ptr [ESP + 0x70],EDX
    m.w32((f.sp+0x00000070u), s.dx);
  }
  L0055fa4a: { // 0x55fa4a: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055fa50: { // 0x55fa50: 89442468 MOV dword ptr [ESP + 0x68],EAX
    m.w32((f.sp+0x00000068u), s.ax);
  }
  L0055fa54: { // 0x55fa54: 8944247c MOV dword ptr [ESP + 0x7c],EAX
    m.w32((f.sp+0x0000007cu), s.ax);
  }
  L0055fa58: { // 0x55fa58: 8d54247c LEA EDX,[ESP + 0x7c]
    s.dx = (f.sp+0x0000007cu);
  }
  L0055fa5c: { // 0x55fa5c: 8d442468 LEA EAX,[ESP + 0x68]
    s.ax = (f.sp+0x00000068u);
  }
  L0055fa60: { // 0x55fa60: 894c246c MOV dword ptr [ESP + 0x6c],ECX
    m.w32((f.sp+0x0000006cu), s.cx);
  }
  L0055fa64: { // 0x55fa64: 898c2480000000 MOV dword ptr [ESP + 0x80],ECX
    m.w32((f.sp+0x00000080u), s.cx);
  }
  L0055fa6b: { // 0x55fa6b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055fa6c: { // 0x55fa6c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055fa6d: { // 0x55fa6d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0055fa72: { // 0x55fa72: e8195afeff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,5634679u); flags=s.arithmetic_flags;
  }
  L0055fa77: { // 0x55fa77: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055fa79: { // 0x55fa79: e84208f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634686u); flags=s.arithmetic_flags;
  }
  L0055fa7e: { // 0x55fa7e: 8d4c2468 LEA ECX,[ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L0055fa82: { // 0x55fa82: 89442470 MOV dword ptr [ESP + 0x70],EAX
    m.w32((f.sp+0x00000070u), s.ax);
  }
  L0055fa86: { // 0x55fa86: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0055fa87: { // 0x55fa87: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fa89: { // 0x55fa89: e8a2540000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634702u); flags=s.arithmetic_flags;
  }
  L0055fa8e: { // 0x55fa8e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fa90: { // 0x55fa90: 7413 JZ 0x0055faa5
    if(integer::condition("JZ",flags)) goto L0055faa5;
  }
  L0055fa92: { // 0x55fa92: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055fa96: { // 0x55fa96: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0055fa9a: { // 0x55fa9a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055fa9b: { // 0x55fa9b: 895500 MOV dword ptr [EBP],EDX
    m.w32((s.bp), s.dx);
  }
  L0055fa9e: { // 0x55fa9e: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055faa2: { // 0x55faa2: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0055faa5: { // 0x55faa5: 837c241418 CMP dword ptr [ESP + 0x14],0x18
    (void)integer::sub(m.r32((f.sp+0x00000014u)),0x00000018u,32,flags);
  }
  L0055faaa: { // 0x55faaa: 0f842e010000 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055fab0: { // 0x55fab0: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055fab4: { // 0x55fab4: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0055fab8: { // 0x55fab8: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0055faba: { // 0x55faba: 6689742436 MOV word ptr [ESP + 0x36],SI
    m.w16((f.sp+0x00000036u), (s.si & 0xffffu));
  }
  L0055fabf: { // 0x55fabf: 6689442434 MOV word ptr [ESP + 0x34],AX
    m.w16((f.sp+0x00000034u), (s.ax & 0xffffu));
  }
  L0055fac4: { // 0x55fac4: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0055fac8: { // 0x55fac8: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0055facc: { // 0x55facc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0055face: { // 0x55face: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055facf: { // 0x55facf: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fad1: { // 0x55fad1: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0055fad5: { // 0x55fad5: e87679ffff CALL 0x00557450
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557450u,5634778u); flags=s.arithmetic_flags;
  }
  L0055fada: { // 0x55fada: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fadc: { // 0x55fadc: 0f84bf000000 JZ 0x0055fba1
    if(integer::condition("JZ",flags)) goto L0055fba1;
  }
  L0055fae2: { // 0x55fae2: 0fbf442410 MOVSX EAX,word ptr [ESP + 0x10]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000010u)),16));
  }
  L0055fae7: { // 0x55fae7: 0fbf4c2412 MOVSX ECX,word ptr [ESP + 0x12]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x00000012u)),16));
  }
  L0055faec: { // 0x55faec: c1e008 SHL EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055faef: { // 0x55faef: 0580000000 ADD EAX,0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L0055faf4: { // 0x55faf4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0055faf6: { // 0x55faf6: 8944245c MOV dword ptr [ESP + 0x5c],EAX
    m.w32((f.sp+0x0000005cu), s.ax);
  }
  L0055fafa: { // 0x55fafa: 89542464 MOV dword ptr [ESP + 0x64],EDX
    m.w32((f.sp+0x00000064u), s.dx);
  }
  L0055fafe: { // 0x55fafe: 8984248c000000 MOV dword ptr [ESP + 0x8c],EAX
    m.w32((f.sp+0x0000008cu), s.ax);
  }
  L0055fb05: { // 0x55fb05: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055fb06: { // 0x55fb06: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055fb0c: { // 0x55fb0c: c1e108 SHL ECX,0x8
    s.cx = integer::shift(s.cx,0x00000008u,32,flags,integer::Shift::left);
  }
  L0055fb0f: { // 0x55fb0f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055fb11: { // 0x55fb11: 81c180000000 ADD ECX,0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L0055fb17: { // 0x55fb17: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0055fb19: { // 0x55fb19: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0055fb1b: { // 0x55fb1b: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0055fb1c: { // 0x55fb1c: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0055fb22: { // 0x55fb22: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0055fb26: { // 0x55fb26: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055fb28: { // 0x55fb28: 898c2490000000 MOV dword ptr [ESP + 0x90],ECX
    m.w32((f.sp+0x00000090u), s.cx);
  }
  L0055fb2f: { // 0x55fb2f: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055fb32: { // 0x55fb32: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0055fb34: { // 0x55fb34: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0055fb37: { // 0x55fb37: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055fb3a: { // 0x55fb3a: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0055fb3c: { // 0x55fb3c: 7815 JS 0x0055fb53
    if(integer::condition("JS",flags)) goto L0055fb53;
  }
  L0055fb3e: { // 0x55fb3e: 3b0d5ca98100 CMP ECX,dword ptr [0x0081a95c]
    (void)integer::sub(s.cx,m.r32((0x0081a95cu)),32,flags);
  }
  L0055fb44: { // 0x55fb44: 7d0d JGE 0x0055fb53
    if(integer::condition("JGE",flags)) goto L0055fb53;
  }
  L0055fb46: { // 0x55fb46: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0055fb4c: { // 0x55fb4c: 8b0c8a MOV ECX,dword ptr [EDX + ECX*0x4]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)));
  }
  L0055fb4f: { // 0x55fb4f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0055fb51: { // 0x55fb51: 751a JNZ 0x0055fb6d
    if(integer::condition("JNZ",flags)) goto L0055fb6d;
  }
  L0055fb53: { // 0x55fb53: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055fb54: { // 0x55fb54: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0055fb55: { // 0x55fb55: 8d8c249c000000 LEA ECX,[ESP + 0x9c]
    s.cx = (f.sp+0x0000009cu);
  }
  L0055fb5c: { // 0x55fb5c: e8cfb1ecff CALL 0x0042ad30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,5634913u); flags=s.arithmetic_flags;
  }
  L0055fb61: { // 0x55fb61: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0055fb63: { // 0x55fb63: b91076a500 MOV ECX,0xa57610
    s.cx = 0x00a57610u;
  }
  L0055fb68: { // 0x55fb68: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055fb6d: { // 0x55fb6d: 8d94248c000000 LEA EDX,[ESP + 0x8c]
    s.dx = (f.sp+0x0000008cu);
  }
  L0055fb74: { // 0x55fb74: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055fb75: { // 0x55fb75: e84607f1ff CALL 0x004702c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004702c0u,5634938u); flags=s.arithmetic_flags;
  }
  L0055fb7a: { // 0x55fb7a: 89442464 MOV dword ptr [ESP + 0x64],EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L0055fb7e: { // 0x55fb7e: 8d44245c LEA EAX,[ESP + 0x5c]
    s.ax = (f.sp+0x0000005cu);
  }
  L0055fb82: { // 0x55fb82: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0055fb83: { // 0x55fb83: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0055fb85: { // 0x55fb85: e8a6530000 CALL 0x00564f30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00564f30u,5634954u); flags=s.arithmetic_flags;
  }
  L0055fb8a: { // 0x55fb8a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0055fb8c: { // 0x55fb8c: 7413 JZ 0x0055fba1
    if(integer::condition("JZ",flags)) goto L0055fba1;
  }
  L0055fb8e: { // 0x55fb8e: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0055fb92: { // 0x55fb92: 894d00 MOV dword ptr [EBP],ECX
    m.w32((s.bp), s.cx);
  }
  L0055fb95: { // 0x55fb95: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055fb99: { // 0x55fb99: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0055fb9a: { // 0x55fb9a: 83c504 ADD EBP,0x4
    s.bp = integer::add(s.bp,0x00000004u,32,flags);
  }
  L0055fb9d: { // 0x55fb9d: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L0055fba1: { // 0x55fba1: 837c241418 CMP dword ptr [ESP + 0x14],0x18
    (void)integer::sub(m.r32((f.sp+0x00000014u)),0x00000018u,32,flags);
  }
  L0055fba6: { // 0x55fba6: 7436 JZ 0x0055fbde
    if(integer::condition("JZ",flags)) goto L0055fbde;
  }
  L0055fba8: { // 0x55fba8: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L0055fbac: { // 0x55fbac: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0055fbad: { // 0x55fbad: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0055fbaf: { // 0x55fbaf: 0f8e54feffff JLE 0x0055fa09
    if(integer::condition("JLE",flags)) goto L0055fa09;
  }
  L0055fbb5: { // 0x55fbb5: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0055fbb9: { // 0x55fbb9: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055fbbd: { // 0x55fbbd: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0055fbc1: { // 0x55fbc1: 83fa18 CMP EDX,0x18
    (void)integer::sub(s.dx,0x00000018u,32,flags);
  }
  L0055fbc4: { // 0x55fbc4: 741c JZ 0x0055fbe2
    if(integer::condition("JZ",flags)) goto L0055fbe2;
  }
  L0055fbc6: { // 0x55fbc6: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L0055fbca: { // 0x55fbca: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0055fbcb: { // 0x55fbcb: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0055fbcc: { // 0x55fbcc: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0055fbce: { // 0x55fbce: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L0055fbd2: { // 0x55fbd2: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0055fbd6: { // 0x55fbd6: 0f8c79fcffff JL 0x0055f855
    if(integer::condition("JL",flags)) goto L0055f855;
  }
  L0055fbdc: { // 0x55fbdc: eb04 JMP 0x0055fbe2
    goto L0055fbe2;
  }
  L0055fbde: { // 0x55fbde: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0055fbe2: { // 0x55fbe2: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0055fbe3: { // 0x55fbe3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0055fbe4: { // 0x55fbe4: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0055fbe6: { // 0x55fbe6: 7e5e JLE 0x0055fc46
    if(integer::condition("JLE",flags)) goto L0055fc46;
  }
  L0055fbe8: { // 0x55fbe8: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0055fbe9: { // 0x55fbe9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0055fbea: { // 0x55fbea: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L0055fbf0: { // 0x55fbf0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0055fbf2: { // 0x55fbf2: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L0055fbf8: { // 0x55fbf8: e843020d00 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5635069u); flags=s.arithmetic_flags;
  }
  L0055fbfd: { // 0x55fbfd: 0fbf948490000000 MOVSX EDX,word ptr [ESP + EAX*0x4 + 0x90]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((f.sp+(s.ax * 0x00000004u)+0x00000090u)),16));
  }
  L0055fc05: { // 0x55fc05: 8d8c8490000000 LEA ECX,[ESP + EAX*0x4 + 0x90]
    s.cx = (f.sp+(s.ax * 0x00000004u)+0x00000090u);
  }
  L0055fc0c: { // 0x55fc0c: 0fbf848492000000 MOVSX EAX,word ptr [ESP + EAX*0x4 + 0x92]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+(s.ax * 0x00000004u)+0x00000092u)),16));
  }
  L0055fc14: { // 0x55fc14: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055fc17: { // 0x55fc17: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0055fc19: { // 0x55fc19: 7814 JS 0x0055fc2f
    if(integer::condition("JS",flags)) goto L0055fc2f;
  }
  L0055fc1b: { // 0x55fc1b: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055fc20: { // 0x55fc20: 7d0d JGE 0x0055fc2f
    if(integer::condition("JGE",flags)) goto L0055fc2f;
  }
  L0055fc22: { // 0x55fc22: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0055fc28: { // 0x55fc28: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0055fc2b: { // 0x55fc2b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055fc2d: { // 0x55fc2d: 754b JNZ 0x0055fc7a
    if(integer::condition("JNZ",flags)) goto L0055fc7a;
  }
  L0055fc2f: { // 0x55fc2f: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0055fc31: { // 0x55fc31: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055fc32: { // 0x55fc32: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0055fc37: { // 0x55fc37: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0055fc3c: { // 0x55fc3c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055fc3d: { // 0x55fc3d: 81c4e8000000 ADD ESP,0xe8
    f.sp = integer::add(f.sp,0x000000e8u,32,flags);
  }
  L0055fc43: { // 0x55fc43: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0055fc46: { // 0x55fc46: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0055fc4a: { // 0x55fc4a: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0055fc4e: { // 0x55fc4e: c1e109 SHL ECX,0x9
    s.cx = integer::shift(s.cx,0x00000009u,32,flags,integer::Shift::left);
  }
  L0055fc51: { // 0x55fc51: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0055fc53: { // 0x55fc53: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0055fc55: { // 0x55fc55: 7814 JS 0x0055fc6b
    if(integer::condition("JS",flags)) goto L0055fc6b;
  }
  L0055fc57: { // 0x55fc57: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0055fc5c: { // 0x55fc5c: 7d0d JGE 0x0055fc6b
    if(integer::condition("JGE",flags)) goto L0055fc6b;
  }
  L0055fc5e: { // 0x55fc5e: 8b0d58a98100 MOV ECX,dword ptr [0x0081a958]
    s.cx = m.r32((0x0081a958u));
  }
  L0055fc64: { // 0x55fc64: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0055fc67: { // 0x55fc67: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0055fc69: { // 0x55fc69: 750f JNZ 0x0055fc7a
    if(integer::condition("JNZ",flags)) goto L0055fc7a;
  }
  L0055fc6b: { // 0x55fc6b: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L0055fc6f: { // 0x55fc6f: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0055fc74: { // 0x55fc74: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L0055fc7a: { // 0x55fc7a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0055fc7b: { // 0x55fc7b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0055fc7c: { // 0x55fc7c: 81c4e8000000 ADD ESP,0xe8
    f.sp = integer::add(f.sp,0x000000e8u,32,flags);
  }
  L0055fc82: { // 0x55fc82: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
