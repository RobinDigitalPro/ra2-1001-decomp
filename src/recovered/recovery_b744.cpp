#include "recovery_b744.hpp"
#include "platform/observed_combo744.hpp"
namespace ra2::recovered::recovery_b744 {
using ra2::platform::combo744::Combo;
unsigned fun_00678060(Memory&m,const Inputs&i){if(i.cx!=5)throw std::domain_error("744 startindex5");auto h=reinterpret_cast<HWND>(std::uintptr_t(m.r32(0xaa4904)));for(unsigned id=0x51b;id<=0x51d;++id){unsigned s=Combo::send(h,id,0x147,0,0),v=Combo::send(h,id,0x150,s,0);if(v<=2)return (v&0xffffff00u)|1;}return 0;}
unsigned fun_005c4c60(Memory&m,const Inputs&i){if(i.dx!=5)throw std::domain_error("744 startindex5");auto h=reinterpret_cast<HWND>(std::uintptr_t(i.cx));unsigned v=0;for(unsigned id=0x416;id<=0x418;++id){unsigned s=Combo::send(h,id,0x147,0,0);v=Combo::send(h,id,0x150,s,0);if(v&&v!=m.r32(0xa5a89c)&&v!=m.r32(0xa5a8a0)&&v!=m.r32(0xa5a8b0))return (v&0xffffff00u)|1;}return v&0xffffff00u;}
}
