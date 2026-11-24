#include "recovered/recovery_b1568.hpp"
#include <stdexcept>
namespace ra2::recovered::recovery_b1568 {
std::uint32_t run(Memory&m,const Inputs&i){using U=std::uint32_t;const U s=i.cx;auto need=[](bool p){if(!p)throw std::domain_error("1568 finite genuineBuilding activation route");};need(m.r32(s)==0x787bbcu&&m.r32(0x787d44u)==0x443500u&&m.r32(0x787d28u)==0x591570u&&m.r32(0x787d8cu)==0x591ab0u&&m.r32(0x787d90u)==0x591a50u);need(i.arg[0]==1&&m.r8(s+0x5b9u)==1&&m.r8(s+0x5afu)==0&&m.r32(s+0x98u)==0&&m.r32(s+0xa0u)==0xffffffffu);const U owner=m.r32(s+0x1b4u);need(owner&&m.r8(owner+0x134u)==0&&m.r8(owner+0x135u)==0&&m.r32(0xa255c8u)==0);
 // Actual591AB0 queues19 witharg2zero, no optionalvirtual callbacks.
 m.w32(s+0xa0u,19u);m.w8(s+0xa4u,0u);
 // Actual591A50 activatesqueued19. Its S-8 read is produced by rootCALL443575.
 // That CALL wrote44357B atS0-16;591AB0RET8 doesnotoverwriteit; laterCALL writesS0-8,
 // SUB0C/PUSHESI leave[ESP+8]=S0-16. This is caller-specific originalPC, never a seed.
 const U frame=m.r32(0xa2896cu);m.w32(s+0x98u,19u);m.w32(s+0xa0u,0xffffffffu);m.w32(s+0xa8u,0u);m.w32(s+0xb0u,frame);m.w32(s+0xb4u,0x44357bu);m.w32(s+0xb8u,0u);m.w32(s+0xacu,frame);m.w8(s+0xa4u,0u);return 0u;
}
}
