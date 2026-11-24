#include "recovered/recovery_b663_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b663 {
namespace {
void f_0001b320(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_001ccb00(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_00058540(Memory&,State&,Frame&,const Operations&);
void f_00130af0(Memory&,State&,Frame&,const Operations&);
void f_00122930(Memory&,State&,Frame&,const Operations&);
void f_002ce4b0(Memory&,State&,Frame&,const Operations&);
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_0005e3c0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0001b320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b320: { // 0x41b320: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041b321: { // 0x41b321: 8b8188000000 MOV EAX,dword ptr [ECX + 0x88]
    s.ax = m.r32((s.cx+0x00000088u));
  }
  L0041b327: { // 0x41b327: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b328: { // 0x41b328: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b32e: { // 0x41b32e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b330: { // 0x41b330: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b333: { // 0x41b333: 6689442400 MOV word ptr [ESP],AX
    m.w16((f.sp), (s.ax & 0xffffu));
  }
  L0041b338: { // 0x41b338: 8b818c000000 MOV EAX,dword ptr [ECX + 0x8c]
    s.ax = m.r32((s.cx+0x0000008cu));
  }
  L0041b33e: { // 0x41b33e: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041b33f: { // 0x41b33f: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041b345: { // 0x41b345: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041b347: { // 0x41b347: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041b34a: { // 0x41b34a: 6689442402 MOV word ptr [ESP + 0x2],AX
    m.w16((f.sp+0x00000002u), (s.ax & 0xffffu));
  }
  L0041b34f: { // 0x41b34f: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L0041b353: { // 0x41b353: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  L0041b357: { // 0x41b357: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  L0041b359: { // 0x41b359: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0041b35a: { // 0x41b35a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00145500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00545500: { // 0x545500: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00545504: { // 0x545504: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00545505: { // 0x545505: 0fbf4202 MOVSX EAX,word ptr [EDX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.dx+0x00000002u)),16));
  }
  L00545509: { // 0x545509: 0fbf32 MOVSX ESI,word ptr [EDX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.dx)),16));
  }
  L0054550c: { // 0x54550c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054550f: { // 0x54550f: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00545511: { // 0x545511: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00545512: { // 0x545512: 7814 JS 0x00545528
    if(integer::condition("JS",flags)) goto L00545528;
  }
  L00545514: { // 0x545514: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L00545519: { // 0x545519: 7d0d JGE 0x00545528
    if(integer::condition("JGE",flags)) goto L00545528;
  }
  L0054551b: { // 0x54551b: 8b8938010000 MOV ECX,dword ptr [ECX + 0x138]
    s.cx = m.r32((s.cx+0x00000138u));
  }
  L00545521: { // 0x545521: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L00545524: { // 0x545524: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00545526: { // 0x545526: 750d JNZ 0x00545535
    if(integer::condition("JNZ",flags)) goto L00545535;
  }
  L00545528: { // 0x545528: 8b12 MOV EDX,dword ptr [EDX]
    s.dx = m.r32((s.dx));
  }
  L0054552a: { // 0x54552a: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054552f: { // 0x54552f: 89153476a500 MOV dword ptr [0x00a57634],EDX
    m.w32((0x00a57634u), s.dx);
  }
  L00545535: { // 0x545535: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_001ccb00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ccb00: { // 0x5ccb00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005ccb01: { // 0x5ccb01: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ccb02: { // 0x5ccb02: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005ccb04: { // 0x5ccb04: 8a0d84aaa500 MOV CL, byte ptr [0xa5aa84]
    s.cx = with_al(s.cx, m.r8((0x00a5aa84u)));
  }
  L005ccb0a: { // 0x5ccb0a: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L005ccb0c: { // 0x5ccb0c: 84c8 TEST AL, CL
    (void)integer::logical(((s.ax & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005ccb0e: { // 0x5ccb0e: 752f JNZ 0x5ccb3f
    if(integer::condition("JNZ",flags)) goto L005ccb3f;
  }
  L005ccb10: { // 0x5ccb10: 8ad1 MOV DL, CL
    s.dx = with_al(s.dx, (s.cx & 0xffu));
  }
  L005ccb12: { // 0x5ccb12: 6880cb5c00 PUSH 0x5ccb80
    f.push(m,0x005ccb80u);
  }
  L005ccb17: { // 0x5ccb17: 0ad0 OR DL, AL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L005ccb19: { // 0x5ccb19: b8ff7f0000 MOV EAX, 0x7fff
    s.ax = 0x00007fffu;
  }
  L005ccb1e: { // 0x5ccb1e: 6689442408 MOV word ptr [ESP + 8], AX
    m.w16((f.sp+8u), (s.ax & 0xffffu));
  }
  L005ccb23: { // 0x5ccb23: 668944240a MOV word ptr [ESP + 0xa], AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L005ccb28: { // 0x5ccb28: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L005ccb2c: { // 0x5ccb2c: 881584aaa500 MOV byte ptr [0xa5aa84], DL
    m.w8((0x00a5aa84u), (s.dx & 0xffu));
  }
  L005ccb32: { // 0x5ccb32: a380aaa500 MOV dword ptr [0xa5aa80], EAX
    m.w32((0x00a5aa80u), s.ax);
  }
  L005ccb37: { // 0x5ccb37: e88e171a00 CALL 0x76e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,6081340u); flags=s.arithmetic_flags;
  }
  L005ccb3c: { // 0x5ccb3c: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L005ccb3f: { // 0x5ccb3f: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L005ccb41: { // 0x5ccb41: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005ccb43: { // 0x5ccb43: ff9284000000 CALL dword ptr [EDX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000084u)),6081353u); flags=s.arithmetic_flags;
  }
  L005ccb49: { // 0x5ccb49: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ccb4b: { // 0x5ccb4b: 750a JNZ 0x5ccb57
    if(integer::condition("JNZ",flags)) goto L005ccb57;
  }
  L005ccb4d: { // 0x5ccb4d: b880aaa500 MOV EAX, 0xa5aa80
    s.ax = 0x00a5aa80u;
  }
  L005ccb52: { // 0x5ccb52: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ccb53: { // 0x5ccb53: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005ccb54: { // 0x5ccb54: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L005ccb57: { // 0x5ccb57: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005ccb59: { // 0x5ccb59: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L005ccb5b: { // 0x5ccb5b: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6081377u); flags=s.arithmetic_flags;
  }
  L005ccb61: { // 0x5ccb61: 8b4c240c MOV ECX, dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L005ccb65: { // 0x5ccb65: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005ccb67: { // 0x5ccb67: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005ccb68: { // 0x5ccb68: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L005ccb6a: { // 0x5ccb6a: ff9290000000 CALL dword ptr [EDX + 0x90]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000090u)),6081392u); flags=s.arithmetic_flags;
  }
  L005ccb70: { // 0x5ccb70: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005ccb71: { // 0x5ccb71: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005ccb72: { // 0x5ccb72: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
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
void f_00058540(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00458540: { // 0x458540: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00458541: { // 0x458541: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00458542: { // 0x458542: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L00458544: { // 0x458544: 8a0df0708300 MOV CL, byte ptr [0x8370f0]
    s.cx = with_al(s.cx, m.r8((0x008370f0u)));
  }
  L0045854a: { // 0x45854a: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L0045854c: { // 0x45854c: 84c8 TEST AL, CL
    (void)integer::logical(((s.ax & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0045854e: { // 0x45854e: 752f JNZ 0x45857f
    if(integer::condition("JNZ",flags)) goto L0045857f;
  }
  L00458550: { // 0x458550: 8ad1 MOV DL, CL
    s.dx = with_al(s.dx, (s.cx & 0xffu));
  }
  L00458552: { // 0x458552: 68a0854500 PUSH 0x4585a0
    f.push(m,0x004585a0u);
  }
  L00458557: { // 0x458557: 0ad0 OR DL, AL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|((s.ax & 0xffu)),8,flags));
  }
  L00458559: { // 0x458559: b8ff7f0000 MOV EAX, 0x7fff
    s.ax = 0x00007fffu;
  }
  L0045855e: { // 0x45855e: 6689442408 MOV word ptr [ESP + 8], AX
    m.w16((f.sp+8u), (s.ax & 0xffffu));
  }
  L00458563: { // 0x458563: 668944240a MOV word ptr [ESP + 0xa], AX
    m.w16((f.sp+0x0000000au), (s.ax & 0xffffu));
  }
  L00458568: { // 0x458568: 8b442408 MOV EAX, dword ptr [ESP + 8]
    s.ax = m.r32((f.sp+8u));
  }
  L0045856c: { // 0x45856c: 8815f0708300 MOV byte ptr [0x8370f0], DL
    m.w8((0x008370f0u), (s.dx & 0xffu));
  }
  L00458572: { // 0x458572: a318718300 MOV dword ptr [0x837118], EAX
    m.w32((0x00837118u), s.ax);
  }
  L00458577: { // 0x458577: e84e5d3100 CALL 0x76e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,4556156u); flags=s.arithmetic_flags;
  }
  L0045857c: { // 0x45857c: 83c404 ADD ESP, 4
    f.sp = integer::add(f.sp,4u,32,flags);
  }
  L0045857f: { // 0x45857f: 8b86940b0000 MOV EAX, dword ptr [ESI + 0xb94]
    s.ax = m.r32((s.si+0x00000b94u));
  }
  L00458585: { // 0x458585: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00458586: { // 0x458586: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00458588: { // 0x458588: 7505 JNZ 0x45858f
    if(integer::condition("JNZ",flags)) goto L0045858f;
  }
  L0045858a: { // 0x45858a: b818718300 MOV EAX, 0x837118
    s.ax = 0x00837118u;
  }
  L0045858f: { // 0x45858f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00458590: { // 0x458590: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_00130af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00530af0: { // 0x530af0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00530af1: { // 0x530af1: 8b742408 MOV ESI, dword ptr [ESP + 8]
    s.si = m.r32((f.sp+8u));
  }
  L00530af5: { // 0x530af5: 81e6ff000000 AND ESI, 0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  L00530afb: { // 0x530afb: 6683fe01 CMP SI, 1
    (void)integer::sub((s.si & 0xffffu),1u,16,flags);
  }
  L00530aff: { // 0x530aff: 7406 JZ 0x530b07
    if(integer::condition("JZ",flags)) goto L00530b07;
  }
  L00530b01: { // 0x530b01: 6683fe02 CMP SI, 2
    (void)integer::sub((s.si & 0xffffu),2u,16,flags);
  }
  L00530b05: { // 0x530b05: 7517 JNZ 0x530b1e
    if(integer::condition("JNZ",flags)) goto L00530b1e;
  }
  L00530b07: { // 0x530b07: 6a17 PUSH 0x17
    f.push(m,0x00000017u);
  }
  L00530b09: { // 0x530b09: ff15dc537800 CALL dword ptr [0x7853dc]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007853dcu)),5442319u); flags=s.arithmetic_flags;
  }
  L00530b0f: { // 0x530b0f: 83f801 CMP EAX, 1
    (void)integer::sub(s.ax,1u,32,flags);
  }
  L00530b12: { // 0x530b12: 750a JNZ 0x530b1e
    if(integer::condition("JNZ",flags)) goto L00530b1e;
  }
  L00530b14: { // 0x530b14: 664e DEC SI
    s.si = (s.si & 0xffff0000u) | ((integer::decrement((s.si & 0xffffu),16,flags)) & 0xffffu);
  }
  L00530b16: { // 0x530b16: 66f7de NEG SI
    s.si = (s.si & 0xffff0000u) | ((integer::sub(0u,(s.si & 0xffffu),16,flags)) & 0xffffu);
  }
  L00530b19: { // 0x530b19: 1bf6 SBB ESI, ESI
    s.si = integer::sub(s.si,s.si,32,flags,flags&integer::CF);
  }
  L00530b1b: { // 0x530b1b: 83c602 ADD ESI, 2
    s.si = integer::add(s.si,2u,32,flags);
  }
  L00530b1e: { // 0x530b1e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L00530b20: { // 0x530b20: 81e1ffff0000 AND ECX, 0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L00530b26: { // 0x530b26: e8051effff CALL 0x522930
    s.arithmetic_flags=flags; invoke(m,s,f,0x00522930u,5442347u); flags=s.arithmetic_flags;
  }
  L00530b2b: { // 0x530b2b: 66f7d8 NEG AX
    s.ax = with_ax(s.ax, integer::sub(0u,(s.ax & 0xffffu),16,flags));
  }
  L00530b2e: { // 0x530b2e: 1bc0 SBB EAX, EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L00530b30: { // 0x530b30: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00530b31: { // 0x530b31: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L00530b33: { // 0x530b33: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_00122930(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00522930: { // 0x522930: a1ec9ea300 MOV EAX, dword ptr [0xa39eec]
    s.ax = m.r32((0x00a39eecu));
  }
  L00522935: { // 0x522935: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00522937: { // 0x522937: 7508 JNZ 0x522941
    if(integer::condition("JNZ",flags)) goto L00522941;
  }
  L00522939: { // 0x522939: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0052293a: { // 0x52293a: ff15b4537800 CALL dword ptr [0x7853b4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007853b4u)),5384512u); flags=s.arithmetic_flags;
  }
  L00522940: { // 0x522940: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00522941: { // 0x522941: 81e1ff000000 AND ECX, 0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  L00522947: { // 0x522947: 668b044d109ca300 MOV AX, word ptr [ECX*2 + 0xa39c10]
    s.ax = with_ax(s.ax, m.r16(((s.cx * 2u)+0x00a39c10u)));
  }
  L0052294f: { // 0x52294f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002ce4b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce4b0: { // 0x6ce4b0: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006ce4b2: { // 0x6ce4b2: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7136440u); flags=s.arithmetic_flags;
  }
  L006ce4b8: { // 0x6ce4b8: 8b10 MOV EDX, dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L006ce4ba: { // 0x6ce4ba: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006ce4bc: { // Exact original indirect tail jump; same guest frame
    if(m.r32(s.dx+0xa4)!=0x45e3c0)throw std::domain_error("663 unproved tail target");
    s.arithmetic_flags=flags;f_0005e3c0(m,s,f,op);return;
  }
}
void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: { // Exact original indirect tail jump; same guest frame
    if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("663 unproved tail target");
    s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
  }
}
void f_0005e3c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0045e3c0: { // 0x45e3c0: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0045e3c2: { // 0x45e3c2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4305696u:f_0001b320(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 6081280u:f_001ccb00(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
case 4556096u:f_00058540(m,s,child,{});break;
case 5442288u:f_00130af0(m,s,child,{});break;
case 5384496u:f_00122930(m,s,child,{});break;
case 7136432u:f_002ce4b0(m,s,child,{});break;
case 7039248u:f_002b6910(m,s,child,{});break;
case 4580288u:f_0005e3c0(m,s,child,{});break;
default:throw std::domain_error("recovery663 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00449620(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00449620: { // 0x449620: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00449623: { // 0x449623: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00449624: { // 0x449624: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00449625: { // 0x449625: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00449626: { // 0x449626: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00449627: { // 0x449627: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00449629: { // 0x449629: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0044962d: { // 0x44962d: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  L0044962f: { // 0x44962f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00449630: { // 0x449630: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00449632: { // 0x449632: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),4494904u); flags=s.arithmetic_flags;
  }
  L00449638: { // 0x449638: 8b28 MOV EBP,dword ptr [EAX]
    s.bp = m.r32((s.ax));
  }
  L0044963a: { // 0x44963a: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L0044963c: { // 0x44963c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044963e: { // 0x44963e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00449640: { // 0x449640: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L00449644: { // 0x449644: ff9200010000 CALL dword ptr [EDX + 0x100]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000100u)),4494922u); flags=s.arithmetic_flags;
  }
  L0044964a: { // 0x44964a: 668b5c2416 MOV BX,word ptr [ESP + 0x16]
    s.bx = with_ax(s.bx, m.r16((f.sp+0x00000016u)));
  }
  L0044964f: { // 0x44964f: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00449651: { // 0x449651: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00449656: { // 0x449656: 668b06 MOV AX,word ptr [ESI]
    s.ax = with_ax(s.ax, m.r16((s.si)));
  }
  L00449659: { // 0x449659: 663dff7f CMP AX,0x7fff
    (void)integer::sub((s.ax & 0xffffu),0x00007fffu,16,flags);
  }
  L0044965d: { // 0x44965d: 7506 JNZ 0x00449665
    if(integer::condition("JNZ",flags)) goto L00449665;
  }
  L0044965f: { // 0x44965f: 66394602 CMP word ptr [ESI + 0x2],AX
    (void)integer::sub(m.r16((s.si+0x00000002u)),(s.ax & 0xffffu),16,flags);
  }
  L00449663: { // 0x449663: 744b JZ 0x004496b0
    if(integer::condition("JZ",flags)) goto L004496b0;
  }
  L00449665: { // 0x449665: 03c5 ADD EAX,EBP
    s.ax = integer::add(s.ax,s.bp,32,flags);
  }
  L00449667: { // 0x449667: 8d542418 LEA EDX,[ESP + 0x18]
    s.dx = (f.sp+0x00000018u);
  }
  L0044966b: { // 0x44966b: 6689442414 MOV word ptr [ESP + 0x14],AX
    m.w16((f.sp+0x00000014u), (s.ax & 0xffffu));
  }
  L00449670: { // 0x449670: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  L00449674: { // 0x449674: 6603c3 ADD AX,BX
    s.ax = with_ax(s.ax, integer::add((s.ax & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00449677: { // 0x449677: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00449678: { // 0x449678: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L0044967d: { // 0x44967d: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L00449681: { // 0x449681: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00449685: { // 0x449685: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0044968a: { // 0x44968a: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0044968d: { // 0x44968d: e86ebe0f00 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4494994u); flags=s.arithmetic_flags;
  }
  L00449692: { // 0x449692: 8b80e4000000 MOV EAX,dword ptr [EAX + 0xe4]
    s.ax = m.r32((s.ax+0x000000e4u));
  }
  L00449698: { // 0x449698: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044969a: { // 0x44969a: 74ba JZ 0x00449656
    if(integer::condition("JZ",flags)) goto L00449656;
  }
  L0044969c: { // 0x44969c: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0044969e: { // 0x44969e: 7509 JNZ 0x004496a9
    if(integer::condition("JNZ",flags)) goto L004496a9;
  }
  L004496a0: { // 0x4496a0: 8b4030 MOV EAX,dword ptr [EAX + 0x30]
    s.ax = m.r32((s.ax+0x00000030u));
  }
  L004496a3: { // 0x4496a3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004496a5: { // 0x4496a5: 75f5 JNZ 0x0044969c
    if(integer::condition("JNZ",flags)) goto L0044969c;
  }
  L004496a7: { // 0x4496a7: ebad JMP 0x00449656
    goto L00449656;
  }
  L004496a9: { // 0x4496a9: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L004496ae: { // 0x4496ae: eba6 JMP 0x00449656
    goto L00449656;
  }
  L004496b0: { // 0x4496b0: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L004496b4: { // 0x4496b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004496b5: { // 0x4496b5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004496b6: { // 0x4496b6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004496b7: { // 0x4496b7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004496b8: { // 0x4496b8: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L004496bb: { // 0x4496bb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006eb4d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006eb4d0: { // 0x6eb4d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006eb4d1: { // 0x6eb4d1: a0b88daa00 MOV AL,[0x00aa8db8]
    s.ax = with_al(s.ax, m.r8((0x00aa8db8u)));
  }
  L006eb4d6: { // 0x6eb4d6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006eb4d7: { // 0x6eb4d7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb4d9: { // 0x6eb4d9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006eb4da: { // 0x6eb4da: 7406 JZ 0x006eb4e2
    if(integer::condition("JZ",flags)) goto L006eb4e2;
  }
  L006eb4dc: { // 0x6eb4dc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006eb4dd: { // 0x6eb4dd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006eb4df: { // 0x6eb4df: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eb4e0: { // 0x6eb4e0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006eb4e1: { // 0x6eb4e1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006eb4e2: { // 0x6eb4e2: a1ec87a200 MOV EAX,[0x00a287ec]
    s.ax = m.r32((0x00a287ecu));
  }
  L006eb4e7: { // 0x6eb4e7: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006eb4ed: { // 0x6eb4ed: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006eb4ee: { // 0x6eb4ee: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006eb4ef: { // 0x6eb4ef: e8fc55e4ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7255284u); flags=s.arithmetic_flags;
  }
  L006eb4f4: { // 0x6eb4f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb4f6: { // 0x6eb4f6: 7519 JNZ 0x006eb511
    if(integer::condition("JNZ",flags)) goto L006eb511;
  }
  L006eb4f8: { // 0x6eb4f8: a1f087a200 MOV EAX,[0x00a287f0]
    s.ax = m.r32((0x00a287f0u));
  }
  L006eb4fd: { // 0x6eb4fd: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006eb503: { // 0x6eb503: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006eb504: { // 0x6eb504: e8e755e4ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7255305u); flags=s.arithmetic_flags;
  }
  L006eb509: { // 0x6eb509: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb50b: { // 0x6eb50b: 7504 JNZ 0x006eb511
    if(integer::condition("JNZ",flags)) goto L006eb511;
  }
  L006eb50d: { // 0x6eb50d: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006eb50f: { // 0x6eb50f: eb02 JMP 0x006eb513
    goto L006eb513;
  }
  L006eb511: { // 0x6eb511: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006eb513: { // 0x6eb513: a1f487a200 MOV EAX,[0x00a287f4]
    s.ax = m.r32((0x00a287f4u));
  }
  L006eb518: { // 0x6eb518: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006eb51e: { // 0x6eb51e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006eb51f: { // 0x6eb51f: e8cc55e4ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7255332u); flags=s.arithmetic_flags;
  }
  L006eb524: { // 0x6eb524: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb526: { // 0x6eb526: 7515 JNZ 0x006eb53d
    if(integer::condition("JNZ",flags)) goto L006eb53d;
  }
  L006eb528: { // 0x6eb528: a1f887a200 MOV EAX,[0x00a287f8]
    s.ax = m.r32((0x00a287f8u));
  }
  L006eb52d: { // 0x6eb52d: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006eb533: { // 0x6eb533: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006eb534: { // 0x6eb534: e8b755e4ff CALL 0x00530af0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530af0u,7255353u); flags=s.arithmetic_flags;
  }
  L006eb539: { // 0x6eb539: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb53b: { // 0x6eb53b: 7402 JZ 0x006eb53f
    if(integer::condition("JZ",flags)) goto L006eb53f;
  }
  L006eb53d: { // 0x6eb53d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006eb53f: { // 0x6eb53f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006eb541: { // 0x6eb541: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006eb542: { // 0x6eb542: 743f JZ 0x006eb583
    if(integer::condition("JZ",flags)) goto L006eb583;
  }
  L006eb544: { // 0x6eb544: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb546: { // 0x6eb546: 743b JZ 0x006eb583
    if(integer::condition("JZ",flags)) goto L006eb583;
  }
  L006eb548: { // 0x6eb548: 8b3db088a200 MOV EDI,dword ptr [0x00a288b0]
    s.di = m.r32((0x00a288b0u));
  }
  L006eb54e: { // 0x6eb54e: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006eb550: { // 0x6eb550: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006eb552: { // 0x6eb552: 7e29 JLE 0x006eb57d
    if(integer::condition("JLE",flags)) goto L006eb57d;
  }
  L006eb554: { // 0x6eb554: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L006eb559: { // 0x6eb559: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L006eb55c: { // 0x6eb55c: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006eb55e: { // 0x6eb55e: 7418 JZ 0x006eb578
    if(integer::condition("JZ",flags)) goto L006eb578;
  }
  L006eb560: { // 0x6eb560: 8a5114 MOV DL,byte ptr [ECX + 0x14]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000014u)));
  }
  L006eb563: { // 0x6eb563: 80e201 AND DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags));
  }
  L006eb566: { // 0x6eb566: 8854240b MOV byte ptr [ESP + 0xb],DL
    m.w8((f.sp+0x0000000bu), (s.dx & 0xffu));
  }
  L006eb56a: { // 0x6eb56a: 740c JZ 0x006eb578
    if(integer::condition("JZ",flags)) goto L006eb578;
  }
  L006eb56c: { // 0x6eb56c: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006eb56e: { // 0x6eb56e: ff904c040000 CALL dword ptr [EAX + 0x44c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000044cu)),7255412u); flags=s.arithmetic_flags;
  }
  L006eb574: { // 0x6eb574: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006eb576: { // 0x6eb576: 740b JZ 0x006eb583
    if(integer::condition("JZ",flags)) goto L006eb583;
  }
  L006eb578: { // 0x6eb578: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L006eb579: { // 0x6eb579: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  L006eb57b: { // 0x6eb57b: 7cd7 JL 0x006eb554
    if(integer::condition("JL",flags)) goto L006eb554;
  }
  L006eb57d: { // 0x6eb57d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006eb57e: { // 0x6eb57e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006eb580: { // 0x6eb580: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eb581: { // 0x6eb581: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006eb582: { // 0x6eb582: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006eb583: { // 0x6eb583: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006eb584: { // 0x6eb584: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006eb586: { // 0x6eb586: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006eb587: { // 0x6eb587: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L006eb588: { // 0x6eb588: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
