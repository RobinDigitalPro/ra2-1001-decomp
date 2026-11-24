#include "recovery_b512.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b512 {
std::uint32_t fun_00707710(Memory&m,const Inputs&i){
 const auto p=i.cx;auto flags=m.r32(p+0x44);
 if(!(flags&8))throw std::domain_error("512 requires original external-data loaded state");
 if(flags&1)return m.r32(p+4);
 unsigned hi,lo;
 if(flags&2)hi=m.r16(p+8);
 else{hi=1;m.w16(p+8,1);flags|=2;m.w32(p+0x44,flags);}
 if(flags&4)lo=m.r16(p+10);
 else{lo=1;m.w16(p+10,1);flags|=4;m.w32(p+0x44,flags);}
 const unsigned result=(hi<<16)|lo;
 m.w32(p+4,result);m.w32(p+0x44,flags|1);return result;
}
}
