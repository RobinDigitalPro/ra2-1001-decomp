#include "recovered/recovery_b1436.hpp"
#include "platform/modal1436.hpp"
#include <stdexcept>
namespace ra2::recovered::b1436 {
std::uint32_t fun_004b7860(Memory&m,const Inputs&i){
 if(i.arg[1]!=0x111u||(i.arg[2]&0xffffu)!=0x481u||i.arg[0]==0u)
  throw std::domain_error("1436 finite WM_COMMAND control481 contract");
 // 4B78EF..4B790E: mask the original notification word, dispatch control481,
 // and pass the actual dialog HWND plus literal481 to the original import.
 (void)ra2::platform::modal1436::end_dialog(m.r32(0x7853bcu),i.arg[0],i.fp);
 // 4B7914 explicitly clears all EAX bits; the API BOOL is not the root result.
 return 0u;
}
}
