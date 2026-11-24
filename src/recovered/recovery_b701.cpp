#include "recovered/recovery_b701_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b701 {
namespace {
void f_002b6910(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void f_0001b380(Memory&,State&,Frame&,const Operations&);
void f_002c2be0(Memory&,State&,Frame&,const Operations&);
void f_002cdb10(Memory&,State&,Frame&,const Operations&);
void f_0004d670(Memory&,State&,Frame&,const Operations&);
void f_002d4b30(Memory&,State&,Frame&,const Operations&);
void f_002d4bf0(Memory&,State&,Frame&,const Operations&);
void f_002cc380(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_000f47b0(Memory&,State&,Frame&,const Operations&);
void f_0001b410(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_002b6910(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006b6910: { // 0x6b6910: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006b6912: {if(m.r32(s.ax+0x84)!=0x4538b0)throw std::domain_error("701 unprovedtail");s.arithmetic_flags=flags;f_000538b0(m,s,f,op);return;
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
void f_0001b380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b380: { // 0x41b380: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0041b382: { // 0x41b382: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_002c2be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c2be0: { // 0x6c2be0: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006c2be2: { // 0x6c2be2: ff9098030000 CALL dword ptr [EAX + 0x398]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000398u)),7089128u); flags=s.arithmetic_flags;
  }
  L006c2be8: { // 0x6c2be8: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c2bea: { // 0x6c2bea: 740b JZ 0x6c2bf7
    if(integer::condition("JZ",flags)) goto L006c2bf7;
  }
  L006c2bec: { // 0x6c2bec: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L006c2bef: { // 0x6c2bef: 7406 JZ 0x6c2bf7
    if(integer::condition("JZ",flags)) goto L006c2bf7;
  }
  L006c2bf1: { // 0x6c2bf1: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L006c2bf6: { // 0x6c2bf6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006c2bf7: { // 0x6c2bf7: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c2bf9: { // 0x6c2bf9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cdb10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cdb10: { // 0x6cdb10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006cdb11: { // 0x6cdb11: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L006cdb13: { // 0x6cdb13: 8b06 MOV EAX, dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006cdb15: { // 0x6cdb15: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7133979u); flags=s.arithmetic_flags;
  }
  L006cdb1b: { // 0x6cdb1b: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L006cdb1d: { // 0x6cdb1d: e8ce700000 CALL 0x6d4bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4bf0u,7133986u); flags=s.arithmetic_flags;
  }
  L006cdb22: { // 0x6cdb22: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cdb24: { // 0x6cdb24: 7413 JZ 0x6cdb39
    if(integer::condition("JZ",flags)) goto L006cdb39;
  }
  L006cdb26: { // 0x6cdb26: 8b860c010000 MOV EAX, dword ptr [ESI + 0x10c]
    s.ax = m.r32((s.si+0x0000010cu));
  }
  L006cdb2c: { // 0x6cdb2c: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb2e: { // 0x6cdb2e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb2f: { // 0x6cdb2f: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb31: { // 0x6cdb31: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134007u); flags=s.arithmetic_flags;
  }
  L006cdb37: { // 0x6cdb37: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb38: { // 0x6cdb38: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006cdb39: { // 0x6cdb39: 8b16 MOV EDX, dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006cdb3b: { // 0x6cdb3b: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006cdb3d: { // 0x6cdb3d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006cdb3e: { // 0x6cdb3e: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L006cdb40: { // 0x6cdb40: ff929c030000 CALL dword ptr [EDX + 0x39c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000039cu)),7134022u); flags=s.arithmetic_flags;
  }
  L006cdb46: { // 0x6cdb46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006cdb47: { // 0x6cdb47: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0004d670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0044d670: { // 0x44d670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0044d671: { // 0x44d671: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d672: { // 0x44d672: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0044d673: { // 0x44d673: 8b6c2410 MOV EBP, dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0044d677: { // 0x44d677: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0044d678: { // 0x44d678: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L0044d67a: { // 0x44d67a: 8a87c6050000 MOV AL, byte ptr [EDI + 0x5c6]
    s.ax = with_al(s.ax, m.r8((s.di+0x000005c6u)));
  }
  L0044d680: { // 0x44d680: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d682: { // 0x44d682: 742c JZ 0x44d6b0
    if(integer::condition("JZ",flags)) goto L0044d6b0;
  }
  L0044d684: { // 0x44d684: 33db XOR EBX, EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0044d686: { // 0x44d686: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0044d688: { // 0x44d688: 7e26 JLE 0x44d6b0
    if(integer::condition("JLE",flags)) goto L0044d6b0;
  }
  L0044d68a: { // 0x44d68a: 8db7c0040000 LEA ESI, [EDI + 0x4c0]
    s.si = (s.di+0x000004c0u);
  }
  L0044d690: { // 0x44d690: 8b0e MOV ECX, dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L0044d692: { // 0x44d692: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0044d694: { // 0x44d694: 740b JZ 0x44d6a1
    if(integer::condition("JZ",flags)) goto L0044d6a1;
  }
  L0044d696: { // 0x44d696: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d697: { // 0x44d697: e894742800 CALL 0x6d4b30
    s.arithmetic_flags=flags; invoke(m,s,f,0x006d4b30u,4511388u); flags=s.arithmetic_flags;
  }
  L0044d69c: { // 0x44d69c: 833800 CMP dword ptr [EAX], 0
    (void)integer::sub(m.r32((s.ax)),0u,32,flags);
  }
  L0044d69f: { // 0x44d69f: 7517 JNZ 0x44d6b8
    if(integer::condition("JNZ",flags)) goto L0044d6b8;
  }
  L0044d6a1: { // 0x44d6a1: 0fbe87c6050000 MOVSX EAX, byte ptr [EDI + 0x5c6]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000005c6u)),8));
  }
  L0044d6a8: { // 0x44d6a8: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L0044d6a9: { // 0x44d6a9: 83c604 ADD ESI, 4
    s.si = integer::add(s.si,4u,32,flags);
  }
  L0044d6ac: { // 0x44d6ac: 3bd8 CMP EBX, EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L0044d6ae: { // 0x44d6ae: 7ce0 JL 0x44d690
    if(integer::condition("JL",flags)) goto L0044d690;
  }
  L0044d6b0: { // 0x44d6b0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0044d6b1: { // 0x44d6b1: 8bcf MOV ECX, EDI
    s.cx = s.di;
  }
  L0044d6b3: { // 0x44d6b3: e8f8032800 CALL 0x6cdab0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006cdab0u,4511416u); flags=s.arithmetic_flags;
  }
  L0044d6b8: { // 0x44d6b8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0044d6b9: { // 0x44d6b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0044d6ba: { // 0x44d6ba: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0044d6bb: { // 0x44d6bb: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0044d6bc: { // 0x44d6bc: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4b30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4b30: { // 0x6d4b30: 8b442404 MOV EAX, dword ptr [ESP + 4]
    s.ax = m.r32((f.sp+4u));
  }
  L006d4b34: { // 0x6d4b34: 8d14c500000000 LEA EDX, [EAX*8]
    s.dx = ((s.ax * 8u));
  }
  L006d4b3b: { // 0x6d4b3b: 2bd0 SUB EDX, EAX
    s.dx = integer::sub(s.dx,s.ax,32,flags);
  }
  L006d4b3d: { // 0x6d4b3d: 8d84914c070000 LEA EAX, [ECX + EDX*4 + 0x74c]
    s.ax = (s.cx+(s.dx * 4u)+0x0000074cu);
  }
  L006d4b44: { // 0x6d4b44: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_002d4bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006d4bf0: { // 0x6d4bf0: 8b9104070000 MOV EDX, dword ptr [ECX + 0x704]
    s.dx = m.r32((s.cx+0x00000704u));
  }
  L006d4bf6: { // 0x6d4bf6: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006d4bf8: { // 0x6d4bf8: 85d2 TEST EDX, EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006d4bfa: { // 0x6d4bfa: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  L006d4bfd: { // 0x6d4bfd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cc380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc380: { // 0x6cc380: 8b8108020000 MOV EAX, dword ptr [ECX + 0x208]
    s.ax = m.r32((s.cx+0x00000208u));
  }
  L006cc386: { // 0x6cc386: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006cc388: { // 0x6cc388: 740a JZ 0x6cc394
    if(integer::condition("JZ",flags)) goto L006cc394;
  }
  L006cc38a: { // 0x6cc38a: 8b4828 MOV ECX, dword ptr [EAX + 0x28]
    s.cx = m.r32((s.ax+0x00000028u));
  }
  L006cc38d: { // 0x6cc38d: 85c9 TEST ECX, ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006cc38f: { // 0x6cc38f: 7403 JZ 0x6cc394
    if(integer::condition("JZ",flags)) goto L006cc394;
  }
  L006cc391: { // 0x6cc391: b001 MOV AL, 1
    s.ax = with_al(s.ax, 1u);
  }
  L006cc393: { // 0x6cc393: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L006cc394: { // 0x6cc394: 32c0 XOR AL, AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cc396: { // 0x6cc396: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

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
  L004f47e0: { // 0x4f47e0: 0f94c0 SETZ AL
    s.ax = with_al(s.ax, (integer::condition("SETZ",flags)?1u:0u));
  }
  L004f47e3: { // 0x4f47e3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0001b410(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041b410: { // 0x41b410: 8a8170010000 MOV AL, byte ptr [ECX + 0x170]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00000170u)));
  }
  L0041b416: { // 0x41b416: c3 RET
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
case 4305792u:f_0001b380(m,s,child,{});break;
case 7089120u:f_002c2be0(m,s,child,{});break;
case 7133968u:f_002cdb10(m,s,child,{});break;
case 4511344u:f_0004d670(m,s,child,{});break;
case 7162672u:f_002d4b30(m,s,child,{});break;
case 7162864u:f_002d4bf0(m,s,child,{});break;
case 7127936u:f_002cc380(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
case 5195696u:f_000f47b0(m,s,child,{});break;
case 4305936u:f_0001b410(m,s,child,{});break;
default:throw std::domain_error("recovery701 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006c8750(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c8750: { // 0x6c8750: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c8751: { // 0x6c8751: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c8752: { // 0x6c8752: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006c8753: { // 0x6c8753: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L006c8757: { // 0x6c8757: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  L006c875a: { // 0x6c875a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c875c: { // 0x6c875c: 7508 JNZ 0x006c8766
    if(integer::condition("JNZ",flags)) goto L006c8766;
  }
  L006c875e: { // 0x6c875e: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  L006c8760: { // 0x6c8760: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c8761: { // 0x6c8761: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c8762: { // 0x6c8762: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c8763: { // 0x6c8763: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c8766: { // 0x6c8766: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006c8768: { // 0x6c8768: 7542 JNZ 0x006c87ac
    if(integer::condition("JNZ",flags)) goto L006c87ac;
  }
  L006c876a: { // 0x6c876a: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c876c: { // 0x6c876c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c876e: { // 0x6c876e: ff9004030000 CALL dword ptr [EAX + 0x304]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000304u)),7112564u); flags=s.arithmetic_flags;
  }
  L006c8774: { // 0x6c8774: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c8776: { // 0x6c8776: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c8778: { // 0x6c8778: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L006c877a: { // 0x6c877a: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7112576u); flags=s.arithmetic_flags;
  }
  L006c8780: { // 0x6c8780: 8b8804050000 MOV ECX,dword ptr [EAX + 0x504]
    s.cx = m.r32((s.ax+0x00000504u));
  }
  L006c8786: { // 0x6c8786: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c8788: { // 0x6c8788: 0f8499000000 JZ 0x006c8827
    if(integer::condition("JZ",flags)) goto L006c8827;
  }
  L006c878e: { // 0x6c878e: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c8790: { // 0x6c8790: 0f8591000000 JNZ 0x006c8827
    if(integer::condition("JNZ",flags)) goto L006c8827;
  }
  L006c8796: { // 0x6c8796: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c8798: { // 0x6c8798: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c879a: { // 0x6c879a: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7112608u); flags=s.arithmetic_flags;
  }
  L006c87a0: { // 0x6c87a0: 8b8004050000 MOV EAX,dword ptr [EAX + 0x504]
    s.ax = m.r32((s.ax+0x00000504u));
  }
  L006c87a6: { // 0x6c87a6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c87a7: { // 0x6c87a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c87a8: { // 0x6c87a8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c87a9: { // 0x6c87a9: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c87ac: { // 0x6c87ac: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c87ae: { // 0x6c87ae: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c87b0: { // 0x6c87b0: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7112630u); flags=s.arithmetic_flags;
  }
  L006c87b6: { // 0x6c87b6: 8b8004050000 MOV EAX,dword ptr [EAX + 0x504]
    s.ax = m.r32((s.ax+0x00000504u));
  }
  L006c87bc: { // 0x6c87bc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c87be: { // 0x6c87be: 7538 JNZ 0x006c87f8
    if(integer::condition("JNZ",flags)) goto L006c87f8;
  }
  L006c87c0: { // 0x6c87c0: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c87c2: { // 0x6c87c2: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006c87c4: { // 0x6c87c4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c87c6: { // 0x6c87c6: ff9054010000 CALL dword ptr [EAX + 0x154]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000154u)),7112652u); flags=s.arithmetic_flags;
  }
  L006c87cc: { // 0x6c87cc: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c87ce: { // 0x6c87ce: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c87d0: { // 0x6c87d0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c87d2: { // 0x6c87d2: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006c87d4: { // 0x6c87d4: ff9254010000 CALL dword ptr [EDX + 0x154]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000154u)),7112666u); flags=s.arithmetic_flags;
  }
  L006c87da: { // 0x6c87da: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L006c87dc: { // 0x6c87dc: 7e0e JLE 0x006c87ec
    if(integer::condition("JLE",flags)) goto L006c87ec;
  }
  L006c87de: { // 0x6c87de: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c87e0: { // 0x6c87e0: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006c87e2: { // 0x6c87e2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c87e4: { // 0x6c87e4: ff9054010000 CALL dword ptr [EAX + 0x154]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000154u)),7112682u); flags=s.arithmetic_flags;
  }
  L006c87ea: { // 0x6c87ea: eb0c JMP 0x006c87f8
    goto L006c87f8;
  }
  L006c87ec: { // 0x6c87ec: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c87ee: { // 0x6c87ee: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006c87f0: { // 0x6c87f0: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c87f2: { // 0x6c87f2: ff9254010000 CALL dword ptr [EDX + 0x154]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000154u)),7112696u); flags=s.arithmetic_flags;
  }
  L006c87f8: { // 0x6c87f8: 03c0 ADD EAX,EAX
    s.ax = integer::add(s.ax,s.ax,32,flags);
  }
  L006c87fa: { // 0x6c87fa: 83ff02 CMP EDI,0x2
    (void)integer::sub(s.di,0x00000002u,32,flags);
  }
  L006c87fd: { // 0x6c87fd: 7524 JNZ 0x006c8823
    if(integer::condition("JNZ",flags)) goto L006c8823;
  }
  L006c87ff: { // 0x6c87ff: 3d00070000 CMP EAX,0x700
    (void)integer::sub(s.ax,0x00000700u,32,flags);
  }
  L006c8804: { // 0x6c8804: 7d0b JGE 0x006c8811
    if(integer::condition("JGE",flags)) goto L006c8811;
  }
  L006c8806: { // 0x6c8806: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c8807: { // 0x6c8807: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c8808: { // 0x6c8808: b800070000 MOV EAX,0x700
    s.ax = 0x00000700u;
  }
  L006c880d: { // 0x6c880d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c880e: { // 0x6c880e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c8811: { // 0x6c8811: 3d00100000 CMP EAX,0x1000
    (void)integer::sub(s.ax,0x00001000u,32,flags);
  }
  L006c8816: { // 0x6c8816: 7e23 JLE 0x006c883b
    if(integer::condition("JLE",flags)) goto L006c883b;
  }
  L006c8818: { // 0x6c8818: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c8819: { // 0x6c8819: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c881a: { // 0x6c881a: b800100000 MOV EAX,0x1000
    s.ax = 0x00001000u;
  }
  L006c881f: { // 0x6c881f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c8820: { // 0x6c8820: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c8823: { // 0x6c8823: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c8825: { // 0x6c8825: 7d08 JGE 0x006c882f
    if(integer::condition("JGE",flags)) goto L006c882f;
  }
  L006c8827: { // 0x6c8827: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c8828: { // 0x6c8828: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c8829: { // 0x6c8829: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006c882b: { // 0x6c882b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c882c: { // 0x6c882c: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c882f: { // 0x6c882f: 3d00100000 CMP EAX,0x1000
    (void)integer::sub(s.ax,0x00001000u,32,flags);
  }
  L006c8834: { // 0x6c8834: 7e05 JLE 0x006c883b
    if(integer::condition("JLE",flags)) goto L006c883b;
  }
  L006c8836: { // 0x6c8836: b800100000 MOV EAX,0x1000
    s.ax = 0x00001000u;
  }
  L006c883b: { // 0x6c883b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006c883c: { // 0x6c883c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c883d: { // 0x6c883d: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c883e: { // 0x6c883e: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006c9630(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c9630: { // 0x6c9630: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006c9635: { // 0x6c9635: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006c9636: { // 0x6c9636: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006c9637: { // 0x6c9637: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006c9639: { // 0x6c9639: 8b0dd47caa00 MOV ECX,dword ptr [0x00aa7cd4]
    s.cx = m.r32((0x00aa7cd4u));
  }
  L006c963f: { // 0x6c963f: 2b86f4030000 SUB EAX,dword ptr [ESI + 0x3f4]
    s.ax = integer::sub(s.ax,m.r32((s.si+0x000003f4u)),32,flags);
  }
  L006c9645: { // 0x6c9645: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L006c9647: { // 0x6c9647: 0f8298000000 JC 0x006c96e5
    if(integer::condition("JC",flags)) goto L006c96e5;
  }
  L006c964d: { // 0x6c964d: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c964f: { // 0x6c964f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9651: { // 0x6c9651: ff92c4010000 CALL dword ptr [EDX + 0x1c4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001c4u)),7116375u); flags=s.arithmetic_flags;
  }
  L006c9657: { // 0x6c9657: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c9659: { // 0x6c9659: 0f8586000000 JNZ 0x006c96e5
    if(integer::condition("JNZ",flags)) goto L006c96e5;
  }
  L006c965f: { // 0x6c965f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c9661: { // 0x6c9661: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9663: { // 0x6c9663: ff9080000000 CALL dword ptr [EAX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000080u)),7116393u); flags=s.arithmetic_flags;
  }
  L006c9669: { // 0x6c9669: 8a88490b0000 MOV CL,byte ptr [EAX + 0xb49]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000b49u)));
  }
  L006c966f: { // 0x6c966f: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c9671: { // 0x6c9671: 7472 JZ 0x006c96e5
    if(integer::condition("JZ",flags)) goto L006c96e5;
  }
  L006c9673: { // 0x6c9673: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c9675: { // 0x6c9675: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9677: { // 0x6c9677: ff522c CALL dword ptr [EDX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000002cu)),7116410u); flags=s.arithmetic_flags;
  }
  L006c967a: { // 0x6c967a: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006c967d: { // 0x6c967d: 751b JNZ 0x006c969a
    if(integer::condition("JNZ",flags)) goto L006c969a;
  }
  L006c967f: { // 0x6c967f: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L006c9685: { // 0x6c9685: 8a881e120000 MOV CL,byte ptr [EAX + 0x121e]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000121eu)));
  }
  L006c968b: { // 0x6c968b: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L006c968d: { // 0x6c968d: 740b JZ 0x006c969a
    if(integer::condition("JZ",flags)) goto L006c969a;
  }
  L006c968f: { // 0x6c968f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c9691: { // 0x6c9691: e8ca98d8ff CALL 0x00452f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00452f60u,7116438u); flags=s.arithmetic_flags;
  }
  L006c9696: { // 0x6c9696: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c9698: { // 0x6c9698: 744b JZ 0x006c96e5
    if(integer::condition("JZ",flags)) goto L006c96e5;
  }
  L006c969a: { // 0x6c969a: 8b8630020000 MOV EAX,dword ptr [ESI + 0x230]
    s.ax = m.r32((s.si+0x00000230u));
  }
  L006c96a0: { // 0x6c96a0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006c96a2: { // 0x6c96a2: 740b JZ 0x006c96af
    if(integer::condition("JZ",flags)) goto L006c96af;
  }
  L006c96a4: { // 0x6c96a4: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  L006c96a7: { // 0x6c96a7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L006c96a9: { // 0x6c96a9: 7404 JZ 0x006c96af
    if(integer::condition("JZ",flags)) goto L006c96af;
  }
  L006c96ab: { // 0x6c96ab: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  L006c96ad: { // 0x6c96ad: eb02 JMP 0x006c96b1
    goto L006c96b1;
  }
  L006c96af: { // 0x6c96af: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L006c96b1: { // 0x6c96b1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006c96b3: { // 0x6c96b3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c96b5: { // 0x6c96b5: ff9204030000 CALL dword ptr [EDX + 0x304]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000304u)),7116475u); flags=s.arithmetic_flags;
  }
  L006c96bb: { // 0x6c96bb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c96bd: { // 0x6c96bd: 740f JZ 0x006c96ce
    if(integer::condition("JZ",flags)) goto L006c96ce;
  }
  L006c96bf: { // 0x6c96bf: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006c96c5: { // 0x6c96c5: e826b1e2ff CALL 0x004f47f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47f0u,7116490u); flags=s.arithmetic_flags;
  }
  L006c96ca: { // 0x6c96ca: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c96cc: { // 0x6c96cc: 7517 JNZ 0x006c96e5
    if(integer::condition("JNZ",flags)) goto L006c96e5;
  }
  L006c96ce: { // 0x6c96ce: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L006c96d0: { // 0x6c96d0: 7513 JNZ 0x006c96e5
    if(integer::condition("JNZ",flags)) goto L006c96e5;
  }
  L006c96d2: { // 0x6c96d2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006c96d4: { // 0x6c96d4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006c96d6: { // 0x6c96d6: ff908c020000 CALL dword ptr [EAX + 0x28c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000028cu)),7116508u); flags=s.arithmetic_flags;
  }
  L006c96dc: { // 0x6c96dc: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006c96de: { // 0x6c96de: 7405 JZ 0x006c96e5
    if(integer::condition("JZ",flags)) goto L006c96e5;
  }
  L006c96e0: { // 0x6c96e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c96e1: { // 0x6c96e1: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006c96e3: { // 0x6c96e3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c96e4: { // 0x6c96e4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006c96e5: { // 0x6c96e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006c96e6: { // 0x6c96e6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006c96e8: { // 0x6c96e8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006c96e9: { // 0x6c96e9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_006ce250(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce250: { // 0x6ce250: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ce251: { // 0x6ce251: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006ce253: { // 0x6ce253: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ce254: { // 0x6ce254: 8b9684010000 MOV EDX,dword ptr [ESI + 0x184]
    s.dx = m.r32((s.si+0x00000184u));
  }
  L006ce25a: { // 0x6ce25a: 8b868c010000 MOV EAX,dword ptr [ESI + 0x18c]
    s.ax = m.r32((s.si+0x0000018cu));
  }
  L006ce260: { // 0x6ce260: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006ce263: { // 0x6ce263: 740e JZ 0x006ce273
    if(integer::condition("JZ",flags)) goto L006ce273;
  }
  L006ce265: { // 0x6ce265: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006ce26b: { // 0x6ce26b: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006ce26d: { // 0x6ce26d: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006ce26f: { // 0x6ce26f: 7d19 JGE 0x006ce28a
    if(integer::condition("JGE",flags)) goto L006ce28a;
  }
  L006ce271: { // 0x6ce271: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006ce273: { // 0x6ce273: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006ce275: { // 0x6ce275: 7413 JZ 0x006ce28a
    if(integer::condition("JZ",flags)) goto L006ce28a;
  }
  L006ce277: { // 0x6ce277: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006ce27d: { // 0x6ce27d: e82e65e2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7135874u); flags=s.arithmetic_flags;
  }
  L006ce282: { // 0x6ce282: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce284: { // 0x6ce284: 0f8482000000 JZ 0x006ce30c
    if(integer::condition("JZ",flags)) goto L006ce30c;
  }
  L006ce28a: { // 0x6ce28a: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  L006ce290: { // 0x6ce290: e81b65e2ff CALL 0x004f47b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f47b0u,7135893u); flags=s.arithmetic_flags;
  }
  L006ce295: { // 0x6ce295: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce297: { // 0x6ce297: 743d JZ 0x006ce2d6
    if(integer::condition("JZ",flags)) goto L006ce2d6;
  }
  L006ce299: { // 0x6ce299: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ce29b: { // 0x6ce29b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ce29d: { // 0x6ce29d: ff90c0000000 CALL dword ptr [EAX + 0xc0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000c0u)),7135907u); flags=s.arithmetic_flags;
  }
  L006ce2a3: { // 0x6ce2a3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce2a5: { // 0x6ce2a5: 742f JZ 0x006ce2d6
    if(integer::condition("JZ",flags)) goto L006ce2d6;
  }
  L006ce2a7: { // 0x6ce2a7: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L006ce2ac: { // 0x6ce2ac: 8bbe74010000 MOV EDI,dword ptr [ESI + 0x174]
    s.di = m.r32((s.si+0x00000174u));
  }
  L006ce2b2: { // 0x6ce2b2: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L006ce2b4: { // 0x6ce2b4: 83c040 ADD EAX,0x40
    s.ax = integer::add(s.ax,0x00000040u,32,flags);
  }
  L006ce2b7: { // 0x6ce2b7: 25ff000080 AND EAX,0x800000ff
    s.ax = integer::logical((s.ax)&(0x800000ffu),32,flags);
  }
  L006ce2bc: { // 0x6ce2bc: 7907 JNS 0x006ce2c5
    if(integer::condition("JNS",flags)) goto L006ce2c5;
  }
  L006ce2be: { // 0x6ce2be: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L006ce2bf: { // 0x6ce2bf: 0d00ffffff OR EAX,0xffffff00
    s.ax = integer::logical((s.ax)|(0xffffff00u),32,flags);
  }
  L006ce2c4: { // 0x6ce2c4: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L006ce2c5: { // 0x6ce2c5: 83f848 CMP EAX,0x48
    (void)integer::sub(s.ax,0x00000048u,32,flags);
  }
  L006ce2c8: { // 0x6ce2c8: 7c42 JL 0x006ce30c
    if(integer::condition("JL",flags)) goto L006ce30c;
  }
  L006ce2ca: { // 0x6ce2ca: 83f877 CMP EAX,0x77
    (void)integer::sub(s.ax,0x00000077u,32,flags);
  }
  L006ce2cd: { // 0x6ce2cd: 7f3d JG 0x006ce30c
    if(integer::condition("JG",flags)) goto L006ce30c;
  }
  L006ce2cf: { // 0x6ce2cf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce2d0: { // 0x6ce2d0: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006ce2d2: { // 0x6ce2d2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce2d3: { // 0x6ce2d3: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ce2d6: { // 0x6ce2d6: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006ce2d8: { // 0x6ce2d8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ce2da: { // 0x6ce2da: ff92a4010000 CALL dword ptr [EDX + 0x1a4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a4u)),7135968u); flags=s.arithmetic_flags;
  }
  L006ce2e0: { // 0x6ce2e0: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006ce2e2: { // 0x6ce2e2: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ce2e4: { // 0x6ce2e4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ce2e6: { // 0x6ce2e6: ff90c0000000 CALL dword ptr [EAX + 0xc0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000c0u)),7135980u); flags=s.arithmetic_flags;
  }
  L006ce2ec: { // 0x6ce2ec: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce2ee: { // 0x6ce2ee: 741c JZ 0x006ce30c
    if(integer::condition("JZ",flags)) goto L006ce30c;
  }
  L006ce2f0: { // 0x6ce2f0: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L006ce2f2: { // 0x6ce2f2: 7418 JZ 0x006ce30c
    if(integer::condition("JZ",flags)) goto L006ce30c;
  }
  L006ce2f4: { // 0x6ce2f4: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006ce2f8: { // 0x6ce2f8: 8b5130 MOV EDX,dword ptr [ECX + 0x30]
    s.dx = m.r32((s.cx+0x00000030u));
  }
  L006ce2fb: { // 0x6ce2fb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006ce2fd: { // 0x6ce2fd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006ce2fe: { // 0x6ce2fe: e8fddbdaff CALL 0x0047bf00
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047bf00u,7136003u); flags=s.arithmetic_flags;
  }
  L006ce303: { // 0x6ce303: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006ce305: { // 0x6ce305: 7505 JNZ 0x006ce30c
    if(integer::condition("JNZ",flags)) goto L006ce30c;
  }
  L006ce307: { // 0x6ce307: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce308: { // 0x6ce308: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce309: { // 0x6ce309: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ce30c: { // 0x6ce30c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce30d: { // 0x6ce30d: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006ce30f: { // 0x6ce30f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce310: { // 0x6ce310: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
