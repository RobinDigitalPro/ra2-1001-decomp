#include "recovered/recovery_b218.hpp"
#include "platform/audio_delete218.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b218 {
std::uint32_t fun_00402990(global_b26::Memory&m,const global_b26::Inputs&,platform::ordinary_heap::Heap&h){
 const unsigned manager=m.r32(0x7b78f8),owner=0x7b7db0;
 if(!m.r32(0x818e8c)||manager!=0x818de8||m.r32(manager+0xc)||m.r32(manager+0x18)||m.r32(0x8198ec)||m.r32(0x8198e8)||m.r32(owner+0x18)!=0x409f10)throw std::domain_error("218 bounded active owner cleanup");
 // Actual first empty-list traversal increments and decrements manager nesting.
 m.w32(manager+0x18,m.r32(manager+0x18)+1);m.w32(manager+0x18,m.r32(manager+0x18)-1);
 const auto node=m.r32(manager);if(!node||node==manager||m.r32(manager+4)!=node||m.r32(manager+8)!=manager||h.r32(node)!=manager||h.r32(node+4)!=manager||h.r32(node+8)!=manager||h.r32(node+0xc)!=owner)throw std::domain_error("218 one-node original list");
 // 72F0/7310 observe the original sentinel; 7380 unlinks in original order.
 const auto prev=h.r32(node+4),next=h.r32(node);m.w32(prev,next);m.w32(next+4,prev);h.w32(node,node);h.w32(node+4,node);
 platform::audio218::Lock::delete_guest(0x8198d0);
 m.w32(owner+0xc,m.r32(owner+0xc)&0xfffffffeu);
 const auto result=h.release(node);m.w32(0x818e88,0);m.w32(0x818e8c,0);return result;
}}
