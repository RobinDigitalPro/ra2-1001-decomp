#include "recovered/recovery_b1056.hpp"
#include <stdexcept>
#include <utility>
namespace ra2::recovered::b1056 {namespace {
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
void name(Memory&m,unsigned a){unsigned n=0;while(n<8u&&m.r8(a+n)!=0u)++n;need(n>=1u&&n<=7u,"1056 original nonempty map name within accepted C-locale compare bound");}
}
unsigned run(Memory&m,const Inputs&i,Observation&o){
 const unsigned p=i.arg[0],f=m.r32(p+0x82u),g=m.r32(p+0x8eu);
 need(m.r32(p)==0x65u&&(f&~0x17u)==0u&&(g&~0xfeu)==0u,"1056 original packed session discriminator and producer flag masks");
 need(m.r8(0xa255e8u)!=(f&1u),"1056 actual initial mismatch selects substantive copy body594E44");
 need(m.r32(0xb10530u)==0u,"1056 genuine C-locale mode-zero case-insensitive compare");
 //594E49 calls actual4068F0, a single RET;680B10 below is also a RET.
 m.w8(0xa255e8u,f&1u);m.w8(0xa25670u,(g>>2u)&1u);m.w8(0xa255f0u,(f>>1u)&1u);
 m.w32(0xa28570u,(m.r32(0xa28570u)&0xffff7fffu)|((f&2u)<<14u));
 m.w8(0xa255f1u,(f>>2u)&1u);m.w8(0xa2566fu,(g>>3u)&1u);m.w8(0xa2566du,(g>>1u)&1u);
 m.w32(0xa25604u,m.r8(p+0x8cu));m.w32(0xa25608u,m.r8(p+0x8du));m.w32(0x7c3978u,m.r8(p+0x8au));
 m.w32(0xa255ecu,m.r32(p+0x7eu));m.w32(0xa25600u,m.r8(p+0x8bu));m.w32(0xa2897cu,m.r32(p+0x92u));
 const unsigned rules=m.r32(p+0x96u);m.w32(0xa28570u,rules);m.w32(0xa255f8u,m.r8(p+0xa2u));m.w32(0xa28758u,m.r8(p+0xa2u));
 m.w8(0xa255f2u,(g>>4u)&1u);m.w8(0xa255f3u,(g>>5u)&1u);m.w8(0xa255f4u,(g>>6u)&1u);m.w32(0xa28570u,rules|0xc0u);m.w8(0xa255fcu,(g>>7u)&1u);
 const unsigned state=m.r32(0xa255c0u),before=m.r32(state);need((before&0x400u)!=0u,"1056 genuine active state bit to clear");m.w32(state,before&0xfffffbffu);m.w8(0xa2566cu,1u);
 o.global_fields_written=20u;o.cleared_active_bits=1u;
 for(const auto&pair:{std::pair<unsigned,unsigned>{0xa25c20u,p+0xa3u},{0xa25e22u,p+0xb0u}}){name(m,pair.first);name(m,pair.second);Inputs q{};q.arg[0]=pair.first;q.arg[1]=pair.second;need(crt_b83::fun_0076d860(m,q)==0u,"1056 original actual post-copy map names compare equal");++o.comparisons;}
 need(m.r8(0xa25e48u)==((f>>4u)&1u)&&m.r32(0xa25e44u)==m.r32(p+0x9eu),"1056 current nonempty map mode and CRC select retained map route");
 need((m.r8(0xa25672u)|(m.r8(0xa25673u)<<8u))!=0u,"1056 genuine nonempty current map filename");
 //594FF2 loads full DWORD;59511D replaces only AL. RET4 is bridge-owned.
 return (m.r32(p+0x9eu)&0xffffff00u)|1u;
}
}
