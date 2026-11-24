#include "recovery_b1278.hpp"
#include "platform/x87_b61.hpp"
#include "platform/x87_extended_b40.hpp"
#include <stdexcept>
namespace ra2::recovered::b1278 {
namespace {
void need(bool x){if(!x)throw std::domain_error("1278 positive Team ongoingtick/zero-distance contract");}
unsigned convert(Memory&m,Inputs const&i,Observation&o){auto&f=i.fp;const unsigned cw=m.r32(0x7c3a04u);need(cw==0x0e7fu);if(f.control()!=cw)f.load_control(static_cast<unsigned short>(cw));++o.fp_conversions;return static_cast<unsigned>(f.pop_integer64());}
unsigned height_cell(Memory&m,Inputs const&i,unsigned cell,Observation&o){need((m.r8(0x838f70u)&7u)==7u&&m.r32(0x838f80u)==0u&&m.r8(cell+0x11bu)==0u&&m.r8(cell+0x11cu)==0u);auto&f=i.fp;f.load_integer32(0u);f.add64(std::uint64_t(m.r32(0x785728u))|(std::uint64_t(m.r32(0x78572cu))<<32u));++o.height_queries;const auto answer=convert(m,i,o);need(answer==0u);return answer;}
unsigned height_actor(Memory&m,Inputs const&i,unsigned actor,Observation&o){const unsigned x=m.r32(actor+0x88u),y=m.r32(actor+0x8cu),z=m.r32(actor+0x90u);need(x==5248u&&y==5248u&&z==0u&&m.r8(actor+0x79u)==0u);const unsigned index=(x>>8u)+512u*(y>>8u);need(index<m.r32(0x81a95cu));const unsigned cell=m.r32(m.r32(0x81a958u)+4u*index);need(cell&&m.r32(cell+0x24u)==0x00140014u);return z-height_cell(m,i,cell,o);}
unsigned mission(Memory&m,unsigned actor,Observation&o){need(m.r32(0x78e540u+0x16cu)==0x591570u);++o.mission_reads;const unsigned current=m.r32(actor+0x98u);return current==0xffffffffu?m.r32(actor+0xa0u):current;}
unsigned infantry_kind(Memory&m,Observation&o){need(m.r32(0x78e540u+0x2cu)==0x508c50u);++o.kind_callbacks;return 15u;}
unsigned step(Memory&m,unsigned script,Observation&o){need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==1u);const unsigned t=m.r32(script+0x24u);need(m.r32(t)==0x794260u&&m.r32(t+0xa0u)==2u&&m.r32(t+0xb0u)==5u);++o.script_reads;return m.r32(t+0xacu);}
unsigned zero_distance(Memory&m,Inputs const&i,unsigned actor,unsigned target,Observation&o){need(m.r32(target)==0x78e540u&&m.r32(0x78e540u+0x48u)==0x5cd4d0u);need(m.r32(target+0x88u)==5248u&&m.r32(target+0x8cu)==5248u&&m.r32(target+0x90u)==0u&&m.r32(actor+0x88u)==5248u&&m.r32(actor+0x8cu)==5248u&&m.r32(actor+0x90u)==0u);
 // Actual 5CD2E6..5CD30C: dy,dz,dx and exact register-level norm order.
 auto&f=i.fp;f.load_integer32(0u);f.load_integer32(0u);f.load_integer32(0u);f.load_st0();platform::x87_extended::multiply_st1(f);f.load_st2();platform::x87_extended::multiply_st3(f);f.add_pop();platform::x87_b61::reg<0xd9c3>(f);platform::x87_extended::multiply_st4(f);f.add_pop();const auto sum=f.pop64();platform::x87_b61::reg<0xddd8>(f);platform::x87_b61::reg<0xddd8>(f);platform::x87_b61::reg<0xddd8>(f);need(sum==0u);
 // Actual 4BA080 equal-zero branch, not B379's positive sqrt-table route.
 f.load64(sum);f.compare32(m.r32(0x785738u));need((f.status()&0x4000u)!=0u);f.pop_st0();f.load32(m.r32(0x785738u));const unsigned distance=convert(m,i,o);need(m.r32(0x78e540u+0x2cu)==0x508c50u);++o.kind_callbacks;need(distance==0u);++o.zero_distances;return distance;
}
unsigned centroid(Memory&m,Inputs const&i,unsigned out0,unsigned out1,Observation&o){const auto team=i.cx,actor=m.r32(team+0x54u),cell=m.r32(team+0x40u);need(actor&&m.r32(actor+0x4c8u)==0u&&m.r8(actor+0x76u)==0u&&m.r8(actor+0x7du)==1u&&m.r32(actor+0x6cu)>0u&&m.r8(actor+0x579u)==1u&&m.r8(actor+0x32du)==1u);m.w32(out0,0u);m.w32(out1,0u);need(step(m,m.r32(team+0x28u),o)==3u&&m.r8(m.r32(team+0x24u)+0xa7u)==0u&&m.r32(m.r32(actor+0x5a8u)+0x52cu)==0u);need(m.r32(cell)==0x788b04u&&m.r32(cell+0x24u)==0x00140014u);need(height_cell(m,i,cell,o)==0u);/* Actual5CD430 squaredXY is integer andzero foridenticalcoordinategetters. */need(m.r32(actor+0x88u)==5248u&&m.r32(actor+0x8cu)==5248u&&m.r32(actor+0x90u)==0u);m.w32(out0,cell);
 // Actual502650/2201: flatcells, nooverlayowner, selfonlyE4 skipsownoccupant;
 // 4766C0 and4C8330 direction3 read genuine21,21 Cell, neverfallback.
 const auto table=m.r32(0x81a958u),neighbor=m.r32(table+4u*(21u+512u*21u));need(neighbor&&m.r32(neighbor+0x24u)==0x00150015u&&m.r16(neighbor+0x116u)==0xffffu&&m.r16(cell+0x116u)==0xffffu&&(m.r32(cell+0x140u)&0x100u)==0u&&(m.r32(neighbor+0x140u)&0x100u)==0u&&m.r32(cell+0x44u)==0xffffffffu&&m.r32(cell+0x54u)==0xffffffffu&&m.r8(cell+0x124u)==0u&&m.r32(cell+0xe4u)==actor&&m.r32(actor+0x30u)==0u&&m.r32(m.r32(actor+0x5a8u)+0x5a4u)==0u&&m.r32(cell+0xecu)==0u&&m.r8(actor+0x370u)==0u&&m.r32(0x8391d0u)==0u);
 need(m.r32(0x81a910u)==32u&&m.r32(0x81a918u)==2u&&m.r32(0x81a91cu)==2u&&m.r32(0x81a920u)==28u&&m.r32(0x81a924u)==24u);auto&f=i.fp;f.load32(m.r32(0x8391d0u));f.compare32(m.r32(0x785738u));need((f.status()&0x4000u)!=0u);f.pop_st0();++o.passability;++o.centroids;m.w32(out0,actor);m.w32(out1,actor);return out1;
}
}
unsigned run(unsigned root,Memory&m,Inputs const&i,Observation&o){need((root==0x2aec60u||root==0x2b1570u)&&m.r32(i.cx)==0x7977f8u&&m.r32(0xa283c4u)==0u);const auto team=i.cx;
 if(root==0x2aec60u)return centroid(m,i,i.arg[0],i.arg[1],o);
 centroid(m,i,team+0x34u,team+0x38u,o);const auto target=m.r32(team+0x34u);m.w32(team+0x40u,target);need(m.r32(target)==0x78e540u&&m.r8(team+0x7cu)==0u&&m.r8(team+0x7fu)==1u&&m.r8(team+0x80u)==0u);const auto actor=m.r32(team+0x54u),rules=m.r32(0x821b88u);need(actor==target&&m.r8(actor+0x579u)==1u&&m.r32(actor+0x4c8u)==0u&&m.r32(rules+0x1384u)==512u);++o.members;need(mission(m,actor,o)==5u&&m.r32(actor+0xa0u)==5u&&step(m,m.r32(team+0x28u),o)==3u);const unsigned grounded=height_actor(m,i,actor,o)>=2u*m.r32(0xa5aaa8u)?1u:0u;need(zero_distance(m,i,actor,target,o)<=512u*(grounded?2u:1u));need(height_actor(m,i,actor,o)==0u);need(infantry_kind(m,o)!=2u&&mission(m,actor,o)==5u&&infantry_kind(m,o)!=2u&&(m.r8(actor+0x14u)&1u)!=0u);need(m.r8(m.r32(actor+0x5a8u)+0xb1au)==0u&&m.r32(actor+0x494u)==0u);m.w8(team+0x80u,1u);++o.completions;
 // Actual40DC20 seeskind15 andreturnstarget; member/target228NULL are genuine6B6564.
 need(infantry_kind(m,o)==15u&&m.r32(actor+0x228u)==0u&&m.r32(target+0x228u)==0u);return 0u;
}
}
