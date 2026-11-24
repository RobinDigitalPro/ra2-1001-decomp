#include "recovered/recovery_b1494.hpp"
#include "platform/peek1494.hpp"
namespace ra2::recovered::b1494 {
unsigned fun_00522410(Memory&m,const Inputs&i){
 using namespace ra2::platform::peek1494;
 need(m.r32(0xa39eec)==0,"1494 genuine PEcold normalmode0");
 need(i.dx==0&&i.arg[0]==0&&i.arg[1]==0&&i.arg[2]==0,"1494 unfiltered PM_NOREMOVE publicarguments");
 return unsigned(Observer::peek(reinterpret_cast<MSG*>(std::uintptr_t(i.cx)),nullptr,0,0,PM_NOREMOVE));
}
}
