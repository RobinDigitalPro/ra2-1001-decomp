#include "recovered/recovery_b867.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b867 {
std::uint32_t fun_00403f80(leaf::Memory&receiver,global_b26::Memory&g,const global_b26::Inputs&i,platform::ordinary_heap::Heap&h){
 if(g.r32(0x8192f8)!=0||g.r32(0x819300)!=0)throw std::domain_error("867 explicitinactive primary/subsystem fixture");
 const auto anchor=g.r32(0x8192b0);if(!anchor||g.r32(anchor+8)!=anchor)throw std::domain_error("867 initializedempty secondarylist");
 const auto owned=g.r32(0x8192f0);if(!owned||owned!=receiver.base())throw std::domain_error("867 positive owned receiver");
 auto child=i;child.cx=owned;auto result=recovery_b852::fun_00401b00(receiver,child,h);
 g.w32(0x8192f0,0);g.w32(0x8192fc,0);g.w32(0x8192f8,0);return result;
}}
