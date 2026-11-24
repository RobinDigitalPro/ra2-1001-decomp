#include "recovery_b1707.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1707 {
namespace ix=direct_b33::integer;
namespace {
void ftol_76aa50(Memory& m,State& s,Frame& f){
    // 0x0076aa50: sub esp, 0xc [83ec0c]
    f.sp=ix::sub(f.sp,0xcu,32u,s.arithmetic_flags);
    // 0x0076aa53: fnstcw word ptr [esp] [d93c24]
    m.w16(f.sp,s.fp.control());
    // 0x0076aa56: lea eax, [esp + 4] [8d442404]
    s.ax=f.sp+0x4u;
    // 0x0076aa5a: mov edx, dword ptr [esp] [8b1424]
    s.dx=m.r32(f.sp);
    // 0x0076aa5d: and edx, 0xffff [81e2ffff0000]
    s.dx=ix::logical(s.dx&0xffffu,32u,s.arithmetic_flags);
    // 0x0076aa63: cmp edx, dword ptr [0x7c3a04] [3b15043a7c00]
    (void)ix::sub(s.dx,m.r32(0x7c3a04u),32u,s.arithmetic_flags);
    // 0x0076aa69: jne 0x76aa76 [750b]
    if(!ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x76aa69");
    // 0x0076aa76: mov edx, dword ptr [0x7c3a04] [8b15043a7c00]
    s.dx=m.r32(0x7c3a04u);
    // 0x0076aa7c: mov dword ptr [esp], edx [891424]
    m.w32(f.sp,s.dx);
    // 0x0076aa7f: fldcw word ptr [esp] [d92c24]
    s.fp.load_control(static_cast<std::uint16_t>(m.r16(f.sp)));
    // 0x0076aa82: fistp qword ptr [eax] [df38]
    floating_b61::write64(m,s.ax,s.fp.pop_integer64());
    // 0x0076aa84: mov edx, dword ptr [eax + 4] [8b5004]
    s.dx=m.r32(s.ax+0x4u);
    // 0x0076aa87: mov eax, dword ptr [eax] [8b00]
    s.ax=m.r32(s.ax);
    // 0x0076aa89: add esp, 0xc [83c40c]
    f.sp=ix::add(f.sp,0xcu,32u,s.arithmetic_flags);
    // 0x0076aa8c: ret [c3]
    recovery_b566::finish(m,s,f,0u);
}
void scale_697fb0(Memory& m,State& s,Frame& f){
    // 0x00697fb0: SUB ESP,0x8 [83ec08]
    f.sp=ix::sub(f.sp,0x8u,32u,s.arithmetic_flags);
    // 0x00697fb3: CMP ECX,0x2d8 [81f9d8020000]
    (void)ix::sub(s.cx,0x2d8u,32u,s.arithmetic_flags);
    // 0x00697fb9: MOV dword ptr [ESP + 0x4],ECX [894c2404]
    m.w32(f.sp+0x4u,s.cx);
    // 0x00697fbd: MOV dword ptr [ESP],0x0 [c744240000000000]
    m.w32(f.sp,0x0u);
    // 0x00697fc5: JL 0x00697fcf [7c08]
    if(!ix::condition("JL",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x697fc5");
    // 0x00697fcf: FILD dword ptr [ESP + 0x4] [db442404]
    s.fp.load_integer32(m.r32(f.sp+0x4u));
    // 0x00697fd3: FMUL double ptr [0x00aa5f90] [dc0d905faa00]
    s.fp.multiply64(floating_b61::read64(m,0xaa5f90u));
    // 0x00697fd9: FIADD dword ptr [ESP] [da442400]
    ra2::platform::x87_extended::add_integer32(s.fp,m.r32(f.sp));
    // 0x00697fdd: FADD double ptr [0x00785728] [dc0528577800]
    s.fp.add64(floating_b61::read64(m,0x785728u));
    // 0x00697fe3: CALL 0x0076aa50 [e8682a0d00]
    {
        f.push(m,0x697fe8u);
        Frame child{f.sp,f.sp,0x697fe8u};
        ftol_76aa50(m,s,child);
        f.sp=child.sp;
    }
    // 0x00697fe8: ADD ESP,0x8 [83c408]
    f.sp=ix::add(f.sp,0x8u,32u,s.arithmetic_flags);
    // 0x00697feb: RET [c3]
    recovery_b566::finish(m,s,f,0u);
}
void cell_41b320(Memory& m,State& s,Frame& f){
    // 0x0041b320: PUSH ECX [51]
    f.push(m,s.cx);
    // 0x0041b321: MOV EAX,dword ptr [ECX + 0x88] [8b8188000000]
    s.ax=m.r32(s.cx+0x88u);
    // 0x0041b327: CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
    // 0x0041b328: AND EDX,0xff [81e2ff000000]
    s.dx=ix::logical(s.dx&0xffu,32u,s.arithmetic_flags);
    // 0x0041b32e: ADD EAX,EDX [03c2]
    s.ax=ix::add(s.ax,s.dx,32u,s.arithmetic_flags);
    // 0x0041b330: SAR EAX,0x8 [c1f808]
    s.ax=ix::shift(s.ax,0x8u,32u,s.arithmetic_flags,ix::Shift::arithmetic_right);
    // 0x0041b333: MOV word ptr [ESP],AX [6689442400]
    m.w16(f.sp,(s.ax&0xffffu));
    // 0x0041b338: MOV EAX,dword ptr [ECX + 0x8c] [8b818c000000]
    s.ax=m.r32(s.cx+0x8cu);
    // 0x0041b33e: CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
    // 0x0041b33f: AND EDX,0xff [81e2ff000000]
    s.dx=ix::logical(s.dx&0xffu,32u,s.arithmetic_flags);
    // 0x0041b345: ADD EAX,EDX [03c2]
    s.ax=ix::add(s.ax,s.dx,32u,s.arithmetic_flags);
    // 0x0041b347: SAR EAX,0x8 [c1f808]
    s.ax=ix::shift(s.ax,0x8u,32u,s.arithmetic_flags,ix::Shift::arithmetic_right);
    // 0x0041b34a: MOV word ptr [ESP + 0x2],AX [6689442402]
    m.w16(f.sp+0x2u,(s.ax&0xffffu));
    // 0x0041b34f: MOV EAX,dword ptr [ESP + 0x8] [8b442408]
    s.ax=m.r32(f.sp+0x8u);
    // 0x0041b353: MOV ECX,dword ptr [ESP] [8b4c2400]
    s.cx=m.r32(f.sp);
    // 0x0041b357: MOV dword ptr [EAX],ECX [8908]
    m.w32(s.ax,s.cx);
    // 0x0041b359: POP ECX [59]
    s.cx=f.pop(m);
    // 0x0041b35a: RET 0x4 [c20400]
    recovery_b566::finish(m,s,f,0x4u);
}
void map_545500(Memory& m,State& s,Frame& f){
    // 0x00545500: MOV EDX,dword ptr [ESP + 0x4] [8b542404]
    s.dx=m.r32(f.sp+0x4u);
    // 0x00545504: PUSH ESI [56]
    f.push(m,s.si);
    // 0x00545505: MOVSX EAX,word ptr [EDX + 0x2] [0fbf4202]
    s.ax=global_b26::sx16(m.r16(s.dx+0x2u));
    // 0x00545509: MOVSX ESI,word ptr [EDX] [0fbf32]
    s.si=global_b26::sx16(m.r16(s.dx));
    // 0x0054550c: SHL EAX,0x9 [c1e009]
    s.ax=ix::shift(s.ax,0x9u,32u,s.arithmetic_flags,ix::Shift::left);
    // 0x0054550f: ADD EAX,ESI [03c6]
    s.ax=ix::add(s.ax,s.si,32u,s.arithmetic_flags);
    // 0x00545511: POP ESI [5e]
    s.si=f.pop(m);
    // 0x00545512: JS 0x00545528 [7814]
    if(ix::condition("JS",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x545512");
    // 0x00545514: CMP EAX,0x40000 [3d00000400]
    (void)ix::sub(s.ax,0x40000u,32u,s.arithmetic_flags);
    // 0x00545519: JGE 0x00545528 [7d0d]
    if(ix::condition("JGE",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x545519");
    // 0x0054551b: MOV ECX,dword ptr [ECX + 0x138] [8b8938010000]
    s.cx=m.r32(s.cx+0x138u);
    // 0x00545521: MOV EAX,dword ptr [ECX + EAX*0x4] [8b0481]
    s.ax=m.r32(s.cx+s.ax*0x4u);
    // 0x00545524: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32u,s.arithmetic_flags);
    // 0x00545526: JNZ 0x00545535 [750d]
    if(!ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x545526");
    // 0x00545535: RET 0x4 [c20400]
    recovery_b566::finish(m,s,f,0x4u);
}
void height_5cce90(Memory& m,State& s,Frame& f){
    // 0x005cce90: MOV EAX,dword ptr [ECX + 0x90] [8b8190000000]
    s.ax=m.r32(s.cx+0x90u);
    // 0x005cce96: RET [c3]
    recovery_b566::finish(m,s,f,0u);
}
void class_6fee90(Memory& m,State& s,Frame& f){
    // 0x006fee90: MOV EAX, 1 [b801000000]
    s.ax=0x1u;
    // 0x006fee95: RET  [c3]
    recovery_b566::finish(m,s,f,0u);
}
} // anonymous namespace

void execute_selected(Memory& m,State& s,Frame& f){
    // Caller performs require_selected_basis and physical ownership checks before observation.
    // 0x006c5410: SUB ESP,0x5c [83ec5c]
    f.sp=ix::sub(f.sp,0x5cu,32u,s.arithmetic_flags);
    // 0x006c5413: PUSH EBX [53]
    f.push(m,s.bx);
    // 0x006c5414: PUSH EBP [55]
    f.push(m,s.bp);
    // 0x006c5415: PUSH ESI [56]
    f.push(m,s.si);
    // 0x006c5416: MOV ESI,ECX [8bf1]
    s.si=s.cx;
    // 0x006c5418: PUSH EDI [57]
    f.push(m,s.di);
    // 0x006c5419: MOV EAX,dword ptr [ESI] [8b06]
    s.ax=m.r32(s.si);
    // 0x006c541b: CALL dword ptr [EAX + 0x1b8] [ff90b8010000]
    if(m.r32(s.ax+0x1b8u)!=0x5cce90u) throw std::domain_error("2C5410 actual virtual target mismatch");
    {
        f.push(m,0x6c5421u);
        Frame child{f.sp,f.sp,0x6c5421u};
        height_5cce90(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c5421: MOV ECX,EAX [8bc8]
    s.cx=s.ax;
    // 0x006c5423: CALL 0x00697fb0 [e8882bfdff]
    {
        f.push(m,0x6c5428u);
        Frame child{f.sp,f.sp,0x6c5428u};
        scale_697fb0(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c5428: MOV EDX,dword ptr [ESI] [8b16]
    s.dx=m.r32(s.si);
    // 0x006c542a: MOV EBP,EAX [8be8]
    s.bp=s.ax;
    // 0x006c542c: LEA EAX,[ESP + 0x3c] [8d44243c]
    s.ax=f.sp+0x3cu;
    // 0x006c5430: MOV ECX,ESI [8bce]
    s.cx=s.si;
    // 0x006c5432: NEG EBP [f7dd]
    s.bp=ix::sub(0u,s.bp,32u,s.arithmetic_flags);
    // 0x006c5434: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x006c5435: MOV dword ptr [ESP + 0x18],EBP [896c2418]
    m.w32(f.sp+0x18u,s.bp);
    // 0x006c5439: CALL dword ptr [EDX + 0x1a0] [ff92a0010000]
    if(m.r32(s.dx+0x1a0u)!=0x41b320u) throw std::domain_error("2C5410 actual virtual target mismatch");
    {
        f.push(m,0x6c543fu);
        Frame child{f.sp,f.sp,0x6c543fu};
        cell_41b320(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c543f: MOV ECX,dword ptr [EAX] [8b08]
    s.cx=m.r32(s.ax);
    // 0x006c5441: LEA EDX,[ESP + 0x10] [8d542410]
    s.dx=f.sp+0x10u;
    // 0x006c5445: MOV dword ptr [ESP + 0x10],ECX [894c2410]
    m.w32(f.sp+0x10u,s.cx);
    // 0x006c5449: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x006c544a: MOV ECX,0x81a820 [b920a88100]
    s.cx=0x81a820u;
    // 0x006c544f: CALL 0x00545500 [e8ac00e8ff]
    {
        f.push(m,0x6c5454u);
        Frame child{f.sp,f.sp,0x6c5454u};
        map_545500(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c5454: MOV EBX,EAX [8bd8]
    s.bx=s.ax;
    // 0x006c5456: MOV EAX,dword ptr [ESI] [8b06]
    s.ax=m.r32(s.si);
    // 0x006c5458: MOV ECX,ESI [8bce]
    s.cx=s.si;
    // 0x006c545a: MOV dword ptr [ESP + 0x24],EBX [895c2424]
    m.w32(f.sp+0x24u,s.bx);
    // 0x006c545e: CALL dword ptr [EAX + 0x2c] [ff502c]
    if(m.r32(s.ax+0x2cu)!=0x6fee90u) throw std::domain_error("2C5410 actual virtual target mismatch");
    {
        f.push(m,0x6c5461u);
        Frame child{f.sp,f.sp,0x6c5461u};
        class_6fee90(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c5461: CMP EAX,0x1 [83f801]
    (void)ix::sub(s.ax,0x1u,32u,s.arithmetic_flags);
    // 0x006c5464: JNZ 0x006c54e1 [757b]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c5464");
    // 0x006c5466: MOV AL,byte ptr [ESI + 0x370] [8a8670030000]
    s.ax=(s.ax&0xffffff00u)|((m.r8(s.si+0x370u))&0xffu);
    // 0x006c546c: TEST AL,AL [84c0]
    (void)ix::logical((s.ax&0xffu)&(s.ax&0xffu),8u,s.arithmetic_flags);
    // 0x006c546e: JZ 0x006c54a1 [7431]
    if(!ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c546e");
    // 0x006c54a1: MOV ECX,dword ptr [ESI + 0x5ac] [8b8eac050000]
    s.cx=m.r32(s.si+0x5acu);
    // 0x006c54a7: MOV AL,byte ptr [ECX + 0xba6] [8a81a60b0000]
    s.ax=(s.ax&0xffffff00u)|((m.r8(s.cx+0xba6u))&0xffu);
    // 0x006c54ad: TEST AL,AL [84c0]
    (void)ix::logical((s.ax&0xffu)&(s.ax&0xffu),8u,s.arithmetic_flags);
    // 0x006c54af: JZ 0x006c54e1 [7430]
    if(!ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c54af");
    // 0x006c54e1: MOV AL,byte ptr [EBX + 0x11c] [8a831c010000]
    s.ax=(s.ax&0xffffff00u)|((m.r8(s.bx+0x11cu))&0xffu);
    // 0x006c54e7: TEST AL,AL [84c0]
    (void)ix::logical((s.ax&0xffu)&(s.ax&0xffu),8u,s.arithmetic_flags);
    // 0x006c54e9: JZ 0x006c563b [0f844c010000]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c54e9");
    // 0x006c54ef: MOV AX,word ptr [ESP + 0x12] [668b442412]
    s.ax=(s.ax&0xffff0000u)|((m.r16(f.sp+0x12u))&0xffffu);
    // 0x006c54f4: MOV ECX,dword ptr [ESP + 0x10] [8b4c2410]
    s.cx=m.r32(f.sp+0x10u);
    // 0x006c54f8: MOV EDX,dword ptr [0x00839db0] [8b15b09d8300]
    s.dx=m.r32(0x839db0u);
    // 0x006c54fe: ADD AX,word ptr [0x00839db2] [660305b29d8300]
    s.ax=(s.ax&0xffff0000u)|((ix::add((s.ax&0xffffu),m.r16(0x839db2u),16u,s.arithmetic_flags))&0xffffu);
    // 0x006c5505: ADD ECX,EDX [03ca]
    s.cx=ix::add(s.cx,s.dx,32u,s.arithmetic_flags);
    // 0x006c5507: LEA EDX,[ESP + 0x20] [8d542420]
    s.dx=f.sp+0x20u;
    // 0x006c550b: MOV word ptr [ESP + 0x18],CX [66894c2418]
    m.w16(f.sp+0x18u,(s.cx&0xffffu));
    // 0x006c5510: MOV word ptr [ESP + 0x1a],AX [668944241a]
    m.w16(f.sp+0x1au,(s.ax&0xffffu));
    // 0x006c5515: MOV ECX,dword ptr [ESP + 0x18] [8b4c2418]
    s.cx=m.r32(f.sp+0x18u);
    // 0x006c5519: PUSH EDX [52]
    f.push(m,s.dx);
    // 0x006c551a: MOV dword ptr [ESP + 0x24],ECX [894c2424]
    m.w32(f.sp+0x24u,s.cx);
    // 0x006c551e: MOV ECX,0x81a820 [b920a88100]
    s.cx=0x81a820u;
    // 0x006c5523: CALL 0x00545500 [e8d8ffe7ff]
    {
        f.push(m,0x6c5528u);
        Frame child{f.sp,f.sp,0x6c5528u};
        map_545500(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c5528: MOV DX,word ptr [ESP + 0x12] [668b542412]
    s.dx=(s.dx&0xffff0000u)|((m.r16(f.sp+0x12u))&0xffffu);
    // 0x006c552d: MOV ECX,dword ptr [0x00839da8] [8b0da89d8300]
    s.cx=m.r32(0x839da8u);
    // 0x006c5533: ADD DX,word ptr [0x00839daa] [660315aa9d8300]
    s.dx=(s.dx&0xffff0000u)|((ix::add((s.dx&0xffffu),m.r16(0x839daau),16u,s.arithmetic_flags))&0xffffu);
    // 0x006c553a: MOV EDI,EAX [8bf8]
    s.di=s.ax;
    // 0x006c553c: MOV EAX,dword ptr [ESP + 0x10] [8b442410]
    s.ax=m.r32(f.sp+0x10u);
    // 0x006c5540: ADD EAX,ECX [03c1]
    s.ax=ix::add(s.ax,s.cx,32u,s.arithmetic_flags);
    // 0x006c5542: LEA ECX,[ESP + 0x1c] [8d4c241c]
    s.cx=f.sp+0x1cu;
    // 0x006c5546: MOV word ptr [ESP + 0x18],AX [6689442418]
    m.w16(f.sp+0x18u,(s.ax&0xffffu));
    // 0x006c554b: MOV word ptr [ESP + 0x1a],DX [668954241a]
    m.w16(f.sp+0x1au,(s.dx&0xffffu));
    // 0x006c5550: MOV EAX,dword ptr [ESP + 0x18] [8b442418]
    s.ax=m.r32(f.sp+0x18u);
    // 0x006c5554: PUSH ECX [51]
    f.push(m,s.cx);
    // 0x006c5555: MOV ECX,0x81a820 [b920a88100]
    s.cx=0x81a820u;
    // 0x006c555a: MOV dword ptr [ESP + 0x20],EAX [89442420]
    m.w32(f.sp+0x20u,s.ax);
    // 0x006c555e: CALL 0x00545500 [e89dffe7ff]
    {
        f.push(m,0x6c5563u);
        Frame child{f.sp,f.sp,0x6c5563u};
        map_545500(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c5563: MOV CX,word ptr [ESP + 0x12] [668b4c2412]
    s.cx=(s.cx&0xffff0000u)|((m.r16(f.sp+0x12u))&0xffffu);
    // 0x006c5568: MOV EDX,dword ptr [ESP + 0x10] [8b542410]
    s.dx=m.r32(f.sp+0x10u);
    // 0x006c556c: ADD CX,word ptr [0x00839dae] [66030dae9d8300]
    s.cx=(s.cx&0xffff0000u)|((ix::add((s.cx&0xffffu),m.r16(0x839daeu),16u,s.arithmetic_flags))&0xffffu);
    // 0x006c5573: MOV EBX,EAX [8bd8]
    s.bx=s.ax;
    // 0x006c5575: MOV EAX,[0x00839dac] [a1ac9d8300]
    s.ax=m.r32(0x839dacu);
    // 0x006c557a: ADD EDX,EAX [03d0]
    s.dx=ix::add(s.dx,s.ax,32u,s.arithmetic_flags);
    // 0x006c557c: MOV word ptr [ESP + 0x1a],CX [66894c241a]
    m.w16(f.sp+0x1au,(s.cx&0xffffu));
    // 0x006c5581: MOV word ptr [ESP + 0x18],DX [6689542418]
    m.w16(f.sp+0x18u,(s.dx&0xffffu));
    // 0x006c5586: MOV EDX,dword ptr [ESP + 0x18] [8b542418]
    s.dx=m.r32(f.sp+0x18u);
    // 0x006c558a: LEA EAX,[ESP + 0x18] [8d442418]
    s.ax=f.sp+0x18u;
    // 0x006c558e: MOV ECX,0x81a820 [b920a88100]
    s.cx=0x81a820u;
    // 0x006c5593: PUSH EAX [50]
    f.push(m,s.ax);
    // 0x006c5594: MOV dword ptr [ESP + 0x1c],EDX [8954241c]
    m.w32(f.sp+0x1cu,s.dx);
    // 0x006c5598: CALL 0x00545500 [e863ffe7ff]
    {
        f.push(m,0x6c559du);
        Frame child{f.sp,f.sp,0x6c559du};
        map_545500(m,s,child);
        f.sp=child.sp;
    }
    // 0x006c559d: TEST EDI,EDI [85ff]
    (void)ix::logical(s.di&s.di,32u,s.arithmetic_flags);
    // 0x006c559f: JZ 0x006c563b [0f8496000000]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c559f");
    // 0x006c55a5: TEST EBX,EBX [85db]
    (void)ix::logical(s.bx&s.bx,32u,s.arithmetic_flags);
    // 0x006c55a7: JZ 0x006c563b [0f848e000000]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c55a7");
    // 0x006c55ad: TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32u,s.arithmetic_flags);
    // 0x006c55af: JZ 0x006c563b [0f8486000000]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c55af");
    // 0x006c55b5: MOV EDI,dword ptr [EDI + 0x44] [8b7f44]
    s.di=m.r32(s.di+0x44u);
    // 0x006c55b8: CMP EDI,-0x1 [83ffff]
    (void)ix::sub(s.di,0xffffffffu,32u,s.arithmetic_flags);
    // 0x006c55bb: JZ 0x006c55e2 [7425]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c55bb");
    // 0x006c55bd: MOV ECX,dword ptr [0x00a1e11c] [8b0d1ce1a100]
    s.cx=m.r32(0xa1e11cu);
    // 0x006c55c3: MOV EDX,dword ptr [ECX + EDI*0x4] [8b14b9]
    s.dx=m.r32(s.cx+s.di*0x4u);
    // 0x006c55c6: MOV AL,byte ptr [EDX + 0x285] [8a8285020000]
    s.ax=(s.ax&0xffffff00u)|((m.r8(s.dx+0x285u))&0xffu);
    // 0x006c55cc: TEST AL,AL [84c0]
    (void)ix::logical((s.ax&0xffu)&(s.ax&0xffu),8u,s.arithmetic_flags);
    // 0x006c55ce: JZ 0x006c563b [746b]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("2C5410 unselected branch at 0x6c55ce");
    // 0x006c55d0: MOV ECX,dword ptr [0x007e09bc] [8b0dbc097e00]
    s.cx=m.r32(0x7e09bcu);
    // 0x006c55d6: POP EDI [5f]
    s.di=f.pop(m);
    // 0x006c55d7: POP ESI [5e]
    s.si=f.pop(m);
    // 0x006c55d8: LEA EAX,[ECX + EBP*0x1 + -0x1] [8d4429ff]
    s.ax=s.cx+s.bp*0x1u+-0x1u;
    // 0x006c55dc: POP EBP [5d]
    s.bp=f.pop(m);
    // 0x006c55dd: POP EBX [5b]
    s.bx=f.pop(m);
    // 0x006c55de: ADD ESP,0x5c [83c45c]
    f.sp=ix::add(f.sp,0x5cu,32u,s.arithmetic_flags);
    // 0x006c55e1: RET [c3]
    recovery_b566::finish(m,s,f,0u);
}

namespace {
void basis(bool ok){if(!ok)throw std::domain_error("2C5410 outside frozen selected public/input basis");}
struct Range {U base;U size;};
void mapped(const Memory& m,Range r){basis(r.size&&std::uint64_t(r.base)+r.size<=0x100000000ull);for(U k=0;k<r.size;++k)(void)m.r8(r.base+k);}
bool separate(Range a,Range b){return std::uint64_t(a.base)+a.size<=b.base||std::uint64_t(b.base)+b.size<=a.base;}
}
void require_selected_basis(const Memory& m,const State& s,const Frame& f){
    // These are readonly declared-input checks, not OS ownership/writability proofs.
    basis(f.sp==f.entry_sp&&f.entry_sp>=0x88u&&f.entry_sp<=0xffffffbbu);
    const Range stack{f.entry_sp-0x88u,0xccu}; mapped(m,stack);
    basis(m.r32(f.entry_sp)==f.outer_return);
    const U self=s.cx; mapped(m,{self,0x5ccu});
    basis(m.r32(self)==0x798c88u&&m.r32(0x798e40u)==0x5cce90u&&
          m.r32(0x798e28u)==0x41b320u&&m.r32(0x798cb4u)==0x6fee90u);
    basis(m.r32(self+0x88u)==0x1e80u&&m.r32(self+0x8cu)==0x1e80u&&
          m.r32(self+0x90u)==0u&&m.r8(self+0x370u)==0u);
    const U type=m.r32(self+0x5acu); basis(type!=0u); mapped(m,{type,0xba8u});basis(m.r8(type+0xba6u)==0u);
    const U table=m.r32(0x81a958u);basis(table!=0u);mapped(m,{table,0x100000u});
    const U center=m.r32(table+4u*(30u*512u+30u));
    const U south=m.r32(table+4u*(31u*512u+30u));
    const U east=m.r32(table+4u*(30u*512u+31u));
    const U se=m.r32(table+4u*(31u*512u+31u));
    basis(center&&south&&east&&se);mapped(m,{center,0x11du});mapped(m,{south,0x48u});mapped(m,{east,0x48u});mapped(m,{se,0x48u});
    basis(m.r8(center+0x11cu)==1u&&m.r32(south+0x44u)==0u);
    const U types=m.r32(0xa1e11cu);basis(types!=0u);mapped(m,{types,4u});const U q=m.r32(types);basis(q!=0u);mapped(m,{q,0x286u});basis(m.r8(q+0x285u)==1u);
    const std::array<Range,9> owned{{{self,0x5ccu},{type,0xba8u},{table,0x100000u},{center,0x11du},{south,0x48u},{east,0x48u},{se,0x48u},{types,4u},{q,0x286u}}};
    for(unsigned i=0;i<owned.size();++i){basis(separate(owned[i],stack));for(unsigned j=0;j<i;++j)basis(separate(owned[i],owned[j]));}
    const std::array<Range,8> globals{{{0x798c88u,0x1bcu},{0x81a958u,4u},{0x839da0u,32u},{0xa1e11cu,4u},{0xaa5f90u,8u},{0x785728u,8u},{0x7c3a04u,4u},{0x7e09bcu,4u}}};
    for(auto g:globals){mapped(m,g);basis(separate(g,stack));for(auto r:owned)basis(separate(g,r));}
    constexpr std::array<U,8> direction{{0xffff0000u,0xffff0001u,1u,0x10001u,0x10000u,0x1ffffu,0xffffu,0xffffffffu}};
    for(U i=0;i<8u;++i)basis(m.r32(0x839da0u+4u*i)==direction[i]);
    basis(m.r32(0xaa5f90u)==0u&&m.r32(0xaa5f94u)==0u&&
          m.r32(0x785728u)==0u&&m.r32(0x78572cu)==0x3fe00000u&&
          m.r32(0x7c3a04u)==0xe7fu&&m.r32(0x7e09bcu)==3u);
    // Frozen incoming FP108 only (c8e8271f...); never a target/poststate oracle.
    constexpr std::array<std::uint8_t,108> incoming{{0x7f,0x3,0xff,0xff,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0}};
    basis(s.fp.image.bytes==incoming);
}
} // namespace ra2::recovered::recovery_b1707
