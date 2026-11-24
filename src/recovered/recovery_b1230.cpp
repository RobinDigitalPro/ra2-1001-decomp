#include "recovered/recovery_b1230.hpp"
#include <stdexcept>
namespace ra2::recovered::b1230{namespace{void need(bool x){if(!x)throw std::domain_error("1230 authentic finite loading-context Infantry Team join");}
unsigned eligibility(Memory&m,unsigned team,unsigned actor,unsigned&index,Observation&o){need(m.r32(team)==0x7977f8u&&m.r32(actor)==0x78e540u&&m.r32(actor+0x4c4u)==0u&&m.r8(actor+0x7du)==1u&&m.r32(actor+0x6cu)>0u&&m.r32(0xa283c4u)==1u&&m.r8(actor+0x76u)==1u&&m.r32(actor+0x1b4u)==m.r32(team+0x2cu));
 // Actual62DDD0 creates one owned4-byte slot containing NULL, not count0.
 // This is a borrowed original used-field view, with no fixture ownership claim.
 need(m.r32(actor+0xd0u)==1u&&m.r32(actor+0xccu)!=0u&&m.r32(m.r32(actor+0xccu))==0u);++o.null_slots;
 need(m.r32(0x78e6acu)==0x591570u&&m.r32(actor+0x98u)==0xffffffffu&&m.r32(actor+0xa0u)==0xffffffffu);++o.virtual_callbacks; //591570 returns -1, excludes591BB0.
 need(m.r8(actor+0x379u)==1u&&m.r8(actor+0x37au)==1u);
 const unsigned script=m.r32(team+0x28u),st=m.r32(script+0x24u);need(m.r32(script)==0x7941d0u&&m.r32(script+0x2cu)==0u&&m.r32(st)==0x794260u&&m.r32(st+0xa0u)==1u&&m.r32(st+0xa4u)==0u&&m.r32(st+0xa8u)==0u);++o.script_reads;
 need(m.r32(0x78e56cu)==0x508c50u);o.virtual_callbacks+=2u; // two actual kind15 calls; no aircraft-specific branches.
 const unsigned tt=m.r32(team+0x24u),tf=m.r32(tt+0xdcu);index=0u;need(m.r32(tt)==0x797898u&&m.r32(tf)==0x797748u&&m.r32(tf+0x9cu)==1u);need(m.r32(0x78e5c4u)==0x505da0u);++o.virtual_callbacks;const unsigned type=m.r32(actor+0x5a8u);need(m.r32(type)==0x78ea78u&&m.r32(tf+0xa8u)==type);need(m.r32(team+0x84u)<m.r32(tf+0xa4u));++o.eligibilities;return(tf&0xffffff00u)|1u;
}}
unsigned run(unsigned root,Memory&m,const Inputs&i,Observation&o){need(root==0x2ae310u||root==0x2ae410u);const unsigned actor=i.arg[0],team=i.cx;unsigned index=0u;const auto answer=eligibility(m,team,actor,index,o);if(root==0x2ae410u){need(i.arg[1]!=0u);m.w32(i.arg[1],index);return answer;}
 // Root6AE323 supplies &publicarg0 to actual6AE410. The complete DWORD
 // overwritten by the produced output index is an observable caller mutation.
 i.arg[0]=index;need(m.r32(actor+0x4c4u)==0u);m.w32(team+0x84u,m.r32(team+0x84u)+1u);const auto old=m.r32(team+0x54u);need(old!=0u);m.w8(actor+0x579u,0u);m.w32(actor+0x4c8u,old);m.w32(team+0x54u,actor);m.w32(actor+0x4c4u,team);
 const auto tt=m.r32(team+0x24u),tf=m.r32(tt+0xdcu);need(m.r32(tt+0x9cu)==0xffffffffu&&m.r32(tf+0x98u)==0xffffffffu);m.w32(actor+0x1acu,0xffffffffu);need(m.r32(team+0x70u)==0u);m.w32(team+0x48u,m.r32(team+0x48u)+1u);
 // Actual78E540+2A0=6C93C0: real type via6B6910/+84, kind15,
 // then Type598 ThreatPosed (not monetary Cost) from original INI publisher.
 need(m.r32(0x78e7e0u)==0x6c93c0u&&m.r32(0x78e5c0u)==0x6b6910u);o.virtual_callbacks+=4u;const auto type=m.r32(actor+0x5a8u);const auto threat=m.r32(type+0x598u);need(threat>=1u&&threat<=997u);m.w32(team+0x4cu,m.r32(team+0x4cu)+threat);need(m.r32(team+0x34u)!=0u);m.w8(team+0x7eu,1u);m.w8(team+0x7du,1u);m.w8(actor+0x37au,m.r8(tt+0xedu));++o.joins;return((team+0x34u)&0xffffff00u)|1u;}
}
