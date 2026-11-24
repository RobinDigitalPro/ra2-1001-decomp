#include "recovered/recovery_b797_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b797 {
namespace {
void f_00005fe0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00005fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00405fe0: { // 0x405fe0: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  L00405fe5: { // 0x405fe5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00405fe6: { // 0x405fe6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00405fe8: { // 0x405fe8: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00405fe9: { // 0x405fe9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00405fea: { // 0x405fea: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00405fec: { // 0x405fec: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00405fee: { // 0x405fee: 746c JZ 0x0040605c
    if(integer::condition("JZ",flags)) goto L0040605c;
  }
  L00405ff0: { // 0x405ff0: 817f0cec928100 CMP dword ptr [EDI + 0xc],0x8192ec
    (void)integer::sub(m.r32((s.di+0x0000000cu)),0x008192ecu,32,flags);
  }
  L00405ff7: { // 0x405ff7: 7563 JNZ 0x0040605c
    if(integer::condition("JNZ",flags)) goto L0040605c;
  }
  L00405ff9: { // 0x405ff9: 8b37 MOV ESI,dword ptr [EDI]
    s.si = m.r32((s.di));
  }
  L00405ffb: { // 0x405ffb: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  L00405ffd: { // 0x405ffd: 745d JZ 0x0040605c
    if(integer::condition("JZ",flags)) goto L0040605c;
  }
  L00405fff: { // 0x405fff: 8b4708 MOV EAX,dword ptr [EDI + 0x8]
    s.ax = m.r32((s.di+0x00000008u));
  }
  L00406002: { // 0x406002: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  L00406005: { // 0x406005: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00406007: { // 0x406007: 7551 JNZ 0x0040605a
    if(integer::condition("JNZ",flags)) goto L0040605a;
  }
  L00406009: { // 0x406009: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0040600c: { // 0x40600c: 8b8638010000 MOV EAX,dword ptr [ESI + 0x138]
    s.ax = m.r32((s.si+0x00000138u));
  }
  L00406012: { // 0x406012: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L00406014: { // 0x406014: 7544 JNZ 0x0040605a
    if(integer::condition("JNZ",flags)) goto L0040605a;
  }
  L00406016: { // 0x406016: f6461820 TEST byte ptr [ESI + 0x18],0x20
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000020u),8,flags);
  }
  L0040601a: { // 0x40601a: 753e JNZ 0x0040605a
    if(integer::condition("JNZ",flags)) goto L0040605a;
  }
  L0040601c: { // 0x40601c: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00406022: { // 0x406022: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00406024: { // 0x406024: 742c JZ 0x00406052
    if(integer::condition("JZ",flags)) goto L00406052;
  }
  L00406026: { // 0x406026: 3bb0c0000000 CMP ESI,dword ptr [EAX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.ax+0x000000c0u)),32,flags);
  }
  L0040602c: { // 0x40602c: 7524 JNZ 0x00406052
    if(integer::condition("JNZ",flags)) goto L00406052;
  }
  L0040602e: { // 0x40602e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00406030: { // 0x406030: e86bc6ffff CALL 0x004026a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026a0u,4218933u); flags=s.arithmetic_flags;
  }
  L00406035: { // 0x406035: 8b5618 MOV EDX,dword ptr [ESI + 0x18]
    s.dx = m.r32((s.si+0x00000018u));
  }
  L00406038: { // 0x406038: 83ca60 OR EDX,0x60
    s.dx = integer::logical((s.dx)|(0x00000060u),32,flags);
  }
  L0040603b: { // 0x40603b: 895618 MOV dword ptr [ESI + 0x18],EDX
    m.w32((s.si+0x00000018u), s.dx);
  }
  L0040603e: { // 0x40603e: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00406044: { // 0x406044: e867c6ffff CALL 0x004026b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026b0u,4218953u); flags=s.arithmetic_flags;
  }
  L00406049: { // 0x406049: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L0040604b: { // 0x40604b: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L0040604e: { // 0x40604e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0040604f: { // 0x40604f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00406050: { // 0x406050: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00406051: { // 0x406051: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00406052: { // 0x406052: 8b4618 MOV EAX,dword ptr [ESI + 0x18]
    s.ax = m.r32((s.si+0x00000018u));
  }
  L00406055: { // 0x406055: 0c60 OR AL,0x60
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000060u),8,flags));
  }
  L00406057: { // 0x406057: 894618 MOV dword ptr [ESI + 0x18],EAX
    m.w32((s.si+0x00000018u), s.ax);
  }
  L0040605a: { // 0x40605a: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L0040605c: { // 0x40605c: 895f08 MOV dword ptr [EDI + 0x8],EBX
    m.w32((s.di+0x00000008u), s.bx);
  }
  L0040605f: { // 0x40605f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00406060: { // 0x406060: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00406061: { // 0x406061: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00406062: { // 0x406062: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4218848u:f_00005fe0(m,s,child,{});break;
default:throw std::domain_error("recovery797 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00435bf0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00435bf0: { // 0x435bf0: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00435bf3: { // 0x435bf3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00435bf4: { // 0x435bf4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00435bf5: { // 0x435bf5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00435bf6: { // 0x435bf6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00435bf8: { // 0x435bf8: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00435bfa: { // 0x435bfa: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00435bfb: { // 0x435bfb: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L00435bfe: { // 0x435bfe: 3bc5 CMP EAX,EBP
    (void)integer::sub(s.ax,s.bp,32,flags);
  }
  L00435c00: { // 0x435c00: 0f8462020000 JZ 0x00435e68
    if(integer::condition("JZ",flags)) goto L00435e68;
  }
  L00435c06: { // 0x435c06: 8a4e58 MOV CL,byte ptr [ESI + 0x58]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000058u)));
  }
  L00435c09: { // 0x435c09: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00435c0b: { // 0x435c0b: 0f8557020000 JNZ 0x00435e68
    if(integer::condition("JNZ",flags)) goto L00435e68;
  }
  L00435c11: { // 0x435c11: 8a4876 MOV CL,byte ptr [EAX + 0x76]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000076u)));
  }
  L00435c14: { // 0x435c14: 896838 MOV dword ptr [EAX + 0x38],EBP
    m.w32((s.ax+0x00000038u), s.bp);
  }
  L00435c17: { // 0x435c17: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L00435c19: { // 0x435c19: 7410 JZ 0x00435c2b
    if(integer::condition("JZ",flags)) goto L00435c2b;
  }
  L00435c1b: { // 0x435c1b: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  L00435c1e: { // 0x435c1e: c6406800 MOV byte ptr [EAX + 0x68],0x0
    m.w8((s.ax+0x00000068u), 0x00000000u);
  }
  L00435c22: { // 0x435c22: c6465801 MOV byte ptr [ESI + 0x58],0x1
    m.w8((s.si+0x00000058u), 0x00000001u);
  }
  L00435c26: { // 0x435c26: e929020000 JMP 0x00435e54
    goto L00435e54;
  }
  L00435c2b: { // 0x435c2b: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  L00435c2e: { // 0x435c2e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00435c30: { // 0x435c30: c6416800 MOV byte ptr [ECX + 0x68],0x0
    m.w8((s.cx+0x00000068u), 0x00000000u);
  }
  L00435c34: { // 0x435c34: 8b562c MOV EDX,dword ptr [ESI + 0x2c]
    s.dx = m.r32((s.si+0x0000002cu));
  }
  L00435c37: { // 0x435c37: 81c288000000 ADD EDX,0x88
    s.dx = integer::add(s.dx,0x00000088u,32,flags);
  }
  L00435c3d: { // 0x435c3d: c6465801 MOV byte ptr [ESI + 0x58],0x1
    m.w8((s.si+0x00000058u), 0x00000001u);
  }
  L00435c41: { // 0x435c41: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L00435c43: { // 0x435c43: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00435c47: { // 0x435c47: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00435c4c: { // 0x435c4c: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L00435c4f: { // 0x435c4f: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  L00435c53: { // 0x435c53: 8b5208 MOV EDX,dword ptr [EDX + 0x8]
    s.dx = m.r32((s.dx+0x00000008u));
  }
  L00435c56: { // 0x435c56: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  L00435c5a: { // 0x435c5a: 8b88880c0000 MOV ECX,dword ptr [EAX + 0xc88]
    s.cx = m.r32((s.ax+0x00000c88u));
  }
  L00435c60: { // 0x435c60: 8b5624 MOV EDX,dword ptr [ESI + 0x24]
    s.dx = m.r32((s.si+0x00000024u));
  }
  L00435c63: { // 0x435c63: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435c64: { // 0x435c64: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435c65: { // 0x435c65: 8b908c0c0000 MOV EDX,dword ptr [EAX + 0xc8c]
    s.dx = m.r32((s.ax+0x00000c8cu));
  }
  L00435c6b: { // 0x435c6b: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L00435c6f: { // 0x435c6f: e84c820400 CALL 0x0047dec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047dec0u,4414580u); flags=s.arithmetic_flags;
  }
  L00435c74: { // 0x435c74: 68a8010000 PUSH 0x1a8
    f.push(m,0x000001a8u);
  }
  L00435c79: { // 0x435c79: e8d97c3300 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4414590u); flags=s.arithmetic_flags;
  }
  L00435c7e: { // 0x435c7e: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00435c80: { // 0x435c80: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00435c83: { // 0x435c83: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L00435c85: { // 0x435c85: 0f8497000000 JZ 0x00435d22
    if(integer::condition("JZ",flags)) goto L00435d22;
  }
  L00435c8b: { // 0x435c8b: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00435c8f: { // 0x435c8f: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00435c93: { // 0x435c93: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435c94: { // 0x435c94: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00435c9a: { // 0x435c9a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435c9b: { // 0x435c9b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435c9d: { // 0x435c9d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00435ca2: { // 0x435ca2: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00435ca5: { // 0x435ca5: 6689442418 MOV word ptr [ESP + 0x18],AX
    m.w16((f.sp+0x00000018u), (s.ax & 0xffffu));
  }
  L00435caa: { // 0x435caa: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00435cae: { // 0x435cae: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00435caf: { // 0x435caf: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L00435cb5: { // 0x435cb5: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00435cb7: { // 0x435cb7: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L00435cba: { // 0x435cba: 668944241a MOV word ptr [ESP + 0x1a],AX
    m.w16((f.sp+0x0000001au), (s.ax & 0xffffu));
  }
  L00435cbf: { // 0x435cbf: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00435cc3: { // 0x435cc3: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00435cc7: { // 0x435cc7: e834f81000 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4414668u); flags=s.arithmetic_flags;
  }
  L00435ccc: { // 0x435ccc: 8b98ec000000 MOV EBX,dword ptr [EAX + 0xec]
    s.bx = m.r32((s.ax+0x000000ecu));
  }
  L00435cd2: { // 0x435cd2: 8b44242c MOV EAX,dword ptr [ESP + 0x2c]
    s.ax = m.r32((f.sp+0x0000002cu));
  }
  L00435cd6: { // 0x435cd6: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00435cda: { // 0x435cda: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L00435cdd: { // 0x435cdd: 8bd4 MOV EDX,ESP
    s.dx = f.sp;
  }
  L00435cdf: { // 0x435cdf: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L00435ce1: { // 0x435ce1: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00435ce5: { // 0x435ce5: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L00435ce8: { // 0x435ce8: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L00435ceb: { // 0x435ceb: e8f09b0400 CALL 0x0047f8e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047f8e0u,4414704u); flags=s.arithmetic_flags;
  }
  L00435cf0: { // 0x435cf0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435cf1: { // 0x435cf1: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L00435cf6: { // 0x435cf6: 6800260000 PUSH 0x2600
    f.push(m,0x00002600u);
  }
  L00435cfb: { // 0x435cfb: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00435cfd: { // 0x435cfd: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L00435d01: { // 0x435d01: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00435d02: { // 0x435d02: 8d54243c LEA EDX,[ESP + 0x3c]
    s.dx = (f.sp+0x0000003cu);
  }
  L00435d06: { // 0x435d06: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435d07: { // 0x435d07: 8b888c0c0000 MOV ECX,dword ptr [EAX + 0xc8c]
    s.cx = m.r32((s.ax+0x00000c8cu));
  }
  L00435d0d: { // 0x435d0d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435d0e: { // 0x435d0e: 8b90880c0000 MOV EDX,dword ptr [EAX + 0xc88]
    s.dx = m.r32((s.ax+0x00000c88u));
  }
  L00435d14: { // 0x435d14: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00435d15: { // 0x435d15: e8d6930400 CALL 0x0047f0f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047f0f0u,4414746u); flags=s.arithmetic_flags;
  }
  L00435d1a: { // 0x435d1a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435d1b: { // 0x435d1b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00435d1d: { // 0x435d1d: e8eea3feff CALL 0x00420110
    s.arithmetic_flags=flags; invoke(m,s,f,0x00420110u,4414754u); flags=s.arithmetic_flags;
  }
  L00435d22: { // 0x435d22: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  L00435d25: { // 0x435d25: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L00435d27: { // 0x435d27: 0f8427010000 JZ 0x00435e54
    if(integer::condition("JZ",flags)) goto L00435e54;
  }
  L00435d2d: { // 0x435d2d: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00435d2f: { // 0x435d2f: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),4414770u); flags=s.arithmetic_flags;
  }
  L00435d32: { // 0x435d32: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L00435d35: { // 0x435d35: 0f8519010000 JNZ 0x00435e54
    if(integer::condition("JNZ",flags)) goto L00435e54;
  }
  L00435d3b: { // 0x435d3b: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  L00435d3e: { // 0x435d3e: 8b9118040000 MOV EDX,dword ptr [ECX + 0x418]
    s.dx = m.r32((s.cx+0x00000418u));
  }
  L00435d44: { // 0x435d44: 8a8250130000 MOV AL,byte ptr [EDX + 0x1350]
    s.ax = with_al(s.ax, m.r8((s.dx+0x00001350u)));
  }
  L00435d4a: { // 0x435d4a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00435d4c: { // 0x435d4c: 0f8402010000 JZ 0x00435e54
    if(integer::condition("JZ",flags)) goto L00435e54;
  }
  L00435d52: { // 0x435d52: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00435d57: { // 0x435d57: bbfeffffff MOV EBX,0xfffffffe
    s.bx = 0xfffffffeu;
  }
  L00435d5c: { // 0x435d5c: bdfeffffff MOV EBP,0xfffffffe
    s.bp = 0xfffffffeu;
  }
  L00435d61: { // 0x435d61: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  L00435d64: { // 0x435d64: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L00435d68: { // 0x435d68: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00435d69: { // 0x435d69: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00435d6b: { // 0x435d6b: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),4414833u); flags=s.arithmetic_flags;
  }
  L00435d71: { // 0x435d71: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L00435d75: { // 0x435d75: 668bcd MOV CX,BP
    s.cx = with_ax(s.cx, (s.bp & 0xffffu));
  }
  L00435d78: { // 0x435d78: 660308 ADD CX,word ptr [EAX]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.ax)),16,flags));
  }
  L00435d7b: { // 0x435d7b: 6603d3 ADD DX,BX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00435d7e: { // 0x435d7e: 6689542416 MOV word ptr [ESP + 0x16],DX
    m.w16((f.sp+0x00000016u), (s.dx & 0xffffu));
  }
  L00435d83: { // 0x435d83: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L00435d88: { // 0x435d88: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00435d8c: { // 0x435d8c: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00435d90: { // 0x435d90: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00435d94: { // 0x435d94: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435d95: { // 0x435d95: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00435d9a: { // 0x435d9a: e861f71000 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4414879u); flags=s.arithmetic_flags;
  }
  L00435d9f: { // 0x435d9f: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  L00435da2: { // 0x435da2: 8b7838 MOV EDI,dword ptr [EAX + 0x38]
    s.di = m.r32((s.ax+0x00000038u));
  }
  L00435da5: { // 0x435da5: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00435da9: { // 0x435da9: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00435dab: { // 0x435dab: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435dac: { // 0x435dac: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4414898u); flags=s.arithmetic_flags;
  }
  L00435db2: { // 0x435db2: 668b5002 MOV DX,word ptr [EAX + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x00000002u)));
  }
  L00435db6: { // 0x435db6: 668bcd MOV CX,BP
    s.cx = with_ax(s.cx, (s.bp & 0xffffu));
  }
  L00435db9: { // 0x435db9: 660308 ADD CX,word ptr [EAX]
    s.cx = with_ax(s.cx, integer::add((s.cx & 0xffffu),m.r16((s.ax)),16,flags));
  }
  L00435dbc: { // 0x435dbc: 6603d3 ADD DX,BX
    s.dx = with_ax(s.dx, integer::add((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L00435dbf: { // 0x435dbf: 668954241a MOV word ptr [ESP + 0x1a],DX
    m.w16((f.sp+0x0000001au), (s.dx & 0xffffu));
  }
  L00435dc4: { // 0x435dc4: 66894c2418 MOV word ptr [ESP + 0x18],CX
    m.w16((f.sp+0x00000018u), (s.cx & 0xffffu));
  }
  L00435dc9: { // 0x435dc9: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00435dcd: { // 0x435dcd: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L00435dd1: { // 0x435dd1: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00435dd5: { // 0x435dd5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00435dd6: { // 0x435dd6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00435ddb: { // 0x435ddb: e820f71000 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,4414944u); flags=s.arithmetic_flags;
  }
  L00435de0: { // 0x435de0: 8b0da047a500 MOV ECX,dword ptr [0x00a547a0]
    s.cx = m.r32((0x00a547a0u));
  }
  L00435de6: { // 0x435de6: 8b4044 MOV EAX,dword ptr [EAX + 0x44]
    s.ax = m.r32((s.ax+0x00000044u));
  }
  L00435de9: { // 0x435de9: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00435deb: { // 0x435deb: 7c07 JL 0x00435df4
    if(integer::condition("JL",flags)) goto L00435df4;
  }
  L00435ded: { // 0x435ded: 83c110 ADD ECX,0x10
    s.cx = integer::add(s.cx,0x00000010u,32,flags);
  }
  L00435df0: { // 0x435df0: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00435df2: { // 0x435df2: 7c0a JL 0x00435dfe
    if(integer::condition("JL",flags)) goto L00435dfe;
  }
  L00435df4: { // 0x435df4: 83f84a CMP EAX,0x4a
    (void)integer::sub(s.ax,0x0000004au,32,flags);
  }
  L00435df7: { // 0x435df7: 7c0a JL 0x00435e03
    if(integer::condition("JL",flags)) goto L00435e03;
  }
  L00435df9: { // 0x435df9: 83f865 CMP EAX,0x65
    (void)integer::sub(s.ax,0x00000065u,32,flags);
  }
  L00435dfc: { // 0x435dfc: 7f05 JG 0x00435e03
    if(integer::condition("JG",flags)) goto L00435e03;
  }
  L00435dfe: { // 0x435dfe: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L00435e03: { // 0x435e03: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00435e04: { // 0x435e04: 83fd03 CMP EBP,0x3
    (void)integer::sub(s.bp,0x00000003u,32,flags);
  }
  L00435e07: { // 0x435e07: 0f8c54ffffff JL 0x00435d61
    if(integer::condition("JL",flags)) goto L00435d61;
  }
  L00435e0d: { // 0x435e0d: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00435e0e: { // 0x435e0e: 83fb03 CMP EBX,0x3
    (void)integer::sub(s.bx,0x00000003u,32,flags);
  }
  L00435e11: { // 0x435e11: 0f8c45ffffff JL 0x00435d5c
    if(integer::condition("JL",flags)) goto L00435d5c;
  }
  L00435e17: { // 0x435e17: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00435e1b: { // 0x435e1b: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  L00435e1e: { // 0x435e1e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00435e20: { // 0x435e20: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00435e22: { // 0x435e22: 7418 JZ 0x00435e3c
    if(integer::condition("JZ",flags)) goto L00435e3c;
  }
  L00435e24: { // 0x435e24: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00435e28: { // 0x435e28: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435e29: { // 0x435e29: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4415023u); flags=s.arithmetic_flags;
  }
  L00435e2f: { // 0x435e2f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435e30: { // 0x435e30: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00435e35: { // 0x435e35: e8e6e61100 CALL 0x00554520
    s.arithmetic_flags=flags; invoke(m,s,f,0x00554520u,4415034u); flags=s.arithmetic_flags;
  }
  L00435e3a: { // 0x435e3a: eb16 JMP 0x00435e52
    goto L00435e52;
  }
  L00435e3c: { // 0x435e3c: 8d442428 LEA EAX,[ESP + 0x28]
    s.ax = (f.sp+0x00000028u);
  }
  L00435e40: { // 0x435e40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435e41: { // 0x435e41: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),4415047u); flags=s.arithmetic_flags;
  }
  L00435e47: { // 0x435e47: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00435e48: { // 0x435e48: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00435e4d: { // 0x435e4d: e85edb1100 CALL 0x005539b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005539b0u,4415058u); flags=s.arithmetic_flags;
  }
  L00435e52: { // 0x435e52: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00435e54: { // 0x435e54: 8d4e3c LEA ECX,[ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  L00435e57: { // 0x435e57: 896e24 MOV dword ptr [ESI + 0x24],EBP
    m.w32((s.si+0x00000024u), s.bp);
  }
  L00435e5a: { // 0x435e5a: 896e2c MOV dword ptr [ESI + 0x2c],EBP
    m.w32((s.si+0x0000002cu), s.bp);
  }
  L00435e5d: { // 0x435e5d: 896e28 MOV dword ptr [ESI + 0x28],EBP
    m.w32((s.si+0x00000028u), s.bp);
  }
  L00435e60: { // 0x435e60: e87b01fdff CALL 0x00405fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00405fe0u,4415077u); flags=s.arithmetic_flags;
  }
  L00435e65: { // 0x435e65: 896e54 MOV dword ptr [ESI + 0x54],EBP
    m.w32((s.si+0x00000054u), s.bp);
  }
  L00435e68: { // 0x435e68: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00435e69: { // 0x435e69: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00435e6a: { // 0x435e6a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00435e6b: { // 0x435e6b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00435e6c: { // 0x435e6c: 83c428 ADD ESP,0x28
    f.sp = integer::add(f.sp,0x00000028u,32,flags);
  }
  L00435e6f: { // 0x435e6f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
