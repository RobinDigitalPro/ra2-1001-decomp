#include "recovered/recovery_b630_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b630 {
namespace {
void f_0000ff10(Memory&,State&,Frame&,const Operations&);
void f_00022ec0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0000ff10(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0040ff10: { // 0x40ff10: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0040ff12: { // 0x40ff12: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L0040ff14: { // 0x40ff14: c74008445e7800 MOV dword ptr [EAX + 0x8],0x785e44
    m.w32((s.ax+0x00000008u), 0x00785e44u);
  }
  L0040ff1b: { // 0x40ff1b: c7400c3c5e7800 MOV dword ptr [EAX + 0xc],0x785e3c
    m.w32((s.ax+0x0000000cu), 0x00785e3cu);
  }
  L0040ff22: { // 0x40ff22: 894818 MOV dword ptr [EAX + 0x18],ECX
    m.w32((s.ax+0x00000018u), s.cx);
  }
  L0040ff25: { // 0x40ff25: 89481c MOV dword ptr [EAX + 0x1c],ECX
    m.w32((s.ax+0x0000001cu), s.cx);
  }
  L0040ff28: { // 0x40ff28: 884820 MOV byte ptr [EAX + 0x20],CL
    m.w8((s.ax+0x00000020u), (s.cx & 0xffu));
  }
  L0040ff2b: { // 0x40ff2b: 8a4814 MOV CL,byte ptr [EAX + 0x14]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00000014u)));
  }
  L0040ff2e: { // 0x40ff2e: 80e1f8 AND CL,0xf8
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))&(0x000000f8u),8,flags));
  }
  L0040ff31: { // 0x40ff31: c74010ffffffff MOV dword ptr [EAX + 0x10],0xffffffff
    m.w32((s.ax+0x00000010u), 0xffffffffu);
  }
  L0040ff38: { // 0x40ff38: c700d85d7800 MOV dword ptr [EAX],0x785dd8
    m.w32((s.ax), 0x00785dd8u);
  }
  L0040ff3e: { // 0x40ff3e: c74004bc5d7800 MOV dword ptr [EAX + 0x4],0x785dbc
    m.w32((s.ax+0x00000004u), 0x00785dbcu);
  }
  L0040ff45: { // 0x40ff45: c74008b45d7800 MOV dword ptr [EAX + 0x8],0x785db4
    m.w32((s.ax+0x00000008u), 0x00785db4u);
  }
  L0040ff4c: { // 0x40ff4c: c7400cac5d7800 MOV dword ptr [EAX + 0xc],0x785dac
    m.w32((s.ax+0x0000000cu), 0x00785dacu);
  }
  L0040ff53: { // 0x40ff53: 884814 MOV byte ptr [EAX + 0x14],CL
    m.w8((s.ax+0x00000014u), (s.cx & 0xffu));
  }
  L0040ff56: { // 0x40ff56: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_00022ec0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00422ec0: { // 0x422ec0: 8b81b0000000 MOV EAX, dword ptr [ECX + 0xb0]
    s.ax = m.r32((s.cx+0x000000b0u));
  }
  L00422ec6: { // 0x422ec6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 4259600u:f_0000ff10(m,s,child,{});break;
case 4337344u:f_00022ec0(m,s,child,{});break;
default:throw std::domain_error("recovery630 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0041ebe0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0041ebe0: { // 0x41ebe0: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0041ebe1: { // 0x41ebe1: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0041ebe2: { // 0x41ebe2: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0041ebe3: { // 0x41ebe3: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0041ebe5: { // 0x41ebe5: e82613ffff CALL 0x0040ff10
    s.arithmetic_flags=flags; invoke(m,s,f,0x0040ff10u,4320234u); flags=s.arithmetic_flags;
  }
  L0041ebea: { // 0x41ebea: 8b4c2410 MOV ECX,dword ptr [ESP + 0x10]
    s.cx = m.r32((f.sp+0x00000010u));
  }
  L0041ebee: { // 0x41ebee: c7463800000000 MOV dword ptr [ESI + 0x38],0x0
    m.w32((s.si+0x00000038u), 0x00000000u);
  }
  L0041ebf5: { // 0x41ebf5: 894e24 MOV dword ptr [ESI + 0x24],ECX
    m.w32((s.si+0x00000024u), s.cx);
  }
  L0041ebf8: { // 0x41ebf8: c6463c00 MOV byte ptr [ESI + 0x3c],0x0
    m.w8((s.si+0x0000003cu), 0x00000000u);
  }
  L0041ebfc: { // 0x41ebfc: c706d46f7800 MOV dword ptr [ESI],0x786fd4
    m.w32((s.si), 0x00786fd4u);
  }
  L0041ec02: { // 0x41ec02: c74604b86f7800 MOV dword ptr [ESI + 0x4],0x786fb8
    m.w32((s.si+0x00000004u), 0x00786fb8u);
  }
  L0041ec09: { // 0x41ec09: c74608b06f7800 MOV dword ptr [ESI + 0x8],0x786fb0
    m.w32((s.si+0x00000008u), 0x00786fb0u);
  }
  L0041ec10: { // 0x41ec10: c7460ca86f7800 MOV dword ptr [ESI + 0xc],0x786fa8
    m.w32((s.si+0x0000000cu), 0x00786fa8u);
  }
  L0041ec17: { // 0x41ec17: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L0041ec19: { // 0x41ec19: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),4320287u); flags=s.arithmetic_flags;
  }
  L0041ec1f: { // 0x41ec1f: 8b80ac000000 MOV EAX,dword ptr [EAX + 0xac]
    s.ax = m.r32((s.ax+0x000000acu));
  }
  L0041ec25: { // 0x41ec25: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L0041ec29: { // 0x41ec29: 8b542418 MOV EDX,dword ptr [ESP + 0x18]
    s.dx = m.r32((f.sp+0x00000018u));
  }
  L0041ec2d: { // 0x41ec2d: 894638 MOV dword ptr [ESI + 0x38],EAX
    m.w32((s.si+0x00000038u), s.ax);
  }
  L0041ec30: { // 0x41ec30: 0fbf7802 MOVSX EDI,word ptr [EAX + 0x2]
    s.di = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000002u)),16));
  }
  L0041ec34: { // 0x41ec34: 0fbf4004 MOVSX EAX,word ptr [EAX + 0x4]
    s.ax = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000004u)),16));
  }
  L0041ec38: { // 0x41ec38: 8d6e28 LEA EBP,[ESI + 0x28]
    s.bp = (s.si+0x00000028u);
  }
  L0041ec3b: { // 0x41ec3b: 894e28 MOV dword ptr [ESI + 0x28],ECX
    m.w32((s.si+0x00000028u), s.cx);
  }
  L0041ec3e: { // 0x41ec3e: 895504 MOV dword ptr [EBP + 0x4],EDX
    m.w32((s.bp+0x00000004u), s.dx);
  }
  L0041ec41: { // 0x41ec41: 897d08 MOV dword ptr [EBP + 0x8],EDI
    m.w32((s.bp+0x00000008u), s.di);
  }
  L0041ec44: { // 0x41ec44: 89450c MOV dword ptr [EBP + 0xc],EAX
    m.w32((s.bp+0x0000000cu), s.ax);
  }
  L0041ec47: { // 0x41ec47: a198498200 MOV EAX,[0x00824998]
    s.ax = m.r32((0x00824998u));
  }
  L0041ec4c: { // 0x41ec4c: 3905a0498200 CMP dword ptr [0x008249a0],EAX
    (void)integer::sub(m.r32((0x008249a0u)),s.ax,32,flags);
  }
  L0041ec52: { // 0x41ec52: 7c2f JL 0x0041ec83
    if(integer::condition("JL",flags)) goto L0041ec83;
  }
  L0041ec54: { // 0x41ec54: 8a0d9d498200 MOV CL,byte ptr [0x0082499d]
    s.cx = with_al(s.cx, m.r8((0x0082499du)));
  }
  L0041ec5a: { // 0x41ec5a: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0041ec5c: { // 0x41ec5c: 7504 JNZ 0x0041ec62
    if(integer::condition("JNZ",flags)) goto L0041ec62;
  }
  L0041ec5e: { // 0x41ec5e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041ec60: { // 0x41ec60: 7539 JNZ 0x0041ec9b
    if(integer::condition("JNZ",flags)) goto L0041ec9b;
  }
  L0041ec62: { // 0x41ec62: 8b0da4498200 MOV ECX,dword ptr [0x008249a4]
    s.cx = m.r32((0x008249a4u));
  }
  L0041ec68: { // 0x41ec68: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0041ec6a: { // 0x41ec6a: 7e2f JLE 0x0041ec9b
    if(integer::condition("JLE",flags)) goto L0041ec9b;
  }
  L0041ec6c: { // 0x41ec6c: 8b1590498200 MOV EDX,dword ptr [0x00824990]
    s.dx = m.r32((0x00824990u));
  }
  L0041ec72: { // 0x41ec72: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0041ec74: { // 0x41ec74: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041ec76: { // 0x41ec76: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041ec77: { // 0x41ec77: b990498200 MOV ECX,0x824990
    s.cx = 0x00824990u;
  }
  L0041ec7c: { // 0x41ec7c: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4320383u); flags=s.arithmetic_flags;
  }
  L0041ec7f: { // 0x41ec7f: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ec81: { // 0x41ec81: 7418 JZ 0x0041ec9b
    if(integer::condition("JZ",flags)) goto L0041ec9b;
  }
  L0041ec83: { // 0x41ec83: 8b0da0498200 MOV ECX,dword ptr [0x008249a0]
    s.cx = m.r32((0x008249a0u));
  }
  L0041ec89: { // 0x41ec89: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041ec8b: { // 0x41ec8b: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0041ec8c: { // 0x41ec8c: 890da0498200 MOV dword ptr [0x008249a0],ECX
    m.w32((0x008249a0u), s.cx);
  }
  L0041ec92: { // 0x41ec92: 8b0d94498200 MOV ECX,dword ptr [0x00824994]
    s.cx = m.r32((0x00824994u));
  }
  L0041ec98: { // 0x41ec98: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L0041ec9b: { // 0x41ec9b: a17088aa00 MOV EAX,[0x00aa8870]
    s.ax = m.r32((0x00aa8870u));
  }
  L0041eca0: { // 0x41eca0: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L0041eca6: { // 0x41eca6: 3bc8 CMP ECX,EAX
    (void)integer::sub(s.cx,s.ax,32,flags);
  }
  L0041eca8: { // 0x41eca8: 7c2f JL 0x0041ecd9
    if(integer::condition("JL",flags)) goto L0041ecd9;
  }
  L0041ecaa: { // 0x41ecaa: 8a0d7588aa00 MOV CL,byte ptr [0x00aa8875]
    s.cx = with_al(s.cx, m.r8((0x00aa8875u)));
  }
  L0041ecb0: { // 0x41ecb0: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0041ecb2: { // 0x41ecb2: 7504 JNZ 0x0041ecb8
    if(integer::condition("JNZ",flags)) goto L0041ecb8;
  }
  L0041ecb4: { // 0x41ecb4: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L0041ecb6: { // 0x41ecb6: 7539 JNZ 0x0041ecf1
    if(integer::condition("JNZ",flags)) goto L0041ecf1;
  }
  L0041ecb8: { // 0x41ecb8: 8b0d7c88aa00 MOV ECX,dword ptr [0x00aa887c]
    s.cx = m.r32((0x00aa887cu));
  }
  L0041ecbe: { // 0x41ecbe: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0041ecc0: { // 0x41ecc0: 7e2f JLE 0x0041ecf1
    if(integer::condition("JLE",flags)) goto L0041ecf1;
  }
  L0041ecc2: { // 0x41ecc2: 8b156888aa00 MOV EDX,dword ptr [0x00aa8868]
    s.dx = m.r32((0x00aa8868u));
  }
  L0041ecc8: { // 0x41ecc8: 03c8 ADD ECX,EAX
    s.cx = integer::add(s.cx,s.ax,32,flags);
  }
  L0041ecca: { // 0x41ecca: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L0041eccc: { // 0x41eccc: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L0041eccd: { // 0x41eccd: b96888aa00 MOV ECX,0xaa8868
    s.cx = 0x00aa8868u;
  }
  L0041ecd2: { // 0x41ecd2: ff5208 CALL dword ptr [EDX + 0x8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x00000008u)),4320469u); flags=s.arithmetic_flags;
  }
  L0041ecd5: { // 0x41ecd5: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ecd7: { // 0x41ecd7: 7418 JZ 0x0041ecf1
    if(integer::condition("JZ",flags)) goto L0041ecf1;
  }
  L0041ecd9: { // 0x41ecd9: 8b0d7888aa00 MOV ECX,dword ptr [0x00aa8878]
    s.cx = m.r32((0x00aa8878u));
  }
  L0041ecdf: { // 0x41ecdf: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0041ece1: { // 0x41ece1: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0041ece2: { // 0x41ece2: 890d7888aa00 MOV dword ptr [0x00aa8878],ECX
    m.w32((0x00aa8878u), s.cx);
  }
  L0041ece8: { // 0x41ece8: 8b0d6c88aa00 MOV ECX,dword ptr [0x00aa886c]
    s.cx = m.r32((0x00aa886cu));
  }
  L0041ecee: { // 0x41ecee: 893481 MOV dword ptr [ECX + EAX*0x4],ESI
    m.w32((s.cx+(s.ax * 0x00000004u)), s.si);
  }
  L0041ecf1: { // 0x41ecf1: a0cc498300 MOV AL,[0x008349cc]
    s.ax = with_al(s.ax, m.r8((0x008349ccu)));
  }
  L0041ecf6: { // 0x41ecf6: 84c0 TEST AL,AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L0041ecf8: { // 0x41ecf8: 756d JNZ 0x0041ed67
    if(integer::condition("JNZ",flags)) goto L0041ed67;
  }
  L0041ecfa: { // 0x41ecfa: c605cc49830001 MOV byte ptr [0x008349cc],0x1
    m.w8((0x008349ccu), 0x00000001u);
  }
  L0041ed01: { // 0x41ed01: 33ff XOR EDI,EDI
    s.di = integer::logical((s.di)^(s.di),32,flags);
  }
  L0041ed03: { // 0x41ed03: 8bcf MOV ECX,EDI
    s.cx = s.di;
  }
  L0041ed05: { // 0x41ed05: 81e1ff000080 AND ECX,0x800000ff
    s.cx = integer::logical((s.cx)&(0x800000ffu),32,flags);
  }
  L0041ed0b: { // 0x41ed0b: 7908 JNS 0x0041ed15
    if(integer::condition("JNS",flags)) goto L0041ed15;
  }
  L0041ed0d: { // 0x41ed0d: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0041ed0e: { // 0x41ed0e: 81c900ffffff OR ECX,0xffffff00
    s.cx = integer::logical((s.cx)|(0xffffff00u),32,flags);
  }
  L0041ed14: { // 0x41ed14: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0041ed15: { // 0x41ed15: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0041ed17: { // 0x41ed17: 99 CDQ
    s.dx=s32(s.ax)<0?0xffffffffu:0u;
  }
  L0041ed18: { // 0x41ed18: 81e2ff000000 AND EDX,0xff
    s.dx = integer::logical((s.dx)&(0x000000ffu),32,flags);
  }
  L0041ed1e: { // 0x41ed1e: 03c2 ADD EAX,EDX
    s.ax = integer::add(s.ax,s.dx,32,flags);
  }
  L0041ed20: { // 0x41ed20: c1f808 SAR EAX,0x8
    s.ax = integer::shift(s.ax,0x00000008u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041ed23: { // 0x41ed23: 0fafc1 IMUL EAX,ECX
    s.ax = integer::imul(s.ax,s.cx,32,flags);
  }
  L0041ed26: { // 0x41ed26: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0041ed28: { // 0x41ed28: b809040281 MOV EAX,0x81020409
    s.ax = 0x81020409u;
  }
  L0041ed2d: { // 0x41ed2d: f7e9 IMUL ECX
    const auto product=integer::sign_extend(s.ax,32)*integer::sign_extend(s.cx,32);
    s.ax=std::uint32_t(product); s.dx=std::uint32_t(std::uint64_t(product)>>32);
    flags=(flags&~(integer::CF|integer::OF))|(integer::outside_signed(product,32)?integer::CF|integer::OF:0);
  }
  L0041ed2f: { // 0x41ed2f: 03d1 ADD EDX,ECX
    s.dx = integer::add(s.dx,s.cx,32,flags);
  }
  L0041ed31: { // 0x41ed31: c1fa06 SAR EDX,0x6
    s.dx = integer::shift(s.dx,0x00000006u,32,flags,integer::Shift::arithmetic_right);
  }
  L0041ed34: { // 0x41ed34: 8bc2 MOV EAX,EDX
    s.ax = s.dx;
  }
  L0041ed36: { // 0x41ed36: c1e81f SHR EAX,0x1f
    s.ax = integer::shift(s.ax,0x0000001fu,32,flags,integer::Shift::right);
  }
  L0041ed39: { // 0x41ed39: 03d0 ADD EDX,EAX
    s.dx = integer::add(s.dx,s.ax,32,flags);
  }
  L0041ed3b: { // 0x41ed3b: 81faff000000 CMP EDX,0xff
    (void)integer::sub(s.dx,0x000000ffu,32,flags);
  }
  L0041ed41: { // 0x41ed41: 7f10 JG 0x0041ed53
    if(integer::condition("JG",flags)) goto L0041ed53;
  }
  L0041ed43: { // 0x41ed43: 85d2 TEST EDX,EDX
    (void)integer::logical((s.dx)&(s.dx),32,flags);
  }
  L0041ed45: { // 0x41ed45: 7d04 JGE 0x0041ed4b
    if(integer::condition("JGE",flags)) goto L0041ed4b;
  }
  L0041ed47: { // 0x41ed47: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L0041ed49: { // 0x41ed49: eb0d JMP 0x0041ed58
    goto L0041ed58;
  }
  L0041ed4b: { // 0x41ed4b: 81faff000000 CMP EDX,0xff
    (void)integer::sub(s.dx,0x000000ffu,32,flags);
  }
  L0041ed51: { // 0x41ed51: 7e05 JLE 0x0041ed58
    if(integer::condition("JLE",flags)) goto L0041ed58;
  }
  L0041ed53: { // 0x41ed53: baff000000 MOV EDX,0xff
    s.dx = 0x000000ffu;
  }
  L0041ed58: { // 0x41ed58: 8897b8498200 MOV byte ptr [EDI + 0x8249b8],DL
    m.w8((s.di+0x008249b8u), (s.dx & 0xffu));
  }
  L0041ed5e: { // 0x41ed5e: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0041ed5f: { // 0x41ed5f: 81ff00000100 CMP EDI,0x10000
    (void)integer::sub(s.di,0x00010000u,32,flags);
  }
  L0041ed65: { // 0x41ed65: 7c9c JL 0x0041ed03
    if(integer::condition("JL",flags)) goto L0041ed03;
  }
  L0041ed67: { // 0x41ed67: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0041ed69: { // 0x41ed69: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0041ed6a: { // 0x41ed6a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0041ed6b: { // 0x41ed6b: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0041ed6c: { // 0x41ed6c: c20c00 RET 0xc
    s.arithmetic_flags=flags; finish(m,s,f,12u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
