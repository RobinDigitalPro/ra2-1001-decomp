#include "recovered/recovery_b818_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b818 {
namespace {
void f_0022fe40(Memory&,State&,Frame&,const Operations&);
void f_0036aa50(Memory&,State&,Frame&,const Operations&);
void f_001cd850(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_0022fe40(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0062fe40: { // 0x62fe40: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L0062fe44: { // 0x62fe44: 8bd1 MOV EDX,ECX
    s.dx = s.cx;
  }
  L0062fe46: { // 0x62fe46: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L0062fe4a: { // 0x62fe4a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L0062fe4b: { // 0x62fe4b: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0062fe4d: { // 0x62fe4d: 8bd8 MOV EBX,EAX
    s.bx = s.ax;
  }
  L0062fe4f: { // 0x62fe4f: 0f8494000000 JZ 0x0062fee9
    if(integer::condition("JZ",flags)) goto L0062fee9;
  }
  L0062fe55: { // 0x62fe55: 7e04 JLE 0x0062fe5b
    if(integer::condition("JLE",flags)) goto L0062fe5b;
  }
  L0062fe57: { // 0x62fe57: 8bd9 MOV EBX,ECX
    s.bx = s.cx;
  }
  L0062fe59: { // 0x62fe59: 8bc8 MOV ECX,EAX
    s.cx = s.ax;
  }
  L0062fe5b: { // 0x62fe5b: 55 PUSH EBP
    f.push(m,s.bp);
  }
  L0062fe5c: { // 0x62fe5c: 2bcb SUB ECX,EBX
    s.cx = integer::sub(s.cx,s.bx,32,flags);
  }
  L0062fe5e: { // 0x62fe5e: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0062fe5f: { // 0x62fe5f: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0062fe61: { // 0x62fe61: f7c700000080 TEST EDI,0x80000000
    (void)integer::logical((s.di)&(0x80000000u),32,flags);
  }
  L0062fe67: { // 0x62fe67: b91f000000 MOV ECX,0x1f
    s.cx = 0x0000001fu;
  }
  L0062fe6c: { // 0x62fe6c: 7510 JNZ 0x0062fe7e
    if(integer::condition("JNZ",flags)) goto L0062fe7e;
  }
  L0062fe6e: { // 0x62fe6e: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0062fe70: { // 0x62fe70: 7e0c JLE 0x0062fe7e
    if(integer::condition("JLE",flags)) goto L0062fe7e;
  }
  L0062fe72: { // 0x62fe72: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0062fe73: { // 0x62fe73: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0062fe78: { // 0x62fe78: d3e0 SHL EAX,CL
    s.ax = integer::shift(s.ax,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe7a: { // 0x62fe7a: 85c7 TEST EDI,EAX
    (void)integer::logical((s.di)&(s.ax),32,flags);
  }
  L0062fe7c: { // 0x62fe7c: 74f0 JZ 0x0062fe6e
    if(integer::condition("JZ",flags)) goto L0062fe6e;
  }
  L0062fe7e: { // 0x62fe7e: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062fe7f: { // 0x62fe7f: 83cdff OR EBP,0xffffffff
    s.bp = integer::logical((s.bp)|(0xffffffffu),32,flags);
  }
  L0062fe82: { // 0x62fe82: d3e5 SHL EBP,CL
    s.bp = integer::shift(s.bp,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L0062fe84: { // 0x62fe84: 8d4701 LEA EAX,[EDI + 0x1]
    s.ax = (s.di+0x00000001u);
  }
  L0062fe87: { // 0x62fe87: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fe89: { // 0x62fe89: f7d5 NOT EBP
    s.bp = (~(s.bp)&integer::mask(32));
  }
  L0062fe8b: { // 0x62fe8b: 7e58 JLE 0x0062fee5
    if(integer::condition("JLE",flags)) goto L0062fee5;
  }
  L0062fe8d: { // 0x62fe8d: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0062fe8e: { // 0x62fe8e: 803a00 CMP byte ptr [EDX],0x0
    (void)integer::sub(m.r8((s.dx)),0x00000000u,8,flags);
  }
  L0062fe91: { // 0x62fe91: 7404 JZ 0x0062fe97
    if(integer::condition("JZ",flags)) goto L0062fe97;
  }
  L0062fe93: { // 0x62fe93: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0062fe95: { // 0x62fe95: eb47 JMP 0x0062fede
    goto L0062fede;
  }
  L0062fe97: { // 0x62fe97: 8b4a04 MOV ECX,dword ptr [EDX + 0x4]
    s.cx = m.r32((s.dx+0x00000004u));
  }
  L0062fe9a: { // 0x62fe9a: 8b748a0c MOV ESI,dword ptr [EDX + ECX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fe9e: { // 0x62fe9e: 8d448a0c LEA EAX,[EDX + ECX*0x4 + 0xc]
    s.ax = (s.dx+(s.cx * 0x00000004u)+0x0000000cu);
  }
  L0062fea2: { // 0x62fea2: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062fea5: { // 0x62fea5: 8b4c8a0c MOV ECX,dword ptr [EDX + ECX*0x4 + 0xc]
    s.cx = m.r32((s.dx+(s.cx * 0x00000004u)+0x0000000cu));
  }
  L0062fea9: { // 0x62fea9: 33f1 XOR ESI,ECX
    s.si = integer::logical((s.si)^(s.cx),32,flags);
  }
  L0062feab: { // 0x62feab: 8930 MOV dword ptr [EAX],ESI
    m.w32((s.ax), s.si);
  }
  L0062fead: { // 0x62fead: 8b4204 MOV EAX,dword ptr [EDX + 0x4]
    s.ax = m.r32((s.dx+0x00000004u));
  }
  L0062feb0: { // 0x62feb0: 8b4a08 MOV ECX,dword ptr [EDX + 0x8]
    s.cx = m.r32((s.dx+0x00000008u));
  }
  L0062feb3: { // 0x62feb3: 8b74820c MOV ESI,dword ptr [EDX + EAX*0x4 + 0xc]
    s.si = m.r32((s.dx+(s.ax * 0x00000004u)+0x0000000cu));
  }
  L0062feb7: { // 0x62feb7: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0062feb8: { // 0x62feb8: 41 INC ECX
    s.cx = integer::increment(s.cx,32,flags);
  }
  L0062feb9: { // 0x62feb9: 3dfa000000 CMP EAX,0xfa
    (void)integer::sub(s.ax,0x000000fau,32,flags);
  }
  L0062febe: { // 0x62febe: 894204 MOV dword ptr [EDX + 0x4],EAX
    m.w32((s.dx+0x00000004u), s.ax);
  }
  L0062fec1: { // 0x62fec1: 894a08 MOV dword ptr [EDX + 0x8],ECX
    m.w32((s.dx+0x00000008u), s.cx);
  }
  L0062fec4: { // 0x62fec4: 7c07 JL 0x0062fecd
    if(integer::condition("JL",flags)) goto L0062fecd;
  }
  L0062fec6: { // 0x62fec6: c7420400000000 MOV dword ptr [EDX + 0x4],0x0
    m.w32((s.dx+0x00000004u), 0x00000000u);
  }
  L0062fecd: { // 0x62fecd: 81f9fa000000 CMP ECX,0xfa
    (void)integer::sub(s.cx,0x000000fau,32,flags);
  }
  L0062fed3: { // 0x62fed3: 7c07 JL 0x0062fedc
    if(integer::condition("JL",flags)) goto L0062fedc;
  }
  L0062fed5: { // 0x62fed5: c7420800000000 MOV dword ptr [EDX + 0x8],0x0
    m.w32((s.dx+0x00000008u), 0x00000000u);
  }
  L0062fedc: { // 0x62fedc: 8bc6 MOV EAX,ESI
    s.ax = s.si;
  }
  L0062fede: { // 0x62fede: 23c5 AND EAX,EBP
    s.ax = integer::logical((s.ax)&(s.bp),32,flags);
  }
  L0062fee0: { // 0x62fee0: 3bc7 CMP EAX,EDI
    (void)integer::sub(s.ax,s.di,32,flags);
  }
  L0062fee2: { // 0x62fee2: 7faa JG 0x0062fe8e
    if(integer::condition("JG",flags)) goto L0062fe8e;
  }
  L0062fee4: { // 0x62fee4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0062fee5: { // 0x62fee5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0062fee6: { // 0x62fee6: 03c3 ADD EAX,EBX
    s.ax = integer::add(s.ax,s.bx,32,flags);
  }
  L0062fee8: { // 0x62fee8: 5d POP EBP
    const auto value=f.pop(m); s.bp = value;
  }
  L0062fee9: { // 0x62fee9: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L0062feea: { // 0x62feea: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); return;
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
void f_001cd850(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005cd850: { // 0x5cd850: 8b442404 MOV EAX,dword ptr [ESP + 0x4]
    s.ax = m.r32((f.sp+0x00000004u));
  }
  L005cd854: { // 0x5cd854: 81c188000000 ADD ECX,0x88
    s.cx = integer::add(s.cx,0x00000088u,32,flags);
  }
  L005cd85a: { // 0x5cd85a: 8b10 MOV EDX,dword ptr [EAX]
    s.dx = m.r32((s.ax));
  }
  L005cd85c: { // 0x5cd85c: 8911 MOV dword ptr [ECX],EDX
    m.w32((s.cx), s.dx);
  }
  L005cd85e: { // 0x5cd85e: 8b5004 MOV EDX,dword ptr [EAX + 0x4]
    s.dx = m.r32((s.ax+0x00000004u));
  }
  L005cd861: { // 0x5cd861: 895104 MOV dword ptr [ECX + 0x4],EDX
    m.w32((s.cx+0x00000004u), s.dx);
  }
  L005cd864: { // 0x5cd864: 8b4008 MOV EAX,dword ptr [EAX + 0x8]
    s.ax = m.r32((s.ax+0x00000008u));
  }
  L005cd867: { // 0x5cd867: 894108 MOV dword ptr [ECX + 0x8],EAX
    m.w32((s.cx+0x00000008u), s.ax);
  }
  L005cd86a: { // 0x5cd86a: c20400 RET 0x4
    s.arithmetic_flags=flags; finish(m,s,f,4u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6487616u:f_0022fe40(m,s,child,{});break;
case 7776848u:f_0036aa50(m,s,child,{});break;
case 6084688u:f_001cd850(m,s,child,{});break;
default:throw std::domain_error("recovery818 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_00600de0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L00600de0: { // 0x600de0: 83ec1c SUB ESP,0x1c
    f.sp = integer::sub(f.sp,0x0000001cu,32,flags);
  }
  L00600de3: { // 0x600de3: 56 PUSH ESI
    f.push(m,s.si);
  }
  L00600de4: { // 0x600de4: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L00600de6: { // 0x600de6: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00600dec: { // 0x600dec: 68feffff7f PUSH 0x7ffffffe
    f.push(m,0x7ffffffeu);
  }
  L00600df1: { // 0x600df1: d986fc000000 FLD float ptr [ESI + 0xfc]
    const auto address=(s.si+0x000000fcu);
    s.fp.load32(m.r32(address));
  }
  L00600df7: { // 0x600df7: d98600010000 FLD float ptr [ESI + 0x100]
    const auto address=(s.si+0x00000100u);
    s.fp.load32(m.r32(address));
  }
  L00600dfd: { // 0x600dfd: 8b86d4000000 MOV EAX,dword ptr [ESI + 0xd4]
    s.ax = m.r32((s.si+0x000000d4u));
  }
  L00600e03: { // 0x600e03: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00600e05: { // 0x600e05: d95c2420 FSTP float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e09: { // 0x600e09: d98604010000 FLD float ptr [ESI + 0x104]
    const auto address=(s.si+0x00000104u);
    s.fp.load32(m.r32(address));
  }
  L00600e0f: { // 0x600e0f: d95c2424 FSTP float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e13: { // 0x600e13: 8944240c MOV dword ptr [ESP + 0xc],EAX
    m.w32((f.sp+0x0000000cu), s.ax);
  }
  L00600e17: { // 0x600e17: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00600e1d: { // 0x600e1d: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L00600e21: { // 0x600e21: d95c2410 FSTP float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e25: { // 0x600e25: d9442420 FLD float ptr [ESP + 0x20]
    const auto address=(f.sp+0x00000020u);
    s.fp.load32(m.r32(address));
  }
  L00600e29: { // 0x600e29: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L00600e2d: { // 0x600e2d: d95c2414 FSTP float ptr [ESP + 0x14]
    const auto address=(f.sp+0x00000014u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e31: { // 0x600e31: d9442424 FLD float ptr [ESP + 0x24]
    const auto address=(f.sp+0x00000024u);
    s.fp.load32(m.r32(address));
  }
  L00600e35: { // 0x600e35: d84c240c FMUL float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.multiply32(m.r32(address));
  }
  L00600e39: { // 0x600e39: d95c2418 FSTP float ptr [ESP + 0x18]
    const auto address=(f.sp+0x00000018u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e3d: { // 0x600e3d: e8feef0200 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6295106u); flags=s.arithmetic_flags;
  }
  L00600e42: { // 0x600e42: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00600e46: { // 0x600e46: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600e4a: { // 0x600e4a: dc0d80727800 FMUL double ptr [0x00787280]
    const auto address=(0x00787280u);
    s.fp.multiply64(read64(m,address));
  }
  L00600e50: { // 0x600e50: dc2528577800 FSUB double ptr [0x00785728]
    const auto address=(0x00785728u);
    s.fp.subtract64(read64(m,address));
  }
  L00600e56: { // 0x600e56: dc0d70757800 FMUL double ptr [0x00787570]
    const auto address=(0x00787570u);
    s.fp.multiply64(read64(m,address));
  }
  L00600e5c: { // 0x600e5c: d886d4000000 FADD float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    s.fp.add32(m.r32(address));
  }
  L00600e62: { // 0x600e62: d99ed4000000 FSTP float ptr [ESI + 0xd4]
    const auto address=(s.si+0x000000d4u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e68: { // 0x600e68: d9442408 FLD float ptr [ESP + 0x8]
    const auto address=(f.sp+0x00000008u);
    s.fp.load32(m.r32(address));
  }
  L00600e6c: { // 0x600e6c: d88608010000 FADD float ptr [ESI + 0x108]
    const auto address=(s.si+0x00000108u);
    s.fp.add32(m.r32(address));
  }
  L00600e72: { // 0x600e72: d99e08010000 FSTP float ptr [ESI + 0x108]
    const auto address=(s.si+0x00000108u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e78: { // 0x600e78: d944240c FLD float ptr [ESP + 0xc]
    const auto address=(f.sp+0x0000000cu);
    s.fp.load32(m.r32(address));
  }
  L00600e7c: { // 0x600e7c: d8860c010000 FADD float ptr [ESI + 0x10c]
    const auto address=(s.si+0x0000010cu);
    s.fp.add32(m.r32(address));
  }
  L00600e82: { // 0x600e82: d99e0c010000 FSTP float ptr [ESI + 0x10c]
    const auto address=(s.si+0x0000010cu);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e88: { // 0x600e88: d9442410 FLD float ptr [ESP + 0x10]
    const auto address=(f.sp+0x00000010u);
    s.fp.load32(m.r32(address));
  }
  L00600e8c: { // 0x600e8c: d88610010000 FADD float ptr [ESI + 0x110]
    const auto address=(s.si+0x00000110u);
    s.fp.add32(m.r32(address));
  }
  L00600e92: { // 0x600e92: d99e10010000 FSTP float ptr [ESI + 0x110]
    const auto address=(s.si+0x00000110u);
    const auto value=s.fp.pop32();
    m.w32(address,value);
  }
  L00600e98: { // 0x600e98: d98608010000 FLD float ptr [ESI + 0x108]
    const auto address=(s.si+0x00000108u);
    s.fp.load32(m.r32(address));
  }
  L00600e9e: { // 0x600e9e: e8ad9b1600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6295203u); flags=s.arithmetic_flags;
  }
  L00600ea3: { // 0x600ea3: d9860c010000 FLD float ptr [ESI + 0x10c]
    const auto address=(s.si+0x0000010cu);
    s.fp.load32(m.r32(address));
  }
  L00600ea9: { // 0x600ea9: 89442414 MOV dword ptr [ESP + 0x14],EAX
    m.w32((f.sp+0x00000014u), s.ax);
  }
  L00600ead: { // 0x600ead: e89e9b1600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6295218u); flags=s.arithmetic_flags;
  }
  L00600eb2: { // 0x600eb2: d98610010000 FLD float ptr [ESI + 0x110]
    const auto address=(s.si+0x00000110u);
    s.fp.load32(m.r32(address));
  }
  L00600eb8: { // 0x600eb8: 89442418 MOV dword ptr [ESP + 0x18],EAX
    m.w32((f.sp+0x00000018u), s.ax);
  }
  L00600ebc: { // 0x600ebc: e88f9b1600 CALL 0x0076aa50
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076aa50u,6295233u); flags=s.arithmetic_flags;
  }
  L00600ec1: { // 0x600ec1: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L00600ec3: { // 0x600ec3: 8944241c MOV dword ptr [ESP + 0x1c],EAX
    m.w32((f.sp+0x0000001cu), s.ax);
  }
  L00600ec7: { // 0x600ec7: 8d442414 LEA EAX,[ESP + 0x14]
    s.ax = (f.sp+0x00000014u);
  }
  L00600ecb: { // 0x600ecb: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L00600ecd: { // 0x600ecd: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L00600ece: { // 0x600ece: ff929c010000 CALL dword ptr [EDX + 0x19c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000019cu)),6295252u); flags=s.arithmetic_flags;
  }
  L00600ed4: { // 0x600ed4: 8b0dc055a200 MOV ECX,dword ptr [0x00a255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L00600eda: { // 0x600eda: 68feffff7f PUSH 0x7ffffffe
    f.push(m,0x7ffffffeu);
  }
  L00600edf: { // 0x600edf: 6a00 PUSH 0x0
    f.push(m,0x00000000u);
  }
  L00600ee1: { // 0x600ee1: 81c118020000 ADD ECX,0x218
    s.cx = integer::add(s.cx,0x00000218u,32,flags);
  }
  L00600ee7: { // 0x600ee7: e854ef0200 CALL 0x0062fe40
    s.arithmetic_flags=flags; invoke(m,s,f,0x0062fe40u,6295276u); flags=s.arithmetic_flags;
  }
  L00600eec: { // 0x600eec: 89442404 MOV dword ptr [ESP + 0x4],EAX
    m.w32((f.sp+0x00000004u), s.ax);
  }
  L00600ef0: { // 0x600ef0: 8b8e98000000 MOV ECX,dword ptr [ESI + 0x98]
    s.cx = m.r32((s.si+0x00000098u));
  }
  L00600ef6: { // 0x600ef6: db442404 FILD dword ptr [ESP + 0x4]
    const auto address=(f.sp+0x00000004u);
    s.fp.load_integer32(m.r32(address));
  }
  L00600efa: { // 0x600efa: dc0d80727800 FMUL double ptr [0x00787280]
    const auto address=(0x00787280u);
    s.fp.multiply64(read64(m,address));
  }
  L00600f00: { // 0x600f00: dc0df8c07800 FMUL double ptr [0x0078c0f8]
    const auto address=(0x0078c0f8u);
    s.fp.multiply64(read64(m,address));
  }
  L00600f06: { // 0x600f06: dc8180020000 FADD double ptr [ECX + 0x280]
    const auto address=(s.cx+0x00000280u);
    s.fp.add64(read64(m,address));
  }
  L00600f0c: { // 0x600f0c: dc86a8000000 FADD double ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    s.fp.add64(read64(m,address));
  }
  L00600f12: { // 0x600f12: dd96a8000000 FST double ptr [ESI + 0xa8]
    const auto address=(s.si+0x000000a8u);
    const auto value=s.fp.store64();
    write64(m,address,value);
  }
  L00600f18: { // 0x600f18: dc1d08577800 FCOMP double ptr [0x00785708]
    const auto address=(0x00785708u);
    s.fp.compare_pop64(read64(m,address));
  }
  L00600f1e: { // 0x600f1e: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L00600f20: { // 0x600f20: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L00600f23: { // 0x600f23: 7547 JNZ 0x00600f6c
    if(integer::condition("JNZ",flags)) goto L00600f6c;
  }
  L00600f25: { // 0x600f25: 8b9198020000 MOV EDX,dword ptr [ECX + 0x298]
    s.dx = m.r32((s.cx+0x00000298u));
  }
  L00600f2b: { // 0x600f2b: 8b86a0000000 MOV EAX,dword ptr [ESI + 0xa0]
    s.ax = m.r32((s.si+0x000000a0u));
  }
  L00600f31: { // 0x600f31: 83ea02 SUB EDX,0x2
    s.dx = integer::sub(s.dx,0x00000002u,32,flags);
  }
  L00600f34: { // 0x600f34: 3bc2 CMP EAX,EDX
    (void)integer::sub(s.ax,s.dx,32,flags);
  }
  L00600f36: { // 0x600f36: 7d20 JGE 0x00600f58
    if(integer::condition("JGE",flags)) goto L00600f58;
  }
  L00600f38: { // 0x600f38: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L00600f39: { // 0x600f39: c786a800000000000000 MOV dword ptr [ESI + 0xa8],0x0
    m.w32((s.si+0x000000a8u), 0x00000000u);
  }
  L00600f43: { // 0x600f43: 8986a0000000 MOV dword ptr [ESI + 0xa0],EAX
    m.w32((s.si+0x000000a0u), s.ax);
  }
  L00600f49: { // 0x600f49: c786ac00000000000000 MOV dword ptr [ESI + 0xac],0x0
    m.w32((s.si+0x000000acu), 0x00000000u);
  }
  L00600f53: { // 0x600f53: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00600f54: { // 0x600f54: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00600f57: { // 0x600f57: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L00600f58: { // 0x600f58: c786a800000000000000 MOV dword ptr [ESI + 0xa8],0x0
    m.w32((s.si+0x000000a8u), 0x00000000u);
  }
  L00600f62: { // 0x600f62: c786ac0000000000f03f MOV dword ptr [ESI + 0xac],0x3ff00000
    m.w32((s.si+0x000000acu), 0x3ff00000u);
  }
  L00600f6c: { // 0x600f6c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L00600f6d: { // 0x600f6d: 83c41c ADD ESP,0x1c
    f.sp = integer::add(f.sp,0x0000001cu,32,flags);
  }
  L00600f70: { // 0x600f70: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
