#include "recovered/recovery_b1532.hpp"
#include <stdexcept>
namespace ra2::recovered::b1532 {
std::uint32_t fun_0047ba60(Memory&m,const Inputs&i,Heap&h){
 const auto owner=i.cx,p=m.r32(owner+0x28u);
 if(!p||h.r32(p)!=0x7875a0u||h.r32(p+4u)!=0u||h.r32(p+8u)!=0u||h.r8(p+0xcu)!=1u||h.r8(p+0xdu)!=0u||h.r32(p+0x10u)!=0u||h.r32(p+0x14u)!=10u)throw std::domain_error("1532 requires genuineownedemptyvector");
 // Actual7875A0+C42CC10: buffer0 excludesbufferrelease, count/cap/D clear.
 h.w32(p+0x10u,0u);h.w8(p+0xdu,0u);h.w32(p+8u,0u);
 // Actualscalar-deleting42D3E0(flag1): basevptr thenrealordinaryfree.
 h.w32(p,0x7875e0u);h.w8(p+0xdu,0u);h.w32(p+8u,0u);h.release(p);
 // DestructorreturnsESIafterfree, rootthenpublishesowner28=0. No dereferenceafterfree.
 m.w32(owner+0x28u,0u);return p;
}
}
