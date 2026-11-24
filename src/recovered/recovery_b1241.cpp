#include "recovery_b1241.hpp"
#include <stdexcept>
#include <initializer_list>
namespace ra2::recovered::b1241 {
unsigned run(Memory&m,const Inputs&i,Heap&heap,Observation&o,unsigned root){
 constexpr unsigned self=0xa255c8u;
 if(root!=0x264f70u||i.cx!=self||m.r32(0x838be0u))throw std::domain_error("1241 exact public cold global Session construction");
 for(unsigned k=0;k<0x299cu;++k)if(m.r8(self+k))throw std::domain_error("1241 original complete zero BSS destination");
 const auto w=[&](unsigned p,unsigned v){m.w32(self+p,v);};const auto b=[&](unsigned p,unsigned v){m.w8(self+p,v);};
 const auto zero=[&](unsigned p,unsigned n){for(unsigned k=0;k<n;++k)b(p+k,0u);};
 const auto address=[&](unsigned p){for(unsigned k=0;k<10u;++k)b(p+k,255u);++o.addresses;};
 const auto vector=[&](unsigned p,unsigned table){w(p,table);w(p+4u,0u);w(p+8u,0u);b(p+12u,1u);b(p+13u,0u);w(p+16u,0u);w(p+20u,10u);++o.vectors;};
 w(4u,0u);
 // Three complete original settings records: count/defaults, five enabled
 // flags and eight explicitly cleared three-DWORD entries.
 for(unsigned p:{0x13cu,0x1b8u,0x234u}){w(p,0u);w(p+4u,0u);w(p+8u,0u);w(p+12u,10000u);w(p+16u,10u);for(unsigned k=0;k<5u;++k)b(p+20u+k,1u);for(unsigned k=0;k<24u;++k)w(p+28u+4u*k,0u);++o.records;}
 for(unsigned k=0;k<8u;++k)address(0x348u+k*0x68u);
 vector(0x640u,0x79444cu);address(0x894u);vector(0x8a0u,0x79442cu);
 // Exact 5B17B0 defaults at9D8, with untouched gaps retained.
 constexpr unsigned record=0x9d8u;
 for(unsigned k=0;k<6u;++k)w(record+4u*k,0u);for(unsigned k=0;k<3u;++k)b(record+0x18u+k,0u);
 for(unsigned p:{0x1cu,0x20u,0x24u,0x2b0u,0x2b4u,0x2bcu,0x2c0u,0x2c4u})w(record+p,0u);
 for(unsigned p:{0x28u,0x16cu,0x2b8u}){b(record+p,0u);b(record+p+1u,0u);}
 for(unsigned k=0;k<7u;++k)w(record+0x1480u+4u*k,0x10001u);++o.records;address(0x1e74u);
 // Real CCFile base/embedded buffer defaults. No allocation by constructors
 // 438140(0,0),4911C0(0,0); filename below is the sole target allocation.
 constexpr unsigned file=0x22fcu;
 w(file,0x7856a0u);w(file+4u,1u);w(file+8u,0u);w(file+12u,0xffffffffu);w(file+16u,0xffffffffu);w(file+20u,0u);zero(file+24u,5u);zero(file+32u,6u);
 for(unsigned p:{0x28u,0x2cu,0x30u,0x34u,0x38u,0x44u,0x48u,0x4cu})w(file+p,0u);
 w(file+0x3cu,0xffffffffu);w(file+0x40u,0xffffffffu);b(file+0x50u,0u);w(file+0x54u,0u);w(file+0x58u,0u);b(file+0x5cu,0u);w(file+0x60u,0u);
 address(0x2368u);address(0x256cu);
 for(unsigned p:{0x27b0u,0x27c8u,0x27e0u})vector(p,0x791838u);
 vector(0x28a0u,0x79440cu);vector(0x28b8u,0x78955cu);vector(0x28d0u,0x7906f4u);
 address(0x290du);address(0x2917u);b(0x298cu,0u);
 w(0u,0u);w(0x14u,2u);w(0x1cu,0u);b(0x20u,1u);w(0x24u,0u);
 for(unsigned p:{0x28u,0x29u,0x2au,0x2bu,0x2cu,0x34u,0x35u,0xa4u,0xa5u,0xa6u,0xa7u,0xa8u,0x108u})b(p,0u);
 for(unsigned p:{0x30u,0x38u,0x104u,0x124u})w(p,0u);
 w(0x40u,1u);w(0x128u,0xffffffffu);w(0x11cu,2u);w(0x120u,0xffffffffu);w(0x134u,m.r32(self+0x124u));w(0x138u,m.r32(self+0x128u));w(0x12cu,m.r32(self+0x11cu));w(0x130u,m.r32(self+0x120u));
 b(0x1e86u,1u);b(0x1e87u,1u);w(0x2b0u,0u);w(0x2b4u,0u);w(0x2bcu,0xffffffffu);b(0x2b8u,0u);b(0x290cu,0u);zero(0x2922u,42u);
 w(0x294cu,0xffffffffu);w(0x2950u,0u);b(0x2954u,1u);w(0x2958u,0xffffffffu);b(0x295cu,0u);w(0x2960u,20u);w(0x2964u,0u);w(0x2968u,0u);w(0x296cu,0xffffffffu);
 b(0x638u,0u);b(0x639u,0u);b(0x63au,0u);w(0x2c0u,8u);w(0x2c4u,0u);w(0x2c8u,15u);w(0x2ccu,5u);w(0x2e0u,15u);zero(0x2ecu,0x340u);w(0x2e4u,0u);w(0x2e8u,0u);b(0x62cu,0u);b(0x62du,0u);w(0x630u,0u);w(0x634u,0u);zero(0x1e88u,2u);w(0x1f68u,m.r32(self+0x1f68u)&~1u);
 // Actual slot+8=46FD50 composes42F550,630110 and three slot+4=401940
 // filename getters. Genuine838BE0=0 excludes directory search/provider.
 if(m.r32(0x7856a8u)!=0x46fd50u||m.r32(0x7856a4u)!=0x401940u)throw std::domain_error("1241 actual CCFile callback provenance");
 o.virtual_callbacks+=4u;const unsigned name=heap.allocate(11u);++o.allocations;if(!name)throw std::runtime_error("1241 genuine filename allocation");
 for(unsigned k=0;k<11u;++k)heap.w8(name+k,m.r8(0x7dcea8u+k));w(file+8u,0u);w(file+12u,0xffffffffu);w(file+20u,name);b(file+28u,1u);
 w(0x2360u,m.r32(self+0x2360u)&~7u);w(0x2364u,0u);b(0x2372u,0u);b(0x2373u,1u);b(0x2374u,0u);zero(0x2376u,2u);zero(0x2576u,2u);w(0x2820u,0u);w(0x2908u,1u);w(0x27acu,0x234u);
 zero(0x8b8u,32u);for(unsigned k=0;k<64u;++k)w(0x8d8u+4u*k,0xffffffffu);
 w(0x283cu,0xffffffffu);w(0x2824u,m.r32(self+0x2824u)|1u);w(0x2828u,0u);w(0x282cu,0x2f8u);w(0x2830u,3u);w(0x2834u,0x2580u);w(0x2838u,0u);w(0x2840u,0u);
 unsigned count=0u;do{const unsigned ch=m.r8(0x8248a4u+count);b(0x284cu+count,ch);++count;if(!ch)break;}while(count<80u);if(count!=1u)throw std::domain_error("1241 genuine original empty label");
 w(0x289cu,0u);w(0x2970u,0x7fffffffu);w(0x2974u,0u);w(0x2978u,0u);for(unsigned k=0;k<3u;++k)w(0x297cu+4u*k,m.r32(0xaa0c40u+4u*k));
 b(0x298cu,0u);w(0x2990u,0u);w(0x2994u,0u);w(0x2998u,0u);b(0x281cu,0u);w(0x3cu,0u);for(unsigned k=0;k<8u;++k){w(0x64u+4u*k,0xffffffffu);w(0x84u+4u*k,0xffffffffu);}w(0x0cu,0u);w(0x10u,0u);b(0x658u,0u);w(0x87cu,0u);b(0x880u,0u);w(0x884u,0u);
 return self;
}
}
