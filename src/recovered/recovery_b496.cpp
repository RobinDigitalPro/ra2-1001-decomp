#include "recovered/recovery_b496.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b496 {
std::uint32_t fun_00626b20(Memory&m,const Inputs&i){
 if(m.r8(0xa28953)||m.r32(i.cx)!=0x785954||m.r32(0x785984)!=0x4e0150||m.r32(0x785980)!=0x4e0130||
    m.r32(0x83ac40)!=0x796224||m.r32(0x79623c)!=0x537220)throw std::domain_error("496 authentic initialized registration closure");
 m.w32(0xa28b34,0);m.w32(0x83ac44,0);m.w32(0x83ac48,0);
 // Actual e0130 query returns false for the just-cleared empty head; e0150
 // installs this freshly initialized row through authentic manager slot30.
 m.w32(0xa28b34,0x83ac40);
 const auto clock=m.r32(0x81a70c);
 auto widget=[&](unsigned self,unsigned id,unsigned x,unsigned y,unsigned image){
  if(m.r8(self+0x5c))throw std::domain_error("496 excludes previously owned resource release");
  m.w32(self+0x24,id);m.w8(self+0x4c,1);m.w32(self+0x50,clock);
  m.w8(self+0x2d,0);m.w32(self+0x30,0);m.w32(self+0x20,5);
  m.w32(self+12,x);m.w32(self+16,y);m.w32(self+0x58,image);
  m.w32(self+20,unsigned(std::int32_t(std::int16_t(m.r16(image+2)))));
  m.w32(self+24,unsigned(std::int32_t(std::int16_t(m.r16(image+4)))));
  m.w8(self+28,1);
 };
 widget(0xa9df30,0xf2,m.r32(0xa9dfb0),m.r32(0xa9dfb4),m.r32(0xa9de98));
 widget(0xa9dec8,0xf3,m.r32(0xa9de80),m.r32(0xa9de84),m.r32(0xa9de60));
 return 0;
}
}
