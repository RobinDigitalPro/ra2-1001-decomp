#include "recovery_b1268.hpp"
#include <stdexcept>
namespace ra2::recovered::b1268 {
// Original557340/51B and557280/178B, adapted only to joined numeric spans.
// Accepted leaf implementations use one span; original Map and table are far
// apart. No synthetic scratch receiver, extra recovered root, or helper edit.
static void reset(Memory&m){constexpr unsigned a=0x81a820u;const unsigned width=m.r32(a+0xf0u);m.w32(a+0x108u,1u);m.w32(a+0x10cu,width);m.w32(a+0x110u,width-1u);m.w32(a+0x114u,m.r32(a+0x138u)+(width<<11u)+4u);}
static unsigned next(Memory&m){constexpr unsigned a=0x81a820u;const unsigned old=m.r32(a+0x114u),left=m.r32(a+0x110u);if(left){m.w32(a+0x108u,m.r32(a+0x108u)+1u);m.w32(a+0x10cu,m.r32(a+0x10cu)-1u);m.w32(a+0x110u,left-1u);m.w32(a+0x114u,old-0x7fcu);}else{const unsigned x=m.r32(a+0x108u),y=m.r32(a+0x10cu),width=m.r32(a+0xf0u);m.w32(a+0x108u,y);m.w32(a+0x10cu,x);if((y-width+x-1u)&1u){m.w32(a+0x10cu,x+1u);m.w32(a+0x110u,width-1u);}else{m.w32(a+0x108u,y+1u);m.w32(a+0x110u,width-2u);}m.w32(a+0x114u,m.r32(a+0x138u)+4u*(m.r32(a+0x108u)+(m.r32(a+0x10cu)<<9u)));}return m.r32(old);}
unsigned run(unsigned root,Memory&m,const Inputs&,Observation&o){if(root!=0x1d4800u)throw std::out_of_range("1268 root");reset(m);unsigned cell=next(m);++o.map_calls;while(cell){++o.visited_cells;if(m.r32(cell+0x44u)==126u){if(m.r8(cell+0x11eu)>=48u)throw std::domain_error("1268 mature overlay rebuild outside bounded contract");m.w32(cell+0x44u,0xffffffffu);m.w8(cell+0x11eu,0u);++o.overlay_clears;}cell=next(m);++o.map_calls;}return 0u;}
}
