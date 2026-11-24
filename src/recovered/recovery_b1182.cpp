#include "recovered/recovery_b1182.hpp"
#include <stdexcept>
namespace ra2::recovered::b1182 {
namespace {void need(bool b){if(!b)throw std::domain_error("1182 genuine populated DialogList ownership cleanup");}}
unsigned run(Memory&m,Inputs&,Heap&h,unsigned root,unsigned,Observation&z){constexpr unsigned owner=0xab83b0u;need(root==0x30b150u&&m.r32(owner)==0x799874u&&m.r32(0x799884u)==0x70b870u&&m.r32(owner+8u)==10u&&m.r8(owner+12u)==1u&&m.r8(owner+13u)==1u&&m.r32(0xab83ccu)==0u&&m.r32(0xab83d4u)==0u&&m.r32(0xab83dcu)==0u);const unsigned backing=m.r32(owner+4u);need(backing&&m.r32(owner+16u)>=2u&&m.r32(owner+16u)<=6u);
 // Actual70A370 reads the genuine cold AB83CC0 and returns without queue work.
 while(m.r32(owner+16u)>0u){const unsigned victim=h.r32(backing);need(victim!=0u);const unsigned n=m.r32(owner+16u);unsigned index=0u;while(index<n&&h.r32(backing+4u*index)!=victim)++index;need(index<n);++z.pointer_searches;++z.virtual_callbacks;const unsigned left=n-1u;m.w32(owner+16u,left);if(index<left){++z.vector_compactions;for(unsigned src=index+1u;src<=left;++src)h.w32(backing+4u*(src-1u),h.r32(backing+4u*src));}++z.removals;need(h.release(victim)!=0u);++z.frees;++z.record_releases;}
 return 0u;
}
unsigned cleanup(Memory&m,Heap&h){constexpr unsigned owner=0xab83b0u;need(m.r32(owner)==0x799874u&&m.r32(owner+16u)==0u&&m.r32(owner+8u)==10u&&m.r8(owner+13u)==1u);const unsigned backing=m.r32(owner+4u);need(backing!=0u);m.w32(owner+16u,0u);const unsigned result=h.release(backing);need(result!=0u);m.w32(owner+4u,0u);m.w8(owner+13u,0u);m.w32(owner+8u,0u);return result;}
}
