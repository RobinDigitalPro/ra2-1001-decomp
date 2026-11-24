#include "platform/x87_integer_subtract_b42.hpp"
#include "recovered/recovery_b727_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b727 {
namespace {
void f_000440d0(Memory&,State&,Frame&,const Operations&);
void f_00043e10(Memory&,State&,Frame&,const Operations&);
void f_000585b0(Memory&,State&,Frame&,const Operations&);
void f_000585c0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_000440d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004440d0: { // 0x4440d0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004440d6: { // 0x4440d6: 83ec0c SUB ESP, 0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L004440d9: { // 0x4440d9: 8a9065130000 MOV DL, byte ptr [EAX + 0x1365]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00001365u)));
  }
  L004440df: { // 0x4440df: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004440e0: { // 0x4440e0: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L004440e2: { // 0x4440e2: 7414 JZ 0x4440f8
    if(integer::condition("JZ",flags)) goto L004440f8;
  }
  L004440e4: { // 0x4440e4: 8b542418 MOV EDX, dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L004440e8: { // 0x4440e8: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L004440ea: { // 0x4440ea: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004440eb: { // 0x4440eb: 8d542408 LEA EDX, [ESP + 8]
    s.dx = (f.sp+8u);
  }
  L004440ef: { // 0x4440ef: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L004440f0: { // 0x4440f0: ff90a4000000 CALL dword ptr [EAX + 0xa4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x000000a4u)),4473078u); flags=s.arithmetic_flags;
  }
  L004440f6: { // 0x4440f6: eb26 JMP 0x44411e
    goto L0044411e;
  }
  L004440f8: { // 0x4440f8: 8a9049130000 MOV DL, byte ptr [EAX + 0x1349]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00001349u)));
  }
  L004440fe: { // 0x4440fe: 84d2 TEST DL, DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00444100: { // 0x444100: 8b11 MOV EDX, dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00444102: { // 0x444102: 7412 JZ 0x444116
    if(integer::condition("JZ",flags)) goto L00444116;
  }
  L00444104: { // 0x444104: 8b442418 MOV EAX, dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00444108: { // 0x444108: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00444109: { // 0x444109: 8d442408 LEA EAX, [ESP + 8]
    s.ax = (f.sp+8u);
  }
  L0044410d: { // 0x44410d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044410e: { // 0x44410e: ff92a4000000 CALL dword ptr [EDX + 0xa4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000000a4u)),4473108u); flags=s.arithmetic_flags;
  }
  L00444114: { // 0x444114: eb08 JMP 0x44411e
    goto L0044411e;
  }
  L00444116: { // 0x444116: 8d442404 LEA EAX, [ESP + 4]
    s.ax = (f.sp+4u);
  }
  L0044411a: { // 0x44411a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0044411b: { // 0x44411b: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),4473118u); flags=s.arithmetic_flags;
  }
  L0044411e: { // 0x44411e: 8bc8 MOV ECX, EAX
    s.cx = s.ax;
  }
  L00444120: { // 0x444120: 8b442414 MOV EAX, dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00444124: { // 0x444124: 8bd0 MOV EDX, EAX
    s.dx = s.ax;
  }
  L00444126: { // 0x444126: 8b31 MOV ESI, dword ptr [ECX]
    s.si = m.r32((s.cx));
  }
  L00444128: { // 0x444128: 8932 MOV dword ptr [EDX], ESI
    m.w32((s.dx), s.si);
  }
  L0044412a: { // 0x44412a: 8b7104 MOV ESI, dword ptr [ECX + 4]
    s.si = m.r32((s.cx+4u));
  }
  L0044412d: { // 0x44412d: 897204 MOV dword ptr [EDX + 4], ESI
    m.w32((s.dx+4u), s.si);
  }
  L00444130: { // 0x444130: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00444131: { // 0x444131: 8b4908 MOV ECX, dword ptr [ECX + 8]
    s.cx = m.r32((s.cx+8u));
  }
  L00444134: { // 0x444134: 894a08 MOV dword ptr [EDX + 8], ECX
    m.w32((s.dx+8u), s.cx);
  }
  L00444137: { // 0x444137: 83c40c ADD ESP, 0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0044413a: { // 0x44413a: c20800 RET 8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
  L00443e12: { // 0x443e12: 8bf9 MOV EDI, ECX
    s.di = s.cx;
  }
  L00443e14: { // 0x443e14: 6a00 PUSH 0
    f.push(m,0u);
  }
  L00443e16: { // 0x443e16: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e1c: { // 0x443e1c: e89f470100 CALL 0x4585c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585c0u,4472353u); flags=s.arithmetic_flags;
  }
  L00443e21: { // 0x443e21: 8b8f18040000 MOV ECX, dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00443e27: { // 0x443e27: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00443e29: { // 0x443e29: c1e607 SHL ESI, 7
    s.si = integer::shift(s.si,7u,32,flags,integer::Shift::left);
  }
  L00443e2c: { // 0x443e2c: 81ee80000000 SUB ESI, 0x80
    s.si = integer::sub(s.si,0x00000080u,32,flags);
  }
  L00443e32: { // 0x443e32: e879470100 CALL 0x4585b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004585b0u,4472375u); flags=s.arithmetic_flags;
  }
  L00443e37: { // 0x443e37: 81c788000000 ADD EDI, 0x88
    s.di = integer::add(s.di,0x00000088u,32,flags);
  }
  L00443e3d: { // 0x443e3d: c1e007 SHL EAX, 7
    s.ax = integer::shift(s.ax,7u,32,flags,integer::Shift::left);
  }
  L00443e40: { // 0x443e40: 8b0f MOV ECX, dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00443e42: { // 0x443e42: 2d80000000 SUB EAX, 0x80
    s.ax = integer::sub(s.ax,0x00000080u,32,flags);
  }
  L00443e47: { // 0x443e47: 03c8 ADD ECX, EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00443e49: { // 0x443e49: 8b44240c MOV EAX, dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L00443e4d: { // 0x443e4d: 8b5704 MOV EDX, dword ptr [EDI + 4]
    s.dx = m.r32((s.di+4u));
  }
  L00443e50: { // 0x443e50: 03d6 ADD EDX, ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L00443e52: { // 0x443e52: 8bf0 MOV ESI, EAX
    s.si = s.ax;
  }
  L00443e54: { // 0x443e54: 8b7f08 MOV EDI, dword ptr [EDI + 8]
    s.di = m.r32((s.di+8u));
  }
  L00443e57: { // 0x443e57: 890e MOV dword ptr [ESI], ECX
    m.w32((s.si), s.cx);
  }
  L00443e59: { // 0x443e59: 895604 MOV dword ptr [ESI + 4], EDX
    m.w32((s.si+4u), s.dx);
  }
  L00443e5c: { // 0x443e5c: 897e08 MOV dword ptr [ESI + 8], EDI
    m.w32((s.si+8u), s.di);
  }
  L00443e5f: { // 0x443e5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00443e60: { // 0x443e60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00443e61: { // 0x443e61: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
void f_000585b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585b0: { // 0x4585b0: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585b6: { // 0x4585b6: 8b048508ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac08]
    s.ax = m.r32(((s.ax * 4u)+0x007bac08u));
  }
  L004585bd: { // 0x4585bd: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000585c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004585c0: { // 0x4585c0: 8a442404 MOV AL, byte ptr [ESP + 4]
    s.ax = with_al(s.ax, m.r8((f.sp+4u)));
  }
  L004585c4: { // 0x4585c4: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585c6: { // 0x4585c6: 7421 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585c8: { // 0x4585c8: 8a8114120000 MOV AL, byte ptr [ECX + 0x1214]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001214u)));
  }
  L004585ce: { // 0x4585ce: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L004585d0: { // 0x4585d0: 7417 JZ 0x4585e9
    if(integer::condition("JZ",flags)) goto L004585e9;
  }
  L004585d2: { // 0x4585d2: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585d8: { // 0x4585d8: ba01000000 MOV EDX, 1
    s.dx = 1u;
  }
  L004585dd: { // 0x4585dd: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585e4: { // 0x4585e4: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585e6: { // 0x4585e6: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L004585e9: { // 0x4585e9: 8b81780c0000 MOV EAX, dword ptr [ECX + 0xc78]
    s.ax = m.r32((s.cx+0x00000c78u));
  }
  L004585ef: { // 0x4585ef: 33d2 XOR EDX, EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004585f1: { // 0x4585f1: 8b048560ac7b00 MOV EAX, dword ptr [EAX*4 + 0x7bac60]
    s.ax = m.r32(((s.ax * 4u)+0x007bac60u));
  }
  L004585f8: { // 0x4585f8: 03c2 ADD EAX, EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L004585fa: { // 0x4585fa: c20400 RET 4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4473040u:f_000440d0(m,s,child,{});break;
case 4472336u:f_00043e10(m,s,child,{});break;
case 4556208u:f_000585b0(m,s,child,{});break;
case 4556224u:f_000585c0(m,s,child,{});break;
default:throw std::domain_error("recovery727 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0062a120(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062a120: { // 0x62a120: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L0062a123: { // 0x62a123: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0062a127: { // 0x62a127: 8b8198140000 MOV EAX,dword ptr [ECX + 0x1498]
    s.ax = m.r32((s.cx+0x00001498u));
  }
  L0062a12d: { // 0x62a12d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062a12e: { // 0x62a12e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062a12f: { // 0x62a12f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062a130: { // 0x62a130: 8b32 MOV ESI,dword ptr [EDX]
    s.si = m.r32((s.dx));
  }
  L0062a132: { // 0x62a132: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L0062a135: { // 0x62a135: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062a136: { // 0x62a136: 8bb99c140000 MOV EDI,dword ptr [ECX + 0x149c]
    s.di = m.r32((s.cx+0x0000149cu));
  }
  L0062a13c: { // 0x62a13c: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0062a13e: { // 0x62a13e: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0062a140: { // 0x62a140: 8b5c2430 MOV EBX,dword ptr [ESP + 0x30]
    s.bx = m.r32((f.sp+0x00000030u));
  }
  L0062a144: { // 0x62a144: 89742410 MOV dword ptr [ESP + 0x10],ESI
    m.w32((f.sp+0x00000010u), s.si);
  }
  L0062a148: { // 0x62a148: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0062a14c: { // 0x62a14c: 8d0492 LEA EAX,[EDX + EDX*0x4]
    s.ax = (s.dx+(s.dx * 0x00000004u));
  }
  L0062a14f: { // 0x62a14f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0062a151: { // 0x62a151: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062a153: { // 0x62a153: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L0062a155: { // 0x62a155: 8bb954120000 MOV EDI,dword ptr [ECX + 0x1254]
    s.di = m.r32((s.cx+0x00001254u));
  }
  L0062a15b: { // 0x62a15b: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  L0062a160: { // 0x62a160: 8b3f MOV EDI,dword ptr [EDI]
    s.di = m.r32((s.di));
  }
  L0062a162: { // 0x62a162: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  L0062a165: { // 0x62a165: 8d3cc7 LEA EDI,[EDI + EAX*0x8]
    s.di = (s.di+(s.ax * 0x00000008u));
  }
  L0062a168: { // 0x62a168: 8b4710 MOV EAX,dword ptr [EDI + 0x10]
    s.ax = m.r32((s.di+0x00000010u));
  }
  L0062a16b: { // 0x62a16b: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  L0062a171: { // 0x62a171: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062a172: { // 0x62a172: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062a174: { // 0x62a174: 7c35 JL 0x0062a1ab
    if(integer::condition("JL",flags)) goto L0062a1ab;
  }
  L0062a176: { // 0x62a176: 8b7f04 MOV EDI,dword ptr [EDI + 0x4]
    s.di = m.r32((s.di+0x00000004u));
  }
  L0062a179: { // 0x62a179: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062a17b: { // 0x62a17b: c1e304 SHL EBX,0x4
    s.bx = integer::shift(s.bx,0x00000004u,32,flags,integer::Shift::left);
  }
  L0062a17e: { // 0x62a17e: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L0062a180: { // 0x62a180: 8d7b04 LEA EDI,[EBX + 0x4]
    s.di = (s.bx+0x00000004u);
  }
  L0062a183: { // 0x62a183: 8b2b MOV EBP,dword ptr [EBX]
    s.bp = m.r32((s.bx));
  }
  L0062a185: { // 0x62a185: 896c2418 MOV dword ptr [ESP + 0x18],EBP
    m.w32((f.sp+0x00000018u), s.bp);
  }
  L0062a189: { // 0x62a189: 8b2f MOV EBP,dword ptr [EDI]
    s.bp = m.r32((s.di));
  }
  L0062a18b: { // 0x62a18b: 3bee CMP EBP,ESI
    (void)integer::sub(s.bp,s.si,32,flags);
  }
  L0062a18d: { // 0x62a18d: 7505 JNZ 0x0062a194
    if(integer::condition("JNZ",flags)) goto L0062a194;
  }
  L0062a18f: { // 0x62a18f: 395704 CMP dword ptr [EDI + 0x4],EDX
    (void)integer::sub(m.r32((s.di+0x00000004u)),s.dx,32,flags);
  }
  L0062a192: { // 0x62a192: 740d JZ 0x0062a1a1
    if(integer::condition("JZ",flags)) goto L0062a1a1;
  }
  L0062a194: { // 0x62a194: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0062a195: { // 0x62a195: 83eb10 SUB EBX,0x10
    s.bx = integer::sub(s.bx,0x00000010u,32,flags);
  }
  L0062a198: { // 0x62a198: 83ef10 SUB EDI,0x10
    s.di = integer::sub(s.di,0x00000010u,32,flags);
  }
  L0062a19b: { // 0x62a19b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062a19d: { // 0x62a19d: 7c0c JL 0x0062a1ab
    if(integer::condition("JL",flags)) goto L0062a1ab;
  }
  L0062a19f: { // 0x62a19f: ebe2 JMP 0x0062a183
    goto L0062a183;
  }
  L0062a1a1: { // 0x62a1a1: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L0062a1a5: { // 0x62a1a5: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0062a1a9: { // 0x62a1a9: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L0062a1ab: { // 0x62a1ab: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0062a1af: { // 0x62a1af: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062a1b0: { // 0x62a1b0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062a1b1: { // 0x62a1b1: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062a1b2: { // 0x62a1b2: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  L0062a1b4: { // 0x62a1b4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062a1b5: { // 0x62a1b5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0062a1b7: { // 0x62a1b7: 7447 JZ 0x0062a200
    if(integer::condition("JZ",flags)) goto L0062a200;
  }
  L0062a1b9: { // 0x62a1b9: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0062a1bb: { // 0x62a1bb: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L0062a1bf: { // 0x62a1bf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0062a1c1: { // 0x62a1c1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0062a1c2: { // 0x62a1c2: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062a1c4: { // 0x62a1c4: ff524c CALL dword ptr [EDX + 0x4c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000004cu)),6463943u); flags=s.arithmetic_flags;
  }
  L0062a1c7: { // 0x62a1c7: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062a1c9: { // 0x62a1c9: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0062a1cb: { // 0x62a1cb: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0062a1cc: { // 0x62a1cc: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0062a1d2: { // 0x62a1d2: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0062a1d4: { // 0x62a1d4: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0062a1d7: { // 0x62a1d7: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0062a1dc: { // 0x62a1dc: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062a1df: { // 0x62a1df: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0062a1e0: { // 0x62a1e0: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0062a1e6: { // 0x62a1e6: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0062a1e8: { // 0x62a1e8: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0062a1ec: { // 0x62a1ec: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0062a1ef: { // 0x62a1ef: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L0062a1f4: { // 0x62a1f4: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0062a1f8: { // 0x62a1f8: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L0062a1fa: { // 0x62a1fa: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0062a1fd: { // 0x62a1fd: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0062a200: { // 0x62a200: db442400 FILD dword ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a204: { // 0x62a204: d8b184140000 FDIV float ptr [ECX + 0x1484]
    const auto address=(s.cx+0x00001484u);
    floating_b61::fp_extended::divide32(s.fp,m.r32(address));
  }
  L0062a20a: { // 0x62a20a: daa18c140000 FISUB dword ptr [ECX + 0x148c]
    ra2::platform::x87_integer_subtract::subtract_integer32(s.fp,m.r32((s.cx+0x0000148cu)));
  }
  L0062a210: { // 0x62a210: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L0062a214: { // 0x62a214: d8b184140000 FDIV float ptr [ECX + 0x1484]
    const auto address=(s.cx+0x00001484u);
    floating_b61::fp_extended::divide32(s.fp,m.r32(address));
  }
  L0062a21a: { // 0x62a21a: da8194140000 FIADD dword ptr [ECX + 0x1494]
    const auto address=(s.cx+0x00001494u);
    floating_b61::fp_extended::add_integer32(s.fp,m.r32(address));
  }
  L0062a220: { // 0x62a220: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0062a222: { // 0x62a222: d8c2 FADD ST0,ST2
    numeric_b88::detail::reg<0xd8c2>(s.fp);
  }
  L0062a224: { // 0x62a224: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a22a: { // 0x62a22a: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L0062a230: { // 0x62a230: e81b081400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6464053u); flags=s.arithmetic_flags;
  }
  L0062a235: { // 0x62a235: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L0062a237: { // 0x62a237: 6689442420 MOV word ptr [ESP + 0x20],AX
    m.w16((f.sp+0x00000020u), (s.ax & 0xffffu));
  }
  L0062a23c: { // 0x62a23c: d80d808d7800 FMUL float ptr [0x00788d80]
    const auto address=(0x00788d80u);
    s.fp.multiply32(m.r32(address));
  }
  L0062a242: { // 0x62a242: dc0528577800 FADD double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.add64(read64(m,address));
  }
  L0062a248: { // 0x62a248: e803081400 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6464077u); flags=s.arithmetic_flags;
  }
  L0062a24d: { // 0x62a24d: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0062a251: { // 0x62a251: 6689442422 MOV word ptr [ESP + 0x22],AX
    m.w16((f.sp+0x00000022u), (s.ax & 0xffffu));
  }
  L0062a256: { // 0x62a256: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0062a25a: { // 0x62a25a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0062a25c: { // 0x62a25c: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L0062a25e: { // 0x62a25e: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L0062a261: { // 0x62a261: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
