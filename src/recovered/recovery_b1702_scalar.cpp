#include "recovered/recovery_b1702.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1702::calls {
namespace ix=direct_b33::integer;
void fbd80(Memory&m,State&s,Frame&caller,U continuation,U actual_target){
    // Readonly finite call identity guard before the original CALL effect.
    if(actual_target!=0x4fbd80u||continuation!=0x4fd4e0u)
        throw std::domain_error("FD5F0 fbd80 target/continuation outside selected call");
    caller.push(m,continuation); //4FD4DD actual CALL
    Frame f{caller.sp,caller.sp,continuation};
    try{
L4fbd80: //MOV EAX,[ESP+4] [8b442404]
        s.ax=m.r32(f.sp+4u);
L4fbd84: //PUSH ESI [56]
        f.push(m,s.si);
L4fbd85: //MOV ESI,[A28CC0] [8b35c08ca200]
        s.si=m.r32(0xa28cc0u);
L4fbd8b: //PUSH EDI [57]
        f.push(m,s.di);
L4fbd8c: //CMP [EAX+14],ESI [397014]
        (void)ix::sub(m.r32(s.ax+0x14u),s.si,32,s.arithmetic_flags);
L4fbd8f: //JNE4FBDC1 [7530]; primary-X differs on exact sample0.
        if(!ix::condition("JNZ",s.arithmetic_flags))
            throw std::domain_error("FD5F0 fbd80 unselected equal primary-X at4FBD8F");
L4fbdc1: //POP EDI [5f]
        s.di=f.pop(m);
L4fbdc2: //MOV EAX,1 [b801000000]
        s.ax=1u;
L4fbdc7: //POP ESI [5e]
        s.si=f.pop(m);
L4fbdc8: //RET4 [c20400]
        recovery_b566::finish(m,s,f,4u);
        caller.sp=f.sp;
    }catch(...){caller.sp=f.sp;throw;} //Keep reached actual SP on failure.
}
void type_6fee90(Memory&m,State&s,Frame&caller,U continuation,U actual_target){
    if(actual_target!=0x6fee90u||continuation!=0x4fd507u)
        throw std::domain_error("FD5F0 type1 target/continuation outside selected call");
    caller.push(m,continuation); //4FD504 actual CALL
    Frame f{caller.sp,caller.sp,continuation};
    try{
L6fee90: //MOV EAX,1 [b801000000]
        s.ax=1u;
L6fee95: //RET [c3]
        recovery_b566::finish(m,s,f,0u);
        caller.sp=f.sp;
    }catch(...){caller.sp=f.sp;throw;}
}
void xyz_5cd4d0(Memory&m,State&s,Frame&caller,U continuation,U actual_target){
    if(actual_target!=0x5cd4d0u||continuation!=0x4fd538u)
        throw std::domain_error("FD5F0 XYZ target/continuation outside selected call");
    caller.push(m,continuation); //4FD535 actual CALL
    Frame f{caller.sp,caller.sp,continuation};
    try{
L5cd4d0: //MOV EAX,[ESP+4] [8b442404]
        s.ax=m.r32(f.sp+4u);
L5cd4d4: //ADD ECX,88 [81c188000000]
        s.cx=ix::add(s.cx,0x88u,32,s.arithmetic_flags);
L5cd4da: //PUSH ESI [56]
        f.push(m,s.si);
L5cd4db: //MOV EDX,EAX [8bd0]
        s.dx=s.ax;
L5cd4dd: //MOV ESI,[ECX] [8b31]
        s.si=m.r32(s.cx);
L5cd4df: //MOV [EDX],ESI [8932]
        m.w32(s.dx,s.si);
L5cd4e1: //MOV ESI,[ECX+4] [8b7104]
        s.si=m.r32(s.cx+4u);
L5cd4e4: //MOV [EDX+4],ESI [897204]
        m.w32(s.dx+4u,s.si);
L5cd4e7: //POP ESI [5e]
        s.si=f.pop(m);
L5cd4e8: //MOV ECX,[ECX+8] [8b4908]
        s.cx=m.r32(s.cx+8u);
L5cd4eb: //MOV [EDX+8],ECX [894a08]
        m.w32(s.dx+8u,s.cx);
L5cd4ee: //RET4 [c20400]
        recovery_b566::finish(m,s,f,4u);
        caller.sp=f.sp;
    }catch(...){caller.sp=f.sp;throw;}
}
}
