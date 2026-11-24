#include "recovered/recovery_b1169.hpp"
#include <stdexcept>
namespace ra2::recovered::b1169 {
unsigned run(Memory&m,Inputs&i,Heap&,unsigned root,unsigned base,Observation&z){const auto need=[](bool b,const char*s){if(!b)throw std::domain_error(s);};const unsigned self=i.cx,owner=m.r32(self+12u);need(root==0xbee60u&&self>=base+0x1000u&&self<base+0x3000u&&m.r32(self)==0x78c0ccu&&m.r32(self+4u)==0x78c004u&&owner==base+0x6000u,"1169 true4BBD80 locomotion and actual53B1F0 linked owner");need(m.r32(owner)==0x78e540u&&m.r32(0x78e6acu)==0x591570u&&m.r32(0x78e56cu)==0x508c50u,"1169 genuine Infantry mission and kind callback identities");need(m.r32(owner+0x98u)==7u&&m.r32(owner+0xa0u)==0xffffffffu,"1169 actual591510 mission7 publication");need(m.r8(self+0x51u)==0u,"1169 useful initial constructor state");
 // Actual mission7 callback bypasses6C69E0. True kind15 bypasses every
 // kind2 service and leaves fullEAX15 through the four stores and epilogue.
 z.mission_queries=1u;z.kind_queries=1u;z.virtual_callbacks=2u;m.w8(self+0x50u,0u);m.w8(self+0x51u,1u);m.w8(self+0x52u,0u);m.w32(self+0x38u,0u);z.positive_transitions=1u;return 15u;
}}
