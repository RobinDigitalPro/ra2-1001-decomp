#include "recovered/recovery_b1105.hpp"
#include <stdexcept>
namespace ra2::recovered::b1105{
static void need(bool b){if(!b)throw std::domain_error("1105 active CP1252/actualLCID0/realCRTlock25");}
static LPVOID address(unsigned n){return reinterpret_cast<LPVOID>(std::uintptr_t(n));}
static void tables(Memory&m,const Api&a,unsigned bp){need(m.r32(0xb10ac8u)==1252u&&m.r32(0xb10ce4u)==0u&&m.r32(0xb10530u)==0u&&m.r32(0xb10714u)==2u&&m.r32(0xb1055cu)==2u);const auto info=bp-0x14u;need(a.cp(1252u,static_cast<CPINFO*>(address(info)))==1&&m.r32(info)==1u);for(unsigned k=0;k<12u;++k)need(m.r8(info+6u+k)==0u);const auto input=bp-0x114u,type=bp-0x514u,lower=bp-0x214u,upper=bp-0x314u;for(unsigned k=0;k<256u;++k)m.w8(input+k,k);m.w8(input,32u);
 // Full427 cachedANSI path uses zeroexplicitLCID thenB10530 (alsozero).
 need(a.type(m.r32(0xb10530u),1u,static_cast<LPCSTR>(address(input)),256,static_cast<LPWORD>(address(type)))!=FALSE);
 // Actual374EA6 boundedlength is256: every selected inputbyte is nonzero.
 unsigned length=0u;while(length<256u&&m.r8(input+length))++length;need(length==256u&&m.r8(input+length)==1u); // Original374EA6 also reads input[256], the initialized adjacent CPINFO.MaxCharSize byte.
 need(a.map(0u,0x100u,static_cast<LPCSTR>(address(input)),int(length),static_cast<LPSTR>(address(lower)),256)==256);need(a.map(0u,0x200u,static_cast<LPCSTR>(address(input)),int(length),static_cast<LPSTR>(address(upper)),256)==256);
 for(unsigned ch=0;ch<256u;++ch){const auto flags=m.r16(type+2u*ch);if(flags&1u){m.w8(0xb10be1u+ch,m.r8(0xb10be1u+ch)|0x10u);m.w8(0xb10ae0u+ch,m.r8(lower+ch));}else if(flags&2u){m.w8(0xb10be1u+ch,m.r8(0xb10be1u+ch)|0x20u);m.w8(0xb10ae0u+ch,m.r8(upper+ch));}else m.w8(0xb10ae0u+ch,0u);}}
unsigned run(Memory&m,const Inputs&i,const Api&a,Observation&o){need(i.arg[0]==1252u&&m.r32(0xb10ac8u)==0u&&a.enter&&a.leave&&a.cp&&a.type&&a.map);auto v=m;leaf::Memory scratch(o.scratch.data(),unsigned(reinterpret_cast<std::uintptr_t>(o.scratch.data())),unsigned(o.scratch.size()));v.add(scratch);const auto lock=m.r32(0x8172dcu);need(lock);auto*critical=static_cast<LPCRITICAL_SECTION>(address(lock));a.enter(critical);m.w32(0xb10568u,0u);const auto codepage=i.arg[0];i.arg[0]=codepage;for(unsigned p=0x817928u;p<0x817a18u;p+=0x30u)need(m.r32(p)!=codepage);need(a.cp(codepage,static_cast<CPINFO*>(address(o.root_cp())))==1&&v.r32(o.root_cp())==1u);for(unsigned k=0;k<12u;++k)need(v.r8(o.root_cp()+6u+k)==0u);m.w32(0xb10ce4u,0u);for(unsigned k=0;k<257u;++k)m.w8(0xb10be0u+k,0u);m.w32(0xb10ac8u,codepage);m.w32(0xb10adcu,0u);for(unsigned k=0;k<3u;++k)m.w32(0xb10ad0u+4u*k,0u);tables(v,a,o.helper_bp());a.leave(critical);return 0u;}
}
