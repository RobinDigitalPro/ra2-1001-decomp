#include "recovered/recovery_b1244.hpp"
#include <stdexcept>
namespace ra2::recovered::b1244{namespace{
void need(bool x){if(!x)throw std::domain_error("1244 bounded authentic selection route");}
unsigned type(Memory&m,unsigned a){need(m.r32(a)==0x78e540u&&m.r32(0x78e5c4u)==0x505da0u&&m.r32(0x78e5c0u)==0x6b6910u);const auto t=m.r32(a+0x5a8u);need(m.r32(t)==0x78ea78u);return t;}
void selectable(Memory&m,unsigned a){need(m.r8(a+0x76u)==0u&&m.r8(a+0x77u)==0u&&m.r8(0xa28953u)==0u&&m.r8(a+0x170u)==0u&&m.r8(type(m,a)+0x200u)==1u);}
void player(Memory&m,unsigned a){auto h=m.r32(a+0x1b4u);need(h&&m.r32(h)==0x78dde0u&&m.r32(0xa255c8u)==0u&&m.r8(h+0x134u)==0u&&m.r8(h+0x135u)==1u);}
// Actual5CB500: same player, no veto, positive spare-capacity tail insertion.
void append(Memory&m,unsigned a,Heap&h){selectable(m,a);player(m,a);need(m.r32(a+0x3fcu)==0u&&m.r8(type(m,a)+0xb04u)==0u&&m.r32(a+0x58cu)==0xffffffffu&&m.r32(a+0x594u)==0u&&m.r32(a+0x208u)==0u&&m.r32(0x81b9c4u)==0u);const auto n=m.r32(0xa288b0u);need(n<10u&&m.r32(0xa288a0u)==0x788b7cu&&m.r32(0xa288a8u)==10u&&m.r8(0xa288adu)==1u&&m.r32(0xa288b4u)==10u&&m.r8(type(m,a)+0xaa8u)==0u&&(m.r8(a+0x14u)&1u));const auto pool=m.r32(0xa288a4u);if(n){const auto prior=h.r32(pool);player(m,prior);need(m.r32(prior+0x1b4u)==m.r32(a+0x1b4u));}m.w32(0xa288b0u,n+1u);h.w32(pool+4u*n,a);m.w32(0xaa8db4u,0u);m.w8(0xaa8db8u,0u);m.w8(a+0x77u,1u);}
unsigned select(Memory&m,unsigned a,Heap&h){if(m.r8(a+0x77u))return 0u;need(m.r8(a+0x373u)==0u);player(m,a);append(m,a,h);need(m.r32(a+0x34u)==0u&&m.r8(0xa5e2fcu)==0u&&m.r8(0xa5e2feu)==0u);unsigned e=1u;if(m.r8(0x7c3976u)){const auto t=type(m,a);need(m.r32(t+0x3e0u)==0u);e=t+0x3d0u;}m.w8(0xa5e2feu,1u);m.w8(0xa5e2feu,0u);return(e&0xffffff00u)|1u;}
bool named(Memory&m,unsigned a,unsigned text){need(m.r8(a+0x7du)==1u);player(m,a);const auto t=type(m,a);need(m.r32(0xb10530u)==0u);for(unsigned k=0;k<25u;++k){auto x=m.r8(text+k),y=m.r8(t+0x24u+k);if(x>='A'&&x<='Z')x+=32u;if(y>='A'&&y<='Z')y+=32u;if(x!=y)return false;if(!x)return true;}throw std::domain_error("1244 actual bounded terminated Typeidentifier");}
}
namespace{
unsigned header(Heap&h,unsigned vt){const auto p=h.allocate(24u);need(p);h.w32(p,vt);h.w32(p+4u,0u);h.w32(p+8u,0u);h.w8(p+12u,1u);h.w8(p+13u,0u);h.w32(p+16u,0u);h.w32(p+20u,10u);return p;}
void push(Heap&h,unsigned p,unsigned value){const auto n=h.r32(p+16u);if(n==0u){need(h.r32(p+8u)==0u);const auto data=h.allocate(40u);h.w32(p+4u,data);h.w32(p+8u,10u);h.w8(p+13u,1u);}need(n<10u);h.w32(h.r32(p+4u)+4u*n,value);h.w32(p+16u,n+1u);}
unsigned destroy(Heap&h,unsigned p,unsigned basevt){h.w32(p,basevt);const auto a=h.r32(p+4u);if(a){h.release(a);h.w32(p+4u,0u);}h.w8(p+13u,0u);h.w32(p+8u,0u);h.release(p);return p;}
bool equal(Memory&m,unsigned a,unsigned b){for(unsigned k=0;k<25u;++k){const auto x=m.r8(a+k),y=m.r8(b+k);if(x!=y)return false;if(!x)return true;}throw std::domain_error("1244 produced Typeidentifier terminator");}
void feedback(Memory&m){need(m.r32(0xab7eb8u)==1u&&m.r32(0xab7ebcu)==1u);const auto record=m.r32(0xab7ec0u);constexpr char key[]="MSG:SelAcrossMap";for(unsigned k=0;k<sizeof(key);++k)need(m.r8(record+k)==unsigned(key[k]));need(m.r32(record+32u)==1u&&m.r32(record+36u)==0u);const auto p=m.r32(m.r32(0xab7ec4u));char16_t scratch[256];unsigned k=0u;for(;k<32u;++k){scratch[k]=char16_t(m.r16(p+2u*k));if(scratch[k]==0u)break;}need(k<32u);const auto house=m.r32(0xa1e0e4u);need(house&&m.r32(house+0x15f40u)==0u&&m.r32(0x836d30u)==0u);
 // Actual6EEB60 finds the genuine catalog,76EFC9 fully copies its produced
 // UTF16 prefix/NUL to a private output.5B1980 returns0 on genuinefontNULL
 // before reading the text bytes or receiver fields; no fabricated API/voice.
}
}
unsigned run(unsigned root,Memory&m,const Inputs&i,Heap&h){need(root==0x2ebb60u||root==0x2ec1b0u);const bool names=root==0x2ec1b0u;need(names||(i.cx&255u)==0u);const auto tactical=m.r32(0x821cacu);need(tactical&&m.r32(tactical)==0x797418u&&m.r32(tactical+0xdb0u)==0u&&m.r32(0xaa8db4u)==0u&&m.r8(0xaa8db9u)==0u&&m.r8(0x7c3976u)==0u);const auto selected=m.r32(0xa288b0u);need(selected>=1u&&selected<=2u);if(selected==1u)player(m,h.r32(m.r32(0xa288a4u)));unsigned name_header=0u;if(names){name_header=header(h,0x7915ccu);for(unsigned j=0;j<selected;++j){const auto a=h.r32(m.r32(0xa288a4u)+4u*j),text=type(m,a)+0x24u;bool found=false;for(unsigned k=0;k<h.r32(name_header+16u);++k)found|=equal(m,text,h.r32(h.r32(name_header+4u)+4u*k));if(!found)push(h,name_header,text);}}
 // Coldmode0 begins with actual empty Tactical list. Empty scan selects
 // across-map mode1, disposes that temporary header, then collects registry.
 m.w8(0xaa8db9u,0u);const auto empty=header(h,0x78579cu);m.w8(0xaa8db9u,1u);destroy(h,empty,0x7857fcu);const auto all=header(h,0x78579cu);const auto n=m.r32(0xa28870u),data=m.r32(0xa28864u);need(n>selected&&n<=4u);for(unsigned j=0;j<n;++j){const auto a=m.r32(data+4u*j);need(m.r8(a+0x7du)==1u);player(m,a);push(h,all,a);}for(unsigned j=0;j<n;++j){const auto a=h.r32(h.r32(all+4u)+4u*j);if(names){bool found=false;for(unsigned k=0;k<h.r32(name_header+16u);++k)found|=named(m,a,h.r32(h.r32(name_header+4u)+4u*k));need(found);}else need(m.r8(type(m,a)+0xb58u)==1u);select(m,a,h);}feedback(m);m.w32(0xaa8db4u,names?2u:1u);m.w8(0xaa8db8u,0u);if(names)destroy(h,name_header,0x7915ecu);return destroy(h,all,0x7857fcu);}
}
