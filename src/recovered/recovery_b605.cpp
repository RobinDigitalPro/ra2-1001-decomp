#include "recovered/recovery_b605_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b605 {
namespace {
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
default:throw std::domain_error("recovery605 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00576620(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00576620: { // 0x576620: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00576621: { // 0x576621: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00576623: { // 0x576623: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00576626: { // 0x576626: 83ec14 SUB ESP,0x14
    f.sp = integer::sub(f.sp,0x00000014u,32,flags);
  }
  L00576629: { // 0x576629: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0057662a: { // 0x57662a: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0057662c: { // 0x57662c: 803e00 CMP byte ptr [ESI],0x0
    (void)integer::sub(m.r8((s.si)),0x00000000u,8,flags);
  }
  L0057662f: { // 0x57662f: 740d JZ 0x0057663e
    if(integer::condition("JZ",flags)) goto L0057663e;
  }
  L00576631: { // 0x576631: c60600 MOV byte ptr [ESI],0x0
    m.w8((s.si), 0x00000000u);
  }
  L00576634: { // 0x576634: dd4608 FLD double ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00576637: { // 0x576637: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00576638: { // 0x576638: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0057663a: { // 0x57663a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0057663b: { // 0x57663b: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0057663c: { // 0x57663c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057663e: { // 0x57663e: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727809u); flags=s.arithmetic_flags;
  }
  L00576641: { // 0x576641: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576643: { // 0x576643: dc2508577800 FSUB double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576649: { // 0x576649: dd5c2408 FSTP double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057664d: { // 0x57664d: ff5610 CALL dword ptr [ESI + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.si+0x00000010u)),5727824u); flags=s.arithmetic_flags;
  }
  L00576650: { // 0x576650: dcc0 FADD ST0,ST0
    numeric_b88::detail::reg<0xdcc0>(s.fp);
  }
  L00576652: { // 0x576652: dc2508577800 FSUB double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.subtract64(read64(m,address));
  }
  L00576658: { // 0x576658: dd542410 FST double ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L0057665c: { // 0x57665c: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L0057665e: { // 0x57665e: dec9 FMULP
    numeric_b88::detail::reg<0xdec9>(s.fp);
  }
  L00576660: { // 0x576660: dd442408 FLD double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load64(read64(m,address));
  }
  L00576664: { // 0x576664: dc4c2408 FMUL double ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.multiply64(read64(m,address));
  }
  L00576668: { // 0x576668: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L0057666a: { // 0x57666a: dc1508577800 FCOM double ptr [0x00785708]
    const auto address=(0x00785708u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L00576670: { // 0x576670: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00576672: { // 0x576672: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00576675: { // 0x576675: 74c5 JZ 0x0057663c
    if(integer::condition("JZ",flags)) goto L0057663c;
  }
  L00576677: { // 0x576677: dc1510667800 FCOM double ptr [0x00786610]
    const auto address=(0x00786610u);
    floating_b61::fp_extended::compare64(s.fp,read64(m,address));
  }
  L0057667d: { // 0x57667d: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0057667f: { // 0x57667f: f6c440 TEST AH,0x40
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000040u),8,flags);
  }
  L00576682: { // 0x576682: 75b8 JNZ 0x0057663c
    if(integer::condition("JNZ",flags)) goto L0057663c;
  }
  L00576684: { // 0x576684: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576686: { // 0x576686: d9ed FLDLN2
    numeric_b88::detail::reg<0xd9ed>(s.fp);
  }
  L00576688: { // 0x576688: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L0057668b: { // 0x57668b: d9c9 FXCH
    numeric_b88::detail::reg<0xd9c9>(s.fp);
  }
  L0057668d: { // 0x57668d: d9f1 FYL2X
    numeric_b88::detail::reg<0xd9f1>(s.fp);
  }
  L0057668f: { // 0x57668f: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L00576691: { // 0x576691: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00576693: { // 0x576693: d8e1 FSUB ST0,ST1
    numeric_b88::detail::reg<0xd8e1>(s.fp);
  }
  L00576695: { // 0x576695: d8f2 FDIV ST0,ST2
    numeric_b88::detail::reg<0xd8f2>(s.fp);
  }
  L00576697: { // 0x576697: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L0057669a: { // 0x57669a: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669c: { // 0x57669c: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L0057669e: { // 0x57669e: e8dd39f4ff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,5727907u); flags=s.arithmetic_flags;
  }
  L005766a3: { // 0x5766a3: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L005766a5: { // 0x5766a5: dc4c2418 FMUL double ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.multiply64(read64(m,address));
  }
  L005766a9: { // 0x5766a9: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005766ac: { // 0x5766ac: c60601 MOV byte ptr [ESI],0x1
    m.w8((s.si), 0x00000001u);
  }
  L005766af: { // 0x5766af: dd5e08 FSTP double ptr [ESI + 0x8]
    const auto address=(s.si+0x00000008u);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005766b2: { // 0x5766b2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005766b3: { // 0x5766b3: dc4c2404 FMUL double ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.multiply64(read64(m,address));
  }
  L005766b7: { // 0x5766b7: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L005766b9: { // 0x5766b9: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L005766ba: { // 0x5766ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
