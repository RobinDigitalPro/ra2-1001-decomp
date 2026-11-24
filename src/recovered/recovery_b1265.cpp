#include "recovery_b1265.hpp"
#include <stdexcept>
namespace ra2::recovered::global_b26 {std::uint32_t fun_00545490(Memory&,const Inputs&);}
namespace ra2::recovered::b1265 {
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){
 const auto need=[](bool x){if(!x)throw std::domain_error("1265 positive placed active Veins animation on fresh Cell20,20");};
 need(root==0x22f50u&&m.r32(i.cx)==0x787084u&&m.r8(i.cx+0x7du)==1u&&m.r8(i.cx+0x17bu)==0u);const auto type=m.r32(i.cx+0xb0u);need(type&&m.r32(type)==0x787318u&&m.r8(type+0x311u)==1u);
 const auto x=m.r32(i.cx+0x88u),y=m.r32(i.cx+0x8cu);need(x>=5120u&&x<5376u&&y>=5120u&&y<5376u);
 // Original copies all12 public coordinate bytes to a produced private local.
 // The accepted valid-cell helper only reads X/Y and does not mutate its input;
 // that exact caller-compatible route can read the same public coordinates.
 Inputs lookup{};lookup.cx=0x81a820u;lookup.arg[0]=i.cx+0x88u;const auto cell=global_b26::fun_00545490(m,lookup);++o.map_calls;
 need(cell!=0xa57610u&&m.r32(cell)==0x788b04u&&m.r32(cell+0xe4u)==0u);
 m.w8(i.cx+0x17bu,1u);++o.expiration_marks;
 // ESI=CellE4=0 skips the remaining root body, preserving full helper EAX.
 return cell;
}
}
