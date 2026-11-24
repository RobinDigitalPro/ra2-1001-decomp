#include "recovery_b331.hpp"

#include <cstdint>
#include <stdexcept>

namespace ra2::recovered::recovery_b331 {
std::uint32_t fun_00478360(Memory& memory, const Inputs& input) {
    if (input.cx == 0u || input.arg[0] != 1u || input.arg[3] != 0xffffffffu ||
        input.arg[5] != 0xffffffffu)
        throw std::domain_error("B331 requires the bounded first-row coefficient route");
    if ((memory.r32(input.cx + 0x140u) & 0x100u) != 0u ||
        memory.r8(input.cx + 0x124u) != 0u ||
        memory.r32(input.cx + 0x44u) != 0xffffffffu ||
        memory.r32(input.cx + 0xecu) != 0u)
        throw std::domain_error("B331 receiver fields do not select the bounded table comparison");
    if (memory.r32(0x00785738u) != 0u)
        throw std::domain_error("B331 requires the original zero float threshold");

    // arg0==1 makes the original address 0x8391d0 + 4*arg0 = 0x8391d4,
    // the first dword of the stride-24 data row. For finite normal inputs,
    // FNSTSW reports C0 in AH for a negative value and C3 in AH for equality.
    const auto bits = memory.r32(0x008391d4u);
    const auto exponent = bits & 0x7f800000u;
    const auto magnitude = bits & 0x7fffffffu;
    if (exponent == 0x7f800000u || (exponent == 0u && magnitude != 0u))
        throw std::domain_error("B331 finite route excludes subnormal and nonfinite encodings");
    if(input.fp.image.word(0)!=0x037f||input.fp.image.word(4)!=0||input.fp.image.word(8)!=0xffff)
        throw std::domain_error("331 initially empty x87 stack with default masked control");
    input.fp.load32(bits);input.fp.compare_pop32(memory.r32(0x785738));
    const auto status=input.fp.status();
    return (status&0x4000)?unsigned(status)&0xff00u:(unsigned(status)&0xff00u)|1u;
}
unsigned fun_0054e180(Memory&m,const Inputs&i){
    if(i.arg[1]!=1||i.arg[2]!=1||i.arg[3]!=1||i.arg[4]!=0xffffffff||i.arg[6]!=0xffffffff||i.arg[8]!=0)
        throw std::domain_error("331 one-cell original consumer bounds");
    const auto saved_six=i.arg[6];const auto x=m.r16(i.arg[0]),y=m.r16(i.arg[0]+2);
    if(x<1||x>31||y<1||y>31)throw std::domain_error("331 positive in-range map coordinate");
    i.arg[6]=x|(y<<16);
    const auto cell=m.r32(m.r32(0x81a958)+4*(y*512+x));
    if(!cell)throw std::domain_error("331 valid supplied map cell");
    Inputs callee=i;callee.cx=cell;callee.arg[0]=i.arg[3];callee.arg[1]=0;callee.arg[2]=0;
    callee.arg[3]=i.arg[4];callee.arg[4]=i.arg[5];callee.arg[5]=saved_six;callee.arg[6]=i.arg[7];
    const auto result=fun_00478360(m,callee);i.fp=callee.fp;
    // Failure returns immediately with the helper's AH intact. Success
    // reloads height and width (both1) before MOV AL,1 in the root epilogue.
    return (result&255)?1u:result&0xffffff00u;
}
}
