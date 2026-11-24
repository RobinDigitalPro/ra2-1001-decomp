#include "recovered/recovery_b1214.hpp"
#include <stdexcept>
namespace ra2::recovered::b1214 {namespace{
void need(bool b){if(!b)throw std::domain_error("1214 genuine mixed human/nonhuman catalog selection factory");}
bool predicate(Memory&m,unsigned actor,Observation&z){++z.predicate_calls;need(m.r32(actor)==0x78e540u&&m.r8(actor+0x7du)==1u&&m.r32(0xa255c8u)==0u);const unsigned house=m.r32(actor+0x1b4u);if(!m.r8(house+0x135u))return false;need(m.r32(0x78e540u+0x2cu)==0x508c50u);++z.virtual_callbacks;return true; // Exact508C50 returns15, satisfying6ECC20's kind!=6 test.
}
}
unsigned run(Memory&m,Inputs&i,Heap&h,unsigned root,unsigned base,Observation&z){need(root==0x2eb850u&&i.cx==0x6ecc20u&&i.dx==0u&&m.r32(0x821cacu)==base+0x1000u&&m.r32(0xa1e0e4u)==base+0x8000u);const unsigned out=h.allocate(24u);need(out);++z.allocations;h.w32(out,0x78579cu);h.w32(out+4u,0u);h.w32(out+8u,0u);h.w8(out+12u,1u);h.w8(out+13u,0u);h.w32(out+16u,0u);h.w32(out+20u,10u);const unsigned count=m.r32(m.r32(0x821cacu)+0xdb0u);need(count>=2u&&count<=6u);unsigned selected=0u;for(unsigned j=0;j<count;++j){const unsigned actor=m.r32(0xaa6100u+12u*j);need(actor);if(!(m.r8(actor+20u)&1u))continue;if(!predicate(m,actor,z))continue;if(!selected){need(m.r32(0x78579cu+8u)==0x40b9f0u);h.w8(out+12u,0u);const unsigned backing=h.allocate(40u);need(backing);++z.allocations;h.w8(out+12u,1u);h.w32(out+4u,backing);h.w32(out+8u,10u);h.w8(out+13u,1u);}h.w32(h.r32(out+4u)+4u*selected,actor);h.w32(out+16u,++selected);++z.insertions;}need(selected>=1u&&selected<count);return out;}
}
