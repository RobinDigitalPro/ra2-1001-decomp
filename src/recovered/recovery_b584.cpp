#include "recovered/recovery_b584_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b584 {
namespace {
void f_0020d4f0(Memory&,State&,Frame&,const Operations&);
void f_002c69a0(Memory&,State&,Frame&,const Operations&);
void f_00208c30(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0020d4f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060d4f0: { // 0x60d4f0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0060d4f3: { // 0x60d4f3: 83fa0b CMP EDX,0xb
    (void)integer::sub(s.dx,0x0000000bu,32,flags);
  }
  L0060d4f6: { // 0x60d4f6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060d4f7: { // 0x60d4f7: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0060d4f9: { // 0x60d4f9: 0f858f000000 JNZ 0x0060d58e
    if(integer::condition("JNZ",flags)) goto L0060d58e;
  }
  L0060d4ff: { // 0x60d4ff: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  L0060d503: { // 0x60d503: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060d505: { // 0x60d505: 7509 JNZ 0x0060d510
    if(integer::condition("JNZ",flags)) goto L0060d510;
  }
  L0060d507: { // 0x60d507: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0060d509: { // 0x60d509: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d50a: { // 0x60d50a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060d50d: { // 0x60d50d: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0060d510: { // 0x60d510: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060d512: { // 0x60d512: 747a JZ 0x0060d58e
    if(integer::condition("JZ",flags)) goto L0060d58e;
  }
  L0060d514: { // 0x60d514: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0060d516: { // 0x60d516: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L0060d51a: { // 0x60d51a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060d51b: { // 0x60d51b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060d51c: { // 0x60d51c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d51e: { // 0x60d51e: ff90a0010000 CALL dword ptr [EAX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000001a0u)),6346020u); flags=s.arithmetic_flags;
  }
  L0060d524: { // 0x60d524: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L0060d526: { // 0x60d526: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0060d528: { // 0x60d528: 8d442408 LEA EAX,[ESP + 0x8]
    s.ax = (f.sp+0x00000008u);
  }
  L0060d52c: { // 0x60d52c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d52e: { // 0x60d52e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060d52f: { // 0x60d52f: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0060d533: { // 0x60d533: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),6346041u); flags=s.arithmetic_flags;
  }
  L0060d539: { // 0x60d539: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0060d53b: { // 0x60d53b: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0060d53f: { // 0x60d53f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0060d543: { // 0x60d543: e818e70900 CALL 0x006abc60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006abc60u,6346056u); flags=s.arithmetic_flags;
  }
  L0060d548: { // 0x60d548: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060d54a: { // 0x60d54a: 7405 JZ 0x0060d551
    if(integer::condition("JZ",flags)) goto L0060d551;
  }
  L0060d54c: { // 0x60d54c: 8b7024 MOV ESI,dword ptr [EAX + 0x24]
    s.si = m.r32((s.ax+0x00000024u));
  }
  L0060d54f: { // 0x60d54f: eb1e JMP 0x0060d56f
    goto L0060d56f;
  }
  L0060d551: { // 0x60d551: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L0060d555: { // 0x60d555: e806da0900 CALL 0x006aaf60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006aaf60u,6346074u); flags=s.arithmetic_flags;
  }
  L0060d55a: { // 0x60d55a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060d55c: { // 0x60d55c: 7415 JZ 0x0060d573
    if(integer::condition("JZ",flags)) goto L0060d573;
  }
  L0060d55e: { // 0x60d55e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0060d560: { // 0x60d560: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L0060d564: { // 0x60d564: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0060d565: { // 0x60d565: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0060d567: { // 0x60d567: ff92a0010000 CALL dword ptr [EDX + 0x1a0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001a0u)),6346093u); flags=s.arithmetic_flags;
  }
  L0060d56d: { // 0x60d56d: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L0060d56f: { // 0x60d56f: 89742408 MOV dword ptr [ESP + 0x8],ESI
    m.w32((f.sp+0x00000008u), s.si);
  }
  L0060d573: { // 0x60d573: 663bfe CMP DI,SI
    (void)integer::sub((s.di & 0xffffu),(s.si & 0xffffu),16,flags);
  }
  L0060d576: { // 0x60d576: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d577: { // 0x60d577: 7515 JNZ 0x0060d58e
    if(integer::condition("JNZ",flags)) goto L0060d58e;
  }
  L0060d579: { // 0x60d579: 668b54240a MOV DX,word ptr [ESP + 0xa]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x0000000au)));
  }
  L0060d57e: { // 0x60d57e: 663b542406 CMP DX,word ptr [ESP + 0x6]
    (void)integer::sub((s.dx & 0xffffu),m.r16((f.sp+0x00000006u)),16,flags);
  }
  L0060d583: { // 0x60d583: 7509 JNZ 0x0060d58e
    if(integer::condition("JNZ",flags)) goto L0060d58e;
  }
  L0060d585: { // 0x60d585: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0060d587: { // 0x60d587: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d588: { // 0x60d588: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060d58b: { // 0x60d58b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
  L0060d58e: { // 0x60d58e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0060d590: { // 0x60d590: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d591: { // 0x60d591: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060d594: { // 0x60d594: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
void f_002c69a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006c69a0: { // 0x6c69a0: 8b8108040000 MOV EAX,dword ptr [ECX + 0x408]
    s.ax = m.r32((s.cx+0x00000408u));
  }
  L006c69a6: { // 0x6c69a6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00208c30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00608c30: { // 0x608c30: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00608c31: { // 0x608c31: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00608c32: { // 0x608c32: 8b7110 MOV ESI,dword ptr [ECX + 0x10]
    s.si = m.r32((s.cx+0x00000010u));
  }
  L00608c35: { // 0x608c35: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L00608c38: { // 0x608c38: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00608c3a: { // 0x608c3a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00608c3c: { // 0x608c3c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00608c3d: { // 0x608c3d: 7e1d JLE 0x00608c5c
    if(integer::condition("JLE",flags)) goto L00608c5c;
  }
  L00608c3f: { // 0x608c3f: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L00608c42: { // 0x608c42: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00608c46: { // 0x608c46: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  L00608c48: { // 0x608c48: 393b CMP dword ptr [EBX],EDI
    (void)integer::sub(m.r32((s.bx)),s.di,32,flags);
  }
  L00608c4a: { // 0x608c4a: 740e JZ 0x00608c5a
    if(integer::condition("JZ",flags)) goto L00608c5a;
  }
  L00608c4c: { // 0x608c4c: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L00608c4d: { // 0x608c4d: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L00608c50: { // 0x608c50: 3bd6 CMP EDX,ESI
    (void)integer::sub(s.dx,s.si,32,flags);
  }
  L00608c52: { // 0x608c52: 7cf2 JL 0x00608c46
    if(integer::condition("JL",flags)) goto L00608c46;
  }
  L00608c54: { // 0x608c54: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00608c55: { // 0x608c55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00608c56: { // 0x608c56: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00608c57: { // 0x608c57: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00608c5a: { // 0x608c5a: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00608c5c: { // 0x608c5c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00608c5d: { // 0x608c5d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00608c5e: { // 0x608c5e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00608c5f: { // 0x608c5f: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6345968u:f_0020d4f0(m,s,child,{});break;
case 7104928u:f_002c69a0(m,s,child,{});break;
case 6327344u:f_00208c30(m,s,child,{});break;
default:throw std::domain_error("recovery584 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0060d660(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060d660: { // 0x60d660: 83ec70 SUB ESP,0x70
    f.sp = integer::sub(f.sp,0x00000070u,32,flags);
  }
  L0060d663: { // 0x60d663: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0060d665: { // 0x60d665: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060d666: { // 0x60d666: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0060d668: { // 0x60d668: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  L0060d66a: { // 0x60d66a: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060d66b: { // 0x60d66b: 80f909 CMP CL,0x9
    (void)integer::sub((s.cx & 0xffu),0x00000009u,8,flags);
  }
  L0060d66e: { // 0x60d66e: 740a JZ 0x0060d67a
    if(integer::condition("JZ",flags)) goto L0060d67a;
  }
  L0060d670: { // 0x60d670: 80f906 CMP CL,0x6
    (void)integer::sub((s.cx & 0xffu),0x00000006u,8,flags);
  }
  L0060d673: { // 0x60d673: 7405 JZ 0x0060d67a
    if(integer::condition("JZ",flags)) goto L0060d67a;
  }
  L0060d675: { // 0x60d675: 80f907 CMP CL,0x7
    (void)integer::sub((s.cx & 0xffu),0x00000007u,8,flags);
  }
  L0060d678: { // 0x60d678: 7508 JNZ 0x0060d682
    if(integer::condition("JNZ",flags)) goto L0060d682;
  }
  L0060d67a: { // 0x60d67a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0060d67c: { // 0x60d67c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d67d: { // 0x60d67d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d67e: { // 0x60d67e: 83c470 ADD ESP,0x70
    f.sp = integer::add(f.sp,0x00000070u,32,flags);
  }
  L0060d681: { // 0x60d681: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060d682: { // 0x60d682: 0fbe500c MOVSX EDX,byte ptr [EAX + 0xc]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000000cu)),8));
  }
  L0060d686: { // 0x60d686: 83c00e ADD EAX,0xe
    s.ax = integer::add(s.ax,0x0000000eu,32,flags);
  }
  L0060d689: { // 0x60d689: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0060d68c: { // 0x60d68c: 8bcc MOV ECX,ESP
    s.cx = f.sp;
  }
  L0060d68e: { // 0x60d68e: 8b38 MOV EDI,dword ptr [EAX]
    s.di = m.r32((s.ax));
  }
  L0060d690: { // 0x60d690: 8939 MOV dword ptr [ECX],EDI
    m.w32((s.cx), s.di);
  }
  L0060d692: { // 0x60d692: 8a4004 MOV AL,byte ptr [EAX + 0x4]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000004u)));
  }
  L0060d695: { // 0x60d695: 884104 MOV byte ptr [ECX + 0x4],AL
    m.w8((s.cx+0x00000004u), (s.ax & 0xffu));
  }
  L0060d698: { // 0x60d698: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d69a: { // 0x60d69a: e851feffff CALL 0x0060d4f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0060d4f0u,6346399u); flags=s.arithmetic_flags;
  }
  L0060d69f: { // 0x60d69f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0060d6a1: { // 0x60d6a1: 7408 JZ 0x0060d6ab
    if(integer::condition("JZ",flags)) goto L0060d6ab;
  }
  L0060d6a3: { // 0x60d6a3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0060d6a5: { // 0x60d6a5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d6a6: { // 0x60d6a6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d6a7: { // 0x60d6a7: 83c470 ADD ESP,0x70
    f.sp = integer::add(f.sp,0x00000070u,32,flags);
  }
  L0060d6aa: { // 0x60d6aa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060d6ab: { // 0x60d6ab: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d6ad: { // 0x60d6ad: e8ee920b00 CALL 0x006c69a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c69a0u,6346418u); flags=s.arithmetic_flags;
  }
  L0060d6b2: { // 0x60d6b2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060d6b4: { // 0x60d6b4: 747e JZ 0x0060d734
    if(integer::condition("JZ",flags)) goto L0060d734;
  }
  L0060d6b6: { // 0x60d6b6: 8b4814 MOV ECX,dword ptr [EAX + 0x14]
    s.cx = m.r32((s.ax+0x00000014u));
  }
  L0060d6b9: { // 0x60d6b9: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0060d6bb: { // 0x60d6bb: 7e77 JLE 0x0060d734
    if(integer::condition("JLE",flags)) goto L0060d734;
  }
  L0060d6bd: { // 0x60d6bd: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L0060d6c0: { // 0x60d6c0: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0060d6c2: { // 0x60d6c2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060d6c3: { // 0x60d6c3: 8b748afc MOV ESI,dword ptr [EDX + ECX*0x4 + -0x4]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)-0x00000004u));
  }
  L0060d6c7: { // 0x60d6c7: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060d6c9: { // 0x60d6c9: e862b5ffff CALL 0x00608c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00608c30u,6346446u); flags=s.arithmetic_flags;
  }
  L0060d6ce: { // 0x60d6ce: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060d6d1: { // 0x60d6d1: 7504 JNZ 0x0060d6d7
    if(integer::condition("JNZ",flags)) goto L0060d6d7;
  }
  L0060d6d3: { // 0x60d6d3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0060d6d5: { // 0x60d6d5: eb06 JMP 0x0060d6dd
    goto L0060d6dd;
  }
  L0060d6d7: { // 0x60d6d7: 8b4e04 MOV ECX,dword ptr [ESI + 0x4]
    s.cx = m.r32((s.si+0x00000004u));
  }
  L0060d6da: { // 0x60d6da: 8b0481 MOV EAX,dword ptr [ECX + EAX*0x4]
    s.ax = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L0060d6dd: { // 0x60d6dd: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0060d6e0: { // 0x60d6e0: b91b000000 MOV ECX,0x1b
    s.cx = 0x0000001bu;
  }
  L0060d6e5: { // 0x60d6e5: 8d7c2408 LEA EDI,[ESP + 0x8]
    s.di = (f.sp+0x00000008u);
  }
  L0060d6e9: { // 0x60d6e9: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L0060d6eb: { // 0x60d6eb: 66a5 MOVSW ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,16u,Repeat::single);
  }
  L0060d6ed: { // 0x60d6ed: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  L0060d6ee: { // 0x60d6ee: 0fbe442414 MOVSX EAX,byte ptr [ESP + 0x14]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((f.sp+0x00000014u)),8));
  }
  L0060d6f3: { // 0x60d6f3: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L0060d6f6: { // 0x60d6f6: 740a JZ 0x0060d702
    if(integer::condition("JZ",flags)) goto L0060d702;
  }
  L0060d6f8: { // 0x60d6f8: 83f808 CMP EAX,0x8
    (void)integer::sub(s.ax,0x00000008u,32,flags);
  }
  L0060d6fb: { // 0x60d6fb: 7405 JZ 0x0060d702
    if(integer::condition("JZ",flags)) goto L0060d702;
  }
  L0060d6fd: { // 0x60d6fd: 83f809 CMP EAX,0x9
    (void)integer::sub(s.ax,0x00000009u,32,flags);
  }
  L0060d700: { // 0x60d700: 750b JNZ 0x0060d70d
    if(integer::condition("JNZ",flags)) goto L0060d70d;
  }
  L0060d702: { // 0x60d702: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0060d707: { // 0x60d707: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d708: { // 0x60d708: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d709: { // 0x60d709: 83c470 ADD ESP,0x70
    f.sp = integer::add(f.sp,0x00000070u,32,flags);
  }
  L0060d70c: { // 0x60d70c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060d70d: { // 0x60d70d: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L0060d710: { // 0x60d710: 7405 JZ 0x0060d717
    if(integer::condition("JZ",flags)) goto L0060d717;
  }
  L0060d712: { // 0x60d712: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L0060d715: { // 0x60d715: 751d JNZ 0x0060d734
    if(integer::condition("JNZ",flags)) goto L0060d734;
  }
  L0060d717: { // 0x60d717: 8a4c241a MOV CL,byte ptr [ESP + 0x1a]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000001au)));
  }
  L0060d71b: { // 0x60d71b: 80f90b CMP CL,0xb
    (void)integer::sub((s.cx & 0xffu),0x0000000bu,8,flags);
  }
  L0060d71e: { // 0x60d71e: 7409 JZ 0x0060d729
    if(integer::condition("JZ",flags)) goto L0060d729;
  }
  L0060d720: { // 0x60d720: 83f80b CMP EAX,0xb
    (void)integer::sub(s.ax,0x0000000bu,32,flags);
  }
  L0060d723: { // 0x60d723: 750f JNZ 0x0060d734
    if(integer::condition("JNZ",flags)) goto L0060d734;
  }
  L0060d725: { // 0x60d725: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0060d727: { // 0x60d727: 750b JNZ 0x0060d734
    if(integer::condition("JNZ",flags)) goto L0060d734;
  }
  L0060d729: { // 0x60d729: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L0060d72e: { // 0x60d72e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d72f: { // 0x60d72f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d730: { // 0x60d730: 83c470 ADD ESP,0x70
    f.sp = integer::add(f.sp,0x00000070u,32,flags);
  }
  L0060d733: { // 0x60d733: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060d734: { // 0x60d734: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060d735: { // 0x60d735: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0060d738: { // 0x60d738: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060d739: { // 0x60d739: 83c470 ADD ESP,0x70
    f.sp = integer::add(f.sp,0x00000070u,32,flags);
  }
  L0060d73c: { // 0x60d73c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0060f5f0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0060f5f0: { // 0x60f5f0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0060f5f3: { // 0x60f5f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060f5f4: { // 0x60f5f4: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060f5f5: { // 0x60f5f5: 8b2db088a200 MOV EBP,dword ptr [0x00a288b0]
    s.bp = m.r32((0x00a288b0u));
  }
  L0060f5fb: { // 0x60f5fb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060f5fc: { // 0x60f5fc: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060f5fd: { // 0x60f5fd: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0060f5ff: { // 0x60f5ff: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0060f601: { // 0x60f601: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0060f603: { // 0x60f603: 0f8e92000000 JLE 0x0060f69b
    if(integer::condition("JLE",flags)) goto L0060f69b;
  }
  L0060f609: { // 0x60f609: a1a488a200 MOV EAX,[0x00a288a4]
    s.ax = m.r32((0x00a288a4u));
  }
  L0060f60e: { // 0x60f60e: 8b0cb8 MOV ECX,dword ptr [EAX + EDI*0x4]
    s.cx = m.r32((s.ax+(s.di * 0x00000004u)));
  }
  L0060f611: { // 0x60f611: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0060f613: { // 0x60f613: 744b JZ 0x0060f660
    if(integer::condition("JZ",flags)) goto L0060f660;
  }
  L0060f615: { // 0x60f615: 8a5114 MOV DL,byte ptr [ECX + 0x14]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000014u)));
  }
  L0060f618: { // 0x60f618: 80e201 AND DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags));
  }
  L0060f61b: { // 0x60f61b: 88542413 MOV byte ptr [ESP + 0x13],DL
    m.w8((f.sp+0x00000013u), (s.dx & 0xffu));
  }
  L0060f61f: { // 0x60f61f: 743f JZ 0x0060f660
    if(integer::condition("JZ",flags)) goto L0060f660;
  }
  L0060f621: { // 0x60f621: e87a730b00 CALL 0x006c69a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x006c69a0u,6354470u); flags=s.arithmetic_flags;
  }
  L0060f626: { // 0x60f626: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0060f628: { // 0x60f628: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0060f62a: { // 0x60f62a: 7434 JZ 0x0060f660
    if(integer::condition("JZ",flags)) goto L0060f660;
  }
  L0060f62c: { // 0x60f62c: 8b8694000000 MOV EAX,dword ptr [ESI + 0x94]
    s.ax = m.r32((s.si+0x00000094u));
  }
  L0060f632: { // 0x60f632: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0060f634: { // 0x60f634: 7f31 JG 0x0060f667
    if(integer::condition("JG",flags)) goto L0060f667;
  }
  L0060f636: { // 0x60f636: 742f JZ 0x0060f667
    if(integer::condition("JZ",flags)) goto L0060f667;
  }
  L0060f638: { // 0x60f638: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L0060f63b: { // 0x60f63b: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  L0060f63e: { // 0x60f63e: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0060f642: { // 0x60f642: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L0060f646: { // 0x60f646: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060f647: { // 0x60f647: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6354506u); flags=s.arithmetic_flags;
  }
  L0060f64a: { // 0x60f64a: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0060f64d: { // 0x60f64d: 7425 JZ 0x0060f674
    if(integer::condition("JZ",flags)) goto L0060f674;
  }
  L0060f64f: { // 0x60f64f: 8b7614 MOV ESI,dword ptr [ESI + 0x14]
    s.si = m.r32((s.si+0x00000014u));
  }
  L0060f652: { // 0x60f652: 8d4eff LEA ECX,[ESI + -0x1]
    s.cx = (s.si-0x00000001u);
  }
  L0060f655: { // 0x60f655: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060f657: { // 0x60f657: 7428 JZ 0x0060f681
    if(integer::condition("JZ",flags)) goto L0060f681;
  }
  L0060f659: { // 0x60f659: 83c6fe ADD ESI,-0x2
    s.si = integer::add(s.si,0xfffffffeu,32,flags);
  }
  L0060f65c: { // 0x60f65c: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0060f65e: { // 0x60f65e: 742e JZ 0x0060f68e
    if(integer::condition("JZ",flags)) goto L0060f68e;
  }
  L0060f660: { // 0x60f660: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0060f661: { // 0x60f661: 3bfd CMP EDI,EBP
    (void)integer::sub(s.di,s.bp,32,flags);
  }
  L0060f663: { // 0x60f663: 7d36 JGE 0x0060f69b
    if(integer::condition("JGE",flags)) goto L0060f69b;
  }
  L0060f665: { // 0x60f665: eba2 JMP 0x0060f609
    goto L0060f609;
  }
  L0060f667: { // 0x60f667: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f668: { // 0x60f668: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f669: { // 0x60f669: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f66a: { // 0x60f66a: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0060f66f: { // 0x60f66f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f670: { // 0x60f670: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f673: { // 0x60f673: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f674: { // 0x60f674: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f675: { // 0x60f675: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f676: { // 0x60f676: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f677: { // 0x60f677: b805000000 MOV EAX,0x5
    s.ax = 0x00000005u;
  }
  L0060f67c: { // 0x60f67c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f67d: { // 0x60f67d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f680: { // 0x60f680: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f681: { // 0x60f681: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f682: { // 0x60f682: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f683: { // 0x60f683: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f684: { // 0x60f684: b802000000 MOV EAX,0x2
    s.ax = 0x00000002u;
  }
  L0060f689: { // 0x60f689: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f68a: { // 0x60f68a: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f68d: { // 0x60f68d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f68e: { // 0x60f68e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f68f: { // 0x60f68f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f690: { // 0x60f690: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f691: { // 0x60f691: b803000000 MOV EAX,0x3
    s.ax = 0x00000003u;
  }
  L0060f696: { // 0x60f696: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f697: { // 0x60f697: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f69a: { // 0x60f69a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0060f69b: { // 0x60f69b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0060f69c: { // 0x60f69c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060f69d: { // 0x60f69d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060f69e: { // 0x60f69e: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0060f6a1: { // 0x60f6a1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060f6a2: { // 0x60f6a2: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L0060f6a5: { // 0x60f6a5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
