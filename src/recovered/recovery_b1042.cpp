#include "recovered/recovery_b1042.hpp"
#include "recovered/recovery_b1035.hpp"
#include <stdexcept>
namespace ra2::recovered::b1042 {
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root){
 if(root!=0x37191au||i.arg[0]!=2u||m.r8(i.arg[1])!=67u||m.r8(i.arg[1]+1u)!=0u||m.r32(0x817470u)!=0x77aae0u)throw std::domain_error("1042 original category2 C-name callback path");
 // Original771AEE C-name fast route produces C, six zero bytes and zero CP.
 const unsigned name=h.allocate(2u);i.arg[1]=name;
 const unsigned previous=m.r32(0x81746cu);i.arg[0]=previous;
 if(previous==0x817340u)throw std::domain_error("1042 prepared positive previous owned name");
 h.w8(name,67u);h.w8(name+1u,0u);m.w32(0x81746cu,name);
 m.w32(0xb10530u,0u);for(unsigned k=0;k<6u;++k)m.w8(0xb106d8u+k,0u);m.w32(0xb10540u,0u);
 if(b1035::run(m,i,h,0x37aae0u)!=0u)throw std::domain_error("1042 actual category callback success");
 if(!h.release(previous))throw std::domain_error("1042 actual previous owned name release");
 return m.r32(0x81746cu);
}
}
