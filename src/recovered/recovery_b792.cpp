#include "recovered/recovery_b792_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b792 {
namespace {
void f_000f47b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000f47b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004f47b0: { // 0x4f47b0: a1c855a200 MOV EAX, dword ptr [0xa255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  L004f47b5: { // 0x4f47b5: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004f47b7: { // 0x4f47b7: 751d JNZ 0x4f47d6
    if(integer::condition("JNZ",flags)) goto L004f47d6;
  }
  L004f47b9: { // 0x4f47b9: 8a8134010000 MOV AL, byte ptr [ECX + 0x134]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000134u)));
  }
  L004f47bf: { // 0x4f47bf: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47c1: { // 0x4f47c1: 750d JNZ 0x4f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47c3: { // 0x4f47c3: 8a8135010000 MOV AL, byte ptr [ECX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000135u)));
  }
  L004f47c9: { // 0x4f47c9: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004f47cb: { // 0x4f47cb: 7503 JNZ 0x4f47d0
    if(integer::condition("JNZ",flags)) goto L004f47d0;
  }
  L004f47cd: { // 0x4f47cd: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47cf: { // 0x4f47cf: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d0: { // 0x4f47d0: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L004f47d5: { // 0x4f47d5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L004f47d6: { // 0x4f47d6: 8b15e4e0a100 MOV EDX, dword ptr [0xa1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L004f47dc: { // 0x4f47dc: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L004f47de: { // 0x4f47de: 3bca CMP ECX, EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L004f47e0: { // 0x4f47e0: 0f94c0 SETE AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f47e3: { // 0x4f47e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5195696u:f_000f47b0(m,s,child,{});break;
default:throw std::domain_error("recovery792 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0044d0d0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d0d0: { // 0x44d0d0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044d0d1: { // 0x44d0d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d0d2: { // 0x44d0d2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0044d0d4: { // 0x44d0d4: 8a8630050000 MOV AL,byte ptr [ESI + 0x530]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000530u)));
  }
  L0044d0da: { // 0x44d0da: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d0dc: { // 0x44d0dc: 0f8538010000 JNZ 0x0044d21a
    if(integer::condition("JNZ",flags)) goto L0044d21a;
  }
  L0044d0e2: { // 0x44d0e2: 8b86fc030000 MOV EAX,dword ptr [ESI + 0x3fc]
    s.ax = m.r32((s.si+0x000003fcu));
  }
  L0044d0e8: { // 0x44d0e8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044d0ea: { // 0x44d0ea: 0f852a010000 JNZ 0x0044d21a
    if(integer::condition("JNZ",flags)) goto L0044d21a;
  }
  L0044d0f0: { // 0x44d0f0: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d0f6: { // 0x44d0f6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0044d0f8: { // 0x44d0f8: 888630050000 MOV byte ptr [ESI + 0x530],AL
    m.w8((s.si+0x00000530u), (s.ax & 0xffu));
  }
  L0044d0fe: { // 0x44d0fe: 884675 MOV byte ptr [ESI + 0x75],AL
    m.w8((s.si+0x00000075u), (s.ax & 0xffu));
  }
  L0044d101: { // 0x44d101: 888168560000 MOV byte ptr [ECX + 0x5668],AL
    m.w8((s.cx+0x00005668u), (s.ax & 0xffu));
  }
  L0044d107: { // 0x44d107: 8b96b4010000 MOV EDX,dword ptr [ESI + 0x1b4]
    s.dx = m.r32((s.si+0x000001b4u));
  }
  L0044d10d: { // 0x44d10d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d10e: { // 0x44d10e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d10f: { // 0x44d10f: 888269560000 MOV byte ptr [EDX + 0x5669],AL
    m.w8((s.dx+0x00005669u), (s.ax & 0xffu));
  }
  L0044d115: { // 0x44d115: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d11b: { // 0x44d11b: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d11d: { // 0x44d11d: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d11e: { // 0x44d11e: 888144010000 MOV byte ptr [ECX + 0x144],AL
    m.w8((s.cx+0x00000144u), (s.ax & 0xffu));
  }
  L0044d124: { // 0x44d124: 8baeb4010000 MOV EBP,dword ptr [ESI + 0x1b4]
    s.bp = m.r32((s.si+0x000001b4u));
  }
  L0044d12a: { // 0x44d12a: 8886ba050000 MOV byte ptr [ESI + 0x5ba],AL
    m.w8((s.si+0x000005bau), (s.ax & 0xffu));
  }
  L0044d130: { // 0x44d130: 8b4578 MOV EAX,dword ptr [EBP + 0x78]
    s.ax = m.r32((s.bp+0x00000078u));
  }
  L0044d133: { // 0x44d133: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0044d135: { // 0x44d135: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0044d139: { // 0x44d139: 7e3d JLE 0x0044d178
    if(integer::condition("JLE",flags)) goto L0044d178;
  }
  L0044d13b: { // 0x44d13b: 8b556c MOV EDX,dword ptr [EBP + 0x6c]
    s.dx = m.r32((s.bp+0x0000006cu));
  }
  L0044d13e: { // 0x44d13e: 8b3c9a MOV EDI,dword ptr [EDX + EBX*0x4]
    s.di = m.r32((s.dx+(s.bx * 0x00000004u)));
  }
  L0044d141: { // 0x44d141: 8a4f7d MOV CL,byte ptr [EDI + 0x7d]
    s.cx = with_al(s.cx, m.r8((s.di+0x0000007du)));
  }
  L0044d144: { // 0x44d144: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d146: { // 0x44d146: 742b JZ 0x0044d173
    if(integer::condition("JZ",flags)) goto L0044d173;
  }
  L0044d148: { // 0x44d148: 8a4f76 MOV CL,byte ptr [EDI + 0x76]
    s.cx = with_al(s.cx, m.r8((s.di+0x00000076u)));
  }
  L0044d14b: { // 0x44d14b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d14d: { // 0x44d14d: 7524 JNZ 0x0044d173
    if(integer::condition("JNZ",flags)) goto L0044d173;
  }
  L0044d14f: { // 0x44d14f: 8b8718040000 MOV EAX,dword ptr [EDI + 0x418]
    s.ax = m.r32((s.di+0x00000418u));
  }
  L0044d155: { // 0x44d155: 8a8858130000 MOV CL,byte ptr [EAX + 0x1358]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001358u)));
  }
  L0044d15b: { // 0x44d15b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0044d15d: { // 0x44d15d: 7409 JZ 0x0044d168
    if(integer::condition("JZ",flags)) goto L0044d168;
  }
  L0044d15f: { // 0x44d15f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044d161: { // 0x44d161: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044d163: { // 0x44d163: e828110000 CALL 0x0044e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4510056u); flags=s.arithmetic_flags;
  }
  L0044d168: { // 0x44d168: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0044d16a: { // 0x44d16a: e861240000 CALL 0x0044f5d0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044f5d0u,4510063u); flags=s.arithmetic_flags;
  }
  L0044d16f: { // 0x44d16f: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L0044d173: { // 0x44d173: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d174: { // 0x44d174: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d176: { // 0x44d176: 7cc3 JL 0x0044d13b
    if(integer::condition("JL",flags)) goto L0044d13b;
  }
  L0044d178: { // 0x44d178: 8b8ee8040000 MOV ECX,dword ptr [ESI + 0x4e8]
    s.cx = m.r32((s.si+0x000004e8u));
  }
  L0044d17e: { // 0x44d17e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d180: { // 0x44d180: 7407 JZ 0x0044d189
    if(integer::condition("JZ",flags)) goto L0044d189;
  }
  L0044d182: { // 0x44d182: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044d184: { // 0x44d184: e897850e00 CALL 0x00535720
    s.arithmetic_flags=flags; invoke(m,s,f,0x00535720u,4510089u); flags=s.arithmetic_flags;
  }
  L0044d189: { // 0x44d189: 8b8e18040000 MOV ECX,dword ptr [ESI + 0x418]
    s.cx = m.r32((s.si+0x00000418u));
  }
  L0044d18f: { // 0x44d18f: 8a8158130000 MOV AL,byte ptr [ECX + 0x1358]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001358u)));
  }
  L0044d195: { // 0x44d195: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d197: { // 0x44d197: 7409 JZ 0x0044d1a2
    if(integer::condition("JZ",flags)) goto L0044d1a2;
  }
  L0044d199: { // 0x44d199: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044d19b: { // 0x44d19b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0044d19d: { // 0x44d19d: e8ee100000 CALL 0x0044e290
    s.arithmetic_flags=flags; invoke(m,s,f,0x0044e290u,4510114u); flags=s.arithmetic_flags;
  }
  L0044d1a2: { // 0x44d1a2: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0044d1a4: { // 0x44d1a4: 8d9e54040000 LEA EBX,[ESI + 0x454]
    s.bx = (s.si+0x00000454u);
  }
  L0044d1aa: { // 0x44d1aa: 8b9618040000 MOV EDX,dword ptr [ESI + 0x418]
    s.dx = m.r32((s.si+0x00000418u));
  }
  L0044d1b0: { // 0x44d1b0: 8a8417140d0000 MOV AL,byte ptr [EDI + EDX*0x1 + 0xd14]
    s.ax = with_al(s.ax, m.r8((s.di+(s.dx * 0x00000001u)+0x00000d14u)));
  }
  L0044d1b7: { // 0x44d1b7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d1b9: { // 0x44d1b9: 740b JZ 0x0044d1c6
    if(integer::condition("JZ",flags)) goto L0044d1c6;
  }
  L0044d1bb: { // 0x44d1bb: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  L0044d1bd: { // 0x44d1bd: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d1bf: { // 0x44d1bf: 7405 JZ 0x0044d1c6
    if(integer::condition("JZ",flags)) goto L0044d1c6;
  }
  L0044d1c1: { // 0x44d1c1: e85a5afdff CALL 0x00422c20
    s.arithmetic_flags=flags; invoke(m,s,f,0x00422c20u,4510150u); flags=s.arithmetic_flags;
  }
  L0044d1c6: { // 0x44d1c6: 83c744 ADD EDI,0x44
    s.di = integer::add(s.di,0x00000044u,32,flags);
  }
  L0044d1c9: { // 0x44d1c9: 83c304 ADD EBX,0x4
    s.bx = integer::add(s.bx,0x00000004u,32,flags);
  }
  L0044d1cc: { // 0x44d1cc: 81ffc8040000 CMP EDI,0x4c8
    (void)integer::sub(s.di,0x000004c8u,32,flags);
  }
  L0044d1d2: { // 0x44d1d2: 7cd6 JL 0x0044d1aa
    if(integer::condition("JL",flags)) goto L0044d1aa;
  }
  L0044d1d4: { // 0x44d1d4: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0044d1da: { // 0x44d1da: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d1db: { // 0x44d1db: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d1dc: { // 0x44d1dc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d1dd: { // 0x44d1dd: 8b88440c0000 MOV ECX,dword ptr [EAX + 0xc44]
    s.cx = m.r32((s.ax+0x00000c44u));
  }
  L0044d1e3: { // 0x44d1e3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d1e5: { // 0x44d1e5: 7415 JZ 0x0044d1fc
    if(integer::condition("JZ",flags)) goto L0044d1fc;
  }
  L0044d1e7: { // 0x44d1e7: 8a80da0a0000 MOV AL,byte ptr [EAX + 0xada]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000adau)));
  }
  L0044d1ed: { // 0x44d1ed: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0044d1ef: { // 0x44d1ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044d1f0: { // 0x44d1f0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0044d1f1: { // 0x44d1f1: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d1f7: { // 0x44d1f7: e874540a00 CALL 0x004f2670
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f2670u,4510204u); flags=s.arithmetic_flags;
  }
  L0044d1fc: { // 0x44d1fc: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L0044d202: { // 0x44d202: e8a9750a00 CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,4510215u); flags=s.arithmetic_flags;
  }
  L0044d207: { // 0x44d207: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d209: { // 0x44d209: 740f JZ 0x0044d21a
    if(integer::condition("JZ",flags)) goto L0044d21a;
  }
  L0044d20b: { // 0x44d20b: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L0044d20d: { // 0x44d20d: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L0044d210: { // 0x44d210: b9eca97b00 MOV ECX,0x7ba9ec
    s.cx = 0x007ba9ecu;
  }
  L0044d215: { // 0x44d215: e8e6d42b00 CALL 0x0070a700
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070a700u,4510234u); flags=s.arithmetic_flags;
  }
  L0044d21a: { // 0x44d21a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d21b: { // 0x44d21b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0044d21c: { // 0x44d21c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00653380(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00653380: { // 0x653380: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00653386: { // 0x653386: 8b812c060000 MOV EAX,dword ptr [ECX + 0x62c]
    s.ax = m.r32((s.cx+0x0000062cu));
  }
  L0065338c: { // 0x65338c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0065338e: { // 0x65338e: 0f84a5000000 JZ 0x00653439
    if(integer::condition("JZ",flags)) goto L00653439;
  }
  L00653394: { // 0x653394: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00653395: { // 0x653395: 89812c060000 MOV dword ptr [ECX + 0x62c],EAX
    m.w32((s.cx+0x0000062cu), s.ax);
  }
  L0065339b: { // 0x65339b: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006533a0: { // 0x6533a0: 8b882c060000 MOV ECX,dword ptr [EAX + 0x62c]
    s.cx = m.r32((s.ax+0x0000062cu));
  }
  L006533a6: { // 0x6533a6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006533a8: { // 0x6533a8: 0f858b000000 JNZ 0x00653439
    if(integer::condition("JNZ",flags)) goto L00653439;
  }
  L006533ae: { // 0x6533ae: 8a0dfce9a900 MOV CL,byte ptr [0x00a9e9fc]
    s.cx = with_al(s.cx, m.r8((0x00a9e9fcu)));
  }
  L006533b4: { // 0x6533b4: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006533b6: { // 0x6533b6: 755f JNZ 0x00653417
    if(integer::condition("JNZ",flags)) goto L00653417;
  }
  L006533b8: { // 0x6533b8: 80b80623000001 CMP byte ptr [EAX + 0x2306],0x1
    (void)integer::sub(m.r8((s.ax+0x00002306u)),0x00000001u,8,flags);
  }
  L006533bf: { // 0x6533bf: 752e JNZ 0x006533ef
    if(integer::condition("JNZ",flags)) goto L006533ef;
  }
  L006533c1: { // 0x6533c1: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L006533c7: { // 0x6533c7: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006533c9: { // 0x6533c9: ff5028 CALL dword ptr [EAX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000028u)),6632396u); flags=s.arithmetic_flags;
  }
  L006533cc: { // 0x6533cc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006533ce: { // 0x6533ce: 741a JZ 0x006533ea
    if(integer::condition("JZ",flags)) goto L006533ea;
  }
  L006533d0: { // 0x6533d0: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L006533d6: { // 0x6533d6: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L006533d8: { // 0x6533d8: ff5210 CALL dword ptr [EDX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000010u)),6632411u); flags=s.arithmetic_flags;
  }
  L006533db: { // 0x6533db: 8b0da81f8200 MOV ECX,dword ptr [0x00821fa8]
    s.cx = m.r32((0x00821fa8u));
  }
  L006533e1: { // 0x6533e1: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006533e3: { // 0x6533e3: ff5028 CALL dword ptr [EAX + 0x28]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000028u)),6632422u); flags=s.arithmetic_flags;
  }
  L006533e6: { // 0x6533e6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006533e8: { // 0x6533e8: 75e6 JNZ 0x006533d0
    if(integer::condition("JNZ",flags)) goto L006533d0;
  }
  L006533ea: { // 0x6533ea: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L006533ef: { // 0x6533ef: c6800623000000 MOV byte ptr [EAX + 0x2306],0x0
    m.w8((s.ax+0x00002306u), 0x00000000u);
  }
  L006533f6: { // 0x6533f6: 8b0da8a78100 MOV ECX,dword ptr [0x0081a7a8]
    s.cx = m.r32((0x0081a7a8u));
  }
  L006533fc: { // 0x6533fc: c6058489a20000 MOV byte ptr [0x00a28984],0x0
    m.w8((0x00a28984u), 0x00000000u);
  }
  L00653403: { // 0x653403: e848d8edff CALL 0x00530c50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00530c50u,6632456u); flags=s.arithmetic_flags;
  }
  L00653408: { // 0x653408: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0065340d: { // 0x65340d: c7057c0caa0000000000 MOV dword ptr [0x00aa0c7c],0x0
    m.w32((0x00aa0c7cu), 0x00000000u);
  }
  L00653417: { // 0x653417: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00653418: { // 0x653418: 8db014060000 LEA ESI,[EAX + 0x614]
    s.si = (s.ax+0x00000614u);
  }
  L0065341e: { // 0x65341e: 8b8014060000 MOV EAX,dword ptr [EAX + 0x614]
    s.ax = m.r32((s.ax+0x00000614u));
  }
  L00653424: { // 0x653424: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L00653427: { // 0x653427: 750a JNZ 0x00653433
    if(integer::condition("JNZ",flags)) goto L00653433;
  }
  L00653429: { // 0x653429: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  L0065342c: { // 0x65342c: e89fc60300 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,6632497u); flags=s.arithmetic_flags;
  }
  L00653431: { // 0x653431: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00653433: { // 0x653433: e8383adbff CALL 0x00406e70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00406e70u,6632504u); flags=s.arithmetic_flags;
  }
  L00653438: { // 0x653438: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00653439: { // 0x653439: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
