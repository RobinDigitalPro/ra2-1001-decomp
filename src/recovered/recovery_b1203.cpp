#include "recovery_b1203.hpp"
#include <stdexcept>
namespace ra2::recovered::b1203{
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){
 if(root!=0x2af0f0u||i.arg[1]<1u||i.arg[1]>3u||!i.arg[0]||!i.arg[2]||m.r32(i.cx)!=0x7977f8u)throw std::domain_error("1203 selected genuine positive Team reaction");
 const unsigned type=m.r32(i.cx+0x24u);
 if(!type||m.r32(type)!=0x797898u||m.r8(type+0xafu)!=0u||m.r8(i.cx+0x7fu)!=0u)throw std::domain_error("1203 actual Team and Type constructor fields");
 m.w32(i.cx+0x34u,0u);m.w8(i.cx+0x75u,1u);m.w8(i.cx+0x7bu,1u);
 // EAX holds Type pointer; MOV AL,[Team7F] then MOV AL,1 preserve upper24.
 return(type&0xffffff00u)|1u;
}
}
