#include "recovered/recovery_b484.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b484 {
std::uint32_t fun_00752760(Memory&m,const Inputs&i,Heap&h){
 const auto t=i.cx;
 const auto old=m.r32(t);
 const auto old_count=m.r32(t+8u);
 if(!old||old_count!=512u||m.r32(t+0x0cu)!=9u||m.r32(t+0x30u)!=256u||m.r8(t+0x14u)!=0u||m.r32(t+0x18u)!=0x6814e0u)
  throw std::domain_error("B484 bounded to a populated 512-bucket table with status zero and high-water 256");
 std::uint32_t result=0;
 for(std::uint32_t b=0;b<old_count;++b){
  auto node=h.r32(old+4u*b);
  while(node){
   const auto next=h.r32(node+8u);
   const auto key=h.r32(node);
   if(!key)throw std::domain_error("B484 positive route requires each node to own a non-null key block");
   result=h.release(key);h.w32(node,0);
   result=h.release(node);
   node=next;
  }
  h.w32(old+4u*b,0);
 }
 m.w32(t+4u,0);
 auto count=old_count;
 auto shift=m.r32(t+0x0cu);
 while(count>m.r32(t+0x30u)){
  count>>=1u;
  --shift;
  m.w32(t+8u,count);m.w32(t+0x0cu,shift);
  const auto fresh=h.allocate(count*4u);
  if(!fresh)throw std::domain_error("B484 excludes allocation failure");
  m.w32(t,fresh);
  for(std::uint32_t b=0;b<count;++b)h.w32(fresh+4u*b,0);
  // Every old chain was freed and every old bucket cleared above, so the
  // original indirect hash callback is unreachable on this positive route.
  result=h.release(old);
 }
 (void)result;
 return m.r32(t+0x30u);
}
}
