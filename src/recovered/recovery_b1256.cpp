#include "recovery_b1256.hpp"
#include "recovered/leaf_b21_b.hpp"
#include <stdexcept>
namespace ra2::recovered::b1256 {
unsigned run(unsigned root,Memory&m,leaf::Memory&cache_arena,const Inputs&i,Observation&o){
 const unsigned receiver=i.cx,descriptor=m.r32(receiver+0x24u);
 if(root!=0x4890u||m.r32(receiver+0xa8u)!=0u||m.r32(descriptor+0x58u)>=33u||m.r32(descriptor+0x138u)!=0u||(m.r32(descriptor+0x10u)&6u)!=0u||m.r32(descriptor+0x13cu)!=0u)throw std::domain_error("1256 useful cold one-key cached consumer route");
 Inputs lookup{};lookup.cx=m.r32(0x8192f0u);lookup.dx=m.r32(descriptor+0xb4u);
 if(m.r32(lookup.cx+12u)!=cache_arena.r32(lookup.cx+12u))throw std::domain_error("1256 joined/leaf views must share actual cache storage");
 const unsigned node=b1253::run(0x1c00u,cache_arena,lookup,o.hit);++o.cache_calls;
 m.w32(receiver+0x28u,node);
 leaf::Inputs retain{};retain.cx=node;const unsigned result=leaf::fun_00401f80(cache_arena,retain);++o.retain_calls;
 m.w32(receiver+0xa8u,1u);
 // 404A40 loads the zero outro field into ECX. EAX retains 401F80's result.
 return result;
}
}
