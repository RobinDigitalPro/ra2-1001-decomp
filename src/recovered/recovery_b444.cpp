#include "recovery_b444.hpp"
#include <stdexcept>
namespace ra2::recovered::labels444 {
std::uint32_t fun_00754740(Memory&m,const Inputs&i){
 if((m.r8(0xb10168)&15)!=15)throw std::domain_error("444 labels require initialized string cache");
 switch(i.cx){case 1:return 0xb101d0;case 2:return 0xb101b8;case 3:return 0xb101e0;default:return 0xb101a0;}
}
std::uint32_t fun_00754870(Memory&m,const Inputs&i){
 if((m.r8(0xb10190)&15)!=15)throw std::domain_error("444 labels require initialized string cache");
 switch(i.cx){case 1:return 0xb10178;case 2:return 0xb1017c;case 3:return 0xb101cc;default:return 0xb1016c;}
}
}
