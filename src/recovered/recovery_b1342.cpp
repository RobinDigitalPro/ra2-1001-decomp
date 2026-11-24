#include "recovery_b1342.hpp"
#include "recovered/recovery_b1296_downstream.hpp"
#include <stdexcept>
namespace ra2::recovered::b1342 {
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){
 if(root!=0x1655a0u)throw std::domain_error("1342 exact region root");
 const unsigned rect=i.arg[0],x=m.r32(rect),y=m.r32(rect+4u),width=m.r32(rect+8u),height=m.r32(rect+12u);
 const auto result=b1296::region_scan(m,i,h);
 // 5655EC/5655F5 overwrite the outer caller arg0 with the last appended point.
 // Child retains the disjoint original rectangle pointer; its local spills stay private.
 i.arg[0]=((y+height-1u)&65535u)<<16u|((x+width-1u)&65535u);return result;
}
}
