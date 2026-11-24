#include "recovery_b1004.hpp"
#include "platform/completion1004.hpp"
namespace b1004_model {
std::uint32_t fun_00729780(Memory&m,const Inputs&i){auto&s=io1004::Scope::current();(void)(s.tick()>>4u);if(!m.r8(i.cx+0x51u))throw std::domain_error("1004 positive completion flag required");(void)(s.tick()>>4u);if(!s.complete(m))throw std::domain_error("1004 completed write required");m.w8(i.cx+0x51u,0u);return s.reset_model(m);}
}
