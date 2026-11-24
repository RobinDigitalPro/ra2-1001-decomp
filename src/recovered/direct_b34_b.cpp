#include "recovered/direct_b34_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::direct_b34 {
namespace {
void f_0013d140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53d140: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53d141: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x53d143: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x53d146: c70694087900 MOV dword ptr [ESI],0x790894
    m.w32((s.si), 0x00790894u);
  }
  { // 0x53d14c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53d14d: e829052300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x53d152: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x53d155: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x53d15c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53d15d: e819052300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x53d162: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x53d165: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53d167: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x53d16e: e8cd940c00 CALL 0x00606640
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x53d173: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x53d178: 7409 JZ 0x0053d183
    if(integer::condition("JZ",flags)) goto L0053d183;
  }
  { // 0x53d17a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53d17b: e8fb042300 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x53d180: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0053d183: { // 0x53d183: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x53d185: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53d186: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0013d1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53d1f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53d1f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x53d1f3: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x53d1f6: c706ac087900 MOV dword ptr [ESI],0x7908ac
    m.w32((s.si), 0x007908acu);
  }
  { // 0x53d1fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53d1fd: e879042300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x53d202: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x53d205: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x53d20c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53d20d: e869042300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x53d212: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x53d215: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53d217: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x53d21e: e88d341500 CALL 0x006906b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x53d223: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53d224: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0013d3e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x53d3e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53d3e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x53d3e3: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x53d3e6: c706ac087900 MOV dword ptr [ESI],0x7908ac
    m.w32((s.si), 0x007908acu);
  }
  { // 0x53d3ec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x53d3ed: e889022300 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x53d3f2: 8b4e18 MOV ECX,dword ptr [ESI + 0x18]
    s.cx = m.r32((s.si+0x00000018u));
  }
  { // 0x53d3f5: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  { // 0x53d3fc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x53d3fd: e879022300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x53d402: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x53d405: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x53d407: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x53d40e: e89d321500 CALL 0x006906b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x53d413: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x53d418: 7409 JZ 0x0053d423
    if(integer::condition("JZ",flags)) goto L0053d423;
  }
  { // 0x53d41a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x53d41b: e85b022300 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x53d420: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0053d423: { // 0x53d423: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x53d425: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x53d426: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00173dd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x573dd0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x573dd1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x573dd3: 68d10e0000 PUSH 0xed1
    f.push(m,0x00000ed1u);
  }
  { // 0x573dd8: 68d0bf7c00 PUSH 0x7cbfd0
    f.push(m,0x007cbfd0u);
  }
  { // 0x573ddd: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x573ddf: b9b4bf7c00 MOV ECX,0x7cbfb4
    s.cx = 0x007cbfb4u;
  }
  { // 0x573de4: e877ad1700 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x573de9: 83c678 ADD ESI,0x78
    s.si = integer::add(s.si,0x00000078u,32,flags);
  }
  { // 0x573dec: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x573ded: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x573dee: e8d6b11f00 CALL 0x0076efc9
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x573df3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x573df6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x573df7: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001803f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5803f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5803f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5803f3: 8b463c MOV EAX,dword ptr [ESI + 0x3c]
    s.ax = m.r32((s.si+0x0000003cu));
  }
  { // 0x5803f6: 83f804 CMP EAX,0x4
    (void)integer::sub(s.ax,0x00000004u,32,flags);
  }
  { // 0x5803f9: 7405 JZ 0x00580400
    if(integer::condition("JZ",flags)) goto L00580400;
  }
  { // 0x5803fb: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x5803fe: 7526 JNZ 0x00580426
    if(integer::condition("JNZ",flags)) goto L00580426;
  }
  L00580400: { // 0x580400: e8abcefeff CALL 0x0056d2b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x580405: e8f6d1feff CALL 0x0056d600
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x58040a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x58040c: e8affbffff CALL 0x0057ffc0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x580411: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x580413: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x580415: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x58041a: e8317afdff CALL 0x00557e50
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x58041f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x580421: e8aaf9ffff CALL 0x0057fdd0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  L00580426: { // 0x580426: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x580427: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0018cac0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58cac0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58cac1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x58cac3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x58cac5: 8d8ec8000000 LEA ECX,[ESI + 0xc8]
    s.cx = (s.si+0x000000c8u);
  }
  { // 0x58cacb: e850c91c00 CALL 0x00759420
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x58cad0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x58cad2: 7414 JZ 0x0058cae8
    if(integer::condition("JZ",flags)) goto L0058cae8;
  }
  { // 0x58cad4: 83becc000000ff CMP dword ptr [ESI + 0xcc],-0x1
    (void)integer::sub(m.r32((s.si+0x000000ccu)),0xffffffffu,32,flags);
  }
  { // 0x58cadb: 740b JZ 0x0058cae8
    if(integer::condition("JZ",flags)) goto L0058cae8;
  }
  { // 0x58cadd: 8d8ed0000000 LEA ECX,[ESI + 0xd0]
    s.cx = (s.si+0x000000d0u);
  }
  { // 0x58cae3: e8e82f1000 CALL 0x0068fad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L0058cae8: { // 0x58cae8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58cae9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0018cba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x58cba0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58cba1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x58cba3: 8d8ec8000000 LEA ECX,[ESI + 0xc8]
    s.cx = (s.si+0x000000c8u);
  }
  { // 0x58cba9: e872c71c00 CALL 0x00759320
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x58cbae: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x58cbb1: e8caff0100 CALL 0x005acb80
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x58cbb6: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x58cbb8: e8932c0200 CALL 0x005af850
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x58cbbd: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x58cbc2: 7409 JZ 0x0058cbcd
    if(integer::condition("JZ",flags)) goto L0058cbcd;
  }
  { // 0x58cbc4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x58cbc5: e8b10a1e00 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x58cbca: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0058cbcd: { // 0x58cbcd: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x58cbcf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x58cbd0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00190110(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x590110: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x590111: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x590113: c7065c117900 MOV dword ptr [ESI],0x79115c
    m.w32((s.si), 0x0079115cu);
  }
  { // 0x590119: c7460494107900 MOV dword ptr [ESI + 0x4],0x791094
    m.w32((s.si+0x00000004u), 0x00791094u);
  }
  { // 0x590120: e8abb0faff CALL 0x0053b1d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x590125: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x59012a: 7409 JZ 0x00590135
    if(integer::condition("JZ",flags)) goto L00590135;
  }
  { // 0x59012c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59012d: e849d51d00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x590132: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00590135: { // 0x590135: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x590137: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x590138: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00191f30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x591f30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x591f31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x591f33: c706e8117900 MOV dword ptr [ESI],0x7911e8
    m.w32((s.si), 0x007911e8u);
  }
  { // 0x591f39: c74604cc117900 MOV dword ptr [ESI + 0x4],0x7911cc
    m.w32((s.si+0x00000004u), 0x007911ccu);
  }
  { // 0x591f40: c74608c4117900 MOV dword ptr [ESI + 0x8],0x7911c4
    m.w32((s.si+0x00000008u), 0x007911c4u);
  }
  { // 0x591f47: c7460cbc117900 MOV dword ptr [ESI + 0xc],0x7911bc
    m.w32((s.si+0x0000000cu), 0x007911bcu);
  }
  { // 0x591f4e: e86d8c0300 CALL 0x005cabc0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x591f53: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x591f58: 7409 JZ 0x00591f63
    if(integer::condition("JZ",flags)) goto L00591f63;
  }
  { // 0x591f5a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x591f5b: e81bb71d00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x591f60: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00591f63: { // 0x591f63: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x591f65: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x591f66: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001929f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5929f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5929f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5929f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5929f4: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  { // 0x5929f7: c70648147900 MOV dword ptr [ESI],0x791448
    m.w32((s.si), 0x00791448u);
  }
  { // 0x5929fd: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5929ff: 7410 JZ 0x00592a11
    if(integer::condition("JZ",flags)) goto L00592a11;
  }
  { // 0x592a01: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x592a03: e8a82aeaff CALL 0x004354b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x592a08: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x592a09: e86dac1d00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x592a0e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00592a11: { // 0x592a11: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x592a13: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  { // 0x592a1a: e891dc0f00 CALL 0x006906b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x592a1f: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x592a24: 7409 JZ 0x00592a2f
    if(integer::condition("JZ",flags)) goto L00592a2f;
  }
  { // 0x592a26: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x592a27: e84fac1d00 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x592a2c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00592a2f: { // 0x592a2f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x592a31: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x592a32: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x592a33: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0019b5e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59b5e0: a0228ba500 MOV AL,[0x00a58b22]
    s.ax = with_al(s.ax, m.r8((0x00a58b22u)));
  }
  { // 0x59b5e5: 81ec00010000 SUB ESP,0x100
    f.sp = integer::sub(f.sp,0x00000100u,32,flags);
  }
  { // 0x59b5eb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x59b5ed: 7436 JZ 0x0059b625
    if(integer::condition("JZ",flags)) goto L0059b625;
  }
  { // 0x59b5ef: 8b8c2408010000 MOV ECX,dword ptr [ESP + 0x108]
    s.cx = m.r32((f.sp+0x00000108u));
  }
  { // 0x59b5f6: 8d84240c010000 LEA EAX,[ESP + 0x10c]
    s.ax = (f.sp+0x0000010cu);
  }
  { // 0x59b5fd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59b5fe: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x59b602: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x59b603: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x59b604: e8b14c1d00 CALL 0x007702ba
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59b609: 8b8c2410010000 MOV ECX,dword ptr [ESP + 0x110]
    s.cx = m.r32((f.sp+0x00000110u));
  }
  { // 0x59b610: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x59b613: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x59b617: c68424ff00000000 MOV byte ptr [ESP + 0xff],0x0
    m.w8((f.sp+0x000000ffu), 0x00000000u);
  }
  { // 0x59b61f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59b620: e89bfeffff CALL 0x0059b4c0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L0059b625: { // 0x59b625: 81c400010000 ADD ESP,0x100
    f.sp = integer::add(f.sp,0x00000100u,32,flags);
  }
  { // 0x59b62b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019c2e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59c2e0: e88b9e0f00 CALL 0x00696170
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59c2e5: babc8ba500 MOV EDX,0xa58bbc
    s.dx = 0x00a58bbcu;
  }
  { // 0x59c2ea: b9706a7c00 MOV ECX,0x7c6a70
    s.cx = 0x007c6a70u;
  }
  { // 0x59c2ef: e85c8defff CALL 0x00495050
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59c2f4: a37c8ba500 MOV [0x00a58b7c],EAX
    m.w32((0x00a58b7cu), s.ax);
  }
  { // 0x59c2f9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019d8b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59d8b0: a0348ca500 MOV AL,[0x00a58c34]
    s.ax = with_al(s.ax, m.r8((0x00a58c34u)));
  }
  { // 0x59d8b5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x59d8b7: 743b JZ 0x0059d8f4
    if(integer::condition("JZ",flags)) goto L0059d8f4;
  }
  { // 0x59d8b9: e892a8e6ff CALL 0x00408150
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59d8be: e84da9e6ff CALL 0x00408210
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59d8c3: e828aae6ff CALL 0x004082f0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x59d8c8: 8b0da8978100 MOV ECX,dword ptr [0x008197a8]
    s.cx = m.r32((0x008197a8u));
  }
  { // 0x59d8ce: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x59d8d3: e8c897e6ff CALL 0x004070a0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x59d8d8: 8b0da0978100 MOV ECX,dword ptr [0x008197a0]
    s.cx = m.r32((0x008197a0u));
  }
  { // 0x59d8de: ba00400000 MOV EDX,0x4000
    s.dx = 0x00004000u;
  }
  { // 0x59d8e3: e8b897e6ff CALL 0x004070a0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x59d8e8: e8c3dc1600 CALL 0x0070b5b0
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x59d8ed: c605348ca50000 MOV byte ptr [0x00a58c34],0x0
    m.w8((0x00a58c34u), 0x00000000u);
  }
  L0059d8f4: { // 0x59d8f4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019d900(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59d900: a0348ca500 MOV AL,[0x00a58c34]
    s.ax = with_al(s.ax, m.r8((0x00a58c34u)));
  }
  { // 0x59d905: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x59d907: 7536 JNZ 0x0059d93f
    if(integer::condition("JNZ",flags)) goto L0059d93f;
  }
  { // 0x59d909: e832dc1600 CALL 0x0070b540
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59d90e: e80da8e6ff CALL 0x00408120
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59d913: e878a8e6ff CALL 0x00408190
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x59d918: 8b0da8978100 MOV ECX,dword ptr [0x008197a8]
    s.cx = m.r32((0x008197a8u));
  }
  { // 0x59d91e: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x59d923: e87897e6ff CALL 0x004070a0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x59d928: 8b0da0978100 MOV ECX,dword ptr [0x008197a0]
    s.cx = m.r32((0x008197a0u));
  }
  { // 0x59d92e: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x59d933: e86897e6ff CALL 0x004070a0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x59d938: c605348ca50001 MOV byte ptr [0x00a58c34],0x1
    m.w8((0x00a58c34u), 0x00000001u);
  }
  L0059d93f: { // 0x59d93f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019e260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59e260: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59e261: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59e263: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x59e265: 744b JZ 0x0059e2b2
    if(integer::condition("JZ",flags)) goto L0059e2b2;
  }
  { // 0x59e267: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x59e269: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e26a: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x59e26c: 7421 JZ 0x0059e28f
    if(integer::condition("JZ",flags)) goto L0059e28f;
  }
  { // 0x59e26e: e83d3b1700 CALL 0x00711db0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59e273: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x59e275: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x59e277: 7410 JZ 0x0059e289
    if(integer::condition("JZ",flags)) goto L0059e289;
  }
  { // 0x59e279: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x59e27b: e8e0311700 CALL 0x00711460
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59e280: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e281: e8f5f31c00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x59e286: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0059e289: { // 0x59e289: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  L0059e28f: { // 0x59e28f: 8b7e48 MOV EDI,dword ptr [ESI + 0x48]
    s.di = m.r32((s.si+0x00000048u));
  }
  { // 0x59e292: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x59e294: 7417 JZ 0x0059e2ad
    if(integer::condition("JZ",flags)) goto L0059e2ad;
  }
  { // 0x59e296: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x59e298: e8a3260f00 CALL 0x00690940
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x59e29d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e29e: e8d8f31c00 CALL 0x0076d67b
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x59e2a3: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x59e2a6: c7464800000000 MOV dword ptr [ESI + 0x48],0x0
    m.w32((s.si+0x00000048u), 0x00000000u);
  }
  L0059e2ad: { // 0x59e2ad: c6464500 MOV byte ptr [ESI + 0x45],0x0
    m.w8((s.si+0x00000045u), 0x00000000u);
  }
  { // 0x59e2b1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0059e2b2: { // 0x59e2b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59e2b3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019e550(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59e550: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59e551: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59e553: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e554: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x59e556: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x59e558: 741b JZ 0x0059e575
    if(integer::condition("JZ",flags)) goto L0059e575;
  }
  { // 0x59e55a: e851381700 CALL 0x00711db0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59e55f: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x59e561: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x59e563: 7410 JZ 0x0059e575
    if(integer::condition("JZ",flags)) goto L0059e575;
  }
  { // 0x59e565: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x59e567: e8f42e1700 CALL 0x00711460
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59e56c: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e56d: e809f11c00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x59e572: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0059e575: { // 0x59e575: 8b7e48 MOV EDI,dword ptr [ESI + 0x48]
    s.di = m.r32((s.si+0x00000048u));
  }
  { // 0x59e578: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x59e57a: 7417 JZ 0x0059e593
    if(integer::condition("JZ",flags)) goto L0059e593;
  }
  { // 0x59e57c: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x59e57e: e8bd230f00 CALL 0x00690940
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x59e583: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e584: e8f2f01c00 CALL 0x0076d67b
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x59e589: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x59e58c: c7464800000000 MOV dword ptr [ESI + 0x48],0x0
    m.w32((s.si+0x00000048u), 0x00000000u);
  }
  L0059e593: { // 0x59e593: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x59e594: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59e595: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019e6f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59e6f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59e6f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59e6f3: 8b4610 MOV EAX,dword ptr [ESI + 0x10]
    s.ax = m.r32((s.si+0x00000010u));
  }
  { // 0x59e6f6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x59e6f8: e8d3361700 CALL 0x00711dd0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59e6fd: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x59e701: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    s.dx = m.r32((s.si+0x00000010u));
  }
  { // 0x59e704: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x59e705: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  { // 0x59e707: e814311700 CALL 0x00711820
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59e70c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59e70d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0019e940(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59e940: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59e941: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59e943: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e944: 8b7e10 MOV EDI,dword ptr [ESI + 0x10]
    s.di = m.r32((s.si+0x00000010u));
  }
  { // 0x59e947: c70664167900 MOV dword ptr [ESI],0x791664
    m.w32((s.si), 0x00791664u);
  }
  { // 0x59e94d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x59e94f: 7410 JZ 0x0059e961
    if(integer::condition("JZ",flags)) goto L0059e961;
  }
  { // 0x59e951: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x59e953: e88814e9ff CALL 0x0042fde0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59e958: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59e959: e81ded1c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59e95e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0059e961: { // 0x59e961: c70638167900 MOV dword ptr [ESI],0x791638
    m.w32((s.si), 0x00791638u);
  }
  { // 0x59e967: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x59e968: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59e969: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0019ed50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59ed50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59ed51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x59ed53: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59ed54: 8b7e10 MOV EDI,dword ptr [ESI + 0x10]
    s.di = m.r32((s.si+0x00000010u));
  }
  { // 0x59ed57: c70664167900 MOV dword ptr [ESI],0x791664
    m.w32((s.si), 0x00791664u);
  }
  { // 0x59ed5d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x59ed5f: 7410 JZ 0x0059ed71
    if(integer::condition("JZ",flags)) goto L0059ed71;
  }
  { // 0x59ed61: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x59ed63: e87810e9ff CALL 0x0042fde0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59ed68: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59ed69: e80de91c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59ed6e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0059ed71: { // 0x59ed71: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x59ed75: c70638167900 MOV dword ptr [ESI],0x791638
    m.w32((s.si), 0x00791638u);
  }
  { // 0x59ed7b: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x59ed7d: 7409 JZ 0x0059ed88
    if(integer::condition("JZ",flags)) goto L0059ed88;
  }
  { // 0x59ed7f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59ed80: e8f6e81c00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x59ed85: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0059ed88: { // 0x59ed88: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x59ed8a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x59ed8b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59ed8c: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0019f310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x59f310: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x59f313: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x59f314: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x59f315: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59f316: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x59f318: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x59f31a: 6a0c PUSH 0xc
    f.push(m,0x0000000cu);
  }
  { // 0x59f31c: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  { // 0x59f320: e832e61c00 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x59f325: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x59f327: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x59f32a: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x59f32c: 7421 JZ 0x0059f34f
    if(integer::condition("JZ",flags)) goto L0059f34f;
  }
  { // 0x59f32e: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x59f330: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x59f334: bb01000000 MOV EBX,0x1
    s.bx = 0x00000001u;
  }
  { // 0x59f339: e8c2d61b00 CALL 0x0075ca00
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x59f33e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x59f340: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x59f341: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x59f342: e869700100 CALL 0x005b63b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x59f347: c70644177900 MOV dword ptr [ESI],0x791744
    m.w32((s.si), 0x00791744u);
  }
  { // 0x59f34d: eb02 JMP 0x0059f351
    goto L0059f351;
  }
  L0059f34f: { // 0x59f34f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0059f351: { // 0x59f351: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x59f354: 7409 JZ 0x0059f35f
    if(integer::condition("JZ",flags)) goto L0059f35f;
  }
  { // 0x59f356: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x59f35a: e831c01b00 CALL 0x0075b390
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  L0059f35f: { // 0x59f35f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x59f361: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x59f362: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x59f363: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x59f364: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x59f367: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a0600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a0600: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a0601: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a0603: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x5a0606: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x5a0608: 7504 JNZ 0x005a060e
    if(integer::condition("JNZ",flags)) goto L005a060e;
  }
  { // 0x5a060a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5a060c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a060d: c3 RET
    finish(m,s,f,0u); return;
  }
  L005a060e: { // 0x5a060e: 8d8660020000 LEA EAX,[ESI + 0x260]
    s.ax = (s.si+0x00000260u);
  }
  { // 0x5a0614: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a0615: e876deeeff CALL 0x0048e490
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a061a: e8b1d10100 CALL 0x005bd7d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a061f: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5a0621: 7419 JZ 0x005a063c
    if(integer::condition("JZ",flags)) goto L005a063c;
  }
  { // 0x5a0623: 8a8e64020000 MOV CL,byte ptr [ESI + 0x264]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000264u)));
  }
  { // 0x5a0629: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x5a062b: 740f JZ 0x005a063c
    if(integer::condition("JZ",flags)) goto L005a063c;
  }
  { // 0x5a062d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a062e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5a0630: e85bfeffff CALL 0x005a0490
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5a0635: c6866402000000 MOV byte ptr [ESI + 0x264],0x0
    m.w8((s.si+0x00000264u), 0x00000000u);
  }
  L005a063c: { // 0x5a063c: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  { // 0x5a063f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5a0640: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x5a0643: e8e8f8eeff CALL 0x0048ff30
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5a0648: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a0649: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a1bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a1bc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a1bc1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a1bc3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5a1bc4: 8b7e44 MOV EDI,dword ptr [ESI + 0x44]
    s.di = m.r32((s.si+0x00000044u));
  }
  { // 0x5a1bc7: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5a1bc9: 7410 JZ 0x005a1bdb
    if(integer::condition("JZ",flags)) goto L005a1bdb;
  }
  { // 0x5a1bcb: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5a1bcd: e85ec3eeff CALL 0x0048df30
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a1bd2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5a1bd3: e8a3ba1c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a1bd8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005a1bdb: { // 0x5a1bdb: 6a70 PUSH 0x70
    f.push(m,0x00000070u);
  }
  { // 0x5a1bdd: c7464400000000 MOV dword ptr [ESI + 0x44],0x0
    m.w32((s.si+0x00000044u), 0x00000000u);
  }
  { // 0x5a1be4: e86ebd1c00 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5a1be9: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5a1bec: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5a1bee: 7409 JZ 0x005a1bf9
    if(integer::condition("JZ",flags)) goto L005a1bf9;
  }
  { // 0x5a1bf0: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5a1bf2: e829c2eeff CALL 0x0048de20
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5a1bf7: eb02 JMP 0x005a1bfb
    goto L005a1bfb;
  }
  L005a1bf9: { // 0x5a1bf9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005a1bfb: { // 0x5a1bfb: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5a1bfd: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5a1bff: 894644 MOV dword ptr [ESI + 0x44],EAX
    m.w32((s.si+0x00000044u), s.ax);
  }
  { // 0x5a1c02: e869d7eeff CALL 0x0048f370
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x5a1c07: 833db87da20002 CMP dword ptr [0x00a27db8],0x2
    (void)integer::sub(m.r32((0x00a27db8u)),0x00000002u,32,flags);
  }
  { // 0x5a1c0e: 7514 JNZ 0x005a1c24
    if(integer::condition("JNZ",flags)) goto L005a1c24;
  }
  { // 0x5a1c10: a1ac7da200 MOV EAX,[0x00a27dac]
    s.ax = m.r32((0x00a27dacu));
  }
  { // 0x5a1c15: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x5a1c18: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x5a1c1a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5a1c1b: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x5a1c1e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5a1c1f: e84cc3eeff CALL 0x0048df70
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  L005a1c24: { // 0x5a1c24: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x5a1c27: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5a1c28: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5a1c2a: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5a1c2d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a1c2e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a4020(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a4020: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5a4021: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a4022: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5a4024: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a4026: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5a4028: 6a6c PUSH 0x6c
    f.push(m,0x0000006cu);
  }
  { // 0x5a402a: 68b4e37c00 PUSH 0x7ce3b4
    f.push(m,0x007ce3b4u);
  }
  { // 0x5a402f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5a4031: b9d4697c00 MOV ECX,0x7c69d4
    s.cx = 0x007c69d4u;
  }
  { // 0x5a4036: c744241424167c00 MOV dword ptr [ESP + 0x14],0x7c1624
    m.w32((f.sp+0x00000014u), 0x007c1624u);
  }
  { // 0x5a403e: e81dab1400 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a4043: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5a4045: b9006a7c00 MOV ECX,0x7c6a00
    s.cx = 0x007c6a00u;
  }
  { // 0x5a404a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a404b: 6a6c PUSH 0x6c
    f.push(m,0x0000006cu);
  }
  { // 0x5a404d: 68b4e37c00 PUSH 0x7ce3b4
    f.push(m,0x007ce3b4u);
  }
  { // 0x5a4052: e809ab1400 CALL 0x006eeb60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a4057: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x5a405b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a405c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a405d: e82ed20000 CALL 0x005b1290
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5a4062: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x5a4064: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x5a4066: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a4067: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5a4068: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5a4069: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a73a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a73a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5a73a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a73a2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a73a4: 6a05 PUSH 0x5
    f.push(m,0x00000005u);
  }
  { // 0x5a73a6: 68b8ff7c00 PUSH 0x7cffb8
    f.push(m,0x007cffb8u);
  }
  { // 0x5a73ab: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5a73ad: b9a8ff7c00 MOV ECX,0x7cffa8
    s.cx = 0x007cffa8u;
  }
  { // 0x5a73b2: e8a9771400 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a73b7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a73b8: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x5a73bc: e83f3f1b00 CALL 0x0075b300
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a73c1: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x5a73c5: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x5a73c7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a73c8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5a73ca: e8e1ef0000 CALL 0x005b63b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5a73cf: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x5a73d3: e8b83f1b00 CALL 0x0075b390
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5a73d8: c706301b7900 MOV dword ptr [ESI],0x791b30
    m.w32((s.si), 0x00791b30u);
  }
  { // 0x5a73de: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5a73e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a73e1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5a73e2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a89a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a89a0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5a89a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a89a2: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a89a4: 6a06 PUSH 0x6
    f.push(m,0x00000006u);
  }
  { // 0x5a89a6: 68ec017d00 PUSH 0x7d01ec
    f.push(m,0x007d01ecu);
  }
  { // 0x5a89ab: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5a89ad: b9dc017d00 MOV ECX,0x7d01dc
    s.cx = 0x007d01dcu;
  }
  { // 0x5a89b2: e8a9611400 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a89b7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a89b8: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x5a89bc: e83f291b00 CALL 0x0075b300
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a89c1: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x5a89c5: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5a89c7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a89c8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5a89ca: e8e1d90000 CALL 0x005b63b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5a89cf: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x5a89d3: e8b8291b00 CALL 0x0075b390
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5a89d8: c7062c1c7900 MOV dword ptr [ESI],0x791c2c
    m.w32((s.si), 0x00791c2cu);
  }
  { // 0x5a89de: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5a89e0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a89e1: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5a89e2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a8a40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a8a40: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5a8a41: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a8a42: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a8a44: 6a16 PUSH 0x16
    f.push(m,0x00000016u);
  }
  { // 0x5a8a46: 68ec017d00 PUSH 0x7d01ec
    f.push(m,0x007d01ecu);
  }
  { // 0x5a8a4b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x5a8a4d: b934027d00 MOV ECX,0x7d0234
    s.cx = 0x007d0234u;
  }
  { // 0x5a8a52: e809611400 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a8a57: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a8a58: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x5a8a5c: e89f281b00 CALL 0x0075b300
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a8a61: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x5a8a65: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x5a8a67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5a8a68: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5a8a6a: e841d90000 CALL 0x005b63b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5a8a6f: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x5a8a73: e818291b00 CALL 0x0075b390
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5a8a78: c7063c1c7900 MOV dword ptr [ESI],0x791c3c
    m.w32((s.si), 0x00791c3cu);
  }
  { // 0x5a8a7e: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5a8a80: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a8a81: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x5a8a82: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001a9280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a9280: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5a9284: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a9285: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a9287: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x5a928b: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x5a928e: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x5a9291: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x5a9294: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  { // 0x5a9298: e833680e00 CALL 0x0068fad0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a929d: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5a92a1: 8a4c241c MOV CL,byte ptr [ESP + 0x1c]
    s.cx = with_al(s.cx, m.r8((f.sp+0x0000001cu)));
  }
  { // 0x5a92a5: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x5a92a8: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x5a92ac: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x5a92b3: 895620 MOV dword ptr [ESI + 0x20],EDX
    m.w32((s.si+0x00000020u), s.dx);
  }
  { // 0x5a92b6: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x5a92ba: 884e34 MOV byte ptr [ESI + 0x34],CL
    m.w8((s.si+0x00000034u), (s.cx & 0xffu));
  }
  { // 0x5a92bd: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5a92c1: 895638 MOV dword ptr [ESI + 0x38],EDX
    m.w32((s.si+0x00000038u), s.dx);
  }
  { // 0x5a92c4: 8d563c LEA EDX,[ESI + 0x3c]
    s.dx = (s.si+0x0000003cu);
  }
  { // 0x5a92c7: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  { // 0x5a92ca: c7462800000000 MOV dword ptr [ESI + 0x28],0x0
    m.w32((s.si+0x00000028u), 0x00000000u);
  }
  { // 0x5a92d1: c706381d7900 MOV dword ptr [ESI],0x791d38
    m.w32((s.si), 0x00791d38u);
  }
  { // 0x5a92d7: c60200 MOV byte ptr [EDX],0x0
    m.w8((s.dx), 0x00000000u);
  }
  { // 0x5a92da: e811beeeff CALL 0x004950f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a92df: 89461c MOV dword ptr [ESI + 0x1c],EAX
    m.w32((s.si+0x0000001cu), s.ax);
  }
  { // 0x5a92e2: c7462c00000000 MOV dword ptr [ESI + 0x2c],0x0
    m.w32((s.si+0x0000002cu), 0x00000000u);
  }
  { // 0x5a92e9: 0fbf4006 MOVSX EAX,word ptr [EAX + 0x6]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  { // 0x5a92ed: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x5a92ee: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x5a92f1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5a92f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a92f4: c21c00 RET 0x1c
    finish(m,s,f,28u); return;
  }
}
void f_001a9990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5a9990: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5a9994: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5a9995: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5a9996: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5a9998: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5a999c: 894e08 MOV dword ptr [ESI + 0x8],ECX
    m.w32((s.si+0x00000008u), s.cx);
  }
  { // 0x5a999f: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x5a99a2: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x5a99a5: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  { // 0x5a99a9: e822610e00 CALL 0x0068fad0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5a99ae: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x5a99b2: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  { // 0x5a99b6: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5a99b8: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x5a99bb: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x5a99bf: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  { // 0x5a99c2: 895620 MOV dword ptr [ESI + 0x20],EDX
    m.w32((s.si+0x00000020u), s.dx);
  }
  { // 0x5a99c5: 8d563c LEA EDX,[ESI + 0x3c]
    s.dx = (s.si+0x0000003cu);
  }
  { // 0x5a99c8: 894e38 MOV dword ptr [ESI + 0x38],ECX
    m.w32((s.si+0x00000038u), s.cx);
  }
  { // 0x5a99cb: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5a99cf: 894624 MOV dword ptr [ESI + 0x24],EAX
    m.w32((s.si+0x00000024u), s.ax);
  }
  { // 0x5a99d2: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  { // 0x5a99d5: 885e34 MOV byte ptr [ESI + 0x34],BL
    m.w8((s.si+0x00000034u), (s.bx & 0xffu));
  }
  { // 0x5a99d8: 881a MOV byte ptr [EDX],BL
    m.w8((s.dx), (s.bx & 0xffu));
  }
  { // 0x5a99da: c706381d7900 MOV dword ptr [ESI],0x791d38
    m.w32((s.si), 0x00791d38u);
  }
  { // 0x5a99e0: e80bb7eeff CALL 0x004950f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5a99e5: 89461c MOV dword ptr [ESI + 0x1c],EAX
    m.w32((s.si+0x0000001cu), s.ax);
  }
  { // 0x5a99e8: 895e2c MOV dword ptr [ESI + 0x2c],EBX
    m.w32((s.si+0x0000002cu), s.bx);
  }
  { // 0x5a99eb: 0fbf5006 MOVSX EDX,word ptr [EAX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  { // 0x5a99ef: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  { // 0x5a99f3: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  { // 0x5a99f4: 894644 MOV dword ptr [ESI + 0x44],EAX
    m.w32((s.si+0x00000044u), s.ax);
  }
  { // 0x5a99f7: 895630 MOV dword ptr [ESI + 0x30],EDX
    m.w32((s.si+0x00000030u), s.dx);
  }
  { // 0x5a99fa: 895e40 MOV dword ptr [ESI + 0x40],EBX
    m.w32((s.si+0x00000040u), s.bx);
  }
  { // 0x5a99fd: c706601d7900 MOV dword ptr [ESI],0x791d60
    m.w32((s.si), 0x00791d60u);
  }
  { // 0x5a9a03: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5a9a05: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5a9a06: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5a9a07: c21c00 RET 0x1c
    finish(m,s,f,28u); return;
  }
}
void f_001aa580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5aa580: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aa581: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5aa583: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5aa584: 8b7e1c MOV EDI,dword ptr [ESI + 0x1c]
    s.di = m.r32((s.si+0x0000001cu));
  }
  { // 0x5aa587: c706b01d7900 MOV dword ptr [ESI],0x791db0
    m.w32((s.si), 0x00791db0u);
  }
  { // 0x5aa58d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5aa58f: 7410 JZ 0x005aa5a1
    if(integer::condition("JZ",flags)) goto L005aa5a1;
  }
  { // 0x5aa591: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5aa593: e84858e8ff CALL 0x0042fde0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5aa598: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5aa599: e8dd301c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5aa59e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005aa5a1: { // 0x5aa5a1: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5aa5a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5aa5a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5aa5a9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001ab060(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ab060: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ab061: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5ab062: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x5ab066: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ab068: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x5ab06a: 8b4704 MOV EAX,dword ptr [EDI + 0x4]
    s.ax = m.r32((s.di+0x00000004u));
  }
  { // 0x5ab06d: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  { // 0x5ab070: 8d4e14 LEA ECX,[ESI + 0x14]
    s.cx = (s.si+0x00000014u);
  }
  { // 0x5ab073: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x5ab076: c6460c01 MOV byte ptr [ESI + 0xc],0x1
    m.w8((s.si+0x0000000cu), 0x00000001u);
  }
  { // 0x5ab07a: e8514a0e00 CALL 0x0068fad0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5ab07f: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5ab083: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x5ab086: c7461800000000 MOV dword ptr [ESI + 0x18],0x0
    m.w32((s.si+0x00000018u), 0x00000000u);
  }
  { // 0x5ab08d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5ab08e: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
  { // 0x5ab091: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5ab097: e8b4021b00 CALL 0x0075b350
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5ab09c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  { // 0x5ab09e: 8d4620 LEA EAX,[ESI + 0x20]
    s.ax = (s.si+0x00000020u);
  }
  { // 0x5ab0a1: 894e20 MOV dword ptr [ESI + 0x20],ECX
    m.w32((s.si+0x00000020u), s.cx);
  }
  { // 0x5ab0a4: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  { // 0x5ab0a7: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  { // 0x5ab0aa: 8b4f08 MOV ECX,dword ptr [EDI + 0x8]
    s.cx = m.r32((s.di+0x00000008u));
  }
  { // 0x5ab0ad: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  { // 0x5ab0b0: 8b570c MOV EDX,dword ptr [EDI + 0xc]
    s.dx = m.r32((s.di+0x0000000cu));
  }
  { // 0x5ab0b3: c6463000 MOV byte ptr [ESI + 0x30],0x0
    m.w8((s.si+0x00000030u), 0x00000000u);
  }
  { // 0x5ab0b7: c706001e7900 MOV dword ptr [ESI],0x791e00
    m.w32((s.si), 0x00791e00u);
  }
  { // 0x5ab0bd: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  { // 0x5ab0c0: 8a442414 MOV AL,byte ptr [ESP + 0x14]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000014u)));
  }
  { // 0x5ab0c4: 884631 MOV byte ptr [ESI + 0x31],AL
    m.w8((s.si+0x00000031u), (s.ax & 0xffu));
  }
  { // 0x5ab0c7: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5ab0c9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5ab0ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ab0cb: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_001ac990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ac990: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ac991: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5ac993: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5ac994: 8b7e1c MOV EDI,dword ptr [ESI + 0x1c]
    s.di = m.r32((s.si+0x0000001cu));
  }
  { // 0x5ac997: c706b01d7900 MOV dword ptr [ESI],0x791db0
    m.w32((s.si), 0x00791db0u);
  }
  { // 0x5ac99d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5ac99f: 7410 JZ 0x005ac9b1
    if(integer::condition("JZ",flags)) goto L005ac9b1;
  }
  { // 0x5ac9a1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5ac9a3: e83834e8ff CALL 0x0042fde0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5ac9a8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5ac9a9: e8cd0c1c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5ac9ae: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005ac9b1: { // 0x5ac9b1: 8a44240c MOV AL,byte ptr [ESP + 0xc]
    s.ax = with_al(s.ax, m.r8((f.sp+0x0000000cu)));
  }
  { // 0x5ac9b5: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5ac9bb: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5ac9bd: 7409 JZ 0x005ac9c8
    if(integer::condition("JZ",flags)) goto L005ac9c8;
  }
  { // 0x5ac9bf: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ac9c0: e8b60c1c00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5ac9c5: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005ac9c8: { // 0x5ac9c8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5ac9ca: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5ac9cb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5ac9cc: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001aca30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5aca30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aca31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5aca33: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
  { // 0x5aca36: c706001e7900 MOV dword ptr [ESI],0x791e00
    m.w32((s.si), 0x00791e00u);
  }
  { // 0x5aca3c: e84fe91a00 CALL 0x0075b390
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5aca41: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x5aca45: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5aca4b: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5aca4d: 7409 JZ 0x005aca58
    if(integer::condition("JZ",flags)) goto L005aca58;
  }
  { // 0x5aca4f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aca50: e8260c1c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5aca55: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005aca58: { // 0x5aca58: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5aca5a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5aca5b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001aca60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5aca60: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aca61: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5aca63: 8d4e1c LEA ECX,[ESI + 0x1c]
    s.cx = (s.si+0x0000001cu);
  }
  { // 0x5aca66: c706281e7900 MOV dword ptr [ESI],0x791e28
    m.w32((s.si), 0x00791e28u);
  }
  { // 0x5aca6c: e81fe91a00 CALL 0x0075b390
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5aca71: 8a442408 MOV AL,byte ptr [ESP + 0x8]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000008u)));
  }
  { // 0x5aca75: c706101d7900 MOV dword ptr [ESI],0x791d10
    m.w32((s.si), 0x00791d10u);
  }
  { // 0x5aca7b: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5aca7d: 7409 JZ 0x005aca88
    if(integer::condition("JZ",flags)) goto L005aca88;
  }
  { // 0x5aca7f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5aca80: e8f60b1c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5aca85: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005aca88: { // 0x5aca88: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5aca8a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5aca8b: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b34c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b34c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b34c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b34c3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5b34c5: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x5b34c7: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x5b34ca: 884608 MOV byte ptr [ESI + 0x8],AL
    m.w8((s.si+0x00000008u), (s.ax & 0xffu));
  }
  { // 0x5b34cd: e85e3ae5ff CALL 0x00406f30
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5b34d2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b34d4: 740f JZ 0x005b34e5
    if(integer::condition("JZ",flags)) goto L005b34e5;
  }
  { // 0x5b34d6: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5b34da: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b34db: e8665c1c00 CALL 0x00779146
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5b34e0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5b34e3: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L005b34e5: { // 0x5b34e5: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5b34e7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b34e8: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001b64b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b64b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b64b1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5b64b3: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5b64b6: c706e4227900 MOV dword ptr [ESI],0x7922e4
    m.w32((s.si), 0x007922e4u);
  }
  { // 0x5b64bc: e8cf4e1a00 CALL 0x0075b390
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5b64c1: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x5b64c6: 7409 JZ 0x005b64d1
    if(integer::condition("JZ",flags)) goto L005b64d1;
  }
  { // 0x5b64c8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5b64c9: e8ad711b00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5b64ce: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005b64d1: { // 0x5b64d1: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5b64d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5b64d4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001b66d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b66d0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5b66d3: b9c885a200 MOV ECX,0xa285c8
    s.cx = 0x00a285c8u;
  }
  { // 0x5b66d8: e8d3d8f6ff CALL 0x00523fb0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5b66dd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b66df: 7506 JNZ 0x005b66e7
    if(integer::condition("JNZ",flags)) goto L005b66e7;
  }
  { // 0x5b66e1: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5b66e3: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5b66e6: c3 RET
    finish(m,s,f,0u); return;
  }
  L005b66e7: { // 0x5b66e7: 833dc855a20004 CMP dword ptr [0x00a255c8],0x4
    (void)integer::sub(m.r32((0x00a255c8u)),0x00000004u,32,flags);
  }
  { // 0x5b66ee: 742c JZ 0x005b671c
    if(integer::condition("JZ",flags)) goto L005b671c;
  }
  { // 0x5b66f0: a12c79a200 MOV EAX,[0x00a2792c]
    s.ax = m.r32((0x00a2792cu));
  }
  { // 0x5b66f5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b66f7: 7423 JZ 0x005b671c
    if(integer::condition("JZ",flags)) goto L005b671c;
  }
  { // 0x5b66f9: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x5b66fd: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x5b6701: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b6702: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5b6703: b93079a200 MOV ECX,0xa27930
    s.cx = 0x00a27930u;
  }
  { // 0x5b6708: e853c3f6ff CALL 0x00522a60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5b670d: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  { // 0x5b6711: b9c885a200 MOV ECX,0xa285c8
    s.cx = 0x00a285c8u;
  }
  { // 0x5b6716: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5b6717: e8b4f2f6ff CALL 0x005259d0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L005b671c: { // 0x5b671c: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5b671e: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5b6721: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001b7630(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5b7630: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5b7633: b9c885a200 MOV ECX,0xa285c8
    s.cx = 0x00a285c8u;
  }
  { // 0x5b7638: e873c9f6ff CALL 0x00523fb0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5b763d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b763f: 7506 JNZ 0x005b7647
    if(integer::condition("JNZ",flags)) goto L005b7647;
  }
  { // 0x5b7641: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5b7643: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5b7646: c3 RET
    finish(m,s,f,0u); return;
  }
  L005b7647: { // 0x5b7647: 833dc855a20004 CMP dword ptr [0x00a255c8],0x4
    (void)integer::sub(m.r32((0x00a255c8u)),0x00000004u,32,flags);
  }
  { // 0x5b764e: 742c JZ 0x005b767c
    if(integer::condition("JZ",flags)) goto L005b767c;
  }
  { // 0x5b7650: a12c79a200 MOV EAX,[0x00a2792c]
    s.ax = m.r32((0x00a2792cu));
  }
  { // 0x5b7655: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5b7657: 7423 JZ 0x005b767c
    if(integer::condition("JZ",flags)) goto L005b767c;
  }
  { // 0x5b7659: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x5b765d: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x5b7661: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5b7662: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5b7663: b93079a200 MOV ECX,0xa27930
    s.cx = 0x00a27930u;
  }
  { // 0x5b7668: e8f3b3f6ff CALL 0x00522a60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5b766d: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  { // 0x5b7671: b9c885a200 MOV ECX,0xa285c8
    s.cx = 0x00a285c8u;
  }
  { // 0x5b7676: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5b7677: e854e3f6ff CALL 0x005259d0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L005b767c: { // 0x5b767c: e81faf0000 CALL 0x005c25a0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5b7681: e83ab20000 CALL 0x005c28c0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x5b7686: e855b20000 CALL 0x005c28e0
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x5b768b: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5b768d: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5b7690: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c2560(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2560: b9d056a200 MOV ECX,0xa256d0
    s.cx = 0x00a256d0u;
  }
  { // 0x5c2565: e8b6c81200 CALL 0x006eee20
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5c256a: 683e79a200 PUSH 0xa2793e
    f.push(m,0x00a2793eu);
  }
  { // 0x5c256f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c2570: e89ecb1a00 CALL 0x0076f113
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5c2575: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5c2578: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x5c257a: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x5c257c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5c257d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c2580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c2580: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c2581: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c2583: b9d056a200 MOV ECX,0xa256d0
    s.cx = 0x00a256d0u;
  }
  { // 0x5c2588: e893c81200 CALL 0x006eee20
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5c258d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c258e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c258f: e87fcb1a00 CALL 0x0076f113
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5c2594: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x5c2597: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x5c2599: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x5c259b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c259c: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x5c259d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c3310(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c3310: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c3311: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c3312: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x5c3314: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x5c3316: e8d5e1f0ff CALL 0x004d14f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5c331b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c331d: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x5c331f: e8acdaf0ff CALL 0x004d0dd0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5c3324: 3b05c07da200 CMP EAX,dword ptr [0x00a27dc0]
    (void)integer::sub(s.ax,m.r32((0x00a27dc0u)),32,flags);
  }
  { // 0x5c332a: 751d JNZ 0x005c3349
    if(integer::condition("JNZ",flags)) goto L005c3349;
  }
  { // 0x5c332c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c332e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c332f: b9c855a200 MOV ECX,0xa255c8
    s.cx = 0x00a255c8u;
  }
  { // 0x5c3334: e867590a00 CALL 0x00668ca0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5c3339: a1ac7da200 MOV EAX,[0x00a27dac]
    s.ax = m.r32((0x00a27dacu));
  }
  { // 0x5c333e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5c333f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x5c3341: e87a1b0a00 CALL 0x00664ec0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5c3346: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c3347: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c3348: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c3349: { // 0x5c3349: 893c852c56a200 MOV dword ptr [EAX*0x4 + 0xa2562c],EDI
    m.w32(((s.ax * 0x00000004u)+0x00a2562cu), s.di);
  }
  { // 0x5c3350: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5c3351: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c3352: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c5ba0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c5ba0: a1c8117d00 MOV EAX,[0x007d11c8]
    s.ax = m.r32((0x007d11c8u));
  }
  { // 0x5c5ba5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c5ba6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c5ba8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c5ba9: e892371900 CALL 0x00759340
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5c5bae: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c5bb0: 755d JNZ 0x005c5c0f
    if(integer::condition("JNZ",flags)) goto L005c5c0f;
  }
  { // 0x5c5bb2: 8b0dcc117d00 MOV ECX,dword ptr [0x007d11cc]
    s.cx = m.r32((0x007d11ccu));
  }
  { // 0x5c5bb8: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5c5bb9: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c5bbb: e880371900 CALL 0x00759340
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5c5bc0: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c5bc2: 754b JNZ 0x005c5c0f
    if(integer::condition("JNZ",flags)) goto L005c5c0f;
  }
  { // 0x5c5bc4: 8b15d0117d00 MOV EDX,dword ptr [0x007d11d0]
    s.dx = m.r32((0x007d11d0u));
  }
  { // 0x5c5bca: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c5bcc: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5c5bcd: e86e371900 CALL 0x00759340
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5c5bd2: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c5bd4: 7539 JNZ 0x005c5c0f
    if(integer::condition("JNZ",flags)) goto L005c5c0f;
  }
  { // 0x5c5bd6: a1d4117d00 MOV EAX,[0x007d11d4]
    s.ax = m.r32((0x007d11d4u));
  }
  { // 0x5c5bdb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c5bdd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c5bde: e85d371900 CALL 0x00759340
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5c5be3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c5be5: 7528 JNZ 0x005c5c0f
    if(integer::condition("JNZ",flags)) goto L005c5c0f;
  }
  { // 0x5c5be7: 8b0dd8117d00 MOV ECX,dword ptr [0x007d11d8]
    s.cx = m.r32((0x007d11d8u));
  }
  { // 0x5c5bed: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5c5bee: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c5bf0: e84b371900 CALL 0x00759340
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x5c5bf5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c5bf7: 7516 JNZ 0x005c5c0f
    if(integer::condition("JNZ",flags)) goto L005c5c0f;
  }
  { // 0x5c5bf9: 8b15dc117d00 MOV EDX,dword ptr [0x007d11dc]
    s.dx = m.r32((0x007d11dcu));
  }
  { // 0x5c5bff: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c5c01: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5c5c02: e839371900 CALL 0x00759340
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x5c5c07: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5c5c09: 7504 JNZ 0x005c5c0f
    if(integer::condition("JNZ",flags)) goto L005c5c0f;
  }
  { // 0x5c5c0b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5c5c0d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c5c0e: c3 RET
    finish(m,s,f,0u); return;
  }
  L005c5c0f: { // 0x5c5c0f: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x5c5c14: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c5c15: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c61d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c61d0: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x5c61d4: 8b542408 MOV EDX,dword ptr [ESP + 0x8]
    s.dx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5c61d8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c61d9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x5c61db: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c61dd: 68b0040000 PUSH 0x4b0
    f.push(m,0x000004b0u);
  }
  { // 0x5c61e2: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x5c61e6: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x5c61e8: 6a3c PUSH 0x3c
    f.push(m,0x0000003cu);
  }
  { // 0x5c61ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c61eb: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x5c61ef: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5c61f0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5c61f1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c61f2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c61f4: e8c7aeebff CALL 0x004810c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5c61f9: 8b4e1c MOV ECX,dword ptr [ESI + 0x1c]
    s.cx = m.r32((s.si+0x0000001cu));
  }
  { // 0x5c61fc: c70688237900 MOV dword ptr [ESI],0x792388
    m.w32((s.si), 0x00792388u);
  }
  { // 0x5c6202: 83c10b ADD ECX,0xb
    s.cx = integer::add(s.cx,0x0000000bu,32,flags);
  }
  { // 0x5c6205: c7464cffffffff MOV dword ptr [ESI + 0x4c],0xffffffff
    m.w32((s.si+0x0000004cu), 0xffffffffu);
  }
  { // 0x5c620c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5c620d: e845771a00 CALL 0x0076d957
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5c6212: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5c6215: 894650 MOV dword ptr [ESI + 0x50],EAX
    m.w32((s.si+0x00000050u), s.ax);
  }
  { // 0x5c6218: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5c621a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c621b: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_001c6220(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c6220: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c6221: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c6223: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x5c6226: c70688237900 MOV dword ptr [ESI],0x792388
    m.w32((s.si), 0x00792388u);
  }
  { // 0x5c622c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c622d: e849741a00 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5c6232: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5c6235: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c6237: e804afebff CALL 0x00481140
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5c623c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c623d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001c6360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5c6360: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c6361: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5c6363: 8b4650 MOV EAX,dword ptr [ESI + 0x50]
    s.ax = m.r32((s.si+0x00000050u));
  }
  { // 0x5c6366: c70688237900 MOV dword ptr [ESI],0x792388
    m.w32((s.si), 0x00792388u);
  }
  { // 0x5c636c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5c636d: e809731a00 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5c6372: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5c6375: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5c6377: e8c4adebff CALL 0x00481140
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5c637c: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x5c6381: 7409 JZ 0x005c638c
    if(integer::condition("JZ",flags)) goto L005c638c;
  }
  { // 0x5c6383: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5c6384: e8f2721a00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5c6389: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005c638c: { // 0x5c638c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5c638e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5c638f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001ccdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ccdf0: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x5ccdf4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccdf5: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x5ccdf9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5ccdfa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccdfb: e82033e4ff CALL 0x00410120
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5cce00: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5cce02: 7c54 JL 0x005cce58
    if(integer::condition("JL",flags)) goto L005cce58;
  }
  { // 0x5cce04: 8d4e30 LEA ECX,[ESI + 0x30]
    s.cx = (s.si+0x00000030u);
  }
  { // 0x5cce07: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5cce08: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x5cce0d: e85e830c00 CALL 0x00695170
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5cce12: 8d5634 LEA EDX,[ESI + 0x34]
    s.dx = (s.si+0x00000034u);
  }
  { // 0x5cce15: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5cce16: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x5cce1b: e850830c00 CALL 0x00695170
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5cce20: 8d4638 LEA EAX,[ESI + 0x38]
    s.ax = (s.si+0x00000038u);
  }
  { // 0x5cce23: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5cce24: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x5cce29: e842830c00 CALL 0x00695170
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5cce2e: 8d4e18 LEA ECX,[ESI + 0x18]
    s.cx = (s.si+0x00000018u);
  }
  { // 0x5cce31: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5cce32: 687053aa00 PUSH 0xaa5370
    f.push(m,0x00aa5370u);
  }
  { // 0x5cce37: e834830c00 CALL 0x00695170
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x5cce3c: 8d4e3c LEA ECX,[ESI + 0x3c]
    s.cx = (s.si+0x0000003cu);
  }
  { // 0x5cce3f: e8ac8de3ff CALL 0x00405bf0
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x5cce44: 8d4e50 LEA ECX,[ESI + 0x50]
    s.cx = (s.si+0x00000050u);
  }
  { // 0x5cce47: e8a48de3ff CALL 0x00405bf0
    invoke(m,s,f,op,6u); flags=0x202u;
  }
  { // 0x5cce4c: c7869400000000000000 MOV dword ptr [ESI + 0x94],0x0
    m.w32((s.si+0x00000094u), 0x00000000u);
  }
  { // 0x5cce56: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005cce58: { // 0x5cce58: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cce59: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001ccff0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5ccff0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccff1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x5ccff5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5ccff6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5ccffb: e870a0f8ff CALL 0x00557070
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5cd000: 8b1598aaa500 MOV EDX,dword ptr [0x00a5aa98]
    s.dx = m.r32((0x00a5aa98u));
  }
  { // 0x5cd006: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x5cd009: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x5cd00b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5cd00d: 7f35 JG 0x005cd044
    if(integer::condition("JG",flags)) goto L005cd044;
  }
  { // 0x5cd00f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd010: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cd015: e87684f7ff CALL 0x00545490
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5cd01a: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  { // 0x5cd020: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5cd023: 741f JZ 0x005cd044
    if(integer::condition("JZ",flags)) goto L005cd044;
  }
  { // 0x5cd025: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd026: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cd02b: e86084f7ff CALL 0x00545490
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5cd030: 8b8828010000 MOV ECX,dword ptr [EAX + 0x128]
    s.cx = m.r32((s.ax+0x00000128u));
  }
  { // 0x5cd036: 0528010000 ADD EAX,0x128
    s.ax = integer::add(s.ax,0x00000128u,32,flags);
  }
  { // 0x5cd03b: 83c940 OR ECX,0x40
    s.cx = integer::logical((s.cx)|(0x00000040u),32,flags);
  }
  { // 0x5cd03e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd03f: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x5cd041: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005cd044: { // 0x5cd044: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd045: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cd04a: e84184f7ff CALL 0x00545490
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5cd04f: 8b8824010000 MOV ECX,dword ptr [EAX + 0x124]
    s.cx = m.r32((s.ax+0x00000124u));
  }
  { // 0x5cd055: 0524010000 ADD EAX,0x124
    s.ax = integer::add(s.ax,0x00000124u,32,flags);
  }
  { // 0x5cd05a: 83c940 OR ECX,0x40
    s.cx = integer::logical((s.cx)|(0x00000040u),32,flags);
  }
  { // 0x5cd05d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd05e: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x5cd060: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cd070(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cd070: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd071: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x5cd075: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd076: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cd07b: e8f09ff8ff CALL 0x00557070
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5cd080: 8b1598aaa500 MOV EDX,dword ptr [0x00a5aa98]
    s.dx = m.r32((0x00a5aa98u));
  }
  { // 0x5cd086: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x5cd089: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x5cd08b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5cd08d: 7f35 JG 0x005cd0c4
    if(integer::condition("JG",flags)) goto L005cd0c4;
  }
  { // 0x5cd08f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd090: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cd095: e8f683f7ff CALL 0x00545490
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5cd09a: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  { // 0x5cd0a0: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x5cd0a3: 741f JZ 0x005cd0c4
    if(integer::condition("JZ",flags)) goto L005cd0c4;
  }
  { // 0x5cd0a5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd0a6: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cd0ab: e8e083f7ff CALL 0x00545490
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5cd0b0: 8b8828010000 MOV ECX,dword ptr [EAX + 0x128]
    s.cx = m.r32((s.ax+0x00000128u));
  }
  { // 0x5cd0b6: 0528010000 ADD EAX,0x128
    s.ax = integer::add(s.ax,0x00000128u,32,flags);
  }
  { // 0x5cd0bb: 83e1bf AND ECX,0xffffffbf
    s.cx = integer::logical((s.cx)&(0xffffffbfu),32,flags);
  }
  { // 0x5cd0be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd0bf: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x5cd0c1: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005cd0c4: { // 0x5cd0c4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd0c5: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x5cd0ca: e8c183f7ff CALL 0x00545490
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5cd0cf: 8b8824010000 MOV ECX,dword ptr [EAX + 0x124]
    s.cx = m.r32((s.ax+0x00000124u));
  }
  { // 0x5cd0d5: 0524010000 ADD EAX,0x124
    s.ax = integer::add(s.ax,0x00000124u,32,flags);
  }
  { // 0x5cd0da: 83e1bf AND ECX,0xffffffbf
    s.cx = integer::logical((s.cx)&(0xffffffbfu),32,flags);
  }
  { // 0x5cd0dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd0de: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x5cd0e0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001cd0f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5cd0f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5cd0f1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5cd0f3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cd0f4: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x5cd0f6: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5cd0f8: 7410 JZ 0x005cd10a
    if(integer::condition("JZ",flags)) goto L005cd10a;
  }
  { // 0x5cd0fa: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5cd0fc: e87f0b1400 CALL 0x0070dc80
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5cd101: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cd102: e874051a00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5cd107: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cd10a: { // 0x5cd10a: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  { // 0x5cd10d: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x5cd113: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x5cd115: 7410 JZ 0x005cd127
    if(integer::condition("JZ",flags)) goto L005cd127;
  }
  { // 0x5cd117: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x5cd119: e872e8fcff CALL 0x0059b990
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5cd11e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5cd11f: e857051a00 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5cd124: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L005cd127: { // 0x5cd127: c7460400000000 MOV dword ptr [ESI + 0x4],0x0
    m.w32((s.si+0x00000004u), 0x00000000u);
  }
  { // 0x5cd12e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5cd12f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5cd130: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001d4ef0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d4ef0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d4ef1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5d4ef3: 689c000000 PUSH 0x9c
    f.push(m,0x0000009cu);
  }
  { // 0x5d4ef8: e85a8a1900 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5d4efd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5d4f00: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d4f02: 7419 JZ 0x005d4f1d
    if(integer::condition("JZ",flags)) goto L005d4f1d;
  }
  { // 0x5d4f04: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x5d4f08: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x5d4f0a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5d4f0b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d4f0c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5d4f0e: e83ddfffff CALL 0x005d2e50
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5d4f13: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d4f15: 7406 JZ 0x005d4f1d
    if(integer::condition("JZ",flags)) goto L005d4f1d;
  }
  { // 0x5d4f17: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5d4f19: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d4f1a: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L005d4f1d: { // 0x5d4f1d: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5d4f1f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d4f20: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_001d4f30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d4f30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d4f31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5d4f33: 689c000000 PUSH 0x9c
    f.push(m,0x0000009cu);
  }
  { // 0x5d4f38: e81a8a1900 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5d4f3d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5d4f40: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5d4f42: 7413 JZ 0x005d4f57
    if(integer::condition("JZ",flags)) goto L005d4f57;
  }
  { // 0x5d4f44: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x5d4f46: 68b8aca500 PUSH 0xa5acb8
    f.push(m,0x00a5acb8u);
  }
  { // 0x5d4f4b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d4f4c: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5d4f4e: e8fddeffff CALL 0x005d2e50
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5d4f53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d4f54: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L005d4f57: { // 0x5d4f57: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5d4f59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d4f5a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001d6f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5d6f90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5d6f91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5d6f93: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5d6f96: e855431800 CALL 0x0075b2f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5d6f9b: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x5d6f9e: e84d431800 CALL 0x0075b2f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5d6fa3: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x5d6fa6: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x5d6fac: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x5d6faf: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  { // 0x5d6fb2: c7461000000000 MOV dword ptr [ESI + 0x10],0x0
    m.w32((s.si+0x00000010u), 0x00000000u);
  }
  { // 0x5d6fb9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5d6fbb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5d6fbc: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f7d70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f7d70: e87bacfbff CALL 0x005b29f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5f7d75: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x5f7d7a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f7d7c: 742c JZ 0x005f7daa
    if(integer::condition("JZ",flags)) goto L005f7daa;
  }
  { // 0x5f7d7e: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  { // 0x5f7d81: 7427 JZ 0x005f7daa
    if(integer::condition("JZ",flags)) goto L005f7daa;
  }
  { // 0x5f7d83: a03c79a200 MOV AL,[0x00a2793c]
    s.ax = with_al(s.ax, m.r8((0x00a2793cu)));
  }
  { // 0x5f7d88: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5f7d8a: 751e JNZ 0x005f7daa
    if(integer::condition("JNZ",flags)) goto L005f7daa;
  }
  { // 0x5f7d8c: a1e87da200 MOV EAX,[0x00a27de8]
    s.ax = m.r32((0x00a27de8u));
  }
  { // 0x5f7d91: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f7d93: 7515 JNZ 0x005f7daa
    if(integer::condition("JNZ",flags)) goto L005f7daa;
  }
  { // 0x5f7d95: e88658f4ff CALL 0x0053d620
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5f7d9a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5f7d9c: 7511 JNZ 0x005f7daf
    if(integer::condition("JNZ",flags)) goto L005f7daf;
  }
  { // 0x5f7d9e: e86d5ef4ff CALL 0x0053dc10
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5f7da3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x5f7da5: 7408 JZ 0x005f7daf
    if(integer::condition("JZ",flags)) goto L005f7daf;
  }
  { // 0x5f7da7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x5f7da9: c3 RET
    finish(m,s,f,0u); return;
  }
  L005f7daa: { // 0x5f7daa: e831a4e8ff CALL 0x004821e0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  L005f7daf: { // 0x5f7daf: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x5f7db1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f81b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f81b0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f81b1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f81b2: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x5f81b4: 8b4728 MOV EAX,dword ptr [EDI + 0x28]
    s.ax = m.r32((s.di+0x00000028u));
  }
  { // 0x5f81b7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5f81b9: 7410 JZ 0x005f81cb
    if(integer::condition("JZ",flags)) goto L005f81cb;
  }
  { // 0x5f81bb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f81bc: e8ba541700 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5f81c1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5f81c4: c7472800000000 MOV dword ptr [EDI + 0x28],0x0
    m.w32((s.di+0x00000028u), 0x00000000u);
  }
  L005f81cb: { // 0x5f81cb: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5f81cf: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5f81d1: 7423 JZ 0x005f81f6
    if(integer::condition("JZ",flags)) goto L005f81f6;
  }
  { // 0x5f81d3: 66833e00 CMP word ptr [ESI],0x0
    (void)integer::sub(m.r16((s.si)),0x00000000u,16,flags);
  }
  { // 0x5f81d7: 741d JZ 0x005f81f6
    if(integer::condition("JZ",flags)) goto L005f81f6;
  }
  { // 0x5f81d9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f81da: e8666d1700 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5f81df: 8d440002 LEA EAX,[EAX + EAX*0x1 + 0x2]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000002u);
  }
  { // 0x5f81e3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f81e4: e86e571700 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x5f81e9: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f81ea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x5f81eb: 894728 MOV dword ptr [EDI + 0x28],EAX
    m.w32((s.di+0x00000028u), s.ax);
  }
  { // 0x5f81ee: e8d66d1700 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x5f81f3: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L005f81f6: { // 0x5f81f6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f81f7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f81f8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001f90c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f90c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f90c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5f90c3: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x5f90c6: e8c5221600 CALL 0x0075b390
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5f90cb: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5f90ce: e8bd221600 CALL 0x0075b390
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5f90d3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f90d4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_001f9430(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5f9430: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5f9431: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5f9432: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x5f9436: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x5f9438: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x5f943a: 8d4f04 LEA ECX,[EDI + 0x4]
    s.cx = (s.di+0x00000004u);
  }
  { // 0x5f943d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x5f943e: 8d4e04 LEA ECX,[ESI + 0x4]
    s.cx = (s.si+0x00000004u);
  }
  { // 0x5f9441: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x5f9443: e8081f1600 CALL 0x0075b350
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5f9448: 8d5708 LEA EDX,[EDI + 0x8]
    s.dx = (s.di+0x00000008u);
  }
  { // 0x5f944b: 8d4e08 LEA ECX,[ESI + 0x8]
    s.cx = (s.si+0x00000008u);
  }
  { // 0x5f944e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x5f944f: e8fc1e1600 CALL 0x0075b350
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5f9454: 8b470c MOV EAX,dword ptr [EDI + 0xc]
    s.ax = m.r32((s.di+0x0000000cu));
  }
  { // 0x5f9457: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x5f945a: 8b4f10 MOV ECX,dword ptr [EDI + 0x10]
    s.cx = m.r32((s.di+0x00000010u));
  }
  { // 0x5f945d: 894e10 MOV dword ptr [ESI + 0x10],ECX
    m.w32((s.si+0x00000010u), s.cx);
  }
  { // 0x5f9460: 8b5714 MOV EDX,dword ptr [EDI + 0x14]
    s.dx = m.r32((s.di+0x00000014u));
  }
  { // 0x5f9463: 895614 MOV dword ptr [ESI + 0x14],EDX
    m.w32((s.si+0x00000014u), s.dx);
  }
  { // 0x5f9466: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x5f9468: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5f9469: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5f946a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_001fbb80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fbb80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fbb81: 8b3568dfa500 MOV ESI,dword ptr [0x00a5df68]
    s.si = m.r32((0x00a5df68u));
  }
  { // 0x5fbb87: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x5fbb89: 741a JZ 0x005fbba5
    if(integer::condition("JZ",flags)) goto L005fbba5;
  }
  { // 0x5fbb8b: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x5fbb8d: e89e020000 CALL 0x005fbe30
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x5fbb92: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fbb93: e8e31a1700 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x5fbb98: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x5fbb9b: c70568dfa50000000000 MOV dword ptr [0x00a5df68],0x0
    m.w32((0x00a5df68u), 0x00000000u);
  }
  L005fbba5: { // 0x5fbba5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fbba6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00206920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x606920: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x606921: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x606922: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x606924: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x606926: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x606928: e863dff9ff CALL 0x005a4890
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x60692d: 8dbe00010000 LEA EDI,[ESI + 0x100]
    s.di = (s.si+0x00000100u);
  }
  { // 0x606933: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x606935: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x606937: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x606939: e852dff9ff CALL 0x005a4890
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x60693e: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x606942: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x606944: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x606946: e875d9f9ff CALL 0x005a42c0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x60694b: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x60694f: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x606951: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x606953: e868d9f9ff CALL 0x005a42c0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x606958: ba40000000 MOV EDX,0x40
    s.dx = 0x00000040u;
  }
  { // 0x60695d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x60695f: e84cdff9ff CALL 0x005a48b0
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x606964: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x606965: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x606966: 898600020000 MOV dword ptr [ESI + 0x200],EAX
    m.w32((s.si+0x00000200u), s.ax);
  }
  { // 0x60696c: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x60696e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60696f: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002069c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6069c0: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x6069c4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6069c5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6069c7: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x6069c9: e8f2d8f9ff CALL 0x005a42c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6069ce: ba40000000 MOV EDX,0x40
    s.dx = 0x00000040u;
  }
  { // 0x6069d3: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6069d5: e8d6def9ff CALL 0x005a48b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6069da: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x6069db: 898600020000 MOV dword ptr [ESI + 0x200],EAX
    m.w32((s.si+0x00000200u), s.ax);
  }
  { // 0x6069e1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6069e2: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00207600(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x607600: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x607601: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x607602: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x607604: e827cbf9ff CALL 0x005a4130
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x607609: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x60760b: e810cbf9ff CALL 0x005a4120
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x607610: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x607612: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  { // 0x607615: 7e50 JLE 0x00607667
    if(integer::condition("JLE",flags)) goto L00607667;
  }
  { // 0x607617: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x607618: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x607619: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x60761d: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  { // 0x607622: 8bdf MOV EBX,EDI
    s.bx = s.di;
  }
  L00607624: { // 0x607624: 66012c31 ADD word ptr [ECX + ESI*0x1],BP
    m.w16((s.cx+(s.si * 0x00000001u)), integer::add(m.r16((s.cx+(s.si * 0x00000001u))),(s.bp & 0xffffu),16,flags));
  }
  { // 0x607628: 668b3c31 MOV DI,word ptr [ECX + ESI*0x1]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.cx+(s.si * 0x00000001u)))) & 0xffffu);
  }
  { // 0x60762c: 668b5408fe MOV DX,word ptr [EAX + ECX*0x1 + -0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+(s.cx * 0x00000001u)-0x00000002u)));
  }
  { // 0x607631: 663bfa CMP DI,DX
    (void)integer::sub((s.di & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  { // 0x607634: 7212 JC 0x00607648
    if(integer::condition("JC",flags)) goto L00607648;
  }
  L00607636: { // 0x607636: 66291431 SUB word ptr [ECX + ESI*0x1],DX
    m.w16((s.cx+(s.si * 0x00000001u)), integer::sub(m.r16((s.cx+(s.si * 0x00000001u))),(s.dx & 0xffffu),16,flags));
  }
  { // 0x60763a: 668b3c31 MOV DI,word ptr [ECX + ESI*0x1]
    s.di = (s.di & 0xffff0000u) | ((m.r16((s.cx+(s.si * 0x00000001u)))) & 0xffffu);
  }
  { // 0x60763e: 668b5408fe MOV DX,word ptr [EAX + ECX*0x1 + -0x2]
    s.dx = with_ax(s.dx, m.r16((s.ax+(s.cx * 0x00000001u)-0x00000002u)));
  }
  { // 0x607643: 663bfa CMP DI,DX
    (void)integer::sub((s.di & 0xffffu),(s.dx & 0xffffu),16,flags);
  }
  { // 0x607646: 73ee JNC 0x00607636
    if(integer::condition("JNC",flags)) goto L00607636;
  }
  L00607648: { // 0x607648: 803e00 CMP byte ptr [ESI],0x0
    (void)integer::sub(m.r8((s.si)),0x00000000u,8,flags);
  }
  { // 0x60764b: 750b JNZ 0x00607658
    if(integer::condition("JNZ",flags)) goto L00607658;
  }
  { // 0x60764d: 66833c3100 CMP word ptr [ECX + ESI*0x1],0x0
    (void)integer::sub(m.r16((s.cx+(s.si * 0x00000001u))),0x00000000u,16,flags);
  }
  { // 0x607652: 7404 JZ 0x00607658
    if(integer::condition("JZ",flags)) goto L00607658;
  }
  { // 0x607654: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x607656: eb05 JMP 0x0060765d
    goto L0060765d;
  }
  L00607658: { // 0x607658: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0060765d: { // 0x60765d: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  { // 0x607660: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x607661: 8816 MOV byte ptr [ESI],DL
    m.w8((s.si), (s.dx & 0xffu));
  }
  { // 0x607663: 75bf JNZ 0x00607624
    if(integer::condition("JNZ",flags)) goto L00607624;
  }
  { // 0x607665: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x607666: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00607667: { // 0x607667: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x607668: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x607669: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00207950(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x607950: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x607951: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x607953: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x607954: 8b7e0c MOV EDI,dword ptr [ESI + 0xc]
    s.di = m.r32((s.si+0x0000000cu));
  }
  { // 0x607957: c70660317900 MOV dword ptr [ESI],0x793160
    m.w32((s.si), 0x00793160u);
  }
  { // 0x60795d: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x60795f: 7410 JZ 0x00607971
    if(integer::condition("JZ",flags)) goto L00607971;
  }
  { // 0x607961: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x607963: e848dbe2ff CALL 0x004354b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x607968: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x607969: e80d5d1600 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x60796e: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00607971: { // 0x607971: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x607973: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  { // 0x60797a: e8c1ecffff CALL 0x00606640
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x60797f: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x607984: 7409 JZ 0x0060798f
    if(integer::condition("JZ",flags)) goto L0060798f;
  }
  { // 0x607986: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x607987: e8ef5c1600 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x60798c: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0060798f: { // 0x60798f: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x607991: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x607992: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x607993: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002079b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6079b0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6079b1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6079b2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6079b3: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6079b5: 8b5f20 MOV EBX,dword ptr [EDI + 0x20]
    s.bx = m.r32((s.di+0x00000020u));
  }
  { // 0x6079b8: 8d7714 LEA ESI,[EDI + 0x14]
    s.si = (s.di+0x00000014u);
  }
  { // 0x6079bb: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6079bd: c70660317900 MOV dword ptr [ESI],0x793160
    m.w32((s.si), 0x00793160u);
  }
  { // 0x6079c3: 7410 JZ 0x006079d5
    if(integer::condition("JZ",flags)) goto L006079d5;
  }
  { // 0x6079c5: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6079c7: e8e4dae2ff CALL 0x004354b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6079cc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6079cd: e8a95c1600 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6079d2: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006079d5: { // 0x6079d5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6079d7: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  { // 0x6079de: e85decffff CALL 0x00606640
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6079e3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6079e5: e856ecffff CALL 0x00606640
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x6079ea: f644241001 TEST byte ptr [ESP + 0x10],0x1
    (void)integer::logical((m.r8((f.sp+0x00000010u)))&(0x00000001u),8,flags);
  }
  { // 0x6079ef: 7409 JZ 0x006079fa
    if(integer::condition("JZ",flags)) goto L006079fa;
  }
  { // 0x6079f1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6079f2: e8845c1600 CALL 0x0076d67b
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x6079f7: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006079fa: { // 0x6079fa: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6079fc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6079fd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6079fe: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6079ff: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00207d30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x607d30: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x607d31: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x607d32: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x607d33: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x607d35: 8b5f20 MOV EBX,dword ptr [EDI + 0x20]
    s.bx = m.r32((s.di+0x00000020u));
  }
  { // 0x607d38: 8d7714 LEA ESI,[EDI + 0x14]
    s.si = (s.di+0x00000014u);
  }
  { // 0x607d3b: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x607d3d: c70648147900 MOV dword ptr [ESI],0x791448
    m.w32((s.si), 0x00791448u);
  }
  { // 0x607d43: 7410 JZ 0x00607d55
    if(integer::condition("JZ",flags)) goto L00607d55;
  }
  { // 0x607d45: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x607d47: e864d7e2ff CALL 0x004354b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x607d4c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x607d4d: e829591600 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x607d52: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00607d55: { // 0x607d55: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x607d57: c7460c00000000 MOV dword ptr [ESI + 0xc],0x0
    m.w32((s.si+0x0000000cu), 0x00000000u);
  }
  { // 0x607d5e: e84d890800 CALL 0x006906b0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x607d63: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x607d65: e846890800 CALL 0x006906b0
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x607d6a: f644241001 TEST byte ptr [ESP + 0x10],0x1
    (void)integer::logical((m.r8((f.sp+0x00000010u)))&(0x00000001u),8,flags);
  }
  { // 0x607d6f: 7409 JZ 0x00607d7a
    if(integer::condition("JZ",flags)) goto L00607d7a;
  }
  { // 0x607d71: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x607d72: e804591600 CALL 0x0076d67b
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x607d77: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00607d7a: { // 0x607d7a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x607d7c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x607d7d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x607d7e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x607d7f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00208da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x608da0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  { // 0x608da3: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x608da6: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x608da8: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  { // 0x608dab: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x608daf: e8acf7ffff CALL 0x00608560
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x608db4: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x608db6: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  { // 0x608dba: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x608dbd: 894c2410 MOV dword ptr [ESP + 0x10],ECX
    m.w32((f.sp+0x00000010u), s.cx);
  }
  { // 0x608dc1: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x608dc5: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  { // 0x608dc8: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x608dcc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x608dcd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x608dce: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  { // 0x608dd4: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  { // 0x608dd8: e833f20800 CALL 0x00698010
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x608ddd: 8b4c2400 MOV ECX,dword ptr [ESP]
    s.cx = m.r32((f.sp));
  }
  { // 0x608de1: 8b1570198200 MOV EDX,dword ptr [0x00821970]
    s.dx = m.r32((0x00821970u));
  }
  { // 0x608de7: a174198200 MOV EAX,[0x00821974]
    s.ax = m.r32((0x00821974u));
  }
  { // 0x608dec: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x608dee: 8b542404 MOV EDX,dword ptr [ESP + 0x4]
    s.dx = m.r32((f.sp+0x00000004u));
  }
  { // 0x608df2: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x608df4: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  { // 0x608df8: 8908 MOV dword ptr [EAX],ECX
    m.w32((s.ax), s.cx);
  }
  { // 0x608dfa: 895004 MOV dword ptr [EAX + 0x4],EDX
    m.w32((s.ax+0x00000004u), s.dx);
  }
  { // 0x608dfd: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  { // 0x608e00: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0020ea50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60ea50: a020e2a500 MOV AL,[0x00a5e220]
    s.ax = with_al(s.ax, m.r8((0x00a5e220u)));
  }
  { // 0x60ea55: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60ea57: 7545 JNZ 0x0060ea9e
    if(integer::condition("JNZ",flags)) goto L0060ea9e;
  }
  { // 0x60ea59: 689f0c0000 PUSH 0xc9f
    f.push(m,0x00000c9fu);
  }
  { // 0x60ea5e: 68645d7d00 PUSH 0x7d5d64
    f.push(m,0x007d5d64u);
  }
  { // 0x60ea63: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x60ea65: b9085e7d00 MOV ECX,0x7d5e08
    s.cx = 0x007d5e08u;
  }
  { // 0x60ea6a: c60520e2a50001 MOV byte ptr [0x00a5e220],0x1
    m.w8((0x00a5e220u), 0x00000001u);
  }
  { // 0x60ea71: e8ea000e00 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x60ea76: bae0010000 MOV EDX,0x1e0
    s.dx = 0x000001e0u;
  }
  { // 0x60ea7b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x60ea7d: e84ebe0d00 CALL 0x006ea8d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x60ea82: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x60ea87: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x60ea8c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x60ea8e: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  { // 0x60ea93: 8b8820060000 MOV ECX,dword ptr [EAX + 0x620]
    s.cx = m.r32((s.ax+0x00000620u));
  }
  { // 0x60ea99: e8d29e0f00 CALL 0x00708970
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L0060ea9e: { // 0x60ea9e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0020eb30(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60eb30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60eb31: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x60eb33: 833cb50ce2a50001 CMP dword ptr [ESI*0x4 + 0xa5e20c],0x1
    (void)integer::sub(m.r32(((s.si * 0x00000004u)+0x00a5e20cu)),0x00000001u,32,flags);
  }
  { // 0x60eb3b: 7d46 JGE 0x0060eb83
    if(integer::condition("JGE",flags)) goto L0060eb83;
  }
  { // 0x60eb3d: 83fe03 CMP ESI,0x3
    (void)integer::sub(s.si,0x00000003u,32,flags);
  }
  { // 0x60eb40: 7513 JNZ 0x0060eb55
    if(integer::condition("JNZ",flags)) goto L0060eb55;
  }
  { // 0x60eb42: 689f0c0000 PUSH 0xc9f
    f.push(m,0x00000c9fu);
  }
  { // 0x60eb47: 68645d7d00 PUSH 0x7d5d64
    f.push(m,0x007d5d64u);
  }
  { // 0x60eb4c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x60eb4e: b9945e7d00 MOV ECX,0x7d5e94
    s.cx = 0x007d5e94u;
  }
  { // 0x60eb53: eb16 JMP 0x0060eb6b
    goto L0060eb6b;
  }
  L0060eb55: { // 0x60eb55: 83fe04 CMP ESI,0x4
    (void)integer::sub(s.si,0x00000004u,32,flags);
  }
  { // 0x60eb58: 7522 JNZ 0x0060eb7c
    if(integer::condition("JNZ",flags)) goto L0060eb7c;
  }
  { // 0x60eb5a: 689f0c0000 PUSH 0xc9f
    f.push(m,0x00000c9fu);
  }
  { // 0x60eb5f: 68645d7d00 PUSH 0x7d5d64
    f.push(m,0x007d5d64u);
  }
  { // 0x60eb64: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x60eb66: b9785e7d00 MOV ECX,0x7d5e78
    s.cx = 0x007d5e78u;
  }
  L0060eb6b: { // 0x60eb6b: e8f0ff0d00 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x60eb70: bae0010000 MOV EDX,0x1e0
    s.dx = 0x000001e0u;
  }
  { // 0x60eb75: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x60eb77: e854bd0d00 CALL 0x006ea8d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L0060eb7c: { // 0x60eb7c: ff04b50ce2a500 INC dword ptr [ESI*0x4 + 0xa5e20c]
    m.w32(((s.si * 0x00000004u)+0x00a5e20cu), integer::increment(m.r32(((s.si * 0x00000004u)+0x00a5e20cu)),32,flags));
  }
  L0060eb83: { // 0x60eb83: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60eb84: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0020ebb0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60ebb0: a020e2a500 MOV AL,[0x00a5e220]
    s.ax = with_al(s.ax, m.r8((0x00a5e220u)));
  }
  { // 0x60ebb5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x60ebb7: 7540 JNZ 0x0060ebf9
    if(integer::condition("JNZ",flags)) goto L0060ebf9;
  }
  { // 0x60ebb9: 689f0c0000 PUSH 0xc9f
    f.push(m,0x00000c9fu);
  }
  { // 0x60ebbe: 68645d7d00 PUSH 0x7d5d64
    f.push(m,0x007d5d64u);
  }
  { // 0x60ebc3: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x60ebc5: c60520e2a50001 MOV byte ptr [0x00a5e220],0x1
    m.w8((0x00a5e220u), 0x00000001u);
  }
  { // 0x60ebcc: e88fff0d00 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x60ebd1: bae0010000 MOV EDX,0x1e0
    s.dx = 0x000001e0u;
  }
  { // 0x60ebd6: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x60ebd8: e8f3bc0d00 CALL 0x006ea8d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x60ebdd: a1881b8200 MOV EAX,[0x00821b88]
    s.ax = m.r32((0x00821b88u));
  }
  { // 0x60ebe2: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  { // 0x60ebe7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x60ebe9: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  { // 0x60ebee: 8b8820060000 MOV ECX,dword ptr [EAX + 0x620]
    s.cx = m.r32((s.ax+0x00000620u));
  }
  { // 0x60ebf4: e8779d0f00 CALL 0x00708970
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L0060ebf9: { // 0x60ebf9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00214030(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x614030: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x614031: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x614032: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x614034: e837240100 CALL 0x00626470
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x614039: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x61403b: 8d8e10150000 LEA ECX,[ESI + 0x1510]
    s.cx = (s.si+0x00001510u);
  }
  { // 0x614041: 889e08150000 MOV byte ptr [ESI + 0x1508],BL
    m.w8((s.si+0x00001508u), (s.bx & 0xffu));
  }
  { // 0x614047: e884ba0700 CALL 0x0068fad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x61404c: 89860c150000 MOV dword ptr [ESI + 0x150c],EAX
    m.w32((s.si+0x0000150cu), s.ax);
  }
  { // 0x614052: 899e14150000 MOV dword ptr [ESI + 0x1514],EBX
    m.w32((s.si+0x00001514u), s.bx);
  }
  { // 0x614058: 8d8e20150000 LEA ECX,[ESI + 0x1520]
    s.cx = (s.si+0x00001520u);
  }
  { // 0x61405e: 899e18150000 MOV dword ptr [ESI + 0x1518],EBX
    m.w32((s.si+0x00001518u), s.bx);
  }
  { // 0x614064: e867ba0700 CALL 0x0068fad0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x614069: 89861c150000 MOV dword ptr [ESI + 0x151c],EAX
    m.w32((s.si+0x0000151cu), s.ax);
  }
  { // 0x61406f: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x614072: 899e24150000 MOV dword ptr [ESI + 0x1524],EBX
    m.w32((s.si+0x00001524u), s.bx);
  }
  { // 0x614078: 898638150000 MOV dword ptr [ESI + 0x1538],EAX
    m.w32((s.si+0x00001538u), s.ax);
  }
  { // 0x61407e: 89863c150000 MOV dword ptr [ESI + 0x153c],EAX
    m.w32((s.si+0x0000153cu), s.ax);
  }
  { // 0x614084: 899e28150000 MOV dword ptr [ESI + 0x1528],EBX
    m.w32((s.si+0x00001528u), s.bx);
  }
  { // 0x61408a: 899e2c150000 MOV dword ptr [ESI + 0x152c],EBX
    m.w32((s.si+0x0000152cu), s.bx);
  }
  { // 0x614090: 899e30150000 MOV dword ptr [ESI + 0x1530],EBX
    m.w32((s.si+0x00001530u), s.bx);
  }
  { // 0x614096: 889e34150000 MOV byte ptr [ESI + 0x1534],BL
    m.w8((s.si+0x00001534u), (s.bx & 0xffu));
  }
  { // 0x61409c: c706ec327900 MOV dword ptr [ESI],0x7932ec
    m.w32((s.si), 0x007932ecu);
  }
  { // 0x6140a2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6140a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6140a5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6140a6: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002140b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6140b0: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x6140b3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6140b4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6140b5: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6140b7: e834280100 CALL 0x006268f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6140bc: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x6140bf: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x6140c3: 898638150000 MOV dword ptr [ESI + 0x1538],EAX
    m.w32((s.si+0x00001538u), s.ax);
  }
  { // 0x6140c9: 89863c150000 MOV dword ptr [ESI + 0x153c],EAX
    m.w32((s.si+0x0000153cu), s.ax);
  }
  { // 0x6140cf: e8fcb90700 CALL 0x0068fad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6140d4: 8d960c150000 LEA EDX,[ESI + 0x150c]
    s.dx = (s.si+0x0000150cu);
  }
  { // 0x6140da: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6140dc: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x6140de: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x6140e0: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6140e4: 899e18150000 MOV dword ptr [ESI + 0x1518],EBX
    m.w32((s.si+0x00001518u), s.bx);
  }
  { // 0x6140ea: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  { // 0x6140ed: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  { // 0x6140f0: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x6140f4: e8d7b90700 CALL 0x0068fad0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6140f9: 8d961c150000 LEA EDX,[ESI + 0x151c]
    s.dx = (s.si+0x0000151cu);
  }
  { // 0x6140ff: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x614101: 899e28150000 MOV dword ptr [ESI + 0x1528],EBX
    m.w32((s.si+0x00001528u), s.bx);
  }
  { // 0x614107: 899e2c150000 MOV dword ptr [ESI + 0x152c],EBX
    m.w32((s.si+0x0000152cu), s.bx);
  }
  { // 0x61410d: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x61410f: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x614113: 899e30150000 MOV dword ptr [ESI + 0x1530],EBX
    m.w32((s.si+0x00001530u), s.bx);
  }
  { // 0x614119: 889e34150000 MOV byte ptr [ESI + 0x1534],BL
    m.w8((s.si+0x00001534u), (s.bx & 0xffu));
  }
  { // 0x61411f: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  { // 0x614122: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x614123: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x614124: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  { // 0x614127: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x61412a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00214140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x614140: e85b280100 CALL 0x006269a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x614145: ba78e4a500 MOV EDX,0xa5e478
    s.dx = 0x00a5e478u;
  }
  { // 0x61414a: b9245f7d00 MOV ECX,0x7d5f24
    s.cx = 0x007d5f24u;
  }
  { // 0x61414f: e8fc0ee8ff CALL 0x00495050
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x614154: a374e4a500 MOV [0x00a5e474],EAX
    m.w32((0x00a5e474u), s.ax);
  }
  { // 0x614159: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00214160(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x614160: e83b270100 CALL 0x006268a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x614165: a078e4a500 MOV AL,[0x00a5e478]
    s.ax = with_al(s.ax, m.r8((0x00a5e478u)));
  }
  { // 0x61416a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x61416c: 7415 JZ 0x00614183
    if(integer::condition("JZ",flags)) goto L00614183;
  }
  { // 0x61416e: a174e4a500 MOV EAX,[0x00a5e474]
    s.ax = m.r32((0x00a5e474u));
  }
  { // 0x614173: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x614174: e802951500 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x614179: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x61417c: c60578e4a50000 MOV byte ptr [0x00a5e478],0x0
    m.w8((0x00a5e478u), 0x00000000u);
  }
  L00614183: { // 0x614183: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00214da0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x614da0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x614da4: 3de7030000 CMP EAX,0x3e7
    (void)integer::sub(s.ax,0x000003e7u,32,flags);
  }
  { // 0x614da9: 753f JNZ 0x00614dea
    if(integer::condition("JNZ",flags)) goto L00614dea;
  }
  { // 0x614dab: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  { // 0x614db0: 8b88d4520000 MOV ECX,dword ptr [EAX + 0x52d4]
    s.cx = m.r32((s.ax+0x000052d4u));
  }
  { // 0x614db6: 8b90d0520000 MOV EDX,dword ptr [EAX + 0x52d0]
    s.dx = m.r32((s.ax+0x000052d0u));
  }
  { // 0x614dbc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x614dbd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x614dbe: 6896020000 PUSH 0x296
    f.push(m,0x00000296u);
  }
  { // 0x614dc3: 68405f7d00 PUSH 0x7d5f40
    f.push(m,0x007d5f40u);
  }
  { // 0x614dc8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x614dca: b9305f7d00 MOV ECX,0x7d5f30
    s.cx = 0x007d5f30u;
  }
  { // 0x614dcf: e88c9d0d00 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x614dd4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x614dd5: 6838e3a500 PUSH 0xa5e338
    f.push(m,0x00a5e338u);
  }
  { // 0x614dda: e8c5a21500 CALL 0x0076f0a4
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x614ddf: 83c410 ADD ESP,0x10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  { // 0x614de2: b838e3a500 MOV EAX,0xa5e338
    s.ax = 0x00a5e338u;
  }
  { // 0x614de7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00614dea: { // 0x614dea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x614deb: e850720100 CALL 0x0062c040
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x614df0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00216ae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x616ae0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x616ae1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x616ae2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x616ae6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x616ae8: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x616aea: 744c JZ 0x00616b38
    if(integer::condition("JZ",flags)) goto L00616b38;
  }
  { // 0x616aec: 8b4654 MOV EAX,dword ptr [ESI + 0x54]
    s.ax = m.r32((s.si+0x00000054u));
  }
  { // 0x616aef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x616af1: 741b JZ 0x00616b0e
    if(integer::condition("JZ",flags)) goto L00616b0e;
  }
  { // 0x616af3: 8a4e58 MOV CL,byte ptr [ESI + 0x58]
    s.cx = with_al(s.cx, m.r8((s.si+0x00000058u)));
  }
  { // 0x616af6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x616af8: 740d JZ 0x00616b07
    if(integer::condition("JZ",flags)) goto L00616b07;
  }
  { // 0x616afa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x616afb: e87b6b1500 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x616b00: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x616b03: c6465800 MOV byte ptr [ESI + 0x58],0x0
    m.w8((s.si+0x00000058u), 0x00000000u);
  }
  L00616b07: { // 0x616b07: c7465400000000 MOV dword ptr [ESI + 0x54],0x0
    m.w32((s.si+0x00000054u), 0x00000000u);
  }
  L00616b0e: { // 0x616b0e: 8d5658 LEA EDX,[ESI + 0x58]
    s.dx = (s.si+0x00000058u);
  }
  { // 0x616b11: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x616b13: e838e5e7ff CALL 0x00495050
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x616b18: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x616b1a: 894654 MOV dword ptr [ESI + 0x54],EAX
    m.w32((s.si+0x00000054u), s.ax);
  }
  { // 0x616b1d: 7419 JZ 0x00616b38
    if(integer::condition("JZ",flags)) goto L00616b38;
  }
  { // 0x616b1f: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  { // 0x616b23: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x616b25: 740a JZ 0x00616b31
    if(integer::condition("JZ",flags)) goto L00616b31;
  }
  { // 0x616b27: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  { // 0x616b29: 894e5c MOV dword ptr [ESI + 0x5c],ECX
    m.w32((s.si+0x0000005cu), s.cx);
  }
  { // 0x616b2c: e8efe4efff CALL 0x00515020
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L00616b31: { // 0x616b31: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  { // 0x616b35: 894674 MOV dword ptr [ESI + 0x74],EAX
    m.w32((s.si+0x00000074u), s.ax);
  }
  L00616b38: { // 0x616b38: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x616b39: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x616b3a: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_002345a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6345a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6345a1: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6345a5: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6345a7: 741d JZ 0x006345c6
    if(integer::condition("JZ",flags)) goto L006345c6;
  }
  { // 0x6345a9: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x6345ad: 8d5602 LEA EDX,[ESI + 0x2]
    s.dx = (s.si+0x00000002u);
  }
  { // 0x6345b0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6345b1: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6345b5: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6345b6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6345b7: e884ffffff CALL 0x00634540
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6345bc: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  { // 0x6345bf: 668906 MOV word ptr [ESI],AX
    m.w16((s.si), (s.ax & 0xffffu));
  }
  { // 0x6345c2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6345c3: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L006345c6: { // 0x6345c6: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  { // 0x6345ca: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x6345ce: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6345cf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6345d1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6345d2: e869ffffff CALL 0x00634540
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6345d7: 83c002 ADD EAX,0x2
    s.ax = integer::add(s.ax,0x00000002u,32,flags);
  }
  { // 0x6345da: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6345db: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_00236130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x636130: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x636131: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x636133: c7064c3e7900 MOV dword ptr [ESI],0x793e4c
    m.w32((s.si), 0x00793e4cu);
  }
  { // 0x636139: c74604843d7900 MOV dword ptr [ESI + 0x4],0x793d84
    m.w32((s.si+0x00000004u), 0x00793d84u);
  }
  { // 0x636140: e88b50f0ff CALL 0x0053b1d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x636145: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x63614a: 7409 JZ 0x00636155
    if(integer::condition("JZ",flags)) goto L00636155;
  }
  { // 0x63614c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x63614d: e829751300 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x636152: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00636155: { // 0x636155: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x636157: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x636158: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00244bc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x644bc0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x644bc1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x644bc2: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x644bc6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x644bc8: 687c9a7b00 PUSH 0x7b9a7c
    f.push(m,0x007b9a7cu);
  }
  { // 0x644bcd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x644bcf: 8d9698110000 LEA EDX,[ESI + 0x1198]
    s.dx = (s.si+0x00001198u);
  }
  { // 0x644bd5: e836000000 CALL 0x00644c10
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x644bda: 68c8ca7b00 PUSH 0x7bcac8
    f.push(m,0x007bcac8u);
  }
  { // 0x644bdf: 8d96e8110000 LEA EDX,[ESI + 0x11e8]
    s.dx = (s.si+0x000011e8u);
  }
  { // 0x644be5: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x644be7: e824000000 CALL 0x00644c10
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x644bec: 68e0b67d00 PUSH 0x7db6e0
    f.push(m,0x007db6e0u);
  }
  { // 0x644bf1: 8d9638120000 LEA EDX,[ESI + 0x1238]
    s.dx = (s.si+0x00001238u);
  }
  { // 0x644bf7: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x644bf9: e812000000 CALL 0x00644c10
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x644bfe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x644bff: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x644c01: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x644c02: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002497d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6497d0: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  { // 0x6497d3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6497d5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6497d7: b9301b8200 MOV ECX,0x821b30
    s.cx = 0x00821b30u;
  }
  { // 0x6497dc: e80f16ecff CALL 0x0050adf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6497e1: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x6497e5: 68606c7c00 PUSH 0x7c6c60
    f.push(m,0x007c6c60u);
  }
  { // 0x6497ea: e881f3e1ff CALL 0x00468b70
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6497ef: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x6497f3: b9301b8200 MOV ECX,0x821b30
    s.cx = 0x00821b30u;
  }
  { // 0x6497f8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6497fa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6497fc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6497fd: e8cefae1ff CALL 0x004692d0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x649802: 8d4c2454 LEA ECX,[ESP + 0x54]
    s.cx = (f.sp+0x00000054u);
  }
  { // 0x649806: c7442400a0567800 MOV dword ptr [ESP],0x7856a0
    m.w32((f.sp), 0x007856a0u);
  }
  { // 0x64980e: c744246000000000 MOV dword ptr [ESP + 0x60],0x0
    m.w32((f.sp+0x00000060u), 0x00000000u);
  }
  { // 0x649816: e875eadeff CALL 0x00438290
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x64981b: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x64981f: c744240058567800 MOV dword ptr [ESP],0x785658
    m.w32((f.sp), 0x00785658u);
  }
  { // 0x649827: e8245adeff CALL 0x0042f250
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x64982c: 83c464 ADD ESP,0x64
    f.sp = integer::add(f.sp,0x00000064u,32,flags);
  }
  { // 0x64982f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0024ae40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64ae40: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x64ae46: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x64ae4a: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x64ae4f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ae50: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x64ae57: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64ae5c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64ae5d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64ae5e: e88d2fecff CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x64ae63: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64ae65: 7412 JZ 0x0064ae79
    if(integer::condition("JZ",flags)) goto L0064ae79;
  }
  { // 0x64ae67: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x64ae6b: e880ac0c00 CALL 0x00715af0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x64ae70: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64ae76: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0064ae79: { // 0x64ae79: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  { // 0x64ae80: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64ae86: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0024ae90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64ae90: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x64ae96: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x64ae9a: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x64ae9f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64aea0: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x64aea7: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64aeac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64aead: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64aeae: e83d2fecff CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x64aeb3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64aeb5: 7412 JZ 0x0064aec9
    if(integer::condition("JZ",flags)) goto L0064aec9;
  }
  { // 0x64aeb7: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x64aebb: e8e0b5ddff CALL 0x004264a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x64aec0: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64aec6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0064aec9: { // 0x64aec9: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  { // 0x64aed0: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64aed6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0024aee0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64aee0: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x64aee6: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x64aeea: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x64aeef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64aef0: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x64aef7: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64aefc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64aefd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64aefe: e8ed2eecff CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x64af03: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64af05: 7412 JZ 0x0064af19
    if(integer::condition("JZ",flags)) goto L0064af19;
  }
  { // 0x64af07: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x64af0b: e890b5ddff CALL 0x004264a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x64af10: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64af16: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0064af19: { // 0x64af19: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  { // 0x64af20: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64af26: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0024b100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64b100: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b106: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x64b10a: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x64b10f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64b110: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x64b117: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64b11c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64b11d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64b11e: e8cd2cecff CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x64b123: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64b125: 7412 JZ 0x0064b139
    if(integer::condition("JZ",flags)) goto L0064b139;
  }
  { // 0x64b127: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x64b12b: e8202ce1ff CALL 0x0045dd50
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x64b130: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b136: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0064b139: { // 0x64b139: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  { // 0x64b140: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b146: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0024b150(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64b150: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b156: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x64b15a: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x64b15f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64b160: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x64b167: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64b16c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64b16d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64b16e: e87d2cecff CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x64b173: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64b175: 7412 JZ 0x0064b189
    if(integer::condition("JZ",flags)) goto L0064b189;
  }
  { // 0x64b177: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x64b17b: e8d010ddff CALL 0x0041c250
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x64b180: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b186: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0064b189: { // 0x64b189: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  { // 0x64b190: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b196: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0024b1a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x64b1a0: 81ec80000000 SUB ESP,0x80
    f.sp = integer::sub(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b1a6: 8d442400 LEA EAX,[ESP]
    s.ax = (f.sp);
  }
  { // 0x64b1aa: 6880000000 PUSH 0x80
    f.push(m,0x00000080u);
  }
  { // 0x64b1af: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64b1b0: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x64b1b7: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64b1bc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x64b1bd: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x64b1be: e82d2cecff CALL 0x0050ddf0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x64b1c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x64b1c5: 7412 JZ 0x0064b1d9
    if(integer::condition("JZ",flags)) goto L0064b1d9;
  }
  { // 0x64b1c7: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x64b1cb: e810fb0800 CALL 0x006dace0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x64b1d0: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b1d6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0064b1d9: { // 0x64b1d9: 8b842488000000 MOV EAX,dword ptr [ESP + 0x88]
    s.ax = m.r32((f.sp+0x00000088u));
  }
  { // 0x64b1e0: 81c480000000 ADD ESP,0x80
    f.sp = integer::add(f.sp,0x00000080u,32,flags);
  }
  { // 0x64b1e6: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0025f230(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x65f230: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x65f231: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x65f233: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x65f235: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x65f237: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x65f23a: 884608 MOV byte ptr [ESI + 0x8],AL
    m.w8((s.si+0x00000008u), (s.ax & 0xffu));
  }
  { // 0x65f23d: e8ee7cdaff CALL 0x00406f30
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x65f242: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x65f244: 740f JZ 0x0065f255
    if(integer::condition("JZ",flags)) goto L0065f255;
  }
  { // 0x65f246: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x65f24a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x65f24b: e8f69e1100 CALL 0x00779146
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x65f250: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x65f253: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0065f255: { // 0x65f255: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x65f257: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x65f258: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002605e0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6605e0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6605e1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6605e3: e8580c0000 CALL 0x00661240
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6605e8: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6605ec: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6605f0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6605f1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6605f2: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6605f4: e8875f0300 CALL 0x00696580
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6605f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6605fa: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00267120(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x667120: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x667123: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x667124: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x667126: 68c4697c00 PUSH 0x7c69c4
    f.push(m,0x007c69c4u);
  }
  { // 0x66712b: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x66712f: e8ac8ffcff CALL 0x006300e0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x667134: 8a86871e0000 MOV AL,byte ptr [ESI + 0x1e87]
    s.ax = with_al(s.ax, m.r8((s.si+0x00001e87u)));
  }
  { // 0x66713a: b9801a8200 MOV ECX,0x821a80
    s.cx = 0x00821a80u;
  }
  { // 0x66713f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x667140: 6810d17d00 PUSH 0x7dd110
    f.push(m,0x007dd110u);
  }
  { // 0x667145: 6864d17d00 PUSH 0x7dd164
    f.push(m,0x007dd164u);
  }
  { // 0x66714a: e88176eaff CALL 0x0050e7d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x66714f: 8a8e861e0000 MOV CL,byte ptr [ESI + 0x1e86]
    s.cx = with_al(s.cx, m.r8((s.si+0x00001e86u)));
  }
  { // 0x667155: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x667156: 6804d17d00 PUSH 0x7dd104
    f.push(m,0x007dd104u);
  }
  { // 0x66715b: 6864d17d00 PUSH 0x7dd164
    f.push(m,0x007dd164u);
  }
  { // 0x667160: b9801a8200 MOV ECX,0x821a80
    s.cx = 0x00821a80u;
  }
  { // 0x667165: e86676eaff CALL 0x0050e7d0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x66716a: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x66716e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x667170: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x667171: b9801a8200 MOV ECX,0x821a80
    s.cx = 0x00821a80u;
  }
  { // 0x667176: e89523e0ff CALL 0x00469510
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x66717b: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x66717f: e8dc8efcff CALL 0x00630060
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x667184: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x667185: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x667188: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00268250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x668250: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x668254: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668255: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x668257: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x668259: 7416 JZ 0x00668271
    if(integer::condition("JZ",flags)) goto L00668271;
  }
  { // 0x66825b: 6a2c PUSH 0x2c
    f.push(m,0x0000002cu);
  }
  { // 0x66825d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66825e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66825f: e8fe6c1000 CALL 0x0076ef62
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x668264: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x668267: 66c746560000 MOV word ptr [ESI + 0x56],0x0
    m.w16((s.si+0x00000056u), 0x00000000u);
  }
  { // 0x66826d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66826e: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00668271: { // 0x668271: 68a1090000 PUSH 0x9a1
    f.push(m,0x000009a1u);
  }
  { // 0x668276: 68b4ce7d00 PUSH 0x7dceb4
    f.push(m,0x007dceb4u);
  }
  { // 0x66827b: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x66827d: b948d57d00 MOV ECX,0x7dd548
    s.cx = 0x007dd548u;
  }
  { // 0x668282: e8d9680800 CALL 0x006eeb60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x668287: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x668288: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668289: e83b6d1000 CALL 0x0076efc9
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x66828e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x668291: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668292: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0026aa70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66aa70: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66aa71: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66aa72: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x66aa74: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x66aa76: 8a465c MOV AL,byte ptr [ESI + 0x5c]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000005cu)));
  }
  { // 0x66aa79: c706a0b67800 MOV dword ptr [ESI],0x78b6a0
    m.w32((s.si), 0x0078b6a0u);
  }
  { // 0x66aa7f: 3ac3 CMP AL,BL
    (void)integer::sub((s.ax & 0xffu),(s.bx & 0xffu),8,flags);
  }
  { // 0x66aa81: 741c JZ 0x0066aa9f
    if(integer::condition("JZ",flags)) goto L0066aa9f;
  }
  { // 0x66aa83: 8b4658 MOV EAX,dword ptr [ESI + 0x58]
    s.ax = m.r32((s.si+0x00000058u));
  }
  { // 0x66aa86: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x66aa88: 7415 JZ 0x0066aa9f
    if(integer::condition("JZ",flags)) goto L0066aa9f;
  }
  { // 0x66aa8a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66aa8b: e8eb2b1000 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x66aa90: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x66aa93: 895e58 MOV dword ptr [ESI + 0x58],EBX
    m.w32((s.si+0x00000058u), s.bx);
  }
  { // 0x66aa96: 885e5c MOV byte ptr [ESI + 0x5c],BL
    m.w8((s.si+0x0000005cu), (s.bx & 0xffu));
  }
  { // 0x66aa99: 895e14 MOV dword ptr [ESI + 0x14],EBX
    m.w32((s.si+0x00000014u), s.bx);
  }
  { // 0x66aa9c: 895e18 MOV dword ptr [ESI + 0x18],EBX
    m.w32((s.si+0x00000018u), s.bx);
  }
  L0066aa9f: { // 0x66aa9f: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x66aaa1: e8ba41e6ff CALL 0x004cec60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x66aaa6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66aaa7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x66aaa8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0026ad00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66ad00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66ad01: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x66ad05: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66ad06: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66ad07: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x66ad0b: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x66ad0d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66ad0e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66ad0f: 8d4e0c LEA ECX,[ESI + 0xc]
    s.cx = (s.si+0x0000000cu);
  }
  { // 0x66ad12: e8f9f8ffff CALL 0x0066a610
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x66ad17: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66ad18: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66ad19: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x66ad1b: e8b0b9f9ff CALL 0x006066d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x66ad20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x66ad21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66ad22: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x66ad23: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0026ad40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x66ad40: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x66ad41: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66ad42: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x66ad46: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x66ad48: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x66ad4a: 742c JZ 0x0066ad78
    if(integer::condition("JZ",flags)) goto L0066ad78;
  }
  { // 0x66ad4c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x66ad50: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  { // 0x66ad53: 7c23 JL 0x0066ad78
    if(integer::condition("JL",flags)) goto L0066ad78;
  }
  { // 0x66ad55: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66ad56: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66ad57: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66ad58: e8e3590200 CALL 0x00690740
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x66ad5d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x66ad5f: 8a460c MOV AL,byte ptr [ESI + 0xc]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000000cu)));
  }
  { // 0x66ad62: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x66ad64: 750a JNZ 0x0066ad70
    if(integer::condition("JNZ",flags)) goto L0066ad70;
  }
  { // 0x66ad66: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x66ad67: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x66ad68: 8d4e10 LEA ECX,[ESI + 0x10]
    s.cx = (s.si+0x00000010u);
  }
  { // 0x66ad6b: e8a0f8ffff CALL 0x0066a610
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L0066ad70: { // 0x66ad70: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x66ad72: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x66ad73: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x66ad74: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66ad75: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L0066ad78: { // 0x66ad78: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x66ad79: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x66ad7b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x66ad7c: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00274590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x674590: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x674591: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x674592: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x674594: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x674595: 8b5650 MOV EDX,dword ptr [ESI + 0x50]
    s.dx = m.r32((s.si+0x00000050u));
  }
  { // 0x674598: 83fa4b CMP EDX,0x4b
    (void)integer::sub(s.dx,0x0000004bu,32,flags);
  }
  { // 0x67459b: 7f58 JG 0x006745f5
    if(integer::condition("JG",flags)) goto L006745f5;
  }
  { // 0x67459d: 8b5c2414 MOV EBX,dword ptr [ESP + 0x14]
    s.bx = m.r32((f.sp+0x00000014u));
  }
  { // 0x6745a1: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x6745a5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6745a7: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x6745a9: 7e14 JLE 0x006745bf
    if(integer::condition("JLE",flags)) goto L006745bf;
  }
  { // 0x6745ab: 8d4654 LEA EAX,[ESI + 0x54]
    s.ax = (s.si+0x00000054u);
  }
  L006745ae: { // 0x6745ae: 397804 CMP dword ptr [EAX + 0x4],EDI
    (void)integer::sub(m.r32((s.ax+0x00000004u)),s.di,32,flags);
  }
  { // 0x6745b1: 7504 JNZ 0x006745b7
    if(integer::condition("JNZ",flags)) goto L006745b7;
  }
  { // 0x6745b3: 3918 CMP dword ptr [EAX],EBX
    (void)integer::sub(m.r32((s.ax)),s.bx,32,flags);
  }
  { // 0x6745b5: 743e JZ 0x006745f5
    if(integer::condition("JZ",flags)) goto L006745f5;
  }
  L006745b7: { // 0x6745b7: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x6745b8: 83c030 ADD EAX,0x30
    s.ax = integer::add(s.ax,0x00000030u,32,flags);
  }
  { // 0x6745bb: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x6745bd: 7cef JL 0x006745ae
    if(integer::condition("JL",flags)) goto L006745ae;
  }
  L006745bf: { // 0x6745bf: a1c483a200 MOV EAX,[0x00a283c4]
    s.ax = m.r32((0x00a283c4u));
  }
  { // 0x6745c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6745c6: 7514 JNZ 0x006745dc
    if(integer::condition("JNZ",flags)) goto L006745dc;
  }
  { // 0x6745c8: 83ff1f CMP EDI,0x1f
    (void)integer::sub(s.di,0x0000001fu,32,flags);
  }
  { // 0x6745cb: 740f JZ 0x006745dc
    if(integer::condition("JZ",flags)) goto L006745dc;
  }
  { // 0x6745cd: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x6745cf: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  { // 0x6745d2: b9c8d67d00 MOV ECX,0x7dd6c8
    s.cx = 0x007dd6c8u;
  }
  { // 0x6745d7: e824610900 CALL 0x0070a700
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L006745dc: { // 0x6745dc: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6745dd: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6745de: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6745e0: e8cbfeffff CALL 0x006744b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6745e5: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6745e7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6745e8: 884638 MOV byte ptr [ESI + 0x38],AL
    m.w8((s.si+0x00000038u), (s.ax & 0xffu));
  }
  { // 0x6745eb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6745ec: a203f78100 MOV [0x0081f703],AL
    m.w8((0x0081f703u), (s.ax & 0xffu));
  }
  { // 0x6745f1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6745f2: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L006745f5: { // 0x6745f5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6745f6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6745f7: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6745f9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6745fa: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_00276d60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x676d60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x676d61: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x676d62: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x676d64: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x676d6a: e8619d0600 CALL 0x006e0ad0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x676d6f: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x676d75: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x676d77: e8449d0600 CALL 0x006e0ac0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x676d7c: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x676d7f: b301 MOV BL,0x1
    s.bx = with_al(s.bx, 0x00000001u);
  }
  { // 0x676d81: 885e34 MOV byte ptr [ESI + 0x34],BL
    m.w8((s.si+0x00000034u), (s.bx & 0xffu));
  }
  { // 0x676d84: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x676d86: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x676d8b: 885838 MOV byte ptr [EAX + 0x38],BL
    m.w8((s.ax+0x00000038u), (s.bx & 0xffu));
  }
  { // 0x676d8e: e89d92e6ff CALL 0x004e0030
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x676d93: 881d03f78100 MOV byte ptr [0x0081f703],BL
    m.w8((0x0081f703u), (s.bx & 0xffu));
  }
  { // 0x676d99: 881d8c48aa00 MOV byte ptr [0x00aa488c],BL
    m.w8((0x00aa488cu), (s.bx & 0xffu));
  }
  { // 0x676d9f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x676da0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x676da1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00276db0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x676db0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x676db1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x676db3: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x676db9: e8229d0600 CALL 0x006e0ae0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x676dbe: 8b462c MOV EAX,dword ptr [ESI + 0x2c]
    s.ax = m.r32((s.si+0x0000002cu));
  }
  { // 0x676dc1: c6463400 MOV byte ptr [ESI + 0x34],0x0
    m.w8((s.si+0x00000034u), 0x00000000u);
  }
  { // 0x676dc5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x676dc7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x676dcc: c6403801 MOV byte ptr [EAX + 0x38],0x1
    m.w8((s.ax+0x00000038u), 0x00000001u);
  }
  { // 0x676dd0: e85b92e6ff CALL 0x004e0030
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x676dd5: c60503f7810001 MOV byte ptr [0x0081f703],0x1
    m.w8((0x0081f703u), 0x00000001u);
  }
  { // 0x676ddc: c6058c48aa0001 MOV byte ptr [0x00aa488c],0x1
    m.w8((0x00aa488cu), 0x00000001u);
  }
  { // 0x676de3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x676de4: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0027d7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x67d7d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x67d7d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x67d7d3: 689c000000 PUSH 0x9c
    f.push(m,0x0000009cu);
  }
  { // 0x67d7d8: e87a010f00 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x67d7dd: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x67d7e0: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x67d7e2: 7413 JZ 0x0067d7f7
    if(integer::condition("JZ",flags)) goto L0067d7f7;
  }
  { // 0x67d7e4: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  { // 0x67d7e6: 68684aaa00 PUSH 0xaa4a68
    f.push(m,0x00aa4a68u);
  }
  { // 0x67d7eb: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x67d7ec: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x67d7ee: e8fdf4ffff CALL 0x0067ccf0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x67d7f3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67d7f4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0067d7f7: { // 0x67d7f7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x67d7f9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x67d7fa: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0028df20(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x68df20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x68df21: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x68df23: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x68df26: c706786f7900 MOV dword ptr [ESI],0x796f78
    m.w32((s.si), 0x00796f78u);
  }
  { // 0x68df2c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x68df2e: 7409 JZ 0x0068df39
    if(integer::condition("JZ",flags)) goto L0068df39;
  }
  { // 0x68df30: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x68df31: e845f70d00 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x68df36: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0068df39: { // 0x68df39: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  { // 0x68df3c: e84fa3daff CALL 0x00438290
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x68df41: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x68df43: e8180de4ff CALL 0x004cec60
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x68df48: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x68df49: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0028e190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x68e190: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x68e191: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x68e193: 8b4630 MOV EAX,dword ptr [ESI + 0x30]
    s.ax = m.r32((s.si+0x00000030u));
  }
  { // 0x68e196: c706786f7900 MOV dword ptr [ESI],0x796f78
    m.w32((s.si), 0x00796f78u);
  }
  { // 0x68e19c: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x68e19e: 7409 JZ 0x0068e1a9
    if(integer::condition("JZ",flags)) goto L0068e1a9;
  }
  { // 0x68e1a0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x68e1a1: e8d5f40d00 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x68e1a6: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0068e1a9: { // 0x68e1a9: 8d4e24 LEA ECX,[ESI + 0x24]
    s.cx = (s.si+0x00000024u);
  }
  { // 0x68e1ac: e8dfa0daff CALL 0x00438290
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x68e1b1: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x68e1b3: e8a80ae4ff CALL 0x004cec60
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x68e1b8: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x68e1bd: 7409 JZ 0x0068e1c8
    if(integer::condition("JZ",flags)) goto L0068e1c8;
  }
  { // 0x68e1bf: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x68e1c0: e8b6f40d00 CALL 0x0076d67b
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x68e1c5: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0068e1c8: { // 0x68e1c8: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x68e1ca: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x68e1cb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002907c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6907c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6907c1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6907c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6907c4: 8b4614 MOV EAX,dword ptr [ESI + 0x14]
    s.ax = m.r32((s.si+0x00000014u));
  }
  { // 0x6907c7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6907c9: 7410 JZ 0x006907db
    if(integer::condition("JZ",flags)) goto L006907db;
  }
  { // 0x6907cb: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6907cc: e8aace0d00 CALL 0x0076d67b
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6907d1: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6907d4: c7461400000000 MOV dword ptr [ESI + 0x14],0x0
    m.w32((s.si+0x00000014u), 0x00000000u);
  }
  L006907db: { // 0x6907db: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6907df: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6907e1: 7424 JZ 0x00690807
    if(integer::condition("JZ",flags)) goto L00690807;
  }
  { // 0x6907e3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6907e4: e85ce70d00 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6907e9: 8d440002 LEA EAX,[EAX + EAX*0x1 + 0x2]
    s.ax = (s.ax+(s.ax * 0x00000001u)+0x00000002u);
  }
  { // 0x6907ed: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6907ee: e864d10d00 CALL 0x0076d957
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6907f3: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6907f6: 894614 MOV dword ptr [ESI + 0x14],EAX
    m.w32((s.si+0x00000014u), s.ax);
  }
  { // 0x6907f9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6907fb: 740a JZ 0x00690807
    if(integer::condition("JZ",flags)) goto L00690807;
  }
  { // 0x6907fd: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6907fe: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6907ff: e8c5e70d00 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x690804: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L00690807: { // 0x690807: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x690808: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x690809: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00295100(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x695100: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x695101: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x695102: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x695104: c706d8717900 MOV dword ptr [ESI],0x7971d8
    m.w32((s.si), 0x007971d8u);
  }
  { // 0x69510a: e871010000 CALL 0x00695280
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x69510f: 8b4620 MOV EAX,dword ptr [ESI + 0x20]
    s.ax = m.r32((s.si+0x00000020u));
  }
  { // 0x695112: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x695114: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x695116: c7461c24727900 MOV dword ptr [ESI + 0x1c],0x797224
    m.w32((s.si+0x0000001cu), 0x00797224u);
  }
  { // 0x69511d: 7411 JZ 0x00695130
    if(integer::condition("JZ",flags)) goto L00695130;
  }
  { // 0x69511f: 385e29 CMP byte ptr [ESI + 0x29],BL
    (void)integer::sub(m.r8((s.si+0x00000029u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x695122: 740c JZ 0x00695130
    if(integer::condition("JZ",flags)) goto L00695130;
  }
  { // 0x695124: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x695125: e851850d00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x69512a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x69512d: 895e20 MOV dword ptr [ESI + 0x20],EBX
    m.w32((s.si+0x00000020u), s.bx);
  }
  L00695130: { // 0x695130: 885e29 MOV byte ptr [ESI + 0x29],BL
    m.w8((s.si+0x00000029u), (s.bx & 0xffu));
  }
  { // 0x695133: 895e24 MOV dword ptr [ESI + 0x24],EBX
    m.w32((s.si+0x00000024u), s.bx);
  }
  { // 0x695136: 8b4608 MOV EAX,dword ptr [ESI + 0x8]
    s.ax = m.r32((s.si+0x00000008u));
  }
  { // 0x695139: c7460424727900 MOV dword ptr [ESI + 0x4],0x797224
    m.w32((s.si+0x00000004u), 0x00797224u);
  }
  { // 0x695140: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x695142: 7411 JZ 0x00695155
    if(integer::condition("JZ",flags)) goto L00695155;
  }
  { // 0x695144: 385e11 CMP byte ptr [ESI + 0x11],BL
    (void)integer::sub(m.r8((s.si+0x00000011u)),(s.bx & 0xffu),8,flags);
  }
  { // 0x695147: 740c JZ 0x00695155
    if(integer::condition("JZ",flags)) goto L00695155;
  }
  { // 0x695149: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x69514a: e82c850d00 CALL 0x0076d67b
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x69514f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x695152: 895e08 MOV dword ptr [ESI + 0x8],EBX
    m.w32((s.si+0x00000008u), s.bx);
  }
  L00695155: { // 0x695155: 885e11 MOV byte ptr [ESI + 0x11],BL
    m.w8((s.si+0x00000011u), (s.bx & 0xffu));
  }
  { // 0x695158: 895e0c MOV dword ptr [ESI + 0xc],EBX
    m.w32((s.si+0x0000000cu), s.bx);
  }
  { // 0x69515b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x69515c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x69515d: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002968b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6968b0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  { // 0x6968b3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6968b5: 7448 JZ 0x006968ff
    if(integer::condition("JZ",flags)) goto L006968ff;
  }
  { // 0x6968b7: 8b4124 MOV EAX,dword ptr [ECX + 0x24]
    s.ax = m.r32((s.cx+0x00000024u));
  }
  { // 0x6968ba: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  { // 0x6968be: 8b510c MOV EDX,dword ptr [ECX + 0xc]
    s.dx = m.r32((s.cx+0x0000000cu));
  }
  { // 0x6968c1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6968c2: 89542408 MOV dword ptr [ESP + 0x8],EDX
    m.w32((f.sp+0x00000008u), s.dx);
  }
  { // 0x6968c6: 8b5110 MOV EDX,dword ptr [ECX + 0x10]
    s.dx = m.r32((s.cx+0x00000010u));
  }
  { // 0x6968c9: 8954240c MOV dword ptr [ESP + 0xc],EDX
    m.w32((f.sp+0x0000000cu), s.dx);
  }
  { // 0x6968cd: 8b5114 MOV EDX,dword ptr [ECX + 0x14]
    s.dx = m.r32((s.cx+0x00000014u));
  }
  { // 0x6968d0: 8b4918 MOV ECX,dword ptr [ECX + 0x18]
    s.cx = m.r32((s.cx+0x00000018u));
  }
  { // 0x6968d3: c644241c00 MOV byte ptr [ESP + 0x1c],0x0
    m.w8((f.sp+0x0000001cu), 0x00000000u);
  }
  { // 0x6968d8: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  { // 0x6968dc: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x6968e2: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  { // 0x6968e6: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  { // 0x6968ea: e8e1a30400 CALL 0x006e0cd0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6968ef: 8b0df01c8200 MOV ECX,dword ptr [0x00821cf0]
    s.cx = m.r32((0x00821cf0u));
  }
  { // 0x6968f5: 8d542400 LEA EDX,[ESP]
    s.dx = (f.sp);
  }
  { // 0x6968f9: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6968fa: e821a20400 CALL 0x006e0b20
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006968ff: { // 0x6968ff: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  { // 0x696902: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00297d00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x697d00: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x697d04: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x697d05: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x697d07: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x697d08: e85382d7ff CALL 0x0040ff60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x697d0d: 8d8ea80d0000 LEA ECX,[ESI + 0xda8]
    s.cx = (s.si+0x00000da8u);
  }
  { // 0x697d13: e8b87dffff CALL 0x0068fad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x697d18: 8986a40d0000 MOV dword ptr [ESI + 0xda4],EAX
    m.w32((s.si+0x00000da4u), s.ax);
  }
  { // 0x697d1e: c786ac0d000000000000 MOV dword ptr [ESI + 0xdac],0x0
    m.w32((s.si+0x00000dacu), 0x00000000u);
  }
  { // 0x697d28: c70618747900 MOV dword ptr [ESI],0x797418
    m.w32((s.si), 0x00797418u);
  }
  { // 0x697d2e: c74604fc737900 MOV dword ptr [ESI + 0x4],0x7973fc
    m.w32((s.si+0x00000004u), 0x007973fcu);
  }
  { // 0x697d35: c74608f4737900 MOV dword ptr [ESI + 0x8],0x7973f4
    m.w32((s.si+0x00000008u), 0x007973f4u);
  }
  { // 0x697d3c: c7460cec737900 MOV dword ptr [ESI + 0xc],0x7973ec
    m.w32((s.si+0x0000000cu), 0x007973ecu);
  }
  { // 0x697d43: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x697d45: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x697d46: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0029bc80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x69bc80: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x69bc83: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x69bc84: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x69bc85: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x69bc89: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x69bc8b: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x69bc8f: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  { // 0x69bc92: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x69bc94: 894c240c MOV dword ptr [ESP + 0xc],ECX
    m.w32((f.sp+0x0000000cu), s.cx);
  }
  { // 0x69bc98: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x69bc99: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x69bc9b: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  { // 0x69bc9f: e81c260000 CALL 0x0069e2c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x69bca4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x69bca6: 7413 JZ 0x0069bcbb
    if(integer::condition("JZ",flags)) goto L0069bcbb;
  }
  { // 0x69bca8: a05389a200 MOV AL,[0x00a28953]
    s.ax = with_al(s.ax, m.r8((0x00a28953u)));
  }
  { // 0x69bcad: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x69bcaf: 750a JNZ 0x0069bcbb
    if(integer::condition("JNZ",flags)) goto L0069bcbb;
  }
  { // 0x69bcb1: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x69bcb5: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x69bcb9: eb05 JMP 0x0069bcc0
    goto L0069bcc0;
  }
  L0069bcbb: { // 0x69bcbb: 8b07 MOV EAX,dword ptr [EDI]
    s.ax = m.r32((s.di));
  }
  { // 0x69bcbd: 8b4f04 MOV ECX,dword ptr [EDI + 0x4]
    s.cx = m.r32((s.di+0x00000004u));
  }
  L0069bcc0: { // 0x69bcc0: 8986640d0000 MOV dword ptr [ESI + 0xd64],EAX
    m.w32((s.si+0x00000d64u), s.ax);
  }
  { // 0x69bcc6: 8986740d0000 MOV dword ptr [ESI + 0xd74],EAX
    m.w32((s.si+0x00000d74u), s.ax);
  }
  { // 0x69bccc: 898e680d0000 MOV dword ptr [ESI + 0xd68],ECX
    m.w32((s.si+0x00000d68u), s.cx);
  }
  { // 0x69bcd2: 898e780d0000 MOV dword ptr [ESI + 0xd78],ECX
    m.w32((s.si+0x00000d78u), s.cx);
  }
  { // 0x69bcd8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x69bcda: e8d12a0000 CALL 0x0069e7b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x69bcdf: c6867d0d000001 MOV byte ptr [ESI + 0xd7d],0x1
    m.w8((s.si+0x00000d7du), 0x00000001u);
  }
  { // 0x69bce6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x69bce7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x69bce8: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x69bceb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002a1e50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a1e50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a1e51: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6a1e53: c70618747900 MOV dword ptr [ESI],0x797418
    m.w32((s.si), 0x00797418u);
  }
  { // 0x6a1e59: c74604fc737900 MOV dword ptr [ESI + 0x4],0x7973fc
    m.w32((s.si+0x00000004u), 0x007973fcu);
  }
  { // 0x6a1e60: c74608f4737900 MOV dword ptr [ESI + 0x8],0x7973f4
    m.w32((s.si+0x00000008u), 0x007973f4u);
  }
  { // 0x6a1e67: c7460cec737900 MOV dword ptr [ESI + 0xc],0x7973ec
    m.w32((s.si+0x0000000cu), 0x007973ecu);
  }
  { // 0x6a1e6e: c705ac1c820000000000 MOV dword ptr [0x00821cac],0x0
    m.w32((0x00821cacu), 0x00000000u);
  }
  { // 0x6a1e78: e813e1d6ff CALL 0x0040ff90
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a1e7d: f644240801 TEST byte ptr [ESP + 0x8],0x1
    (void)integer::logical((m.r8((f.sp+0x00000008u)))&(0x00000001u),8,flags);
  }
  { // 0x6a1e82: 7409 JZ 0x006a1e8d
    if(integer::condition("JZ",flags)) goto L006a1e8d;
  }
  { // 0x6a1e84: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a1e85: e8f1b70c00 CALL 0x0076d67b
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a1e8a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L006a1e8d: { // 0x6a1e8d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6a1e8f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a1e90: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002a4fa0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a4fa0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a4fa1: 8b4144 MOV EAX,dword ptr [ECX + 0x44]
    s.ax = m.r32((s.cx+0x00000044u));
  }
  { // 0x6a4fa4: 8d4c2400 LEA ECX,[ESP]
    s.cx = (f.sp);
  }
  { // 0x6a4fa8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a4fa9: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a4faa: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x6a4fb0: e87b51fbff CALL 0x0065a130
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a4fb5: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x6a4fb7: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6a4fb8: e813a2e7ff CALL 0x0051f1d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a4fbd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a4fbf: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6a4fc0: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a6490(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a6490: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a6491: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6a6493: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a6494: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6a6495: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x6a649b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x6a649d: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x6a649f: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  { // 0x6a64a2: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x6a64a3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x6a64a9: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x6a64ab: c1fe08 SAR ESI,0x8
    s.si = integer::shift(s.si,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6a64ae: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x6a64b1: 6689742404 MOV word ptr [ESP + 0x4],SI
    m.w16((f.sp+0x00000004u), (s.si & 0xffffu));
  }
  { // 0x6a64b6: 6689442406 MOV word ptr [ESP + 0x6],AX
    m.w16((f.sp+0x00000006u), (s.ax & 0xffffu));
  }
  { // 0x6a64bb: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  { // 0x6a64bf: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x6a64c3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6a64c5: 663b35b878aa00 CMP SI,word ptr [0x00aa78b8]
    (void)integer::sub((s.si & 0xffffu),m.r16((0x00aa78b8u)),16,flags);
  }
  { // 0x6a64cc: 7509 JNZ 0x006a64d7
    if(integer::condition("JNZ",flags)) goto L006a64d7;
  }
  { // 0x6a64ce: 663b05ba78aa00 CMP AX,word ptr [0x00aa78ba]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00aa78bau)),16,flags);
  }
  { // 0x6a64d5: 7427 JZ 0x006a64fe
    if(integer::condition("JZ",flags)) goto L006a64fe;
  }
  L006a64d7: { // 0x6a64d7: 8d542404 LEA EDX,[ESP + 0x4]
    s.dx = (f.sp+0x00000004u);
  }
  { // 0x6a64db: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6a64e0: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6a64e1: e81af0e9ff CALL 0x00545500
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a64e6: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x6a64e8: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a64ea: e8c1aedcff CALL 0x004713b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a64ef: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a64f1: 750d JNZ 0x006a6500
    if(integer::condition("JNZ",flags)) goto L006a6500;
  }
  { // 0x6a64f3: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a64f4: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6a64f6: e8e5aedcff CALL 0x004713e0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6a64fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a64fc: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6a64fd: c3 RET
    finish(m,s,f,0u); return;
  }
  L006a64fe: { // 0x6a64fe: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L006a6500: { // 0x6a6500: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a6501: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6a6502: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002a70d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a70d0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a70d1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6a70d3: e8b880e7ff CALL 0x0051f190
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a70d8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6a70da: 7406 JZ 0x006a70e2
    if(integer::condition("JZ",flags)) goto L006a70e2;
  }
  { // 0x6a70dc: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6a70de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a70df: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a70e2: { // 0x6a70e2: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x6a70e8: a1b878aa00 MOV EAX,[0x00aa78b8]
    s.ax = m.r32((0x00aa78b8u));
  }
  { // 0x6a70ed: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6a70ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a70f0: 8b91e8130000 MOV EDX,dword ptr [ECX + 0x13e8]
    s.dx = m.r32((s.cx+0x000013e8u));
  }
  { // 0x6a70f6: 8b4e74 MOV ECX,dword ptr [ESI + 0x74]
    s.cx = m.r32((s.si+0x00000074u));
  }
  { // 0x6a70f9: e8727de7ff CALL 0x0051ee70
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a70fe: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a7100: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a7101: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a7920(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a7920: 8b4974 MOV ECX,dword ptr [ECX + 0x74]
    s.cx = m.r32((s.cx+0x00000074u));
  }
  { // 0x6a7923: 83f9ff CMP ECX,-0x1
    (void)integer::sub(s.cx,0xffffffffu,32,flags);
  }
  { // 0x6a7926: 740c JZ 0x006a7934
    if(integer::condition("JZ",flags)) goto L006a7934;
  }
  { // 0x6a7928: e83353e4ff CALL 0x004ecc60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a792d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6a792f: e87cdee4ff CALL 0x004f57b0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006a7934: { // 0x6a7934: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a7936: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a7e80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a7e80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a7e81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a7e82: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6a7e84: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  { // 0x6a7e88: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x6a7e8b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a7e8c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6a7e8d: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x6a7e93: e89822fbff CALL 0x0065a130
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a7e98: 8b5674 MOV EDX,dword ptr [ESI + 0x74]
    s.dx = m.r32((s.si+0x00000074u));
  }
  { // 0x6a7e9b: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  { // 0x6a7e9d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6a7e9e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6a7e9f: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6a7ea4: e8673beaff CALL 0x0054ba10
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a7ea9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a7eaa: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x6a7eab: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a85a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a85a0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a85a1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6a85a3: 8b4e30 MOV ECX,dword ptr [ESI + 0x30]
    s.cx = m.r32((s.si+0x00000030u));
  }
  { // 0x6a85a6: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6a85a8: 741a JZ 0x006a85c4
    if(integer::condition("JZ",flags)) goto L006a85c4;
  }
  { // 0x6a85aa: e8f1d10000 CALL 0x006b57a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a85af: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a85b1: 741a JZ 0x006a85cd
    if(integer::condition("JZ",flags)) goto L006a85cd;
  }
  { // 0x6a85b3: 8b5674 MOV EDX,dword ptr [ESI + 0x74]
    s.dx = m.r32((s.si+0x00000074u));
  }
  { // 0x6a85b6: 8b4854 MOV ECX,dword ptr [EAX + 0x54]
    s.cx = m.r32((s.ax+0x00000054u));
  }
  { // 0x6a85b9: e8825f0200 CALL 0x006ce540
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a85be: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a85c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a85c1: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a85c4: { // 0x6a85c4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6a85c6: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6a85c8: e8735f0200 CALL 0x006ce540
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L006a85cd: { // 0x6a85cd: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a85cf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a85d0: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a8660(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a8660: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a8661: 8b7174 MOV ESI,dword ptr [ECX + 0x74]
    s.si = m.r32((s.cx+0x00000074u));
  }
  { // 0x6a8664: 83fe04 CMP ESI,0x4
    (void)integer::sub(s.si,0x00000004u,32,flags);
  }
  { // 0x6a8667: 7d35 JGE 0x006a869e
    if(integer::condition("JGE",flags)) goto L006a869e;
  }
  { // 0x6a8669: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6a866b: 7c31 JL 0x006a869e
    if(integer::condition("JL",flags)) goto L006a869e;
  }
  { // 0x6a866d: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6a866f: c1e004 SHL EAX,0x4
    s.ax = integer::shift(s.ax,0x00000004u,32,flags,integer::Shift::left);
  }
  { // 0x6a8672: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  { // 0x6a8674: 8d04c0 LEA EAX,[EAX + EAX*0x8]
    s.ax = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x6a8677: 8d0446 LEA EAX,[ESI + EAX*0x2]
    s.ax = (s.si+(s.ax * 0x00000002u));
  }
  { // 0x6a867a: 8d0c40 LEA ECX,[EAX + EAX*0x2]
    s.cx = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x6a867d: 8d0c8d60bd8100 LEA ECX,[ECX*0x4 + 0x81bd60]
    s.cx = ((s.cx * 0x00000004u)+0x0081bd60u);
  }
  { // 0x6a8684: e807e8fcff CALL 0x00676e90
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a8689: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6a868b: 7411 JZ 0x006a869e
    if(integer::condition("JZ",flags)) goto L006a869e;
  }
  { // 0x6a868d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a868e: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6a8693: e8b8aafcff CALL 0x00673150
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a8698: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6a869a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a869b: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
  L006a869e: { // 0x6a869e: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6a86a0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a86a1: c21000 RET 0x10
    finish(m,s,f,16u); return;
  }
}
void f_002a9380(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6a9380: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6a9381: 8b356079aa00 MOV ESI,dword ptr [0x00aa7960]
    s.si = m.r32((0x00aa7960u));
  }
  { // 0x6a9387: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a9388: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6a938a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6a938c: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6a938e: 7e15 JLE 0x006a93a5
    if(integer::condition("JLE",flags)) goto L006a93a5;
  }
  { // 0x6a9390: 8b155479aa00 MOV EDX,dword ptr [0x00aa7954]
    s.dx = m.r32((0x00aa7954u));
  }
  L006a9396: { // 0x6a9396: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x6a9398: 397824 CMP dword ptr [EAX + 0x24],EDI
    (void)integer::sub(m.r32((s.ax+0x00000024u)),s.di,32,flags);
  }
  { // 0x6a939b: 7423 JZ 0x006a93c0
    if(integer::condition("JZ",flags)) goto L006a93c0;
  }
  { // 0x6a939d: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x6a939e: 83c204 ADD EDX,0x4
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  { // 0x6a93a1: 3bce CMP ECX,ESI
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  { // 0x6a93a3: 7cf1 JL 0x006a9396
    if(integer::condition("JL",flags)) goto L006a9396;
  }
  L006a93a5: { // 0x6a93a5: 6a38 PUSH 0x38
    f.push(m,0x00000038u);
  }
  { // 0x6a93a7: e8ab450c00 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6a93ac: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6a93af: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6a93b1: 740b JZ 0x006a93be
    if(integer::condition("JZ",flags)) goto L006a93be;
  }
  { // 0x6a93b3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6a93b4: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6a93b6: e805fbffff CALL 0x006a8ec0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6a93bb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a93bc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a93bd: c3 RET
    finish(m,s,f,0u); return;
  }
  L006a93be: { // 0x6a93be: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L006a93c0: { // 0x6a93c0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6a93c1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6a93c2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002affe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6affe0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6affe3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6affe4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6affe6: 8a467f MOV AL,byte ptr [ESI + 0x7f]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007fu)));
  }
  { // 0x6affe9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6affeb: 744e JZ 0x006b003b
    if(integer::condition("JZ",flags)) goto L006b003b;
  }
  { // 0x6affed: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6afff0: e8fbf8faff CALL 0x0065f8f0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6afff5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6afff7: 7442 JZ 0x006b003b
    if(integer::condition("JZ",flags)) goto L006b003b;
  }
  { // 0x6afff9: 8b4e28 MOV ECX,dword ptr [ESI + 0x28]
    s.cx = m.r32((s.si+0x00000028u));
  }
  { // 0x6afffc: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  { // 0x6b0000: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b0001: e81af8faff CALL 0x0065f820
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6b0006: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6b0008: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  { // 0x6b000a: 83f803 CMP EAX,0x3
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  { // 0x6b000d: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  { // 0x6b0010: 7529 JNZ 0x006b003b
    if(integer::condition("JNZ",flags)) goto L006b003b;
  }
  { // 0x6b0012: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6b0014: 8d542408 LEA EDX,[ESP + 0x8]
    s.dx = (f.sp+0x00000008u);
  }
  { // 0x6b0018: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6b0019: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  { // 0x6b001f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6b0020: e80ba1faff CALL 0x0065a130
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6b0025: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b0026: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6b002b: e82074eaff CALL 0x00557450
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x6b0030: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b0032: 7507 JNZ 0x006b003b
    if(integer::condition("JNZ",flags)) goto L006b003b;
  }
  { // 0x6b0034: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6b0036: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b0037: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b003a: c3 RET
    finish(m,s,f,0u); return;
  }
  L006b003b: { // 0x6b003b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6b003d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b003e: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6b0041: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002b1ab0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1ab0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1ab1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b1ab3: e8d8d6e6ff CALL 0x0051f190
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6b1ab8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b1aba: 7520 JNZ 0x006b1adc
    if(integer::condition("JNZ",flags)) goto L006b1adc;
  }
  { // 0x6b1abc: a1587baa00 MOV EAX,[0x00aa7b58]
    s.ax = m.r32((0x00aa7b58u));
  }
  { // 0x6b1ac1: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  { // 0x6b1ac7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6b1ac9: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6b1aca: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x6b1ace: 8b91e8130000 MOV EDX,dword ptr [ECX + 0x13e8]
    s.dx = m.r32((s.cx+0x000013e8u));
  }
  { // 0x6b1ad4: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x6b1ad7: e894d3e6ff CALL 0x0051ee70
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006b1adc: { // 0x6b1adc: c6868000000001 MOV byte ptr [ESI + 0x80],0x1
    m.w8((s.si+0x00000080u), 0x00000001u);
  }
  { // 0x6b1ae3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1ae4: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002b1af0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6b1af0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6b1af1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6b1af3: e898d6e6ff CALL 0x0051f190
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6b1af8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6b1afa: 7405 JZ 0x006b1b01
    if(integer::condition("JZ",flags)) goto L006b1b01;
  }
  { // 0x6b1afc: e8efd5e6ff CALL 0x0051f0f0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006b1b01: { // 0x6b1b01: c6868000000001 MOV byte ptr [ESI + 0x80],0x1
    m.w8((s.si+0x00000080u), 0x00000001u);
  }
  { // 0x6b1b08: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6b1b09: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002d7a50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6d7a50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6d7a51: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6d7a52: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6d7a54: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x6d7a56: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6d7a59: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x6d7a5b: 7412 JZ 0x006d7a6f
    if(integer::condition("JZ",flags)) goto L006d7a6f;
  }
  { // 0x6d7a5d: 889804020000 MOV byte ptr [EAX + 0x204],BL
    m.w8((s.ax+0x00000204u), (s.bx & 0xffu));
  }
  { // 0x6d7a63: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6d7a66: 89980c020000 MOV dword ptr [EAX + 0x20c],EBX
    m.w32((s.ax+0x0000020cu), s.bx);
  }
  { // 0x6d7a6c: 895e28 MOV dword ptr [ESI + 0x28],EBX
    m.w32((s.si+0x00000028u), s.bx);
  }
  L006d7a6f: { // 0x6d7a6f: 8b4644 MOV EAX,dword ptr [ESI + 0x44]
    s.ax = m.r32((s.si+0x00000044u));
  }
  { // 0x6d7a72: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x6d7a74: 7413 JZ 0x006d7a89
    if(integer::condition("JZ",flags)) goto L006d7a89;
  }
  { // 0x6d7a76: 397040 CMP dword ptr [EAX + 0x40],ESI
    (void)integer::sub(m.r32((s.ax+0x00000040u)),s.si,32,flags);
  }
  { // 0x6d7a79: 7503 JNZ 0x006d7a7e
    if(integer::condition("JNZ",flags)) goto L006d7a7e;
  }
  { // 0x6d7a7b: 895840 MOV dword ptr [EAX + 0x40],EBX
    m.w32((s.ax+0x00000040u), s.bx);
  }
  L006d7a7e: { // 0x6d7a7e: 8b4e44 MOV ECX,dword ptr [ESI + 0x44]
    s.cx = m.r32((s.si+0x00000044u));
  }
  { // 0x6d7a81: e85a000000 CALL 0x006d7ae0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6d7a86: 895e44 MOV dword ptr [ESI + 0x44],EBX
    m.w32((s.si+0x00000044u), s.bx);
  }
  L006d7a89: { // 0x6d7a89: 8b4640 MOV EAX,dword ptr [ESI + 0x40]
    s.ax = m.r32((s.si+0x00000040u));
  }
  { // 0x6d7a8c: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  { // 0x6d7a8e: 7413 JZ 0x006d7aa3
    if(integer::condition("JZ",flags)) goto L006d7aa3;
  }
  { // 0x6d7a90: 397044 CMP dword ptr [EAX + 0x44],ESI
    (void)integer::sub(m.r32((s.ax+0x00000044u)),s.si,32,flags);
  }
  { // 0x6d7a93: 7503 JNZ 0x006d7a98
    if(integer::condition("JNZ",flags)) goto L006d7a98;
  }
  { // 0x6d7a95: 895844 MOV dword ptr [EAX + 0x44],EBX
    m.w32((s.ax+0x00000044u), s.bx);
  }
  L006d7a98: { // 0x6d7a98: 8b4e40 MOV ECX,dword ptr [ESI + 0x40]
    s.cx = m.r32((s.si+0x00000040u));
  }
  { // 0x6d7a9b: e840000000 CALL 0x006d7ae0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6d7aa0: 895e40 MOV dword ptr [ESI + 0x40],EBX
    m.w32((s.si+0x00000040u), s.bx);
  }
  L006d7aa3: { // 0x6d7aa3: 895e44 MOV dword ptr [ESI + 0x44],EBX
    m.w32((s.si+0x00000044u), s.bx);
  }
  { // 0x6d7aa6: 895e40 MOV dword ptr [ESI + 0x40],EBX
    m.w32((s.si+0x00000040u), s.bx);
  }
  { // 0x6d7aa9: 895e3c MOV dword ptr [ESI + 0x3c],EBX
    m.w32((s.si+0x0000003cu), s.bx);
  }
  { // 0x6d7aac: 895e38 MOV dword ptr [ESI + 0x38],EBX
    m.w32((s.si+0x00000038u), s.bx);
  }
  { // 0x6d7aaf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6d7ab0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6d7ab1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002da820(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6da820: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6da821: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6da823: 68c8000000 PUSH 0xc8
    f.push(m,0x000000c8u);
  }
  { // 0x6da828: e82a310900 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6da82d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6da830: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6da832: 7417 JZ 0x006da84b
    if(integer::condition("JZ",flags)) goto L006da84b;
  }
  { // 0x6da834: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6da838: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6da839: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6da83a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6da83c: e84fdeffff CALL 0x006d8690
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6da841: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6da843: 7406 JZ 0x006da84b
    if(integer::condition("JZ",flags)) goto L006da84b;
  }
  { // 0x6da845: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6da847: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6da848: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
  L006da84b: { // 0x6da84b: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6da84d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6da84e: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_002da860(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6da860: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6da861: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6da863: 68c8000000 PUSH 0xc8
    f.push(m,0x000000c8u);
  }
  { // 0x6da868: e8ea300900 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6da86d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6da870: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6da872: 7411 JZ 0x006da885
    if(integer::condition("JZ",flags)) goto L006da885;
  }
  { // 0x6da874: 68ec7eaa00 PUSH 0xaa7eec
    f.push(m,0x00aa7eecu);
  }
  { // 0x6da879: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6da87a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6da87c: e80fdeffff CALL 0x006d8690
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6da881: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6da882: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006da885: { // 0x6da885: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6da887: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6da888: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002dbbc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dbbc0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6dbbc1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dbbc2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6dbbc3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6dbbc5: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  { // 0x6dbbca: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6dbbcc: c7463400000000 MOV dword ptr [ESI + 0x34],0x0
    m.w32((s.si+0x00000034u), 0x00000000u);
  }
  { // 0x6dbbd3: e82a2c0900 CALL 0x0076e802
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6dbbd8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6dbbd9: e85f2b0900 CALL 0x0076e73d
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6dbbde: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  { // 0x6dbbe3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6dbbe5: 89462c MOV dword ptr [ESI + 0x2c],EAX
    m.w32((s.si+0x0000002cu), s.ax);
  }
  { // 0x6dbbe8: e8152c0900 CALL 0x0076e802
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6dbbed: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6dbbee: e84a2b0900 CALL 0x0076e73d
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x6dbbf3: 6850997b00 PUSH 0x7b9950
    f.push(m,0x007b9950u);
  }
  { // 0x6dbbf8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6dbbfa: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x6dbbfc: e8012c0900 CALL 0x0076e802
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x6dbc01: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x6dbc03: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6dbc04: e8342b0900 CALL 0x0076e73d
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x6dbc09: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6dbc0b: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  { // 0x6dbc0e: 83e900 SUB ECX,0x0
    s.cx = integer::sub(s.cx,0x00000000u,32,flags);
  }
  { // 0x6dbc11: 7411 JZ 0x006dbc24
    if(integer::condition("JZ",flags)) goto L006dbc24;
  }
  { // 0x6dbc13: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x6dbc14: 7511 JNZ 0x006dbc27
    if(integer::condition("JNZ",flags)) goto L006dbc27;
  }
  { // 0x6dbc16: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6dbc18: e8938cfdff CALL 0x006b48b0
    invoke(m,s,f,op,6u); flags=0x202u;
  }
  { // 0x6dbc1d: 894630 MOV dword ptr [ESI + 0x30],EAX
    m.w32((s.si+0x00000030u), s.ax);
  }
  { // 0x6dbc20: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6dbc21: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dbc22: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6dbc23: c3 RET
    finish(m,s,f,0u); return;
  }
  L006dbc24: { // 0x6dbc24: 894634 MOV dword ptr [ESI + 0x34],EAX
    m.w32((s.si+0x00000034u), s.ax);
  }
  L006dbc27: { // 0x6dbc27: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6dbc28: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dbc29: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6dbc2a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002dd590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dd590: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dd591: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6dd593: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dd596: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6dd598: 7428 JZ 0x006dd5c2
    if(integer::condition("JZ",flags)) goto L006dd5c2;
  }
  { // 0x6dd59a: 8a4611 MOV AL,byte ptr [ESI + 0x11]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000011u)));
  }
  { // 0x6dd59d: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6dd59f: 7411 JZ 0x006dd5b2
    if(integer::condition("JZ",flags)) goto L006dd5b2;
  }
  { // 0x6dd5a1: e84aaad2ff CALL 0x00407ff0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6dd5a6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dd5a8: 7508 JNZ 0x006dd5b2
    if(integer::condition("JNZ",flags)) goto L006dd5b2;
  }
  { // 0x6dd5aa: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dd5ad: e8aea8d2ff CALL 0x00407e60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006dd5b2: { // 0x6dd5b2: 8b4e2c MOV ECX,dword ptr [ESI + 0x2c]
    s.cx = m.r32((s.si+0x0000002cu));
  }
  { // 0x6dd5b5: e8d6a9d2ff CALL 0x00407f90
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6dd5ba: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x6dd5bc: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x6dd5be: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dd5bf: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x6dd5c1: c3 RET
    finish(m,s,f,0u); return;
  }
  L006dd5c2: { // 0x6dd5c2: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x6dd5c4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dd5c5: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e2810(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e2810: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2811: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e2813: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2816: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e2819: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e281b: 7423 JZ 0x006e2840
    if(integer::condition("JZ",flags)) goto L006e2840;
  }
  { // 0x6e281d: e87e0c0000 CALL 0x006e34a0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e2822: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2824: 7513 JNZ 0x006e2839
    if(integer::condition("JNZ",flags)) goto L006e2839;
  }
  { // 0x6e2826: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2829: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  { // 0x6e282c: e86f0c0000 CALL 0x006e34a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e2831: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2833: 7504 JNZ 0x006e2839
    if(integer::condition("JNZ",flags)) goto L006e2839;
  }
  { // 0x6e2835: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e2837: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2838: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e2839: { // 0x6e2839: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6e283e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e283f: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e2840: { // 0x6e2840: e85b0c0000 CALL 0x006e34a0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6e2845: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2846: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e2850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e2850: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2851: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e2853: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2856: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e2859: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e285b: 7423 JZ 0x006e2880
    if(integer::condition("JZ",flags)) goto L006e2880;
  }
  { // 0x6e285d: e86e0c0000 CALL 0x006e34d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e2862: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2864: 7513 JNZ 0x006e2879
    if(integer::condition("JNZ",flags)) goto L006e2879;
  }
  { // 0x6e2866: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2869: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  { // 0x6e286c: e85f0c0000 CALL 0x006e34d0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e2871: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e2873: 7504 JNZ 0x006e2879
    if(integer::condition("JNZ",flags)) goto L006e2879;
  }
  { // 0x6e2875: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e2877: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2878: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e2879: { // 0x6e2879: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6e287e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e287f: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e2880: { // 0x6e2880: e84b0c0000 CALL 0x006e34d0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6e2885: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2886: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e2890(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e2890: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2891: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e2893: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e2896: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e2898: 7433 JZ 0x006e28cd
    if(integer::condition("JZ",flags)) goto L006e28cd;
  }
  { // 0x6e289a: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e289d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e289e: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6e28a2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e28a3: e8580c0000 CALL 0x006e3500
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e28a8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e28aa: 7517 JNZ 0x006e28c3
    if(integer::condition("JNZ",flags)) goto L006e28c3;
  }
  { // 0x6e28ac: 8b4628 MOV EAX,dword ptr [ESI + 0x28]
    s.ax = m.r32((s.si+0x00000028u));
  }
  { // 0x6e28af: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e28b0: 8b4824 MOV ECX,dword ptr [EAX + 0x24]
    s.cx = m.r32((s.ax+0x00000024u));
  }
  { // 0x6e28b3: e8480c0000 CALL 0x006e3500
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e28b8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e28ba: 7507 JNZ 0x006e28c3
    if(integer::condition("JNZ",flags)) goto L006e28c3;
  }
  { // 0x6e28bc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e28bd: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e28bf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e28c0: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006e28c3: { // 0x6e28c3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e28c4: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6e28c9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e28ca: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006e28cd: { // 0x6e28cd: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6e28d1: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e28d2: 8b4e24 MOV ECX,dword ptr [ESI + 0x24]
    s.cx = m.r32((s.si+0x00000024u));
  }
  { // 0x6e28d5: e8260c0000 CALL 0x006e3500
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6e28da: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e28db: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e2b60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e2b60: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6e2b61: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2b62: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e2b64: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e2b66: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e2b67: 7444 JZ 0x006e2bad
    if(integer::condition("JZ",flags)) goto L006e2bad;
  }
  { // 0x6e2b69: 8b15f086a200 MOV EDX,dword ptr [0x00a286f0]
    s.dx = m.r32((0x00a286f0u));
  }
  { // 0x6e2b6f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e2b71: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x6e2b73: 7e17 JLE 0x006e2b8c
    if(integer::condition("JLE",flags)) goto L006e2b8c;
  }
  { // 0x6e2b75: 8b3de486a200 MOV EDI,dword ptr [0x00a286e4]
    s.di = m.r32((0x00a286e4u));
  }
  { // 0x6e2b7b: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L006e2b7d: { // 0x6e2b7d: 8b19 MOV EBX,dword ptr [ECX]
    s.bx = m.r32((s.cx));
  }
  { // 0x6e2b7f: 3b7324 CMP ESI,dword ptr [EBX + 0x24]
    (void)integer::sub(s.si,m.r32((s.bx+0x00000024u)),32,flags);
  }
  { // 0x6e2b82: 7422 JZ 0x006e2ba6
    if(integer::condition("JZ",flags)) goto L006e2ba6;
  }
  { // 0x6e2b84: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x6e2b85: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  { // 0x6e2b88: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x6e2b8a: 7cf1 JL 0x006e2b7d
    if(integer::condition("JL",flags)) goto L006e2b7d;
  }
  L006e2b8c: { // 0x6e2b8c: 6a44 PUSH 0x44
    f.push(m,0x00000044u);
  }
  { // 0x6e2b8e: e8c4ad0800 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e2b93: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6e2b96: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e2b98: 7413 JZ 0x006e2bad
    if(integer::condition("JZ",flags)) goto L006e2bad;
  }
  { // 0x6e2b9a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e2b9b: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6e2b9d: e83ef9ffff CALL 0x006e24e0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e2ba2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e2ba3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2ba4: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e2ba5: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e2ba6: { // 0x6e2ba6: 8b0487 MOV EAX,dword ptr [EDI + EAX*0x4]
    s.ax = m.r32((s.di+(s.ax * 0x00000004u)));
  }
  { // 0x6e2ba9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e2baa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2bab: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e2bac: c3 RET
    finish(m,s,f,0u); return;
  }
  L006e2bad: { // 0x6e2bad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e2bae: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e2baf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e2bb1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6e2bb2: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e4240(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e4240: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e4241: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e4242: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6e4244: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6e4246: 7452 JZ 0x006e429a
    if(integer::condition("JZ",flags)) goto L006e429a;
  }
  { // 0x6e4248: 668b07 MOV AX,word ptr [EDI]
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  { // 0x6e424b: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x6e424d: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  { // 0x6e4250: 7420 JZ 0x006e4272
    if(integer::condition("JZ",flags)) goto L006e4272;
  }
  L006e4252: { // 0x6e4252: 663d2000 CMP AX,0x20
    (void)integer::sub((s.ax & 0xffffu),0x00000020u,16,flags);
  }
  { // 0x6e4256: 770c JA 0x006e4264
    if(integer::condition("JA",flags)) goto L006e4264;
  }
  { // 0x6e4258: 668b4602 MOV AX,word ptr [ESI + 0x2]
    s.ax = with_ax(s.ax, m.r16((s.si+0x00000002u)));
  }
  { // 0x6e425c: 83c602 ADD ESI,0x2
    s.si = integer::add(s.si,0x00000002u,32,flags);
  }
  { // 0x6e425f: 6685c0 TEST AX,AX
    (void)integer::logical(((s.ax & 0xffffu))&((s.ax & 0xffffu)),16,flags);
  }
  { // 0x6e4262: 75ee JNZ 0x006e4252
    if(integer::condition("JNZ",flags)) goto L006e4252;
  }
  L006e4264: { // 0x6e4264: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x6e4266: 740a JZ 0x006e4272
    if(integer::condition("JZ",flags)) goto L006e4272;
  }
  { // 0x6e4268: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e4269: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e426a: e85aad0800 CALL 0x0076efc9
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e426f: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006e4272: { // 0x6e4272: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e4273: e8cdac0800 CALL 0x0076ef45
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e4278: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6e427b: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x6e427c: 781c JS 0x006e429a
    if(integer::condition("JS",flags)) goto L006e429a;
  }
  { // 0x6e427e: 8d0c47 LEA ECX,[EDI + EAX*0x2]
    s.cx = (s.di+(s.ax * 0x00000002u));
  }
  L006e4281: { // 0x6e4281: 66833e00 CMP word ptr [ESI],0x0
    (void)integer::sub(m.r16((s.si)),0x00000000u,16,flags);
  }
  { // 0x6e4285: 7413 JZ 0x006e429a
    if(integer::condition("JZ",flags)) goto L006e429a;
  }
  { // 0x6e4287: 66833920 CMP word ptr [ECX],0x20
    (void)integer::sub(m.r16((s.cx)),0x00000020u,16,flags);
  }
  { // 0x6e428b: 770d JA 0x006e429a
    if(integer::condition("JA",flags)) goto L006e429a;
  }
  { // 0x6e428d: 66c7010000 MOV word ptr [ECX],0x0
    m.w16((s.cx), 0x00000000u);
  }
  { // 0x6e4292: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x6e4293: 83e902 SUB ECX,0x2
    s.cx = integer::sub(s.cx,0x00000002u,32,flags);
  }
  { // 0x6e4296: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e4298: 7de7 JGE 0x006e4281
    if(integer::condition("JGE",flags)) goto L006e4281;
  }
  L006e429a: { // 0x6e429a: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x6e429c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e429d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e429e: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e7580(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e7580: a1d48baa00 MOV EAX,[0x00aa8bd4]
    s.ax = m.r32((0x00aa8bd4u));
  }
  { // 0x6e7585: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e7586: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e7588: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e758a: 7515 JNZ 0x006e75a1
    if(integer::condition("JNZ",flags)) goto L006e75a1;
  }
  { // 0x6e758c: 8b0d581f7e00 MOV ECX,dword ptr [0x007e1f58]
    s.cx = m.r32((0x007e1f58u));
  }
  { // 0x6e7592: 68d48baa00 PUSH 0xaa8bd4
    f.push(m,0x00aa8bd4u);
  }
  { // 0x6e7597: bad08baa00 MOV EDX,0xaa8bd0
    s.dx = 0x00aa8bd0u;
  }
  { // 0x6e759c: e8dffaffff CALL 0x006e7080
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L006e75a1: { // 0x6e75a1: a1dc8baa00 MOV EAX,[0x00aa8bdc]
    s.ax = m.r32((0x00aa8bdcu));
  }
  { // 0x6e75a6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e75a8: 751f JNZ 0x006e75c9
    if(integer::condition("JNZ",flags)) goto L006e75c9;
  }
  { // 0x6e75aa: 8b0d5c1f7e00 MOV ECX,dword ptr [0x007e1f5c]
    s.cx = m.r32((0x007e1f5cu));
  }
  { // 0x6e75b0: 68dc8baa00 PUSH 0xaa8bdc
    f.push(m,0x00aa8bdcu);
  }
  { // 0x6e75b5: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e75b7: bad88baa00 MOV EDX,0xaa8bd8
    s.dx = 0x00aa8bd8u;
  }
  { // 0x6e75bc: 7406 JZ 0x006e75c4
    if(integer::condition("JZ",flags)) goto L006e75c4;
  }
  { // 0x6e75be: 8b0d601f7e00 MOV ECX,dword ptr [0x007e1f60]
    s.cx = m.r32((0x007e1f60u));
  }
  L006e75c4: { // 0x6e75c4: e8b7faffff CALL 0x006e7080
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006e75c9: { // 0x6e75c9: a1e48baa00 MOV EAX,[0x00aa8be4]
    s.ax = m.r32((0x00aa8be4u));
  }
  { // 0x6e75ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e75cf: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6e75d1: 7515 JNZ 0x006e75e8
    if(integer::condition("JNZ",flags)) goto L006e75e8;
  }
  { // 0x6e75d3: 8b0d641f7e00 MOV ECX,dword ptr [0x007e1f64]
    s.cx = m.r32((0x007e1f64u));
  }
  { // 0x6e75d9: 68e48baa00 PUSH 0xaa8be4
    f.push(m,0x00aa8be4u);
  }
  { // 0x6e75de: bae08baa00 MOV EDX,0xaa8be0
    s.dx = 0x00aa8be0u;
  }
  { // 0x6e75e3: e898faffff CALL 0x006e7080
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L006e75e8: { // 0x6e75e8: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e7700(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e7700: a0f88baa00 MOV AL,[0x00aa8bf8]
    s.ax = with_al(s.ax, m.r8((0x00aa8bf8u)));
  }
  { // 0x6e7705: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e7706: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6e7708: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6e770a: 752b JNZ 0x006e7737
    if(integer::condition("JNZ",flags)) goto L006e7737;
  }
  { // 0x6e770c: e81f010000 CALL 0x006e7830
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e7711: 8b0d6c1f7e00 MOV ECX,dword ptr [0x007e1f6c]
    s.cx = m.r32((0x007e1f6cu));
  }
  { // 0x6e7717: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6e7719: 7406 JZ 0x006e7721
    if(integer::condition("JZ",flags)) goto L006e7721;
  }
  { // 0x6e771b: 8b0d701f7e00 MOV ECX,dword ptr [0x007e1f70]
    s.cx = m.r32((0x007e1f70u));
  }
  L006e7721: { // 0x6e7721: 68f48baa00 PUSH 0xaa8bf4
    f.push(m,0x00aa8bf4u);
  }
  { // 0x6e7726: baf08baa00 MOV EDX,0xaa8bf0
    s.dx = 0x00aa8bf0u;
  }
  { // 0x6e772b: e850f9ffff CALL 0x006e7080
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e7730: c605f88baa0001 MOV byte ptr [0x00aa8bf8],0x1
    m.w8((0x00aa8bf8u), 0x00000001u);
  }
  L006e7737: { // 0x6e7737: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e7738: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e8a10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e8a10: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x6e8a14: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8a15: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e8a16: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x6e8a18: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6e8a1a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8a1b: e820fcffff CALL 0x006e8640
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e8a20: 8b0d0c8baa00 MOV ECX,dword ptr [0x00aa8b0c]
    s.cx = m.r32((0x00aa8b0cu));
  }
  { // 0x6e8a26: 8b15bc8baa00 MOV EDX,dword ptr [0x00aa8bbc]
    s.dx = m.r32((0x00aa8bbcu));
  }
  { // 0x6e8a2c: a1188caa00 MOV EAX,[0x00aa8c18]
    s.ax = m.r32((0x00aa8c18u));
  }
  { // 0x6e8a31: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8a32: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6e8a33: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8a34: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x6e8a36: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6e8a38: e8e3feffff CALL 0x006e8920
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e8a3d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e8a3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e8a3f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002e8be0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e8be0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8be3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8be4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e8be5: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x6e8be7: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6e8be9: e8d2f8ffff CALL 0x006e84c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e8bee: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x6e8bf0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6e8bf2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6e8bf4: e847faffff CALL 0x006e8640
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e8bf9: a1508caa00 MOV EAX,[0x00aa8c50]
    s.ax = m.r32((0x00aa8c50u));
  }
  { // 0x6e8bfe: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  { // 0x6e8c06: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x6e8c0e: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6e8c10: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x6e8c14: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x6e8c17: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6e8c19: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e8c1b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c1c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8c1d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c1e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c1f: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x6e8c24: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c25: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c26: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c27: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x6e8c2c: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  { // 0x6e8c30: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8c31: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8c32: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c33: 8b0db08baa00 MOV ECX,dword ptr [0x00aa8bb0]
    s.cx = m.r32((0x00aa8bb0u));
  }
  { // 0x6e8c39: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  { // 0x6e8c3d: 8b15f48baa00 MOV EDX,dword ptr [0x00aa8bf4]
    s.dx = m.r32((0x00aa8bf4u));
  }
  { // 0x6e8c43: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8c44: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6e8c46: e8855fdbff CALL 0x0049ebd0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6e8c4b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e8c4c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e8c4d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8c50: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002e8cc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6e8cc0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8cc3: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8cc4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6e8cc5: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  { // 0x6e8cc7: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x6e8cc9: e8f2f7ffff CALL 0x006e84c0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6e8cce: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x6e8cd0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6e8cd2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6e8cd4: e867f9ffff CALL 0x006e8640
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6e8cd9: a1508caa00 MOV EAX,[0x00aa8c50]
    s.ax = m.r32((0x00aa8c50u));
  }
  { // 0x6e8cde: c744240800000000 MOV dword ptr [ESP + 0x8],0x0
    m.w32((f.sp+0x00000008u), 0x00000000u);
  }
  { // 0x6e8ce6: c744240c00000000 MOV dword ptr [ESP + 0xc],0x0
    m.w32((f.sp+0x0000000cu), 0x00000000u);
  }
  { // 0x6e8cee: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6e8cf0: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  { // 0x6e8cf4: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x6e8cf7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x6e8cf9: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6e8cfb: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8cfc: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8cfd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8cfe: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8cff: 68e8030000 PUSH 0x3e8
    f.push(m,0x000003e8u);
  }
  { // 0x6e8d04: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8d05: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8d06: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8d07: 6800040000 PUSH 0x400
    f.push(m,0x00000400u);
  }
  { // 0x6e8d0c: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  { // 0x6e8d10: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6e8d11: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6e8d12: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8d13: 8b0da88baa00 MOV ECX,dword ptr [0x00aa8ba8]
    s.cx = m.r32((0x00aa8ba8u));
  }
  { // 0x6e8d19: 8954243c MOV dword ptr [ESP + 0x3c],EDX
    m.w32((f.sp+0x0000003cu), s.dx);
  }
  { // 0x6e8d1d: 8b15008caa00 MOV EDX,dword ptr [0x00aa8c00]
    s.dx = m.r32((0x00aa8c00u));
  }
  { // 0x6e8d23: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6e8d24: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6e8d26: e8a55edbff CALL 0x0049ebd0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6e8d2b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6e8d2c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6e8d2d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6e8d30: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eb5f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eb5f0: a1b088a200 MOV EAX,[0x00a288b0]
    s.ax = m.r32((0x00a288b0u));
  }
  { // 0x6eb5f5: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eb5f6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6eb5f8: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6eb5fa: 7522 JNZ 0x006eb61e
    if(integer::condition("JNZ",flags)) goto L006eb61e;
  }
  { // 0x6eb5fc: 6831030000 PUSH 0x331
    f.push(m,0x00000331u);
  }
  { // 0x6eb601: 685c247e00 PUSH 0x7e245c
    f.push(m,0x007e245cu);
  }
  { // 0x6eb606: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6eb608: b948247e00 MOV ECX,0x7e2448
    s.cx = 0x007e2448u;
  }
  { // 0x6eb60d: e84e350000 CALL 0x006eeb60
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6eb612: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6eb613: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eb614: e8b0390800 CALL 0x0076efc9
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6eb619: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6eb61c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6eb61d: c3 RET
    finish(m,s,f,0u); return;
  }
  L006eb61e: { // 0x6eb61e: a0b98daa00 MOV AL,[0x00aa8db9]
    s.ax = with_al(s.ax, m.r8((0x00aa8db9u)));
  }
  { // 0x6eb623: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6eb625: 7422 JZ 0x006eb649
    if(integer::condition("JZ",flags)) goto L006eb649;
  }
  { // 0x6eb627: 6833030000 PUSH 0x333
    f.push(m,0x00000333u);
  }
  { // 0x6eb62c: 685c247e00 PUSH 0x7e245c
    f.push(m,0x007e245cu);
  }
  { // 0x6eb631: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6eb633: b984247e00 MOV ECX,0x7e2484
    s.cx = 0x007e2484u;
  }
  { // 0x6eb638: e823350000 CALL 0x006eeb60
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6eb63d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6eb63e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eb63f: e885390800 CALL 0x0076efc9
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  { // 0x6eb644: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6eb647: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6eb648: c3 RET
    finish(m,s,f,0u); return;
  }
  L006eb649: { // 0x6eb649: 6835030000 PUSH 0x335
    f.push(m,0x00000335u);
  }
  { // 0x6eb64e: 685c247e00 PUSH 0x7e245c
    f.push(m,0x007e245cu);
  }
  { // 0x6eb653: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x6eb655: b970247e00 MOV ECX,0x7e2470
    s.cx = 0x007e2470u;
  }
  { // 0x6eb65a: e801350000 CALL 0x006eeb60
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x6eb65f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6eb660: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eb661: e863390800 CALL 0x0076efc9
    invoke(m,s,f,op,5u); flags=0x202u;
  }
  { // 0x6eb666: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6eb669: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6eb66a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002ebfe0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ebfe0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ebfe1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ebfe3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ebfe4: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x6ebfe6: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x6ebfe8: 7441 JZ 0x006ec02b
    if(integer::condition("JZ",flags)) goto L006ec02b;
  }
  { // 0x6ebfea: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  { // 0x6ebfed: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ebfef: 743a JZ 0x006ec02b
    if(integer::condition("JZ",flags)) goto L006ec02b;
  }
  { // 0x6ebff1: a1c855a200 MOV EAX,[0x00a255c8]
    s.ax = m.r32((0x00a255c8u));
  }
  { // 0x6ebff6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ebff8: 750e JNZ 0x006ec008
    if(integer::condition("JNZ",flags)) goto L006ec008;
  }
  { // 0x6ebffa: 8b86b4010000 MOV EAX,dword ptr [ESI + 0x1b4]
    s.ax = m.r32((s.si+0x000001b4u));
  }
  { // 0x6ec000: 8a8035010000 MOV AL,byte ptr [EAX + 0x135]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000135u)));
  }
  { // 0x6ec006: eb0b JMP 0x006ec013
    goto L006ec013;
  }
  L006ec008: { // 0x6ec008: 8b8eb4010000 MOV ECX,dword ptr [ESI + 0x1b4]
    s.cx = m.r32((s.si+0x000001b4u));
  }
  { // 0x6ec00e: e89d87e0ff CALL 0x004f47b0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  L006ec013: { // 0x6ec013: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ec015: 7414 JZ 0x006ec02b
    if(integer::condition("JZ",flags)) goto L006ec02b;
  }
  { // 0x6ec017: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6ec018: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6ec01a: e841eeedff CALL 0x005cae60
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6ec01f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6ec021: 7408 JZ 0x006ec02b
    if(integer::condition("JZ",flags)) goto L006ec02b;
  }
  { // 0x6ec023: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ec024: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6ec029: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ec02a: c3 RET
    finish(m,s,f,0u); return;
  }
  L006ec02b: { // 0x6ec02b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6ec02c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6ec02e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ec02f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eec50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eec50: a1d07eab00 MOV EAX,[0x00ab7ed0]
    s.ax = m.r32((0x00ab7ed0u));
  }
  { // 0x6eec55: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eec56: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6eec58: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x6eec5a: 7416 JZ 0x006eec72
    if(integer::condition("JZ",flags)) goto L006eec72;
  }
  { // 0x6eec5c: e8cffdffff CALL 0x006eea30
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6eec61: 8b0db47eab00 MOV ECX,dword ptr [0x00ab7eb4]
    s.cx = m.r32((0x00ab7eb4u));
  }
  { // 0x6eec67: 8935d07eab00 MOV dword ptr [0x00ab7ed0],ESI
    m.w32((0x00ab7ed0u), s.si);
  }
  { // 0x6eec6d: e85eeeffff CALL 0x006edad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006eec72: { // 0x6eec72: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6eec73: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002eec80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6eec80: a138257e00 MOV EAX,[0x007e2538]
    s.ax = m.r32((0x007e2538u));
  }
  { // 0x6eec85: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6eec86: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6eec88: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x6eec8a: 7416 JZ 0x006eeca2
    if(integer::condition("JZ",flags)) goto L006eeca2;
  }
  { // 0x6eec8c: e89ffdffff CALL 0x006eea30
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6eec91: 8b0db47eab00 MOV ECX,dword ptr [0x00ab7eb4]
    s.cx = m.r32((0x00ab7eb4u));
  }
  { // 0x6eec97: 893538257e00 MOV dword ptr [0x007e2538],ESI
    m.w32((0x007e2538u), s.si);
  }
  { // 0x6eec9d: e82eeeffff CALL 0x006edad0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006eeca2: { // 0x6eeca2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6eeca3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002f9360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6f9360: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6f9361: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6f9363: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6f9364: 8dbea8020000 LEA EDI,[ESI + 0x2a8]
    s.di = (s.si+0x000002a8u);
  }
  { // 0x6f936a: c686ba05000000 MOV byte ptr [ESI + 0x5ba],0x0
    m.w8((s.si+0x000005bau), 0x00000000u);
  }
  { // 0x6f9371: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6f9373: e8b8d5d9ff CALL 0x00496930
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6f9378: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6f937a: 751b JNZ 0x006f9397
    if(integer::condition("JNZ",flags)) goto L006f9397;
  }
  { // 0x6f937c: 8b86ac050000 MOV EAX,dword ptr [ESI + 0x5ac]
    s.ax = m.r32((s.si+0x000005acu));
  }
  { // 0x6f9382: 8b889c030000 MOV ECX,dword ptr [EAX + 0x39c]
    s.cx = m.r32((s.ax+0x0000039cu));
  }
  { // 0x6f9388: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6f9389: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6f938b: 8b9098030000 MOV EDX,dword ptr [EAX + 0x398]
    s.dx = m.r32((s.ax+0x00000398u));
  }
  { // 0x6f9391: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6f9392: e809d6d9ff CALL 0x004969a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006f9397: { // 0x6f9397: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6f9399: e822a2dcff CALL 0x004c35c0
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  { // 0x6f939e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6f939f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6f93a0: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002fc590(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6fc590: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc591: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x6fc595: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6fc596: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc597: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6fc59c: e8ef8ee4ff CALL 0x00545490
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6fc5a1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc5a2: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6fc5a7: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x6fc5a9: e8c2aae5ff CALL 0x00557070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6fc5ae: 8b15f87fab00 MOV EDX,dword ptr [0x00ab7ff8]
    s.dx = m.r32((0x00ab7ff8u));
  }
  { // 0x6fc5b4: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x6fc5b7: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x6fc5b9: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6fc5bb: 7f1e JG 0x006fc5db
    if(integer::condition("JG",flags)) goto L006fc5db;
  }
  { // 0x6fc5bd: 8b8740010000 MOV EAX,dword ptr [EDI + 0x140]
    s.ax = m.r32((s.di+0x00000140u));
  }
  { // 0x6fc5c3: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x6fc5c6: 7413 JZ 0x006fc5db
    if(integer::condition("JZ",flags)) goto L006fc5db;
  }
  { // 0x6fc5c8: 8b8728010000 MOV EAX,dword ptr [EDI + 0x128]
    s.ax = m.r32((s.di+0x00000128u));
  }
  { // 0x6fc5ce: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  { // 0x6fc5d0: 898728010000 MOV dword ptr [EDI + 0x128],EAX
    m.w32((s.di+0x00000128u), s.ax);
  }
  { // 0x6fc5d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6fc5d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6fc5d8: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006fc5db: { // 0x6fc5db: 8b8724010000 MOV EAX,dword ptr [EDI + 0x124]
    s.ax = m.r32((s.di+0x00000124u));
  }
  { // 0x6fc5e1: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  { // 0x6fc5e3: 898724010000 MOV dword ptr [EDI + 0x124],EAX
    m.w32((s.di+0x00000124u), s.ax);
  }
  { // 0x6fc5e9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6fc5ea: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6fc5eb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002fc5f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6fc5f0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc5f1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x6fc5f5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6fc5f6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc5f7: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6fc5fc: e88f8ee4ff CALL 0x00545490
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6fc601: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc602: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  { // 0x6fc607: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x6fc609: e862aae5ff CALL 0x00557070
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6fc60e: 8b15f87fab00 MOV EDX,dword ptr [0x00ab7ff8]
    s.dx = m.r32((0x00ab7ff8u));
  }
  { // 0x6fc614: 8b4e08 MOV ECX,dword ptr [ESI + 0x8]
    s.cx = m.r32((s.si+0x00000008u));
  }
  { // 0x6fc617: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x6fc619: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x6fc61b: 7f13 JG 0x006fc630
    if(integer::condition("JG",flags)) goto L006fc630;
  }
  { // 0x6fc61d: 8b8728010000 MOV EAX,dword ptr [EDI + 0x128]
    s.ax = m.r32((s.di+0x00000128u));
  }
  { // 0x6fc623: 24df AND AL,0xdf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000dfu),8,flags));
  }
  { // 0x6fc625: 898728010000 MOV dword ptr [EDI + 0x128],EAX
    m.w32((s.di+0x00000128u), s.ax);
  }
  { // 0x6fc62b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6fc62c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6fc62d: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006fc630: { // 0x6fc630: 8b8724010000 MOV EAX,dword ptr [EDI + 0x124]
    s.ax = m.r32((s.di+0x00000124u));
  }
  { // 0x6fc636: 24df AND AL,0xdf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000dfu),8,flags));
  }
  { // 0x6fc638: 898724010000 MOV dword ptr [EDI + 0x124],EAX
    m.w32((s.di+0x00000124u), s.ax);
  }
  { // 0x6fc63e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6fc63f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6fc640: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002fc9c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6fc9c0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc9c1: 8b742408 MOV ESI,dword ptr [ESP + 0x8]
    s.si = m.r32((f.sp+0x00000008u));
  }
  { // 0x6fc9c5: 8b8ec4050000 MOV ECX,dword ptr [ESI + 0x5c4]
    s.cx = m.r32((s.si+0x000005c4u));
  }
  { // 0x6fc9cb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6fc9cd: 740f JZ 0x006fc9de
    if(integer::condition("JZ",flags)) goto L006fc9de;
  }
  { // 0x6fc9cf: e8fc58dbff CALL 0x004b22d0
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6fc9d4: c786c405000000000000 MOV dword ptr [ESI + 0x5c4],0x0
    m.w32((s.si+0x000005c4u), 0x00000000u);
  }
  L006fc9de: { // 0x6fc9de: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x6fc9e2: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6fc9e6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6fc9e7: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6fc9e8: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fc9e9: e8f2d1dcff CALL 0x004c9be0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6fc9ee: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6fc9ef: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_002fcae0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6fcae0: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fcae1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6fcae3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6fcae4: 8b7c240c MOV EDI,dword ptr [ESP + 0xc]
    s.di = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6fcae8: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x6fcaeb: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6fcaed: 745e JZ 0x006fcb4d
    if(integer::condition("JZ",flags)) goto L006fcb4d;
  }
  { // 0x6fcaef: 83be90020000ff CMP dword ptr [ESI + 0x290],-0x1
    (void)integer::sub(m.r32((s.si+0x00000290u)),0xffffffffu,32,flags);
  }
  { // 0x6fcaf6: 7409 JZ 0x006fcb01
    if(integer::condition("JZ",flags)) goto L006fcb01;
  }
  { // 0x6fcaf8: e843cdfaff CALL 0x006a9840
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6fcafd: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6fcaff: 754c JNZ 0x006fcb4d
    if(integer::condition("JNZ",flags)) goto L006fcb4d;
  }
  L006fcb01: { // 0x6fcb01: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x6fcb03: 7415 JZ 0x006fcb1a
    if(integer::condition("JZ",flags)) goto L006fcb1a;
  }
  { // 0x6fcb05: a1087fab00 MOV EAX,[0x00ab7f08]
    s.ax = m.r32((0x00ab7f08u));
  }
  { // 0x6fcb0a: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x6fcb0d: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6fcb0f: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6fcb11: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6fcb12: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fcb13: 6a07 PUSH 0x7
    f.push(m,0x00000007u);
  }
  { // 0x6fcb15: e826c9faff CALL 0x006a9440
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  L006fcb1a: { // 0x6fcb1a: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x6fcb1d: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6fcb1f: 7413 JZ 0x006fcb34
    if(integer::condition("JZ",flags)) goto L006fcb34;
  }
  { // 0x6fcb21: 8b15087fab00 MOV EDX,dword ptr [0x00ab7f08]
    s.dx = m.r32((0x00ab7f08u));
  }
  { // 0x6fcb27: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6fcb29: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6fcb2b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6fcb2c: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fcb2d: 6a30 PUSH 0x30
    f.push(m,0x00000030u);
  }
  { // 0x6fcb2f: e80cc9faff CALL 0x006a9440
    invoke(m,s,f,op,2u); flags=0x202u;
  }
  L006fcb34: { // 0x6fcb34: 8b4e34 MOV ECX,dword ptr [ESI + 0x34]
    s.cx = m.r32((s.si+0x00000034u));
  }
  { // 0x6fcb37: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x6fcb39: 7412 JZ 0x006fcb4d
    if(integer::condition("JZ",flags)) goto L006fcb4d;
  }
  { // 0x6fcb3b: a1087fab00 MOV EAX,[0x00ab7f08]
    s.ax = m.r32((0x00ab7f08u));
  }
  { // 0x6fcb40: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6fcb42: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6fcb44: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6fcb45: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6fcb46: 6a1d PUSH 0x1d
    f.push(m,0x0000001du);
  }
  { // 0x6fcb48: e8f3c8faff CALL 0x006a9440
    invoke(m,s,f,op,3u); flags=0x202u;
  }
  L006fcb4d: { // 0x6fcb4d: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6fcb4e: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6fcb50: e8ab77fcff CALL 0x006c4300
    invoke(m,s,f,op,4u); flags=0x202u;
  }
  { // 0x6fcb55: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6fcb56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6fcb57: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002ff640(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6ff640: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ff641: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6ff643: 68d0070000 PUSH 0x7d0
    f.push(m,0x000007d0u);
  }
  { // 0x6ff648: e80ae30600 CALL 0x0076d957
    invoke(m,s,f,op,0u); flags=0x202u;
  }
  { // 0x6ff64d: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x6ff650: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6ff652: 7411 JZ 0x006ff665
    if(integer::condition("JZ",flags)) goto L006ff665;
  }
  { // 0x6ff654: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x6ff658: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6ff659: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6ff65a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6ff65c: e83ffafeff CALL 0x006ef0a0
    invoke(m,s,f,op,1u); flags=0x202u;
  }
  { // 0x6ff661: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ff662: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006ff665: { // 0x6ff665: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6ff667: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6ff668: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
} // namespace
const std::array<Entry,137>& entries_b() {
  static const std::array<Entry,137> entries{{
    {0x13d140u,f_0013d140},
    {0x13d1f0u,f_0013d1f0},
    {0x13d3e0u,f_0013d3e0},
    {0x173dd0u,f_00173dd0},
    {0x1803f0u,f_001803f0},
    {0x18cac0u,f_0018cac0},
    {0x18cba0u,f_0018cba0},
    {0x190110u,f_00190110},
    {0x191f30u,f_00191f30},
    {0x1929f0u,f_001929f0},
    {0x19b5e0u,f_0019b5e0},
    {0x19c2e0u,f_0019c2e0},
    {0x19d8b0u,f_0019d8b0},
    {0x19d900u,f_0019d900},
    {0x19e260u,f_0019e260},
    {0x19e550u,f_0019e550},
    {0x19e6f0u,f_0019e6f0},
    {0x19e940u,f_0019e940},
    {0x19ed50u,f_0019ed50},
    {0x19f310u,f_0019f310},
    {0x1a0600u,f_001a0600},
    {0x1a1bc0u,f_001a1bc0},
    {0x1a4020u,f_001a4020},
    {0x1a73a0u,f_001a73a0},
    {0x1a89a0u,f_001a89a0},
    {0x1a8a40u,f_001a8a40},
    {0x1a9280u,f_001a9280},
    {0x1a9990u,f_001a9990},
    {0x1aa580u,f_001aa580},
    {0x1ab060u,f_001ab060},
    {0x1ac990u,f_001ac990},
    {0x1aca30u,f_001aca30},
    {0x1aca60u,f_001aca60},
    {0x1b34c0u,f_001b34c0},
    {0x1b64b0u,f_001b64b0},
    {0x1b66d0u,f_001b66d0},
    {0x1b7630u,f_001b7630},
    {0x1c2560u,f_001c2560},
    {0x1c2580u,f_001c2580},
    {0x1c3310u,f_001c3310},
    {0x1c5ba0u,f_001c5ba0},
    {0x1c61d0u,f_001c61d0},
    {0x1c6220u,f_001c6220},
    {0x1c6360u,f_001c6360},
    {0x1ccdf0u,f_001ccdf0},
    {0x1ccff0u,f_001ccff0},
    {0x1cd070u,f_001cd070},
    {0x1cd0f0u,f_001cd0f0},
    {0x1d4ef0u,f_001d4ef0},
    {0x1d4f30u,f_001d4f30},
    {0x1d6f90u,f_001d6f90},
    {0x1f7d70u,f_001f7d70},
    {0x1f81b0u,f_001f81b0},
    {0x1f90c0u,f_001f90c0},
    {0x1f9430u,f_001f9430},
    {0x1fbb80u,f_001fbb80},
    {0x206920u,f_00206920},
    {0x2069c0u,f_002069c0},
    {0x207600u,f_00207600},
    {0x207950u,f_00207950},
    {0x2079b0u,f_002079b0},
    {0x207d30u,f_00207d30},
    {0x208da0u,f_00208da0},
    {0x20ea50u,f_0020ea50},
    {0x20eb30u,f_0020eb30},
    {0x20ebb0u,f_0020ebb0},
    {0x214030u,f_00214030},
    {0x2140b0u,f_002140b0},
    {0x214140u,f_00214140},
    {0x214160u,f_00214160},
    {0x214da0u,f_00214da0},
    {0x216ae0u,f_00216ae0},
    {0x2345a0u,f_002345a0},
    {0x236130u,f_00236130},
    {0x244bc0u,f_00244bc0},
    {0x2497d0u,f_002497d0},
    {0x24ae40u,f_0024ae40},
    {0x24ae90u,f_0024ae90},
    {0x24aee0u,f_0024aee0},
    {0x24b100u,f_0024b100},
    {0x24b150u,f_0024b150},
    {0x24b1a0u,f_0024b1a0},
    {0x25f230u,f_0025f230},
    {0x2605e0u,f_002605e0},
    {0x267120u,f_00267120},
    {0x268250u,f_00268250},
    {0x26aa70u,f_0026aa70},
    {0x26ad00u,f_0026ad00},
    {0x26ad40u,f_0026ad40},
    {0x274590u,f_00274590},
    {0x276d60u,f_00276d60},
    {0x276db0u,f_00276db0},
    {0x27d7d0u,f_0027d7d0},
    {0x28df20u,f_0028df20},
    {0x28e190u,f_0028e190},
    {0x2907c0u,f_002907c0},
    {0x295100u,f_00295100},
    {0x2968b0u,f_002968b0},
    {0x297d00u,f_00297d00},
    {0x29bc80u,f_0029bc80},
    {0x2a1e50u,f_002a1e50},
    {0x2a4fa0u,f_002a4fa0},
    {0x2a6490u,f_002a6490},
    {0x2a70d0u,f_002a70d0},
    {0x2a7920u,f_002a7920},
    {0x2a7e80u,f_002a7e80},
    {0x2a85a0u,f_002a85a0},
    {0x2a8660u,f_002a8660},
    {0x2a9380u,f_002a9380},
    {0x2affe0u,f_002affe0},
    {0x2b1ab0u,f_002b1ab0},
    {0x2b1af0u,f_002b1af0},
    {0x2d7a50u,f_002d7a50},
    {0x2da820u,f_002da820},
    {0x2da860u,f_002da860},
    {0x2dbbc0u,f_002dbbc0},
    {0x2dd590u,f_002dd590},
    {0x2e2810u,f_002e2810},
    {0x2e2850u,f_002e2850},
    {0x2e2890u,f_002e2890},
    {0x2e2b60u,f_002e2b60},
    {0x2e4240u,f_002e4240},
    {0x2e7580u,f_002e7580},
    {0x2e7700u,f_002e7700},
    {0x2e8a10u,f_002e8a10},
    {0x2e8be0u,f_002e8be0},
    {0x2e8cc0u,f_002e8cc0},
    {0x2eb5f0u,f_002eb5f0},
    {0x2ebfe0u,f_002ebfe0},
    {0x2eec50u,f_002eec50},
    {0x2eec80u,f_002eec80},
    {0x2f9360u,f_002f9360},
    {0x2fc590u,f_002fc590},
    {0x2fc5f0u,f_002fc5f0},
    {0x2fc9c0u,f_002fc9c0},
    {0x2fcae0u,f_002fcae0},
    {0x2ff640u,f_002ff640},
  }}; return entries;
}
} // namespace ra2::recovered::direct_b34
