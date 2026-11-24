#include "recovered/recovery_b670_machine.hpp"
#include "recovered/direct_b33_integer.hpp"
#include <limits>
// Draft structural translations. Per-RVA native proof is still required.
namespace ra2::recovered::recovery_b670 {
namespace {
void f_001d57d0(Memory&,State&,Frame&,const Operations&);
void invoke(Memory&,State&,Frame&,std::uint32_t,std::uint32_t);

void f_001d57d0(Memory& m,State& s,Frame& f,const Operations& op) {
  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d57d0: { // 0x5d57d0: 81ec64020000 SUB ESP, 0x264
    f.sp = integer::sub(f.sp,0x00000264u,32,flags);
  }
  L005d57d6: { // 0x5d57d6: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d57d7: { // 0x5d57d7: 8bf1 MOV ESI, ECX
    s.si = s.cx;
  }
  L005d57d9: { // 0x5d57d9: 8b86a4000000 MOV EAX, dword ptr [ESI + 0xa4]
    s.ax = m.r32((s.si+0x000000a4u));
  }
  L005d57df: { // 0x5d57df: 85c0 TEST EAX, EAX
    (void)integer::logical((s.ax)&(s.ax),32,flags);
  }
  L005d57e1: { // 0x5d57e1: 0f85f0000000 JNZ 0x5d58d7
    if(integer::condition("JNZ",flags)) goto L005d58d7;
  }
  L005d57e7: { // 0x5d57e7: 8a8e7f020000 MOV CL, byte ptr [ESI + 0x27f]
    s.cx = with_al(s.cx, m.r8((s.si+0x0000027fu)));
  }
  L005d57ed: { // 0x5d57ed: 84c9 TEST CL, CL
    (void)integer::logical(((s.cx & 0xffu))&((s.cx & 0xffu)),8,flags);
  }
  L005d57ef: { // 0x5d57ef: 0f84e2000000 JZ 0x5d58d7
    if(integer::condition("JZ",flags)) goto L005d58d7;
  }
  L005d57f5: { // 0x5d57f5: 8d4664 LEA EAX, [ESI + 0x64]
    s.ax = (s.si+0x00000064u);
  }
  L005d57f8: { // 0x5d57f8: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d57f9: { // 0x5d57f9: 68a49f7b00 PUSH 0x7b9fa4
    f.push(m,0x007b9fa4u);
  }
  L005d57fe: { // 0x5d57fe: e8ed10e3ff CALL 0x4068f0
    s.arithmetic_flags=flags; invoke(m,s,f,0x004068f0u,6117379u); flags=s.arithmetic_flags;
  }
  L005d5803: { // 0x5d5803: 8a86fc010000 MOV AL, byte ptr [ESI + 0x1fc]
    s.ax = with_al(s.ax, m.r8((s.si+0x000001fcu)));
  }
  L005d5809: { // 0x5d5809: 83c408 ADD ESP, 8
    f.sp = integer::add(f.sp,8u,32,flags);
  }
  L005d580c: { // 0x5d580c: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d580e: { // 0x5d580e: 7434 JZ 0x5d5844
    if(integer::condition("JZ",flags)) goto L005d5844;
  }
  L005d5810: { // 0x5d5810: 8b0dc055a200 MOV ECX, dword ptr [0xa255c0]
    s.cx = m.r32((0x00a255c0u));
  }
  L005d5816: { // 0x5d5816: 8b8138080000 MOV EAX, dword ptr [ECX + 0x838]
    s.ax = m.r32((s.cx+0x00000838u));
  }
  L005d581c: { // 0x5d581c: 8d1440 LEA EDX, [EAX + EAX*2]
    s.dx = (s.ax+(s.ax * 2u));
  }
  L005d581f: { // 0x5d581f: 8d0490 LEA EAX, [EAX + EDX*4]
    s.ax = (s.ax+(s.dx * 4u));
  }
  L005d5822: { // 0x5d5822: 8d96c8010000 LEA EDX, [ESI + 0x1c8]
    s.dx = (s.si+0x000001c8u);
  }
  L005d5828: { // 0x5d5828: 8d0cc5ac5b7800 LEA ECX, [EAX*8 + 0x785bac]
    s.cx = ((s.ax * 8u)+0x00785bacu);
  }
  L005d582f: { // 0x5d582f: 8d442468 LEA EAX, [ESP + 0x68]
    s.ax = (f.sp+0x00000068u);
  }
  L005d5833: { // 0x5d5833: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5834: { // 0x5d5834: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d5835: { // 0x5d5835: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5837: { // 0x5d5837: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5839: { // 0x5d5839: 50 PUSH EAX
    f.push(m,s.ax);
  }
  L005d583a: { // 0x5d583a: e8f1921900 CALL 0x76eb30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076eb30u,6117439u); flags=s.arithmetic_flags;
  }
  L005d583f: { // 0x5d583f: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005d5842: { // 0x5d5842: eb3b JMP 0x5d587f
    goto L005d587f;
  }
  L005d5844: { // 0x5d5844: 8a8607020000 MOV AL, byte ptr [ESI + 0x207]
    s.ax = with_al(s.ax, m.r8((s.si+0x00000207u)));
  }
  L005d584a: { // 0x5d584a: 84c0 TEST AL, AL
    (void)integer::logical(((s.ax & 0xffu))&((s.ax & 0xffu)),8,flags);
  }
  L005d584c: { // 0x5d584c: 7431 JZ 0x5d587f
    if(integer::condition("JZ",flags)) goto L005d587f;
  }
  L005d584e: { // 0x5d584e: 8d8ec8010000 LEA ECX, [ESI + 0x1c8]
    s.cx = (s.si+0x000001c8u);
  }
  L005d5854: { // 0x5d5854: 68a49c7b00 PUSH 0x7b9ca4
    f.push(m,0x007b9ca4u);
  }
  L005d5859: { // 0x5d5859: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d585a: { // 0x5d585a: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d585c: { // 0x5d585c: 8d542474 LEA EDX, [ESP + 0x74]
    s.dx = (f.sp+0x00000074u);
  }
  L005d5860: { // 0x5d5860: 6a00 PUSH 0
    f.push(m,0u);
  }
  L005d5862: { // 0x5d5862: 52 PUSH EDX
    f.push(m,s.dx);
  }
  L005d5863: { // 0x5d5863: e8c8921900 CALL 0x76eb30
    s.arithmetic_flags=flags; invoke(m,s,f,0x0076eb30u,6117480u); flags=s.arithmetic_flags;
  }
  L005d5868: { // 0x5d5868: a1c055a200 MOV EAX, dword ptr [0xa255c0]
    s.ax = m.r32((0x00a255c0u));
  }
  L005d586d: { // 0x5d586d: 83c414 ADD ESP, 0x14
    f.sp = integer::add(f.sp,0x00000014u,32,flags);
  }
  L005d5870: { // 0x5d5870: 8d4c2468 LEA ECX, [ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L005d5874: { // 0x5d5874: 8b9038080000 MOV EDX, dword ptr [EAX + 0x838]
    s.dx = m.r32((s.ax+0x00000838u));
  }
  L005d587a: { // 0x5d587a: e8e1a9ffff CALL 0x5d0260
    s.arithmetic_flags=flags; invoke(m,s,f,0x005d0260u,6117503u); flags=s.arithmetic_flags;
  }
  L005d587f: { // 0x5d587f: 8d4c2468 LEA ECX, [ESP + 0x68]
    s.cx = (f.sp+0x00000068u);
  }
  L005d5883: { // 0x5d5883: 57 PUSH EDI
    f.push(m,s.di);
  }
  L005d5884: { // 0x5d5884: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5885: { // 0x5d5885: 8d4c240c LEA ECX, [ESP + 0xc]
    s.cx = (f.sp+0x0000000cu);
  }
  L005d5889: { // 0x5d5889: e8e232e9ff CALL 0x468b70
    s.arithmetic_flags=flags; invoke(m,s,f,0x00468b70u,6117518u); flags=s.arithmetic_flags;
  }
  L005d588e: { // 0x5d588e: 8d4c2408 LEA ECX, [ESP + 8]
    s.cx = (f.sp+8u);
  }
  L005d5892: { // 0x5d5892: e879f7ebff CALL 0x495010
    s.arithmetic_flags=flags; invoke(m,s,f,0x00495010u,6117527u); flags=s.arithmetic_flags;
  }
  L005d5897: { // 0x5d5897: 8bf8 MOV EDI, EAX
    s.di = s.ax;
  }
  L005d5899: { // 0x5d5899: 85ff TEST EDI, EDI
    (void)integer::logical((s.di)&(s.di),32,flags);
  }
  L005d589b: { // 0x5d589b: 89bea4000000 MOV dword ptr [ESI + 0xa4], EDI
    m.w32((s.si+0x000000a4u), s.di);
  }
  L005d58a1: { // 0x5d58a1: 7407 JZ 0x5d58aa
    if(integer::condition("JZ",flags)) goto L005d58aa;
  }
  L005d58a3: { // 0x5d58a3: c686a800000001 MOV byte ptr [ESI + 0xa8], 1
    m.w8((s.si+0x000000a8u), 1u);
  }
  L005d58aa: { // 0x5d58aa: 8d4c245c LEA ECX, [ESP + 0x5c]
    s.cx = (f.sp+0x0000005cu);
  }
  L005d58ae: { // 0x5d58ae: c7442408a0567800 MOV dword ptr [ESP + 8], 0x7856a0
    m.w32((f.sp+8u), 0x007856a0u);
  }
  L005d58b6: { // 0x5d58b6: c744246800000000 MOV dword ptr [ESP + 0x68], 0
    m.w32((f.sp+0x00000068u), 0u);
  }
  L005d58be: { // 0x5d58be: e8cd29e6ff CALL 0x438290
    s.arithmetic_flags=flags; invoke(m,s,f,0x00438290u,6117571u); flags=s.arithmetic_flags;
  }
  L005d58c3: { // 0x5d58c3: 8d4c2408 LEA ECX, [ESP + 8]
    s.cx = (f.sp+8u);
  }
  L005d58c7: { // 0x5d58c7: c744240858567800 MOV dword ptr [ESP + 8], 0x785658
    m.w32((f.sp+8u), 0x00785658u);
  }
  L005d58cf: { // 0x5d58cf: e87c99e5ff CALL 0x42f250
    s.arithmetic_flags=flags; invoke(m,s,f,0x0042f250u,6117588u); flags=s.arithmetic_flags;
  }
  L005d58d4: { // 0x5d58d4: 8bc7 MOV EAX, EDI
    s.ax = s.di;
  }
  L005d58d6: { // 0x5d58d6: 5f POP EDI
    const auto value=f.pop(m); s.di = value;
  }
  L005d58d7: { // 0x5d58d7: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d58d8: { // 0x5d58d8: 81c464020000 ADD ESP, 0x264
    f.sp = integer::add(f.sp,0x00000264u,32,flags);
  }
  L005d58de: { // 0x5d58de: c3 RET
    s.arithmetic_flags=flags; finish(m,s,f,0u); return;
  }
}
} // namespace
namespace {
void invoke(Memory&m,State&s,Frame&f,std::uint32_t target,std::uint32_t continuation){
 f.push(m,continuation);Frame child{f.sp,f.sp,continuation};
 switch(target){
case 6117328u:f_001d57d0(m,s,child,{});break;
default:throw std::domain_error("recovery670 unreviewed original call");}
f.sp=child.sp;
}
}

std::uint32_t fun_005d5680(Memory& original,const Inputs& i){
 std::array<std::uint8_t,0x8000> stack{};constexpr std::uint32_t base=0x7d000000u,frame_entry=base+0x6004u;
 leaf::Memory local(stack.data(),base,std::uint32_t(stack.size()));Memory m=original;m.add(local);
 State s{};s.ax=i.ax;s.cx=i.cx;s.dx=i.dx;s.fp=i.fp;s.arithmetic_flags=i.arithmetic_flags;
 Frame f{frame_entry,frame_entry,0x76543210u};const Operations op{};m.w32(frame_entry,0x76543210u);
 for(unsigned k=0;k<i.arg.size();++k)m.w32(frame_entry+4+4*k,i.arg[k]);
 m.w32(frame_entry-8,i.stack_minus8);m.w32(((frame_entry-4)&~7u)-8,i.stack_minus8);

  std::uint32_t flags=s.arithmetic_flags; (void)flags; (void)op;
  L005d5680: { // 0x5d5680: 51 PUSH ECX
    f.push(m,s.cx);
  }
  L005d5681: { // 0x5d5681: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d5682: { // 0x5d5682: 56 PUSH ESI
    f.push(m,s.si);
  }
  L005d5683: { // 0x5d5683: 8bf1 MOV ESI,ECX
    s.si = s.cx;
  }
  L005d5685: { // 0x5d5685: 8b06 MOV EAX,dword ptr [ESI]
    s.ax = m.r32((s.si));
  }
  L005d5687: { // 0x5d5687: ff909c000000 CALL dword ptr [EAX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.ax+0x0000009cu)),6117005u); flags=s.arithmetic_flags;
  }
  L005d568d: { // 0x5d568d: 33db XOR EBX,EBX
    s.bx = integer::logical((s.bx)^(s.bx),32,flags);
  }
  L005d568f: { // 0x5d568f: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005d5691: { // 0x5d5691: 751e JNZ 0x005d56b1
    if(integer::condition("JNZ",flags)) goto L005d56b1;
  }
  L005d5693: { // 0x5d5693: 8b8e6c020000 MOV ECX,dword ptr [ESI + 0x26c]
    s.cx = m.r32((s.si+0x0000026cu));
  }
  L005d5699: { // 0x5d5699: 3bcb CMP ECX,EBX
    (void)integer::sub(s.cx,s.bx,32,flags);
  }
  L005d569b: { // 0x5d569b: 0f8407010000 JZ 0x005d57a8
    if(integer::condition("JZ",flags)) goto L005d57a8;
  }
  L005d56a1: { // 0x5d56a1: 8b11 MOV EDX,dword ptr [ECX]
    s.dx = m.r32((s.cx));
  }
  L005d56a3: { // 0x5d56a3: ff929c000000 CALL dword ptr [EDX + 0x9c]
    s.arithmetic_flags=flags; invoke(m,s,f,m.r32((s.dx+0x0000009cu)),6117033u); flags=s.arithmetic_flags;
  }
  L005d56a9: { // 0x5d56a9: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005d56ab: { // 0x5d56ab: 0f84f7000000 JZ 0x005d57a8
    if(integer::condition("JZ",flags)) goto L005d57a8;
  }
  L005d56b1: { // 0x5d56b1: 8bb664020000 MOV ESI,dword ptr [ESI + 0x264]
    s.si = m.r32((s.si+0x00000264u));
  }
  L005d56b7: { // 0x5d56b7: 83fe7f CMP ESI,0x7f
    (void)integer::sub(s.si,0x0000007fu,32,flags);
  }
  L005d56ba: { // 0x5d56ba: 7c08 JL 0x005d56c4
    if(integer::condition("JL",flags)) goto L005d56c4;
  }
  L005d56bc: { // 0x5d56bc: 81fe8a000000 CMP ESI,0x8a
    (void)integer::sub(s.si,0x0000008au,32,flags);
  }
  L005d56c2: { // 0x5d56c2: 7e10 JLE 0x005d56d4
    if(integer::condition("JLE",flags)) goto L005d56d4;
  }
  L005d56c4: { // 0x5d56c4: 81fe93000000 CMP ESI,0x93
    (void)integer::sub(s.si,0x00000093u,32,flags);
  }
  L005d56ca: { // 0x5d56ca: 7c7a JL 0x005d5746
    if(integer::condition("JL",flags)) goto L005d5746;
  }
  L005d56cc: { // 0x5d56cc: 81fe9e000000 CMP ESI,0x9e
    (void)integer::sub(s.si,0x0000009eu,32,flags);
  }
  L005d56d2: { // 0x5d56d2: 7f72 JG 0x005d5746
    if(integer::condition("JG",flags)) goto L005d5746;
  }
  L005d56d4: { // 0x5d56d4: 0fbf5006 MOVSX EDX,word ptr [EAX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L005d56d8: { // 0x5d56d8: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005d56dc: { // 0x5d56dc: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005d56de: { // 0x5d56de: 7328 JNC 0x005d5708
    if(integer::condition("JNC",flags)) goto L005d5708;
  }
  L005d56e0: { // 0x5d56e0: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L005d56e3: { // 0x5d56e3: 8d44c808 LEA EAX,[EAX + ECX*0x8 + 0x8]
    s.ax = (s.ax+(s.cx * 0x00000008u)+0x00000008u);
  }
  L005d56e7: { // 0x5d56e7: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005d56e9: { // 0x5d56e9: 741d JZ 0x005d5708
    if(integer::condition("JZ",flags)) goto L005d5708;
  }
  L005d56eb: { // 0x5d56eb: 8a500c MOV DL,byte ptr [EAX + 0xc]
    s.dx = with_al(s.dx, m.r8((s.ax+0x0000000cu)));
  }
  L005d56ee: { // 0x5d56ee: 8a480d MOV CL,byte ptr [EAX + 0xd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000000du)));
  }
  L005d56f1: { // 0x5d56f1: 8a400e MOV AL,byte ptr [EAX + 0xe]
    s.ax = with_al(s.ax, m.r8((s.ax+0x0000000eu)));
  }
  L005d56f4: { // 0x5d56f4: 88542414 MOV byte ptr [ESP + 0x14],DL
    m.w8((f.sp+0x00000014u), (s.dx & 0xffu));
  }
  L005d56f8: { // 0x5d56f8: 884c2415 MOV byte ptr [ESP + 0x15],CL
    m.w8((f.sp+0x00000015u), (s.cx & 0xffu));
  }
  L005d56fc: { // 0x5d56fc: 668b542414 MOV DX,word ptr [ESP + 0x14]
    s.dx = with_ax(s.dx, m.r16((f.sp+0x00000014u)));
  }
  L005d5701: { // 0x5d5701: 6689542414 MOV word ptr [ESP + 0x14],DX
    m.w16((f.sp+0x00000014u), (s.dx & 0xffffu));
  }
  L005d5706: { // 0x5d5706: eb17 JMP 0x005d571f
    goto L005d571f;
  }
  L005d5708: { // 0x5d5708: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d5709: { // 0x5d5709: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d570a: { // 0x5d570a: 53 PUSH EBX
    f.push(m,s.bx);
  }
  L005d570b: { // 0x5d570b: 8d4c2414 LEA ECX,[ESP + 0x14]
    s.cx = (f.sp+0x00000014u);
  }
  L005d570f: { // 0x5d570f: e81cd5e5ff CALL 0x00432c30
    s.arithmetic_flags=flags; invoke(m,s,f,0x00432c30u,6117140u); flags=s.arithmetic_flags;
  }
  L005d5714: { // 0x5d5714: 668b08 MOV CX,word ptr [EAX]
    s.cx = with_ax(s.cx, m.r16((s.ax)));
  }
  L005d5717: { // 0x5d5717: 66894c2414 MOV word ptr [ESP + 0x14],CX
    m.w16((f.sp+0x00000014u), (s.cx & 0xffffu));
  }
  L005d571c: { // 0x5d571c: 8a4002 MOV AL,byte ptr [EAX + 0x2]
    s.ax = with_al(s.ax, m.r8((s.ax+0x00000002u)));
  }
  L005d571f: { // 0x5d571f: 8a542414 MOV DL,byte ptr [ESP + 0x14]
    s.dx = with_al(s.dx, m.r8((f.sp+0x00000014u)));
  }
  L005d5723: { // 0x5d5723: 8a4c2415 MOV CL,byte ptr [ESP + 0x15]
    s.cx = with_al(s.cx, m.r8((f.sp+0x00000015u)));
  }
  L005d5727: { // 0x5d5727: 88442409 MOV byte ptr [ESP + 0x9],AL
    m.w8((f.sp+0x00000009u), (s.ax & 0xffu));
  }
  L005d572b: { // 0x5d572b: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005d572f: { // 0x5d572f: 88542408 MOV byte ptr [ESP + 0x8],DL
    m.w8((f.sp+0x00000008u), (s.dx & 0xffu));
  }
  L005d5733: { // 0x5d5733: 668b742408 MOV SI,word ptr [ESP + 0x8]
    s.si = (s.si & 0xffff0000u) | ((m.r16((f.sp+0x00000008u))) & 0xffffu);
  }
  L005d5738: { // 0x5d5738: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005d573a: { // 0x5d573a: 668932 MOV word ptr [EDX],SI
    m.w16((s.dx), (s.si & 0xffffu));
  }
  L005d573d: { // 0x5d573d: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d573e: { // 0x5d573e: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d573f: { // 0x5d573f: 884a02 MOV byte ptr [EDX + 0x2],CL
    m.w8((s.dx+0x00000002u), (s.cx & 0xffu));
  }
  L005d5742: { // 0x5d5742: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d5743: { // 0x5d5743: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005d5746: { // 0x5d5746: 0fbf5006 MOVSX EDX,word ptr [EAX + 0x6]
    s.dx = std::uint32_t(integer::sign_extend(m.r16((s.ax+0x00000006u)),16));
  }
  L005d574a: { // 0x5d574a: 8b4c2414 MOV ECX,dword ptr [ESP + 0x14]
    s.cx = m.r32((f.sp+0x00000014u));
  }
  L005d574e: { // 0x5d574e: 3bca CMP ECX,EDX
    (void)integer::sub(s.cx,s.dx,32,flags);
  }
  L005d5750: { // 0x5d5750: 7335 JNC 0x005d5787
    if(integer::condition("JNC",flags)) goto L005d5787;
  }
  L005d5752: { // 0x5d5752: 8d0c49 LEA ECX,[ECX + ECX*0x2]
    s.cx = (s.cx+(s.cx * 0x00000002u));
  }
  L005d5755: { // 0x5d5755: 8d44c808 LEA EAX,[EAX + ECX*0x8 + 0x8]
    s.ax = (s.ax+(s.cx * 0x00000008u)+0x00000008u);
  }
  L005d5759: { // 0x5d5759: 3bc3 CMP EAX,EBX
    (void)integer::sub(s.ax,s.bx,32,flags);
  }
  L005d575b: { // 0x5d575b: 742a JZ 0x005d5787
    if(integer::condition("JZ",flags)) goto L005d5787;
  }
  L005d575d: { // 0x5d575d: 8a500c MOV DL,byte ptr [EAX + 0xc]
    s.dx = with_al(s.dx, m.r8((s.ax+0x0000000cu)));
  }
  L005d5760: { // 0x5d5760: 8a480d MOV CL,byte ptr [EAX + 0xd]
    s.cx = with_al(s.cx, m.r8((s.ax+0x0000000du)));
  }
  L005d5763: { // 0x5d5763: 8a400e MOV AL,byte ptr [EAX + 0xe]
    s.ax = with_al(s.ax, m.r8((s.ax+0x0000000eu)));
  }
  L005d5766: { // 0x5d5766: 88542414 MOV byte ptr [ESP + 0x14],DL
    m.w8((f.sp+0x00000014u), (s.dx & 0xffu));
  }
  L005d576a: { // 0x5d576a: 8ad0 MOV DL,AL
    s.dx = with_al(s.dx, (s.ax & 0xffu));
  }
  L005d576c: { // 0x5d576c: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005d5770: { // 0x5d5770: 884c2415 MOV byte ptr [ESP + 0x15],CL
    m.w8((f.sp+0x00000015u), (s.cx & 0xffu));
  }
  L005d5774: { // 0x5d5774: 668b4c2414 MOV CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000014u)));
  }
  L005d5779: { // 0x5d5779: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005d577b: { // 0x5d577b: 66890e MOV word ptr [ESI],CX
    m.w16((s.si), (s.cx & 0xffffu));
  }
  L005d577e: { // 0x5d577e: 885602 MOV byte ptr [ESI + 0x2],DL
    m.w8((s.si+0x00000002u), (s.dx & 0xffu));
  }
  L005d5781: { // 0x5d5781: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d5782: { // 0x5d5782: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d5783: { // 0x5d5783: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d5784: { // 0x5d5784: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005d5787: { // 0x5d5787: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005d578b: { // 0x5d578b: 885c2414 MOV byte ptr [ESP + 0x14],BL
    m.w8((f.sp+0x00000014u), (s.bx & 0xffu));
  }
  L005d578f: { // 0x5d578f: 885c2415 MOV byte ptr [ESP + 0x15],BL
    m.w8((f.sp+0x00000015u), (s.bx & 0xffu));
  }
  L005d5793: { // 0x5d5793: 668b4c2414 MOV CX,word ptr [ESP + 0x14]
    s.cx = with_ax(s.cx, m.r16((f.sp+0x00000014u)));
  }
  L005d5798: { // 0x5d5798: 8bf0 MOV ESI,EAX
    s.si = s.ax;
  }
  L005d579a: { // 0x5d579a: 32d2 XOR DL,DL
    s.dx = with_al(s.dx, integer::logical(((s.dx & 0xffu))^((s.dx & 0xffu)),8,flags));
  }
  L005d579c: { // 0x5d579c: 66890e MOV word ptr [ESI],CX
    m.w16((s.si), (s.cx & 0xffffu));
  }
  L005d579f: { // 0x5d579f: 885602 MOV byte ptr [ESI + 0x2],DL
    m.w8((s.si+0x00000002u), (s.dx & 0xffu));
  }
  L005d57a2: { // 0x5d57a2: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d57a3: { // 0x5d57a3: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d57a4: { // 0x5d57a4: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d57a5: { // 0x5d57a5: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }
  L005d57a8: { // 0x5d57a8: 8b442410 MOV EAX,dword ptr [ESP + 0x10]
    s.ax = m.r32((f.sp+0x00000010u));
  }
  L005d57ac: { // 0x5d57ac: 885c2414 MOV byte ptr [ESP + 0x14],BL
    m.w8((f.sp+0x00000014u), (s.bx & 0xffu));
  }
  L005d57b0: { // 0x5d57b0: 885c2415 MOV byte ptr [ESP + 0x15],BL
    m.w8((f.sp+0x00000015u), (s.bx & 0xffu));
  }
  L005d57b4: { // 0x5d57b4: 668b742414 MOV SI,word ptr [ESP + 0x14]
    s.si = (s.si & 0xffff0000u) | ((m.r16((f.sp+0x00000014u))) & 0xffffu);
  }
  L005d57b9: { // 0x5d57b9: 8bd0 MOV EDX,EAX
    s.dx = s.ax;
  }
  L005d57bb: { // 0x5d57bb: 32c9 XOR CL,CL
    s.cx = with_al(s.cx, integer::logical(((s.cx & 0xffu))^((s.cx & 0xffu)),8,flags));
  }
  L005d57bd: { // 0x5d57bd: 668932 MOV word ptr [EDX],SI
    m.w16((s.dx), (s.si & 0xffffu));
  }
  L005d57c0: { // 0x5d57c0: 5e POP ESI
    const auto value=f.pop(m); s.si = value;
  }
  L005d57c1: { // 0x5d57c1: 5b POP EBX
    const auto value=f.pop(m); s.bx = value;
  }
  L005d57c2: { // 0x5d57c2: 884a02 MOV byte ptr [EDX + 0x2],CL
    m.w8((s.dx+0x00000002u), (s.cx & 0xffu));
  }
  L005d57c5: { // 0x5d57c5: 59 POP ECX
    const auto value=f.pop(m); s.cx = value;
  }
  L005d57c6: { // 0x5d57c6: c20800 RET 0x8
    s.arithmetic_flags=flags; finish(m,s,f,8u); i.fp=s.fp;for(unsigned k=0;k<i.arg.size();++k)i.arg[k]=m.r32(frame_entry+4+4*k);return s.ax;
  }

}
}
