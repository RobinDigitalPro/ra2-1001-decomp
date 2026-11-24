#include "recovery_b1197.hpp"
#include <stdexcept>
namespace ra2::recovered::b1197{
static void need(bool x){if(!x)throw std::domain_error("1197 genuine positive Cell E4 Infantry unlink");}
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){
 need(root==0x73920u&&i.arg[0]!=0u&&(i.arg[1]&255u)==0u&&i.arg[1]==(i.cx&0xffffff00u));
 need(m.r32(i.cx)==0x788b04u&&m.r32(i.cx+0xe8u)==0u);
 const unsigned actor=i.arg[0];need(m.r32(actor)==0x78e540u&&m.r32(0x78e56cu)==0x508c50u&&m.r8(actor+0x79u)==0u);
 unsigned current=m.r32(i.cx+0xe4u);need(current!=0u);
 if(current==actor)m.w32(i.cx+0xe4u,m.r32(actor+0x30u));
 else{unsigned steps=0u;while(current&&m.r32(current+0x30u)!=actor){current=m.r32(current+0x30u);need(++steps<6u);}need(current!=0u);m.w32(current+0x30u,m.r32(actor+0x30u));}
 m.w32(actor+0x30u,0u);
 // True78E540+2C points508C50: MOV EAX,15;RET. It suppresses BC/EC arms.
 return 15u;
}
}
