#include "recovered/recovery_b590_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b590 {
namespace {
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void f_00147f40(Memory&,State&,Frame&,const Operations&);
void f_00145500(Memory&,State&,Frame&,const Operations&);
void f_00078320(Memory&,State&,Frame&,const Operations&);
void f_00053890(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
void f_00147f40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00547f40: { // 0x547f40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00547f44: { // 0x547f44: 8b91f0000000 MOV EDX,dword ptr [ECX + 0xf0]
    s.dx = m.r32((s.cx+0x000000f0u));
  }
  L00547f4a: { // 0x547f4a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00547f4b: { // 0x547f4b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00547f4c: { // 0x547f4c: 0fbf30 MOVSX ESI,word ptr [EAX]
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.ax)),16));
  }
  L00547f4f: { // 0x547f4f: 0fbf4002 MOVSX EAX,word ptr [EAX + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L00547f53: { // 0x547f53: 8d3c30 LEA EDI,[EAX + ESI*0x1]
    s.di = (s.ax+(s.si * 0x00000001u));
  }
  L00547f56: { // 0x547f56: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L00547f58: { // 0x547f58: 7e24 JLE 0x00547f7e
    if(integer::condition("JLE",flags)) goto L00547f7e;
  }
  L00547f5a: { // 0x547f5a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00547f5b: { // 0x547f5b: 8bde MOV EBX,ESI
    s.bx = s.si;
  }
  L00547f5d: { // 0x547f5d: 2bd8 SUB EBX,EAX
    s.bx = integer::sub(s.bx,s.ax,32,flags);
  }
  L00547f5f: { // 0x547f5f: 3bda CMP EBX,EDX
    (void)integer::sub(s.bx,s.dx,32,flags);
  }
  L00547f61: { // 0x547f61: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00547f62: { // 0x547f62: 7d1a JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f64: { // 0x547f64: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00547f66: { // 0x547f66: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00547f68: { // 0x547f68: 7d14 JGE 0x00547f7e
    if(integer::condition("JGE",flags)) goto L00547f7e;
  }
  L00547f6a: { // 0x547f6a: 8b81f4000000 MOV EAX,dword ptr [ECX + 0xf4]
    s.ax = m.r32((s.cx+0x000000f4u));
  }
  L00547f70: { // 0x547f70: 8d0c42 LEA ECX,[EDX + EAX*0x2]
    s.cx = (s.dx+(s.ax * 0x00000002u));
  }
  L00547f73: { // 0x547f73: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L00547f75: { // 0x547f75: 7f07 JG 0x00547f7e
    if(integer::condition("JG",flags)) goto L00547f7e;
  }
  L00547f77: { // 0x547f77: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f78: { // 0x547f78: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00547f7a: { // 0x547f7a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f7b: { // 0x547f7b: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L00547f7e: { // 0x547f7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00547f7f: { // 0x547f7f: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00547f81: { // 0x547f81: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00547f82: { // 0x547f82: c20400 RET 0x4
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
void f_00078320(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00478320: { // 0x478320: 8b8140010000 MOV EAX,dword ptr [ECX + 0x140]
    s.ax = m.r32((s.cx+0x00000140u));
  }
  L00478326: { // 0x478326: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L00478328: { // 0x478328: 7412 JZ 0x0047833c
    if(integer::condition("JZ",flags)) goto L0047833c;
  }
  L0047832a: { // 0x47832a: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L0047832c: { // 0x47832c: c74150ffffffff MOV dword ptr [ECX + 0x50],0xffffffff
    m.w32((s.cx+0x00000050u), 0xffffffffu);
  }
  L00478333: { // 0x478333: 898140010000 MOV dword ptr [ECX + 0x140],EAX
    m.w32((s.cx+0x00000140u), s.ax);
  }
  L00478339: { // 0x478339: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0047833b: { // 0x47833b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0047833c: { // 0x47833c: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0047833e: { // 0x47833e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00053890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00453890: { // 0x453890: b806000000 MOV EAX,0x6
    s.ax = 0x00000006u;
  }
  L00453895: { // 0x453895: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4472336u:f_00043e10(m,s,child,{});break;
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
case 5537600u:f_00147f40(m,s,child,{});break;
case 5526784u:f_00145500(m,s,child,{});break;
case 4686624u:f_00078320(m,s,child,{});break;
case 4536464u:f_00053890(m,s,child,{});break;
default:throw std::domain_error("recovery590 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_004e6b70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004e6b70: { // 0x4e6b70: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L004e6b73: { // 0x4e6b73: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004e6b74: { // 0x4e6b74: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e6b75: { // 0x4e6b75: 8b74241c MOV ESI,dword ptr [ESP + 0x1c]
    s.si = m.r32((f.sp+0x0000001cu));
  }
  L004e6b79: { // 0x4e6b79: 32db XOR BL,BL
    s.bx = with_al(s.bx, integer::logical(((s.bx & 0xffu))^((s.bx & 0xffu)),8,flags));
  }
  L004e6b7b: { // 0x4e6b7b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004e6b7c: { // 0x4e6b7c: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L004e6b7e: { // 0x4e6b7e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L004e6b80: { // 0x4e6b80: 0f84f8000000 JZ 0x004e6c7e
    if(integer::condition("JZ",flags)) goto L004e6c7e;
  }
  L004e6b86: { // 0x4e6b86: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004e6b88: { // 0x4e6b88: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e6b8a: { // 0x4e6b8a: ff502c CALL dword ptr [EAX + 0x2c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000002cu)),5139341u); flags=s.arithmetic_flags;
  }
  L004e6b8d: { // 0x4e6b8d: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L004e6b90: { // 0x4e6b90: 751f JNZ 0x004e6bb1
    if(integer::condition("JNZ",flags)) goto L004e6bb1;
  }
  L004e6b92: { // 0x4e6b92: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e6b94: { // 0x4e6b94: e8d72a2100 CALL 0x006f9670
    s.arithmetic_flags=flags; invoke(m,s,f,0x006f9670u,5139353u); flags=s.arithmetic_flags;
  }
  L004e6b99: { // 0x4e6b99: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L004e6b9b: { // 0x4e6b9b: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e6b9d: { // 0x4e6b9d: 0f848c000000 JZ 0x004e6c2f
    if(integer::condition("JZ",flags)) goto L004e6c2f;
  }
  L004e6ba3: { // 0x4e6ba3: 39b708530000 CMP dword ptr [EDI + 0x5308],ESI
    (void)integer::sub(m.r32((s.di+0x00005308u)),s.si,32,flags);
  }
  L004e6ba9: { // 0x4e6ba9: 0f8580000000 JNZ 0x004e6c2f
    if(integer::condition("JNZ",flags)) goto L004e6c2f;
  }
  L004e6baf: { // 0x4e6baf: eb74 JMP 0x004e6c25
    goto L004e6c25;
  }
  L004e6bb1: { // 0x4e6bb1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L004e6bb3: { // 0x4e6bb3: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L004e6bb7: { // 0x4e6bb7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6bb8: { // 0x4e6bb8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004e6bba: { // 0x4e6bba: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),5139389u); flags=s.arithmetic_flags;
  }
  L004e6bbd: { // 0x4e6bbd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004e6bbf: { // 0x4e6bbf: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004e6bc1: { // 0x4e6bc1: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004e6bc2: { // 0x4e6bc2: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004e6bc8: { // 0x4e6bc8: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004e6bca: { // 0x4e6bca: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004e6bcd: { // 0x4e6bcd: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L004e6bd2: { // 0x4e6bd2: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004e6bd5: { // 0x4e6bd5: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L004e6bd6: { // 0x4e6bd6: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L004e6bdc: { // 0x4e6bdc: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004e6bde: { // 0x4e6bde: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  L004e6be2: { // 0x4e6be2: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L004e6be5: { // 0x4e6be5: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L004e6bea: { // 0x4e6bea: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L004e6bee: { // 0x4e6bee: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  L004e6bf2: { // 0x4e6bf2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004e6bf3: { // 0x4e6bf3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6bf8: { // 0x4e6bf8: e843130600 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5139453u); flags=s.arithmetic_flags;
  }
  L004e6bfd: { // 0x4e6bfd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e6bff: { // 0x4e6bff: 742e JZ 0x004e6c2f
    if(integer::condition("JZ",flags)) goto L004e6c2f;
  }
  L004e6c01: { // 0x4e6c01: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  L004e6c05: { // 0x4e6c05: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6c0a: { // 0x4e6c0a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L004e6c0b: { // 0x4e6c0b: e8f0e80500 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5139472u); flags=s.arithmetic_flags;
  }
  L004e6c10: { // 0x4e6c10: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L004e6c12: { // 0x4e6c12: e80917f9ff CALL 0x00478320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00478320u,5139479u); flags=s.arithmetic_flags;
  }
  L004e6c17: { // 0x4e6c17: 8ad8 MOV BL,AL
    s.bx = with_al(s.bx, (s.ax & 0xffu));
  }
  L004e6c19: { // 0x4e6c19: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  L004e6c1b: { // 0x4e6c1b: 7412 JZ 0x004e6c2f
    if(integer::condition("JZ",flags)) goto L004e6c2f;
  }
  L004e6c1d: { // 0x4e6c1d: 39b708530000 CMP dword ptr [EDI + 0x5308],ESI
    (void)integer::sub(m.r32((s.di+0x00005308u)),s.si,32,flags);
  }
  L004e6c23: { // 0x4e6c23: 750a JNZ 0x004e6c2f
    if(integer::condition("JNZ",flags)) goto L004e6c2f;
  }
  L004e6c25: { // 0x4e6c25: c7870853000000000000 MOV dword ptr [EDI + 0x5308],0x0
    m.w32((s.di+0x00005308u), 0x00000000u);
  }
  L004e6c2f: { // 0x4e6c2f: 8a442424 MOV AL,byte ptr [ESP + 0x24]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000024u)));
  }
  L004e6c33: { // 0x4e6c33: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004e6c35: { // 0x4e6c35: 743c JZ 0x004e6c73
    if(integer::condition("JZ",flags)) goto L004e6c73;
  }
  L004e6c37: { // 0x4e6c37: 668b8f0c530000 MOV CX,word ptr [EDI + 0x530c]
    s.cx = with_ax(s.cx, m.r16((s.di+0x0000530cu)));
  }
  L004e6c3e: { // 0x4e6c3e: 8db70c530000 LEA ESI,[EDI + 0x530c]
    s.si = (s.di+0x0000530cu);
  }
  L004e6c44: { // 0x4e6c44: 663b0d5c8ba200 CMP CX,word ptr [0x00a28b5c]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a28b5cu)),16,flags);
  }
  L004e6c4b: { // 0x4e6c4b: 750d JNZ 0x004e6c5a
    if(integer::condition("JNZ",flags)) goto L004e6c5a;
  }
  L004e6c4d: { // 0x4e6c4d: 668b5602 MOV DX,word ptr [ESI + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.si+0x00000002u)));
  }
  L004e6c51: { // 0x4e6c51: 663b155e8ba200 CMP DX,word ptr [0x00a28b5e]
    (void)integer::sub((s.dx & 0xffffu),m.r16((0x00a28b5eu)),16,flags);
  }
  L004e6c58: { // 0x4e6c58: 7419 JZ 0x004e6c73
    if(integer::condition("JZ",flags)) goto L004e6c73;
  }
  L004e6c5a: { // 0x4e6c5a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004e6c5b: { // 0x4e6c5b: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L004e6c60: { // 0x4e6c60: e89be80500 CALL 0x00545500
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,5139557u); flags=s.arithmetic_flags;
  }
  L004e6c65: { // 0x4e6c65: c74044ffffffff MOV dword ptr [EAX + 0x44],0xffffffff
    m.w32((s.ax+0x00000044u), 0xffffffffu);
  }
  L004e6c6c: { // 0x4e6c6c: a15c8ba200 MOV EAX,[0x00a28b5c]
    s.ax = m.r32((0x00a28b5cu));
  }
  L004e6c71: { // 0x4e6c71: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L004e6c73: { // 0x4e6c73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e6c74: { // 0x4e6c74: 8ac3 MOV AL,BL
    s.ax = with_al(s.ax, (s.bx & 0xffu));
  }
  L004e6c76: { // 0x4e6c76: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e6c77: { // 0x4e6c77: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e6c78: { // 0x4e6c78: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e6c7b: { // 0x4e6c7b: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004e6c7e: { // 0x4e6c7e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004e6c7f: { // 0x4e6c7f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004e6c80: { // 0x4e6c80: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004e6c82: { // 0x4e6c82: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004e6c83: { // 0x4e6c83: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L004e6c86: { // 0x4e6c86: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
