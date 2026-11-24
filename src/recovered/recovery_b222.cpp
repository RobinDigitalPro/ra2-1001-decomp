#include "recovered/recovery_b222.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b222 {
unsigned fun_005acb80(global_b26::Memory&m,const global_b26::Inputs&i,platform::ordinary_heap::Heap&h){
 const auto s=i.cx;
 if(m.r32(s)!=0x791ebc||m.r32(s+0x2c)!=0x791e9c||m.r32(s+0x44)!=0x791e7c||m.r32(0x791e88)!=0x5ae4b0||m.r32(0x791ea8)!=0x5ae450||m.r32(0x791ec8)!=0x5ae3f0||m.r32(s+0x54)!=1||!m.r8(s+0x51)||m.r32(s+0x3c)||m.r32(s+0x10)||m.r32(s+0x30)||m.r32(s+4)||m.r32(s+0x28))throw std::domain_error("222 bounded authentic member cleanup");
 const auto backing=m.r32(s+0x48),wrapper=h.r32(backing);if(!wrapper||h.r32(wrapper))throw std::domain_error("222 live null-slot wrapper required");
 // 1AD310 first loop, actual359320 null-slot store, then original free.
 h.w32(wrapper,0);h.release(wrapper);
 const auto clear=[&](unsigned o){m.w32(o+0x10,0);const auto p=m.r32(o+4);if(p&&m.r8(o+0xd)){h.release(p);m.w32(o+4,0);}m.w8(o+0xd,0);m.w32(o+8,0);};
 clear(s+0x44);m.w32(s+0x18,0);m.w32(s+0x1c,0);m.w32(s+0x20,0x280);m.w32(s+0x24,0x190);clear(s+0x2c);clear(s);
 // Root observes cleared owned pointers, resets wrappers and null string.
 m.w32(s+0x44,0x791f1c);m.w8(s+0x51,0);m.w32(s+0x4c,0);
 m.w32(s+0x2c,0x791efc);m.w8(s+0x39,0);m.w32(s+0x34,0);m.w32(s+0x28,0);
 const auto eax=m.r32(s+4);m.w32(s,0x791edc);m.w8(s+0xd,0);m.w32(s+8,0);return eax;
}}
