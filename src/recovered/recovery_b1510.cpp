#include "recovered/recovery_b1510_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1510 {
namespace {
void f_0029f450(Memory&,State&,Frame&,const Operations&);
void f_00299990(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_002d9bd0(Memory&,State&,Frame&,const Operations&);
void f_002d96f0(Memory&,State&,Frame&,const Operations&);
void f_001cd5a0(Memory&,State&,Frame&,const Operations&);
void f_002d9dc0(Memory&,State&,Frame&,const Operations&);
void f_002d9bc0(Memory&,State&,Frame&,const Operations&);
void f_0001c300(Memory&,State&,Frame&,const Operations&);
void f_001cae40(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void tail(Memory&,State&,Frame&,std::uint32_t);
void f_0029f450(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069f450: { // 0x69f450: 83ec30 SUB ESP, 0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L0069f453: { // 0x69f453: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0069f457: { // 0x69f457: 8b542438 MOV EDX, dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0069f45b: { // 0x69f45b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0069f45d: { // 0x69f45d: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0069f45f: { // 0x69f45f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069f460: { // 0x69f460: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0069f464: { // 0x69f464: e88709d8ff CALL 0x41fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6943849u); flags=s.arithmetic_flags;
  }
  L0069f469: { // 0x69f469: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069f46b: { // 0x69f46b: 894c2400 MOV dword ptr [ESP], ECX
    m.w32((f.sp), s.cx);
  }
  L0069f46f: { // 0x69f46f: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0069f472: { // 0x69f472: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L0069f476: { // 0x69f476: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L0069f479: { // 0x69f479: 894c2408 MOV dword ptr [ESP + 8], ECX
    m.w32((f.sp+8u), s.cx);
  }
  L0069f47d: { // 0x69f47d: 8b500c MOV EDX, dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0069f480: { // 0x69f480: a1e8a88300 MOV EAX, dword ptr [0x83a8e8]
    s.ax = m.r32((0x0083a8e8u));
  }
  L0069f485: { // 0x69f485: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0069f486: { // 0x69f486: 8954240c MOV dword ptr [ESP + 0xc], EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L0069f48a: { // 0x69f48a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0069f48c: { // 0x69f48c: 89442438 MOV dword ptr [ESP + 0x38], EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L0069f490: { // 0x69f490: 0f8cf0000000 JL 0x69f586
    if(integer::condition("JL",flags)) goto L0069f586;
  }
  L0069f496: { // 0x69f496: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069f497: { // 0x69f497: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069f498: { // 0x69f498: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069f499: { // 0x69f499: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069f49a: { // 0x69f49a: 8b0ddca88300 MOV ECX, dword ptr [0x83a8dc]
    s.cx = m.r32((0x0083a8dcu));
  }
  L0069f4a0: { // 0x69f4a0: 8b3481 MOV ESI, dword ptr [ECX + EAX*4]
    s.si = m.r32((s.cx+(s.ax * 4u)));
  }
  L0069f4a3: { // 0x69f4a3: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f4a5: { // 0x69f4a5: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069f4a7: { // 0x69f4a7: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6943914u); flags=s.arithmetic_flags;
  }
  L0069f4aa: { // 0x69f4aa: 83f824 CMP EAX, 0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L0069f4ad: { // 0x69f4ad: 0f85c0000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4b3: { // 0x69f4b3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0069f4b5: { // 0x69f4b5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f4b7: { // 0x69f4b7: ff5044 CALL dword ptr [EAX + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000044u)),6943930u); flags=s.arithmetic_flags;
  }
  L0069f4ba: { // 0x69f4ba: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069f4bc: { // 0x69f4bc: 0f85b1000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4c2: { // 0x69f4c2: 8b8eb0000000 MOV ECX, dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L0069f4c8: { // 0x69f4c8: 8a8183020000 MOV AL, byte ptr [ECX + 0x283]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000283u)));
  }
  L0069f4ce: { // 0x69f4ce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069f4d0: { // 0x69f4d0: 0f859d000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4d6: { // 0x69f4d6: 8a86b5000000 MOV AL, byte ptr [ESI + 0xb5]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000b5u)));
  }
  L0069f4dc: { // 0x69f4dc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069f4de: { // 0x69f4de: 0f858f000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4e4: { // 0x69f4e4: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069f4e6: { // 0x69f4e6: 8b3d70198200 MOV EDI, dword ptr [0x821970]
    s.di = m.r32((0x00821970u));
  }
  L0069f4ec: { // 0x69f4ec: 8b2d74198200 MOV EBP, dword ptr [0x821974]
    s.bp = m.r32((0x00821974u));
  }
  L0069f4f2: { // 0x69f4f2: 8d442430 LEA EAX, [ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0069f4f6: { // 0x69f4f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069f4f7: { // 0x69f4f7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f4f9: { // 0x69f4f9: ff9224010000 CALL dword ptr [EDX + 0x124]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000124u)),6943999u); flags=s.arithmetic_flags;
  }
  L0069f4ff: { // 0x69f4ff: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0069f502: { // 0x69f502: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069f504: { // 0x69f504: 8b5c2418 MOV EBX, dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0069f508: { // 0x69f508: 03d5 ADD EDX, EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L0069f50a: { // 0x69f50a: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0069f50e: { // 0x69f50e: 03cf ADD ECX, EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L0069f510: { // 0x69f510: 8b7808 MOV EDI, dword ptr [EAX + 8]
    s.di = m.r32((s.ax+8u));
  }
  L0069f513: { // 0x69f513: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0069f516: { // 0x69f516: 03dd ADD EBX, EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069f518: { // 0x69f518: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069f51a: { // 0x69f51a: 7d57 JGE 0x69f573
    if(integer::condition("JGE",flags)) goto L0069f573;
  }
  L0069f51c: { // 0x69f51c: 8b5c2414 MOV EBX, dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069f520: { // 0x69f520: 8b6c241c MOV EBP, dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L0069f524: { // 0x69f524: 03eb ADD EBP, EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0069f526: { // 0x69f526: 3bd5 CMP EDX, EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L0069f528: { // 0x69f528: 7d49 JGE 0x69f573
    if(integer::condition("JGE",flags)) goto L0069f573;
  }
  L0069f52a: { // 0x69f52a: 03f9 ADD EDI, ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0069f52c: { // 0x69f52c: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0069f530: { // 0x69f530: 3bf9 CMP EDI, ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0069f532: { // 0x69f532: 7e3f JLE 0x69f573
    if(integer::condition("JLE",flags)) goto L0069f573;
  }
  L0069f534: { // 0x69f534: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069f536: { // 0x69f536: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0069f538: { // 0x69f538: 7e39 JLE 0x69f573
    if(integer::condition("JLE",flags)) goto L0069f573;
  }
  L0069f53a: { // 0x69f53a: 8b4c244c MOV ECX, dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0069f53e: { // 0x69f53e: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0069f540: { // 0x69f540: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0069f542: { // 0x69f542: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0069f546: { // 0x69f546: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0069f549: { // 0x69f549: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0069f54d: { // 0x69f54d: 8b5108 MOV EDX, dword ptr [ECX + 8]
    s.dx = m.r32((s.cx+8u));
  }
  L0069f550: { // 0x69f550: 8954242c MOV dword ptr [ESP + 0x2c], EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0069f554: { // 0x69f554: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069f556: { // 0x69f556: 8b410c MOV EAX, dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0069f559: { // 0x69f559: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0069f55d: { // 0x69f55d: 89442430 MOV dword ptr [ESP + 0x30], EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0069f561: { // 0x69f561: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0069f565: { // 0x69f565: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069f566: { // 0x69f566: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069f567: { // 0x69f567: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f569: { // 0x69f569: ff92fc000000 CALL dword ptr [EDX + 0xfc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000fcu)),6944111u); flags=s.arithmetic_flags;
  }
  L0069f56f: { // 0x69f56f: c6467500 MOV byte ptr [ESI + 0x75], 0
    m.w8((s.si+0x00000075u), 0u);
  }
  L0069f573: { // 0x69f573: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0069f577: { // 0x69f577: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0069f578: { // 0x69f578: 89442448 MOV dword ptr [ESP + 0x48], EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0069f57c: { // 0x69f57c: 0f8918ffffff JNS 0x69f49a
    if(integer::condition("JNS",flags)) goto L0069f49a;
  }
  L0069f582: { // 0x69f582: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069f583: { // 0x69f583: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069f584: { // 0x69f584: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069f585: { // 0x69f585: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069f586: { // 0x69f586: 83c430 ADD ESP, 0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0069f589: { // 0x69f589: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_00299990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00699990: { // 0x699990: 83ec4c SUB ESP, 0x4c
    f.sp = integer::sub(f.sp,0x0000004cu,32,flags);
  }
  L00699993: { // 0x699993: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00699994: { // 0x699994: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00699995: { // 0x699995: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00699996: { // 0x699996: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00699998: { // 0x699998: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00699999: { // 0x699999: 8b86e0000000 MOV EAX, dword ptr [ESI + 0xe0]
    s.ax = m.r32((s.si+0x000000e0u));
  }
  L0069999f: { // 0x69999f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006999a1: { // 0x6999a1: 0f8e01010000 JLE 0x699aa8
    if(integer::condition("JLE",flags)) goto L00699aa8;
  }
  L006999a7: { // 0x6999a7: c744241000000000 MOV dword ptr [ESP + 0x10], 0
    m.w32((f.sp+0x00000010u), 0u);
  }
  L006999af: { // 0x6999af: 8dbee4000000 LEA EDI, [ESI + 0xe4]
    s.di = (s.si+0x000000e4u);
  }
  L006999b5: { // 0x6999b5: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006999b7: { // 0x6999b7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006999b9: { // 0x6999b9: 8b4024 MOV EAX, dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L006999bc: { // 0x6999bc: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006999c0: { // 0x6999c0: 0fbfc8 MOVSX ECX, AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006999c3: { // 0x6999c3: 0fbf44241a MOVSX EAX, word ptr [ESP + 0x1a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001au)),16));
  }
  L006999c8: { // 0x6999c8: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L006999cb: { // 0x6999cb: 0580000000 ADD EAX, 0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L006999d0: { // 0x6999d0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006999d1: { // 0x6999d1: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006999d7: { // 0x6999d7: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006999d9: { // 0x6999d9: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006999dc: { // 0x6999dc: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L006999df: { // 0x6999df: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L006999e2: { // 0x6999e2: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006999e8: { // 0x6999e8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006999e9: { // 0x6999e9: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L006999eb: { // 0x6999eb: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L006999ef: { // 0x6999ef: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006999f0: { // 0x6999f0: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006999f6: { // 0x6999f6: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006999f8: { // 0x6999f8: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006999fb: { // 0x6999fb: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L006999fe: { // 0x6999fe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006999ff: { // 0x6999ff: e82c1cd8ff CALL 0x41b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,6920708u); flags=s.arithmetic_flags;
  }
  L00699a04: { // 0x699a04: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00699a08: { // 0x699a08: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00699a0c: { // 0x699a0c: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00699a10: { // 0x699a10: 894c242c MOV dword ptr [ESP + 0x2c], ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00699a14: { // 0x699a14: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L00699a18: { // 0x699a18: 8d4c242c LEA ECX, [ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00699a1c: { // 0x699a1c: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00699a20: { // 0x699a20: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00699a21: { // 0x699a21: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00699a22: { // 0x699a22: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699a24: { // 0x699a24: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00699a28: { // 0x699a28: e8b3e3ffff CALL 0x697de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697de0u,6920749u); flags=s.arithmetic_flags;
  }
  L00699a2d: { // 0x699a2d: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00699a2f: { // 0x699a2f: 8b9eb4000000 MOV EBX, dword ptr [ESI + 0xb4]
    s.bx = m.r32((s.si+0x000000b4u));
  }
  L00699a35: { // 0x699a35: 8b96b0000000 MOV EDX, dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00699a3b: { // 0x699a3b: 8b2d74198200 MOV EBP, dword ptr [0x821974]
    s.bp = m.r32((0x00821974u));
  }
  L00699a41: { // 0x699a41: 8b4004 MOV EAX, dword ptr [EAX + 4]
    s.ax = m.r32((s.ax+4u));
  }
  L00699a44: { // 0x699a44: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00699a46: { // 0x699a46: 2bc3 SUB EAX, EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00699a48: { // 0x699a48: 83c1e2 ADD ECX, -0x1e
    s.cx = integer::add(s.cx,0xffffffe2u,32,flags);
  }
  L00699a4b: { // 0x699a4b: 89442440 MOV dword ptr [ESP + 0x40], EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00699a4f: { // 0x699a4f: 03c5 ADD EAX, EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00699a51: { // 0x699a51: 89442440 MOV dword ptr [ESP + 0x40], EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00699a55: { // 0x699a55: 89442450 MOV dword ptr [ESP + 0x50], EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L00699a59: { // 0x699a59: 894c243c MOV dword ptr [ESP + 0x3c], ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L00699a5d: { // 0x699a5d: 894c244c MOV dword ptr [ESP + 0x4c], ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L00699a61: { // 0x699a61: 8d44244c LEA EAX, [ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L00699a65: { // 0x699a65: 8d4c243c LEA ECX, [ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00699a69: { // 0x699a69: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699a6a: { // 0x699a6a: ba3c000000 MOV EDX, 0x3c
    s.dx = 0x0000003cu;
  }
  L00699a6f: { // 0x699a6f: bb1e000000 MOV EBX, 0x1e
    s.bx = 0x0000001eu;
  }
  L00699a74: { // 0x699a74: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00699a75: { // 0x699a75: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699a77: { // 0x699a77: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699a79: { // 0x699a79: 89542450 MOV dword ptr [ESP + 0x50], EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L00699a7d: { // 0x699a7d: 895c2454 MOV dword ptr [ESP + 0x54], EBX
    m.w32((f.sp+0x00000054u), s.bx);
  }
  L00699a81: { // 0x699a81: 89542460 MOV dword ptr [ESP + 0x60], EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00699a85: { // 0x699a85: 895c2464 MOV dword ptr [ESP + 0x64], EBX
    m.w32((f.sp+0x00000064u), s.bx);
  }
  L00699a89: { // 0x699a89: e8c2590000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6920846u); flags=s.arithmetic_flags;
  }
  L00699a8e: { // 0x699a8e: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00699a92: { // 0x699a92: 8b8ee0000000 MOV ECX, dword ptr [ESI + 0xe0]
    s.cx = m.r32((s.si+0x000000e0u));
  }
  L00699a98: { // 0x699a98: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00699a99: { // 0x699a99: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L00699a9c: { // 0x699a9c: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00699a9e: { // 0x699a9e: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00699aa2: { // 0x699aa2: 0f8c0dffffff JL 0x6999b5
    if(integer::condition("JL",flags)) goto L006999b5;
  }
  L00699aa8: { // 0x699aa8: a1c860aa00 MOV EAX, dword ptr [0xaa60c8]
    s.ax = m.r32((0x00aa60c8u));
  }
  L00699aad: { // 0x699aad: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00699aaf: { // 0x699aaf: 0f84b8000000 JZ 0x699b6d
    if(integer::condition("JZ",flags)) goto L00699b6d;
  }
  L00699ab5: { // 0x699ab5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00699ab6: { // 0x699ab6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00699ab8: { // 0x699ab8: 0f8caf000000 JL 0x699b6d
    if(integer::condition("JL",flags)) goto L00699b6d;
  }
  L00699abe: { // 0x699abe: 8d3c80 LEA EDI, [EAX + EAX*4]
    s.di = (s.ax+(s.ax * 4u));
  }
  L00699ac1: { // 0x699ac1: 8d5801 LEA EBX, [EAX + 1]
    s.bx = (s.ax+1u);
  }
  L00699ac4: { // 0x699ac4: c1e702 SHL EDI, 2
    s.di = integer::shift(s.di,2u,32,flags,integer::Shift::left);
  }
  L00699ac7: { // 0x699ac7: 8b15bc60aa00 MOV EDX, dword ptr [0xaa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00699acd: { // 0x699acd: 8b2d74198200 MOV EBP, dword ptr [0x821974]
    s.bp = m.r32((0x00821974u));
  }
  L00699ad3: { // 0x699ad3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00699ad5: { // 0x699ad5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00699ad7: { // 0x699ad7: 8d0417 LEA EAX, [EDI + EDX]
    s.ax = (s.di+s.dx);
  }
  L00699ada: { // 0x699ada: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00699adc: { // 0x699adc: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00699ade: { // 0x699ade: 89542434 MOV dword ptr [ESP + 0x34], EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L00699ae2: { // 0x699ae2: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00699ae5: { // 0x699ae5: 89442438 MOV dword ptr [ESP + 0x38], EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00699ae9: { // 0x699ae9: 03c5 ADD EAX, EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00699aeb: { // 0x699aeb: 8b5108 MOV EDX, dword ptr [ECX + 8]
    s.dx = m.r32((s.cx+8u));
  }
  L00699aee: { // 0x699aee: 8954243c MOV dword ptr [ESP + 0x3c], EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L00699af2: { // 0x699af2: 8d542434 LEA EDX, [ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L00699af6: { // 0x699af6: 8b490c MOV ECX, dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00699af9: { // 0x699af9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00699afa: { // 0x699afa: 894c2444 MOV dword ptr [ESP + 0x44], ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00699afe: { // 0x699afe: ba70198200 MOV EDX, 0x821970
    s.dx = 0x00821970u;
  }
  L00699b03: { // 0x699b03: 8d4c2448 LEA ECX, [ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L00699b07: { // 0x699b07: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00699b0b: { // 0x699b0b: e8e062d8ff CALL 0x41fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6920976u); flags=s.arithmetic_flags;
  }
  L00699b10: { // 0x699b10: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00699b12: { // 0x699b12: 8b0a MOV ECX, dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00699b14: { // 0x699b14: 894c242c MOV dword ptr [ESP + 0x2c], ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00699b18: { // 0x699b18: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L00699b1b: { // 0x699b1b: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00699b1f: { // 0x699b1f: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L00699b22: { // 0x699b22: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L00699b26: { // 0x699b26: 8b520c MOV EDX, dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L00699b29: { // 0x699b29: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699b2b: { // 0x699b2b: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00699b2f: { // 0x699b2f: 7e32 JLE 0x699b63
    if(integer::condition("JLE",flags)) goto L00699b63;
  }
  L00699b31: { // 0x699b31: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00699b33: { // 0x699b33: 7e2e JLE 0x699b63
    if(integer::condition("JLE",flags)) goto L00699b63;
  }
  L00699b35: { // 0x699b35: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00699b37: { // 0x699b37: 8b4804 MOV ECX, dword ptr [EAX + 4]
    s.cx = m.r32((s.ax+4u));
  }
  L00699b3a: { // 0x699b3a: 8954244c MOV dword ptr [ESP + 0x4c], EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00699b3e: { // 0x699b3e: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L00699b41: { // 0x699b41: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00699b44: { // 0x699b44: 894c2450 MOV dword ptr [ESP + 0x50], ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L00699b48: { // 0x699b48: 89542454 MOV dword ptr [ESP + 0x54], EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L00699b4c: { // 0x699b4c: 8d4c244c LEA ECX, [ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L00699b50: { // 0x699b50: 8d54242c LEA EDX, [ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L00699b54: { // 0x699b54: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00699b55: { // 0x699b55: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00699b56: { // 0x699b56: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699b58: { // 0x699b58: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699b5a: { // 0x699b5a: 89442464 MOV dword ptr [ESP + 0x64], EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00699b5e: { // 0x699b5e: e8ed580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921059u); flags=s.arithmetic_flags;
  }
  L00699b63: { // 0x699b63: 83ef14 SUB EDI, 0x14
    s.di = integer::sub(s.di,0x00000014u,32,flags);
  }
  L00699b66: { // 0x699b66: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00699b67: { // 0x699b67: 0f855affffff JNZ 0x699ac7
    if(integer::condition("JNZ",flags)) goto L00699ac7;
  }
  L00699b6d: { // 0x699b6d: 8a442468 MOV AL, byte ptr [ESP + 0x68]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000068u)));
  }
  L00699b71: { // 0x699b71: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00699b73: { // 0x699b73: 741d JZ 0x699b92
    if(integer::condition("JZ",flags)) goto L00699b92;
  }
  L00699b75: { // 0x699b75: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L00699b7a: { // 0x699b7a: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L00699b7f: { // 0x699b7f: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699b81: { // 0x699b81: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699b83: { // 0x699b83: e8c8580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921096u); flags=s.arithmetic_flags;
  }
  L00699b88: { // 0x699b88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00699b89: { // 0x699b89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00699b8a: { // 0x699b8a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00699b8b: { // 0x699b8b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00699b8c: { // 0x699b8c: 83c44c ADD ESP, 0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L00699b8f: { // 0x699b8f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L00699b92: { // 0x699b92: 8b442460 MOV EAX, dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L00699b96: { // 0x699b96: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L00699b99: { // 0x699b99: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699b9b: { // 0x699b9b: 7e12 JLE 0x699baf
    if(integer::condition("JLE",flags)) goto L00699baf;
  }
  L00699b9d: { // 0x699b9d: 8b480c MOV ECX, dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00699ba0: { // 0x699ba0: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699ba2: { // 0x699ba2: 7e0b JLE 0x699baf
    if(integer::condition("JLE",flags)) goto L00699baf;
  }
  L00699ba4: { // 0x699ba4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699ba5: { // 0x699ba5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699ba6: { // 0x699ba6: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699ba8: { // 0x699ba8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699baa: { // 0x699baa: e8a1580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921135u); flags=s.arithmetic_flags;
  }
  L00699baf: { // 0x699baf: 8b442464 MOV EAX, dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L00699bb3: { // 0x699bb3: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L00699bb6: { // 0x699bb6: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699bb8: { // 0x699bb8: 7e12 JLE 0x699bcc
    if(integer::condition("JLE",flags)) goto L00699bcc;
  }
  L00699bba: { // 0x699bba: 8b480c MOV ECX, dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00699bbd: { // 0x699bbd: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699bbf: { // 0x699bbf: 7e0b JLE 0x699bcc
    if(integer::condition("JLE",flags)) goto L00699bcc;
  }
  L00699bc1: { // 0x699bc1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699bc2: { // 0x699bc2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699bc3: { // 0x699bc3: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699bc5: { // 0x699bc5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699bc7: { // 0x699bc7: e884580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921164u); flags=s.arithmetic_flags;
  }
  L00699bcc: { // 0x699bcc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00699bcd: { // 0x699bcd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00699bce: { // 0x699bce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00699bcf: { // 0x699bcf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00699bd0: { // 0x699bd0: 83c44c ADD ESP, 0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L00699bd3: { // 0x699bd3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_0001fdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041fdf0: { // 0x41fdf0: 83ec18 SUB ESP, 0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0041fdf3: { // 0x41fdf3: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L0041fdf5: { // 0x41fdf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041fdf6: { // 0x41fdf6: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fdfa: { // 0x41fdfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041fdfb: { // 0x41fdfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041fdfc: { // 0x41fdfc: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0041fdfe: { // 0x41fdfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041fdff: { // 0x41fdff: 8b1e MOV EBX, dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L0041fe01: { // 0x41fe01: 8b7e04 MOV EDI, dword ptr [ESI + 4]
    s.di = m.r32((s.si+4u));
  }
  L0041fe04: { // 0x41fe04: 8b6e08 MOV EBP, dword ptr [ESI + 8]
    s.bp = m.r32((s.si+8u));
  }
  L0041fe07: { // 0x41fe07: 896c2420 MOV dword ptr [ESP + 0x20], EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe0b: { // 0x41fe0b: 8b760c MOV ESI, dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  L0041fe0e: { // 0x41fe0e: 89742424 MOV dword ptr [ESP + 0x24], ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0041fe12: { // 0x41fe12: 8b7208 MOV ESI, dword ptr [EDX + 8]
    s.si = m.r32((s.dx+8u));
  }
  L0041fe15: { // 0x41fe15: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041fe17: { // 0x41fe17: 0f8edb000000 JLE 0x41fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe1d: { // 0x41fe1d: 8b6a0c MOV EBP, dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0041fe20: { // 0x41fe20: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe22: { // 0x41fe22: 896c2414 MOV dword ptr [ESP + 0x14], EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0041fe26: { // 0x41fe26: 0f8ecc000000 JLE 0x41fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe2c: { // 0x41fe2c: 8b6908 MOV EBP, dword ptr [ECX + 8]
    s.bp = m.r32((s.cx+8u));
  }
  L0041fe2f: { // 0x41fe2f: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe31: { // 0x41fe31: 0f8ec1000000 JLE 0x41fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe37: { // 0x41fe37: 8b690c MOV EBP, dword ptr [ECX + 0xc]
    s.bp = m.r32((s.cx+0x0000000cu));
  }
  L0041fe3a: { // 0x41fe3a: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe3c: { // 0x41fe3c: 0f8eb6000000 JLE 0x41fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe42: { // 0x41fe42: 8b0a MOV ECX, dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0041fe44: { // 0x41fe44: 3bd9 CMP EBX, ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe46: { // 0x41fe46: 7d0e JGE 0x41fe56
    if(integer::condition("JGE",flags)) goto L0041fe56;
  }
  L0041fe48: { // 0x41fe48: 8b6c2420 MOV EBP, dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe4c: { // 0x41fe4c: 2bd9 SUB EBX, ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe4e: { // 0x41fe4e: 03eb ADD EBP, EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe50: { // 0x41fe50: 8bd9 MOV EBX, ECX
    s.bx = s.cx;
  }
  L0041fe52: { // 0x41fe52: 896c2420 MOV dword ptr [ESP + 0x20], EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe56: { // 0x41fe56: 837c242001 CMP dword ptr [ESP + 0x20], 1
    (void)integer::sub(m.r32((f.sp+0x00000020u)),1u,32,flags);
  }
  L0041fe5b: { // 0x41fe5b: 0f8c97000000 JL 0x41fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe61: { // 0x41fe61: 8b5204 MOV EDX, dword ptr [EDX + 4]
    s.dx = m.r32((s.dx+4u));
  }
  L0041fe64: { // 0x41fe64: 3bfa CMP EDI, EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe66: { // 0x41fe66: 89542410 MOV dword ptr [ESP + 0x10], EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0041fe6a: { // 0x41fe6a: 7d0e JGE 0x41fe7a
    if(integer::condition("JGE",flags)) goto L0041fe7a;
  }
  L0041fe6c: { // 0x41fe6c: 8b6c2424 MOV EBP, dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0041fe70: { // 0x41fe70: 2bfa SUB EDI, EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe72: { // 0x41fe72: 03ef ADD EBP, EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041fe74: { // 0x41fe74: 8bfa MOV EDI, EDX
    s.di = s.dx;
  }
  L0041fe76: { // 0x41fe76: 896c2424 MOV dword ptr [ESP + 0x24], EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0041fe7a: { // 0x41fe7a: 837c242401 CMP dword ptr [ESP + 0x24], 1
    (void)integer::sub(m.r32((f.sp+0x00000024u)),1u,32,flags);
  }
  L0041fe7f: { // 0x41fe7f: 7c77 JL 0x41fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe81: { // 0x41fe81: 8b6c2420 MOV EBP, dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe85: { // 0x41fe85: 8d1431 LEA EDX, [ECX + ESI]
    s.dx = (s.cx+s.si);
  }
  L0041fe88: { // 0x41fe88: 03eb ADD EBP, EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe8a: { // 0x41fe8a: 3bea CMP EBP, EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041fe8c: { // 0x41fe8c: 7e06 JLE 0x41fe94
    if(integer::condition("JLE",flags)) goto L0041fe94;
  }
  L0041fe8e: { // 0x41fe8e: 2bcb SUB ECX, EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0041fe90: { // 0x41fe90: 03ce ADD ECX, ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041fe92: { // 0x41fe92: eb04 JMP 0x41fe98
    goto L0041fe98;
  }
  L0041fe94: { // 0x41fe94: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fe98: { // 0x41fe98: 83f901 CMP ECX, 1
    (void)integer::sub(s.cx,1u,32,flags);
  }
  L0041fe9b: { // 0x41fe9b: 7c5b JL 0x41fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe9d: { // 0x41fe9d: 8b542410 MOV EDX, dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041fea1: { // 0x41fea1: 8b742414 MOV ESI, dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0041fea5: { // 0x41fea5: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041fea7: { // 0x41fea7: 8b742424 MOV ESI, dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041feab: { // 0x41feab: 8d2c3e LEA EBP, [ESI + EDI]
    s.bp = (s.si+s.di);
  }
  L0041feae: { // 0x41feae: 3bea CMP EBP, EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041feb0: { // 0x41feb0: 7e04 JLE 0x41feb6
    if(integer::condition("JLE",flags)) goto L0041feb6;
  }
  L0041feb2: { // 0x41feb2: 2bd7 SUB EDX, EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0041feb4: { // 0x41feb4: 8bf2 MOV ESI, EDX
    s.si = s.dx;
  }
  L0041feb6: { // 0x41feb6: 83fe01 CMP ESI, 1
    (void)integer::sub(s.si,1u,32,flags);
  }
  L0041feb9: { // 0x41feb9: 7c3d JL 0x41fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041febb: { // 0x41febb: 8b542430 MOV EDX, dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0041febf: { // 0x41febf: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fec1: { // 0x41fec1: 740b JZ 0x41fece
    if(integer::condition("JZ",flags)) goto L0041fece;
  }
  L0041fec3: { // 0x41fec3: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041fec7: { // 0x41fec7: 8b6d00 MOV EBP, dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L0041feca: { // 0x41feca: 2beb SUB EBP, EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0041fecc: { // 0x41fecc: 012a ADD dword ptr [EDX], EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fece: { // 0x41fece: 8b542434 MOV EDX, dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0041fed2: { // 0x41fed2: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fed4: { // 0x41fed4: 740b JZ 0x41fee1
    if(integer::condition("JZ",flags)) goto L0041fee1;
  }
  L0041fed6: { // 0x41fed6: 8b6c242c MOV EBP, dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041feda: { // 0x41feda: 8b6d04 MOV EBP, dword ptr [EBP + 4]
    s.bp = m.r32((s.bp+4u));
  }
  L0041fedd: { // 0x41fedd: 2bef SUB EBP, EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0041fedf: { // 0x41fedf: 012a ADD dword ptr [EDX], EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fee1: { // 0x41fee1: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0041fee3: { // 0x41fee3: 891a MOV dword ptr [EDX], EBX
    m.w32((s.dx), s.bx);
  }
  L0041fee5: { // 0x41fee5: 897a04 MOV dword ptr [EDX + 4], EDI
    m.w32((s.dx+4u), s.di);
  }
  L0041fee8: { // 0x41fee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fee9: { // 0x41fee9: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L0041feec: { // 0x41feec: 89720c MOV dword ptr [EDX + 0xc], ESI
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
  L0041fef2: { // 0x41fef2: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041fef5: { // 0x41fef5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041fef8: { // 0x41fef8: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L0041fefa: { // 0x41fefa: 33c9 XOR ECX, ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041fefc: { // 0x41fefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fefd: { // 0x41fefd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fefe: { // 0x41fefe: 890a MOV dword ptr [EDX], ECX
    m.w32((s.dx), s.cx);
  }
  L0041ff00: { // 0x41ff00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ff01: { // 0x41ff01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ff02: { // 0x41ff02: 894a04 MOV dword ptr [EDX + 4], ECX
    m.w32((s.dx+4u), s.cx);
  }
  L0041ff05: { // 0x41ff05: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L0041ff08: { // 0x41ff08: 894a0c MOV dword ptr [EDX + 0xc], ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L0041ff0b: { // 0x41ff0b: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041ff0e: { // 0x41ff0e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_002d9bd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d9bd0: { // 0x6d9bd0: 83ec40 SUB ESP, 0x40
    f.sp = integer::sub(f.sp,0x00000040u,32,flags);
  }
  L006d9bd3: { // 0x6d9bd3: a1ac1c8200 MOV EAX, dword ptr [0x821cac]
    s.ax = m.r32((0x00821cacu));
  }
  L006d9bd8: { // 0x6d9bd8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d9bd9: { // 0x6d9bd9: 8b90b0000000 MOV EDX, dword ptr [EAX + 0xb0]
    s.dx = m.r32((s.ax+0x000000b0u));
  }
  L006d9bdf: { // 0x6d9bdf: 8bb0b4000000 MOV ESI, dword ptr [EAX + 0xb4]
    s.si = m.r32((s.ax+0x000000b4u));
  }
  L006d9be5: { // 0x6d9be5: 8b81c0000000 MOV EAX, dword ptr [ECX + 0xc0]
    s.ax = m.r32((s.cx+0x000000c0u));
  }
  L006d9beb: { // 0x6d9beb: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006d9bed: { // 0x6d9bed: 8944240c MOV dword ptr [ESP + 0xc], EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L006d9bf1: { // 0x6d9bf1: 8b81c4000000 MOV EAX, dword ptr [ECX + 0xc4]
    s.ax = m.r32((s.cx+0x000000c4u));
  }
  L006d9bf7: { // 0x6d9bf7: 2bc6 SUB EAX, ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006d9bf9: { // 0x6d9bf9: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L006d9bfd: { // 0x6d9bfd: e83e12efff CALL 0x5cae40
    s.arithmetic_flags=flags; invoke(m,s,f,0x005cae40u,7183362u); flags=s.arithmetic_flags;
  }
  L006d9c02: { // 0x6d9c02: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L006d9c04: { // 0x6d9c04: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006d9c06: { // 0x6d9c06: 89742404 MOV dword ptr [ESP + 4], ESI
    m.w32((f.sp+4u), s.si);
  }
  L006d9c0a: { // 0x6d9c0a: 7530 JNZ 0x6d9c3c
    if(integer::condition("JNZ",flags)) goto L006d9c3c;
  }
  L006d9c0c: { // 0x6d9c0c: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L006d9c10: { // 0x6d9c10: 8b15607eaa00 MOV EDX, dword ptr [0xaa7e60]
    s.dx = m.r32((0x00aa7e60u));
  }
  L006d9c16: { // 0x6d9c16: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006d9c18: { // 0x6d9c18: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d9c19: { // 0x6d9c19: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L006d9c1b: { // 0x6d9c1b: 8b15647eaa00 MOV EDX, dword ptr [0xaa7e64]
    s.dx = m.r32((0x00aa7e64u));
  }
  L006d9c21: { // 0x6d9c21: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L006d9c24: { // 0x6d9c24: 8b15687eaa00 MOV EDX, dword ptr [0xaa7e68]
    s.dx = m.r32((0x00aa7e68u));
  }
  L006d9c2a: { // 0x6d9c2a: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L006d9c2d: { // 0x6d9c2d: 8b156c7eaa00 MOV EDX, dword ptr [0xaa7e6c]
    s.dx = m.r32((0x00aa7e6cu));
  }
  L006d9c33: { // 0x6d9c33: 89510c MOV dword ptr [ECX + 0xc], EDX
    m.w32((s.cx+0x0000000cu), s.dx);
  }
  L006d9c36: { // 0x6d9c36: 83c440 ADD ESP, 0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L006d9c39: { // 0x6d9c39: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L006d9c3c: { // 0x6d9c3c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006d9c3d: { // 0x6d9c3d: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006d9c3e: { // 0x6d9c3e: 0fbf5e06 MOVSX EBX, word ptr [ESI + 6]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.si+6u)),16));
  }
  L006d9c42: { // 0x6d9c42: 8b2d6c7eaa00 MOV EBP, dword ptr [0xaa7e6c]
    s.bp = m.r32((0x00aa7e6cu));
  }
  L006d9c48: { // 0x6d9c48: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d9c49: { // 0x6d9c49: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006d9c4b: { // 0x6d9c4b: 7620 JBE 0x6d9c6d
    if(integer::condition("JBE",flags)) goto L006d9c6d;
  }
  L006d9c4d: { // 0x6d9c4d: 8d4608 LEA EAX, [ESI + 8]
    s.ax = (s.si+8u);
  }
  L006d9c50: { // 0x6d9c50: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d9c52: { // 0x6d9c52: 7419 JZ 0x6d9c6d
    if(integer::condition("JZ",flags)) goto L006d9c6d;
  }
  L006d9c54: { // 0x6d9c54: 0fbf08 MOVSX ECX, word ptr [EAX]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L006d9c57: { // 0x6d9c57: 0fbf5002 MOVSX EDX, word ptr [EAX + 2]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+2u)),16));
  }
  L006d9c5b: { // 0x6d9c5b: 0fbf7804 MOVSX EDI, word ptr [EAX + 4]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+4u)),16));
  }
  L006d9c5f: { // 0x6d9c5f: 0fbf4006 MOVSX EAX, word ptr [EAX + 6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+6u)),16));
  }
  L006d9c63: { // 0x6d9c63: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L006d9c67: { // 0x6d9c67: 8944242c MOV dword ptr [ESP + 0x2c], EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L006d9c6b: { // 0x6d9c6b: eb19 JMP 0x6d9c86
    goto L006d9c86;
  }
  L006d9c6d: { // 0x6d9c6d: a1647eaa00 MOV EAX, dword ptr [0xaa7e64]
    s.ax = m.r32((0x00aa7e64u));
  }
  L006d9c72: { // 0x6d9c72: 8b0d607eaa00 MOV ECX, dword ptr [0xaa7e60]
    s.cx = m.r32((0x00aa7e60u));
  }
  L006d9c78: { // 0x6d9c78: 8b3d687eaa00 MOV EDI, dword ptr [0xaa7e68]
    s.di = m.r32((0x00aa7e68u));
  }
  L006d9c7e: { // 0x6d9c7e: 89442424 MOV dword ptr [ESP + 0x24], EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L006d9c82: { // 0x6d9c82: 896c242c MOV dword ptr [ESP + 0x2c], EBP
    m.w32((f.sp+0x0000002cu), s.bp);
  }
  L006d9c86: { // 0x6d9c86: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L006d9c88: { // 0x6d9c88: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006d9c89: { // 0x6d9c89: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006d9c8b: { // 0x6d9c8b: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006d9c8d: { // 0x6d9c8d: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006d9c8f: { // 0x6d9c8f: 732e JNC 0x6d9cbf
    if(integer::condition("JNC",flags)) goto L006d9cbf;
  }
  L006d9c91: { // 0x6d9c91: 8d1440 LEA EDX, [EAX + EAX*2]
    s.dx = (s.ax+(s.ax * 2u));
  }
  L006d9c94: { // 0x6d9c94: 8d44d608 LEA EAX, [ESI + EDX*8 + 8]
    s.ax = (s.si+(s.dx * 8u)+8u);
  }
  L006d9c98: { // 0x6d9c98: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d9c9a: { // 0x6d9c9a: 7423 JZ 0x6d9cbf
    if(integer::condition("JZ",flags)) goto L006d9cbf;
  }
  L006d9c9c: { // 0x6d9c9c: 0fbf5802 MOVSX EBX, word ptr [EAX + 2]
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.ax+2u)),16));
  }
  L006d9ca0: { // 0x6d9ca0: 0fbf6804 MOVSX EBP, word ptr [EAX + 4]
    s.bp = std::uint32_t(integer::sign_extend(m.r16((s.ax+4u)),16));
  }
  L006d9ca4: { // 0x6d9ca4: 0fbf7006 MOVSX ESI, word ptr [EAX + 6]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax+6u)),16));
  }
  L006d9ca8: { // 0x6d9ca8: 0fbf10 MOVSX EDX, word ptr [EAX]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L006d9cab: { // 0x6d9cab: 8bc3 MOV EAX, EBX
    s.ax = s.bx;
  }
  L006d9cad: { // 0x6d9cad: 8bdd MOV EBX, EBP
    s.bx = s.bp;
  }
  L006d9caf: { // 0x6d9caf: 8bee MOV EBP, ESI
    s.bp = s.si;
  }
  L006d9cb1: { // 0x6d9cb1: 8b742410 MOV ESI, dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L006d9cb5: { // 0x6d9cb5: 895c2438 MOV dword ptr [ESP + 0x38], EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L006d9cb9: { // 0x6d9cb9: 896c243c MOV dword ptr [ESP + 0x3c], EBP
    m.w32((f.sp+0x0000003cu), s.bp);
  }
  L006d9cbd: { // 0x6d9cbd: eb19 JMP 0x6d9cd8
    goto L006d9cd8;
  }
  L006d9cbf: { // 0x6d9cbf: 8b1d687eaa00 MOV EBX, dword ptr [0xaa7e68]
    s.bx = m.r32((0x00aa7e68u));
  }
  L006d9cc5: { // 0x6d9cc5: 8b15607eaa00 MOV EDX, dword ptr [0xaa7e60]
    s.dx = m.r32((0x00aa7e60u));
  }
  L006d9ccb: { // 0x6d9ccb: a1647eaa00 MOV EAX, dword ptr [0xaa7e64]
    s.ax = m.r32((0x00aa7e64u));
  }
  L006d9cd0: { // 0x6d9cd0: 895c2438 MOV dword ptr [ESP + 0x38], EBX
    m.w32((f.sp+0x00000038u), s.bx);
  }
  L006d9cd4: { // 0x6d9cd4: 896c243c MOV dword ptr [ESP + 0x3c], EBP
    m.w32((f.sp+0x0000003cu), s.bp);
  }
  L006d9cd8: { // 0x6d9cd8: 0fbf7602 MOVSX ESI, word ptr [ESI + 2]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.si+2u)),16));
  }
  L006d9cdc: { // 0x6d9cdc: 89742414 MOV dword ptr [ESP + 0x14], ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L006d9ce0: { // 0x6d9ce0: 8b742410 MOV ESI, dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L006d9ce4: { // 0x6d9ce4: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006d9ce6: { // 0x6d9ce6: 0fbf7604 MOVSX ESI, word ptr [ESI + 4]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.si+4u)),16));
  }
  L006d9cea: { // 0x6d9cea: 89742410 MOV dword ptr [ESP + 0x10], ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L006d9cee: { // 0x6d9cee: 7e76 JLE 0x6d9d66
    if(integer::condition("JLE",flags)) goto L006d9d66;
  }
  L006d9cf0: { // 0x6d9cf0: 8b74242c MOV ESI, dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L006d9cf4: { // 0x6d9cf4: 85f6 TEST ESI, ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006d9cf6: { // 0x6d9cf6: 7e6e JLE 0x6d9d66
    if(integer::condition("JLE",flags)) goto L006d9d66;
  }
  L006d9cf8: { // 0x6d9cf8: 85db TEST EBX, EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L006d9cfa: { // 0x6d9cfa: 7e60 JLE 0x6d9d5c
    if(integer::condition("JLE",flags)) goto L006d9d5c;
  }
  L006d9cfc: { // 0x6d9cfc: 85ed TEST EBP, EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L006d9cfe: { // 0x6d9cfe: 7e5c JLE 0x6d9d5c
    if(integer::condition("JLE",flags)) goto L006d9d5c;
  }
  L006d9d00: { // 0x6d9d00: 8b742424 MOV ESI, dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L006d9d04: { // 0x6d9d04: 8b5c242c MOV EBX, dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L006d9d08: { // 0x6d9d08: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L006d9d0a: { // 0x6d9d0a: 894c2440 MOV dword ptr [ESP + 0x40], ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L006d9d0e: { // 0x6d9d0e: 7e0a JLE 0x6d9d1a
    if(integer::condition("JLE",flags)) goto L006d9d1a;
  }
  L006d9d10: { // 0x6d9d10: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006d9d12: { // 0x6d9d12: 89542440 MOV dword ptr [ESP + 0x40], EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L006d9d16: { // 0x6d9d16: 03cf ADD ECX, EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L006d9d18: { // 0x6d9d18: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L006d9d1a: { // 0x6d9d1a: 3bf0 CMP ESI, EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L006d9d1c: { // 0x6d9d1c: 7e06 JLE 0x6d9d24
    if(integer::condition("JLE",flags)) goto L006d9d24;
  }
  L006d9d1e: { // 0x6d9d1e: 2bf0 SUB ESI, EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006d9d20: { // 0x6d9d20: 03de ADD EBX, ESI
    s.bx = integer::add(s.bx,s.si,32,flags);
  }
  L006d9d22: { // 0x6d9d22: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L006d9d24: { // 0x6d9d24: 8b4c2438 MOV ECX, dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L006d9d28: { // 0x6d9d28: 8b6c2440 MOV EBP, dword ptr [ESP + 0x40]
    s.bp = m.r32((f.sp+0x00000040u));
  }
  L006d9d2c: { // 0x6d9d2c: 03ca ADD ECX, EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L006d9d2e: { // 0x6d9d2e: 03ef ADD EBP, EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L006d9d30: { // 0x6d9d30: 3be9 CMP EBP, ECX
    (void)integer::sub(s.bp,s.cx,32,flags);
  }
  L006d9d32: { // 0x6d9d32: 7d0e JGE 0x6d9d42
    if(integer::condition("JGE",flags)) goto L006d9d42;
  }
  L006d9d34: { // 0x6d9d34: 8b4c2440 MOV ECX, dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L006d9d38: { // 0x6d9d38: 2bd1 SUB EDX, ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L006d9d3a: { // 0x6d9d3a: 8b4c2438 MOV ECX, dword ptr [ESP + 0x38]
    s.cx = m.r32((f.sp+0x00000038u));
  }
  L006d9d3e: { // 0x6d9d3e: 8d7c0a01 LEA EDI, [EDX + ECX + 1]
    s.di = (s.dx+s.cx+1u);
  }
  L006d9d42: { // 0x6d9d42: 8b4c243c MOV ECX, dword ptr [ESP + 0x3c]
    s.cx = m.r32((f.sp+0x0000003cu));
  }
  L006d9d46: { // 0x6d9d46: 8d2c33 LEA EBP, [EBX + ESI]
    s.bp = (s.bx+s.si);
  }
  L006d9d49: { // 0x6d9d49: 8d1408 LEA EDX, [EAX + ECX]
    s.dx = (s.ax+s.cx);
  }
  L006d9d4c: { // 0x6d9d4c: 3bea CMP EBP, EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L006d9d4e: { // 0x6d9d4e: 7d06 JGE 0x6d9d56
    if(integer::condition("JGE",flags)) goto L006d9d56;
  }
  L006d9d50: { // 0x6d9d50: 2bc6 SUB EAX, ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L006d9d52: { // 0x6d9d52: 8d5c0801 LEA EBX, [EAX + ECX + 1]
    s.bx = (s.ax+s.cx+1u);
  }
  L006d9d56: { // 0x6d9d56: 8b4c2440 MOV ECX, dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L006d9d5a: { // 0x6d9d5a: eb12 JMP 0x6d9d6e
    goto L006d9d6e;
  }
  L006d9d5c: { // 0x6d9d5c: 8b742424 MOV ESI, dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L006d9d60: { // 0x6d9d60: 8b5c242c MOV EBX, dword ptr [ESP + 0x2c]
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L006d9d64: { // 0x6d9d64: eb08 JMP 0x6d9d6e
    goto L006d9d6e;
  }
  L006d9d66: { // 0x6d9d66: 8bfb MOV EDI, EBX
    s.di = s.bx;
  }
  L006d9d68: { // 0x6d9d68: 8bca MOV ECX, EDX
    s.cx = s.dx;
  }
  L006d9d6a: { // 0x6d9d6a: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L006d9d6c: { // 0x6d9d6c: 8bdd MOV EBX, EBP
    s.bx = s.bp;
  }
  L006d9d6e: { // 0x6d9d6e: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006d9d72: { // 0x6d9d72: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006d9d73: { // 0x6d9d73: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006d9d75: { // 0x6d9d75: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006d9d77: { // 0x6d9d77: 2bc8 SUB ECX, EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L006d9d79: { // 0x6d9d79: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L006d9d7d: { // 0x6d9d7d: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006d9d7f: { // 0x6d9d7f: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L006d9d83: { // 0x6d9d83: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006d9d84: { // 0x6d9d84: 2bc2 SUB EAX, EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006d9d86: { // 0x6d9d86: d1f8 SAR EAX, 1
    s.ax = integer::shift(s.ax,1u,32,flags,integer::Shift::arithmetic_right);
  }
  L006d9d88: { // 0x6d9d88: 2bf0 SUB ESI, EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L006d9d8a: { // 0x6d9d8a: 8b44241c MOV EAX, dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006d9d8e: { // 0x6d9d8e: 03f0 ADD ESI, EAX
    s.si = integer::add(s.si,s.ax,32,flags);
  }
  L006d9d90: { // 0x6d9d90: 8b442454 MOV EAX, dword ptr [ESP + 0x54]
    s.ax = m.r32((f.sp+0x00000054u));
  }
  L006d9d94: { // 0x6d9d94: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L006d9d96: { // 0x6d9d96: 890a MOV dword ptr [EDX], ECX
    m.w32((s.dx), s.cx);
  }
  L006d9d98: { // 0x6d9d98: 897204 MOV dword ptr [EDX + 4], ESI
    m.w32((s.dx+4u), s.si);
  }
  L006d9d9b: { // 0x6d9d9b: 897a08 MOV dword ptr [EDX + 8], EDI
    m.w32((s.dx+8u), s.di);
  }
  L006d9d9e: { // 0x6d9d9e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006d9d9f: { // 0x6d9d9f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d9da0: { // 0x6d9da0: 895a0c MOV dword ptr [EDX + 0xc], EBX
    m.w32((s.dx+0x0000000cu), s.bx);
  }
  L006d9da3: { // 0x6d9da3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006d9da4: { // 0x6d9da4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d9da5: { // 0x6d9da5: 83c440 ADD ESP, 0x40
    f.sp = integer::add(f.sp,0x00000040u,32,flags);
  }
  L006d9da8: { // 0x6d9da8: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d96f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d96f0: { // 0x6d96f0: a05389a200 MOV AL, byte ptr [0xa28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  L006d96f5: { // 0x6d96f5: 83ec18 SUB ESP, 0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L006d96f8: { // 0x6d96f8: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d96fa: { // 0x6d96fa: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006d96fb: { // 0x6d96fb: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L006d96fc: { // 0x6d96fc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d96fd: { // 0x6d96fd: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006d96fe: { // 0x6d96fe: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L006d9700: { // 0x6d9700: 7532 JNZ 0x6d9734
    if(integer::condition("JNZ",flags)) goto L006d9734;
  }
  L006d9702: { // 0x6d9702: a150deb000 MOV EAX, dword ptr [0xb0de50]
    s.ax = m.r32((0x00b0de50u));
  }
  L006d9707: { // 0x6d9707: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006d9709: { // 0x6d9709: 7429 JZ 0x6d9734
    if(integer::condition("JZ",flags)) goto L006d9734;
  }
  L006d970b: { // 0x6d970b: 8a442430 MOV AL, byte ptr [ESP + 0x30]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000030u)));
  }
  L006d970f: { // 0x6d970f: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d9711: { // 0x6d9711: 750b JNZ 0x6d971e
    if(integer::condition("JNZ",flags)) goto L006d971e;
  }
  L006d9713: { // 0x6d9713: 8a4775 MOV AL, byte ptr [EDI + 0x75]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000075u)));
  }
  L006d9716: { // 0x6d9716: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d9718: { // 0x6d9718: 0f8406010000 JZ 0x6d9824
    if(integer::condition("JZ",flags)) goto L006d9824;
  }
  L006d971e: { // 0x6d971e: 8a4774 MOV AL, byte ptr [EDI + 0x74]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000074u)));
  }
  L006d9721: { // 0x6d9721: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d9723: { // 0x6d9723: 0f84fb000000 JZ 0x6d9824
    if(integer::condition("JZ",flags)) goto L006d9824;
  }
  L006d9729: { // 0x6d9729: 8a4776 MOV AL, byte ptr [EDI + 0x76]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000076u)));
  }
  L006d972c: { // 0x6d972c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006d972e: { // 0x6d972e: 0f85f0000000 JNZ 0x6d9824
    if(integer::condition("JNZ",flags)) goto L006d9824;
  }
  L006d9734: { // 0x6d9734: 8b74242c MOV ESI, dword ptr [ESP + 0x2c]
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L006d9738: { // 0x6d9738: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006d973a: { // 0x6d973a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006d973c: { // 0x6d973c: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L006d9741: { // 0x6d9741: 8bd6 MOV EDX, ESI
    s.dx = s.si;
  }
  L006d9743: { // 0x6d9743: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L006d9747: { // 0x6d9747: c6477500 MOV byte ptr [EDI + 0x75], 0
    m.w8((s.di+0x00000075u), 0u);
  }
  L006d974b: { // 0x6d974b: e8a066d4ff CALL 0x41fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7182160u); flags=s.arithmetic_flags;
  }
  L006d9750: { // 0x6d9750: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006d9752: { // 0x6d9752: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006d9754: { // 0x6d9754: 8911 MOV dword ptr [ECX], EDX
    m.w32((s.cx), s.dx);
  }
  L006d9756: { // 0x6d9756: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L006d9759: { // 0x6d9759: 895104 MOV dword ptr [ECX + 4], EDX
    m.w32((s.cx+4u), s.dx);
  }
  L006d975c: { // 0x6d975c: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L006d975f: { // 0x6d975f: 895108 MOV dword ptr [ECX + 8], EDX
    m.w32((s.cx+8u), s.dx);
  }
  L006d9762: { // 0x6d9762: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L006d9765: { // 0x6d9765: 89410c MOV dword ptr [ECX + 0xc], EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L006d9768: { // 0x6d9768: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006d976a: { // 0x6d976a: 8b1d70198200 MOV EBX, dword ptr [0x821970]
    s.bx = m.r32((0x00821970u));
  }
  L006d9770: { // 0x6d9770: 8b2d74198200 MOV EBP, dword ptr [0x821974]
    s.bp = m.r32((0x00821974u));
  }
  L006d9776: { // 0x6d9776: 8d442418 LEA EAX, [ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  L006d977a: { // 0x6d977a: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006d977c: { // 0x6d977c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d977d: { // 0x6d977d: ff9224010000 CALL dword ptr [EDX + 0x124]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000124u)),7182211u); flags=s.arithmetic_flags;
  }
  L006d9783: { // 0x6d9783: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L006d9785: { // 0x6d9785: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L006d9788: { // 0x6d9788: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L006d978a: { // 0x6d978a: 8b5808 MOV EBX, dword ptr [EAX + 8]
    s.bx = m.r32((s.ax+8u));
  }
  L006d978d: { // 0x6d978d: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L006d9790: { // 0x6d9790: 03ea ADD EBP, EDX
    s.bp = integer::add(s.bp,s.dx,32,flags);
  }
  L006d9792: { // 0x6d9792: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006d9794: { // 0x6d9794: 03d9 ADD EBX, ECX
    s.bx = integer::add(s.bx,s.cx,32,flags);
  }
  L006d9796: { // 0x6d9796: 3bd3 CMP EDX, EBX
    (void)integer::sub(s.dx,s.bx,32,flags);
  }
  L006d9798: { // 0x6d9798: 0f8d86000000 JGE 0x6d9824
    if(integer::condition("JGE",flags)) goto L006d9824;
  }
  L006d979e: { // 0x6d979e: 8b5e04 MOV EBX, dword ptr [ESI + 4]
    s.bx = m.r32((s.si+4u));
  }
  L006d97a1: { // 0x6d97a1: 03c5 ADD EAX, EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L006d97a3: { // 0x6d97a3: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L006d97a5: { // 0x6d97a5: 7d7d JGE 0x6d9824
    if(integer::condition("JGE",flags)) goto L006d9824;
  }
  L006d97a7: { // 0x6d97a7: 8b4608 MOV EAX, dword ptr [ESI + 8]
    s.ax = m.r32((s.si+8u));
  }
  L006d97aa: { // 0x6d97aa: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006d97ac: { // 0x6d97ac: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006d97ae: { // 0x6d97ae: 7e74 JLE 0x6d9824
    if(integer::condition("JLE",flags)) goto L006d9824;
  }
  L006d97b0: { // 0x6d97b0: 8b4e0c MOV ECX, dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L006d97b3: { // 0x6d97b3: 03cb ADD ECX, EBX
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L006d97b5: { // 0x6d97b5: 3bcd CMP ECX, EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L006d97b7: { // 0x6d97b7: 7e6b JLE 0x6d9824
    if(integer::condition("JLE",flags)) goto L006d9824;
  }
  L006d97b9: { // 0x6d97b9: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006d97bb: { // 0x6d97bb: 8d542410 LEA EDX, [ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L006d97bf: { // 0x6d97bf: 8d4c2418 LEA ECX, [ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L006d97c3: { // 0x6d97c3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006d97c4: { // 0x6d97c4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006d97c5: { // 0x6d97c5: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006d97c7: { // 0x6d97c7: ff90a8000000 CALL dword ptr [EAX + 0xa8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000a8u)),7182285u); flags=s.arithmetic_flags;
  }
  L006d97cd: { // 0x6d97cd: 8b0dac1c8200 MOV ECX, dword ptr [0x821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L006d97d3: { // 0x6d97d3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d97d4: { // 0x6d97d4: e837e8fbff CALL 0x698010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00698010u,7182297u); flags=s.arithmetic_flags;
  }
  L006d97d9: { // 0x6d97d9: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L006d97db: { // 0x6d97db: a170198200 MOV EAX, dword ptr [0x821970]
    s.ax = m.r32((0x00821970u));
  }
  L006d97e0: { // 0x6d97e0: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006d97e2: { // 0x6d97e2: 7e0c JLE 0x6d97f0
    if(integer::condition("JLE",flags)) goto L006d97f0;
  }
  L006d97e4: { // 0x6d97e4: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006d97e6: { // 0x6d97e6: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L006d97ea: { // 0x6d97ea: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006d97ec: { // 0x6d97ec: 894c2410 MOV dword ptr [ESP + 0x10], ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  L006d97f0: { // 0x6d97f0: 8b4e04 MOV ECX, dword ptr [ESI + 4]
    s.cx = m.r32((s.si+4u));
  }
  L006d97f3: { // 0x6d97f3: a174198200 MOV EAX, dword ptr [0x821974]
    s.ax = m.r32((0x00821974u));
  }
  L006d97f8: { // 0x6d97f8: 3bc8 CMP ECX, EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006d97fa: { // 0x6d97fa: 7e0c JLE 0x6d9808
    if(integer::condition("JLE",flags)) goto L006d9808;
  }
  L006d97fc: { // 0x6d97fc: 2bc1 SUB EAX, ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006d97fe: { // 0x6d97fe: 8b4c2414 MOV ECX, dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L006d9802: { // 0x6d9802: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L006d9804: { // 0x6d9804: 894c2414 MOV dword ptr [ESP + 0x14], ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006d9808: { // 0x6d9808: 8b17 MOV EDX, dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L006d980a: { // 0x6d980a: 8d442410 LEA EAX, [ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L006d980e: { // 0x6d980e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006d980f: { // 0x6d980f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006d9810: { // 0x6d9810: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L006d9812: { // 0x6d9812: ff920c010000 CALL dword ptr [EDX + 0x10c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000010cu)),7182360u); flags=s.arithmetic_flags;
  }
  L006d9818: { // 0x6d9818: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006d9819: { // 0x6d9819: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d981a: { // 0x6d981a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d981b: { // 0x6d981b: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L006d981d: { // 0x6d981d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006d981e: { // 0x6d981e: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006d9821: { // 0x6d9821: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L006d9824: { // 0x6d9824: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006d9825: { // 0x6d9825: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006d9826: { // 0x6d9826: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L006d9827: { // 0x6d9827: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006d9829: { // 0x6d9829: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006d982a: { // 0x6d982a: 83c418 ADD ESP, 0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L006d982d: { // 0x6d982d: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
void f_001cd5a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd5a0: { // 0x5cd5a0: 8a517d MOV DL, byte ptr [ECX + 0x7d]
    s.dx = with_al(s.dx, m.r8((s.cx+0x0000007du)));
  }
  L005cd5a3: { // 0x5cd5a3: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005cd5a5: { // 0x5cd5a5: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L005cd5a7: { // 0x5cd5a7: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005cd5aa: { // 0x5cd5aa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d9dc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d9dc0: { // 0x6d9dc0: b824000000 MOV EAX, 0x24
    s.ax = 0x00000024u;
  }
  L006d9dc5: { // 0x6d9dc5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002d9bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d9bc0: { // 0x6d9bc0: 8b81b0000000 MOV EAX, dword ptr [ECX + 0xb0]
    s.ax = m.r32((s.cx+0x000000b0u));
  }
  L006d9bc6: { // 0x6d9bc6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001c300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041c300: { // 0x41c300: 8b81a4000000 MOV EAX, dword ptr [ECX + 0xa4]
    s.ax = m.r32((s.cx+0x000000a4u));
  }
  L0041c306: { // 0x41c306: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_001cae40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cae40: { // 0x5cae40: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005cae42: { // 0x5cae42: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6073928u); flags=s.arithmetic_flags;
  }
  L005cae48: { // 0x5cae48: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005cae4a: { // 0x5cae4a: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L005cae4c: { // 0x5cae4c: ffa29c000000 JMP dword ptr [EDX + 0x9c]
    switch(m.r32((s.dx+0x0000009cu))){
    case 0x005cae40u: goto L005cae40;
    case 0x005cae42u: goto L005cae42;
    case 0x005cae48u: goto L005cae48;
    case 0x005cae4au: goto L005cae4a;
    case 0x005cae4cu: goto L005cae4c;
    default:s.arithmetic_flags=flags; tail(m,s,f,m.r32((s.dx+0x0000009cu))); return;}
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6943824u:f_0029f450(m,s,child,{});break;
case 6920592u:f_00299990(m,s,child,{});break;
case 4324848u:f_0001fdf0(m,s,child,{});break;
case 7183312u:f_002d9bd0(m,s,child,{});break;
case 7182064u:f_002d96f0(m,s,child,{});break;
case 6084000u:f_001cd5a0(m,s,child,{});break;
case 7183808u:f_002d9dc0(m,s,child,{});break;
case 7183296u:f_002d9bc0(m,s,child,{});break;
case 4309760u:f_0001c300(m,s,child,{});break;
case 6073920u:f_001cae40(m,s,child,{});break;
default:throw std::domain_error("recovery1510 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){ if(target!=0x41c300u)throw std::domain_error("B1510 unreviewed tail");f_0001c300(m,s,f,{}); } }

std::uint32_t fun_00699990(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00699990: { // 0x699990: 83ec4c SUB ESP, 0x4c
    f.sp = integer::sub(f.sp,0x0000004cu,32,flags);
  }
  L00699993: { // 0x699993: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00699994: { // 0x699994: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00699995: { // 0x699995: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00699996: { // 0x699996: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00699998: { // 0x699998: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00699999: { // 0x699999: 8b86e0000000 MOV EAX, dword ptr [ESI + 0xe0]
    s.ax = m.r32((s.si+0x000000e0u));
  }
  L0069999f: { // 0x69999f: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006999a1: { // 0x6999a1: 0f8e01010000 JLE 0x699aa8
    if(integer::condition("JLE",flags)) goto L00699aa8;
  }
  L006999a7: { // 0x6999a7: c744241000000000 MOV dword ptr [ESP + 0x10], 0
    m.w32((f.sp+0x00000010u), 0u);
  }
  L006999af: { // 0x6999af: 8dbee4000000 LEA EDI, [ESI + 0xe4]
    s.di = (s.si+0x000000e4u);
  }
  L006999b5: { // 0x6999b5: 8b07 MOV EAX, dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L006999b7: { // 0x6999b7: 6a00 PUSH 0
    f.push(m,0u);
  }
  L006999b9: { // 0x6999b9: 8b4024 MOV EAX, dword ptr [EAX + 0x24]
    s.ax = m.r32((s.ax+0x00000024u));
  }
  L006999bc: { // 0x6999bc: 89442418 MOV dword ptr [ESP + 0x18], EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L006999c0: { // 0x6999c0: 0fbfc8 MOVSX ECX, AX
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L006999c3: { // 0x6999c3: 0fbf44241a MOVSX EAX, word ptr [ESP + 0x1a]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((f.sp+0x0000001au)),16));
  }
  L006999c8: { // 0x6999c8: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L006999cb: { // 0x6999cb: 0580000000 ADD EAX, 0x80
    s.ax = integer::add(s.ax,0x00000080u,32,flags);
  }
  L006999d0: { // 0x6999d0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006999d1: { // 0x6999d1: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006999d7: { // 0x6999d7: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006999d9: { // 0x6999d9: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006999dc: { // 0x6999dc: c1e108 SHL ECX, 8
    s.cx = integer::shift(s.cx,8u,32,flags,integer::Shift::left);
  }
  L006999df: { // 0x6999df: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L006999e2: { // 0x6999e2: 81c180000000 ADD ECX, 0x80
    s.cx = integer::add(s.cx,0x00000080u,32,flags);
  }
  L006999e8: { // 0x6999e8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006999e9: { // 0x6999e9: 8bc1 MOV EAX, ECX
    s.ax = s.cx;
  }
  L006999eb: { // 0x6999eb: 8d4c2428 LEA ECX, [ESP + 0x28]
    s.cx = (f.sp+0x00000028u);
  }
  L006999ef: { // 0x6999ef: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006999f0: { // 0x6999f0: 81e2ff000000 AND EDX, 0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006999f6: { // 0x6999f6: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006999f8: { // 0x6999f8: c1f808 SAR EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::arithmetic_right);
  }
  L006999fb: { // 0x6999fb: c1e008 SHL EAX, 8
    s.ax = integer::shift(s.ax,8u,32,flags,integer::Shift::left);
  }
  L006999fe: { // 0x6999fe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006999ff: { // 0x6999ff: e82c1cd8ff CALL 0x41b630
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041b630u,6920708u); flags=s.arithmetic_flags;
  }
  L00699a04: { // 0x699a04: 8b4c2420 MOV ECX, dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00699a08: { // 0x699a08: 8b542424 MOV EDX, dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00699a0c: { // 0x699a0c: 8b442428 MOV EAX, dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L00699a10: { // 0x699a10: 894c242c MOV dword ptr [ESP + 0x2c], ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00699a14: { // 0x699a14: 89542430 MOV dword ptr [ESP + 0x30], EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L00699a18: { // 0x699a18: 8d4c242c LEA ECX, [ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00699a1c: { // 0x699a1c: 8d542418 LEA EDX, [ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L00699a20: { // 0x699a20: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00699a21: { // 0x699a21: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00699a22: { // 0x699a22: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699a24: { // 0x699a24: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00699a28: { // 0x699a28: e8b3e3ffff CALL 0x697de0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697de0u,6920749u); flags=s.arithmetic_flags;
  }
  L00699a2d: { // 0x699a2d: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00699a2f: { // 0x699a2f: 8b9eb4000000 MOV EBX, dword ptr [ESI + 0xb4]
    s.bx = m.r32((s.si+0x000000b4u));
  }
  L00699a35: { // 0x699a35: 8b96b0000000 MOV EDX, dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00699a3b: { // 0x699a3b: 8b2d74198200 MOV EBP, dword ptr [0x821974]
    s.bp = m.r32((0x00821974u));
  }
  L00699a41: { // 0x699a41: 8b4004 MOV EAX, dword ptr [EAX + 4]
    s.ax = m.r32((s.ax+4u));
  }
  L00699a44: { // 0x699a44: 2bca SUB ECX, EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00699a46: { // 0x699a46: 2bc3 SUB EAX, EBX
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00699a48: { // 0x699a48: 83c1e2 ADD ECX, -0x1e
    s.cx = integer::add(s.cx,0xffffffe2u,32,flags);
  }
  L00699a4b: { // 0x699a4b: 89442440 MOV dword ptr [ESP + 0x40], EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00699a4f: { // 0x699a4f: 03c5 ADD EAX, EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00699a51: { // 0x699a51: 89442440 MOV dword ptr [ESP + 0x40], EAX
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00699a55: { // 0x699a55: 89442450 MOV dword ptr [ESP + 0x50], EAX
    m.w32((f.sp+0x00000050u), s.ax);
  }
  L00699a59: { // 0x699a59: 894c243c MOV dword ptr [ESP + 0x3c], ECX
    m.w32((f.sp+0x0000003cu), s.cx);
  }
  L00699a5d: { // 0x699a5d: 894c244c MOV dword ptr [ESP + 0x4c], ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  L00699a61: { // 0x699a61: 8d44244c LEA EAX, [ESP + 0x4c]
    s.ax = (f.sp+0x0000004cu);
  }
  L00699a65: { // 0x699a65: 8d4c243c LEA ECX, [ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  L00699a69: { // 0x699a69: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699a6a: { // 0x699a6a: ba3c000000 MOV EDX, 0x3c
    s.dx = 0x0000003cu;
  }
  L00699a6f: { // 0x699a6f: bb1e000000 MOV EBX, 0x1e
    s.bx = 0x0000001eu;
  }
  L00699a74: { // 0x699a74: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00699a75: { // 0x699a75: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699a77: { // 0x699a77: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699a79: { // 0x699a79: 89542450 MOV dword ptr [ESP + 0x50], EDX
    m.w32((f.sp+0x00000050u), s.dx);
  }
  L00699a7d: { // 0x699a7d: 895c2454 MOV dword ptr [ESP + 0x54], EBX
    m.w32((f.sp+0x00000054u), s.bx);
  }
  L00699a81: { // 0x699a81: 89542460 MOV dword ptr [ESP + 0x60], EDX
    m.w32((f.sp+0x00000060u), s.dx);
  }
  L00699a85: { // 0x699a85: 895c2464 MOV dword ptr [ESP + 0x64], EBX
    m.w32((f.sp+0x00000064u), s.bx);
  }
  L00699a89: { // 0x699a89: e8c2590000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6920846u); flags=s.arithmetic_flags;
  }
  L00699a8e: { // 0x699a8e: 8b442410 MOV EAX, dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L00699a92: { // 0x699a92: 8b8ee0000000 MOV ECX, dword ptr [ESI + 0xe0]
    s.cx = m.r32((s.si+0x000000e0u));
  }
  L00699a98: { // 0x699a98: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00699a99: { // 0x699a99: 83c704 ADD EDI, 4
    s.di = integer::add(s.di,4u,32,flags);
  }
  L00699a9c: { // 0x699a9c: 3bc1 CMP EAX, ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00699a9e: { // 0x699a9e: 89442410 MOV dword ptr [ESP + 0x10], EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L00699aa2: { // 0x699aa2: 0f8c0dffffff JL 0x6999b5
    if(integer::condition("JL",flags)) goto L006999b5;
  }
  L00699aa8: { // 0x699aa8: a1c860aa00 MOV EAX, dword ptr [0xaa60c8]
    s.ax = m.r32((0x00aa60c8u));
  }
  L00699aad: { // 0x699aad: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00699aaf: { // 0x699aaf: 0f84b8000000 JZ 0x699b6d
    if(integer::condition("JZ",flags)) goto L00699b6d;
  }
  L00699ab5: { // 0x699ab5: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00699ab6: { // 0x699ab6: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00699ab8: { // 0x699ab8: 0f8caf000000 JL 0x699b6d
    if(integer::condition("JL",flags)) goto L00699b6d;
  }
  L00699abe: { // 0x699abe: 8d3c80 LEA EDI, [EAX + EAX*4]
    s.di = (s.ax+(s.ax * 4u));
  }
  L00699ac1: { // 0x699ac1: 8d5801 LEA EBX, [EAX + 1]
    s.bx = (s.ax+1u);
  }
  L00699ac4: { // 0x699ac4: c1e702 SHL EDI, 2
    s.di = integer::shift(s.di,2u,32,flags,integer::Shift::left);
  }
  L00699ac7: { // 0x699ac7: 8b15bc60aa00 MOV EDX, dword ptr [0xaa60bc]
    s.dx = m.r32((0x00aa60bcu));
  }
  L00699acd: { // 0x699acd: 8b2d74198200 MOV EBP, dword ptr [0x821974]
    s.bp = m.r32((0x00821974u));
  }
  L00699ad3: { // 0x699ad3: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00699ad5: { // 0x699ad5: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00699ad7: { // 0x699ad7: 8d0417 LEA EAX, [EDI + EDX]
    s.ax = (s.di+s.dx);
  }
  L00699ada: { // 0x699ada: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00699adc: { // 0x699adc: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00699ade: { // 0x699ade: 89542434 MOV dword ptr [ESP + 0x34], EDX
    m.w32((f.sp+0x00000034u), s.dx);
  }
  L00699ae2: { // 0x699ae2: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L00699ae5: { // 0x699ae5: 89442438 MOV dword ptr [ESP + 0x38], EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00699ae9: { // 0x699ae9: 03c5 ADD EAX, EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00699aeb: { // 0x699aeb: 8b5108 MOV EDX, dword ptr [ECX + 8]
    s.dx = m.r32((s.cx+8u));
  }
  L00699aee: { // 0x699aee: 8954243c MOV dword ptr [ESP + 0x3c], EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  L00699af2: { // 0x699af2: 8d542434 LEA EDX, [ESP + 0x34]
    s.dx = (f.sp+0x00000034u);
  }
  L00699af6: { // 0x699af6: 8b490c MOV ECX, dword ptr [ECX + 0xc]
    s.cx = m.r32((s.cx+0x0000000cu));
  }
  L00699af9: { // 0x699af9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00699afa: { // 0x699afa: 894c2444 MOV dword ptr [ESP + 0x44], ECX
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00699afe: { // 0x699afe: ba70198200 MOV EDX, 0x821970
    s.dx = 0x00821970u;
  }
  L00699b03: { // 0x699b03: 8d4c2448 LEA ECX, [ESP + 0x48]
    s.cx = (f.sp+0x00000048u);
  }
  L00699b07: { // 0x699b07: 8944243c MOV dword ptr [ESP + 0x3c], EAX
    m.w32((f.sp+0x0000003cu), s.ax);
  }
  L00699b0b: { // 0x699b0b: e8e062d8ff CALL 0x41fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6920976u); flags=s.arithmetic_flags;
  }
  L00699b10: { // 0x699b10: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00699b12: { // 0x699b12: 8b0a MOV ECX, dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L00699b14: { // 0x699b14: 894c242c MOV dword ptr [ESP + 0x2c], ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L00699b18: { // 0x699b18: 8b4a04 MOV ECX, dword ptr [EDX + 4]
    s.cx = m.r32((s.dx+4u));
  }
  L00699b1b: { // 0x699b1b: 894c2430 MOV dword ptr [ESP + 0x30], ECX
    m.w32((f.sp+0x00000030u), s.cx);
  }
  L00699b1f: { // 0x699b1f: 8b4a08 MOV ECX, dword ptr [EDX + 8]
    s.cx = m.r32((s.dx+8u));
  }
  L00699b22: { // 0x699b22: 894c2434 MOV dword ptr [ESP + 0x34], ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L00699b26: { // 0x699b26: 8b520c MOV EDX, dword ptr [EDX + 0xc]
    s.dx = m.r32((s.dx+0x0000000cu));
  }
  L00699b29: { // 0x699b29: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699b2b: { // 0x699b2b: 89542438 MOV dword ptr [ESP + 0x38], EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00699b2f: { // 0x699b2f: 7e32 JLE 0x699b63
    if(integer::condition("JLE",flags)) goto L00699b63;
  }
  L00699b31: { // 0x699b31: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00699b33: { // 0x699b33: 7e2e JLE 0x699b63
    if(integer::condition("JLE",flags)) goto L00699b63;
  }
  L00699b35: { // 0x699b35: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00699b37: { // 0x699b37: 8b4804 MOV ECX, dword ptr [EAX + 4]
    s.cx = m.r32((s.ax+4u));
  }
  L00699b3a: { // 0x699b3a: 8954244c MOV dword ptr [ESP + 0x4c], EDX
    m.w32((f.sp+0x0000004cu), s.dx);
  }
  L00699b3e: { // 0x699b3e: 8b5008 MOV EDX, dword ptr [EAX + 8]
    s.dx = m.r32((s.ax+8u));
  }
  L00699b41: { // 0x699b41: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L00699b44: { // 0x699b44: 894c2450 MOV dword ptr [ESP + 0x50], ECX
    m.w32((f.sp+0x00000050u), s.cx);
  }
  L00699b48: { // 0x699b48: 89542454 MOV dword ptr [ESP + 0x54], EDX
    m.w32((f.sp+0x00000054u), s.dx);
  }
  L00699b4c: { // 0x699b4c: 8d4c244c LEA ECX, [ESP + 0x4c]
    s.cx = (f.sp+0x0000004cu);
  }
  L00699b50: { // 0x699b50: 8d54242c LEA EDX, [ESP + 0x2c]
    s.dx = (f.sp+0x0000002cu);
  }
  L00699b54: { // 0x699b54: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00699b55: { // 0x699b55: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00699b56: { // 0x699b56: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699b58: { // 0x699b58: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699b5a: { // 0x699b5a: 89442464 MOV dword ptr [ESP + 0x64], EAX
    m.w32((f.sp+0x00000064u), s.ax);
  }
  L00699b5e: { // 0x699b5e: e8ed580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921059u); flags=s.arithmetic_flags;
  }
  L00699b63: { // 0x699b63: 83ef14 SUB EDI, 0x14
    s.di = integer::sub(s.di,0x00000014u,32,flags);
  }
  L00699b66: { // 0x699b66: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  L00699b67: { // 0x699b67: 0f855affffff JNZ 0x699ac7
    if(integer::condition("JNZ",flags)) goto L00699ac7;
  }
  L00699b6d: { // 0x699b6d: 8a442468 MOV AL, byte ptr [ESP + 0x68]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000068u)));
  }
  L00699b71: { // 0x699b71: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00699b73: { // 0x699b73: 741d JZ 0x699b92
    if(integer::condition("JZ",flags)) goto L00699b92;
  }
  L00699b75: { // 0x699b75: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L00699b7a: { // 0x699b7a: 6870198200 PUSH 0x821970
    f.push(m,0x00821970u);
  }
  L00699b7f: { // 0x699b7f: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699b81: { // 0x699b81: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699b83: { // 0x699b83: e8c8580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921096u); flags=s.arithmetic_flags;
  }
  L00699b88: { // 0x699b88: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00699b89: { // 0x699b89: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00699b8a: { // 0x699b8a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00699b8b: { // 0x699b8b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00699b8c: { // 0x699b8c: 83c44c ADD ESP, 0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L00699b8f: { // 0x699b8f: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00699b92: { // 0x699b92: 8b442460 MOV EAX, dword ptr [ESP + 0x60]
    s.ax = m.r32((f.sp+0x00000060u));
  }
  L00699b96: { // 0x699b96: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L00699b99: { // 0x699b99: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699b9b: { // 0x699b9b: 7e12 JLE 0x699baf
    if(integer::condition("JLE",flags)) goto L00699baf;
  }
  L00699b9d: { // 0x699b9d: 8b480c MOV ECX, dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00699ba0: { // 0x699ba0: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699ba2: { // 0x699ba2: 7e0b JLE 0x699baf
    if(integer::condition("JLE",flags)) goto L00699baf;
  }
  L00699ba4: { // 0x699ba4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699ba5: { // 0x699ba5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699ba6: { // 0x699ba6: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699ba8: { // 0x699ba8: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699baa: { // 0x699baa: e8a1580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921135u); flags=s.arithmetic_flags;
  }
  L00699baf: { // 0x699baf: 8b442464 MOV EAX, dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L00699bb3: { // 0x699bb3: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L00699bb6: { // 0x699bb6: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699bb8: { // 0x699bb8: 7e12 JLE 0x699bcc
    if(integer::condition("JLE",flags)) goto L00699bcc;
  }
  L00699bba: { // 0x699bba: 8b480c MOV ECX, dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  L00699bbd: { // 0x699bbd: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00699bbf: { // 0x699bbf: 7e0b JLE 0x699bcc
    if(integer::condition("JLE",flags)) goto L00699bcc;
  }
  L00699bc1: { // 0x699bc1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699bc2: { // 0x699bc2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00699bc3: { // 0x699bc3: 6a01 PUSH 1
    f.push(m,1u);
  }
  L00699bc5: { // 0x699bc5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00699bc7: { // 0x699bc7: e884580000 CALL 0x69f450
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069f450u,6921164u); flags=s.arithmetic_flags;
  }
  L00699bcc: { // 0x699bcc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00699bcd: { // 0x699bcd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00699bce: { // 0x699bce: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00699bcf: { // 0x699bcf: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00699bd0: { // 0x699bd0: 83c44c ADD ESP, 0x4c
    f.sp = integer::add(f.sp,0x0000004cu,32,flags);
  }
  L00699bd3: { // 0x699bd3: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0069f450(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0069f450: { // 0x69f450: 83ec30 SUB ESP, 0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  L0069f453: { // 0x69f453: 8b44243c MOV EAX, dword ptr [ESP + 0x3c]
    s.ax = m.r32((f.sp+0x0000003cu));
  }
  L0069f457: { // 0x69f457: 8b542438 MOV EDX, dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L0069f45b: { // 0x69f45b: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0069f45d: { // 0x69f45d: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0069f45f: { // 0x69f45f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069f460: { // 0x69f460: 8d4c241c LEA ECX, [ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L0069f464: { // 0x69f464: e88709d8ff CALL 0x41fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,6943849u); flags=s.arithmetic_flags;
  }
  L0069f469: { // 0x69f469: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069f46b: { // 0x69f46b: 894c2400 MOV dword ptr [ESP], ECX
    m.w32((f.sp), s.cx);
  }
  L0069f46f: { // 0x69f46f: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0069f472: { // 0x69f472: 89542404 MOV dword ptr [ESP + 4], EDX
    m.w32((f.sp+4u), s.dx);
  }
  L0069f476: { // 0x69f476: 8b4808 MOV ECX, dword ptr [EAX + 8]
    s.cx = m.r32((s.ax+8u));
  }
  L0069f479: { // 0x69f479: 894c2408 MOV dword ptr [ESP + 8], ECX
    m.w32((f.sp+8u), s.cx);
  }
  L0069f47d: { // 0x69f47d: 8b500c MOV EDX, dword ptr [EAX + 0xc]
    s.dx = m.r32((s.ax+0x0000000cu));
  }
  L0069f480: { // 0x69f480: a1e8a88300 MOV EAX, dword ptr [0x83a8e8]
    s.ax = m.r32((0x0083a8e8u));
  }
  L0069f485: { // 0x69f485: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0069f486: { // 0x69f486: 8954240c MOV dword ptr [ESP + 0xc], EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  L0069f48a: { // 0x69f48a: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0069f48c: { // 0x69f48c: 89442438 MOV dword ptr [ESP + 0x38], EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L0069f490: { // 0x69f490: 0f8cf0000000 JL 0x69f586
    if(integer::condition("JL",flags)) goto L0069f586;
  }
  L0069f496: { // 0x69f496: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0069f497: { // 0x69f497: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0069f498: { // 0x69f498: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0069f499: { // 0x69f499: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0069f49a: { // 0x69f49a: 8b0ddca88300 MOV ECX, dword ptr [0x83a8dc]
    s.cx = m.r32((0x0083a8dcu));
  }
  L0069f4a0: { // 0x69f4a0: 8b3481 MOV ESI, dword ptr [ECX + EAX*4]
    s.si = m.r32((s.cx+(s.ax * 4u)));
  }
  L0069f4a3: { // 0x69f4a3: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f4a5: { // 0x69f4a5: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069f4a7: { // 0x69f4a7: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),6943914u); flags=s.arithmetic_flags;
  }
  L0069f4aa: { // 0x69f4aa: 83f824 CMP EAX, 0x24
    (void)integer::sub(s.ax,0x00000024u,32,flags);
  }
  L0069f4ad: { // 0x69f4ad: 0f85c0000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4b3: { // 0x69f4b3: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0069f4b5: { // 0x69f4b5: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f4b7: { // 0x69f4b7: ff5044 CALL dword ptr [EAX + 0x44]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000044u)),6943930u); flags=s.arithmetic_flags;
  }
  L0069f4ba: { // 0x69f4ba: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069f4bc: { // 0x69f4bc: 0f85b1000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4c2: { // 0x69f4c2: 8b8eb0000000 MOV ECX, dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L0069f4c8: { // 0x69f4c8: 8a8183020000 MOV AL, byte ptr [ECX + 0x283]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000283u)));
  }
  L0069f4ce: { // 0x69f4ce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069f4d0: { // 0x69f4d0: 0f859d000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4d6: { // 0x69f4d6: 8a86b5000000 MOV AL, byte ptr [ESI + 0xb5]
    s.ax = with_al(s.ax, m.r8((s.si+0x000000b5u)));
  }
  L0069f4dc: { // 0x69f4dc: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0069f4de: { // 0x69f4de: 0f858f000000 JNZ 0x69f573
    if(integer::condition("JNZ",flags)) goto L0069f573;
  }
  L0069f4e4: { // 0x69f4e4: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069f4e6: { // 0x69f4e6: 8b3d70198200 MOV EDI, dword ptr [0x821970]
    s.di = m.r32((0x00821970u));
  }
  L0069f4ec: { // 0x69f4ec: 8b2d74198200 MOV EBP, dword ptr [0x821974]
    s.bp = m.r32((0x00821974u));
  }
  L0069f4f2: { // 0x69f4f2: 8d442430 LEA EAX, [ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0069f4f6: { // 0x69f4f6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069f4f7: { // 0x69f4f7: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f4f9: { // 0x69f4f9: ff9224010000 CALL dword ptr [EDX + 0x124]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000124u)),6943999u); flags=s.arithmetic_flags;
  }
  L0069f4ff: { // 0x69f4ff: 8b5004 MOV EDX, dword ptr [EAX + 4]
    s.dx = m.r32((s.ax+4u));
  }
  L0069f502: { // 0x69f502: 8b08 MOV ECX, dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L0069f504: { // 0x69f504: 8b5c2418 MOV EBX, dword ptr [ESP + 0x18]
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L0069f508: { // 0x69f508: 03d5 ADD EDX, EBP
    s.dx = integer::add(s.dx,s.bp,32,flags);
  }
  L0069f50a: { // 0x69f50a: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0069f50e: { // 0x69f50e: 03cf ADD ECX, EDI
    s.cx = integer::add(s.cx,s.di,32,flags);
  }
  L0069f510: { // 0x69f510: 8b7808 MOV EDI, dword ptr [EAX + 8]
    s.di = m.r32((s.ax+8u));
  }
  L0069f513: { // 0x69f513: 8b400c MOV EAX, dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0069f516: { // 0x69f516: 03dd ADD EBX, EBP
    s.bx = integer::add(s.bx,s.bp,32,flags);
  }
  L0069f518: { // 0x69f518: 3bcb CMP ECX, EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L0069f51a: { // 0x69f51a: 7d57 JGE 0x69f573
    if(integer::condition("JGE",flags)) goto L0069f573;
  }
  L0069f51c: { // 0x69f51c: 8b5c2414 MOV EBX, dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  L0069f520: { // 0x69f520: 8b6c241c MOV EBP, dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L0069f524: { // 0x69f524: 03eb ADD EBP, EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0069f526: { // 0x69f526: 3bd5 CMP EDX, EBP
    (void)integer::sub(s.dx,s.bp,32,flags);
  }
  L0069f528: { // 0x69f528: 7d49 JGE 0x69f573
    if(integer::condition("JGE",flags)) goto L0069f573;
  }
  L0069f52a: { // 0x69f52a: 03f9 ADD EDI, ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0069f52c: { // 0x69f52c: 8b4c2410 MOV ECX, dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0069f530: { // 0x69f530: 3bf9 CMP EDI, ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0069f532: { // 0x69f532: 7e3f JLE 0x69f573
    if(integer::condition("JLE",flags)) goto L0069f573;
  }
  L0069f534: { // 0x69f534: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0069f536: { // 0x69f536: 3bc3 CMP EAX, EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L0069f538: { // 0x69f538: 7e39 JLE 0x69f573
    if(integer::condition("JLE",flags)) goto L0069f573;
  }
  L0069f53a: { // 0x69f53a: 8b4c244c MOV ECX, dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L0069f53e: { // 0x69f53e: 6a00 PUSH 0
    f.push(m,0u);
  }
  L0069f540: { // 0x69f540: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0069f542: { // 0x69f542: 89542424 MOV dword ptr [ESP + 0x24], EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0069f546: { // 0x69f546: 8b4104 MOV EAX, dword ptr [ECX + 4]
    s.ax = m.r32((s.cx+4u));
  }
  L0069f549: { // 0x69f549: 89442428 MOV dword ptr [ESP + 0x28], EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0069f54d: { // 0x69f54d: 8b5108 MOV EDX, dword ptr [ECX + 8]
    s.dx = m.r32((s.cx+8u));
  }
  L0069f550: { // 0x69f550: 8954242c MOV dword ptr [ESP + 0x2c], EDX
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L0069f554: { // 0x69f554: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0069f556: { // 0x69f556: 8b410c MOV EAX, dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L0069f559: { // 0x69f559: 8d4c2424 LEA ECX, [ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0069f55d: { // 0x69f55d: 89442430 MOV dword ptr [ESP + 0x30], EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0069f561: { // 0x69f561: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0069f565: { // 0x69f565: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0069f566: { // 0x69f566: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0069f567: { // 0x69f567: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0069f569: { // 0x69f569: ff92fc000000 CALL dword ptr [EDX + 0xfc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000fcu)),6944111u); flags=s.arithmetic_flags;
  }
  L0069f56f: { // 0x69f56f: c6467500 MOV byte ptr [ESI + 0x75], 0
    m.w8((s.si+0x00000075u), 0u);
  }
  L0069f573: { // 0x69f573: 8b442448 MOV EAX, dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0069f577: { // 0x69f577: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0069f578: { // 0x69f578: 89442448 MOV dword ptr [ESP + 0x48], EAX
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0069f57c: { // 0x69f57c: 0f8918ffffff JNS 0x69f49a
    if(integer::condition("JNS",flags)) goto L0069f49a;
  }
  L0069f582: { // 0x69f582: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0069f583: { // 0x69f583: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0069f584: { // 0x69f584: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0069f585: { // 0x69f585: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0069f586: { // 0x69f586: 83c430 ADD ESP, 0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  L0069f589: { // 0x69f589: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
