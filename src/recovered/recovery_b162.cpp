#include "recovered/recovery_b162.hpp"
#include "platform/observed_combo162.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b162 {
unsigned fun_005c3360(Memory&m,const Inputs&i){
 using ra2::platform::combo162::Combo;const auto hwnd=reinterpret_cast<HWND>(std::uintptr_t(i.cx));
 const auto selected=Combo::send(hwnd,int(i.dx),0x147,0,0);
 const auto data=Combo::send(hwnd,int(i.dx),0x150,unsigned(selected),0);
 unsigned index;if(i.dx==0x6a2)index=0;else if(i.dx>=0x522&&i.dx<=0x528)index=i.dx-0x521;else throw std::domain_error("162boundedcontrolIDs");
 if(m.r32(0xa27dc0)==index)throw std::domain_error("162localindexbranchoutsidecontract");
 m.w32(0xa2564c+4*index,unsigned(data));return index;
}
}
