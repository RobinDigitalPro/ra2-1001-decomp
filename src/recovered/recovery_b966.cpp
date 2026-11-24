#include "recovered/recovery_b966.hpp"
#include "platform/observed_thread966.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b966 {
std::uint32_t fun_00636e90(Memory&m,const Inputs&i){
 const auto handle=m.r32(i.cx+0x1cu);if(!handle)throw std::domain_error("B966 completed nonnull thread required");
 // Original logging helper4068F0 is exactly RET; it does not inspect its strings.
 const auto result=ra2::platform::thread966::wait_one(handle,i.arg[0]);
 if(result!=WAIT_OBJECT_0)throw std::domain_error("B966 successful completed-thread route only");
 m.w32(i.cx+0x1cu,0u);return (result&0xffffff00u)|1u;
}
}
