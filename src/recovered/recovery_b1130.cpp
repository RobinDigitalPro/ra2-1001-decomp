#include "recovered/recovery_b1130.hpp"
#include <stdexcept>
namespace ra2::recovered::b1130 {
unsigned run(Memory&m,Inputs&i,Heap&,unsigned root,unsigned base,Observation&z){
 if((root!=0xe7430u&&root!=0xe7620u)||i.cx!=base+0x1000u||m.r32(0xa1e0e4u)!=i.cx||i.arg[0]!=1u||m.r32(0xa255c8u)!=0u||m.r8(i.cx+0x134u)||m.r8(i.cx+0x135u)||m.r8(i.cx+0x13eu)||m.r8(i.cx+0x140u))throw std::domain_error("1130 exact original immediate positive active receiver transition");
 if(root==0xe7430u){if(m.r8(i.cx+0x13fu))throw std::domain_error("1130 first transition must change state");m.w8(i.cx+0x13fu,1u);}
 else {if(m.r8(i.cx+0x13fu)!=1u)throw std::domain_error("1130 second transition clears prior first state");m.w8(i.cx+0x13fu,0u);m.w8(i.cx+0x140u,1u);}
 (void)z;return 1u;
}
}
