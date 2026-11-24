#include "recovered/recovery_b166.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b166 {
std::uint32_t fun_00425230(Memory&m,const Inputs&,Heap&h){
 if(!m.r8(0xa28953)||m.r32(0x84e520)<1||m.r32(0x84e520)>8)throw std::domain_error("166 bounded positive registry cleanup required");
 unsigned k=0;
 do{
  const auto object=m.r32(m.r32(0x84e514)+k*4);
  if(!m.r8(object+0x31a)||!m.r8(object+0x1fc))throw std::domain_error("166 active record cleanup branch required");
  const auto payload=m.r32(object+0xa4);
  if(payload&&m.r8(object+0xa8)){(void)h.release(payload);m.w8(object+0xa8,0);}
  m.w32(object+0xa4,0);++k;
 }while(k<m.r32(0x84e520));
 return k;
}
}
