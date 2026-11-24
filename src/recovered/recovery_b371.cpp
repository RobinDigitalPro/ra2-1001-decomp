#include "recovery_b371.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b371 {
std::uint32_t fun_0060ee30(Memory& m,const Inputs& i){
 if(i.cx>2u||m.r32(0xa288b0u)!=0u||m.r8(0xa5e220u)==0u)
  throw std::domain_error("371 requires empty queue and already-shown notice in mode0..2");
 // 6A0380 sees zero queue count; tail6EB5E0 clears the current notice state.
 m.w32(0xaa8db4u,0u);m.w8(0xaa8db8u,0u);
 // Mode0 only changes AL after EAX=0. Modes1/2 explicitly loaded EAX=1.
 return i.cx==0u?m.r8(0xa5e220u):1u;
}
}
