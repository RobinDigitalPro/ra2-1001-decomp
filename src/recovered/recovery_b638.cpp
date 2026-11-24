#include "platform/observed_control635.hpp"
#include "recovered/recovery_b638_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b638 {
namespace {
void f_001d6fc0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_001d6fc0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d6fc0: { // 0x5d6fc0: 8b01 MOV EAX, dword ptr [ECX]
    s.ax = m.r32((s.cx));
  }
  L005d6fc2: { // 0x5d6fc2: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}


} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6123456u:f_001d6fc0(m,s,child,{});break;
default:{if(target!=ra2::platform::control635::Control::address())throw std::domain_error("638 unreviewed API");s.ax=ra2::platform::control635::Control::guest_call(m.r32(child.sp+4));child.sp+=8;break;}}
f.sp=child.sp;
}
}

std::uint32_t fun_005ded00(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005ded00: { // 0x5ded00: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005ded01: { // 0x5ded01: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005ded06: { // 0x5ded06: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005ded07: { // 0x5ded07: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005ded09: { // 0x5ded09: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005ded0a: { // 0x5ded0a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ded0c: { // 0x5ded0c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005ded0e: { // 0x5ded0e: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L005ded12: { // 0x5ded12: 7441 JZ 0x005ded55
    if(integer::condition("JZ",flags)) goto L005ded55;
  }
  L005ded14: { // 0x5ded14: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L005ded18: { // 0x5ded18: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6155550u); flags=s.arithmetic_flags;
  }
  L005ded1e: { // 0x5ded1e: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005ded24: { // 0x5ded24: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005ded29: { // 0x5ded29: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005ded2b: { // 0x5ded2b: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005ded2c: { // 0x5ded2c: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005ded2e: { // 0x5ded2e: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005ded33: { // 0x5ded33: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005ded36: { // 0x5ded36: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ded38: { // 0x5ded38: 741b JZ 0x005ded55
    if(integer::condition("JZ",flags)) goto L005ded55;
  }
  L005ded3a: { // 0x5ded3a: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005ded3e: { // 0x5ded3e: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005ded40: { // 0x5ded40: 740c JZ 0x005ded4e
    if(integer::condition("JZ",flags)) goto L005ded4e;
  }
  L005ded42: { // 0x5ded42: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005ded48: { // 0x5ded48: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ded4a: { // 0x5ded4a: 75f2 JNZ 0x005ded3e
    if(integer::condition("JNZ",flags)) goto L005ded3e;
  }
  L005ded4c: { // 0x5ded4c: eb07 JMP 0x005ded55
    goto L005ded55;
  }
  L005ded4e: { // 0x5ded4e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005ded50: { // 0x5ded50: 7403 JZ 0x005ded55
    if(integer::condition("JZ",flags)) goto L005ded55;
  }
  L005ded52: { // 0x5ded52: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005ded55: { // 0x5ded55: 8b766c MOV ESI,dword ptr [ESI + 0x6c]
    s.si = m.r32((s.si+0x0000006cu));
  }
  L005ded58: { // 0x5ded58: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005ded59: { // 0x5ded59: ff15f4537800 CALL dword ptr [0x007853f4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007853f4u)),6155615u); flags=s.arithmetic_flags;
  }
  L005ded5f: { // 0x5ded5f: 81fe0c010000 CMP ESI,0x10c
    (void)integer::sub(s.si,0x0000010cu,32,flags);
  }
  L005ded65: { // 0x5ded65: 0f84ee010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005ded6b: { // 0x5ded6b: 81fe94000000 CMP ESI,0x94
    (void)integer::sub(s.si,0x00000094u,32,flags);
  }
  L005ded71: { // 0x5ded71: 0f84e2010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005ded77: { // 0x5ded77: 81fea3000000 CMP ESI,0xa3
    (void)integer::sub(s.si,0x000000a3u,32,flags);
  }
  L005ded7d: { // 0x5ded7d: 0f84d6010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005ded83: { // 0x5ded83: 83fe73 CMP ESI,0x73
    (void)integer::sub(s.si,0x00000073u,32,flags);
  }
  L005ded86: { // 0x5ded86: 0f84cd010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005ded8c: { // 0x5ded8c: 81fed8000000 CMP ESI,0xd8
    (void)integer::sub(s.si,0x000000d8u,32,flags);
  }
  L005ded92: { // 0x5ded92: 0f84c1010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005ded98: { // 0x5ded98: 81febb0b0000 CMP ESI,0xbbb
    (void)integer::sub(s.si,0x00000bbbu,32,flags);
  }
  L005ded9e: { // 0x5ded9e: 0f84b5010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deda4: { // 0x5deda4: 81fef5000000 CMP ESI,0xf5
    (void)integer::sub(s.si,0x000000f5u,32,flags);
  }
  L005dedaa: { // 0x5dedaa: 0f84a9010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dedb0: { // 0x5dedb0: 81fe05010000 CMP ESI,0x105
    (void)integer::sub(s.si,0x00000105u,32,flags);
  }
  L005dedb6: { // 0x5dedb6: 0f849d010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dedbc: { // 0x5dedbc: 81fee2000000 CMP ESI,0xe2
    (void)integer::sub(s.si,0x000000e2u,32,flags);
  }
  L005dedc2: { // 0x5dedc2: 0f8491010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dedc8: { // 0x5dedc8: 81fed5000000 CMP ESI,0xd5
    (void)integer::sub(s.si,0x000000d5u,32,flags);
  }
  L005dedce: { // 0x5dedce: 0f8485010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dedd4: { // 0x5dedd4: 81feb5020000 CMP ESI,0x2b5
    (void)integer::sub(s.si,0x000002b5u,32,flags);
  }
  L005dedda: { // 0x5dedda: 0f8479010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dede0: { // 0x5dede0: 81feb7000000 CMP ESI,0xb7
    (void)integer::sub(s.si,0x000000b7u,32,flags);
  }
  L005dede6: { // 0x5dede6: 0f846d010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dedec: { // 0x5dedec: 81feb4020000 CMP ESI,0x2b4
    (void)integer::sub(s.si,0x000002b4u,32,flags);
  }
  L005dedf2: { // 0x5dedf2: 0f8461010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dedf8: { // 0x5dedf8: 81fec70b0000 CMP ESI,0xbc7
    (void)integer::sub(s.si,0x00000bc7u,32,flags);
  }
  L005dedfe: { // 0x5dedfe: 0f8455010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee04: { // 0x5dee04: 81fe01010000 CMP ESI,0x101
    (void)integer::sub(s.si,0x00000101u,32,flags);
  }
  L005dee0a: { // 0x5dee0a: 0f8449010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee10: { // 0x5dee10: 81fe29010000 CMP ESI,0x129
    (void)integer::sub(s.si,0x00000129u,32,flags);
  }
  L005dee16: { // 0x5dee16: 0f843d010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee1c: { // 0x5dee1c: 81fec60b0000 CMP ESI,0xbc6
    (void)integer::sub(s.si,0x00000bc6u,32,flags);
  }
  L005dee22: { // 0x5dee22: 0f8431010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee28: { // 0x5dee28: 81fed7000000 CMP ESI,0xd7
    (void)integer::sub(s.si,0x000000d7u,32,flags);
  }
  L005dee2e: { // 0x5dee2e: 0f8425010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee34: { // 0x5dee34: 81fe08010000 CMP ESI,0x108
    (void)integer::sub(s.si,0x00000108u,32,flags);
  }
  L005dee3a: { // 0x5dee3a: 0f8419010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee40: { // 0x5dee40: 81febc000000 CMP ESI,0xbc
    (void)integer::sub(s.si,0x000000bcu,32,flags);
  }
  L005dee46: { // 0x5dee46: 0f840d010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee4c: { // 0x5dee4c: 81febd000000 CMP ESI,0xbd
    (void)integer::sub(s.si,0x000000bdu,32,flags);
  }
  L005dee52: { // 0x5dee52: 0f8401010000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee58: { // 0x5dee58: 81febb000000 CMP ESI,0xbb
    (void)integer::sub(s.si,0x000000bbu,32,flags);
  }
  L005dee5e: { // 0x5dee5e: 0f84f5000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee64: { // 0x5dee64: 81feb5000000 CMP ESI,0xb5
    (void)integer::sub(s.si,0x000000b5u,32,flags);
  }
  L005dee6a: { // 0x5dee6a: 0f84e9000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee70: { // 0x5dee70: 81feba0b0000 CMP ESI,0xbba
    (void)integer::sub(s.si,0x00000bbau,32,flags);
  }
  L005dee76: { // 0x5dee76: 0f84dd000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee7c: { // 0x5dee7c: 81feff000000 CMP ESI,0xff
    (void)integer::sub(s.si,0x000000ffu,32,flags);
  }
  L005dee82: { // 0x5dee82: 0f84d1000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee88: { // 0x5dee88: 83fe6b CMP ESI,0x6b
    (void)integer::sub(s.si,0x0000006bu,32,flags);
  }
  L005dee8b: { // 0x5dee8b: 0f84c8000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee91: { // 0x5dee91: 81fe00010000 CMP ESI,0x100
    (void)integer::sub(s.si,0x00000100u,32,flags);
  }
  L005dee97: { // 0x5dee97: 0f84bc000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005dee9d: { // 0x5dee9d: 81fe02010000 CMP ESI,0x102
    (void)integer::sub(s.si,0x00000102u,32,flags);
  }
  L005deea3: { // 0x5deea3: 0f84b0000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deea9: { // 0x5deea9: 81feb8000000 CMP ESI,0xb8
    (void)integer::sub(s.si,0x000000b8u,32,flags);
  }
  L005deeaf: { // 0x5deeaf: 0f84a4000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deeb5: { // 0x5deeb5: 81fed6000000 CMP ESI,0xd6
    (void)integer::sub(s.si,0x000000d6u,32,flags);
  }
  L005deebb: { // 0x5deebb: 0f8498000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deec1: { // 0x5deec1: 81fe03010000 CMP ESI,0x103
    (void)integer::sub(s.si,0x00000103u,32,flags);
  }
  L005deec7: { // 0x5deec7: 0f848c000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deecd: { // 0x5deecd: 81fe25010000 CMP ESI,0x125
    (void)integer::sub(s.si,0x00000125u,32,flags);
  }
  L005deed3: { // 0x5deed3: 0f8480000000 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deed9: { // 0x5deed9: 81fee7000000 CMP ESI,0xe7
    (void)integer::sub(s.si,0x000000e7u,32,flags);
  }
  L005deedf: { // 0x5deedf: 7478 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deee1: { // 0x5deee1: 81fe16010000 CMP ESI,0x116
    (void)integer::sub(s.si,0x00000116u,32,flags);
  }
  L005deee7: { // 0x5deee7: 7470 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deee9: { // 0x5deee9: 81fec2000000 CMP ESI,0xc2
    (void)integer::sub(s.si,0x000000c2u,32,flags);
  }
  L005deeef: { // 0x5deeef: 7468 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deef1: { // 0x5deef1: 81fec9000000 CMP ESI,0xc9
    (void)integer::sub(s.si,0x000000c9u,32,flags);
  }
  L005deef7: { // 0x5deef7: 7460 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005deef9: { // 0x5deef9: 81fe1d010000 CMP ESI,0x11d
    (void)integer::sub(s.si,0x0000011du,32,flags);
  }
  L005deeff: { // 0x5deeff: 7458 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def01: { // 0x5def01: 81fe1c010000 CMP ESI,0x11c
    (void)integer::sub(s.si,0x0000011cu,32,flags);
  }
  L005def07: { // 0x5def07: 7450 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def09: { // 0x5def09: 81fe14010000 CMP ESI,0x114
    (void)integer::sub(s.si,0x00000114u,32,flags);
  }
  L005def0f: { // 0x5def0f: 7448 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def11: { // 0x5def11: 81febc020000 CMP ESI,0x2bc
    (void)integer::sub(s.si,0x000002bcu,32,flags);
  }
  L005def17: { // 0x5def17: 7440 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def19: { // 0x5def19: 81fe13010000 CMP ESI,0x113
    (void)integer::sub(s.si,0x00000113u,32,flags);
  }
  L005def1f: { // 0x5def1f: 7438 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def21: { // 0x5def21: 81fe09010000 CMP ESI,0x109
    (void)integer::sub(s.si,0x00000109u,32,flags);
  }
  L005def27: { // 0x5def27: 7430 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def29: { // 0x5def29: 81fe0f010000 CMP ESI,0x10f
    (void)integer::sub(s.si,0x0000010fu,32,flags);
  }
  L005def2f: { // 0x5def2f: 7428 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def31: { // 0x5def31: 81fe17010000 CMP ESI,0x117
    (void)integer::sub(s.si,0x00000117u,32,flags);
  }
  L005def37: { // 0x5def37: 7420 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def39: { // 0x5def39: 81fee6000000 CMP ESI,0xe6
    (void)integer::sub(s.si,0x000000e6u,32,flags);
  }
  L005def3f: { // 0x5def3f: 7418 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def41: { // 0x5def41: 81fef3000000 CMP ESI,0xf3
    (void)integer::sub(s.si,0x000000f3u,32,flags);
  }
  L005def47: { // 0x5def47: 7410 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def49: { // 0x5def49: 81fef4000000 CMP ESI,0xf4
    (void)integer::sub(s.si,0x000000f4u,32,flags);
  }
  L005def4f: { // 0x5def4f: 7408 JZ 0x005def59
    if(integer::condition("JZ",flags)) goto L005def59;
  }
  L005def51: { // 0x5def51: 81fe0e010000 CMP ESI,0x10e
    (void)integer::sub(s.si,0x0000010eu,32,flags);
  }
  L005def57: { // 0x5def57: 750d JNZ 0x005def66
    if(integer::condition("JNZ",flags)) goto L005def66;
  }
  L005def59: { // 0x5def59: 3d94060000 CMP EAX,0x694
    (void)integer::sub(s.ax,0x00000694u,32,flags);
  }
  L005def5e: { // 0x5def5e: 7506 JNZ 0x005def66
    if(integer::condition("JNZ",flags)) goto L005def66;
  }
  L005def60: { // 0x5def60: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005def61: { // 0x5def61: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005def63: { // 0x5def63: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005def64: { // 0x5def64: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005def65: { // 0x5def65: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005def66: { // 0x5def66: 81fe94000000 CMP ESI,0x94
    (void)integer::sub(s.si,0x00000094u,32,flags);
  }
  L005def6c: { // 0x5def6c: 0f8410010000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005def72: { // 0x5def72: 81fed8000000 CMP ESI,0xd8
    (void)integer::sub(s.si,0x000000d8u,32,flags);
  }
  L005def78: { // 0x5def78: 0f8404010000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005def7e: { // 0x5def7e: 81fef5000000 CMP ESI,0xf5
    (void)integer::sub(s.si,0x000000f5u,32,flags);
  }
  L005def84: { // 0x5def84: 0f84f8000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005def8a: { // 0x5def8a: 81fee2000000 CMP ESI,0xe2
    (void)integer::sub(s.si,0x000000e2u,32,flags);
  }
  L005def90: { // 0x5def90: 0f84ec000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005def96: { // 0x5def96: 81fed5000000 CMP ESI,0xd5
    (void)integer::sub(s.si,0x000000d5u,32,flags);
  }
  L005def9c: { // 0x5def9c: 0f84e0000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005defa2: { // 0x5defa2: 81fe01010000 CMP ESI,0x101
    (void)integer::sub(s.si,0x00000101u,32,flags);
  }
  L005defa8: { // 0x5defa8: 0f84d4000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005defae: { // 0x5defae: 81fe29010000 CMP ESI,0x129
    (void)integer::sub(s.si,0x00000129u,32,flags);
  }
  L005defb4: { // 0x5defb4: 0f84c8000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005defba: { // 0x5defba: 81fed7000000 CMP ESI,0xd7
    (void)integer::sub(s.si,0x000000d7u,32,flags);
  }
  L005defc0: { // 0x5defc0: 0f84bc000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005defc6: { // 0x5defc6: 81febb000000 CMP ESI,0xbb
    (void)integer::sub(s.si,0x000000bbu,32,flags);
  }
  L005defcc: { // 0x5defcc: 0f84b0000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005defd2: { // 0x5defd2: 81fe00010000 CMP ESI,0x100
    (void)integer::sub(s.si,0x00000100u,32,flags);
  }
  L005defd8: { // 0x5defd8: 0f84a4000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005defde: { // 0x5defde: 81fed6000000 CMP ESI,0xd6
    (void)integer::sub(s.si,0x000000d6u,32,flags);
  }
  L005defe4: { // 0x5defe4: 0f8498000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005defea: { // 0x5defea: 81fe25010000 CMP ESI,0x125
    (void)integer::sub(s.si,0x00000125u,32,flags);
  }
  L005deff0: { // 0x5deff0: 0f848c000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005deff6: { // 0x5deff6: 81fe22010000 CMP ESI,0x122
    (void)integer::sub(s.si,0x00000122u,32,flags);
  }
  L005deffc: { // 0x5deffc: 0f8480000000 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df002: { // 0x5df002: 81fe12010000 CMP ESI,0x112
    (void)integer::sub(s.si,0x00000112u,32,flags);
  }
  L005df008: { // 0x5df008: 7478 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df00a: { // 0x5df00a: 81fee7000000 CMP ESI,0xe7
    (void)integer::sub(s.si,0x000000e7u,32,flags);
  }
  L005df010: { // 0x5df010: 7470 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df012: { // 0x5df012: 81fe16010000 CMP ESI,0x116
    (void)integer::sub(s.si,0x00000116u,32,flags);
  }
  L005df018: { // 0x5df018: 7468 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df01a: { // 0x5df01a: 81fe1d010000 CMP ESI,0x11d
    (void)integer::sub(s.si,0x0000011du,32,flags);
  }
  L005df020: { // 0x5df020: 7460 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df022: { // 0x5df022: 81fe1c010000 CMP ESI,0x11c
    (void)integer::sub(s.si,0x0000011cu,32,flags);
  }
  L005df028: { // 0x5df028: 7458 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df02a: { // 0x5df02a: 81fefe000000 CMP ESI,0xfe
    (void)integer::sub(s.si,0x000000feu,32,flags);
  }
  L005df030: { // 0x5df030: 7450 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df032: { // 0x5df032: 81fe0f010000 CMP ESI,0x10f
    (void)integer::sub(s.si,0x0000010fu,32,flags);
  }
  L005df038: { // 0x5df038: 7448 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df03a: { // 0x5df03a: 81fe17010000 CMP ESI,0x117
    (void)integer::sub(s.si,0x00000117u,32,flags);
  }
  L005df040: { // 0x5df040: 7440 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df042: { // 0x5df042: 81fe14010000 CMP ESI,0x114
    (void)integer::sub(s.si,0x00000114u,32,flags);
  }
  L005df048: { // 0x5df048: 7438 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df04a: { // 0x5df04a: 81fee6000000 CMP ESI,0xe6
    (void)integer::sub(s.si,0x000000e6u,32,flags);
  }
  L005df050: { // 0x5df050: 7430 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df052: { // 0x5df052: 81fef3000000 CMP ESI,0xf3
    (void)integer::sub(s.si,0x000000f3u,32,flags);
  }
  L005df058: { // 0x5df058: 7428 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df05a: { // 0x5df05a: 81fef4000000 CMP ESI,0xf4
    (void)integer::sub(s.si,0x000000f4u,32,flags);
  }
  L005df060: { // 0x5df060: 7420 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df062: { // 0x5df062: 81febc020000 CMP ESI,0x2bc
    (void)integer::sub(s.si,0x000002bcu,32,flags);
  }
  L005df068: { // 0x5df068: 7418 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df06a: { // 0x5df06a: 81fe0e010000 CMP ESI,0x10e
    (void)integer::sub(s.si,0x0000010eu,32,flags);
  }
  L005df070: { // 0x5df070: 7410 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df072: { // 0x5df072: 81fec60b0000 CMP ESI,0xbc6
    (void)integer::sub(s.si,0x00000bc6u,32,flags);
  }
  L005df078: { // 0x5df078: 7408 JZ 0x005df082
    if(integer::condition("JZ",flags)) goto L005df082;
  }
  L005df07a: { // 0x5df07a: 81fec70b0000 CMP ESI,0xbc7
    (void)integer::sub(s.si,0x00000bc7u,32,flags);
  }
  L005df080: { // 0x5df080: 750d JNZ 0x005df08f
    if(integer::condition("JNZ",flags)) goto L005df08f;
  }
  L005df082: { // 0x5df082: 3d1c070000 CMP EAX,0x71c
    (void)integer::sub(s.ax,0x0000071cu,32,flags);
  }
  L005df087: { // 0x5df087: 7506 JNZ 0x005df08f
    if(integer::condition("JNZ",flags)) goto L005df08f;
  }
  L005df089: { // 0x5df089: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df08a: { // 0x5df08a: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005df08c: { // 0x5df08c: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df08d: { // 0x5df08d: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df08e: { // 0x5df08e: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df08f: { // 0x5df08f: 81febc000000 CMP ESI,0xbc
    (void)integer::sub(s.si,0x000000bcu,32,flags);
  }
  L005df095: { // 0x5df095: 7435 JZ 0x005df0cc
    if(integer::condition("JZ",flags)) goto L005df0cc;
  }
  L005df097: { // 0x5df097: 81febd000000 CMP ESI,0xbd
    (void)integer::sub(s.si,0x000000bdu,32,flags);
  }
  L005df09d: { // 0x5df09d: 742d JZ 0x005df0cc
    if(integer::condition("JZ",flags)) goto L005df0cc;
  }
  L005df09f: { // 0x5df09f: 81fe02010000 CMP ESI,0x102
    (void)integer::sub(s.si,0x00000102u,32,flags);
  }
  L005df0a5: { // 0x5df0a5: 7425 JZ 0x005df0cc
    if(integer::condition("JZ",flags)) goto L005df0cc;
  }
  L005df0a7: { // 0x5df0a7: 81fec2000000 CMP ESI,0xc2
    (void)integer::sub(s.si,0x000000c2u,32,flags);
  }
  L005df0ad: { // 0x5df0ad: 741d JZ 0x005df0cc
    if(integer::condition("JZ",flags)) goto L005df0cc;
  }
  L005df0af: { // 0x5df0af: 81fec9000000 CMP ESI,0xc9
    (void)integer::sub(s.si,0x000000c9u,32,flags);
  }
  L005df0b5: { // 0x5df0b5: 7415 JZ 0x005df0cc
    if(integer::condition("JZ",flags)) goto L005df0cc;
  }
  L005df0b7: { // 0x5df0b7: 81fe05010000 CMP ESI,0x105
    (void)integer::sub(s.si,0x00000105u,32,flags);
  }
  L005df0bd: { // 0x5df0bd: 740d JZ 0x005df0cc
    if(integer::condition("JZ",flags)) goto L005df0cc;
  }
  L005df0bf: { // 0x5df0bf: 83fe6b CMP ESI,0x6b
    (void)integer::sub(s.si,0x0000006bu,32,flags);
  }
  L005df0c2: { // 0x5df0c2: 7408 JZ 0x005df0cc
    if(integer::condition("JZ",flags)) goto L005df0cc;
  }
  L005df0c4: { // 0x5df0c4: 81fe13010000 CMP ESI,0x113
    (void)integer::sub(s.si,0x00000113u,32,flags);
  }
  L005df0ca: { // 0x5df0ca: 750d JNZ 0x005df0d9
    if(integer::condition("JNZ",flags)) goto L005df0d9;
  }
  L005df0cc: { // 0x5df0cc: 3d68040000 CMP EAX,0x468
    (void)integer::sub(s.ax,0x00000468u,32,flags);
  }
  L005df0d1: { // 0x5df0d1: 7506 JNZ 0x005df0d9
    if(integer::condition("JNZ",flags)) goto L005df0d9;
  }
  L005df0d3: { // 0x5df0d3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df0d4: { // 0x5df0d4: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005df0d6: { // 0x5df0d6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df0d7: { // 0x5df0d7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df0d8: { // 0x5df0d8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df0d9: { // 0x5df0d9: 81fee2000000 CMP ESI,0xe2
    (void)integer::sub(s.si,0x000000e2u,32,flags);
  }
  L005df0df: { // 0x5df0df: 7536 JNZ 0x005df117
    if(integer::condition("JNZ",flags)) goto L005df117;
  }
  L005df0e1: { // 0x5df0e1: 3d86060000 CMP EAX,0x686
    (void)integer::sub(s.ax,0x00000686u,32,flags);
  }
  L005df0e6: { // 0x5df0e6: 0f8454050000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df0ec: { // 0x5df0ec: 3d78050000 CMP EAX,0x578
    (void)integer::sub(s.ax,0x00000578u,32,flags);
  }
  L005df0f1: { // 0x5df0f1: 0f8449050000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df0f7: { // 0x5df0f7: 3d5c050000 CMP EAX,0x55c
    (void)integer::sub(s.ax,0x0000055cu,32,flags);
  }
  L005df0fc: { // 0x5df0fc: 0f843e050000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df102: { // 0x5df102: 3d83060000 CMP EAX,0x683
    (void)integer::sub(s.ax,0x00000683u,32,flags);
  }
  L005df107: { // 0x5df107: 0f8433050000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df10d: { // 0x5df10d: 3d84060000 CMP EAX,0x684
    (void)integer::sub(s.ax,0x00000684u,32,flags);
  }
  L005df112: { // 0x5df112: e92f040000 JMP 0x005df546
    goto L005df546;
  }
  L005df117: { // 0x5df117: 81fe01010000 CMP ESI,0x101
    (void)integer::sub(s.si,0x00000101u,32,flags);
  }
  L005df11d: { // 0x5df11d: 7520 JNZ 0x005df13f
    if(integer::condition("JNZ",flags)) goto L005df13f;
  }
  L005df11f: { // 0x5df11f: 3d8e060000 CMP EAX,0x68e
    (void)integer::sub(s.ax,0x0000068eu,32,flags);
  }
  L005df124: { // 0x5df124: 0f8416050000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df12a: { // 0x5df12a: 3d8d060000 CMP EAX,0x68d
    (void)integer::sub(s.ax,0x0000068du,32,flags);
  }
  L005df12f: { // 0x5df12f: 0f840b050000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df135: { // 0x5df135: 3d8f060000 CMP EAX,0x68f
    (void)integer::sub(s.ax,0x0000068fu,32,flags);
  }
  L005df13a: { // 0x5df13a: e907040000 JMP 0x005df546
    goto L005df546;
  }
  L005df13f: { // 0x5df13f: 81fe29010000 CMP ESI,0x129
    (void)integer::sub(s.si,0x00000129u,32,flags);
  }
  L005df145: { // 0x5df145: 7510 JNZ 0x005df157
    if(integer::condition("JNZ",flags)) goto L005df157;
  }
  L005df147: { // 0x5df147: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df149: { // 0x5df149: 3d45070000 CMP EAX,0x745
    (void)integer::sub(s.ax,0x00000745u,32,flags);
  }
  L005df14e: { // 0x5df14e: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df151: { // 0x5df151: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df152: { // 0x5df152: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df154: { // 0x5df154: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df155: { // 0x5df155: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df156: { // 0x5df156: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df157: { // 0x5df157: 81fe00010000 CMP ESI,0x100
    (void)integer::sub(s.si,0x00000100u,32,flags);
  }
  L005df15d: { // 0x5df15d: 7520 JNZ 0x005df17f
    if(integer::condition("JNZ",flags)) goto L005df17f;
  }
  L005df15f: { // 0x5df15f: 3d89060000 CMP EAX,0x689
    (void)integer::sub(s.ax,0x00000689u,32,flags);
  }
  L005df164: { // 0x5df164: 0f84d6040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df16a: { // 0x5df16a: 3d88060000 CMP EAX,0x688
    (void)integer::sub(s.ax,0x00000688u,32,flags);
  }
  L005df16f: { // 0x5df16f: 0f84cb040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df175: { // 0x5df175: 3d79050000 CMP EAX,0x579
    (void)integer::sub(s.ax,0x00000579u,32,flags);
  }
  L005df17a: { // 0x5df17a: e9c7030000 JMP 0x005df546
    goto L005df546;
  }
  L005df17f: { // 0x5df17f: 81fe94000000 CMP ESI,0x94
    (void)integer::sub(s.si,0x00000094u,32,flags);
  }
  L005df185: { // 0x5df185: 7510 JNZ 0x005df197
    if(integer::condition("JNZ",flags)) goto L005df197;
  }
  L005df187: { // 0x5df187: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df189: { // 0x5df189: 3d0e040000 CMP EAX,0x40e
    (void)integer::sub(s.ax,0x0000040eu,32,flags);
  }
  L005df18e: { // 0x5df18e: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df191: { // 0x5df191: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df192: { // 0x5df192: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df194: { // 0x5df194: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df195: { // 0x5df195: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df196: { // 0x5df196: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df197: { // 0x5df197: 81feb7000000 CMP ESI,0xb7
    (void)integer::sub(s.si,0x000000b7u,32,flags);
  }
  L005df19d: { // 0x5df19d: 7510 JNZ 0x005df1af
    if(integer::condition("JNZ",flags)) goto L005df1af;
  }
  L005df19f: { // 0x5df19f: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df1a1: { // 0x5df1a1: 3d0f040000 CMP EAX,0x40f
    (void)integer::sub(s.ax,0x0000040fu,32,flags);
  }
  L005df1a6: { // 0x5df1a6: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df1a9: { // 0x5df1a9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df1aa: { // 0x5df1aa: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df1ac: { // 0x5df1ac: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df1ad: { // 0x5df1ad: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df1ae: { // 0x5df1ae: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df1af: { // 0x5df1af: 81feb4020000 CMP ESI,0x2b4
    (void)integer::sub(s.si,0x000002b4u,32,flags);
  }
  L005df1b5: { // 0x5df1b5: 7510 JNZ 0x005df1c7
    if(integer::condition("JNZ",flags)) goto L005df1c7;
  }
  L005df1b7: { // 0x5df1b7: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df1b9: { // 0x5df1b9: 3dc7060000 CMP EAX,0x6c7
    (void)integer::sub(s.ax,0x000006c7u,32,flags);
  }
  L005df1be: { // 0x5df1be: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df1c1: { // 0x5df1c1: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df1c2: { // 0x5df1c2: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df1c4: { // 0x5df1c4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df1c5: { // 0x5df1c5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df1c6: { // 0x5df1c6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df1c7: { // 0x5df1c7: 81feb5020000 CMP ESI,0x2b5
    (void)integer::sub(s.si,0x000002b5u,32,flags);
  }
  L005df1cd: { // 0x5df1cd: 7510 JNZ 0x005df1df
    if(integer::condition("JNZ",flags)) goto L005df1df;
  }
  L005df1cf: { // 0x5df1cf: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df1d1: { // 0x5df1d1: 3dc8060000 CMP EAX,0x6c8
    (void)integer::sub(s.ax,0x000006c8u,32,flags);
  }
  L005df1d6: { // 0x5df1d6: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df1d9: { // 0x5df1d9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df1da: { // 0x5df1da: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df1dc: { // 0x5df1dc: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df1dd: { // 0x5df1dd: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df1de: { // 0x5df1de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df1df: { // 0x5df1df: 81fe05010000 CMP ESI,0x105
    (void)integer::sub(s.si,0x00000105u,32,flags);
  }
  L005df1e5: { // 0x5df1e5: 752b JNZ 0x005df212
    if(integer::condition("JNZ",flags)) goto L005df212;
  }
  L005df1e7: { // 0x5df1e7: 3dc4060000 CMP EAX,0x6c4
    (void)integer::sub(s.ax,0x000006c4u,32,flags);
  }
  L005df1ec: { // 0x5df1ec: 0f844e040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df1f2: { // 0x5df1f2: 3dc2060000 CMP EAX,0x6c2
    (void)integer::sub(s.ax,0x000006c2u,32,flags);
  }
  L005df1f7: { // 0x5df1f7: 0f8443040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df1fd: { // 0x5df1fd: 3dc3060000 CMP EAX,0x6c3
    (void)integer::sub(s.ax,0x000006c3u,32,flags);
  }
  L005df202: { // 0x5df202: 0f8438040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df208: { // 0x5df208: 3dc5060000 CMP EAX,0x6c5
    (void)integer::sub(s.ax,0x000006c5u,32,flags);
  }
  L005df20d: { // 0x5df20d: e934030000 JMP 0x005df546
    goto L005df546;
  }
  L005df212: { // 0x5df212: 81fe02010000 CMP ESI,0x102
    (void)integer::sub(s.si,0x00000102u,32,flags);
  }
  L005df218: { // 0x5df218: 752b JNZ 0x005df245
    if(integer::condition("JNZ",flags)) goto L005df245;
  }
  L005df21a: { // 0x5df21a: 3dec060000 CMP EAX,0x6ec
    (void)integer::sub(s.ax,0x000006ecu,32,flags);
  }
  L005df21f: { // 0x5df21f: 0f841b040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df225: { // 0x5df225: 3daa050000 CMP EAX,0x5aa
    (void)integer::sub(s.ax,0x000005aau,32,flags);
  }
  L005df22a: { // 0x5df22a: 0f8410040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df230: { // 0x5df230: 3da8050000 CMP EAX,0x5a8
    (void)integer::sub(s.ax,0x000005a8u,32,flags);
  }
  L005df235: { // 0x5df235: 0f8405040000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df23b: { // 0x5df23b: 3d17060000 CMP EAX,0x617
    (void)integer::sub(s.ax,0x00000617u,32,flags);
  }
  L005df240: { // 0x5df240: e901030000 JMP 0x005df546
    goto L005df546;
  }
  L005df245: { // 0x5df245: 81feb5000000 CMP ESI,0xb5
    (void)integer::sub(s.si,0x000000b5u,32,flags);
  }
  L005df24b: { // 0x5df24b: 7536 JNZ 0x005df283
    if(integer::condition("JNZ",flags)) goto L005df283;
  }
  L005df24d: { // 0x5df24d: 3d22050000 CMP EAX,0x522
    (void)integer::sub(s.ax,0x00000522u,32,flags);
  }
  L005df252: { // 0x5df252: 0f84e8030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df258: { // 0x5df258: 3d21050000 CMP EAX,0x521
    (void)integer::sub(s.ax,0x00000521u,32,flags);
  }
  L005df25d: { // 0x5df25d: 0f84dd030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df263: { // 0x5df263: 3d1e050000 CMP EAX,0x51e
    (void)integer::sub(s.ax,0x0000051eu,32,flags);
  }
  L005df268: { // 0x5df268: 0f84d2030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df26e: { // 0x5df26e: 3d1f050000 CMP EAX,0x51f
    (void)integer::sub(s.ax,0x0000051fu,32,flags);
  }
  L005df273: { // 0x5df273: 0f84c7030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df279: { // 0x5df279: 3d20050000 CMP EAX,0x520
    (void)integer::sub(s.ax,0x00000520u,32,flags);
  }
  L005df27e: { // 0x5df27e: e9c3020000 JMP 0x005df546
    goto L005df546;
  }
  L005df283: { // 0x5df283: 81feba0b0000 CMP ESI,0xbba
    (void)integer::sub(s.si,0x00000bbau,32,flags);
  }
  L005df289: { // 0x5df289: 7515 JNZ 0x005df2a0
    if(integer::condition("JNZ",flags)) goto L005df2a0;
  }
  L005df28b: { // 0x5df28b: 3d22050000 CMP EAX,0x522
    (void)integer::sub(s.ax,0x00000522u,32,flags);
  }
  L005df290: { // 0x5df290: 0f84aa030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df296: { // 0x5df296: 3d21050000 CMP EAX,0x521
    (void)integer::sub(s.ax,0x00000521u,32,flags);
  }
  L005df29b: { // 0x5df29b: e9a6020000 JMP 0x005df546
    goto L005df546;
  }
  L005df2a0: { // 0x5df2a0: 81febb0b0000 CMP ESI,0xbbb
    (void)integer::sub(s.si,0x00000bbbu,32,flags);
  }
  L005df2a6: { // 0x5df2a6: 7515 JNZ 0x005df2bd
    if(integer::condition("JNZ",flags)) goto L005df2bd;
  }
  L005df2a8: { // 0x5df2a8: 3d2c050000 CMP EAX,0x52c
    (void)integer::sub(s.ax,0x0000052cu,32,flags);
  }
  L005df2ad: { // 0x5df2ad: 0f848d030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df2b3: { // 0x5df2b3: 3d2d050000 CMP EAX,0x52d
    (void)integer::sub(s.ax,0x0000052du,32,flags);
  }
  L005df2b8: { // 0x5df2b8: e989020000 JMP 0x005df546
    goto L005df546;
  }
  L005df2bd: { // 0x5df2bd: 81fed5000000 CMP ESI,0xd5
    (void)integer::sub(s.si,0x000000d5u,32,flags);
  }
  L005df2c3: { // 0x5df2c3: 7515 JNZ 0x005df2da
    if(integer::condition("JNZ",flags)) goto L005df2da;
  }
  L005df2c5: { // 0x5df2c5: 3dce050000 CMP EAX,0x5ce
    (void)integer::sub(s.ax,0x000005ceu,32,flags);
  }
  L005df2ca: { // 0x5df2ca: 0f8470030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df2d0: { // 0x5df2d0: 3dcd050000 CMP EAX,0x5cd
    (void)integer::sub(s.ax,0x000005cdu,32,flags);
  }
  L005df2d5: { // 0x5df2d5: e96c020000 JMP 0x005df546
    goto L005df546;
  }
  L005df2da: { // 0x5df2da: 81fefb000000 CMP ESI,0xfb
    (void)integer::sub(s.si,0x000000fbu,32,flags);
  }
  L005df2e0: { // 0x5df2e0: 7511 JNZ 0x005df2f3
    if(integer::condition("JNZ",flags)) goto L005df2f3;
  }
  L005df2e2: { // 0x5df2e2: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L005df2e5: { // 0x5df2e5: 0f8455030000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df2eb: { // 0x5df2eb: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df2ee: { // 0x5df2ee: e953020000 JMP 0x005df546
    goto L005df546;
  }
  L005df2f3: { // 0x5df2f3: 81fed8000000 CMP ESI,0xd8
    (void)integer::sub(s.si,0x000000d8u,32,flags);
  }
  L005df2f9: { // 0x5df2f9: 7510 JNZ 0x005df30b
    if(integer::condition("JNZ",flags)) goto L005df30b;
  }
  L005df2fb: { // 0x5df2fb: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df2fd: { // 0x5df2fd: 3dcb060000 CMP EAX,0x6cb
    (void)integer::sub(s.ax,0x000006cbu,32,flags);
  }
  L005df302: { // 0x5df302: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df305: { // 0x5df305: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df306: { // 0x5df306: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df308: { // 0x5df308: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df309: { // 0x5df309: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df30a: { // 0x5df30a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df30b: { // 0x5df30b: 81fed7000000 CMP ESI,0xd7
    (void)integer::sub(s.si,0x000000d7u,32,flags);
  }
  L005df311: { // 0x5df311: 750e JNZ 0x005df321
    if(integer::condition("JNZ",flags)) goto L005df321;
  }
  L005df313: { // 0x5df313: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df315: { // 0x5df315: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df318: { // 0x5df318: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df31b: { // 0x5df31b: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df31c: { // 0x5df31c: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df31e: { // 0x5df31e: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df31f: { // 0x5df31f: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df320: { // 0x5df320: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df321: { // 0x5df321: 81febc000000 CMP ESI,0xbc
    (void)integer::sub(s.si,0x000000bcu,32,flags);
  }
  L005df327: { // 0x5df327: 0f84f1020000 JZ 0x005df61e
    if(integer::condition("JZ",flags)) goto L005df61e;
  }
  L005df32d: { // 0x5df32d: 81fec2000000 CMP ESI,0xc2
    (void)integer::sub(s.si,0x000000c2u,32,flags);
  }
  L005df333: { // 0x5df333: 0f84e5020000 JZ 0x005df61e
    if(integer::condition("JZ",flags)) goto L005df61e;
  }
  L005df339: { // 0x5df339: 81febd000000 CMP ESI,0xbd
    (void)integer::sub(s.si,0x000000bdu,32,flags);
  }
  L005df33f: { // 0x5df33f: 0f84be020000 JZ 0x005df603
    if(integer::condition("JZ",flags)) goto L005df603;
  }
  L005df345: { // 0x5df345: 81fec9000000 CMP ESI,0xc9
    (void)integer::sub(s.si,0x000000c9u,32,flags);
  }
  L005df34b: { // 0x5df34b: 0f84b2020000 JZ 0x005df603
    if(integer::condition("JZ",flags)) goto L005df603;
  }
  L005df351: { // 0x5df351: 81febb000000 CMP ESI,0xbb
    (void)integer::sub(s.si,0x000000bbu,32,flags);
  }
  L005df357: { // 0x5df357: 7515 JNZ 0x005df36e
    if(integer::condition("JNZ",flags)) goto L005df36e;
  }
  L005df359: { // 0x5df359: 3dcd060000 CMP EAX,0x6cd
    (void)integer::sub(s.ax,0x000006cdu,32,flags);
  }
  L005df35e: { // 0x5df35e: 0f84dc020000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df364: { // 0x5df364: 3dcc060000 CMP EAX,0x6cc
    (void)integer::sub(s.ax,0x000006ccu,32,flags);
  }
  L005df369: { // 0x5df369: e9d8010000 JMP 0x005df546
    goto L005df546;
  }
  L005df36e: { // 0x5df36e: 81feb6000000 CMP ESI,0xb6
    (void)integer::sub(s.si,0x000000b6u,32,flags);
  }
  L005df374: { // 0x5df374: 7520 JNZ 0x005df396
    if(integer::condition("JNZ",flags)) goto L005df396;
  }
  L005df376: { // 0x5df376: 3dc9060000 CMP EAX,0x6c9
    (void)integer::sub(s.ax,0x000006c9u,32,flags);
  }
  L005df37b: { // 0x5df37b: 0f84bf020000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df381: { // 0x5df381: 3d12070000 CMP EAX,0x712
    (void)integer::sub(s.ax,0x00000712u,32,flags);
  }
  L005df386: { // 0x5df386: 0f84b4020000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df38c: { // 0x5df38c: 3d24050000 CMP EAX,0x524
    (void)integer::sub(s.ax,0x00000524u,32,flags);
  }
  L005df391: { // 0x5df391: e9b0010000 JMP 0x005df546
    goto L005df546;
  }
  L005df396: { // 0x5df396: 83fe6b CMP ESI,0x6b
    (void)integer::sub(s.si,0x0000006bu,32,flags);
  }
  L005df399: { // 0x5df399: 7515 JNZ 0x005df3b0
    if(integer::condition("JNZ",flags)) goto L005df3b0;
  }
  L005df39b: { // 0x5df39b: 3d83050000 CMP EAX,0x583
    (void)integer::sub(s.ax,0x00000583u,32,flags);
  }
  L005df3a0: { // 0x5df3a0: 0f849a020000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df3a6: { // 0x5df3a6: 3dc5060000 CMP EAX,0x6c5
    (void)integer::sub(s.ax,0x000006c5u,32,flags);
  }
  L005df3ab: { // 0x5df3ab: e996010000 JMP 0x005df546
    goto L005df546;
  }
  L005df3b0: { // 0x5df3b0: 81fec60b0000 CMP ESI,0xbc6
    (void)integer::sub(s.si,0x00000bc6u,32,flags);
  }
  L005df3b6: { // 0x5df3b6: 7510 JNZ 0x005df3c8
    if(integer::condition("JNZ",flags)) goto L005df3c8;
  }
  L005df3b8: { // 0x5df3b8: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df3ba: { // 0x5df3ba: 3dd1060000 CMP EAX,0x6d1
    (void)integer::sub(s.ax,0x000006d1u,32,flags);
  }
  L005df3bf: { // 0x5df3bf: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df3c2: { // 0x5df3c2: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df3c3: { // 0x5df3c3: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df3c5: { // 0x5df3c5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df3c6: { // 0x5df3c6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df3c7: { // 0x5df3c7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df3c8: { // 0x5df3c8: 81fec70b0000 CMP ESI,0xbc7
    (void)integer::sub(s.si,0x00000bc7u,32,flags);
  }
  L005df3ce: { // 0x5df3ce: 7510 JNZ 0x005df3e0
    if(integer::condition("JNZ",flags)) goto L005df3e0;
  }
  L005df3d0: { // 0x5df3d0: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df3d2: { // 0x5df3d2: 3dd1060000 CMP EAX,0x6d1
    (void)integer::sub(s.ax,0x000006d1u,32,flags);
  }
  L005df3d7: { // 0x5df3d7: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df3da: { // 0x5df3da: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df3db: { // 0x5df3db: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df3dd: { // 0x5df3dd: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df3de: { // 0x5df3de: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df3df: { // 0x5df3df: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df3e0: { // 0x5df3e0: 81fe0f010000 CMP ESI,0x10f
    (void)integer::sub(s.si,0x0000010fu,32,flags);
  }
  L005df3e6: { // 0x5df3e6: 0f84f5010000 JZ 0x005df5e1
    if(integer::condition("JZ",flags)) goto L005df5e1;
  }
  L005df3ec: { // 0x5df3ec: 81fe1d010000 CMP ESI,0x11d
    (void)integer::sub(s.si,0x0000011du,32,flags);
  }
  L005df3f2: { // 0x5df3f2: 0f84e9010000 JZ 0x005df5e1
    if(integer::condition("JZ",flags)) goto L005df5e1;
  }
  L005df3f8: { // 0x5df3f8: 81fe09010000 CMP ESI,0x109
    (void)integer::sub(s.si,0x00000109u,32,flags);
  }
  L005df3fe: { // 0x5df3fe: 751e JNZ 0x005df41e
    if(integer::condition("JNZ",flags)) goto L005df41e;
  }
  L005df400: { // 0x5df400: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df403: { // 0x5df403: 0f8437020000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df409: { // 0x5df409: 3d25060000 CMP EAX,0x625
    (void)integer::sub(s.ax,0x00000625u,32,flags);
  }
  L005df40e: { // 0x5df40e: 0f842c020000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df414: { // 0x5df414: 3d3b050000 CMP EAX,0x53b
    (void)integer::sub(s.ax,0x0000053bu,32,flags);
  }
  L005df419: { // 0x5df419: e928010000 JMP 0x005df546
    goto L005df546;
  }
  L005df41e: { // 0x5df41e: 81fe0e010000 CMP ESI,0x10e
    (void)integer::sub(s.si,0x0000010eu,32,flags);
  }
  L005df424: { // 0x5df424: 0f848a010000 JZ 0x005df5b4
    if(integer::condition("JZ",flags)) goto L005df5b4;
  }
  L005df42a: { // 0x5df42a: 81fe1c010000 CMP ESI,0x11c
    (void)integer::sub(s.si,0x0000011cu,32,flags);
  }
  L005df430: { // 0x5df430: 0f847e010000 JZ 0x005df5b4
    if(integer::condition("JZ",flags)) goto L005df5b4;
  }
  L005df436: { // 0x5df436: 81fe14010000 CMP ESI,0x114
    (void)integer::sub(s.si,0x00000114u,32,flags);
  }
  L005df43c: { // 0x5df43c: 7536 JNZ 0x005df474
    if(integer::condition("JNZ",flags)) goto L005df474;
  }
  L005df43e: { // 0x5df43e: 3d87060000 CMP EAX,0x687
    (void)integer::sub(s.ax,0x00000687u,32,flags);
  }
  L005df443: { // 0x5df443: 0f84f7010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df449: { // 0x5df449: 3dea060000 CMP EAX,0x6ea
    (void)integer::sub(s.ax,0x000006eau,32,flags);
  }
  L005df44e: { // 0x5df44e: 0f84ec010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df454: { // 0x5df454: 3dec060000 CMP EAX,0x6ec
    (void)integer::sub(s.ax,0x000006ecu,32,flags);
  }
  L005df459: { // 0x5df459: 0f84e1010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df45f: { // 0x5df45f: 3deb060000 CMP EAX,0x6eb
    (void)integer::sub(s.ax,0x000006ebu,32,flags);
  }
  L005df464: { // 0x5df464: 0f84d6010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df46a: { // 0x5df46a: 3d88060000 CMP EAX,0x688
    (void)integer::sub(s.ax,0x00000688u,32,flags);
  }
  L005df46f: { // 0x5df46f: e9d2000000 JMP 0x005df546
    goto L005df546;
  }
  L005df474: { // 0x5df474: 81fe13010000 CMP ESI,0x113
    (void)integer::sub(s.si,0x00000113u,32,flags);
  }
  L005df47a: { // 0x5df47a: 7541 JNZ 0x005df4bd
    if(integer::condition("JNZ",flags)) goto L005df4bd;
  }
  L005df47c: { // 0x5df47c: 3d1f060000 CMP EAX,0x61f
    (void)integer::sub(s.ax,0x0000061fu,32,flags);
  }
  L005df481: { // 0x5df481: 0f84b9010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df487: { // 0x5df487: 3d58050000 CMP EAX,0x558
    (void)integer::sub(s.ax,0x00000558u,32,flags);
  }
  L005df48c: { // 0x5df48c: 0f84ae010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df492: { // 0x5df492: 3d89060000 CMP EAX,0x689
    (void)integer::sub(s.ax,0x00000689u,32,flags);
  }
  L005df497: { // 0x5df497: 0f84a3010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df49d: { // 0x5df49d: 3d2d060000 CMP EAX,0x62d
    (void)integer::sub(s.ax,0x0000062du,32,flags);
  }
  L005df4a2: { // 0x5df4a2: 0f8498010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df4a8: { // 0x5df4a8: 3d2b060000 CMP EAX,0x62b
    (void)integer::sub(s.ax,0x0000062bu,32,flags);
  }
  L005df4ad: { // 0x5df4ad: 0f848d010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df4b3: { // 0x5df4b3: 3d3d050000 CMP EAX,0x53d
    (void)integer::sub(s.ax,0x0000053du,32,flags);
  }
  L005df4b8: { // 0x5df4b8: e989000000 JMP 0x005df546
    goto L005df546;
  }
  L005df4bd: { // 0x5df4bd: 81febc020000 CMP ESI,0x2bc
    (void)integer::sub(s.si,0x000002bcu,32,flags);
  }
  L005df4c3: { // 0x5df4c3: 7510 JNZ 0x005df4d5
    if(integer::condition("JNZ",flags)) goto L005df4d5;
  }
  L005df4c5: { // 0x5df4c5: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df4c8: { // 0x5df4c8: 0f8472010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df4ce: { // 0x5df4ce: 3d3a060000 CMP EAX,0x63a
    (void)integer::sub(s.ax,0x0000063au,32,flags);
  }
  L005df4d3: { // 0x5df4d3: eb71 JMP 0x005df546
    goto L005df546;
  }
  L005df4d5: { // 0x5df4d5: 81fe16010000 CMP ESI,0x116
    (void)integer::sub(s.si,0x00000116u,32,flags);
  }
  L005df4db: { // 0x5df4db: 7533 JNZ 0x005df510
    if(integer::condition("JNZ",flags)) goto L005df510;
  }
  L005df4dd: { // 0x5df4dd: 3d2b060000 CMP EAX,0x62b
    (void)integer::sub(s.ax,0x0000062bu,32,flags);
  }
  L005df4e2: { // 0x5df4e2: 0f8458010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df4e8: { // 0x5df4e8: 3d2d060000 CMP EAX,0x62d
    (void)integer::sub(s.ax,0x0000062du,32,flags);
  }
  L005df4ed: { // 0x5df4ed: 0f844d010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df4f3: { // 0x5df4f3: 3dc2050000 CMP EAX,0x5c2
    (void)integer::sub(s.ax,0x000005c2u,32,flags);
  }
  L005df4f8: { // 0x5df4f8: 0f8442010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df4fe: { // 0x5df4fe: 3d02070000 CMP EAX,0x702
    (void)integer::sub(s.ax,0x00000702u,32,flags);
  }
  L005df503: { // 0x5df503: 0f8437010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df509: { // 0x5df509: 3d03070000 CMP EAX,0x703
    (void)integer::sub(s.ax,0x00000703u,32,flags);
  }
  L005df50e: { // 0x5df50e: eb36 JMP 0x005df546
    goto L005df546;
  }
  L005df510: { // 0x5df510: 81feff000000 CMP ESI,0xff
    (void)integer::sub(s.si,0x000000ffu,32,flags);
  }
  L005df516: { // 0x5df516: 7512 JNZ 0x005df52a
    if(integer::condition("JNZ",flags)) goto L005df52a;
  }
  L005df518: { // 0x5df518: 3d21050000 CMP EAX,0x521
    (void)integer::sub(s.ax,0x00000521u,32,flags);
  }
  L005df51d: { // 0x5df51d: 0f841d010000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df523: { // 0x5df523: 3d22050000 CMP EAX,0x522
    (void)integer::sub(s.ax,0x00000522u,32,flags);
  }
  L005df528: { // 0x5df528: eb1c JMP 0x005df546
    goto L005df546;
  }
  L005df52a: { // 0x5df52a: 81fe22010000 CMP ESI,0x122
    (void)integer::sub(s.si,0x00000122u,32,flags);
  }
  L005df530: { // 0x5df530: 7408 JZ 0x005df53a
    if(integer::condition("JZ",flags)) goto L005df53a;
  }
  L005df532: { // 0x5df532: 81fe12010000 CMP ESI,0x112
    (void)integer::sub(s.si,0x00000112u,32,flags);
  }
  L005df538: { // 0x5df538: 7518 JNZ 0x005df552
    if(integer::condition("JNZ",flags)) goto L005df552;
  }
  L005df53a: { // 0x5df53a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df53d: { // 0x5df53d: 0f84fd000000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df543: { // 0x5df543: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005df546: { // 0x5df546: 0f84f4000000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df54c: { // 0x5df54c: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df54d: { // 0x5df54d: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005df54f: { // 0x5df54f: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df550: { // 0x5df550: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df551: { // 0x5df551: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df552: { // 0x5df552: 81fee7000000 CMP ESI,0xe7
    (void)integer::sub(s.si,0x000000e7u,32,flags);
  }
  L005df558: { // 0x5df558: 751a JNZ 0x005df574
    if(integer::condition("JNZ",flags)) goto L005df574;
  }
  L005df55a: { // 0x5df55a: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df55d: { // 0x5df55d: 0f84dd000000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df563: { // 0x5df563: 3d76050000 CMP EAX,0x576
    (void)integer::sub(s.ax,0x00000576u,32,flags);
  }
  L005df568: { // 0x5df568: 0f84d2000000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df56e: { // 0x5df56e: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df56f: { // 0x5df56f: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005df571: { // 0x5df571: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df572: { // 0x5df572: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df573: { // 0x5df573: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df574: { // 0x5df574: 81fefe000000 CMP ESI,0xfe
    (void)integer::sub(s.si,0x000000feu,32,flags);
  }
  L005df57a: { // 0x5df57a: 750e JNZ 0x005df58a
    if(integer::condition("JNZ",flags)) goto L005df58a;
  }
  L005df57c: { // 0x5df57c: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df57e: { // 0x5df57e: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df581: { // 0x5df581: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df584: { // 0x5df584: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df585: { // 0x5df585: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df587: { // 0x5df587: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df588: { // 0x5df588: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df589: { // 0x5df589: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df58a: { // 0x5df58a: 81fee6000000 CMP ESI,0xe6
    (void)integer::sub(s.si,0x000000e6u,32,flags);
  }
  L005df590: { // 0x5df590: 0f847dfdffff JZ 0x005df313
    if(integer::condition("JZ",flags)) goto L005df313;
  }
  L005df596: { // 0x5df596: 81fef3000000 CMP ESI,0xf3
    (void)integer::sub(s.si,0x000000f3u,32,flags);
  }
  L005df59c: { // 0x5df59c: 0f8471fdffff JZ 0x005df313
    if(integer::condition("JZ",flags)) goto L005df313;
  }
  L005df5a2: { // 0x5df5a2: 81fef4000000 CMP ESI,0xf4
    (void)integer::sub(s.si,0x000000f4u,32,flags);
  }
  L005df5a8: { // 0x5df5a8: 0f8465fdffff JZ 0x005df313
    if(integer::condition("JZ",flags)) goto L005df313;
  }
  L005df5ae: { // 0x5df5ae: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df5af: { // 0x5df5af: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005df5b1: { // 0x5df5b1: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df5b2: { // 0x5df5b2: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df5b3: { // 0x5df5b3: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df5b4: { // 0x5df5b4: 3de0060000 CMP EAX,0x6e0
    (void)integer::sub(s.ax,0x000006e0u,32,flags);
  }
  L005df5b9: { // 0x5df5b9: 0f8481000000 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5bf: { // 0x5df5bf: 3de1060000 CMP EAX,0x6e1
    (void)integer::sub(s.ax,0x000006e1u,32,flags);
  }
  L005df5c4: { // 0x5df5c4: 747a JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5c6: { // 0x5df5c6: 3de2060000 CMP EAX,0x6e2
    (void)integer::sub(s.ax,0x000006e2u,32,flags);
  }
  L005df5cb: { // 0x5df5cb: 7473 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5cd: { // 0x5df5cd: 3de4060000 CMP EAX,0x6e4
    (void)integer::sub(s.ax,0x000006e4u,32,flags);
  }
  L005df5d2: { // 0x5df5d2: 746c JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5d4: { // 0x5df5d4: 3de3060000 CMP EAX,0x6e3
    (void)integer::sub(s.ax,0x000006e3u,32,flags);
  }
  L005df5d9: { // 0x5df5d9: 7465 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5db: { // 0x5df5db: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df5dc: { // 0x5df5dc: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005df5de: { // 0x5df5de: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df5df: { // 0x5df5df: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df5e0: { // 0x5df5e0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df5e1: { // 0x5df5e1: 3d39050000 CMP EAX,0x539
    (void)integer::sub(s.ax,0x00000539u,32,flags);
  }
  L005df5e6: { // 0x5df5e6: 7458 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5e8: { // 0x5df5e8: 3dea060000 CMP EAX,0x6ea
    (void)integer::sub(s.ax,0x000006eau,32,flags);
  }
  L005df5ed: { // 0x5df5ed: 7451 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5ef: { // 0x5df5ef: 3dec060000 CMP EAX,0x6ec
    (void)integer::sub(s.ax,0x000006ecu,32,flags);
  }
  L005df5f4: { // 0x5df5f4: 744a JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5f6: { // 0x5df5f6: 3deb060000 CMP EAX,0x6eb
    (void)integer::sub(s.ax,0x000006ebu,32,flags);
  }
  L005df5fb: { // 0x5df5fb: 7443 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df5fd: { // 0x5df5fd: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df5fe: { // 0x5df5fe: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005df600: { // 0x5df600: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df601: { // 0x5df601: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df602: { // 0x5df602: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df603: { // 0x5df603: 3d9f050000 CMP EAX,0x59f
    (void)integer::sub(s.ax,0x0000059fu,32,flags);
  }
  L005df608: { // 0x5df608: 7436 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df60a: { // 0x5df60a: 3dec060000 CMP EAX,0x6ec
    (void)integer::sub(s.ax,0x000006ecu,32,flags);
  }
  L005df60f: { // 0x5df60f: 742f JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df611: { // 0x5df611: 3da8050000 CMP EAX,0x5a8
    (void)integer::sub(s.ax,0x000005a8u,32,flags);
  }
  L005df616: { // 0x5df616: 7428 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df618: { // 0x5df618: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df619: { // 0x5df619: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005df61b: { // 0x5df61b: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df61c: { // 0x5df61c: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df61d: { // 0x5df61d: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df61e: { // 0x5df61e: 3dec060000 CMP EAX,0x6ec
    (void)integer::sub(s.ax,0x000006ecu,32,flags);
  }
  L005df623: { // 0x5df623: 741b JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df625: { // 0x5df625: 3d88050000 CMP EAX,0x588
    (void)integer::sub(s.ax,0x00000588u,32,flags);
  }
  L005df62a: { // 0x5df62a: 7414 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df62c: { // 0x5df62c: 3daa050000 CMP EAX,0x5aa
    (void)integer::sub(s.ax,0x000005aau,32,flags);
  }
  L005df631: { // 0x5df631: 740d JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df633: { // 0x5df633: 3da8050000 CMP EAX,0x5a8
    (void)integer::sub(s.ax,0x000005a8u,32,flags);
  }
  L005df638: { // 0x5df638: 7406 JZ 0x005df640
    if(integer::condition("JZ",flags)) goto L005df640;
  }
  L005df63a: { // 0x5df63a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df63b: { // 0x5df63b: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005df63d: { // 0x5df63d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df63e: { // 0x5df63e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df63f: { // 0x5df63f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df640: { // 0x5df640: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df641: { // 0x5df641: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L005df646: { // 0x5df646: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df647: { // 0x5df647: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df648: { // 0x5df648: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005df6e0(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005df6e0: { // 0x5df6e0: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005df6e1: { // 0x5df6e1: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005df6e6: { // 0x5df6e6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005df6e7: { // 0x5df6e7: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005df6e9: { // 0x5df6e9: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005df6ea: { // 0x5df6ea: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005df6ec: { // 0x5df6ec: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005df6ee: { // 0x5df6ee: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L005df6f2: { // 0x5df6f2: 7441 JZ 0x005df735
    if(integer::condition("JZ",flags)) goto L005df735;
  }
  L005df6f4: { // 0x5df6f4: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L005df6f8: { // 0x5df6f8: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6158078u); flags=s.arithmetic_flags;
  }
  L005df6fe: { // 0x5df6fe: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005df704: { // 0x5df704: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005df709: { // 0x5df709: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005df70b: { // 0x5df70b: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005df70c: { // 0x5df70c: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005df70e: { // 0x5df70e: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005df713: { // 0x5df713: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005df716: { // 0x5df716: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005df718: { // 0x5df718: 741b JZ 0x005df735
    if(integer::condition("JZ",flags)) goto L005df735;
  }
  L005df71a: { // 0x5df71a: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005df71e: { // 0x5df71e: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005df720: { // 0x5df720: 740c JZ 0x005df72e
    if(integer::condition("JZ",flags)) goto L005df72e;
  }
  L005df722: { // 0x5df722: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005df728: { // 0x5df728: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005df72a: { // 0x5df72a: 75f2 JNZ 0x005df71e
    if(integer::condition("JNZ",flags)) goto L005df71e;
  }
  L005df72c: { // 0x5df72c: eb07 JMP 0x005df735
    goto L005df735;
  }
  L005df72e: { // 0x5df72e: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005df730: { // 0x5df730: 7403 JZ 0x005df735
    if(integer::condition("JZ",flags)) goto L005df735;
  }
  L005df732: { // 0x5df732: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005df735: { // 0x5df735: 8b766c MOV ESI,dword ptr [ESI + 0x6c]
    s.si = m.r32((s.si+0x0000006cu));
  }
  L005df738: { // 0x5df738: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005df739: { // 0x5df739: ff15f4537800 CALL dword ptr [0x007853f4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007853f4u)),6158143u); flags=s.arithmetic_flags;
  }
  L005df73f: { // 0x5df73f: 81fee2000000 CMP ESI,0xe2
    (void)integer::sub(s.si,0x000000e2u,32,flags);
  }
  L005df745: { // 0x5df745: 7510 JNZ 0x005df757
    if(integer::condition("JNZ",flags)) goto L005df757;
  }
  L005df747: { // 0x5df747: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df749: { // 0x5df749: 3dee030000 CMP EAX,0x3ee
    (void)integer::sub(s.ax,0x000003eeu,32,flags);
  }
  L005df74e: { // 0x5df74e: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df751: { // 0x5df751: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df752: { // 0x5df752: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df754: { // 0x5df754: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df755: { // 0x5df755: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df756: { // 0x5df756: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df757: { // 0x5df757: 83fe73 CMP ESI,0x73
    (void)integer::sub(s.si,0x00000073u,32,flags);
  }
  L005df75a: { // 0x5df75a: 0f84bd020000 JZ 0x005dfa1d
    if(integer::condition("JZ",flags)) goto L005dfa1d;
  }
  L005df760: { // 0x5df760: 81fe0c010000 CMP ESI,0x10c
    (void)integer::sub(s.si,0x0000010cu,32,flags);
  }
  L005df766: { // 0x5df766: 0f84b1020000 JZ 0x005dfa1d
    if(integer::condition("JZ",flags)) goto L005dfa1d;
  }
  L005df76c: { // 0x5df76c: 81fe03010000 CMP ESI,0x103
    (void)integer::sub(s.si,0x00000103u,32,flags);
  }
  L005df772: { // 0x5df772: 0f84a5020000 JZ 0x005dfa1d
    if(integer::condition("JZ",flags)) goto L005dfa1d;
  }
  L005df778: { // 0x5df778: 81fe08010000 CMP ESI,0x108
    (void)integer::sub(s.si,0x00000108u,32,flags);
  }
  L005df77e: { // 0x5df77e: 7510 JNZ 0x005df790
    if(integer::condition("JNZ",flags)) goto L005df790;
  }
  L005df780: { // 0x5df780: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df782: { // 0x5df782: 3dd1060000 CMP EAX,0x6d1
    (void)integer::sub(s.ax,0x000006d1u,32,flags);
  }
  L005df787: { // 0x5df787: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df78a: { // 0x5df78a: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df78b: { // 0x5df78b: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df78d: { // 0x5df78d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df78e: { // 0x5df78e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df78f: { // 0x5df78f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df790: { // 0x5df790: 81fe94000000 CMP ESI,0x94
    (void)integer::sub(s.si,0x00000094u,32,flags);
  }
  L005df796: { // 0x5df796: 0f8471020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df79c: { // 0x5df79c: 81feb6000000 CMP ESI,0xb6
    (void)integer::sub(s.si,0x000000b6u,32,flags);
  }
  L005df7a2: { // 0x5df7a2: 0f8465020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7a8: { // 0x5df7a8: 81fea3000000 CMP ESI,0xa3
    (void)integer::sub(s.si,0x000000a3u,32,flags);
  }
  L005df7ae: { // 0x5df7ae: 0f8459020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7b4: { // 0x5df7b4: 81fed8000000 CMP ESI,0xd8
    (void)integer::sub(s.si,0x000000d8u,32,flags);
  }
  L005df7ba: { // 0x5df7ba: 0f844d020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7c0: { // 0x5df7c0: 81febb0b0000 CMP ESI,0xbbb
    (void)integer::sub(s.si,0x00000bbbu,32,flags);
  }
  L005df7c6: { // 0x5df7c6: 0f8441020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7cc: { // 0x5df7cc: 81fef5000000 CMP ESI,0xf5
    (void)integer::sub(s.si,0x000000f5u,32,flags);
  }
  L005df7d2: { // 0x5df7d2: 0f8435020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7d8: { // 0x5df7d8: 81fed5000000 CMP ESI,0xd5
    (void)integer::sub(s.si,0x000000d5u,32,flags);
  }
  L005df7de: { // 0x5df7de: 0f8429020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7e4: { // 0x5df7e4: 81feb5020000 CMP ESI,0x2b5
    (void)integer::sub(s.si,0x000002b5u,32,flags);
  }
  L005df7ea: { // 0x5df7ea: 0f841d020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7f0: { // 0x5df7f0: 81feb7000000 CMP ESI,0xb7
    (void)integer::sub(s.si,0x000000b7u,32,flags);
  }
  L005df7f6: { // 0x5df7f6: 0f8411020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df7fc: { // 0x5df7fc: 81feb4020000 CMP ESI,0x2b4
    (void)integer::sub(s.si,0x000002b4u,32,flags);
  }
  L005df802: { // 0x5df802: 0f8405020000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df808: { // 0x5df808: 81fe01010000 CMP ESI,0x101
    (void)integer::sub(s.si,0x00000101u,32,flags);
  }
  L005df80e: { // 0x5df80e: 0f84f9010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df814: { // 0x5df814: 81fe29010000 CMP ESI,0x129
    (void)integer::sub(s.si,0x00000129u,32,flags);
  }
  L005df81a: { // 0x5df81a: 0f84ed010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df820: { // 0x5df820: 81feb5000000 CMP ESI,0xb5
    (void)integer::sub(s.si,0x000000b5u,32,flags);
  }
  L005df826: { // 0x5df826: 0f84e1010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df82c: { // 0x5df82c: 81feba0b0000 CMP ESI,0xbba
    (void)integer::sub(s.si,0x00000bbau,32,flags);
  }
  L005df832: { // 0x5df832: 0f84d5010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df838: { // 0x5df838: 81fe00010000 CMP ESI,0x100
    (void)integer::sub(s.si,0x00000100u,32,flags);
  }
  L005df83e: { // 0x5df83e: 0f84c9010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df844: { // 0x5df844: 81feb8000000 CMP ESI,0xb8
    (void)integer::sub(s.si,0x000000b8u,32,flags);
  }
  L005df84a: { // 0x5df84a: 0f84bd010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df850: { // 0x5df850: 81fed6000000 CMP ESI,0xd6
    (void)integer::sub(s.si,0x000000d6u,32,flags);
  }
  L005df856: { // 0x5df856: 0f84b1010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df85c: { // 0x5df85c: 81fe25010000 CMP ESI,0x125
    (void)integer::sub(s.si,0x00000125u,32,flags);
  }
  L005df862: { // 0x5df862: 0f84a5010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df868: { // 0x5df868: 81fe16010000 CMP ESI,0x116
    (void)integer::sub(s.si,0x00000116u,32,flags);
  }
  L005df86e: { // 0x5df86e: 0f8499010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df874: { // 0x5df874: 81fe1d010000 CMP ESI,0x11d
    (void)integer::sub(s.si,0x0000011du,32,flags);
  }
  L005df87a: { // 0x5df87a: 0f848d010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df880: { // 0x5df880: 81fe1c010000 CMP ESI,0x11c
    (void)integer::sub(s.si,0x0000011cu,32,flags);
  }
  L005df886: { // 0x5df886: 0f8481010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df88c: { // 0x5df88c: 81fe13010000 CMP ESI,0x113
    (void)integer::sub(s.si,0x00000113u,32,flags);
  }
  L005df892: { // 0x5df892: 0f8475010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df898: { // 0x5df898: 81fe09010000 CMP ESI,0x109
    (void)integer::sub(s.si,0x00000109u,32,flags);
  }
  L005df89e: { // 0x5df89e: 0f8469010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df8a4: { // 0x5df8a4: 81fe0f010000 CMP ESI,0x10f
    (void)integer::sub(s.si,0x0000010fu,32,flags);
  }
  L005df8aa: { // 0x5df8aa: 0f845d010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df8b0: { // 0x5df8b0: 81fe14010000 CMP ESI,0x114
    (void)integer::sub(s.si,0x00000114u,32,flags);
  }
  L005df8b6: { // 0x5df8b6: 0f8451010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df8bc: { // 0x5df8bc: 81fe0e010000 CMP ESI,0x10e
    (void)integer::sub(s.si,0x0000010eu,32,flags);
  }
  L005df8c2: { // 0x5df8c2: 0f8445010000 JZ 0x005dfa0d
    if(integer::condition("JZ",flags)) goto L005dfa0d;
  }
  L005df8c8: { // 0x5df8c8: 81fe02010000 CMP ESI,0x102
    (void)integer::sub(s.si,0x00000102u,32,flags);
  }
  L005df8ce: { // 0x5df8ce: 0f8429010000 JZ 0x005df9fd
    if(integer::condition("JZ",flags)) goto L005df9fd;
  }
  L005df8d4: { // 0x5df8d4: 81fe05010000 CMP ESI,0x105
    (void)integer::sub(s.si,0x00000105u,32,flags);
  }
  L005df8da: { // 0x5df8da: 0f841d010000 JZ 0x005df9fd
    if(integer::condition("JZ",flags)) goto L005df9fd;
  }
  L005df8e0: { // 0x5df8e0: 83fe6b CMP ESI,0x6b
    (void)integer::sub(s.si,0x0000006bu,32,flags);
  }
  L005df8e3: { // 0x5df8e3: 0f8414010000 JZ 0x005df9fd
    if(integer::condition("JZ",flags)) goto L005df9fd;
  }
  L005df8e9: { // 0x5df8e9: 81febb000000 CMP ESI,0xbb
    (void)integer::sub(s.si,0x000000bbu,32,flags);
  }
  L005df8ef: { // 0x5df8ef: 0f8408010000 JZ 0x005df9fd
    if(integer::condition("JZ",flags)) goto L005df9fd;
  }
  L005df8f5: { // 0x5df8f5: 81fe17010000 CMP ESI,0x117
    (void)integer::sub(s.si,0x00000117u,32,flags);
  }
  L005df8fb: { // 0x5df8fb: 0f84fc000000 JZ 0x005df9fd
    if(integer::condition("JZ",flags)) goto L005df9fd;
  }
  L005df901: { // 0x5df901: 81fec60b0000 CMP ESI,0xbc6
    (void)integer::sub(s.si,0x00000bc6u,32,flags);
  }
  L005df907: { // 0x5df907: 0f84f0000000 JZ 0x005df9fd
    if(integer::condition("JZ",flags)) goto L005df9fd;
  }
  L005df90d: { // 0x5df90d: 81febc000000 CMP ESI,0xbc
    (void)integer::sub(s.si,0x000000bcu,32,flags);
  }
  L005df913: { // 0x5df913: 0f84d6000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df919: { // 0x5df919: 81febd000000 CMP ESI,0xbd
    (void)integer::sub(s.si,0x000000bdu,32,flags);
  }
  L005df91f: { // 0x5df91f: 0f84ca000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df925: { // 0x5df925: 81feea000000 CMP ESI,0xea
    (void)integer::sub(s.si,0x000000eau,32,flags);
  }
  L005df92b: { // 0x5df92b: 0f84be000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df931: { // 0x5df931: 81fed7000000 CMP ESI,0xd7
    (void)integer::sub(s.si,0x000000d7u,32,flags);
  }
  L005df937: { // 0x5df937: 0f84b2000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df93d: { // 0x5df93d: 81fec2000000 CMP ESI,0xc2
    (void)integer::sub(s.si,0x000000c2u,32,flags);
  }
  L005df943: { // 0x5df943: 0f84a6000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df949: { // 0x5df949: 81fec9000000 CMP ESI,0xc9
    (void)integer::sub(s.si,0x000000c9u,32,flags);
  }
  L005df94f: { // 0x5df94f: 0f849a000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df955: { // 0x5df955: 81febc020000 CMP ESI,0x2bc
    (void)integer::sub(s.si,0x000002bcu,32,flags);
  }
  L005df95b: { // 0x5df95b: 0f848e000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df961: { // 0x5df961: 81fee7000000 CMP ESI,0xe7
    (void)integer::sub(s.si,0x000000e7u,32,flags);
  }
  L005df967: { // 0x5df967: 0f8482000000 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df96d: { // 0x5df96d: 81fee6000000 CMP ESI,0xe6
    (void)integer::sub(s.si,0x000000e6u,32,flags);
  }
  L005df973: { // 0x5df973: 747a JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df975: { // 0x5df975: 81fef3000000 CMP ESI,0xf3
    (void)integer::sub(s.si,0x000000f3u,32,flags);
  }
  L005df97b: { // 0x5df97b: 7472 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df97d: { // 0x5df97d: 81fef4000000 CMP ESI,0xf4
    (void)integer::sub(s.si,0x000000f4u,32,flags);
  }
  L005df983: { // 0x5df983: 746a JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df985: { // 0x5df985: 81fe22010000 CMP ESI,0x122
    (void)integer::sub(s.si,0x00000122u,32,flags);
  }
  L005df98b: { // 0x5df98b: 7462 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df98d: { // 0x5df98d: 81fe12010000 CMP ESI,0x112
    (void)integer::sub(s.si,0x00000112u,32,flags);
  }
  L005df993: { // 0x5df993: 745a JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df995: { // 0x5df995: 81fefe000000 CMP ESI,0xfe
    (void)integer::sub(s.si,0x000000feu,32,flags);
  }
  L005df99b: { // 0x5df99b: 7452 JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df99d: { // 0x5df99d: 81fefc000000 CMP ESI,0xfc
    (void)integer::sub(s.si,0x000000fcu,32,flags);
  }
  L005df9a3: { // 0x5df9a3: 744a JZ 0x005df9ef
    if(integer::condition("JZ",flags)) goto L005df9ef;
  }
  L005df9a5: { // 0x5df9a5: 81fed4000000 CMP ESI,0xd4
    (void)integer::sub(s.si,0x000000d4u,32,flags);
  }
  L005df9ab: { // 0x5df9ab: 750e JNZ 0x005df9bb
    if(integer::condition("JNZ",flags)) goto L005df9bb;
  }
  L005df9ad: { // 0x5df9ad: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df9af: { // 0x5df9af: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005df9b2: { // 0x5df9b2: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df9b5: { // 0x5df9b5: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df9b6: { // 0x5df9b6: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df9b8: { // 0x5df9b8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df9b9: { // 0x5df9b9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df9ba: { // 0x5df9ba: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df9bb: { // 0x5df9bb: 81fefb000000 CMP ESI,0xfb
    (void)integer::sub(s.si,0x000000fbu,32,flags);
  }
  L005df9c1: { // 0x5df9c1: 750e JNZ 0x005df9d1
    if(integer::condition("JNZ",flags)) goto L005df9d1;
  }
  L005df9c3: { // 0x5df9c3: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df9c5: { // 0x5df9c5: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L005df9c8: { // 0x5df9c8: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df9cb: { // 0x5df9cb: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df9cc: { // 0x5df9cc: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df9ce: { // 0x5df9ce: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df9cf: { // 0x5df9cf: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df9d0: { // 0x5df9d0: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df9d1: { // 0x5df9d1: 81feff000000 CMP ESI,0xff
    (void)integer::sub(s.si,0x000000ffu,32,flags);
  }
  L005df9d7: { // 0x5df9d7: 7510 JNZ 0x005df9e9
    if(integer::condition("JNZ",flags)) goto L005df9e9;
  }
  L005df9d9: { // 0x5df9d9: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df9db: { // 0x5df9db: 3d75060000 CMP EAX,0x675
    (void)integer::sub(s.ax,0x00000675u,32,flags);
  }
  L005df9e0: { // 0x5df9e0: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df9e3: { // 0x5df9e3: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df9e4: { // 0x5df9e4: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005df9e6: { // 0x5df9e6: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df9e7: { // 0x5df9e7: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df9e8: { // 0x5df9e8: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df9e9: { // 0x5df9e9: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df9ea: { // 0x5df9ea: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005df9ec: { // 0x5df9ec: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df9ed: { // 0x5df9ed: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df9ee: { // 0x5df9ee: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df9ef: { // 0x5df9ef: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005df9f1: { // 0x5df9f1: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005df9f4: { // 0x5df9f4: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005df9f7: { // 0x5df9f7: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005df9f8: { // 0x5df9f8: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005df9fa: { // 0x5df9fa: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005df9fb: { // 0x5df9fb: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005df9fc: { // 0x5df9fc: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005df9fd: { // 0x5df9fd: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005df9ff: { // 0x5df9ff: 3dc0050000 CMP EAX,0x5c0
    (void)integer::sub(s.ax,0x000005c0u,32,flags);
  }
  L005dfa04: { // 0x5dfa04: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005dfa07: { // 0x5dfa07: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005dfa08: { // 0x5dfa08: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005dfa0a: { // 0x5dfa0a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005dfa0b: { // 0x5dfa0b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005dfa0c: { // 0x5dfa0c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005dfa0d: { // 0x5dfa0d: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005dfa0f: { // 0x5dfa0f: 3d86060000 CMP EAX,0x686
    (void)integer::sub(s.ax,0x00000686u,32,flags);
  }
  L005dfa14: { // 0x5dfa14: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005dfa17: { // 0x5dfa17: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005dfa18: { // 0x5dfa18: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005dfa1a: { // 0x5dfa1a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005dfa1b: { // 0x5dfa1b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005dfa1c: { // 0x5dfa1c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005dfa1d: { // 0x5dfa1d: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005dfa1f: { // 0x5dfa1f: 3d23040000 CMP EAX,0x423
    (void)integer::sub(s.ax,0x00000423u,32,flags);
  }
  L005dfa24: { // 0x5dfa24: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005dfa27: { // 0x5dfa27: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005dfa28: { // 0x5dfa28: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005dfa2a: { // 0x5dfa2a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005dfa2b: { // 0x5dfa2b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005dfa2c: { // 0x5dfa2c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005dfd80(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005dfd80: { // 0x5dfd80: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005dfd81: { // 0x5dfd81: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005dfd86: { // 0x5dfd86: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005dfd87: { // 0x5dfd87: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005dfd89: { // 0x5dfd89: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005dfd8a: { // 0x5dfd8a: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005dfd8c: { // 0x5dfd8c: 8bfa MOV EDI,EDX
    s.di = s.dx;
  }
  L005dfd8e: { // 0x5dfd8e: 894c2408 MOV dword ptr [ESP + 0x8],ECX
    m.w32((f.sp+0x00000008u), s.cx);
  }
  L005dfd92: { // 0x5dfd92: 7441 JZ 0x005dfdd5
    if(integer::condition("JZ",flags)) goto L005dfdd5;
  }
  L005dfd94: { // 0x5dfd94: 8d4c2408 LEA ECX,[ESP + 0x8]
    s.cx = (f.sp+0x00000008u);
  }
  L005dfd98: { // 0x5dfd98: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6159774u); flags=s.arithmetic_flags;
  }
  L005dfd9e: { // 0x5dfd9e: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005dfda4: { // 0x5dfda4: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005dfda9: { // 0x5dfda9: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005dfdab: { // 0x5dfdab: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005dfdac: { // 0x5dfdac: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005dfdae: { // 0x5dfdae: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005dfdb3: { // 0x5dfdb3: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005dfdb6: { // 0x5dfdb6: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005dfdb8: { // 0x5dfdb8: 741b JZ 0x005dfdd5
    if(integer::condition("JZ",flags)) goto L005dfdd5;
  }
  L005dfdba: { // 0x5dfdba: 8b4c2408 MOV ECX,dword ptr [ESP + 0x8]
    s.cx = m.r32((f.sp+0x00000008u));
  }
  L005dfdbe: { // 0x5dfdbe: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005dfdc0: { // 0x5dfdc0: 740c JZ 0x005dfdce
    if(integer::condition("JZ",flags)) goto L005dfdce;
  }
  L005dfdc2: { // 0x5dfdc2: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005dfdc8: { // 0x5dfdc8: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005dfdca: { // 0x5dfdca: 75f2 JNZ 0x005dfdbe
    if(integer::condition("JNZ",flags)) goto L005dfdbe;
  }
  L005dfdcc: { // 0x5dfdcc: eb07 JMP 0x005dfdd5
    goto L005dfdd5;
  }
  L005dfdce: { // 0x5dfdce: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005dfdd0: { // 0x5dfdd0: 7403 JZ 0x005dfdd5
    if(integer::condition("JZ",flags)) goto L005dfdd5;
  }
  L005dfdd2: { // 0x5dfdd2: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005dfdd5: { // 0x5dfdd5: 8b766c MOV ESI,dword ptr [ESI + 0x6c]
    s.si = m.r32((s.si+0x0000006cu));
  }
  L005dfdd8: { // 0x5dfdd8: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005dfdd9: { // 0x5dfdd9: ff15f4537800 CALL dword ptr [0x007853f4]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x007853f4u)),6159839u); flags=s.arithmetic_flags;
  }
  L005dfddf: { // 0x5dfddf: 81fe0d010000 CMP ESI,0x10d
    (void)integer::sub(s.si,0x0000010du,32,flags);
  }
  L005dfde5: { // 0x5dfde5: 7515 JNZ 0x005dfdfc
    if(integer::condition("JNZ",flags)) goto L005dfdfc;
  }
  L005dfde7: { // 0x5dfde7: 3dc1050000 CMP EAX,0x5c1
    (void)integer::sub(s.ax,0x000005c1u,32,flags);
  }
  L005dfdec: { // 0x5dfdec: 0f8455020000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfdf2: { // 0x5dfdf2: 3dc0050000 CMP EAX,0x5c0
    (void)integer::sub(s.ax,0x000005c0u,32,flags);
  }
  L005dfdf7: { // 0x5dfdf7: e943020000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dfdfc: { // 0x5dfdfc: 81fed9000000 CMP ESI,0xd9
    (void)integer::sub(s.si,0x000000d9u,32,flags);
  }
  L005dfe02: { // 0x5dfe02: 7515 JNZ 0x005dfe19
    if(integer::condition("JNZ",flags)) goto L005dfe19;
  }
  L005dfe04: { // 0x5dfe04: 3dc1050000 CMP EAX,0x5c1
    (void)integer::sub(s.ax,0x000005c1u,32,flags);
  }
  L005dfe09: { // 0x5dfe09: 0f8438020000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfe0f: { // 0x5dfe0f: 3dca060000 CMP EAX,0x6ca
    (void)integer::sub(s.ax,0x000006cau,32,flags);
  }
  L005dfe14: { // 0x5dfe14: e926020000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dfe19: { // 0x5dfe19: 81fea3000000 CMP ESI,0xa3
    (void)integer::sub(s.si,0x000000a3u,32,flags);
  }
  L005dfe1f: { // 0x5dfe1f: 7515 JNZ 0x005dfe36
    if(integer::condition("JNZ",flags)) goto L005dfe36;
  }
  L005dfe21: { // 0x5dfe21: 3dcf040000 CMP EAX,0x4cf
    (void)integer::sub(s.ax,0x000004cfu,32,flags);
  }
  L005dfe26: { // 0x5dfe26: 0f841b020000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfe2c: { // 0x5dfe2c: 3dd0040000 CMP EAX,0x4d0
    (void)integer::sub(s.ax,0x000004d0u,32,flags);
  }
  L005dfe31: { // 0x5dfe31: e909020000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dfe36: { // 0x5dfe36: 81fe05010000 CMP ESI,0x105
    (void)integer::sub(s.si,0x00000105u,32,flags);
  }
  L005dfe3c: { // 0x5dfe3c: 7515 JNZ 0x005dfe53
    if(integer::condition("JNZ",flags)) goto L005dfe53;
  }
  L005dfe3e: { // 0x5dfe3e: 3d20060000 CMP EAX,0x620
    (void)integer::sub(s.ax,0x00000620u,32,flags);
  }
  L005dfe43: { // 0x5dfe43: 0f84fe010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfe49: { // 0x5dfe49: 3d21060000 CMP EAX,0x621
    (void)integer::sub(s.ax,0x00000621u,32,flags);
  }
  L005dfe4e: { // 0x5dfe4e: e9ec010000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dfe53: { // 0x5dfe53: 81fef0000000 CMP ESI,0xf0
    (void)integer::sub(s.si,0x000000f0u,32,flags);
  }
  L005dfe59: { // 0x5dfe59: 7510 JNZ 0x005dfe6b
    if(integer::condition("JNZ",flags)) goto L005dfe6b;
  }
  L005dfe5b: { // 0x5dfe5b: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005dfe5d: { // 0x5dfe5d: 3dc0050000 CMP EAX,0x5c0
    (void)integer::sub(s.ax,0x000005c0u,32,flags);
  }
  L005dfe62: { // 0x5dfe62: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005dfe65: { // 0x5dfe65: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005dfe66: { // 0x5dfe66: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005dfe68: { // 0x5dfe68: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005dfe69: { // 0x5dfe69: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005dfe6a: { // 0x5dfe6a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005dfe6b: { // 0x5dfe6b: 81fece000000 CMP ESI,0xce
    (void)integer::sub(s.si,0x000000ceu,32,flags);
  }
  L005dfe71: { // 0x5dfe71: 7510 JNZ 0x005dfe83
    if(integer::condition("JNZ",flags)) goto L005dfe83;
  }
  L005dfe73: { // 0x5dfe73: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005dfe75: { // 0x5dfe75: 3dae050000 CMP EAX,0x5ae
    (void)integer::sub(s.ax,0x000005aeu,32,flags);
  }
  L005dfe7a: { // 0x5dfe7a: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005dfe7d: { // 0x5dfe7d: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005dfe7e: { // 0x5dfe7e: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005dfe80: { // 0x5dfe80: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005dfe81: { // 0x5dfe81: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005dfe82: { // 0x5dfe82: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005dfe83: { // 0x5dfe83: 81fe20010000 CMP ESI,0x120
    (void)integer::sub(s.si,0x00000120u,32,flags);
  }
  L005dfe89: { // 0x5dfe89: 7513 JNZ 0x005dfe9e
    if(integer::condition("JNZ",flags)) goto L005dfe9e;
  }
  L005dfe8b: { // 0x5dfe8b: 3dae050000 CMP EAX,0x5ae
    (void)integer::sub(s.ax,0x000005aeu,32,flags);
  }
  L005dfe90: { // 0x5dfe90: 0f84b1010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfe96: { // 0x5dfe96: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005dfe99: { // 0x5dfe99: e9a1010000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dfe9e: { // 0x5dfe9e: 81fe21010000 CMP ESI,0x121
    (void)integer::sub(s.si,0x00000121u,32,flags);
  }
  L005dfea4: { // 0x5dfea4: 751e JNZ 0x005dfec4
    if(integer::condition("JNZ",flags)) goto L005dfec4;
  }
  L005dfea6: { // 0x5dfea6: 3dae050000 CMP EAX,0x5ae
    (void)integer::sub(s.ax,0x000005aeu,32,flags);
  }
  L005dfeab: { // 0x5dfeab: 0f8496010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfeb1: { // 0x5dfeb1: 3daf050000 CMP EAX,0x5af
    (void)integer::sub(s.ax,0x000005afu,32,flags);
  }
  L005dfeb6: { // 0x5dfeb6: 0f848b010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfebc: { // 0x5dfebc: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005dfebf: { // 0x5dfebf: e97b010000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dfec4: { // 0x5dfec4: 81feea000000 CMP ESI,0xea
    (void)integer::sub(s.si,0x000000eau,32,flags);
  }
  L005dfeca: { // 0x5dfeca: 7557 JNZ 0x005dff23
    if(integer::condition("JNZ",flags)) goto L005dff23;
  }
  L005dfecc: { // 0x5dfecc: 3d40060000 CMP EAX,0x640
    (void)integer::sub(s.ax,0x00000640u,32,flags);
  }
  L005dfed1: { // 0x5dfed1: 0f8470010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfed7: { // 0x5dfed7: 3d42060000 CMP EAX,0x642
    (void)integer::sub(s.ax,0x00000642u,32,flags);
  }
  L005dfedc: { // 0x5dfedc: 0f8465010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfee2: { // 0x5dfee2: 3d41060000 CMP EAX,0x641
    (void)integer::sub(s.ax,0x00000641u,32,flags);
  }
  L005dfee7: { // 0x5dfee7: 0f845a010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfeed: { // 0x5dfeed: 3d43060000 CMP EAX,0x643
    (void)integer::sub(s.ax,0x00000643u,32,flags);
  }
  L005dfef2: { // 0x5dfef2: 0f844f010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dfef8: { // 0x5dfef8: 3d44060000 CMP EAX,0x644
    (void)integer::sub(s.ax,0x00000644u,32,flags);
  }
  L005dfefd: { // 0x5dfefd: 0f8444010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dff03: { // 0x5dff03: 3d45060000 CMP EAX,0x645
    (void)integer::sub(s.ax,0x00000645u,32,flags);
  }
  L005dff08: { // 0x5dff08: 0f8439010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dff0e: { // 0x5dff0e: 3d46060000 CMP EAX,0x646
    (void)integer::sub(s.ax,0x00000646u,32,flags);
  }
  L005dff13: { // 0x5dff13: 0f842e010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dff19: { // 0x5dff19: 3d47060000 CMP EAX,0x647
    (void)integer::sub(s.ax,0x00000647u,32,flags);
  }
  L005dff1e: { // 0x5dff1e: e91c010000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dff23: { // 0x5dff23: 81feb8000000 CMP ESI,0xb8
    (void)integer::sub(s.si,0x000000b8u,32,flags);
  }
  L005dff29: { // 0x5dff29: 7515 JNZ 0x005dff40
    if(integer::condition("JNZ",flags)) goto L005dff40;
  }
  L005dff2b: { // 0x5dff2b: 3d31050000 CMP EAX,0x531
    (void)integer::sub(s.ax,0x00000531u,32,flags);
  }
  L005dff30: { // 0x5dff30: 0f8411010000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dff36: { // 0x5dff36: 3d35050000 CMP EAX,0x535
    (void)integer::sub(s.ax,0x00000535u,32,flags);
  }
  L005dff3b: { // 0x5dff3b: e9ff000000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dff40: { // 0x5dff40: 81fe1f010000 CMP ESI,0x11f
    (void)integer::sub(s.si,0x0000011fu,32,flags);
  }
  L005dff46: { // 0x5dff46: 7510 JNZ 0x005dff58
    if(integer::condition("JNZ",flags)) goto L005dff58;
  }
  L005dff48: { // 0x5dff48: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005dff4a: { // 0x5dff4a: 3dc0050000 CMP EAX,0x5c0
    (void)integer::sub(s.ax,0x000005c0u,32,flags);
  }
  L005dff4f: { // 0x5dff4f: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005dff52: { // 0x5dff52: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005dff53: { // 0x5dff53: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005dff55: { // 0x5dff55: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005dff56: { // 0x5dff56: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005dff57: { // 0x5dff57: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005dff58: { // 0x5dff58: 81fe15010000 CMP ESI,0x115
    (void)integer::sub(s.si,0x00000115u,32,flags);
  }
  L005dff5e: { // 0x5dff5e: 7515 JNZ 0x005dff75
    if(integer::condition("JNZ",flags)) goto L005dff75;
  }
  L005dff60: { // 0x5dff60: 3d02070000 CMP EAX,0x702
    (void)integer::sub(s.ax,0x00000702u,32,flags);
  }
  L005dff65: { // 0x5dff65: 0f84dc000000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dff6b: { // 0x5dff6b: 3d86060000 CMP EAX,0x686
    (void)integer::sub(s.ax,0x00000686u,32,flags);
  }
  L005dff70: { // 0x5dff70: e9ca000000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dff75: { // 0x5dff75: 81fed3000000 CMP ESI,0xd3
    (void)integer::sub(s.si,0x000000d3u,32,flags);
  }
  L005dff7b: { // 0x5dff7b: 750e JNZ 0x005dff8b
    if(integer::condition("JNZ",flags)) goto L005dff8b;
  }
  L005dff7d: { // 0x5dff7d: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005dff7f: { // 0x5dff7f: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005dff82: { // 0x5dff82: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005dff85: { // 0x5dff85: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005dff86: { // 0x5dff86: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005dff88: { // 0x5dff88: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005dff89: { // 0x5dff89: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005dff8a: { // 0x5dff8a: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005dff8b: { // 0x5dff8b: 81fecf000000 CMP ESI,0xcf
    (void)integer::sub(s.si,0x000000cfu,32,flags);
  }
  L005dff91: { // 0x5dff91: 7513 JNZ 0x005dffa6
    if(integer::condition("JNZ",flags)) goto L005dffa6;
  }
  L005dff93: { // 0x5dff93: 3dc2050000 CMP EAX,0x5c2
    (void)integer::sub(s.ax,0x000005c2u,32,flags);
  }
  L005dff98: { // 0x5dff98: 0f84a9000000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dff9e: { // 0x5dff9e: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005dffa1: { // 0x5dffa1: e999000000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dffa6: { // 0x5dffa6: 81fec3000000 CMP ESI,0xc3
    (void)integer::sub(s.si,0x000000c3u,32,flags);
  }
  L005dffac: { // 0x5dffac: 7511 JNZ 0x005dffbf
    if(integer::condition("JNZ",flags)) goto L005dffbf;
  }
  L005dffae: { // 0x5dffae: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005dffb1: { // 0x5dffb1: 0f8490000000 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dffb7: { // 0x5dffb7: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005dffba: { // 0x5dffba: e980000000 JMP 0x005e003f
    goto L005e003f;
  }
  L005dffbf: { // 0x5dffbf: 81fe1b010000 CMP ESI,0x11b
    (void)integer::sub(s.si,0x0000011bu,32,flags);
  }
  L005dffc5: { // 0x5dffc5: 750e JNZ 0x005dffd5
    if(integer::condition("JNZ",flags)) goto L005dffd5;
  }
  L005dffc7: { // 0x5dffc7: 3dc2050000 CMP EAX,0x5c2
    (void)integer::sub(s.ax,0x000005c2u,32,flags);
  }
  L005dffcc: { // 0x5dffcc: 7479 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dffce: { // 0x5dffce: 3d86060000 CMP EAX,0x686
    (void)integer::sub(s.ax,0x00000686u,32,flags);
  }
  L005dffd3: { // 0x5dffd3: eb6a JMP 0x005e003f
    goto L005e003f;
  }
  L005dffd5: { // 0x5dffd5: 81fee1000000 CMP ESI,0xe1
    (void)integer::sub(s.si,0x000000e1u,32,flags);
  }
  L005dffdb: { // 0x5dffdb: 750a JNZ 0x005dffe7
    if(integer::condition("JNZ",flags)) goto L005dffe7;
  }
  L005dffdd: { // 0x5dffdd: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005dffe0: { // 0x5dffe0: 7465 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005dffe2: { // 0x5dffe2: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005dffe5: { // 0x5dffe5: eb58 JMP 0x005e003f
    goto L005e003f;
  }
  L005dffe7: { // 0x5dffe7: 81fe1e010000 CMP ESI,0x11e
    (void)integer::sub(s.si,0x0000011eu,32,flags);
  }
  L005dffed: { // 0x5dffed: 74d8 JZ 0x005dffc7
    if(integer::condition("JZ",flags)) goto L005dffc7;
  }
  L005dffef: { // 0x5dffef: 81fec4000000 CMP ESI,0xc4
    (void)integer::sub(s.si,0x000000c4u,32,flags);
  }
  L005dfff5: { // 0x5dfff5: 7510 JNZ 0x005e0007
    if(integer::condition("JNZ",flags)) goto L005e0007;
  }
  L005dfff7: { // 0x5dfff7: 33c9 XOR ECX,ECX
    s.cx = integer::logical((s.cx)^(s.cx),32,flags);
  }
  L005dfff9: { // 0x5dfff9: 3d8d050000 CMP EAX,0x58d
    (void)integer::sub(s.ax,0x0000058du,32,flags);
  }
  L005dfffe: { // 0x5dfffe: 0f94c1 SETZ CL
    s.cx = with_al(s.cx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005e0001: { // 0x5e0001: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005e0002: { // 0x5e0002: 8ac1 MOV AL,CL
    s.ax = with_al(s.ax, (s.cx & 0xffu));
  }
  L005e0004: { // 0x5e0004: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e0005: { // 0x5e0005: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e0006: { // 0x5e0006: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e0007: { // 0x5e0007: 81fed0000000 CMP ESI,0xd0
    (void)integer::sub(s.si,0x000000d0u,32,flags);
  }
  L005e000d: { // 0x5e000d: 750e JNZ 0x005e001d
    if(integer::condition("JNZ",flags)) goto L005e001d;
  }
  L005e000f: { // 0x5e000f: 33d2 XOR EDX,EDX
    s.dx = integer::logical((s.dx)^(s.dx),32,flags);
  }
  L005e0011: { // 0x5e0011: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005e0014: { // 0x5e0014: 0f94c2 SETZ DL
    s.dx = with_al(s.dx, (integer::condition("SETZ",flags)?1u:0u));
  }
  L005e0017: { // 0x5e0017: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005e0018: { // 0x5e0018: 8ac2 MOV AL,DL
    s.ax = with_al(s.ax, (s.dx & 0xffu));
  }
  L005e001a: { // 0x5e001a: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e001b: { // 0x5e001b: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e001c: { // 0x5e001c: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e001d: { // 0x5e001d: 81fefc000000 CMP ESI,0xfc
    (void)integer::sub(s.si,0x000000fcu,32,flags);
  }
  L005e0023: { // 0x5e0023: 750a JNZ 0x005e002f
    if(integer::condition("JNZ",flags)) goto L005e002f;
  }
  L005e0025: { // 0x5e0025: 83f801 CMP EAX,0x1
    (void)integer::sub(s.ax,0x00000001u,32,flags);
  }
  L005e0028: { // 0x5e0028: 741d JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005e002a: { // 0x5e002a: 83f802 CMP EAX,0x2
    (void)integer::sub(s.ax,0x00000002u,32,flags);
  }
  L005e002d: { // 0x5e002d: eb10 JMP 0x005e003f
    goto L005e003f;
  }
  L005e002f: { // 0x5e002f: 81fe26010000 CMP ESI,0x126
    (void)integer::sub(s.si,0x00000126u,32,flags);
  }
  L005e0035: { // 0x5e0035: 7519 JNZ 0x005e0050
    if(integer::condition("JNZ",flags)) goto L005e0050;
  }
  L005e0037: { // 0x5e0037: 83f806 CMP EAX,0x6
    (void)integer::sub(s.ax,0x00000006u,32,flags);
  }
  L005e003a: { // 0x5e003a: 740b JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005e003c: { // 0x5e003c: 83f807 CMP EAX,0x7
    (void)integer::sub(s.ax,0x00000007u,32,flags);
  }
  L005e003f: { // 0x5e003f: 7406 JZ 0x005e0047
    if(integer::condition("JZ",flags)) goto L005e0047;
  }
  L005e0041: { // 0x5e0041: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005e0042: { // 0x5e0042: 33c0 XOR EAX,EAX
    s.ax = integer::logical((s.ax)^(s.ax),32,flags);
  }
  L005e0044: { // 0x5e0044: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e0045: { // 0x5e0045: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e0046: { // 0x5e0046: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e0047: { // 0x5e0047: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005e0048: { // 0x5e0048: b801000000 MOV EAX,0x1
    s.ax = 0x00000001u;
  }
  L005e004d: { // 0x5e004d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e004e: { // 0x5e004e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e004f: { // 0x5e004f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e0050: { // 0x5e0050: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005e0051: { // 0x5e0051: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005e0053: { // 0x5e0053: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e0054: { // 0x5e0054: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e0055: { // 0x5e0055: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
