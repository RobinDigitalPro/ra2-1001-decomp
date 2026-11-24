#include "recovered/recovery_b897_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b897 {
namespace {
void f_00053890(Memory&,State&,Frame&,const Operations&);
void f_00307f60(Memory&,State&,Frame&,const Operations&);
void f_00307fe0(Memory&,State&,Frame&,const Operations&);
void f_002cc350(Memory&,State&,Frame&,const Operations&);
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_0007bec0(Memory&,State&,Frame&,const Operations&);
void tail(Memory&,State&,Frame&,std::uint32_t);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX, 6
    s.ax = 6u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707f60: { // 0x707f60: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f62: { // 0x707f62: dc1d08577800 FCOMP qword ptr [0x785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f68: { // 0x707f68: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f6a: { // 0x707f6a: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f6d: { // 0x707f6d: 7515 JNZ 0x707f84
    if(integer::condition("JNZ",flags)) goto L00707f84;
  }
  L00707f6f: { // 0x707f6f: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707f71: { // 0x707f71: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707f77: { // 0x707f77: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707f79: { // 0x707f79: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707f7c: { // 0x707f7c: 7406 JZ 0x707f84
    if(integer::condition("JZ",flags)) goto L00707f84;
  }
  L00707f7e: { // 0x707f7e: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707f83: { // 0x707f83: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707f84: { // 0x707f84: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707f86: { // 0x707f86: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00307fe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00707fe0: { // 0x707fe0: dd01 FLD qword ptr [ECX]
    const auto address=(s.cx);
    s.fp.load64(read64(m,address));
  }
  L00707fe2: { // 0x707fe2: dc1df8567800 FCOMP qword ptr [0x7856f8]
    const auto address=(0x007856f8u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00707fe8: { // 0x707fe8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00707fea: { // 0x707fea: f6c401 TEST AH, 1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(1u),8,flags);
  }
  L00707fed: { // 0x707fed: 7506 JNZ 0x707ff5
    if(integer::condition("JNZ",flags)) goto L00707ff5;
  }
  L00707fef: { // 0x707fef: b801000000 MOV EAX, 1
    s.ax = 1u;
  }
  L00707ff4: { // 0x707ff4: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L00707ff5: { // 0x707ff5: 33c0 XOR EAX, EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00707ff7: { // 0x707ff7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_002cc350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006cc350: { // 0x6cc350: 8a812a030000 MOV AL,byte ptr [ECX + 0x32a]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000032au)));
  }
  L006cc356: { // 0x6cc356: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006cc358: { // 0x6cc358: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L006cc35b: { // 0x6cc35b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00043e10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00443e10: { // 0x443e10: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00443e11: { // 0x443e11: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00443e12: { // 0x443e12: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00443e14: { // 0x443e14: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00443e16: { // 0x443e16: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e1c: { // 0x443e1c: e89f470100 CALL 0x004585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4472353u); flags=s.arithmetic_flags;
  }
  L00443e21: { // 0x443e21: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e27: { // 0x443e27: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00443e29: { // 0x443e29: c1e607 SHL ESI,0x7
    s.si = integer::shift(s.si,0x00000007u,32,flags,integer::Shift::left);
  }
  L00443e2c: { // 0x443e2c: 81ee80000000 SUB ESI,0x80
    s.si = integer::sub(s.si,0x00000080u,32,flags);
  }
  L00443e32: { // 0x443e32: e879470100 CALL 0x004585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4472375u); flags=s.arithmetic_flags;
  }
  L00443e37: { // 0x443e37: 81c788000000 ADD EDI,0x88
    s.di = integer::add(s.di,0x00000088u,32,flags);
  }
  L00443e3d: { // 0x443e3d: c1e007 SHL EAX,0x7
    s.ax = integer::shift(s.ax,0x00000007u,32,flags,integer::Shift::left);
  }
  L00443e40: { // 0x443e40: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00443e42: { // 0x443e42: 2d80000000 SUB EAX,0x80
    s.ax = integer::sub(s.ax,0x00000080u,32,flags);
  }
  L00443e47: { // 0x443e47: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00443e49: { // 0x443e49: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00443e4d: { // 0x443e4d: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00443e50: { // 0x443e50: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00443e52: { // 0x443e52: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00443e54: { // 0x443e54: 8b7f08 MOV EDI,dword ptr [EDI + 0x8]
    s.di = m.r32((s.di+0x00000008u));
  }
  L00443e57: { // 0x443e57: 890e MOV dword ptr [ESI],ECX
    m.w32((s.si), s.cx);
  }
  L00443e59: { // 0x443e59: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L00443e5c: { // 0x443e5c: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  L00443e5f: { // 0x443e5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00443e60: { // 0x443e60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00443e61: { // 0x443e61: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000585b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585b0: { // 0x4585b0: 8b81780c0000 MOV EAX,dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585b6: { // 0x4585b6: 8b048508ac7b00 MOV EAX,dword ptr [EAX*0x4 + 0x7bac08]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007bac08u));
  }
  L004585bd: { // 0x4585bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000585c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585c0: { // 0x4585c0: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  L004585c4: { // 0x4585c4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585c6: { // 0x4585c6: 7421 JZ 0x004585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585c8: { // 0x4585c8: 8a8114120000 MOV AL,byte ptr [ECX + 0x1214]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001214u)));
  }
  L004585ce: { // 0x4585ce: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585d0: { // 0x4585d0: 7417 JZ 0x004585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585d2: { // 0x4585d2: 8b81780c0000 MOV EAX,dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585d8: { // 0x4585d8: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L004585dd: { // 0x4585dd: 8b048560ac7b00 MOV EAX,dword ptr [EAX*0x4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007bac60u));
  }
  L004585e4: { // 0x4585e4: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585e6: { // 0x4585e6: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004585e9: { // 0x4585e9: 8b81780c0000 MOV EAX,dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585ef: { // 0x4585ef: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004585f1: { // 0x4585f1: 8b048560ac7b00 MOV EAX,dword ptr [EAX*0x4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 0x00000004u)+0x007bac60u));
  }
  L004585f8: { // 0x4585f8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585fa: { // 0x4585fa: c20400 RET 0x4
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
void f_0007bec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0047bec0: { // 0x47bec0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0047bec2: { // 0x47bec2: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0047bec7: { // 0x47bec7: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L0047becb: { // 0x47becb: 8b4078 MOV EAX,dword ptr [EAX + 0x78]
    s.ax = m.r32((s.ax+0x00000078u));
  }
  L0047bece: { // 0x47bece: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0047bed0: { // 0x47bed0: 23c2 AND EAX,EDX
    s.ax = integer::logical((s.ax)&(s.dx),32,flags);
  }
  L0047bed2: { // 0x47bed2: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0047bed4: { // 0x47bed4: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  L0047bed6: { // 0x47bed6: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0047bed8: { // 0x47bed8: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4536464u:f_00053890(m,s,child,{});break;
case 7372640u:f_00307f60(m,s,child,{});break;
case 7372768u:f_00307fe0(m,s,child,{});break;
case 7127888u:f_002cc350(m,s,child,{});break;
case 4472336u:f_00043e10(m,s,child,{});break;
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4701888u:f_0007bec0(m,s,child,{});break;
default:throw std::domain_error("recovery897 unreviewed original call");}
f.sp=child.sp;
}
}
namespace { void tail(Memory&m,State&s,Frame&f,std::uint32_t target){switch(target){case 4536464u:f_00053890(m,s,f,{});return;case 7372640u:f_00307f60(m,s,f,{});return;case 7372768u:f_00307fe0(m,s,f,{});return;case 7127888u:f_002cc350(m,s,f,{});return;case 4472336u:f_00043e10(m,s,f,{});return;case 4556208u:f_000585b0(m,s,f,{});return;case 4556224u:f_000585c0(m,s,f,{});return;case 5526784u:f_00145500(m,s,f,{});return;case 4701888u:f_0007bec0(m,s,f,{});return;default:throw std::domain_error("B897 unexpected tail target");}}}

std::uint32_t fun_006be600(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006be600: { // 0x6be600: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L006be603: { // 0x6be603: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L006be604: { // 0x6be604: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006be605: { // 0x6be605: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006be607: { // 0x6be607: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006be608: { // 0x6be608: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006be60a: { // 0x6be60a: ff9068020000 CALL dword ptr [EAX + 0x268]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000268u)),7071248u); flags=s.arithmetic_flags;
  }
  L006be610: { // 0x6be610: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be612: { // 0x6be612: 0f85d4000000 JNZ 0x006be6ec
    if(integer::condition("JNZ",flags)) goto L006be6ec;
  }
  L006be618: { // 0x6be618: 8d9e18010000 LEA EBX,[ESI + 0x118]
    s.bx = (s.si+0x00000118u);
  }
  L006be61e: { // 0x6be61e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be620: { // 0x6be620: e83b990400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7071269u); flags=s.arithmetic_flags;
  }
  L006be625: { // 0x6be625: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be627: { // 0x6be627: 750b JNZ 0x006be634
    if(integer::condition("JNZ",flags)) goto L006be634;
  }
  L006be629: { // 0x6be629: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be62b: { // 0x6be62b: e8b0990400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7071280u); flags=s.arithmetic_flags;
  }
  L006be630: { // 0x6be630: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be632: { // 0x6be632: 7444 JZ 0x006be678
    if(integer::condition("JZ",flags)) goto L006be678;
  }
  L006be634: { // 0x6be634: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006be636: { // 0x6be636: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be638: { // 0x6be638: ff9280000000 CALL dword ptr [EDX + 0x80]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000080u)),7071294u); flags=s.arithmetic_flags;
  }
  L006be63e: { // 0x6be63e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be640: { // 0x6be640: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006be642: { // 0x6be642: e819990400 CALL 0x00707f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707f60u,7071303u); flags=s.arithmetic_flags;
  }
  L006be647: { // 0x6be647: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be649: { // 0x6be649: 740e JZ 0x006be659
    if(integer::condition("JZ",flags)) goto L006be659;
  }
  L006be64b: { // 0x6be64b: 8a8772020000 MOV AL,byte ptr [EDI + 0x272]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000272u)));
  }
  L006be651: { // 0x6be651: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be653: { // 0x6be653: 0f8593000000 JNZ 0x006be6ec
    if(integer::condition("JNZ",flags)) goto L006be6ec;
  }
  L006be659: { // 0x6be659: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L006be65b: { // 0x6be65b: e880990400 CALL 0x00707fe0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00707fe0u,7071328u); flags=s.arithmetic_flags;
  }
  L006be660: { // 0x6be660: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be662: { // 0x6be662: 7414 JZ 0x006be678
    if(integer::condition("JZ",flags)) goto L006be678;
  }
  L006be664: { // 0x6be664: 8a8772020000 MOV AL,byte ptr [EDI + 0x272]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000272u)));
  }
  L006be66a: { // 0x6be66a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be66c: { // 0x6be66c: 757e JNZ 0x006be6ec
    if(integer::condition("JNZ",flags)) goto L006be6ec;
  }
  L006be66e: { // 0x6be66e: 8a8784020000 MOV AL,byte ptr [EDI + 0x284]
    s.ax = with_al(s.ax, m.r8((s.di+0x00000284u)));
  }
  L006be674: { // 0x6be674: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be676: { // 0x6be676: 7574 JNZ 0x006be6ec
    if(integer::condition("JNZ",flags)) goto L006be6ec;
  }
  L006be678: { // 0x6be678: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006be67a: { // 0x6be67a: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L006be67e: { // 0x6be67e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006be67f: { // 0x6be67f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be681: { // 0x6be681: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),7071364u); flags=s.arithmetic_flags;
  }
  L006be684: { // 0x6be684: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006be686: { // 0x6be686: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L006be688: { // 0x6be688: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006be689: { // 0x6be689: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006be68f: { // 0x6be68f: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006be691: { // 0x6be691: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006be694: { // 0x6be694: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  L006be699: { // 0x6be699: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L006be69c: { // 0x6be69c: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006be69d: { // 0x6be69d: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L006be6a3: { // 0x6be6a3: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L006be6a5: { // 0x6be6a5: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L006be6a8: { // 0x6be6a8: 668944240e MOV word ptr [ESP + 0xe],AX
    m.w16((f.sp+0x0000000eu), (s.ax & 0xffffu));
  }
  L006be6ad: { // 0x6be6ad: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L006be6b1: { // 0x6be6b1: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  L006be6b7: { // 0x6be6b7: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006be6bb: { // 0x6be6bb: 8d542410 LEA EDX,[ESP + 0x10]
    s.dx = (f.sp+0x00000010u);
  }
  L006be6bf: { // 0x6be6bf: 8b4830 MOV ECX,dword ptr [EAX + 0x30]
    s.cx = m.r32((s.ax+0x00000030u));
  }
  L006be6c2: { // 0x6be6c2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006be6c3: { // 0x6be6c3: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006be6c4: { // 0x6be6c4: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006be6c9: { // 0x6be6c9: e8326ee8ff CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,7071438u); flags=s.arithmetic_flags;
  }
  L006be6ce: { // 0x6be6ce: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006be6d0: { // 0x6be6d0: e8ebd7dbff CALL 0x0047bec0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047bec0u,7071445u); flags=s.arithmetic_flags;
  }
  L006be6d5: { // 0x6be6d5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be6d7: { // 0x6be6d7: 7513 JNZ 0x006be6ec
    if(integer::condition("JNZ",flags)) goto L006be6ec;
  }
  L006be6d9: { // 0x6be6d9: 8a862a030000 MOV AL,byte ptr [ESI + 0x32a]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000032au)));
  }
  L006be6df: { // 0x6be6df: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be6e1: { // 0x6be6e1: 7509 JNZ 0x006be6ec
    if(integer::condition("JNZ",flags)) goto L006be6ec;
  }
  L006be6e3: { // 0x6be6e3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be6e4: { // 0x6be6e4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be6e5: { // 0x6be6e5: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be6e7: { // 0x6be6e7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be6e8: { // 0x6be6e8: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be6eb: { // 0x6be6eb: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006be6ec: { // 0x6be6ec: 83beb801000002 CMP dword ptr [ESI + 0x1b8],0x2
    (void)integer::sub(m.r32((s.si+0x000001b8u)),0x00000002u,32,flags);
  }
  L006be6f3: { // 0x6be6f3: 7509 JNZ 0x006be6fe
    if(integer::condition("JNZ",flags)) goto L006be6fe;
  }
  L006be6f5: { // 0x6be6f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be6f6: { // 0x6be6f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be6f7: { // 0x6be6f7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be6f9: { // 0x6be6f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be6fa: { // 0x6be6fa: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be6fd: { // 0x6be6fd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006be6fe: { // 0x6be6fe: 8b9644020000 MOV EDX,dword ptr [ESI + 0x244]
    s.dx = m.r32((s.si+0x00000244u));
  }
  L006be704: { // 0x6be704: 8b864c020000 MOV EAX,dword ptr [ESI + 0x24c]
    s.ax = m.r32((s.si+0x0000024cu));
  }
  L006be70a: { // 0x6be70a: 83faff CMP EDX,-0x1
    (void)integer::sub(s.dx,0xffffffffu,32,flags);
  }
  L006be70d: { // 0x6be70d: 740e JZ 0x006be71d
    if(integer::condition("JZ",flags)) goto L006be71d;
  }
  L006be70f: { // 0x6be70f: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006be715: { // 0x6be715: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L006be717: { // 0x6be717: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006be719: { // 0x6be719: 7d0f JGE 0x006be72a
    if(integer::condition("JGE",flags)) goto L006be72a;
  }
  L006be71b: { // 0x6be71b: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006be71d: { // 0x6be71d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006be71f: { // 0x6be71f: 7409 JZ 0x006be72a
    if(integer::condition("JZ",flags)) goto L006be72a;
  }
  L006be721: { // 0x6be721: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be722: { // 0x6be722: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be723: { // 0x6be723: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be725: { // 0x6be725: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be726: { // 0x6be726: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be729: { // 0x6be729: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006be72a: { // 0x6be72a: 8b8628020000 MOV EAX,dword ptr [ESI + 0x228]
    s.ax = m.r32((s.si+0x00000228u));
  }
  L006be730: { // 0x6be730: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006be732: { // 0x6be732: 7418 JZ 0x006be74c
    if(integer::condition("JZ",flags)) goto L006be74c;
  }
  L006be734: { // 0x6be734: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L006be736: { // 0x6be736: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006be737: { // 0x6be737: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be739: { // 0x6be739: ff9254030000 CALL dword ptr [EDX + 0x354]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000354u)),7071551u); flags=s.arithmetic_flags;
  }
  L006be73f: { // 0x6be73f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006be741: { // 0x6be741: 7409 JZ 0x006be74c
    if(integer::condition("JZ",flags)) goto L006be74c;
  }
  L006be743: { // 0x6be743: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be744: { // 0x6be744: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be745: { // 0x6be745: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be747: { // 0x6be747: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be748: { // 0x6be748: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be74b: { // 0x6be74b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006be74c: { // 0x6be74c: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006be74e: { // 0x6be74e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006be750: { // 0x6be750: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),7071571u); flags=s.arithmetic_flags;
  }
  L006be753: { // 0x6be753: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L006be756: { // 0x6be756: 7413 JZ 0x006be76b
    if(integer::condition("JZ",flags)) goto L006be76b;
  }
  L006be758: { // 0x6be758: 8b86bc010000 MOV EAX,dword ptr [ESI + 0x1bc]
    s.ax = m.r32((s.si+0x000001bcu));
  }
  L006be75e: { // 0x6be75e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006be760: { // 0x6be760: 7409 JZ 0x006be76b
    if(integer::condition("JZ",flags)) goto L006be76b;
  }
  L006be762: { // 0x6be762: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be763: { // 0x6be763: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be764: { // 0x6be764: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be766: { // 0x6be766: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be767: { // 0x6be767: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be76a: { // 0x6be76a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006be76b: { // 0x6be76b: 8b86dc010000 MOV EAX,dword ptr [ESI + 0x1dc]
    s.ax = m.r32((s.si+0x000001dcu));
  }
  L006be771: { // 0x6be771: 8bb6d4010000 MOV ESI,dword ptr [ESI + 0x1d4]
    s.si = m.r32((s.si+0x000001d4u));
  }
  L006be777: { // 0x6be777: 83feff CMP ESI,-0x1
    (void)integer::sub(s.si,0xffffffffu,32,flags);
  }
  L006be77a: { // 0x6be77a: 740e JZ 0x006be78a
    if(integer::condition("JZ",flags)) goto L006be78a;
  }
  L006be77c: { // 0x6be77c: 8b0d6c89a200 MOV ECX,dword ptr [0x00a2896c]
    s.cx = m.r32((0x00a2896cu));
  }
  L006be782: { // 0x6be782: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L006be784: { // 0x6be784: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006be786: { // 0x6be786: 7d0f JGE 0x006be797
    if(integer::condition("JGE",flags)) goto L006be797;
  }
  L006be788: { // 0x6be788: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006be78a: { // 0x6be78a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L006be78c: { // 0x6be78c: 7409 JZ 0x006be797
    if(integer::condition("JZ",flags)) goto L006be797;
  }
  L006be78e: { // 0x6be78e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be78f: { // 0x6be78f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be790: { // 0x6be790: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006be792: { // 0x6be792: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be793: { // 0x6be793: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be796: { // 0x6be796: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006be797: { // 0x6be797: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006be798: { // 0x6be798: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006be799: { // 0x6be799: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L006be79b: { // 0x6be79b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006be79c: { // 0x6be79c: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L006be79f: { // 0x6be79f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
