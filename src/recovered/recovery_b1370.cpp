#include "recovery_b1370.hpp"
#include <stdexcept>
namespace ra2::recovered::b1370 {
namespace {using U=std::uint32_t;
void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
U original_60d7e0_inhibited(Memory&m,U eax){need(m.r8(0xa5e2c8u)==1,"1370 actual inhibited refresh");return (eax&0xffffff00u)|1u;}
U original_612da0_borrowed(Memory&m,U self){const U eax=m.r32(self+4);need(eax!=0&&m.r8(self+0xd)==0,"1370 borrowed nonowning storage");m.w8(self+0xd,0);m.w32(self+8,0);return eax;}
// Only fields really produced by40BC10 and subsequent root stores are modeled.
// The unproduced private padding is neither read nor exported by this route.
struct PrivateVector {U vptr,pointer,capacity;std::uint8_t valid,owned;U count,growth;};
PrivateVector original_40bc10_zero(){return {0x7857fcu,0,0,1,0,0,0};}
U original_40b960_null(PrivateVector& v){const U eax=v.pointer;need(eax==0&&v.owned==0,"1370 actual constructed empty buffer");v.owned=0;v.capacity=0;return eax;}
void original_4e0020(Memory&m){m.w32(0xa28b34u,0);}
void original_498a30_static(Memory&m){original_4e0020(m);need(m.r8(0xa28953u)==1,"1370 no live control setup");}
void original_626b20_static(Memory&m){original_498a30_static(m);need(m.r8(0xa28953u)==1,"1370 no live widget creation");}
U original_671290(Memory&m){
 const U a=m.r32(0x798c14u),b=m.r32(0x798c18u),c=m.r32(0x82197cu),d=m.r32(0x821974u);
 const U base=b+c+d-0x9eu;need(base>=0x66u&&base<=100000u,"1370 positive bounded layout span");
 m.w32(0x821968u,a);m.w32(0x821964u,0x9e);m.w32(0x82196cu,base);
 const bool flag=m.r8(m.r32(0xa255c0u)+0x2239u)!=0;
 m.w32(0xaa4854u,flag?0xa6:0xa5);m.w32(0xaa4858u,flag?0x40:0x34);m.w32(0xaa4860u,0xc5);
 m.w32(0xaa4864u,flag?0x1d:0x20);m.w32(0xaa486cu,0xe3);m.w32(0xaa4870u,flag?0x3f:0x40);m.w32(0xaa4874u,0x32);
 const U value=base-(flag?0x1au:0x12u)-0x4cu;
 // Actual IMUL highDWORD, SAR4, sign correction; bounded value is nonnegative.
 const U high=U((std::uint64_t(value)*0x51eb851full)>>32u),quotient=high>>4u;
 const U span=quotient*50u;m.w32(0xaa4878u,span);const U eax=span+0xea;
 m.w32(0xaa4884u,flag?0x2e:0x2d);m.w32(0xaa4880u,eax);m.w32(0xaa4888u,0x32);return eax;
}
constexpr U borrowed16[]{0xaa8b00u,0xaa8b7cu,0xaa8b74u,0xaa8b38u,0xaa8b9cu,0xaa8af8u,0xaa8b40u,0xaa8b48u,0xaa8b90u,0xaa8b08u,0xaa8b54u,0xaa8b34u,0xaa8b30u,0xaa8b58u,0xaa8b64u,0xaa8b68u};
U original_6ea140_borrowed(Memory&m,U eax){for(U k=0;k<16;++k){need(m.r8(0xaa8cc6u+k)==0&&m.r32(borrowed16[k])!=0,"1370 actual nonowning helper buffer");eax&=0xffffff00u;m.w32(borrowed16[k],0);}return eax;}
U original_76df28_null(U arg,U eax){need(arg==0,"1370 genuine null CRT free branch");return eax;}
U original_76d67b_null(U arg,U eax){return original_76df28_null(arg,eax);}
U original_6ea3f0_null(Memory&m,U eax){for(U k=0;k<16;++k){const U arg=m.r32(0xaa8c64u+4*k);need(arg==0,"1370 original sixteen null free arguments");if(k%3==0)eax=arg;eax=original_76d67b_null(arg,eax);m.w32(0xaa8c64u+4*k,0);}return eax;}
}
U fun_0060bbf0(Memory&m,const Inputs&i){
 (void)original_60d7e0_inhibited(m,i.ax);const U pending=m.r32(0xa5e208u),count=m.r32(0xa288b0u);
 need(pending!=0&&count>=1&&count<=3,"1370 pending reference and existing selection");m.w32(0xa5e208u,0);
 need(m.r32(0xa5e2a0u)==0&&m.r32(0xa5e2c0u)==0&&m.r32(0xa5e2a8u)==0xffffffffu,"1370 no queued object/action callbacks");
 m.w32(0xa5e2c0u,0);const U eax=original_612da0_borrowed(m,0xa5e2b0u);
 m.w8(0xa5e2e8u,0);m.w8(0xa5e2e0u,0);m.w8(0xa5e220u,0);return eax;
}
U fun_0060f6d0(Memory&m,const Inputs&){
 const U count=m.r32(0xa288b0u),table=m.r32(0xa288a4u);need(m.r32(0xa5e250u)!=0&&count>=1&&count<=3,"1370 pending command with nonempty selection");m.w32(0xa5e250u,0);
 auto local=original_40bc10_zero();local.vptr=0x78579cu;local.growth=10;local.count=0;
 for(U k=0;k<count;++k){const U object=m.r32(table+4*k);need(object!=0&&(m.r8(object+0x14u)&1u)==0,"1370 real inactive selected record");}
 need(local.count==0,"1370 no selected active producers");local.vptr=0x7857fcu;return original_40b960_null(local);
}
U fun_00671450(Memory&m,const Inputs&){
 original_626b20_static(m);(void)original_671290(m);
 U eax=0;if(m.r8(0xa28770u)!=0)eax=m.r32(0x821970u)+m.r32(0x821978u);
 need(eax<=100000u,"1370 bounded original layout offset");m.w32(0x821960u,eax);m.w32(0xaa4868u,eax+0x16u);
 const bool flag=m.r8(m.r32(0xa255c0u)+0x2239u)!=0;
 m.w32(0xaa4850u,eax+(flag?0x14u:0x21u));m.w32(0xaa485cu,eax+(flag?0x1au:0x14u));eax+=0x27u;m.w32(0xaa487cu,eax);
 return (eax&0xffffff00u)|m.r8(0xa28953u);
}
U fun_006e6e00(Memory&m,const Inputs&i){
 U eax=i.ax;constexpr U first[]{0xaa8ca8u,0xaa8cacu,0xaa8cb0u,0xaa8b78u};
 for(U k=0;k<4;++k){need(m.r8(0xaa8cb4u+k)==0&&m.r32(first[k])!=0,"1370 root nonowning buffers");eax&=0xffffff00u;m.w32(first[k],0);}
 for(U a:{0xaa8bc0u,0xaa8bc4u,0xaa8bc8u,0xaa8bccu})need(m.r32(a)==0,"1370 absent owning provider");
 eax=0;need(m.r8(0xaa8c2cu)==0,"1370 no active owned subsystem");eax=original_6ea140_borrowed(m,eax);
 for(U a:{0xaa8c30u,0xaa8c34u,0xaa8c38u,0xaa8c3cu})need(m.r32(a)==0,"1370 absent later owning provider");
 eax=original_6ea3f0_null(m,0);m.w8(0xaa8c40u,0);return eax;
}
}
