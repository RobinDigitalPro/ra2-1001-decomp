#include "recovered/strings_b37_memory.hpp"
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_primitives.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::strings_b37 {
namespace {
void f_001fab40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x5fab40: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fab41: 8b5904 MOV EBX,dword ptr [ECX + 0x4]
    s.bx = m.r32((s.cx+0x00000004u));
  }
  { // 0x5fab44: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x5fab46: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fab47: 741b JZ 0x005fab64
    if(integer::condition("JZ",flags)) goto L005fab64;
  }
  { // 0x5fab49: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  L005fab4d: { // 0x5fab4d: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x5fab4f: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x5fab50: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x5fab51: e8fa451700 CALL 0x0076f150
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x5fab56: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x5fab59: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x5fab5b: 7413 JZ 0x005fab70
    if(integer::condition("JZ",flags)) goto L005fab70;
  }
  { // 0x5fab5d: 8b5b0c MOV EBX,dword ptr [EBX + 0xc]
    s.bx = m.r32((s.bx+0x0000000cu));
  }
  { // 0x5fab60: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x5fab62: 75e9 JNZ 0x005fab4d
    if(integer::condition("JNZ",flags)) goto L005fab4d;
  }
  L005fab64: { // 0x5fab64: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x5fab66: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5fab67: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x5fab69: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5fab6c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5fab6d: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L005fab70: { // 0x5fab70: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x5fab72: 7433 JZ 0x005faba7
    if(integer::condition("JZ",flags)) goto L005faba7;
  }
  { // 0x5fab74: 8b542414 MOV EDX,dword ptr [ESP + 0x14]
    s.dx = m.r32((f.sp+0x00000014u));
  }
  { // 0x5fab78: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x5fab7a: 668b4306 MOV AX,word ptr [EBX + 0x6]
    s.ax = with_ax(s.ax, m.r16((s.bx+0x00000006u)));
  }
  { // 0x5fab7e: 8b0a MOV ECX,dword ptr [EDX]
    s.cx = m.r32((s.dx));
  }
  { // 0x5fab80: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x5fab82: 7d02 JGE 0x005fab86
    if(integer::condition("JGE",flags)) goto L005fab86;
  }
  { // 0x5fab84: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L005fab86: { // 0x5fab86: 8b7308 MOV ESI,dword ptr [EBX + 0x8]
    s.si = m.r32((s.bx+0x00000008u));
  }
  { // 0x5fab89: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x5fab8b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x5fab8c: 8b7c2414 MOV EDI,dword ptr [ESP + 0x14]
    s.di = m.r32((f.sp+0x00000014u));
  }
  { // 0x5fab90: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x5fab93: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x5fab95: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x5fab97: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x5fab9a: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x5fab9c: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x5fab9e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x5fab9f: 668b4b06 MOV CX,word ptr [EBX + 0x6]
    s.cx = with_ax(s.cx, m.r16((s.bx+0x00000006u)));
  }
  { // 0x5faba3: 890a MOV dword ptr [EDX],ECX
    m.w32((s.dx), s.cx);
  }
  { // 0x5faba5: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  L005faba7: { // 0x5faba7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x5faba8: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x5faba9: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  { // 0x5fabac: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0020c750(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x60c750: 8a442404 MOV AL,byte ptr [ESP + 0x4]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000004u)));
  }
  { // 0x60c754: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x60c755: 3c04 CMP AL,0x4
    (void)integer::sub((s.ax & 0xffu),0x00000004u,8,flags);
  }
  { // 0x60c757: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x60c758: 7520 JNZ 0x0060c77a
    if(integer::condition("JNZ",flags)) goto L0060c77a;
  }
  { // 0x60c75a: 83ec70 SUB ESP,0x70
    f.sp = integer::sub(f.sp,0x00000070u,32,flags);
  }
  { // 0x60c75d: b91b000000 MOV ECX,0x1b
    s.cx = 0x0000001bu;
  }
  { // 0x60c762: 8d74247c LEA ESI,[ESP + 0x7c]
    s.si = (f.sp+0x0000007cu);
  }
  { // 0x60c766: 8bfc MOV EDI,ESP
    s.di = f.sp;
  }
  { // 0x60c768: c684249900000001 MOV byte ptr [ESP + 0x99],0x1
    m.w8((f.sp+0x00000099u), 0x00000001u);
  }
  { // 0x60c770: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x60c772: 66a5 MOVSW ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,16u,Repeat::single);
  }
  { // 0x60c774: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  { // 0x60c775: e826970100 CALL 0x00625ea0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  L0060c77a: { // 0x60c77a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x60c77b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x60c77c: c27000 RET 0x70
    finish(m,s,f,112u); return;
  }
}
void f_0021e9d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x61e9d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x61e9d1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x61e9d2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x61e9d3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x61e9d5: 68c7010000 PUSH 0x1c7
    f.push(m,0x000001c7u);
  }
  { // 0x61e9da: e878ef1400 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x61e9df: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x61e9e1: b971000000 MOV ECX,0x71
    s.cx = 0x00000071u;
  }
  { // 0x61e9e6: 8bfb MOV EDI,EBX
    s.di = s.bx;
  }
  { // 0x61e9e8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x61e9eb: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x61e9ed: 66a5 MOVSW ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,16u,Repeat::single);
  }
  { // 0x61e9ef: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  { // 0x61e9f0: a1705ea200 MOV EAX,[0x00a25e70]
    s.ax = m.r32((0x00a25e70u));
  }
  { // 0x61e9f5: 8b0d785ea200 MOV ECX,dword ptr [0x00a25e78]
    s.cx = m.r32((0x00a25e78u));
  }
  { // 0x61e9fb: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  { // 0x61e9fd: 7c2e JL 0x0061ea2d
    if(integer::condition("JL",flags)) goto L0061ea2d;
  }
  { // 0x61e9ff: 8a0d755ea200 MOV CL,byte ptr [0x00a25e75]
    s.cx = with_al(s.cx, m.r8((0x00a25e75u)));
  }
  { // 0x61ea05: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  { // 0x61ea07: 7504 JNZ 0x0061ea0d
    if(integer::condition("JNZ",flags)) goto L0061ea0d;
  }
  { // 0x61ea09: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x61ea0b: 7538 JNZ 0x0061ea45
    if(integer::condition("JNZ",flags)) goto L0061ea45;
  }
  L0061ea0d: { // 0x61ea0d: 8b0d7c5ea200 MOV ECX,dword ptr [0x00a25e7c]
    s.cx = m.r32((0x00a25e7cu));
  }
  { // 0x61ea13: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x61ea15: 7e2e JLE 0x0061ea45
    if(integer::condition("JLE",flags)) goto L0061ea45;
  }
  { // 0x61ea17: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  { // 0x61ea19: a1685ea200 MOV EAX,[0x00a25e68]
    s.ax = m.r32((0x00a25e68u));
  }
  { // 0x61ea1e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x61ea20: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x61ea21: b9685ea200 MOV ECX,0xa25e68
    s.cx = 0x00a25e68u;
  }
  { // 0x61ea26: ff5008 CALL dword ptr [EAX + 0x8]
    const std::uint32_t call_target=m.r32((s.ax+0x00000008u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x61ea29: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x61ea2b: 7418 JZ 0x0061ea45
    if(integer::condition("JZ",flags)) goto L0061ea45;
  }
  L0061ea2d: { // 0x61ea2d: 8b0d785ea200 MOV ECX,dword ptr [0x00a25e78]
    s.cx = m.r32((0x00a25e78u));
  }
  { // 0x61ea33: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x61ea35: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x61ea36: 890d785ea200 MOV dword ptr [0x00a25e78],ECX
    m.w32((0x00a25e78u), s.cx);
  }
  { // 0x61ea3c: 8b0d6c5ea200 MOV ECX,dword ptr [0x00a25e6c]
    s.cx = m.r32((0x00a25e6cu));
  }
  { // 0x61ea42: 891c81 MOV dword ptr [ECX + EAX*0x4],EBX
    m.w32((s.cx+(s.ax * 0x00000004u)), s.bx);
  }
  L0061ea45: { // 0x61ea45: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x61ea46: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x61ea47: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x61ea48: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00225ea0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x625ea0: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  { // 0x625ea5: 89442407 MOV dword ptr [ESP + 0x7],EAX
    m.w32((f.sp+0x00000007u), s.ax);
  }
  { // 0x625ea9: a168a6a100 MOV EAX,[0x00a1a668]
    s.ax = m.r32((0x00a1a668u));
  }
  { // 0x625eae: 3d80000000 CMP EAX,0x80
    (void)integer::sub(s.ax,0x00000080u,32,flags);
  }
  { // 0x625eb3: 7d55 JGE 0x00625f0a
    if(integer::condition("JGE",flags)) goto L00625f0a;
  }
  { // 0x625eb5: a170a6a100 MOV EAX,[0x00a1a670]
    s.ax = m.r32((0x00a1a670u));
  }
  { // 0x625eba: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x625ebb: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x625ebc: 8d74240c LEA ESI,[ESP + 0xc]
    s.si = (f.sp+0x0000000cu);
  }
  { // 0x625ec0: 8d0cc0 LEA ECX,[EAX + EAX*0x8]
    s.cx = (s.ax+(s.ax * 0x00000008u));
  }
  { // 0x625ec3: 8d0488 LEA EAX,[EAX + ECX*0x4]
    s.ax = (s.ax+(s.cx * 0x00000004u));
  }
  { // 0x625ec6: b91b000000 MOV ECX,0x1b
    s.cx = 0x0000001bu;
  }
  { // 0x625ecb: 8dbc4074a6a100 LEA EDI,[EAX + EAX*0x2 + 0xa1a674]
    s.di = (s.ax+(s.ax * 0x00000002u)+0x00a1a674u);
  }
  { // 0x625ed2: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x625ed4: 66a5 MOVSW ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,16u,Repeat::single);
  }
  { // 0x625ed6: a4 MOVSB ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::single);
  }
  { // 0x625ed7: ff1524557800 CALL dword ptr [0x00785524]
    const std::uint32_t call_target=m.r32((0x00785524u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x625edd: 8b1570a6a100 MOV EDX,dword ptr [0x00a1a670]
    s.dx = m.r32((0x00a1a670u));
  }
  { // 0x625ee3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x625ee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x625ee5: 890495f4dda100 MOV dword ptr [EDX*0x4 + 0xa1ddf4],EAX
    m.w32(((s.dx * 0x00000004u)+0x00a1ddf4u), s.ax);
  }
  { // 0x625eec: a170a6a100 MOV EAX,[0x00a1a670]
    s.ax = m.r32((0x00a1a670u));
  }
  { // 0x625ef1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x625ef2: 83e07f AND EAX,0x7f
    s.ax = integer::logical((s.ax)&(0x0000007fu),32,flags);
  }
  { // 0x625ef5: a370a6a100 MOV [0x00a1a670],EAX
    m.w32((0x00a1a670u), s.ax);
  }
  { // 0x625efa: a168a6a100 MOV EAX,[0x00a1a668]
    s.ax = m.r32((0x00a1a668u));
  }
  { // 0x625eff: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x625f00: a368a6a100 MOV [0x00a1a668],EAX
    m.w32((0x00a1a668u), s.ax);
  }
  { // 0x625f05: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x625f07: c27000 RET 0x70
    finish(m,s,f,112u); return;
  }
  L00625f0a: { // 0x625f0a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x625f0c: c27000 RET 0x70
    finish(m,s,f,112u); return;
  }
}
void f_00233830(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x633830: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x633831: a118e3a900 MOV EAX,[0x00a9e318]
    s.ax = m.r32((0x00a9e318u));
  }
  { // 0x633836: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x633837: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x633838: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x63383a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x63383c: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x633840: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  { // 0x633842: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x633844: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x633845: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x633846: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  { // 0x63384a: ff5110 CALL dword ptr [ECX + 0x10]
    const std::uint32_t call_target=m.r32((s.cx+0x00000010u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x63384d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x63384f: 7d06 JGE 0x00633857
    if(integer::condition("JGE",flags)) goto L00633857;
  }
  L00633851: { // 0x633851: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x633852: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x633854: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x633855: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x633856: c3 RET
    finish(m,s,f,0u); return;
  }
  L00633857: { // 0x633857: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x63385b: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x63385d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x63385f: 7e21 JLE 0x00633882
    if(integer::condition("JLE",flags)) goto L00633882;
  }
  L00633861: { // 0x633861: 8b0d0ce3a900 MOV ECX,dword ptr [0x00a9e30c]
    s.cx = m.r32((0x00a9e30cu));
  }
  { // 0x633867: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x633869: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x63386b: 6a40 PUSH 0x40
    f.push(m,0x00000040u);
  }
  { // 0x63386d: 8b14b9 MOV EDX,dword ptr [ECX + EDI*0x4]
    s.dx = m.r32((s.cx+(s.di * 0x00000004u)));
  }
  { // 0x633870: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x633871: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x633872: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x633875: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x633877: 7cd8 JL 0x00633851
    if(integer::condition("JL",flags)) goto L00633851;
  }
  { // 0x633879: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x63387d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x63387e: 3bf8 CMP EDI,EAX
    (void)integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x633880: 7cdf JL 0x00633861
    if(integer::condition("JL",flags)) goto L00633861;
  }
  L00633882: { // 0x633882: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x633884: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x633886: 6a04 PUSH 0x4
    f.push(m,0x00000004u);
  }
  { // 0x633888: 68e0e2a900 PUSH 0xa9e2e0
    f.push(m,0x00a9e2e0u);
  }
  { // 0x63388d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x63388e: ff5010 CALL dword ptr [EAX + 0x10]
    const std::uint32_t call_target=m.r32((s.ax+0x00000010u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x633891: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x633893: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x633894: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x633895: 0f9dc0 SETGE AL
    s.ax = with_al(s.ax, (integer::condition("JGE",flags)?1u:0u));
  }
  { // 0x633898: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x633899: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_002346c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6346c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6346c1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6346c2: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6346c3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6346c4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6346c6: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x6346c8: bd20000000 MOV EBP,0x20
    s.bp = 0x00000020u;
  }
  { // 0x6346cd: 897e04 MOV dword ptr [ESI + 0x4],EDI
    m.w32((s.si+0x00000004u), s.di);
  }
  { // 0x6346d0: 897e08 MOV dword ptr [ESI + 0x8],EDI
    m.w32((s.si+0x00000008u), s.di);
  }
  { // 0x6346d3: c706f8997800 MOV dword ptr [ESI],0x7899f8
    m.w32((s.si), 0x007899f8u);
  }
  { // 0x6346d9: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  { // 0x6346dc: 897e10 MOV dword ptr [ESI + 0x10],EDI
    m.w32((s.si+0x00000010u), s.di);
  }
  { // 0x6346df: 8d5e14 LEA EBX,[ESI + 0x14]
    s.bx = (s.si+0x00000014u);
  }
  L006346e2: { // 0x6346e2: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6346e3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6346e4: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x6346e6: e805b8ffff CALL 0x0062fef0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6346eb: 83c308 ADD EBX,0x8
    s.bx = integer::add(s.bx,0x00000008u,32,flags);
  }
  { // 0x6346ee: 4d DEC EBP
    s.bp = integer::decrement(s.bp,32,flags);
  }
  { // 0x6346ef: 75f1 JNZ 0x006346e2
    if(integer::condition("JNZ",flags)) goto L006346e2;
  }
  { // 0x6346f1: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  { // 0x6346f4: 897e10 MOV dword ptr [ESI + 0x10],EDI
    m.w32((s.si+0x00000010u), s.di);
  }
  { // 0x6346f7: b940000000 MOV ECX,0x40
    s.cx = 0x00000040u;
  }
  { // 0x6346fc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6346fe: 8d7e14 LEA EDI,[ESI + 0x14]
    s.di = (s.si+0x00000014u);
  }
  { // 0x634701: c706643d7900 MOV dword ptr [ESI],0x793d64
    m.w32((s.si), 0x00793d64u);
  }
  { // 0x634707: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x634709: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x63470b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x63470c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x63470d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x63470e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x63470f: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00234c80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x634c80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x634c81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x634c83: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x634c84: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x634c86: b940000000 MOV ECX,0x40
    s.cx = 0x00000040u;
  }
  { // 0x634c8b: 8d7e14 LEA EDI,[ESI + 0x14]
    s.di = (s.si+0x00000014u);
  }
  { // 0x634c8e: c706643d7900 MOV dword ptr [ESI],0x793d64
    m.w32((s.si), 0x00793d64u);
  }
  { // 0x634c94: 89460c MOV dword ptr [ESI + 0xc],EAX
    m.w32((s.si+0x0000000cu), s.ax);
  }
  { // 0x634c97: 894610 MOV dword ptr [ESI + 0x10],EAX
    m.w32((s.si+0x00000010u), s.ax);
  }
  { // 0x634c9a: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x634c9c: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x634c9e: e80dba0500 CALL 0x006906b0
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x634ca3: f644240c01 TEST byte ptr [ESP + 0xc],0x1
    (void)integer::logical((m.r8((f.sp+0x0000000cu)))&(0x00000001u),8,flags);
  }
  { // 0x634ca8: 7409 JZ 0x00634cb3
    if(integer::condition("JZ",flags)) goto L00634cb3;
  }
  { // 0x634caa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x634cab: e8cb891300 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x634cb0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00634cb3: { // 0x634cb3: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x634cb5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x634cb6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x634cb7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00242b00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x642b00: a10c3f7900 MOV EAX,[0x00793f0c]
    s.ax = m.r32((0x00793f0cu));
  }
  { // 0x642b05: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x642b08: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x642b09: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x642b0a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x642b0b: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x642b0f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642b10: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642b12: e83994ecff CALL 0x0050bf50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x642b17: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x642b19: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x642b1b: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x642b1d: 7e3b JLE 0x00642b5a
    if(integer::condition("JLE",flags)) goto L00642b5a;
  }
  L00642b1f: { // 0x642b1f: 8b150c3f7900 MOV EDX,dword ptr [0x00793f0c]
    s.dx = m.r32((0x00793f0cu));
  }
  { // 0x642b25: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x642b29: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x642b2b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x642b2c: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x642b31: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x642b32: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x642b33: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642b35: e81697ecff CALL 0x0050c250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x642b3a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642b3b: a10c3f7900 MOV EAX,[0x00793f0c]
    s.ax = m.r32((0x00793f0cu));
  }
  { // 0x642b40: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642b41: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642b43: e8a8b2ecff CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x642b48: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x642b4a: 7409 JZ 0x00642b55
    if(integer::condition("JZ",flags)) goto L00642b55;
  }
  { // 0x642b4c: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x642b50: e8cb77ecff CALL 0x0050a320
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00642b55: { // 0x642b55: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x642b56: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x642b58: 7cc5 JL 0x00642b1f
    if(integer::condition("JL",flags)) goto L00642b1f;
  }
  L00642b5a: { // 0x642b5a: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x642b5c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x642b5d: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x642b5f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x642b60: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x642b61: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x642b64: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x642b67: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00242b70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x642b70: a1103f7900 MOV EAX,[0x00793f10]
    s.ax = m.r32((0x00793f10u));
  }
  { // 0x642b75: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x642b78: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x642b79: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x642b7a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x642b7b: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x642b7f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642b80: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642b82: e8c993ecff CALL 0x0050bf50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x642b87: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x642b89: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x642b8b: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x642b8d: 7e3b JLE 0x00642bca
    if(integer::condition("JLE",flags)) goto L00642bca;
  }
  L00642b8f: { // 0x642b8f: 8b15103f7900 MOV EDX,dword ptr [0x00793f10]
    s.dx = m.r32((0x00793f10u));
  }
  { // 0x642b95: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x642b99: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x642b9b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x642b9c: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x642ba1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x642ba2: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x642ba3: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642ba5: e8a696ecff CALL 0x0050c250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x642baa: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642bab: a1103f7900 MOV EAX,[0x00793f10]
    s.ax = m.r32((0x00793f10u));
  }
  { // 0x642bb0: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642bb1: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642bb3: e838b2ecff CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x642bb8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x642bba: 7409 JZ 0x00642bc5
    if(integer::condition("JZ",flags)) goto L00642bc5;
  }
  { // 0x642bbc: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x642bc0: e88b6cebff CALL 0x004f9850
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00642bc5: { // 0x642bc5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x642bc6: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x642bc8: 7cc5 JL 0x00642b8f
    if(integer::condition("JL",flags)) goto L00642b8f;
  }
  L00642bca: { // 0x642bca: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x642bcc: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x642bcd: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x642bcf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x642bd0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x642bd1: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x642bd4: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x642bd7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00242c50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x642c50: a1183f7900 MOV EAX,[0x00793f18]
    s.ax = m.r32((0x00793f18u));
  }
  { // 0x642c55: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x642c58: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x642c59: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x642c5a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x642c5b: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x642c5f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642c60: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642c62: e8e992ecff CALL 0x0050bf50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x642c67: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x642c69: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x642c6b: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x642c6d: 7e3b JLE 0x00642caa
    if(integer::condition("JLE",flags)) goto L00642caa;
  }
  L00642c6f: { // 0x642c6f: 8b15183f7900 MOV EDX,dword ptr [0x00793f18]
    s.dx = m.r32((0x00793f18u));
  }
  { // 0x642c75: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x642c79: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x642c7b: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x642c7c: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x642c81: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x642c82: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x642c83: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642c85: e8c695ecff CALL 0x0050c250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x642c8a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642c8b: a1183f7900 MOV EAX,[0x00793f18]
    s.ax = m.r32((0x00793f18u));
  }
  { // 0x642c90: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x642c91: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x642c93: e858b1ecff CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x642c98: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x642c9a: 7409 JZ 0x00642ca5
    if(integer::condition("JZ",flags)) goto L00642ca5;
  }
  { // 0x642c9c: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x642ca0: e8ab95ddff CALL 0x0041c250
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00642ca5: { // 0x642ca5: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x642ca6: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x642ca8: 7cc5 JL 0x00642c6f
    if(integer::condition("JL",flags)) goto L00642c6f;
  }
  L00642caa: { // 0x642caa: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x642cac: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x642cad: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x642caf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x642cb0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x642cb1: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x642cb4: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x642cb7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00243130(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x643130: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x643133: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x643134: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x643135: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x643136: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x64313a: 6880b27d00 PUSH 0x7db280
    f.push(m,0x007db280u);
  }
  { // 0x64313f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x643141: e80a8eecff CALL 0x0050bf50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x643146: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x643148: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64314a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x64314c: 7e38 JLE 0x00643186
    if(integer::condition("JLE",flags)) goto L00643186;
  }
  L0064314e: { // 0x64314e: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x643152: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x643154: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x643155: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64315a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64315b: 6880b27d00 PUSH 0x7db280
    f.push(m,0x007db280u);
  }
  { // 0x643160: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x643162: e8e990ecff CALL 0x0050c250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x643167: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x643168: 6880b27d00 PUSH 0x7db280
    f.push(m,0x007db280u);
  }
  { // 0x64316d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x64316f: e87cacecff CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x643174: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x643176: 7409 JZ 0x00643181
    if(integer::condition("JZ",flags)) goto L00643181;
  }
  { // 0x643178: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x64317c: e81f33deff CALL 0x004264a0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00643181: { // 0x643181: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x643182: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x643184: 7cc8 JL 0x0064314e
    if(integer::condition("JL",flags)) goto L0064314e;
  }
  L00643186: { // 0x643186: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x643188: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x643189: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x64318b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64318c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64318d: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x643190: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x643193: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002431a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6431a0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x6431a3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6431a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6431a5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6431a6: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x6431aa: 688cb27d00 PUSH 0x7db28c
    f.push(m,0x007db28cu);
  }
  { // 0x6431af: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6431b1: e89a8decff CALL 0x0050bf50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6431b6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x6431b8: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6431ba: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6431bc: 7e38 JLE 0x006431f6
    if(integer::condition("JLE",flags)) goto L006431f6;
  }
  L006431be: { // 0x6431be: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x6431c2: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x6431c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6431c5: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x6431ca: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6431cb: 688cb27d00 PUSH 0x7db28c
    f.push(m,0x007db28cu);
  }
  { // 0x6431d0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6431d2: e87990ecff CALL 0x0050c250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6431d7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6431d8: 688cb27d00 PUSH 0x7db28c
    f.push(m,0x007db28cu);
  }
  { // 0x6431dd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6431df: e80cacecff CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6431e4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6431e6: 7409 JZ 0x006431f1
    if(integer::condition("JZ",flags)) goto L006431f1;
  }
  { // 0x6431e8: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x6431ec: e84f070c00 CALL 0x00703940
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L006431f1: { // 0x6431f1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6431f2: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x6431f4: 7cc8 JL 0x006431be
    if(integer::condition("JL",flags)) goto L006431be;
  }
  L006431f6: { // 0x6431f6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6431f8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6431f9: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6431fb: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6431fc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6431fd: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x643200: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x643203: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00243280(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x643280: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x643283: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x643284: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x643285: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x643286: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x64328a: 6898b27d00 PUSH 0x7db298
    f.push(m,0x007db298u);
  }
  { // 0x64328f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x643291: e8ba8cecff CALL 0x0050bf50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x643296: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x643298: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64329a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x64329c: 7e38 JLE 0x006432d6
    if(integer::condition("JLE",flags)) goto L006432d6;
  }
  L0064329e: { // 0x64329e: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x6432a2: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x6432a4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6432a5: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x6432aa: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6432ab: 6898b27d00 PUSH 0x7db298
    f.push(m,0x007db298u);
  }
  { // 0x6432b0: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6432b2: e8998fecff CALL 0x0050c250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6432b7: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6432b8: 6898b27d00 PUSH 0x7db298
    f.push(m,0x007db298u);
  }
  { // 0x6432bd: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x6432bf: e82cabecff CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6432c4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6432c6: 7409 JZ 0x006432d1
    if(integer::condition("JZ",flags)) goto L006432d1;
  }
  { // 0x6432c8: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x6432cc: e80f66fdff CALL 0x006198e0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L006432d1: { // 0x6432d1: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6432d2: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x6432d4: 7cc8 JL 0x0064329e
    if(integer::condition("JL",flags)) goto L0064329e;
  }
  L006432d6: { // 0x6432d6: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6432d8: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6432d9: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x6432db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6432dc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6432dd: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x6432e0: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x6432e3: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002432f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6432f0: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x6432f3: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6432f4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6432f5: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6432f6: 8b7c2430 MOV EDI,dword ptr [ESP + 0x30]
    s.di = m.r32((f.sp+0x00000030u));
  }
  { // 0x6432fa: 68a4b27d00 PUSH 0x7db2a4
    f.push(m,0x007db2a4u);
  }
  { // 0x6432ff: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x643301: e84a8cecff CALL 0x0050bf50
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x643306: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  { // 0x643308: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x64330a: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x64330c: 7e38 JLE 0x00643346
    if(integer::condition("JLE",flags)) goto L00643346;
  }
  L0064330e: { // 0x64330e: 8d44240c LEA EAX,[ESP + 0xc]
    s.ax = (f.sp+0x0000000cu);
  }
  { // 0x643312: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x643314: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x643315: 68a4488200 PUSH 0x8248a4
    f.push(m,0x008248a4u);
  }
  { // 0x64331a: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x64331b: 68a4b27d00 PUSH 0x7db2a4
    f.push(m,0x007db2a4u);
  }
  { // 0x643320: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x643322: e8298fecff CALL 0x0050c250
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x643327: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x643328: 68a4b27d00 PUSH 0x7db2a4
    f.push(m,0x007db2a4u);
  }
  { // 0x64332d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x64332f: e8bcaaecff CALL 0x0050ddf0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x643334: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x643336: 7409 JZ 0x00643341
    if(integer::condition("JZ",flags)) goto L00643341;
  }
  { // 0x643338: 8d4c240c LEA ECX,[ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  { // 0x64333c: e83f56fdff CALL 0x00618980
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  L00643341: { // 0x643341: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x643342: 3bf3 CMP ESI,EBX
    (void)integer::sub(s.si,s.bx,32,flags);
  }
  { // 0x643344: 7cc8 JL 0x0064330e
    if(integer::condition("JL",flags)) goto L0064330e;
  }
  L00643346: { // 0x643346: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x643348: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x643349: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x64334b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x64334c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x64334d: 0f9fc0 SETG AL
    s.ax = with_al(s.ax, (integer::condition("JG",flags)?1u:0u));
  }
  { // 0x643350: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x643353: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00268300(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x668300: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  { // 0x668304: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x668305: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x668307: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x668309: 741d JZ 0x00668328
    if(integer::condition("JZ",flags)) goto L00668328;
  }
  { // 0x66830b: 6a20 PUSH 0x20
    f.push(m,0x00000020u);
  }
  { // 0x66830d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x66830e: 8d865c010000 LEA EAX,[ESI + 0x15c]
    s.ax = (s.si+0x0000015cu);
  }
  { // 0x668314: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x668315: e8f6591000 CALL 0x0076dd10
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x66831a: 83c40c ADD ESP,0xc
    f.sp = integer::add(f.sp,0x0000000cu,32,flags);
  }
  { // 0x66831d: c6867b01000000 MOV byte ptr [ESI + 0x17b],0x0
    m.w8((s.si+0x0000017bu), 0x00000000u);
  }
  { // 0x668324: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668325: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L00668328: { // 0x668328: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x668329: bf78d37d00 MOV EDI,0x7dd378
    s.di = 0x007dd378u;
  }
  { // 0x66832e: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x668331: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x668333: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x668335: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x668337: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x668339: 8d965c010000 LEA EDX,[ESI + 0x15c]
    s.dx = (s.si+0x0000015cu);
  }
  { // 0x66833f: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x668341: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x668343: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x668345: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x668348: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x66834a: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x66834c: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x66834f: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  { // 0x668351: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x668352: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x668353: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00295360(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x695360: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x695364: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x695365: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x695367: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x695368: 750a JNZ 0x00695374
    if(integer::condition("JNZ",flags)) goto L00695374;
  }
  { // 0x69536a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x69536b: b803400080 MOV EAX,0x80004003
    s.ax = 0x80004003u;
  }
  { // 0x695370: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x695371: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L00695374: { // 0x695374: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  { // 0x695378: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x695379: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x69537e: bf60d07800 MOV EDI,0x78d060
    s.di = 0x0078d060u;
  }
  { // 0x695383: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x695385: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x695387: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x695389: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x69538a: 741c JZ 0x006953a8
    if(integer::condition("JZ",flags)) goto L006953a8;
  }
  { // 0x69538c: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x69538e: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  { // 0x695393: bff8aa7900 MOV EDI,0x79aaf8
    s.di = 0x0079aaf8u;
  }
  { // 0x695398: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x69539a: f3a7 CMPSD.REPE ES:EDI,ESI
    string_instruction(m,s,flags,Kind::compare,32u,Repeat::equal);
  }
  { // 0x69539c: 740a JZ 0x006953a8
    if(integer::condition("JZ",flags)) goto L006953a8;
  }
  { // 0x69539e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x69539f: b802400080 MOV EAX,0x80004002
    s.ax = 0x80004002u;
  }
  { // 0x6953a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6953a5: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
  L006953a8: { // 0x6953a8: 8b44240c MOV EAX,dword ptr [ESP + 0xc]
    s.ax = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6953ac: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  { // 0x6953ae: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6953af: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x6953b1: ff5104 CALL dword ptr [ECX + 0x4]
    const std::uint32_t call_target=m.r32((s.cx+0x00000004u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6953b4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6953b5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6953b7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6953b8: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_002cdb50(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6cdb50: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6cdb51: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6cdb52: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6cdb53: 8b7c2410 MOV EDI,dword ptr [ESP + 0x10]
    s.di = m.r32((f.sp+0x00000010u));
  }
  { // 0x6cdb57: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x6cdb59: 83ff02 CMP EDI,0x2
    (void)integer::sub(s.di,0x00000002u,32,flags);
  }
  { // 0x6cdb5c: 0f9cc3 SETL BL
    s.bx = with_al(s.bx, (integer::condition("JL",flags)?1u:0u));
  }
  { // 0x6cdb5f: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x6cdb61: ff9080000000 CALL dword ptr [EAX + 0x80]
    const std::uint32_t call_target=m.r32((s.ax+0x00000080u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6cdb67: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x6cdb69: e882700000 CALL 0x006d4bf0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x6cdb6e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cdb70: 7416 JZ 0x006cdb88
    if(integer::condition("JZ",flags)) goto L006cdb88;
  }
  { // 0x6cdb72: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  { // 0x6cdb74: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x6cdb76: ff9280000000 CALL dword ptr [EDX + 0x80]
    const std::uint32_t call_target=m.r32((s.dx+0x00000080u));
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x6cdb7c: 3bb808070000 CMP EDI,dword ptr [EAX + 0x708]
    (void)integer::sub(s.di,m.r32((s.ax+0x00000708u)),32,flags);
  }
  { // 0x6cdb82: 7d04 JGE 0x006cdb88
    if(integer::condition("JGE",flags)) goto L006cdb88;
  }
  { // 0x6cdb84: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x6cdb86: eb02 JMP 0x006cdb8a
    goto L006cdb8a;
  }
  L006cdb88: { // 0x6cdb88: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L006cdb8a: { // 0x6cdb8a: 83ffff CMP EDI,-0x1
    (void)integer::sub(s.di,0xffffffffu,32,flags);
  }
  { // 0x6cdb8d: 7c13 JL 0x006cdba2
    if(integer::condition("JL",flags)) goto L006cdba2;
  }
  { // 0x6cdb8f: 84db TEST BL,BL
    (void)integer::logical(((s.bx & 0xffu))&((s.bx & 0xffu)),8,flags);
  }
  { // 0x6cdb91: 7504 JNZ 0x006cdb97
    if(integer::condition("JNZ",flags)) goto L006cdb97;
  }
  { // 0x6cdb93: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x6cdb95: 740b JZ 0x006cdba2
    if(integer::condition("JZ",flags)) goto L006cdba2;
  }
  L006cdb97: { // 0x6cdb97: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cdb98: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cdb99: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  { // 0x6cdb9e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6cdb9f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006cdba2: { // 0x6cdba2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6cdba3: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6cdba4: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6cdba6: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6cdba7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002dbb70(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dbb70: 8b4130 MOV EAX,dword ptr [ECX + 0x30]
    s.ax = m.r32((s.cx+0x00000030u));
  }
  { // 0x6dbb73: 8b5134 MOV EDX,dword ptr [ECX + 0x34]
    s.dx = m.r32((s.cx+0x00000034u));
  }
  { // 0x6dbb76: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dbb78: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6dbb79: 7411 JZ 0x006dbb8c
    if(integer::condition("JZ",flags)) goto L006dbb8c;
  }
  { // 0x6dbb7b: 83c024 ADD EAX,0x24
    s.ax = integer::add(s.ax,0x00000024u,32,flags);
  }
  { // 0x6dbb7e: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6dbb7f: 8b412c MOV EAX,dword ptr [ECX + 0x2c]
    s.ax = m.r32((s.cx+0x0000002cu));
  }
  { // 0x6dbb82: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6dbb84: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x6dbb85: 685c1b7e00 PUSH 0x7e1b5c
    f.push(m,0x007e1b5cu);
  }
  { // 0x6dbb8a: eb0c JMP 0x006dbb98
    goto L006dbb98;
  }
  L006dbb8c: { // 0x6dbb8c: 8b492c MOV ECX,dword ptr [ECX + 0x2c]
    s.cx = m.r32((s.cx+0x0000002cu));
  }
  { // 0x6dbb8f: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x6dbb90: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x6dbb92: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6dbb93: 68f0a27b00 PUSH 0x7ba2f0
    f.push(m,0x007ba2f0u);
  }
  L006dbb98: { // 0x6dbb98: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  { // 0x6dbb9c: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x6dbb9f: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x6dbba1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6dbba3: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x6dbba5: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x6dbba7: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x6dbba8: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x6dbbaa: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6dbbab: ff15a4547800 CALL dword ptr [0x007854a4]
    const std::uint32_t call_target=m.r32((0x007854a4u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6dbbb1: 83c414 ADD ESP,0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  { // 0x6dbbb4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6dbbb5: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_002dd7d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x6dd7d0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x6dd7d1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6dd7d2: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x6dd7d6: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x6dd7d7: 85ed TEST EBP,EBP
    (void)integer::logical((s.bp)&(s.bp),32,flags);
  }
  { // 0x6dd7d9: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x6dd7db: 7435 JZ 0x006dd812
    if(integer::condition("JZ",flags)) goto L006dd812;
  }
  { // 0x6dd7dd: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6dd7de: 8bfd MOV EDI,EBP
    s.di = s.bp;
  }
  { // 0x6dd7e0: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x6dd7e3: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x6dd7e5: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x6dd7e7: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x6dd7e9: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x6dd7ea: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6dd7eb: 7425 JZ 0x006dd812
    if(integer::condition("JZ",flags)) goto L006dd812;
  }
  { // 0x6dd7ed: 8b4324 MOV EAX,dword ptr [EBX + 0x24]
    s.ax = m.r32((s.bx+0x00000024u));
  }
  { // 0x6dd7f0: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x6dd7f2: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dd7f4: 7e1c JLE 0x006dd812
    if(integer::condition("JLE",flags)) goto L006dd812;
  }
  L006dd7f6: { // 0x6dd7f6: 8b4318 MOV EAX,dword ptr [EBX + 0x18]
    s.ax = m.r32((s.bx+0x00000018u));
  }
  { // 0x6dd7f9: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x6dd7fa: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  { // 0x6dd7fd: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6dd7fe: e85d000900 CALL 0x0076d860
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x6dd803: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x6dd806: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x6dd808: 7411 JZ 0x006dd81b
    if(integer::condition("JZ",flags)) goto L006dd81b;
  }
  { // 0x6dd80a: 8b4324 MOV EAX,dword ptr [EBX + 0x24]
    s.ax = m.r32((s.bx+0x00000024u));
  }
  { // 0x6dd80d: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x6dd80e: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  { // 0x6dd810: 7ce4 JL 0x006dd7f6
    if(integer::condition("JL",flags)) goto L006dd7f6;
  }
  L006dd812: { // 0x6dd812: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dd813: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6dd814: 83c8ff OR EAX,0xffffffff
    s.ax = integer::logical((s.ax)|(0xffffffffu),32,flags);
  }
  { // 0x6dd817: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6dd818: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L006dd81b: { // 0x6dd81b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x6dd81d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6dd81e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6dd81f: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x6dd820: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0030bc10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x70bc10: 83ec78 SUB ESP,0x78
    f.sp = integer::sub(f.sp,0x00000078u,32,flags);
  }
  { // 0x70bc13: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x70bc14: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x70bc15: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x70bc17: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  { // 0x70bc19: 8b942488000000 MOV EDX,dword ptr [ESP + 0x88]
    s.dx = m.r32((f.sp+0x00000088u));
  }
  { // 0x70bc20: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x70bc21: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x70bc22: 8d4c2458 LEA ECX,[ESP + 0x58]
    s.cx = (f.sp+0x00000058u);
  }
  { // 0x70bc26: e8f525e8ff CALL 0x0058e220
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x70bc2b: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  { // 0x70bc30: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  { // 0x70bc32: 8b842494000000 MOV EAX,dword ptr [ESP + 0x94]
    s.ax = m.r32((f.sp+0x00000094u));
  }
  { // 0x70bc39: 8d7c2428 LEA EDI,[ESP + 0x28]
    s.di = (f.sp+0x00000028u);
  }
  { // 0x70bc3d: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x70bc3f: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x70bc43: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70bc44: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x70bc45: 8d4c2430 LEA ECX,[ESP + 0x30]
    s.cx = (f.sp+0x00000030u);
  }
  { // 0x70bc49: e8821ee8ff CALL 0x0058dad0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x70bc4e: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  { // 0x70bc50: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  { // 0x70bc54: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  { // 0x70bc57: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  { // 0x70bc5b: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  { // 0x70bc5d: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  { // 0x70bc60: 8b84248c000000 MOV EAX,dword ptr [ESP + 0x8c]
    s.ax = m.r32((f.sp+0x0000008cu));
  }
  { // 0x70bc67: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x70bc68: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x70bc69: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  { // 0x70bc6d: e8ae270000 CALL 0x0070e420
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x70bc72: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x70bc74: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x70bc78: 8a90a3000000 MOV DL,byte ptr [EAX + 0xa3]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000000a3u)));
  }
  { // 0x70bc7e: e85d490000 CALL 0x007105e0
    const std::uint32_t call_target=f.boundaries[3u].target;
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x70bc83: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x70bc84: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x70bc85: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x70bc86: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x70bc87: 83c478 ADD ESP,0x78
    f.sp = integer::add(f.sp,0x00000078u,32,flags);
  }
  { // 0x70bc8a: c20c00 RET 0xc
    finish(m,s,f,12u); return;
  }
}
void f_0032ccf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x72ccf0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  { // 0x72ccf3: f6c5ff TEST CH,0xff
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x000000ffu),8,flags);
  }
  { // 0x72ccf6: 7414 JZ 0x0072cd0c
    if(integer::condition("JZ",flags)) goto L0072cd0c;
  }
  { // 0x72ccf8: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x72ccfa: 884c2401 MOV byte ptr [ESP + 0x1],CL
    m.w8((f.sp+0x00000001u), (s.cx & 0xffu));
  }
  { // 0x72ccfe: c1e808 SHR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::right);
  }
  { // 0x72cd01: 88442400 MOV byte ptr [ESP],AL
    m.w8((f.sp), (s.ax & 0xffu));
  }
  { // 0x72cd05: c644240200 MOV byte ptr [ESP + 0x2],0x0
    m.w8((f.sp+0x00000002u), 0x00000000u);
  }
  { // 0x72cd0a: eb09 JMP 0x0072cd15
    goto L0072cd15;
  }
  L0072cd0c: { // 0x72cd0c: 884c2400 MOV byte ptr [ESP],CL
    m.w8((f.sp), (s.cx & 0xffu));
  }
  { // 0x72cd10: c644240100 MOV byte ptr [ESP + 0x1],0x0
    m.w8((f.sp+0x00000001u), 0x00000000u);
  }
  L0072cd15: { // 0x72cd15: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x72cd16: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  { // 0x72cd1a: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x72cd1c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72cd1d: 8d7c240c LEA EDI,[ESP + 0xc]
    s.di = (f.sp+0x0000000cu);
  }
  { // 0x72cd21: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x72cd24: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x72cd26: 8d54240c LEA EDX,[ESP + 0xc]
    s.dx = (f.sp+0x0000000cu);
  }
  { // 0x72cd2a: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x72cd2c: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x72cd2e: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x72cd2f: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x72cd30: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x72cd31: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72cd32: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x72cd33: ff15b8517800 CALL dword ptr [0x007851b8]
    const std::uint32_t call_target=m.r32((0x007851b8u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x72cd39: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  { // 0x72cd3a: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  { // 0x72cd3e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x72cd3f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x72cd41: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x72cd43: f7d0 NOT EAX
    s.ax = (~(s.ax)&integer::mask(32));
  }
  { // 0x72cd45: 23c1 AND EAX,ECX
    s.ax = integer::logical((s.ax)&(s.cx),32,flags);
  }
  { // 0x72cd47: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x72cd4a: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0033ee80(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x73ee80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x73ee81: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x73ee83: b9c4000000 MOV ECX,0xc4
    s.cx = 0x000000c4u;
  }
  { // 0x73ee88: e873b6feff CALL 0x0072a500
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x73ee8d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x73ee8f: 741b JZ 0x0073eeac
    if(integer::condition("JZ",flags)) goto L0073eeac;
  }
  { // 0x73ee91: 8b0da800b100 MOV ECX,dword ptr [0x00b100a8]
    s.cx = m.r32((0x00b100a8u));
  }
  { // 0x73ee97: f7d6 NOT ESI
    s.si = (~(s.si)&integer::mask(32));
  }
  { // 0x73ee99: 23ce AND ECX,ESI
    s.cx = integer::logical((s.cx)&(s.si),32,flags);
  }
  { // 0x73ee9b: 890da800b100 MOV dword ptr [0x00b100a8],ECX
    m.w32((0x00b100a8u), s.cx);
  }
  { // 0x73eea1: 7509 JNZ 0x0073eeac
    if(integer::condition("JNZ",flags)) goto L0073eeac;
  }
  { // 0x73eea3: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x73eea5: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x73eea7: e8f4b4feff CALL 0x0072a3a0
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L0073eeac: { // 0x73eeac: e81fb8feff CALL 0x0072a6d0
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x73eeb1: 6840050000 PUSH 0x540
    f.push(m,0x00000540u);
  }
  { // 0x73eeb6: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x73eeb7: ff159c547800 CALL dword ptr [0x0078549c]
    const std::uint32_t call_target=m.r32((0x0078549cu));
    invoke(m,s,f,op,3u,call_target); flags=0x202u;
  }
  { // 0x73eebd: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x73eebf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x73eec0: 7407 JZ 0x0073eec9
    if(integer::condition("JZ",flags)) goto L0073eec9;
  }
  { // 0x73eec2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x73eec3: ff158c537800 CALL dword ptr [0x0078538c]
    const std::uint32_t call_target=m.r32((0x0078538cu));
    invoke(m,s,f,op,4u,call_target); flags=0x202u;
  }
  L0073eec9: { // 0x73eec9: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00359260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x759260: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x759261: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x759262: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x759266: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x759268: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75926a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75926b: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  { // 0x759271: 740d JZ 0x00759280
    if(integer::condition("JZ",flags)) goto L00759280;
  }
  { // 0x759273: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x759275: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x759278: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75927a: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75927c: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x75927e: eb05 JMP 0x00759285
    goto L00759285;
  }
  L00759280: { // 0x759280: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00759285: { // 0x759285: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x759286: e8cc460100 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75928b: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75928e: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x759290: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x759292: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  { // 0x759295: 741f JZ 0x007592b6
    if(integer::condition("JZ",flags)) goto L007592b6;
  }
  { // 0x759297: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x759299: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75929c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75929e: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x7592a0: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x7592a2: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x7592a4: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x7592a6: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x7592a8: 8b3b MOV EDI,dword ptr [EBX]
    s.di = m.r32((s.bx));
  }
  { // 0x7592aa: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x7592ad: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x7592af: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x7592b1: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x7592b4: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L007592b6: { // 0x7592b6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7592b7: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x7592b9: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7592ba: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x7592bb: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_003592c0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7592c0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x7592c1: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7592c2: 8b74240c MOV ESI,dword ptr [ESP + 0xc]
    s.si = m.r32((f.sp+0x0000000cu));
  }
  { // 0x7592c6: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x7592c8: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7592c9: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  { // 0x7592cf: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x7592d1: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  { // 0x7592d3: 7435 JZ 0x0075930a
    if(integer::condition("JZ",flags)) goto L0075930a;
  }
  { // 0x7592d5: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x7592d8: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7592da: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x7592dc: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x7592de: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x7592df: e873460100 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x7592e4: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  { // 0x7592e6: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x7592e9: 8913 MOV dword ptr [EBX],EDX
    m.w32((s.bx), s.dx);
  }
  { // 0x7592eb: 8b3e MOV EDI,dword ptr [ESI]
    s.di = m.r32((s.si));
  }
  { // 0x7592ed: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7592ef: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x7592f2: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x7592f4: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x7592f6: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x7592f8: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x7592fa: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x7592fc: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x7592fe: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x759301: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x759303: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x759305: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x759308: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L0075930a: { // 0x75930a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75930b: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x75930d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75930e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75930f: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00359500(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x759500: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x759501: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x759503: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x759504: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x759505: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x759507: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x759509: 7409 JZ 0x00759514
    if(integer::condition("JZ",flags)) goto L00759514;
  }
  { // 0x75950b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75950c: e86a410100 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x759511: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00759514: { // 0x759514: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x759518: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  { // 0x75951e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x759520: 740d JZ 0x0075952f
    if(integer::condition("JZ",flags)) goto L0075952f;
  }
  { // 0x759522: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x759524: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x759527: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x759529: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75952b: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x75952d: eb05 JMP 0x00759534
    goto L00759534;
  }
  L0075952f: { // 0x75952f: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L00759534: { // 0x759534: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x759535: e81d440100 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75953a: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75953d: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x75953f: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x759541: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  { // 0x759544: 741f JZ 0x00759565
    if(integer::condition("JZ",flags)) goto L00759565;
  }
  { // 0x759546: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x759548: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75954b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75954d: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75954f: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x759551: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x759553: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x759555: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x759557: 8b3b MOV EDI,dword ptr [EBX]
    s.di = m.r32((s.bx));
  }
  { // 0x759559: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x75955c: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x75955e: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x759560: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x759563: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L00759565: { // 0x759565: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x759566: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  { // 0x759568: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x759569: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75956a: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00359e00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x759e00: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x759e01: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x759e02: 8b6c240c MOV EBP,dword ptr [ESP + 0xc]
    s.bp = m.r32((f.sp+0x0000000cu));
  }
  { // 0x759e06: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x759e07: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x759e08: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x759e0a: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L00759e0c: { // 0x759e0c: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x759e0e: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x759e10: 7504 JNZ 0x00759e16
    if(integer::condition("JNZ",flags)) goto L00759e16;
  }
  { // 0x759e12: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x759e14: eb0c JMP 0x00759e22
    goto L00759e22;
  }
  L00759e16: { // 0x759e16: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x759e18: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x759e1b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x759e1d: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x759e1f: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x759e21: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00759e22: { // 0x759e22: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x759e24: 7d21 JGE 0x00759e47
    if(integer::condition("JGE",flags)) goto L00759e47;
  }
  { // 0x759e26: 8b4500 MOV EAX,dword ptr [EBP]
    s.ax = m.r32((s.bp));
  }
  { // 0x759e29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x759e2b: 7505 JNZ 0x00759e32
    if(integer::condition("JNZ",flags)) goto L00759e32;
  }
  { // 0x759e2d: b8a4488200 MOV EAX,0x8248a4
    s.ax = 0x008248a4u;
  }
  L00759e32: { // 0x759e32: 0fbe0c32 MOVSX ECX,byte ptr [EDX + ESI*0x1]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.dx+(s.si * 0x00000001u))),8));
  }
  { // 0x759e36: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x759e37: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x759e38: e8335c0100 CALL 0x0076fa70
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x759e3d: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x759e40: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x759e42: 7403 JZ 0x00759e47
    if(integer::condition("JZ",flags)) goto L00759e47;
  }
  { // 0x759e44: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x759e45: ebc5 JMP 0x00759e0c
    goto L00759e0c;
  }
  L00759e47: { // 0x759e47: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x759e49: 7e0a JLE 0x00759e55
    if(integer::condition("JLE",flags)) goto L00759e55;
  }
  { // 0x759e4b: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x759e4c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x759e4e: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x759e50: e8fbfdffff CALL 0x00759c50
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  L00759e55: { // 0x759e55: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x759e56: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x759e57: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x759e58: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x759e59: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00359f90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x759f90: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x759f91: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x759f92: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x759f94: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x759f96: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x759f98: 7409 JZ 0x00759fa3
    if(integer::condition("JZ",flags)) goto L00759fa3;
  }
  { // 0x759f9a: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x759f9b: e8db360100 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x759fa0: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00759fa3: { // 0x759fa3: 8b5c240c MOV EBX,dword ptr [ESP + 0xc]
    s.bx = m.r32((f.sp+0x0000000cu));
  }
  { // 0x759fa7: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x759fad: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x759faf: 7c21 JL 0x00759fd2
    if(integer::condition("JL",flags)) goto L00759fd2;
  }
  { // 0x759fb1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x759fb2: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x759fb3: e89f390100 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x759fb8: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x759fba: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x759fbc: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x759fbe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x759fc0: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x759fc3: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  { // 0x759fc5: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x759fc8: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x759fca: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x759fcc: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x759fcf: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  { // 0x759fd1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00759fd2: { // 0x759fd2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x759fd3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x759fd4: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035a670(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75a670: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75a671: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x75a673: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75a674: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75a675: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  { // 0x75a677: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75a679: 7409 JZ 0x0075a684
    if(integer::condition("JZ",flags)) goto L0075a684;
  }
  { // 0x75a67b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75a67c: e8fa2f0100 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75a681: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075a684: { // 0x75a684: 8b742410 MOV ESI,dword ptr [ESP + 0x10]
    s.si = m.r32((f.sp+0x00000010u));
  }
  { // 0x75a688: c70300000000 MOV dword ptr [EBX],0x0
    m.w32((s.bx), 0x00000000u);
  }
  { // 0x75a68e: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75a690: 740d JZ 0x0075a69f
    if(integer::condition("JZ",flags)) goto L0075a69f;
  }
  { // 0x75a692: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x75a694: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75a697: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75a699: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75a69b: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x75a69d: eb05 JMP 0x0075a6a4
    goto L0075a6a4;
  }
  L0075a69f: { // 0x75a69f: b901000000 MOV ECX,0x1
    s.cx = 0x00000001u;
  }
  L0075a6a4: { // 0x75a6a4: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x75a6a5: e8ad320100 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75a6aa: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75a6ad: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  { // 0x75a6af: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  { // 0x75a6b1: c60000 MOV byte ptr [EAX],0x0
    m.w8((s.ax), 0x00000000u);
  }
  { // 0x75a6b4: 741f JZ 0x0075a6d5
    if(integer::condition("JZ",flags)) goto L0075a6d5;
  }
  { // 0x75a6b6: 8bfe MOV EDI,ESI
    s.di = s.si;
  }
  { // 0x75a6b8: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75a6bb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75a6bd: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75a6bf: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x75a6c1: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x75a6c3: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x75a6c5: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x75a6c7: 8b3b MOV EDI,dword ptr [EBX]
    s.di = m.r32((s.bx));
  }
  { // 0x75a6c9: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x75a6cc: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x75a6ce: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  { // 0x75a6d0: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x75a6d3: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L0075a6d5: { // 0x75a6d5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75a6d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75a6d7: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x75a6d9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75a6da: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035a760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75a760: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75a761: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75a762: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75a763: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x75a765: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0075a767: { // 0x75a767: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x75a769: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x75a76b: 7431 JZ 0x0075a79e
    if(integer::condition("JZ",flags)) goto L0075a79e;
  }
  { // 0x75a76d: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x75a76f: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75a772: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75a774: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75a776: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x75a778: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x75a779: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x75a77b: 7321 JNC 0x0075a79e
    if(integer::condition("JNC",flags)) goto L0075a79e;
  }
  { // 0x75a77d: 8a1432 MOV DL,byte ptr [EDX + ESI*0x1]
    s.dx = with_al(s.dx, m.r8((s.dx+(s.si * 0x00000001u))));
  }
  { // 0x75a780: 80fa41 CMP DL,0x41
    (void)integer::sub((s.dx & 0xffu),0x00000041u,8,flags);
  }
  { // 0x75a783: 7c16 JL 0x0075a79b
    if(integer::condition("JL",flags)) goto L0075a79b;
  }
  { // 0x75a785: 80fa5a CMP DL,0x5a
    (void)integer::sub((s.dx & 0xffu),0x0000005au,8,flags);
  }
  { // 0x75a788: 7f11 JG 0x0075a79b
    if(integer::condition("JG",flags)) goto L0075a79b;
  }
  { // 0x75a78a: 0fbec2 MOVSX EAX,DL
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffu),8));
  }
  { // 0x75a78d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75a78e: e8a1530100 CALL 0x0076fb34
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75a793: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x75a795: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75a798: 880431 MOV byte ptr [ECX + ESI*0x1],AL
    m.w8((s.cx+(s.si * 0x00000001u)), (s.ax & 0xffu));
  }
  L0075a79b: { // 0x75a79b: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x75a79c: ebc9 JMP 0x0075a767
    goto L0075a767;
  }
  L0075a79e: { // 0x75a79e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75a79f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75a7a0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75a7a1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035a880(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75a880: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75a881: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75a882: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75a883: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  { // 0x75a885: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0075a887: { // 0x75a887: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  { // 0x75a889: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x75a88b: 7431 JZ 0x0075a8be
    if(integer::condition("JZ",flags)) goto L0075a8be;
  }
  { // 0x75a88d: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x75a88f: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75a892: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75a894: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75a896: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x75a898: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x75a899: 3bf1 CMP ESI,ECX
    (void)integer::sub(s.si,s.cx,32,flags);
  }
  { // 0x75a89b: 7321 JNC 0x0075a8be
    if(integer::condition("JNC",flags)) goto L0075a8be;
  }
  { // 0x75a89d: 8a1432 MOV DL,byte ptr [EDX + ESI*0x1]
    s.dx = with_al(s.dx, m.r8((s.dx+(s.si * 0x00000001u))));
  }
  { // 0x75a8a0: 80fa61 CMP DL,0x61
    (void)integer::sub((s.dx & 0xffu),0x00000061u,8,flags);
  }
  { // 0x75a8a3: 7c16 JL 0x0075a8bb
    if(integer::condition("JL",flags)) goto L0075a8bb;
  }
  { // 0x75a8a5: 80fa7a CMP DL,0x7a
    (void)integer::sub((s.dx & 0xffu),0x0000007au,8,flags);
  }
  { // 0x75a8a8: 7f11 JG 0x0075a8bb
    if(integer::condition("JG",flags)) goto L0075a8bb;
  }
  { // 0x75a8aa: 0fbec2 MOVSX EAX,DL
    s.ax = std::uint32_t(integer::sign_extend((s.dx & 0xffu),8));
  }
  { // 0x75a8ad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75a8ae: e8603a0100 CALL 0x0076e313
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75a8b3: 8b0b MOV ECX,dword ptr [EBX]
    s.cx = m.r32((s.bx));
  }
  { // 0x75a8b5: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75a8b8: 880431 MOV byte ptr [ECX + ESI*0x1],AL
    m.w8((s.cx+(s.si * 0x00000001u)), (s.ax & 0xffu));
  }
  L0075a8bb: { // 0x75a8bb: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x75a8bc: ebc9 JMP 0x0075a887
    goto L0075a887;
  }
  L0075a8be: { // 0x75a8be: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75a8bf: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75a8c0: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75a8c1: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0035b260(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75b260: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75b261: 8b5c2408 MOV EBX,dword ptr [ESP + 0x8]
    s.bx = m.r32((f.sp+0x00000008u));
  }
  { // 0x75b265: 85db TEST EBX,EBX
    (void)integer::logical((s.bx)&(s.bx),32,flags);
  }
  { // 0x75b267: 742c JZ 0x0075b295
    if(integer::condition("JZ",flags)) goto L0075b295;
  }
  { // 0x75b269: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  { // 0x75b26b: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x75b26d: 7426 JZ 0x0075b295
    if(integer::condition("JZ",flags)) goto L0075b295;
  }
  { // 0x75b26f: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75b270: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75b271: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  { // 0x75b273: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x75b276: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75b278: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75b279: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x75b27b: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  { // 0x75b27d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  { // 0x75b27e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x75b27f: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75b281: e88a600100 CALL 0x00771310
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75b286: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  { // 0x75b289: 3bc6 CMP EAX,ESI
    (void)integer::sub(s.ax,s.si,32,flags);
  }
  { // 0x75b28b: 1bc0 SBB EAX,EAX
    s.ax = integer::sub(s.ax,s.ax,32,flags,flags&integer::CF);
  }
  { // 0x75b28d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75b28e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75b28f: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x75b291: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75b292: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
  L0075b295: { // 0x75b295: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x75b297: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x75b298: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_0035bc90(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x75bc90: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x75bc91: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  { // 0x75bc93: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  { // 0x75bc95: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75bc97: 7409 JZ 0x0075bca2
    if(integer::condition("JZ",flags)) goto L0075bca2;
  }
  { // 0x75bc99: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x75bc9a: e8dc190100 CALL 0x0076d67b
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x75bc9f: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L0075bca2: { // 0x75bca2: 8b442408 MOV EAX,dword ptr [ESP + 0x8]
    s.ax = m.r32((f.sp+0x00000008u));
  }
  { // 0x75bca6: c70600000000 MOV dword ptr [ESI],0x0
    m.w32((s.si), 0x00000000u);
  }
  { // 0x75bcac: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x75bcae: 7c26 JL 0x0075bcd6
    if(integer::condition("JL",flags)) goto L0075bcd6;
  }
  { // 0x75bcb0: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75bcb1: 8d1c00 LEA EBX,[EAX + EAX*0x1]
    s.bx = (s.ax+(s.ax * 0x00000001u));
  }
  { // 0x75bcb4: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x75bcb5: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x75bcb6: e89c1c0100 CALL 0x0076d957
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x75bcbb: 8bcb MOV ECX,EBX
    s.cx = s.bx;
  }
  { // 0x75bcbd: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  { // 0x75bcbf: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  { // 0x75bcc1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x75bcc3: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  { // 0x75bcc6: 893e MOV dword ptr [ESI],EDI
    m.w32((s.si), s.di);
  }
  { // 0x75bcc8: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  { // 0x75bccb: f3ab STOSD.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::count);
  }
  { // 0x75bccd: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  { // 0x75bccf: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  { // 0x75bcd2: f3aa STOSB.REP ES:EDI
    string_instruction(m,s,flags,Kind::store,8u,Repeat::count);
  }
  { // 0x75bcd4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x75bcd5: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0075bcd6: { // 0x75bcd6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x75bcd7: c20400 RET 0x4
    finish(m,s,f,4u); return;
  }
}
void f_00376b24(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x776b24: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x776b25: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x776b27: 83ec20 SUB ESP,0x20
    f.sp = integer::sub(f.sp,0x00000020u,32,flags);
  }
  { // 0x776b2a: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x776b2d: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x776b2e: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x776b2f: 6a08 PUSH 0x8
    f.push(m,0x00000008u);
  }
  { // 0x776b31: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x776b32: be38c87900 MOV ESI,0x79c838
    s.si = 0x0079c838u;
  }
  { // 0x776b37: 8d7de0 LEA EDI,[EBP + -0x20]
    s.di = (s.bp-0x00000020u);
  }
  { // 0x776b3a: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  { // 0x776b3c: 8945f8 MOV dword ptr [EBP + -0x8],EAX
    m.w32((s.bp-0x00000008u), s.ax);
  }
  { // 0x776b3f: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x776b42: 8945fc MOV dword ptr [EBP + -0x4],EAX
    m.w32((s.bp-0x00000004u), s.ax);
  }
  { // 0x776b45: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x776b48: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x776b49: ff75f0 PUSH dword ptr [EBP + -0x10]
    f.push(m,m.r32((s.bp-0x00000010u)));
  }
  { // 0x776b4c: ff75e4 PUSH dword ptr [EBP + -0x1c]
    f.push(m,m.r32((s.bp-0x0000001cu)));
  }
  { // 0x776b4f: ff75e0 PUSH dword ptr [EBP + -0x20]
    f.push(m,m.r32((s.bp-0x00000020u)));
  }
  { // 0x776b52: ff1538537800 CALL dword ptr [0x00785338]
    const std::uint32_t call_target=m.r32((0x00785338u));
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x776b58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x776b59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x776b5a: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x776b5b: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
void f_0037ba3b(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77ba3b: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77ba3c: 8b7c2408 MOV EDI,dword ptr [ESP + 0x8]
    s.di = m.r32((f.sp+0x00000008u));
  }
  { // 0x77ba40: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x77ba42: ab STOSD ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::single);
  }
  { // 0x77ba43: ab STOSD ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::single);
  }
  { // 0x77ba44: ab STOSD ES:EDI
    string_instruction(m,s,flags,Kind::store,32u,Repeat::single);
  }
  { // 0x77ba45: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77ba46: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_0037be00(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x77be00: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x77be01: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x77be03: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  { // 0x77be06: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x77be07: 8d4508 LEA EAX,[EBP + 0x8]
    s.ax = (s.bp+0x00000008u);
  }
  { // 0x77be0a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77be0b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77be0c: 8d45f4 LEA EAX,[EBP + -0xc]
    s.ax = (s.bp-0x0000000cu);
  }
  { // 0x77be0f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77be10: e847000000 CALL 0x0077be5c
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x77be15: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77be16: 8d45d8 LEA EAX,[EBP + -0x28]
    s.ax = (s.bp-0x00000028u);
  }
  { // 0x77be19: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x77be1a: 8d75f4 LEA ESI,[EBP + -0xc]
    s.si = (s.bp-0x0000000cu);
  }
  { // 0x77be1d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77be1e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x77be20: 6a11 PUSH 0x11
    f.push(m,0x00000011u);
  }
  { // 0x77be22: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x77be25: 8bfc MOV EDI,ESP
    s.di = f.sp;
  }
  { // 0x77be27: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  { // 0x77be28: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  { // 0x77be29: 66a5 MOVSW ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,16u,Repeat::single);
  }
  { // 0x77be2b: e87f470000 CALL 0x007805af
    const std::uint32_t call_target=f.boundaries[1u].target;
    invoke(m,s,f,op,1u,call_target); flags=0x202u;
  }
  { // 0x77be30: 8b7510 MOV ESI,dword ptr [EBP + 0x10]
    s.si = m.r32((s.bp+0x00000010u));
  }
  { // 0x77be33: 8b7d14 MOV EDI,dword ptr [EBP + 0x14]
    s.di = m.r32((s.bp+0x00000014u));
  }
  { // 0x77be36: 894608 MOV dword ptr [ESI + 0x8],EAX
    m.w32((s.si+0x00000008u), s.ax);
  }
  { // 0x77be39: 0fbe45da MOVSX EAX,byte ptr [EBP + -0x26]
    s.ax = std::uint32_t(integer::sign_extend(m.r8((s.bp-0x00000026u)),8));
  }
  { // 0x77be3d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  { // 0x77be3f: 0fbf45d8 MOVSX EAX,word ptr [EBP + -0x28]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.bp-0x00000028u)),16));
  }
  { // 0x77be43: 894604 MOV dword ptr [ESI + 0x4],EAX
    m.w32((s.si+0x00000004u), s.ax);
  }
  { // 0x77be46: 8d45dc LEA EAX,[EBP + -0x24]
    s.ax = (s.bp-0x00000024u);
  }
  { // 0x77be49: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x77be4a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x77be4b: e8c0d1ffff CALL 0x00779010
    const std::uint32_t call_target=f.boundaries[2u].target;
    invoke(m,s,f,op,2u,call_target); flags=0x202u;
  }
  { // 0x77be50: 83c420 ADD ESP,0x20
    f.sp = integer::add(f.sp,0x00000020u,32,flags);
  }
  { // 0x77be53: 897e0c MOV dword ptr [ESI + 0xc],EDI
    m.w32((s.si+0x0000000cu), s.di);
  }
  { // 0x77be56: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x77be58: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x77be59: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x77be5a: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x77be5b: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_00380c48(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x780c48: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x780c49: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x780c4b: 83ec0c SUB ESP,0xc
    f.sp = integer::sub(f.sp,0x0000000cu,32,flags);
  }
  { // 0x780c4e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x780c4f: bb88878100 MOV EBX,0x818788
    s.bx = 0x00818788u;
  }
  { // 0x780c54: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x780c56: 83eb60 SUB EBX,0x60
    s.bx = integer::sub(s.bx,0x00000060u,32,flags);
  }
  { // 0x780c59: 394d0c CMP dword ptr [EBP + 0xc],ECX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.cx,32,flags);
  }
  { // 0x780c5c: 7463 JZ 0x00780cc1
    if(integer::condition("JZ",flags)) goto L00780cc1;
  }
  { // 0x780c5e: 7d10 JGE 0x00780c70
    if(integer::condition("JGE",flags)) goto L00780c70;
  }
  { // 0x780c60: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x780c63: bbe8888100 MOV EBX,0x8188e8
    s.bx = 0x008188e8u;
  }
  { // 0x780c68: f7d8 NEG EAX
    s.ax = integer::sub(0u,s.ax,32,flags);
  }
  { // 0x780c6a: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  { // 0x780c6d: 83eb60 SUB EBX,0x60
    s.bx = integer::sub(s.bx,0x00000060u,32,flags);
  }
  L00780c70: { // 0x780c70: 394d10 CMP dword ptr [EBP + 0x10],ECX
    (void)integer::sub(m.r32((s.bp+0x00000010u)),s.cx,32,flags);
  }
  { // 0x780c73: 7506 JNZ 0x00780c7b
    if(integer::condition("JNZ",flags)) goto L00780c7b;
  }
  { // 0x780c75: 8b4508 MOV EAX,dword ptr [EBP + 0x8]
    s.ax = m.r32((s.bp+0x00000008u));
  }
  { // 0x780c78: 668908 MOV word ptr [EAX],CX
    m.w16((s.ax), (s.cx & 0xffffu));
  }
  L00780c7b: { // 0x780c7b: 394d0c CMP dword ptr [EBP + 0xc],ECX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.cx,32,flags);
  }
  { // 0x780c7e: 7441 JZ 0x00780cc1
    if(integer::condition("JZ",flags)) goto L00780cc1;
  }
  { // 0x780c80: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780c81: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00780c82: { // 0x780c82: 8b450c MOV EAX,dword ptr [EBP + 0xc]
    s.ax = m.r32((s.bp+0x0000000cu));
  }
  { // 0x780c85: 83c354 ADD EBX,0x54
    s.bx = integer::add(s.bx,0x00000054u,32,flags);
  }
  { // 0x780c88: c17d0c03 SAR dword ptr [EBP + 0xc],0x3
    m.w32((s.bp+0x0000000cu), integer::shift(m.r32((s.bp+0x0000000cu)),0x00000003u,32,flags,integer::Shift::arithmetic_right));
  }
  { // 0x780c8c: 83e007 AND EAX,0x7
    s.ax = integer::logical((s.ax)&(0x00000007u),32,flags);
  }
  { // 0x780c8f: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x780c91: 7427 JZ 0x00780cba
    if(integer::condition("JZ",flags)) goto L00780cba;
  }
  { // 0x780c93: 8d0440 LEA EAX,[EAX + EAX*0x2]
    s.ax = (s.ax+(s.ax * 0x00000002u));
  }
  { // 0x780c96: 66813c830080 CMP word ptr [EBX + EAX*0x4],0x8000
    (void)integer::sub(m.r16((s.bx+(s.ax * 0x00000004u))),0x00008000u,16,flags);
  }
  { // 0x780c9c: 8d3483 LEA ESI,[EBX + EAX*0x4]
    s.si = (s.bx+(s.ax * 0x00000004u));
  }
  { // 0x780c9f: 720c JC 0x00780cad
    if(integer::condition("JC",flags)) goto L00780cad;
  }
  { // 0x780ca1: 8d7df4 LEA EDI,[EBP + -0xc]
    s.di = (s.bp-0x0000000cu);
  }
  { // 0x780ca4: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  { // 0x780ca5: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  { // 0x780ca6: a5 MOVSD ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::single);
  }
  { // 0x780ca7: ff4df6 DEC dword ptr [EBP + -0xa]
    m.w32((s.bp-0x0000000au), integer::decrement(m.r32((s.bp-0x0000000au)),32,flags));
  }
  { // 0x780caa: 8d75f4 LEA ESI,[EBP + -0xc]
    s.si = (s.bp-0x0000000cu);
  }
  L00780cad: { // 0x780cad: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x780cae: ff7508 PUSH dword ptr [EBP + 0x8]
    f.push(m,m.r32((s.bp+0x00000008u)));
  }
  { // 0x780cb1: e872fdffff CALL 0x00780a28
    const std::uint32_t call_target=f.boundaries[0u].target;
    invoke(m,s,f,op,0u,call_target); flags=0x202u;
  }
  { // 0x780cb6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x780cb7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  { // 0x780cb8: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00780cba: { // 0x780cba: 394d0c CMP dword ptr [EBP + 0xc],ECX
    (void)integer::sub(m.r32((s.bp+0x0000000cu)),s.cx,32,flags);
  }
  { // 0x780cbd: 75c3 JNZ 0x00780c82
    if(integer::condition("JNZ",flags)) goto L00780c82;
  }
  { // 0x780cbf: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x780cc0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00780cc1: { // 0x780cc1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x780cc2: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x780cc3: c3 RET
    finish(m,s,f,0u); return;
  }
}
void f_003829a0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x7829a0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x7829a1: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  { // 0x7829a3: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x7829a4: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x7829a5: 8b7d08 MOV EDI,dword ptr [EBP + 0x8]
    s.di = m.r32((s.bp+0x00000008u));
  }
  { // 0x7829a8: 8bd7 MOV EDX,EDI
    s.dx = s.di;
  }
  { // 0x7829aa: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  { // 0x7829ac: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x7829ae: 83c9ff OR ECX,0xffffffff
    s.cx = integer::logical((s.cx)|(0xffffffffu),32,flags);
  }
  { // 0x7829b1: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  { // 0x7829b3: 83f9fe CMP ECX,-0x2
    (void)integer::sub(s.cx,0xfffffffeu,32,flags);
  }
  { // 0x7829b6: 7412 JZ 0x007829ca
    if(integer::condition("JZ",flags)) goto L007829ca;
  }
  { // 0x7829b8: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x7829b9: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L007829ba: { // 0x7829ba: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x7829bc: 730c JNC 0x007829ca
    if(integer::condition("JNC",flags)) goto L007829ca;
  }
  { // 0x7829be: 8a26 MOV AH,byte ptr [ESI]
    s.ax = (s.ax & 0xffff00ffu) | (((m.r8((s.si))) & 0xffu) << 8);
  }
  { // 0x7829c0: 8a07 MOV AL,byte ptr [EDI]
    s.ax = with_al(s.ax, m.r8((s.di)));
  }
  { // 0x7829c2: 8806 MOV byte ptr [ESI],AL
    m.w8((s.si), (s.ax & 0xffu));
  }
  { // 0x7829c4: 8827 MOV byte ptr [EDI],AH
    m.w8((s.di), ((s.ax >> 8) & 0xffu));
  }
  { // 0x7829c6: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  { // 0x7829c7: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x7829c8: ebf0 JMP 0x007829ba
    goto L007829ba;
  }
  L007829ca: { // 0x7829ca: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x7829cc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x7829cd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x7829ce: c9 LEAVE
    f.sp=s.bp; s.bp=f.pop(m);
  }
  { // 0x7829cf: c3 RET
    finish(m,s,f,0u); return;
  }
}
} // namespace
const std::array<Entry,37>& entries_b() {
  static const std::array<Entry,37> entries{{
    {0x1fab40u,f_001fab40},
    {0x20c750u,f_0020c750},
    {0x21e9d0u,f_0021e9d0},
    {0x225ea0u,f_00225ea0},
    {0x233830u,f_00233830},
    {0x2346c0u,f_002346c0},
    {0x234c80u,f_00234c80},
    {0x242b00u,f_00242b00},
    {0x242b70u,f_00242b70},
    {0x242c50u,f_00242c50},
    {0x243130u,f_00243130},
    {0x2431a0u,f_002431a0},
    {0x243280u,f_00243280},
    {0x2432f0u,f_002432f0},
    {0x268300u,f_00268300},
    {0x295360u,f_00295360},
    {0x2cdb50u,f_002cdb50},
    {0x2dbb70u,f_002dbb70},
    {0x2dd7d0u,f_002dd7d0},
    {0x30bc10u,f_0030bc10},
    {0x32ccf0u,f_0032ccf0},
    {0x33ee80u,f_0033ee80},
    {0x359260u,f_00359260},
    {0x3592c0u,f_003592c0},
    {0x359500u,f_00359500},
    {0x359e00u,f_00359e00},
    {0x359f90u,f_00359f90},
    {0x35a670u,f_0035a670},
    {0x35a760u,f_0035a760},
    {0x35a880u,f_0035a880},
    {0x35b260u,f_0035b260},
    {0x35bc90u,f_0035bc90},
    {0x376b24u,f_00376b24},
    {0x37ba3bu,f_0037ba3b},
    {0x37be00u,f_0037be00},
    {0x380c48u,f_00380c48},
    {0x3829a0u,f_003829a0},
  }}; return entries;
}
} // namespace ra2::recovered::strings_b37
