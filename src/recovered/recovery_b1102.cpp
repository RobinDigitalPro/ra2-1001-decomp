#include "recovered/recovery_b1102.hpp"
#include <stdexcept>
namespace ra2::recovered::b1102 {
unsigned run(Memory&m,const Inputs&i,State&,const Api&a){
 if(m.r32(0xa27df4u)!=0u||!i.cx||!a.item||!a.enable)throw std::domain_error("1102 actual cold unconfigured connection and genuine parent/three children required");
 unsigned eax=0u;for(int id:{0x653,0x654,0x655}){auto child=a.item(reinterpret_cast<HWND>(std::uintptr_t(i.cx)),id);if(!child)throw std::domain_error("1102 selected controls must exist");eax=unsigned(a.enable(child,FALSE));}return eax;
}
}
