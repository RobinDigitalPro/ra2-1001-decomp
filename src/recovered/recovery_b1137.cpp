#include "recovered/recovery_b1137.hpp"
#include <stdexcept>
namespace ra2::recovered::b1137 {
unsigned run(Memory&m,Inputs&i,Heap&,unsigned root,unsigned base,Observation&z){
 if(root==0x992b0u){
  if(i.cx!=0x81a820u||m.r32(i.cx)!=0x785954u||m.r32(i.cx+0x1178u)!=0u||i.arg[0]!=base+0x5000u||i.arg[1]!=base+0x5010u)throw std::domain_error("1137 original global Map explicit disjoint caller coordinate exchange");
  const unsigned next=m.r32(i.arg[1]);if((next&65535u)==(m.r32(0x83a940u)&65535u))throw std::domain_error("1137 explicit positive low coordinate differs original sentinel");
  const unsigned old=m.r32(i.cx+0x1170u);if(old==next)throw std::domain_error("1137 useful coordinate change required");
  i.arg[1]=next;m.w32(i.cx+0x1170u,next);m.w32(i.arg[0],old);z.coordinate_exchanges=1u;return i.arg[0];
 }
 if(root==0x106380u){
  if(i.cx!=base+0x1000u||m.r32(i.cx+0x5a8u)!=base+0x4000u||m.r32(i.cx+0x5acu)!=5u||m.r8(i.cx+0x5c3u)!=1u)throw std::domain_error("1137 true original receiver descriptor/state5 producer projection");
  const unsigned d=m.r32(i.cx+0x5a8u),old=m.r32(i.cx+0x5bcu);if(old<51u||old>300u||m.r8(d+0xc0au)!=0u||m.r8(d+0xc0du)!=0u)throw std::domain_error("1137 bounded positive countdown51to300 descriptor defaults exclude callbacks");
  const unsigned next=old-1u;m.w32(i.cx+0x5bcu,next);z.countdown_decrements=1u;return next&0xffffff00u;
 }
 throw std::domain_error("1137 exactly two useful positive numeric routes");
}
}
