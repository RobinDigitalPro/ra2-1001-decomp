#include "recovered/recovery_b1445.hpp"
#include "platform/custom_combo1430.hpp"
namespace ra2::recovered::b1445 {
unsigned fun_004d1b00(Memory&m,const Inputs&i,Heap&heap){
 b1430::ui::need(i.dx==0&&m.r32(0xa256f8)==0&&m.r32(0xa256f4)<8,"1445 original owner0 normal selected-global contract");
 Inputs child=i;child.arg[0]=m.r32(0xa256f4);child.dx=0x6a2;
 const auto result=b1417::fun_004d1bb0(m,child,heap);i.fp.image=child.fp.image;return result;
}
}
