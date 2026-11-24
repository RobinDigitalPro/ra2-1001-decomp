#include "recovered/recovery_b1587.hpp"
#include "platform/observed_combo1587.hpp"
#include <stdexcept>
namespace ra2::recovered::b1587 {
U fun_005b4070(Memory&m,const Inputs&i,Heap&heap){auto need=[](bool v){if(!v)throw std::domain_error("1587 finite owned ComboBox cleanup and fresh append");};const U self=i.cx,vector=self+8;need(i.arg[1]==0xffffffffu&&m.r32(self)==0x791a7cu&&m.r32(0x791b1cu)==0x5b41c0u&&m.r32(vector)==0x79223cu&&m.r32(0x792248u)==0x5b5830u);need(m.r32(vector+4)==0&&m.r32(vector+8)==0&&m.r8(vector+12)==1&&m.r8(vector+13)==0&&m.r32(vector+16)==0&&m.r32(vector+20)==10);need(m.r32(0x7854a0u)==ra2::platform::combo1587::ptr(reinterpret_cast<void*>(&ra2::platform::combo1587::send)));ra2::platform::combo1587::clear(reinterpret_cast<HWND>(std::uintptr_t(i.arg[0])),i.fp.image);m.w32(vector+16,0);m.w8(vector+13,0);m.w32(vector+8,0);Inputs child=i;child.arg[0]=vector;(void)b1424::fun_005b41c0(m,child,heap);i.fp=child.fp;return i.arg[1];}
}
