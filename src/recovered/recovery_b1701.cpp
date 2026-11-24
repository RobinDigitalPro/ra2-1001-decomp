#include "recovery_b1701.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1701 {
namespace ix=direct_b33::integer;
void execute_selected(Memory&m,State&s,Frame&f){
    helpers::require_selected_basis(m,s,f); // readonly before first guest instruction
L62a890: // SUB ESP,0x48 [83ec48]
    f.sp=ix::sub(f.sp,0x48u,32,s.arithmetic_flags);
L62a893: // PUSH EBX [53]
    f.push(m,s.bx);
L62a894: // PUSH EBP [55]
    f.push(m,s.bp);
L62a895: // PUSH ESI [56]
    f.push(m,s.si);
L62a896: // MOV ESI,ECX [8bf1]
    s.si=s.cx;
L62a898: // PUSH EDI [57]
    f.push(m,s.di);
L62a899: // LEA EBX,[ESI + 0x1208] [8d9e08120000]
    s.bx=(s.si + 0x1208u);
L62a89f: // MOV EAX,EBX [8bc3]
    s.ax=s.bx;
L62a8a1: // MOV dword ptr [ESP + 0x34],EBX [895c2434]
    m.w32((f.sp + 0x34u),s.bx);
L62a8a5: // MOV ECX,dword ptr [EAX] [8b08]
    s.cx=m.r32((s.ax));
L62a8a7: // MOV dword ptr [ESP + 0x48],ECX [894c2448]
    m.w32((f.sp + 0x48u),s.cx);
L62a8ab: // MOV EDX,dword ptr [EAX + 0x4] [8b5004]
    s.dx=m.r32((s.ax + 0x4u));
L62a8ae: // MOV dword ptr [ESP + 0x4c],EDX [8954244c]
    m.w32((f.sp + 0x4cu),s.dx);
L62a8b2: // MOV ECX,dword ptr [EAX + 0x8] [8b4808]
    s.cx=m.r32((s.ax + 0x8u));
L62a8b5: // MOV dword ptr [ESP + 0x50],ECX [894c2450]
    m.w32((f.sp + 0x50u),s.cx);
L62a8b9: // MOV ECX,dword ptr [ESI + 0x14ac] [8b8eac140000]
    s.cx=m.r32((s.si + 0x14acu));
L62a8bf: // MOV EDX,dword ptr [EAX + 0xc] [8b500c]
    s.dx=m.r32((s.ax + 0xcu));
L62a8c2: // MOV EAX,0x1 [b801000000]
    s.ax=0x1u;
L62a8c7: // CMP ECX,EAX [3bc8]
    (void)ix::sub(s.cx,s.ax,32,s.arithmetic_flags);
L62a8c9: // MOV dword ptr [ESP + 0x54],EDX [89542454]
    m.w32((f.sp + 0x54u),s.dx);
L62a8cd: // JNZ 0x0062a8dd [750e]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62A8CD");
L62a8cf: // MOV ECX,dword ptr [ESI + 0x14a8] [8b8ea8140000]
    s.cx=m.r32((s.si + 0x14a8u));
L62a8d5: // MOV byte ptr [ESP + 0x12],AL [88442412]
    m.w8((f.sp + 0x12u),(s.ax&255u));
L62a8d9: // CMP ECX,EAX [3bc8]
    (void)ix::sub(s.cx,s.ax,32,s.arithmetic_flags);
L62a8db: // JZ 0x0062a8e2 [7405]
    if(ix::condition("JZ",s.arithmetic_flags)) goto L62a8e2; throw std::domain_error("22A890 escaped selected branch at62A8DB");
L62a8e2: // MOV EAX,[0x00821978] [a178198200]
    s.ax=m.r32((0x00821978u));
L62a8e7: // MOV ECX,dword ptr [0x00821970] [8b0d70198200]
    s.cx=m.r32((0x00821970u));
L62a8ed: // CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
L62a8ee: // SUB EAX,EDX [2bc2]
    s.ax=ix::sub(s.ax,s.dx,32,s.arithmetic_flags);
L62a8f0: // SAR EAX,0x1 [d1f8]
    s.ax=ix::shift(s.ax,0x1u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
L62a8f2: // ADD EAX,ECX [03c1]
    s.ax=ix::add(s.ax,s.cx,32,s.arithmetic_flags);
L62a8f4: // LEA ECX,[ESP + 0x38] [8d4c2438]
    s.cx=(f.sp + 0x38u);
L62a8f8: // MOV dword ptr [ESP + 0x24],EAX [89442424]
    m.w32((f.sp + 0x24u),s.ax);
L62a8fc: // MOV EAX,[0x0082197c] [a17c198200]
    s.ax=m.r32((0x0082197cu));
L62a901: // CDQ [99]
    s.dx=(s.ax&0x80000000u)?0xffffffffu:0u;
L62a902: // SUB EAX,EDX [2bc2]
    s.ax=ix::sub(s.ax,s.dx,32,s.arithmetic_flags);
L62a904: // MOV EDX,dword ptr [0x00821974] [8b1574198200]
    s.dx=m.r32((0x00821974u));
L62a90a: // SAR EAX,0x1 [d1f8]
    s.ax=ix::shift(s.ax,0x1u,32,s.arithmetic_flags,ix::Shift::arithmetic_right);
L62a90c: // ADD EAX,EDX [03c2]
    s.ax=ix::add(s.ax,s.dx,32,s.arithmetic_flags);
L62a90e: // MOV dword ptr [ESP + 0x28],EAX [89442428]
    m.w32((f.sp + 0x28u),s.ax);
L62a912: // LEA EAX,[ESP + 0x24] [8d442424]
    s.ax=(f.sp + 0x24u);
L62a916: // PUSH EAX [50]
    f.push(m,s.ax);
L62a917: // PUSH ECX [51]
    f.push(m,s.cx);
L62a918: // MOV ECX,dword ptr [0x00821cac] [8b0dac1c8200]
    s.cx=m.r32((0x00821cacu));
L62a91e: // CALL 0x0069c210 [e8ed180700]
    helpers::pick(m,s,f,0x62a923u);
L62a923: // PUSH EAX [50]
    f.push(m,s.ax);
L62a924: // MOV ECX,0x81a820 [b920a88100]
    s.cx=0x81a820u;
L62a929: // CALL 0x00545500 [e8d2abf1ff]
    helpers::map_cell(m,s,f,0x62a92eu);
L62a92e: // MOV EAX,dword ptr [EAX + 0x24] [8b4024]
    s.ax=m.r32((s.ax + 0x24u));
L62a931: // MOV ECX,dword ptr [ESI + 0x148c] [8b8e8c140000]
    s.cx=m.r32((s.si + 0x148cu));
L62a937: // MOV dword ptr [ESP + 0x24],EAX [89442424]
    m.w32((f.sp + 0x24u),s.ax);
L62a93b: // MOV EDX,dword ptr [ESI + 0x1498] [8b9698140000]
    s.dx=m.r32((s.si + 0x1498u));
L62a941: // MOVSX EBP,word ptr [ESP + 0x26] [0fbf6c2426]
    s.bp=U(ix::sign_extend(m.r16((f.sp + 0x26u)),16));
L62a946: // MOVSX EAX,AX [0fbfc0]
    s.ax=U(ix::sign_extend((s.ax&65535u),16));
L62a949: // SUB ECX,EBP [2bcd]
    s.cx=ix::sub(s.cx,s.bp,32,s.arithmetic_flags);
L62a94b: // LEA EDI,[ESI + 0x1498] [8dbe98140000]
    s.di=(s.si + 0x1498u);
L62a951: // ADD ECX,EAX [03c8]
    s.cx=ix::add(s.cx,s.ax,32,s.arithmetic_flags);
L62a953: // MOV dword ptr [ESP + 0x24],EDX [89542424]
    m.w32((f.sp + 0x24u),s.dx);
L62a957: // MOV dword ptr [ESP + 0x14],ECX [894c2414]
    m.w32((f.sp + 0x14u),s.cx);
L62a95b: // MOV dword ptr [ESP + 0x38],EAX [89442438]
    m.w32((f.sp + 0x38u),s.ax);
L62a95f: // FILD dword ptr [ESP + 0x14] [db442414]
    s.fp.load_integer32(m.r32((f.sp + 0x14u)));
L62a963: // FMUL float ptr [ESI + 0x1484] [d88e84140000]
    s.fp.multiply32(m.r32((s.si + 0x1484u)));
L62a969: // FIADD dword ptr [ESP + 0x24] [da442424]
    floating_b61::fp_extended::add_integer32(s.fp,m.r32((f.sp + 0x24u)));
L62a96d: // CALL 0x0076aa50 [e8de001400]
    helpers::ftol(m,s,f,0x62a972u);
L62a972: // MOV EDX,dword ptr [ESI + 0x1494] [8b9694140000]
    s.dx=m.r32((s.si + 0x1494u));
L62a978: // MOV ECX,dword ptr [ESP + 0x38] [8b4c2438]
    s.cx=m.r32((f.sp + 0x38u));
L62a97c: // SUB EBP,EDX [2bea]
    s.bp=ix::sub(s.bp,s.dx,32,s.arithmetic_flags);
L62a97e: // MOV dword ptr [ESP + 0x14],EAX [89442414]
    m.w32((f.sp + 0x14u),s.ax);
L62a982: // ADD EBP,ECX [03e9]
    s.bp=ix::add(s.bp,s.cx,32,s.arithmetic_flags);
L62a984: // MOV dword ptr [ESP + 0x38],EBP [896c2438]
    m.w32((f.sp + 0x38u),s.bp);
L62a988: // FILD dword ptr [ESP + 0x38] [db442438]
    s.fp.load_integer32(m.r32((f.sp + 0x38u)));
L62a98c: // FMUL float ptr [ESI + 0x1484] [d88e84140000]
    s.fp.multiply32(m.r32((s.si + 0x1484u)));
L62a992: // FIADD dword ptr [ESI + 0x149c] [da869c140000]
    floating_b61::fp_extended::add_integer32(s.fp,m.r32((s.si + 0x149cu)));
L62a998: // CALL 0x0076aa50 [e8b3001400]
    helpers::ftol(m,s,f,0x62a99du);
L62a99d: // MOV EDX,dword ptr [ESP + 0x24] [8b542424]
    s.dx=m.r32((f.sp + 0x24u));
L62a9a1: // MOV dword ptr [ESP + 0x38],EAX [89442438]
    m.w32((f.sp + 0x38u),s.ax);
L62a9a5: // MOV EAX,dword ptr [ESP + 0x14] [8b442414]
    s.ax=m.r32((f.sp + 0x14u));
L62a9a9: // DEC EDX [4a]
    s.dx=ix::decrement(s.dx,32,s.arithmetic_flags);
L62a9aa: // CMP EAX,EDX [3bc2]
    (void)ix::sub(s.ax,s.dx,32,s.arithmetic_flags);
L62a9ac: // JNZ 0x0062a9b3 [7505]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L62a9b3; throw std::domain_error("22A890 escaped selected branch at62A9AC");
L62a9b3: // FLD float ptr [0x00793804] [d90504387900]
    s.fp.load32(m.r32((0x00793804u)));
L62a9b9: // FDIV float ptr [ESI + 0x1484] [d8b684140000]
    floating_b61::fp_extended::divide32(s.fp,m.r32((s.si + 0x1484u)));
L62a9bf: // MOV EDX,dword ptr [ESP + 0x14] [8b542414]
    s.dx=m.r32((f.sp + 0x14u));
L62a9c3: // LEA EBP,[ESI + 0x14d8] [8daed8140000]
    s.bp=(s.si + 0x14d8u);
L62a9c9: // MOV EAX,EBP [8bc5]
    s.ax=s.bp;
L62a9cb: // MOV ECX,0x1 [b901000000]
    s.cx=0x1u;
L62a9d0: // MOV dword ptr [ESP + 0x30],ECX [894c2430]
    m.w32((f.sp + 0x30u),s.cx);
L62a9d4: // MOV dword ptr [EAX],EDX [8910]
    m.w32((s.ax),s.dx);
L62a9d6: // MOV EDX,dword ptr [ESP + 0x38] [8b542438]
    s.dx=m.r32((f.sp + 0x38u));
L62a9da: // MOV dword ptr [EAX + 0x4],EDX [895004]
    m.w32((s.ax + 0x4u),s.dx);
L62a9dd: // MOV dword ptr [EAX + 0x8],ECX [894808]
    m.w32((s.ax + 0x8u),s.cx);
L62a9e0: // MOV dword ptr [EAX + 0xc],ECX [89480c]
    m.w32((s.ax + 0xcu),s.cx);
L62a9e3: // MOV EDX,dword ptr [0x00821978] [8b1578198200]
    s.dx=m.r32((0x00821978u));
L62a9e9: // LEA EAX,[EDX + EDX*0x1] [8d0412]
    s.ax=(s.dx + s.dx*0x1u);
L62a9ec: // MOV dword ptr [ESP + 0x38],EAX [89442438]
    m.w32((f.sp + 0x38u),s.ax);
L62a9f0: // FILD dword ptr [ESP + 0x38] [db442438]
    s.fp.load_integer32(m.r32((f.sp + 0x38u)));
L62a9f4: // FDIV ST0,ST1 [d8f1]
    numeric_b88::detail::reg<0xd8f1>(s.fp);
L62a9f6: // FADD float ptr [0x007867f8] [d805f8677800]
    s.fp.add32(m.r32((0x007867f8u)));
L62a9fc: // CALL 0x0076aa50 [e84f001400]
    helpers::ftol(m,s,f,0x62aa01u);
L62aa01: // FLD float ptr [0x00793800] [d90500387900]
    s.fp.load32(m.r32((0x00793800u)));
L62aa07: // FDIV float ptr [ESI + 0x1484] [d8b684140000]
    floating_b61::fp_extended::divide32(s.fp,m.r32((s.si + 0x1484u)));
L62aa0d: // MOV dword ptr [ESI + 0x14e0],EAX [8986e0140000]
    m.w32((s.si + 0x14e0u),s.ax);
L62aa13: // MOV ECX,dword ptr [0x0082197c] [8b0d7c198200]
    s.cx=m.r32((0x0082197cu));
L62aa19: // LEA EDX,[ECX + ECX*0x1] [8d1409]
    s.dx=(s.cx + s.cx*0x1u);
L62aa1c: // MOV dword ptr [ESP + 0x38],EDX [89542438]
    m.w32((f.sp + 0x38u),s.dx);
L62aa20: // FSTP float ptr [ESP + 0x24] [d95c2424]
    m.w32((f.sp + 0x24u),s.fp.pop32());
L62aa24: // FILD dword ptr [ESP + 0x38] [db442438]
    s.fp.load_integer32(m.r32((f.sp + 0x38u)));
L62aa28: // FDIV float ptr [ESP + 0x24] [d8742424]
    floating_b61::fp_extended::divide32(s.fp,m.r32((f.sp + 0x24u)));
L62aa2c: // CALL 0x0076aa50 [e81f001400]
    helpers::ftol(m,s,f,0x62aa31u);
L62aa31: // MOV dword ptr [ESI + 0x14e4],EAX [8986e4140000]
    m.w32((s.si + 0x14e4u),s.ax);
L62aa37: // FILD dword ptr [0x00821978] [db0578198200]
    s.fp.load_integer32(m.r32((0x00821978u)));
L62aa3d: // FDIV ST0,ST1 [d8f1]
    numeric_b88::detail::reg<0xd8f1>(s.fp);
L62aa3f: // CALL 0x0076aa50 [e80c001400]
    helpers::ftol(m,s,f,0x62aa44u);
L62aa44: // MOV dword ptr [ESP + 0x14],EAX [89442414]
    m.w32((f.sp + 0x14u),s.ax);
L62aa48: // MOV EAX,[0x0082197c] [a17c198200]
    s.ax=m.r32((0x0082197cu));
L62aa4d: // FSTP ST0 [ddd8]
    s.fp.pop_st0();
L62aa4f: // LEA ECX,[EAX + EAX*0x1] [8d0c00]
    s.cx=(s.ax + s.ax*0x1u);
L62aa52: // MOV dword ptr [ESP + 0x38],ECX [894c2438]
    m.w32((f.sp + 0x38u),s.cx);
L62aa56: // FILD dword ptr [ESP + 0x38] [db442438]
    s.fp.load_integer32(m.r32((f.sp + 0x38u)));
L62aa5a: // FDIV float ptr [ESP + 0x24] [d8742424]
    floating_b61::fp_extended::divide32(s.fp,m.r32((f.sp + 0x24u)));
L62aa5e: // FMUL float ptr [0x00788d80] [d80d808d7800]
    s.fp.multiply32(m.r32((0x00788d80u)));
L62aa64: // CALL 0x0076aa50 [e8e7ff1300]
    helpers::ftol(m,s,f,0x62aa69u);
L62aa69: // MOV EDX,dword ptr [ESP + 0x14] [8b542414]
    s.dx=m.r32((f.sp + 0x14u));
L62aa6d: // MOV ECX,dword ptr [EBP] [8b4d00]
    s.cx=m.r32((s.bp));
L62aa70: // SUB ECX,EDX [2bca]
    s.cx=ix::sub(s.cx,s.dx,32,s.arithmetic_flags);
L62aa72: // MOV dword ptr [EBP],ECX [894d00]
    m.w32((s.bp),s.cx);
L62aa75: // MOV ECX,dword ptr [EBP + 0x4] [8b4d04]
    s.cx=m.r32((s.bp + 0x4u));
L62aa78: // SUB ECX,EAX [2bc8]
    s.cx=ix::sub(s.cx,s.ax,32,s.arithmetic_flags);
L62aa7a: // MOV dword ptr [EBP + 0x4],ECX [894d04]
    m.w32((s.bp + 0x4u),s.cx);
L62aa7d: // MOV ECX,dword ptr [EBP] [8b4d00]
    s.cx=m.r32((s.bp));
L62aa80: // MOV EAX,dword ptr [EDI] [8b07]
    s.ax=m.r32((s.di));
L62aa82: // CMP ECX,EAX [3bc8]
    (void)ix::sub(s.cx,s.ax,32,s.arithmetic_flags);
L62aa84: // JGE 0x0062aa8b [7d05]
    if(ix::condition("JGE",s.arithmetic_flags)) goto L62aa8b; throw std::domain_error("22A890 escaped selected branch at62AA84");
L62aa8b: // MOV EDX,dword ptr [ESI + 0x14a0] [8b96a0140000]
    s.dx=m.r32((s.si + 0x14a0u));
L62aa91: // MOV dword ptr [ESP + 0x24],EDX [89542424]
    m.w32((f.sp + 0x24u),s.dx);
L62aa95: // MOV EDX,dword ptr [ESI + 0x14e0] [8b96e0140000]
    s.dx=m.r32((s.si + 0x14e0u));
L62aa9b: // ADD EDX,ECX [03d1]
    s.dx=ix::add(s.dx,s.cx,32,s.arithmetic_flags);
L62aa9d: // MOV ECX,dword ptr [ESP + 0x24] [8b4c2424]
    s.cx=m.r32((f.sp + 0x24u));
L62aaa1: // ADD ECX,EAX [03c8]
    s.cx=ix::add(s.cx,s.ax,32,s.arithmetic_flags);
L62aaa3: // CMP EDX,ECX [3bd1]
    (void)ix::sub(s.dx,s.cx,32,s.arithmetic_flags);
L62aaa5: // JL 0x0062aaba [7c13]
    if(ix::condition("JL",s.arithmetic_flags)) goto L62aaba; throw std::domain_error("22A890 escaped selected branch at62AAA5");
L62aaba: // MOV ECX,dword ptr [ESI + 0x14dc] [8b8edc140000]
    s.cx=m.r32((s.si + 0x14dcu));
L62aac0: // MOV EAX,dword ptr [ESI + 0x149c] [8b869c140000]
    s.ax=m.r32((s.si + 0x149cu));
L62aac6: // CMP ECX,EAX [3bc8]
    (void)ix::sub(s.cx,s.ax,32,s.arithmetic_flags);
L62aac8: // JGE 0x0062aad2 [7d08]
    if(ix::condition("JGE",s.arithmetic_flags)) goto L62aad2; throw std::domain_error("22A890 escaped selected branch at62AAC8");
L62aad2: // MOV EDX,dword ptr [ESI + 0x14e4] [8b96e4140000]
    s.dx=m.r32((s.si + 0x14e4u));
L62aad8: // MOV EAX,dword ptr [ESI + 0x14a4] [8b86a4140000]
    s.ax=m.r32((s.si + 0x14a4u));
L62aade: // ADD EDX,ECX [03d1]
    s.dx=ix::add(s.dx,s.cx,32,s.arithmetic_flags);
L62aae0: // MOV ECX,dword ptr [ESI + 0x149c] [8b8e9c140000]
    s.cx=m.r32((s.si + 0x149cu));
L62aae6: // ADD ECX,EAX [03c8]
    s.cx=ix::add(s.cx,s.ax,32,s.arithmetic_flags);
L62aae8: // CMP EDX,ECX [3bd1]
    (void)ix::sub(s.dx,s.cx,32,s.arithmetic_flags);
L62aaea: // JL 0x0062ab04 [7c18]
    if(ix::condition("JL",s.arithmetic_flags)) goto L62ab04; throw std::domain_error("22A890 escaped selected branch at62AAEA");
L62ab04: // MOV AL,byte ptr [ESI + 0x14d6] [8a86d6140000]
    s.ax=(s.ax&0xffffff00u)|(m.r8((s.si + 0x14d6u))&255u);
L62ab0a: // TEST AL,AL [84c0]
    (void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L62ab0c: // JZ 0x0062ab2c [741e]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB0C");
L62ab0e: // MOV ECX,EBP [8bcd]
    s.cx=s.bp;
L62ab10: // LEA EAX,[ESI + 0x14e8] [8d86e8140000]
    s.ax=(s.si + 0x14e8u);
L62ab16: // MOV EDX,dword ptr [ECX] [8b11]
    s.dx=m.r32((s.cx));
L62ab18: // MOV dword ptr [EAX],EDX [8910]
    m.w32((s.ax),s.dx);
L62ab1a: // MOV EDX,dword ptr [ECX + 0x4] [8b5104]
    s.dx=m.r32((s.cx + 0x4u));
L62ab1d: // MOV dword ptr [EAX + 0x4],EDX [895004]
    m.w32((s.ax + 0x4u),s.dx);
L62ab20: // MOV EDX,dword ptr [ECX + 0x8] [8b5108]
    s.dx=m.r32((s.cx + 0x8u));
L62ab23: // MOV dword ptr [EAX + 0x8],EDX [895008]
    m.w32((s.ax + 0x8u),s.dx);
L62ab26: // MOV ECX,dword ptr [ECX + 0xc] [8b490c]
    s.cx=m.r32((s.cx + 0xcu));
L62ab29: // MOV dword ptr [EAX + 0xc],ECX [89480c]
    m.w32((s.ax + 0xcu),s.cx);
L62ab2c: // MOV AL,byte ptr [ESI + 0x14d5] [8a86d5140000]
    s.ax=(s.ax&0xffffff00u)|(m.r8((s.si + 0x14d5u))&255u);
L62ab32: // TEST AL,AL [84c0]
    (void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L62ab34: // JNZ 0x0062ab99 [7563]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB34");
L62ab36: // MOV EDX,dword ptr [ESI + 0x14e8] [8b96e8140000]
    s.dx=m.r32((s.si + 0x14e8u));
L62ab3c: // MOV EAX,dword ptr [EBP] [8b4500]
    s.ax=m.r32((s.bp));
L62ab3f: // CMP EDX,EAX [3bd0]
    (void)ix::sub(s.dx,s.ax,32,s.arithmetic_flags);
L62ab41: // JNZ 0x0062ab99 [7556]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB41");
L62ab43: // MOV EAX,dword ptr [ESI + 0x14ec] [8b86ec140000]
    s.ax=m.r32((s.si + 0x14ecu));
L62ab49: // MOV ECX,dword ptr [EBP + 0x4] [8b4d04]
    s.cx=m.r32((s.bp + 0x4u));
L62ab4c: // CMP EAX,ECX [3bc1]
    (void)ix::sub(s.ax,s.cx,32,s.arithmetic_flags);
L62ab4e: // JNZ 0x0062ab99 [7549]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB4E");
L62ab50: // MOV ECX,dword ptr [ESI + 0x14f0] [8b8ef0140000]
    s.cx=m.r32((s.si + 0x14f0u));
L62ab56: // MOV EAX,dword ptr [EBP + 0x8] [8b4508]
    s.ax=m.r32((s.bp + 0x8u));
L62ab59: // CMP ECX,EAX [3bc8]
    (void)ix::sub(s.cx,s.ax,32,s.arithmetic_flags);
L62ab5b: // JNZ 0x0062ab99 [753c]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB5B");
L62ab5d: // MOV EDX,dword ptr [ESI + 0x14f4] [8b96f4140000]
    s.dx=m.r32((s.si + 0x14f4u));
L62ab63: // MOV EAX,dword ptr [EBP + 0xc] [8b450c]
    s.ax=m.r32((s.bp + 0xcu));
L62ab66: // CMP EDX,EAX [3bd0]
    (void)ix::sub(s.dx,s.ax,32,s.arithmetic_flags);
L62ab68: // JNZ 0x0062ab99 [752f]
    if(ix::condition("JNZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB68");
L62ab6a: // CALL 0x00633590 [e8218a0000]
    helpers::global_predicate(m,s,f,0x62ab6fu);
L62ab6f: // TEST AL,AL [84c0]
    (void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L62ab71: // JZ 0x0062ab99 [7426]
    if(ix::condition("JZ",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB71");
L62ab73: // MOV EAX,dword ptr [ESI + 0x1268] [8b8668120000]
    s.ax=m.r32((s.si + 0x1268u));
L62ab79: // TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32,s.arithmetic_flags);
L62ab7b: // JG 0x0062ab99 [7f1c]
    if(ix::condition("JG",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB7B");
L62ab7d: // MOV EAX,dword ptr [ESI + 0x1230] [8b8630120000]
    s.ax=m.r32((s.si + 0x1230u));
L62ab83: // TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32,s.arithmetic_flags);
L62ab85: // JG 0x0062ab99 [7f12]
    if(ix::condition("JG",s.arithmetic_flags)) throw std::domain_error("22A890 unselected branch at62AB85");
L62ab87: // MOV ECX,0x836c18 [b9186c8300]
    s.cx=0x836c18u;
L62ab8c: // CALL 0x0042eee0 [e84f43e0ff]
    helpers::empty_predicate(m,s,f,0x62ab91u);
L62ab91: // TEST AL,AL [84c0]
    (void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L62ab93: // JZ 0x0062b23a [0f84a1060000]
    if(ix::condition("JZ",s.arithmetic_flags)) goto L62b23a; throw std::domain_error("22A890 escaped selected branch at62AB93");
L62b23a: // MOV EAX,dword ptr [ESI + 0x1270] [8b8670120000]
    s.ax=m.r32((s.si + 0x1270u));
L62b240: // TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32,s.arithmetic_flags);
L62b242: // JZ 0x0062b288 [7444]
    if(ix::condition("JZ",s.arithmetic_flags)) goto L62b288; throw std::domain_error("22A890 escaped selected branch at62B242");
L62b288: // MOV AL,byte ptr [ESP + 0x12] [8a442412]
    s.ax=(s.ax&0xffffff00u)|(m.r8((f.sp + 0x12u))&255u);
L62b28c: // TEST AL,AL [84c0]
    (void)ix::logical((s.ax&255u)&(s.ax&255u),8,s.arithmetic_flags);
L62b28e: // JNZ 0x0062b2ab [751b]
    if(ix::condition("JNZ",s.arithmetic_flags)) goto L62b2ab; throw std::domain_error("22A890 escaped selected branch at62B28E");
L62b2ab: // POP EDI [5f]
    s.di=f.pop(m);
L62b2ac: // POP ESI [5e]
    s.si=f.pop(m);
L62b2ad: // POP EBP [5d]
    s.bp=f.pop(m);
L62b2ae: // POP EBX [5b]
    s.bx=f.pop(m);
L62b2af: // ADD ESP,0x48 [83c448]
    f.sp=ix::add(f.sp,0x48u,32,s.arithmetic_flags);
L62b2b2: // RET [c3]
    recovery_b566::finish(m,s,f,0u); return;
}
} // namespace ra2::recovered::recovery_b1701

namespace ra2::recovered::recovery_b1701::helpers {
void global_predicate(Memory&m,State&s,Frame&caller,U continuation){
    if(continuation!=0x62ab6fu)
        throw std::domain_error("22A890 global predicate continuation");
    caller.push(m,continuation);
    Frame f{caller.sp,caller.sp,continuation};
L633590: // MOV EAX,[0x00a9e318] [a118e3a900]
    s.ax=m.r32(0xa9e318u);
L633595: // TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32,s.arithmetic_flags);
L633597: // SETZ AL [0f94c0]
    s.ax=(s.ax&0xffffff00u)|((s.arithmetic_flags&ix::ZF)?1u:0u);
L63359a: // RET [c3]
    recovery_b566::finish(m,s,f,0u);
    caller.sp=f.sp;
}

void empty_predicate(Memory&m,State&s,Frame&caller,U continuation){
    if(continuation!=0x62ab91u||s.cx!=0x836c18u||m.r32(s.cx+0x60u)!=0u)
        throw std::domain_error("22A890 selected real zero-field predicate basis");
    caller.push(m,continuation);
    Frame f{caller.sp,caller.sp,continuation};
L42eee0: // SUB ESP,0xc [83ec0c]
    f.sp=ix::sub(f.sp,0xcu,32,s.arithmetic_flags);
L42eee3: // MOV EAX,dword ptr [ECX + 0x60] [8b4160]
    s.ax=m.r32(s.cx+0x60u);
L42eee6: // MOV dword ptr [ESP + 0x8],ECX [894c2408]
    m.w32(f.sp+8u,s.cx);
L42eeea: // TEST EAX,EAX [85c0]
    (void)ix::logical(s.ax&s.ax,32,s.arithmetic_flags);
L42eeec: // JZ 0x0042ef90 [0f849e000000]
    if(ix::condition("JZ",s.arithmetic_flags)) goto L42ef90;
    throw std::domain_error("22A890 unselected predicate pointer scan");
L42ef90: // XOR AL,AL [32c0]
    s.ax=(s.ax&0xffffff00u)|ix::logical((s.ax&255u)^(s.ax&255u),8,s.arithmetic_flags);
L42ef92: // ADD ESP,0xc [83c40c]
    f.sp=ix::add(f.sp,0xcu,32,s.arithmetic_flags);
L42ef95: // RET [c3]
    recovery_b566::finish(m,s,f,0u);
    caller.sp=f.sp;
}
} // namespace ra2::recovered::recovery_b1701::helpers
