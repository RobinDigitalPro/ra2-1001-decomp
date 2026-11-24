#include "recovered/recovery_b625_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b625 {
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
default:throw std::domain_error("recovery625 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005e2290(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005e2290: { // 0x5e2290: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005e2291: { // 0x5e2291: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005e2296: { // 0x5e2296: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005e2297: { // 0x5e2297: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005e2299: { // 0x5e2299: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L005e229d: { // 0x5e229d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e229f: { // 0x5e229f: 7441 JZ 0x005e22e2
    if(integer::condition("JZ",flags)) goto L005e22e2;
  }
  L005e22a1: { // 0x5e22a1: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L005e22a5: { // 0x5e22a5: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6169259u); flags=s.arithmetic_flags;
  }
  L005e22ab: { // 0x5e22ab: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005e22b1: { // 0x5e22b1: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005e22b6: { // 0x5e22b6: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e22b8: { // 0x5e22b8: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005e22b9: { // 0x5e22b9: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005e22bb: { // 0x5e22bb: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005e22c0: { // 0x5e22c0: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005e22c3: { // 0x5e22c3: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e22c5: { // 0x5e22c5: 741b JZ 0x005e22e2
    if(integer::condition("JZ",flags)) goto L005e22e2;
  }
  L005e22c7: { // 0x5e22c7: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L005e22cb: { // 0x5e22cb: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005e22cd: { // 0x5e22cd: 740c JZ 0x005e22db
    if(integer::condition("JZ",flags)) goto L005e22db;
  }
  L005e22cf: { // 0x5e22cf: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005e22d5: { // 0x5e22d5: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e22d7: { // 0x5e22d7: 75f2 JNZ 0x005e22cb
    if(integer::condition("JNZ",flags)) goto L005e22cb;
  }
  L005e22d9: { // 0x5e22d9: eb07 JMP 0x005e22e2
    goto L005e22e2;
  }
  L005e22db: { // 0x5e22db: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e22dd: { // 0x5e22dd: 7403 JZ 0x005e22e2
    if(integer::condition("JZ",flags)) goto L005e22e2;
  }
  L005e22df: { // 0x5e22df: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005e22e2: { // 0x5e22e2: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L005e22e5: { // 0x5e22e5: 3d0c010000 CMP EAX,0x10c
    (void)integer::sub(s.ax,0x0000010cu,32,flags);
  }
  L005e22ea: { // 0x5e22ea: 0f840b020000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e22f0: { // 0x5e22f0: 3d94000000 CMP EAX,0x94
    (void)integer::sub(s.ax,0x00000094u,32,flags);
  }
  L005e22f5: { // 0x5e22f5: 0f8400020000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e22fb: { // 0x5e22fb: 3db6000000 CMP EAX,0xb6
    (void)integer::sub(s.ax,0x000000b6u,32,flags);
  }
  L005e2300: { // 0x5e2300: 0f84f5010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2306: { // 0x5e2306: 3da3000000 CMP EAX,0xa3
    (void)integer::sub(s.ax,0x000000a3u,32,flags);
  }
  L005e230b: { // 0x5e230b: 0f84ea010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2311: { // 0x5e2311: 83f873 CMP EAX,0x73
    (void)integer::sub(s.ax,0x00000073u,32,flags);
  }
  L005e2314: { // 0x5e2314: 0f84e1010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e231a: { // 0x5e231a: 3dd8000000 CMP EAX,0xd8
    (void)integer::sub(s.ax,0x000000d8u,32,flags);
  }
  L005e231f: { // 0x5e231f: 0f84d6010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2325: { // 0x5e2325: 3dbb0b0000 CMP EAX,0xbbb
    (void)integer::sub(s.ax,0x00000bbbu,32,flags);
  }
  L005e232a: { // 0x5e232a: 0f84cb010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2330: { // 0x5e2330: 3df5000000 CMP EAX,0xf5
    (void)integer::sub(s.ax,0x000000f5u,32,flags);
  }
  L005e2335: { // 0x5e2335: 0f84c0010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e233b: { // 0x5e233b: 3d05010000 CMP EAX,0x105
    (void)integer::sub(s.ax,0x00000105u,32,flags);
  }
  L005e2340: { // 0x5e2340: 0f84b5010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2346: { // 0x5e2346: 3dd5000000 CMP EAX,0xd5
    (void)integer::sub(s.ax,0x000000d5u,32,flags);
  }
  L005e234b: { // 0x5e234b: 0f84aa010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2351: { // 0x5e2351: 3de2000000 CMP EAX,0xe2
    (void)integer::sub(s.ax,0x000000e2u,32,flags);
  }
  L005e2356: { // 0x5e2356: 0f849f010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e235c: { // 0x5e235c: 3db5020000 CMP EAX,0x2b5
    (void)integer::sub(s.ax,0x000002b5u,32,flags);
  }
  L005e2361: { // 0x5e2361: 0f8494010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2367: { // 0x5e2367: 3db7000000 CMP EAX,0xb7
    (void)integer::sub(s.ax,0x000000b7u,32,flags);
  }
  L005e236c: { // 0x5e236c: 0f8489010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2372: { // 0x5e2372: 3db4020000 CMP EAX,0x2b4
    (void)integer::sub(s.ax,0x000002b4u,32,flags);
  }
  L005e2377: { // 0x5e2377: 0f847e010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e237d: { // 0x5e237d: 3d01010000 CMP EAX,0x101
    (void)integer::sub(s.ax,0x00000101u,32,flags);
  }
  L005e2382: { // 0x5e2382: 0f8473010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2388: { // 0x5e2388: 3d29010000 CMP EAX,0x129
    (void)integer::sub(s.ax,0x00000129u,32,flags);
  }
  L005e238d: { // 0x5e238d: 0f8468010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2393: { // 0x5e2393: 3dc60b0000 CMP EAX,0xbc6
    (void)integer::sub(s.ax,0x00000bc6u,32,flags);
  }
  L005e2398: { // 0x5e2398: 0f845d010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e239e: { // 0x5e239e: 3dc70b0000 CMP EAX,0xbc7
    (void)integer::sub(s.ax,0x00000bc7u,32,flags);
  }
  L005e23a3: { // 0x5e23a3: 0f8452010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23a9: { // 0x5e23a9: 3d0b010000 CMP EAX,0x10b
    (void)integer::sub(s.ax,0x0000010bu,32,flags);
  }
  L005e23ae: { // 0x5e23ae: 0f8447010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23b4: { // 0x5e23b4: 3dd7000000 CMP EAX,0xd7
    (void)integer::sub(s.ax,0x000000d7u,32,flags);
  }
  L005e23b9: { // 0x5e23b9: 0f843c010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23bf: { // 0x5e23bf: 3d08010000 CMP EAX,0x108
    (void)integer::sub(s.ax,0x00000108u,32,flags);
  }
  L005e23c4: { // 0x5e23c4: 0f8431010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23ca: { // 0x5e23ca: 3dbc000000 CMP EAX,0xbc
    (void)integer::sub(s.ax,0x000000bcu,32,flags);
  }
  L005e23cf: { // 0x5e23cf: 0f8426010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23d5: { // 0x5e23d5: 3dbd000000 CMP EAX,0xbd
    (void)integer::sub(s.ax,0x000000bdu,32,flags);
  }
  L005e23da: { // 0x5e23da: 0f841b010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23e0: { // 0x5e23e0: 3dbb000000 CMP EAX,0xbb
    (void)integer::sub(s.ax,0x000000bbu,32,flags);
  }
  L005e23e5: { // 0x5e23e5: 0f8410010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23eb: { // 0x5e23eb: 3db5000000 CMP EAX,0xb5
    (void)integer::sub(s.ax,0x000000b5u,32,flags);
  }
  L005e23f0: { // 0x5e23f0: 0f8405010000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e23f6: { // 0x5e23f6: 3dba0b0000 CMP EAX,0xbba
    (void)integer::sub(s.ax,0x00000bbau,32,flags);
  }
  L005e23fb: { // 0x5e23fb: 0f84fa000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2401: { // 0x5e2401: 3dff000000 CMP EAX,0xff
    (void)integer::sub(s.ax,0x000000ffu,32,flags);
  }
  L005e2406: { // 0x5e2406: 0f84ef000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e240c: { // 0x5e240c: 3dea000000 CMP EAX,0xea
    (void)integer::sub(s.ax,0x000000eau,32,flags);
  }
  L005e2411: { // 0x5e2411: 0f84e4000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2417: { // 0x5e2417: 83f86b CMP EAX,0x6b
    (void)integer::sub(s.ax,0x0000006bu,32,flags);
  }
  L005e241a: { // 0x5e241a: 0f84db000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2420: { // 0x5e2420: 3d00010000 CMP EAX,0x100
    (void)integer::sub(s.ax,0x00000100u,32,flags);
  }
  L005e2425: { // 0x5e2425: 0f84d0000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e242b: { // 0x5e242b: 3d02010000 CMP EAX,0x102
    (void)integer::sub(s.ax,0x00000102u,32,flags);
  }
  L005e2430: { // 0x5e2430: 0f84c5000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2436: { // 0x5e2436: 3db8000000 CMP EAX,0xb8
    (void)integer::sub(s.ax,0x000000b8u,32,flags);
  }
  L005e243b: { // 0x5e243b: 0f84ba000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2441: { // 0x5e2441: 3dd6000000 CMP EAX,0xd6
    (void)integer::sub(s.ax,0x000000d6u,32,flags);
  }
  L005e2446: { // 0x5e2446: 0f84af000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e244c: { // 0x5e244c: 3d03010000 CMP EAX,0x103
    (void)integer::sub(s.ax,0x00000103u,32,flags);
  }
  L005e2451: { // 0x5e2451: 0f84a4000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2457: { // 0x5e2457: 3dd4000000 CMP EAX,0xd4
    (void)integer::sub(s.ax,0x000000d4u,32,flags);
  }
  L005e245c: { // 0x5e245c: 0f8499000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2462: { // 0x5e2462: 3d25010000 CMP EAX,0x125
    (void)integer::sub(s.ax,0x00000125u,32,flags);
  }
  L005e2467: { // 0x5e2467: 0f848e000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e246d: { // 0x5e246d: 3d22010000 CMP EAX,0x122
    (void)integer::sub(s.ax,0x00000122u,32,flags);
  }
  L005e2472: { // 0x5e2472: 0f8483000000 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2478: { // 0x5e2478: 3d12010000 CMP EAX,0x112
    (void)integer::sub(s.ax,0x00000112u,32,flags);
  }
  L005e247d: { // 0x5e247d: 747c JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e247f: { // 0x5e247f: 3de7000000 CMP EAX,0xe7
    (void)integer::sub(s.ax,0x000000e7u,32,flags);
  }
  L005e2484: { // 0x5e2484: 7475 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2486: { // 0x5e2486: 3d16010000 CMP EAX,0x116
    (void)integer::sub(s.ax,0x00000116u,32,flags);
  }
  L005e248b: { // 0x5e248b: 746e JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e248d: { // 0x5e248d: 3dc2000000 CMP EAX,0xc2
    (void)integer::sub(s.ax,0x000000c2u,32,flags);
  }
  L005e2492: { // 0x5e2492: 7467 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e2494: { // 0x5e2494: 3dc9000000 CMP EAX,0xc9
    (void)integer::sub(s.ax,0x000000c9u,32,flags);
  }
  L005e2499: { // 0x5e2499: 7460 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e249b: { // 0x5e249b: 3d13010000 CMP EAX,0x113
    (void)integer::sub(s.ax,0x00000113u,32,flags);
  }
  L005e24a0: { // 0x5e24a0: 7459 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24a2: { // 0x5e24a2: 3dfe000000 CMP EAX,0xfe
    (void)integer::sub(s.ax,0x000000feu,32,flags);
  }
  L005e24a7: { // 0x5e24a7: 7452 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24a9: { // 0x5e24a9: 3d0f010000 CMP EAX,0x10f
    (void)integer::sub(s.ax,0x0000010fu,32,flags);
  }
  L005e24ae: { // 0x5e24ae: 744b JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24b0: { // 0x5e24b0: 3d1d010000 CMP EAX,0x11d
    (void)integer::sub(s.ax,0x0000011du,32,flags);
  }
  L005e24b5: { // 0x5e24b5: 7444 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24b7: { // 0x5e24b7: 3d1c010000 CMP EAX,0x11c
    (void)integer::sub(s.ax,0x0000011cu,32,flags);
  }
  L005e24bc: { // 0x5e24bc: 743d JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24be: { // 0x5e24be: 3d17010000 CMP EAX,0x117
    (void)integer::sub(s.ax,0x00000117u,32,flags);
  }
  L005e24c3: { // 0x5e24c3: 7436 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24c5: { // 0x5e24c5: 3d14010000 CMP EAX,0x114
    (void)integer::sub(s.ax,0x00000114u,32,flags);
  }
  L005e24ca: { // 0x5e24ca: 742f JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24cc: { // 0x5e24cc: 3de6000000 CMP EAX,0xe6
    (void)integer::sub(s.ax,0x000000e6u,32,flags);
  }
  L005e24d1: { // 0x5e24d1: 7428 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24d3: { // 0x5e24d3: 3df3000000 CMP EAX,0xf3
    (void)integer::sub(s.ax,0x000000f3u,32,flags);
  }
  L005e24d8: { // 0x5e24d8: 7421 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24da: { // 0x5e24da: 3df4000000 CMP EAX,0xf4
    (void)integer::sub(s.ax,0x000000f4u,32,flags);
  }
  L005e24df: { // 0x5e24df: 741a JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24e1: { // 0x5e24e1: 3dbc020000 CMP EAX,0x2bc
    (void)integer::sub(s.ax,0x000002bcu,32,flags);
  }
  L005e24e6: { // 0x5e24e6: 7413 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24e8: { // 0x5e24e8: 3d0e010000 CMP EAX,0x10e
    (void)integer::sub(s.ax,0x0000010eu,32,flags);
  }
  L005e24ed: { // 0x5e24ed: 740c JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24ef: { // 0x5e24ef: 3dfb000000 CMP EAX,0xfb
    (void)integer::sub(s.ax,0x000000fbu,32,flags);
  }
  L005e24f4: { // 0x5e24f4: 7405 JZ 0x005e24fb
    if(integer::condition("JZ",flags)) goto L005e24fb;
  }
  L005e24f6: { // 0x5e24f6: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005e24f8: { // 0x5e24f8: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e24f9: { // 0x5e24f9: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e24fa: { // 0x5e24fa: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e24fb: { // 0x5e24fb: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005e24fd: { // 0x5e24fd: c786b000000001000000 MOV dword ptr [ESI + 0xb0],0x1
    m.w32((s.si+0x000000b0u), 0x00000001u);
  }
  L005e2507: { // 0x5e2507: 8886bd000000 MOV byte ptr [ESI + 0xbd],AL
    m.w8((s.si+0x000000bdu), (s.ax & 0xffu));
  }
  L005e250d: { // 0x5e250d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e250e: { // 0x5e250e: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e250f: { // 0x5e250f: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}

std::uint32_t fun_005e2510(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005e2510: { // 0x5e2510: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005e2511: { // 0x5e2511: a1a4b1a500 MOV EAX,[0x00a5b1a4]
    s.ax = m.r32((0x00a5b1a4u));
  }
  L005e2516: { // 0x5e2516: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005e2517: { // 0x5e2517: 33f6 XOR ESI,ESI
    s.si = integer::logical((s.si)^(s.si),32,flags);
  }
  L005e2519: { // 0x5e2519: 894c2404 MOV dword ptr [ESP + 0x4],ECX
    m.w32((f.sp+0x00000004u), s.cx);
  }
  L005e251d: { // 0x5e251d: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e251f: { // 0x5e251f: 7441 JZ 0x005e2562
    if(integer::condition("JZ",flags)) goto L005e2562;
  }
  L005e2521: { // 0x5e2521: 8d4c2404 LEA ECX,[ESP + 0x4]
    s.cx = (f.sp+0x00000004u);
  }
  L005e2525: { // 0x5e2525: ff15b8b1a500 CALL dword ptr [0x00a5b1b8]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((0x00a5b1b8u)),6169899u); flags=s.arithmetic_flags;
  }
  L005e252b: { // 0x5e252b: 8b0dacb1a500 MOV ECX,dword ptr [0x00a5b1ac]
    s.cx = m.r32((0x00a5b1acu));
  }
  L005e2531: { // 0x5e2531: ba01000000 MOV EDX,0x1
    s.dx = 0x00000001u;
  }
  L005e2536: { // 0x5e2536: d3e2 SHL EDX,CL
    s.dx = integer::shift(s.dx,(s.cx & 0xffu),32,flags,integer::Shift::left);
  }
  L005e2538: { // 0x5e2538: 4a DEC EDX
    s.dx = integer::decrement(s.dx,32,flags);
  }
  L005e2539: { // 0x5e2539: 23d0 AND EDX,EAX
    s.dx = integer::logical((s.dx)&(s.ax),32,flags);
  }
  L005e253b: { // 0x5e253b: a1a0b1a500 MOV EAX,[0x00a5b1a0]
    s.ax = m.r32((0x00a5b1a0u));
  }
  L005e2540: { // 0x5e2540: 8b0490 MOV EAX,dword ptr [EAX + EDX*0x4]
    s.ax = m.r32((s.ax+(s.dx * 0x00000004u)));
  }
  L005e2543: { // 0x5e2543: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2545: { // 0x5e2545: 741b JZ 0x005e2562
    if(integer::condition("JZ",flags)) goto L005e2562;
  }
  L005e2547: { // 0x5e2547: 8b4c2404 MOV ECX,dword ptr [ESP + 0x4]
    s.cx = m.r32((f.sp+0x00000004u));
  }
  L005e254b: { // 0x5e254b: 3908 CMP dword ptr [EAX],ECX
    (void)integer::sub(m.r32((s.ax)),s.cx,32,flags);
  }
  L005e254d: { // 0x5e254d: 740c JZ 0x005e255b
    if(integer::condition("JZ",flags)) goto L005e255b;
  }
  L005e254f: { // 0x5e254f: 8b8004020000 MOV EAX,dword ptr [EAX + 0x204]
    s.ax = m.r32((s.ax+0x00000204u));
  }
  L005e2555: { // 0x5e2555: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e2557: { // 0x5e2557: 75f2 JNZ 0x005e254b
    if(integer::condition("JNZ",flags)) goto L005e254b;
  }
  L005e2559: { // 0x5e2559: eb07 JMP 0x005e2562
    goto L005e2562;
  }
  L005e255b: { // 0x5e255b: 85c0 TEST EAX,EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005e255d: { // 0x5e255d: 7403 JZ 0x005e2562
    if(integer::condition("JZ",flags)) goto L005e2562;
  }
  L005e255f: { // 0x5e255f: 8d7004 LEA ESI,[EAX + 0x4]
    s.si = (s.ax+0x00000004u);
  }
  L005e2562: { // 0x5e2562: 8b466c MOV EAX,dword ptr [ESI + 0x6c]
    s.ax = m.r32((s.si+0x0000006cu));
  }
  L005e2565: { // 0x5e2565: 3d0d010000 CMP EAX,0x10d
    (void)integer::sub(s.ax,0x0000010du,32,flags);
  }
  L005e256a: { // 0x5e256a: 747c JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e256c: { // 0x5e256c: 3dd9000000 CMP EAX,0xd9
    (void)integer::sub(s.ax,0x000000d9u,32,flags);
  }
  L005e2571: { // 0x5e2571: 7475 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e2573: { // 0x5e2573: 3df0000000 CMP EAX,0xf0
    (void)integer::sub(s.ax,0x000000f0u,32,flags);
  }
  L005e2578: { // 0x5e2578: 746e JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e257a: { // 0x5e257a: 3dce000000 CMP EAX,0xce
    (void)integer::sub(s.ax,0x000000ceu,32,flags);
  }
  L005e257f: { // 0x5e257f: 7467 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e2581: { // 0x5e2581: 3d20010000 CMP EAX,0x120
    (void)integer::sub(s.ax,0x00000120u,32,flags);
  }
  L005e2586: { // 0x5e2586: 7460 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e2588: { // 0x5e2588: 3d21010000 CMP EAX,0x121
    (void)integer::sub(s.ax,0x00000121u,32,flags);
  }
  L005e258d: { // 0x5e258d: 7459 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e258f: { // 0x5e258f: 3d15010000 CMP EAX,0x115
    (void)integer::sub(s.ax,0x00000115u,32,flags);
  }
  L005e2594: { // 0x5e2594: 7452 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e2596: { // 0x5e2596: 3dd3000000 CMP EAX,0xd3
    (void)integer::sub(s.ax,0x000000d3u,32,flags);
  }
  L005e259b: { // 0x5e259b: 744b JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e259d: { // 0x5e259d: 3dcf000000 CMP EAX,0xcf
    (void)integer::sub(s.ax,0x000000cfu,32,flags);
  }
  L005e25a2: { // 0x5e25a2: 7444 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25a4: { // 0x5e25a4: 3d1f010000 CMP EAX,0x11f
    (void)integer::sub(s.ax,0x0000011fu,32,flags);
  }
  L005e25a9: { // 0x5e25a9: 743d JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25ab: { // 0x5e25ab: 3dc3000000 CMP EAX,0xc3
    (void)integer::sub(s.ax,0x000000c3u,32,flags);
  }
  L005e25b0: { // 0x5e25b0: 7436 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25b2: { // 0x5e25b2: 3d1b010000 CMP EAX,0x11b
    (void)integer::sub(s.ax,0x0000011bu,32,flags);
  }
  L005e25b7: { // 0x5e25b7: 742f JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25b9: { // 0x5e25b9: 3de1000000 CMP EAX,0xe1
    (void)integer::sub(s.ax,0x000000e1u,32,flags);
  }
  L005e25be: { // 0x5e25be: 7428 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25c0: { // 0x5e25c0: 3d1e010000 CMP EAX,0x11e
    (void)integer::sub(s.ax,0x0000011eu,32,flags);
  }
  L005e25c5: { // 0x5e25c5: 7421 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25c7: { // 0x5e25c7: 3dc4000000 CMP EAX,0xc4
    (void)integer::sub(s.ax,0x000000c4u,32,flags);
  }
  L005e25cc: { // 0x5e25cc: 741a JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25ce: { // 0x5e25ce: 3dd0000000 CMP EAX,0xd0
    (void)integer::sub(s.ax,0x000000d0u,32,flags);
  }
  L005e25d3: { // 0x5e25d3: 7413 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25d5: { // 0x5e25d5: 3dfc000000 CMP EAX,0xfc
    (void)integer::sub(s.ax,0x000000fcu,32,flags);
  }
  L005e25da: { // 0x5e25da: 740c JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25dc: { // 0x5e25dc: 3d26010000 CMP EAX,0x126
    (void)integer::sub(s.ax,0x00000126u,32,flags);
  }
  L005e25e1: { // 0x5e25e1: 7405 JZ 0x005e25e8
    if(integer::condition("JZ",flags)) goto L005e25e8;
  }
  L005e25e3: { // 0x5e25e3: 32c0 XOR AL,AL
    s.ax = with_al(s.ax, integer::logical(((s.ax & 0xffu))^((s.ax & 0xffu)),8,flags));
  }
  L005e25e5: { // 0x5e25e5: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e25e6: { // 0x5e25e6: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e25e7: { // 0x5e25e7: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005e25e8: { // 0x5e25e8: c786b000000002000000 MOV dword ptr [ESI + 0xb0],0x2
    m.w32((s.si+0x000000b0u), 0x00000002u);
  }
  L005e25f2: { // 0x5e25f2: b001 MOV AL,0x1
    s.ax = with_al(s.ax, 0x00000001u);
  }
  L005e25f4: { // 0x5e25f4: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005e25f5: { // 0x5e25f5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005e25f6: { // 0x5e25f6: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
