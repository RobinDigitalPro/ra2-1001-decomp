#include "recovered/recovery_b224_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b224 {
namespace {
void f_00147f40(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 5537600u:f_00147f40(m,s,child,{});break;
default:throw std::domain_error("recovery224 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0051ee70(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0051ee70: { // 0x51ee70: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0051ee71: { // 0x51ee71: 668b442408 MOV AX,word ptr [ESP + 0x8]
    s.ax = with_ax(s.ax, m.r16((f.sp+0x00000008u)));
  }
  L0051ee76: { // 0x51ee76: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0051ee77: { // 0x51ee77: 663b05e894a300 CMP AX,word ptr [0x00a394e8]
    (void)integer::sub((s.ax & 0xffffu),m.r16((0x00a394e8u)),16,flags);
  }
  L0051ee7e: { // 0x51ee7e: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0051ee7f: { // 0x51ee7f: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0051ee80: { // 0x51ee80: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L0051ee82: { // 0x51ee82: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L0051ee84: { // 0x51ee84: 7579 JNZ 0x0051eeff
    if(integer::condition("JNZ",flags)) goto L0051eeff;
  }
  L0051ee86: { // 0x51ee86: 668b4c2416 MOV CX,word ptr [ESP + 0x16]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000016u)));
  }
  L0051ee8b: { // 0x51ee8b: 663b0dea94a300 CMP CX,word ptr [0x00a394ea]
    (void)integer::sub((s.cx & 0xffffu),m.r16((0x00a394eau)),16,flags);
  }
  L0051ee92: { // 0x51ee92: 756b JNZ 0x0051eeff
    if(integer::condition("JNZ",flags)) goto L0051eeff;
  }
  L0051ee94: { // 0x51ee94: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L0051ee98: { // 0x51ee98: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0051ee9d: { // 0x51ee9d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0051ee9e: { // 0x51ee9e: e89d900200 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5369507u); flags=s.arithmetic_flags;
  }
  L0051eea3: { // 0x51eea3: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0051eea5: { // 0x51eea5: 7558 JNZ 0x0051eeff
    if(integer::condition("JNZ",flags)) goto L0051eeff;
  }
  L0051eea7: { // 0x51eea7: a14ca98100 MOV EAX,[0x0081a94c]
    s.ax = m.r32((0x0081a94cu));
  }
  L0051eeac: { // 0x51eeac: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0051eead: { // 0x51eead: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0051eeb2: { // 0x51eeb2: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0051eeb4: { // 0x51eeb4: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L0051eeba: { // 0x51eeba: e8810f1100 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5369535u); flags=s.arithmetic_flags;
  }
  L0051eebf: { // 0x51eebf: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L0051eec5: { // 0x51eec5: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0051eec7: { // 0x51eec7: a148a98100 MOV EAX,[0x0081a948]
    s.ax = m.r32((0x0081a948u));
  }
  L0051eecc: { // 0x51eecc: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L0051eed2: { // 0x51eed2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0051eed3: { // 0x51eed3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0051eed5: { // 0x51eed5: e8660f1100 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,5369562u); flags=s.arithmetic_flags;
  }
  L0051eeda: { // 0x51eeda: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0051eedf: { // 0x51eedf: 668944240c MOV word ptr [ESP + 0xc],AX
    m.w16((f.sp+0x0000000cu), (s.ax & 0xffffu));
  }
  L0051eee4: { // 0x51eee4: 668974240e MOV word ptr [ESP + 0xe],SI
    m.w16((f.sp+0x0000000eu), (s.si & 0xffffu));
  }
  L0051eee9: { // 0x51eee9: 8b54240c MOV EDX,dword ptr [ESP + 0xc]
    s.dx = m.r32((f.sp+0x0000000cu));
  }
  L0051eeed: { // 0x51eeed: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L0051eef1: { // 0x51eef1: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0051eef2: { // 0x51eef2: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L0051eef6: { // 0x51eef6: e845900200 CALL 0x00547f40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00547f40u,5369595u); flags=s.arithmetic_flags;
  }
  L0051eefb: { // 0x51eefb: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0051eefd: { // 0x51eefd: 74a8 JZ 0x0051eea7
    if(integer::condition("JZ",flags)) goto L0051eea7;
  }
  L0051eeff: { // 0x51eeff: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0051ef03: { // 0x51ef03: a07495a300 MOV AL,[0x00a39574]
    s.ax = with_al(s.ax, m.r8((0x00a39574u)));
  }
  L0051ef08: { // 0x51ef08: 890db894a300 MOV dword ptr [0x00a394b8],ECX
    m.w32((0x00a394b8u), s.cx);
  }
  L0051ef0e: { // 0x51ef0e: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0051ef12: { // 0x51ef12: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0051ef14: { // 0x51ef14: 890d8095a300 MOV dword ptr [0x00a39580],ECX
    m.w32((0x00a39580u), s.cx);
  }
  L0051ef1a: { // 0x51ef1a: 0f85ba010000 JNZ 0x0051f0da
    if(integer::condition("JNZ",flags)) goto L0051f0da;
  }
  L0051ef20: { // 0x51ef20: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0051ef22: { // 0x51ef22: 7420 JZ 0x0051ef44
    if(integer::condition("JZ",flags)) goto L0051ef44;
  }
  L0051ef24: { // 0x51ef24: a17895a300 MOV EAX,[0x00a39578]
    s.ax = m.r32((0x00a39578u));
  }
  L0051ef29: { // 0x51ef29: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0051ef2b: { // 0x51ef2b: 7404 JZ 0x0051ef31
    if(integer::condition("JZ",flags)) goto L0051ef31;
  }
  L0051ef2d: { // 0x51ef2d: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0051ef2f: { // 0x51ef2f: 7c06 JL 0x0051ef37
    if(integer::condition("JL",flags)) goto L0051ef37;
  }
  L0051ef31: { // 0x51ef31: 893d7895a300 MOV dword ptr [0x00a39578],EDI
    m.w32((0x00a39578u), s.di);
  }
  L0051ef37: { // 0x51ef37: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0051ef38: { // 0x51ef38: 892dd48b7c00 MOV dword ptr [0x007c8bd4],EBP
    m.w32((0x007c8bd4u), s.bp);
  }
  L0051ef3e: { // 0x51ef3e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0051ef3f: { // 0x51ef3f: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0051ef40: { // 0x51ef40: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0051ef41: { // 0x51ef41: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0051ef44: { // 0x51ef44: a1d8a5a100 MOV EAX,[0x00a1a5d8]
    s.ax = m.r32((0x00a1a5d8u));
  }
  L0051ef49: { // 0x51ef49: 8b156c89a200 MOV EDX,dword ptr [0x00a2896c]
    s.dx = m.r32((0x00a2896cu));
  }
  L0051ef4f: { // 0x51ef4f: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L0051ef51: { // 0x51ef51: 892dd48b7c00 MOV dword ptr [0x007c8bd4],EBP
    m.w32((0x007c8bd4u), s.bp);
  }
  L0051ef57: { // 0x51ef57: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0051ef59: { // 0x51ef59: 8915d08b7c00 MOV dword ptr [0x007c8bd0],EDX
    m.w32((0x007c8bd0u), s.dx);
  }
  L0051ef5f: { // 0x51ef5f: c6057495a30001 MOV byte ptr [0x00a39574],0x1
    m.w8((0x00a39574u), 0x00000001u);
  }
  L0051ef66: { // 0x51ef66: 7e49 JLE 0x0051efb1
    if(integer::condition("JLE",flags)) goto L0051efb1;
  }
  L0051ef68: { // 0x51ef68: eb06 JMP 0x0051ef70
    goto L0051ef70;
  }
  L0051ef6a: { // 0x51ef6a: 8b0d8095a300 MOV ECX,dword ptr [0x00a39580]
    s.cx = m.r32((0x00a39580u));
  }
  L0051ef70: { // 0x51ef70: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0051ef72: { // 0x51ef72: 7412 JZ 0x0051ef86
    if(integer::condition("JZ",flags)) goto L0051ef86;
  }
  L0051ef74: { // 0x51ef74: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L0051ef79: { // 0x51ef79: 8b14b0 MOV EDX,dword ptr [EAX + ESI*0x4]
    s.dx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0051ef7c: { // 0x51ef7c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0051ef7d: { // 0x51ef7d: e85e5cfcff CALL 0x004e4be0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e4be0u,5369730u); flags=s.arithmetic_flags;
  }
  L0051ef82: { // 0x51ef82: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0051ef84: { // 0x51ef84: 7521 JNZ 0x0051efa7
    if(integer::condition("JNZ",flags)) goto L0051efa7;
  }
  L0051ef86: { // 0x51ef86: a1cca5a100 MOV EAX,[0x00a1a5cc]
    s.ax = m.r32((0x00a1a5ccu));
  }
  L0051ef8b: { // 0x51ef8b: 8b0cb0 MOV ECX,dword ptr [EAX + ESI*0x4]
    s.cx = m.r32((s.ax+(s.si * 0x00000004u)));
  }
  L0051ef8e: { // 0x51ef8e: 8a813d010000 MOV AL,byte ptr [ECX + 0x13d]
    s.ax = with_al(s.ax, m.r8((s.cx+0x0000013du)));
  }
  L0051ef94: { // 0x51ef94: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0051ef96: { // 0x51ef96: 750f JNZ 0x0051efa7
    if(integer::condition("JNZ",flags)) goto L0051efa7;
  }
  L0051ef98: { // 0x51ef98: a17858a200 MOV EAX,[0x00a25878]
    s.ax = m.r32((0x00a25878u));
  }
  L0051ef9d: { // 0x51ef9d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0051ef9f: { // 0x51ef9f: 7506 JNZ 0x0051efa7
    if(integer::condition("JNZ",flags)) goto L0051efa7;
  }
  L0051efa1: { // 0x51efa1: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0051efa2: { // 0x51efa2: e8995dfdff CALL 0x004f4d40
    s.arithmetic_flags=flags; invoke(m,s,f,0x004f4d40u,5369767u); flags=s.arithmetic_flags;
  }
  L0051efa7: { // 0x51efa7: a1d8a5a100 MOV EAX,[0x00a1a5d8]
    s.ax = m.r32((0x00a1a5d8u));
  }
  L0051efac: { // 0x51efac: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0051efad: { // 0x51efad: 3bf0 CMP ESI,EAX
    (void)integer::sub(s.si,s.ax,32,flags);
  }
  L0051efaf: { // 0x51efaf: 7cb9 JL 0x0051ef6a
    if(integer::condition("JL",flags)) goto L0051ef6a;
  }
  L0051efb1: { // 0x51efb1: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0051efb6: { // 0x51efb6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0051efb8: { // 0x51efb8: 740c JZ 0x0051efc6
    if(integer::condition("JZ",flags)) goto L0051efc6;
  }
  L0051efba: { // 0x51efba: c6806956000001 MOV byte ptr [EAX + 0x5669],0x1
    m.w8((s.ax+0x00005669u), 0x00000001u);
  }
  L0051efc1: { // 0x51efc1: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0051efc6: { // 0x51efc6: 833d7c95a30001 CMP dword ptr [0x00a3957c],0x1
    (void)integer::sub(m.r32((0x00a3957cu)),0x00000001u,32,flags);
  }
  L0051efcd: { // 0x51efcd: 0f8493000000 JZ 0x0051f066
    if(integer::condition("JZ",flags)) goto L0051f066;
  }
  L0051efd3: { // 0x51efd3: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0051efd8: { // 0x51efd8: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0051efda: { // 0x51efda: 8b88c8220000 MOV ECX,dword ptr [EAX + 0x22c8]
    s.cx = m.r32((s.ax+0x000022c8u));
  }
  L0051efe0: { // 0x51efe0: 8988b0220000 MOV dword ptr [EAX + 0x22b0],ECX
    m.w32((s.ax+0x000022b0u), s.cx);
  }
  L0051efe6: { // 0x51efe6: 8b3dc055a200 MOV EDI,dword ptr [0x00a255c0]
    s.di = m.r32((0x00a255c0u));
  }
  L0051efec: { // 0x51efec: 8b87d4220000 MOV EAX,dword ptr [EDI + 0x22d4]
    s.ax = m.r32((s.di+0x000022d4u));
  }
  L0051eff2: { // 0x51eff2: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051eff5: { // 0x51eff5: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051eff8: { // 0x51eff8: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0051effb: { // 0x51effb: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0051f000: { // 0x51f000: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0051f003: { // 0x51f003: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0051f005: { // 0x51f005: c1fa05 SAR EDX,0x5
    s.dx = integer::shift(s.dx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0051f008: { // 0x51f008: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0051f00a: { // 0x51f00a: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0051f00d: { // 0x51f00d: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0051f00f: { // 0x51f00f: 8b87d0220000 MOV EAX,dword ptr [EDI + 0x22d0]
    s.ax = m.r32((s.di+0x000022d0u));
  }
  L0051f015: { // 0x51f015: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0051f016: { // 0x51f016: 8bbfcc220000 MOV EDI,dword ptr [EDI + 0x22cc]
    s.di = m.r32((s.di+0x000022ccu));
  }
  L0051f01c: { // 0x51f01c: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051f01f: { // 0x51f01f: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051f022: { // 0x51f022: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0051f025: { // 0x51f025: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0051f02a: { // 0x51f02a: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0051f02d: { // 0x51f02d: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0051f02f: { // 0x51f02f: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L0051f031: { // 0x51f031: 8d04bf LEA EAX,[EDI + EDI*0x4]
    s.ax = (s.di+(s.di * 0x00000004u));
  }
  L0051f034: { // 0x51f034: c1fe05 SAR ESI,0x5
    s.si = integer::shift(s.si,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0051f037: { // 0x51f037: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0051f039: { // 0x51f039: 8d0480 LEA EAX,[EAX + EAX*0x4]
    s.ax = (s.ax+(s.ax * 0x00000004u));
  }
  L0051f03c: { // 0x51f03c: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0051f03f: { // 0x51f03f: 03f1 ADD ESI,ECX
    s.si = integer::add(s.si,s.cx,32,flags);
  }
  L0051f041: { // 0x51f041: 8d0c80 LEA ECX,[EAX + EAX*0x4]
    s.cx = (s.ax+(s.ax * 0x00000004u));
  }
  L0051f044: { // 0x51f044: c1e103 SHL ECX,0x3
    s.cx = integer::shift(s.cx,0x00000003u,32,flags,integer::Shift::left);
  }
  L0051f047: { // 0x51f047: b81f85eb51 MOV EAX,0x51eb851f
    s.ax = 0x51eb851fu;
  }
  L0051f04c: { // 0x51f04c: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0051f04e: { // 0x51f04e: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L0051f050: { // 0x51f050: c1f905 SAR ECX,0x5
    s.cx = integer::shift(s.cx,0x00000005u,32,flags,integer::Shift::arithmetic_right);
  }
  L0051f053: { // 0x51f053: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0051f055: { // 0x51f055: c1ea1f SHR EDX,0x1f
    s.dx = integer::shift(s.dx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0051f058: { // 0x51f058: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0051f05a: { // 0x51f05a: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  L0051f05c: { // 0x51f05c: e8df0f0000 CALL 0x00520040
    s.arithmetic_flags=flags; invoke(m,s,f,0x00520040u,5369953u); flags=s.arithmetic_flags;
  }
  L0051f061: { // 0x51f061: a1e4e0a100 MOV EAX,[0x00a1e0e4]
    s.ax = m.r32((0x00a1e0e4u));
  }
  L0051f066: { // 0x51f066: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0051f06c: { // 0x51f06c: 8a9104140000 MOV DL,byte ptr [ECX + 0x1404]
    s.dx = with_al(s.dx, m.r8((s.cx+0x00001404u)));
  }
  L0051f072: { // 0x51f072: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L0051f074: { // 0x51f074: 7458 JZ 0x0051f0ce
    if(integer::condition("JZ",flags)) goto L0051f0ce;
  }
  L0051f076: { // 0x51f076: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0051f078: { // 0x51f078: be03000000 MOV ESI,0x3
    s.si = 0x00000003u;
  }
  L0051f07d: { // 0x51f07d: 7406 JZ 0x0051f085
    if(integer::condition("JZ",flags)) goto L0051f085;
  }
  L0051f07f: { // 0x51f07f: 8bb0405f0100 MOV ESI,dword ptr [EAX + 0x15f40]
    s.si = m.r32((s.ax+0x00015f40u));
  }
  L0051f085: { // 0x51f085: 8b8950060000 MOV ECX,dword ptr [ECX + 0x650]
    s.cx = m.r32((s.cx+0x00000650u));
  }
  L0051f08b: { // 0x51f08b: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0051f08d: { // 0x51f08d: ba00200000 MOV EDX,0x2000
    s.dx = 0x00002000u;
  }
  L0051f092: { // 0x51f092: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L0051f097: { // 0x51f097: e8d4981e00 CALL 0x00708970
    s.arithmetic_flags=flags; invoke(m,s,f,0x00708970u,5370012u); flags=s.arithmetic_flags;
  }
  L0051f09c: { // 0x51f09c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0051f09e: { // 0x51f09e: b9548c7c00 MOV ECX,0x7c8c54
    s.cx = 0x007c8c54u;
  }
  L0051f0a3: { // 0x51f0a3: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0051f0a5: { // 0x51f0a5: 6896000000 PUSH 0x96
    f.push(m,0x00000096u);
  }
  L0051f0aa: { // 0x51f0aa: 6846400000 PUSH 0x4046
    f.push(m,0x00004046u);
  }
  L0051f0af: { // 0x51f0af: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0051f0b0: { // 0x51f0b0: 68ce010000 PUSH 0x1ce
    f.push(m,0x000001ceu);
  }
  L0051f0b5: { // 0x51f0b5: 68448c7c00 PUSH 0x7c8c44
    f.push(m,0x007c8c44u);
  }
  L0051f0ba: { // 0x51f0ba: e8a1fa1c00 CALL 0x006eeb60
    s.arithmetic_flags=flags; invoke(m,s,f,0x006eeb60u,5370047u); flags=s.arithmetic_flags;
  }
  L0051f0bf: { // 0x51f0bf: b9a05fa200 MOV ECX,0xa25fa0
    s.cx = 0x00a25fa0u;
  }
  L0051f0c4: { // 0x51f0c4: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0051f0c5: { // 0x51f0c5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0051f0c7: { // 0x51f0c7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0051f0c9: { // 0x51f0c9: e8b2280900 CALL 0x005b1980
    s.arithmetic_flags=flags; invoke(m,s,f,0x005b1980u,5370062u); flags=s.arithmetic_flags;
  }
  L0051f0ce: { // 0x51f0ce: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  L0051f0d0: { // 0x51f0d0: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0051f0d5: { // 0x51f0d5: e8560ffcff CALL 0x004e0030
    s.arithmetic_flags=flags; invoke(m,s,f,0x004e0030u,5370074u); flags=s.arithmetic_flags;
  }
  L0051f0da: { // 0x51f0da: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0051f0db: { // 0x51f0db: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0051f0dc: { // 0x51f0dc: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0051f0dd: { // 0x51f0dd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L0051f0de: { // 0x51f0de: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
