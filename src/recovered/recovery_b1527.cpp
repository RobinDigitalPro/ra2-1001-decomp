#include "recovered/recovery_b1527_offsets.hpp"
#include "recovered/recovery_b1527_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1527 {
namespace {
void f_000ea880(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00073a30(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_000ea880(Memory& m,State& s,Frame& f,const Operations& op) { const auto world=m.r32(f.sp+4u);const auto bx=static_cast<std::int32_t>(m.r32(world))/256,by=static_cast<std::int32_t>(m.r32(world+4u))/256;if(bx < -200||bx > -50||by < -200||by > -50||m.r32(0x790914u)!=369u||m.r8(0xa285a8u)!=1u||m.r32(0xa576f8u)!=0u)throw std::domain_error("B1527 selected boundary domain");for(unsigned k=0;k<369u;++k)if(m.r32(0xa56e68u+4u*k)!=authentic_offsets[k])throw std::domain_error("B1527 original offset producer");
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ea880: { // 0x4ea880: 83ec40 SUB ESP, 0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L004ea883: { // 0x4ea883: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004ea884: { // 0x4ea884: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ea885: { // 0x4ea885: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ea886: { // 0x4ea886: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L004ea888: { // 0x4ea888: 8b4c2450 MOV ECX, dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L004ea88c: { // 0x4ea88c: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004ea88e: { // 0x4ea88e: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L004ea892: { // 0x4ea892: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L004ea896: { // 0x4ea896: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ea898: { // 0x4ea898: 89742410 MOV dword ptr [ESP + 0x10], ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004ea89c: { // 0x4ea89c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ea89d: { // 0x4ea89d: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004ea8a3: { // 0x4ea8a3: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ea8a5: { // 0x4ea8a5: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L004ea8a7: { // 0x4ea8a7: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L004ea8aa: { // 0x4ea8aa: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ea8ab: { // 0x4ea8ab: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004ea8b1: { // 0x4ea8b1: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ea8b3: { // 0x4ea8b3: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004ea8b5: { // 0x4ea8b5: a114097900 MOV EAX, dword ptr [0x790914]
    s.ax = m.r32((0x00790914u));
  }
  L004ea8ba: { // 0x4ea8ba: c1fd08 SAR EBP, 8
    s.bp = integer::shift(s.bp,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ea8bd: { // 0x4ea8bd: c1f908 SAR ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ea8c0: { // 0x4ea8c0: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004ea8c2: { // 0x4ea8c2: 66894c2422 MOV word ptr [ESP + 0x22], CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  L004ea8c7: { // 0x4ea8c7: 0f8e8b010000 JLE 0x4eaa58
    if(integer::condition("JLE",flags)) goto L004eaa58;
  }
  L004ea8cd: { // 0x4ea8cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ea8ce: { // 0x4ea8ce: bb686ea500 MOV EBX, 0xa56e68
    s.bx = 0x00a56e68u;
  }
  L004ea8d3: { // 0x4ea8d3: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004ea8d7: { // 0x4ea8d7: eb05 JMP 0x4ea8de
    goto L004ea8de;
  }
  L004ea8d9: { // 0x4ea8d9: 668b4c2426 MOV CX, word ptr [ESP + 0x26]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000026u)));
  }
  L004ea8de: { // 0x4ea8de: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L004ea8e1: { // 0x4ea8e1: 668b5302 MOV DX, word ptr [EBX + 2]
    s.dx = with_ax(s.dx, m.r16((s.bx+2u)));
  }
  L004ea8e5: { // 0x4ea8e5: 6603c5 ADD AX, BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L004ea8e8: { // 0x4ea8e8: 6603d1 ADD DX, CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L004ea8eb: { // 0x4ea8eb: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L004ea8ef: { // 0x4ea8ef: 6689442410 MOV word ptr [ESP + 0x10], AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L004ea8f4: { // 0x4ea8f4: 6689542412 MOV word ptr [ESP + 0x12], DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L004ea8f9: { // 0x4ea8f9: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004ea8fd: { // 0x4ea8fd: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004ea8ff: { // 0x4ea8ff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ea900: { // 0x4ea900: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004ea905: { // 0x4ea905: 89442430 MOV dword ptr [ESP + 0x30], EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L004ea909: { // 0x4ea909: e8f2ab0500 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5155086u); flags=s.arithmetic_flags;
  }
  L004ea90e: { // 0x4ea90e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004ea910: { // 0x4ea910: e81b91f8ff CALL 0x473a30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00473a30u,5155093u); flags=s.arithmetic_flags;
  }
  L004ea915: { // 0x4ea915: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L004ea917: { // 0x4ea917: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004ea919: { // 0x4ea919: 0f841e010000 JZ 0x4eaa3d
    if(integer::condition("JZ",flags)) goto L004eaa3d;
  }
  L004ea91f: { // 0x4ea91f: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L004ea922: { // 0x4ea922: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ea924: { // 0x4ea924: 0f8513010000 JNZ 0x4eaa3d
    if(integer::condition("JNZ",flags)) goto L004eaa3d;
  }
  L004ea92a: { // 0x4ea92a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ea92c: { // 0x4ea92c: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea92e: { // 0x4ea92e: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),5155121u); flags=s.arithmetic_flags;
  }
  L004ea931: { // 0x4ea931: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ea933: { // 0x4ea933: 7437 JZ 0x4ea96c
    if(integer::condition("JZ",flags)) goto L004ea96c;
  }
  L004ea935: { // 0x4ea935: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004ea937: { // 0x4ea937: 0f8400010000 JZ 0x4eaa3d
    if(integer::condition("JZ",flags)) goto L004eaa3d;
  }
  L004ea93d: { // 0x4ea93d: 8b4830 MOV ECX, dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L004ea940: { // 0x4ea940: 8b4730 MOV EAX, dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  L004ea943: { // 0x4ea943: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004ea945: { // 0x4ea945: 7504 JNZ 0x4ea94b
    if(integer::condition("JNZ",flags)) goto L004ea94b;
  }
  L004ea947: { // 0x4ea947: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004ea949: { // 0x4ea949: eb19 JMP 0x4ea964
    goto L004ea964;
  }
  L004ea94b: { // 0x4ea94b: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004ea94e: { // 0x4ea94e: 7412 JZ 0x4ea962
    if(integer::condition("JZ",flags)) goto L004ea962;
  }
  L004ea950: { // 0x4ea950: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004ea955: { // 0x4ea955: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004ea957: { // 0x4ea957: 858774560000 TEST dword ptr [EDI + 0x5674], EAX
    (void)integer::logical((m.r32((s.di+0x00005674u)))&(s.ax),32,flags);
  }
  L004ea95d: { // 0x4ea95d: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004ea960: { // 0x4ea960: eb02 JMP 0x4ea964
    goto L004ea964;
  }
  L004ea962: { // 0x4ea962: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004ea964: { // 0x4ea964: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ea966: { // 0x4ea966: 0f85d1000000 JNZ 0x4eaa3d
    if(integer::condition("JNZ",flags)) goto L004eaa3d;
  }
  L004ea96c: { // 0x4ea96c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ea96e: { // 0x4ea96e: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L004ea974: { // 0x4ea974: 8d442438 LEA EAX, [ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L004ea978: { // 0x4ea978: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea97a: { // 0x4ea97a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ea97b: { // 0x4ea97b: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),5155198u); flags=s.arithmetic_flags;
  }
  L004ea97e: { // 0x4ea97e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ea97f: { // 0x4ea97f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004ea981: { // 0x4ea981: e8daf8ffff CALL 0x4ea260
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ea260u,5155206u); flags=s.arithmetic_flags;
  }
  L004ea986: { // 0x4ea986: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L004ea989: { // 0x4ea989: 0f85aa000000 JNZ 0x4eaa39
    if(integer::condition("JNZ",flags)) goto L004eaa39;
  }
  L004ea98f: { // 0x4ea98f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ea991: { // 0x4ea991: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea993: { // 0x4ea993: ff92b0010000 CALL dword ptr [EDX + 0x1b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001b0u)),5155225u); flags=s.arithmetic_flags;
  }
  L004ea999: { // 0x4ea999: 83f8ec CMP EAX, -0x14
    (void)integer::sub(s.ax,0xffffffecu,32,flags);
  }
  L004ea99c: { // 0x4ea99c: 0f8c97000000 JL 0x4eaa39
    if(integer::condition("JL",flags)) goto L004eaa39;
  }
  L004ea9a2: { // 0x4ea9a2: 83beb801000002 CMP dword ptr [ESI + 0x1b8], 2
    (void)integer::sub(m.r32((s.si+0x000001b8u)),2u,32,flags);
  }
  L004ea9a9: { // 0x4ea9a9: 0f848a000000 JZ 0x4eaa39
    if(integer::condition("JZ",flags)) goto L004eaa39;
  }
  L004ea9af: { // 0x4ea9af: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ea9b1: { // 0x4ea9b1: 8d4c2444 LEA ECX, [ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L004ea9b5: { // 0x4ea9b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ea9b6: { // 0x4ea9b6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea9b8: { // 0x4ea9b8: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5155259u); flags=s.arithmetic_flags;
  }
  L004ea9bb: { // 0x4ea9bb: 8b4c2454 MOV ECX, dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L004ea9bf: { // 0x4ea9bf: 8b38 MOV EDI, dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004ea9c1: { // 0x4ea9c1: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L004ea9c4: { // 0x4ea9c4: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004ea9c6: { // 0x4ea9c6: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L004ea9c8: { // 0x4ea9c8: 8b7804 MOV EDI, dword ptr [EAX + 4]
    s.di = m.r32((s.ax+4u));
  }
  L004ea9cb: { // 0x4ea9cb: 89542434 MOV dword ptr [ESP + 0x34], EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L004ea9cf: { // 0x4ea9cf: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  L004ea9d2: { // 0x4ea9d2: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L004ea9d5: { // 0x4ea9d5: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L004ea9d7: { // 0x4ea9d7: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L004ea9db: { // 0x4ea9db: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L004ea9de: { // 0x4ea9de: db442438 FILD dword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load_integer32(m.r32(address));
  }
  L004ea9e2: { // 0x4ea9e2: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004ea9e4: { // 0x4ea9e4: 894c243c MOV dword ptr [ESP + 0x3c], ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L004ea9e8: { // 0x4ea9e8: db44243c FILD dword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004ea9ec: { // 0x4ea9ec: db442434 FILD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L004ea9f0: { // 0x4ea9f0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004ea9f2: { // 0x4ea9f2: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004ea9f4: { // 0x4ea9f4: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004ea9f6: { // 0x4ea9f6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004ea9f8: { // 0x4ea9f8: dec1 FADDP ST1
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004ea9fa: { // 0x4ea9fa: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L004ea9fc: { // 0x4ea9fc: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L004ea9fe: { // 0x4ea9fe: dec1 FADDP ST1
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004eaa00: { // 0x4eaa00: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004eaa03: { // 0x4eaa03: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004eaa05: { // 0x4eaa05: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004eaa07: { // 0x4eaa07: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004eaa09: { // 0x4eaa09: e872f6fcff CALL 0x4ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5155342u); flags=s.arithmetic_flags;
  }
  L004eaa0e: { // 0x4eaa0e: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004eaa11: { // 0x4eaa11: e83a002800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5155350u); flags=s.arithmetic_flags;
  }
  L004eaa16: { // 0x4eaa16: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004eaa18: { // 0x4eaa18: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004eaa1a: { // 0x4eaa1a: e8c1031e00 CALL 0x6cade0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cade0u,5155359u); flags=s.arithmetic_flags;
  }
  L004eaa1f: { // 0x4eaa1f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eaa21: { // 0x4eaa21: 7402 JZ 0x4eaa25
    if(integer::condition("JZ",flags)) goto L004eaa25;
  }
  L004eaa23: { // 0x4eaa23: 03ff ADD EDI, EDI
    s.di = integer::add(s.di,s.di,32,flags);
  }
  L004eaa25: { // 0x4eaa25: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004eaa29: { // 0x4eaa29: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eaa2b: { // 0x4eaa2b: 7404 JZ 0x4eaa31
    if(integer::condition("JZ",flags)) goto L004eaa31;
  }
  L004eaa2d: { // 0x4eaa2d: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004eaa2f: { // 0x4eaa2f: 7d08 JGE 0x4eaa39
    if(integer::condition("JGE",flags)) goto L004eaa39;
  }
  L004eaa31: { // 0x4eaa31: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L004eaa35: { // 0x4eaa35: 89742420 MOV dword ptr [ESP + 0x20], ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L004eaa39: { // 0x4eaa39: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L004eaa3d: { // 0x4eaa3d: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004eaa41: { // 0x4eaa41: 83c304 ADD EBX, 4
    s.bx = integer::add(s.bx,4u,32,flags);
  }
  L004eaa44: { // 0x4eaa44: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004eaa45: { // 0x4eaa45: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004eaa49: { // 0x4eaa49: 0f858afeffff JNZ 0x4ea8d9
    if(integer::condition("JNZ",flags)) goto L004ea8d9;
  }
  L004eaa4f: { // 0x4eaa4f: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004eaa53: { // 0x4eaa53: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004eaa54: { // 0x4eaa54: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eaa56: { // 0x4eaa56: 7502 JNZ 0x4eaa5a
    if(integer::condition("JNZ",flags)) goto L004eaa5a;
  }
  L004eaa58: { // 0x4eaa58: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004eaa5a: { // 0x4eaa5a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eaa5b: { // 0x4eaa5b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa5c: { // 0x4eaa5c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004eaa5d: { // 0x4eaa5d: 83c440 ADD ESP, 0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L004eaa60: { // 0x4eaa60: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX, dword ptr [ESP + 4]
    s.dx = m.r32((f.sp+4u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX, word ptr [EDX + 2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+2u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI, word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX, 9
    s.ax = integer::shift(s.ax,9u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX, ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX, 0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX, dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX, dword ptr [ECX + EAX*4]
    s.ax = m.r32((s.cx+(s.ax * 4u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX, dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX, 0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0xa57634], EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00073a30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00473a30: { // 0x473a30: a0a885a200 MOV AL, byte ptr [0xa285a8]
    s.ax = with_al(s.ax, m.r8((0x00a285a8u)));
  }
  L00473a35: { // 0x473a35: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00473a36: { // 0x473a36: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00473a38: { // 0x473a38: 742d JZ 0x473a67
    if(integer::condition("JZ",flags)) goto L00473a67;
  }
  L00473a3a: { // 0x473a3a: 8a442408 MOV AL, byte ptr [ESP + 8]
    s.ax = with_al(s.ax, m.r8((f.sp+8u)));
  }
  L00473a3e: { // 0x473a3e: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00473a40: { // 0x473a40: 7408 JZ 0x473a4a
    if(integer::condition("JZ",flags)) goto L00473a4a;
  }
  L00473a42: { // 0x473a42: 8bb1e8000000 MOV ESI, dword ptr [ECX + 0xe8]
    s.si = m.r32((s.cx+0x000000e8u));
  }
  L00473a48: { // 0x473a48: eb06 JMP 0x473a50
    goto L00473a50;
  }
  L00473a4a: { // 0x473a4a: 8bb1e4000000 MOV ESI, dword ptr [ECX + 0xe4]
    s.si = m.r32((s.cx+0x000000e4u));
  }
  L00473a50: { // 0x473a50: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00473a52: { // 0x473a52: 7413 JZ 0x473a67
    if(integer::condition("JZ",flags)) goto L00473a67;
  }
  L00473a54: { // 0x473a54: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00473a56: { // 0x473a56: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00473a58: { // 0x473a58: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4667995u); flags=s.arithmetic_flags;
  }
  L00473a5b: { // 0x473a5b: 83f801 CMP EAX, 1
    (void)integer::sub(s.ax,1u,32,flags);
  }
  L00473a5e: { // 0x473a5e: 740d JZ 0x473a6d
    if(integer::condition("JZ",flags)) goto L00473a6d;
  }
  L00473a60: { // 0x473a60: 8b7630 MOV ESI, dword ptr [ESI + 0x30]
    s.si = m.r32((s.si+0x00000030u));
  }
  L00473a63: { // 0x473a63: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00473a65: { // 0x473a65: 75ed JNZ 0x473a54
    if(integer::condition("JNZ",flags)) goto L00473a54;
  }
  L00473a67: { // 0x473a67: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00473a69: { // 0x473a69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00473a6a: { // 0x473a6a: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00473a6d: { // 0x473a6d: 8bc6 MOV EAX, ESI
    s.ax = s.si;
  }
  L00473a6f: { // 0x473a6f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00473a70: { // 0x473a70: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5154944u:f_000ea880(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4667952u:f_00073a30(m,s,child,{});break;
default:throw std::domain_error("recovery1527 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ throw std::domain_error("B1527 no reviewed tail"); } }

std::uint32_t fun_004ea880(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);
 const auto world=m.r32(f.sp+4u);const auto bx=static_cast<std::int32_t>(m.r32(world))/256,by=static_cast<std::int32_t>(m.r32(world+4u))/256;if(bx < -200||bx > -50||by < -200||by > -50||m.r32(0x790914u)!=369u||m.r8(0xa285a8u)!=1u||m.r32(0xa576f8u)!=0u)throw std::domain_error("B1527 selected boundary domain");for(unsigned k=0;k<369u;++k)if(m.r32(0xa56e68u+4u*k)!=authentic_offsets[k])throw std::domain_error("B1527 original offset producer");
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004ea880: { // 0x4ea880: 83ec40 SUB ESP, 0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L004ea883: { // 0x4ea883: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004ea884: { // 0x4ea884: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004ea885: { // 0x4ea885: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004ea886: { // 0x4ea886: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L004ea888: { // 0x4ea888: 8b4c2450 MOV ECX, dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  L004ea88c: { // 0x4ea88c: 33f6 XOR ESI, ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004ea88e: { // 0x4ea88e: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L004ea892: { // 0x4ea892: 8974241c MOV dword ptr [ESP + 0x1c], ESI
    m.w32((f.sp+0x0000001cu), s.si);
  }
  L004ea896: { // 0x4ea896: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004ea898: { // 0x4ea898: 89742410 MOV dword ptr [ESP + 0x10], ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L004ea89c: { // 0x4ea89c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ea89d: { // 0x4ea89d: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004ea8a3: { // 0x4ea8a3: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ea8a5: { // 0x4ea8a5: 8be8 MOV EBP, EAX
    s.bp = s.ax;
  }
  L004ea8a7: { // 0x4ea8a7: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L004ea8aa: { // 0x4ea8aa: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004ea8ab: { // 0x4ea8ab: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004ea8b1: { // 0x4ea8b1: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004ea8b3: { // 0x4ea8b3: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004ea8b5: { // 0x4ea8b5: a114097900 MOV EAX, dword ptr [0x790914]
    s.ax = m.r32((0x00790914u));
  }
  L004ea8ba: { // 0x4ea8ba: c1fd08 SAR EBP, 8
    s.bp = integer::shift(s.bp,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ea8bd: { // 0x4ea8bd: c1f908 SAR ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L004ea8c0: { // 0x4ea8c0: 3bc6 CMP EAX, ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L004ea8c2: { // 0x4ea8c2: 66894c2422 MOV word ptr [ESP + 0x22], CX
    m.w16((f.sp+0x00000022u), (s.cx & 0xffffu));
  }
  L004ea8c7: { // 0x4ea8c7: 0f8e8b010000 JLE 0x4eaa58
    if(integer::condition("JLE",flags)) goto L004eaa58;
  }
  L004ea8cd: { // 0x4ea8cd: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004ea8ce: { // 0x4ea8ce: bb686ea500 MOV EBX, 0xa56e68
    s.bx = 0x00a56e68u;
  }
  L004ea8d3: { // 0x4ea8d3: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004ea8d7: { // 0x4ea8d7: eb05 JMP 0x4ea8de
    goto L004ea8de;
  }
  L004ea8d9: { // 0x4ea8d9: 668b4c2426 MOV CX, word ptr [ESP + 0x26]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000026u)));
  }
  L004ea8de: { // 0x4ea8de: 668b03 MOV AX, word ptr [EBX]
    s.ax = with_ax(s.ax, m.r16((s.bx)));
  }
  L004ea8e1: { // 0x4ea8e1: 668b5302 MOV DX, word ptr [EBX + 2]
    s.dx = with_ax(s.dx, m.r16((s.bx+2u)));
  }
  L004ea8e5: { // 0x4ea8e5: 6603c5 ADD AX, BP
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bp & 0xffffu),16,flags));
  }
  L004ea8e8: { // 0x4ea8e8: 6603d1 ADD DX, CX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.cx & 0xffffu),16,flags));
  }
  L004ea8eb: { // 0x4ea8eb: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L004ea8ef: { // 0x4ea8ef: 6689442410 MOV word ptr [ESP + 0x10], AX
    m.w16((f.sp+0x00000010u), (s.ax & 0xffffu));
  }
  L004ea8f4: { // 0x4ea8f4: 6689542412 MOV word ptr [ESP + 0x12], DX
    m.w16((f.sp+0x00000012u), (s.dx & 0xffffu));
  }
  L004ea8f9: { // 0x4ea8f9: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004ea8fd: { // 0x4ea8fd: 6a01 PUSH 1
    f.push(m,1u);
  }
  L004ea8ff: { // 0x4ea8ff: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ea900: { // 0x4ea900: b920a88100 MOV ECX, 0x81a820
    s.cx = 0x0081a820u;
  }
  L004ea905: { // 0x4ea905: 89442430 MOV dword ptr [ESP + 0x30], EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L004ea909: { // 0x4ea909: e8f2ab0500 CALL 0x545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5155086u); flags=s.arithmetic_flags;
  }
  L004ea90e: { // 0x4ea90e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L004ea910: { // 0x4ea910: e81b91f8ff CALL 0x473a30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00473a30u,5155093u); flags=s.arithmetic_flags;
  }
  L004ea915: { // 0x4ea915: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L004ea917: { // 0x4ea917: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004ea919: { // 0x4ea919: 0f841e010000 JZ 0x4eaa3d
    if(integer::condition("JZ",flags)) goto L004eaa3d;
  }
  L004ea91f: { // 0x4ea91f: 8a4676 MOV AL, byte ptr [ESI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000076u)));
  }
  L004ea922: { // 0x4ea922: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ea924: { // 0x4ea924: 0f8513010000 JNZ 0x4eaa3d
    if(integer::condition("JNZ",flags)) goto L004eaa3d;
  }
  L004ea92a: { // 0x4ea92a: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ea92c: { // 0x4ea92c: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea92e: { // 0x4ea92e: ff523c CALL dword ptr [EDX + 0x3c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000003cu)),5155121u); flags=s.arithmetic_flags;
  }
  L004ea931: { // 0x4ea931: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004ea933: { // 0x4ea933: 7437 JZ 0x4ea96c
    if(integer::condition("JZ",flags)) goto L004ea96c;
  }
  L004ea935: { // 0x4ea935: 3bc7 CMP EAX, EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L004ea937: { // 0x4ea937: 0f8400010000 JZ 0x4eaa3d
    if(integer::condition("JZ",flags)) goto L004eaa3d;
  }
  L004ea93d: { // 0x4ea93d: 8b4830 MOV ECX, dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L004ea940: { // 0x4ea940: 8b4730 MOV EAX, dword ptr [EDI + 0x30]
    s.ax = m.r32((s.di+0x00000030u));
  }
  L004ea943: { // 0x4ea943: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L004ea945: { // 0x4ea945: 7504 JNZ 0x4ea94b
    if(integer::condition("JNZ",flags)) goto L004ea94b;
  }
  L004ea947: { // 0x4ea947: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L004ea949: { // 0x4ea949: eb19 JMP 0x4ea964
    goto L004ea964;
  }
  L004ea94b: { // 0x4ea94b: 83f9ff CMP ECX, -1
    (void)integer::sub(s.cx,4294967295u,32,flags);
  }
  L004ea94e: { // 0x4ea94e: 7412 JZ 0x4ea962
    if(integer::condition("JZ",flags)) goto L004ea962;
  }
  L004ea950: { // 0x4ea950: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004ea955: { // 0x4ea955: d3e0 SHL EAX, CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L004ea957: { // 0x4ea957: 858774560000 TEST dword ptr [EDI + 0x5674], EAX
    (void)integer::logical((m.r32((s.di+0x00005674u)))&(s.ax),32,flags);
  }
  L004ea95d: { // 0x4ea95d: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L004ea960: { // 0x4ea960: eb02 JMP 0x4ea964
    goto L004ea964;
  }
  L004ea962: { // 0x4ea962: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004ea964: { // 0x4ea964: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004ea966: { // 0x4ea966: 0f85d1000000 JNZ 0x4eaa3d
    if(integer::condition("JNZ",flags)) goto L004eaa3d;
  }
  L004ea96c: { // 0x4ea96c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ea96e: { // 0x4ea96e: 8bbeb4010000 MOV EDI, dword ptr [ESI + 0x1b4]
    s.di = m.r32((s.si+0x000001b4u));
  }
  L004ea974: { // 0x4ea974: 8d442438 LEA EAX, [ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L004ea978: { // 0x4ea978: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea97a: { // 0x4ea97a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ea97b: { // 0x4ea97b: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),5155198u); flags=s.arithmetic_flags;
  }
  L004ea97e: { // 0x4ea97e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004ea97f: { // 0x4ea97f: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L004ea981: { // 0x4ea981: e8daf8ffff CALL 0x4ea260
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ea260u,5155206u); flags=s.arithmetic_flags;
  }
  L004ea986: { // 0x4ea986: 83f8ff CMP EAX, -1
    (void)integer::sub(s.ax,4294967295u,32,flags);
  }
  L004ea989: { // 0x4ea989: 0f85aa000000 JNZ 0x4eaa39
    if(integer::condition("JNZ",flags)) goto L004eaa39;
  }
  L004ea98f: { // 0x4ea98f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004ea991: { // 0x4ea991: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea993: { // 0x4ea993: ff92b0010000 CALL dword ptr [EDX + 0x1b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001b0u)),5155225u); flags=s.arithmetic_flags;
  }
  L004ea999: { // 0x4ea999: 83f8ec CMP EAX, -0x14
    (void)integer::sub(s.ax,0xffffffecu,32,flags);
  }
  L004ea99c: { // 0x4ea99c: 0f8c97000000 JL 0x4eaa39
    if(integer::condition("JL",flags)) goto L004eaa39;
  }
  L004ea9a2: { // 0x4ea9a2: 83beb801000002 CMP dword ptr [ESI + 0x1b8], 2
    (void)integer::sub(m.r32((s.si+0x000001b8u)),2u,32,flags);
  }
  L004ea9a9: { // 0x4ea9a9: 0f848a000000 JZ 0x4eaa39
    if(integer::condition("JZ",flags)) goto L004eaa39;
  }
  L004ea9af: { // 0x4ea9af: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004ea9b1: { // 0x4ea9b1: 8d4c2444 LEA ECX, [ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L004ea9b5: { // 0x4ea9b5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004ea9b6: { // 0x4ea9b6: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004ea9b8: { // 0x4ea9b8: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),5155259u); flags=s.arithmetic_flags;
  }
  L004ea9bb: { // 0x4ea9bb: 8b4c2454 MOV ECX, dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  L004ea9bf: { // 0x4ea9bf: 8b38 MOV EDI, dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L004ea9c1: { // 0x4ea9c1: 83ec08 SUB ESP, 8
    f.sp = integer::sub(f.sp,8u,32,flags);
  }
  L004ea9c4: { // 0x4ea9c4: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L004ea9c6: { // 0x4ea9c6: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L004ea9c8: { // 0x4ea9c8: 8b7804 MOV EDI, dword ptr [EAX + 4]
    s.di = m.r32((s.ax+4u));
  }
  L004ea9cb: { // 0x4ea9cb: 89542434 MOV dword ptr [ESP + 0x34], EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L004ea9cf: { // 0x4ea9cf: 8b5104 MOV EDX, dword ptr [ECX + 4]
    s.dx = m.r32((s.cx+4u));
  }
  L004ea9d2: { // 0x4ea9d2: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L004ea9d5: { // 0x4ea9d5: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L004ea9d7: { // 0x4ea9d7: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L004ea9db: { // 0x4ea9db: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L004ea9de: { // 0x4ea9de: db442438 FILD dword ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load_integer32(m.r32(address));
  }
  L004ea9e2: { // 0x4ea9e2: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L004ea9e4: { // 0x4ea9e4: 894c243c MOV dword ptr [ESP + 0x3c], ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L004ea9e8: { // 0x4ea9e8: db44243c FILD dword ptr [ESP + 0x3c]
    const auto address=(f.sp+0x0000003cu);
    s.fp.load_integer32(m.r32(address));
  }
  L004ea9ec: { // 0x4ea9ec: db442434 FILD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L004ea9f0: { // 0x4ea9f0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L004ea9f2: { // 0x4ea9f2: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L004ea9f4: { // 0x4ea9f4: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L004ea9f6: { // 0x4ea9f6: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L004ea9f8: { // 0x4ea9f8: dec1 FADDP ST1
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004ea9fa: { // 0x4ea9fa: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L004ea9fc: { // 0x4ea9fc: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L004ea9fe: { // 0x4ea9fe: dec1 FADDP ST1
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L004eaa00: { // 0x4eaa00: dd1c24 FSTP qword ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L004eaa03: { // 0x4eaa03: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004eaa05: { // 0x4eaa05: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004eaa07: { // 0x4eaa07: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L004eaa09: { // 0x4eaa09: e872f6fcff CALL 0x4ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5155342u); flags=s.arithmetic_flags;
  }
  L004eaa0e: { // 0x4eaa0e: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L004eaa11: { // 0x4eaa11: e83a002800 CALL 0x76aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,5155350u); flags=s.arithmetic_flags;
  }
  L004eaa16: { // 0x4eaa16: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L004eaa18: { // 0x4eaa18: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L004eaa1a: { // 0x4eaa1a: e8c1031e00 CALL 0x6cade0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cade0u,5155359u); flags=s.arithmetic_flags;
  }
  L004eaa1f: { // 0x4eaa1f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eaa21: { // 0x4eaa21: 7402 JZ 0x4eaa25
    if(integer::condition("JZ",flags)) goto L004eaa25;
  }
  L004eaa23: { // 0x4eaa23: 03ff ADD EDI, EDI
    s.di = integer::add(s.di,s.di,32,flags);
  }
  L004eaa25: { // 0x4eaa25: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L004eaa29: { // 0x4eaa29: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eaa2b: { // 0x4eaa2b: 7404 JZ 0x4eaa31
    if(integer::condition("JZ",flags)) goto L004eaa31;
  }
  L004eaa2d: { // 0x4eaa2d: 3bf8 CMP EDI, EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L004eaa2f: { // 0x4eaa2f: 7d08 JGE 0x4eaa39
    if(integer::condition("JGE",flags)) goto L004eaa39;
  }
  L004eaa31: { // 0x4eaa31: 897c2414 MOV dword ptr [ESP + 0x14], EDI
    m.w32((f.sp+0x00000014u), s.di);
  }
  L004eaa35: { // 0x4eaa35: 89742420 MOV dword ptr [ESP + 0x20], ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L004eaa39: { // 0x4eaa39: 8b7c2418 MOV EDI, dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L004eaa3d: { // 0x4eaa3d: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L004eaa41: { // 0x4eaa41: 83c304 ADD EBX, 4
    s.bx = integer::add(s.bx,4u,32,flags);
  }
  L004eaa44: { // 0x4eaa44: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L004eaa45: { // 0x4eaa45: 8944241c MOV dword ptr [ESP + 0x1c], EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L004eaa49: { // 0x4eaa49: 0f858afeffff JNZ 0x4ea8d9
    if(integer::condition("JNZ",flags)) goto L004ea8d9;
  }
  L004eaa4f: { // 0x4eaa4f: 8b442420 MOV EAX, dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L004eaa53: { // 0x4eaa53: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004eaa54: { // 0x4eaa54: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eaa56: { // 0x4eaa56: 7502 JNZ 0x4eaa5a
    if(integer::condition("JNZ",flags)) goto L004eaa5a;
  }
  L004eaa58: { // 0x4eaa58: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004eaa5a: { // 0x4eaa5a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eaa5b: { // 0x4eaa5b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eaa5c: { // 0x4eaa5c: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004eaa5d: { // 0x4eaa5d: 83c440 ADD ESP, 0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L004eaa60: { // 0x4eaa60: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
