#include "recovered/recovery_b1644.hpp"
#include "recovered/recovery_b566_machine.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
namespace ra2::recovered::b1644 {
namespace {
using namespace floating_b61;
using State=recovery_b566::State;
using Frame=recovery_b566::Frame;
using recovery_b566::finish;
using recovery_b566::string_instruction;
using recovery_b566::Kind;
using recovery_b566::Repeat;
using recovery_b566::reverse_divide32;
using recovery_b566::reverse_divide64;
namespace integer=direct_b33::integer;
inline void need(bool ok,const char*s){if(!ok)throw std::domain_error(s);}
struct Operations{Api*api;};
// Private single root only; parent supplies B566 aliases and reviewed Operations/invoke.
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t,const Operations&);
void f_0025e250(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0065e250: { // 0x65e250: a098eaa900 MOV AL,[0x00a9ea98]
    s.ax = with_al(s.ax, m.r8((0x00a9ea98u)));
  }
  L0065e255: { // 0x65e255: 83ec24 SUB ESP,0x24
    f.sp = integer::sub(f.sp,0x00000024u,32,flags);
  }
  L0065e258: { // 0x65e258: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0065e25a: { // 0x65e25a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0065e25b: { // 0x65e25b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0065e25c: { // 0x65e25c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0065e25d: { // 0x65e25d: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0065e25f: { // 0x65e25f: 7531 JNZ 0x0065e292
    if(integer::condition("JNZ",flags)) goto L0065e292;
  }
  L0065e261: { // 0x65e261: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0065e263: { // 0x65e263: b954eaa900 MOV ECX,0xa9ea54
    s.cx = 0x00a9ea54u;
  }
  L0065e268: { // 0x65e268: 80ca01 OR DL,0x1
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))|(0x00000001u),8,flags));
  }
  L0065e26b: { // 0x65e26b: 881598eaa900 MOV byte ptr [0x00a9ea98],DL
    m.w8((0x00a9ea98u), (s.dx & 0xffu));
  }
  L0065e271: { // 0x65e271: e85a180300 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,6677110u,op); flags=s.arithmetic_flags;
  }
  L0065e276: { // 0x65e276: 68c0e36500 PUSH 0x65e3c0
    f.push(m,0x0065e3c0u);
  }
  L0065e27b: { // 0x65e27b: a350eaa900 MOV [0x00a9ea50],EAX
    m.w32((0x00a9ea50u), s.ax);
  }
  L0065e280: { // 0x65e280: c70558eaa90000000000 MOV dword ptr [0x00a9ea58],0x0
    m.w32((0x00a9ea58u), 0x00000000u);
  }
  L0065e28a: { // 0x65e28a: e83b001100 CALL 0x0076e2ca
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076e2cau,6677135u,op); flags=s.arithmetic_flags;
  }
  L0065e28f: { // 0x65e28f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0065e292: { // 0x65e292: 8b742438 MOV ESI,dword ptr [ESP + 0x38]
    s.si = m.r32((f.sp+0x00000038u));
  }
  L0065e296: { // 0x65e296: 8b7c2434 MOV EDI,dword ptr [ESP + 0x34]
    s.di = m.r32((f.sp+0x00000034u));
  }
  L0065e29a: { // 0x65e29a: a1a4eaa900 MOV EAX,[0x00a9eaa4]
    s.ax = m.r32((0x00a9eaa4u));
  }
  L0065e29f: { // 0x65e29f: 83c60e ADD ESI,0xe
    s.si = integer::add(s.si,0x0000000eu,32,flags);
  }
  L0065e2a2: { // 0x65e2a2: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  L0065e2a4: { // 0x65e2a4: 743e JZ 0x0065e2e4
    if(integer::condition("JZ",flags)) goto L0065e2e4;
  }
  L0065e2a6: { // 0x65e2a6: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L0065e2ac: { // 0x65e2ac: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0065e2ae: { // 0x65e2ae: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0065e2b2: { // 0x65e2b2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0065e2b4: { // 0x65e2b4: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065e2b5: { // 0x65e2b5: 8b15981c8200 MOV EDX,dword ptr [0x00821c98]
    s.dx = m.r32((0x00821c98u));
  }
  L0065e2bb: { // 0x65e2bb: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065e2bc: { // 0x65e2bc: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0065e2c0: { // 0x65e2c0: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0065e2c4: { // 0x65e2c4: c74424380b000000 MOV dword ptr [ESP + 0x38],0xb
    m.w32((f.sp+0x00000038u), 0x0000000bu);
  }
  L0065e2cc: { // 0x65e2cc: c744243c01000000 MOV dword ptr [ESP + 0x3c],0x1
    m.w32((f.sp+0x0000003cu), 0x00000001u);
  }
  L0065e2d4: { // 0x65e2d4: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0065e2d6: { // 0x65e2d6: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  L0065e2da: { // 0x65e2da: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0065e2db: { // 0x65e2db: ff5008 CALL dword ptr [EAX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000008u)),6677214u,op); flags=s.arithmetic_flags;
  }
  L0065e2de: { // 0x65e2de: 893da4eaa900 MOV dword ptr [0x00a9eaa4],EDI
    m.w32((0x00a9eaa4u), s.di);
  }
  L0065e2e4: { // 0x65e2e4: a188eaa900 MOV EAX,[0x00a9ea88]
    s.ax = m.r32((0x00a9ea88u));
  }
  L0065e2e9: { // 0x65e2e9: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0065e2eb: { // 0x65e2eb: 742e JZ 0x0065e31b
    if(integer::condition("JZ",flags)) goto L0065e31b;
  }
  L0065e2ed: { // 0x65e2ed: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L0065e2f3: { // 0x65e2f3: 8d470a LEA EAX,[EDI + 0xa]
    s.ax = (s.di+0x0000000au);
  }
  L0065e2f6: { // 0x65e2f6: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L0065e2fa: { // 0x65e2fa: 8b4518 MOV EAX,dword ptr [EBP + 0x18]
    s.ax = m.r32((s.bp+0x00000018u));
  }
  L0065e2fd: { // 0x65e2fd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065e2fe: { // 0x65e2fe: 8d442410 LEA EAX,[ESP + 0x10]
    s.ax = (f.sp+0x00000010u);
  }
  L0065e302: { // 0x65e302: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065e303: { // 0x65e303: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L0065e307: { // 0x65e307: 897c241c MOV dword ptr [ESP + 0x1c],EDI
    m.w32((f.sp+0x0000001cu), s.di);
  }
  L0065e30b: { // 0x65e30b: 89742420 MOV dword ptr [ESP + 0x20],ESI
    m.w32((f.sp+0x00000020u), s.si);
  }
  L0065e30f: { // 0x65e30f: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0065e311: { // 0x65e311: 8d44241c LEA EAX,[ESP + 0x1c]
    s.ax = (f.sp+0x0000001cu);
  }
  L0065e315: { // 0x65e315: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065e316: { // 0x65e316: ff5230 CALL dword ptr [EDX + 0x30]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000030u)),6677273u,op); flags=s.arithmetic_flags;
  }
  L0065e319: { // 0x65e319: eb35 JMP 0x0065e350
    goto L0065e350;
  }
  L0065e31b: { // 0x65e31b: 8b0d941c8200 MOV ECX,dword ptr [0x00821c94]
    s.cx = m.r32((0x00821c94u));
  }
  L0065e321: { // 0x65e321: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0065e323: { // 0x65e323: 8d442424 LEA EAX,[ESP + 0x24]
    s.ax = (f.sp+0x00000024u);
  }
  L0065e327: { // 0x65e327: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0065e329: { // 0x65e329: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065e32a: { // 0x65e32a: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  L0065e32d: { // 0x65e32d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065e32e: { // 0x65e32e: 897c2430 MOV dword ptr [ESP + 0x30],EDI
    m.w32((f.sp+0x00000030u), s.di);
  }
  L0065e332: { // 0x65e332: 89742434 MOV dword ptr [ESP + 0x34],ESI
    m.w32((f.sp+0x00000034u), s.si);
  }
  L0065e336: { // 0x65e336: c74424380b000000 MOV dword ptr [ESP + 0x38],0xb
    m.w32((f.sp+0x00000038u), 0x0000000bu);
  }
  L0065e33e: { // 0x65e33e: c744243c01000000 MOV dword ptr [ESP + 0x3c],0x1
    m.w32((f.sp+0x0000003cu), 0x00000001u);
  }
  L0065e346: { // 0x65e346: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L0065e348: { // 0x65e348: 8d442430 LEA EAX,[ESP + 0x30]
    s.ax = (f.sp+0x00000030u);
  }
  L0065e34c: { // 0x65e34c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0065e34d: { // 0x65e34d: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),6677328u,op); flags=s.arithmetic_flags;
  }
  L0065e350: { // 0x65e350: a150eaa900 MOV EAX,[0x00a9ea50]
    s.ax = m.r32((0x00a9ea50u));
  }
  L0065e355: { // 0x65e355: 8b3558eaa900 MOV ESI,dword ptr [0x00a9ea58]
    s.si = m.r32((0x00a9ea58u));
  }
  L0065e35b: { // 0x65e35b: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  L0065e35e: { // 0x65e35e: 7416 JZ 0x0065e376
    if(integer::condition("JZ",flags)) goto L0065e376;
  }
  L0065e360: { // 0x65e360: b954eaa900 MOV ECX,0xa9ea54
    s.cx = 0x00a9ea54u;
  }
  L0065e365: { // 0x65e365: e866170300 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,6677354u,op); flags=s.arithmetic_flags;
  }
  L0065e36a: { // 0x65e36a: 2b0550eaa900 SUB EAX,dword ptr [0x00a9ea50]
    s.ax = integer::sub(s.ax,m.r32((0x00a9ea50u)),32,flags);
  }
  L0065e370: { // 0x65e370: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  L0065e372: { // 0x65e372: 7d06 JGE 0x0065e37a
    if(integer::condition("JGE",flags)) goto L0065e37a;
  }
  L0065e374: { // 0x65e374: 2bf0 SUB ESI,EAX
    s.si = integer::sub(s.si,s.ax,32,flags);
  }
  L0065e376: { // 0x65e376: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0065e378: { // 0x65e378: 7530 JNZ 0x0065e3aa
    if(integer::condition("JNZ",flags)) goto L0065e3aa;
  }
  L0065e37a: { // 0x65e37a: a188eaa900 MOV EAX,[0x00a9ea88]
    s.ax = m.r32((0x00a9ea88u));
  }
  L0065e37f: { // 0x65e37f: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0065e383: { // 0x65e383: 83f001 XOR EAX,0x1
    s.ax = integer::logical((s.ax)^(0x00000001u),32,flags);
  }
  L0065e386: { // 0x65e386: a388eaa900 MOV [0x00a9ea88],EAX
    m.w32((0x00a9ea88u), s.ax);
  }
  L0065e38b: { // 0x65e38b: e840170300 CALL 0x0068fad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0068fad0u,6677392u,op); flags=s.arithmetic_flags;
  }
  L0065e390: { // 0x65e390: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0065e394: { // 0x65e394: b905000000 MOV ECX,0x5
    s.cx = 0x00000005u;
  }
  L0065e399: { // 0x65e399: a350eaa900 MOV [0x00a9ea50],EAX
    m.w32((0x00a9ea50u), s.ax);
  }
  L0065e39e: { // 0x65e39e: 891554eaa900 MOV dword ptr [0x00a9ea54],EDX
    m.w32((0x00a9ea54u), s.dx);
  }
  L0065e3a4: { // 0x65e3a4: 890d58eaa900 MOV dword ptr [0x00a9ea58],ECX
    m.w32((0x00a9ea58u), s.cx);
  }
  L0065e3aa: { // 0x65e3aa: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0065e3ab: { // 0x65e3ab: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0065e3ac: { // 0x65e3ac: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0065e3ad: { // 0x65e3ad: 83c424 ADD ESP,0x24
    f.sp = integer::add(f.sp,0x00000024u,32,flags);
  }
  L0065e3b0: { // 0x65e3b0: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}

// Private helper methods only; parent supplies B566 aliases and reviewed dispatch/memory bindings.
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t,const Operations&);
void f_00011290(Memory&,State&,Frame&,const Operations&);
void f_000112c0(Memory&,State&,Frame&,const Operations&);
void f_00360f60(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_0035f2c0(Memory&,State&,Frame&,const Operations&);
void f_0001fdf0(Memory&,State&,Frame&,const Operations&);
void f_0035f290(Memory&,State&,Frame&,const Operations&);

void f_00011290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00411290: { // 0x411290: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00411294: { // 0x411294: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00411295: { // 0x411295: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00411296: { // 0x411296: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00411297: { // 0x411297: 8b7904 MOV EDI,dword ptr [ECX + 0x4]
    s.di = m.r32((s.cx+0x00000004u));
  }
  L0041129a: { // 0x41129a: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L0041129d: { // 0x41129d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0041129f: { // 0x41129f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L004112a1: { // 0x4112a1: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L004112a3: { // 0x4112a3: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  L004112a5: { // 0x4112a5: 897304 MOV dword ptr [EBX + 0x4],ESI
    m.w32((s.bx+0x00000004u), s.si);
  }
  L004112a8: { // 0x4112a8: 897b08 MOV dword ptr [EBX + 0x8],EDI
    m.w32((s.bx+0x00000008u), s.di);
  }
  L004112ab: { // 0x4112ab: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L004112ac: { // 0x4112ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L004112ad: { // 0x4112ad: 894b0c MOV dword ptr [EBX + 0xc],ECX
    m.w32((s.bx+0x0000000cu), s.cx);
  }
  L004112b0: { // 0x4112b0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L004112b1: { // 0x4112b1: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_000112c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004112c0: { // 0x4112c0: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L004112c3: { // 0x4112c3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_00360f60(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00760f60: { // 0x760f60: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00760f61: { // 0x760f61: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00760f63: { // 0x760f63: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00760f66: { // 0x760f66: 83ec64 SUB ESP,0x64
    f.sp = integer::sub(f.sp,0x00000064u,32,flags);
  }
  L00760f69: { // 0x760f69: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L00760f6a: { // 0x760f6a: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00760f6b: { // 0x760f6b: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00760f6c: { // 0x760f6c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00760f6e: { // 0x760f6e: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L00760f70: { // 0x760f70: 8b4d08 MOV ECX,dword ptr [EBP + 0x8]
    s.cx = m.r32((s.bp+0x00000008u));
  }
  L00760f73: { // 0x760f73: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00760f77: { // 0x760f77: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L00760f79: { // 0x760f79: 8b7104 MOV ESI,dword ptr [ECX + 0x4]
    s.si = m.r32((s.cx+0x00000004u));
  }
  L00760f7c: { // 0x760f7c: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00760f80: { // 0x760f80: 8b5908 MOV EBX,dword ptr [ECX + 0x8]
    s.bx = m.r32((s.cx+0x00000008u));
  }
  L00760f83: { // 0x760f83: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f87: { // 0x760f87: 89742414 MOV dword ptr [ESP + 0x14],ESI
    m.w32((f.sp+0x00000014u), s.si);
  }
  L00760f8b: { // 0x760f8b: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00760f8d: { // 0x760f8d: dd542430 FST double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760f91: { // 0x760f91: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f95: { // 0x760f95: 895c2414 MOV dword ptr [ESP + 0x14],EBX
    m.w32((f.sp+0x00000014u), s.bx);
  }
  L00760f99: { // 0x760f99: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00760f9b: { // 0x760f9b: db02 FILD dword ptr [EDX]
    const auto address=(s.dx);
    s.fp.load_integer32(m.r32(address));
  }
  L00760f9d: { // 0x760f9d: dd5c2438 FSTP double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fa1: { // 0x760fa1: db4204 FILD dword ptr [EDX + 0x4]
    const auto address=(s.dx+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fa4: { // 0x760fa4: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00760fa6: { // 0x760fa6: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760faa: { // 0x760faa: db07 FILD dword ptr [EDI]
    const auto address=(s.di);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fac: { // 0x760fac: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00760fb0: { // 0x760fb0: db4704 FILD dword ptr [EDI + 0x4]
    const auto address=(s.di+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fb3: { // 0x760fb3: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fb7: { // 0x760fb7: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L00760fbb: { // 0x760fbb: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fbd: { // 0x760fbd: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00760fbf: { // 0x760fbf: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00760fc3: { // 0x760fc3: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L00760fc7: { // 0x760fc7: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00760fc9: { // 0x760fc9: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fcb: { // 0x760fcb: dd5c2458 FSTP double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fcf: { // 0x760fcf: d8f1 FDIV ST0,ST1
    numeric_b88::detail::reg<0xd8f1>(s.fp);
  }
  L00760fd1: { // 0x760fd1: dd5c2460 FSTP double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fd5: { // 0x760fd5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fd7: { // 0x760fd7: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L00760fdb: { // 0x760fdb: dd5c2448 FSTP double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00760fdf: { // 0x760fdf: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00760fe3: { // 0x760fe3: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760fe5: { // 0x760fe5: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760fe8: { // 0x760fe8: 7509 JNZ 0x00760ff3
    if(integer::condition("JNZ",flags)) goto L00760ff3;
  }
  L00760fea: { // 0x760fea: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00760fec: { // 0x760fec: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L00760ff1: { // 0x760ff1: eb0e JMP 0x00761001
    goto L00761001;
  }
  L00760ff3: { // 0x760ff3: d8dc FCOMP ST4
    numeric_b88::detail::reg<0xd8dc>(s.fp);
  }
  L00760ff5: { // 0x760ff5: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00760ff7: { // 0x760ff7: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00760ffa: { // 0x760ffa: 7405 JZ 0x00761001
    if(integer::condition("JZ",flags)) goto L00761001;
  }
  L00760ffc: { // 0x760ffc: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L00761001: { // 0x761001: 8b410c MOV EAX,dword ptr [ECX + 0xc]
    s.ax = m.r32((s.cx+0x0000000cu));
  }
  L00761004: { // 0x761004: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L00761006: { // 0x761006: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0076100a: { // 0x76100a: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L0076100e: { // 0x76100e: dd5c2450 FSTP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761012: { // 0x761012: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L00761016: { // 0x761016: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0076101a: { // 0x76101a: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076101c: { // 0x76101c: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076101f: { // 0x76101f: 7505 JNZ 0x00761026
    if(integer::condition("JNZ",flags)) goto L00761026;
  }
  L00761021: { // 0x761021: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L00761024: { // 0x761024: eb10 JMP 0x00761036
    goto L00761036;
  }
  L00761026: { // 0x761026: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L0076102a: { // 0x76102a: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076102c: { // 0x76102c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076102e: { // 0x76102e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761031: { // 0x761031: 7403 JZ 0x00761036
    if(integer::condition("JZ",flags)) goto L00761036;
  }
  L00761033: { // 0x761033: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761036: { // 0x761036: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0076103a: { // 0x76103a: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076103c: { // 0x76103c: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0076103e: { // 0x76103e: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761041: { // 0x761041: 7509 JNZ 0x0076104c
    if(integer::condition("JNZ",flags)) goto L0076104c;
  }
  L00761043: { // 0x761043: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761045: { // 0x761045: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L0076104a: { // 0x76104a: eb0e JMP 0x0076105a
    goto L0076105a;
  }
  L0076104c: { // 0x76104c: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L0076104e: { // 0x76104e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761050: { // 0x761050: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761053: { // 0x761053: 7405 JZ 0x0076105a
    if(integer::condition("JZ",flags)) goto L0076105a;
  }
  L00761055: { // 0x761055: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0076105a: { // 0x76105a: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L0076105e: { // 0x76105e: dc5c2450 FCOMP double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00761062: { // 0x761062: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761064: { // 0x761064: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761067: { // 0x761067: 7505 JNZ 0x0076106e
    if(integer::condition("JNZ",flags)) goto L0076106e;
  }
  L00761069: { // 0x761069: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L0076106c: { // 0x76106c: eb10 JMP 0x0076107e
    goto L0076107e;
  }
  L0076106e: { // 0x76106e: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761072: { // 0x761072: d8da FCOMP ST2
    numeric_b88::detail::reg<0xd8da>(s.fp);
  }
  L00761074: { // 0x761074: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761076: { // 0x761076: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761079: { // 0x761079: 7403 JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076107b: { // 0x76107b: 83c908 OR ECX,0x8
    s.cx = integer::logical((s.cx)|(0x00000008u),32,flags);
  }
  L0076107e: { // 0x76107e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761080: { // 0x761080: 7508 JNZ 0x0076108a
    if(integer::condition("JNZ",flags)) goto L0076108a;
  }
  L00761082: { // 0x761082: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00761084: { // 0x761084: 0f844f010000 JZ 0x007611d9
    if(integer::condition("JZ",flags)) goto L007611d9;
  }
  L0076108a: { // 0x76108a: 85ca TEST EDX,ECX
    (void)integer::logical((s.dx)&(s.cx),32,flags);
  }
  L0076108c: { // 0x76108c: 0f858a010000 JNZ 0x0076121c
    if(integer::condition("JNZ",flags)) goto L0076121c;
  }
  L00761092: { // 0x761092: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00761094: { // 0x761094: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00761096: { // 0x761096: 7502 JNZ 0x0076109a
    if(integer::condition("JNZ",flags)) goto L0076109a;
  }
  L00761098: { // 0x761098: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0076109a: { // 0x76109a: a808 TEST AL,0x8
    (void)integer::logical(((s.ax & 0xffu))&(0x00000008u),8,flags);
  }
  L0076109c: { // 0x76109c: 7418 JZ 0x007610b6
    if(integer::condition("JZ",flags)) goto L007610b6;
  }
  L0076109e: { // 0x76109e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610a0: { // 0x7610a0: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610a2: { // 0x7610a2: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610a6: { // 0x7610a6: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610aa: { // 0x7610aa: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610ae: { // 0x7610ae: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L007610b2: { // 0x7610b2: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610b4: { // 0x7610b4: eb72 JMP 0x00761128
    goto L00761128;
  }
  L007610b6: { // 0x7610b6: a804 TEST AL,0x4
    (void)integer::logical(((s.ax & 0xffu))&(0x00000004u),8,flags);
  }
  L007610b8: { // 0x7610b8: 741f JZ 0x007610d9
    if(integer::condition("JZ",flags)) goto L007610d9;
  }
  L007610ba: { // 0x7610ba: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  L007610be: { // 0x7610be: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610bf: { // 0x7610bf: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610c1: { // 0x7610c1: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610c5: { // 0x7610c5: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610c9: { // 0x7610c9: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L007610cb: { // 0x7610cb: dc642428 FSUB double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.subtract64(read64(m,address));
  }
  L007610cf: { // 0x7610cf: dc4c2458 FMUL double ptr [ESP + 0x58]
    const auto address=(f.sp+0x00000058u);
    s.fp.multiply64(read64(m,address));
  }
  L007610d3: { // 0x7610d3: dc442438 FADD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.add64(read64(m,address));
  }
  L007610d7: { // 0x7610d7: eb4b JMP 0x00761124
    goto L00761124;
  }
  L007610d9: { // 0x7610d9: a802 TEST AL,0x2
    (void)integer::logical(((s.ax & 0xffu))&(0x00000002u),8,flags);
  }
  L007610db: { // 0x7610db: 7431 JZ 0x0076110e
    if(integer::condition("JZ",flags)) goto L0076110e;
  }
  L007610dd: { // 0x7610dd: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L007610e1: { // 0x7610e1: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L007610e2: { // 0x7610e2: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007610e4: { // 0x7610e4: 89742418 MOV dword ptr [ESP + 0x18],ESI
    m.w32((f.sp+0x00000018u), s.si);
  }
  L007610e8: { // 0x7610e8: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L007610ec: { // 0x7610ec: dd542418 FST double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L007610f0: { // 0x7610f0: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L007610f4: { // 0x7610f4: 8b742418 MOV ESI,dword ptr [ESP + 0x18]
    s.si = m.r32((f.sp+0x00000018u));
  }
  L007610f8: { // 0x7610f8: 8b5c241c MOV EBX,dword ptr [ESP + 0x1c]
    s.bx = m.r32((f.sp+0x0000001cu));
  }
  L007610fc: { // 0x7610fc: 89742430 MOV dword ptr [ESP + 0x30],ESI
    m.w32((f.sp+0x00000030u), s.si);
  }
  L00761100: { // 0x761100: 895c2434 MOV dword ptr [ESP + 0x34],EBX
    m.w32((f.sp+0x00000034u), s.bx);
  }
  L00761104: { // 0x761104: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L00761108: { // 0x761108: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L0076110c: { // 0x76110c: eb1a JMP 0x00761128
    goto L00761128;
  }
  L0076110e: { // 0x76110e: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00761110: { // 0x761110: 7416 JZ 0x00761128
    if(integer::condition("JZ",flags)) goto L00761128;
  }
  L00761112: { // 0x761112: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761114: { // 0x761114: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761116: { // 0x761116: dc642438 FSUB double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.subtract64(read64(m,address));
  }
  L0076111a: { // 0x76111a: dc4c2460 FMUL double ptr [ESP + 0x60]
    const auto address=(f.sp+0x00000060u);
    s.fp.multiply64(read64(m,address));
  }
  L0076111e: { // 0x76111e: dc442428 FADD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.add64(read64(m,address));
  }
  L00761122: { // 0x761122: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L00761124: { // 0x761124: dd5c2430 FSTP double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761128: { // 0x761128: dd442430 FLD double ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load64(read64(m,address));
  }
  L0076112c: { // 0x76112c: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0076112e: { // 0x76112e: 7556 JNZ 0x00761186
    if(integer::condition("JNZ",flags)) goto L00761186;
  }
  L00761130: { // 0x761130: dd542438 FST double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00761134: { // 0x761134: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L00761136: { // 0x761136: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00761138: { // 0x761138: dd5c2428 FSTP double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0076113c: { // 0x76113c: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761140: { // 0x761140: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761142: { // 0x761142: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761145: { // 0x761145: 7509 JNZ 0x00761150
    if(integer::condition("JNZ",flags)) goto L00761150;
  }
  L00761147: { // 0x761147: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761149: { // 0x761149: ba02000000 MOV EDX,0x2
    s.dx = 0x00000002u;
  }
  L0076114e: { // 0x76114e: eb0e JMP 0x0076115e
    goto L0076115e;
  }
  L00761150: { // 0x761150: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L00761152: { // 0x761152: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761154: { // 0x761154: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761157: { // 0x761157: 7405 JZ 0x0076115e
    if(integer::condition("JZ",flags)) goto L0076115e;
  }
  L00761159: { // 0x761159: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L0076115e: { // 0x76115e: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761162: { // 0x761162: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761164: { // 0x761164: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761167: { // 0x761167: 7508 JNZ 0x00761171
    if(integer::condition("JNZ",flags)) goto L00761171;
  }
  L00761169: { // 0x761169: 83ca04 OR EDX,0x4
    s.dx = integer::logical((s.dx)|(0x00000004u),32,flags);
  }
  L0076116c: { // 0x76116c: e90dffffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761171: { // 0x761171: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L00761173: { // 0x761173: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761175: { // 0x761175: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00761178: { // 0x761178: 0f8400ffffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L0076117e: { // 0x76117e: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L00761181: { // 0x761181: e9f8feffff JMP 0x0076107e
    goto L0076107e;
  }
  L00761186: { // 0x761186: dd542468 FST double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0076118a: { // 0x76118a: d9c1 FLD ST1
    numeric_b88::detail::reg<0xd9c1>(s.fp);
  }
  L0076118c: { // 0x76118c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0076118e: { // 0x76118e: dd5c2440 FSTP double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L00761192: { // 0x761192: dc542448 FCOM double ptr [ESP + 0x48]
    const auto address=(f.sp+0x00000048u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00761196: { // 0x761196: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00761198: { // 0x761198: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0076119b: { // 0x76119b: 7509 JNZ 0x007611a6
    if(integer::condition("JNZ",flags)) goto L007611a6;
  }
  L0076119d: { // 0x76119d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076119f: { // 0x76119f: b902000000 MOV ECX,0x2
    s.cx = 0x00000002u;
  }
  L007611a4: { // 0x7611a4: eb0e JMP 0x007611b4
    goto L007611b4;
  }
  L007611a6: { // 0x7611a6: d8db FCOMP ST3
    numeric_b88::detail::reg<0xd8db>(s.fp);
  }
  L007611a8: { // 0x7611a8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611aa: { // 0x7611aa: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ad: { // 0x7611ad: 7405 JZ 0x007611b4
    if(integer::condition("JZ",flags)) goto L007611b4;
  }
  L007611af: { // 0x7611af: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L007611b4: { // 0x7611b4: dc542450 FCOM double ptr [ESP + 0x50]
    const auto address=(f.sp+0x00000050u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L007611b8: { // 0x7611b8: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611ba: { // 0x7611ba: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611bd: { // 0x7611bd: 7508 JNZ 0x007611c7
    if(integer::condition("JNZ",flags)) goto L007611c7;
  }
  L007611bf: { // 0x7611bf: 83c904 OR ECX,0x4
    s.cx = integer::logical((s.cx)|(0x00000004u),32,flags);
  }
  L007611c2: { // 0x7611c2: e9b7feffff JMP 0x0076107e
    goto L0076107e;
  }
  L007611c7: { // 0x7611c7: d8d1 FCOM
    numeric_b88::detail::reg<0xd8d1>(s.fp);
  }
  L007611c9: { // 0x7611c9: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L007611cb: { // 0x7611cb: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L007611ce: { // 0x7611ce: 0f84aafeffff JZ 0x0076107e
    if(integer::condition("JZ",flags)) goto L0076107e;
  }
  L007611d4: { // 0x7611d4: e9a2feffff JMP 0x0076107b
    goto L0076107b;
  }
  L007611d9: { // 0x7611d9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611db: { // 0x7611db: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611dd: { // 0x7611dd: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L007611df: { // 0x7611df: dd442438 FLD double ptr [ESP + 0x38]
    const auto address=(f.sp+0x00000038u);
    s.fp.load64(read64(m,address));
  }
  L007611e3: { // 0x7611e3: e868980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737832u,op); flags=s.arithmetic_flags;
  }
  L007611e8: { // 0x7611e8: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L007611ec: { // 0x7611ec: dd442428 FLD double ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    s.fp.load64(read64(m,address));
  }
  L007611f0: { // 0x7611f0: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L007611f2: { // 0x7611f2: e859980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737847u,op); flags=s.arithmetic_flags;
  }
  L007611f7: { // 0x7611f7: dd442468 FLD double ptr [ESP + 0x68]
    const auto address=(f.sp+0x00000068u);
    s.fp.load64(read64(m,address));
  }
  L007611fb: { // 0x7611fb: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  L007611fe: { // 0x7611fe: e84d980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737859u,op); flags=s.arithmetic_flags;
  }
  L00761203: { // 0x761203: dd442440 FLD double ptr [ESP + 0x40]
    const auto address=(f.sp+0x00000040u);
    s.fp.load64(read64(m,address));
  }
  L00761207: { // 0x761207: 8907 MOV dword ptr [EDI],EAX
    m.w32((s.di), s.ax);
  }
  L00761209: { // 0x761209: e842980000 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,7737870u,op); flags=s.arithmetic_flags;
  }
  L0076120e: { // 0x76120e: 894704 MOV dword ptr [EDI + 0x4],EAX
    m.w32((s.di+0x00000004u), s.ax);
  }
  L00761211: { // 0x761211: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L00761213: { // 0x761213: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761214: { // 0x761214: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761215: { // 0x761215: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761216: { // 0x761216: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761218: { // 0x761218: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00761219: { // 0x761219: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
  L0076121c: { // 0x76121c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0076121e: { // 0x76121e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761220: { // 0x761220: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00761221: { // 0x761221: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00761222: { // 0x761222: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00761224: { // 0x761224: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L00761226: { // 0x761226: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00761227: { // 0x761227: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00761229: { // 0x761229: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0076122a: { // 0x76122a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0036aa50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0076aa50: { // 0x76aa50: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  L0076aa53: { // 0x76aa53: d93c24 FNSTCW word ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.control();
    m.w16(address,value);
  }
  L0076aa56: { // 0x76aa56: 8d442404 LEA EAX,[ESP + 0x4]
    s.ax = (f.sp+0x00000004u);
  }
  L0076aa5a: { // 0x76aa5a: 8b1424 MOV EDX,dword ptr [ESP]
    s.dx = m.r32((f.sp));
  }
  L0076aa5d: { // 0x76aa5d: 81e2ffff0000 AND EDX,0xffff
    s.dx = integer::logical((s.dx)&(0x0000ffffu),32,flags);
  }
  L0076aa63: { // 0x76aa63: 3b15043a7c00 CMP EDX,dword ptr [0x007c3a04]
    (void)integer::sub(s.dx,m.r32((0x007c3a04u)),32,flags);
  }
  L0076aa69: { // 0x76aa69: 750b JNZ 0x0076aa76
    if(integer::condition("JNZ",flags)) goto L0076aa76;
  }
  L0076aa6b: { // 0x76aa6b: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa6d: { // 0x76aa6d: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa70: { // 0x76aa70: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa72: { // 0x76aa72: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa75: { // 0x76aa75: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0076aa76: { // 0x76aa76: 8b15043a7c00 MOV EDX,dword ptr [0x007c3a04]
    s.dx = m.r32((0x007c3a04u));
  }
  L0076aa7c: { // 0x76aa7c: 891424 MOV dword ptr [ESP],EDX
    m.w32((f.sp), s.dx);
  }
  L0076aa7f: { // 0x76aa7f: d92c24 FLDCW word ptr [ESP]
    const auto address=(f.sp);
    s.fp.load_control(m.r16(address));
  }
  L0076aa82: { // 0x76aa82: df38 FISTP qword ptr [EAX]
    const auto address=(s.ax);
    const auto value=s.fp.pop_integer64();
    write64(m,address,value);
  }
  L0076aa84: { // 0x76aa84: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0076aa87: { // 0x76aa87: 8b00 MOV EAX,dword ptr [EAX]
    s.ax = m.r32((s.ax));
  }
  L0076aa89: { // 0x76aa89: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  L0076aa8c: { // 0x76aa8c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}

void f_0035f2c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f2c0: { // 0x75f2c0: 83ec44 SUB ESP,0x44
    f.sp = integer::sub(f.sp,0x00000044u,32,flags);
  }
  L0075f2c3: { // 0x75f2c3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0075f2c4: { // 0x75f2c4: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0075f2c6: { // 0x75f2c6: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0075f2c7: { // 0x75f2c7: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075f2c8: { // 0x75f2c8: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f2ca: { // 0x75f2ca: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  L0075f2ce: { // 0x75f2ce: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0075f2cf: { // 0x75f2cf: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2d0: { // 0x75f2d0: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f2d2: { // 0x75f2d2: ff5078 CALL dword ptr [EAX + 0x78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7729877u,op); flags=s.arithmetic_flags;
  }
  L0075f2d5: { // 0x75f2d5: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  L0075f2d9: { // 0x75f2d9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075f2db: { // 0x75f2db: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0075f2dd: { // 0x75f2dd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2de: { // 0x75f2de: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L0075f2e2: { // 0x75f2e2: e8090bccff CALL 0x0041fdf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0041fdf0u,7729895u,op); flags=s.arithmetic_flags;
  }
  L0075f2e7: { // 0x75f2e7: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L0075f2e9: { // 0x75f2e9: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0075f2ed: { // 0x75f2ed: 8b7004 MOV ESI,dword ptr [EAX + 0x4]
    s.si = m.r32((s.ax+0x00000004u));
  }
  L0075f2f0: { // 0x75f2f0: 89742428 MOV dword ptr [ESP + 0x28],ESI
    m.w32((f.sp+0x00000028u), s.si);
  }
  L0075f2f4: { // 0x75f2f4: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L0075f2f7: { // 0x75f2f7: 894c242c MOV dword ptr [ESP + 0x2c],ECX
    m.w32((f.sp+0x0000002cu), s.cx);
  }
  L0075f2fb: { // 0x75f2fb: 8b4c245c MOV ECX,dword ptr [ESP + 0x5c]
    s.cx = m.r32((f.sp+0x0000005cu));
  }
  L0075f2ff: { // 0x75f2ff: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0075f302: { // 0x75f302: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L0075f306: { // 0x75f306: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0075f308: { // 0x75f308: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0075f30b: { // 0x75f30b: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0075f30d: { // 0x75f30d: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f30f: { // 0x75f30f: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L0075f313: { // 0x75f313: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L0075f317: { // 0x75f317: 8b4c2460 MOV ECX,dword ptr [ESP + 0x60]
    s.cx = m.r32((f.sp+0x00000060u));
  }
  L0075f31b: { // 0x75f31b: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0075f31d: { // 0x75f31d: 8b4904 MOV ECX,dword ptr [ECX + 0x4]
    s.cx = m.r32((s.cx+0x00000004u));
  }
  L0075f320: { // 0x75f320: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f322: { // 0x75f322: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0075f324: { // 0x75f324: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0075f328: { // 0x75f328: 8d4c2424 LEA ECX,[ESP + 0x24]
    s.cx = (f.sp+0x00000024u);
  }
  L0075f32c: { // 0x75f32c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f32d: { // 0x75f32d: 8d542420 LEA EDX,[ESP + 0x20]
    s.dx = (f.sp+0x00000020u);
  }
  L0075f331: { // 0x75f331: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L0075f335: { // 0x75f335: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L0075f339: { // 0x75f339: e8221c0000 CALL 0x00760f60
    s.arithmetic_flags=flags; invoke(m,s,f,0x00760f60u,7729982u,op); flags=s.arithmetic_flags;
  }
  L0075f33e: { // 0x75f33e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0075f340: { // 0x75f340: 0f841b020000 JZ 0x0075f561
    if(integer::condition("JZ",flags)) goto L0075f561;
  }
  L0075f346: { // 0x75f346: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L0075f34a: { // 0x75f34a: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0075f34e: { // 0x75f34e: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f350: { // 0x75f350: 7e18 JLE 0x0075f36a
    if(integer::condition("JLE",flags)) goto L0075f36a;
  }
  L0075f352: { // 0x75f352: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0075f356: { // 0x75f356: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L0075f35a: { // 0x75f35a: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  L0075f35e: { // 0x75f35e: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L0075f362: { // 0x75f362: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0075f366: { // 0x75f366: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L0075f36a: { // 0x75f36a: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f36c: { // 0x75f36c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f36e: { // 0x75f36e: ff5070 CALL dword ptr [EAX + 0x70]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000070u)),7730033u,op); flags=s.arithmetic_flags;
  }
  L0075f371: { // 0x75f371: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0075f375: { // 0x75f375: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f377: { // 0x75f377: 8be8 MOV EBP,EAX
    s.bp = s.ax;
  }
  L0075f379: { // 0x75f379: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  L0075f37d: { // 0x75f37d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f37e: { // 0x75f37e: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f37f: { // 0x75f37f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f381: { // 0x75f381: 896c2464 MOV dword ptr [ESP + 0x64],EBP
    m.w32((f.sp+0x00000064u), s.bp);
  }
  L0075f385: { // 0x75f385: ff525c CALL dword ptr [EDX + 0x5c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000005cu)),7730056u,op); flags=s.arithmetic_flags;
  }
  L0075f388: { // 0x75f388: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0075f38a: { // 0x75f38a: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0075f38c: { // 0x75f38c: 0f84cf010000 JZ 0x0075f561
    if(integer::condition("JZ",flags)) goto L0075f561;
  }
  L0075f392: { // 0x75f392: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0075f396: { // 0x75f396: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0075f39a: { // 0x75f39a: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0075f39c: { // 0x75f39c: 757f JNZ 0x0075f41d
    if(integer::condition("JNZ",flags)) goto L0075f41d;
  }
  L0075f39e: { // 0x75f39e: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L0075f3a1: { // 0x75f3a1: 753c JNZ 0x0075f3df
    if(integer::condition("JNZ",flags)) goto L0075f3df;
  }
  L0075f3a3: { // 0x75f3a3: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3a7: { // 0x75f3a7: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f3ab: { // 0x75f3ab: 8a442464 MOV AL,byte ptr [ESP + 0x64]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000064u)));
  }
  L0075f3af: { // 0x75f3af: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0075f3b1: { // 0x75f3b1: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L0075f3b3: { // 0x75f3b3: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0075f3b4: { // 0x75f3b4: 8af2 MOV DH,DL
    s.dx = (s.dx & 0xffff00ffu) | ((((s.dx & 0xffu)) & 0xffu) << 8);
  }
  L0075f3b6: { // 0x75f3b6: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0075f3b8: { // 0x75f3b8: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0075f3ba: { // 0x75f3ba: c1e010 SHL EAX,0x10
    s.ax = integer::shift(s.ax,0x00000010u,32,flags,integer::Shift::left);
  }
  L0075f3bd: { // 0x75f3bd: 668bc2 MOV AX,DX
    s.ax = with_ax(s.ax, (s.dx & 0xffffu));
  }
  L0075f3c0: { // 0x75f3c0: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L0075f3c3: { // 0x75f3c3: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  L0075f3c5: { // 0x75f3c5: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075f3c7: { // 0x75f3c7: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L0075f3ca: { // 0x75f3ca: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  L0075f3cc: { // 0x75f3cc: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f3ce: { // 0x75f3ce: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f3d0: { // 0x75f3d0: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730131u,op); flags=s.arithmetic_flags;
  }
  L0075f3d3: { // 0x75f3d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f3d4: { // 0x75f3d4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f3d5: { // 0x75f3d5: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f3d6: { // 0x75f3d6: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f3d8: { // 0x75f3d8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f3d9: { // 0x75f3d9: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f3dc: { // 0x75f3dc: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f3df: { // 0x75f3df: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3e3: { // 0x75f3e3: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f3e7: { // 0x75f3e7: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0075f3e9: { // 0x75f3e9: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L0075f3eb: { // 0x75f3eb: 0f885d010000 JS 0x0075f54e
    if(integer::condition("JS",flags)) goto L0075f54e;
  }
  L0075f3f1: { // 0x75f3f1: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L0075f3f5: { // 0x75f3f5: 66890f MOV word ptr [EDI],CX
    m.w16((s.di), (s.cx & 0xffffu));
  }
  L0075f3f8: { // 0x75f3f8: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  L0075f3fc: { // 0x75f3fc: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  L0075f400: { // 0x75f400: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0075f401: { // 0x75f401: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L0075f403: { // 0x75f403: 83c702 ADD EDI,0x2
    s.di = integer::add(s.di,0x00000002u,32,flags);
  }
  L0075f406: { // 0x75f406: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f408: { // 0x75f408: 7eeb JLE 0x0075f3f5
    if(integer::condition("JLE",flags)) goto L0075f3f5;
  }
  L0075f40a: { // 0x75f40a: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f40c: { // 0x75f40c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f40e: { // 0x75f40e: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730193u,op); flags=s.arithmetic_flags;
  }
  L0075f411: { // 0x75f411: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f412: { // 0x75f412: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f413: { // 0x75f413: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f414: { // 0x75f414: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f416: { // 0x75f416: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f417: { // 0x75f417: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f41a: { // 0x75f41a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f41d: { // 0x75f41d: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0075f421: { // 0x75f421: 8b4c241c MOV ECX,dword ptr [ESP + 0x1c]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f425: { // 0x75f425: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  L0075f427: { // 0x75f427: 755a JNZ 0x0075f483
    if(integer::condition("JNZ",flags)) goto L0075f483;
  }
  L0075f429: { // 0x75f429: 3bd0 CMP EDX,EAX
    (void)integer::sub(s.dx,s.ax,32,flags);
  }
  L0075f42b: { // 0x75f42b: 7e0d JLE 0x0075f43a
    if(integer::condition("JLE",flags)) goto L0075f43a;
  }
  L0075f42d: { // 0x75f42d: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f42f: { // 0x75f42f: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f431: { // 0x75f431: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730228u,op); flags=s.arithmetic_flags;
  }
  L0075f434: { // 0x75f434: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0075f436: { // 0x75f436: f7d9 NEG ECX
    s.cx = integer::sub(0u,s.cx,32,flags);
  }
  L0075f438: { // 0x75f438: eb09 JMP 0x0075f443
    goto L0075f443;
  }
  L0075f43a: { // 0x75f43a: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f43c: { // 0x75f43c: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f43e: { // 0x75f43e: ff5274 CALL dword ptr [EDX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000074u)),7730241u,op); flags=s.arithmetic_flags;
  }
  L0075f441: { // 0x75f441: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0075f443: { // 0x75f443: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  L0075f447: { // 0x75f447: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0075f44b: { // 0x75f44b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f44d: { // 0x75f44d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0075f44e: { // 0x75f44e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0075f450: { // 0x75f450: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f452: { // 0x75f452: 0f88f6000000 JS 0x0075f54e
    if(integer::condition("JS",flags)) goto L0075f54e;
  }
  L0075f458: { // 0x75f458: 8d5001 LEA EDX,[EAX + 0x1]
    s.dx = (s.ax+0x00000001u);
  }
  L0075f45b: { // 0x75f45b: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f45f: { // 0x75f45f: 83fd01 CMP EBP,0x1
    (void)integer::sub(s.bp,0x00000001u,32,flags);
  }
  L0075f462: { // 0x75f462: 7504 JNZ 0x0075f468
    if(integer::condition("JNZ",flags)) goto L0075f468;
  }
  L0075f464: { // 0x75f464: 8807 MOV byte ptr [EDI],AL
    m.w8((s.di), (s.ax & 0xffu));
  }
  L0075f466: { // 0x75f466: eb03 JMP 0x0075f46b
    goto L0075f46b;
  }
  L0075f468: { // 0x75f468: 668907 MOV word ptr [EDI],AX
    m.w16((s.di), (s.ax & 0xffffu));
  }
  L0075f46b: { // 0x75f46b: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  L0075f46d: { // 0x75f46d: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L0075f46e: { // 0x75f46e: 75ef JNZ 0x0075f45f
    if(integer::condition("JNZ",flags)) goto L0075f45f;
  }
  L0075f470: { // 0x75f470: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f472: { // 0x75f472: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f474: { // 0x75f474: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730295u,op); flags=s.arithmetic_flags;
  }
  L0075f477: { // 0x75f477: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f478: { // 0x75f478: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f479: { // 0x75f479: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f47a: { // 0x75f47a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f47c: { // 0x75f47c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f47d: { // 0x75f47d: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f480: { // 0x75f480: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f483: { // 0x75f483: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f485: { // 0x75f485: 2bce SUB ECX,ESI
    s.cx = integer::sub(s.cx,s.si,32,flags);
  }
  L0075f487: { // 0x75f487: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0075f489: { // 0x75f489: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L0075f48b: { // 0x75f48b: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0075f48d: { // 0x75f48d: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f48f: { // 0x75f48f: ff5074 CALL dword ptr [EAX + 0x74]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000074u)),7730322u,op); flags=s.arithmetic_flags;
  }
  L0075f492: { // 0x75f492: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0075f494: { // 0x75f494: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0075f498: { // 0x75f498: 7d06 JGE 0x0075f4a0
    if(integer::condition("JGE",flags)) goto L0075f4a0;
  }
  L0075f49a: { // 0x75f49a: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  L0075f49c: { // 0x75f49c: 89442458 MOV dword ptr [ESP + 0x58],EAX
    m.w32((f.sp+0x00000058u), s.ax);
  }
  L0075f4a0: { // 0x75f4a0: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0075f4a2: { // 0x75f4a2: 8d742d00 LEA ESI,[EBP + EBP*0x1]
    s.si = (s.bp+(s.bp * 0x00000001u));
  }
  L0075f4a6: { // 0x75f4a6: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0075f4a7: { // 0x75f4a7: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L0075f4a9: { // 0x75f4a9: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0075f4ab: { // 0x75f4ab: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  L0075f4ad: { // 0x75f4ad: 8d0c00 LEA ECX,[EAX + EAX*0x1]
    s.cx = (s.ax+(s.ax * 0x00000001u));
  }
  L0075f4b0: { // 0x75f4b0: 894c2460 MOV dword ptr [ESP + 0x60],ECX
    m.w32((f.sp+0x00000060u), s.cx);
  }
  L0075f4b4: { // 0x75f4b4: 7e54 JLE 0x0075f50a
    if(integer::condition("JLE",flags)) goto L0075f50a;
  }
  L0075f4b6: { // 0x75f4b6: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0075f4b8: { // 0x75f4b8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0075f4ba: { // 0x75f4ba: 2bc5 SUB EAX,EBP
    s.ax = integer::sub(s.ax,s.bp,32,flags);
  }
  L0075f4bc: { // 0x75f4bc: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0075f4be: { // 0x75f4be: 0f8e8a000000 JLE 0x0075f54e
    if(integer::condition("JLE",flags)) goto L0075f54e;
  }
  L0075f4c4: { // 0x75f4c4: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0075f4c8: { // 0x75f4c8: 837c245c01 CMP dword ptr [ESP + 0x5c],0x1
    (void)integer::sub(m.r32((f.sp+0x0000005cu)),0x00000001u,32,flags);
  }
  L0075f4cd: { // 0x75f4cd: 7505 JNZ 0x0075f4d4
    if(integer::condition("JNZ",flags)) goto L0075f4d4;
  }
  L0075f4cf: { // 0x75f4cf: 881439 MOV byte ptr [ECX + EDI*0x1],DL
    m.w8((s.cx+(s.di * 0x00000001u)), (s.dx & 0xffu));
  }
  L0075f4d2: { // 0x75f4d2: eb08 JMP 0x0075f4dc
    goto L0075f4dc;
  }
  L0075f4d4: { // 0x75f4d4: 6689144f MOV word ptr [EDI + ECX*0x2],DX
    m.w16((s.di+(s.cx * 0x00000002u)), (s.dx & 0xffffu));
  }
  L0075f4d8: { // 0x75f4d8: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  L0075f4dc: { // 0x75f4dc: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075f4de: { // 0x75f4de: 7e0c JLE 0x0075f4ec
    if(integer::condition("JLE",flags)) goto L0075f4ec;
  }
  L0075f4e0: { // 0x75f4e0: 8b742458 MOV ESI,dword ptr [ESP + 0x58]
    s.si = m.r32((f.sp+0x00000058u));
  }
  L0075f4e4: { // 0x75f4e4: 03fe ADD EDI,ESI
    s.di = integer::add(s.di,s.si,32,flags);
  }
  L0075f4e6: { // 0x75f4e6: 8d742d00 LEA ESI,[EBP + EBP*0x1]
    s.si = (s.bp+(s.bp * 0x00000001u));
  }
  L0075f4ea: { // 0x75f4ea: 2bc6 SUB EAX,ESI
    s.ax = integer::sub(s.ax,s.si,32,flags);
  }
  L0075f4ec: { // 0x75f4ec: 8b742460 MOV ESI,dword ptr [ESP + 0x60]
    s.si = m.r32((f.sp+0x00000060u));
  }
  L0075f4f0: { // 0x75f4f0: 03c6 ADD EAX,ESI
    s.ax = integer::add(s.ax,s.si,32,flags);
  }
  L0075f4f2: { // 0x75f4f2: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0075f4f3: { // 0x75f4f3: 3bcd CMP ECX,EBP
    (void)integer::sub(s.cx,s.bp,32,flags);
  }
  L0075f4f5: { // 0x75f4f5: 7cd1 JL 0x0075f4c8
    if(integer::condition("JL",flags)) goto L0075f4c8;
  }
  L0075f4f7: { // 0x75f4f7: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f4f9: { // 0x75f4f9: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f4fb: { // 0x75f4fb: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730430u,op); flags=s.arithmetic_flags;
  }
  L0075f4fe: { // 0x75f4fe: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f4ff: { // 0x75f4ff: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f500: { // 0x75f500: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f501: { // 0x75f501: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f503: { // 0x75f503: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f504: { // 0x75f504: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f507: { // 0x75f507: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f50a: { // 0x75f50a: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0075f50c: { // 0x75f50c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0075f50e: { // 0x75f50e: 2bc8 SUB ECX,EAX
    s.cx = integer::sub(s.cx,s.ax,32,flags);
  }
  L0075f510: { // 0x75f510: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0075f512: { // 0x75f512: 7e3a JLE 0x0075f54e
    if(integer::condition("JLE",flags)) goto L0075f54e;
  }
  L0075f514: { // 0x75f514: 89442410 MOV dword ptr [ESP + 0x10],EAX
    m.w32((f.sp+0x00000010u), s.ax);
  }
  L0075f518: { // 0x75f518: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f51c: { // 0x75f51c: 837c245c01 CMP dword ptr [ESP + 0x5c],0x1
    (void)integer::sub(m.r32((f.sp+0x0000005cu)),0x00000001u,32,flags);
  }
  L0075f521: { // 0x75f521: 7505 JNZ 0x0075f528
    if(integer::condition("JNZ",flags)) goto L0075f528;
  }
  L0075f523: { // 0x75f523: 88043a MOV byte ptr [EDX + EDI*0x1],AL
    m.w8((s.dx+(s.di * 0x00000001u)), (s.ax & 0xffu));
  }
  L0075f526: { // 0x75f526: eb08 JMP 0x0075f530
    goto L0075f530;
  }
  L0075f528: { // 0x75f528: 66890457 MOV word ptr [EDI + EDX*0x2],AX
    m.w16((s.di+(s.dx * 0x00000002u)), (s.ax & 0xffffu));
  }
  L0075f52c: { // 0x75f52c: 8b442464 MOV EAX,dword ptr [ESP + 0x64]
    s.ax = m.r32((f.sp+0x00000064u));
  }
  L0075f530: { // 0x75f530: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0075f532: { // 0x75f532: 7e07 JLE 0x0075f53b
    if(integer::condition("JLE",flags)) goto L0075f53b;
  }
  L0075f534: { // 0x75f534: 8b6c2460 MOV EBP,dword ptr [ESP + 0x60]
    s.bp = m.r32((f.sp+0x00000060u));
  }
  L0075f538: { // 0x75f538: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0075f539: { // 0x75f539: 2bcd SUB ECX,EBP
    s.cx = integer::sub(s.cx,s.bp,32,flags);
  }
  L0075f53b: { // 0x75f53b: 8b6c2458 MOV EBP,dword ptr [ESP + 0x58]
    s.bp = m.r32((f.sp+0x00000058u));
  }
  L0075f53f: { // 0x75f53f: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0075f541: { // 0x75f541: 03fd ADD EDI,EBP
    s.di = integer::add(s.di,s.bp,32,flags);
  }
  L0075f543: { // 0x75f543: 8b6c2410 MOV EBP,dword ptr [ESP + 0x10]
    s.bp = m.r32((f.sp+0x00000010u));
  }
  L0075f547: { // 0x75f547: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  L0075f548: { // 0x75f548: 896c2410 MOV dword ptr [ESP + 0x10],EBP
    m.w32((f.sp+0x00000010u), s.bp);
  }
  L0075f54c: { // 0x75f54c: 75ce JNZ 0x0075f51c
    if(integer::condition("JNZ",flags)) goto L0075f51c;
  }
  L0075f54e: { // 0x75f54e: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L0075f550: { // 0x75f550: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  L0075f552: { // 0x75f552: ff5260 CALL dword ptr [EDX + 0x60]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000060u)),7730517u,op); flags=s.arithmetic_flags;
  }
  L0075f555: { // 0x75f555: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f556: { // 0x75f556: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f557: { // 0x75f557: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f558: { // 0x75f558: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L0075f55a: { // 0x75f55a: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f55b: { // 0x75f55b: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f55e: { // 0x75f55e: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
  L0075f561: { // 0x75f561: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0075f562: { // 0x75f562: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f563: { // 0x75f563: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0075f564: { // 0x75f564: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L0075f566: { // 0x75f566: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075f567: { // 0x75f567: 83c444 ADD ESP,0x44
    f.sp = integer::add(f.sp,0x00000044u,32,flags);
  }
  L0075f56a: { // 0x75f56a: c21000 RET 0x10
    s.arithmetic_flags=flags; finish(m,s,f,16u); return;
  }
}

void f_0001fdf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041fdf0: { // 0x41fdf0: 83ec18 SUB ESP,0x18
    f.sp = integer::sub(f.sp,0x00000018u,32,flags);
  }
  L0041fdf3: { // 0x41fdf3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041fdf5: { // 0x41fdf5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0041fdf6: { // 0x41fdf6: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fdfa: { // 0x41fdfa: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041fdfb: { // 0x41fdfb: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041fdfc: { // 0x41fdfc: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041fdfe: { // 0x41fdfe: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041fdff: { // 0x41fdff: 8b1e MOV EBX,dword ptr [ESI]
    s.bx = m.r32((s.si));
  }
  L0041fe01: { // 0x41fe01: 8b7e04 MOV EDI,dword ptr [ESI + 0x4]
    s.di = m.r32((s.si+0x00000004u));
  }
  L0041fe04: { // 0x41fe04: 8b6e08 MOV EBP,dword ptr [ESI + 0x8]
    s.bp = m.r32((s.si+0x00000008u));
  }
  L0041fe07: { // 0x41fe07: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe0b: { // 0x41fe0b: 8b760c MOV ESI,dword ptr [ESI + 0xc]
    s.si = m.r32((s.si+0x0000000cu));
  }
  L0041fe0e: { // 0x41fe0e: 89742424 MOV dword ptr [ESP + 0x24],ESI
    m.w32((f.sp+0x00000024u), s.si);
  }
  L0041fe12: { // 0x41fe12: 8b7208 MOV ESI,dword ptr [EDX + 0x8]
    s.si = m.r32((s.dx+0x00000008u));
  }
  L0041fe15: { // 0x41fe15: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L0041fe17: { // 0x41fe17: 0f8edb000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe1d: { // 0x41fe1d: 8b6a0c MOV EBP,dword ptr [EDX + 0xc]
    s.bp = m.r32((s.dx+0x0000000cu));
  }
  L0041fe20: { // 0x41fe20: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe22: { // 0x41fe22: 896c2414 MOV dword ptr [ESP + 0x14],EBP
    m.w32((f.sp+0x00000014u), s.bp);
  }
  L0041fe26: { // 0x41fe26: 0f8ecc000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe2c: { // 0x41fe2c: 8b6908 MOV EBP,dword ptr [ECX + 0x8]
    s.bp = m.r32((s.cx+0x00000008u));
  }
  L0041fe2f: { // 0x41fe2f: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe31: { // 0x41fe31: 0f8ec1000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe37: { // 0x41fe37: 8b690c MOV EBP,dword ptr [ECX + 0xc]
    s.bp = m.r32((s.cx+0x0000000cu));
  }
  L0041fe3a: { // 0x41fe3a: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  L0041fe3c: { // 0x41fe3c: 0f8eb6000000 JLE 0x0041fef8
    if(integer::condition("JLE",flags)) goto L0041fef8;
  }
  L0041fe42: { // 0x41fe42: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  L0041fe44: { // 0x41fe44: 3bd9 CMP EBX,ECX
    (void)integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe46: { // 0x41fe46: 7d0e JGE 0x0041fe56
    if(integer::condition("JGE",flags)) goto L0041fe56;
  }
  L0041fe48: { // 0x41fe48: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe4c: { // 0x41fe4c: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  L0041fe4e: { // 0x41fe4e: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe50: { // 0x41fe50: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0041fe52: { // 0x41fe52: 896c2420 MOV dword ptr [ESP + 0x20],EBP
    m.w32((f.sp+0x00000020u), s.bp);
  }
  L0041fe56: { // 0x41fe56: 837c242001 CMP dword ptr [ESP + 0x20],0x1
    (void)integer::sub(m.r32((f.sp+0x00000020u)),0x00000001u,32,flags);
  }
  L0041fe5b: { // 0x41fe5b: 0f8c97000000 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe61: { // 0x41fe61: 8b5204 MOV EDX,dword ptr [EDX + 0x4]
    s.dx = m.r32((s.dx+0x00000004u));
  }
  L0041fe64: { // 0x41fe64: 3bfa CMP EDI,EDX
    (void)integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe66: { // 0x41fe66: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L0041fe6a: { // 0x41fe6a: 7d0e JGE 0x0041fe7a
    if(integer::condition("JGE",flags)) goto L0041fe7a;
  }
  L0041fe6c: { // 0x41fe6c: 8b6c2424 MOV EBP,dword ptr [ESP + 0x24]
    s.bp = m.r32((f.sp+0x00000024u));
  }
  L0041fe70: { // 0x41fe70: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  L0041fe72: { // 0x41fe72: 03ef ADD EBP,EDI
    s.bp = integer::add(s.bp,s.di,32,flags);
  }
  L0041fe74: { // 0x41fe74: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0041fe76: { // 0x41fe76: 896c2424 MOV dword ptr [ESP + 0x24],EBP
    m.w32((f.sp+0x00000024u), s.bp);
  }
  L0041fe7a: { // 0x41fe7a: 837c242401 CMP dword ptr [ESP + 0x24],0x1
    (void)integer::sub(m.r32((f.sp+0x00000024u)),0x00000001u,32,flags);
  }
  L0041fe7f: { // 0x41fe7f: 7c77 JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe81: { // 0x41fe81: 8b6c2420 MOV EBP,dword ptr [ESP + 0x20]
    s.bp = m.r32((f.sp+0x00000020u));
  }
  L0041fe85: { // 0x41fe85: 8d1431 LEA EDX,[ECX + ESI*0x1]
    s.dx = (s.cx+(s.si * 0x00000001u));
  }
  L0041fe88: { // 0x41fe88: 03eb ADD EBP,EBX
    s.bp = integer::add(s.bp,s.bx,32,flags);
  }
  L0041fe8a: { // 0x41fe8a: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041fe8c: { // 0x41fe8c: 7e06 JLE 0x0041fe94
    if(integer::condition("JLE",flags)) goto L0041fe94;
  }
  L0041fe8e: { // 0x41fe8e: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0041fe90: { // 0x41fe90: 03ce ADD ECX,ESI
    s.cx = integer::add(s.cx,s.si,32,flags);
  }
  L0041fe92: { // 0x41fe92: eb04 JMP 0x0041fe98
    goto L0041fe98;
  }
  L0041fe94: { // 0x41fe94: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L0041fe98: { // 0x41fe98: 83f901 CMP ECX,0x1
    (void)integer::sub(s.cx,0x00000001u,32,flags);
  }
  L0041fe9b: { // 0x41fe9b: 7c5b JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041fe9d: { // 0x41fe9d: 8b542410 MOV EDX,dword ptr [ESP + 0x10]
    s.dx = m.r32((f.sp+0x00000010u));
  }
  L0041fea1: { // 0x41fea1: 8b742414 MOV ESI,dword ptr [ESP + 0x14]
    s.si = m.r32((f.sp+0x00000014u));
  }
  L0041fea5: { // 0x41fea5: 03d6 ADD EDX,ESI
    s.dx = integer::add(s.dx,s.si,32,flags);
  }
  L0041fea7: { // 0x41fea7: 8b742424 MOV ESI,dword ptr [ESP + 0x24]
    s.si = m.r32((f.sp+0x00000024u));
  }
  L0041feab: { // 0x41feab: 8d2c3e LEA EBP,[ESI + EDI*0x1]
    s.bp = (s.si+(s.di * 0x00000001u));
  }
  L0041feae: { // 0x41feae: 3bea CMP EBP,EDX
    (void)integer::sub(s.bp,s.dx,32,flags);
  }
  L0041feb0: { // 0x41feb0: 7e04 JLE 0x0041feb6
    if(integer::condition("JLE",flags)) goto L0041feb6;
  }
  L0041feb2: { // 0x41feb2: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  L0041feb4: { // 0x41feb4: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0041feb6: { // 0x41feb6: 83fe01 CMP ESI,0x1
    (void)integer::sub(s.si,0x00000001u,32,flags);
  }
  L0041feb9: { // 0x41feb9: 7c3d JL 0x0041fef8
    if(integer::condition("JL",flags)) goto L0041fef8;
  }
  L0041febb: { // 0x41febb: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L0041febf: { // 0x41febf: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fec1: { // 0x41fec1: 740b JZ 0x0041fece
    if(integer::condition("JZ",flags)) goto L0041fece;
  }
  L0041fec3: { // 0x41fec3: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041fec7: { // 0x41fec7: 8b6d00 MOV EBP,dword ptr [EBP]
    s.bp = m.r32((s.bp));
  }
  L0041feca: { // 0x41feca: 2beb SUB EBP,EBX
    s.bp = integer::sub(s.bp,s.bx,32,flags);
  }
  L0041fecc: { // 0x41fecc: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fece: { // 0x41fece: 8b542434 MOV EDX,dword ptr [ESP + 0x34]
    s.dx = m.r32((f.sp+0x00000034u));
  }
  L0041fed2: { // 0x41fed2: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041fed4: { // 0x41fed4: 740b JZ 0x0041fee1
    if(integer::condition("JZ",flags)) goto L0041fee1;
  }
  L0041fed6: { // 0x41fed6: 8b6c242c MOV EBP,dword ptr [ESP + 0x2c]
    s.bp = m.r32((f.sp+0x0000002cu));
  }
  L0041feda: { // 0x41feda: 8b6d04 MOV EBP,dword ptr [EBP + 0x4]
    s.bp = m.r32((s.bp+0x00000004u));
  }
  L0041fedd: { // 0x41fedd: 2bef SUB EBP,EDI
    s.bp = integer::sub(s.bp,s.di,32,flags);
  }
  L0041fedf: { // 0x41fedf: 012a ADD dword ptr [EDX],EBP
    m.w32((s.dx), integer::add(m.r32((s.dx)),s.bp,32,flags));
  }
  L0041fee1: { // 0x41fee1: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fee3: { // 0x41fee3: 891a MOV dword ptr [EDX],EBX
    m.w32((s.dx), s.bx);
  }
  L0041fee5: { // 0x41fee5: 897a04 MOV dword ptr [EDX + 0x4],EDI
    m.w32((s.dx+0x00000004u), s.di);
  }
  L0041fee8: { // 0x41fee8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fee9: { // 0x41fee9: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041feec: { // 0x41feec: 89720c MOV dword ptr [EDX + 0xc],ESI
    m.w32((s.dx+0x0000000cu), s.si);
  }
  L0041feef: { // 0x41feef: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fef0: { // 0x41fef0: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041fef1: { // 0x41fef1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041fef2: { // 0x41fef2: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041fef5: { // 0x41fef5: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
  L0041fef8: { // 0x41fef8: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L0041fefa: { // 0x41fefa: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0041fefc: { // 0x41fefc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041fefd: { // 0x41fefd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041fefe: { // 0x41fefe: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  L0041ff00: { // 0x41ff00: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ff01: { // 0x41ff01: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0041ff02: { // 0x41ff02: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L0041ff05: { // 0x41ff05: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0041ff08: { // 0x41ff08: 894a0c MOV dword ptr [EDX + 0xc],ECX
    m.w32((s.dx+0x0000000cu), s.cx);
  }
  L0041ff0b: { // 0x41ff0b: 83c418 ADD ESP,0x18
    f.sp = integer::add(f.sp,0x00000018u,32,flags);
  }
  L0041ff0e: { // 0x41ff0e: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

void f_0035f290(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0075f290: { // 0x75f290: 8b44240c MOV EAX, DWORD PTR [ESP + 0XC]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  L0075f294: { // 0x75f294: 83ec10 SUB ESP, 0X10
    f.sp = integer::sub(f.sp,0x00000010u,32,flags);
  }
  L0075f297: { // 0x75f297: 8b542414 MOV EDX, DWORD PTR [ESP + 0X14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  L0075f29b: { // 0x75f29b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0075f29c: { // 0x75f29c: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L0075f29e: { // 0x75f29e: 8b4c241c MOV ECX, DWORD PTR [ESP + 0X1C]
    s.cx = m.r32((f.sp+0x0000001cu));
  }
  L0075f2a2: { // 0x75f2a2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2a3: { // 0x75f2a3: 8b06 MOV EAX, DWORD PTR [ESI]
    s.ax = m.r32((s.si));
  }
  L0075f2a5: { // 0x75f2a5: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2a6: { // 0x75f2a6: 8d4c240c LEA ECX, [ESP + 0XC]
    s.cx = (f.sp+0x0000000cu);
  }
  L0075f2aa: { // 0x75f2aa: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0075f2ab: { // 0x75f2ab: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0075f2ac: { // 0x75f2ac: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0075f2ae: { // 0x75f2ae: ff5078 CALL DWORD PTR [EAX + 0X78]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000078u)),7729841u,op); flags=s.arithmetic_flags;
  }
  L0075f2b1: { // 0x75f2b1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0075f2b2: { // 0x75f2b2: 8bce MOV ECX, ESI
    s.cx = s.si;
  }
  L0075f2b4: { // 0x75f2b4: e807000000 CALL 0X75F2C0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0075f2c0u,7729849u,op); flags=s.arithmetic_flags;
  }
  L0075f2b9: { // 0x75f2b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0075f2ba: { // 0x75f2ba: 83c410 ADD ESP, 0X10
    f.sp = integer::add(f.sp,0x00000010u,32,flags);
  }
  L0075f2bd: { // 0x75f2bd: c20c00 RET 0XC
    s.arithmetic_flags=flags; finish(m,s,f,12u); return;
  }
}

inline void invoke(Memory&m,State&s,Frame&f,unsigned target,unsigned continuation,const Operations&op){
 need(op.api!=nullptr,"explicit provider context");auto&api=*op.api;
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};const auto arg=[&](unsigned k){return m.r32(child.sp+4+4*k);};
 if(target==api.clock_target()){s.ax=api.clock(s.fp);finish(m,s,child,0);}
 else switch(target){
 case 0x65e250:f_0025e250(m,s,child,op);break;
 case 0x75f290:f_0035f290(m,s,child,op);break;
 case 0x411290:f_00011290(m,s,child,op);break;
 case 0x4112c0:f_000112c0(m,s,child,op);break;
 case 0x41fdf0:f_0001fdf0(m,s,child,op);break;
 case 0x760f60:f_00360f60(m,s,child,op);break;
 case 0x76aa50:f_0036aa50(m,s,child,op);break;
 case 0x75f2c0:f_0035f2c0(m,s,child,op);break;
 case 0x68fad0:
  // Authenticated body: FF1524557800 / C1E804 / C3.
  invoke(m,s,child,m.r32(0x785524),0x68fad6,op);s.ax=integer::shift(s.ax,4,32,s.arithmetic_flags,integer::Shift::right);finish(m,s,child,0);break;
 case 0x4aa970:s.ax=m.r32(s.cx+0x10);finish(m,s,child,0);break;
 case 0x4aa980:s.ax=m.r32(m.r32(s.cx+0x20)+0x10);finish(m,s,child,0);break;
 case 0x4aa990:case 0x4aab50:{
  const unsigned self=s.cx,surface=m.r32(self+28),count=m.r32(self+12);need(m.r8(0x839fe0)==1&&m.r32(self)==0x78bbe4&&m.r32(self+20)!=0&&surface==api.surface(),"genuine borrowed prelocked surface");
  const unsigned lost=api.is_lost(surface,s.fp);need(lost==0,"actual nonlost provider");
  if(target==0x4aa990){need(count==1&&arg(0)<32&&arg(1)<24,"positive nested1-to2 Lock");const unsigned offset=m.r32(m.r32(self+32)+16)*arg(1)+m.r32(self+16)*arg(0);m.w32(self+12,2);s.cx=self;s.dx=m.r32(self);s.ax=integer::add(m.r32(self+20),offset,32,s.arithmetic_flags);finish(m,s,child,8);}
  else{need(count==2,"nested2-to1 Unlock");m.w32(self+12,1);s.ax=1;s.arithmetic_flags=integer::logical(s.ax,32,s.arithmetic_flags);finish(m,s,child,0);}break;
 }
 default:throw std::domain_error("25E250 out-of-recipe call");
 }
 f.sp=child.sp;
}
}
unsigned run(Memory&world,const Inputs&in,Api&api){
 need((world.r8(0xa9ea98)&1)&&world.r32(0xa9ea88)==1&&world.r32(0xa9eaa4)==in.arg[0]&&world.r32(0xa9ea58)==5&&world.r8(0x7c13c4)==1&&world.r32(world.r32(0x821c94)+12)==1&&world.r32(world.r32(0x821c94)+20)!=0,"warm positive cursor/elapsed timer/prelocked recipe");
 std::array<std::uint8_t,0x8000>storage{};constexpr unsigned base=0x7d000000,entry=base+0x6004;ra2::recovered::leaf::Memory local(storage.data(),base,unsigned(storage.size()));Memory m=world;m.add(local);
 State s{};s.ax=in.ax;s.cx=in.cx;s.dx=in.dx;s.bx=0x13572468;s.bp=0x24681357;s.si=0x31415926;s.di=0x27182818;s.fp=in.fp;s.arithmetic_flags=in.arithmetic_flags;const auto before=s;
 Frame frame{entry,entry,0x76543210};m.w32(entry,frame.outer_return);for(unsigned k=0;k<16;++k)m.w32(entry+4+4*k,in.arg[k]);const Operations op{&api};f_0025e250(m,s,frame,op);
 need(frame.sp==entry+12&&s.bx==before.bx&&s.bp==before.bp&&s.si==before.si&&s.di==before.di,"full return/nonvolatile recipe");for(unsigned k=0;k<16;++k)need(m.r32(entry+4+4*k)==in.arg[k],"exact all16 caller poststate");in.fp=s.fp;return s.ax;
}
}
