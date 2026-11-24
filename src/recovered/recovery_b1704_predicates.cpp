#include "recovered/recovery_b1704.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1704 {
namespace ix=direct_b33::integer;
namespace calls {
void timer_41b390(Memory& m,State& s,Frame& caller,U continuation,U actual_target){
    if(actual_target!=0x41b390u||m.r32(s.cx)!=0x798c88u||m.r32(0x798fb4u)!=actual_target)
        throw std::domain_error("2C31B0 actual normalUnit32C target");
    if(m.r32(s.cx+0x154u)!=0xffffffffu||m.r32(s.cx+0x15cu)!=0u)
        throw std::domain_error("41B390 finite borrowed timer prestate");
    caller.push(m,continuation);
    Frame c{caller.sp,caller.sp,continuation};
    // 0x41b390: MOV EDX, DWORD PTR [ECX + 0X154] [8b9154010000]
    s.dx=m.r32(s.cx+0x154u);
    // 0x41b396: MOV EAX, DWORD PTR [ECX + 0X15C] [8b815c010000]
    s.ax=m.r32(s.cx+0x15cu);
    // 0x41b39c: CMP EDX, -1 [83faff]
    (void)ix::sub(s.dx,0xffffffffu,32,s.arithmetic_flags);
    // 0x41b39f: JE 0X41B3BB [741a]
    if(!ix::condition("JZ",s.arithmetic_flags))throw std::domain_error("41B390 finite realtimer sentinel branch");
    // 0x41b3bb: XOR ECX, ECX [33c9]
    s.cx=ix::logical(s.cx^s.cx,32,s.arithmetic_flags);
    // 0x41b3bd: TEST EAX, EAX [85c0]
    (void)ix::logical(s.ax,32,s.arithmetic_flags);
    // 0x41b3bf: SETG CL [0f9fc1]
    s.cx=(s.cx&0xffffff00u)|(ix::condition("JG",s.arithmetic_flags)?1u:0u);
    // 0x41b3c2: MOV AL, CL [8ac1]
    s.ax=(s.ax&0xffffff00u)|(s.cx&0xffu);
    // 0x41b3c4: RET  [c3]
    recovery_b566::finish(m,s,c,0u);caller.sp=c.sp;
}
void byte_6cc360(Memory& m,State& s,Frame& caller,U continuation,U actual_target){
    if(actual_target!=0x6cc360u||m.r32(s.cx)!=0x798c88u||m.r32(0x798e44u)!=actual_target)
        throw std::domain_error("2C31B0 actual normalUnit1BC target");
    if(m.r8(s.cx+0x204u)!=1u)throw std::domain_error("6CC360 finite borrowedSelf204 prestate");
    caller.push(m,continuation);
    Frame c{caller.sp,caller.sp,continuation};
    // 0x6cc360: MOV AL, BYTE PTR [ECX + 0X204] [8a8104020000]
    s.ax=(s.ax&0xffffff00u)|m.r8(s.cx+0x204u);
    // 0x6cc366: RET  [c3]
    recovery_b566::finish(m,s,c,0u);caller.sp=c.sp;
}
} // namespace calls
} // namespace ra2::recovered::recovery_b1704
