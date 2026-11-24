#include "recovery_b558.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b558{
std::uint32_t fun_0070a370(Memory&m,const Inputs&,Heap&h){
 if(!m.r32(0xab83cc)||m.r32(0xab83c8))throw std::domain_error("558 bounded active owner/no standalone");
 unsigned count=0;
 for(unsigned head:{0xab8310,0xab82e8,0xab8360,0xab836c,0xab8378,0xab8384}){
  // Actual4072F0 returns zero when [head] equals [[head]+8].
  auto p=h.r32(head);if(p==h.r32(p+8))continue;
  if(head!=0xab82e8||count++||h.r32(p)!=head||h.r32(p+4)!=head)throw std::domain_error("558 exactly one owned node");
  //407380 ordered next/previous updates and retained self links.
  auto prev=h.r32(p+4),next=h.r32(p);h.w32(prev,next);
  next=h.r32(p);prev=h.r32(p+4);h.w32(next+4,prev);h.w32(p,p);h.w32(p+4,p);
  m.w32(h.r32(p+12)+0x48,2);h.release(p);
  p=h.r32(head);if(p!=h.r32(p+8))throw std::domain_error("558 must have drained list");
 }
 if(count!=1)throw std::domain_error("558 positive drain required");
 return 0;
}}
