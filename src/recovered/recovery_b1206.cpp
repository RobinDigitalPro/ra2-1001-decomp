#include "recovery_b1206.hpp"
#include <stdexcept>
namespace ra2::recovered::b1206 {
unsigned run(unsigned root,Memory&m,const Inputs&i,State&){
 if(root!=0x2af590u||m.r32(i.cx)!=0x7977f8u||m.r8(i.cx+0x75u)!=1u||m.r32(0xa283c4u)!=0u)throw std::domain_error("1206 finite loaded Team completion");
 unsigned member=m.r32(i.cx+0x54u),count=0u;if(!member)throw std::domain_error("1206 nonempty Team required");
 while(member){if(++count>6u||m.r32(member)!=0x78e540u||m.r8(member+0x7du)!=1u||m.r32(member+0x6cu)==0u||m.r8(member+0x76u)!=1u||m.r32(member+0x4c4u)!=i.cx)throw std::domain_error("1206 original linked Infantry read-set");member=m.r32(member+0x4c8u);}
 m.w8(i.cx+0x75u,0u);return 1u;
}
}
