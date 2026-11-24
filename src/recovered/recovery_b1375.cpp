#include "recovery_b1375.hpp"
#include <stdexcept>
namespace ra2::recovered::b1375 {using U=std::uint32_t;
namespace {void need(bool b,const char*s){if(!b)throw std::domain_error(s);}
// True fixed comparator4C22B0, signed firstDWORD of each8B record.
std::int32_t comparator(Memory&m,U a,U b){const auto x=std::int32_t(m.r32(a)),y=std::int32_t(m.r32(b));return x==y?0:x<y?-1:1;}
void swap8(Memory&m,U a,U b){if(a==b)return;for(U k=0;k<8;++k){const auto x=m.r8(a+k);m.w8(a+k,m.r8(b+k));m.w8(b+k,x);}}
void sort2(Memory&m,U p){
 // Actual76D686 n2 width8 selects76D7DA: findmaximumthen76D828 byteexchange.
 // Privatecallee argument words modified byCRT never alias the outer16words.
 const U high=p+8,maximum=comparator(m,high,p)>0?high:p;swap8(m,maximum,high);
}
}
U fun_004c0c80(Memory&m,const Inputs&){
 need(m.r32(0xb0de50u)!=0&&m.r32(0x84e174u)==2&&m.r8(0x84e17cu)==0,"1375 pendingtwo-record preparation");
 const U p=m.r32(0x84e170u);need(p&&m.r32(p)!=m.r32(p+8),"1375 realunequalkeys");
 for(U k=0;k<2;++k)need(m.r32(p+8*k+4)!=0&&m.r8(m.r32(p+8*k+4)+0x74u)==0,"1375 inactiveexistingrenderobject");
 sort2(m,p);m.w32(0x84e180u,0);m.w8(0x84e17cu,1);
 // Both actualinactive traversal arms converge on84E174reload.
 return m.r32(0x84e174u);
}
U fun_00699340(Memory&m,const Inputs&i){
 need((i.arg[2]&255u)==1&&m.r32(i.cx+0xe0u)==0&&m.r32(0xaa60c8u)==0,"1375 whole-region preparation");
 auto child=i;child.cx=0x821970u;(void)fun_004c0c80(m,child);return m.r32(0xaa60c8u);
}
}
