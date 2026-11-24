#include "recovered/recovery_b151.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b151 {
namespace {
unsigned lookup545500(Memory&m,unsigned packed){
 const auto x=global_b26::sx16(packed),y=global_b26::sx16(packed>>16);const auto index=(y<<9)+x;
 if(global_b26::s32(index)<0||index>=0x40000)throw std::domain_error("151 positive indexed lookup contract");
 const auto tile=m.r32(m.r32(0x81a958)+index*4);
 if(!tile)throw std::domain_error("151 fallback tile outside contract");return tile;
}
unsigned diamond547f40(Memory&m,unsigned coordinate){
 const auto x=global_b26::s32(global_b26::sx16(m.r16(coordinate)));auto eax=global_b26::sx16(m.r16(coordinate+2));
 const auto y=global_b26::s32(eax),d=global_b26::s32(m.r32(0x81a910));const auto sum=x+y;
 if(sum<=d||x-y>=d)return eax&0xffffff00u;
 eax-=unsigned(x);if(global_b26::s32(eax)>=d)return eax&0xffffff00u;
 eax=m.r32(0x81a914);if(sum>d+2*global_b26::s32(eax))return eax&0xffffff00u;
 return (eax&0xffffff00u)|1;
}
}
std::uint32_t fun_0067e170(Memory&m,const Inputs&i){
 const auto root=i.cx,coordinates=i.arg[0],width=m.r32(root+0x268),height=m.r32(root+0x26c);
 if(width<1||width>4||height<1||height>4||!(i.arg[1]&255))throw std::domain_error("151 positive footprint/nonzero lowmode");
 const auto x=m.r16(coordinates),y=m.r16(coordinates+2);
 if(x<60||x>67||y<60||y>67||m.r32(0x81a910)!=64||(m.r32(0x81a914)!=1&&m.r32(0x81a914)!=64))throw std::domain_error("151 bounded coordinate arithmetic");
 for(unsigned row=0;row<height;++row)for(unsigned col=0;col<width;++col){
  const auto packed=((x+col)&65535)|(((y+row)&65535)<<16);i.arg[0]=packed;
  const auto tile=lookup545500(m,packed);auto eax=diamond547f40(m,coordinates);
  if(!(eax&255))return eax;
  const auto flag=m.r8(tile+0x11c);eax=(eax&0xffffff00u)|flag;if(flag)return eax&0xffffff00u;
  eax=0xffffffff;if(m.r32(tile+0x48)!=eax||m.r32(tile+0x44)!=eax)return eax&0xffffff00u;
  // The nonzero low byte of original arg1 branches around713b0.
  eax=(eax&0xffffff00u)|(i.arg[1]&255);
  auto index=m.r32(tile+0x38);if(global_b26::s32(index)<0||global_b26::s32(index)>=global_b26::s32(m.r32(0xa28920)))index=0;
  const auto object=m.r32(m.r32(0xa28914)+4*index);const auto enabled=m.r8(object+0x2b0);
  eax=(eax&0xffffff00u)|enabled;if(!enabled)return eax;
 }
 return (height&0xffffff00u)|1;
}
}
