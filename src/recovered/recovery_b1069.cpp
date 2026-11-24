#include "recovered/recovery_b1069.hpp"
#include <stdexcept>
namespace ra2::recovered::b1069{
static void need(bool v){if(!v)throw std::domain_error("1069 outside genuine populated conversion cleanup");}
// Actual41E510 release:39 shared references from immutable1063 construction.
// The last release removes the sole cache entry and frees its table, retaining
// the global owned array and its stale pointer cell exactly as original.
static void table_release(Memory&m,Heap&h,unsigned p){need(p!=0u);const auto refs=h.r32(p+0x20004u);need(refs>0u);h.w32(p+0x20004u,refs-1u);if(refs!=1u)return;const auto data=m.r32(0x824924u);need(m.r32(0x824930u)==1u&&h.r32(data)==p);m.w32(0x824930u,0u);need(h.release(p)!=0u);}
static unsigned plain(Heap&h,unsigned p,unsigned base){h.w32(p,base);need(h.release(p)!=0u);return p;}
static unsigned cached(Memory&m,Heap&h,unsigned p,unsigned tag,unsigned off,unsigned base){h.w32(p,tag);table_release(m,h,h.r32(p+off));h.w32(p+off,0u);h.w32(p,base);need(h.release(p)!=0u);return p;}
// Exact original slot0 type dispatch. Native uses the unmodified original
// vtables and methods; this is typed destructor semantics, no CPU interpreter.
static unsigned destroy(Memory&m,Heap&h,unsigned p){switch(h.r32(p)){
 case 0x788f78u:return cached(m,h,p,0x788f78u,8u,0x78953cu); // actual0x48d710
 case 0x788f84u:return cached(m,h,p,0x788f84u,8u,0x78953cu); // actual0x48d6d0
 case 0x788f90u:return cached(m,h,p,0x788f90u,8u,0x78953cu); // actual0x48d690
 case 0x788f9cu:return cached(m,h,p,0x788f9cu,12u,0x78953cu); // actual0x48d650
 case 0x788fa8u:return cached(m,h,p,0x788fa8u,8u,0x78953cu); // actual0x48d610
 case 0x788fb4u:return cached(m,h,p,0x788fb4u,8u,0x78953cu); // actual0x48d5d0
 case 0x788fc0u:return cached(m,h,p,0x788fc0u,8u,0x78953cu); // actual0x48d590
 case 0x788fccu:return cached(m,h,p,0x788fccu,8u,0x78953cu); // actual0x48d550
 case 0x788fd8u:return cached(m,h,p,0x788fd8u,8u,0x78953cu); // actual0x48d510
 case 0x788fe4u:return cached(m,h,p,0x788fe4u,8u,0x78953cu); // actual0x48d4d0
 case 0x788ff0u:return cached(m,h,p,0x788ff0u,8u,0x78953cu); // actual0x48d490
 case 0x788ffcu:return cached(m,h,p,0x788ffcu,12u,0x78953cu); // actual0x48d450
 case 0x789008u:return cached(m,h,p,0x789008u,8u,0x78953cu); // actual0x48d410
 case 0x789014u:return cached(m,h,p,0x789014u,8u,0x78953cu); // actual0x48d3d0
 case 0x789020u:return cached(m,h,p,0x789020u,8u,0x78953cu); // actual0x48d390
 case 0x78902cu:return cached(m,h,p,0x78902cu,8u,0x78953cu); // actual0x48d350
 case 0x789038u:return cached(m,h,p,0x789038u,12u,0x78953cu); // actual0x48d310
 case 0x789044u:return cached(m,h,p,0x789044u,8u,0x78953cu); // actual0x48d2d0
 case 0x789050u:return plain(h,p,0x78953cu); // actual0x48d2b0
 case 0x78905cu:return plain(h,p,0x78953cu); // actual0x48d290
 case 0x789068u:return plain(h,p,0x78953cu); // actual0x48d270
 case 0x789074u:return plain(h,p,0x78953cu); // actual0x48d250
 case 0x789080u:return plain(h,p,0x78953cu); // actual0x48d230
 case 0x78908cu:return plain(h,p,0x78953cu); // actual0x48d210
 case 0x789098u:return plain(h,p,0x78953cu); // actual0x48d1f0
 case 0x7890a4u:return plain(h,p,0x78953cu); // actual0x48d1d0
 case 0x7890b0u:return plain(h,p,0x78953cu); // actual0x48d1b0
 case 0x7890bcu:return plain(h,p,0x78953cu); // actual0x48d190
 case 0x7890c8u:return plain(h,p,0x78953cu); // actual0x48d170
 case 0x7890d4u:return plain(h,p,0x78953cu); // actual0x48d150
 case 0x7890e0u:return plain(h,p,0x78953cu); // actual0x48d130
 case 0x7890ecu:return plain(h,p,0x78953cu); // actual0x48d110
 case 0x7890f8u:return plain(h,p,0x78953cu); // actual0x48d0f0
 case 0x789104u:return plain(h,p,0x78953cu); // actual0x48d0d0
 case 0x789110u:return plain(h,p,0x78953cu); // actual0x48d0b0
 case 0x78911cu:return plain(h,p,0x78953cu); // actual0x48d090
 case 0x789128u:return plain(h,p,0x78953cu); // actual0x48d070
 case 0x789134u:return plain(h,p,0x78953cu); // actual0x48d050
 case 0x789140u:return plain(h,p,0x78953cu); // actual0x48d030
 case 0x78914cu:return cached(m,h,p,0x78914cu,8u,0x78952cu); // actual0x48cff0
 case 0x78915cu:return cached(m,h,p,0x78915cu,8u,0x78952cu); // actual0x48cfb0
 case 0x78916cu:return cached(m,h,p,0x78916cu,8u,0x78952cu); // actual0x48cf70
 case 0x78917cu:return cached(m,h,p,0x78917cu,12u,0x78952cu); // actual0x48cf30
 case 0x78918cu:return cached(m,h,p,0x78918cu,8u,0x78952cu); // actual0x48cef0
 case 0x78919cu:return cached(m,h,p,0x78919cu,8u,0x78952cu); // actual0x48ceb0
 case 0x7891acu:return cached(m,h,p,0x7891acu,8u,0x78952cu); // actual0x48ce70
 case 0x7891bcu:return cached(m,h,p,0x7891bcu,8u,0x78952cu); // actual0x48ce30
 case 0x7891ccu:return cached(m,h,p,0x7891ccu,8u,0x78952cu); // actual0x48cdf0
 case 0x7891dcu:return cached(m,h,p,0x7891dcu,8u,0x78952cu); // actual0x48cdb0
 case 0x7891ecu:return cached(m,h,p,0x7891ecu,8u,0x78952cu); // actual0x48cd70
 case 0x7891fcu:return cached(m,h,p,0x7891fcu,12u,0x78952cu); // actual0x48cd30
 case 0x78920cu:return cached(m,h,p,0x78920cu,8u,0x78952cu); // actual0x48ccf0
 case 0x78921cu:return plain(h,p,0x78952cu); // actual0x48ccd0
 case 0x78922cu:return plain(h,p,0x78952cu); // actual0x48ccb0
 case 0x78923cu:return plain(h,p,0x78952cu); // actual0x48cc90
 case 0x78924cu:return plain(h,p,0x78952cu); // actual0x48cc70
 case 0x78925cu:return plain(h,p,0x78952cu); // actual0x48cc50
 case 0x78926cu:return cached(m,h,p,0x78926cu,8u,0x78952cu); // actual0x48cc10
 case 0x78927cu:return cached(m,h,p,0x78927cu,8u,0x78952cu); // actual0x48cbd0
 case 0x78928cu:return cached(m,h,p,0x78928cu,8u,0x78952cu); // actual0x48cb90
 case 0x78929cu:return cached(m,h,p,0x78929cu,12u,0x78952cu); // actual0x48cb50
 case 0x7892acu:return cached(m,h,p,0x7892acu,8u,0x78952cu); // actual0x48cb10
 case 0x7892bcu:return cached(m,h,p,0x7892bcu,8u,0x78952cu); // actual0x48cad0
 case 0x7892ccu:return plain(h,p,0x78952cu); // actual0x48cab0
 case 0x7892dcu:return plain(h,p,0x78952cu); // actual0x48ca90
 case 0x7892ecu:return plain(h,p,0x78952cu); // actual0x48ca70
 case 0x7892fcu:return plain(h,p,0x78952cu); // actual0x48ca50
 case 0x78930cu:return plain(h,p,0x78952cu); // actual0x48ca30
 case 0x78931cu:return plain(h,p,0x78952cu); // actual0x48ca10
 case 0x78932cu:return plain(h,p,0x78952cu); // actual0x48c9f0
 case 0x78933cu:return plain(h,p,0x78952cu); // actual0x48c9d0
 case 0x78934cu:return plain(h,p,0x78952cu); // actual0x48c9b0
 case 0x78935cu:return plain(h,p,0x78952cu); // actual0x48c990
 case 0x78936cu:return plain(h,p,0x78952cu); // actual0x48c970
 case 0x78937cu:return plain(h,p,0x78952cu); // actual0x48c950
 case 0x78938cu:return plain(h,p,0x78952cu); // actual0x48c930
 case 0x78939cu:return plain(h,p,0x78952cu); // actual0x48c910
 case 0x7893acu:return plain(h,p,0x78952cu); // actual0x48c8f0
 case 0x7893bcu:return plain(h,p,0x78952cu); // actual0x48c8d0
 case 0x7893ccu:return plain(h,p,0x78952cu); // actual0x48c8b0
 case 0x7893dcu:return plain(h,p,0x78952cu); // actual0x48c890
 case 0x7893ecu:return plain(h,p,0x78952cu); // actual0x48c870
 case 0x7893fcu:return plain(h,p,0x78952cu); // actual0x48c850
 case 0x78940cu:return plain(h,p,0x78952cu); // actual0x48c830
 case 0x78941cu:return plain(h,p,0x78952cu); // actual0x48c810
 case 0x78942cu:return plain(h,p,0x78952cu); // actual0x48c570
 case 0x78943cu:return plain(h,p,0x78952cu); // actual0x48c7f0
 case 0x78944cu:return plain(h,p,0x78953cu); // actual0x48c7d0
 case 0x789458u:return plain(h,p,0x78953cu); // actual0x48c7b0
 case 0x789464u:return plain(h,p,0x78953cu); // actual0x48c790
 case 0x789470u:return plain(h,p,0x78953cu); // actual0x48c770
 case 0x78947cu:return plain(h,p,0x78953cu); // actual0x48c750
 case 0x789488u:return plain(h,p,0x78953cu); // actual0x48c730
 case 0x789494u:return plain(h,p,0x78953cu); // actual0x48c710
 case 0x7894a0u:return plain(h,p,0x78953cu); // actual0x48c6f0
 case 0x7894acu:return plain(h,p,0x78953cu); // actual0x48c6d0
 case 0x7894b8u:return plain(h,p,0x78953cu); // actual0x48c6b0
 case 0x7894c4u:return plain(h,p,0x78953cu); // actual0x48c690
 case 0x7894d0u:return plain(h,p,0x78953cu); // actual0x48c650
 case 0x7894dcu:return plain(h,p,0x78952cu); // actual0x48c630
 case 0x7894ecu:return plain(h,p,0x78952cu); // actual0x48c610
 case 0x7894fcu:return plain(h,p,0x78952cu); // actual0x48c5f0
 case 0x78950cu:return plain(h,p,0x78952cu); // actual0x48c5d0
 case 0x78951cu:return plain(h,p,0x78952cu); // actual0x48c5b0
 default:throw std::domain_error("1069 unproved original descriptor vptr");}}
unsigned fun_00485180(Memory&m,const Inputs&i,Heap&h){const auto p=i.cx;unsigned result=i.ax;const auto clear=[&](unsigned off){const auto a=m.r32(p+off);if(a)result=destroy(m,h,a);m.w32(p+off,0u);};
 clear(0x8u);
 clear(0xcu);
 clear(0x10u);
 clear(0x14u);
 clear(0x18u);
 clear(0x1cu);
 clear(0x20u);
 clear(0x24u);
 clear(0x28u);
 clear(0x2cu);
 clear(0x30u);
 clear(0x34u);
 clear(0x38u);
 clear(0x3cu);
 clear(0x40u);
 clear(0x44u);
 clear(0x48u);
 clear(0x4cu);
 clear(0x50u);
 clear(0x54u);
 clear(0x58u);
 clear(0x5cu);
 clear(0x60u);
 clear(0x64u);
 clear(0x68u);
 clear(0x6cu);
 clear(0x70u);
 clear(0x74u);
 clear(0x78u);
 clear(0x7cu);
 clear(0x8cu);
 clear(0x90u);
 clear(0x80u);
 clear(0x84u);
 clear(0x88u);
 clear(0x94u);
 clear(0x98u);
 clear(0x9cu);
 clear(0xa0u);
 clear(0xa4u);
 clear(0xa8u);
 clear(0xacu);
 clear(0xb0u);
 clear(0xb4u);
 clear(0xb8u);
 clear(0xbcu);
 clear(0xc0u);
 clear(0xc4u);
 clear(0xc8u);
 clear(0xccu);
 clear(0xd0u);
 clear(0xd4u);
 clear(0xd8u);
 clear(0xdcu);
 clear(0xe0u);
 clear(0xe4u);
 clear(0xe8u);
 clear(0xecu);
 clear(0xf0u);
 clear(0xf4u);
 clear(0xf8u);
 clear(0xfcu);
 clear(0x100u);
 clear(0x104u);
 clear(0x108u);
 clear(0x10cu);
 clear(0x110u);
 clear(0x114u);
 clear(0x118u);
 clear(0x11cu);
 clear(0x120u);
 clear(0x124u);
 clear(0x128u);
 clear(0x12cu);
 clear(0x130u);
 clear(0x134u);
 clear(0x138u);
 clear(0x13cu);
 clear(0x140u);
 clear(0x144u);
 clear(0x148u);
 clear(0x14cu);
 clear(0x150u);
 clear(0x154u);
 clear(0x158u);
 clear(0x15cu);
 clear(0x160u);
 clear(0x164u);
 clear(0x168u);
 return result;}
unsigned fun_004850f0(Memory&m,const Inputs&i,Heap&h){const auto p=i.cx;m.w32(p,0x788f70u);fun_00485180(m,i,h);const auto a=m.r32(p+0x170u);need(a!=0u);need(h.release(a)!=0u);const auto remap=m.r32(p+0x178u);m.w32(p+0x170u,0u);if(remap)need(h.release(remap)!=0u);m.w32(p+0x178u,0u);
 const auto count=m.r32(0x839490u),data=m.r32(0x839484u);need(count>=1u&&count<=4u&&m.r32(0x839480u)==0x788f30u);unsigned index=0u;while(index<count&&h.r32(data+4u*index)!=p)++index;need(index<count);const auto last=count-1u;m.w32(0x839490u,last);while(index<last){++index;h.w32(data+4u*(index-1u),h.r32(data+4u*index));}return index;
}
unsigned run(Memory&m,const Inputs&i,Heap&h,State&,unsigned root){switch(root){case 0x850f0u:return fun_004850f0(m,i,h);case 0x85180u:return fun_00485180(m,i,h);default:throw std::domain_error("1069 root");}}
}
