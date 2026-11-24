#include "recovered/recovery_b108_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b108 {
namespace {
void f_00001f90(Memory&,State&,Frame&,const Operations&);
void f_00007380(Memory&,State&,Frame&,const Operations&);
void f_00007460(Memory&,State&,Frame&,const Operations&);
void f_0038048d(Memory&,State&,Frame&,const Operations&);
void f_0038042f(Memory&,State&,Frame&,const Operations&);
void f_0038040e(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00001f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00401f90: { // 0x401f90: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00401f93: { // 0x401f93: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00401f94: { // 0x401f94: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00401f96: { // 0x401f96: 89410c MOV dword ptr [ECX + 0xc],EAX
    m.w32((s.cx+0x0000000cu), s.ax);
  }
  L00401f99: { // 0x401f99: 7d07 JGE 0x00401fa2
    if(integer::condition("JGE",flags)) goto L00401fa2;
  }
  L00401f9b: { // 0x401f9b: c7410c00000000 MOV dword ptr [ECX + 0xc],0x0
    m.w32((s.cx+0x0000000cu), 0x00000000u);
  }
  L00401fa2: { // 0x401fa2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00007380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00407380: { // 0x407380: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L00407383: { // 0x407383: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00407385: { // 0x407385: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00407387: { // 0x407387: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00407389: { // 0x407389: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0040738c: { // 0x40738c: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  L0040738f: { // 0x40738f: 8909 MOV dword ptr [ECX],ECX
    m.w32((s.cx), s.cx);
  }
  L00407391: { // 0x407391: 894904 MOV dword ptr [ECX + 0x4],ECX
    m.w32((s.cx+0x00000004u), s.cx);
  }
  L00407394: { // 0x407394: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00007460(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00407460: { // 0x407460: 8d42f8 LEA EAX,[EDX + -0x8]
    s.ax = (s.dx-0x00000008u);
  }
  L00407463: { // 0x407463: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00407465: { // 0x407465: 8910 MOV dword ptr [EAX],EDX
    m.w32((s.ax), s.dx);
  }
  L00407467: { // 0x407467: 8901 MOV dword ptr [ECX],EAX
    m.w32((s.cx), s.ax);
  }
  L00407469: { // 0x407469: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}





void f_0038048d(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0078048d: { // 0x78048d: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00780491: { // 0x780491: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780492: { // 0x780492: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00780493: { // 0x780493: 8b30 MOV ESI,dword ptr [EAX]
    s.si = m.r32((s.ax));
  }
  L00780495: { // 0x780495: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00780498: { // 0x780498: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0078049a: { // 0x78049a: 03f6 ADD ESI,ESI
    s.si = integer::add(s.si,s.si,32,flags);
  }
  L0078049c: { // 0x78049c: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0078049e: { // 0x78049e: 8d343f LEA ESI,[EDI + EDI*0x1]
    s.si = (s.di+(s.di * 0x00000001u));
  }
  L007804a1: { // 0x7804a1: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L007804a4: { // 0x7804a4: 0bf1 OR ESI,ECX
    s.si = integer::logical((s.si)|(s.cx),32,flags);
  }
  L007804a6: { // 0x7804a6: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L007804a9: { // 0x7804a9: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  L007804ab: { // 0x7804ab: 897004 MOV dword ptr [EAX + 0x4],ESI
    m.w32((s.ax+0x00000004u), s.si);
  }
  L007804ae: { // 0x7804ae: c1ea1f SHR EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L007804b1: { // 0x7804b1: d1e1 SHL ECX,0x1
    s.cx = integer::shift(s.cx,0x00000001u,32,flags,integer::Shift::left);
  }
  L007804b3: { // 0x7804b3: 0bca OR ECX,EDX
    s.cx = integer::logical((s.cx)|(s.dx),32,flags);
  }
  L007804b5: { // 0x7804b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007804b6: { // 0x7804b6: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L007804b9: { // 0x7804b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007804ba: { // 0x7804ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0038042f(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0078042f: { // 0x78042f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780430: { // 0x780430: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  L00780434: { // 0x780434: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00780435: { // 0x780435: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00780439: { // 0x780439: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0078043a: { // 0x78043a: ff37 PUSH dword ptr [EDI]
    f.push(m,m.r32((s.di)));
  }
  L0078043c: { // 0x78043c: ff36 PUSH dword ptr [ESI]
    f.push(m,m.r32((s.si)));
  }
  L0078043e: { // 0x78043e: e8cbffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865411u); flags=s.arithmetic_flags;
  }
  L00780443: { // 0x780443: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00780446: { // 0x780446: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00780448: { // 0x780448: 7417 JZ 0x00780461
    if(integer::condition("JZ",flags)) goto L00780461;
  }
  L0078044a: { // 0x78044a: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L0078044d: { // 0x78044d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078044e: { // 0x78044e: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00780450: { // 0x780450: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  L00780452: { // 0x780452: e8b7ffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865431u); flags=s.arithmetic_flags;
  }
  L00780457: { // 0x780457: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0078045a: { // 0x78045a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0078045c: { // 0x78045c: 7403 JZ 0x00780461
    if(integer::condition("JZ",flags)) goto L00780461;
  }
  L0078045e: { // 0x78045e: ff4608 INC dword ptr [ESI + 0x8]
    m.w32((s.si+0x00000008u), integer::increment(m.r32((s.si+0x00000008u)),32,flags));
  }
  L00780461: { // 0x780461: 8d4604 LEA EAX,[ESI + 0x4]
    s.ax = (s.si+0x00000004u);
  }
  L00780464: { // 0x780464: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780465: { // 0x780465: ff7704 PUSH dword ptr [EDI + 0x4]
    f.push(m,m.r32((s.di+0x00000004u)));
  }
  L00780468: { // 0x780468: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  L0078046a: { // 0x78046a: e89fffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865455u); flags=s.arithmetic_flags;
  }
  L0078046f: { // 0x78046f: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L00780472: { // 0x780472: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00780474: { // 0x780474: 7403 JZ 0x00780479
    if(integer::condition("JZ",flags)) goto L00780479;
  }
  L00780476: { // 0x780476: ff4608 INC dword ptr [ESI + 0x8]
    m.w32((s.si+0x00000008u), integer::increment(m.r32((s.si+0x00000008u)),32,flags));
  }
  L00780479: { // 0x780479: 8d4608 LEA EAX,[ESI + 0x8]
    s.ax = (s.si+0x00000008u);
  }
  L0078047c: { // 0x78047c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0078047d: { // 0x78047d: ff7708 PUSH dword ptr [EDI + 0x8]
    f.push(m,m.r32((s.di+0x00000008u)));
  }
  L00780480: { // 0x780480: ff30 PUSH dword ptr [EAX]
    f.push(m,m.r32((s.ax)));
  }
  L00780482: { // 0x780482: e887ffffff CALL 0x0078040e
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078040eu,7865479u); flags=s.arithmetic_flags;
  }
  L00780487: { // 0x780487: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0078048a: { // 0x78048a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0078048b: { // 0x78048b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0078048c: { // 0x78048c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0038040e(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0078040e: { // 0x78040e: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  L00780412: { // 0x780412: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00780413: { // 0x780413: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L00780417: { // 0x780417: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L00780419: { // 0x780419: 8d0c32 LEA ECX,[EDX + ESI*0x1]
    s.cx = (s.dx+(s.si * 0x00000001u));
  }
  L0078041c: { // 0x78041c: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0078041e: { // 0x78041e: 7204 JC 0x00780424
    if(integer::condition("JC",flags)) goto L00780424;
  }
  L00780420: { // 0x780420: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00780422: { // 0x780422: 7303 JNC 0x00780427
    if(integer::condition("JNC",flags)) goto L00780427;
  }
  L00780424: { // 0x780424: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L00780426: { // 0x780426: 58 POP EAX
    const auto value=f.pop(m); s.ax = value;
  }
  L00780427: { // 0x780427: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0078042b: { // 0x78042b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0078042c: { // 0x78042c: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0078042e: { // 0x78042e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4202384u:f_00001f90(m,s,child,{});break;
case 4223872u:f_00007380(m,s,child,{});break;
case 4224096u:f_00007460(m,s,child,{});break;
case 7865485u:f_0038048d(m,s,child,{});break;
case 7865391u:f_0038042f(m,s,child,{});break;
case 7865358u:f_0038040e(m,s,child,{});break;
default:throw std::domain_error("recovery108 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00404e50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00404e50: { // 0x404e50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00404e51: { // 0x404e51: a1f8928100 MOV EAX,[0x008192f8]
    s.ax = m.r32((0x008192f8u));
  }
  L00404e56: { // 0x404e56: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00404e57: { // 0x404e57: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00404e59: { // 0x404e59: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00404e5a: { // 0x404e5a: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00404e5c: { // 0x404e5c: 0f843c010000 JZ 0x00404f9e
    if(integer::condition("JZ",flags)) goto L00404f9e;
  }
  L00404e62: { // 0x404e62: 8b35e0918100 MOV ESI,dword ptr [0x008191e0]
    s.si = m.r32((0x008191e0u));
  }
  L00404e68: { // 0x404e68: 81fee0918100 CMP ESI,0x8191e0
    (void)integer::sub(s.si,0x008191e0u,32,flags);
  }
  L00404e6e: { // 0x404e6e: 0f842a010000 JZ 0x00404f9e
    if(integer::condition("JZ",flags)) goto L00404f9e;
  }
  L00404e74: { // 0x404e74: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00404e75: { // 0x404e75: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00404e76: { // 0x404e76: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L00404e78: { // 0x404e78: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L00404e7c: { // 0x404e7c: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
  L00404e7f: { // 0x404e7f: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00404e81: { // 0x404e81: 0f85ce000000 JNZ 0x00404f55
    if(integer::condition("JNZ",flags)) goto L00404f55;
  }
  L00404e87: { // 0x404e87: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00404e8d: { // 0x404e8d: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00404e8f: { // 0x404e8f: 7478 JZ 0x00404f09
    if(integer::condition("JZ",flags)) goto L00404f09;
  }
  L00404e91: { // 0x404e91: 3bb1c0000000 CMP ESI,dword ptr [ECX + 0xc0]
    (void)integer::sub(s.si,m.r32((s.cx+0x000000c0u)),32,flags);
  }
  L00404e97: { // 0x404e97: 7570 JNZ 0x00404f09
    if(integer::condition("JNZ",flags)) goto L00404f09;
  }
  L00404e99: { // 0x404e99: f6461802 TEST byte ptr [ESI + 0x18],0x2
    (void)integer::logical((m.r8((s.si+0x00000018u)))&(0x00000002u),8,flags);
  }
  L00404e9d: { // 0x404e9d: 7405 JZ 0x00404ea4
    if(integer::condition("JZ",flags)) goto L00404ea4;
  }
  L00404e9f: { // 0x404e9f: e80cd7ffff CALL 0x004025b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004025b0u,4214436u); flags=s.arithmetic_flags;
  }
  L00404ea4: { // 0x404ea4: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00404eaa: { // 0x404eaa: e841d8ffff CALL 0x004026f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004026f0u,4214447u); flags=s.arithmetic_flags;
  }
  L00404eaf: { // 0x404eaf: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00404eb5: { // 0x404eb5: 8998c0000000 MOV dword ptr [EAX + 0xc0],EBX
    m.w32((s.ax+0x000000c0u), s.bx);
  }
  L00404ebb: { // 0x404ebb: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00404ec1: { // 0x404ec1: 8999bc000000 MOV dword ptr [ECX + 0xbc],EBX
    m.w32((s.cx+0x000000bcu), s.bx);
  }
  L00404ec7: { // 0x404ec7: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00404ecd: { // 0x404ecd: 899ab4000000 MOV dword ptr [EDX + 0xb4],EBX
    m.w32((s.dx+0x000000b4u), s.bx);
  }
  L00404ed3: { // 0x404ed3: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00404ed9: { // 0x404ed9: 8998b8000000 MOV dword ptr [EAX + 0xb8],EBX
    m.w32((s.ax+0x000000b8u), s.bx);
  }
  L00404edf: { // 0x404edf: 8b8eb0000000 MOV ECX,dword ptr [ESI + 0xb0]
    s.cx = m.r32((s.si+0x000000b0u));
  }
  L00404ee5: { // 0x404ee5: 899990000000 MOV dword ptr [ECX + 0x90],EBX
    m.w32((s.cx+0x00000090u), s.bx);
  }
  L00404eeb: { // 0x404eeb: 8b96b0000000 MOV EDX,dword ptr [ESI + 0xb0]
    s.dx = m.r32((s.si+0x000000b0u));
  }
  L00404ef1: { // 0x404ef1: 899a98000000 MOV dword ptr [EDX + 0x98],EBX
    m.w32((s.dx+0x00000098u), s.bx);
  }
  L00404ef7: { // 0x404ef7: 8b86b0000000 MOV EAX,dword ptr [ESI + 0xb0]
    s.ax = m.r32((s.si+0x000000b0u));
  }
  L00404efd: { // 0x404efd: 89989c000000 MOV dword ptr [EAX + 0x9c],EBX
    m.w32((s.ax+0x0000009cu), s.bx);
  }
  L00404f03: { // 0x404f03: 899eb0000000 MOV dword ptr [ESI + 0xb0],EBX
    m.w32((s.si+0x000000b0u), s.bx);
  }
  L00404f09: { // 0x404f09: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00404f0f: { // 0x404f0f: 33ed XOR EBP,EBP
    s.bp = integer::logical((s.bp)^(s.bp),32,flags);
  }
  L00404f11: { // 0x404f11: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L00404f13: { // 0x404f13: 7e1e JLE 0x00404f33
    if(integer::condition("JLE",flags)) goto L00404f33;
  }
  L00404f15: { // 0x404f15: 8d7e28 LEA EDI,[ESI + 0x28]
    s.di = (s.si+0x00000028u);
  }
  L00404f18: { // 0x404f18: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L00404f1a: { // 0x404f1a: e871d0ffff CALL 0x00401f90
    s.arithmetic_flags=flags; invoke(m,s,f,0x00401f90u,4214559u); flags=s.arithmetic_flags;
  }
  L00404f1f: { // 0x404f1f: 891f MOV dword ptr [EDI],EBX
    m.w32((s.di), s.bx);
  }
  L00404f21: { // 0x404f21: 8b86a8000000 MOV EAX,dword ptr [ESI + 0xa8]
    s.ax = m.r32((s.si+0x000000a8u));
  }
  L00404f27: { // 0x404f27: 45 INC EBP
    s.bp = integer::increment(s.bp,32,flags);
  }
  L00404f28: { // 0x404f28: 83c704 ADD EDI,0x4
    s.di = integer::add(s.di,0x00000004u,32,flags);
  }
  L00404f2b: { // 0x404f2b: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L00404f2d: { // 0x404f2d: 7ce9 JL 0x00404f18
    if(integer::condition("JL",flags)) goto L00404f18;
  }
  L00404f2f: { // 0x404f2f: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L00404f33: { // 0x404f33: 899ea8000000 MOV dword ptr [ESI + 0xa8],EBX
    m.w32((s.si+0x000000a8u), s.bx);
  }
  L00404f39: { // 0x404f39: c7461c04000000 MOV dword ptr [ESI + 0x1c],0x4
    m.w32((s.si+0x0000001cu), 0x00000004u);
  }
  L00404f40: { // 0x404f40: 899e38010000 MOV dword ptr [ESI + 0x138],EBX
    m.w32((s.si+0x00000138u), s.bx);
  }
  L00404f46: { // 0x404f46: 899e78020000 MOV dword ptr [ESI + 0x278],EBX
    m.w32((s.si+0x00000278u), s.bx);
  }
  L00404f4c: { // 0x404f4c: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  L00404f4f: { // 0x404f4f: 83c901 OR ECX,0x1
    s.cx = integer::logical((s.cx)|(0x00000001u),32,flags);
  }
  L00404f52: { // 0x404f52: 894e18 MOV dword ptr [ESI + 0x18],ECX
    m.w32((s.si+0x00000018u), s.cx);
  }
  L00404f55: { // 0x404f55: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00404f57: { // 0x404f57: e824240000 CALL 0x00407380
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407380u,4214620u); flags=s.arithmetic_flags;
  }
  L00404f5c: { // 0x404f5c: 899e38010000 MOV dword ptr [ESI + 0x138],EBX
    m.w32((s.si+0x00000138u), s.bx);
  }
  L00404f62: { // 0x404f62: 8a4618 MOV AL,byte ptr [ESI + 0x18]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000018u)));
  }
  L00404f65: { // 0x404f65: a880 TEST AL,0x80
    (void)integer::logical(((s.ax & 0xffu))&(0x00000080u),8,flags);
  }
  L00404f67: { // 0x404f67: 740b JZ 0x00404f74
    if(integer::condition("JZ",flags)) goto L00404f74;
  }
  L00404f69: { // 0x404f69: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00404f6a: { // 0x404f6a: e80c873600 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,4214639u); flags=s.arithmetic_flags;
  }
  L00404f6f: { // 0x404f6f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00404f72: { // 0x404f72: eb0d JMP 0x00404f81
    goto L00404f81;
  }
  L00404f74: { // 0x404f74: 8b0d00938100 MOV ECX,dword ptr [0x00819300]
    s.cx = m.r32((0x00819300u));
  }
  L00404f7a: { // 0x404f7a: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L00404f7c: { // 0x404f7c: e8df240000 CALL 0x00407460
    s.arithmetic_flags=flags; invoke(m,s,f,0x00407460u,4214657u); flags=s.arithmetic_flags;
  }
  L00404f81: { // 0x404f81: 8b0de4928100 MOV ECX,dword ptr [0x008192e4]
    s.cx = m.r32((0x008192e4u));
  }
  L00404f87: { // 0x404f87: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L00404f89: { // 0x404f89: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00404f8a: { // 0x404f8a: 81ffe0918100 CMP EDI,0x8191e0
    (void)integer::sub(s.di,0x008191e0u,32,flags);
  }
  L00404f90: { // 0x404f90: 890de4928100 MOV dword ptr [0x008192e4],ECX
    m.w32((0x008192e4u), s.cx);
  }
  L00404f96: { // 0x404f96: 0f85dafeffff JNZ 0x00404e76
    if(integer::condition("JNZ",flags)) goto L00404e76;
  }
  L00404f9c: { // 0x404f9c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00404f9d: { // 0x404f9d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00404f9e: { // 0x404f9e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00404f9f: { // 0x404f9f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00404fa0: { // 0x404fa0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00404fa1: { // 0x404fa1: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_004eec40(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004eec40: { // 0x4eec40: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L004eec41: { // 0x4eec41: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  L004eec45: { // 0x4eec45: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004eec46: { // 0x4eec46: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L004eec47: { // 0x4eec47: 56 PUSH ESI
    f.push(m,s.si);
  }
  L004eec48: { // 0x4eec48: 8b8870050000 MOV ECX,dword ptr [EAX + 0x570]
    s.cx = m.r32((s.ax+0x00000570u));
  }
  L004eec4e: { // 0x4eec4e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L004eec4f: { // 0x4eec4f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L004eec51: { // 0x4eec51: c744241000000000 MOV dword ptr [ESP + 0x10],0x0
    m.w32((f.sp+0x00000010u), 0x00000000u);
  }
  L004eec59: { // 0x4eec59: 0f8e00010000 JLE 0x004eed5f
    if(integer::condition("JLE",flags)) goto L004eed5f;
  }
  L004eec5f: { // 0x4eec5f: 8b7c2420 MOV EDI,dword ptr [ESP + 0x20]
    s.di = m.r32((f.sp+0x00000020u));
  }
  L004eec63: { // 0x4eec63: 8b6c241c MOV EBP,dword ptr [ESP + 0x1c]
    s.bp = m.r32((f.sp+0x0000001cu));
  }
  L004eec67: { // 0x4eec67: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004eec6b: { // 0x4eec6b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004eec6f: { // 0x4eec6f: 8b9164050000 MOV EDX,dword ptr [ECX + 0x564]
    s.dx = m.r32((s.cx+0x00000564u));
  }
  L004eec75: { // 0x4eec75: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L004eec78: { // 0x4eec78: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eec7a: { // 0x4eec7a: 7c2c JL 0x004eeca8
    if(integer::condition("JL",flags)) goto L004eeca8;
  }
  L004eec7c: { // 0x4eec7c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004eec7e: { // 0x4eec7e: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004eec80: { // 0x4eec80: 0f8ecf000000 JLE 0x004eed55
    if(integer::condition("JLE",flags)) goto L004eed55;
  }
  L004eec86: { // 0x4eec86: 8b150ce0a100 MOV EDX,dword ptr [0x00a1e00c]
    s.dx = m.r32((0x00a1e00cu));
  }
  L004eec8c: { // 0x4eec8c: 8b1482 MOV EDX,dword ptr [EDX + EAX*0x4]
    s.dx = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L004eec8f: { // 0x4eec8f: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L004eec92: { // 0x4eec92: 3910 CMP dword ptr [EAX],EDX
    (void)integer::sub(m.r32((s.ax)),s.dx,32,flags);
  }
  L004eec94: { // 0x4eec94: 0f849f000000 JZ 0x004eed39
    if(integer::condition("JZ",flags)) goto L004eed39;
  }
  L004eec9a: { // 0x4eec9a: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004eec9b: { // 0x4eec9b: 83c004 ADD EAX,0x4
    s.ax = integer::add(s.ax,0x00000004u,32,flags);
  }
  L004eec9e: { // 0x4eec9e: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L004eeca0: { // 0x4eeca0: 0f8daf000000 JGE 0x004eed55
    if(integer::condition("JGE",flags)) goto L004eed55;
  }
  L004eeca6: { // 0x4eeca6: ebea JMP 0x004eec92
    goto L004eec92;
  }
  L004eeca8: { // 0x4eeca8: 83c006 ADD EAX,0x6
    s.ax = integer::add(s.ax,0x00000006u,32,flags);
  }
  L004eecab: { // 0x4eecab: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004eecad: { // 0x4eecad: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L004eecb0: { // 0x4eecb0: 7757 JA 0x004eed09
    if(integer::condition("JA",flags)) goto L004eed09;
  }
  L004eecb2: { // 0x4eecb2: ff24856ced4e00 JMP dword ptr [EAX*0x4 + 0x4eed6c]
    switch(m.r32(((s.ax * 0x00000004u)+0x004eed6cu))){
    case 0x004eec40u: goto L004eec40;
    case 0x004eec41u: goto L004eec41;
    case 0x004eec45u: goto L004eec45;
    case 0x004eec46u: goto L004eec46;
    case 0x004eec47u: goto L004eec47;
    case 0x004eec48u: goto L004eec48;
    case 0x004eec4eu: goto L004eec4e;
    case 0x004eec4fu: goto L004eec4f;
    case 0x004eec51u: goto L004eec51;
    case 0x004eec59u: goto L004eec59;
    case 0x004eec5fu: goto L004eec5f;
    case 0x004eec63u: goto L004eec63;
    case 0x004eec67u: goto L004eec67;
    case 0x004eec6bu: goto L004eec6b;
    case 0x004eec6fu: goto L004eec6f;
    case 0x004eec75u: goto L004eec75;
    case 0x004eec78u: goto L004eec78;
    case 0x004eec7au: goto L004eec7a;
    case 0x004eec7cu: goto L004eec7c;
    case 0x004eec7eu: goto L004eec7e;
    case 0x004eec80u: goto L004eec80;
    case 0x004eec86u: goto L004eec86;
    case 0x004eec8cu: goto L004eec8c;
    case 0x004eec8fu: goto L004eec8f;
    case 0x004eec92u: goto L004eec92;
    case 0x004eec94u: goto L004eec94;
    case 0x004eec9au: goto L004eec9a;
    case 0x004eec9bu: goto L004eec9b;
    case 0x004eec9eu: goto L004eec9e;
    case 0x004eeca0u: goto L004eeca0;
    case 0x004eeca6u: goto L004eeca6;
    case 0x004eeca8u: goto L004eeca8;
    case 0x004eecabu: goto L004eecab;
    case 0x004eecadu: goto L004eecad;
    case 0x004eecb0u: goto L004eecb0;
    case 0x004eecb2u: goto L004eecb2;
    case 0x004eecb9u: goto L004eecb9;
    case 0x004eecbeu: goto L004eecbe;
    case 0x004eecc4u: goto L004eecc4;
    case 0x004eecc6u: goto L004eecc6;
    case 0x004eecccu: goto L004eeccc;
    case 0x004eecd2u: goto L004eecd2;
    case 0x004eecd4u: goto L004eecd4;
    case 0x004eecdau: goto L004eecda;
    case 0x004eece0u: goto L004eece0;
    case 0x004eece2u: goto L004eece2;
    case 0x004eece7u: goto L004eece7;
    case 0x004eecedu: goto L004eeced;
    case 0x004eecefu: goto L004eecef;
    case 0x004eecf5u: goto L004eecf5;
    case 0x004eecfbu: goto L004eecfb;
    case 0x004eecfdu: goto L004eecfd;
    case 0x004eed03u: goto L004eed03;
    case 0x004eed09u: goto L004eed09;
    case 0x004eed0cu: goto L004eed0c;
    case 0x004eed0eu: goto L004eed0e;
    case 0x004eed10u: goto L004eed10;
    case 0x004eed12u: goto L004eed12;
    case 0x004eed14u: goto L004eed14;
    case 0x004eed15u: goto L004eed15;
    case 0x004eed17u: goto L004eed17;
    case 0x004eed1au: goto L004eed1a;
    case 0x004eed1cu: goto L004eed1c;
    case 0x004eed1eu: goto L004eed1e;
    case 0x004eed20u: goto L004eed20;
    case 0x004eed23u: goto L004eed23;
    case 0x004eed25u: goto L004eed25;
    case 0x004eed27u: goto L004eed27;
    case 0x004eed28u: goto L004eed28;
    case 0x004eed2bu: goto L004eed2b;
    case 0x004eed2du: goto L004eed2d;
    case 0x004eed2fu: goto L004eed2f;
    case 0x004eed32u: goto L004eed32;
    case 0x004eed33u: goto L004eed33;
    case 0x004eed35u: goto L004eed35;
    case 0x004eed37u: goto L004eed37;
    case 0x004eed39u: goto L004eed39;
    case 0x004eed3du: goto L004eed3d;
    case 0x004eed41u: goto L004eed41;
    case 0x004eed42u: goto L004eed42;
    case 0x004eed48u: goto L004eed48;
    case 0x004eed4cu: goto L004eed4c;
    case 0x004eed4eu: goto L004eed4e;
    case 0x004eed50u: goto L004eed50;
    case 0x004eed55u: goto L004eed55;
    case 0x004eed56u: goto L004eed56;
    case 0x004eed57u: goto L004eed57;
    case 0x004eed58u: goto L004eed58;
    case 0x004eed5au: goto L004eed5a;
    case 0x004eed5bu: goto L004eed5b;
    case 0x004eed5cu: goto L004eed5c;
    case 0x004eed5fu: goto L004eed5f;
    case 0x004eed60u: goto L004eed60;
    case 0x004eed61u: goto L004eed61;
    case 0x004eed62u: goto L004eed62;
    case 0x004eed64u: goto L004eed64;
    case 0x004eed65u: goto L004eed65;
    case 0x004eed66u: goto L004eed66;
    default:throw std::domain_error("recovery108 unsupported switch destination");}
  }
  L004eecb9: { // 0x4eecb9: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004eecbe: { // 0x4eecbe: 8db0e4070000 LEA ESI,[EAX + 0x7e4]
    s.si = (s.ax+0x000007e4u);
  }
  L004eecc4: { // 0x4eecc4: eb43 JMP 0x004eed09
    goto L004eed09;
  }
  L004eecc6: { // 0x4eecc6: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004eeccc: { // 0x4eeccc: 8db154080000 LEA ESI,[ECX + 0x854]
    s.si = (s.cx+0x00000854u);
  }
  L004eecd2: { // 0x4eecd2: eb35 JMP 0x004eed09
    goto L004eed09;
  }
  L004eecd4: { // 0x4eecd4: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L004eecda: { // 0x4eecda: 8db21c080000 LEA ESI,[EDX + 0x81c]
    s.si = (s.dx+0x0000081cu);
  }
  L004eece0: { // 0x4eece0: eb27 JMP 0x004eed09
    goto L004eed09;
  }
  L004eece2: { // 0x4eece2: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L004eece7: { // 0x4eece7: 8db0e0080000 LEA ESI,[EAX + 0x8e0]
    s.si = (s.ax+0x000008e0u);
  }
  L004eeced: { // 0x4eeced: eb1a JMP 0x004eed09
    goto L004eed09;
  }
  L004eecef: { // 0x4eecef: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L004eecf5: { // 0x4eecf5: 8db138080000 LEA ESI,[ECX + 0x838]
    s.si = (s.cx+0x00000838u);
  }
  L004eecfb: { // 0x4eecfb: eb0c JMP 0x004eed09
    goto L004eed09;
  }
  L004eecfd: { // 0x4eecfd: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L004eed03: { // 0x4eed03: 8db200080000 LEA ESI,[EDX + 0x800]
    s.si = (s.dx+0x00000800u);
  }
  L004eed09: { // 0x4eed09: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004eed0c: { // 0x4eed0c: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L004eed0e: { // 0x4eed0e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L004eed10: { // 0x4eed10: 7e43 JLE 0x004eed55
    if(integer::condition("JLE",flags)) goto L004eed55;
  }
  L004eed12: { // 0x4eed12: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L004eed14: { // 0x4eed14: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L004eed15: { // 0x4eed15: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L004eed17: { // 0x4eed17: ff5018 CALL dword ptr [EAX + 0x18]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000018u)),5172506u); flags=s.arithmetic_flags;
  }
  L004eed1a: { // 0x4eed1a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L004eed1c: { // 0x4eed1c: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L004eed1e: { // 0x4eed1e: 7e0f JLE 0x004eed2f
    if(integer::condition("JLE",flags)) goto L004eed2f;
  }
  L004eed20: { // 0x4eed20: 8b5504 MOV EDX,dword ptr [EBP + 0x4]
    s.dx = m.r32((s.bp+0x00000004u));
  }
  L004eed23: { // 0x4eed23: 3902 CMP dword ptr [EDX],EAX
    (void)integer::sub(m.r32((s.dx)),s.ax,32,flags);
  }
  L004eed25: { // 0x4eed25: 7412 JZ 0x004eed39
    if(integer::condition("JZ",flags)) goto L004eed39;
  }
  L004eed27: { // 0x4eed27: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L004eed28: { // 0x4eed28: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L004eed2b: { // 0x4eed2b: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  L004eed2d: { // 0x4eed2d: 7cf4 JL 0x004eed23
    if(integer::condition("JL",flags)) goto L004eed23;
  }
  L004eed2f: { // 0x4eed2f: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  L004eed32: { // 0x4eed32: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  L004eed33: { // 0x4eed33: 3bd8 CMP EBX,EAX
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L004eed35: { // 0x4eed35: 7d1e JGE 0x004eed55
    if(integer::condition("JGE",flags)) goto L004eed55;
  }
  L004eed37: { // 0x4eed37: ebd9 JMP 0x004eed12
    goto L004eed12;
  }
  L004eed39: { // 0x4eed39: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004eed3d: { // 0x4eed3d: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L004eed41: { // 0x4eed41: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L004eed42: { // 0x4eed42: 8b9170050000 MOV EDX,dword ptr [ECX + 0x570]
    s.dx = m.r32((s.cx+0x00000570u));
  }
  L004eed48: { // 0x4eed48: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L004eed4c: { // 0x4eed4c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L004eed4e: { // 0x4eed4e: 7d0f JGE 0x004eed5f
    if(integer::condition("JGE",flags)) goto L004eed5f;
  }
  L004eed50: { // 0x4eed50: e912ffffff JMP 0x004eec67
    goto L004eec67;
  }
  L004eed55: { // 0x4eed55: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eed56: { // 0x4eed56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eed57: { // 0x4eed57: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004eed58: { // 0x4eed58: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L004eed5a: { // 0x4eed5a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004eed5b: { // 0x4eed5b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004eed5c: { // 0x4eed5c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L004eed5f: { // 0x4eed5f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004eed60: { // 0x4eed60: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004eed61: { // 0x4eed61: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L004eed62: { // 0x4eed62: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L004eed64: { // 0x4eed64: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004eed65: { // 0x4eed65: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L004eed66: { // 0x4eed66: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0054cd80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0054cd80: { // 0x54cd80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0054cd81: { // 0x54cd81: 8a442410 MOV AL,byte ptr [ESP + 0x10]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000010u)));
  }
  L0054cd85: { // 0x54cd85: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0054cd86: { // 0x54cd86: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0054cd87: { // 0x54cd87: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cd88: { // 0x54cd88: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0054cd8c: { // 0x54cd8c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0054cd8d: { // 0x54cd8d: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0054cd8f: { // 0x54cd8f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cd91: { // 0x54cd91: 897c2410 MOV dword ptr [ESP + 0x10],EDI
    m.w32((f.sp+0x00000010u), s.di);
  }
  L0054cd95: { // 0x54cd95: 0f84f6000000 JZ 0x0054ce91
    if(integer::condition("JZ",flags)) goto L0054ce91;
  }
  L0054cd9b: { // 0x54cd9b: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cd9f: { // 0x54cd9f: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054cda2: { // 0x54cda2: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054cda5: { // 0x54cda5: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054cda7: { // 0x54cda7: 7814 JS 0x0054cdbd
    if(integer::condition("JS",flags)) goto L0054cdbd;
  }
  L0054cda9: { // 0x54cda9: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054cdae: { // 0x54cdae: 7d0d JGE 0x0054cdbd
    if(integer::condition("JGE",flags)) goto L0054cdbd;
  }
  L0054cdb0: { // 0x54cdb0: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054cdb6: { // 0x54cdb6: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054cdb9: { // 0x54cdb9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054cdbb: { // 0x54cdbb: 750c JNZ 0x0054cdc9
    if(integer::condition("JNZ",flags)) goto L0054cdc9;
  }
  L0054cdbd: { // 0x54cdbd: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0054cdbf: { // 0x54cdbf: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054cdc4: { // 0x54cdc4: b81076a500 MOV EAX,0xa57610
    s.ax = 0x00a57610u;
  }
  L0054cdc9: { // 0x54cdc9: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L0054cdcf: { // 0x54cdcf: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054cdd2: { // 0x54cdd2: 0f84b9000000 JZ 0x0054ce91
    if(integer::condition("JZ",flags)) goto L0054ce91;
  }
  L0054cdd8: { // 0x54cdd8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0054cdda: { // 0x54cdda: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0054cddc: { // 0x54cddc: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054cddd: { // 0x54cddd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054cddf: { // 0x54cddf: e87c070000 CALL 0x0054d560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0054d560u,5557732u); flags=s.arithmetic_flags;
  }
  L0054cde4: { // 0x54cde4: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0054cde7: { // 0x54cde7: 0f84ca000000 JZ 0x0054ceb7
    if(integer::condition("JZ",flags)) goto L0054ceb7;
  }
  L0054cded: { // 0x54cded: 8b4f50 MOV ECX,dword ptr [EDI + 0x50]
    s.cx = m.r32((s.di+0x00000050u));
  }
  L0054cdf0: { // 0x54cdf0: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  L0054cdf3: { // 0x54cdf3: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054cdf5: { // 0x54cdf5: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0054cdf7: { // 0x54cdf7: 8a4308 MOV AL,byte ptr [EBX + 0x8]
    s.ax = with_al(s.ax, m.r8((s.bx+0x00000008u)));
  }
  L0054cdfa: { // 0x54cdfa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054cdfc: { // 0x54cdfc: 7407 JZ 0x0054ce05
    if(integer::condition("JZ",flags)) goto L0054ce05;
  }
  L0054cdfe: { // 0x54cdfe: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0054ce00: { // 0x54ce00: e98c000000 JMP 0x0054ce91
    goto L0054ce91;
  }
  L0054ce05: { // 0x54ce05: 0fbf4602 MOVSX EAX,word ptr [ESI + 0x2]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054ce09: { // 0x54ce09: 0fbf0e MOVSX ECX,word ptr [ESI]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054ce0c: { // 0x54ce0c: c1e009 SHL EAX,0x9
    s.ax = integer::shift(s.ax,0x00000009u,32,flags,integer::Shift::left);
  }
  L0054ce0f: { // 0x54ce0f: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0054ce11: { // 0x54ce11: 7818 JS 0x0054ce2b
    if(integer::condition("JS",flags)) goto L0054ce2b;
  }
  L0054ce13: { // 0x54ce13: 3d00000400 CMP EAX,0x40000
    (void)integer::sub(s.ax,0x00040000u,32,flags);
  }
  L0054ce18: { // 0x54ce18: 7d11 JGE 0x0054ce2b
    if(integer::condition("JGE",flags)) goto L0054ce2b;
  }
  L0054ce1a: { // 0x54ce1a: 8b1558a98100 MOV EDX,dword ptr [0x0081a958]
    s.dx = m.r32((0x0081a958u));
  }
  L0054ce20: { // 0x54ce20: 8b0482 MOV EAX,dword ptr [EDX + EAX*0x4]
    s.ax = m.r32((s.dx+(s.ax * 0x00000004u)));
  }
  L0054ce23: { // 0x54ce23: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0054ce25: { // 0x54ce25: 7404 JZ 0x0054ce2b
    if(integer::condition("JZ",flags)) goto L0054ce2b;
  }
  L0054ce27: { // 0x54ce27: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054ce29: { // 0x54ce29: eb0c JMP 0x0054ce37
    goto L0054ce37;
  }
  L0054ce2b: { // 0x54ce2b: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L0054ce2d: { // 0x54ce2d: bf1076a500 MOV EDI,0xa57610
    s.di = 0x00a57610u;
  }
  L0054ce32: { // 0x54ce32: a33476a500 MOV [0x00a57634],EAX
    m.w32((0x00a57634u), s.ax);
  }
  L0054ce37: { // 0x54ce37: 668b33 MOV SI,word ptr [EBX]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.bx))) & 0xffffu);
  }
  L0054ce3a: { // 0x54ce3a: 8d6b04 LEA EBP,[EBX + 0x4]
    s.bp = (s.bx+0x00000004u);
  }
  L0054ce3d: { // 0x54ce3d: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0054ce43: { // 0x54ce43: 662b7500 SUB SI,word ptr [EBP]
    s.si = (s.si & 0xffff0000u) | ((integer::sub((s.si & 0xffffu),m.r16((s.bp)),16,flags)) & 0xffffu);
  }
  L0054ce47: { // 0x54ce47: 66f7de NEG SI
    s.si = (s.si & 0xffff0000u) | ((integer::sub(0u,(s.si & 0xffffu),16,flags)) & 0xffffu);
  }
  L0054ce4a: { // 0x54ce4a: 1bf6 SBB ESI,ESI
    s.si = integer::sub(s.si,s.si,32,flags,flags&integer::CF);
  }
  L0054ce4c: { // 0x54ce4c: 83e6fe AND ESI,0xfffffffe
    s.si = integer::logical((s.si)&(0xfffffffeu),32,flags);
  }
  L0054ce4f: { // 0x54ce4f: 83c604 ADD ESI,0x4
    s.si = integer::add(s.si,0x00000004u,32,flags);
  }
  L0054ce52: { // 0x54ce52: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054ce55: { // 0x54ce55: 7415 JZ 0x0054ce6c
    if(integer::condition("JZ",flags)) goto L0054ce6c;
  }
  L0054ce57: { // 0x54ce57: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0054ce58: { // 0x54ce58: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce5a: { // 0x54ce5a: e86198f2ff CALL 0x004766c0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004766c0u,5557855u); flags=s.arithmetic_flags;
  }
  L0054ce5f: { // 0x54ce5f: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0054ce61: { // 0x54ce61: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  L0054ce67: { // 0x54ce67: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0054ce6a: { // 0x54ce6a: 75eb JNZ 0x0054ce57
    if(integer::condition("JNZ",flags)) goto L0054ce57;
  }
  L0054ce6c: { // 0x54ce6c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce6e: { // 0x54ce6e: e8ede6f2ff CALL 0x0047b560
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b560u,5557875u); flags=s.arithmetic_flags;
  }
  L0054ce73: { // 0x54ce73: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ce75: { // 0x54ce75: 750b JNZ 0x0054ce82
    if(integer::condition("JNZ",flags)) goto L0054ce82;
  }
  L0054ce77: { // 0x54ce77: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0054ce79: { // 0x54ce79: e802e7f2ff CALL 0x0047b580
    s.arithmetic_flags=flags; invoke(m,s,f,0x0047b580u,5557886u); flags=s.arithmetic_flags;
  }
  L0054ce7e: { // 0x54ce7e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0054ce80: { // 0x54ce80: 7431 JZ 0x0054ceb3
    if(integer::condition("JZ",flags)) goto L0054ceb3;
  }
  L0054ce82: { // 0x54ce82: 83bfec00000003 CMP dword ptr [EDI + 0xec],0x3
    (void)integer::sub(m.r32((s.di+0x000000ecu)),0x00000003u,32,flags);
  }
  L0054ce89: { // 0x54ce89: 7428 JZ 0x0054ceb3
    if(integer::condition("JZ",flags)) goto L0054ceb3;
  }
  L0054ce8b: { // 0x54ce8b: 8bf5 MOV ESI,EBP
    s.si = s.bp;
  }
  L0054ce8d: { // 0x54ce8d: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  L0054ce91: { // 0x54ce91: 8b8ff4000000 MOV ECX,dword ptr [EDI + 0xf4]
    s.cx = m.r32((s.di+0x000000f4u));
  }
  L0054ce97: { // 0x54ce97: 8b97f0000000 MOV EDX,dword ptr [EDI + 0xf0]
    s.dx = m.r32((s.di+0x000000f0u));
  }
  L0054ce9d: { // 0x54ce9d: 8d441101 LEA EAX,[ECX + EDX*0x1 + 0x1]
    s.ax = (s.cx+(s.dx * 0x00000001u)+0x00000001u);
  }
  L0054cea1: { // 0x54cea1: 0fbf4e02 MOVSX ECX,word ptr [ESI + 0x2]
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.si+0x00000002u)),16));
  }
  L0054cea5: { // 0x54cea5: 0fbf16 MOVSX EDX,word ptr [ESI]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.si)),16));
  }
  L0054cea8: { // 0x54cea8: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L0054ceab: { // 0x54ceab: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0054cead: { // 0x54cead: 7913 JNS 0x0054cec2
    if(integer::condition("JNS",flags)) goto L0054cec2;
  }
  L0054ceaf: { // 0x54ceaf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054ceb1: { // 0x54ceb1: eb19 JMP 0x0054cecc
    goto L0054cecc;
  }
  L0054ceb3: { // 0x54ceb3: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L0054ceb5: { // 0x54ceb5: ebd6 JMP 0x0054ce8d
    goto L0054ce8d;
  }
  L0054ceb7: { // 0x54ceb7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054ceb8: { // 0x54ceb8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054ceb9: { // 0x54ceb9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054ceba: { // 0x54ceba: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  L0054cebd: { // 0x54cebd: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cebe: { // 0x54cebe: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cebf: { // 0x54cebf: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0054cec2: { // 0x54cec2: 8b4f68 MOV ECX,dword ptr [EDI + 0x68]
    s.cx = m.r32((s.di+0x00000068u));
  }
  L0054cec5: { // 0x54cec5: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0054cec7: { // 0x54cec7: 7c03 JL 0x0054cecc
    if(integer::condition("JL",flags)) goto L0054cecc;
  }
  L0054cec9: { // 0x54cec9: 8d41ff LEA EAX,[ECX + -0x1]
    s.ax = (s.cx-0x00000001u);
  }
  L0054cecc: { // 0x54cecc: 8b4f64 MOV ECX,dword ptr [EDI + 0x64]
    s.cx = m.r32((s.di+0x00000064u));
  }
  L0054cecf: { // 0x54cecf: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0054ced1: { // 0x54ced1: 668b548102 MOV DX,word ptr [ECX + EAX*0x4 + 0x2]
    s.dx = with_ax(s.dx, m.r16((s.cx+(s.ax * 0x00000004u)+0x00000002u)));
  }
  L0054ced6: { // 0x54ced6: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L0054ceda: { // 0x54ceda: 8b4c8718 MOV ECX,dword ptr [EDI + EAX*0x4 + 0x18]
    s.cx = m.r32((s.di+(s.ax * 0x00000004u)+0x00000018u));
  }
  L0054cede: { // 0x54cede: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0054cedf: { // 0x54cedf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0054cee1: { // 0x54cee1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0054cee2: { // 0x54cee2: 668b0451 MOV AX,word ptr [ECX + EDX*0x2]
    s.ax = with_ax(s.ax, m.r16((s.cx+(s.dx * 0x00000002u))));
  }
  L0054cee6: { // 0x54cee6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0054cee7: { // 0x54cee7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0054cee8: { // 0x54cee8: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0054cee9: { // 0x54cee9: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005d5d50(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d5d50: { // 0x5d5d50: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5d51: { // 0x5d5d51: a130ada500 MOV EAX,[0x00a5ad30]
    s.ax = m.r32((0x00a5ad30u));
  }
  L005d5d56: { // 0x5d5d56: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d5d57: { // 0x5d5d57: 8d78ff LEA EDI,[EAX + -0x1]
    s.di = (s.ax-0x00000001u);
  }
  L005d5d5a: { // 0x5d5d5a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005d5d5c: { // 0x5d5d5c: 7c73 JL 0x005d5dd1
    if(integer::condition("JL",flags)) goto L005d5dd1;
  }
  L005d5d5e: { // 0x5d5d5e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d5d5f: { // 0x5d5d5f: 8b0d24ada500 MOV ECX,dword ptr [0x00a5ad24]
    s.cx = m.r32((0x00a5ad24u));
  }
  L005d5d65: { // 0x5d5d65: 8b34b9 MOV ESI,dword ptr [ECX + EDI*0x4]
    s.si = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  L005d5d68: { // 0x5d5d68: 8b4e0c MOV ECX,dword ptr [ESI + 0xc]
    s.cx = m.r32((s.si+0x0000000cu));
  }
  L005d5d6b: { // 0x5d5d6b: 83c108 ADD ECX,0x8
    s.cx = integer::add(s.cx,0x00000008u,32,flags);
  }
  L005d5d6e: { // 0x5d5d6e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L005d5d70: { // 0x5d5d70: 894e0c MOV dword ptr [ESI + 0xc],ECX
    m.w32((s.si+0x0000000cu), s.cx);
  }
  L005d5d73: { // 0x5d5d73: 83f850 CMP EAX,0x50
    (void)integer::sub(s.ax,0x00000050u,32,flags);
  }
  L005d5d76: { // 0x5d5d76: 7c55 JL 0x005d5dcd
    if(integer::condition("JL",flags)) goto L005d5dcd;
  }
  L005d5d78: { // 0x5d5d78: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L005d5d7a: { // 0x5d5d7a: 7451 JZ 0x005d5dcd
    if(integer::condition("JZ",flags)) goto L005d5dcd;
  }
  L005d5d7c: { // 0x5d5d7c: a120ada500 MOV EAX,[0x00a5ad20]
    s.ax = m.r32((0x00a5ad20u));
  }
  L005d5d81: { // 0x5d5d81: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  L005d5d85: { // 0x5d5d85: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d5d86: { // 0x5d5d86: b920ada500 MOV ECX,0xa5ad20
    s.cx = 0x00a5ad20u;
  }
  L005d5d8b: { // 0x5d5d8b: 8974240c MOV dword ptr [ESP + 0xc],ESI
    m.w32((f.sp+0x0000000cu), s.si);
  }
  L005d5d8f: { // 0x5d5d8f: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6118802u); flags=s.arithmetic_flags;
  }
  L005d5d92: { // 0x5d5d92: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L005d5d95: { // 0x5d5d95: 742d JZ 0x005d5dc4
    if(integer::condition("JZ",flags)) goto L005d5dc4;
  }
  L005d5d97: { // 0x5d5d97: 8b0d30ada500 MOV ECX,dword ptr [0x00a5ad30]
    s.cx = m.r32((0x00a5ad30u));
  }
  L005d5d9d: { // 0x5d5d9d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005d5d9f: { // 0x5d5d9f: 7d23 JGE 0x005d5dc4
    if(integer::condition("JGE",flags)) goto L005d5dc4;
  }
  L005d5da1: { // 0x5d5da1: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L005d5da2: { // 0x5d5da2: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005d5da4: { // 0x5d5da4: 890d30ada500 MOV dword ptr [0x00a5ad30],ECX
    m.w32((0x00a5ad30u), s.cx);
  }
  L005d5daa: { // 0x5d5daa: 7d18 JGE 0x005d5dc4
    if(integer::condition("JGE",flags)) goto L005d5dc4;
  }
  L005d5dac: { // 0x5d5dac: 8b0d24ada500 MOV ECX,dword ptr [0x00a5ad24]
    s.cx = m.r32((0x00a5ad24u));
  }
  L005d5db2: { // 0x5d5db2: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L005d5db3: { // 0x5d5db3: 8b1481 MOV EDX,dword ptr [ECX + EAX*0x4]
    s.dx = m.r32((s.cx+(s.ax * 0x00000004u)));
  }
  L005d5db6: { // 0x5d5db6: 895481fc MOV dword ptr [ECX + EAX*0x4 + -0x4],EDX
    m.w32((s.cx+(s.ax * 0x00000004u)-0x00000004u), s.dx);
  }
  L005d5dba: { // 0x5d5dba: 8b0d30ada500 MOV ECX,dword ptr [0x00a5ad30]
    s.cx = m.r32((0x00a5ad30u));
  }
  L005d5dc0: { // 0x5d5dc0: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L005d5dc2: { // 0x5d5dc2: 7ce8 JL 0x005d5dac
    if(integer::condition("JL",flags)) goto L005d5dac;
  }
  L005d5dc4: { // 0x5d5dc4: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d5dc5: { // 0x5d5dc5: e8b1781900 CALL 0x0076d67b
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d67bu,6118858u); flags=s.arithmetic_flags;
  }
  L005d5dca: { // 0x5d5dca: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005d5dcd: { // 0x5d5dcd: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L005d5dce: { // 0x5d5dce: 798f JNS 0x005d5d5f
    if(integer::condition("JNS",flags)) goto L005d5d5f;
  }
  L005d5dd0: { // 0x5d5dd0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d5dd1: { // 0x5d5dd1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d5dd2: { // 0x5d5dd2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d5dd3: { // 0x5d5dd3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_0077e422(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0077e422: { // 0x77e422: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0077e423: { // 0x77e423: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L0077e425: { // 0x77e425: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077e426: { // 0x77e426: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077e427: { // 0x77e427: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077e428: { // 0x77e428: 8b750c MOV ESI,dword ptr [EBP + 0xc]
    s.si = m.r32((s.bp+0x0000000cu));
  }
  L0077e42b: { // 0x77e42b: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0077e42e: { // 0x77e42e: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0077e431: { // 0x77e431: a882 TEST AL,0x82
    (void)integer::logical(((s.ax & 0xffu))&(0x00000082u),8,flags);
  }
  L0077e433: { // 0x77e433: 894dfc MOV dword ptr [EBP + -0x4],ECX
    m.w32((s.bp-0x00000004u), s.cx);
  }
  L0077e436: { // 0x77e436: 0f84ff000000 JZ 0x0077e53b
    if(integer::condition("JZ",flags)) goto L0077e53b;
  }
  L0077e43c: { // 0x77e43c: a840 TEST AL,0x40
    (void)integer::logical(((s.ax & 0xffu))&(0x00000040u),8,flags);
  }
  L0077e43e: { // 0x77e43e: 0f85f7000000 JNZ 0x0077e53b
    if(integer::condition("JNZ",flags)) goto L0077e53b;
  }
  L0077e444: { // 0x77e444: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0077e446: { // 0x77e446: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0077e448: { // 0x77e448: 7415 JZ 0x0077e45f
    if(integer::condition("JZ",flags)) goto L0077e45f;
  }
  L0077e44a: { // 0x77e44a: a810 TEST AL,0x10
    (void)integer::logical(((s.ax & 0xffu))&(0x00000010u),8,flags);
  }
  L0077e44c: { // 0x77e44c: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0077e44f: { // 0x77e44f: 0f84e6000000 JZ 0x0077e53b
    if(integer::condition("JZ",flags)) goto L0077e53b;
  }
  L0077e455: { // 0x77e455: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    s.dx = m.r32((s.si+0x00000008u));
  }
  L0077e458: { // 0x77e458: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L0077e45a: { // 0x77e45a: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0077e45c: { // 0x77e45c: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0077e45f: { // 0x77e45f: 8b460c MOV EAX,dword ptr [ESI + 0xc]
    s.ax = m.r32((s.si+0x0000000cu));
  }
  L0077e462: { // 0x77e462: 895e04 MOV dword ptr [ESI + 0x4],EBX
    m.w32((s.si+0x00000004u), s.bx);
  }
  L0077e465: { // 0x77e465: 24ef AND AL,0xef
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000efu),8,flags));
  }
  L0077e467: { // 0x77e467: 895d0c MOV dword ptr [EBP + 0xc],EBX
    m.w32((s.bp+0x0000000cu), s.bx);
  }
  L0077e46a: { // 0x77e46a: 0c02 OR AL,0x2
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000002u),8,flags));
  }
  L0077e46c: { // 0x77e46c: 66a90c01 TEST AX,0x10c
    (void)integer::logical(((s.ax & 0xffffu))&(0x0000010cu),16,flags);
  }
  L0077e470: { // 0x77e470: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0077e473: { // 0x77e473: 7525 JNZ 0x0077e49a
    if(integer::condition("JNZ",flags)) goto L0077e49a;
  }
  L0077e475: { // 0x77e475: 81fef06f8100 CMP ESI,0x816ff0
    (void)integer::sub(s.si,0x00816ff0u,32,flags);
  }
  L0077e47b: { // 0x77e47b: 7408 JZ 0x0077e485
    if(integer::condition("JZ",flags)) goto L0077e485;
  }
  L0077e47d: { // 0x77e47d: 81fe10708100 CMP ESI,0x817010
    (void)integer::sub(s.si,0x00817010u,32,flags);
  }
  L0077e483: { // 0x77e483: 750b JNZ 0x0077e490
    if(integer::condition("JNZ",flags)) goto L0077e490;
  }
  L0077e485: { // 0x77e485: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077e486: { // 0x77e486: e809d3ffff CALL 0x0077b794
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077b794u,7857291u); flags=s.arithmetic_flags;
  }
  L0077e48b: { // 0x77e48b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0077e48d: { // 0x77e48d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077e48e: { // 0x77e48e: 7507 JNZ 0x0077e497
    if(integer::condition("JNZ",flags)) goto L0077e497;
  }
  L0077e490: { // 0x77e490: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0077e491: { // 0x77e491: e8bad2ffff CALL 0x0077b750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077b750u,7857302u); flags=s.arithmetic_flags;
  }
  L0077e496: { // 0x77e496: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0077e497: { // 0x77e497: 8b4dfc MOV ECX,dword ptr [EBP + -0x4]
    s.cx = m.r32((s.bp-0x00000004u));
  }
  L0077e49a: { // 0x77e49a: 66f7460c0801 TEST word ptr [ESI + 0xc],0x108
    (void)integer::logical((m.r16((s.si+0x0000000cu)))&(0x00000108u),16,flags);
  }
  L0077e4a0: { // 0x77e4a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077e4a1: { // 0x77e4a1: 7468 JZ 0x0077e50b
    if(integer::condition("JZ",flags)) goto L0077e50b;
  }
  L0077e4a3: { // 0x77e4a3: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0077e4a6: { // 0x77e4a6: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  L0077e4a8: { // 0x77e4a8: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  L0077e4aa: { // 0x77e4aa: 8d5002 LEA EDX,[EAX + 0x2]
    s.dx = (s.ax+0x00000002u);
  }
  L0077e4ad: { // 0x77e4ad: 8916 MOV dword ptr [ESI],EDX
    m.w32((s.si), s.dx);
  }
  L0077e4af: { // 0x77e4af: 8b5618 MOV EDX,dword ptr [ESI + 0x18]
    s.dx = m.r32((s.si+0x00000018u));
  }
  L0077e4b2: { // 0x77e4b2: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0077e4b3: { // 0x77e4b3: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0077e4b4: { // 0x77e4b4: 3bfb CMP EDI,EBX
    (void)integer::sub(s.di,s.bx,32,flags);
  }
  L0077e4b6: { // 0x77e4b6: 895604 MOV dword ptr [ESI + 0x4],EDX
    m.w32((s.si+0x00000004u), s.dx);
  }
  L0077e4b9: { // 0x77e4b9: 7e10 JLE 0x0077e4cb
    if(integer::condition("JLE",flags)) goto L0077e4cb;
  }
  L0077e4bb: { // 0x77e4bb: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077e4bc: { // 0x77e4bc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077e4bd: { // 0x77e4bd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077e4be: { // 0x77e4be: e85264ffff CALL 0x00774915
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774915u,7857347u); flags=s.arithmetic_flags;
  }
  L0077e4c3: { // 0x77e4c3: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0077e4c6: { // 0x77e4c6: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L0077e4c9: { // 0x77e4c9: eb35 JMP 0x0077e500
    goto L0077e500;
  }
  L0077e4cb: { // 0x77e4cb: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  L0077e4ce: { // 0x77e4ce: 7419 JZ 0x0077e4e9
    if(integer::condition("JZ",flags)) goto L0077e4e9;
  }
  L0077e4d0: { // 0x77e4d0: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0077e4d2: { // 0x77e4d2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0077e4d4: { // 0x77e4d4: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0077e4d7: { // 0x77e4d7: 83e01f AND EAX,0x1f
    s.ax = integer::logical((s.ax)&(0x0000001fu),32,flags);
  }
  L0077e4da: { // 0x77e4da: 8b1495000db100 MOV EDX,dword ptr [EDX*0x4 + 0xb10d00]
    s.dx = m.r32(((s.dx * 0x00000004u)+0x00b10d00u));
  }
  L0077e4e1: { // 0x77e4e1: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  L0077e4e4: { // 0x77e4e4: 8d0482 LEA EAX,[EDX + EAX*0x4]
    s.ax = (s.dx+(s.ax * 0x00000004u));
  }
  L0077e4e7: { // 0x77e4e7: eb05 JMP 0x0077e4ee
    goto L0077e4ee;
  }
  L0077e4e9: { // 0x77e4e9: b8f8788100 MOV EAX,0x8178f8
    s.ax = 0x008178f8u;
  }
  L0077e4ee: { // 0x77e4ee: f6400420 TEST byte ptr [EAX + 0x4],0x20
    (void)integer::logical((m.r8((s.ax+0x00000004u)))&(0x00000020u),8,flags);
  }
  L0077e4f2: { // 0x77e4f2: 740c JZ 0x0077e500
    if(integer::condition("JZ",flags)) goto L0077e500;
  }
  L0077e4f4: { // 0x77e4f4: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0077e4f6: { // 0x77e4f6: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0077e4f7: { // 0x77e4f7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077e4f8: { // 0x77e4f8: e87bd1ffff CALL 0x0077b678
    s.arithmetic_flags=flags; invoke(m,s,f,0x0077b678u,7857405u); flags=s.arithmetic_flags;
  }
  L0077e4fd: { // 0x77e4fd: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0077e500: { // 0x77e500: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  L0077e503: { // 0x77e503: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0077e506: { // 0x77e506: 668918 MOV word ptr [EAX],BX
    m.w16((s.ax), (s.bx & 0xffffu));
  }
  L0077e509: { // 0x77e509: eb1b JMP 0x0077e526
    goto L0077e526;
  }
  L0077e50b: { // 0x77e50b: 8b5d08 MOV EBX,dword ptr [EBP + 0x8]
    s.bx = m.r32((s.bp+0x00000008u));
  }
  L0077e50e: { // 0x77e50e: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L0077e510: { // 0x77e510: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077e511: { // 0x77e511: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  L0077e514: { // 0x77e514: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0077e515: { // 0x77e515: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0077e516: { // 0x77e516: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0077e517: { // 0x77e517: 66895d08 MOV word ptr [EBP + 0x8],BX
    m.w16((s.bp+0x00000008u), (s.bx & 0xffffu));
  }
  L0077e51b: { // 0x77e51b: e8f563ffff CALL 0x00774915
    s.arithmetic_flags=flags; invoke(m,s,f,0x00774915u,7857440u); flags=s.arithmetic_flags;
  }
  L0077e520: { // 0x77e520: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0077e523: { // 0x77e523: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L0077e526: { // 0x77e526: 397d0c CMP dword ptr [EBP + 0xc],EDI
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.di,32,flags);
  }
  L0077e529: { // 0x77e529: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0077e52a: { // 0x77e52a: 7406 JZ 0x0077e532
    if(integer::condition("JZ",flags)) goto L0077e532;
  }
  L0077e52c: { // 0x77e52c: 834e0c20 OR dword ptr [ESI + 0xc],0x20
    m.w32((s.si+0x0000000cu), integer::logical((m.r32((s.si+0x0000000cu)))|(0x00000020u),32,flags));
  }
  L0077e530: { // 0x77e530: eb0e JMP 0x0077e540
    goto L0077e540;
  }
  L0077e532: { // 0x77e532: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0077e534: { // 0x77e534: 25ffff0000 AND EAX,0xffff
    s.ax = integer::logical((s.ax)&(0x0000ffffu),32,flags);
  }
  L0077e539: { // 0x77e539: eb0a JMP 0x0077e545
    goto L0077e545;
  }
  L0077e53b: { // 0x77e53b: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  L0077e53d: { // 0x77e53d: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  L0077e540: { // 0x77e540: b8ffff0000 MOV EAX,0xffff
    s.ax = 0x0000ffffu;
  }
  L0077e545: { // 0x77e545: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0077e546: { // 0x77e546: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0077e547: { // 0x77e547: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L0077e548: { // 0x77e548: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_007804e8(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007804e8: { // 0x7804e8: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007804e9: { // 0x7804e9: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L007804eb: { // 0x7804eb: 83ec10 SUB ESP,0x10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L007804ee: { // 0x7804ee: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  L007804f1: { // 0x7804f1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007804f2: { // 0x7804f2: 8b5d10 MOV EBX,dword ptr [EBP + 0x10]
    s.bx = m.r32((s.bp+0x00000010u));
  }
  L007804f5: { // 0x7804f5: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L007804f7: { // 0x7804f7: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L007804f9: { // 0x7804f9: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007804fa: { // 0x7804fa: c745fc4e400000 MOV dword ptr [EBP + -0x4],0x404e
    m.w32((s.bp-0x00000004u), 0x0000404eu);
  }
  L00780501: { // 0x780501: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L00780503: { // 0x780503: 895304 MOV dword ptr [EBX + 0x4],EDX
    m.w32((s.bx+0x00000004u), s.dx);
  }
  L00780506: { // 0x780506: 895308 MOV dword ptr [EBX + 0x8],EDX
    m.w32((s.bx+0x00000008u), s.dx);
  }
  L00780509: { // 0x780509: 7651 JBE 0x0078055c
    if(integer::condition("JBE",flags)) goto L0078055c;
  }
  L0078050b: { // 0x78050b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0078050c: { // 0x78050c: 894510 MOV dword ptr [EBP + 0x10],EAX
    m.w32((s.bp+0x00000010u), s.ax);
  }
  L0078050f: { // 0x78050f: 8bf3 MOV ESI,EBX
    s.si = s.bx;
  }
  L00780511: { // 0x780511: 8d7df0 LEA EDI,[EBP + -0x10]
    s.di = (s.bp-0x00000010u);
  }
  L00780514: { // 0x780514: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780515: { // 0x780515: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780516: { // 0x780516: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780517: { // 0x780517: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  L00780518: { // 0x780518: e870ffffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865629u); flags=s.arithmetic_flags;
  }
  L0078051d: { // 0x78051d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0078051e: { // 0x78051e: e86affffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865635u); flags=s.arithmetic_flags;
  }
  L00780523: { // 0x780523: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780526: { // 0x780526: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780527: { // 0x780527: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780528: { // 0x780528: e802ffffff CALL 0x0078042f
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078042fu,7865645u); flags=s.arithmetic_flags;
  }
  L0078052d: { // 0x78052d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0078052e: { // 0x78052e: e85affffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865651u); flags=s.arithmetic_flags;
  }
  L00780533: { // 0x780533: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L00780536: { // 0x780536: 8365f400 AND dword ptr [EBP + -0xc],0x0
    m.w32((s.bp-0x0000000cu), integer::logical((m.r32((s.bp-0x0000000cu)))&(0x00000000u),32,flags));
  }
  L0078053a: { // 0x78053a: 8365f800 AND dword ptr [EBP + -0x8],0x0
    m.w32((s.bp-0x00000008u), integer::logical((m.r32((s.bp-0x00000008u)))&(0x00000000u),32,flags));
  }
  L0078053e: { // 0x78053e: 0fbe00 MOVSX EAX,byte ptr [EAX]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.ax)),8));
  }
  L00780541: { // 0x780541: 8945f0 MOV dword ptr [EBP + -0x10],EAX
    m.w32((s.bp-0x00000010u), s.ax);
  }
  L00780544: { // 0x780544: 8d45f0 LEA EAX,[EBP + -0x10]
    s.ax = (s.bp-0x00000010u);
  }
  L00780547: { // 0x780547: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00780548: { // 0x780548: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780549: { // 0x780549: e8e1feffff CALL 0x0078042f
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078042fu,7865678u); flags=s.arithmetic_flags;
  }
  L0078054e: { // 0x78054e: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00780551: { // 0x780551: ff4508 INC dword ptr [EBP + 0x8]
    m.w32((s.bp+0x00000008u), integer::increment(m.r32((s.bp+0x00000008u)),32,flags));
  }
  L00780554: { // 0x780554: ff4d10 DEC dword ptr [EBP + 0x10]
    m.w32((s.bp+0x00000010u), integer::decrement(m.r32((s.bp+0x00000010u)),32,flags));
  }
  L00780557: { // 0x780557: 75b6 JNZ 0x0078050f
    if(integer::condition("JNZ",flags)) goto L0078050f;
  }
  L00780559: { // 0x780559: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0078055b: { // 0x78055b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0078055c: { // 0x78055c: 395308 CMP dword ptr [EBX + 0x8],EDX
    (void)integer::sub(m.r32((s.bx+0x00000008u)),s.dx,32,flags);
  }
  L0078055f: { // 0x78055f: 7528 JNZ 0x00780589
    if(integer::condition("JNZ",flags)) goto L00780589;
  }
  L00780561: { // 0x780561: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00780564: { // 0x780564: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00780566: { // 0x780566: c1e810 SHR EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::right);
  }
  L00780569: { // 0x780569: 894308 MOV dword ptr [EBX + 0x8],EAX
    m.w32((s.bx+0x00000008u), s.ax);
  }
  L0078056c: { // 0x78056c: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0078056e: { // 0x78056e: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00780570: { // 0x780570: c1ee10 SHR ESI,0x10
    s.si = integer::shift(s.si,0x00000010u,32,flags,integer::Shift::right);
  }
  L00780573: { // 0x780573: c1e110 SHL ECX,0x10
    s.cx = integer::shift(s.cx,0x00000010u,32,flags,integer::Shift::left);
  }
  L00780576: { // 0x780576: 0bf1 OR ESI,ECX
    s.si = integer::logical((s.si)|(s.cx),32,flags);
  }
  L00780578: { // 0x780578: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0078057b: { // 0x78057b: 8145fcf0ff0000 ADD dword ptr [EBP + -0x4],0xfff0
    m.w32((s.bp-0x00000004u), integer::add(m.r32((s.bp-0x00000004u)),0x0000fff0u,32,flags));
  }
  L00780582: { // 0x780582: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L00780585: { // 0x780585: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L00780587: { // 0x780587: ebd3 JMP 0x0078055c
    goto L0078055c;
  }
  L00780589: { // 0x780589: be00800000 MOV ESI,0x8000
    s.si = 0x00008000u;
  }
  L0078058e: { // 0x78058e: 857308 TEST dword ptr [EBX + 0x8],ESI
    (void)integer::logical((m.r32((s.bx+0x00000008u)))&(s.si),32,flags);
  }
  L00780591: { // 0x780591: 7510 JNZ 0x007805a3
    if(integer::condition("JNZ",flags)) goto L007805a3;
  }
  L00780593: { // 0x780593: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00780594: { // 0x780594: e8f4feffff CALL 0x0078048d
    s.arithmetic_flags=flags; invoke(m,s,f,0x0078048du,7865753u); flags=s.arithmetic_flags;
  }
  L00780599: { // 0x780599: 8145fcffff0000 ADD dword ptr [EBP + -0x4],0xffff
    m.w32((s.bp-0x00000004u), integer::add(m.r32((s.bp-0x00000004u)),0x0000ffffu,32,flags));
  }
  L007805a0: { // 0x7805a0: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L007805a1: { // 0x7805a1: ebeb JMP 0x0078058e
    goto L0078058e;
  }
  L007805a3: { // 0x7805a3: 668b45fc MOV AX,word ptr [EBP + -0x4]
    s.ax = with_ax(s.ax, m.r16((s.bp-0x00000004u)));
  }
  L007805a7: { // 0x7805a7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007805a8: { // 0x7805a8: 6689430a MOV word ptr [EBX + 0xa],AX
    m.w16((s.bx+0x0000000au), (s.ax & 0xffffu));
  }
  L007805ac: { // 0x7805ac: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L007805ad: { // 0x7805ad: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  L007805ae: { // 0x7805ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
