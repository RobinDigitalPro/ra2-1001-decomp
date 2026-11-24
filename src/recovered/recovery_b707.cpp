#include "recovered/recovery_b707.hpp"
#include <array>
#include <stdexcept>

namespace ra2::recovered::recovery_b707 {
Result run(Memory&original,const floating_b61::Inputs&i){
 // Keep the caller's declared spans, then add the private frame only to this
 // invocation's view. This avoids retaining a pointer to the local stack or
 // accumulating duplicate numeric spans across the 512-case comparison.
 Memory m=original;
 constexpr std::uint32_t stack_base=0x7e000000u,entry_sp=stack_base+0x6004u,outer=0x76543210u;
 std::array<std::uint8_t,0x8000> bytes{};leaf::Memory stack(bytes.data(),stack_base,std::uint32_t(bytes.size()));m.add(stack);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry_sp,entry_sp,outer};m.w32(entry_sp,outer);for(unsigned k=0;k<i.arg.size();++k)m.w32(entry_sp+4u+4u*k,i.arg[k]);
 const Operations op{};fun_00432350(m,s,f,op);
 if(f.sp!=entry_sp+4u+40u)throw std::runtime_error("text707 root RET 0x28 stack cleanup mismatch");
 i.fp=s.fp;Result r{};r.eax=s.ax;for(unsigned k=0;k<r.args.size();++k)r.args[k]=m.r32(entry_sp+4u+4u*k);return r;
}
std::uint32_t call_root(Memory&m,const floating_b61::Inputs&i){
 const auto r=run(m,i);for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=r.args[k];return r.eax;
}
}

#include "recovered/recovery_b108_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_primitives.hpp"
#include <limits>
#include <algorithm>
#include <stdexcept>
#include "recovered/recovery_b702.hpp"
#include "recovered/recovery_b706.hpp"
#include "recovered/indirect_b30_memory.hpp"
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b707 {
using namespace ra2::recovered::recovery_b108;
namespace integer=direct_b33::integer;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00032350(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x432350: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  { // 0x432353: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x432354: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x432355: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x432356: 8b742440 MOV ESI,dword ptr [ESP + 0x40]
    s.si = m.r32((f.sp+0x00000040u));
  }
  { // 0x43235a: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x43235b: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x43235d: 3bf7 CMP ESI,EDI
    (void)integer::sub(s.si,s.di,32,flags);
  }
  { // 0x43235f: 0f8422060000 JZ 0x00432987
    if(integer::condition("JZ",flags)) goto L00432987;
  }
  { // 0x432365: 8b6c244c MOV EBP,dword ptr [ESP + 0x4c]
    s.bp = m.r32((f.sp+0x0000004cu));
  }
  { // 0x432369: 3bef CMP EBP,EDI
    (void)integer::sub(s.bp,s.di,32,flags);
  }
  { // 0x43236b: 0f8416060000 JZ 0x00432987
    if(integer::condition("JZ",flags)) goto L00432987;
  }
  { // 0x432371: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  { // 0x432375: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x432377: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432378: e8f3fbffff CALL 0x00431f70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431f70u,0x0043237du); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x43237d: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  { // 0x432381: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x432382: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  { // 0x432384: e807f4ffff CALL 0x00431790
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431790u,0x00432389u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x432389: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  { // 0x43238d: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  { // 0x43238f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x432391: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x432393: 668b7224 MOV SI,word ptr [EDX + 0x24]
    s.si = (s.si & 0xffff0000u) | ((m.r16((s.dx+0x00000024u))) & 0xffffu);
  }
  { // 0x432397: 8bd5 MOV EDX,EBP
    s.dx = s.bp;
  }
  { // 0x432399: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x43239b: 897c2420 MOV dword ptr [ESP + 0x20],EDI
    m.w32((f.sp+0x00000020u), s.di);
  }
  { // 0x43239f: 668b12 MOV DX,word ptr [EDX]
    s.dx = with_ax(s.dx, m.r16((s.dx)));
  }
  { // 0x4323a2: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  { // 0x4323a6: 6685d2 TEST DX,DX
    (void)integer::logical(((s.dx & 0xffffu))&((s.dx & 0xffffu)),16,flags);
  }
  { // 0x4323a9: 897c2424 MOV dword ptr [ESP + 0x24],EDI
    m.w32((f.sp+0x00000024u), s.di);
  }
  { // 0x4323ad: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  { // 0x4323b1: 89542428 MOV dword ptr [ESP + 0x28],EDX
    m.w32((f.sp+0x00000028u), s.dx);
  }
  { // 0x4323b5: 0f842c040000 JZ 0x004327e7
    if(integer::condition("JZ",flags)) goto L004327e7;
  }
  L004323bb: { // 0x4323bb: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  { // 0x4323bf: 81e1ffff0000 AND ECX,0xffff
    s.cx = integer::logical((s.cx)&(0x0000ffffu),32,flags);
  }
  { // 0x4323c5: 83c1f7 ADD ECX,-0x9
    s.cx = integer::add(s.cx,0xfffffff7u,32,flags);
  }
  { // 0x4323c8: 83f917 CMP ECX,0x17
    (void)integer::sub(s.cx,0x00000017u,32,flags);
  }
  { // 0x4323cb: 0f87b9010000 JA 0x0043258a
    if(integer::condition("JA",flags)) goto L0043258a;
  }
  { // 0x4323d1: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  { // 0x4323d3: 8a91a4294300 MOV DL,byte ptr [ECX + 0x4329a4]
    s.dx = with_al(s.dx, m.r8((s.cx+0x004329a4u)));
  }
  { // 0x4323d9: ff249594294300 JMP dword ptr [EDX*0x4 + 0x432994]
    throw std::domain_error("text707 out-of-contract computed switch");
  }
  { // 0x4323e0: 663d0d00 CMP AX,0xd
    (void)integer::sub((s.ax & 0xffffu),0x0000000du,16,flags);
  }
  { // 0x4323e4: 0f8477010000 JZ 0x00432561
    if(integer::condition("JZ",flags)) goto L00432561;
  }
  { // 0x4323ea: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  { // 0x4323ee: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4323f0: 3bcf CMP ECX,EDI
    (void)integer::sub(s.cx,s.di,32,flags);
  }
  { // 0x4323f2: 7e1d JLE 0x00432411
    if(integer::condition("JLE",flags)) goto L00432411;
  }
  { // 0x4323f4: 8a542460 MOV DL,byte ptr [ESP + 0x60]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000060u)));
  }
  { // 0x4323f8: f6c201 TEST DL,0x1
    (void)integer::logical(((s.dx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4323fb: 740b JZ 0x00432408
    if(integer::condition("JZ",flags)) goto L00432408;
  }
  { // 0x4323fd: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x4323ff: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x432401: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x432402: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x432404: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x432406: eb09 JMP 0x00432411
    goto L00432411;
  }
  L00432408: { // 0x432408: f6c202 TEST DL,0x2
    (void)integer::logical(((s.dx & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x43240b: 7404 JZ 0x00432411
    if(integer::condition("JZ",flags)) goto L00432411;
  }
  { // 0x43240d: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x43240f: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00432411: { // 0x432411: 8b4c2450 MOV ECX,dword ptr [ESP + 0x50]
    s.cx = m.r32((f.sp+0x00000050u));
  }
  { // 0x432415: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x432417: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x43241b: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  { // 0x43241f: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x432421: 0f830f010000 JNC 0x00432536
    if(integer::condition("JNC",flags)) goto L00432536;
  }
  { // 0x432427: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  { // 0x43242b: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x43242f: 8b542468 MOV EDX,dword ptr [ESP + 0x68]
    s.dx = m.r32((f.sp+0x00000068u));
  }
  { // 0x432433: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  { // 0x432435: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x432437: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x432438: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  { // 0x43243a: 8d5c1001 LEA EBX,[EAX + EDX*0x1 + 0x1]
    s.bx = (s.ax+(s.dx * 0x00000001u)+0x00000001u);
  }
  { // 0x43243e: eb04 JMP 0x00432444
    goto L00432444;
  }
  L00432440: { // 0x432440: 8b4c2464 MOV ECX,dword ptr [ESP + 0x64]
    s.cx = m.r32((f.sp+0x00000064u));
  }
  L00432444: { // 0x432444: 8b442418 MOV EAX,dword ptr [ESP + 0x18]
    s.ax = m.r32((f.sp+0x00000018u));
  }
  { // 0x432448: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  { // 0x432449: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x43244a: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  { // 0x43244b: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  { // 0x43244f: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x432451: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x432453: 0f84a8000000 JZ 0x00432501
    if(integer::condition("JZ",flags)) goto L00432501;
  }
  { // 0x432459: 394c2418 CMP dword ptr [ESP + 0x18],ECX
    (void)integer::sub(m.r32((f.sp+0x00000018u)),s.cx,32,flags);
  }
  { // 0x43245d: 0f8df0040000 JGE 0x00432953
    if(integer::condition("JGE",flags)) goto L00432953;
  }
  { // 0x432463: 3b7c2468 CMP EDI,dword ptr [ESP + 0x68]
    (void)integer::sub(s.di,m.r32((f.sp+0x00000068u)),32,flags);
  }
  { // 0x432467: 0f8d94000000 JGE 0x00432501
    if(integer::condition("JGE",flags)) goto L00432501;
  }
  { // 0x43246d: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  { // 0x432474: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x432476: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x432479: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  { // 0x43247f: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x432481: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  { // 0x432488: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x43248b: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  { // 0x432491: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432492: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x432494: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x432496: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  { // 0x43249d: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x4324a0: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  { // 0x4324a6: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4324a7: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x4324a9: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x4324ad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4324ae: e87d070000 CALL 0x00432c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432c30u,0x004324b3u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x4324b3: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  { // 0x4324b6: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  { // 0x4324bb: 66894c2434 MOV word ptr [ESP + 0x34],CX
    m.w16((f.sp+0x00000034u), (s.cx & 0xffffu));
  }
  { // 0x4324c0: 8d4c2434 LEA ECX,[ESP + 0x34]
    s.cx = (f.sp+0x00000034u);
  }
  { // 0x4324c4: 8a5002 MOV DL,byte ptr [EAX + 0x2]
    s.dx = with_al(s.dx, m.r8((s.ax+0x00000002u)));
  }
  { // 0x4324c7: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  { // 0x4324cc: 88542436 MOV byte ptr [ESP + 0x36],DL
    m.w8((f.sp+0x00000036u), (s.dx & 0xffu));
  }
  { // 0x4324d0: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4324d1: f77c246c IDIV dword ptr [ESP + 0x6c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x0000006cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x4324d5: 0fafc3 IMUL EAX,EBX
    s.ax = integer::imul(s.ax,s.bx,32,flags);
  }
  { // 0x4324d8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4324d9: e8321e2000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,0x004324deu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x4324de: 8b442432 MOV EAX,dword ptr [ESP + 0x32]
    s.ax = m.r32((f.sp+0x00000032u));
  }
  { // 0x4324e2: 8b542431 MOV EDX,dword ptr [ESP + 0x31]
    s.dx = m.r32((f.sp+0x00000031u));
  }
  { // 0x4324e6: 8b4c2430 MOV ECX,dword ptr [ESP + 0x30]
    s.cx = m.r32((f.sp+0x00000030u));
  }
  { // 0x4324ea: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4324ef: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4324f0: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x4324f6: 81e1ff000000 AND ECX,0xff
    s.cx = integer::logical((s.cx)&(0x000000ffu),32,flags);
  }
  { // 0x4324fc: e84f070000 CALL 0x00432c50
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432c50u,0x00432501u); flags=0x202u; s.arithmetic_flags=flags;
  }
  L00432501: { // 0x432501: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x432504: 0f8449040000 JZ 0x00432953
    if(integer::condition("JZ",flags)) goto L00432953;
  }
  { // 0x43250a: 8b542454 MOV EDX,dword ptr [ESP + 0x54]
    s.dx = m.r32((f.sp+0x00000054u));
  }
  { // 0x43250e: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  { // 0x432512: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432513: 8b442420 MOV EAX,dword ptr [ESP + 0x20]
    s.ax = m.r32((f.sp+0x00000020u));
  }
  { // 0x432517: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x432518: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432519: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x43251a: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  { // 0x43251e: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  { // 0x432521: e87af2ffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,0x00432526u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x432526: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x43252a: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  { // 0x43252e: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x432530: 0f820affffff JC 0x00432440
    if(integer::condition("JC",flags)) goto L00432440;
  }
  L00432536: { // 0x432536: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x43253a: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x43253e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x432540: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x432542: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  { // 0x432545: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x432547: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  { // 0x43254b: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  { // 0x43254f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x432551: 740a JZ 0x0043255d
    if(integer::condition("JZ",flags)) goto L0043255d;
  }
  { // 0x432553: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  { // 0x432557: 0f8d70020000 JGE 0x004327cd
    if(integer::condition("JGE",flags)) goto L004327cd;
  }
  L0043255d: { // 0x43255d: 01442454 ADD dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), integer::add(m.r32((f.sp+0x00000054u)),s.ax,32,flags));
  }
  L00432561: { // 0x432561: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  { // 0x432564: e944020000 JMP 0x004327ad
    goto L004327ad;
  }
  { // 0x432569: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x43256d: 8b4928 MOV ECX,dword ptr [ECX + 0x28]
    s.cx = m.r32((s.cx+0x00000028u));
  }
  { // 0x432570: 03f9 ADD EDI,ECX
    s.di = integer::add(s.di,s.cx,32,flags);
  }
  { // 0x432572: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  { // 0x432574: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x432575: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x432577: 2bfa SUB EDI,EDX
    s.di = integer::sub(s.di,s.dx,32,flags);
  }
  { // 0x432579: e92f020000 JMP 0x004327ad
    goto L004327ad;
  }
  { // 0x43257e: 8b54244c MOV EDX,dword ptr [ESP + 0x4c]
    s.dx = m.r32((f.sp+0x0000004cu));
  }
  { // 0x432582: 897c242c MOV dword ptr [ESP + 0x2c],EDI
    m.w32((f.sp+0x0000002cu), s.di);
  }
  { // 0x432586: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L0043258a: { // 0x43258a: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x43258e: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x432592: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432593: e8a8f7ffff CALL 0x00431d40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431d40u,0x00432598u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x432598: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x43259a: 7513 JNZ 0x004325af
    if(integer::condition("JNZ",flags)) goto L004325af;
  }
  { // 0x43259c: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x4325a0: 6a3f PUSH 0x3f
    f.push(m,0x0000003fu);
  }
  { // 0x4325a2: e899f7ffff CALL 0x00431d40
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431d40u,0x004325a7u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x4325a7: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  { // 0x4325a9: 0f84fe010000 JZ 0x004327ad
    if(integer::condition("JZ",flags)) goto L004327ad;
  }
  L004325af: { // 0x4325af: 8b542444 MOV EDX,dword ptr [ESP + 0x44]
    s.dx = m.r32((f.sp+0x00000044u));
  }
  { // 0x4325b3: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  { // 0x4325b5: 8a08 MOV CL,byte ptr [EAX]
    s.cx = with_al(s.cx, m.r8((s.ax)));
  }
  { // 0x4325b7: 43 INC EBX
    s.bx = integer::increment(s.bx,32,flags);
  }
  { // 0x4325b8: 8b422c MOV EAX,dword ptr [EDX + 0x2c]
    s.ax = m.r32((s.dx+0x0000002cu));
  }
  { // 0x4325bb: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  { // 0x4325bd: 8b4c2458 MOV ECX,dword ptr [ESP + 0x58]
    s.cx = m.r32((f.sp+0x00000058u));
  }
  { // 0x4325c1: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  { // 0x4325c3: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4325c5: 0f84e2010000 JZ 0x004327ad
    if(integer::condition("JZ",flags)) goto L004327ad;
  }
  { // 0x4325cb: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  { // 0x4325cd: 0f8eda010000 JLE 0x004327ad
    if(integer::condition("JLE",flags)) goto L004327ad;
  }
  { // 0x4325d3: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  { // 0x4325d7: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x4325d9: 740f JZ 0x004325ea
    if(integer::condition("JZ",flags)) goto L004325ea;
  }
  { // 0x4325db: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  { // 0x4325de: 7e1c JLE 0x004325fc
    if(integer::condition("JLE",flags)) goto L004325fc;
  }
  { // 0x4325e0: 8b7c242c MOV EDI,dword ptr [ESP + 0x2c]
    s.di = m.r32((f.sp+0x0000002cu));
  }
  { // 0x4325e4: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  { // 0x4325e8: eb12 JMP 0x004325fc
    goto L004325fc;
  }
  L004325ea: { // 0x4325ea: 83fb01 CMP EBX,0x1
    (void)integer::sub(s.bx,0x00000001u,32,flags);
  }
  { // 0x4325ed: 7e0d JLE 0x004325fc
    if(integer::condition("JLE",flags)) goto L004325fc;
  }
  { // 0x4325ef: 2bf8 SUB EDI,EAX
    s.di = integer::sub(s.di,s.ax,32,flags);
  }
  { // 0x4325f1: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  { // 0x4325f5: 83e802 SUB EAX,0x2
    s.ax = integer::sub(s.ax,0x00000002u,32,flags);
  }
  { // 0x4325f8: 8944244c MOV dword ptr [ESP + 0x4c],EAX
    m.w32((f.sp+0x0000004cu), s.ax);
  }
  L004325fc: { // 0x4325fc: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  { // 0x432600: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x432602: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x432604: 7e1d JLE 0x00432623
    if(integer::condition("JLE",flags)) goto L00432623;
  }
  { // 0x432606: 8a5c2460 MOV BL,byte ptr [ESP + 0x60]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000060u)));
  }
  { // 0x43260a: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x43260d: 740b JZ 0x0043261a
    if(integer::condition("JZ",flags)) goto L0043261a;
  }
  { // 0x43260f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x432611: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x432613: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x432614: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x432616: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x432618: eb09 JMP 0x00432623
    goto L00432623;
  }
  L0043261a: { // 0x43261a: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x43261d: 7404 JZ 0x00432623
    if(integer::condition("JZ",flags)) goto L00432623;
  }
  { // 0x43261f: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x432621: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L00432623: { // 0x432623: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  { // 0x432627: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x432629: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x43262d: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  { // 0x432631: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x432633: 0f833c010000 JNC 0x00432775
    if(integer::condition("JNC",flags)) goto L00432775;
  }
  { // 0x432639: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  { // 0x43263d: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x432641: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  { // 0x432645: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x432647: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x432649: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x43264b: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x43264c: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x43264e: 8d7c3801 LEA EDI,[EAX + EDI*0x1 + 0x1]
    s.di = (s.ax+(s.di * 0x00000001u)+0x00000001u);
  }
  { // 0x432652: eb08 JMP 0x0043265c
    goto L0043265c;
  }
  L00432654: { // 0x432654: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  { // 0x432658: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L0043265c: { // 0x43265c: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x43265d: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x43265e: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x43265f: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  { // 0x432663: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x432665: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x432667: 0f84cf000000 JZ 0x0043273c
    if(integer::condition("JZ",flags)) goto L0043273c;
  }
  { // 0x43266d: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x43266f: 0f8dde020000 JGE 0x00432953
    if(integer::condition("JGE",flags)) goto L00432953;
  }
  { // 0x432675: 3b5c2468 CMP EBX,dword ptr [ESP + 0x68]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000068u)),32,flags);
  }
  { // 0x432679: 0f8dbd000000 JGE 0x0043273c
    if(integer::condition("JGE",flags)) goto L0043273c;
  }
  { // 0x43267f: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  { // 0x432686: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x432688: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x43268b: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  { // 0x432691: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  { // 0x432696: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x432698: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  { // 0x43269f: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x4326a2: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  { // 0x4326a8: 88542414 MOV byte ptr [ESP + 0x14],DL
    m.w8((f.sp+0x00000014u), (s.dx & 0xffu));
  }
  { // 0x4326ac: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x4326ae: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  { // 0x4326b5: 88442415 MOV byte ptr [ESP + 0x15],AL
    m.w8((f.sp+0x00000015u), (s.ax & 0xffu));
  }
  { // 0x4326b9: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x4326bb: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x4326be: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  { // 0x4326c4: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x4326c6: 668b4c2414 MOV CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000014u)));
  }
  { // 0x4326cb: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  { // 0x4326d0: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  { // 0x4326d4: 8844243e MOV byte ptr [ESP + 0x3e],AL
    m.w8((f.sp+0x0000003eu), (s.ax & 0xffu));
  }
  { // 0x4326d8: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  { // 0x4326dd: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4326de: f77c246c IDIV dword ptr [ESP + 0x6c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x0000006cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x4326e2: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  { // 0x4326e5: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4326e6: e8251c2000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,0x004326ebu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x4326eb: 8b442439 MOV EAX,dword ptr [ESP + 0x39]
    s.ax = m.r32((f.sp+0x00000039u));
  }
  { // 0x4326ef: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x4326f5: 8b54243a MOV EDX,dword ptr [ESP + 0x3a]
    s.dx = m.r32((f.sp+0x0000003au));
  }
  { // 0x4326f9: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4326fe: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x432700: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x432706: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x43270c: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x43270e: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x432714: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x432716: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x43271c: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x43271e: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  { // 0x432724: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x432726: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  { // 0x43272a: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x432730: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x432732: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  { // 0x432738: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x43273a: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L0043273c: { // 0x43273c: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x43273f: 0f840e020000 JZ 0x00432953
    if(integer::condition("JZ",flags)) goto L00432953;
  }
  { // 0x432745: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x432749: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  { // 0x43274d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x43274e: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  { // 0x432752: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432753: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x432754: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x432755: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  { // 0x432759: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  { // 0x43275c: e83ff0ffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,0x00432761u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x432761: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x432765: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  { // 0x432769: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x43276b: 0f82e3feffff JC 0x00432654
    if(integer::condition("JC",flags)) goto L00432654;
  }
  { // 0x432771: 8b4c2424 MOV ECX,dword ptr [ESP + 0x24]
    s.cx = m.r32((f.sp+0x00000024u));
  }
  L00432775: { // 0x432775: 394c244c CMP dword ptr [ESP + 0x4c],ECX
    (void)integer::sub(m.r32((f.sp+0x0000004cu)),s.cx,32,flags);
  }
  { // 0x432779: 750b JNZ 0x00432786
    if(integer::condition("JNZ",flags)) goto L00432786;
  }
  { // 0x43277b: c744242400000000 MOV dword ptr [ESP + 0x24],0x0
    m.w32((f.sp+0x00000024u), 0x00000000u);
  }
  { // 0x432783: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  L00432786: { // 0x432786: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x43278a: 8b542420 MOV EDX,dword ptr [ESP + 0x20]
    s.dx = m.r32((f.sp+0x00000020u));
  }
  { // 0x43278e: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  { // 0x432790: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  { // 0x432792: 8b411c MOV EAX,dword ptr [ECX + 0x1c]
    s.ax = m.r32((s.cx+0x0000001cu));
  }
  { // 0x432795: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  { // 0x432797: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  { // 0x43279b: 8b54245c MOV EDX,dword ptr [ESP + 0x5c]
    s.dx = m.r32((f.sp+0x0000005cu));
  }
  { // 0x43279f: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x4327a1: 7406 JZ 0x004327a9
    if(integer::condition("JZ",flags)) goto L004327a9;
  }
  { // 0x4327a3: 39542420 CMP dword ptr [ESP + 0x20],EDX
    (void)integer::sub(m.r32((f.sp+0x00000020u)),s.dx,32,flags);
  }
  { // 0x4327a7: 7d24 JGE 0x004327cd
    if(integer::condition("JGE",flags)) goto L004327cd;
  }
  L004327a9: { // 0x4327a9: 01442454 ADD dword ptr [ESP + 0x54],EAX
    m.w32((f.sp+0x00000054u), integer::add(m.r32((f.sp+0x00000054u)),s.ax,32,flags));
  }
  L004327ad: { // 0x4327ad: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  { // 0x4327b1: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x4327b5: 83c102 ADD ECX,0x2
    s.cx = integer::add(s.cx,0x00000002u,32,flags);
  }
  { // 0x4327b8: 894c244c MOV dword ptr [ESP + 0x4c],ECX
    m.w32((f.sp+0x0000004cu), s.cx);
  }
  { // 0x4327bc: 668b09 MOV CX,word ptr [ECX]
    s.cx = with_ax(s.cx, m.r16((s.cx)));
  }
  { // 0x4327bf: 6685c9 TEST CX,CX
    (void)integer::logical(((s.cx & 0xffffu))&((s.cx & 0xffffu)),16,flags);
  }
  { // 0x4327c2: 894c2428 MOV dword ptr [ESP + 0x28],ECX
    m.w32((f.sp+0x00000028u), s.cx);
  }
  { // 0x4327c6: 741b JZ 0x004327e3
    if(integer::condition("JZ",flags)) goto L004327e3;
  }
  { // 0x4327c8: e9eefbffff JMP 0x004323bb
    goto L004323bb;
  }
  L004327cd: { // 0x4327cd: 8b542448 MOV EDX,dword ptr [ESP + 0x48]
    s.dx = m.r32((f.sp+0x00000048u));
  }
  { // 0x4327d1: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x4327d2: e839f8ffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,0x004327d7u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x4327d7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x4327d8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x4327d9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x4327da: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x4327dc: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x4327dd: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x4327e0: c22800 RET 0x28
    finish(m,s,f,40u); return;
  }
  L004327e3: { // 0x4327e3: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L004327e7: { // 0x4327e7: 8b542458 MOV EDX,dword ptr [ESP + 0x58]
    s.dx = m.r32((f.sp+0x00000058u));
  }
  { // 0x4327eb: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  { // 0x4327ed: 3bd7 CMP EDX,EDI
    (void)integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x4327ef: 7e1d JLE 0x0043280e
    if(integer::condition("JLE",flags)) goto L0043280e;
  }
  { // 0x4327f1: 8a5c2460 MOV BL,byte ptr [ESP + 0x60]
    s.bx = with_al(s.bx, m.r8((f.sp+0x00000060u)));
  }
  { // 0x4327f5: f6c301 TEST BL,0x1
    (void)integer::logical(((s.bx & 0xffu))&(0x00000001u),8,flags);
  }
  { // 0x4327f8: 740b JZ 0x00432805
    if(integer::condition("JZ",flags)) goto L00432805;
  }
  { // 0x4327fa: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  { // 0x4327fc: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  { // 0x4327fe: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4327ff: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x432801: d1f8 SAR EAX,0x1
    s.ax = integer::shift(s.ax,0x00000001u,32,flags,integer::Shift::arithmetic_right);
  }
  { // 0x432803: eb09 JMP 0x0043280e
    goto L0043280e;
  }
  L00432805: { // 0x432805: f6c302 TEST BL,0x2
    (void)integer::logical(((s.bx & 0xffu))&(0x00000002u),8,flags);
  }
  { // 0x432808: 7404 JZ 0x0043280e
    if(integer::condition("JZ",flags)) goto L0043280e;
  }
  { // 0x43280a: 2bd7 SUB EDX,EDI
    s.dx = integer::sub(s.dx,s.di,32,flags);
  }
  { // 0x43280c: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0043280e: { // 0x43280e: 8b542450 MOV EDX,dword ptr [ESP + 0x50]
    s.dx = m.r32((f.sp+0x00000050u));
  }
  { // 0x432812: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  { // 0x432814: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x432818: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  { // 0x43281c: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x43281e: 0f8349010000 JNC 0x0043296d
    if(integer::condition("JNC",flags)) goto L0043296d;
  }
  { // 0x432824: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  { // 0x432828: 8b7c2468 MOV EDI,dword ptr [ESP + 0x68]
    s.di = m.r32((f.sp+0x00000068u));
  }
  { // 0x43282c: 8bda MOV EBX,EDX
    s.bx = s.dx;
  }
  { // 0x43282e: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  { // 0x432830: 2bd9 SUB EBX,ECX
    s.bx = integer::sub(s.bx,s.cx,32,flags);
  }
  { // 0x432832: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x432833: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  { // 0x432835: 8d7c3801 LEA EDI,[EAX + EDI*0x1 + 0x1]
    s.di = (s.ax+(s.di * 0x00000001u)+0x00000001u);
  }
  L00432839: { // 0x432839: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  { // 0x43283a: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  { // 0x43283b: 4b DEC EBX
    s.bx = integer::decrement(s.bx,32,flags);
  }
  { // 0x43283c: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  { // 0x432840: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  { // 0x432842: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x432844: 0f84cf000000 JZ 0x00432919
    if(integer::condition("JZ",flags)) goto L00432919;
  }
  { // 0x43284a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  { // 0x43284c: 0f8d01010000 JGE 0x00432953
    if(integer::condition("JGE",flags)) goto L00432953;
  }
  { // 0x432852: 3b5c2468 CMP EBX,dword ptr [ESP + 0x68]
    (void)integer::sub(s.bx,m.r32((f.sp+0x00000068u)),32,flags);
  }
  { // 0x432856: 0f8dbd000000 JGE 0x00432919
    if(integer::condition("JGE",flags)) goto L00432919;
  }
  { // 0x43285c: 668b0de8b28300 MOV CX,word ptr [0x0083b2e8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2e8u)));
  }
  { // 0x432863: 8bd6 MOV EDX,ESI
    s.dx = s.si;
  }
  { // 0x432865: 66d3ea SHR DX,CL
    s.dx = with_ax(s.dx, integer::shift((s.dx & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x432868: 8b0decb28300 MOV ECX,dword ptr [0x0083b2ec]
    s.cx = m.r32((0x0083b2ecu));
  }
  { // 0x43286e: 6869e3a900 PUSH 0xa9e369
    f.push(m,0x00a9e369u);
  }
  { // 0x432873: d2e2 SHL DL,CL
    s.dx = with_al(s.dx, integer::shift((s.dx & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x432875: 668b0df8b28300 MOV CX,word ptr [0x0083b2f8]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f8u)));
  }
  { // 0x43287c: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x43287f: 8b0dfcb28300 MOV ECX,dword ptr [0x0083b2fc]
    s.cx = m.r32((0x0083b2fcu));
  }
  { // 0x432885: 8854245c MOV byte ptr [ESP + 0x5c],DL
    m.w8((f.sp+0x0000005cu), (s.dx & 0xffu));
  }
  { // 0x432889: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x43288b: 668b0df0b28300 MOV CX,word ptr [0x0083b2f0]
    s.cx = with_ax(s.cx, m.r16((0x0083b2f0u)));
  }
  { // 0x432892: 8844245d MOV byte ptr [ESP + 0x5d],AL
    m.w8((f.sp+0x0000005du), (s.ax & 0xffu));
  }
  { // 0x432896: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  { // 0x432898: 66d3e8 SHR AX,CL
    s.ax = with_ax(s.ax, integer::shift((s.ax & 0xffffu),(s.cx & 0xffu),16,flags,integer::Shift::right));
  }
  { // 0x43289b: 8b0df4b28300 MOV ECX,dword ptr [0x0083b2f4]
    s.cx = m.r32((0x0083b2f4u));
  }
  { // 0x4328a1: d2e0 SHL AL,CL
    s.ax = with_al(s.ax, integer::shift((s.ax & 0xffu),(s.cx & 0xffu),8,flags,integer::Shift::left));
  }
  { // 0x4328a3: 668b4c245c MOV CX,word ptr [ESP + 0x5c]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x0000005cu)));
  }
  { // 0x4328a8: 66894c243c MOV word ptr [ESP + 0x3c],CX
    m.w16((f.sp+0x0000003cu), (s.cx & 0xffffu));
  }
  { // 0x4328ad: 8d4c243c LEA ECX,[ESP + 0x3c]
    s.cx = (f.sp+0x0000003cu);
  }
  { // 0x4328b1: 8844243e MOV byte ptr [ESP + 0x3e],AL
    m.w8((f.sp+0x0000003eu), (s.ax & 0xffu));
  }
  { // 0x4328b5: b8ff000000 MOV EAX,0xff
    s.ax = 0x000000ffu;
  }
  { // 0x4328ba: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  { // 0x4328bb: f77c246c IDIV dword ptr [ESP + 0x6c]
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(m.r32((f.sp+0x0000006cu)),32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  { // 0x4328bf: 0fafc7 IMUL EAX,EDI
    s.ax = integer::imul(s.ax,s.di,32,flags);
  }
  { // 0x4328c2: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x4328c3: e8481a2000 CALL 0x00634310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00634310u,0x004328c8u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x4328c8: 8b442439 MOV EAX,dword ptr [ESP + 0x39]
    s.ax = m.r32((f.sp+0x00000039u));
  }
  { // 0x4328cc: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x4328d2: 8b54243a MOV EDX,dword ptr [ESP + 0x3a]
    s.dx = m.r32((f.sp+0x0000003au));
  }
  { // 0x4328d6: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x4328db: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x4328dd: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x4328e3: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x4328e9: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x4328eb: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x4328f1: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x4328f3: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x4328f9: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x4328fb: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  { // 0x432901: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  { // 0x432903: 8b542438 MOV EDX,dword ptr [ESP + 0x38]
    s.dx = m.r32((f.sp+0x00000038u));
  }
  { // 0x432907: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x43290d: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x43290f: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  { // 0x432915: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x432917: 0bc2 OR EAX,EDX
    s.ax = integer::logical((s.ax)|(s.dx),32,flags);
  }
  L00432919: { // 0x432919: 83f8ff CMP EAX,-0x1
    (void)integer::sub(s.ax,0xffffffffu,32,flags);
  }
  { // 0x43291c: 7435 JZ 0x00432953
    if(integer::condition("JZ",flags)) goto L00432953;
  }
  { // 0x43291e: 8b54241c MOV EDX,dword ptr [ESP + 0x1c]
    s.dx = m.r32((f.sp+0x0000001cu));
  }
  { // 0x432922: 668b4d00 MOV CX,word ptr [EBP]
    s.cx = with_ax(s.cx, m.r16((s.bp)));
  }
  { // 0x432926: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x432927: 8b442458 MOV EAX,dword ptr [ESP + 0x58]
    s.ax = m.r32((f.sp+0x00000058u));
  }
  { // 0x43292b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x43292c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x43292d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x43292e: 8b4c2454 MOV ECX,dword ptr [ESP + 0x54]
    s.cx = m.r32((f.sp+0x00000054u));
  }
  { // 0x432932: 83c502 ADD EBP,0x2
    s.bp = integer::add(s.bp,0x00000002u,32,flags);
  }
  { // 0x432935: e866eeffff CALL 0x004317a0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004317a0u,0x0043293au); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x43293a: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  { // 0x43293e: 8b44244c MOV EAX,dword ptr [ESP + 0x4c]
    s.ax = m.r32((f.sp+0x0000004cu));
  }
  { // 0x432942: 3be8 CMP EBP,EAX
    (void)integer::sub(s.bp,s.ax,32,flags);
  }
  { // 0x432944: 7327 JNC 0x0043296d
    if(integer::condition("JNC",flags)) goto L0043296d;
  }
  { // 0x432946: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x43294a: 8b542464 MOV EDX,dword ptr [ESP + 0x64]
    s.dx = m.r32((f.sp+0x00000064u));
  }
  { // 0x43294e: e9e6feffff JMP 0x00432839
    goto L00432839;
  }
  L00432953: { // 0x432953: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  { // 0x432957: 8b4c2444 MOV ECX,dword ptr [ESP + 0x44]
    s.cx = m.r32((f.sp+0x00000044u));
  }
  { // 0x43295b: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x43295c: e8aff6ffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,0x00432961u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x432961: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x432962: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x432963: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x432964: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x432966: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x432967: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x43296a: c22800 RET 0x28
    finish(m,s,f,40u); return;
  }
  L0043296d: { // 0x43296d: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  { // 0x432971: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x432972: 8b4c2448 MOV ECX,dword ptr [ESP + 0x48]
    s.cx = m.r32((f.sp+0x00000048u));
  }
  { // 0x432976: e895f6ffff CALL 0x00432010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432010u,0x0043297bu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x43297b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x43297c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x43297d: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x43297e: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  { // 0x432980: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x432981: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x432984: c22800 RET 0x28
    finish(m,s,f,40u); return;
  }
  L00432987: { // 0x432987: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x432988: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x432989: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x43298a: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  { // 0x43298c: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  { // 0x43298d: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x432990: c22800 RET 0x28
    finish(m,s,f,40u); return;
  }
}
} // namespace

namespace {
using U=std::uint32_t;
using In=ra2::recovered::floating_b61::Inputs;
using B27State=ra2::recovered::global_b27::State;
void callback(Memory&m,B27State&s,const ra2::recovered::indirect_b30::Call&call,void*){
 if(call.target!=0x004112f0u)throw std::domain_error("text707 unknown Surface+60 target");
 const U value=m.r32(s.cx+0x0cu)-1u;m.w32(s.cx+0x0cu,value);s.ax=(value&0xffffff00u)|1u;
}
void invoke(Memory&m,State&s,Frame&f,U target,U continuation){
 f.push(m,continuation);In q{};q.ax=s.ax;q.cx=s.cx;q.dx=s.dx;q.arithmetic_flags=s.arithmetic_flags;
 for(unsigned k=0;k<q.arg.size();++k)q.arg[k]=m.r32(f.sp+4u+4u*k);
 U cleanup=0;
 switch(target){
 case 0x00431f70u:s.ax=ra2::recovered::recovery_b702::fun_00431f70(m,q);cleanup=4;break;
 case 0x00431790u:m.w32(q.cx+0x20u,q.arg[0]);s.ax=q.arg[0];cleanup=4;break;
 case 0x00431d40u:{const U p=m.r32(q.cx+4u);if(!p)s.ax=0;else{const U entry=m.r16(m.r32(p+0x18u)+(q.arg[0]&0xffffu)*2u);s.ax=entry?m.r32(p+0x14u)*(entry-1u)+m.r32(p+0x1cu):0;}cleanup=4;break;}
 case 0x004317a0u:if(q.arg[3]!=m.r16(q.cx+0x24u))throw std::domain_error("text707 expects explicit foreground color");q.arg[3]=0xffffffffu;s.ax=ra2::recovered::recovery_b706::fun_004317a0(m,q);cleanup=16;break;
 case 0x00432010u:{
   B27State bs{};bs.ax=s.ax;bs.cx=s.cx;bs.dx=s.dx;bs.bx=s.bx;bs.bp=s.bp;bs.si=s.si;bs.di=s.di;bs.arithmetic_flags=s.arithmetic_flags;
   ra2::recovered::indirect_b30::Frame cf{};cf.entry_sp=f.sp;cf.sp=f.sp;cf.outer_return=continuation;cf.call_return=0x0043201cu;
   const ra2::recovered::indirect_b30::Operations ops{callback,nullptr};
   auto entries=ra2::recovered::indirect_b30::entries_a();auto it=std::find_if(entries.begin(),entries.end(),[](auto e){return e.rva==0x32010u;});
   if(it==entries.end())throw std::domain_error("text707 accepted 32010 entry missing");
   it->function(m,bs,cf,ops);f.sp=cf.sp;s.ax=bs.ax;s.cx=bs.cx;s.dx=bs.dx;s.bx=bs.bx;s.bp=bs.bp;s.si=bs.si;s.di=bs.di;s.arithmetic_flags=bs.arithmetic_flags;return;
 }
 case 0x00432c30u:case 0x00634310u:case 0x00432c50u:throw std::domain_error("text707 out-of-contract color-conversion path");
 default:throw std::domain_error("text707 unreviewed direct call target");
 }
 for(unsigned k=0;k<q.arg.size();++k)m.w32(f.sp+4u+4u*k,q.arg[k]);
 if(m.r32(f.sp)!=continuation)throw std::runtime_error("text707 direct helper return address changed");
 f.sp+=4u+cleanup;
}
}
void fun_00432350(Memory& m, State& s, Frame& f, const Operations& op) { f_00032350(m,s,f,op); }
} // namespace ra2::recovered::recovery_b707
