#include "recovered/recovery_b1111.hpp"
#include <stdexcept>
namespace ra2::recovered::b1111 {
static void need(bool b){if(!b)throw std::domain_error("1111 bounded populated original list operations");}
static void redraw(Memory&m,unsigned p){need(m.r32(p)==0x790624u&&m.r32(0x79066cu)==0x538b70u&&m.r8(p+0x54u)==0u);m.w8(p+0x1cu,1u);}
unsigned run(Memory&m,const Inputs&i,unsigned root){
 const auto p=i.cx,n=m.r32(p+0x44u),items=m.r32(p+0x38u),visible=m.r32(p+0x50u);
 need(m.r32(p)==0x790624u&&m.r32(p+0x34u)==0x7906f4u&&n>=2u&&n<=8u&&visible>=n+1u&&m.r8(p+0x54u)==0u&&m.r32(p+0x170u)==0u);
 if(root==0x138240u){
  need(i.arg[0]&&n<m.r32(p+0x3cu));m.w32(p+0x44u,n+1u);m.w32(items+4u*n,i.arg[0]);redraw(m,p);return n;
 }
 need(root==0x1383d0u&&i.arg[0]==0x100u&&m.r32(p+0x28u)==0u&&m.r32(0x84e320u)==0u);
 const auto key=m.r32(i.arg[1]),old=m.r32(p+0x16cu);need((key==0x26u||key==0x28u)&&old>=1u&&old+1u<n);
 need(m.r32(0x7906c8u)==0x538b50u&&m.r32(0x7906dcu)==0x538ae0u&&m.r32(0x79069cu)==0x4cf190u);
 m.w32(p+0x16cu,key==0x26u?old-1u:old+1u);redraw(m,p);m.w32(i.arg[1],0u);
 // Original483290 maps nonzero gadget ID to an event and calls4CEE00.
 const auto id=m.r32(p+0x24u);need(id&&id<0x8000u);m.w32(i.arg[1],id|0x8000u);m.w8(p+0x1cu,1u);
 // Actual4CF190 consumes low flag byte0; original active global remainszero.
 return 1u;
}
}
