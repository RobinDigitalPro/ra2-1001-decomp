#include "recovered/codec_b78.hpp"
#include <cstdint>
namespace ra2::recovered::codec_b78 {
// Literal and match states follow 0x53cb50, including the two distinct
// short-offset states after an ordinary literal run and after match tails.
std::uint32_t fun_0053cb50(Memory& m,const Inputs& i){
    using U=std::uint32_t;
    U s=i.cx,d=i.arg[0],t=0;const U start=d,end=s+i.dx;
    m.w32(i.arg[1],0);
    auto literal=[&](U n){while(n--)m.w8(d++,m.r8(s++));};
    auto match=[&](U distance,U n){U p=d-distance;while(n--)m.w8(d++,m.r8(p++));};
    auto extended=[&](U base){while(m.r8(s)==0){base+=255;++s;}return base+m.r8(s++);};
    if(m.r8(s)>17){t=m.r8(s++)-17;literal(t);goto after_literals;}
next_control:
    t=m.r8(s++);
    if(t>=16)goto long_match;
    if(!t)t=extended(15);
    literal(t+3);
after_literals:
    t=m.r8(s++);
    if(t>=16)goto long_match;
    match(0x801u+(t>>2)+(m.r8(s++)<<2),3);
    goto after_match;
long_match:
    if(t>=64){const U distance=1+((t>>2)&7)+(m.r8(s++)<<3);match(distance,(t>>5)+1);}
    else if(t>=32){t&=31;if(!t)t=extended(31);const U lo=m.r8(s++),hi=m.r8(s++);match(1+(lo>>2)+(hi<<6),t+2);}
    else {U distance=(t&8)<<11;t&=7;if(!t)t=extended(7);const U lo=m.r8(s++),hi=m.r8(s++);distance+=(lo>>2)+(hi<<6);
        if(!distance){m.w32(i.arg[1],d-start);return s==end?0u:0xffffffffu;}
        match(distance+0x4000,t+2);
    }
after_match:
    t=m.r8(s-2)&3;
    if(!t)goto next_control;
    literal(t);t=m.r8(s++);
    if(t>=16)goto long_match;
    match(1+(t>>2)+(m.r8(s++)<<2),2);
    goto after_match;
}
}
