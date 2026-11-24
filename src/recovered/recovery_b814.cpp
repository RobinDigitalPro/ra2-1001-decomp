#include "recovered/recovery_b814_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b814 {
namespace {
void f_001ccbd0(Memory&,State&,Frame&,const Operations&);
void f_000538b0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_001ccbd0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ccbd0: { // 0x5ccbd0: 83ec08 SUB ESP,0x8
    f.sp = integer::sub(f.sp,0x00000008u,32,flags);
  }
  L005ccbd3: { // 0x5ccbd3: db416c FILD dword ptr [ECX + 0x6c]
    const auto address=(s.cx+0x0000006cu);
    s.fp.load_integer32(m.r32(address));
  }
  L005ccbd6: { // 0x5ccbd6: 8b01 MOV EAX,dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005ccbd8: { // 0x5ccbd8: dd5c2400 FSTP double ptr [ESP]
    const auto address=(f.sp);
    const auto value=s.fp.pop64();
    write64(m,address,value);
  }
  L005ccbdc: { // 0x5ccbdc: ff9084000000 CALL dword ptr [EAX + 0x84]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x00000084u)),6081506u); flags=s.arithmetic_flags;
  }
  L005ccbe2: { // 0x5ccbe2: db80a0000000 FILD dword ptr [EAX + 0xa0]
    const auto address=(s.ax+0x000000a0u);
    s.fp.load_integer32(m.r32(address));
  }
  L005ccbe8: { // 0x5ccbe8: dc7c2400 FDIVR double ptr [ESP]
    const auto address=(f.sp);
    reverse_divide64(s.fp,read64(m,address));
  }
  L005ccbec: { // 0x5ccbec: 83c408 ADD ESP,0x8
    f.sp = integer::add(f.sp,0x00000008u,32,flags);
  }
  L005ccbef: { // 0x5ccbef: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
void f_000538b0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L004538b0: { // 0x4538b0: 8b8118040000 MOV EAX, dword ptr [ECX + 0x418]
    s.ax = m.r32((s.cx+0x00000418u));
  }
  L004538b6: { // 0x4538b6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6081488u:f_001ccbd0(m,s,child,{});break;
case 4536496u:f_000538b0(m,s,child,{});break;
default:throw std::domain_error("recovery814 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_0043bca0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L0043bca0: { // 0x43bca0: 56 PUSH ESI
    f.push(m,s.si);
  }
  L0043bca1: { // 0x43bca1: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L0043bca3: { // 0x43bca3: 57 PUSH EDI
    f.push(m,s.di);
  }
  L0043bca4: { // 0x43bca4: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043bcaa: { // 0x43bcaa: 8bbee0000000 MOV EDI,dword ptr [ESI + 0xe0]
    s.di = m.r32((s.si+0x000000e0u));
  }
  L0043bcb0: { // 0x43bcb0: 8a8859130000 MOV CL,byte ptr [EAX + 0x1359]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001359u)));
  }
  L0043bcb6: { // 0x43bcb6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043bcb8: { // 0x43bcb8: 7409 JZ 0x0043bcc3
    if(integer::condition("JZ",flags)) goto L0043bcc3;
  }
  L0043bcba: { // 0x43bcba: 8b86ec040000 MOV EAX,dword ptr [ESI + 0x4ec]
    s.ax = m.r32((s.si+0x000004ecu));
  }
  L0043bcc0: { // 0x43bcc0: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bcc1: { // 0x43bcc1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bcc2: { // 0x43bcc2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bcc3: { // 0x43bcc3: 8a885a130000 MOV CL,byte ptr [EAX + 0x135a]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000135au)));
  }
  L0043bcc9: { // 0x43bcc9: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043bccb: { // 0x43bccb: 7409 JZ 0x0043bcd6
    if(integer::condition("JZ",flags)) goto L0043bcd6;
  }
  L0043bccd: { // 0x43bccd: 8b86f0040000 MOV EAX,dword ptr [ESI + 0x4f0]
    s.ax = m.r32((s.si+0x000004f0u));
  }
  L0043bcd3: { // 0x43bcd3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bcd4: { // 0x43bcd4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bcd5: { // 0x43bcd5: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bcd6: { // 0x43bcd6: 8b8e2c040000 MOV ECX,dword ptr [ESI + 0x42c]
    s.cx = m.r32((s.si+0x0000042cu));
  }
  L0043bcdc: { // 0x43bcdc: 85c9 TEST ECX,ECX
    (void)integer::logical((s.cx)&(s.cx),32,flags);
  }
  L0043bcde: { // 0x43bcde: 755a JNZ 0x0043bd3a
    if(integer::condition("JNZ",flags)) goto L0043bd3a;
  }
  L0043bce0: { // 0x43bce0: 8a8851130000 MOV CL,byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L0043bce6: { // 0x43bce6: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043bce8: { // 0x43bce8: 7413 JZ 0x0043bcfd
    if(integer::condition("JZ",flags)) goto L0043bcfd;
  }
  L0043bcea: { // 0x43bcea: 8b88900c0000 MOV ECX,dword ptr [EAX + 0xc90]
    s.cx = m.r32((s.ax+0x00000c90u));
  }
  L0043bcf0: { // 0x43bcf0: 8b908c0c0000 MOV EDX,dword ptr [EAX + 0xc8c]
    s.dx = m.r32((s.ax+0x00000c8cu));
  }
  L0043bcf6: { // 0x43bcf6: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043bcf8: { // 0x43bcf8: 2bcf SUB ECX,EDI
    s.cx = integer::sub(s.cx,s.di,32,flags);
  }
  L0043bcfa: { // 0x43bcfa: 49 DEC ECX
    s.cx = integer::decrement(s.cx,32,flags);
  }
  L0043bcfb: { // 0x43bcfb: 8bf9 MOV EDI,ECX
    s.di = s.cx;
  }
  L0043bcfd: { // 0x43bcfd: 8b16 MOV EDX,dword ptr [ESI]
    s.dx = m.r32((s.si));
  }
  L0043bcff: { // 0x43bcff: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043bd01: { // 0x43bd01: ff926c010000 CALL dword ptr [EDX + 0x16c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000016cu)),4439303u); flags=s.arithmetic_flags;
  }
  L0043bd07: { // 0x43bd07: 83f813 CMP EAX,0x13
    (void)integer::sub(s.ax,0x00000013u,32,flags);
  }
  L0043bd0a: { // 0x43bd0a: 0f851c010000 JNZ 0x0043be2c
    if(integer::condition("JNZ",flags)) goto L0043be2c;
  }
  L0043bd10: { // 0x43bd10: 8b862c040000 MOV EAX,dword ptr [ESI + 0x42c]
    s.ax = m.r32((s.si+0x0000042cu));
  }
  L0043bd16: { // 0x43bd16: 8bb618040000 MOV ESI,dword ptr [ESI + 0x418]
    s.si = m.r32((s.si+0x00000418u));
  }
  L0043bd1c: { // 0x43bd1c: 8d8c4024030000 LEA ECX,[EAX + EAX*0x2 + 0x324]
    s.cx = (s.ax+(s.ax * 0x00000002u)+0x00000324u);
  }
  L0043bd23: { // 0x43bd23: 8d1440 LEA EDX,[EAX + EAX*0x2]
    s.dx = (s.ax+(s.ax * 0x00000002u));
  }
  L0043bd26: { // 0x43bd26: 8b048e MOV EAX,dword ptr [ESI + ECX*0x4]
    s.ax = m.r32((s.si+(s.cx * 0x00000004u)));
  }
  L0043bd29: { // 0x43bd29: 8b8c968c0c0000 MOV ECX,dword ptr [ESI + EDX*0x4 + 0xc8c]
    s.cx = m.r32((s.si+(s.dx * 0x00000004u)+0x00000c8cu));
  }
  L0043bd30: { // 0x43bd30: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0043bd32: { // 0x43bd32: 2bc7 SUB EAX,EDI
    s.ax = integer::sub(s.ax,s.di,32,flags);
  }
  L0043bd34: { // 0x43bd34: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0043bd35: { // 0x43bd35: 8bf8 MOV EDI,EAX
    s.di = s.ax;
  }
  L0043bd37: { // 0x43bd37: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bd38: { // 0x43bd38: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bd39: { // 0x43bd39: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bd3a: { // 0x43bd3a: 8a881e120000 MOV CL,byte ptr [EAX + 0x121e]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000121eu)));
  }
  L0043bd40: { // 0x43bd40: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043bd42: { // 0x43bd42: 7436 JZ 0x0043bd7a
    if(integer::condition("JZ",flags)) goto L0043bd7a;
  }
  L0043bd44: { // 0x43bd44: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043bd46: { // 0x43bd46: e8850e1900 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4439371u); flags=s.arithmetic_flags;
  }
  L0043bd4b: { // 0x43bd4b: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0043bd51: { // 0x43bd51: dc9970130000 FCOMP double ptr [ECX + 0x1370]
    const auto address=(s.cx+0x00001370u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0043bd57: { // 0x43bd57: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0043bd59: { // 0x43bd59: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0043bd5c: { // 0x43bd5c: 7408 JZ 0x0043bd66
    if(integer::condition("JZ",flags)) goto L0043bd66;
  }
  L0043bd5e: { // 0x43bd5e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bd5f: { // 0x43bd5f: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L0043bd64: { // 0x43bd64: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bd65: { // 0x43bd65: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bd66: { // 0x43bd66: 8bbe64050000 MOV EDI,dword ptr [ESI + 0x564]
    s.di = m.r32((s.si+0x00000564u));
  }
  L0043bd6c: { // 0x43bd6c: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043bd6e: { // 0x43bd6e: 85ff TEST EDI,EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L0043bd70: { // 0x43bd70: 0f9ec0 SETLE AL
    s.ax = with_al(s.ax, (integer::condition("SETLE",flags)?1u:0u));
  }
  L0043bd73: { // 0x43bd73: 48 DEC EAX
    s.ax = integer::decrement(s.ax,32,flags);
  }
  L0043bd74: { // 0x43bd74: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bd75: { // 0x43bd75: 83e002 AND EAX,0x2
    s.ax = integer::logical((s.ax)&(0x00000002u),32,flags);
  }
  L0043bd78: { // 0x43bd78: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bd79: { // 0x43bd79: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bd7a: { // 0x43bd7a: 8a8851130000 MOV CL,byte ptr [EAX + 0x1351]
    s.cx = with_al(s.cx, m.r8((s.ax+0x00001351u)));
  }
  L0043bd80: { // 0x43bd80: 84c9 TEST CL,CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L0043bd82: { // 0x43bd82: 8bce MOV ECX,ESI
    s.cx = s.si;
  }
  L0043bd84: { // 0x43bd84: 742d JZ 0x0043bdb3
    if(integer::condition("JZ",flags)) goto L0043bdb3;
  }
  L0043bd86: { // 0x43bd86: e8450e1900 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4439435u); flags=s.arithmetic_flags;
  }
  L0043bd8b: { // 0x43bd8b: 8b15881b8200 MOV EDX,dword ptr [0x00821b88]
    s.dx = m.r32((0x00821b88u));
  }
  L0043bd91: { // 0x43bd91: dc9a68130000 FCOMP double ptr [EDX + 0x1368]
    const auto address=(s.dx+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0043bd97: { // 0x43bd97: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0043bd99: { // 0x43bd99: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0043bd9c: { // 0x43bd9c: 7410 JZ 0x0043bdae
    if(integer::condition("JZ",flags)) goto L0043bdae;
  }
  L0043bd9e: { // 0x43bd9e: 8b8618040000 MOV EAX,dword ptr [ESI + 0x418]
    s.ax = m.r32((s.si+0x00000418u));
  }
  L0043bda4: { // 0x43bda4: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bda5: { // 0x43bda5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bda6: { // 0x43bda6: 8b807c130000 MOV EAX,dword ptr [EAX + 0x137c]
    s.ax = m.r32((s.ax+0x0000137cu));
  }
  L0043bdac: { // 0x43bdac: 40 INC EAX
    s.ax = integer::increment(s.ax,32,flags);
  }
  L0043bdad: { // 0x43bdad: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bdae: { // 0x43bdae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bdaf: { // 0x43bdaf: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L0043bdb1: { // 0x43bdb1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bdb2: { // 0x43bdb2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bdb3: { // 0x43bdb3: e8180e1900 CALL 0x005ccbd0
    s.arithmetic_flags=flags; invoke(m,s,f,0x005ccbd0u,4439480u); flags=s.arithmetic_flags;
  }
  L0043bdb8: { // 0x43bdb8: 8b0d881b8200 MOV ECX,dword ptr [0x00821b88]
    s.cx = m.r32((0x00821b88u));
  }
  L0043bdbe: { // 0x43bdbe: dc9968130000 FCOMP double ptr [ECX + 0x1368]
    const auto address=(s.cx+0x00001368u);
    s.fp.compare_pop64(read64(m,address));
  }
  L0043bdc4: { // 0x43bdc4: dfe0 FNSTSW AX
    s.ax=with_ax(s.ax,s.fp.status());
  }
  L0043bdc6: { // 0x43bdc6: f6c441 TEST AH,0x41
    (void)integer::logical((((s.ax >> 8) & 0xffu))&(0x00000041u),8,flags);
  }
  L0043bdc9: { // 0x43bdc9: 7461 JZ 0x0043be2c
    if(integer::condition("JZ",flags)) goto L0043be2c;
  }
  L0043bdcb: { // 0x43bdcb: 83be2c04000001 CMP dword ptr [ESI + 0x42c],0x1
    (void)integer::sub(m.r32((s.si+0x0000042cu)),0x00000001u,32,flags);
  }
  L0043bdd2: { // 0x43bdd2: 7506 JNZ 0x0043bdda
    if(integer::condition("JNZ",flags)) goto L0043bdda;
  }
  L0043bdd4: { // 0x43bdd4: 47 INC EDI
    s.di = integer::increment(s.di,32,flags);
  }
  L0043bdd5: { // 0x43bdd5: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0043bdd7: { // 0x43bdd7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043bdd8: { // 0x43bdd8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043bdd9: { // 0x43bdd9: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L0043bdda: { // 0x43bdda: 8bb618040000 MOV ESI,dword ptr [ESI + 0x418]
    s.si = m.r32((s.si+0x00000418u));
  }
  L0043bde0: { // 0x43bde0: 8b869c0c0000 MOV EAX,dword ptr [ESI + 0xc9c]
    s.ax = m.r32((s.si+0x00000c9cu));
  }
  L0043bde6: { // 0x43bde6: 8b8e980c0000 MOV ECX,dword ptr [ESI + 0xc98]
    s.cx = m.r32((s.si+0x00000c98u));
  }
  L0043bdec: { // 0x43bdec: 8b96a40c0000 MOV EDX,dword ptr [ESI + 0xca4]
    s.dx = m.r32((s.si+0x00000ca4u));
  }
  L0043bdf2: { // 0x43bdf2: 03c1 ADD EAX,ECX
    s.ax = integer::add(s.ax,s.cx,32,flags);
  }
  L0043bdf4: { // 0x43bdf4: 8b8ea80c0000 MOV ECX,dword ptr [ESI + 0xca8]
    s.cx = m.r32((s.si+0x00000ca8u));
  }
  L0043bdfa: { // 0x43bdfa: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043bdfc: { // 0x43bdfc: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043bdfe: { // 0x43bdfe: 7f02 JG 0x0043be02
    if(integer::condition("JG",flags)) goto L0043be02;
  }
  L0043be00: { // 0x43be00: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0043be02: { // 0x43be02: 8b8ec00c0000 MOV ECX,dword ptr [ESI + 0xcc0]
    s.cx = m.r32((s.si+0x00000cc0u));
  }
  L0043be08: { // 0x43be08: 8b96bc0c0000 MOV EDX,dword ptr [ESI + 0xcbc]
    s.dx = m.r32((s.si+0x00000cbcu));
  }
  L0043be0e: { // 0x43be0e: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043be10: { // 0x43be10: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043be12: { // 0x43be12: 7f02 JG 0x0043be16
    if(integer::condition("JG",flags)) goto L0043be16;
  }
  L0043be14: { // 0x43be14: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0043be16: { // 0x43be16: 8b8ecc0c0000 MOV ECX,dword ptr [ESI + 0xccc]
    s.cx = m.r32((s.si+0x00000cccu));
  }
  L0043be1c: { // 0x43be1c: 8b96c80c0000 MOV EDX,dword ptr [ESI + 0xcc8]
    s.dx = m.r32((s.si+0x00000cc8u));
  }
  L0043be22: { // 0x43be22: 03ca ADD ECX,EDX
    s.cx = integer::add(s.cx,s.dx,32,flags);
  }
  L0043be24: { // 0x43be24: 3bc1 CMP EAX,ECX
    (void)integer::sub(s.ax,s.cx,32,flags);
  }
  L0043be26: { // 0x43be26: 7f02 JG 0x0043be2a
    if(integer::condition("JG",flags)) goto L0043be2a;
  }
  L0043be28: { // 0x43be28: 8bc1 MOV EAX,ECX
    s.ax = s.cx;
  }
  L0043be2a: { // 0x43be2a: 03f8 ADD EDI,EAX
    s.di = integer::add(s.di,s.ax,32,flags);
  }
  L0043be2c: { // 0x43be2c: 8bc7 MOV EAX,EDI
    s.ax = s.di;
  }
  L0043be2e: { // 0x43be2e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L0043be2f: { // 0x43be2f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L0043be30: { // 0x43be30: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
