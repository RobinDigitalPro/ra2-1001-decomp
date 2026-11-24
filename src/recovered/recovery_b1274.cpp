#include "recovery_b1274.hpp"
#include "platform/x87_b61.hpp"
#include "platform/x87_extended_b40.hpp"
#include <stdexcept>
namespace ra2::recovered::b1274 {
namespace {
void need(bool x){if(!x)throw std::domain_error("1274 positive Team ongoingtick/zero-distance contract");}
unsigned command_for(unsigned r){switch(r){case 0x2af7f0u:case 0x2b04b0u:return 3u;case 0x2b1e00u:return 47u;case 0x2b1fd0u:return 58u;case 0x2b30f0u:return 53u;case 0x2b3400u:return 54u;default:throw std::out_of_range("1274 root");}}
unsigned convert(Memory&m,Inputs const&i,Observation&o){auto&f=i.fp;const unsigned cw=m.r32(0x7c3a04u);need(cw==0x0e7fu);if(f.control()!=cw)f.load_control(static_cast<unsigned short>(cw));++o.fp_conversions;return static_cast<unsigned>(f.pop_integer64());}
unsigned height_cell(Memory&m,Inputs const&i,unsigned cell,Observation&o){need((m.r8(0x838f70u)&7u)==7u&&m.r32(0x838f80u)==0u&&m.r8(cell+0x11bu)==0u&&m.r8(cell+0x11cu)==0u);auto&f=i.fp;f.load_integer32(0u);f.add64(std::uint64_t(m.r32(0x785728u))|(std::uint64_t(m.r32(0x78572cu))<<32u));++o.height_queries;const auto answer=convert(m,i,o);need(answer==0u);return answer;}
unsigned height_actor(Memory&m,Inputs const&i,unsigned actor,Observation&o){const unsigned x=m.r32(actor+0x88u),y=m.r32(actor+0x8cu),z=m.r32(actor+0x90u);need(x==5248u&&y==5248u&&z==0u&&m.r8(actor+0x79u)==0u);const unsigned index=(x>>8u)+512u*(y>>8u);need(index<m.r32(0x81a95cu));const unsigned cell=m.r32(m.r32(0x81a958u)+4u*index);need(cell&&m.r32(cell+0x24u)==0x00140014u);return z-height_cell(m,i,cell,o);}
unsigned mission(Memory&m,unsigned actor,Observation&o){need(m.r32(0x78e540u+0x16cu)==0x591570u);++o.mission_reads;const unsigned current=m.r32(actor+0x98u);return current==0xffffffffu?m.r32(actor+0xa0u):current;}
unsigned infantry_kind(Memory&m,Observation&o){need(m.r32(0x78e540u+0x2cu)==0x508c50u);++o.kind_callbacks;return 15u;}
unsigned step(Memory&m,unsigned script,Observation&o){need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==0u);const unsigned t=m.r32(script+0x24u);need(m.r32(t)==0x794260u&&m.r32(t+0xa0u)==1u&&m.r32(t+0xa8u)==5u);++o.script_reads;return m.r32(t+0xa4u);}
unsigned zero_distance(Memory&m,Inputs const&i,unsigned actor,unsigned cell,Observation&o){need(m.r32(cell)==0x788b04u&&m.r32(cell+0x24u)==0x00140014u&&m.r32(0x788b04u+0x48u)==0x47b650u&&m.r32(0x78e540u+0x48u)==0x5cd4d0u);const unsigned target_z=height_cell(m,i,cell,o);need(m.r32(actor+0x88u)==5248u&&m.r32(actor+0x8cu)==5248u&&m.r32(actor+0x90u)==target_z);
 // Actual 5CD2E6..5CD30C: dy,dz,dx and exact register-level norm order.
 auto&f=i.fp;f.load_integer32(0u);f.load_integer32(0u);f.load_integer32(0u);f.load_st0();platform::x87_extended::multiply_st1(f);f.load_st2();platform::x87_extended::multiply_st3(f);f.add_pop();platform::x87_b61::reg<0xd9c3>(f);platform::x87_extended::multiply_st4(f);f.add_pop();const auto sum=f.pop64();platform::x87_b61::reg<0xddd8>(f);platform::x87_b61::reg<0xddd8>(f);platform::x87_b61::reg<0xddd8>(f);need(sum==0u);
 // Actual 4BA080 equal-zero branch, not B379's positive sqrt-table route.
 f.load64(sum);f.compare32(m.r32(0x785738u));need((f.status()&0x4000u)!=0u);f.pop_st0();f.load32(m.r32(0x785738u));const unsigned distance=convert(m,i,o);need(m.r32(0x788b04u+0x2cu)==0x47cb80u);++o.kind_callbacks;need(distance==0u);++o.zero_distances;return distance;
}
}
unsigned run(unsigned root,Memory&m,Inputs const&i,Observation&o){const unsigned wanted=command_for(root);if(root==0x2b04b0u||root==0x2b3400u||root==0x2b1fd0u||root==0x2b30f0u)need((i.arg[1]&255u)==0u);const unsigned team=i.cx;need(m.r32(team)==0x7977f8u&&m.r8(team+0x7cu)==0u&&m.r8(team+0x7fu)==1u&&m.r8(team+0x80u)==0u&&m.r32(team+0x34u)==0u&&m.r32(0xa283c4u)==0u);const unsigned cell=m.r32(team+0x40u);need(cell&&m.r32(team+0x3cu)==cell);const unsigned rules=m.r32(0x821b88u),script=m.r32(team+0x28u);need(m.r32(rules+0x1384u)==512u&&m.r32(rules+0x1388u)==512u);unsigned actor=m.r32(team+0x54u),last=0u;need(actor);
 while(actor){need(++o.members<=6u&&m.r32(actor)==0x78e540u&&m.r32(actor+0x4c4u)==team&&m.r8(actor+0x7du)==1u&&m.r32(actor+0x6cu)>0u&&m.r8(actor+0x76u)==0u&&m.r8(actor+0x579u)==0u);need(step(m,script,o)==wanted);++o.null_distances;m.w8(actor+0x579u,1u);++o.arrivals;need(mission(m,actor,o)!=16u&&m.r32(actor+0xa0u)!=16u);need(mission(m,actor,o)==5u&&step(m,script,o)==wanted);
 need(m.r32(0x78e540u+0x54u)==0x4cca70u&&m.r8(actor+0x74u)==1u);const unsigned grounded=height_actor(m,i,actor,o)>=2u*m.r32(0xa5aaa8u)?1u:0u;const unsigned range=(wanted==53u||wanted==54u?m.r32(rules+0x1388u):m.r32(rules+0x1384u))*(grounded?2u:1u);need(zero_distance(m,i,actor,cell,o)<=range);need(m.r32(0x78e540u+0x1b0u)==0x5ccea0u);need(height_actor(m,i,actor,o)==0u);need(infantry_kind(m,o)!=2u&&mission(m,actor,o)==5u&&infantry_kind(m,o)!=2u);need((m.r8(actor+0x14u)&1u)!=0u&&m.r32(0x78e540u+0x80u)==0x6b6910u&&m.r32(0x78e540u+0x84u)==0x505da0u);last=m.r32(actor+0x5a8u);need(last&&m.r8(last+0xb1au)==0u&&m.r32(actor+0x494u)==0u);++o.type_reads;actor=m.r32(actor+0x4c8u);
 }m.w8(team+0x80u,1u);++o.completions;return(last&0xffffff00u)|1u;
}
}
