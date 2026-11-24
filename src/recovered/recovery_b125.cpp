#include "recovery_b125.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b125 {
std::uint32_t fun_00752870(Memory&m,const Inputs&i,Heap&h){
 const auto object=i.cx;auto capacity=m.r32(object+8);const auto minimum=m.r32(object+0x30);
 if((capacity!=512&&capacity!=1024&&capacity!=2048)||minimum!=256||m.r8(object+0x14))throw std::domain_error("uncontracted bucket-table capacity");
 auto old=m.r32(object);for(unsigned k=0;k<capacity;++k){if(h.r32(old+4*k))throw std::domain_error("nonempty bucket outside contracted route");h.w32(old+4*k,0);}
 m.w32(object+4,0);
 while(capacity>minimum){const auto next=capacity/2;old=m.r32(object);m.w32(object+8,next);m.w32(object+0xc,m.r32(object+0xc)-1);
  const auto fresh=h.allocate(next*4);if(!fresh)throw std::runtime_error("ordinary allocation failed");m.w32(object,fresh);
  for(unsigned k=0;k<next;++k)h.w32(fresh+4*k,0);
  for(unsigned k=0;k<capacity;++k)if(h.r32(old+4*k))throw std::domain_error("nonempty rebucket outside contracted route");
  h.release(old);capacity=m.r32(object+8);
 }
 return m.r32(object+0x30);
}
}
