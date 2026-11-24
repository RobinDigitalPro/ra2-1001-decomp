#include "platform/observed_ticks152.hpp"
#include "recovered/recovery_b1722_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b1722 {
namespace {
void f_0028fad0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0028fad0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0068fad0: { // 0x0068fad0: ff1524557800 CALL dword ptr [0x00785524]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00785524u)),6879958u); flags=s.arithmetic_flags;
  }
  L0068fad6: { // 0x0068fad6: c1e804 SHR EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::right);
  }
  L0068fad9: { // 0x0068fad9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 if(target==m.r32(0x785524u)&&target==std::uint32_t(reinterpret_cast<std::uintptr_t>(&ra2::platform::ticks152::Tick::get))){
  // stdcall WinMM timeGetTime(void): push/pop the return address, real observed OS result in EAX.
  f.push(m,continuation);s.ax=ra2::platform::ticks152::Tick::get();(void)f.pop(m);return;}
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6879952u:f_0028fad0(m,s,child,{});break;
default:throw std::domain_error("recovery1722 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_006ce540(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L006ce540: { // 0x6ce540: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L006ce543: { // 0x6ce543: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006ce544: { // 0x6ce544: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L006ce546: { // 0x6ce546: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L006ce548: { // 0x6ce548: 746a JZ 0x006ce5b4
    if(integer::condition("JZ",flags)) goto L006ce5b4;
  }
  L006ce54a: { // 0x6ce54a: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006ce54c: { // 0x6ce54c: 7466 JZ 0x006ce5b4
    if(integer::condition("JZ",flags)) goto L006ce5b4;
  }
  L006ce54e: { // 0x6ce54e: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  L006ce553: { // 0x6ce553: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006ce554: { // 0x6ce554: 8915d07caa00 MOV dword ptr [0x00aa7cd0],EDX
    m.w32((0x00aa7cd0u), s.dx);
  }
  L006ce55a: { // 0x6ce55a: 8935cc7caa00 MOV dword ptr [0x00aa7ccc],ESI
    m.w32((0x00aa7cccu), s.si);
  }
  L006ce560: { // 0x6ce560: 8bb844140000 MOV EDI,dword ptr [EAX + 0x1444]
    s.di = m.r32((s.ax+0x00001444u));
  }
  L006ce566: { // 0x6ce566: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L006ce56a: { // 0x6ce56a: e86115fcff CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,7136623u); flags=s.arithmetic_flags;
  }
  L006ce56f: { // 0x6ce56f: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L006ce573: { // 0x6ce573: 8b15e4e0a100 MOV EDX,dword ptr [0x00a1e0e4]
    s.dx = m.r32((0x00a1e0e4u));
  }
  L006ce579: { // 0x6ce579: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ce57b: { // 0x6ce57b: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L006ce57d: { // 0x6ce57d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ce57f: { // 0x6ce57f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ce581: { // 0x6ce581: 890d747caa00 MOV dword ptr [0x00aa7c74],ECX
    m.w32((0x00aa7c74u), s.cx);
  }
  L006ce587: { // 0x6ce587: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L006ce589: { // 0x6ce589: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L006ce58a: { // 0x6ce58a: 8d4c2420 LEA ECX,[ESP + 0x20]
    s.cx = (f.sp+0x00000020u);
  }
  L006ce58e: { // 0x6ce58e: a3707caa00 MOV [0x00aa7c70],EAX
    m.w32((0x00aa7c70u), s.ax);
  }
  L006ce593: { // 0x6ce593: 893d787caa00 MOV dword ptr [0x00aa7c78],EDI
    m.w32((0x00aa7c78u), s.di);
  }
  L006ce599: { // 0x6ce599: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L006ce59b: { // 0x6ce59b: 6a02 PUSH 0x2
    f.push(m,0x00000002u);
  }
  L006ce59d: { // 0x6ce59d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L006ce59e: { // 0x6ce59e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L006ce5a0: { // 0x6ce5a0: ff5048 CALL dword ptr [EAX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000048u)),7136675u); flags=s.arithmetic_flags;
  }
  L006ce5a3: { // 0x6ce5a3: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006ce5a8: { // 0x6ce5a8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006ce5a9: { // 0x6ce5a9: e8328be7ff CALL 0x005470e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005470e0u,7136686u); flags=s.arithmetic_flags;
  }
  L006ce5ae: { // 0x6ce5ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L006ce5af: { // 0x6ce5af: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce5b0: { // 0x6ce5b0: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006ce5b3: { // 0x6ce5b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L006ce5b4: { // 0x6ce5b4: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L006ce5b8: { // 0x6ce5b8: c705d07caa0000000000 MOV dword ptr [0x00aa7cd0],0x0
    m.w32((0x00aa7cd0u), 0x00000000u);
  }
  L006ce5c2: { // 0x6ce5c2: c705cc7caa0000000000 MOV dword ptr [0x00aa7ccc],0x0
    m.w32((0x00aa7cccu), 0x00000000u);
  }
  L006ce5cc: { // 0x6ce5cc: e8ff14fcff CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,7136721u); flags=s.arithmetic_flags;
  }
  L006ce5d1: { // 0x6ce5d1: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  L006ce5d5: { // 0x6ce5d5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L006ce5d7: { // 0x6ce5d7: a3707caa00 MOV [0x00aa7c70],EAX
    m.w32((0x00aa7c70u), s.ax);
  }
  L006ce5dc: { // 0x6ce5dc: 8915747caa00 MOV dword ptr [0x00aa7c74],EDX
    m.w32((0x00aa7c74u), s.dx);
  }
  L006ce5e2: { // 0x6ce5e2: 890d787caa00 MOV dword ptr [0x00aa7c78],ECX
    m.w32((0x00aa7c78u), s.cx);
  }
  L006ce5e8: { // 0x6ce5e8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L006ce5e9: { // 0x6ce5e9: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L006ce5ec: { // 0x6ce5ec: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
