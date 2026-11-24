#include "recovered/recovery_b741.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::recovery_b741 {
Result run(Memory& original,const floating_b61::Inputs&i){
 Memory m=original;
 constexpr std::uint32_t stack_base=0x7e000000u,entry_sp=stack_base+0x6004u,outer=0x76543210u;
 std::array<std::uint8_t,0x8000> bytes{};leaf::Memory stack(bytes.data(),stack_base,std::uint32_t(bytes.size()));m.add(stack);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{entry_sp,entry_sp,outer};m.w32(entry_sp,outer);for(unsigned k=0;k<i.arg.size();++k)m.w32(entry_sp+4u+4u*k,i.arg[k]);
 fun_00677870(m,s,f,Operations{});
 if(f.sp!=entry_sp+4u+8u)throw std::runtime_error("B741 RET 8 stack cleanup mismatch");
 i.fp=s.fp;Result r{};r.eax=s.ax;for(unsigned k=0;k<r.args.size();++k)r.args[k]=m.r32(entry_sp+4u+4u*k);return r;
}
std::uint32_t call_root(Memory&m,const floating_b61::Inputs&i){const auto r=run(m,i);for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=r.args[k];return r.eax;}
}

#include "recovered/recovery_b108_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include "recovered/strings_b37_primitives.hpp"
#include <limits>
#include <algorithm>
#include <stdexcept>
#include "recovered/recovery_b108_machine.hpp"
#include "recovered/recovery_b145_lookup.hpp"
#include "recovered/leaf_b56_b.hpp"
#include "recovered/recovery_b707.hpp"
#include "recovered/recovery_b741.hpp"
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b741 {
using namespace ra2::recovered::recovery_b108;
namespace integer=direct_b33::integer;
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);
void f_00277870(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  { // 0x677870: 83ec30 SUB ESP,0x30
    f.sp = integer::sub(f.sp,0x00000030u,32,flags);
  }
  { // 0x677873: a000f78100 MOV AL,[0x0081f700]
    s.ax = with_al(s.ax, m.r8((0x0081f700u)));
  }
  { // 0x677878: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  { // 0x67787c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  { // 0x67787e: 0f8427010000 JZ 0x006779ab
    if(integer::condition("JZ",flags)) goto L006779ab;
  }
  { // 0x677884: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  { // 0x677886: 0f841f010000 JZ 0x006779ab
    if(integer::condition("JZ",flags)) goto L006779ab;
  }
  { // 0x67788c: 8b02 MOV EAX,dword ptr [EDX]
    s.ax = m.r32((s.dx));
  }
  { // 0x67788e: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x67788f: 8b5a04 MOV EBX,dword ptr [EDX + 0x4]
    s.bx = m.r32((s.dx+0x00000004u));
  }
  { // 0x677892: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x677893: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x677894: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x677895: 8b3d306d8300 MOV EDI,dword ptr [0x00836d30]
    s.di = m.r32((0x00836d30u));
  }
  { // 0x67789b: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  { // 0x6778a0: b9dc5f7d00 MOV ECX,0x7d5fdc
    s.cx = 0x007d5fdcu;
  }
  { // 0x6778a5: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  { // 0x6778a9: e83234feff CALL 0x0065ace0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0065ace0u,0x006778aeu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x6778ae: 8d4c2410 LEA ECX,[ESP + 0x10]
    s.cx = (f.sp+0x00000010u);
  }
  { // 0x6778b2: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x6778b3: 8d8808030000 LEA ECX,[EAX + 0x308]
    s.cx = (s.ax+0x00000308u);
  }
  { // 0x6778b9: e8926ce8ff CALL 0x004fe550
    s.arithmetic_flags=flags; invoke(m,s,f,0x004fe550u,0x006778beu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x6778be: 668b10 MOV DX,word ptr [EAX]
    s.dx = with_ax(s.dx, m.r16((s.ax)));
  }
  { // 0x6778c1: 8a0df4b28300 MOV CL,byte ptr [0x0083b2f4]
    s.cx = with_al(s.cx, m.r8((0x0083b2f4u)));
  }
  { // 0x6778c7: 6689542420 MOV word ptr [ESP + 0x20],DX
    m.w16((f.sp+0x00000020u), (s.dx & 0xffffu));
  }
  { // 0x6778cc: 6a01 PUSH 0x1
    f.push(m,0x00000001u);
  }
  { // 0x6778ce: 8a4002 MOV AL,byte ptr [EAX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000002u)));
  }
  { // 0x6778d1: 88442426 MOV byte ptr [ESP + 0x26],AL
    m.w8((f.sp+0x00000026u), (s.ax & 0xffu));
  }
  { // 0x6778d5: 8b742426 MOV ESI,dword ptr [ESP + 0x26]
    s.si = m.r32((f.sp+0x00000026u));
  }
  { // 0x6778d9: 8b542425 MOV EDX,dword ptr [ESP + 0x25]
    s.dx = m.r32((f.sp+0x00000025u));
  }
  { // 0x6778dd: 81e6ff000000 AND ESI,0xff
    s.si = integer::logical((s.si)&(0x000000ffu),32,flags);
  }
  { // 0x6778e3: d3ee SHR ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x6778e5: 8b0df0b28300 MOV ECX,dword ptr [0x0083b2f0]
    s.cx = m.r32((0x0083b2f0u));
  }
  { // 0x6778eb: 8b442424 MOV EAX,dword ptr [ESP + 0x24]
    s.ax = m.r32((f.sp+0x00000024u));
  }
  { // 0x6778ef: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  { // 0x6778f5: 25ff000000 AND EAX,0xff
    s.ax = integer::logical((s.ax)&(0x000000ffu),32,flags);
  }
  { // 0x6778fa: d3e6 SHL ESI,CL
    s.si = integer::shift(s.si,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x6778fc: 8a0dfcb28300 MOV CL,byte ptr [0x0083b2fc]
    s.cx = with_al(s.cx, m.r8((0x0083b2fcu)));
  }
  { // 0x677902: d3ea SHR EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x677904: 8b0df8b28300 MOV ECX,dword ptr [0x0083b2f8]
    s.cx = m.r32((0x0083b2f8u));
  }
  { // 0x67790a: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x67790c: 8a0decb28300 MOV CL,byte ptr [0x0083b2ec]
    s.cx = with_al(s.cx, m.r8((0x0083b2ecu)));
  }
  { // 0x677912: d3e8 SHR EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::right);
  }
  { // 0x677914: 8b0de8b28300 MOV ECX,dword ptr [0x0083b2e8]
    s.cx = m.r32((0x0083b2e8u));
  }
  { // 0x67791a: 0bf2 OR ESI,EDX
    s.si = integer::logical((s.si)|(s.dx),32,flags);
  }
  { // 0x67791c: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  { // 0x67791e: 0bf0 OR ESI,EAX
    s.si = integer::logical((s.si)|(s.ax),32,flags);
  }
  { // 0x677920: 8b442448 MOV EAX,dword ptr [ESP + 0x48]
    s.ax = m.r32((f.sp+0x00000048u));
  }
  { // 0x677924: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  { // 0x677926: 8b6808 MOV EBP,dword ptr [EAX + 0x8]
    s.bp = m.r32((s.ax+0x00000008u));
  }
  { // 0x677929: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  { // 0x67792c: 894c2434 MOV dword ptr [ESP + 0x34],ECX
    m.w32((f.sp+0x00000034u), s.cx);
  }
  { // 0x677930: 03e9 ADD EBP,ECX
    s.bp = integer::add(s.bp,s.cx,32,flags);
  }
  { // 0x677932: 8b480c MOV ECX,dword ptr [EAX + 0xc]
    s.cx = m.r32((s.ax+0x0000000cu));
  }
  { // 0x677935: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  { // 0x677937: 89542438 MOV dword ptr [ESP + 0x38],EDX
    m.w32((f.sp+0x00000038u), s.dx);
  }
  { // 0x67793b: 894c2440 MOV dword ptr [ESP + 0x40],ECX
    m.w32((f.sp+0x00000040u), s.cx);
  }
  { // 0x67793f: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x677941: 896c243c MOV dword ptr [ESP + 0x3c],EBP
    m.w32((f.sp+0x0000003cu), s.bp);
  }
  { // 0x677945: e8c699dbff CALL 0x00431310
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431310u,0x0067794au); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x67794a: 8d542430 LEA EDX,[ESP + 0x30]
    s.dx = (f.sp+0x00000030u);
  }
  { // 0x67794e: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x677950: 52 PUSH EDX
    f.push(m,s.dx);
  }
  { // 0x677951: e8ca99dbff CALL 0x00431320
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431320u,0x00677956u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x677956: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x677958: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x677959: e89299dbff CALL 0x004312f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004312f0u,0x0067795eu); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x67795e: 8d442418 LEA EAX,[ESP + 0x18]
    s.ax = (f.sp+0x00000018u);
  }
  { // 0x677962: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  { // 0x677966: 8b742448 MOV ESI,dword ptr [ESP + 0x48]
    s.si = m.r32((f.sp+0x00000048u));
  }
  { // 0x67796a: 8b6c2414 MOV EBP,dword ptr [ESP + 0x14]
    s.bp = m.r32((f.sp+0x00000014u));
  }
  { // 0x67796e: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x67796f: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x677970: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x677971: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x677972: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  { // 0x677974: e8f799dbff CALL 0x00431370
    s.arithmetic_flags=flags; invoke(m,s,f,0x00431370u,0x00677979u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x677979: 8b571c MOV EDX,dword ptr [EDI + 0x1c]
    s.dx = m.r32((s.di+0x0000001cu));
  }
  { // 0x67797c: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  { // 0x677980: 8b442428 MOV EAX,dword ptr [ESP + 0x28]
    s.ax = m.r32((f.sp+0x00000028u));
  }
  { // 0x677984: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x677986: 2bd1 SUB EDX,ECX
    s.dx = integer::sub(s.dx,s.cx,32,flags);
  }
  { // 0x677988: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x67798a: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x67798c: 03da ADD EBX,EDX
    s.bx = integer::add(s.bx,s.dx,32,flags);
  }
  { // 0x67798e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  { // 0x677990: 56 PUSH ESI
    f.push(m,s.si);
  }
  { // 0x677991: 53 PUSH EBX
    f.push(m,s.bx);
  }
  { // 0x677992: 8b0d881c8200 MOV ECX,dword ptr [0x00821c88]
    s.cx = m.r32((0x00821c88u));
  }
  { // 0x677998: 50 PUSH EAX
    f.push(m,s.ax);
  }
  { // 0x677999: 55 PUSH EBP
    f.push(m,s.bp);
  }
  { // 0x67799a: 51 PUSH ECX
    f.push(m,s.cx);
  }
  { // 0x67799b: 8b0d186d8300 MOV ECX,dword ptr [0x00836d18]
    s.cx = m.r32((0x00836d18u));
  }
  { // 0x6779a1: 57 PUSH EDI
    f.push(m,s.di);
  }
  { // 0x6779a2: e8a9a9dbff CALL 0x00432350
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432350u,0x006779a7u); flags=0x202u; s.arithmetic_flags=flags;
  }
  { // 0x6779a7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  { // 0x6779a8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  { // 0x6779a9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  { // 0x6779aa: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L006779ab: { // 0x6779ab: 83c430 ADD ESP,0x30
    f.sp = integer::add(f.sp,0x00000030u,32,flags);
  }
  { // 0x6779ae: c20800 RET 0x8
    finish(m,s,f,8u); return;
  }
}
} // namespace

namespace {
using U=std::uint32_t;
using B26=ra2::recovered::global_b26::Inputs;
void invoke(Memory&m,State&s,Frame&f,U target,U continuation){
 f.push(m,continuation);B26 q{};q.ax=s.ax;q.cx=s.cx;q.dx=s.dx;q.arithmetic_flags=s.arithmetic_flags;
 for(unsigned k=0;k<q.arg.size();++k)q.arg[k]=m.r32(f.sp+4u+4u*k);
 U cleanup=4;std::uint16_t write_mask=0;
 switch(target){
 case 0x0065ace0u:{ cleanup=0; const U count=m.r32(0x00a9ea10u), table=m.r32(0x00a9ea04u); s.ax=0; if(count>0 && count<16u){ for(U n=0;n<count;++n){ const U row=m.r32(table+4u*n); B26 c{};c.arg[0]=q.cx;c.arg[1]=m.r32(row+0x304u); if(ra2::recovered::recovery_b145::lookup::fun_0076d860(m,c)==0u && m.r32(row+0x310u)==q.dx){s.ax=row;break;} } } break;}
 case 0x004fe550u:{ cleanup=4; std::array<std::uint8_t,6> b{};ra2::recovered::leaf::Memory lm(b.data(),0x1000u,6u);for(U k=0;k<3u;++k)b[k]=static_cast<std::uint8_t>(m.r8(q.cx+k));ra2::recovered::leaf::Inputs cv{};cv.cx=0x1000u;cv.arg[0]=0x1003u;(void)ra2::recovered::leaf::fun_004fe550(lm,cv);for(U k=0;k<3u;++k)m.w8(q.arg[0]+k,b[3u+k]);s.ax=q.cx;break;}
 case 0x00431310u:{const U old=m.r8(q.cx+0x41u);m.w8(q.cx+0x41u,q.arg[0]);s.ax=old;break;}
 case 0x00431320u:{const U src=q.arg[0];if(!src){for(U k=0;k<4;++k)m.w32(q.cx+0x30u+4u*k,0u);s.ax=0;}else{for(U k=0;k<4;++k)m.w32(q.cx+0x30u+4u*k,m.r32(src+4u*k));s.ax=m.r32(src+12u);}break;}
 case 0x004312f0u:{const U old=m.r16(q.cx+0x24u);m.w16(q.cx+0x24u,q.arg[0]);s.ax=old;break;}
 case 0x00431370u:{ cleanup=16; const U font=m.r32(q.cx+4u),fb=m.r32(q.cx+8u),table=m.r32(font+0x18u),stride=m.r32(font+0x14u),glyphs=m.r32(font+0x1cu),txt=q.arg[0];U width=0,maxw=0;for(U n=0;n<16u;++n){const U ch=m.r16(txt+2u*n);if(!ch)break;const U glyph=m.r16(table+ch*2u);const U data=glyph?glyphs+(glyph-1u)*stride:0u;const U p=data?data:fb;if(p)width+=m.r8(p)+m.r32(q.cx+0x2cu);if(width>maxw)maxw=width;}m.w32(q.arg[1],maxw);m.w32(q.arg[2],m.r32(q.cx+0x1cu));q.arg[0]=maxw;write_mask=1u;s.ax=(q.arg[2]&0xffffff00u)|1u;break;}
 case 0x00432350u:{State child=s;Frame cf{f.sp,f.sp,continuation};ra2::recovered::recovery_b707::fun_00432350(m,child,cf,Operations{});s=child;f.sp=cf.sp;return;}
 default:throw std::domain_error("B741 unreviewed direct call target");
 }
 for(unsigned k=0;k<q.arg.size();++k)if(write_mask&(std::uint16_t(1u)<<k))m.w32(f.sp+4u+4u*k,q.arg[k]);
 if(m.r32(f.sp)!=continuation)throw std::runtime_error("B741 helper return address changed");
 f.sp+=4u+cleanup;
}
}
void fun_00677870(Memory&m,State&s,Frame&f,const Operations&op){f_00277870(m,s,f,op);}
} // namespace ra2::recovered::recovery_b741
