#include "recovery_b1002.hpp"
#include "platform/observed_locks1002.hpp"
namespace b1002_model {
std::uint32_t fun_0077824c(Memory&m,const Inputs&i){
 if((i.arg[0]!=15u&&i.arg[0]!=22u)||i.arg[1]>1u)throw std::domain_error("1002 signal/default-ignore contract");
 const auto address=i.arg[0]==15u?0xb10578u:0xb10574u;
 auto&lock=locks_b1002::ActualLock::current();lock.enter_model(m);
 const auto old=m.r32(address);m.w32(address,i.arg[1]);lock.leave_model(m);return old;
}}
