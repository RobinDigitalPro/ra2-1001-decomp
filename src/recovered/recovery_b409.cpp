#include "recovered/recovery_b409.hpp"
#include "recovered/recovery_b389.hpp"
#include "recovered/leaf_b56_b.hpp"
#include <array>
namespace ra2::recovered::recovery_b409 {
unsigned fun_00497c60(Memory&caller,const Inputs&i){
 // The original conversion writes three bytes over the by-value fourth
 // argument. Preserve its high byte and use separate private result storage.
 std::array<unsigned char,32> bytes{};leaf::Memory converted(bytes.data(),0x1000,bytes.size());
 for(unsigned k=0;k<3;++k)converted.w8(0x1000+k,caller.r8(i.arg[3]+0x308+k));
 leaf::Inputs cv{};cv.cx=0x1000;cv.arg[0]=0x1010;leaf::fun_004fe550(converted,cv);
 const auto r=converted.r8(0x1010),g=converted.r8(0x1011),b=converted.r8(0x1012);
 i.arg[3]=(i.arg[3]&0xff000000u)|r|(g<<8)|(b<<16);
 auto shifted=[&](unsigned v,unsigned down,unsigned up){return (v>>(down&31))<<(up&31);};
 const auto color=shifted(b,caller.r8(0x83b2f4),caller.r32(0x83b2f0))|shifted(g,caller.r8(0x83b2fc),caller.r32(0x83b2f8))|shifted(r,caller.r8(0x83b2ec),caller.r32(0x83b2e8));
 constexpr unsigned local=0xf1000000;std::array<unsigned char,8> result{};leaf::Memory span(result.data(),local,result.size());Memory m=caller;m.add(span);
 Inputs child=i;child.cx=local;child.arg[3]=color;recovery_b389::fun_00497ac0(m,child);
 caller.w32(i.cx,m.r32(local));caller.w32(i.cx+4,m.r32(local+4));return i.cx;
}
}
