#include "recovered/recovery_b520_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b520 {
namespace {
void f_00312760(Memory&,State&,Frame&,const Operations&);
void f_00363190(Memory&,State&,Frame&,const Operations&);
void f_00068bf0(Memory&,State&,Frame&,const Operations&);
void f_0006f990(Memory&,State&,Frame&,const Operations&);
void f_0002f1f0(Memory&,State&,Frame&,const Operations&);
void f_00038140(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_00312760(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00712760: { // 0x712760: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00712762: { // 0x712762: b201 MOV DL,0x1
    s.dx = with_al(s.dx, 0x00000001u);
  }
  L00712764: { // 0x712764: 8ac8 MOV CL,AL
    s.cx = with_al(s.cx, (s.ax & 0xffu));
  }
  L00712766: { // 0x712766: 83e107 AND ECX,0x7
    s.cx = integer::logical((s.cx)&(0x00000007u),32,flags);
  }
  L00712769: { // 0x712769: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  L0071276b: { // 0x71276b: c1f803 SAR EAX,0x3
    s.ax = integer::shift(s.ax,0x00000003u,32,flags,integer::Shift::arithmetic_right);
  }
  L0071276e: { // 0x71276e: 8490a00aae00 TEST byte ptr [EAX + 0xae0aa0],DL
    (void)integer::logical((m.r8((s.ax+0x00ae0aa0u)))&((s.dx & 0xffu)),8,flags);
  }
  L00712774: { // 0x712774: 0f95c0 SETNZ AL
    s.ax = with_al(s.ax, (integer::condition("SETNZ",flags)?1u:0u));
  }
  L00712777: { // 0x712777: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00363190(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00763190: { // 0x763190: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00763191: { // 0x763191: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00763192: { // 0x763192: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L00763194: { // 0x763194: beb0977e00 MOV ESI,0x7e97b0
    s.si = 0x007e97b0u;
  }
  L00763199: { // 0x763199: b922000000 MOV ECX,0x22
    s.cx = 0x00000022u;
  }
  L0076319e: { // 0x76319e: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L007631a0: { // 0x7631a0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L007631a1: { // 0x7631a1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L007631a2: { // 0x7631a2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00068bf0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00468bf0: { // 0x468bf0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00468bf1: { // 0x468bf1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00468bf3: { // 0x468bf3: e8986d0000 CALL 0x0046f990
    s.arithmetic_flags=flags; invoke(m,s,f,0x0046f990u,4623352u); flags=s.arithmetic_flags;
  }
  L00468bf8: { // 0x468bf8: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00468bfa: { // 0x468bfa: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00468bfc: { // 0x468bfc: 8d4e54 LEA ECX,[ESI + 0x54]
    s.cx = (s.si+0x00000054u);
  }
  L00468bff: { // 0x468bff: e83cf5fcff CALL 0x00438140
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438140u,4623364u); flags=s.arithmetic_flags;
  }
  L00468c04: { // 0x468c04: c7466000000000 MOV dword ptr [ESI + 0x60],0x0
    m.w32((s.si+0x00000060u), 0x00000000u);
  }
  L00468c0b: { // 0x468c0b: c706a0567800 MOV dword ptr [ESI],0x7856a0
    m.w32((s.si), 0x007856a0u);
  }
  L00468c11: { // 0x468c11: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L00468c13: { // 0x468c13: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00468c14: { // 0x468c14: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0006f990(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0046f990: { // 0x0046f990: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0046f991: { // 0x0046f991: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0046f993: { // 0x0046f993: e858f8fbff CALL 0x0042f1f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042f1f0u,4651416u); flags=s.arithmetic_flags;
  }
  L0046f998: { // 0x0046f998: c6465000 MOV byte ptr [ESI + 0x50],0x0
    m.w8((s.si+0x00000050u), 0x00000000u);
  }
  L0046f99c: { // 0x0046f99c: c70658567800 MOV dword ptr [ESI],0x785658
    m.w32((s.si), 0x00785658u);
  }
  L0046f9a2: { // 0x0046f9a2: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0046f9a4: { // 0x0046f9a4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0046f9a5: { // 0x0046f9a5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_0002f1f0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0042f1f0: { // 0x42f1f0: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0042f1f2: { // 0x42f1f2: 83caff OR EDX,0xffffffff
    s.dx = integer::logical((s.dx)|(0xffffffffu),32,flags);
  }
  L0042f1f5: { // 0x42f1f5: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0042f1f7: { // 0x42f1f7: c7400401000000 MOV dword ptr [EAX + 0x4],0x1
    m.w32((s.ax+0x00000004u), 0x00000001u);
  }
  L0042f1fe: { // 0x42f1fe: 894808 MOV dword ptr [EAX + 0x8],ECX
    m.w32((s.ax+0x00000008u), s.cx);
  }
  L0042f201: { // 0x42f201: 89500c MOV dword ptr [EAX + 0xc],EDX
    m.w32((s.ax+0x0000000cu), s.dx);
  }
  L0042f204: { // 0x42f204: 895010 MOV dword ptr [EAX + 0x10],EDX
    m.w32((s.ax+0x00000010u), s.dx);
  }
  L0042f207: { // 0x42f207: 894814 MOV dword ptr [EAX + 0x14],ECX
    m.w32((s.ax+0x00000014u), s.cx);
  }
  L0042f20a: { // 0x42f20a: 66894818 MOV word ptr [EAX + 0x18],CX
    m.w16((s.ax+0x00000018u), (s.cx & 0xffffu));
  }
  L0042f20e: { // 0x42f20e: 6689481a MOV word ptr [EAX + 0x1a],CX
    m.w16((s.ax+0x0000001au), (s.cx & 0xffffu));
  }
  L0042f212: { // 0x42f212: 88481c MOV byte ptr [EAX + 0x1c],CL
    m.w8((s.ax+0x0000001cu), (s.cx & 0xffu));
  }
  L0042f215: { // 0x42f215: 884820 MOV byte ptr [EAX + 0x20],CL
    m.w8((s.ax+0x00000020u), (s.cx & 0xffu));
  }
  L0042f218: { // 0x42f218: 884821 MOV byte ptr [EAX + 0x21],CL
    m.w8((s.ax+0x00000021u), (s.cx & 0xffu));
  }
  L0042f21b: { // 0x42f21b: 884822 MOV byte ptr [EAX + 0x22],CL
    m.w8((s.ax+0x00000022u), (s.cx & 0xffu));
  }
  L0042f21e: { // 0x42f21e: 884823 MOV byte ptr [EAX + 0x23],CL
    m.w8((s.ax+0x00000023u), (s.cx & 0xffu));
  }
  L0042f221: { // 0x42f221: 884824 MOV byte ptr [EAX + 0x24],CL
    m.w8((s.ax+0x00000024u), (s.cx & 0xffu));
  }
  L0042f224: { // 0x42f224: 884825 MOV byte ptr [EAX + 0x25],CL
    m.w8((s.ax+0x00000025u), (s.cx & 0xffu));
  }
  L0042f227: { // 0x42f227: 894828 MOV dword ptr [EAX + 0x28],ECX
    m.w32((s.ax+0x00000028u), s.cx);
  }
  L0042f22a: { // 0x42f22a: 89482c MOV dword ptr [EAX + 0x2c],ECX
    m.w32((s.ax+0x0000002cu), s.cx);
  }
  L0042f22d: { // 0x42f22d: 894830 MOV dword ptr [EAX + 0x30],ECX
    m.w32((s.ax+0x00000030u), s.cx);
  }
  L0042f230: { // 0x42f230: 894834 MOV dword ptr [EAX + 0x34],ECX
    m.w32((s.ax+0x00000034u), s.cx);
  }
  L0042f233: { // 0x42f233: 894838 MOV dword ptr [EAX + 0x38],ECX
    m.w32((s.ax+0x00000038u), s.cx);
  }
  L0042f236: { // 0x42f236: 89503c MOV dword ptr [EAX + 0x3c],EDX
    m.w32((s.ax+0x0000003cu), s.dx);
  }
  L0042f239: { // 0x42f239: 895040 MOV dword ptr [EAX + 0x40],EDX
    m.w32((s.ax+0x00000040u), s.dx);
  }
  L0042f23c: { // 0x42f23c: 894844 MOV dword ptr [EAX + 0x44],ECX
    m.w32((s.ax+0x00000044u), s.cx);
  }
  L0042f23f: { // 0x42f23f: 894848 MOV dword ptr [EAX + 0x48],ECX
    m.w32((s.ax+0x00000048u), s.cx);
  }
  L0042f242: { // 0x42f242: 89484c MOV dword ptr [EAX + 0x4c],ECX
    m.w32((s.ax+0x0000004cu), s.cx);
  }
  L0042f245: { // 0x42f245: c7003c777800 MOV dword ptr [EAX],0x78773c
    m.w32((s.ax), 0x0078773cu);
  }
  L0042f24b: { // 0x42f24b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00038140(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00438140: { // 0x438140: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L00438144: { // 0x438144: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00438145: { // 0x438145: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00438147: { // 0x438147: 8b4c240c MOV ECX,dword ptr [ESP + 0xc]
    s.cx = m.r32((f.sp+0x0000000cu));
  }
  L0043814b: { // 0x43814b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0043814d: { // 0x43814d: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L0043814f: { // 0x43814f: 894e04 MOV dword ptr [ESI + 0x4],ECX
    m.w32((s.si+0x00000004u), s.cx);
  }
  L00438152: { // 0x438152: c6460800 MOV byte ptr [ESI + 0x8],0x0
    m.w8((s.si+0x00000008u), 0x00000000u);
  }
  L00438156: { // 0x438156: 7513 JNZ 0x0043816b
    if(integer::condition("JNZ",flags)) goto L0043816b;
  }
  L00438158: { // 0x438158: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043815a: { // 0x43815a: 7e0f JLE 0x0043816b
    if(integer::condition("JLE",flags)) goto L0043816b;
  }
  L0043815c: { // 0x43815c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0043815d: { // 0x43815d: e8f5573300 CALL 0x0076d957
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076d957u,4424034u); flags=s.arithmetic_flags;
  }
  L00438162: { // 0x438162: 83c404 ADD ESP,0x4
    f.sp = integer::add(f.sp,0x00000004u,32,flags);
  }
  L00438165: { // 0x438165: 8906 MOV dword ptr [ESI],EAX
    m.w32((s.si), s.ax);
  }
  L00438167: { // 0x438167: c6460801 MOV byte ptr [ESI + 0x8],0x1
    m.w8((s.si+0x00000008u), 0x00000001u);
  }
  L0043816b: { // 0x43816b: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0043816d: { // 0x43816d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043816e: { // 0x43816e: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 7415648u:f_00312760(m,s,child,{});break;
case 7745936u:f_00363190(m,s,child,{});break;
case 4623344u:f_00068bf0(m,s,child,{});break;
case 4651408u:f_0006f990(m,s,child,{});break;
case 4387312u:f_0002f1f0(m,s,child,{});break;
case 4424000u:f_00038140(m,s,child,{});break;
default:throw std::domain_error("recovery520 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_007111b0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L007111b0: { // 0x7111b0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L007111b1: { // 0x7111b1: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L007111b2: { // 0x7111b2: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L007111b3: { // 0x7111b3: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L007111b5: { // 0x7111b5: 56 PUSH ESI
    f.push(m,s.si);
  }
  L007111b6: { // 0x7111b6: 57 PUSH EDI
    f.push(m,s.di);
  }
  L007111b7: { // 0x7111b7: 8d4d04 LEA ECX,[EBP + 0x4]
    s.cx = (s.bp+0x00000004u);
  }
  L007111ba: { // 0x7111ba: e8317ad5ff CALL 0x00468bf0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468bf0u,7410111u); flags=s.arithmetic_flags;
  }
  L007111bf: { // 0x7111bf: 8d8d70010000 LEA ECX,[EBP + 0x170]
    s.cx = (s.bp+0x00000170u);
  }
  L007111c5: { // 0x7111c5: e8c61f0500 CALL 0x00763190
    s.arithmetic_flags=flags; invoke(m,s,f,0x00763190u,7410122u); flags=s.arithmetic_flags;
  }
  L007111ca: { // 0x7111ca: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L007111ce: { // 0x7111ce: 8d4c2413 LEA ECX,[ESP + 0x13]
    s.cx = (f.sp+0x00000013u);
  }
  L007111d2: { // 0x7111d2: 898524050000 MOV dword ptr [EBP + 0x524],EAX
    m.w32((s.bp+0x00000524u), s.ax);
  }
  L007111d8: { // 0x7111d8: 89addc010000 MOV dword ptr [EBP + 0x1dc],EBP
    m.w32((s.bp+0x000001dcu), s.bp);
  }
  L007111de: { // 0x7111de: 898d8c010000 MOV dword ptr [EBP + 0x18c],ECX
    m.w32((s.bp+0x0000018cu), s.cx);
  }
  L007111e4: { // 0x7111e4: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L007111e6: { // 0x7111e6: b90f000000 MOV ECX,0xf
    s.cx = 0x0000000fu;
  }
  L007111eb: { // 0x7111eb: 899db0010000 MOV dword ptr [EBP + 0x1b0],EBX
    m.w32((s.bp+0x000001b0u), s.bx);
  }
  L007111f1: { // 0x7111f1: e86a150000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410166u); flags=s.arithmetic_flags;
  }
  L007111f6: { // 0x7111f6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L007111f8: { // 0x7111f8: bf01000000 MOV EDI,0x1
    s.di = 0x00000001u;
  }
  L007111fd: { // 0x7111fd: 7506 JNZ 0x00711205
    if(integer::condition("JNZ",flags)) goto L00711205;
  }
  L007111ff: { // 0x7111ff: 09bdb0010000 OR dword ptr [EBP + 0x1b0],EDI
    m.w32((s.bp+0x000001b0u), integer::logical((m.r32((s.bp+0x000001b0u)))|(s.di),32,flags));
  }
  L00711205: { // 0x711205: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00711207: { // 0x711207: e854150000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410188u); flags=s.arithmetic_flags;
  }
  L0071120c: { // 0x71120c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0071120e: { // 0x71120e: 750e JNZ 0x0071121e
    if(integer::condition("JNZ",flags)) goto L0071121e;
  }
  L00711210: { // 0x711210: 8b85b0010000 MOV EAX,dword ptr [EBP + 0x1b0]
    s.ax = m.r32((s.bp+0x000001b0u));
  }
  L00711216: { // 0x711216: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L00711218: { // 0x711218: 8985b0010000 MOV dword ptr [EBP + 0x1b0],EAX
    m.w32((s.bp+0x000001b0u), s.ax);
  }
  L0071121e: { // 0x71121e: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  L00711223: { // 0x711223: e838150000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410216u); flags=s.arithmetic_flags;
  }
  L00711228: { // 0x711228: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L0071122a: { // 0x71122a: 750e JNZ 0x0071123a
    if(integer::condition("JNZ",flags)) goto L0071123a;
  }
  L0071122c: { // 0x71122c: 8b85b0010000 MOV EAX,dword ptr [EBP + 0x1b0]
    s.ax = m.r32((s.bp+0x000001b0u));
  }
  L00711232: { // 0x711232: 0c40 OR AL,0x40
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000040u),8,flags));
  }
  L00711234: { // 0x711234: 8985b0010000 MOV dword ptr [EBP + 0x1b0],EAX
    m.w32((s.bp+0x000001b0u), s.ax);
  }
  L0071123a: { // 0x71123a: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L0071123f: { // 0x71123f: e81c150000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410244u); flags=s.arithmetic_flags;
  }
  L00711244: { // 0x711244: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L00711246: { // 0x711246: 750e JNZ 0x00711256
    if(integer::condition("JNZ",flags)) goto L00711256;
  }
  L00711248: { // 0x711248: 8b85b0010000 MOV EAX,dword ptr [EBP + 0x1b0]
    s.ax = m.r32((s.bp+0x000001b0u));
  }
  L0071124e: { // 0x71124e: 0c80 OR AL,0x80
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000080u),8,flags));
  }
  L00711250: { // 0x711250: 8985b0010000 MOV dword ptr [EBP + 0x1b0],EAX
    m.w32((s.bp+0x000001b0u), s.ax);
  }
  L00711256: { // 0x711256: 8b95b4010000 MOV EDX,dword ptr [EBP + 0x1b4]
    s.dx = m.r32((s.bp+0x000001b4u));
  }
  L0071125c: { // 0x71125c: 83ca08 OR EDX,0x8
    s.dx = integer::logical((s.dx)|(0x00000008u),32,flags);
  }
  L0071125f: { // 0x71125f: 8995b4010000 MOV dword ptr [EBP + 0x1b4],EDX
    m.w32((s.bp+0x000001b4u), s.dx);
  }
  L00711265: { // 0x711265: 8a8d24050000 MOV CL,byte ptr [EBP + 0x524]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000524u)));
  }
  L0071126b: { // 0x71126b: f6c102 TEST CL,0x2
    (void)integer::logical(((s.cx & 0xffu))&(0x00000002u),8,flags);
  }
  L0071126e: { // 0x71126e: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00711270: { // 0x711270: 7418 JZ 0x0071128a
    if(integer::condition("JZ",flags)) goto L0071128a;
  }
  L00711272: { // 0x711272: 0c20 OR AL,0x20
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000020u),8,flags));
  }
  L00711274: { // 0x711274: 8985b4010000 MOV dword ptr [EBP + 0x1b4],EAX
    m.w32((s.bp+0x000001b4u), s.ax);
  }
  L0071127a: { // 0x71127a: 8a8d24050000 MOV CL,byte ptr [EBP + 0x524]
    s.cx = with_al(s.cx, m.r8((s.bp+0x00000524u)));
  }
  L00711280: { // 0x711280: f6c104 TEST CL,0x4
    (void)integer::logical(((s.cx & 0xffu))&(0x00000004u),8,flags);
  }
  L00711283: { // 0x711283: 740d JZ 0x00711292
    if(integer::condition("JZ",flags)) goto L00711292;
  }
  L00711285: { // 0x711285: 80cc01 OR AH,0x1
    s.ax = (s.ax & 0xffff00ffu) | (((integer::logical((((s.ax >> 8) & 0xffu))|(0x00000001u),8,flags)) & 0xffu) << 8);
  }
  L00711288: { // 0x711288: eb02 JMP 0x0071128c
    goto L0071128c;
  }
  L0071128a: { // 0x71128a: 24df AND AL,0xdf
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000dfu),8,flags));
  }
  L0071128c: { // 0x71128c: 8985b4010000 MOV dword ptr [EBP + 0x1b4],EAX
    m.w32((s.bp+0x000001b4u), s.ax);
  }
  L00711292: { // 0x711292: b911000000 MOV ECX,0x11
    s.cx = 0x00000011u;
  }
  L00711297: { // 0x711297: e8c4140000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410332u); flags=s.arithmetic_flags;
  }
  L0071129c: { // 0x71129c: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L0071129e: { // 0x71129e: 8b85b4010000 MOV EAX,dword ptr [EBP + 0x1b4]
    s.ax = m.r32((s.bp+0x000001b4u));
  }
  L007112a4: { // 0x7112a4: 7504 JNZ 0x007112aa
    if(integer::condition("JNZ",flags)) goto L007112aa;
  }
  L007112a6: { // 0x7112a6: 0c04 OR AL,0x4
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))|(0x00000004u),8,flags));
  }
  L007112a8: { // 0x7112a8: eb02 JMP 0x007112ac
    goto L007112ac;
  }
  L007112aa: { // 0x7112aa: 24fb AND AL,0xfb
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000fbu),8,flags));
  }
  L007112ac: { // 0x7112ac: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L007112b1: { // 0x7112b1: 8985b4010000 MOV dword ptr [EBP + 0x1b4],EAX
    m.w32((s.bp+0x000001b4u), s.ax);
  }
  L007112b7: { // 0x7112b7: e8a4140000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410364u); flags=s.arithmetic_flags;
  }
  L007112bc: { // 0x7112bc: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L007112be: { // 0x7112be: 8b85b4010000 MOV EAX,dword ptr [EBP + 0x1b4]
    s.ax = m.r32((s.bp+0x000001b4u));
  }
  L007112c4: { // 0x7112c4: 7504 JNZ 0x007112ca
    if(integer::condition("JNZ",flags)) goto L007112ca;
  }
  L007112c6: { // 0x7112c6: 24fe AND AL,0xfe
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))&(0x000000feu),8,flags));
  }
  L007112c8: { // 0x7112c8: eb02 JMP 0x007112cc
    goto L007112cc;
  }
  L007112ca: { // 0x7112ca: 0bc7 OR EAX,EDI
    s.ax = integer::logical((s.ax)|(s.di),32,flags);
  }
  L007112cc: { // 0x7112cc: 8b54242c MOV EDX,dword ptr [ESP + 0x2c]
    s.dx = m.r32((f.sp+0x0000002cu));
  }
  L007112d0: { // 0x7112d0: 83ceff OR ESI,0xffffffff
    s.si = integer::logical((s.si)|(0xffffffffu),32,flags);
  }
  L007112d3: { // 0x7112d3: 8985b4010000 MOV dword ptr [EBP + 0x1b4],EAX
    m.w32((s.bp+0x000001b4u), s.ax);
  }
  L007112d9: { // 0x7112d9: 8b442430 MOV EAX,dword ptr [ESP + 0x30]
    s.ax = m.r32((f.sp+0x00000030u));
  }
  L007112dd: { // 0x7112dd: 89b590010000 MOV dword ptr [EBP + 0x190],ESI
    m.w32((s.bp+0x00000190u), s.si);
  }
  L007112e3: { // 0x7112e3: 89b594010000 MOV dword ptr [EBP + 0x194],ESI
    m.w32((s.bp+0x00000194u), s.si);
  }
  L007112e9: { // 0x7112e9: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L007112ee: { // 0x7112ee: 899d98010000 MOV dword ptr [EBP + 0x198],EBX
    m.w32((s.bp+0x00000198u), s.bx);
  }
  L007112f4: { // 0x7112f4: 899d9c010000 MOV dword ptr [EBP + 0x19c],EBX
    m.w32((s.bp+0x0000019cu), s.bx);
  }
  L007112fa: { // 0x7112fa: 899d7c010000 MOV dword ptr [EBP + 0x17c],EBX
    m.w32((s.bp+0x0000017cu), s.bx);
  }
  L00711300: { // 0x711300: 8995a0010000 MOV dword ptr [EBP + 0x1a0],EDX
    m.w32((s.bp+0x000001a0u), s.dx);
  }
  L00711306: { // 0x711306: 8985a4010000 MOV dword ptr [EBP + 0x1a4],EAX
    m.w32((s.bp+0x000001a4u), s.ax);
  }
  L0071130c: { // 0x71130c: e84f140000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410449u); flags=s.arithmetic_flags;
  }
  L00711311: { // 0x711311: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L00711313: { // 0x711313: 7508 JNZ 0x0071131d
    if(integer::condition("JNZ",flags)) goto L0071131d;
  }
  L00711315: { // 0x711315: 89bdb8010000 MOV dword ptr [EBP + 0x1b8],EDI
    m.w32((s.bp+0x000001b8u), s.di);
  }
  L0071131b: { // 0x71131b: eb0a JMP 0x00711327
    goto L00711327;
  }
  L0071131d: { // 0x71131d: c785b80100000e000000 MOV dword ptr [EBP + 0x1b8],0xe
    m.w32((s.bp+0x000001b8u), 0x0000000eu);
  }
  L00711327: { // 0x711327: 8a8524050000 MOV AL,byte ptr [EBP + 0x524]
    s.ax = with_al(s.ax, m.r8((s.bp+0x00000524u)));
  }
  L0071132d: { // 0x71132d: 89b5bc010000 MOV dword ptr [EBP + 0x1bc],ESI
    m.w32((s.bp+0x000001bcu), s.si);
  }
  L00711333: { // 0x711333: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00711335: { // 0x711335: 740c JZ 0x00711343
    if(integer::condition("JZ",flags)) goto L00711343;
  }
  L00711337: { // 0x711337: c7857001000000227100 MOV dword ptr [EBP + 0x170],0x712200
    m.w32((s.bp+0x00000170u), 0x00712200u);
  }
  L00711341: { // 0x711341: eb0a JMP 0x0071134d
    goto L0071134d;
  }
  L00711343: { // 0x711343: c7857001000050207100 MOV dword ptr [EBP + 0x170],0x712050
    m.w32((s.bp+0x00000170u), 0x00712050u);
  }
  L0071134d: { // 0x71134d: b904000000 MOV ECX,0x4
    s.cx = 0x00000004u;
  }
  L00711352: { // 0x711352: c7857401000040227100 MOV dword ptr [EBP + 0x174],0x712240
    m.w32((s.bp+0x00000174u), 0x00712240u);
  }
  L0071135c: { // 0x71135c: c78578010000a0227100 MOV dword ptr [EBP + 0x178],0x7122a0
    m.w32((s.bp+0x00000178u), 0x007122a0u);
  }
  L00711366: { // 0x711366: e8f5130000 CALL 0x00712760
    s.arithmetic_flags=flags; invoke(m,s,f,0x00712760u,7410539u); flags=s.arithmetic_flags;
  }
  L0071136b: { // 0x71136b: 3c01 CMP AL,0x1
    (void)integer::sub((s.ax & 0xffu),0x00000001u,8,flags);
  }
  L0071136d: { // 0x71136d: 7516 JNZ 0x00711385
    if(integer::condition("JNZ",flags)) goto L00711385;
  }
  L0071136f: { // 0x71136f: c78580010000c0224100 MOV dword ptr [EBP + 0x180],0x4122c0
    m.w32((s.bp+0x00000180u), 0x004122c0u);
  }
  L00711379: { // 0x711379: c785a80100003c000000 MOV dword ptr [EBP + 0x1a8],0x3c
    m.w32((s.bp+0x000001a8u), 0x0000003cu);
  }
  L00711383: { // 0x711383: eb26 JMP 0x007113ab
    goto L007113ab;
  }
  L00711385: { // 0x711385: c7858001000020144100 MOV dword ptr [EBP + 0x180],0x411420
    m.w32((s.bp+0x00000180u), 0x00411420u);
  }
  L0071138f: { // 0x71138f: c785a80100003c000000 MOV dword ptr [EBP + 0x1a8],0x3c
    m.w32((s.bp+0x000001a8u), 0x0000003cu);
  }
  L00711399: { // 0x711399: 8b0d9487a200 MOV ECX,dword ptr [0x00a28794]
    s.cx = m.r32((0x00a28794u));
  }
  L0071139f: { // 0x71139f: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  L007113a5: { // 0x7113a5: 898df4010000 MOV dword ptr [EBP + 0x1f4],ECX
    m.w32((s.bp+0x000001f4u), s.cx);
  }
  L007113ab: { // 0x7113ab: 8b7c2418 MOV EDI,dword ptr [ESP + 0x18]
    s.di = m.r32((f.sp+0x00000018u));
  }
  L007113af: { // 0x7113af: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L007113b1: { // 0x7113b1: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L007113b3: { // 0x7113b3: c78588010000a0154100 MOV dword ptr [EBP + 0x188],0x4115a0
    m.w32((s.bp+0x00000188u), 0x004115a0u);
  }
  L007113bd: { // 0x7113bd: c785cc01000000200000 MOV dword ptr [EBP + 0x1cc],0x2000
    m.w32((s.bp+0x000001ccu), 0x00002000u);
  }
  L007113c7: { // 0x7113c7: 899dfc040000 MOV dword ptr [EBP + 0x4fc],EBX
    m.w32((s.bp+0x000004fcu), s.bx);
  }
  L007113cd: { // 0x7113cd: 899d44050000 MOV dword ptr [EBP + 0x544],EBX
    m.w32((s.bp+0x00000544u), s.bx);
  }
  L007113d3: { // 0x7113d3: 899d00050000 MOV dword ptr [EBP + 0x500],EBX
    m.w32((s.bp+0x00000500u), s.bx);
  }
  L007113d9: { // 0x7113d9: f2ae SCASB.REPNE ES:EDI
    string_instruction(m,s,flags,Kind::scan,8u,Repeat::not_equal);
  }
  L007113db: { // 0x7113db: f7d1 NOT ECX
    s.cx = (~(s.cx)&integer::mask(32));
  }
  L007113dd: { // 0x7113dd: 2bf9 SUB EDI,ECX
    s.di = integer::sub(s.di,s.cx,32,flags);
  }
  L007113df: { // 0x7113df: 8d5569 LEA EDX,[EBP + 0x69]
    s.dx = (s.bp+0x00000069u);
  }
  L007113e2: { // 0x7113e2: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L007113e4: { // 0x7113e4: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L007113e6: { // 0x7113e6: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L007113e8: { // 0x7113e8: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L007113ec: { // 0x7113ec: c1e902 SHR ECX,0x2
    s.cx = integer::shift(s.cx,0x00000002u,32,flags,integer::Shift::right);
  }
  L007113ef: { // 0x7113ef: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L007113f1: { // 0x7113f1: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L007113f3: { // 0x7113f3: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  L007113f7: { // 0x7113f7: 83e103 AND ECX,0x3
    s.cx = integer::logical((s.cx)&(0x00000003u),32,flags);
  }
  L007113fa: { // 0x7113fa: f3a4 MOVSB.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,8u,Repeat::count);
  }
  L007113fc: { // 0x7113fc: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00711400: { // 0x711400: 898540050000 MOV dword ptr [EBP + 0x540],EAX
    m.w32((s.bp+0x00000540u), s.ax);
  }
  L00711406: { // 0x711406: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00711407: { // 0x711407: 899d10050000 MOV dword ptr [EBP + 0x510],EBX
    m.w32((s.bp+0x00000510u), s.bx);
  }
  L0071140d: { // 0x71140d: 899d14050000 MOV dword ptr [EBP + 0x514],EBX
    m.w32((s.bp+0x00000514u), s.bx);
  }
  L00711413: { // 0x711413: 899d18050000 MOV dword ptr [EBP + 0x518],EBX
    m.w32((s.bp+0x00000518u), s.bx);
  }
  L00711419: { // 0x711419: 899d1c050000 MOV dword ptr [EBP + 0x51c],EBX
    m.w32((s.bp+0x0000051cu), s.bx);
  }
  L0071141f: { // 0x71141f: c78508050000ffffffff MOV dword ptr [EBP + 0x508],0xffffffff
    m.w32((s.bp+0x00000508u), 0xffffffffu);
  }
  L00711429: { // 0x711429: 889d20050000 MOV byte ptr [EBP + 0x520],BL
    m.w8((s.bp+0x00000520u), (s.bx & 0xffu));
  }
  L0071142f: { // 0x71142f: 898d38050000 MOV dword ptr [EBP + 0x538],ECX
    m.w32((s.bp+0x00000538u), s.cx);
  }
  L00711435: { // 0x711435: 89953c050000 MOV dword ptr [EBP + 0x53c],EDX
    m.w32((s.bp+0x0000053cu), s.dx);
  }
  L0071143b: { // 0x71143b: 885d68 MOV byte ptr [EBP + 0x68],BL
    m.w8((s.bp+0x00000068u), (s.bx & 0xffu));
  }
  L0071143e: { // 0x71143e: 889d0c050000 MOV byte ptr [EBP + 0x50c],BL
    m.w8((s.bp+0x0000050cu), (s.bx & 0xffu));
  }
  L00711444: { // 0x711444: 889d48050000 MOV byte ptr [EBP + 0x548],BL
    m.w8((s.bp+0x00000548u), (s.bx & 0xffu));
  }
  L0071144a: { // 0x71144a: 889d49050000 MOV byte ptr [EBP + 0x549],BL
    m.w8((s.bp+0x00000549u), (s.bx & 0xffu));
  }
  L00711450: { // 0x711450: 895d00 MOV dword ptr [EBP],EBX
    m.w32((s.bp), s.bx);
  }
  L00711453: { // 0x711453: 8bc5 MOV EAX,EBP
    s.ax = s.bp;
  }
  L00711455: { // 0x711455: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00711456: { // 0x711456: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00711457: { // 0x711457: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00711458: { // 0x711458: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L00711459: { // 0x711459: c21c00 RET 0x1c
    s.arithmetic_flags=flags; finish(m,s,f,28u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
