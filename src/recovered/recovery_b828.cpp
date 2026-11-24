#include "recovered/recovery_b828_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b828 {
namespace {
void f_0000ffc0(Memory&,State&,Frame&,const Operations&);
void f_0022fde0(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0000ffc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ffc0: { // 0x40ffc0: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0040ffc4: { // 0x40ffc4: 8b400c MOV EAX,dword ptr [EAX + 0xc]
    s.ax = m.r32((s.ax+0x0000000cu));
  }
  L0040ffc7: { // 0x40ffc7: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}

void f_0022fde0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fde0: { // 0x62fde0: 803900 CMP byte ptr [ECX],0x0
    (void)integer::sub(m.r8((s.cx)),0x00000000u,8,flags);
  }
  L0062fde3: { // 0x62fde3: 7403 JZ 0x0062fde8
    if(integer::condition("JZ",flags)) goto L0062fde8;
  }
  L0062fde5: { // 0x62fde5: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fde7: { // 0x62fde7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
  L0062fde8: { // 0x62fde8: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0062fdeb: { // 0x62fdeb: 8b5108 MOV EDX,dword ptr [ECX + 0x8]
    s.dx = m.r32((s.cx+0x00000008u));
  }
  L0062fdee: { // 0x62fdee: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fdef: { // 0x62fdef: 8b54910c MOV EDX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.dx = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fdf3: { // 0x62fdf3: 8b74810c MOV ESI,dword ptr [ECX + EAX*0x4 + 0xc]
    s.si = m.r32((s.cx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062fdf7: { // 0x62fdf7: 8d44810c LEA EAX,[ECX + EAX*0x4 + 0xc]
    s.ax = (s.cx+(s.ax * 0x00000004u)+0x0000000cu);
  }
  L0062fdfb: { // 0x62fdfb: 33f2 XOR ESI,EDX
    s.si = integer::logical((s.si)^(s.dx),32,flags);
  }
  L0062fdfd: { // 0x62fdfd: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fdff: { // 0x62fdff: 8b5104 MOV EDX,dword ptr [ECX + 0x4]
    s.dx = m.r32((s.cx+0x00000004u));
  }
  L0062fe02: { // 0x62fe02: 8b7108 MOV ESI,dword ptr [ECX + 0x8]
    s.si = m.r32((s.cx+0x00000008u));
  }
  L0062fe05: { // 0x62fe05: 8b44910c MOV EAX,dword ptr [ECX + EDX*0x4 + 0xc]
    s.ax = m.r32((s.cx+(s.dx * 0x00000004u)+0x0000000cu));
  }
  L0062fe09: { // 0x62fe09: 42 INC EDX
    s.dx = integer::increment(s.dx,32,flags);
  }
  L0062fe0a: { // 0x62fe0a: 46 INC ESI
    s.si = integer::increment(s.si,32,flags);
  }
  L0062fe0b: { // 0x62fe0b: 81fafa000000 CMP EDX,0xfa
    (void)integer::sub(s.dx,0x000000fau,32,flags);
  }
  L0062fe11: { // 0x62fe11: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L0062fe14: { // 0x62fe14: 897108 MOV dword ptr [ECX + 0x8],ESI
    m.w32((s.cx+0x00000008u), s.si);
  }
  L0062fe17: { // 0x62fe17: 7c07 JL 0x0062fe20
    if(integer::condition("JL",flags)) goto L0062fe20;
  }
  L0062fe19: { // 0x62fe19: c7410400000000 MOV dword ptr [ECX + 0x4],0x0
    m.w32((s.cx+0x00000004u), 0x00000000u);
  }
  L0062fe20: { // 0x62fe20: 81fefa000000 CMP ESI,0xfa
    (void)integer::sub(s.si,0x000000fau,32,flags);
  }
  L0062fe26: { // 0x62fe26: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fe27: { // 0x62fe27: 7c07 JL 0x0062fe30
    if(integer::condition("JL",flags)) goto L0062fe30;
  }
  L0062fe29: { // 0x62fe29: c7410800000000 MOV dword ptr [ECX + 0x8],0x0
    m.w32((s.cx+0x00000008u), 0x00000000u);
  }
  L0062fe30: { // 0x62fe30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
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
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4259776u:f_0000ffc0(m,s,child,{});break;
case 6487520u:f_0022fde0(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
default:throw std::domain_error("recovery828 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00600790(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00600790: { // 0x600790: a06c89a200 MOV AL,[0x00a2896c]
    s.ax = with_al(s.ax, m.r8((0x00a2896cu)));
  }
  L00600795: { // 0x600795: 81ecdc000000 SUB ESP,0xdc
    f.sp = integer::sub(f.sp,0x000000dcu,32,flags);
  }
  L0060079b: { // 0x60079b: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L0060079d: { // 0x60079d: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060079e: { // 0x60079e: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060079f: { // 0x60079f: 56 PUSH ESI
    f.push(m,s.si);
  }
  L006007a0: { // 0x6007a0: 57 PUSH EDI
    f.push(m,s.di);
  }
  L006007a1: { // 0x6007a1: 8be9 MOV EBP,ECX
    s.bp = s.cx;
  }
  L006007a3: { // 0x6007a3: 0f8599040000 JNZ 0x00600c42
    if(integer::condition("JNZ",flags)) goto L00600c42;
  }
  L006007a9: { // 0x6007a9: 8d8588000000 LEA EAX,[EBP + 0x88]
    s.ax = (s.bp+0x00000088u);
  }
  L006007af: { // 0x6007af: 8b8d88000000 MOV ECX,dword ptr [EBP + 0x88]
    s.cx = m.r32((s.bp+0x00000088u));
  }
  L006007b5: { // 0x6007b5: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006007b9: { // 0x6007b9: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L006007bf: { // 0x6007bf: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L006007c2: { // 0x6007c2: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L006007c8: { // 0x6007c8: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006007cc: { // 0x6007cc: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L006007cf: { // 0x6007cf: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006007d3: { // 0x6007d3: e808f60200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6293464u); flags=s.arithmetic_flags;
  }
  L006007d8: { // 0x6007d8: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006007d9: { // 0x6007d9: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L006007db: { // 0x6007db: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006007dd: { // 0x6007dd: a807 TEST AL,0x7
    (void)integer::logical(((s.ax & 0xffu))&(0x00000007u),8,flags);
  }
  L006007df: { // 0x6007df: 0f85c0000000 JNZ 0x006008a5
    if(integer::condition("JNZ",flags)) goto L006008a5;
  }
  L006007e5: { // 0x6007e5: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L006007eb: { // 0x6007eb: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L006007ed: { // 0x6007ed: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L006007ef: { // 0x6007ef: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L006007f5: { // 0x6007f5: e8e6f50200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6293498u); flags=s.arithmetic_flags;
  }
  L006007fa: { // 0x6007fa: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L006007fb: { // 0x6007fb: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L006007fd: { // 0x6007fd: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L006007ff: { // 0x6007ff: a801 TEST AL,0x1
    (void)integer::logical(((s.ax & 0xffu))&(0x00000001u),8,flags);
  }
  L00600801: { // 0x600801: 7522 JNZ 0x00600825
    if(integer::condition("JNZ",flags)) goto L00600825;
  }
  L00600803: { // 0x600803: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L00600808: { // 0x600808: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L0060080e: { // 0x60080e: e8cdf50200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6293523u); flags=s.arithmetic_flags;
  }
  L00600813: { // 0x600813: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00600814: { // 0x600814: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00600816: { // 0x600816: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L0060081b: { // 0x60081b: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L0060081d: { // 0x60081d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0060081e: { // 0x60081e: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00600820: { // 0x600820: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L00600822: { // 0x600822: 4f DEC EDI
    s.di = integer::decrement(s.di,32,flags);
  }
  L00600823: { // 0x600823: eb21 JMP 0x00600846
    goto L00600846;
  }
  L00600825: { // 0x600825: 8b15c055a200 MOV EDX,dword ptr [0x00a255c0]
    s.dx = m.r32((0x00a255c0u));
  }
  L0060082b: { // 0x60082b: 8d8a18020000 LEA ECX,[EDX + 0x218]
    s.cx = (s.dx+0x00000218u);
  }
  L00600831: { // 0x600831: e8aaf50200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6293558u); flags=s.arithmetic_flags;
  }
  L00600836: { // 0x600836: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00600837: { // 0x600837: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00600839: { // 0x600839: b903000000 MOV ECX,0x3
    s.cx = 0x00000003u;
  }
  L0060083e: { // 0x60083e: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00600840: { // 0x600840: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00600841: { // 0x600841: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00600843: { // 0x600843: 8bf2 MOV ESI,EDX
    s.si = s.dx;
  }
  L00600845: { // 0x600845: 4e DEC ESI
    s.si = integer::decrement(s.si,32,flags);
  }
  L00600846: { // 0x600846: 8b9db0000000 MOV EBX,dword ptr [EBP + 0xb0]
    s.bx = m.r32((s.bp+0x000000b0u));
  }
  L0060084c: { // 0x60084c: b9fbffffff MOV ECX,0xfffffffb
    s.cx = 0xfffffffbu;
  }
  L00600851: { // 0x600851: 03df ADD EBX,EDI
    s.bx = integer::add(s.bx,s.di,32,flags);
  }
  L00600853: { // 0x600853: 8bbdb4000000 MOV EDI,dword ptr [EBP + 0xb4]
    s.di = m.r32((s.bp+0x000000b4u));
  }
  L00600859: { // 0x600859: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0060085b: { // 0x60085b: 03fe ADD EDI,ESI
    s.di = integer::add(s.di,s.si,32,flags);
  }
  L0060085d: { // 0x60085d: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060085f: { // 0x60085f: 899db0000000 MOV dword ptr [EBP + 0xb0],EBX
    m.w32((s.bp+0x000000b0u), s.bx);
  }
  L00600865: { // 0x600865: 89bdb4000000 MOV dword ptr [EBP + 0xb4],EDI
    m.w32((s.bp+0x000000b4u), s.di);
  }
  L0060086b: { // 0x60086b: 7d08 JGE 0x00600875
    if(integer::condition("JGE",flags)) goto L00600875;
  }
  L0060086d: { // 0x60086d: 898db0000000 MOV dword ptr [EBP + 0xb0],ECX
    m.w32((s.bp+0x000000b0u), s.cx);
  }
  L00600873: { // 0x600873: eb0f JMP 0x00600884
    goto L00600884;
  }
  L00600875: { // 0x600875: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00600878: { // 0x600878: 7e0a JLE 0x00600884
    if(integer::condition("JLE",flags)) goto L00600884;
  }
  L0060087a: { // 0x60087a: c785b000000005000000 MOV dword ptr [EBP + 0xb0],0x5
    m.w32((s.bp+0x000000b0u), 0x00000005u);
  }
  L00600884: { // 0x600884: 8b85b4000000 MOV EAX,dword ptr [EBP + 0xb4]
    s.ax = m.r32((s.bp+0x000000b4u));
  }
  L0060088a: { // 0x60088a: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0060088c: { // 0x60088c: 7d08 JGE 0x00600896
    if(integer::condition("JGE",flags)) goto L00600896;
  }
  L0060088e: { // 0x60088e: 898db4000000 MOV dword ptr [EBP + 0xb4],ECX
    m.w32((s.bp+0x000000b4u), s.cx);
  }
  L00600894: { // 0x600894: eb0f JMP 0x006008a5
    goto L006008a5;
  }
  L00600896: { // 0x600896: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00600899: { // 0x600899: 7e0a JLE 0x006008a5
    if(integer::condition("JLE",flags)) goto L006008a5;
  }
  L0060089b: { // 0x60089b: c785b400000005000000 MOV dword ptr [EBP + 0xb4],0x5
    m.w32((s.bp+0x000000b4u), 0x00000005u);
  }
  L006008a5: { // 0x6008a5: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L006008a9: { // 0x6008a9: 8d9dbc000000 LEA EBX,[EBP + 0xbc]
    s.bx = (s.bp+0x000000bcu);
  }
  L006008af: { // 0x6008af: c744241400000000 MOV dword ptr [ESP + 0x14],0x0
    m.w32((f.sp+0x00000014u), 0x00000000u);
  }
  L006008b7: { // 0x6008b7: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L006008bb: { // 0x6008bb: 8bd3 MOV EDX,EBX
    s.dx = s.bx;
  }
  L006008bd: { // 0x6008bd: d95c2428 FSTP float ptr [ESP + 0x28]
    const auto address=(f.sp+0x00000028u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006008c1: { // 0x6008c1: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L006008c5: { // 0x6008c5: c744241800000000 MOV dword ptr [ESP + 0x18],0x0
    m.w32((f.sp+0x00000018u), 0x00000000u);
  }
  L006008cd: { // 0x6008cd: 8b4c2418 MOV ECX,dword ptr [ESP + 0x18]
    s.cx = m.r32((f.sp+0x00000018u));
  }
  L006008d1: { // 0x6008d1: 8902 MOV dword ptr [EDX],EAX
    m.w32((s.dx), s.ax);
  }
  L006008d3: { // 0x6008d3: d95c242c FSTP float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006008d7: { // 0x6008d7: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006008db: { // 0x6008db: c744241c000000c0 MOV dword ptr [ESP + 0x1c],0xc0000000
    m.w32((f.sp+0x0000001cu), 0xc0000000u);
  }
  L006008e3: { // 0x6008e3: 8b44241c MOV EAX,dword ptr [ESP + 0x1c]
    s.ax = m.r32((f.sp+0x0000001cu));
  }
  L006008e7: { // 0x6008e7: 894a04 MOV dword ptr [EDX + 0x4],ECX
    m.w32((s.dx+0x00000004u), s.cx);
  }
  L006008ea: { // 0x6008ea: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006008ee: { // 0x6008ee: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L006008f1: { // 0x6008f1: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L006008f7: { // 0x6008f7: d94308 FLD float ptr [EBX + 0x8]
    const auto address=(s.bx+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L006008fa: { // 0x6008fa: db8120130000 FILD dword ptr [ECX + 0x1320]
    const auto address=(s.cx+0x00001320u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600900: { // 0x600900: dee9 FSUBP
    numeric_b88::detail::reg<0xdee9>(s.fp);
  }
  L00600902: { // 0x600902: d95b08 FSTP float ptr [EBX + 0x8]
    const auto address=(s.bx+0x00000008u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600905: { // 0x600905: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L00600909: { // 0x600909: e842a11600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6293774u); flags=s.arithmetic_flags;
  }
  L0060090e: { // 0x60090e: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L00600912: { // 0x600912: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600913: { // 0x600913: e838a11600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6293784u); flags=s.arithmetic_flags;
  }
  L00600918: { // 0x600918: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0060091c: { // 0x60091c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060091d: { // 0x60091d: e82ea11600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6293794u); flags=s.arithmetic_flags;
  }
  L00600922: { // 0x600922: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600923: { // 0x600923: 8d4c2444 LEA ECX,[ESP + 0x44]
    s.cx = (f.sp+0x00000044u);
  }
  L00600927: { // 0x600927: e8b43de3ff CALL 0x004346e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004346e0u,6293804u); flags=s.arithmetic_flags;
  }
  L0060092c: { // 0x60092c: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060092d: { // 0x60092d: 8d4c242c LEA ECX,[ESP + 0x2c]
    s.cx = (f.sp+0x0000002cu);
  }
  L00600931: { // 0x600931: e82a6ce3ff CALL 0x00437560
    s.arithmetic_flags=flags; invoke(m,s,f,0x00437560u,6293814u); flags=s.arithmetic_flags;
  }
  L00600936: { // 0x600936: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L0060093a: { // 0x60093a: e811a11600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6293823u); flags=s.arithmetic_flags;
  }
  L0060093f: { // 0x60093f: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L00600943: { // 0x600943: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600944: { // 0x600944: e807a11600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6293833u); flags=s.arithmetic_flags;
  }
  L00600949: { // 0x600949: d944242c FLD float ptr [ESP + 0x2c]
    const auto address=(f.sp+0x0000002cu);
    s.fp.load32(m.r32(address));
  }
  L0060094d: { // 0x60094d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L0060094e: { // 0x60094e: e8fda01600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6293843u); flags=s.arithmetic_flags;
  }
  L00600953: { // 0x600953: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600954: { // 0x600954: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00600958: { // 0x600958: e8833de3ff CALL 0x004346e0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004346e0u,6293853u); flags=s.arithmetic_flags;
  }
  L0060095d: { // 0x60095d: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L00600961: { // 0x600961: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00600966: { // 0x600966: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00600967: { // 0x600967: e80467f5ff CALL 0x00557070
    s.arithmetic_flags=flags; invoke(m,s,f,0x00557070u,6293868u); flags=s.arithmetic_flags;
  }
  L0060096c: { // 0x60096c: 8b0d70e0a500 MOV ECX,dword ptr [0x00a5e070]
    s.cx = m.r32((0x00a5e070u));
  }
  L00600972: { // 0x600972: 89442420 MOV dword ptr [ESP + 0x20],EAX
    m.w32((f.sp+0x00000020u), s.ax);
  }
  L00600976: { // 0x600976: 8d542444 LEA EDX,[ESP + 0x44]
    s.dx = (f.sp+0x00000044u);
  }
  L0060097a: { // 0x60097a: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0060097c: { // 0x60097c: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060097d: { // 0x60097d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00600982: { // 0x600982: 89442438 MOV dword ptr [ESP + 0x38],EAX
    m.w32((f.sp+0x00000038u), s.ax);
  }
  L00600986: { // 0x600986: e8054bf4ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6293899u); flags=s.arithmetic_flags;
  }
  L0060098b: { // 0x60098b: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L0060098d: { // 0x60098d: bf00010000 MOV EDI,0x100
    s.di = 0x00000100u;
  }
  L00600992: { // 0x600992: c644241300 MOV byte ptr [ESP + 0x13],0x0
    m.w8((f.sp+0x00000013u), 0x00000000u);
  }
  L00600997: { // 0x600997: c644241200 MOV byte ptr [ESP + 0x12],0x0
    m.w8((f.sp+0x00000012u), 0x00000000u);
  }
  L0060099c: { // 0x60099c: 85be40010000 TEST dword ptr [ESI + 0x140],EDI
    (void)integer::logical((m.r32((s.si+0x00000140u)))&(s.di),32,flags);
  }
  L006009a2: { // 0x6009a2: 7517 JNZ 0x006009bb
    if(integer::condition("JNZ",flags)) goto L006009bb;
  }
  L006009a4: { // 0x6009a4: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L006009a8: { // 0x6009a8: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L006009ad: { // 0x6009ad: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L006009ae: { // 0x6009ae: e8dd4af4ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6293939u); flags=s.arithmetic_flags;
  }
  L006009b3: { // 0x6009b3: 85b840010000 TEST dword ptr [EAX + 0x140],EDI
    (void)integer::logical((m.r32((s.ax+0x00000140u)))&(s.di),32,flags);
  }
  L006009b9: { // 0x6009b9: 7424 JZ 0x006009df
    if(integer::condition("JZ",flags)) goto L006009df;
  }
  L006009bb: { // 0x6009bb: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L006009bf: { // 0x6009bf: 8b4c244c MOV ECX,dword ptr [ESP + 0x4c]
    s.cx = m.r32((f.sp+0x0000004cu));
  }
  L006009c3: { // 0x6009c3: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006009c5: { // 0x6009c5: 8b4c2440 MOV ECX,dword ptr [ESP + 0x40]
    s.cx = m.r32((f.sp+0x00000040u));
  }
  L006009c9: { // 0x6009c9: 7c0b JL 0x006009d6
    if(integer::condition("JL",flags)) goto L006009d6;
  }
  L006009cb: { // 0x6009cb: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006009cd: { // 0x6009cd: 7d10 JGE 0x006009df
    if(integer::condition("JGE",flags)) goto L006009df;
  }
  L006009cf: { // 0x6009cf: c644241201 MOV byte ptr [ESP + 0x12],0x1
    m.w8((f.sp+0x00000012u), 0x00000001u);
  }
  L006009d4: { // 0x6009d4: eb09 JMP 0x006009df
    goto L006009df;
  }
  L006009d6: { // 0x6009d6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L006009d8: { // 0x6009d8: 7c05 JL 0x006009df
    if(integer::condition("JL",flags)) goto L006009df;
  }
  L006009da: { // 0x6009da: c644241301 MOV byte ptr [ESP + 0x13],0x1
    m.w8((f.sp+0x00000013u), 0x00000001u);
  }
  L006009df: { // 0x6009df: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L006009e3: { // 0x6009e3: c644241100 MOV byte ptr [ESP + 0x11],0x0
    m.w8((f.sp+0x00000011u), 0x00000000u);
  }
  L006009e8: { // 0x6009e8: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006009ea: { // 0x6009ea: 0f858f000000 JNZ 0x00600a7f
    if(integer::condition("JNZ",flags)) goto L00600a7f;
  }
  L006009f0: { // 0x6009f0: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L006009f4: { // 0x6009f4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L006009f6: { // 0x6009f6: 0f8583000000 JNZ 0x00600a7f
    if(integer::condition("JNZ",flags)) goto L00600a7f;
  }
  L006009fc: { // 0x6009fc: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600a00: { // 0x600a00: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L00600a04: { // 0x600a04: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L00600a06: { // 0x600a06: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00600a08: { // 0x600a08: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00600a0b: { // 0x600a0b: 7570 JNZ 0x00600a7d
    if(integer::condition("JNZ",flags)) goto L00600a7d;
  }
  L00600a0d: { // 0x600a0d: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L00600a11: { // 0x600a11: d825a87a7800 FSUB float ptr [0x00787aa8]
    const auto address=(0x00787aa8u);
    s.fp.subtract32(m.r32(address));
  }
  L00600a17: { // 0x600a17: d8d9 FCOMP
    numeric_b88::detail::reg<0xd8d9>(s.fp);
  }
  L00600a19: { // 0x600a19: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00600a1b: { // 0x600a1b: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00600a1e: { // 0x600a1e: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00600a20: { // 0x600a20: 745d JZ 0x00600a7f
    if(integer::condition("JZ",flags)) goto L00600a7f;
  }
  L00600a22: { // 0x600a22: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00600a24: { // 0x600a24: e88709e7ff CALL 0x004713b0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004713b0u,6294057u); flags=s.arithmetic_flags;
  }
  L00600a29: { // 0x600a29: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L00600a2b: { // 0x600a2b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00600a2d: { // 0x600a2d: 7515 JNZ 0x00600a44
    if(integer::condition("JNZ",flags)) goto L00600a44;
  }
  L00600a2f: { // 0x600a2f: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00600a31: { // 0x600a31: 6aff PUSH -0x1
    f.push(m,0xffffffffu);
  }
  L00600a33: { // 0x600a33: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00600a35: { // 0x600a35: e8064ae7ff CALL 0x00475440
    s.arithmetic_flags=flags; invoke(m,s,f,0x00475440u,6294074u); flags=s.arithmetic_flags;
  }
  L00600a3a: { // 0x600a3a: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600a3c: { // 0x600a3c: 7506 JNZ 0x00600a44
    if(integer::condition("JNZ",flags)) goto L00600a44;
  }
  L00600a3e: { // 0x600a3e: 88442411 MOV byte ptr [ESP + 0x11],AL
    m.w8((f.sp+0x00000011u), (s.ax & 0xffu));
  }
  L00600a42: { // 0x600a42: eb3b JMP 0x00600a7f
    goto L00600a7f;
  }
  L00600a44: { // 0x600a44: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00600a46: { // 0x600a46: c644241101 MOV byte ptr [ESP + 0x11],0x1
    m.w8((f.sp+0x00000011u), 0x00000001u);
  }
  L00600a4b: { // 0x600a4b: 7432 JZ 0x00600a7f
    if(integer::condition("JZ",flags)) goto L00600a7f;
  }
  L00600a4d: { // 0x600a4d: 8b8f18040000 MOV ECX,dword ptr [EDI + 0x418]
    s.cx = m.r32((s.di+0x00000418u));
  }
  L00600a53: { // 0x600a53: 8a8159130000 MOV AL,byte ptr [ECX + 0x1359]
    s.ax = with_al(s.ax, m.r8((s.cx+0x00001359u)));
  }
  L00600a59: { // 0x600a59: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600a5b: { // 0x600a5b: 740e JZ 0x00600a6b
    if(integer::condition("JZ",flags)) goto L00600a6b;
  }
  L00600a5d: { // 0x600a5d: 83bfec04000008 CMP dword ptr [EDI + 0x4ec],0x8
    (void)integer::sub(m.r32((s.di+0x000004ecu)),0x00000008u,32,flags);
  }
  L00600a64: { // 0x600a64: 7c05 JL 0x00600a6b
    if(integer::condition("JL",flags)) goto L00600a6b;
  }
  L00600a66: { // 0x600a66: c644241100 MOV byte ptr [ESP + 0x11],0x0
    m.w8((f.sp+0x00000011u), 0x00000000u);
  }
  L00600a6b: { // 0x600a6b: 8b17 MOV EDX,dword ptr [EDI]
    s.dx = m.r32((s.di));
  }
  L00600a6d: { // 0x600a6d: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00600a6f: { // 0x600a6f: ff527c CALL dword ptr [EDX + 0x7c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000007cu)),6294130u); flags=s.arithmetic_flags;
  }
  L00600a72: { // 0x600a72: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600a74: { // 0x600a74: 7409 JZ 0x00600a7f
    if(integer::condition("JZ",flags)) goto L00600a7f;
  }
  L00600a76: { // 0x600a76: c644241100 MOV byte ptr [ESP + 0x11],0x0
    m.w8((f.sp+0x00000011u), 0x00000000u);
  }
  L00600a7b: { // 0x600a7b: eb02 JMP 0x00600a7f
    goto L00600a7f;
  }
  L00600a7d: { // 0x600a7d: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L00600a7f: { // 0x600a7f: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600a83: { // 0x600a83: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600a87: { // 0x600a87: d9442430 FLD float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.load32(m.r32(address));
  }
  L00600a8b: { // 0x600a8b: d85c2424 FCOMP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00600a8f: { // 0x600a8f: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00600a91: { // 0x600a91: 8a442413 MOV AL,byte ptr [ESP + 0x13]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000013u)));
  }
  L00600a95: { // 0x600a95: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00600a98: { // 0x600a98: 0f8559010000 JNZ 0x00600bf7
    if(integer::condition("JNZ",flags)) goto L00600bf7;
  }
  L00600a9e: { // 0x600a9e: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600aa0: { // 0x600aa0: 0f8555010000 JNZ 0x00600bfb
    if(integer::condition("JNZ",flags)) goto L00600bfb;
  }
  L00600aa6: { // 0x600aa6: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L00600aaa: { // 0x600aaa: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600aac: { // 0x600aac: 0f8562010000 JNZ 0x00600c14
    if(integer::condition("JNZ",flags)) goto L00600c14;
  }
  L00600ab2: { // 0x600ab2: 8a442411 MOV AL,byte ptr [ESP + 0x11]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000011u)));
  }
  L00600ab6: { // 0x600ab6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600ab8: { // 0x600ab8: 0f8403010000 JZ 0x00600bc1
    if(integer::condition("JZ",flags)) goto L00600bc1;
  }
  L00600abe: { // 0x600abe: 8b4c2420 MOV ECX,dword ptr [ESP + 0x20]
    s.cx = m.r32((f.sp+0x00000020u));
  }
  L00600ac2: { // 0x600ac2: 83c19c ADD ECX,-0x64
    s.cx = integer::add(s.cx,0xffffff9cu,32,flags);
  }
  L00600ac5: { // 0x600ac5: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00600ac9: { // 0x600ac9: db442420 FILD dword ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600acd: { // 0x600acd: d85c2430 FCOMP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    s.fp.compare_pop32(m.r32(address));
  }
  L00600ad1: { // 0x600ad1: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00600ad3: { // 0x600ad3: f6c401 TEST AH,0x1
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L00600ad6: { // 0x600ad6: 7408 JZ 0x00600ae0
    if(integer::condition("JZ",flags)) goto L00600ae0;
  }
  L00600ad8: { // 0x600ad8: 8b542424 MOV EDX,dword ptr [ESP + 0x24]
    s.dx = m.r32((f.sp+0x00000024u));
  }
  L00600adc: { // 0x600adc: 89542430 MOV dword ptr [ESP + 0x30],EDX
    m.w32((f.sp+0x00000030u), s.dx);
  }
  L00600ae0: { // 0x600ae0: 8b0dac1c8200 MOV ECX,dword ptr [0x00821cac]
    s.cx = m.r32((0x00821cacu));
  }
  L00600ae6: { // 0x600ae6: 8d442444 LEA EAX,[ESP + 0x44]
    s.ax = (f.sp+0x00000044u);
  }
  L00600aea: { // 0x600aea: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600aeb: { // 0x600aeb: e860bc0900 CALL 0x0069c750
    s.arithmetic_flags=flags; invoke(m,s,f,0x0069c750u,6294256u); flags=s.arithmetic_flags;
  }
  L00600af0: { // 0x600af0: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L00600af2: { // 0x600af2: 8d8c24bc000000 LEA ECX,[ESP + 0xbc]
    s.cx = (f.sp+0x000000bcu);
  }
  L00600af9: { // 0x600af9: e822ce1000 CALL 0x0070d920
    s.arithmetic_flags=flags; invoke(m,s,f,0x0070d920u,6294270u); flags=s.arithmetic_flags;
  }
  L00600afe: { // 0x600afe: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L00600b03: { // 0x600b03: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00600b05: { // 0x600b05: 8d7c245c LEA EDI,[ESP + 0x5c]
    s.di = (f.sp+0x0000005cu);
  }
  L00600b09: { // 0x600b09: 8d54245c LEA EDX,[ESP + 0x5c]
    s.dx = (f.sp+0x0000005cu);
  }
  L00600b0d: { // 0x600b0d: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00600b0f: { // 0x600b0f: 8d8c24bc000000 LEA ECX,[ESP + 0xbc]
    s.cx = (f.sp+0x000000bcu);
  }
  L00600b16: { // 0x600b16: e805d7f8ff CALL 0x0058e220
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058e220u,6294299u); flags=s.arithmetic_flags;
  }
  L00600b1b: { // 0x600b1b: d94304 FLD float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    s.fp.load32(m.r32(address));
  }
  L00600b1e: { // 0x600b1e: b90c000000 MOV ECX,0xc
    s.cx = 0x0000000cu;
  }
  L00600b23: { // 0x600b23: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L00600b25: { // 0x600b25: 8dbc248c000000 LEA EDI,[ESP + 0x8c]
    s.di = (f.sp+0x0000008cu);
  }
  L00600b2c: { // 0x600b2c: 8b13 MOV EDX,dword ptr [EBX]
    s.dx = m.r32((s.bx));
  }
  L00600b2e: { // 0x600b2e: f3a5 MOVSD.REP ES:EDI,ESI
    string_instruction(m,s,flags,Kind::move,32u,Repeat::count);
  }
  L00600b30: { // 0x600b30: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00600b32: { // 0x600b32: 8b4b08 MOV ECX,dword ptr [EBX + 0x8]
    s.cx = m.r32((s.bx+0x00000008u));
  }
  L00600b35: { // 0x600b35: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00600b36: { // 0x600b36: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00600b37: { // 0x600b37: 8d4c241c LEA ECX,[ESP + 0x1c]
    s.cx = (f.sp+0x0000001cu);
  }
  L00600b3b: { // 0x600b3b: d91c24 FSTP float ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600b3e: { // 0x600b3e: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00600b3f: { // 0x600b3f: e8cc69e3ff CALL 0x00437510
    s.arithmetic_flags=flags; invoke(m,s,f,0x00437510u,6294340u); flags=s.arithmetic_flags;
  }
  L00600b44: { // 0x600b44: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00600b48: { // 0x600b48: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00600b4c: { // 0x600b4c: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600b4d: { // 0x600b4d: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00600b4e: { // 0x600b4e: 8d8c2494000000 LEA ECX,[ESP + 0x94]
    s.cx = (f.sp+0x00000094u);
  }
  L00600b55: { // 0x600b55: e876cff8ff CALL 0x0058dad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058dad0u,6294362u); flags=s.arithmetic_flags;
  }
  L00600b5a: { // 0x600b5a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00600b5c: { // 0x600b5c: 680000803f PUSH 0x3f800000
    f.push(m,0x3f800000u);
  }
  L00600b61: { // 0x600b61: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L00600b65: { // 0x600b65: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00600b68: { // 0x600b68: 894c241c MOV dword ptr [ESP + 0x1c],ECX
    m.w32((f.sp+0x0000001cu), s.cx);
  }
  L00600b6c: { // 0x600b6c: 8d4c2418 LEA ECX,[ESP + 0x18]
    s.cx = (f.sp+0x00000018u);
  }
  L00600b70: { // 0x600b70: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00600b73: { // 0x600b73: 89542420 MOV dword ptr [ESP + 0x20],EDX
    m.w32((f.sp+0x00000020u), s.dx);
  }
  L00600b77: { // 0x600b77: e8b469e3ff CALL 0x00437530
    s.arithmetic_flags=flags; invoke(m,s,f,0x00437530u,6294396u); flags=s.arithmetic_flags;
  }
  L00600b7c: { // 0x600b7c: d944241c FLD float ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load32(m.r32(address));
  }
  L00600b80: { // 0x600b80: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00600b84: { // 0x600b84: 8d4c2450 LEA ECX,[ESP + 0x50]
    s.cx = (f.sp+0x00000050u);
  }
  L00600b88: { // 0x600b88: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600b89: { // 0x600b89: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00600b8a: { // 0x600b8a: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00600b8c: { // 0x600b8c: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600b90: { // 0x600b90: 8d4c2464 LEA ECX,[ESP + 0x64]
    s.cx = (f.sp+0x00000064u);
  }
  L00600b94: { // 0x600b94: e837cff8ff CALL 0x0058dad0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0058dad0u,6294425u); flags=s.arithmetic_flags;
  }
  L00600b99: { // 0x600b99: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00600b9b: { // 0x600b9b: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00600b9f: { // 0x600b9f: 8b4804 MOV ECX,dword ptr [EAX + 0x4]
    s.cx = m.r32((s.ax+0x00000004u));
  }
  L00600ba2: { // 0x600ba2: 894c2418 MOV dword ptr [ESP + 0x18],ECX
    m.w32((f.sp+0x00000018u), s.cx);
  }
  L00600ba6: { // 0x600ba6: 8b5008 MOV EDX,dword ptr [EAX + 0x8]
    s.dx = m.r32((s.ax+0x00000008u));
  }
  L00600ba9: { // 0x600ba9: 8b442414 MOV EAX,dword ptr [ESP + 0x14]
    s.ax = m.r32((f.sp+0x00000014u));
  }
  L00600bad: { // 0x600bad: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L00600bb1: { // 0x600bb1: d9e0 FCHS
    numeric_b88::detail::reg<0xd9e0>(s.fp);
  }
  L00600bb3: { // 0x600bb3: d95b04 FSTP float ptr [EBX + 0x4]
    const auto address=(s.bx+0x00000004u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600bb6: { // 0x600bb6: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00600bb8: { // 0x600bb8: 8954241c MOV dword ptr [ESP + 0x1c],EDX
    m.w32((f.sp+0x0000001cu), s.dx);
  }
  L00600bbc: { // 0x600bbc: 8903 MOV dword ptr [EBX],EAX
    m.w32((s.bx), s.ax);
  }
  L00600bbe: { // 0x600bbe: 894b08 MOV dword ptr [EBX + 0x8],ECX
    m.w32((s.bx+0x00000008u), s.cx);
  }
  L00600bc1: { // 0x600bc1: 8b5500 MOV EDX,dword ptr [EBP]
    s.dx = m.r32((s.bp));
  }
  L00600bc4: { // 0x600bc4: 8bcd MOV ECX,EBP
    s.cx = s.bp;
  }
  L00600bc6: { // 0x600bc6: ff92b0010000 CALL dword ptr [EDX + 0x1b0]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x000001b0u)),6294476u); flags=s.arithmetic_flags;
  }
  L00600bcc: { // 0x600bcc: 83f805 CMP EAX,0x5
    (void)integer::sub(s.ax,0x00000005u,32,flags);
  }
  L00600bcf: { // 0x600bcf: 7e5b JLE 0x00600c2c
    if(integer::condition("JLE",flags)) goto L00600c2c;
  }
  L00600bd1: { // 0x600bd1: a16c89a200 MOV EAX,[0x00a2896c]
    s.ax = m.r32((0x00a2896cu));
  }
  L00600bd6: { // 0x600bd6: 2501000080 AND EAX,0x80000001
    s.ax = integer::logical((s.ax)&(0x80000001u),32,flags);
  }
  L00600bdb: { // 0x600bdb: 7905 JNS 0x00600be2
    if(integer::condition("JNS",flags)) goto L00600be2;
  }
  L00600bdd: { // 0x600bdd: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00600bde: { // 0x600bde: 83c8fe OR EAX,0xfffffffe
    s.ax = integer::logical((s.ax)|(0xfffffffeu),32,flags);
  }
  L00600be1: { // 0x600be1: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00600be2: { // 0x600be2: 7548 JNZ 0x00600c2c
    if(integer::condition("JNZ",flags)) goto L00600c2c;
  }
  L00600be4: { // 0x600be4: 8b85b8000000 MOV EAX,dword ptr [EBP + 0xb8]
    s.ax = m.r32((s.bp+0x000000b8u));
  }
  L00600bea: { // 0x600bea: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L00600beb: { // 0x600beb: 83f8fb CMP EAX,-0x5
    (void)integer::sub(s.ax,0xfffffffbu,32,flags);
  }
  L00600bee: { // 0x600bee: 7d4c JGE 0x00600c3c
    if(integer::condition("JGE",flags)) goto L00600c3c;
  }
  L00600bf0: { // 0x600bf0: b8fbffffff MOV EAX,0xfffffffb
    s.ax = 0xfffffffbu;
  }
  L00600bf5: { // 0x600bf5: eb45 JMP 0x00600c3c
    goto L00600c3c;
  }
  L00600bf7: { // 0x600bf7: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600bf9: { // 0x600bf9: 740d JZ 0x00600c08
    if(integer::condition("JZ",flags)) goto L00600c08;
  }
  L00600bfb: { // 0x600bfb: db442434 FILD dword ptr [ESP + 0x34]
    const auto address=(f.sp+0x00000034u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600bff: { // 0x600bff: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600c03: { // 0x600c03: e9d8feffff JMP 0x00600ae0
    goto L00600ae0;
  }
  L00600c08: { // 0x600c08: 8a442412 MOV AL,byte ptr [ESP + 0x12]
    s.ax = with_al(s.ax, m.r8((f.sp+0x00000012u)));
  }
  L00600c0c: { // 0x600c0c: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600c0e: { // 0x600c0e: 0f84aafeffff JZ 0x00600abe
    if(integer::condition("JZ",flags)) goto L00600abe;
  }
  L00600c14: { // 0x600c14: 8b442434 MOV EAX,dword ptr [ESP + 0x34]
    s.ax = m.r32((f.sp+0x00000034u));
  }
  L00600c18: { // 0x600c18: 83c0ec ADD EAX,-0x14
    s.ax = integer::add(s.ax,0xffffffecu,32,flags);
  }
  L00600c1b: { // 0x600c1b: 89442424 MOV dword ptr [ESP + 0x24],EAX
    m.w32((f.sp+0x00000024u), s.ax);
  }
  L00600c1f: { // 0x600c1f: db442424 FILD dword ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600c23: { // 0x600c23: d95c2430 FSTP float ptr [ESP + 0x30]
    const auto address=(f.sp+0x00000030u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600c27: { // 0x600c27: e9b4feffff JMP 0x00600ae0
    goto L00600ae0;
  }
  L00600c2c: { // 0x600c2c: 8b85b8000000 MOV EAX,dword ptr [EBP + 0xb8]
    s.ax = m.r32((s.bp+0x000000b8u));
  }
  L00600c32: { // 0x600c32: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00600c34: { // 0x600c34: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00600c36: { // 0x600c36: 0f9ec1 SETLE CL
    s.cx = with_al(s.cx, (integer::condition("SETLE",flags)?1u:0u));
  }
  L00600c39: { // 0x600c39: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L00600c3a: { // 0x600c3a: 23c1 AND EAX,ECX
    s.ax = integer::logical((s.ax)&(s.cx),32,flags);
  }
  L00600c3c: { // 0x600c3c: 8985b8000000 MOV dword ptr [EBP + 0xb8],EAX
    m.w32((s.bp+0x000000b8u), s.ax);
  }
  L00600c42: { // 0x600c42: 66ff8d1a010000 DEC word ptr [EBP + 0x11a]
    m.w16((s.bp+0x0000011au), integer::decrement(m.r16((s.bp+0x0000011au)),16,flags));
  }
  L00600c49: { // 0x600c49: 6683bd1a01000000 CMP word ptr [EBP + 0x11a],0x0
    (void)integer::sub(m.r16((s.bp+0x0000011au)),0x00000000u,16,flags);
  }
  L00600c51: { // 0x600c51: 0f85ee000000 JNZ 0x00600d45
    if(integer::condition("JNZ",flags)) goto L00600d45;
  }
  L00600c57: { // 0x600c57: 8b8598000000 MOV EAX,dword ptr [EBP + 0x98]
    s.ax = m.r32((s.bp+0x00000098u));
  }
  L00600c5d: { // 0x600c5d: 8b88b8020000 MOV ECX,dword ptr [EAX + 0x2b8]
    s.cx = m.r32((s.ax+0x000002b8u));
  }
  L00600c63: { // 0x600c63: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L00600c65: { // 0x600c65: 0f84da000000 JZ 0x00600d45
    if(integer::condition("JZ",flags)) goto L00600d45;
  }
  L00600c6b: { // 0x600c6b: 668b90ac020000 MOV DX,word ptr [EAX + 0x2ac]
    s.dx = with_ax(s.dx, m.r16((s.ax+0x000002acu)));
  }
  L00600c72: { // 0x600c72: 8d8588000000 LEA EAX,[EBP + 0x88]
    s.ax = (s.bp+0x00000088u);
  }
  L00600c78: { // 0x600c78: 6689951a010000 MOV word ptr [EBP + 0x11a],DX
    m.w16((s.bp+0x0000011au), (s.dx & 0xffffu));
  }
  L00600c7f: { // 0x600c7f: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00600c81: { // 0x600c81: 894c2438 MOV dword ptr [ESP + 0x38],ECX
    m.w32((f.sp+0x00000038u), s.cx);
  }
  L00600c85: { // 0x600c85: 8d4c2438 LEA ECX,[ESP + 0x38]
    s.cx = (f.sp+0x00000038u);
  }
  L00600c89: { // 0x600c89: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L00600c8c: { // 0x600c8c: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L00600c8d: { // 0x600c8d: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L00600c92: { // 0x600c92: 89542440 MOV dword ptr [ESP + 0x40],EDX
    m.w32((f.sp+0x00000040u), s.dx);
  }
  L00600c96: { // 0x600c96: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L00600c99: { // 0x600c99: 89442444 MOV dword ptr [ESP + 0x44],EAX
    m.w32((f.sp+0x00000044u), s.ax);
  }
  L00600c9d: { // 0x600c9d: e8ee47f4ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6294690u); flags=s.arithmetic_flags;
  }
  L00600ca2: { // 0x600ca2: 8bb0e4000000 MOV ESI,dword ptr [EAX + 0xe4]
    s.si = m.r32((s.ax+0x000000e4u));
  }
  L00600ca8: { // 0x600ca8: 85f6 TEST ESI,ESI
    (void)integer::logical((s.si)&(s.si),32,flags);
  }
  L00600caa: { // 0x600caa: 0f8495000000 JZ 0x00600d45
    if(integer::condition("JZ",flags)) goto L00600d45;
  }
  L00600cb0: { // 0x600cb0: 8d9688000000 LEA EDX,[ESI + 0x88]
    s.dx = (s.si+0x00000088u);
  }
  L00600cb6: { // 0x600cb6: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L00600cb8: { // 0x600cb8: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L00600cba: { // 0x600cba: 8b7804 MOV EDI,dword ptr [EAX + 0x4]
    s.di = m.r32((s.ax+0x00000004u));
  }
  L00600cbd: { // 0x600cbd: 8b4808 MOV ECX,dword ptr [EAX + 0x8]
    s.cx = m.r32((s.ax+0x00000008u));
  }
  L00600cc0: { // 0x600cc0: 8d8588000000 LEA EAX,[EBP + 0x88]
    s.ax = (s.bp+0x00000088u);
  }
  L00600cc6: { // 0x600cc6: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00600cc8: { // 0x600cc8: 894c2458 MOV dword ptr [ESP + 0x58],ECX
    m.w32((f.sp+0x00000058u), s.cx);
  }
  L00600ccc: { // 0x600ccc: 8b03 MOV EAX,dword ptr [EBX]
    s.ax = m.r32((s.bx));
  }
  L00600cce: { // 0x600cce: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00600cd0: { // 0x600cd0: 8b4b04 MOV ECX,dword ptr [EBX + 0x4]
    s.cx = m.r32((s.bx+0x00000004u));
  }
  L00600cd3: { // 0x600cd3: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L00600cd5: { // 0x600cd5: 8b7e30 MOV EDI,dword ptr [ESI + 0x30]
    s.di = m.r32((s.si+0x00000030u));
  }
  L00600cd8: { // 0x600cd8: 8b5b08 MOV EBX,dword ptr [EBX + 0x8]
    s.bx = m.r32((s.bx+0x00000008u));
  }
  L00600cdb: { // 0x600cdb: 895c2458 MOV dword ptr [ESP + 0x58],EBX
    m.w32((f.sp+0x00000058u), s.bx);
  }
  L00600cdf: { // 0x600cdf: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00600ce1: { // 0x600ce1: 8a467d MOV AL,byte ptr [ESI + 0x7d]
    s.ax = with_al(s.ax, m.r8((s.si+0x0000007du)));
  }
  L00600ce4: { // 0x600ce4: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600ce6: { // 0x600ce6: 7453 JZ 0x00600d3b
    if(integer::condition("JZ",flags)) goto L00600d3b;
  }
  L00600ce8: { // 0x600ce8: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L00600ceb: { // 0x600ceb: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L00600ced: { // 0x600ced: 7e4c JLE 0x00600d3b
    if(integer::condition("JLE",flags)) goto L00600d3b;
  }
  L00600cef: { // 0x600cef: 8b9598000000 MOV EDX,dword ptr [EBP + 0x98]
    s.dx = m.r32((s.bp+0x00000098u));
  }
  L00600cf5: { // 0x600cf5: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00600cf7: { // 0x600cf7: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00600cf9: { // 0x600cf9: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00600cfb: { // 0x600cfb: 8b82b8020000 MOV EAX,dword ptr [EDX + 0x2b8]
    s.ax = m.r32((s.dx+0x000002b8u));
  }
  L00600d01: { // 0x600d01: 89442430 MOV dword ptr [ESP + 0x30],EAX
    m.w32((f.sp+0x00000030u), s.ax);
  }
  L00600d05: { // 0x600d05: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L00600d07: { // 0x600d07: 8b92b4020000 MOV EDX,dword ptr [EDX + 0x2b4]
    s.dx = m.r32((s.dx+0x000002b4u));
  }
  L00600d0d: { // 0x600d0d: 8944242c MOV dword ptr [ESP + 0x2c],EAX
    m.w32((f.sp+0x0000002cu), s.ax);
  }
  L00600d11: { // 0x600d11: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L00600d13: { // 0x600d13: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00600d14: { // 0x600d14: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00600d15: { // 0x600d15: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00600d17: { // 0x600d17: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00600d19: { // 0x600d19: 33ca XOR ECX,EDX
    s.cx = integer::logical((s.cx)^(s.dx),32,flags);
  }
  L00600d1b: { // 0x600d1b: 2bca SUB ECX,EDX
    s.cx = integer::sub(s.cx,s.dx,32,flags);
  }
  L00600d1d: { // 0x600d1d: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00600d1e: { // 0x600d1e: 33c2 XOR EAX,EDX
    s.ax = integer::logical((s.ax)^(s.dx),32,flags);
  }
  L00600d20: { // 0x600d20: 2bc2 SUB EAX,EDX
    s.ax = integer::sub(s.ax,s.dx,32,flags);
  }
  L00600d22: { // 0x600d22: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L00600d24: { // 0x600d24: e887720900 CALL 0x00697fb0
    s.arithmetic_flags=flags; invoke(m,s,f,0x00697fb0u,6294825u); flags=s.arithmetic_flags;
  }
  L00600d29: { // 0x600d29: 8b542430 MOV EDX,dword ptr [ESP + 0x30]
    s.dx = m.r32((f.sp+0x00000030u));
  }
  L00600d2d: { // 0x600d2d: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600d2e: { // 0x600d2e: 8d442438 LEA EAX,[ESP + 0x38]
    s.ax = (f.sp+0x00000038u);
  }
  L00600d32: { // 0x600d32: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00600d34: { // 0x600d34: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600d35: { // 0x600d35: ff9258010000 CALL dword ptr [EDX + 0x158]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000158u)),6294843u); flags=s.arithmetic_flags;
  }
  L00600d3b: { // 0x600d3b: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00600d3d: { // 0x600d3d: 8bf7 MOV ESI,EDI
    s.si = s.di;
  }
  L00600d3f: { // 0x600d3f: 0f856bffffff JNZ 0x00600cb0
    if(integer::condition("JNZ",flags)) goto L00600cb0;
  }
  L00600d45: { // 0x600d45: 8b4504 MOV EAX,dword ptr [EBP + 0x4]
    s.ax = m.r32((s.bp+0x00000004u));
  }
  L00600d48: { // 0x600d48: 8bbd98000000 MOV EDI,dword ptr [EBP + 0x98]
    s.di = m.r32((s.bp+0x00000098u));
  }
  L00600d4e: { // 0x600d4e: 8d7504 LEA ESI,[EBP + 0x4]
    s.si = (s.bp+0x00000004u);
  }
  L00600d51: { // 0x600d51: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00600d52: { // 0x600d52: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6294869u); flags=s.arithmetic_flags;
  }
  L00600d55: { // 0x600d55: 8b9598000000 MOV EDX,dword ptr [EBP + 0x98]
    s.dx = m.r32((s.bp+0x00000098u));
  }
  L00600d5b: { // 0x600d5b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00600d5d: { // 0x600d5d: 668b8d18010000 MOV CX,word ptr [EBP + 0x118]
    s.cx = with_ax(s.cx, m.r16((s.bp+0x00000118u)));
  }
  L00600d64: { // 0x600d64: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00600d66: { // 0x600d66: 8b82b0020000 MOV EAX,dword ptr [EDX + 0x2b0]
    s.ax = m.r32((s.dx+0x000002b0u));
  }
  L00600d6c: { // 0x600d6c: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00600d6d: { // 0x600d6d: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L00600d6f: { // 0x600d6f: 8b0e MOV ECX,dword ptr [ESI]
    s.cx = m.r32((s.si));
  }
  L00600d71: { // 0x600d71: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L00600d73: { // 0x600d73: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6294902u); flags=s.arithmetic_flags;
  }
  L00600d76: { // 0x600d76: 0fbe97db020000 MOVSX EDX,byte ptr [EDI + 0x2db]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.di+0x000002dbu)),8));
  }
  L00600d7d: { // 0x600d7d: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L00600d7f: { // 0x600d7f: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L00600d81: { // 0x600d81: 83e101 AND ECX,0x1
    s.cx = integer::logical((s.cx)&(0x00000001u),32,flags);
  }
  L00600d84: { // 0x600d84: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00600d86: { // 0x600d86: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00600d87: { // 0x600d87: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00600d89: { // 0x600d89: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00600d8b: { // 0x600d8b: 7506 JNZ 0x00600d93
    if(integer::condition("JNZ",flags)) goto L00600d93;
  }
  L00600d8d: { // 0x600d8d: fe851e010000 INC byte ptr [EBP + 0x11e]
    m.w8((s.bp+0x0000011eu), integer::increment(m.r8((s.bp+0x0000011eu)),8,flags));
  }
  L00600d93: { // 0x600d93: 8a851e010000 MOV AL,byte ptr [EBP + 0x11e]
    s.ax = with_al(s.ax, m.r8((s.bp+0x0000011eu)));
  }
  L00600d99: { // 0x600d99: 8a8fd9020000 MOV CL,byte ptr [EDI + 0x2d9]
    s.cx = with_al(s.cx, m.r8((s.di+0x000002d9u)));
  }
  L00600d9f: { // 0x600d9f: 3ac1 CMP AL,CL
    (void)integer::sub((s.ax & 0xffu),(s.cx & 0xffu),8,flags);
  }
  L00600da1: { // 0x600da1: 7523 JNZ 0x00600dc6
    if(integer::condition("JNZ",flags)) goto L00600dc6;
  }
  L00600da3: { // 0x600da3: 8a87d8020000 MOV AL,byte ptr [EDI + 0x2d8]
    s.ax = with_al(s.ax, m.r8((s.di+0x000002d8u)));
  }
  L00600da9: { // 0x600da9: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L00600dab: { // 0x600dab: 7412 JZ 0x00600dbf
    if(integer::condition("JZ",flags)) goto L00600dbf;
  }
  L00600dad: { // 0x600dad: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00600dae: { // 0x600dae: c6852101000001 MOV byte ptr [EBP + 0x121],0x1
    m.w8((s.bp+0x00000121u), 0x00000001u);
  }
  L00600db5: { // 0x600db5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00600db6: { // 0x600db6: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00600db7: { // 0x600db7: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00600db8: { // 0x600db8: 81c4dc000000 ADD ESP,0xdc
    f.sp = integer::add(f.sp,0x000000dcu,32,flags);
  }
  L00600dbe: { // 0x600dbe: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00600dbf: { // 0x600dbf: c6851e01000000 MOV byte ptr [EBP + 0x11e],0x0
    m.w8((s.bp+0x0000011eu), 0x00000000u);
  }
  L00600dc6: { // 0x600dc6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00600dc7: { // 0x600dc7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00600dc8: { // 0x600dc8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00600dc9: { // 0x600dc9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00600dca: { // 0x600dca: 81c4dc000000 ADD ESP,0xdc
    f.sp = integer::add(f.sp,0x000000dcu,32,flags);
  }
  L00600dd0: { // 0x600dd0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_00601550(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00601550: { // 0x601550: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L00601551: { // 0x601551: 8bec MOV EBP,ESP
    s.bp = f.sp;
  }
  L00601553: { // 0x601553: 83e4f8 AND ESP,0xfffffff8
    f.sp = integer::logical((f.sp)&(0xfffffff8u),32,flags);
  }
  L00601556: { // 0x601556: 83ec28 SUB ESP,0x28
    f.sp = integer::sub(f.sp,0x00000028u,32,flags);
  }
  L00601559: { // 0x601559: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0060155a: { // 0x60155a: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0060155b: { // 0x60155b: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0060155c: { // 0x60155c: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0060155e: { // 0x60155e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060155f: { // 0x60155f: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L00601565: { // 0x601565: dc1d10667800 FCOMP double ptr [0x00786610]
    const auto address=(0x00786610u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0060156b: { // 0x60156b: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0060156d: { // 0x60156d: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00601570: { // 0x601570: 0f85e1020000 JNZ 0x00601857
    if(integer::condition("JNZ",flags)) goto L00601857;
  }
  L00601576: { // 0x601576: a1c055a200 MOV EAX,[0x00a255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L0060157b: { // 0x60157b: 8d8818020000 LEA ECX,[EAX + 0x218]
    s.cx = (s.ax+0x00000218u);
  }
  L00601581: { // 0x601581: e85ae80200 CALL 0x0062fde0
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fde0u,6296966u); flags=s.arithmetic_flags;
  }
  L00601586: { // 0x601586: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00601587: { // 0x601587: b90a000000 MOV ECX,0xa
    s.cx = 0x0000000au;
  }
  L0060158c: { // 0x60158c: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L0060158e: { // 0x60158e: 83ea05 SUB EDX,0x5
    s.dx = integer::sub(s.dx,0x00000005u,32,flags);
  }
  L00601591: { // 0x601591: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L00601595: { // 0x601595: db442410 FILD dword ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load_integer32(m.r32(address));
  }
  L00601599: { // 0x601599: dc0df02e7900 FMUL double ptr [0x00792ef0]
    const auto address=(0x00792ef0u);
    s.fp.multiply64(read64(m,address));
  }
  L0060159f: { // 0x60159f: dc0508577800 FADD double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.add64(read64(m,address));
  }
  L006015a5: { // 0x6015a5: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L006015a7: { // 0x6015a7: d88efc000000 FMUL float ptr [ESI + 0xfc]
    const auto address=(s.si+0x000000fcu);
    s.fp.multiply32(m.r32(address));
  }
  L006015ad: { // 0x6015ad: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006015b1: { // 0x6015b1: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L006015b3: { // 0x6015b3: d88e00010000 FMUL float ptr [ESI + 0x100]
    const auto address=(s.si+0x00000100u);
    s.fp.multiply32(m.r32(address));
  }
  L006015b9: { // 0x6015b9: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006015bd: { // 0x6015bd: d88e04010000 FMUL float ptr [ESI + 0x104]
    const auto address=(s.si+0x00000104u);
    s.fp.multiply32(m.r32(address));
  }
  L006015c3: { // 0x6015c3: d9442414 FLD float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load32(m.r32(address));
  }
  L006015c7: { // 0x6015c7: d88ed4000000 FMUL float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.multiply32(m.r32(address));
  }
  L006015cd: { // 0x6015cd: e87e941600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6297042u); flags=s.arithmetic_flags;
  }
  L006015d2: { // 0x6015d2: d9442418 FLD float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load32(m.r32(address));
  }
  L006015d6: { // 0x6015d6: d88ed4000000 FMUL float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.multiply32(m.r32(address));
  }
  L006015dc: { // 0x6015dc: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L006015de: { // 0x6015de: e86d941600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6297059u); flags=s.arithmetic_flags;
  }
  L006015e3: { // 0x6015e3: d88ed4000000 FMUL float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.multiply32(m.r32(address));
  }
  L006015e9: { // 0x6015e9: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L006015eb: { // 0x6015eb: e860941600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6297072u); flags=s.arithmetic_flags;
  }
  L006015f0: { // 0x6015f0: 8d96f0000000 LEA EDX,[ESI + 0xf0]
    s.dx = (s.si+0x000000f0u);
  }
  L006015f6: { // 0x6015f6: 8a8e1e010000 MOV CL,byte ptr [ESI + 0x11e]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011eu)));
  }
  L006015fc: { // 0x6015fc: 893a MOV dword ptr [EDX],EDI
    m.w32((s.dx), s.di);
  }
  L006015fe: { // 0x6015fe: 895a04 MOV dword ptr [EDX + 0x4],EBX
    m.w32((s.dx+0x00000004u), s.bx);
  }
  L00601601: { // 0x601601: 894208 MOV dword ptr [EDX + 0x8],EAX
    m.w32((s.dx+0x00000008u), s.ax);
  }
  L00601604: { // 0x601604: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L0060160a: { // 0x60160a: 3a88d9020000 CMP CL,byte ptr [EAX + 0x2d9]
    (void)integer::sub((s.cx & 0xffu),m.r8((s.ax+0x000002d9u)),8,flags);
  }
  L00601610: { // 0x601610: 0f8da1000000 JGE 0x006016b7
    if(integer::condition("JGE",flags)) goto L006016b7;
  }
  L00601616: { // 0x601616: 8b4604 MOV EAX,dword ptr [ESI + 0x4]
    s.ax = m.r32((s.si+0x00000004u));
  }
  L00601619: { // 0x601619: 8d7e04 LEA EDI,[ESI + 0x4]
    s.di = (s.si+0x00000004u);
  }
  L0060161c: { // 0x60161c: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0060161d: { // 0x60161d: ff5010 CALL dword ptr [EAX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000010u)),6297120u); flags=s.arithmetic_flags;
  }
  L00601620: { // 0x601620: 8b9698000000 MOV EDX,dword ptr [ESI + 0x98]
    s.dx = m.r32((s.si+0x00000098u));
  }
  L00601626: { // 0x601626: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L00601628: { // 0x601628: 668b8e18010000 MOV CX,word ptr [ESI + 0x118]
    s.cx = with_ax(s.cx, m.r16((s.si+0x00000118u)));
  }
  L0060162f: { // 0x60162f: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L00601631: { // 0x601631: 8b82b0020000 MOV EAX,dword ptr [EDX + 0x2b0]
    s.ax = m.r32((s.dx+0x000002b0u));
  }
  L00601637: { // 0x601637: 57 PUSH EDI
    f.push(m,s.di);
  }
  L00601638: { // 0x601638: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L0060163a: { // 0x60163a: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L0060163c: { // 0x60163c: 03d8 ADD EBX,EAX
    s.bx = integer::add(s.bx,s.ax,32,flags);
  }
  L0060163e: { // 0x60163e: ff5110 CALL dword ptr [ECX + 0x10]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.cx+0x00000010u)),6297153u); flags=s.arithmetic_flags;
  }
  L00601641: { // 0x601641: 0fbe961c010000 MOVSX EDX,byte ptr [ESI + 0x11c]
    s.dx = std::uint32_t(integer::sign_extend(m.r8((s.si+0x0000011cu)),8));
  }
  L00601648: { // 0x601648: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0060164a: { // 0x60164a: 8bc3 MOV EAX,EBX
    s.ax = s.bx;
  }
  L0060164c: { // 0x60164c: 83e101 AND ECX,0x1
    s.cx = integer::logical((s.cx)&(0x00000001u),32,flags);
  }
  L0060164f: { // 0x60164f: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L00601651: { // 0x601651: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L00601652: { // 0x601652: f7f9 IDIV ECX
    const auto numerator=std::int64_t(s32(s.dx))*4294967296ll+std::int64_t(s.ax);
    const auto divisor=integer::sign_extend(s.cx,32);
    if(!divisor||(numerator==std::numeric_limits<std::int64_t>::min()&&divisor==-1)) throw std::domain_error("D33 IDIV fault domain");
    const auto quotient=numerator/divisor,remainder=numerator%divisor;
    if(integer::outside_signed(quotient,32)) throw std::domain_error("D33 IDIV quotient overflow");
    s.ax=std::uint32_t(quotient); s.dx=std::uint32_t(remainder);
  }
  L00601654: { // 0x601654: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L00601656: { // 0x601656: 753d JNZ 0x00601695
    if(integer::condition("JNZ",flags)) goto L00601695;
  }
  L00601658: { // 0x601658: 8a9e1e010000 MOV BL,byte ptr [ESI + 0x11e]
    s.bx = with_al(s.bx, m.r8((s.si+0x0000011eu)));
  }
  L0060165e: { // 0x60165e: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L00601664: { // 0x601664: fec3 INC BL
    s.bx = with_al(s.bx, integer::increment((s.bx & 0xffu),8,flags));
  }
  L00601666: { // 0x601666: 8acb MOV CL,BL
    s.cx = with_al(s.cx, (s.bx & 0xffu));
  }
  L00601668: { // 0x601668: 889e1e010000 MOV byte ptr [ESI + 0x11e],BL
    m.w8((s.si+0x0000011eu), (s.bx & 0xffu));
  }
  L0060166e: { // 0x60166e: 8a90dd020000 MOV DL,byte ptr [EAX + 0x2dd]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000002ddu)));
  }
  L00601674: { // 0x601674: 0fbec9 MOVSX ECX,CL
    s.cx = std::uint32_t(integer::sign_extend((s.cx & 0xffu),8));
  }
  L00601677: { // 0x601677: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L00601679: { // 0x601679: 7507 JNZ 0x00601682
    if(integer::condition("JNZ",flags)) goto L00601682;
  }
  L0060167b: { // 0x60167b: c6861f01000019 MOV byte ptr [ESI + 0x11f],0x19
    m.w8((s.si+0x0000011fu), 0x00000019u);
  }
  L00601682: { // 0x601682: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L00601684: { // 0x601684: 8a90de020000 MOV DL,byte ptr [EAX + 0x2de]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000002deu)));
  }
  L0060168a: { // 0x60168a: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L0060168c: { // 0x60168c: 7507 JNZ 0x00601695
    if(integer::condition("JNZ",flags)) goto L00601695;
  }
  L0060168e: { // 0x60168e: c6861f01000032 MOV byte ptr [ESI + 0x11f],0x32
    m.w8((s.si+0x0000011fu), 0x00000032u);
  }
  L00601695: { // 0x601695: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L0060169b: { // 0x60169b: 8a8e1e010000 MOV CL,byte ptr [ESI + 0x11e]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000011eu)));
  }
  L006016a1: { // 0x6016a1: 3a88d9020000 CMP CL,byte ptr [EAX + 0x2d9]
    (void)integer::sub((s.cx & 0xffu),m.r8((s.ax+0x000002d9u)),8,flags);
  }
  L006016a7: { // 0x6016a7: 750e JNZ 0x006016b7
    if(integer::condition("JNZ",flags)) goto L006016b7;
  }
  L006016a9: { // 0x6016a9: 8a90d8020000 MOV DL,byte ptr [EAX + 0x2d8]
    s.dx = with_al(s.dx, m.r8((s.ax+0x000002d8u)));
  }
  L006016af: { // 0x6016af: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L006016b1: { // 0x6016b1: 0f85aa010000 JNZ 0x00601861
    if(integer::condition("JNZ",flags)) goto L00601861;
  }
  L006016b7: { // 0x6016b7: d986d4000000 FLD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.load32(m.r32(address));
  }
  L006016bd: { // 0x6016bd: d8a0d0020000 FSUB float ptr [EAX + 0x2d0]
    const auto address=(s.ax+0x000002d0u);
    s.fp.subtract32(m.r32(address));
  }
  L006016c3: { // 0x6016c3: 66ff8e1a010000 DEC word ptr [ESI + 0x11a]
    m.w16((s.si+0x0000011au), integer::decrement(m.r16((s.si+0x0000011au)),16,flags));
  }
  L006016ca: { // 0x6016ca: 6683be1a01000000 CMP word ptr [ESI + 0x11a],0x0
    (void)integer::sub(m.r16((s.si+0x0000011au)),0x00000000u,16,flags);
  }
  L006016d2: { // 0x6016d2: d99ed4000000 FSTP float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L006016d8: { // 0x6016d8: 0f858a010000 JNZ 0x00601868
    if(integer::condition("JNZ",flags)) goto L00601868;
  }
  L006016de: { // 0x6016de: 8b90b8020000 MOV EDX,dword ptr [EAX + 0x2b8]
    s.dx = m.r32((s.ax+0x000002b8u));
  }
  L006016e4: { // 0x6016e4: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006016e6: { // 0x6016e6: 0f847c010000 JZ 0x00601868
    if(integer::condition("JZ",flags)) goto L00601868;
  }
  L006016ec: { // 0x6016ec: 3a88dc020000 CMP CL,byte ptr [EAX + 0x2dc]
    (void)integer::sub((s.cx & 0xffu),m.r8((s.ax+0x000002dcu)),8,flags);
  }
  L006016f2: { // 0x6016f2: 0f8f70010000 JG 0x00601868
    if(integer::condition("JG",flags)) goto L00601868;
  }
  L006016f8: { // 0x6016f8: 668b80ac020000 MOV AX,word ptr [EAX + 0x2ac]
    s.ax = with_ax(s.ax, m.r16((s.ax+0x000002acu)));
  }
  L006016ff: { // 0x6016ff: 8dbe88000000 LEA EDI,[ESI + 0x88]
    s.di = (s.si+0x00000088u);
  }
  L00601705: { // 0x601705: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00601707: { // 0x601707: 6689861a010000 MOV word ptr [ESI + 0x11a],AX
    m.w16((s.si+0x0000011au), (s.ax & 0xffffu));
  }
  L0060170e: { // 0x60170e: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L00601710: { // 0x601710: 89542414 MOV dword ptr [ESP + 0x14],EDX
    m.w32((f.sp+0x00000014u), s.dx);
  }
  L00601714: { // 0x601714: 8d542414 LEA EDX,[ESP + 0x14]
    s.dx = (f.sp+0x00000014u);
  }
  L00601718: { // 0x601718: 8b4104 MOV EAX,dword ptr [ECX + 0x4]
    s.ax = m.r32((s.cx+0x00000004u));
  }
  L0060171b: { // 0x60171b: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060171c: { // 0x60171c: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00601720: { // 0x601720: 8b4908 MOV ECX,dword ptr [ECX + 0x8]
    s.cx = m.r32((s.cx+0x00000008u));
  }
  L00601723: { // 0x601723: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00601727: { // 0x601727: b920a88100 MOV ECX,0x81a820
    s.cx = 0x0081a820u;
  }
  L0060172c: { // 0x60172c: e85f3df4ff CALL 0x00545490
    s.arithmetic_flags=flags; invoke(m,s,f,0x00545490u,6297393u); flags=s.arithmetic_flags;
  }
  L00601731: { // 0x601731: 8b8840010000 MOV ECX,dword ptr [EAX + 0x140]
    s.cx = m.r32((s.ax+0x00000140u));
  }
  L00601737: { // 0x601737: f6c501 TEST CH,0x1
    (void)integer::logical((((s.cx >> 8) & 0xffu))&(0x00000001u),8,flags);
  }
  L0060173a: { // 0x60173a: 742d JZ 0x00601769
    if(integer::condition("JZ",flags)) goto L00601769;
  }
  L0060173c: { // 0x60173c: 8b0f MOV ECX,dword ptr [EDI]
    s.cx = m.r32((s.di));
  }
  L0060173e: { // 0x60173e: 8b5704 MOV EDX,dword ptr [EDI + 0x4]
    s.dx = m.r32((s.di+0x00000004u));
  }
  L00601741: { // 0x601741: 894c2420 MOV dword ptr [ESP + 0x20],ECX
    m.w32((f.sp+0x00000020u), s.cx);
  }
  L00601745: { // 0x601745: 8b7f08 MOV EDI,dword ptr [EDI + 0x8]
    s.di = m.r32((s.di+0x00000008u));
  }
  L00601748: { // 0x601748: 0fbe881b010000 MOVSX ECX,byte ptr [EAX + 0x11b]
    s.cx = std::uint32_t(integer::sign_extend(m.r8((s.ax+0x0000011bu)),8));
  }
  L0060174f: { // 0x60174f: 83c104 ADD ECX,0x4
    s.cx = integer::add(s.cx,0x00000004u,32,flags);
  }
  L00601752: { // 0x601752: 89542424 MOV dword ptr [ESP + 0x24],EDX
    m.w32((f.sp+0x00000024u), s.dx);
  }
  L00601756: { // 0x601756: 0faf0d80e0a500 IMUL ECX,dword ptr [0x00a5e080]
    s.cx = integer::imul(s.cx,m.r32((0x00a5e080u)),32,flags);
  }
  L0060175d: { // 0x60175d: 3bf9 CMP EDI,ECX
    (void)integer::sub(s.di,s.cx,32,flags);
  }
  L0060175f: { // 0x60175f: 7c08 JL 0x00601769
    if(integer::condition("JL",flags)) goto L00601769;
  }
  L00601761: { // 0x601761: 8bb8e8000000 MOV EDI,dword ptr [EAX + 0xe8]
    s.di = m.r32((s.ax+0x000000e8u));
  }
  L00601767: { // 0x601767: eb06 JMP 0x0060176f
    goto L0060176f;
  }
  L00601769: { // 0x601769: 8bb8e4000000 MOV EDI,dword ptr [EAX + 0xe4]
    s.di = m.r32((s.ax+0x000000e4u));
  }
  L0060176f: { // 0x60176f: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00601771: { // 0x601771: 0f84f1000000 JZ 0x00601868
    if(integer::condition("JZ",flags)) goto L00601868;
  }
  L00601777: { // 0x601777: 8d9788000000 LEA EDX,[EDI + 0x88]
    s.dx = (s.di+0x00000088u);
  }
  L0060177d: { // 0x60177d: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0060177f: { // 0x60177f: 8b1a MOV EBX,dword ptr [EDX]
    s.bx = m.r32((s.dx));
  }
  L00601781: { // 0x601781: 8b6a04 MOV EBP,dword ptr [EDX + 0x4]
    s.bp = m.r32((s.dx+0x00000004u));
  }
  L00601784: { // 0x601784: 8b4208 MOV EAX,dword ptr [EDX + 0x8]
    s.ax = m.r32((s.dx+0x00000008u));
  }
  L00601787: { // 0x601787: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00601789: { // 0x601789: 89442428 MOV dword ptr [ESP + 0x28],EAX
    m.w32((f.sp+0x00000028u), s.ax);
  }
  L0060178d: { // 0x60178d: 8d44242c LEA EAX,[ESP + 0x2c]
    s.ax = (f.sp+0x0000002cu);
  }
  L00601791: { // 0x601791: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00601792: { // 0x601792: ff5248 CALL dword ptr [EDX + 0x48]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000048u)),6297493u); flags=s.arithmetic_flags;
  }
  L00601795: { // 0x601795: 8b08 MOV ECX,dword ptr [EAX]
    s.cx = m.r32((s.ax));
  }
  L00601797: { // 0x601797: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L0060179a: { // 0x60179a: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L0060179d: { // 0x60179d: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0060179f: { // 0x60179f: 894c2414 MOV dword ptr [ESP + 0x14],ECX
    m.w32((f.sp+0x00000014u), s.cx);
  }
  L006017a3: { // 0x6017a3: 8b4c2428 MOV ECX,dword ptr [ESP + 0x28]
    s.cx = m.r32((f.sp+0x00000028u));
  }
  L006017a7: { // 0x6017a7: 2bd5 SUB EDX,EBP
    s.dx = integer::sub(s.dx,s.bp,32,flags);
  }
  L006017a9: { // 0x6017a9: 2bc1 SUB EAX,ECX
    s.ax = integer::sub(s.ax,s.cx,32,flags);
  }
  L006017ab: { // 0x6017ab: 89542418 MOV dword ptr [ESP + 0x18],EDX
    m.w32((f.sp+0x00000018u), s.dx);
  }
  L006017af: { // 0x6017af: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L006017b3: { // 0x6017b3: db442418 FILD dword ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    s.fp.load_integer32(m.r32(address));
  }
  L006017b7: { // 0x6017b7: db44241c FILD dword ptr [ESP + 0x1c]
    const auto address=(f.sp+0x0000001cu);
    s.fp.load_integer32(m.r32(address));
  }
  L006017bb: { // 0x6017bb: db442414 FILD dword ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    s.fp.load_integer32(m.r32(address));
  }
  L006017bf: { // 0x6017bf: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L006017c2: { // 0x6017c2: d9c0 FLD ST0
    numeric_b88::detail::reg<0xd9c0>(s.fp);
  }
  L006017c4: { // 0x6017c4: d8c9 FMUL ST1
    numeric_b88::detail::reg<0xd8c9>(s.fp);
  }
  L006017c6: { // 0x6017c6: d9c2 FLD ST2
    numeric_b88::detail::reg<0xd9c2>(s.fp);
  }
  L006017c8: { // 0x6017c8: d8cb FMUL ST3
    numeric_b88::detail::reg<0xd8cb>(s.fp);
  }
  L006017ca: { // 0x6017ca: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006017cc: { // 0x6017cc: d9c3 FLD ST3
    numeric_b88::detail::reg<0xd9c3>(s.fp);
  }
  L006017ce: { // 0x6017ce: d8cc FMUL ST4
    numeric_b88::detail::reg<0xd8cc>(s.fp);
  }
  L006017d0: { // 0x6017d0: dec1 FADDP
    numeric_b88::detail::reg<0xdec1>(s.fp);
  }
  L006017d2: { // 0x6017d2: dd1c24 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L006017d5: { // 0x6017d5: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006017d7: { // 0x6017d7: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006017d9: { // 0x6017d9: ddd8 FSTP ST0
    numeric_b88::detail::reg<0xddd8>(s.fp);
  }
  L006017db: { // 0x6017db: e8a088ebff CALL 0x004ba080
    s.arithmetic_flags=flags; invoke(m,s,f,0x004ba080u,6297568u); flags=s.arithmetic_flags;
  }
  L006017e0: { // 0x6017e0: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L006017e3: { // 0x6017e3: e868921600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6297576u); flags=s.arithmetic_flags;
  }
  L006017e8: { // 0x6017e8: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L006017ea: { // 0x6017ea: 8b8698000000 MOV EAX,dword ptr [ESI + 0x98]
    s.ax = m.r32((s.si+0x00000098u));
  }
  L006017f0: { // 0x6017f0: 8b90b8020000 MOV EDX,dword ptr [EAX + 0x2b8]
    s.dx = m.r32((s.ax+0x000002b8u));
  }
  L006017f6: { // 0x6017f6: 89542410 MOV dword ptr [ESP + 0x10],EDX
    m.w32((f.sp+0x00000010u), s.dx);
  }
  L006017fa: { // 0x6017fa: 8b576c MOV EDX,dword ptr [EDI + 0x6c]
    s.dx = m.r32((s.di+0x0000006cu));
  }
  L006017fd: { // 0x6017fd: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L006017ff: { // 0x6017ff: 7e43 JLE 0x00601844
    if(integer::condition("JLE",flags)) goto L00601844;
  }
  L00601801: { // 0x601801: 8a577d MOV DL,byte ptr [EDI + 0x7d]
    s.dx = with_al(s.dx, m.r8((s.di+0x0000007du)));
  }
  L00601804: { // 0x601804: 84d2 TEST DL,DL
    (void)integer::logical(((s.dx & 0xffu))&((s.dx & 0xffu)),8,flags);
  }
  L00601806: { // 0x601806: 743c JZ 0x00601844
    if(integer::condition("JZ",flags)) goto L00601844;
  }
  L00601808: { // 0x601808: 8b9614010000 MOV EDX,dword ptr [ESI + 0x114]
    s.dx = m.r32((s.si+0x00000114u));
  }
  L0060180e: { // 0x60180e: 3bbacc000000 CMP EDI,dword ptr [EDX + 0xcc]
    (void)integer::sub(s.di,m.r32((s.dx+0x000000ccu)),32,flags);
  }
  L00601814: { // 0x601814: 742e JZ 0x00601844
    if(integer::condition("JZ",flags)) goto L00601844;
  }
  L00601816: { // 0x601816: 8b80b4020000 MOV EAX,dword ptr [EAX + 0x2b4]
    s.ax = m.r32((s.ax+0x000002b4u));
  }
  L0060181c: { // 0x60181c: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0060181e: { // 0x60181e: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00601820: { // 0x601820: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00601822: { // 0x601822: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00601823: { // 0x601823: b867666666 MOV EAX,0x66666667
    s.ax = 0x66666667u;
  }
  L00601828: { // 0x601828: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0060182a: { // 0x60182a: c1fa02 SAR EDX,0x2
    s.dx = integer::shift(s.dx,0x00000002u,32,flags,integer::Shift::arithmetic_right);
  }
  L0060182d: { // 0x60182d: 8b1f MOV EBX,dword ptr [EDI]
    s.bx = m.r32((s.di));
  }
  L0060182f: { // 0x60182f: 8bca MOV ECX,EDX
    s.cx = s.dx;
  }
  L00601831: { // 0x601831: c1e91f SHR ECX,0x1f
    s.cx = integer::shift(s.cx,0x0000001fu,32,flags,integer::Shift::right);
  }
  L00601834: { // 0x601834: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L00601836: { // 0x601836: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L00601838: { // 0x601838: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L00601839: { // 0x601839: 8d542424 LEA EDX,[ESP + 0x24]
    s.dx = (f.sp+0x00000024u);
  }
  L0060183d: { // 0x60183d: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L0060183e: { // 0x60183e: ff9358010000 CALL dword ptr [EBX + 0x158]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.bx+0x00000158u)),6297668u); flags=s.arithmetic_flags;
  }
  L00601844: { // 0x601844: 8b7f30 MOV EDI,dword ptr [EDI + 0x30]
    s.di = m.r32((s.di+0x00000030u));
  }
  L00601847: { // 0x601847: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L00601849: { // 0x601849: 0f8528ffffff JNZ 0x00601777
    if(integer::condition("JNZ",flags)) goto L00601777;
  }
  L0060184f: { // 0x60184f: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00601850: { // 0x601850: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00601851: { // 0x601851: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00601852: { // 0x601852: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L00601853: { // 0x601853: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L00601855: { // 0x601855: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L00601856: { // 0x601856: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00601857: { // 0x601857: c786d400000000000000 MOV dword ptr [ESI + 0xd4],0x0
    m.w32((s.si+0x000000d4u), 0x00000000u);
  }
  L00601861: { // 0x601861: c6862101000001 MOV byte ptr [ESI + 0x121],0x1
    m.w8((s.si+0x00000121u), 0x00000001u);
  }
  L00601868: { // 0x601868: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L00601869: { // 0x601869: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0060186a: { // 0x60186a: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060186b: { // 0x60186b: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0060186c: { // 0x60186c: 8be5 MOV ESP,EBP
    f.sp = s.bp;
  }
  L0060186e: { // 0x60186e: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0060186f: { // 0x60186f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
