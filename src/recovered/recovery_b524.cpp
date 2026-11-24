#include "recovered/recovery_b108_machine.hpp"
#include "recovered/map_b87.hpp"
#include "recovered/recovery_b460.hpp"
#include <stdexcept>
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_primitives.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::global_b26 {
std::uint32_t fun_0058a810(Memory&,const Inputs&); std::uint32_t fun_0056b760(Memory&,const Inputs&);
std::uint32_t fun_00545500(Memory&,const Inputs&); std::uint32_t fun_00572ad0(Memory&,const Inputs&);
}
namespace ra2::recovered::raster524 {
using namespace ra2::recovered::recovery_b108;
namespace integer=direct_b33::integer;
static std::uint32_t b516_pc=0;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00171c40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00571c40: { // 0x571c40: 83ec2c SUB ESP,0x2c
    b516_pc=0x571c40u;
    f.sp = integer::sub(f.sp,0x0000002cu,32,flags);
  }
  L00571c43: { // 0x571c43: 53 PUSH EBX
    b516_pc=0x571c43u;
    f.push(m,s.bx);
  }
  L00571c44: { // 0x571c44: 55 PUSH EBP
    b516_pc=0x571c44u;
    f.push(m,s.bp);
  }
  L00571c45: { // 0x571c45: 8b6c243c MOV EBP,dword ptr [ESP + 0x3c]
    b516_pc=0x571c45u;
    s.bp = m.r32((f.sp+0x0000003cu));
  }
  L00571c49: { // 0x571c49: 56 PUSH ESI
    b516_pc=0x571c49u;
    f.push(m,s.si);
  }
  L00571c4a: { // 0x571c4a: 57 PUSH EDI
    b516_pc=0x571c4au;
    f.push(m,s.di);
  }
  L00571c4b: { // 0x571c4b: 8b7c2440 MOV EDI,dword ptr [ESP + 0x40]
    b516_pc=0x571c4bu;
    s.di = m.r32((f.sp+0x00000040u));
  }
  L00571c4f: { // 0x571c4f: 0fbf7500 MOVSX ESI,word ptr [EBP]
    b516_pc=0x571c4fu;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00571c53: { // 0x571c53: 0fbf07 MOVSX EAX,word ptr [EDI]
    b516_pc=0x571c53u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00571c56: { // 0x571c56: 2bc6 SUB EAX,ESI
    b516_pc=0x571c56u;
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00571c58: { // 0x571c58: 8bd9 MOV EBX,ECX
    b516_pc=0x571c58u;
    s.bx = s.cx;
  }
  L00571c5a: { // 0x571c5a: 83f803 CMP EAX,0x3
    b516_pc=0x571c5au;
    (void)integer::sub(s.ax,0x00000003u,32,flags);
  }
  L00571c5d: { // 0x571c5d: 895c2410 MOV dword ptr [ESP + 0x10],EBX
    b516_pc=0x571c5du;
    m.w32((f.sp+0x00000010u), s.bx);
  }
  L00571c61: { // 0x571c61: 0f8c5f050000 JL 0x005721c6
    b516_pc=0x571c61u;
    if(integer::condition("JL",flags)) goto L005721c6;
  }
  L00571c67: { // 0x571c67: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    b516_pc=0x571c67u;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00571c6b: { // 0x571c6b: 0fbf4d02 MOVSX ECX,word ptr [EBP + 0x2]
    b516_pc=0x571c6bu;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00571c6f: { // 0x571c6f: 2bca SUB ECX,EDX
    b516_pc=0x571c6fu;
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00571c71: { // 0x571c71: 83f903 CMP ECX,0x3
    b516_pc=0x571c71u;
    (void)integer::sub(s.cx,0x00000003u,32,flags);
  }
  L00571c74: { // 0x571c74: 0f8c4c050000 JL 0x005721c6
    b516_pc=0x571c74u;
    if(integer::condition("JL",flags)) goto L005721c6;
  }
  L00571c7a: { // 0x571c7a: 83c00a ADD EAX,0xa
    b516_pc=0x571c7au;
    s.ax = integer::add(s.ax,0x0000000au,32,flags);
  }
  L00571c7d: { // 0x571c7d: 83c10a ADD ECX,0xa
    b516_pc=0x571c7du;
    s.cx = integer::add(s.cx,0x0000000au,32,flags);
  }
  L00571c80: { // 0x571c80: 89442424 MOV dword ptr [ESP + 0x24],EAX
    b516_pc=0x571c80u;
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00571c84: { // 0x571c84: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x571c84u;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00571c88: { // 0x571c88: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    b516_pc=0x571c88u;
    m.w32((f.sp+0x00000028u), s.cx);
  }
  L00571c8c: { // 0x571c8c: 8d4c241c LEA ECX,[ESP + 0x1c]
    b516_pc=0x571c8cu;
    s.cx = (f.sp+0x0000001cu);
  }
  L00571c90: { // 0x571c90: 50 PUSH EAX
    b516_pc=0x571c90u;
    f.push(m,s.ax);
  }
  L00571c91: { // 0x571c91: 83c6f9 ADD ESI,-0x7
    b516_pc=0x571c91u;
    s.si = integer::add(s.si,0xfffffff9u,32,flags);
  }
  L00571c94: { // 0x571c94: 83c2f9 ADD EDX,-0x7
    b516_pc=0x571c94u;
    s.dx = integer::add(s.dx,0xfffffff9u,32,flags);
  }
  L00571c97: { // 0x571c97: 51 PUSH ECX
    b516_pc=0x571c97u;
    f.push(m,s.cx);
  }
  L00571c98: { // 0x571c98: 8bcb MOV ECX,EBX
    b516_pc=0x571c98u;
    s.cx = s.bx;
  }
  L00571c9a: { // 0x571c9a: 89742424 MOV dword ptr [ESP + 0x24],ESI
    b516_pc=0x571c9au;
    m.w32((f.sp+0x00000024u), s.si);
  }
  L00571c9e: { // 0x571c9e: 89542428 MOV dword ptr [ESP + 0x28],EDX
    b516_pc=0x571c9eu;
    m.w32((f.sp+0x00000028u), s.dx);
  }
  L00571ca2: { // 0x571ca2: e8590a0000 CALL 0x00572700
    b516_pc=0x571ca2u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572700u,0x00571ca7u); flags=0x202u;
  }
  L00571ca7: { // 0x571ca7: 84c0 TEST AL,AL
    b516_pc=0x571ca7u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571ca9: { // 0x571ca9: 0f8417050000 JZ 0x005721c6
    b516_pc=0x571ca9u;
    if(integer::condition("JZ",flags)) goto L005721c6;
  }
  L00571caf: { // 0x571caf: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    b516_pc=0x571cafu;
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00571cb3: { // 0x571cb3: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    b516_pc=0x571cb3u;
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00571cb7: { // 0x571cb7: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    b516_pc=0x571cb7u;
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00571cbb: { // 0x571cbb: 89442440 MOV dword ptr [ESP + 0x40],EAX
    b516_pc=0x571cbbu;
    m.w32((f.sp+0x00000040u), s.ax);
  }
  L00571cbf: { // 0x571cbf: 8d4807 LEA ECX,[EAX + 0x7]
    b516_pc=0x571cbfu;
    s.cx = (s.ax+0x00000007u);
  }
  L00571cc2: { // 0x571cc2: 3bc1 CMP EAX,ECX
    b516_pc=0x571cc2u;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00571cc4: { // 0x571cc4: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    b516_pc=0x571cc4u;
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00571cc8: { // 0x571cc8: 0f8d83000000 JGE 0x00571d51
    b516_pc=0x571cc8u;
    if(integer::condition("JGE",flags)) goto L00571d51;
  }
  L00571cce: { // 0x571cce: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    b516_pc=0x571cceu;
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00571cd2: { // 0x571cd2: 8d3411 LEA ESI,[ECX + EDX*0x1]
    b516_pc=0x571cd2u;
    s.si = (s.cx+(s.dx * 0x00000001u));
  }
  L00571cd5: { // 0x571cd5: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x571cd5u;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00571cd9: { // 0x571cd9: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x571cd9u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00571cdd: { // 0x571cdd: 8bcb MOV ECX,EBX
    b516_pc=0x571cddu;
    s.cx = s.bx;
  }
  L00571cdf: { // 0x571cdf: 3bce CMP ECX,ESI
    b516_pc=0x571cdfu;
    (void)integer::sub(s.cx,s.si,32,flags);
  }
  L00571ce1: { // 0x571ce1: 7d5d JGE 0x00571d40
    b516_pc=0x571ce1u;
    if(integer::condition("JGE",flags)) goto L00571d40;
  }
  L00571ce3: { // 0x571ce3: 668b542440 MOV DX,word ptr [ESP + 0x40]
    b516_pc=0x571ce3u;
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000040u)));
  }
  L00571ce8: { // 0x571ce8: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571ce8u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571cec: { // 0x571cec: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x571cecu;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00571cf1: { // 0x571cf1: 6689542446 MOV word ptr [ESP + 0x46],DX
    b516_pc=0x571cf1u;
    m.w16((f.sp+0x00000046u), (s.dx & 0xffffu));
  }
  L00571cf6: { // 0x571cf6: e8158b0100 CALL 0x0058a810
    b516_pc=0x571cf6u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00571cfbu); flags=0x202u;
  }
  L00571cfb: { // 0x571cfb: 84c0 TEST AL,AL
    b516_pc=0x571cfbu;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571cfd: { // 0x571cfd: 7434 JZ 0x00571d33
    b516_pc=0x571cfdu;
    if(integer::condition("JZ",flags)) goto L00571d33;
  }
  L00571cff: { // 0x571cff: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    b516_pc=0x571cffu;
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00571d03: { // 0x571d03: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571d03u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571d07: { // 0x571d07: e8549affff CALL 0x0056b760
    b516_pc=0x571d07u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571d0cu); flags=0x202u;
  }
  L00571d0c: { // 0x571d0c: 8d442444 LEA EAX,[ESP + 0x44]
    b516_pc=0x571d0cu;
    s.ax = (f.sp+0x00000044u);
  }
  L00571d10: { // 0x571d10: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571d10u;
    s.cx = 0x0081a820u;
  }
  L00571d15: { // 0x571d15: 50 PUSH EAX
    b516_pc=0x571d15u;
    f.push(m,s.ax);
  }
  L00571d16: { // 0x571d16: e8e537fdff CALL 0x00545500
    b516_pc=0x571d16u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571d1bu); flags=0x202u;
  }
  L00571d1b: { // 0x571d1b: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    b516_pc=0x571d1bu;
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00571d1f: { // 0x571d1f: 8bf0 MOV ESI,EAX
    b516_pc=0x571d1fu;
    s.si = s.ax;
  }
  L00571d21: { // 0x571d21: e8aa0d0000 CALL 0x00572ad0
    b516_pc=0x571d21u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,0x00571d26u); flags=0x202u;
  }
  L00571d26: { // 0x571d26: 8a4810 MOV CL,byte ptr [EAX + 0x10]
    b516_pc=0x571d26u;
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000010u)));
  }
  L00571d29: { // 0x571d29: 888e1b010000 MOV byte ptr [ESI + 0x11b],CL
    b516_pc=0x571d29u;
    m.w8((s.si+0x0000011bu), (s.cx & 0xffu));
  }
  L00571d2f: { // 0x571d2f: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    b516_pc=0x571d2fu;
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00571d33: { // 0x571d33: 43 INC EBX
    b516_pc=0x571d33u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571d34: { // 0x571d34: 3bde CMP EBX,ESI
    b516_pc=0x571d34u;
    (void)integer::sub(s.bx,s.si,32,flags);
  }
  L00571d36: { // 0x571d36: 7cab JL 0x00571ce3
    b516_pc=0x571d36u;
    if(integer::condition("JL",flags)) goto L00571ce3;
  }
  L00571d38: { // 0x571d38: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    b516_pc=0x571d38u;
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L00571d3c: { // 0x571d3c: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    b516_pc=0x571d3cu;
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L00571d40: { // 0x571d40: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    b516_pc=0x571d40u;
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00571d44: { // 0x571d44: 8b5c2418 MOV EBX,dword ptr [ESP + 0x18]
    b516_pc=0x571d44u;
    s.bx = m.r32((f.sp+0x00000018u));
  }
  L00571d48: { // 0x571d48: 41 INC ECX
    b516_pc=0x571d48u;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00571d49: { // 0x571d49: 3bcb CMP ECX,EBX
    b516_pc=0x571d49u;
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L00571d4b: { // 0x571d4b: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571d4bu;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00571d4f: { // 0x571d4f: 7c88 JL 0x00571cd9
    b516_pc=0x571d4fu;
    if(integer::condition("JL",flags)) goto L00571cd9;
  }
  L00571d51: { // 0x571d51: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    b516_pc=0x571d51u;
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L00571d55: { // 0x571d55: 8bda MOV EBX,EDX
    b516_pc=0x571d55u;
    s.bx = s.dx;
  }
  L00571d57: { // 0x571d57: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    b516_pc=0x571d57u;
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L00571d5b: { // 0x571d5b: 03c8 ADD ECX,EAX
    b516_pc=0x571d5bu;
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00571d5d: { // 0x571d5d: 8bf0 MOV ESI,EAX
    b516_pc=0x571d5du;
    s.si = s.ax;
  }
  L00571d5f: { // 0x571d5f: 3bc1 CMP EAX,ECX
    b516_pc=0x571d5fu;
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L00571d61: { // 0x571d61: 895c242c MOV dword ptr [ESP + 0x2c],EBX
    b516_pc=0x571d61u;
    m.w32((f.sp+0x0000002cu), s.bx);
  }
  L00571d65: { // 0x571d65: 89442430 MOV dword ptr [ESP + 0x30],EAX
    b516_pc=0x571d65u;
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00571d69: { // 0x571d69: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x571d69u;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00571d6d: { // 0x571d6d: 7d78 JGE 0x00571de7
    b516_pc=0x571d6du;
    if(integer::condition("JGE",flags)) goto L00571de7;
  }
  L00571d6f: { // 0x571d6f: 83c207 ADD EDX,0x7
    b516_pc=0x571d6fu;
    s.dx = integer::add(s.dx,0x00000007u,32,flags);
  }
  L00571d72: { // 0x571d72: 89542440 MOV dword ptr [ESP + 0x40],EDX
    b516_pc=0x571d72u;
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00571d76: { // 0x571d76: 3b5c2440 CMP EBX,dword ptr [ESP + 0x40]
    b516_pc=0x571d76u;
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000040u)),32,flags);
  }
  L00571d7a: { // 0x571d7a: 7d58 JGE 0x00571dd4
    b516_pc=0x571d7au;
    if(integer::condition("JGE",flags)) goto L00571dd4;
  }
  L00571d7c: { // 0x571d7c: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571d7cu;
    s.cx = (f.sp+0x00000044u);
  }
  L00571d80: { // 0x571d80: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x571d80u;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00571d85: { // 0x571d85: 6689742446 MOV word ptr [ESP + 0x46],SI
    b516_pc=0x571d85u;
    m.w16((f.sp+0x00000046u), (s.si & 0xffffu));
  }
  L00571d8a: { // 0x571d8a: e8818a0100 CALL 0x0058a810
    b516_pc=0x571d8au;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00571d8fu); flags=0x202u;
  }
  L00571d8f: { // 0x571d8f: 84c0 TEST AL,AL
    b516_pc=0x571d8fu;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571d91: { // 0x571d91: 7434 JZ 0x00571dc7
    b516_pc=0x571d91u;
    if(integer::condition("JZ",flags)) goto L00571dc7;
  }
  L00571d93: { // 0x571d93: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    b516_pc=0x571d93u;
    s.dx = m.r32((f.sp+0x00000048u));
  }
  L00571d97: { // 0x571d97: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571d97u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571d9b: { // 0x571d9b: e8c099ffff CALL 0x0056b760
    b516_pc=0x571d9bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571da0u); flags=0x202u;
  }
  L00571da0: { // 0x571da0: 8d542444 LEA EDX,[ESP + 0x44]
    b516_pc=0x571da0u;
    s.dx = (f.sp+0x00000044u);
  }
  L00571da4: { // 0x571da4: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571da4u;
    s.cx = 0x0081a820u;
  }
  L00571da9: { // 0x571da9: 52 PUSH EDX
    b516_pc=0x571da9u;
    f.push(m,s.dx);
  }
  L00571daa: { // 0x571daa: e85137fdff CALL 0x00545500
    b516_pc=0x571daau;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571dafu); flags=0x202u;
  }
  L00571daf: { // 0x571daf: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    b516_pc=0x571dafu;
    s.cx = m.r32((f.sp+0x00000048u));
  }
  L00571db3: { // 0x571db3: 8bf0 MOV ESI,EAX
    b516_pc=0x571db3u;
    s.si = s.ax;
  }
  L00571db5: { // 0x571db5: e8160d0000 CALL 0x00572ad0
    b516_pc=0x571db5u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00572ad0u,0x00571dbau); flags=0x202u;
  }
  L00571dba: { // 0x571dba: 8a4010 MOV AL,byte ptr [EAX + 0x10]
    b516_pc=0x571dbau;
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000010u)));
  }
  L00571dbd: { // 0x571dbd: 88861b010000 MOV byte ptr [ESI + 0x11b],AL
    b516_pc=0x571dbdu;
    m.w8((s.si+0x0000011bu), (s.ax & 0xffu));
  }
  L00571dc3: { // 0x571dc3: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    b516_pc=0x571dc3u;
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00571dc7: { // 0x571dc7: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    b516_pc=0x571dc7u;
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00571dcb: { // 0x571dcb: 43 INC EBX
    b516_pc=0x571dcbu;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571dcc: { // 0x571dcc: 3bd8 CMP EBX,EAX
    b516_pc=0x571dccu;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00571dce: { // 0x571dce: 7cac JL 0x00571d7c
    b516_pc=0x571dceu;
    if(integer::condition("JL",flags)) goto L00571d7c;
  }
  L00571dd0: { // 0x571dd0: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x571dd0u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00571dd4: { // 0x571dd4: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    b516_pc=0x571dd4u;
    s.cx = m.r32((f.sp+0x00000030u));
  }
  L00571dd8: { // 0x571dd8: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    b516_pc=0x571dd8u;
    s.dx = m.r32((f.sp+0x00000038u));
  }
  L00571ddc: { // 0x571ddc: 46 INC ESI
    b516_pc=0x571ddcu;
    s.si = integer::increment(s.si,32,flags);
  }
  L00571ddd: { // 0x571ddd: 03d1 ADD EDX,ECX
    b516_pc=0x571dddu;
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00571ddf: { // 0x571ddf: 3bf2 CMP ESI,EDX
    b516_pc=0x571ddfu;
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00571de1: { // 0x571de1: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x571de1u;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00571de5: { // 0x571de5: 7c8f JL 0x00571d76
    b516_pc=0x571de5u;
    if(integer::condition("JL",flags)) goto L00571d76;
  }
  L00571de7: { // 0x571de7: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    b516_pc=0x571de7u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00571deb: { // 0x571deb: 0fbf37 MOVSX ESI,word ptr [EDI]
    b516_pc=0x571debu;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00571dee: { // 0x571dee: 8d5102 LEA EDX,[ECX + 0x2]
    b516_pc=0x571deeu;
    s.dx = (s.cx+0x00000002u);
  }
  L00571df1: { // 0x571df1: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x571df1u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00571df5: { // 0x571df5: 3bca CMP ECX,EDX
    b516_pc=0x571df5u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00571df7: { // 0x571df7: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571df7u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00571dfb: { // 0x571dfb: 89542418 MOV dword ptr [ESP + 0x18],EDX
    b516_pc=0x571dfbu;
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00571dff: { // 0x571dff: 7d65 JGE 0x00571e66
    b516_pc=0x571dffu;
    if(integer::condition("JGE",flags)) goto L00571e66;
  }
  L00571e01: { // 0x571e01: 8d4601 LEA EAX,[ESI + 0x1]
    b516_pc=0x571e01u;
    s.ax = (s.si+0x00000001u);
  }
  L00571e04: { // 0x571e04: 3bf0 CMP ESI,EAX
    b516_pc=0x571e04u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00571e06: { // 0x571e06: 8bde MOV EBX,ESI
    b516_pc=0x571e06u;
    s.bx = s.si;
  }
  L00571e08: { // 0x571e08: 7d53 JGE 0x00571e5d
    b516_pc=0x571e08u;
    if(integer::condition("JGE",flags)) goto L00571e5d;
  }
  L00571e0a: { // 0x571e0a: 66894c2446 MOV word ptr [ESP + 0x46],CX
    b516_pc=0x571e0au;
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L00571e0f: { // 0x571e0f: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571e0fu;
    s.cx = (f.sp+0x00000044u);
  }
  L00571e13: { // 0x571e13: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x571e13u;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00571e18: { // 0x571e18: e8f3890100 CALL 0x0058a810
    b516_pc=0x571e18u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00571e1du); flags=0x202u;
  }
  L00571e1d: { // 0x571e1d: 84c0 TEST AL,AL
    b516_pc=0x571e1du;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571e1f: { // 0x571e1f: 742c JZ 0x00571e4d
    b516_pc=0x571e1fu;
    if(integer::condition("JZ",flags)) goto L00571e4d;
  }
  L00571e21: { // 0x571e21: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x571e21u;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00571e25: { // 0x571e25: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571e25u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571e29: { // 0x571e29: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x571e29u;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L00571e2c: { // 0x571e2c: e82f99ffff CALL 0x0056b760
    b516_pc=0x571e2cu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571e31u); flags=0x202u;
  }
  L00571e31: { // 0x571e31: 8d442444 LEA EAX,[ESP + 0x44]
    b516_pc=0x571e31u;
    s.ax = (f.sp+0x00000044u);
  }
  L00571e35: { // 0x571e35: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571e35u;
    s.cx = 0x0081a820u;
  }
  L00571e3a: { // 0x571e3a: 50 PUSH EAX
    b516_pc=0x571e3au;
    f.push(m,s.ax);
  }
  L00571e3b: { // 0x571e3b: e8c036fdff CALL 0x00545500
    b516_pc=0x571e3bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571e40u); flags=0x202u;
  }
  L00571e40: { // 0x571e40: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x571e40u;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L00571e43: { // 0x571e43: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x571e43u;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00571e47: { // 0x571e47: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571e47u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00571e4d: { // 0x571e4d: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    b516_pc=0x571e4du;
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00571e51: { // 0x571e51: 43 INC EBX
    b516_pc=0x571e51u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571e52: { // 0x571e52: 8d4601 LEA EAX,[ESI + 0x1]
    b516_pc=0x571e52u;
    s.ax = (s.si+0x00000001u);
  }
  L00571e55: { // 0x571e55: 3bd8 CMP EBX,EAX
    b516_pc=0x571e55u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00571e57: { // 0x571e57: 7cb1 JL 0x00571e0a
    b516_pc=0x571e57u;
    if(integer::condition("JL",flags)) goto L00571e0a;
  }
  L00571e59: { // 0x571e59: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    b516_pc=0x571e59u;
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00571e5d: { // 0x571e5d: 41 INC ECX
    b516_pc=0x571e5du;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00571e5e: { // 0x571e5e: 3bca CMP ECX,EDX
    b516_pc=0x571e5eu;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00571e60: { // 0x571e60: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571e60u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00571e64: { // 0x571e64: 7c9e JL 0x00571e04
    b516_pc=0x571e64u;
    if(integer::condition("JL",flags)) goto L00571e04;
  }
  L00571e66: { // 0x571e66: 0fbf4d02 MOVSX ECX,word ptr [EBP + 0x2]
    b516_pc=0x571e66u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00571e6a: { // 0x571e6a: 0fbf7500 MOVSX ESI,word ptr [EBP]
    b516_pc=0x571e6au;
    s.si = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00571e6e: { // 0x571e6e: 8d5101 LEA EDX,[ECX + 0x1]
    b516_pc=0x571e6eu;
    s.dx = (s.cx+0x00000001u);
  }
  L00571e71: { // 0x571e71: 8974242c MOV dword ptr [ESP + 0x2c],ESI
    b516_pc=0x571e71u;
    m.w32((f.sp+0x0000002cu), s.si);
  }
  L00571e75: { // 0x571e75: 3bca CMP ECX,EDX
    b516_pc=0x571e75u;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00571e77: { // 0x571e77: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571e77u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00571e7b: { // 0x571e7b: 89542418 MOV dword ptr [ESP + 0x18],EDX
    b516_pc=0x571e7bu;
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00571e7f: { // 0x571e7f: 7d65 JGE 0x00571ee6
    b516_pc=0x571e7fu;
    if(integer::condition("JGE",flags)) goto L00571ee6;
  }
  L00571e81: { // 0x571e81: 8d4602 LEA EAX,[ESI + 0x2]
    b516_pc=0x571e81u;
    s.ax = (s.si+0x00000002u);
  }
  L00571e84: { // 0x571e84: 3bf0 CMP ESI,EAX
    b516_pc=0x571e84u;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00571e86: { // 0x571e86: 8bde MOV EBX,ESI
    b516_pc=0x571e86u;
    s.bx = s.si;
  }
  L00571e88: { // 0x571e88: 7d53 JGE 0x00571edd
    b516_pc=0x571e88u;
    if(integer::condition("JGE",flags)) goto L00571edd;
  }
  L00571e8a: { // 0x571e8a: 66894c2446 MOV word ptr [ESP + 0x46],CX
    b516_pc=0x571e8au;
    m.w16((f.sp+0x00000046u), (s.cx & 0xffffu));
  }
  L00571e8f: { // 0x571e8f: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571e8fu;
    s.cx = (f.sp+0x00000044u);
  }
  L00571e93: { // 0x571e93: 66895c2444 MOV word ptr [ESP + 0x44],BX
    b516_pc=0x571e93u;
    m.w16((f.sp+0x00000044u), (s.bx & 0xffffu));
  }
  L00571e98: { // 0x571e98: e873890100 CALL 0x0058a810
    b516_pc=0x571e98u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00571e9du); flags=0x202u;
  }
  L00571e9d: { // 0x571e9d: 84c0 TEST AL,AL
    b516_pc=0x571e9du;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571e9f: { // 0x571e9f: 742c JZ 0x00571ecd
    b516_pc=0x571e9fu;
    if(integer::condition("JZ",flags)) goto L00571ecd;
  }
  L00571ea1: { // 0x571ea1: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x571ea1u;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00571ea5: { // 0x571ea5: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571ea5u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571ea9: { // 0x571ea9: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x571ea9u;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L00571eac: { // 0x571eac: e8af98ffff CALL 0x0056b760
    b516_pc=0x571eacu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571eb1u); flags=0x202u;
  }
  L00571eb1: { // 0x571eb1: 8d542444 LEA EDX,[ESP + 0x44]
    b516_pc=0x571eb1u;
    s.dx = (f.sp+0x00000044u);
  }
  L00571eb5: { // 0x571eb5: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571eb5u;
    s.cx = 0x0081a820u;
  }
  L00571eba: { // 0x571eba: 52 PUSH EDX
    b516_pc=0x571ebau;
    f.push(m,s.dx);
  }
  L00571ebb: { // 0x571ebb: e84036fdff CALL 0x00545500
    b516_pc=0x571ebbu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571ec0u); flags=0x202u;
  }
  L00571ec0: { // 0x571ec0: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x571ec0u;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L00571ec3: { // 0x571ec3: 8b74242c MOV ESI,dword ptr [ESP + 0x2c]
    b516_pc=0x571ec3u;
    s.si = m.r32((f.sp+0x0000002cu));
  }
  L00571ec7: { // 0x571ec7: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571ec7u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00571ecd: { // 0x571ecd: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    b516_pc=0x571ecdu;
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L00571ed1: { // 0x571ed1: 43 INC EBX
    b516_pc=0x571ed1u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571ed2: { // 0x571ed2: 8d4602 LEA EAX,[ESI + 0x2]
    b516_pc=0x571ed2u;
    s.ax = (s.si+0x00000002u);
  }
  L00571ed5: { // 0x571ed5: 3bd8 CMP EBX,EAX
    b516_pc=0x571ed5u;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00571ed7: { // 0x571ed7: 7cb1 JL 0x00571e8a
    b516_pc=0x571ed7u;
    if(integer::condition("JL",flags)) goto L00571e8a;
  }
  L00571ed9: { // 0x571ed9: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    b516_pc=0x571ed9u;
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L00571edd: { // 0x571edd: 41 INC ECX
    b516_pc=0x571eddu;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00571ede: { // 0x571ede: 3bca CMP ECX,EDX
    b516_pc=0x571edeu;
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00571ee0: { // 0x571ee0: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571ee0u;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00571ee4: { // 0x571ee4: 7c9e JL 0x00571e84
    b516_pc=0x571ee4u;
    if(integer::condition("JL",flags)) goto L00571e84;
  }
  L00571ee6: { // 0x571ee6: 0fbf4500 MOVSX EAX,word ptr [EBP]
    b516_pc=0x571ee6u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00571eea: { // 0x571eea: 0fbf0f MOVSX ECX,word ptr [EDI]
    b516_pc=0x571eeau;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di)),16));
  }
  L00571eed: { // 0x571eed: 0fbf5f02 MOVSX EBX,word ptr [EDI + 0x2]
    b516_pc=0x571eedu;
    s.bx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00571ef1: { // 0x571ef1: 8d5001 LEA EDX,[EAX + 0x1]
    b516_pc=0x571ef1u;
    s.dx = (s.ax+0x00000001u);
  }
  L00571ef4: { // 0x571ef4: 2bc8 SUB ECX,EAX
    b516_pc=0x571ef4u;
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L00571ef6: { // 0x571ef6: 0fbf4502 MOVSX EAX,word ptr [EBP + 0x2]
    b516_pc=0x571ef6u;
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp+0x00000002u)),16));
  }
  L00571efa: { // 0x571efa: 2bc3 SUB EAX,EBX
    b516_pc=0x571efau;
    s.ax = integer::sub(s.ax,s.bx,32,flags);
  }
  L00571efc: { // 0x571efc: 8954242c MOV dword ptr [ESP + 0x2c],EDX
    b516_pc=0x571efcu;
    m.w32((f.sp+0x0000002cu), s.dx);
  }
  L00571f00: { // 0x571f00: 49 DEC ECX
    b516_pc=0x571f00u;
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00571f01: { // 0x571f01: 8d5301 LEA EDX,[EBX + 0x1]
    b516_pc=0x571f01u;
    s.dx = (s.bx+0x00000001u);
  }
  L00571f04: { // 0x571f04: 48 DEC EAX
    b516_pc=0x571f04u;
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00571f05: { // 0x571f05: 8bf2 MOV ESI,EDX
    b516_pc=0x571f05u;
    s.si = s.dx;
  }
  L00571f07: { // 0x571f07: 03c2 ADD EAX,EDX
    b516_pc=0x571f07u;
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L00571f09: { // 0x571f09: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x571f09u;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00571f0d: { // 0x571f0d: 3bd0 CMP EDX,EAX
    b516_pc=0x571f0du;
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L00571f0f: { // 0x571f0f: 89442418 MOV dword ptr [ESP + 0x18],EAX
    b516_pc=0x571f0fu;
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00571f13: { // 0x571f13: 7d6e JGE 0x00571f83
    b516_pc=0x571f13u;
    if(integer::condition("JGE",flags)) goto L00571f83;
  }
  L00571f15: { // 0x571f15: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x571f15u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00571f19: { // 0x571f19: 03cb ADD ECX,EBX
    b516_pc=0x571f19u;
    s.cx = integer::add(s.cx,s.bx,32,flags);
  }
  L00571f1b: { // 0x571f1b: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    b516_pc=0x571f1bu;
    m.w32((f.sp+0x00000040u), s.cx);
  }
  L00571f1f: { // 0x571f1f: 3b5c2440 CMP EBX,dword ptr [ESP + 0x40]
    b516_pc=0x571f1fu;
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000040u)),32,flags);
  }
  L00571f23: { // 0x571f23: 7d55 JGE 0x00571f7a
    b516_pc=0x571f23u;
    if(integer::condition("JGE",flags)) goto L00571f7a;
  }
  L00571f25: { // 0x571f25: 56 PUSH ESI
    b516_pc=0x571f25u;
    f.push(m,s.si);
  }
  L00571f26: { // 0x571f26: 53 PUSH EBX
    b516_pc=0x571f26u;
    f.push(m,s.bx);
  }
  L00571f27: { // 0x571f27: 8d4c244c LEA ECX,[ESP + 0x4c]
    b516_pc=0x571f27u;
    s.cx = (f.sp+0x0000004cu);
  }
  L00571f2b: { // 0x571f2b: e8008eebff CALL 0x0042ad30
    b516_pc=0x571f2bu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042ad30u,0x00571f30u); flags=0x202u;
  }
  L00571f30: { // 0x571f30: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571f30u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571f34: { // 0x571f34: e8d7880100 CALL 0x0058a810
    b516_pc=0x571f34u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058a810u,0x00571f39u); flags=0x202u;
  }
  L00571f39: { // 0x571f39: 84c0 TEST AL,AL
    b516_pc=0x571f39u;
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00571f3b: { // 0x571f3b: 742c JZ 0x00571f69
    b516_pc=0x571f3bu;
    if(integer::condition("JZ",flags)) goto L00571f69;
  }
  L00571f3d: { // 0x571f3d: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x571f3du;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00571f41: { // 0x571f41: 8d4c2444 LEA ECX,[ESP + 0x44]
    b516_pc=0x571f41u;
    s.cx = (f.sp+0x00000044u);
  }
  L00571f45: { // 0x571f45: 8b5608 MOV EDX,dword ptr [ESI + 0x8]
    b516_pc=0x571f45u;
    s.dx = m.r32((s.si+0x00000008u));
  }
  L00571f48: { // 0x571f48: e81398ffff CALL 0x0056b760
    b516_pc=0x571f48u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x0056b760u,0x00571f4du); flags=0x202u;
  }
  L00571f4d: { // 0x571f4d: 8d442444 LEA EAX,[ESP + 0x44]
    b516_pc=0x571f4du;
    s.ax = (f.sp+0x00000044u);
  }
  L00571f51: { // 0x571f51: b920a88100 MOV ECX,0x81a820
    b516_pc=0x571f51u;
    s.cx = 0x0081a820u;
  }
  L00571f56: { // 0x571f56: 50 PUSH EAX
    b516_pc=0x571f56u;
    f.push(m,s.ax);
  }
  L00571f57: { // 0x571f57: e8a435fdff CALL 0x00545500
    b516_pc=0x571f57u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00571f5cu); flags=0x202u;
  }
  L00571f5c: { // 0x571f5c: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x571f5cu;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L00571f5f: { // 0x571f5f: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    b516_pc=0x571f5fu;
    s.si = m.r32((f.sp+0x00000014u));
  }
  L00571f63: { // 0x571f63: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x571f63u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L00571f69: { // 0x571f69: 8b442440 MOV EAX,dword ptr [ESP + 0x40]
    b516_pc=0x571f69u;
    s.ax = m.r32((f.sp+0x00000040u));
  }
  L00571f6d: { // 0x571f6d: 43 INC EBX
    b516_pc=0x571f6du;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00571f6e: { // 0x571f6e: 3bd8 CMP EBX,EAX
    b516_pc=0x571f6eu;
    (void)integer::sub(s.bx,s.ax,32,flags);
  }
  L00571f70: { // 0x571f70: 7cb3 JL 0x00571f25
    b516_pc=0x571f70u;
    if(integer::condition("JL",flags)) goto L00571f25;
  }
  L00571f72: { // 0x571f72: 8b5c242c MOV EBX,dword ptr [ESP + 0x2c]
    b516_pc=0x571f72u;
    s.bx = m.r32((f.sp+0x0000002cu));
  }
  L00571f76: { // 0x571f76: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    b516_pc=0x571f76u;
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L00571f7a: { // 0x571f7a: 46 INC ESI
    b516_pc=0x571f7au;
    s.si = integer::increment(s.si,32,flags);
  }
  L00571f7b: { // 0x571f7b: 3bf0 CMP ESI,EAX
    b516_pc=0x571f7bu;
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L00571f7d: { // 0x571f7d: 89742414 MOV dword ptr [ESP + 0x14],ESI
    b516_pc=0x571f7du;
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00571f81: { // 0x571f81: 7c9c JL 0x00571f1f
    b516_pc=0x571f81u;
    if(integer::condition("JL",flags)) goto L00571f1f;
  }
  L00571f83: { // 0x571f83: 668b17 MOV DX,word ptr [EDI]
    b516_pc=0x571f83u;
    s.dx = with_ax(s.dx, m.r16((s.di)));
  }
  L00571f86: { // 0x571f86: 668b4702 MOV AX,word ptr [EDI + 0x2]
    b516_pc=0x571f86u;
    s.ax = with_ax(s.ax, m.r16((s.di+0x00000002u)));
  }
  L00571f8a: { // 0x571f8a: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    b516_pc=0x571f8au;
    s.si = m.r32((f.sp+0x00000010u));
  }
  L00571f8e: { // 0x571f8e: 8b5c2448 MOV EBX,dword ptr [ESP + 0x48]
    b516_pc=0x571f8eu;
    s.bx = m.r32((f.sp+0x00000048u));
  }
  L00571f92: { // 0x571f92: 6683ea02 SUB DX,0x2
    b516_pc=0x571f92u;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000002u,16,flags));
  }
  L00571f96: { // 0x571f96: 662d0300 SUB AX,0x3
    b516_pc=0x571f96u;
    s.ax = with_ax(s.ax, integer::sub((s.ax & 0xffffu),0x00000003u,16,flags));
  }
  L00571f9a: { // 0x571f9a: 6689542444 MOV word ptr [ESP + 0x44],DX
    b516_pc=0x571f9au;
    m.w16((f.sp+0x00000044u), (s.dx & 0xffffu));
  }
  L00571f9f: { // 0x571f9f: 8b5610 MOV EDX,dword ptr [ESI + 0x10]
    b516_pc=0x571f9fu;
    s.dx = m.r32((s.si+0x00000010u));
  }
  L00571fa2: { // 0x571fa2: 6689442446 MOV word ptr [ESP + 0x46],AX
    b516_pc=0x571fa2u;
    m.w16((f.sp+0x00000046u), (s.ax & 0xffffu));
  }
  L00571fa7: { // 0x571fa7: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    b516_pc=0x571fa7u;
    s.cx = m.r32((f.sp+0x00000044u));
  }
  L00571fab: { // 0x571fab: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x571fabu;
    s.ax = m.r32((0x00a55c70u));
  }
  L00571fb0: { // 0x571fb0: 894c2444 MOV dword ptr [ESP + 0x44],ECX
    b516_pc=0x571fb0u;
    m.w32((f.sp+0x00000044u), s.cx);
  }
  L00571fb4: { // 0x571fb4: 52 PUSH EDX
    b516_pc=0x571fb4u;
    f.push(m,s.dx);
  }
  L00571fb5: { // 0x571fb5: 53 PUSH EBX
    b516_pc=0x571fb5u;
    f.push(m,s.bx);
  }
  L00571fb6: { // 0x571fb6: 8d54244c LEA EDX,[ESP + 0x4c]
    b516_pc=0x571fb6u;
    s.dx = (f.sp+0x0000004cu);
  }
  L00571fba: { // 0x571fba: 8d4805 LEA ECX,[EAX + 0x5]
    b516_pc=0x571fbau;
    s.cx = (s.ax+0x00000005u);
  }
  L00571fbd: { // 0x571fbd: e82e320100 CALL 0x005851f0
    b516_pc=0x571fbdu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x00571fc2u); flags=0x202u;
  }
  L00571fc2: { // 0x571fc2: 668b0f MOV CX,word ptr [EDI]
    b516_pc=0x571fc2u;
    s.cx = with_ax(s.cx, m.r16((s.di)));
  }
  L00571fc5: { // 0x571fc5: 668b5702 MOV DX,word ptr [EDI + 0x2]
    b516_pc=0x571fc5u;
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L00571fc9: { // 0x571fc9: 6649 DEC CX
    b516_pc=0x571fc9u;
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L00571fcb: { // 0x571fcb: 664a DEC DX
    b516_pc=0x571fcbu;
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L00571fcd: { // 0x571fcd: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x571fcdu;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L00571fd2: { // 0x571fd2: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    b516_pc=0x571fd2u;
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00571fd5: { // 0x571fd5: 668954244a MOV word ptr [ESP + 0x4a],DX
    b516_pc=0x571fd5u;
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L00571fda: { // 0x571fda: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x571fdau;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00571fde: { // 0x571fde: 89442448 MOV dword ptr [ESP + 0x48],EAX
    b516_pc=0x571fdeu;
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L00571fe2: { // 0x571fe2: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x571fe2u;
    s.ax = m.r32((0x00a55c70u));
  }
  L00571fe7: { // 0x571fe7: 51 PUSH ECX
    b516_pc=0x571fe7u;
    f.push(m,s.cx);
  }
  L00571fe8: { // 0x571fe8: 53 PUSH EBX
    b516_pc=0x571fe8u;
    f.push(m,s.bx);
  }
  L00571fe9: { // 0x571fe9: 8d542450 LEA EDX,[ESP + 0x50]
    b516_pc=0x571fe9u;
    s.dx = (f.sp+0x00000050u);
  }
  L00571fed: { // 0x571fed: 8d4806 LEA ECX,[EAX + 0x6]
    b516_pc=0x571fedu;
    s.cx = (s.ax+0x00000006u);
  }
  L00571ff0: { // 0x571ff0: e8fb310100 CALL 0x005851f0
    b516_pc=0x571ff0u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x00571ff5u); flags=0x202u;
  }
  L00571ff5: { // 0x571ff5: 668b4d00 MOV CX,word ptr [EBP]
    b516_pc=0x571ff5u;
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00571ff9: { // 0x571ff9: 668b5502 MOV DX,word ptr [EBP + 0x2]
    b516_pc=0x571ff9u;
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L00571ffd: { // 0x571ffd: 6683e903 SUB CX,0x3
    b516_pc=0x571ffdu;
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),0x00000003u,16,flags));
  }
  L00572001: { // 0x572001: 6683ea02 SUB DX,0x2
    b516_pc=0x572001u;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),0x00000002u,16,flags));
  }
  L00572005: { // 0x572005: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x572005u;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L0057200a: { // 0x57200a: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    b516_pc=0x57200au;
    s.cx = m.r32((s.si+0x00000010u));
  }
  L0057200d: { // 0x57200d: 668954244a MOV word ptr [ESP + 0x4a],DX
    b516_pc=0x57200du;
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L00572012: { // 0x572012: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x572012u;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L00572016: { // 0x572016: 89442448 MOV dword ptr [ESP + 0x48],EAX
    b516_pc=0x572016u;
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0057201a: { // 0x57201a: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x57201au;
    s.ax = m.r32((0x00a55c70u));
  }
  L0057201f: { // 0x57201f: 51 PUSH ECX
    b516_pc=0x57201fu;
    f.push(m,s.cx);
  }
  L00572020: { // 0x572020: 53 PUSH EBX
    b516_pc=0x572020u;
    f.push(m,s.bx);
  }
  L00572021: { // 0x572021: 8d542450 LEA EDX,[ESP + 0x50]
    b516_pc=0x572021u;
    s.dx = (f.sp+0x00000050u);
  }
  L00572025: { // 0x572025: 8d4808 LEA ECX,[EAX + 0x8]
    b516_pc=0x572025u;
    s.cx = (s.ax+0x00000008u);
  }
  L00572028: { // 0x572028: e8c3310100 CALL 0x005851f0
    b516_pc=0x572028u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x0057202du); flags=0x202u;
  }
  L0057202d: { // 0x57202d: 668b4d00 MOV CX,word ptr [EBP]
    b516_pc=0x57202du;
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00572031: { // 0x572031: 668b5502 MOV DX,word ptr [EBP + 0x2]
    b516_pc=0x572031u;
    s.dx = with_ax(s.dx, m.r16((s.bp+0x00000002u)));
  }
  L00572035: { // 0x572035: 6649 DEC CX
    b516_pc=0x572035u;
    s.cx = with_ax(s.cx, integer::decrement((s.cx & 0xffffu),16,flags));
  }
  L00572037: { // 0x572037: 664a DEC DX
    b516_pc=0x572037u;
    s.dx = with_ax(s.dx, integer::decrement((s.dx & 0xffffu),16,flags));
  }
  L00572039: { // 0x572039: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x572039u;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L0057203e: { // 0x57203e: 8b4e10 MOV ECX,dword ptr [ESI + 0x10]
    b516_pc=0x57203eu;
    s.cx = m.r32((s.si+0x00000010u));
  }
  L00572041: { // 0x572041: 668954244a MOV word ptr [ESP + 0x4a],DX
    b516_pc=0x572041u;
    m.w16((f.sp+0x0000004au), (s.dx & 0xffffu));
  }
  L00572046: { // 0x572046: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    b516_pc=0x572046u;
    s.ax = m.r32((f.sp+0x00000048u));
  }
  L0057204a: { // 0x57204a: 89442448 MOV dword ptr [ESP + 0x48],EAX
    b516_pc=0x57204au;
    m.w32((f.sp+0x00000048u), s.ax);
  }
  L0057204e: { // 0x57204e: a1705ca500 MOV EAX,[0x00a55c70]
    b516_pc=0x57204eu;
    s.ax = m.r32((0x00a55c70u));
  }
  L00572053: { // 0x572053: 51 PUSH ECX
    b516_pc=0x572053u;
    f.push(m,s.cx);
  }
  L00572054: { // 0x572054: 53 PUSH EBX
    b516_pc=0x572054u;
    f.push(m,s.bx);
  }
  L00572055: { // 0x572055: 8d542450 LEA EDX,[ESP + 0x50]
    b516_pc=0x572055u;
    s.dx = (f.sp+0x00000050u);
  }
  L00572059: { // 0x572059: 8d4809 LEA ECX,[EAX + 0x9]
    b516_pc=0x572059u;
    s.cx = (s.ax+0x00000009u);
  }
  L0057205c: { // 0x57205c: e88f310100 CALL 0x005851f0
    b516_pc=0x57205cu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x005851f0u,0x00572061u); flags=0x202u;
  }
  L00572061: { // 0x572061: 33db XOR EBX,EBX
    b516_pc=0x572061u;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L00572063: { // 0x572063: 668b4d00 MOV CX,word ptr [EBP]
    b516_pc=0x572063u;
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  L00572067: { // 0x572067: 668b5702 MOV DX,word ptr [EDI + 0x2]
    b516_pc=0x572067u;
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L0057206b: { // 0x57206b: 662bcb SUB CX,BX
    b516_pc=0x57206bu;
    s.cx = with_ax(s.cx, integer::sub((s.cx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L0057206e: { // 0x57206e: 8d442448 LEA EAX,[ESP + 0x48]
    b516_pc=0x57206eu;
    s.ax = (f.sp+0x00000048u);
  }
  L00572072: { // 0x572072: 66894c2448 MOV word ptr [ESP + 0x48],CX
    b516_pc=0x572072u;
    m.w16((f.sp+0x00000048u), (s.cx & 0xffffu));
  }
  L00572077: { // 0x572077: 662bd3 SUB DX,BX
    b516_pc=0x572077u;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L0057207a: { // 0x57207a: 50 PUSH EAX
    b516_pc=0x57207au;
    f.push(m,s.ax);
  }
  L0057207b: { // 0x57207b: b920a88100 MOV ECX,0x81a820
    b516_pc=0x57207bu;
    s.cx = 0x0081a820u;
  }
  L00572080: { // 0x572080: 668954244e MOV word ptr [ESP + 0x4e],DX
    b516_pc=0x572080u;
    m.w16((f.sp+0x0000004eu), (s.dx & 0xffffu));
  }
  L00572085: { // 0x572085: e87634fdff CALL 0x00545500
    b516_pc=0x572085u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x0057208au); flags=0x202u;
  }
  L0057208a: { // 0x57208a: 8a4e10 MOV CL,byte ptr [ESI + 0x10]
    b516_pc=0x57208au;
    s.cx = with_al(s.cx, m.r8((s.si+0x00000010u)));
  }
  L0057208d: { // 0x57208d: c6801c01000005 MOV byte ptr [EAX + 0x11c],0x5
    b516_pc=0x57208du;
    m.w8((s.ax+0x0000011cu), 0x00000005u);
  }
  L00572094: { // 0x572094: 2acb SUB CL,BL
    b516_pc=0x572094u;
    s.cx = with_al(s.cx, integer::sub((s.cx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00572096: { // 0x572096: fec9 DEC CL
    b516_pc=0x572096u;
    s.cx = with_al(s.cx, integer::decrement((s.cx & 0xffu),8,flags));
  }
  L00572098: { // 0x572098: 88881b010000 MOV byte ptr [EAX + 0x11b],CL
    b516_pc=0x572098u;
    m.w8((s.ax+0x0000011bu), (s.cx & 0xffu));
  }
  L0057209e: { // 0x57209e: 8b15505ca500 MOV EDX,dword ptr [0x00a55c50]
    b516_pc=0x57209eu;
    s.dx = m.r32((0x00a55c50u));
  }
  L005720a4: { // 0x5720a4: 83c204 ADD EDX,0x4
    b516_pc=0x5720a4u;
    s.dx = integer::add(s.dx,0x00000004u,32,flags);
  }
  L005720a7: { // 0x5720a7: 43 INC EBX
    b516_pc=0x5720a7u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005720a8: { // 0x5720a8: 83fb04 CMP EBX,0x4
    b516_pc=0x5720a8u;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L005720ab: { // 0x5720ab: 895038 MOV dword ptr [EAX + 0x38],EDX
    b516_pc=0x5720abu;
    m.w32((s.ax+0x00000038u), s.dx);
  }
  L005720ae: { // 0x5720ae: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x5720aeu;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L005720b5: { // 0x5720b5: 7cac JL 0x00572063
    b516_pc=0x5720b5u;
    if(integer::condition("JL",flags)) goto L00572063;
  }
  L005720b7: { // 0x5720b7: 33db XOR EBX,EBX
    b516_pc=0x5720b7u;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005720b9: { // 0x5720b9: 668b07 MOV AX,word ptr [EDI]
    b516_pc=0x5720b9u;
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L005720bc: { // 0x5720bc: 33f6 XOR ESI,ESI
    b516_pc=0x5720bcu;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005720be: { // 0x5720be: 0fbf5500 MOVSX EDX,word ptr [EBP]
    b516_pc=0x5720beu;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L005720c2: { // 0x5720c2: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x5720c2u;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005720c5: { // 0x5720c5: 2bca SUB ECX,EDX
    b516_pc=0x5720c5u;
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L005720c7: { // 0x5720c7: 8d4c19fd LEA ECX,[ECX + EBX*0x1 + -0x3]
    b516_pc=0x5720c7u;
    s.cx = (s.cx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L005720cb: { // 0x5720cb: 85c9 TEST ECX,ECX
    b516_pc=0x5720cbu;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L005720cd: { // 0x5720cd: 7e63 JLE 0x00572132
    b516_pc=0x5720cdu;
    if(integer::condition("JLE",flags)) goto L00572132;
  }
  L005720cf: { // 0x5720cf: 668b5702 MOV DX,word ptr [EDI + 0x2]
    b516_pc=0x5720cfu;
    s.dx = with_ax(s.dx, m.r16((s.di+0x00000002u)));
  }
  L005720d3: { // 0x5720d3: 2bc6 SUB EAX,ESI
    b516_pc=0x5720d3u;
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L005720d5: { // 0x5720d5: 83e803 SUB EAX,0x3
    b516_pc=0x5720d5u;
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L005720d8: { // 0x5720d8: 662bd3 SUB DX,BX
    b516_pc=0x5720d8u;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L005720db: { // 0x5720db: 6689442448 MOV word ptr [ESP + 0x48],AX
    b516_pc=0x5720dbu;
    m.w16((f.sp+0x00000048u), (s.ax & 0xffffu));
  }
  L005720e0: { // 0x5720e0: 8d442448 LEA EAX,[ESP + 0x48]
    b516_pc=0x5720e0u;
    s.ax = (f.sp+0x00000048u);
  }
  L005720e4: { // 0x5720e4: 50 PUSH EAX
    b516_pc=0x5720e4u;
    f.push(m,s.ax);
  }
  L005720e5: { // 0x5720e5: b920a88100 MOV ECX,0x81a820
    b516_pc=0x5720e5u;
    s.cx = 0x0081a820u;
  }
  L005720ea: { // 0x5720ea: 668954244e MOV word ptr [ESP + 0x4e],DX
    b516_pc=0x5720eau;
    m.w16((f.sp+0x0000004eu), (s.dx & 0xffffu));
  }
  L005720ef: { // 0x5720ef: e80c34fdff CALL 0x00545500
    b516_pc=0x5720efu;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x005720f4u); flags=0x202u;
  }
  L005720f4: { // 0x5720f4: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    b516_pc=0x5720f4u;
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L005720f8: { // 0x5720f8: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    b516_pc=0x5720f8u;
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L005720fb: { // 0x5720fb: c6801c01000002 MOV byte ptr [EAX + 0x11c],0x2
    b516_pc=0x5720fbu;
    m.w8((s.ax+0x0000011cu), 0x00000002u);
  }
  L00572102: { // 0x572102: 2ad3 SUB DL,BL
    b516_pc=0x572102u;
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00572104: { // 0x572104: feca DEC DL
    b516_pc=0x572104u;
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L00572106: { // 0x572106: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    b516_pc=0x572106u;
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0057210c: { // 0x57210c: 8b0d505ca500 MOV ECX,dword ptr [0x00a55c50]
    b516_pc=0x57210cu;
    s.cx = m.r32((0x00a55c50u));
  }
  L00572112: { // 0x572112: 41 INC ECX
    b516_pc=0x572112u;
    s.cx = integer::increment(s.cx,32,flags);
  }
  L00572113: { // 0x572113: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x572113u;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0057211a: { // 0x57211a: 894838 MOV dword ptr [EAX + 0x38],ECX
    b516_pc=0x57211au;
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0057211d: { // 0x57211d: 668b07 MOV AX,word ptr [EDI]
    b516_pc=0x57211du;
    s.ax = with_ax(s.ax, m.r16((s.di)));
  }
  L00572120: { // 0x572120: 0fbf4d00 MOVSX ECX,word ptr [EBP]
    b516_pc=0x572120u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.bp)),16));
  }
  L00572124: { // 0x572124: 0fbfd0 MOVSX EDX,AX
    b516_pc=0x572124u;
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00572127: { // 0x572127: 2bd1 SUB EDX,ECX
    b516_pc=0x572127u;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L00572129: { // 0x572129: 46 INC ESI
    b516_pc=0x572129u;
    s.si = integer::increment(s.si,32,flags);
  }
  L0057212a: { // 0x57212a: 8d541afd LEA EDX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x57212au;
    s.dx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L0057212e: { // 0x57212e: 3bf2 CMP ESI,EDX
    b516_pc=0x57212eu;
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L00572130: { // 0x572130: 7c9d JL 0x005720cf
    b516_pc=0x572130u;
    if(integer::condition("JL",flags)) goto L005720cf;
  }
  L00572132: { // 0x572132: 43 INC EBX
    b516_pc=0x572132u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L00572133: { // 0x572133: 83fb04 CMP EBX,0x4
    b516_pc=0x572133u;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L00572136: { // 0x572136: 7c81 JL 0x005720b9
    b516_pc=0x572136u;
    if(integer::condition("JL",flags)) goto L005720b9;
  }
  L00572138: { // 0x572138: 33db XOR EBX,EBX
    b516_pc=0x572138u;
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L0057213a: { // 0x57213a: 668b4502 MOV AX,word ptr [EBP + 0x2]
    b516_pc=0x57213au;
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L0057213e: { // 0x57213e: 33f6 XOR ESI,ESI
    b516_pc=0x57213eu;
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00572140: { // 0x572140: 0fbf5702 MOVSX EDX,word ptr [EDI + 0x2]
    b516_pc=0x572140u;
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L00572144: { // 0x572144: 0fbfc8 MOVSX ECX,AX
    b516_pc=0x572144u;
    s.cx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L00572147: { // 0x572147: 2bca SUB ECX,EDX
    b516_pc=0x572147u;
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00572149: { // 0x572149: 8d4c19fd LEA ECX,[ECX + EBX*0x1 + -0x3]
    b516_pc=0x572149u;
    s.cx = (s.cx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L0057214d: { // 0x57214d: 85c9 TEST ECX,ECX
    b516_pc=0x57214du;
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0057214f: { // 0x57214f: 7e63 JLE 0x005721b4
    b516_pc=0x57214fu;
    if(integer::condition("JLE",flags)) goto L005721b4;
  }
  L00572151: { // 0x572151: 668b5500 MOV DX,word ptr [EBP]
    b516_pc=0x572151u;
    s.dx = with_ax(s.dx, m.r16((s.bp)));
  }
  L00572155: { // 0x572155: 2bc6 SUB EAX,ESI
    b516_pc=0x572155u;
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L00572157: { // 0x572157: 83e803 SUB EAX,0x3
    b516_pc=0x572157u;
    s.ax = integer::sub(s.ax,0x00000003u,32,flags);
  }
  L0057215a: { // 0x57215a: 662bd3 SUB DX,BX
    b516_pc=0x57215au;
    s.dx = with_ax(s.dx, integer::sub((s.dx & 0xffffu),(s.bx & 0xffffu),16,flags));
  }
  L0057215d: { // 0x57215d: 668944244a MOV word ptr [ESP + 0x4a],AX
    b516_pc=0x57215du;
    m.w16((f.sp+0x0000004au), (s.ax & 0xffffu));
  }
  L00572162: { // 0x572162: 8d442448 LEA EAX,[ESP + 0x48]
    b516_pc=0x572162u;
    s.ax = (f.sp+0x00000048u);
  }
  L00572166: { // 0x572166: 50 PUSH EAX
    b516_pc=0x572166u;
    f.push(m,s.ax);
  }
  L00572167: { // 0x572167: b920a88100 MOV ECX,0x81a820
    b516_pc=0x572167u;
    s.cx = 0x0081a820u;
  }
  L0057216c: { // 0x57216c: 668954244c MOV word ptr [ESP + 0x4c],DX
    b516_pc=0x57216cu;
    m.w16((f.sp+0x0000004cu), (s.dx & 0xffffu));
  }
  L00572171: { // 0x572171: e88a33fdff CALL 0x00545500
    b516_pc=0x572171u;
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545500u,0x00572176u); flags=0x202u;
  }
  L00572176: { // 0x572176: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    b516_pc=0x572176u;
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0057217a: { // 0x57217a: 8a5110 MOV DL,byte ptr [ECX + 0x10]
    b516_pc=0x57217au;
    s.dx = with_al(s.dx, m.r8((s.cx+0x00000010u)));
  }
  L0057217d: { // 0x57217d: c6801c01000001 MOV byte ptr [EAX + 0x11c],0x1
    b516_pc=0x57217du;
    m.w8((s.ax+0x0000011cu), 0x00000001u);
  }
  L00572184: { // 0x572184: 2ad3 SUB DL,BL
    b516_pc=0x572184u;
    s.dx = with_al(s.dx, integer::sub((s.dx & 0xffu),(s.bx & 0xffu),8,flags));
  }
  L00572186: { // 0x572186: feca DEC DL
    b516_pc=0x572186u;
    s.dx = with_al(s.dx, integer::decrement((s.dx & 0xffu),8,flags));
  }
  L00572188: { // 0x572188: 46 INC ESI
    b516_pc=0x572188u;
    s.si = integer::increment(s.si,32,flags);
  }
  L00572189: { // 0x572189: 88901b010000 MOV byte ptr [EAX + 0x11b],DL
    b516_pc=0x572189u;
    m.w8((s.ax+0x0000011bu), (s.dx & 0xffu));
  }
  L0057218f: { // 0x57218f: 8b0d505ca500 MOV ECX,dword ptr [0x00a55c50]
    b516_pc=0x57218fu;
    s.cx = m.r32((0x00a55c50u));
  }
  L00572195: { // 0x572195: 894838 MOV dword ptr [EAX + 0x38],ECX
    b516_pc=0x572195u;
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L00572198: { // 0x572198: c6801a01000000 MOV byte ptr [EAX + 0x11a],0x0
    b516_pc=0x572198u;
    m.w8((s.ax+0x0000011au), 0x00000000u);
  }
  L0057219f: { // 0x57219f: 668b4502 MOV AX,word ptr [EBP + 0x2]
    b516_pc=0x57219fu;
    s.ax = with_ax(s.ax, m.r16((s.bp+0x00000002u)));
  }
  L005721a3: { // 0x5721a3: 0fbf4f02 MOVSX ECX,word ptr [EDI + 0x2]
    b516_pc=0x5721a3u;
    s.cx = std::uint32_t(integer::sign_extend(m.r16((s.di+0x00000002u)),16));
  }
  L005721a7: { // 0x5721a7: 0fbfd0 MOVSX EDX,AX
    b516_pc=0x5721a7u;
    s.dx = std::uint32_t(integer::sign_extend((s.ax & 0xffffu),16));
  }
  L005721aa: { // 0x5721aa: 2bd1 SUB EDX,ECX
    b516_pc=0x5721aau;
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  L005721ac: { // 0x5721ac: 8d541afd LEA EDX,[EDX + EBX*0x1 + -0x3]
    b516_pc=0x5721acu;
    s.dx = (s.dx+(s.bx * 0x00000001u)-0x00000003u);
  }
  L005721b0: { // 0x5721b0: 3bf2 CMP ESI,EDX
    b516_pc=0x5721b0u;
    (void)integer::sub(s.si,s.dx,32,flags);
  }
  L005721b2: { // 0x5721b2: 7c9d JL 0x00572151
    b516_pc=0x5721b2u;
    if(integer::condition("JL",flags)) goto L00572151;
  }
  L005721b4: { // 0x5721b4: 43 INC EBX
    b516_pc=0x5721b4u;
    s.bx = integer::increment(s.bx,32,flags);
  }
  L005721b5: { // 0x5721b5: 83fb04 CMP EBX,0x4
    b516_pc=0x5721b5u;
    (void)integer::sub(s.bx,0x00000004u,32,flags);
  }
  L005721b8: { // 0x5721b8: 7c80 JL 0x0057213a
    b516_pc=0x5721b8u;
    if(integer::condition("JL",flags)) goto L0057213a;
  }
  L005721ba: { // 0x5721ba: 5f POP EDI
    b516_pc=0x5721bau;
    const auto value=f.pop(m); s.di = value;
  }
  L005721bb: { // 0x5721bb: 5e POP ESI
    b516_pc=0x5721bbu;
    const auto value=f.pop(m); s.si = value;
  }
  L005721bc: { // 0x5721bc: 5d POP EBP
    b516_pc=0x5721bcu;
    const auto value=f.pop(m); s.bp = value;
  }
  L005721bd: { // 0x5721bd: b001 MOV AL,0x1
    b516_pc=0x5721bdu;
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005721bf: { // 0x5721bf: 5b POP EBX
    b516_pc=0x5721bfu;
    const auto value=f.pop(m); s.bx = value;
  }
  L005721c0: { // 0x5721c0: 83c42c ADD ESP,0x2c
    b516_pc=0x5721c0u;
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005721c3: { // 0x5721c3: c20c00 RET 0xc
    b516_pc=0x5721c3u;
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L005721c6: { // 0x5721c6: 5f POP EDI
    b516_pc=0x5721c6u;
    const auto value=f.pop(m); s.di = value;
  }
  L005721c7: { // 0x5721c7: 5e POP ESI
    b516_pc=0x5721c7u;
    const auto value=f.pop(m); s.si = value;
  }
  L005721c8: { // 0x5721c8: 5d POP EBP
    b516_pc=0x5721c8u;
    const auto value=f.pop(m); s.bp = value;
  }
  L005721c9: { // 0x5721c9: 32c0 XOR AL,AL
    b516_pc=0x5721c9u;
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005721cb: { // 0x5721cb: 5b POP EBX
    b516_pc=0x5721cbu;
    const auto value=f.pop(m); s.bx = value;
  }
  L005721cc: { // 0x5721cc: 83c42c ADD ESP,0x2c
    b516_pc=0x5721ccu;
    f.sp = integer::add(f.sp,0x0000002cu,32,flags);
  }
  L005721cf: { // 0x5721cf: c20c00 RET 0xc
    b516_pc=0x5721cfu;
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}
} // namespace

namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 (void)continuation; floating_b61::Inputs q{};q.ax=s.ax;q.cx=s.cx;q.dx=s.dx;q.fp=s.fp;
 for(unsigned n=0;n<q.arg.size();++n)q.arg[n]=m.r32(f.sp+4u*n);
 std::uint32_t result=0,cleanup=0,writeback=0;
 switch(target){
 case 0x00572700u:result=ra2::recovered::map_b87::fun_00572700(m,q);cleanup=8;writeback=2;break;
 case 0x0058a810u:result=ra2::recovered::global_b26::fun_0058a810(m,q);break;
 case 0x0056b760u:result=ra2::recovered::global_b26::fun_0056b760(m,q);break;
 case 0x00545500u:result=ra2::recovered::global_b26::fun_00545500(m,q);cleanup=4;writeback=1;break;
 case 0x00572ad0u:result=ra2::recovered::global_b26::fun_00572ad0(m,q);break;
 case 0x005851f0u:result=ra2::recovered::map_footprint_b460::fun_005851f0(m,q);cleanup=8;writeback=2;break;
 case 0x0042ad30u:{const auto a=m.r32(f.sp),b=m.r32(f.sp+4u);m.w16(s.cx,std::uint16_t(a));m.w16(s.cx+2u,std::uint16_t(b));result=s.cx;cleanup=8;break;}
 default:throw std::domain_error("B516 unreviewed call target");}
 for(unsigned n=0;n<writeback;++n)m.w32(f.sp+4u*n,q.arg[n]);
 m.w32(f.sp-4u,continuation);s.ax=result;s.fp=q.fp;f.sp+=cleanup;
}
struct Result{std::uint32_t eax;std::array<std::uint32_t,16> args;};
Result run(Memory&original,const floating_b61::Inputs&i,void(*fn)(Memory&,State&,Frame&,const Operations&)){
 Memory m=original;
 constexpr std::uint32_t base=0x7d000000u,sp=base+0x6004u,outer=0x76543210u;
 std::array<std::uint8_t,0x8000> stack{};leaf::Memory sm(stack.data(),base,stack.size());m.add(sm);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{sp,sp,outer};m.w32(sp,outer);for(unsigned n=0;n<i.arg.size();++n)m.w32(sp+4u+n*4u,i.arg[n]);
 const Operations op{};try{fn(m,s,f,op);}catch(const std::exception&e){throw std::runtime_error("B524 pc="+std::to_string(b516_pc)+" "+e.what());}i.fp=s.fp;Result r{};r.eax=s.ax;for(unsigned n=0;n<r.args.size();++n)r.args[n]=m.r32(sp+4u+n*4u);return r;
}
}
Result fun_00571c40(Memory&m,const floating_b61::Inputs&i){return run(m,i,f_00171c40);}
}

namespace ra2::recovered::recovery_b524 {
using floating_b61::Memory;using floating_b61::Inputs;
std::uint32_t fun_00571c40(Memory&m,const Inputs&i){auto r=raster524::fun_00571c40(m,i);i.arg=r.args;return r.eax;}
}
