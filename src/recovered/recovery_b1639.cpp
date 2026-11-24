#include "recovered/recovery_b1639.hpp"
#include "platform/x87_state.hpp"
#include <array>
#include <stdexcept>
namespace ra2::recovered::b1639 {
namespace {
void need(bool b){if(!b)throw std::domain_error("1639 finite cold-prefix/positiveBC configuration");}
bool disjoint(U a,U n,U b,U z){return std::uint64_t(a)+n<=b||std::uint64_t(b)+z<=a;}
void readable(Memory&m,U a,U n){const auto end=std::uint64_t(a)+n;need(a>=0x10000000u&&n&&end<=0x70000000ull);(void)m.r8(a);(void)m.r8(U(end-1));}
// Caller-specific exact finite B83 ASCII/C-locale path (76D860).
// Existing crt_b83.cpp and its accepted guards remain unchanged.
U lower(U c){return c>='A'&&c<='Z'?c+0x20u:c;}
U compare(Memory&m,U a,U b){
 need(m.r32(0xb10530)==0);
 for(U n=0;n<8;++n){const U x=m.r8(a++),y=m.r8(b++);need(x<128&&y<128);
  if(x==y){if(!x)return 0;continue;}
  const U lx=lower(x),ly=lower(y);if(lx!=ly)return lx<ly?0xffffffffu:1u;if(!lx)return 0;
 }
 return 0;
}
// Whole75A030 getter, including authentic nullholder fallback.
U text_pointer(Memory&m,U holder){U p=m.r32(holder);return p?p:0x8248a4u;}
}
U fun_00735d80(Memory&m,const Inputs&i,b979::Heap&heap,b1633::Api&api,U root_pre_call_S){
 namespace fp=ra2::platform::x87;const auto host=fp::capture_host();
 try{
 need(std::uint64_t(root_pre_call_S)>=0x124ull+0x624ull);
 const U record=i.cx;readable(m,record,0x2c);need((m.r32(record)&0x8000u)==0);
 U length=0;for(;length<7;++length){const U c=m.r8(record+0x24u+length);if(!c)break;need(c>='A'&&c<='Z');}need(length>=1&&length<=6);
 need(m.r32(0xb0eea0)==0&&m.r32(0xb100f8)==0&&m.r32(0xb0fc00)==0&&m.r32(0xb0e5f0)==0&&m.r32(0xb10530)==0&&m.r8(0x8248a4)==0);
 constexpr std::array<std::array<U,2>,8> outputs{{{{0xa5a230,36}},{{0xa5a254,36}},{{0xa5a278,36}},{{0xa5a2b4,114}},{{0xa5a464,114}},{{0xa5a5c4,36}},{{0xaa4bf0,0x304}},{{0xa27dc4,32}}}};
 for(auto r:outputs)need(disjoint(record,0x2c,r[0],r[1]));
 for(U k=0;k<8;++k){const U p=m.r32(0xa27dc4+4*k);readable(m,p,0x69);need(disjoint(record,0x2c,p,0x69));}
 // Incoming borrowed record is also disjoint from every actual child-mutated
 // normal Static record. These are input guards, not an extra provider seam.
 need(api.parent&&m.r32(0xa5b1a4)==16&&m.r32(0xa5b1a8)==128&&m.r32(0xa5b1ac)==7&&m.r32(0xa5b1b8)==0x5d6fc0);
 for(U k=0;k<16;++k){need(api.controls[k]);const U h=U(reinterpret_cast<std::uintptr_t>(api.controls[k]));U node=m.r32(m.r32(0xa5b1a0)+4*(h&127));bool found=false;
  for(U j=0;node&&j<16;++j){readable(m,node,0x208);if(m.r32(node)==h){need(disjoint(record,0x2c,node,0x208));found=true;break;}node=m.r32(node+0x204);}need(found);
 }
 fp::restore_host(i.fp.image);
 // Genuine incoming ASCII and authentic empty global holder are compared;
 // the computed result is ignored exactly as in735D9F..735DA4.
 const U empty=text_pointer(m,0xb0e5f0);(void)compare(m,empty,record+0x24u);
 // Actual cold globals take735DD2->7360AE->7362D5->736440.
 // The produced F18/F10 locals have no selected semantic reads outside this
 // abstract algorithm. No Original private frame is mapped, read or seeded.
 Inputs child=i;child.cx=0;child.dx=0;child.fp.image=fp::capture_host();
 // AX/highDX/arg copies are unused abstract carriers, not assertions about
 // Original child volatile registers or unproduced child caller words.
 const U result=b1636::fun_00734590(m,child,heap,api,root_pre_call_S-0x124u);
 i.fp.image=child.fp.image;fp::restore_host(child.fp.image);
 // Integer POP/ADD/RET preserve the full actual childEAX (selected value0).
 i.fp.image=fp::capture_host();fp::restore_host(host);return result;
 }catch(...){fp::restore_host(host);throw;}
}
}
